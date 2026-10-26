// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B48E0
// Canonical corpus name: CollisionObjectInsertion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionObjectInsertion_004b48e0.c

void UnknownObject::CollisionObjectInsert()
{
    // Inserts a collision object into one of four type-specific sub-lists hanging off the this object. The 3-bit type tag is extracted from the high bits of the header dword a2 (a2 >> 29) and mapped through jump table jpt_4B4900 to a list index (0..3, or -1 for unmapped tags). The node is reused from the free list anchored at dword_8AB708 (validated by sub_4BB6B0) or freshly allocated via ConditionalAllocation and the list helpers LinkedListNodeInsertion_ac40/LinkedListNodeRemoval_acf0. Collision data is processed into the node by ArithmeticComparison_3a90. A 12-byte linked-list entry is allocated with OperatorNewNhMallocWrapper and linked into the sub-list at this+112+16*index (head v6[0], next v6[1], tail v6[2], count v6[3]), then ArithmeticComparison_47a0 finalizes the insertion. Returns 1 on success, 0 if disabled, on validation failure, or on allocation failure.
    // GUARD: If the enable byte at this+0 is zero, return 0 immediately without inserting. [field:this:0x00000000, source:raw]
    // CALCULATION: Extract the 3-bit collision type tag from the header dword a2 via a2 >> 29. [source:raw]
    // CALCULATION: Map the tag to a sub-list index v3 via jump table jpt_4B4900: 1 -> 0, 2/3 -> 1, 4 -> 2, 6 -> 3, default -> -1. [global:0x004B4A10, source:raw]
    // GUARD: Call ArithmeticComparison_4760(v3, a2); if it returns nonzero the insertion is rejected and the function returns 0. [callee:0x004B4760, source:raw]
    // CALL: Check free-list availability with ShortComputation_a780 on the free list head dword_8AB700. [callee:0x004BA780, global:0x008AB700, source:raw]
    // ASSIGNMENT: When the free-list anchor dword_8AB708 holds a node, take it as v4, clear the byte at anchor+8, and run sub_4BB6B0(v10, 1) to validate it; a failed validation resets v4 to null. [global:0x008AB708, callee:0x004BB6B0, source:raw]
    // CALL: When no reusable node exists, allocate a new one: OperatorNewNhMallocWrapper(4) gates ConditionalAllocation(0), the result is inserted into the free list via LinkedListNodeInsertion_ac40, then a node is removed for use via LinkedListNodeRemoval_acf0 from dword_8AB700. [callee:0x00587C03, callee:0x004BA950, callee:0x004BAC40, callee:0x004BACF0, global:0x008AB700, source:raw]
    // CALL: Process the collision data into the acquired node with ArithmeticComparison_3a90(v4, a2). [callee:0x004B3A90, source:raw]
    // CALCULATION: Compute the target sub-list head v6 = &this[16*v3 + 112] using the mapped index. [source:raw]
    // GUARD: If the node v4 is null, return 0. [source:raw]
    // CALL: Allocate a 12-byte list entry with OperatorNewNhMallocWrapper(12) and initialize it: entry[0] = v4 (node pointer), entry[4] = 0, entry[8] = 0. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Link the new entry into the sub-list: if the list is non-empty point the old tail's next (at +4) at the new entry, otherwise set both head and tail to it; then set v6[1] to the new entry. [source:raw]
    // CALCULATION: Increment the sub-list element count stored at v6[3]. [source:raw]
    // CALL: Finalize the insertion with ArithmeticComparison_47a0(this, v8, 1, v3, *v4); v8 is the prior tail pointer and only assigned on the non-empty-list path. [callee:0x004B47A0, source:raw]
    // RETURN: Return 1 on success; the function is called by PitStallProximityCheck (0x004B5DA0) for collision zone management. [caller:0x004B5DA0, source:raw]

    // Conservative worker pseudocode:
    //   char sub_4B48E0(char *this, DWORD *a2, int a3) {
    //     if (!*this) return 0;
    //     int v3 = -1;
    //     switch (*a2 >> 29) {
    //       case 1: v3 = 0; break;
    //       case 2: case 3: v3 = 1; break;
    //       case 4: v3 = 2; break;
    //       case 6: v3 = 3; break;
    //     }
    //     if (ArithmeticComparison_4760(v3, a2)) return 0;
    //     void *v4 = 0;
    //     ShortComputation_a780(&dword_8AB700);
    //     if (dword_8AB708) {
    //       v4 = *(void**)dword_8AB708;
    //       *(char*)(dword_8AB708 + 8) = 0;
    //       if (!sub_4BB6B0(*(DWORD*)dword_8AB708, 1)) v4 = 0;
    //     }
    //     if (!v4) {
    //       int n = OperatorNewNhMallocWrapper(4) ? ConditionalAllocation(0) : 0;
    //       LinkedListNodeInsertion_ac40(n, 0);
    //       v4 = LinkedListNodeRemoval_acf0(&dword_8AB700);
    //     }
    //     ArithmeticComparison_3a90(v4, a2);
    //     DWORD *v6 = (DWORD*)(this + 112 + 16*v3);
    //     if (!v4) return 0;
    //     DWORD *entry = OperatorNewNhMallocWrapper(12);
    //     if (entry) { entry[0] = (DWORD)v4; entry[1] = 0; *(char*)((char*)entry+8) = 0; }
    //     if (*v6) { DWORD *tail = (DWORD*)v6[1]; *(DWORD*)((char*)tail+4) = (DWORD)entry; }
    //     else { *v6 = (DWORD)entry; v6[2] = (DWORD)entry; }
    //     v6[1] = (DWORD)entry;
    //     ++v6[3];
    //     ArithmeticComparison_47a0((int)this, (DWORD)v8, 1, v3, *(char*)v4);
    //     return 1;
    //   }
    // UNRESOLVED: v8 (prior tail) is only assigned on the non-empty-list path; the decompiler passes a stale stack value to ArithmeticComparison_47a0 on the empty-list path, so the exact fifth/sixth argument semantics of the finalize call are uncertain.
    // UNRESOLVED: dword_8AB6F0 is listed in the packet globals but never referenced by the raw source of this function; its role here is unknown.
    // UNRESOLVED: The structure of a2 (header tag plus payload) and the meanings of the individual type tag values 1..6 are not established here.
    // UNRESOLVED: This object layout (head/next/tail/count per sub-list at 112 + 16*index, 16-byte stride) is inferred from the raw source only.
}
