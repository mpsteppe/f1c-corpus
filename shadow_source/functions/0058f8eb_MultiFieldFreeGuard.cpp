// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058F8EB
// Canonical corpus name: MultiFieldFree_f8eb
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldFree_f8eb_0058f8eb.c

void UnknownObject::MultiFieldFreeGuard()
{
    // Conditionally frees seven pointer fields (indices 3-9, offsets 0xC-0x24) of a caller-provided structure through sub_58AA6F. Frees are skipped entirely when the structure is null or when the field at offset 0xC points at the static sentinel word_8D41CC, protecting static/read-only data from deallocation.
    // GUARD: Return immediately when the structure pointer a1 is null. [source:raw]
    // GUARD: Skip all freeing when the field at offset 0xC (a1[3]) equals the static sentinel word_8D41CC, i.e. the structure references static/read-only data. [field:this:0x0000000C, global:0x008D41CC, source:raw]
    // CALL: Free the seven pointer fields at offsets 0xC through 0x24 (indices 3-9) via sub_58AA6F. [callee:0x0058AA6F, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // RETURN: Return after the conditional free sequence completes. [function:0x0058F8EB, source:raw]

    // Conservative worker pseudocode:
    //   void sub_58F8EB(LPVOID *a1) {
    //     if (a1 && a1[3] != &word_8D41CC) {
    //       sub_58AA6F(a1[3]); sub_58AA6F(a1[4]); sub_58AA6F(a1[5]);
    //       sub_58AA6F(a1[6]); sub_58AA6F(a1[7]); sub_58AA6F(a1[8]); sub_58AA6F(a1[9]);
    //     }
    //   }
    // UNRESOLVED: Identity and exact semantics of callee sub_58AA6F (assumed free) are unknown.
    // UNRESOLVED: Owner class of the freed structure is unknown; the word_8D41CC sentinel role is inferred as a static-data marker.
    // UNRESOLVED: Legacy ABI hint (abi:lead) and the relationship to caller PhysicsAllocatorNodeInit_f6fe (0x0058F6FE) are unverified.
}
