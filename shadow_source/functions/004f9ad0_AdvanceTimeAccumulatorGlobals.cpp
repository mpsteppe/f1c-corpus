// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9AD0
// Canonical corpus name: ArithmeticComparison_9ad0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_9ad0_004f9ad0.c

void UnknownObject::AdvanceTimeAccumulatorGlobals()
{
    // Reads a delta value from sub_556730(0) into dbl_8AFE90, copies it into dbl_8AFE98, and accumulates it into two further double globals dbl_8AFEA0 and dbl_8AFEA8. Returns the low DWORD of the delta as the integer result. Called by AutoJoinRetryLoop (004637A0) and Options_Setup (004A0EB0).
    // CALL: Fetch the shared delta value: dbl_8AFE90 = sub_556730(0). [callee:0x00556730, global:0x008AFE90, source:raw]
    // CALCULATION: Capture the fetched value into v1 and set result = LODWORD(v1), the low DWORD of the delta. [global:0x008AFE90, source:raw]
    // ASSIGNMENT: Copy the delta into the paired accumulator: dbl_8AFE98 = dbl_8AFE90. [global:0x008AFE98, global:0x008AFE90, source:raw]
    // CALCULATION: Accumulate the delta into dbl_8AFEA0: dbl_8AFEA0 = dbl_8AFEA0 + dbl_8AFE90. [global:0x008AFEA0, global:0x008AFE90, source:raw]
    // CALCULATION: Accumulate the delta into dbl_8AFEA8: dbl_8AFEA8 = dbl_8AFEA8 + dbl_8AFE90. [global:0x008AFEA8, global:0x008AFE90, source:raw]
    // RETURN: Return result, the low DWORD of the fetched delta value. [source:raw]

    // Conservative worker pseudocode:
    //   dbl_8AFE90 = sub_556730(0);
    //   double delta = dbl_8AFE90;
    //   int result = LODWORD(delta);
    //   dbl_8AFE98 = dbl_8AFE90;
    //   dbl_8AFEA0 = dbl_8AFEA0 + dbl_8AFE90;
    //   dbl_8AFEA8 = dbl_8AFEA8 + dbl_8AFE90;
    //   return result;
    // UNRESOLVED: dword_8AFE64 is flagged read-only by packet facts but never appears in the raw decompiled source; its role in this function is not verifiable.
    // UNRESOLVED: byte_8AFE94 and byte_8AFE9C lie inside the storage of the adjacent double globals dbl_8AFE90 and dbl_8AFE98 (8-byte doubles); they have no independent packet-visible role and likely overlap the high/low words.
    // UNRESOLVED: The purpose of the three accumulator globals and whether sub_556730(0) returns a frame-delta or an absolute value is unknown.
}
