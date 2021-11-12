#if !defined(_SEMD_FUNCTIONS_H_)
#define _SEMD_FUNCTIONS_H_

#include "macros/avx2_macros.h"
#include "semd.h"

// BASIC MATH OPERATIONS

template <alignment align, typename fp_type>
semd<align, fp_type> operator+(semd<align, fp_type> const &x, semd<align, fp_type> const &y)
{
    AVX2_ASSERT(x.size() == y.size(), "Sizes of the x and y must not differ.");
    semd<align, fp_type> out(x.size());
    AVX2_ASSERT(avx2_basics::add_avx2<fp_type>(x.raw_data(), y.raw_data(), out.raw_data(), x.size()) == true,
                "Error inside add_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator+(semd<align, fp_type> const &x, fp_type const y)
{
    semd<align, fp_type> out(x.size());
    AVX2_ASSERT(avx2_basics::add_broad_avx2<fp_type>(x.raw_data(), y, out.raw_data(), x.size()) == true,
                "Error inside add_broad_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator+(fp_type const x, semd<align, fp_type> const &y)
{
    semd<align, fp_type> out(y.size());
    AVX2_ASSERT(avx2_basics::add_broad_avx2<fp_type>(y.raw_data(), x, out.raw_data(), y.size()) == true,
                "Error inside add_broad_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator-(semd<align, fp_type> const &x, semd<align, fp_type> const &y)
{
    AVX2_ASSERT(x.size() == y.size(), "Sizes of the x and y must not differ.");
    semd<align, fp_type> out(x.size());
    AVX2_ASSERT(avx2_basics::sub_avx2<fp_type>(x.raw_data(), y.raw_data(), out.raw_data(), x.size()) == true,
                "Error inside sub_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator-(semd<align, fp_type> const &x, fp_type const y)
{
    semd<align, fp_type> out(x.size());
    AVX2_ASSERT(avx2_basics::sub_broad_avx2<fp_type>(x.raw_data(), y, out.raw_data(), x.size()) == true,
                "Error inside sub_broad_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator-(fp_type const x, semd<align, fp_type> const &y)
{
    semd<align, fp_type> out(y.size());
    AVX2_ASSERT(avx2_basics::sub_broad_avx2<fp_type>(x, y.raw_data(), out.raw_data(), y.size()) == true,
                "Error inside sub_broad_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator*(semd<align, fp_type> const &x, semd<align, fp_type> const &y)
{
    AVX2_ASSERT(x.size() == y.size(), "Sizes of the x and y must not differ.");
    semd<align, fp_type> out(x.size());
    AVX2_ASSERT(avx2_basics::mul_avx2<fp_type>(x.raw_data(), y.raw_data(), out.raw_data(), x.size()) == true,
                "Error inside mul_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator*(semd<align, fp_type> const &x, fp_type const y)
{
    semd<align, fp_type> out(x.size());
    AVX2_ASSERT(avx2_basics::mul_broad_avx2<fp_type>(x.raw_data(), y, out.raw_data(), x.size()) == true,
                "Error inside mul_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator*(fp_type const x, semd<align, fp_type> const &y)
{
    semd<align, fp_type> out(y.size());
    AVX2_ASSERT(avx2_basics::mul_broad_avx2<fp_type>(y.raw_data(), x, out.raw_data(), y.size()) == true,
                "Error inside mul_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator/(semd<align, fp_type> const &x, semd<align, fp_type> const &y)
{
    AVX2_ASSERT(x.size() == y.size(), "Sizes of the x and y must not differ.");
    semd<align, fp_type> out(x.size());
    AVX2_ASSERT(avx2_basics::div_avx2<fp_type>(x.raw_data(), y.raw_data(), out.raw_data(), x.size()) == true,
                "Error inside div_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator/(semd<align, fp_type> const &x, fp_type const y)
{
    semd<align, fp_type> out(x.size());
    AVX2_ASSERT(avx2_basics::div_broad_avx2<fp_type>(x.raw_data(), y, out.raw_data(), x.size()) == true,
                "Error inside div_broad_avx2");
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> operator/(fp_type const x, semd<align, fp_type> const &y)
{
    semd<align, fp_type> out(y.size());
    AVX2_ASSERT(avx2_basics::div_broad_avx2<fp_type>(x, y.raw_data(), out.raw_data(), y.size()) == true,
                "Error inside div_broad_avx2");
    return std::move(out);
}

// BASIC MATH FUNCTIONS

template <alignment align, typename fp_type> semd<align, fp_type> abs(semd<align, fp_type> const &x)
{
    semd<align, fp_type> out(x.size());
    avx2_basics::abs_avx2<fp_type>(x.raw_data(), out.raw_data(), x.size());
    return std::move(out);
}

template <alignment align, typename fp_type> semd<align, fp_type> sqrt(semd<align, fp_type> const &x)
{
    semd<align, fp_type> out(x.size());
    avx2_basics::sqrt_avx2<fp_type>(x.raw_data(), out.raw_data(), x.size());
    return std::move(out);
}

template <alignment align, typename fp_type> semd<align, fp_type> sqrp(semd<align, fp_type> const &x)
{
    semd<align, fp_type> out(x.size());
    avx2_basics::sqrp_avx2<fp_type>(x.raw_data(), out.raw_data(), x.size());
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> min(semd<align, fp_type> const &x, semd<align, fp_type> const &y)
{
    AVX2_ASSERT(x.size() == y.size(), "Sizes of the x and y must not differ.");
    semd<align, fp_type> out(x.size());
    avx2_basics::min_avx2<fp_type>(x.raw_data(), y.raw_data(), out.raw_data(), x.size());
    return std::move(out);
}

template <alignment align, typename fp_type> semd<align, fp_type> min(semd<align, fp_type> const &x, fp_type const y)
{
    semd<align, fp_type> out(x.size());
    avx2_basics::min_avx2<fp_type>(x.raw_data(), y, out.raw_data(), x.size());
    return std::move(out);
}

template <alignment align, typename fp_type> semd<align, fp_type> min(fp_type const x, semd<align, fp_type> const &y)
{
    semd<align, fp_type> out(y.size());
    avx2_basics::min_avx2<fp_type>(y.raw_data(), x, out.raw_data(), y.size());
    return std::move(out);
}

template <alignment align, typename fp_type>
semd<align, fp_type> max(semd<align, fp_type> const &x, semd<align, fp_type> const &y)
{
    AVX2_ASSERT(x.size() == y.size(), "Sizes of the x and y must not differ.");
    semd<align, fp_type> out(x.size());
    avx2_basics::max_avx2<fp_type>(x.raw_data(), y.raw_data(), out.raw_data(), x.size());
    return std::move(out);
}

template <alignment align, typename fp_type> semd<align, fp_type> max(semd<align, fp_type> const &x, fp_type const y)
{
    semd<align, fp_type> out(x.size());
    avx2_basics::max_avx2<fp_type>(x.raw_data(), y, out.raw_data(), x.size());
    return std::move(out);
}

template <alignment align, typename fp_type> semd<align, fp_type> max(fp_type const x, semd<align, fp_type> const &y)
{
    semd<align, fp_type> out(y.size());
    avx2_basics::max_avx2<fp_type>(y.raw_data(), x, out.raw_data(), y.size());
    return std::move(out);
}

// ELEMENTARY MATH FUNCTIONS

#endif ///_SEMD_FUNCTIONS_H_
