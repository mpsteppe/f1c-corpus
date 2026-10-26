// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B25D0
// Canonical corpus name: FloatToFixedConversionWithClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToFixedConversionWithClamp_004b25d0.c

void UnknownObject::FloatToFixedConversionWithClamp()
{
    // Converts three floats from the a2 array into fixed-point fields of the object: a2[0] clamped to the byte range and scaled by the byte multiplier, stored as an 8-bit value at this+0x24; a2[1] clamped to the short range and scaled by the short multiplier, stored as a 16-bit value at this+0x26; a2[2] clamped to the byte range and scaled by the byte multiplier, stored at this+0x25 and returned. Out-of-range values clamp to signed sentinel min/max values.
    // GUARD: Two-sided range check on a2[0] against the byte-range clamp-bound globals (flt_5ACCA0 / flt_5ACCA4, literal bounds +/-6.3499999); clamp low to -127 and high to 127 when out of range. [global:0x005ACCA0, global:0x005ACCA4, source:raw]
    // CALCULATION: Within range, scale a2[0] by the byte multiplier global flt_59E8EC (literal 20.0), truncate to an 8-bit value, and store it at this+0x24. [global:0x0059E8EC, field:this:0x00000024, source:raw]
    // GUARD: Two-sided range check on a2[1] against the short-range clamp-bound globals (flt_5ACCA8 / flt_5ACCAC, literal bounds +/-65.533997); clamp low to -32767 and high to 0x7FFF when out of range. [global:0x005ACCA8, global:0x005ACCAC, source:raw]
    // CALCULATION: Within range, scale a2[1] by the short multiplier global flt_59E91C (literal 500.0), truncate to a 16-bit value, and store it at this+0x26. [global:0x0059E91C, field:this:0x00000026, source:raw]
    // GUARD: Two-sided range check on a2[2] against the same byte-range clamp bounds (literal +/-6.3499999); clamp low to -127 and high to 127 when out of range. [global:0x005ACCA0, global:0x005ACCA4, source:raw]
    // CALCULATION: Within range, scale a2[2] by the byte multiplier (literal 20.0), truncate to an 8-bit value, store it at this+0x25, and use the same value as the return result. [global:0x0059E8EC, field:this:0x00000025, source:raw]
    // RETURN: Return the clamped/scaled value derived from a2[2]. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B25D0(int obj, float *a2) {
    //     *(_BYTE*)(obj + 0x24) = clampByte((int)(a2[0] * 20.0));
    //     *(_WORD*)(obj + 0x26) = clampShort((int)(a2[1] * 500.0));
    //     int result = clampByte((int)(a2[2] * 20.0));
    //     *(_BYTE*)(obj + 0x25) = result;
    //     return result;
    //   }
    // UNRESOLVED: Which clamp-bound global pair serves which range (byte vs short) is inferred from the literal magnitudes; the exact global-to-range mapping needs external evidence.
    // UNRESOLVED: Whether the three floats represent Euler-angle components or another triple is not established from this packet alone.
}
