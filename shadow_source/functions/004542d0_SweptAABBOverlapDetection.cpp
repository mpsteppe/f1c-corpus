// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004542D0
// Canonical corpus name: SweptAABBOverlapDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SweptAABBOverlapDetection_004542d0.c

void UnknownObject::SweptAABBOverlapDetection()
{
    // Per-entry swept-interval overlap test indexed by a2 (entry) with an array selector a3. Selects a per-entry data base at this+3464, or this+4484 when a3 is non-zero. Rejects (returns 0) when the quantity (value at base + 4*a2 + 920 minus value at base + 4*a2 + 96) times value at base + 4*a2 + 64 minus the caller-supplied input at a4 + 4*a2 is at least -0.34999999. On overlap, writes a float bit pattern into dword_7D1490[216*a3 + 27*a2]: 1056964608 when the a4 input is at most 0.92500001, otherwise 1065353216, and returns 1.
    // ASSIGNMENT: Data base selection: v4 = this + 3464, replaced by this + 4484 when a3 is non-zero, choosing between two per-entry data arrays [source:raw]
    // GUARD: Rejection test: when (value at v4 + 4*a2 + 920 minus value at v4 + 4*a2 + 96) times value at v4 + 4*a2 + 64 minus the caller input at a4 + 4*a2 is at least -0.34999999, return 0 without writing [source:raw]
    // ASSIGNMENT: Write to dword_7D1490[216*a3 + 27*a2] the float bit pattern 1056964608 when the caller input at a4 + 4*a2 is at most 0.92500001, otherwise 1065353216 [global:0x007D1490, source:raw]
    // RETURN: Returns 1 when the overlap test passed (bit pattern written) and 0 when rejected; called by sub_454350 [function:0x004542D0, caller:0x00454350, source:raw]

    // Conservative worker pseudocode:
    //   v4 = this + (a3 ? 4484 : 3464);
    //   if ((*(v4 + 4*a2 + 920) - *(v4 + 4*a2 + 96)) * *(v4 + 4*a2 + 64) - *(a4 + 4*a2) >= -0.34999999)
    //     return 0;
    //   dword_7D1490[216*a3 + 27*a2] = (*(a4 + 4*a2) <= 0.92500001) ? 1056964608 : 1065353216;
    //   return 1;
    // UNRESOLVED: flt_59EF7C and flt_59EF80 are flagged as read-only globals by packet facts but never appear in the raw decompiled source; their role is unverifiable from this packet
}
