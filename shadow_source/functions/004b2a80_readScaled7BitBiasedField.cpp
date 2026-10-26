// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2A80
// Canonical corpus name: BitfieldToFloatConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldToFloatConversion_004b2a80.c

void UnknownObject::readScaled7BitBiasedField()
{
    // Extracts the low 7 bits of the dword at this+0x2C, subtracts bias 64, and scales the result by 0.015873017 (1/63) to produce a double. Trivial thiscall decoder; no guards and no calls.
    // CALCULATION: Read dword at this+0x2C, mask with 0x7F to isolate the low 7-bit biased signed value, then subtract bias 64 [field:this:0x0000002C, source:raw]
    // CALCULATION: Multiply the biased-extracted integer by 0.015873017 (scale factor at flt_5ACCDC) to produce the double result [global:0x005ACCDC, source:raw]
    // RETURN: Return the scaled value as a double [function:0x004B2A80, source:raw]

    // Conservative worker pseudocode:
    //   double result = (double)((this[0x2C] & 0x7F) - 64) * 0.015873017;
    //   return result;
    // UNRESOLVED: Semantic meaning of the 7-bit biased value at this+0x2C bits 0-6 is unknown.
    // UNRESOLVED: Owner of this function (containing object) is unidentified.
}
