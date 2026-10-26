// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056EB30
// Canonical corpus name: LinearSearchInStructArrayByString
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinearSearchInStructArrayByString_0056eb30.c

void UnknownObject::LinearSearchInStructArrayByString()
{
    // Linear search over an array of 72-byte structs that skips null entries: if the element count at this+0x18 is <= 0, returns 0; otherwise iterates the array whose base pointer is at this+0x1C with stride 72. The loop continues while the element string pointer is null OR sub_588410 (string comparison) reports non-match; when the search exhausts the element count it returns 0; on the first non-null matching element it returns this+0x1C + 72*index.
    // GUARD: If the element count at this+0x18 is <= 0, return 0 immediately (empty container) [field:this:0x00000018, guard:0, function:0x0056EB30]
    // LOOP: Iterate the array with stride 72: the loop condition keeps iterating while the element string pointer at this+0x1C + i is null, or sub_588410(a2, element string pointer) returns non-zero (no match) [field:this:0x0000001C, callee:0x00588410, source:raw]
    // GUARD: Inside the loop, increment v3; when v3 reaches the element count at this+0x18, return 0 (array exhausted without a match) [field:this:0x00000018, source:raw]
    // RETURN: On the first non-null matching element the loop exits and returns this+0x1C + 72*v3, the pointer to that element [field:this:0x0000001C, function:0x0056EB30, source:raw]

    // Conservative worker pseudocode:
    //   if (count <= 0) return 0;
    //   for (i = 0; !*(char **)(base + i) || StringCompare(a2, *(char **)(base + i)); i += 72) {
    //       if (++v3 >= count) return 0;
    //   }
    //   return base + 72 * v3;
    // UNRESOLVED: sub_588410 is treated as a string comparison returning 0 on match (per existing analysis) but its exact contract is not part of this packet
    // UNRESOLVED: The concrete 72-byte struct type and why entries may be null are unverified from this packet alone
}
