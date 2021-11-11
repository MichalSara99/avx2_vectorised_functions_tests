#include <iostream>
#include <string>

// EXTERNAL TESTS
#include "external_tests/basic_functions_et.h"
#include "external_tests/basic_operations_et.h"
#include "external_tests/exp_functions_et.h"
#include "external_tests/hyp_functions_et.h"
#include "external_tests/log_functions_et.h"
//#include "external_tests/normal_dist_functions_et.h"
#include "external_tests/special_functions_et.h"
#include "external_tests/trig_functions_et.h"

int main(int argc, char const *argv[])
{

    /// ==========================================================
    /// ============== AVX  EXTERNAL TESTS =======================
    /// ==========================================================

    // ===================================================
    // ============= basic_operations_et.h ===============

    // testBasicAddAVX2Double();                // -- checked
    // testBasicAddAVX2Float();                 // -- checked
    // testBasicAddBroadAVX2Double();           // -- checked
    // testBasicAddBroadAVX2Float();            // -- checked
    // testBasicSubAVX2Double();                // -- checked
    // testBasicSubAVX2Float();                 // -- checked
    // testBasicSubBroad1AVX2Double();          // -- checked
    // testBasicSubBroad1AVX2Float();           // -- checked
    // testBasicSubBroad2AVX2Double();          // -- checked
    // testBasicSubBroad2AVX2Float();           // -- checked
    // testBasicMulAVX2Double();                // -- checked
    // testBasicMulAVX2Float();                 // -- checked
    // testBasicMulBroadAVX2Double();           // -- checked
    // testBasicMulBroadAVX2Float();            // -- checked
    // testBasicDivAVX2Double();       // -- checked
    // testBasicDivAVX2Float();        // -- checked
    // testBasicDivBroad1AVX2Double(); // -- checked
    // testBasicDivBroad1AVX2Float();  // -- checked
    // testBasicDivBroad2AVX2Double(); // -- checked
    // testBasicDivBroad2AVX2Float();  // -- checked
    // testBasicInvAVX2Double(); // -- checked
    // testBasicInvAVX2Float();  // -- checked
    // testBasicNegAVX2Double(); // -- checked
    // testBasicNegAVX2Float();  // -- checked

    // ===================================================
    // ============== basic_functions_et.h ===============

    // testBasicAbsAVX2Double();  // -- checked
    // testBasicAbsAVX2Float();   // -- checked
    // testBasicSqrtAVX2Double(); // -- checked
    // testBasicSqrtAVX2Float();  // -- checked
    // testBasicSqrpAVX2Double(); // -- checked
    // testBasicSqrpAVX2Float();  // -- checked
    // testBasicMinAVX2Double(); // -- checked
    // testBasicMinAVX2Float();  // -- checked
    // testBasicMinBroadAVX2Double(); // -- checked
    // testBasicMinBroadAVX2Float();  // -- checked
    // testBasicMaxAVX2Double(); // -- checked
    // testBasicMaxAVX2Float();  // -- checked
    // testBasicMaxBroadAVX2Double(); // -- checked
    // testBasicMaxBroadAVX2Float();  // -- checked

    // ===================================================
    // ================ hyp_functions_et.h ===============

    // testBasicCoshAVX2Double();   // -- checked
    // testBasicCoshAVX2Float();    // -- checked
    // testBasicSinhAVX2Double();   // -- checked
    // testBasicSinhAVX2Float();    // -- checked
    // testBasicTanhAVX2Double();   // -- checked
    // testBasicTanhAVX2Float();    // -- checked

    // ==================================================

    // ===================================================
    // ================ trig_functions_et.h ===============

    // testBasicSinAVX2Double();    //-- checked
    // testBasicSinAVX2Float();     //-- checked
    // testBasicCosAVX2Double();    //-- checked
    // testBasicCosAVX2Float();     //-- checked
    // testBasicTanAVX2Float();     //-- checked
    // testBasicTanAVX2Double();    //-- checked
    // testBasicCotAVX2Float();     //-- checked
    // testBasicCotAVX2Double();    //-- checked
    // testBasicAsinAVX2Double();   //-- checked
    // testBasicAsinAVX2Float();    //-- checked
    // testBasicAcosAVX2Double();   //-- checked
    // testBasicAcosAVX2Float();    //-- checked
    // testBasicAtanAVX2Double();   //-- checked
    // testBasicAtanAVX2Float();    //-- checked

    // ==================================================

    // ==================================================
    // ================ exp_functions_et.h ===============

    // testBasicExpAVX2Double();    // -- checked
    // testBasicExpAVX2Float();     // -- checked
    // testBasicPow2nAVX2Double();  // -- checked
    // testBasicPow2nAVX2Float();   // -- checked
    // testBasicExpmAVX2Double();   // -- checked
    // testBasicExpmAVX2Float();    // -- checked

    // ==================================================

    // ==================================================
    // ================ log_functions_et.h ===============

    // testBasicLogAVX2Float();     // -- checked
    // testBasicLogAVX2Double();    // -- checked (make nan mask for negatives)

    // ==================================================

    // ==================================================
    // ============ special_functions_et.h ==============

    // testBasicErfAVX2Float();     // -- checked
    // testBasicErfAVX2Double();    // -- checked
    // testBasicErfcAVX2Float();    // -- checked
    // testBasicErfcAVX2Double();   // -- checked
    // testBasicExpintAVX2Float();  //-- checked
    // testBasicExpintAVX2Double(); //-- checked

    // ==================================================

    std::cin.get();
    std::cin.get();
    return 0;
}
