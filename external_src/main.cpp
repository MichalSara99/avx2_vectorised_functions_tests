#include <iostream>
#include <string>

// EXTERNAL TESTS
//#include "external_tests/avx_trig_functions_et.h"
//#include "external_tests/basic_functions_et.h"
//#include "external_tests/basic_operations_et.h"
#include "external_tests/exp_functions_et.h"
#include "external_tests/hyp_functions_et.h"
#include "external_tests/log_functions_et.h"
//#include "external_tests/normal_dist_functions_et.h"
//#include "external_tests/special_functions_et.h"
#include "external_tests/trig_functions_et.h"

int main(int argc, char const *argv[])
{

    /// ==========================================================
    /// ============== AVX  EXTERNAL TESTS =======================
    /// ==========================================================

    // ===================================================
    // ================ hyp_functions_et.h ===============

    // testBasicCoshAVX2Double();
    // testBasicCoshAVX2Float();

    // ==================================================

    // ===================================================
    // ================ trig_functions_et.h ===============

    // testBasicSinAVX2Double();
    // testBasicSinAVX2Float();
    // testBasicCosAVX2Double();
    // testBasicCosAVX2Float();
    // testBasicTanAVX2Float();
    // testBasicTanAVX2Double();
    // testBasicCotAVX2Float();
    // testBasicCotAVX2Double();
    // testBasicAsinAVX2Double();
    // testBasicAsinAVX2Float();
    // testBasicAcosAVX2Double();
    // testBasicAcosAVX2Float();
    // testBasicAtanAVX2Double();
    // testBasicAtanAVX2Float();

    // ==================================================

    // ==================================================
    // ================ exp_functions_et.h ===============

    // testBasicExpAVX2Double();
    // testBasicExpAVX2Float();

    // ==================================================

    // ==================================================
    // ================ log_functions_et.h ===============

    // testBasicLogAVX2Float();
    // testBasicLogAVX2Double();

    // ==================================================

    std::cin.get();
    std::cin.get();
    return 0;
}
