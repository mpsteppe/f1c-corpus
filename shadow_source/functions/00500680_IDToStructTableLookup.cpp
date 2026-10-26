// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00500680
// Canonical corpus name: IDToStructTableLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IDToStructTableLookup_00500680.c

void UnknownObject::IDToStructTableLookup()
{
    // Linear search over a stride-9-element table for the entry whose first DWORD equals a1 (an ID). Returns a pointer to the matched entry, or the fallback pointer unk_5AD4E0 when the table is empty or the ID is not found. The table spans flt_5AD508 (base) to off_5D7150 (end); entries are 9 elements apart (36 bytes, per the float-typed cursor).
    // ASSIGNMENT: Start the search at the table base pointer flt_5AD508. [global:0x005AD508]
    // GUARD: If the table end off_5D7150 is at or below the table base flt_5AD508, the table is empty; return the fallback pointer unk_5AD4E0. [global:0x005D7150, global:0x005AD508, global:0x005AD4E0]
    // LOOP: while-loop over table entries comparing the first DWORD of each entry against the input ID a1. [source:raw]
    // CALCULATION: Advance the cursor by 9 elements (one table entry stride) when the current entry does not match. [source:raw]
    // GUARD: If the cursor reaches or passes off_5D7150, no entry matched; return the fallback pointer unk_5AD4E0. [global:0x005D7150, global:0x005AD4E0]
    // RETURN: Return the matched entry pointer when the first DWORD of an entry equals a1. [source:raw]

    // Conservative worker pseudocode:
    //   float *sub_500680(int id) {
    //     float *p = flt_5AD508;
    //     if (off_5D7150 <= flt_5AD508) return (float *)&unk_5AD4E0;
    //     while (*(int *)p != id) {
    //       p += 9;
    //       if (p >= off_5D7150) return (float *)&unk_5AD4E0;
    //     }
    //     return p;
    //   }
    // UNRESOLVED: Meaning of unk_5AD4E0 fallback (likely a default/zeroed entry whose first DWORD is never a real ID).
    // UNRESOLVED: Structure of the stride-9 entries beyond the first DWORD is not consumed here.
    // UNRESOLVED: Caller DDSTextureSurfaceCreation at 0x005026A4 uses the returned entry for texture/surface data.
}
