#pragma once
#if !defined(_AVX2_MACROS)
#define _AVX2_MACROS

#define AVX2_ASSERT(condition, message)                                                                                \
    {                                                                                                                  \
        do                                                                                                             \
        {                                                                                                              \
            if (!(condition))                                                                                          \
            {                                                                                                          \
                std::cerr << "Assertion `" #condition "` failed in " << __FILE__ << " line " << __LINE__ << ": "       \
                          << message << std::endl;                                                                     \
                std::terminate();                                                                                      \
            }                                                                                                          \
        } while (false);                                                                                               \
    }

#endif ///_AVX2_MACROS
