// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00410AF0
// Canonical corpus name: sub_410AF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_410AF0_00410af0.c

void UnknownObject::ArraySlotSwapRemove()
{
    // Removes an array element by index using swap-with-last in O(1). Reads the index from *a2, decrements the element count at this[0], copies the last slot (at array base + 4*newcount) into the removed slot, writes the removed index into the first dword of the object stored at the removed slot, resets *a2 to -1, and returns the removed index. No guards. Callers: ConditionalCleanupChain (0040F100), StateDependentUpdateDispatch (0040F130), LazyInitCallback (004E0D00).
    // CALCULATION: result = *a2 (index of the element to remove); v3 = *this - 1 (new count) [source:raw, field:this:0x00000000]
    // ASSIGNMENT: Store the decremented count v3 back into this[0] [field:this:0x00000000]
    // ASSIGNMENT: Copy slot[newcount] (array base this[2] + 4*v3) into slot[result] (array base this[2] + 4*result), swapping the last element over the removed slot [field:this:0x00000008]
    // ASSIGNMENT: Dereference the pointer stored at slot[result] and write the removed index result into its first dword [field:this:0x00000008]
    // ASSIGNMENT: Reset the caller's index *a2 to -1 to mark the slot as free [source:raw]
    // RETURN: Return the removed element index result [source:raw, function:0x00410AF0]
    // CALL: Invoked by ConditionalCleanupChain (0040F100), StateDependentUpdateDispatch (0040F130), and LazyInitCallback (004E0D00) [caller:0x0040F100, caller:0x0040F130, caller:0x004E0D00, source:raw]

    // Conservative worker pseudocode:
    //   result = *a2;
    //   v3 = *this - 1;
    //   *this = v3;
    //   *(int*)(this[2] + 4 * result) = *(int*)(this[2] + 4 * v3);
    //   **(int**)(this[2] + 4 * result) = result;
    //   *a2 = -1;
    //   return result;
    // UNRESOLVED: Legacy ABI name is 'Linked_List_Node_Removal', but the raw source performs array slot swap-remove, not a linked-list unlink; the mismatch is unresolved
    // UNRESOLVED: Purpose of writing the removed index into the removed object's first dword (owner back-reference) is inferred, not documented
    // UNRESOLVED: Element count at this[0] is a per-frame recalculated field; external pokes do not persist
}
