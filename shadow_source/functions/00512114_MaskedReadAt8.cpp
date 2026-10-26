// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00512114
// Canonical corpus name: MaskedReadAt8
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MaskedReadAt8_00512114.c

void UnknownObject::MaskedReadAt8()
{
    // Cdecl null-guarded masked read: when both a1 and a2 are non-null, returns a3 & *(dword*)(a2+8); otherwise returns 0. Called by sub_50210E (0x0050210E).
    // GUARD: Guard on a1 && a2 being non-null before dereferencing a2. [source:raw]
    // CALCULATION: Read the dword at a2+8 and mask it with a3: return a3 & *(_DWORD*)(a2+8). [source:raw]
    // RETURN: Return 0 on the null-argument fallback path. [function:0x00512114, source:raw]
    // CALL: Invoked by sub_50210E (0x0050210E) to query a masked dword stored at offset +8 of an object. [caller:0x0050210E]

    // Conservative worker pseudocode:
    //   int MaskedReadAt8(int a1, int a2, int a3) {
    //     if (a1 && a2) return a3 & *(_DWORD *)(a2 + 8);
    //     return 0;
    //   }
    // UNRESOLVED: Role of a1 beyond the null check is not established here; it may identify the object type or owner.
    // UNRESOLVED: The dword at a2+8 has no named field evidence in this packet, so its meaning depends on sub_50210E (0x0050210E).
}
