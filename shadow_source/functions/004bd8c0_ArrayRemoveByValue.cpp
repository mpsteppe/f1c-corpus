// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BD8C0
// Canonical corpus name: ArithmeticComparison_d8c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_d8c0_004bd8c0.c

void UnknownObject::ArrayRemoveByValue()
{
    // Searches an integer array whose element count is at offset 0x4 and whose data pointer is at offset 0x8 for a value equal to argument a2. If found, the element at that index is replaced with the last element and the count at offset 0x4 is decremented (swap-remove). Returns the index of the removed element, or the count value when the value is not present.
    // GUARD: When the element count at offset 0x4 is not greater than 0 the function returns 0 immediately (empty array) [field:this:0x00000004, source:raw]
    // LOOP: Iterates the integer array at offset 0x8 from index 0, advancing while the current element differs from a2, and stops early when the running index reaches the count at offset 0x4 [field:this:0x00000004, field:this:0x00000008, source:raw]
    // RETURN: When the value a2 is not found before the index reaches the count, returns the count value (index one past the end) [field:this:0x00000004, source:raw]
    // ASSIGNMENT: When a2 is found, decrements the element count at offset 0x4 by 1 [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Replaces the found element in the array at offset 0x8 with the last element of the array (swap-remove) [field:this:0x00000008, source:raw]
    // RETURN: Returns the index of the removed element, or the count when a2 was not found [field:this:0x00000004, function:0x004BD8C0, source:raw]

    // Conservative worker pseudocode:
    //   count = *(int*)(this + 0x4);
    //   result = 0;
    //   if (count > 0) {
    //       array_data = (int*)*(int*)(this + 0x8);
    //       for (i = array_data; *i != a2; ++i)
    //           if (++result >= count) return result;
    //       *(int*)(this + 0x4) = count - 1;
    //       array_data[result] = array_data[count - 1];
    //   }
    //   return result;
    // UNRESOLVED: The identity of the object owning offsets 0x4 and 0x8 is unknown
    // UNRESOLVED: Whether the swap-remove preserves array order or is order-independent is not stated
    // UNRESOLVED: The semantics of the returned index for callers outside this packet are inferred from the source only
}
