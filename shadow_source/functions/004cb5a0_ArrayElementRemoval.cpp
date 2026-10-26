// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CB5A0
// Canonical corpus name: ArrayElementRemoval
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayElementRemoval_004cb5a0.c

void UnknownObject::ArrayElementRemoval()
{
    // Swap-remove of an element from a flat array of pointers. Reads the array base pointer from this+0x68 (element 26), decrements the element count at this+0x64 (element 25), copies the last element into the removed slot, updates the moved element's own index field (+4 within the pointed-to element), marks the removed element handle as invalid (-1), then calls a helper with the element handle and returns its result.
    // ASSIGNMENT: Load v2 = this[26], the pointer to the flat array base (offset 0x68). [source:raw, field:this:0x00000068]
    // CALCULATION: Compute the new element count v3 = this[25] - 1 (count field at offset 0x64). [source:raw, field:this:0x00000064]
    // ASSIGNMENT: Store the decremented count back into this[25] (offset 0x64). [source:raw, field:this:0x00000064]
    // ASSIGNMENT: Copy the last element (array[v3]) into the removed slot (array[a2[1]]) within the flat array at 0x68. [source:raw, field:this:0x00000068]
    // ASSIGNMENT: Write a2[1] into the +4 index field of the element now occupying slot a2[1], keeping the moved element's stored index in sync. [source:raw, field:this:0x00000068]
    // STATE_TRANSITION: Mark the removed element handle as invalid by storing -1 into a2[1]. [source:raw]
    // CALL: Call the helper sub_558B30 with *a2 as its argument and return its result. The helper address is not present in the packet callee evidence. [source:raw]
    // RETURN: Return the result of the helper call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4CB5A0(int *this, int *a2) {
    //     int base = this[26];
    //     int newCount = this[25] - 1;
    //     this[25] = newCount;
    //     base[a2[1]] = base[newCount];
    //     base[a2[1]][1] = a2[1];
    //     a2[1] = -1;
    //     return sub_558B30(*a2);
    //   }
    // UNRESOLVED: The helper sub_558B30 called with *a2 has no callee entry in the packet; its address and semantics are not confirmed by packet facts.
    // UNRESOLVED: No bounds check: the removed index a2[1] is assumed valid within the current count; behavior on an out-of-range index is undefined.
    // UNRESOLVED: Element layout is only partially known: each array entry points to a record whose second DWORD (+4) stores that record's own array index.
}
