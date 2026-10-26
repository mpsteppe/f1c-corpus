// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005125C9
// Canonical corpus name: BitPackingUnpacking
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitPackingUnpacking_005125c9.c

void UnknownObject::BitPackingUnpacking()
{
    // Unpacks bit-packed elements from an input buffer into per-element byte fields written backwards, driven by a bit depth read from this+0x9 (1, 2 or 4 bits per element) and an element count from this+0x0. When the depth is >= 8 the function does nothing. After the unpack (or when the depth is another value below 8) it updates packing metadata: resets this+0x9 to 8, writes this+0xB = 8 * this+0xA and this+0x4 = element count * this+0xA. Called by sub_51389E.
    // GUARD: Read the bit depth v3 from this+0x9; when v3 >= 8 the function returns immediately and neither unpacks nor updates metadata [field:this:0x00000009, source:raw]
    // ASSIGNMENT: Load the element count v4 from this+0x0 (dword) [field:this:0x00000000, source:raw]
    // LOOP: 1-bit unpack path (v3 == 1): for each of the v4 elements extract (*(src) >> (7 - ((v4-1) & 7))) & 1 into the destination bytes written backwards from a2 + v4 - 1, advancing the source byte each time the shift wraps [field:this:0x00000000, source:raw]
    // LOOP: 2-bit unpack path (v3 == 2): for each of the v4 elements extract (*(src) >> (6 - 2*((v4-1) & 3))) & 3 into the destination bytes, advancing the source when the shift wraps [field:this:0x00000000, source:raw]
    // LOOP: 4-bit unpack path (v3 == 4): for each of the v4 elements extract (*(src) >> (4 - 4*((v4-1) & 1))) & 0xF into the destination bytes, advancing the source when the shift wraps [field:this:0x00000000, source:raw]
    // GUARD: Other bit depths below 8 (and a zero element count) skip the unpack loops and fall through to the metadata update [field:this:0x00000009, source:raw]
    // ASSIGNMENT: Read the multiplier v16 from this+0xA (byte) [field:this:0x0000000A, source:raw]
    // ASSIGNMENT: Reset this+0x9 to 8 after processing [field:this:0x00000009, source:raw]
    // CALCULATION: Set this+0xB = 8 * v16 (byte) [field:this:0x0000000B, field:this:0x0000000A, source:raw]
    // ASSIGNMENT: Write this+0x4 = v4 * v16 (element count times multiplier), the computed output size [field:this:0x00000004, field:this:0x00000000, source:raw]
    // RETURN: Returns void; called by sub_51389E [function:0x005125C9, caller:0x0051389E, source:raw]

    // Conservative worker pseudocode:
    //   bits = *((_BYTE*)a1 + 9);
    //   if (bits >= 8) return;
    //   count = *a1;
    //   if (bits == 1) unpack_1bit(count, a2);
    //   else if (bits == 2) unpack_2bit(count, a2);
    //   else if (bits == 4) unpack_4bit(count, a2);
    //   mult = *((_BYTE*)a1 + 10);
    //   *((_BYTE*)a1 + 9) = 8;
    //   *((_BYTE*)a1 + 11) = 8 * mult;
    //   *(a1 + 1) = count * mult;
    // UNRESOLVED: The interpretation of this+0x9 values 1/2/4 as bit depths and this+0x4 as output size follows the existing analysis and is DERIVED; the raw source shows only the shift/mask arithmetic and the metadata writes
    // UNRESOLVED: The raw source shows the metadata update (reset this+0x9 to 8, this+0xB = 8*mult, this+0x4 = count*mult) runs only when v3 < 8; the existing analysis claiming it runs after the >= 8 guard does not match the raw source
    // UNRESOLVED: Owner object identity and the meaning of the multiplier at this+0xA are not established by this packet
}
