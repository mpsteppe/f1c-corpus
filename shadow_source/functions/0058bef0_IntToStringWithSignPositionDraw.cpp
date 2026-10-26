// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BEF0
// Canonical corpus name: IntToStringWithSignPositionDraw
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IntToStringWithSignPositionDraw_0058bef0.c

void UnknownObject::IntToStringWithSignPositionDraw()
{
    // Formats a double read from a1 into a localized string and draws it with sign-aware position adjustment. Loads the double, converts it via LocaleAwareStringFormat into a scratch struct and buffer, advances the x position by one column when the sign flag is the '-' character (ASCII 45), offsets y by the conversion result, draws via UtilityFunction_bf45, and returns the original x position a2.
    // ASSIGNMENT: Load v4 = *a1 as a double from the caller-provided pointer. [field:this:0x00000000, source:raw]
    // CALL: LocaleAwareStringFormat(low/high words of v4, v6, v5) converts the double into the scratch struct v6 and buffer v5. [callee:0x00595621, source:raw]
    // CALCULATION: Adjust the draw position: x becomes a2 + (v6[0] == 45) (one extra column when the sign flag is '-'), y becomes a3 + v6[1]. [source:raw]
    // CALL: sub_5955AA(a2 + (v6[0] == 45), a3 + v6[1], v6) consumes the formatted struct at the adjusted position. [callee:0x005955AA, source:raw]
    // CALL: UtilityFunction_bf45(a2, a3, v6, 0) performs the actual draw using the original position and the formatted struct. [callee:0x0058BF45, source:raw]
    // RETURN: Return a2, the original x position, to the caller (CfltcvtCRTFloatConversionDispatch). [source:raw, caller:0x0058C07F]

    // Conservative worker pseudocode:
    //   int sub_58BEF0(double *a1, int a2, int a3) {
    //     double v4 = *a1;
    //     _DWORD v6[4]; _BYTE v5[24];
    //     LocaleAwareStringFormat(LOBYTE(v4), HIDWORD(v4), v6, v5);
    //     sub_5955AA(a2 + (v6[0] == 45), a3 + v6[1], v6);
    //     UtilityFunction_bf45(a2, a3, v6, 0);
    //     return a2;
    //   }
    // UNRESOLVED: Exact roles of v6[1] (vertical offset) and v5[24] buffer are not grounded beyond the raw source.
    // UNRESOLVED: Division of labour between sub_5955AA and UtilityFunction_bf45 (both consume v6) is unclear.
    // UNRESOLVED: SetFlagIfPointerNonNull-independent: identity of the double's numeric type (a1 double*) is taken from the raw source.
}
