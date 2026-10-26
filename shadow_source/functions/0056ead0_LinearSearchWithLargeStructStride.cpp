// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056EAD0
// Canonical corpus name: LinearSearchWithLargeStructStride
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinearSearchWithLargeStructStride_0056ead0.c

void UnknownObject::LinearSearchWithLargeStructStride()
{
    // Linear search over an array of 580-byte elements: if the element count at this+0 is <= 0, returns 0; otherwise iterates the array whose base pointer is at this+4 with stride 580, calling sub_588410 (string comparison) against each element's first dword as the string pointer. The loop continues while the comparison reports non-match; when the search exhausts the element count it returns 0; on a match it returns this+4 + 580*index, the pointer to the matching element.
    // GUARD: If the element count at this+0 is <= 0, return 0 immediately (empty container) [field:this:0x00000000, guard:0, function:0x0056EAD0]
    // LOOP: Iterate the array: each pass advances i by 580 and the loop condition evaluates sub_588410(a2, element-string pointer at this+4 + i); the loop continues while the comparison returns non-zero (no match yet) [field:this:0x00000004, callee:0x00588410, source:raw]
    // GUARD: Inside the loop, increment v3; when v3 reaches the element count at this+0, return 0 (array exhausted without a match) [field:this:0x00000000, source:raw]
    // RETURN: On a match the loop exits and returns this+4 + 580*v3, the pointer to the matching element [field:this:0x00000004, function:0x0056EAD0, source:raw]

    // Conservative worker pseudocode:
    //   if (count <= 0) return 0;
    //   for (i = 0; StringCompare(a2, *(char **)(base + i)); i += 580) {
    //       if (++v3 >= count) return 0;
    //   }
    //   return base + 580 * v3;
    // UNRESOLVED: sub_588410 is treated as a string comparison returning 0 on match (per existing analysis) but its exact contract is not part of this packet
    // UNRESOLVED: The concrete element/container type for the 580-byte stride is unverified from this packet alone
}
