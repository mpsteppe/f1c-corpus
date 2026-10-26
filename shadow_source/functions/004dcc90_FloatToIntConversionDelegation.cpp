// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCC90
// Canonical corpus name: FloatToIntConversionDelegation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToIntConversionDelegation_004dcc90.c

void UnknownObject::FloatToIntConversionDelegation()
{
    // Convert screen-relative/proportional float parameters to integer coordinates using two screen-dimension globals, then delegate to sub_4DCBA0 (0x004DCBA0) with the computed integers. Screen width global dword_5D6D60 is widened to double and converted to int twice; screen height global dword_5D6D64 is converted to float and scaled by a8 before int conversion; a6 is converted directly. a4 and a5 are declared but unused in the raw source.
    // ASSIGNMENT: v10 = (double)dword_5D6D60, reading the screen-width global as double. [global:0x005D6D60, source:raw]
    // ASSIGNMENT: v12 = CRTFtol(v10): convert the width global to int for argument 4 of the delegate. [callee:0x00587BDC, source:raw]
    // ASSIGNMENT: v18 = (float)dword_5D6D64: read the screen-height global as float. [global:0x005D6D64, source:raw]
    // ASSIGNMENT: v13 = CRTFtol(v10): second int conversion of the width global for argument 5 of the delegate. [callee:0x00587BDC, source:raw]
    // CALCULATION: v14 = CRTFtol(v10 * a7): scale the width by proportional parameter a7 and convert to int. [callee:0x00587BDC, source:raw]
    // CALCULATION: v17 = CRTFtol(v18 * a8): scale the height float by proportional parameter a8 and convert to int. [callee:0x00587BDC, source:raw]
    // CALCULATION: v15 = CRTFtol(a6): convert parameter a6 directly to int. [callee:0x00587BDC, source:raw]
    // CALL: Return sub_4DCBA0(this, a2, a3, v12, v13, v15, v14, v17, a9, a10): delegate to the downstream initializer with the six converted integer coordinates plus pass-through a2, a3, a9, a10. [callee:0x004DCBA0, function:0x004DCC90, source:raw]
    // RETURN: Return the int result produced by sub_4DCBA0. [function:0x004DCC90, source:raw]
    // CALL: Called by UtilityFunction_cfb0 (0x004DCFB0), presumably to build screen-space layout integers for a texture/object from proportional parameters. [caller:0x004DCFB0, source:raw]

    // Conservative worker pseudocode:
    //   int FloatToIntConversionDelegation(int this, int a2, int a3,
    //       float a4, float a5, float a6, float a7, float a8, int a9, int a10) {
    //     double w = (double)dword_5D6D60;
    //     int w1 = CRTFtol(w);
    //     float h = (float)dword_5D6D64;
    //     int w2 = CRTFtol(w);
    //     int y1 = CRTFtol(w * a7);
    //     int y2 = CRTFtol(h * a8);
    //     int x = CRTFtol(a6);
    //     return sub_4DCBA0(this, a2, a3, w1, w2, x, y1, y2, a9, a10);
    //   }
    // UNRESOLVED: Parameters a4 and a5 are declared in the prototype but never referenced in the raw source.
    // UNRESOLVED: Semantic meaning of pass-through arguments a2, a3, a9, a10 is only defined by the downstream sub_4DCBA0 (0x004DCBA0).
    // UNRESOLVED: The exact role of each converted coordinate (w1, w2, x, y1, y2) in sub_4DCBA0 is not visible here.
}
