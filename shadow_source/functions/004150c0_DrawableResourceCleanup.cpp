// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004150C0
// Canonical corpus name: DrawableResourceCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DrawableResourceCleanup_004150c0.c

void UnknownObject::DrawableResourceCleanup()
{
    // Cleans up three linked lists of drawable resources hanging off the receiver: walks each list node (active flag at +8, next pointer at +4, resource pointer at +0), frees each active resource through its type-specific destructor and then frees the node, and finally zeroes each list's four tracking fields (head/tail/count/tracking). Returns 0 in practice.
    // LOOP: First list teardown: iterate from this[0] (this+0x0); per node read the active flag at node+8 and advance via the next pointer at node+4; when active and the resource pointer at node+0 is non-null, run TextFormatStructInitializer(resource), four ArrayDestructorIterator passes over resource sub-ranges (v6+34, v6+24, v6+14, v6+4, each stride 20 count 2) with destructor ShortComputation_4370, then ShortComputation_4370(resource) and FreeWrapper_7bcf(resource); finally FreeWrapper_7bcf(node). [source:raw, field:this:0x00000000, field:obj:0x00000008, field:*(obj+0x4):0x00000004, field:obj:0x00000000, callee:0x004149A0, callee:0x00401030, callee:0x00414370, global:0x00414370, callee:0x00587BCF]
    // ASSIGNMENT: Zero the first list's four tracking fields: this[0..3] (this+0x0, +0x4, +0x8, +0xC) set to 0. [source:raw, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // LOOP: Second list teardown: iterate from this[4] (this+0x10); per node read the active flag at node+8 and advance via the next pointer at node+4; when active and the resource pointer at node+0 is non-null, run MultiFieldPointerFree(resource), then FreeWrapper_7bcf(resource); finally FreeWrapper_7bcf(node). [source:raw, field:this:0x00000010, field:obj:0x00000008, field:*(this+0x14):0x00000004, field:obj:0x00000000, callee:0x00414380, callee:0x00587BCF]
    // ASSIGNMENT: Zero the second list's four tracking fields: this[4..7] (this+0x10, +0x14, +0x18, +0x1C) set to 0. [source:raw, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // LOOP: Third list teardown: iterate from this[8] (this+0x20); per node read the active flag at node+8 and advance via the next pointer at node+4; when active and the resource pointer at node+0 is non-null, run TextFormatStructInitializer_4fe0(resource), two ArrayDestructorIterator passes over resource sub-ranges (v14+13 and v14+3, each stride 20 count 2) with destructor ShortComputation_4370, then ShortComputation_4370(resource) and FreeWrapper_7bcf(resource); finally FreeWrapper_7bcf(node). [source:raw, field:this:0x00000020, field:obj:0x00000008, field:*(this+0x24):0x00000004, field:obj:0x00000000, callee:0x00414FE0, callee:0x00401030, callee:0x00414370, global:0x00414370, callee:0x00587BCF]
    // ASSIGNMENT: Zero the third list's four tracking fields: this[8..11] (this+0x20, +0x24, +0x28, +0x2C) set to 0. [source:raw, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // RETURN: Return the loop-scoped result, which is 0 after every executed iteration and 0 when a list is empty. [source:raw]
    // CALL: Invoked by GlobalListTripleCleanupWithTimerRemoval (0x00414210) and ShortComputation_8900 (0x00418900) to tear down drawable resource lists. [caller:0x00414210, caller:0x00418900, source:raw]

    // Conservative worker pseudocode:
    //   int DrawableResourceCleanup(int *this) {
    //     for (node = this[0]; node; node = *(DWORD*)(node+4)) {
    //       if (*(BYTE*)(node+8)) {
    //         res = *(LPVOID*)node;
    //         if (res) {
    //           TextFormatStructInitializer(res);
    //           ArrayDestructorIterator(res+34*4, 20, 2, ShortComputation_4370);
    //           ArrayDestructorIterator(res+24*4, 20, 2, ShortComputation_4370);
    //           ArrayDestructorIterator(res+14*4, 20, 2, ShortComputation_4370);
    //           ArrayDestructorIterator(res+4*4, 20, 2, ShortComputation_4370);
    //           ShortComputation_4370(res);
    //           FreeWrapper_7bcf(res);
    //         }
    //       }
    //       FreeWrapper_7bcf(node);
    //     }
    //     this[0] = this[1] = this[2] = this[3] = 0;
    //     for (node = this[4]; node; node = *(DWORD*)(node+4)) {
    //       if (*(BYTE*)(node+8)) {
    //         res = *(LPVOID*)node;
    //         if (res) { MultiFieldPointerFree(res); FreeWrapper_7bcf(res); }
    //       }
    //       FreeWrapper_7bcf(node);
    //     }
    //     this[4] = this[5] = this[6] = this[7] = 0;
    //     for (node = this[8]; node; node = *(DWORD*)(node+4)) {
    //       if (*(BYTE*)(node+8)) {
    //         res = *(LPVOID*)node;
    //         if (res) {
    //           TextFormatStructInitializer_4fe0(res);
    //           ArrayDestructorIterator(res+13*4, 20, 2, ShortComputation_4370);
    //           ArrayDestructorIterator(res+3*4, 20, 2, ShortComputation_4370);
    //           ShortComputation_4370(res);
    //           FreeWrapper_7bcf(res);
    //         }
    //       }
    //       FreeWrapper_7bcf(node);
    //     }
    //     this[8] = this[9] = this[10] = this[11] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: TextFormatStructInitializer (0x004149A0) and TextFormatStructInitializer_4fe0 (0x00414FE0) are called here immediately before ArrayDestructorIterator and free, so their names likely mislabel teardown/destructor work.
    // UNRESOLVED: The two array groups in the first resource type (v6+34 and v6+24 at stride 20 count 2, plus v6+14 and v6+4) and in the third type (v14+13 and v14+3) are unnamed; exact element layouts unknown.
    // UNRESOLVED: List tracking-field semantics (head/tail/count/tracking per four-field group) are inferred from ordering, not proven.
    // UNRESOLVED: The unused-list guard byte at node+8 is a flag, but its exact meaning (active vs allocated) is not established.
}
