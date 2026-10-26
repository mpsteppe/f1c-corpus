// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E21D0
// Canonical corpus name: ColorAlphaUpdateFlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ColorAlphaUpdateFlagSet_004e21d0.c

void UnknownObject::ColorAlphaUpdateFlagSet()
{
    // Computes a packed ARGB color value from an alpha parameter (alpha = CRTFtol(a2 * 254.0 + 0.5), packed into the top byte with the low 24 bits set to 0xFFFFFF), writes that color into the offset 0x18 field of every element of the packed color-data array behind a1, then sets dirty flag bit 0x10000000 on the flag word at a1+0x14 and returns the updated flag word.
    // CALCULATION: Quantize the alpha parameter with CRTFtol(a2 * 254.0 + 0.5), shift it left 24 bits and OR with 0xFFFFFF to build the packed ARGB color value v2. [callee:0x00587BDC, source:raw]
    // CALL: Obtain the element count v3 of the packed color-data array via PackedArrayTotalSize(a1). [callee:0x0054E100, source:raw]
    // LOOP: Iterate i from 0 while i < v3; each iteration resolves the element pointer via PackedArrayIndexLookup(i) and writes the packed color v2 to its offset 0x18 field. [callee:0x0054E120, source:raw]
    // ASSIGNMENT: Write the packed ARGB color v2 into the offset 0x18 dword of each resolved packed-array element. [source:raw]
    // STATE_TRANSITION: Read the flag word at a1+0x14, OR it with 0x10000000 to mark the color-alpha update, and write the result back. [field:this:0x00000014, source:raw]
    // RETURN: Return the updated flag word. [source:raw]

    // Conservative worker pseudocode:
    //   v2 = (CRTFtol(a2 * 254.0 + 0.5) << 24) | 0xFFFFFF;
    //   v3 = PackedArrayTotalSize(a1);
    //   for (i = 0; i < v3; i++) {
    //       v5 = PackedArrayIndexLookup(i);
    //       *(DWORD *)(v5 + 0x18) = v2;
    //   }
    //   result = *(DWORD *)(a1 + 0x14) | 0x10000000;
    //   *(DWORD *)(a1 + 0x14) = result;
    //   return result;
    // UNRESOLVED: The packet facts list globals flt_59E450 and flt_5ACEC4 as referenced, but neither appears in the reconstructed raw body; their role in this function is unclear.
    // UNRESOLVED: The packed-array element type and the exact meaning of the offset 0x18 color field (ARGB ordering assumed from the 0xFFFFFF low 24 bits) are inferred.
    // UNRESOLVED: The flag bit 0x10000000 is treated as a dirty/update marker per the prior analysis; no independent source confirms the flag semantics.
}
