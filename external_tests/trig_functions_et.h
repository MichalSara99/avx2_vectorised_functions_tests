#pragma once
#if !defined(_TRIG_FUNCTIONS_ET)
#define _TRIG_FUNCTIONS_ET

#include <avx2_math_x86_lib.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <new>
#include <random>

#include "macros/avx2_macros.h"

using namespace avx2_basics;

void testBasicSinAVX2Double()
{

    int const n = 16; //+ 1;
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
    x[16] = 4.0 * pi / 16.0;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sin_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = sin(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed cosine SSE occured");

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

void testBasicSinAVX2Float()
{

    int const n = 16; //+ 1;
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
    x[16] = 4.0f * pi / 16.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sin_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = sin(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed cosine SSE occured");

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

void testBasicCosAVX2Double()
{

    int const n = 16; // + 1;
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
    x[16] = 4.0 * pi / 2.0;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = cos_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = cos(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed cosine SSE occured");

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

void testBasicCosAVX2Float()
{

    int const n = 16; // + 1;
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
    x[16] = 4.0f * pi / 2.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = cos_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = cos(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed cosine SSE occured");

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

void testBasicTanAVX2Float()
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
    x[16] = 4.0f * pi / 6.0f;
    x[17] = -4.0f * pi / 6.0f;
    x[18] = -3.0f * pi;
    x[19] = -8.0f * pi / 2.0f;
    x[20] = -2.0f * pi;
    x[21] = pi / 8.0f;
    x[22] = -3.0f * pi / 2.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = tan_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = tan(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed tangens SSE occured");

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

void testBasicTanAVX2Double()
{
    int const n = 16 + 4;
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
    x[14] = 0.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 4.0 * pi / 6.0;
    x[17] = -4.0 * pi / 6.0;
    x[18] = -3.0 * pi;
    x[19] = -5.0 * pi / 2.0;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = tan_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = tan(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed tangens SSE occured");

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

void testBasicCotAVX2Float()
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
    x[16] = 4.0f * pi / 6.0f;
    x[17] = -4.0f * pi / 6.0f;
    x[18] = -3.0f * pi;
    x[19] = -8.0f * pi / 2.0f;
    x[20] = -2.0f * pi;
    x[21] = pi / 8.0f;
    x[22] = -3.0f * pi / 2.0f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = cot_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = 1.0f / tan(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed cotangens SSE occured");

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

void testBasicCotAVX2Double()
{
    int const n = 16 + 4;
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
    x[14] = 0.5;
    x[15] = 4.0 * pi / 3.0;
    x[16] = 4.0 * pi / 6.0;
    x[17] = -4.0 * pi / 6.0;
    x[18] = -3.0 * pi;
    x[19] = -5.0 * pi / 2.0;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = cot_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = 1.0f / tan(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed cotangens SSE occured");

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

void testBasicAsinAVX2Double()
{
    int const n = 16 + 3;
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
    x[16] = -0.32;
    x[17] = 0.056;
    x[18] = 0.015;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = asin_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = asin(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed arcus sine SSE occured");

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

void testBasicAsinAVX2Float()
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
    x[16] = -0.32f;
    x[17] = 0.056f;
    x[18] = 0.015f;
    x[19] = -0.15f;
    x[20] = -10.0f;
    x[21] = 0.75f;
    x[22] = 0.99f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = asin_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = asin(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed arcus sine SSE occured");

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

void testBasicAcosAVX2Double()
{
    int const n = 16 + 3;
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
    x[16] = -0.32;
    x[17] = 0.056;
    x[18] = 0.015;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = acos_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = acos(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed arcus cosine SSE occured");

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

void testBasicAcosAVX2Float()
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
    x[16] = -0.32f;
    x[17] = 0.056f;
    x[18] = 0.015f;
    x[19] = -0.15f;
    x[20] = -10.0f;
    x[21] = 0.75f;
    x[22] = 0.99f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = acos_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = acos(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed arcus cosine SSE occured");

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

void testBasicAtanAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // test some basic known values:
    const double pi = avx2_constants::pi<double>();

    x[0] = -1.01;
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
    x[16] = -0.32;
    x[17] = 0.056;
    x[18] = 0.015;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = atan_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = atan(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed arcus tangens SSE occured");

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

void testBasicAtanAVX2Float()
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
    x[16] = -0.32f;
    x[17] = 0.056f;
    x[18] = 0.015f;
    x[19] = -0.15f;
    x[20] = -10.0f;
    x[21] = 0.75f;
    x[22] = 0.99f;

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = atan_avx2(x, res1, n);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = atan(x[i]);
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed arcus tangens SSE occured");

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

#endif ///_TRIG_FUNCTIONS_ET
