// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C270
// Canonical corpus name: LoopWithRepeatedCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LoopWithRepeatedCall_0054c270.c

void UnknownObject::InitializeFloatStructArray256()
{
    // Iterates 256 contiguous elements starting at unk_8B8F40, advancing by a 26-dword (104-byte) stride, and calls F_10FloatStructInitializer (0x0053B130) on each element. Returns the last initializer result. Shape is a fixed-count batch initialization of a 256-element array of 104-byte float-bearing structs.
    // ASSIGNMENT: Initialize the walking pointer v0 to the base of the 256-element array at unk_8B8F40 (0x008B8F40). [global:0x008B8F40, source:raw]
    // ASSIGNMENT: Initialize the element counter v1 to 256, fixing the array size the loop walks. [source:raw]
    // LOOP: do/while loop: call F_10FloatStructInitializer (0x0053B130) with the current v0 element, advance v0 by 26 dwords (104 bytes), decrement v1, and repeat while v1 is nonzero. Runs exactly 256 times. [callee:0x0053B130, source:raw]
    // RETURN: Return the result of the last F_10FloatStructInitializer call (the 256th element's result). [function:0x0054C270, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *InitializeFloatStructArray256(void) {
    //       _DWORD *v0 = &unk_8B8F40;
    //       int v1 = 256;
    //       _DWORD *result;
    //       do {
    //           result = F_10FloatStructInitializer(v0);
    //           v0 += 26;
    //           --v1;
    //       } while (v1);
    //       return result;
    //   }
    // UNRESOLVED: F_10FloatStructInitializer's semantics and the object type of the 256-element array at unk_8B8F40 (104-byte = 0x68 stride) are not evidenced in this packet.
    // UNRESOLVED: The array is read-only from this function's perspective (unk_8B8F40 listed as R), so the callee is presumed to fill each element in place.
}
