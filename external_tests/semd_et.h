#pragma once
#if !defined(_SEMD_ET_H_)
#define _SEMD_ET_H_

#include "semd/semd.h"
#include "semd/semd_functions.h"
#include <chrono>
#include <iostream>
#include <random>

void testAbs()
{

    const std::size_t n = 1100006;

    semd<alignment::align_32, double> x(n);
    semd<alignment::align_32, double> y(n);
    double c = 3.141592;
    double *x1 = avx2_utility::aligned_alloc<double>(n, (std::size_t)alignment::align_32);
    double *y1 = avx2_utility::aligned_alloc<double>(n, (std::size_t)alignment::align_32);
    double *res1 = avx2_utility::aligned_alloc<double>(n, (std::size_t)alignment::align_32);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(-100.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = x1[i] = uni_rnd(device);
        y[i] = y1[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    auto const res = abs(x * y + c * y);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res1[i] = std::abs(x1[i] * y1[i] + c * y1[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    std::cout << "		C++				Assembly (SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    // for (std::size_t i = 10000; i < n; ++i)
    //{
    //     std::cout << i << " | " << res1[i];
    //     std::cout << " | " << (res[i]);
    //     std::cout << " | " << (res1[i] - res[i]) << "\n";
    // }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x1);
    avx2_utility::aligned_free(y1);
    avx2_utility::aligned_free(res1);
}

#endif ///_SEMD_ET_H_
