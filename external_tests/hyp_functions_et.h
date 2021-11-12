#pragma once
#if !defined(_HYP_FUNCTIONS_ET)
#define _HYP_FUNCTIONS_ET

#include <avx2_math_x86_lib.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <new>
#include <random>

#include "macros/avx2_macros.h"

using namespace avx2_basics;

void testBasicCoshAVX2Double()
{

    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = avx2_constants::pi<double>();

    x[0] = 0.0;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 10.5;
    x[17] = -1.5;
    x[18] = -10.5;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = cosh_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::cosh(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed hyperboic cosine SSE occured");

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

void testBasicCoshAVX2Float()
{

    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = avx2_constants::pi<float>();

    x[0] = 0.0f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 10.5f;
    x[17] = -1.5f;
    x[18] = -10.5f;
    x[19] = 2.5f;
    x[20] = pi / 4.0f;
    x[21] = -5.08f;
    x[22] = 5.08f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = cosh_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::cosh(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed hyperboic cosine SSE occured");

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

void testBasicSinhAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = avx2_constants::pi<double>();

    x[0] = 0.0;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 10.5;
    x[17] = -1.5;
    x[18] = -10.5;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sinh_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::sinh(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed hyperboic sine SSE occured");

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

void testBasicSinhAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = avx2_constants::pi<float>();

    x[0] = 0.0f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 10.5f;
    x[17] = -1.5f;
    x[18] = -10.5f;
    x[19] = 2.5f;
    x[20] = pi / 4.0f;
    x[21] = -5.08f;
    x[22] = 5.08f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sinh_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::sinh(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed hyperboic sine SSE occured");

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

void testBasicTanhAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = avx2_constants::pi<double>();

    x[0] = 0.0;
    x[1] = pi / 2.0;
    x[2] = pi;
    x[3] = 3.0 * pi / 2.0;
    x[4] = 5.0 * pi / 4.0;
    x[5] = 2.0 * pi;
    x[6] = 4.0 * pi;
    x[7] = 3.0 * pi;
    x[8] = 6.0 * pi / 3.0;
    x[9] = -2.0 * pi;
    x[10] = -pi / 4.0;
    x[11] = 7.0 * pi / 4.0;
    x[12] = 0.5;
    x[13] = pi / 3.0;
    x[14] = 23.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 10.5;
    x[17] = -1.5;
    x[18] = -10.5;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = tanh_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::tanh(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed hyperboic tangens SSE occured");

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

void testBasicTanhAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = avx2_constants::pi<float>();

    x[0] = 0.0f;
    x[1] = pi / 2.0f;
    x[2] = pi;
    x[3] = 3.0f * pi / 2.0f;
    x[4] = 5.0f * pi / 4.0f;
    x[5] = 2.0f * pi;
    x[6] = 4.0f * pi;
    x[7] = 3.0f * pi;
    x[8] = 6.0f * pi / 3.0f;
    x[9] = -2.0f * pi;
    x[10] = -pi / 4.0f;
    x[11] = 7.0f * pi / 4.0f;
    x[12] = 0.5f;
    x[13] = pi / 3.0f;
    x[14] = 23.5f;
    x[15] = 4.0f * pi / 3.0f;
    x[16] = 10.5f;
    x[17] = -1.5f;
    x[18] = -10.5f;
    x[19] = 2.5f;
    x[20] = pi / 4.0f;
    x[21] = -5.08f;
    x[22] = 5.08f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = tanh_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::tanh(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed hyperboic tangens SSE occured");

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

#endif ///_HYP_FUNCTIONS_ET
