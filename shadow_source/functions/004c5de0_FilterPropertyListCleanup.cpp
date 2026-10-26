// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5DE0
// Canonical corpus name: sub_4C5DE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C5DE0_004c5de0.c

void UnknownObject::FilterPropertyListCleanup()
{
    // Full teardown of a filter-property structure: cleans the inner resource list, walks the linked list of filter nodes freeing each node's data (with optional secondary pointer when owned) and the node itself, zeroes the four list fields, then frees the base structure pointer if present.
    // CALL: Call ResourceListCleanup (0x004C62C0) on this to clean the inner resource list before node teardown. [callee:0x004C62C0, source:raw]
    // ASSIGNMENT: Load the list head v2 = this[2] (offset 0x8) as the starting node. [field:this:0x00000008, source:raw]
    // LOOP: while(v2) walk the singly-linked node list via the next pointer v2[1], keeping v3 as the current node. [source:raw]
    // GUARD: Read the ownership flag byte at node+8; when non-zero the node owns heap data to release. [source:raw]
    // GUARD: Load the data pointer v5 = *v3; proceed only when it is non-null. [source:raw]
    // GUARD: If the secondary pointer v5[1] (offset 0x4 of the data block) is non-null, free it first via FreeWrapper (0x00587BCF). [field:*(this+0x8):0x00000004, callee:0x00587BCF, source:raw]
    // CALL: Free the node's data block v5 via FreeWrapper (0x00587BCF). [callee:0x00587BCF, source:raw]
    // CALL: Free the node itself v3 via FreeWrapper (0x00587BCF). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four list fields: head (0x8), tail (0xC), iterator/first-node (0x10) and count (0x14). [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // GUARD: Load the base structure pointer v7 = *this (offset 0x0); free it when non-null. [field:this:0x00000000, callee:0x00587BCF, source:raw]
    // RETURN: Return 0 when the base structure pointer was null. [source:raw]
    // CALL: Called by sub_47FB10 (0x0047FB10) to tear down its filter property structure. [caller:0x0047FB10, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C5DE0(LPVOID **self) {
    //     ResourceListCleanup(self);
    //     for (LPVOID **node = (LPVOID**)self[2]; node; ) {
    //       LPVOID **cur = node;
    //       int owned = *((_BYTE*)node + 8);
    //       node = (LPVOID**)node[1];
    //       if (owned) {
    //         LPVOID *data = *cur;
    //         if (data) {
    //           if (data[1]) FreeWrapper(data[1]);
    //           FreeWrapper(data);
    //         }
    //       }
    //       FreeWrapper(cur);
    //     }
    //     self[2] = 0; self[3] = 0; self[4] = 0; self[5] = 0;
    //     if (self[0]) return FreeWrapper(self[0]);
    //     return 0;
    //   }
    // UNRESOLVED: Exact layout and semantics of the per-node filter property data block (only the data pointer at +0 and secondary pointer at +4 are evidenced).
    // UNRESOLVED: Meaning of the ownership flag byte at node+8 is inferred from the guard/free pattern, not proven.
    // UNRESOLVED: Identity and contents of the base structure pointer at this+0x0.
}
