// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B29F0
// Canonical corpus name: ShortComputation_29f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_29f0_004b29f0.c

void UnknownObject::readScaled5BitField()
{
    // Extracts a 5-bit field from bits 12-16 of the dword at this+0x2C, shifts right by 12, masks with 0x1F, and scales the integer result by 0.032258064 (1/31) to produce a double. Trivial thiscall getter/decoder; no guards and no calls.
    // CALCULATION: Read dword at this+0x2C, shift right by 12 and mask with 0x1F to isolate the 5-bit packed value [field:this:0x0000002C, source:raw]
    // CALCULATION: Multiply the extracted integer by 0.032258064 (scale factor at flt_5ACCD4) to produce the double result [global:0x005ACCD4, source:raw]
    // RETURN: Return the scaled value as a double [function:0x004B29F0, source:raw]

    // Conservative worker pseudocode:
    //   double result = (double)((this[0x2C] >> 12) & 0x1F) * 0.032258064;
    //   return result;
    // UNRESOLVED: Semantic meaning of the 5-bit packed value at this+0x2C bits 12-16 is unknown.
    // UNRESOLVED: Owner of this function (containing object) is unidentified.
}
