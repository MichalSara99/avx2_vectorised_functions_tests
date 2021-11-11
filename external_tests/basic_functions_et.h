#pragma once
#if !defined(_BASIC_FUNCTIONS_ET)
#define _BASIC_FUNCTIONS_ET

#include <avx2_math_x86_lib.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <new>
#include <random>

#include "macros/avx2_macros.h"

using namespace avx2_basics;

void testBasicAbsAVX2Double()
{

    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(-10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = abs_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::abs(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed absolute value AVX2 occured");

    std::cout << "		C++				Assembly (SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicAbsAVX2Float()
{

    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(-10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = abs_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::abs(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed absolute value AVX2 occured");

    std::cout << "		C++				Assembly (SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicSqrtAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sqrt_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::sqrt(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed square root AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicSqrtAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sqrt_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::sqrt(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed square root AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicSqrpAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sqrp_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] * x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed square power AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicSqrpAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sqrp_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] * x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed square power AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicMinAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *y = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(-10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = min_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::min(x[i], y[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed minimum value AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(y);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicMinAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *y = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(-10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = min_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::min(x[i], y[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed minimum vaule AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(y);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicMinBroadAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *y = avx2_utility::aligned_alloc<double>(n, align);
    double x = 3.14159;
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(-10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = min_avx2(y, x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::min(x, y[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast minimum value AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(y);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicMinBroadAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *y = avx2_utility::aligned_alloc<float>(n, align);
    float x = 3.1415f;
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(-10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = min_avx2(y, x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::min(x, y[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast minimum value AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(y);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicMaxAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *y = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(-10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = max_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::max(x[i], y[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed maximum value SSE occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(y);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicMaxAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *y = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(-10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = max_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::max(y[i], x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed maximum value AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(y);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicMaxBroadAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double y = 3.151492;
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(-10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = max_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::max(x[i], y);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast maximum value AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicMaxBroadAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float y = 3.14152f;
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(-10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = max_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::max(y, x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast maximum value AVX2 occured");

    std::cout << "		C++				Assembly "
                 "(SSE)			Difference\n";
    std::cout << "=========================================================\n\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << " | " << res2[i];
        std::cout << " | " << res1[i];
        std::cout << " | " << (res1[i] - res2[i]) << "\n";
    }
    std::cout << "=========================================================\n\n";
    std::cout << "\n"
              << "Elapsed (C++): " << elapsed_cpp;
    std::cout << "\n"
              << "Elapsed (Assembly): " << elapsed_asm << "\n";

    avx2_utility::aligned_free(x);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

#endif ///_BASIC_FUNCTIONS_ET
