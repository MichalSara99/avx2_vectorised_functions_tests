#if !defined(_SEMD_H_)
#define _SEMD_H_

#include <avx2_math_x86_lib.h>
#include <memory>

enum alignment : std::size_t
{
    align_16 = 16,
    align_32 = 32
};

/**
 * semd = single expression multiple data
 */
template <alignment align, typename fp_type> class semd
{
  private:
    std::size_t n_;
    fp_type *data_{nullptr};

  public:
    semd() = delete;
    semd(std::size_t const &size) : n_{size}
    {
        data_ = avx2_utilities::aligned_alloc<fp_type>(n_, static_cast<std::size_t>(align));
    }

    ~semd()
    {
        avx2_utilities::aligned_free<fp_type>(data_);
    }

    semd(semd const &) = delete;

    semd(semd &&other) noexcept : n_{std::move(other.n_)}, data_{std::move(other.data_)}
    {
        other.data_ = nullptr;
    }

    semd &operator=(semd &&other) noexcept
    {
        avx2_utilities::aligned_free<fp_type>(data_);
        n_ = std::move(other.n_);
        data_ = std::move(other.data_);
        other.data_ = nullptr;
        return *this;
    }

    semd &operator=(semd const &) = delete;

    std::size_t size() const
    {
        return n_;
    }

    fp_type *raw_data() const
    {
        return data_;
    }

    fp_type &operator[](std::size_t const &idx)
    {
        AVX2_ASSERT(idx < n_, "idx out of range");
        return data_[idx];
    }

    const fp_type operator[](std::size_t const &idx) const
    {
        AVX2_ASSERT(idx < n_, "idx out of range");
        return data_[idx];
    }
};
#endif ///_SEMD_H_
