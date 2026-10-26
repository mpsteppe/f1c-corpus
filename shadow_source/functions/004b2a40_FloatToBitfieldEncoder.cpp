// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2A40
// Canonical corpus name: FloatToBitfieldEncoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToBitfieldEncoder_004b2a40.c

void UnknownObject::FloatToBitfieldEncoder()
{
    // Multiplies the input float by 63.0 (scale constant read from module global flt_5ACCD8), truncates to unsigned 8-bit, subtracts a 64 bias and masks to 7 bits, then merges the biased 7-bit signed value into bits 0-6 of the bitfield dword at this+0x2C, clearing bits 0-6 and preserving bits 7-31; returns the new dword. Trivial thiscall encoder with no calls; per-frame callers include setup-car-lighting/render and audio cross-fade paths.
    // CALCULATION: Multiply input float a2 by 63.0 into v3; the 63.0 scale constant is backed by read-only module global flt_5ACCD8 per the deterministic facts [global:0x005ACCD8, source:raw]
    // CALCULATION: Truncate the scaled float to unsigned 8-bit, subtract the 64 bias and mask to 7 bits (biased = ((unsigned __int8)(int)v3 - 64) & 0x7F) [source:raw]
    // ASSIGNMENT: Clear bits 0-6 of the bitfield dword at this+0x2C and merge the biased value in, preserving bits 7-31 (this[11] = (this[11] & 0xFFFFFF80) | biased) [field:this:0x0000002C, source:raw]
    // RETURN: Return the new bitfield dword [function:0x004B2A40, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int biased = ((unsigned __int8)(int)(a2 * 63.0f) - 64) & 0x7F;
    //   unsigned int result = (this[11] & 0xFFFFFF80) | biased;
    //   this[11] = result;
    //   return result;
    // UNRESOLVED: flt_5ACCD8 appears in the deterministic globals as a read while the raw source shows an inline 63.0 literal; the global is the presumed backing of the scale constant but the binding is not visible in this function's code
    // UNRESOLVED: Semantic meaning of the 7-bit biased signed value and the owner of the containing object are unidentified
}
