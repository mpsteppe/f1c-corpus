// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C190
// Canonical corpus name: ArithmeticComparison_c190
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_c190_0053c190.c

void UnknownObject::IterateStructArray42()
{
    // Iterates 42 contiguous elements starting at dword_8B6C28, advancing by a 76-byte stride, and calls sub_556220 (0x00556220) on each element. Returns the result of the last call. Shape is a fixed-count batch walk over a 42-element array; the per-element action's semantics are in sub_556220.
    // ASSIGNMENT: Initialize the walking pointer v0 to the base of the 42-element array at dword_8B6C28 (0x008B6C28). [global:0x008B6C28, source:raw]
    // ASSIGNMENT: Initialize the element counter v1 to 42, fixing the array size the loop walks. [source:raw]
    // LOOP: do/while loop: call sub_556220 (0x00556220) with the current v0 element, advance v0 by 76 bytes, decrement v1, and repeat while v1 is nonzero. Runs exactly 42 times. [callee:0x00556220, source:raw]
    // RETURN: Return the result of the last sub_556220 call (the 42nd element's result). [function:0x0053C190, source:raw]

    // Conservative worker pseudocode:
    //   int IterateStructArray42(void) {
    //       char *v0 = (char *)&dword_8B6C28;
    //       int v1 = 42;
    //       int result;
    //       do {
    //           result = sub_556220(v0);
    //           v0 += 76;
    //           --v1;
    //       } while (v1);
    //       return result;
    //   }
    // UNRESOLVED: sub_556220's semantics and the object type of the 42-element array at dword_8B6C28 (76-byte = 0x4C stride) are not evidenced in this packet.
    // UNRESOLVED: The array is read-only from this function's perspective (dword_8B6C28 listed as R), so sub_556220 is presumed to mutate the element in place rather than receive a fresh copy.
}
