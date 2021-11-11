#pragma once
#if !defined(_SPECIAL_FUNCTIONS_ET)
#define _SPECIAL_FUNCTIONS_ET

#include <avx2_math_x86_lib.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <new>
#include <random>

#include "macros/avx2_macros.h"

using namespace avx2_specials;

void testBasicErfAVX2Double()
{

    int const n = 16 + 4;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = avx2_constants::pi<double>();

    x[0] = -1.0;
    x[1] = -0.99;
    x[2] = -0.89;
    x[3] = -0.79;
    x[4] = -0.69;
    x[5] = -0.5;
    x[6] = -0.45;
    x[7] = -0.32;
    x[8] = 0.0;
    x[9] = 0.32;
    x[10] = 0.45;
    x[11] = 0.5;
    x[12] = 0.69;
    x[13] = 0.79;
    x[14] = 0.89;
    x[15] = 1.1;
    x[16] = 1.45;
    x[17] = 2.5;
    x[18] = -2.69;
    x[19] = 1.79;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = erf_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::erf(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed error function SSE occured");

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

void testBasicErfAVX2Float()
{

    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = avx2_constants::pi<float>();

    x[0] = -1.0f;
    x[1] = -0.99f;
    x[2] = -0.89f;
    x[3] = -0.79f;
    x[4] = -0.69f;
    x[5] = -0.5f;
    x[6] = -0.45f;
    x[7] = -0.32f;
    x[8] = 0.0f;
    x[9] = 0.32f;
    x[10] = 0.45f;
    x[11] = 0.5f;
    x[12] = 0.69f;
    x[13] = 0.79f;
    x[14] = 0.89f;
    x[15] = 1.1f;
    x[16] = 1.45f;
    x[17] = 2.5f;
    x[18] = -2.69f;
    x[19] = 1.79f;
    x[20] = 5.89f;
    x[21] = -5.1f;
    x[22] = 10.1f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = erf_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::erf(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed error function SSE occured");

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

void testBasicErfcAVX2Double()
{

    int const n = 16 + 4;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = avx2_constants::pi<double>();

    x[0] = -1.0;
    x[1] = -0.99;
    x[2] = -0.89;
    x[3] = -0.79;
    x[4] = -0.69;
    x[5] = -0.5;
    x[6] = -0.45;
    x[7] = -0.32;
    x[8] = 0.0;
    x[9] = 0.32;
    x[10] = 0.45;
    x[11] = 0.5;
    x[12] = 0.69;
    x[13] = 0.79;
    x[14] = 0.89;
    x[15] = 1.1;
    x[16] = 1.45;
    x[17] = 2.5;
    x[18] = -2.69;
    x[19] = 1.79;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = erfc_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::erfc(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed complementary error function SSE occured");

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

void testBasicErfcAVX2Float()
{

    int const n = 16 + 7; // + 1;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = avx2_constants::pi<float>();

    x[0] = -1.0f;
    x[1] = -0.99f;
    x[2] = -0.89f;
    x[3] = -0.79f;
    x[4] = -0.69f;
    x[5] = -0.5f;
    x[6] = -0.45f;
    x[7] = -0.32f;
    x[8] = 0.0f;
    x[9] = 0.32f;
    x[10] = 0.45f;
    x[11] = 0.5f;
    x[12] = 0.69f;
    x[13] = 0.79f;
    x[14] = 0.89f;
    x[15] = 1.1f;
    x[16] = 1.45f;
    x[17] = 2.5f;
    x[18] = -2.69f;
    x[19] = 1.79f;
    x[20] = 5.89f;
    x[21] = -5.1f;
    x[22] = 10.1f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = erfc_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = std::erfc(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed complementary error function SSE occured");

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

void testBasicExpintAVX2Double()
{
    int const n = 16 + 4;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = avx2_constants::pi<double>();

    x[0] = 1.0;
    x[1] = 0.99;
    x[2] = 0.89;
    x[3] = 0.79;
    x[4] = 0.69;
    x[5] = 0.5;
    x[6] = 0.45;
    x[7] = 0.32;
    x[8] = 0.0;
    x[9] = 1.32;
    x[10] = 1.45;
    x[11] = 1.5;
    x[12] = 1.69;
    x[13] = 1.79;
    x[14] = 1.89;
    x[15] = 1.1;
    x[16] = 2.45;
    x[17] = 2.5;
    x[18] = -2.69;
    x[19] = 1.79;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = expint_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = -1.0 * std::expint(-1.0 * x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed exponential integral function SSE occured");

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

void testBasicExpintAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // test some basic known values:
    const float pi = avx2_constants::pi<float>();

    x[0] = 1.0f;
    x[1] = 0.99f;
    x[2] = 0.89f;
    x[3] = 0.79f;
    x[4] = 0.69f;
    x[5] = 0.5f;
    x[6] = 0.45f;
    x[7] = 0.32f;
    x[8] = 0.0f;
    x[9] = 1.32f;
    x[10] = 1.45f;
    x[11] = 1.5f;
    x[12] = 1.69f;
    x[13] = 1.79f;
    x[14] = 1.89f;
    x[15] = 1.1f;
    x[16] = 1.45f;
    x[17] = 2.5f;
    x[18] = -2.69f;
    x[19] = 10.79f;
    x[20] = 5.89f;
    x[21] = 50.1f;
    x[22] = 10.1f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = expint_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = -1.0f * std::expint(-1.0 * x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed exponential integral function SSE occured");

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
#endif ///_SPECIAL_FUNCTIONS_ET
