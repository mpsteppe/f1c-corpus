// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D0B20
// Canonical corpus name: F_3DDistanceCheckAccumulate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DDistanceCheckAccumulate_004d0b20.c

void UnknownObject::F_3DDistanceCheckAccumulate()
{
    // Iterates a list of elements (count this+0x0, array pointer this+0x4, stride 132 bytes). Reference position comes from a virtual dispatch on the SessionManager global dword_5EA510. For each valid element (flag at element+104 non-zero), reads its position via TripleFieldQuery, computes the squared 3D distance to the reference position, and when that squared distance is below 1024.0 (i.e. within 32 units) accumulates the parameter a2 into the element's float at +128, conditionally subtracting the value at +124, then calls sub_4A2840(element+4, accumulated). Returns the element count.
    // CALL: Virtual dispatch on the SessionManager global dword_5EA510 via VirtualDispatchHelper to obtain the reference position/transform pointer. [source:raw, callee:0x0040C870, global:0x005EA510]
    // ASSIGNMENT: Negate the three reference-position floats to build a vector used for the delta calculation. [source:raw]
    // GUARD: Count guard: this+0x0 <= 0 skips the accumulation loop entirely; the loop runs only when the count is positive. [source:raw, field:this:0x00000000, guard:0]
    // LOOP: Iterate the element array rooted at this+0x4 with a stride of 132 bytes. [source:raw, field:this:0x00000004]
    // GUARD: Per-element validity check: the dword at element+104 must be non-zero before the element is processed. [source:raw]
    // CALL: Read the element's three position floats (X, Y, Z) into locals via TripleFieldQuery. [source:raw, callee:0x0054B420]
    // CALCULATION: Compute the delta vector by subtracting the negated reference position from the element position. [source:raw]
    // CALCULATION: Squared-distance check: dx*dx + dy*dy + dz*dz < 1024.0 (equivalent to a 32-unit radius). [source:raw]
    // CALCULATION: Accumulate parameter a2 into the element's float at +128; under a flag-derived condition (carry/borrow from the distance compare) the value at +124 is subtracted from the accumulator. [source:raw]
    // CALL: Call sub_4A2840(element+4, accumulatedValue) to process the updated element. [source:raw, callee:0x004A2840]
    // RETURN: Return the element count from this+0x0. [source:raw, field:this:0x00000000]

    // Conservative worker pseudocode:
    //   int sub_4D0B20(int *this, float a2) {
    //     float *ref = (float *)VirtualDispatchHelper(&dword_5EA510) + 3;
    //     float rx = -ref[0], ry = -ref[1], rz = -ref[2];
    //     if (*this <= 0) return *this;
    //     for (int i = 0; i < *this; ++i) {
    //       int elem = this[1] + i * 132;
    //       if (*(int *)(elem + 104) != 0) {
    //         float x, y, z;
    //         TripleFieldQuery(&x, &y, &z);
    //         x -= rx; y -= ry; z -= rz;
    //         if (z * z + y * y + x * x < 1024.0f) {
    //           float acc = a2 + *(float *)(elem + 128);
    //           *(float *)(elem + 128) = acc;
    //           if (/* carry/borrow flag condition * / 1)
    //             *(float *)(elem + 128) = acc - *(float *)(elem + 124);
    //           sub_4A2840(elem + 4, *(float *)(elem + 128));
    //         }
    //       }
    //     }
    //     return *this;
    //   }
    // UNRESOLVED: The global flt_5ACEE4 is listed in the packet globals but does not appear in the provided raw source text; its role in this function is unclear.
    // UNRESOLVED: The decompiler's v16|v17 flags (carry/borrow from the squared-distance compare) gate the subtraction of the element+124 value from the accumulator; the exact conditional semantics are unresolved.
    // UNRESOLVED: The meaning of the element fields at +4, +104, +124, +128 and of sub_4A2840's action depend on the element type, which is not established here.
}
