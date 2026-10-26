// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2B40
// Canonical corpus name: BitfieldExtractionWithScale
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldExtractionWithScale_004b2b40.c

void UnknownObject::readScaled2BitField()
{
    // Extracts a 2-bit field from bits 22-23 of the dword at this+0x30, shifts right by 22, masks with 3, and scales the result by 0.33333334 (1/3) to produce a double. Trivial thiscall decoder; no guards and no calls.
    // CALCULATION: Read dword at this+0x30, shift right by 22 and mask with 3 to isolate the 2-bit encoded value [field:this:0x00000030, source:raw]
    // CALCULATION: Multiply the extracted integer by 0.33333334 (scale factor at flt_59E98C) to produce the double result [global:0x0059E98C, source:raw]
    // RETURN: Return the scaled value as a double [function:0x004B2B40, source:raw]

    // Conservative worker pseudocode:
    //   double result = (double)((this[0x30] >> 22) & 3) * 0.33333334;
    //   return result;
    // UNRESOLVED: Semantic meaning of the 2-bit field at this+0x30 bits 22-23 is unknown.
    // UNRESOLVED: Owner of this function (containing object) is unidentified.
}
