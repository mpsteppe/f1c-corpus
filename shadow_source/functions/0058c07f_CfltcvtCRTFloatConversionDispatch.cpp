// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C07F
// Canonical corpus name: CfltcvtCRTFloatConversionDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CfltcvtCRTFloatConversionDispatch_0058c07f.c

void UnknownObject::CfltcvtCRTFloatConversionDispatch()
{
    // Format-dispatch helper for CRT-style float-to-string conversion. Inspects the format code argument a3 and selects one of three conversion helpers: for ASCII 'e'/'E' (101/69) calls FloatToStringWithSignWidth(a1, a2, a4, a5) (exponent/scientific form); for ASCII 'f' (102) calls IntToStringWithSignPositionDraw(a1, a2, a4); otherwise falls through to the default UtilityFunction_bfec(a1, a2, a4, a5). Returns the pointer (to the resulting string buffer) produced by whichever helper ran. Owning object unknown.
    // GUARD: Guard: when a3 == 101 ('e') or a3 == 69 ('E'), take the scientific/exponent float-to-string path and return its result immediately. [callee:0x0058BDCD, source:raw]
    // CALL: Call FloatToStringWithSignWidth(a1, (int)a2, a4, a5) which formats the double a1 into the buffer a2 with sign/width handling; its returned pointer becomes the function result. [callee:0x0058BDCD, source:raw]
    // GUARD: Guard: when a3 == 102 ('f'), take the fixed-point int-with-sign path and return its result immediately. [callee:0x0058BEF0, source:raw]
    // CALL: Call IntToStringWithSignPositionDraw(a1, (int)a2, a4) which formats with sign and position (fixed) semantics; its returned pointer becomes the function result. [callee:0x0058BEF0, source:raw]
    // CALL: Fallback path: call UtilityFunction_bfec(a1, a2, a4, a5) for any format code other than 'e'/'E'/'f'; its returned pointer becomes the function result. [callee:0x0058BFEC, source:raw]
    // RETURN: Return the pointer produced by the selected conversion helper. [source:raw]

    // Conservative worker pseudocode:
    //   _BYTE *CfltcvtCRTFloatConversionDispatch(double *a1, _BYTE *a2, int a3, int a4, int a5) {
    //     if (a3 == 101 || a3 == 69)
    //       return FloatToStringWithSignWidth(a1, (int)a2, a4, a5);
    //     if (a3 == 102)
    //       return IntToStringWithSignPositionDraw(a1, (int)a2, a4);
    //     return UtilityFunction_bfec(a1, a2, a4, a5);
    //   }
    // UNRESOLVED: The exact meaning of the forwarded arguments a4 and a5 (e.g. width/precision) is not established by the packet.
    // UNRESOLVED: The purpose and behavior of the default path UtilityFunction_bfec for format codes other than 'e'/'E'/'f' is unknown.
    // UNRESOLVED: The owning object (CRT float conversion context) behind this dispatcher is unknown.
}
