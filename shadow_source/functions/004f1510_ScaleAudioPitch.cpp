// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1510
// Canonical corpus name: ScaleAudioPitch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScaleAudioPitch_004f1510.c

void UnknownObject::ScaleAudioPitch()
{
    // Scales audio pitch and wheel RPM values by a speed ratio (a2 / previous value stored at this+0x3BF4), gated by physics-random flag bits of byte_7D01C4: bit 0 drives a pair-wise running update over an 8-byte-strided array (count this+0x39B0, base pointer this+0x39A4), bit 1 scales a second array at this+0x39D0 by the reciprocal ratio, bit 4 scales the pitch-scale field this+0x3984; then stores a2 as the new previous value and runs the tire brush model solver.
    // ASSIGNMENT: Compute pitch/speed ratio v14 = a2 / previous value stored at field this+0x3BF4 under the thiscall ABI lead. [abi:lead, field:this:0x00003BF4, source:raw]
    // LOOP: Scale four float elements starting at this+0x361C with stride 0xF8, multiplying each by ratio v14. [source:raw]
    // GUARD: Flag guard: physics-random flag bit 0 of byte_7D01C4. [global:0x007D01C4, source:raw]
    // CALL: Call sub_5881F0(v14) to scale pitch parameter arrays. [callee:0x005881F0, source:raw]
    // LOOP: For i in 0..count-1 (count = field this+0x39B0), apply a pair-wise running update over 8-byte-strided entries of the array at field this+0x39A4: entry[i+1] = (entry[i] + entry[i+1]) * v14 - entry[i]. [field:this:0x000039B0, field:this:0x000039A4, source:raw]
    // GUARD: Flag guard: physics-random flag bit 1 of byte_7D01C4. [global:0x007D01C4, source:raw]
    // CALL: Call sub_5881F0(v14). [callee:0x005881F0, source:raw]
    // GUARD: Guard: field this+0x39F8 (gear/parameter count) >= 1 before scaling the second array. [guard:0, field:this:0x000039F8, source:raw]
    // LOOP: Scale entries of the float array at this+0x39D0 by 1/v14; every 9th processed element (index 917) advances the pointer by 918 elements instead of 1 (per-element stride pattern). [source:raw]
    // GUARD: Flag guard: physics-random flag bit 2 of byte_7D01C4. [global:0x007D01C4, source:raw]
    // CALL: Call sub_5881F0(v14). [callee:0x005881F0, source:raw]
    // CALCULATION: Scale pitch-scale field this+0x3984 by ratio v14. [field:this:0x00003984, source:raw]
    // ASSIGNMENT: Store new input a2 back into field this+0x3BF4 as the previous value for the next frame. [field:this:0x00003BF4, source:raw]
    // CALL: Solve the tire brush model: TireBrushModelForceSolver(this, 0). [callee:0x004E8010, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4F1510(int this, float a2) {
    //     float ratio = a2 / *(float*)(this + 0x3BF4);
    //     for (int k = 0; k < 4; k++)
    //       *(float*)(this + 0x361C + k * 0xF8) *= ratio;
    //     if (byte_7D01C4 & 1) {
    //       sub_5881F0(ratio);
    //       for (int i = 0; i < *(int*)(this + 0x39B0); i++) {
    //         float* p = (float*)(*(int*)(this + 0x39A4) + 8 * i);
    //         float cur = *p;
    //         p[1] = (cur + p[1]) * ratio - cur;
    //       }
    //     }
    //     if (byte_7D01C4 & 2) {
    //       sub_5881F0(ratio);
    //       int n = *(int*)(this + 0x39F8);
    //       if (n >= 1) {
    //         float* p = (float*)(this + 0x39D0);
    //         int j = 1;
    //         do {
    //           float inv = 1.0f / ratio;
    //           if (++j == 9) { float s = inv * p[917]; p += 918; *(p - 1) = s; }
    //           else          { float s = inv * *p; *p = s; p++; }
    //         } while (j <= n);
    //       }
    //     }
    //     if (byte_7D01C4 & 4) {
    //       sub_5881F0(ratio);
    //       *(float*)(this + 0x3984) *= ratio;
    //     }
    //     *(float*)(this + 0x3BF4) = a2;
    //     TireBrushModelForceSolver(this, 0);
    //   }
    // UNRESOLVED: Four packet globals (flt_59E43C, dbl_59EB50, dbl_5AD240, dbl_5AD248) are read by the raw function but do not appear in the decompiled C text; their exact role is unresolved.
    // UNRESOLVED: Field this+0x4824 is listed as read but is absent from the decompiled body; possibly consumed inside sub_5881F0 or a folded path.
    // UNRESOLVED: The 8-byte-stride array at this+0x39A4 and the special 918-element stride in the second loop are derived from raw arithmetic; the underlying container layout is unknown.
}
