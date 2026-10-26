// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2930
// Canonical corpus name: FloatToBitfieldPack
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToBitfieldPack_004b2930.c

void UnknownObject::FloatToBitfieldPack()
{
    // Multiplies the input float by 10.0 (scale constant read from module global flt_59E5FC), truncates to int, clamps to [0, 0x7FFF], shifts left 17 bits, and merges the result into bits 17-31 of the bitfield dword at this+0x2C, preserving the low 17 bits; returns the packed value. Trivial thiscall packer with no calls; per-frame callers include vehicle orientation, setup-car-lighting/render and audio cross-fade paths.
    // CALCULATION: Multiply input float a2 by 10.0 into v4; the 10.0 scale constant is backed by read-only module global flt_59E5FC per the deterministic facts [global:0x0059E5FC, source:raw]
    // CALCULATION: Truncate the scaled float to int (v2 = (int)v4) [source:raw]
    // GUARD: Clamp lower bound: if v2 < 0, set v2 = 0 so negative inputs saturate to zero [source:raw]
    // GUARD: Clamp upper bound: if v2 > 0x7FFF, set v2 = 0x7FFF (saturate to 15-bit maximum) [source:raw]
    // CALCULATION: Shift the clamped value left 17 bits into bits 17-31 (result = v2 << 17) [source:raw]
    // ASSIGNMENT: Merge the packed value into the bitfield dword at this+0x2C while preserving the low 17 bits (this[11] = result | (this[11] & 0x1FFFF)) [field:this:0x0000002C, source:raw]
    // RETURN: Return the packed value [function:0x004B2930, source:raw]

    // Conservative worker pseudocode:
    //   int scaled = (int)(a2 * 10.0f);
    //   if (scaled < 0) scaled = 0;
    //   else if (scaled > 0x7FFF) scaled = 0x7FFF;
    //   int packed = scaled << 17;
    //   this[11] = packed | (this[11] & 0x1FFFF);
    //   return packed;
    // UNRESOLVED: flt_59E5FC appears in the deterministic globals as a read while the raw source shows an inline 10.0 literal; the global is the presumed backing of the scale constant but the binding is not visible in this function's code
    // UNRESOLVED: Semantic meaning of the packed 15-bit value and the owner of the containing object are unidentified
}
