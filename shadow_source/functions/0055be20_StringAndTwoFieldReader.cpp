// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BE20
// Canonical corpus name: sub_55BE20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55BE20_0055be20.c

void UnknownObject::StringAndTwoFieldReader()
{
    // String-plus-fields reader on a thiscall object. If output buffer a2 is non-null, copies the null-terminated string stored at this+4 into a2, byte by byte including the terminating NUL. If a3 is non-null writes this[68] (offset 0x110) to *a3; if a4 is non-null writes this[69] (offset 0x114) to *a4. Returns a4 as result. All three outputs are optional and gated by null-pointer checks.
    // GUARD: If a2 is non-null, enter the string-copy path; otherwise skip it entirely. [source:raw]
    // LOOP: Copy the null-terminated string at this+4 into a2: iterate a byte cursor v4 from this+4, reading v5 = *v4, writing v5 to the corresponding byte of a2 (v4[a2 - (this+4)] = *v4), advancing v4, and continuing while v5 (the byte just copied) is non-zero so the NUL terminator is also copied. [field:this:0x00000004, source:raw]
    // GUARD: If a3 is non-null, write the field at offset 0x110 (this[68]) into *a3. [field:this:0x00000110]
    // GUARD: If a4 is non-null, write the field at offset 0x114 (this[69]) into *a4. [field:this:0x00000114]
    // RETURN: Return a4 as the result pointer. [source:raw]
    // CALL: Invoked by sub_55F0D0 (0x0055F0D0); part of a display/audio config accessor path. [caller:0x0055F0D0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *StringAndTwoFieldReader(char *this, char *dst, _DWORD *out1, _DWORD *out2) {
    //     if (dst) {
    //       char *src = this + 4;
    //       do {
    //         char c = *src;
    //         dst[src - (this + 4)] = c;
    //         ++src;
    //       } while (c);
    //     }
    //     if (out1) *out1 = ((_DWORD *)this)[68];
    //     if (out2) *out2 = ((_DWORD *)this)[69];
    //     return out2;
    //   }
    // UNRESOLVED: Semantics of the two dword fields at offsets 0x110 and 0x114 (whether they are integer config values or packed data) are not resolvable from this packet.
    // UNRESOLVED: The concrete type of `this` (display mode vs audio config object) is unproven; the packet owner is UnknownObject.
    // UNRESOLVED: The destination buffer a2's size contract is unknown; the copy is unbounded (relies on the NUL terminator at this+4).
}
