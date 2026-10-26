// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C50E0
// Canonical corpus name: GuardedListAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedListAccessor_004c50e0.c

void UnknownObject::GuardedListAccessor()
{
    // Guarded indexed access into a list stored behind this. Rejects a negative requested index (returns 0), reads an (index, count) pair from this+0x14 via ReadFieldAtOffset0x14, returns 0 when the range is empty or invalid, bounds-checks the index via BoundsCheckedIndexSetter_6760, then walks a singly-linked list from the node pointer at this+0x8 until the target index or the end of the list, returning the first dword stored at the selected node's data address or the unspecified MEMORY[0] placeholder on any failure. Called by AIOpponentSelection (004BF790) and AIPathPerformanceFunction (004BFA00).
    // GUARD: Reject a negative requested index: when a2 < 0 return 0. [source:raw]
    // CALL: ReadFieldAtOffset0x14(this) loads the (index, count) pair from the field at this+0x14. [callee:0x005871F0, source:raw]
    // GUARD: Reject an empty or invalid range: when the high dword of v2 (index) >= its low dword (count) return 0. [source:raw]
    // CALL: BoundsCheckedIndexSetter_6760(HIDWORD(v2)) bounds-checks the index against the guarded structure. [callee:0x004C6760, source:raw]
    // GUARD: When the bounds-checked index v3 >= count at +0x14, return the unspecified MEMORY[0] placeholder. [source:raw]
    // LOOP: Walk the singly-linked list starting from the node pointer at v4+0x8, following the next pointer at node+0x4 until the index countdown reaches zero; if the list ends first, return the unspecified MEMORY[0] placeholder. [source:raw]
    // RETURN: When the selected node is non-null, return the first dword stored at the address held by the node's first field (*node dereferenced); otherwise return the unspecified MEMORY[0] placeholder. [source:raw]
    // CALL: Used by AIOpponentSelection (004BF790) and AIPathPerformanceFunction (004BFA00) to access guarded list entries by index. [caller:0x004BF790, caller:0x004BFA00, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 < 0) return 0;
    //   pair = ReadFieldAtOffset0x14(this);
    //   if (SHIDWORD(pair) >= (int)pair) return 0;
    //   index = BoundsCheckedIndexSetter_6760(HIDWORD(pair));
    //   if (index >= *(base + 20)) return <unspecified>;
    //   node = *(base + 8);
    //   while (index > 0) {
    //     node = node->next;
    //     if (--index <= 0) break;
    //   }
    //   if (!node) return <unspecified>;
    //   return **(node);
    // UNRESOLVED: MEMORY[0] is a decompiler placeholder for the failure-path return value, not a real address; the actual value is unspecified.
    // UNRESOLVED: The provenance of the v3/v4 registers after BoundsCheckedIndexSetter_6760 is implicit in the raw source; the relationship between the bounds-checked index, the +0x14 count, and the +0x8 node pointer base is register-shared.
}
