// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564990
// Canonical corpus name: ArrayElementRemovalWithShift
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayElementRemovalWithShift_00564990.c

void UnknownObject::ArrayElementRemovalWithShift()
{
    // Removes the element at index a2 from a packed record array rooted at a1: when a2 is not the final element it shifts the array tail down by one record by copying the byte span a1[2] * (count - a2 - 1) from element a2 + 1 onto element a2 via sub_58B130, then decrements the stored count at a1[0] and returns the new count. The single caller NetworkConnection suggests the array is a connection/record list that shrinks when an entry is dropped.
    // GUARD: Proceed with the shift only when the removal index a2 is strictly less than the last valid index *a1 - 1, i.e. a2 is not the final element. [source:raw]
    // CALCULATION: Compute the byte span v8 = a1[2] * (*a1 - a2 - 1), the size of the contiguous tail starting at element a2 + 1. [source:raw]
    // CALL: Resolve the address of element a2 + 1 as v7 = LinearInterpolation(a1, a2 + 1). [callee:0x005648B0, source:raw]
    // CALL: Resolve the address of element a2 as v5 = LinearInterpolation(v4, a2), where v4 is the ecx this pointer equal to a1. [callee:0x005648B0, source:raw]
    // CALL: Shift the tail into the removed slot by calling sub_58B130(v5, v7, v8): v8 bytes copied from element a2 + 1 onto element a2 (memmove-like block move). [callee:0x0058B130, source:raw]
    // ASSIGNMENT: Decrement the stored element count: result = *a1 - 1; *a1 = result. [source:raw]
    // RETURN: Return the decremented count. [source:raw]

    // Conservative worker pseudocode:
    //   int arrayElementRemovalWithShift(int* a1, int a2) {
    //     if (a2 < a1[0] - 1) {
    //       int bytes = a1[2] * (a1[0] - a2 - 1);
    //       int* src = LinearInterpolation(a1, a2 + 1);
    //       int* dst = LinearInterpolation(a1, a2);
    //       sub_58B130(dst, src, bytes);
    //     }
    //     int result = a1[0] - 1;
    //     a1[0] = result;
    //     return result;
    //   }
    // UNRESOLVED: a1[2] is assumed to be the per-record byte stride; the packet provides no name evidence, only its use in the byte-span arithmetic.
    // UNRESOLVED: LinearInterpolation is the Hex-Rays symbol; its role as an element-address/offset resolver is DERIVED from the call pattern.
    // UNRESOLVED: sub_58B130 is presumed to be a byte-block copy/move (memmove-like); its exact contract is not evidenced in this packet.
    // UNRESOLVED: Why the caller NetworkConnection (0x00563260) removes array elements, and what the array holds, is not derivable here.
    // UNRESOLVED: v4 is uninitialized in the decompiled listing and is interpreted as the ecx this pointer equal to a1, a DERIVED assumption.
}
