// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005975F4
// Canonical corpus name: F_96BitRightShift
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_96BitRightShift_005975f4.c

void UnknownObject::RightShift96Bit()
{
    // Right-shifts an in-place 96-bit value by one bit. The value is three consecutive dwords at this+0, this+4 and this+8 (little-endian: low, middle, high). The low dword is rebuilt as (old middle dword << 31) | (old low dword >> 1), the middle dword as a 64-bit right shift of the (middle, high) pair, and the high dword as old high >> 1, thereby propagating each carry bit between dwords. Returns the original pointer to the 96-bit value.
    // CALCULATION: Save the three dwords of the 96-bit value: high dword read from this+8 into v2, middle dword from this+4 into v3, and the pointer kept as the result [field:this:0x00000008, field:this:0x00000004, source:raw]
    // CALCULATION: Middle dword becomes a 64-bit right shift by 1 of the (middle, high) dword pair: the bit shifted out of the middle dword (its low bit) is replaced by the bit shifted in from the high dword [field:this:0x00000004, source:raw]
    // CALCULATION: Low dword rebuilt as (old middle dword << 31) OR (old low dword >> 1), folding the middle dword's low carry bit into the top of the low dword [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALCULATION: High dword shifted right by 1 and written back to this+8; the rebuilt low dword written to this+0 [field:this:0x00000008, field:this:0x00000000, source:raw]
    // RETURN: Return the unchanged pointer to the 96-bit value; the shift is invoked by sub_5976E8 and sub_597AA0 [function:0x005975F4, caller:0x005976E8, caller:0x00597AA0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = a1[2]; v3 = a1[1];
    //   a1[1] = (uint64)(a1[1], a1[2]) >> 1;
    //   a1[0] = (v3 << 31) | ((uint32)a1[0] >> 1);
    //   a1[2] = v2 >> 1;
    //   return a1;
    // UNRESOLVED: The semantic role of the 96-bit value (what the caller's long-precision counter or timestamp represents) is not documented in this packet; the two callers sub_5976E8 and sub_597AA0 would need to be read to resolve it
    // UNRESOLVED: The cluster prelabel names a structural twin TripleFieldSetter_6280 (00456280), but the raw source unambiguously shows a bit-shift rather than a triple field assignment; the twin relation was not verified
}
