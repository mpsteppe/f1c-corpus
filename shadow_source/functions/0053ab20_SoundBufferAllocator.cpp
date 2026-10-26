// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053AB20
// Canonical corpus name: SoundBufferAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SoundBufferAllocator_0053ab20.c

void UnknownObject::SoundBufferAllocator()
{
    // Sound buffer constructor. Stores the size parameter a2 into field 0x0, computes a log2-based index into field 0x4 via CRTFtol over a __FYL2X__ product, allocates a buffer of (8 * a2 + 16) bytes into field 0xC, zeroes fields 0x10 and 0x14, and calls CurveSplinePointGenerator with a3 before returning this.
    // ASSIGNMENT: Store size parameter a2 into field 0x0 (this[0]). [source:raw, field:this:0x00000000]
    // CALCULATION: Compute log2-based index: __FYL2X__((double)a2, 0.6931471805599453094) * 1.442695036924675, converted by CRTFtol, and store the result into field 0x4 (this[1]). [source:raw, field:this:0x00000004, callee:0x00587BDC, global:0x005B8908]
    // CALL: Call OperatorNewNhMallocWrapper(8 * a2 + 16) and store the returned buffer pointer into field 0xC (this[3]). [source:raw, field:this:0x0000000C, callee:0x00587C03]
    // ASSIGNMENT: Initialize field 0x14 (this[5]) to 0. [source:raw, field:this:0x00000014]
    // ASSIGNMENT: Initialize field 0x10 (this[4]) to 0. [source:raw, field:this:0x00000010]
    // CALL: Call CurveSplinePointGenerator with argument a3 for curve/spline setup. [source:raw, callee:0x0053AB80]
    // RETURN: Return the initialized this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   int* SoundBufferAllocator(int* this, int size, int a3) {
    //     this[0] = size;
    //     this[1] = CRTFtol(__FYL2X__((double)size, 0.6931471805599453094) * 1.442695036924675);
    //     this[3] = OperatorNewNhMallocWrapper(8 * size + 16);
    //     this[5] = 0;
    //     this[4] = 0;
    //     CurveSplinePointGenerator(a3);
    //     return this;
    //   }
    // UNRESOLVED: Field 0x4 semantics: log2-based size index; exact consumer and purpose not evidenced here.
    // UNRESOLVED: Field 0xC buffer layout and the sample format it holds are not evidenced by this function.
    // UNRESOLVED: dbl_5B8908 role: read as one of the two log2 constants in the index computation, but which value it supplies is not determinable from this packet.
    // UNRESOLVED: a3 and the CurveSplinePointGenerator purpose are caller-dependent.
}
