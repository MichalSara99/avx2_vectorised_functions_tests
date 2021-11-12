#include <iostream>
#include <string>

// EXTERNAL TESTS
#include "external_tests/basic_functions_et.h"
#include "external_tests/basic_operations_et.h"
#include "external_tests/exp_functions_et.h"
#include "external_tests/hyp_functions_et.h"
#include "external_tests/log_functions_et.h"
//#include "external_tests/normal_dist_functions_et.h"
#include "external_tests/semd_et.h"
#include "external_tests/special_functions_et.h"
#include "external_tests/trig_functions_et.h"

bool __vectorcall my_abs(double x)
{
    return std::abs(x);
}

int main(int argc, char const *argv[])
{

    /// ==========================================================
    /// ============== AVX  EXTERNAL TESTS =======================
    /// ==========================================================

    // ===================================================
    // =================== semd_et.h =====================
    // testAbs();

    // ===================================================
    // ============= basic_operations_et.h ===============

    // testBasicAddAVX2Double();     // -- checked __vect
    // testBasicAddAVX2Float();      // -- checked __vect
    // testBasicAddBroadAVX2Double(); // -- checked __vect
    // testBasicAddBroadAVX2Float();  // -- checked __vect
    // testBasicSubAVX2Double(); // -- checked __vect
    // testBasicSubAVX2Float();  // -- checked __vect
    // testBasicSubBroad1AVX2Double(); // -- checked __vect
    // testBasicSubBroad1AVX2Float();  // -- checked __vect
    // testBasicSubBroad2AVX2Double(); // -- checked __vect
    // testBasicSubBroad2AVX2Float();  // -- checked __vect
    // testBasicMulAVX2Double();      // -- checked __vect
    // testBasicMulAVX2Float();       // -- checked __vect
    // testBasicMulBroadAVX2Double(); // -- checked __vect
    // testBasicMulBroadAVX2Float();  // -- checked __vect
    // testBasicDivAVX2Double();       // -- checked __vect
    // testBasicDivAVX2Float();        // -- checked __vect
    // testBasicDivBroad1AVX2Double(); // -- checked __vect
    // testBasicDivBroad1AVX2Float();  // -- checked __vect
    // testBasicDivBroad2AVX2Double(); // -- checked __vect
    // testBasicDivBroad2AVX2Float();  // -- checked __vect
    // testBasicInvAVX2Double(); // -- checked __vect
    // testBasicInvAVX2Float();  // -- checked __vect
    // testBasicNegAVX2Double(); // -- checked __vect
    // testBasicNegAVX2Float();  // -- checked __vect

    // ===================================================
    // ============== basic_functions_et.h ===============

    // testBasicAbsAVX2Double(); // -- checked __vect
    // testBasicAbsAVX2Float();  // -- checked __vect
    // testBasicSqrtAVX2Double(); // -- checked __vect
    // testBasicSqrtAVX2Float();  // -- checked __vect
    // testBasicSqrpAVX2Double(); // -- checked __vect
    // testBasicSqrpAVX2Float();  // -- checked __vect
    // testBasicMinAVX2Double(); // -- checked __vect
    // testBasicMinAVX2Float();  // -- checked __vect
    // testBasicMinBroadAVX2Double(); // -- checked __vect
    // testBasicMinBroadAVX2Float();  // -- checked __vect
    // testBasicMaxAVX2Double(); // -- checked __vect
    // testBasicMaxAVX2Float();  // -- checked __vect
    // testBasicMaxBroadAVX2Double(); // -- checked __vect
    // testBasicMaxBroadAVX2Float();  // -- checked __vect

    // ===================================================
    // ================ hyp_functions_et.h ===============

    // testBasicCoshAVX2Double(); // -- checked __vect
    // testBasicCoshAVX2Float();  // -- checked __vect
    //  testBasicSinhAVX2Double(); // -- checked __vect
    //  testBasicSinhAVX2Float();  // -- checked __vect
    //  testBasicTanhAVX2Double(); // -- checked __vect
    //  testBasicTanhAVX2Float();  // -- checked __vect

    // ==================================================

    // ===================================================
    // ================ trig_functions_et.h ===============

    // testBasicSinAVX2Double(); //-- checked __vect
    // testBasicSinAVX2Float();  //-- checked __vect
    // testBasicCosAVX2Double(); //-- checked __vect
    // testBasicCosAVX2Float();  //-- checked __vect
    // testBasicTanAVX2Float();  //-- checked __vect
    // testBasicTanAVX2Double(); //-- checked __vect
    // testBasicCotAVX2Float();  //-- checked __vect
    // testBasicCotAVX2Double(); //-- checked __vect
    // testBasicAsinAVX2Double(); //-- checked __vect
    // testBasicAsinAVX2Float();  //-- checked __vect
    // testBasicAcosAVX2Double(); //-- checked __vect
    // testBasicAcosAVX2Float();  //-- checked __vect
    // testBasicAtanAVX2Double(); //-- checked __vect
    // testBasicAtanAVX2Float();  //-- checked __vect

    // ==================================================

    // ==================================================
    // ================ exp_functions_et.h ===============

    // testBasicExpAVX2Double(); // -- checked __vect
    // testBasicExpAVX2Float();  // -- checked __vect
    // testBasicPow2nAVX2Double(); // -- checked __vect
    // testBasicPow2nAVX2Float();  // -- checked __vect
    // testBasicExpmAVX2Double(); // -- checked __vect
    // testBasicExpmAVX2Float();  // -- checked __vect

    // ==================================================

    // ==================================================
    // ================ log_functions_et.h ===============

    // testBasicLogAVX2Float();  // -- checked __vect
    // testBasicLogAVX2Double(); // -- checked __vect (make nan mask for negatives)

    // ==================================================

    // ==================================================
    // ============ special_functions_et.h ==============

    // testBasicErfAVX2Float();   // -- checked __vect
    // testBasicErfAVX2Double();  // -- checked __vect
    // testBasicErfcAVX2Float();  // -- checked __vect
    // testBasicErfcAVX2Double(); // -- checked __vect
    // testBasicExpintAVX2Float();  //-- checked __vect
    // testBasicExpintAVX2Double(); //-- checked __vect

    // ==================================================

    std::cin.get();
    std::cin.get();
    return 0;
}
