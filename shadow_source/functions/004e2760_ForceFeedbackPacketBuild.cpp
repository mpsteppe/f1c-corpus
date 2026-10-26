// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2760
// Canonical corpus name: ForceFeedback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ForceFeedback_004e2760.c

void UnknownObject::ForceFeedbackPacketBuild()
{
    // Builds a force-feedback output packet at this+0x938. Iterates 4 wheel blocks (stride 296 bytes from this+0x108) clamping each wheel type (value<24 -> value>>3 else 3), scaling the wheel force (read at v3-24) and an intensity (v3-20) by 7.0 and the force at v3+224 (this+0x1E8) by 15.0, and packing the results into a dword at this+0x938 and a word at this+0x93C. Packs steering/vibration bytes from this+0xC0, +0xAC, +0x98 scaled by 7.0/7.0/3.0 into this+0x93E. If the FFB enable flag at this+0x98C is set, iterates 17 channels from this+0x9A8, setting bitmask this+0x940 per active channel, packing two 4-bit intensity fields into this+0x93F, and clamping three force components to +/-511.98001 then scaling by 64.0 (saturating to +/-32767) into words this+0x944/+0x946/+0x948; otherwise zeroes this+0x93F/+0x940/+0x944/+0x946/+0x948. Returns this+0x938.
    // LOOP: Four-iteration wheel loop: v3 starts at this+264 (this+0x108) and advances 296 bytes per wheel; per wheel a type, two force floats and one 15.0-scaled force are read. [field:this:0x00000108, source:raw]
    // GUARD: Per-wheel type clamp: if the int at this+0x108 is < 24 the type is value >> 3, otherwise it becomes 3. [field:this:0x00000108, guard:0, source:raw]
    // CALCULATION: v5 = CRTFtol(wheelForce*7.0 + 0.5) + 8*v4; v6 = CRTFtol(wheelIntensity*7.0 + 0.5); v7 = (float at v3+224, this+0x1E8 on the first wheel) * 15.0. The wheel force and intensity floats at v3-24 and v3-20 have no field evidence. [callee:0x00587BDC, field:this:0x00000108, field:this:0x000001E8, source:raw]
    // ASSIGNMENT: v24[v2] = v6 + 8*v5 and v23[v2] = CRTFtol(v7 + 0.5), accumulating the per-wheel packed values in the two stack arrays. [callee:0x00587BDC, source:raw]
    // CALCULATION: Steering/vibration byte packing: v8 = (float at this+0xC0)*7.0, then three successive byte fields accumulate CRTFtol scales of this+0xC0, this+0xAC (7.0) and this+0x98 (3.0) with factors 8, 4 and 1. [callee:0x00587BDC, field:this:0x00000098, field:this:0x000000AC, field:this:0x000000C0, source:raw]
    // ASSIGNMENT: Write the packed per-wheel dword to this+0x938: v24[3] + ((v24[2] + ((v24[1] + (v24[0] << 8)) << 8)) << 8). [field:this:0x00000938, source:raw]
    // ASSIGNMENT: Write the packed word to this+0x93C: v23[3] + 16*(v23[2] + 16*(v23[1] + 16*v23[0])). [field:this:0x0000093C, source:raw]
    // ASSIGNMENT: Write the accumulated steering/vibration byte v9 into this+0x93E. [field:this:0x0000093E, source:raw]
    // GUARD: Branch on the FFB enable flag byte at this+0x98C (this+2444); if nonzero, pack the 17 channels, otherwise zero the FFB fields. [field:this:0x0000098C, source:raw]
    // ASSIGNMENT: Enabled branch: initialize the channel bitmask this+0x940 to 0. [field:this:0x00000940, source:raw]
    // LOOP: Seventeen-iteration channel loop: v13 starts at this+2472 (this+0x9A8) and advances 7 floats (28 bytes) per channel; the channel flag byte at v13-24 gates each channel. [field:this:0x000009A8, source:raw]
    // GUARD: Per-channel guard: if the channel flag byte at v13-24 is nonzero, the channel is packed. [field:this:0x000009A8, source:raw]
    // ASSIGNMENT: Set bit v12 of the channel bitmask: this+0x940 |= 1 << v12 for each active channel. [field:this:0x00000940, source:raw]
    // CALCULATION: Pack the two channel intensity bytes (v13-24, v13-23), each clamped to max 15, into this+0x93F = v15 + 16*v14. [field:this:0x0000093F, source:raw]
    // CALCULATION: For each of the three channel force components (v13-2, v13-1, *v13): if within +/-511.98001 multiply by 64.0, else saturate to 0x7FFF/-32767; write the three words to this+0x944, this+0x946, this+0x948. The two components at v13-2 and v13-1 have no field evidence; *v13 is the evidenced channel base this+0x9A8. [field:this:0x00000944, field:this:0x00000946, field:this:0x00000948, field:this:0x000009A8, source:raw]
    // RETURN: Enabled branch return: return this+0x938, the start of the FFB output packet. [field:this:0x00000938, source:raw]
    // ASSIGNMENT: Disabled branch: zero the FFB output fields this+0x93F, +0x940, +0x944, +0x946, +0x948. [field:this:0x0000093F, field:this:0x00000940, field:this:0x00000944, field:this:0x00000946, field:this:0x00000948, source:raw]
    // RETURN: Disabled branch return: return this+0x938, the start of the FFB output packet. [field:this:0x00000938, source:raw]

    // Conservative worker pseudocode:
    //   int ForceFeedbackPacketBuild(int this) {
    //       int v2 = 0;
    //       int v3 = this + 264;
    //       do {
    //           int v4 = (*(int*)v3 < 24) ? (*(int*)v3 >> 3) : 3;
    //           int v5 = CRTFtol(*(float*)(v3 - 24) * 7.0 + 0.5) + 8 * v4;
    //           int v6 = CRTFtol(*(float*)(v3 - 20) * 7.0 + 0.5);
    //           double v7 = *(float*)(v3 + 224) * 15.0;
    //           v24[v2] = v6 + 8 * v5;
    //           v23[v2++] = CRTFtol(v7 + 0.5);
    //           v3 += 296;
    //       } while (v2 < 4);
    //       double v8 = *(float*)(this + 192) * 7.0;
    //       int v9 = v23[2];
    //       int v10 = 16 * v23[0];
    //       *(DWORD*)(this + 2360) = v24[3] + ((v24[2] + ((v24[1] + (v24[0] << 8)) << 8)) << 8);
    //       *(WORD*)(this + 2364) = v23[3] + 16 * (v9 + 16 * (v23[1] + v10));
    //       LOBYTE(v9) = 8 * CRTFtol(v8 + 0.5);
    //       LOBYTE(v9) = 4 * (CRTFtol(*(float*)(this + 172) * 7.0 + 0.5) + v9);
    //       LOBYTE(v9) = CRTFtol(*(float*)(this + 152) * 3.0 + 0.5) + v9;
    //       char v11 = *(BYTE*)(this + 2444);
    //       *(BYTE*)(this + 2366) = v9;
    //       if (v11) {
    //           *(DWORD*)(this + 2368) = 0;
    //           int v12 = 0;
    //           float* v13 = (float*)(this + 2472);
    //           do {
    //               if (*((BYTE*)v13 - 24)) {
    //                   *(DWORD*)(this + 2368) |= 1 << v12;
    //                   char v14 = *((BYTE*)v13 - 24); if ((BYTE)v14 > 0xF) v14 = 15;
    //                   char v15 = *((BYTE*)v13 - 23); if ((BYTE)v15 > 0xF) v15 = 15;
    //                   *(BYTE*)(this + 2367) = v15 + 16 * v14;
    //                   short v16 = clamp_scale(*(v13 - 2));
    //                   short v17 = clamp_scale(*(v13 - 1));
    //                   short v18 = clamp_scale(*v13);
    //                   *(WORD*)(this + 2372) = v16;
    //                   *(WORD*)(this + 2374) = v17;
    //                   *(WORD*)(this + 2376) = v18;
    //               }
    //               ++v12; v13 += 7;
    //           } while (v12 < 17);
    //           return this + 2360;
    //       }
    //       *(BYTE*)(this + 2367) = 0;
    //       *(DWORD*)(this + 2368) = 0;
    //       *(WORD*)(this + 2372) = 0;
    //       *(WORD*)(this + 2374) = 0;
    //       *(WORD*)(this + 2376) = 0;
    //       return this + 2360;
    //   }
    // UNRESOLVED: Seven read-only globals (flt_59E450, flt_59E478, flt_59E708, flt_59E70C, flt_59E710, flt_59E864, flt_59E8D8) are reported referenced but do not appear in the inlined raw source; their binding to the float literals (7.0, 15.0, 3.0, 64.0, 511.98001, 0.5) is unconfirmed.
    // UNRESOLVED: The per-channel sub-fields at v13-24 (flag), v13-23 (intensity byte B), v13-2 and v13-1 (two force components) have no field evidence refs; only the channel base this+0x9A8 is evidenced.
    // UNRESOLVED: The wheel force floats read at v3-24 and v3-20 have no field evidence refs.
    // UNRESOLVED: The exact bit-field semantics of the packed word at this+0x93C and byte at this+0x93E (steering/vibration) are not resolved beyond the packing expression.
    // UNRESOLVED: A single caller, sub_4EF2E0, is recorded; the call context and how the returned packet at this+0x938 is consumed are unknown.
    // UNRESOLVED: The owner class and the meaning of the legacy ABI label Force_Feedback_Controller_Output_Packing are unconfirmed.
}
