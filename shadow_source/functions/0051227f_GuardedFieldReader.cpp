// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051227F
// Canonical corpus name: GuardedFieldReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedFieldReader_0051227f.c

void UnknownObject::GuardedFieldReader()
{
    // Guard-gated field reader over a per-object state struct a2: validates the caller pointer a1, the state pointer a2, an enable flag bit (byte at a2+8 bit 0x08), and the output pointer a3, then copies a 32-bit field at a2+16 into *a3 and a 16-bit field at a2+20 into *a4, returning 8 on success or 0 when any guard fails.
    // GUARD: Guard: return 0 when the first argument a1 is null. [source:raw]
    // GUARD: Guard: return 0 when the state pointer a2 is null. [source:raw]
    // GUARD: Guard: return 0 when the enable flag bit 0x08 in the byte at a2+8 is clear. [source:raw]
    // GUARD: Guard: return 0 when the 32-bit output pointer a3 is null. [source:raw]
    // ASSIGNMENT: Store the 32-bit field at a2+16 into *a3. [source:raw]
    // ASSIGNMENT: Store the unsigned 16-bit field at a2+20 into *a4. [source:raw]
    // RETURN: Return 8 to signal success; all guard failures return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_51227F(int a1, int a2, _DWORD *a3, _DWORD *a4) {
    //     if (!a1 || !a2 || ((*(BYTE *)(a2 + 8) & 8) == 0) || !a3) return 0;
    //     *a3 = *(_DWORD *)(a2 + 16);
    //     *a4 = *(unsigned __int16 *)(a2 + 20);
    //     return 8;
    //   }
    // UNRESOLVED: a4 is dereferenced without a null guard while a3 is guarded; the caller must guarantee a4 is valid.
    // UNRESOLVED: Meaning of the return value 8 and the enable bit 0x08 at a2+8 depend on the state object layout known only to caller sub_50210E.
    // UNRESOLVED: Identity of the object behind a2 and the semantics of fields at a2+16 (32-bit) and a2+20 (16-bit) are not established.
}
