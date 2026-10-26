// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054B4A0
// Canonical corpus name: ArithmeticComparison_b4a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_b4a0_0054b4a0.c

void UnknownObject::ArithmeticComparison_b4a0()
{
    // Triple float field query: writes this[11] (offset 0x2C) to *a2 when a2 is non-null, this[12] (offset 0x30) to *a3 when a3 is non-null, this[13] (offset 0x34) to *a4 when a4 is non-null, and returns a4. Called by DualMatrixTransformMultiply (0x0054B530) on the frame path.
    // GUARD: If a2 is non-null, write this[11] (dword at offset 0x2C) into *a2. [field:this:0x0000002C, source:raw]
    // GUARD: If a3 is non-null, write this[12] (dword at offset 0x30) into *a3. [field:this:0x00000030, source:raw]
    // CALCULATION: Set result = a4, which becomes the function's return value. [source:raw]
    // GUARD: If a4 is non-null, write this[13] (dword at offset 0x34) into *a4. [field:this:0x00000034, source:raw]
    // RETURN: Return result, i.e. the a4 output pointer, after the three conditional writes. [function:0x0054B4A0, source:raw]

    // Conservative worker pseudocode:
    //   void *ArithmeticComparison_b4a0(void *this, void *a2, void *a3, void *a4) {
    //       if (a2) *(void **)a2 = *(void **)((char *)this + 0x2C);
    //       if (a3) *(void **)a3 = *(void **)((char *)this + 0x30);
    //       if (a4) *(void **)a4 = *(void **)((char *)this + 0x34);
    //       return a4;
    //   }
    // UNRESOLVED: The three source fields are adjacent (0x2C, 0x30, 0x34) and likely a contiguous value triple, but whether they are floats, vectors, or scalars is not evidenced by the packet alone.
    // UNRESOLVED: Existing analysis labels this a per-frame query called by DualMatrixTransformMultiply; the consumer semantics of the returned a4 pointer are outside this packet.
}
