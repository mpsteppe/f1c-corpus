// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407D40
// Canonical corpus name: ShortComputation_7d40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_7d40_00407d40.c

void UnknownObject::setAudioDirectionFromAngles()
{
    // Direction/angle store helper (thiscall on an audio sample object): copies a 3-int triple from a2 into this+0x58/0x5C/0x60 and a 3-float angle triple from a3 into this+0x64/0x68/0x6C, then computes trig terms from a3[1] (and a3[0] folded through a multiply-by-0.0) and stores them at this+0x70 (cosine-derived), this+0x74 (zero) and this+0x78 (sine-derived). Returns the low dword of the float stored at this+0x78.
    // ASSIGNMENT: Copy the 3-int triple: this+0x58 = a2[0], this+0x5C = a2[1], this+0x60 = a2[2]. [field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060]
    // ASSIGNMENT: Copy the 3-float angle triple: this+0x64 = a3[0], this+0x68 = a3[1], this+0x6C = a3[2]. [field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C]
    // CALCULATION: Trig seed terms: v7 = -cos(a3[1]) using the second angle (this+0x68); v9 = -sin(a3[0]) * 0.0 using the first angle (this+0x64), a multiply by literal zero. [field:this:0x00000068, field:this:0x00000064, source:raw]
    // CALCULATION: Combine terms: v3 = v9 - v7; v4 = sin(a3[1]); v5 = v7 * 0.0 - v4 * 0.0; v8 = v4 - v9. The multiply-by-0.0 terms reduce to zero in floating point. [field:this:0x00000068, source:raw]
    // ASSIGNMENT: Store the results: this+0x70 = v3 (cosine-derived), this+0x74 = v5 (zero term), this+0x78 = v8 (sine-derived). [field:this:0x00000070, field:this:0x00000074, field:this:0x00000078]
    // RETURN: Return result = LODWORD(v8), the low dword of the float stored at this+0x78. [source:raw]
    // CALL: Invoked by AudioSamplePositionVolumeSetter (004071F0) to refresh the sample object's direction/trig terms during position/volume updates. [caller:0x004071F0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_407D40(int this, int *a2, float *a3) {
    //     *(int *)(this + 0x58) = a2[0]; *(int *)(this + 0x5C) = a2[1]; *(int *)(this + 0x60) = a2[2];
    //     *(float *)(this + 0x64) = a3[0]; *(float *)(this + 0x68) = a3[1]; *(float *)(this + 0x6C) = a3[2];
    //     float cosT = -cos(a3[1]);
    //     float zero = -sin(a3[0]) * 0.0f;
    //     float v3 = zero - cosT;
    //     float sinT = sin(a3[1]);
    //     float v5 = cosT * 0.0f - sinT * 0.0f;
    //     float v8 = sinT - zero;
    //     *(float *)(this + 0x70) = v3;
    //     *(float *)(this + 0x74) = v5;
    //     *(float *)(this + 0x78) = v8;
    //     return LODWORD(v8);
    //   }
    // UNRESOLVED: The read-only global flt_59E440 is flagged by packet facts but never appears in the raw decompiled source; it may be the zero constant folded into the multiply-by-0.0 terms, not verifiable here.
    // UNRESOLVED: The role of the 3-int triple copied to this+0x58..0x60 is established only by the caller (004071F0), not by this function.
    // UNRESOLVED: The multiply-by-0.0 terms are compiler artifacts of an expression reduced to zero; the original formula is not recoverable from the raw source.
}
