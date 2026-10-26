// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486460
// Canonical corpus name: ConditionalDelegation_6460
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDelegation_6460_00486460.c

void UnknownObject::IndexedListNodeLookup()
{
    // Loads the sub-object pointer v2 from this[50] (offset 0xC8) and returns 0 if it is null. From that sub-object reads a list head at offset +8 and a bound at offset +12, returning 0 when a2 exceeds the bound. Otherwise walks a2 steps along the list, following the next-pointer at node offset +36 whenever the current node is non-null, and returns the node reached (0/null when a null node ends the walk early).
    // ASSIGNMENT: v2 = this[50] loads the sub-object pointer at offset 0xC8. [field:this:0x000000C8]
    // GUARD: If v2 is null, return 0 immediately. [field:this:0x000000C8]
    // ASSIGNMENT: result = *(v2 + 8) seeds the walk with the sub-object's list head; v4 = a2. [source:raw]
    // GUARD: If a2 > *(v2 + 12), the stored bound, return 0 immediately. [source:raw]
    // LOOP: While v4 is non-zero: if result is non-null, advance result = *(result + 36) (the node next-pointer); decrement v4. [source:raw]
    // RETURN: Return the reached node pointer, which is 0/null if the walk hit a null next-pointer early. [source:raw]

    // Conservative worker pseudocode:
    //   v2 = this[50];
    //   if (!v2) return 0;
    //   result = *(v2 + 8);
    //   if (a2 > *(v2 + 12)) return 0;
    //   while (a2-- > 0) if (result) result = *(result + 36);
    //   return result;
    // UNRESOLVED: The extracted field bases this+0xD0, this+0xD4 and *(*(this+0xD0)+0x24) are listed for this function but do not appear in the raw source; their role is not evidenced here.
    // UNRESOLVED: The list node layout (head at +8, bound at +12, next at +36) is inferred from the raw source only.
}
