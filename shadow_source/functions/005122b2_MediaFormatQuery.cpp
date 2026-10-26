// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005122B2
// Canonical corpus name: MediaFormatQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MediaFormatQuery_005122b2.c

void UnknownObject::MediaFormatQuery()
{
    // Format-gated media descriptor query over state a2: requires a1, a2, and the enable bit 0x10 in the byte at a2+8, then branches on a format discriminator byte at a2+25. Format 3 exposes a 32-bit field at a2+48 into *a3 and sets result to 16; other formats zero *a3 instead. Both branches write the descriptor pointer a2+52 into *a5 and mark success 16 when a5 is present. When a4 is present, its 16-bit field at a2+22 is written and the 0x10 bit is OR-ed into the returned result.
    // ASSIGNMENT: Initialize result to 0. [source:raw]
    // GUARD: Guard: proceed only when a1 and a2 are non-null and the enable bit 0x10 in the byte at a2+8 is set; otherwise return result 0. [source:raw]
    // GUARD: Branch on the format discriminator byte at a2+25 equal to 3. [source:raw]
    // ASSIGNMENT: Format 3: when a3 is present, store the 32-bit field at a2+48 into *a3 and set result to 16. [source:raw]
    // ASSIGNMENT: Format 3: when a5 is present, store the descriptor pointer a2+52 into *a5. [source:raw]
    // ASSIGNMENT: Other formats: when a5 is present, store a2+52 into *a5 and set result to 16. [source:raw]
    // ASSIGNMENT: Other formats: when a3 is present, store 0 into *a3. [source:raw]
    // GUARD: Guard: when a4 is present, store the unsigned 16-bit field at a2+22 into *a4 and return result OR-ed with 0x10. [source:raw]
    // RETURN: Return result (0 if the outer guard failed or a4 was absent, otherwise the accumulated success bits). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5122B2(int a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5) {
    //     int result = 0;
    //     if (a1 && a2 && (*(BYTE *)(a2 + 8) & 0x10)) {
    //       if (*(BYTE *)(a2 + 25) == 3) {
    //         if (a3) { *a3 = *(_DWORD *)(a2 + 48); result = 16; }
    //         if (a5) *a5 = a2 + 52;
    //       } else {
    //         if (a5) { *a5 = a2 + 52; result = 16; }
    //         if (a3) *a3 = 0;
    //       }
    //       if (a4) { *a4 = *(unsigned __int16 *)(a2 + 22); return result | 0x10; }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The format discriminator semantics (byte at a2+25, with 3 being one distinct format) and the meaning of fields at a2+48, a2+52, and a2+22 depend on the object layout known only to caller sub_50210E.
    // UNRESOLVED: Whether the 0x10 return bit and the enable bit at a2+8 share a flag word is not established.
    // UNRESOLVED: a5 is written with a pointer into the state object (a2+52); whether that address is an embedded buffer or a descriptor reference is unknown.
}
