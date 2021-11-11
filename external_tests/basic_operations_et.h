#pragma once
#if !defined(_BASIC_OPERATIONS_ET)
#define _BASIC_OPERATIONS_ET

#include <avx2_math_x86_lib.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <new>
#include <random>

#include "macros/avx2_macros.h"

using namespace avx2_basics;

void testBasicAddAVX2Double()
{

    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *y = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = add_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] + y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed addition SSE occured");

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
    avx2_utility::aligned_free(y);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicAddAVX2Float()
{

    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *y = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = add_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] + y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed addition SSE occured");

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
    avx2_utility::aligned_free(y);
    avx2_utility::aligned_free(res1);
    avx2_utility::aligned_free(res2);
}

void testBasicAddBroadAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double y = 5.26;
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
    bool rc1 = add_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] + y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast addition SSE occured");

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

void testBasicAddBroadAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float y = 5.26f;
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
    bool rc1 = add_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] + y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast addition SSE occured");

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

void testBasicSubAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *y = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sub_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] - y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed subtraction SSE occured");

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

void testBasicSubAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *y = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sub_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] - y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed subtraction SSE occured");

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

void testBasicSubBroad1AVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double y = 3.14159;
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
    bool rc1 = sub_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] - y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast subtraction SSE occured");

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

void testBasicSubBroad1AVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float y = 3.1415f;
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
    bool rc1 = sub_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] - y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast subtraction SSE occured");

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

void testBasicSubBroad2AVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *y = avx2_utility::aligned_alloc<double>(n, align);
    double x = 3.14159;
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sub_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x - y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast subtraction SSE occured");

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

void testBasicSubBroad2AVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *y = avx2_utility::aligned_alloc<float>(n, align);
    float x = 3.1415f;
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = sub_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x - y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast subtraction SSE occured");

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

void testBasicMulAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *y = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = mul_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] * y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed multiplication SSE occured");

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

void testBasicMulAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *y = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = mul_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = y[i] * x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed multiplication SSE occured");

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

void testBasicMulBroadAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double y = 3.151492;
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
    bool rc1 = mul_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] * y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast multiplication SSE occured");

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

void testBasicMulBroadAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float y = 3.14152f;
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
    bool rc1 = mul_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = y * x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast multiplication SSE occured");

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

void testBasicDivAVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double *y = avx2_utility::aligned_alloc<double>(n, align);
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = div_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] / y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed division SSE occured");

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

void testBasicDivAVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float *y = avx2_utility::aligned_alloc<float>(n, align);
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        x[i] = uni_rnd(device);
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = div_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] / y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed division SSE occured");

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

void testBasicDivBroad1AVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *x = avx2_utility::aligned_alloc<double>(n, align);
    double y = 3.151492;
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
    bool rc1 = div_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] / y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast division SSE occured");

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

void testBasicDivBroad1AVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *x = avx2_utility::aligned_alloc<float>(n, align);
    float y = 3.14152f;
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
    bool rc1 = div_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x[i] / y;
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast division SSE occured");

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

void testBasicDivBroad2AVX2Double()
{
    int const n = 16 + 3;
    std::size_t const align = 32;

    double *y = avx2_utility::aligned_alloc<double>(n, align);
    double x = 3.151492;
    double *res1 = avx2_utility::aligned_alloc<double>(n, align);
    double *res2 = avx2_utility::aligned_alloc<double>(n, align);

    // get generator:
    std::uniform_real_distribution<double> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = div_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x / y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast division SSE occured");

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

void testBasicDivBroad2AVX2Float()
{
    int const n = 16 + 7;
    std::size_t const align = 32;

    float *y = avx2_utility::aligned_alloc<float>(n, align);
    float x = 3.14152f;
    float *res1 = avx2_utility::aligned_alloc<float>(n, align);
    float *res2 = avx2_utility::aligned_alloc<float>(n, align);

    // get generator:
    std::uniform_real_distribution<float> uni_rnd(10.5, 100.0);
    // get engine:
    std::random_device device;

    for (std::size_t i = 0; i < n; ++i)
    {
        y[i] = uni_rnd(device);
    }

    auto start_asm = std::chrono::system_clock::now();
    bool rc1 = div_broad_avx2(x, y, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = x / y[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed broadcast division SSE occured");

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

void testBasicInvAVX2Double()
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
    bool rc1 = inv_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = 1.0 / x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed inversion AVX2 occured");

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

void testBasicInvAVX2Float()
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
    bool rc1 = inv_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = 1.0f / x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed inversion AVX2 occured");

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

void testBasicNegAVX2Double()
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
    bool rc1 = neg_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = -x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed negation AVX2 occured");

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

void testBasicNegAVX2Float()
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
    bool rc1 = neg_avx2(x, n, res1);
    auto end_asm = std::chrono::system_clock::now();
    auto elapsed_asm = std::chrono::duration<double>(end_asm - start_asm).count();

    auto start_cpp = std::chrono::system_clock::now();
    for (int i = 0; i < n; ++i)
    {
        res2[i] = -x[i];
    }
    auto end_cpp = std::chrono::system_clock::now();
    auto elapsed_cpp = std::chrono::duration<double>(end_cpp - start_cpp).count();

    AVX2_ASSERT(rc1 == 1, "Failure in packed negation AVX2 occured");

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
#endif ///_BASIC_OPERATIONS_ET
