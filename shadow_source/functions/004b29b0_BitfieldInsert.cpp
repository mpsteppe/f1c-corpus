// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B29B0
// Canonical corpus name: BitfieldInsert
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldInsert_004b29b0.c

void UnknownObject::BitfieldInsert()
{
    // Multiplies the input float by 31.0 (scale constant read from module global flt_5ACCD0), truncates to unsigned 8-bit, shifts left 12 bits, and XOR-merges a 5-bit value into bits 12-16 (mask 0x1F000) of the bitfield dword at this+0x2C, preserving all other bits; returns the computed field value. Trivial thiscall bitfield insert with no calls; per-frame callers include vehicle orientation, setup-car-lighting/render and audio cross-fade paths.
    // CALCULATION: Multiply input float a2 by 31.0 into v4; the 31.0 scale constant is backed by read-only module global flt_5ACCD0 per the deterministic facts [global:0x005ACCD0, source:raw]
    // CALCULATION: Truncate the scaled float to unsigned 8-bit and shift left 12 bits into the target field (field = (unsigned __int8)(int)v4 << 12) [source:raw]
    // CALCULATION: Isolate the target region by XORing the current dword with the shifted field and masking with 0x1F000 (result = (v2 ^ field) & 0x1F000) [source:raw]
    // ASSIGNMENT: Merge the computed region back into the bitfield dword at this+0x2C via XOR (this[11] = result ^ v2), replacing the 5-bit field while preserving all other bits [field:this:0x0000002C, source:raw]
    // RETURN: Return the computed field value [function:0x004B29B0, source:raw]

    // Conservative worker pseudocode:
    //   int current = this[11];
    //   unsigned int field = ((unsigned __int8)(int)(a2 * 31.0f)) << 12;
    //   int result = (current ^ field) & 0x1F000;
    //   this[11] = result ^ current;
    //   return result;
    // UNRESOLVED: flt_5ACCD0 appears in the deterministic globals as a read while the raw source shows an inline 31.0 literal; the global is the presumed backing of the scale constant but the binding is not visible in this function's code
    // UNRESOLVED: Semantic meaning of the 5-bit packed value at this+0x2C bits 12-16 and the owner of the containing object are unidentified
}
