// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00435410
// Canonical corpus name: SuspensionSetupSectionReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SuspensionSetupSectionReader_00435410.c

void UnknownObject::SuspensionSetupSectionReader()
{
    // Reads a suspension setup section from a configuration stream. Copies the body anchor (a4) into this+0x4/0xC/0x14 and the rotation reference (a5) into this+0x4C region, stores the setup index a2 into this+0x0. When a2 is non-zero and the stream opens, parses tokenized fields: head mass (obj:0xAC and its reciprocal obj:0xB4), head inertia, min/max position, min/max orientation (deg-to-rad via 0.0174532925199433), and a spring list — growing the spring array (this:0x94 capacity, this:0x98 count, this:0x9C pointer) as needed, classifying each spring as sliding/normal/free-damping (0/1/2), and reading per-spring direction, head anchor, body anchor (converted through the rotation matrix), collision length and spring parameters. Returns the SubCallWithConditionalFieldFree result on exit, or the stored a2 when the setup index is zero.
    // CALL: PhysicsBufferClear() — reset the physics/parse buffer before reading. [callee:0x004358F0, function:0x00435410, source:raw]
    // ASSIGNMENT: qmemcpy(this + 1, a4, 0x18u) copies the body-anchor block into this:0x4/0xC/0x14; qmemcpy(this + 19, a5, 0x18u) copies the rotation-reference block into this+0x4C region (raw-source location); *this = a2 stores the setup index into this:0x0. [field:this:0x00000000, field:this:0x00000004, field:this:0x0000000C, field:this:0x00000014, function:0x00435410, source:raw]
    // GUARD: If a2 (the setup index) is non-zero, enter the parse path; otherwise return a2 unchanged. [function:0x00435410, source:raw]
    // CALL: ZeroInitSmallStruct(v27); initialize the per-spring parse scratch state. [callee:0x005668B0, function:0x00435410, source:raw]
    // GUARD: If AudioStreamOpen(a3, 1) returns non-zero, proceed to the tokenized field reading; otherwise skip to the cleanup return. [callee:0x00566B20, function:0x00435410, source:raw]
    // ASSIGNMENT: memset(v48, 0, sizeof(v48)); reset local read state v43 = 0, v47 = 0, v45 = 0, v46 = 0 and set v44 = 1. [function:0x00435410, source:raw]
    // LOOP: If ConditionalDispatchBasedOnFlag(v48, 384): loop while sub_5651B0(v42) reads the next line into v42; on each iteration process the line and re-check ConditionalDispatchBasedOnFlag(v48, 384); if the flag clears, return SubCallWithConditionalFieldFree(v27). [callee:0x00566CC0, callee:0x005651B0, callee:0x005668D0, function:0x00435410, source:raw]
    // GUARD: If sub_565AA0(aHeadmass, &v26, 0, 0, 0): write *(double *)(*this + 172) = v26 into obj:0xAC (head mass) and *(double *)(*this + 180) = 1.0 / v8 into obj:0xB4 (reciprocal head mass). [callee:0x00565AA0, global:0x005C412C, field:obj:0x000000AC, field:obj:0x000000B4, function:0x00435410, source:raw]
    // GUARD: If sub_565AA0(aHeadinertia, v28, v29, v30, 0): call StructCopyWithReciprocalDivision(v28) to copy the head-inertia values with reciprocal handling. [callee:0x00565AA0, callee:0x005697A0, global:0x005C4120, function:0x00435410, source:raw]
    // CALL: sub_565AA0(aMinpos, this + 7, this + 9, this + 11, 0) reads the minimum position triple; sub_565AA0(aMaxpos, this + 13, this + 15, this + 17, 0) reads the maximum position triple (destinations at raw-source offsets, not packet fields). [callee:0x00565AA0, global:0x005C4118, global:0x005C4110, function:0x00435410, source:raw]
    // GUARD: If sub_565AA0(aMinori, this + 25, this + 27, this + 29, 0): convert this:0x64/0x6C/0x74 (min orientation) from degrees to radians by multiplying by 0.0174532925199433. Same for aMaxori into this:0x7C/0x84/0x8C. [callee:0x00565AA0, global:0x005C4108, global:0x005C4100, field:this:0x00000064, field:this:0x0000006C, field:this:0x00000074, field:this:0x0000007C, field:this:0x00000084, field:this:0x0000008C, function:0x00435410, source:raw]
    // GUARD: If sub_565520(aSpring, v41, 0): grow the spring array when needed — if this:0x98 (count, this[38]) >= this:0x94 (capacity, this[37]), grow capacity by 3 (v10 = this[37] + 3), allocate OperatorNewNhMallocWrapper(100 * v10), initialize each entry via CategoryScoringStateInitializer, copy existing entries (this:0x98 > 0, guard:0) from the old pointer this:0x9C, free the old array with FreeWrapper_7bcf, and store the new pointer into this:0x9C. [callee:0x00565520, field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C, callee:0x00587C03, callee:0x00435390, callee:0x00587BCF, guard:0, function:0x00435410, source:raw]
    // GUARD: Classify the new spring: if sub_588410(v41, aSliding) write the current spring slot type 0; else if aNormal write 1; else if aFreedamping write 2; then increment the spring count this:0x98. The slot address is computed as 100 * this:0x98 + this:0x9C. [callee:0x00588410, global:0x005C40F0, global:0x005C40E8, global:0x005C40DC, global:0x005C40F8, field:this:0x00000098, field:this:0x0000009C, function:0x00435410, source:raw]
    // GUARD: v19 = this:0x98 - 1; if v19 in [0, this:0x94): v20 = this:0x9C + 100 * v19; sub_565AA0(aSpringdir, v20 + 4, ...) reads spring direction; sub_565AA0(aSpringhead, v20 + 28, ...) reads the head anchor; if sub_565AA0(aSpringbody, &v23, &v24, &v25, 0): call EulerAnglesTo33RotationMatrix(this + 19) and write the body-anchor world coordinates (from the rotation matrix) into the spring entry at v20 + 52/60/68. [field:this:0x00000098, field:this:0x00000094, field:this:0x0000009C, callee:0x00565AA0, callee:0x0056BD40, global:0x005C40D0, global:0x005C40C4, global:0x005C40B8, function:0x00435410, source:raw]
    // CALL: sub_565AA0(aSpringcolllen, v20 + 76, 0, 0, 0) reads the spring collision length; sub_565AA0(aSpringparams, v20 + 84, v20 + 92, 0, 0) reads the spring parameters into the entry. [callee:0x00565AA0, global:0x005C40A8, global:0x005C4098, function:0x00435410, source:raw]
    // STATE_TRANSITION: After each parsed line, loop back to LABEL_39 and re-check ConditionalDispatchBasedOnFlag(v48, 384); when the flag clears or the stream ends, return SubCallWithConditionalFieldFree(v27). [callee:0x00566CC0, callee:0x005668D0, function:0x00435410, source:raw]
    // RETURN: Return result (a2) when the setup index was zero or the stream did not open; otherwise return the SubCallWithConditionalFieldFree(v27) result. [function:0x00435410, source:raw]

    // Conservative worker pseudocode:
    //   PhysicsBufferClear();
    //   result = a2;
    //   qmemcpy(this + 1, a4, 0x18);  /* this:0x4 body anchor * /
    //   qmemcpy(this + 19, a5, 0x18); /* this:0x4C rotation reference * /
    //   *this = a2;
    //   if (a2) {
    //     ZeroInitSmallStruct(v27);
    //     if (AudioStreamOpen(a3, 1)) {
    //       memset(v48, 0, sizeof(v48)); v44 = 1;
    //       if (ConditionalDispatchBasedOnFlag(v48, 384)) {
    //         while (sub_5651B0(v42)) {
    //           /* per-line processing: * /
    //           if (!ConditionalDispatchBasedOnFlag(v48, 384)) return SubCallWithConditionalFieldFree(v27);
    //           if (sub_565AA0(aHeadmass, &v26, 0, 0, 0)) {
    //             *(double*)(*this + 172) = v26;        /* obj:0xAC * /
    //             *(double*)(*this + 180) = 1.0 / v26;  /* obj:0xB4 * /
    //           }
    //           if (sub_565AA0(aHeadinertia, v28, v29, v30, 0)) StructCopyWithReciprocalDivision(v28);
    //           sub_565AA0(aMinpos, this + 7, this + 9, this + 11, 0);
    //           sub_565AA0(aMaxpos, this + 13, this + 15, this + 17, 0);
    //           if (sub_565AA0(aMinori, this + 25, this + 27, this + 29, 0)) {
    //             this[25] *= 0.0174532925199433; this[27] *= 0.0174532925199433; this[29] *= 0.0174532925199433;
    //           }
    //           if (sub_565AA0(aMaxori, this + 31, this + 33, this + 35, 0)) {
    //             this[31] *= 0.0174532925199433; this[33] *= 0.0174532925199433; this[35] *= 0.0174532925199433;
    //           }
    //           if (sub_565520(aSpring, v41, 0)) {
    //             if (this[38] >= this[37]) {  /* grow spring array * /
    //               v10 = this[37] + 3; this[37] = v10;
    //               v11 = OperatorNewNhMallocWrapper(100 * v10);
    //               init entries via CategoryScoringStateInitializer;
    //               copy existing entries from this[39];
    //               if (this[39]) FreeWrapper_7bcf((LPVOID)this[39]);
    //               this[39] = (int)v11;
    //             }
    //             if (!sub_588410(v41, aSliding))    slot type = 0;
    //             else if (!sub_588410(v41, aNormal)) slot type = 1;
    //             else if (!sub_588410(v41, aFreedamping)) slot type = 2;
    //             ++this[38];  /* this:0x98 * /
    //           }
    //           v19 = this[38] - 1;
    //           if (v19 >= 0 && v19 < this[37]) {
    //             v20 = this[39] + 100 * v19;
    //             sub_565AA0(aSpringdir, v20 + 4, v20 + 12, v20 + 20, 0);
    //             sub_565AA0(aSpringhead, v20 + 28, v20 + 36, v20 + 44, 0);
    //             if (sub_565AA0(aSpringbody, &v23, &v24, &v25, 0)) {
    //               EulerAnglesTo33RotationMatrix(this + 19);
    //               write body-anchor world coordinates into v20 + 52/60/68;
    //             }
    //             sub_565AA0(aSpringcolllen, v20 + 76, 0, 0, 0);
    //             sub_565AA0(aSpringparams, v20 + 84, v20 + 92, 0, 0);
    //           }
    //         }
    //       }
    //     }
    //     return SubCallWithConditionalFieldFree(v27);
    //   }
    //   return result;
    // UNRESOLVED: Globals dbl_59E420 and dbl_59EAE8 are listed as read in the packet but do not appear in the raw source; they may hold the degree-to-radian constant (0.0174532925199433 is inlined in the raw text) or other tuning constants, but their exact role is unknown.
    // UNRESOLVED: Several parse destinations are not packet fields and are inferred from the raw code only: the min/max position triples (this + dword indices 7/9/11 and 13/15/17), the rotation reference (this + 19), and the per-spring sub-offsets (v20 + 4..92).
    // UNRESOLVED: The identity and exact grammar of the token strings (aSpringparams etc.) are known from the packet globals; the parser helpers sub_5651B0 / sub_565520 / sub_565AA0 / sub_588410 semantics are not detailed here.
    // UNRESOLVED: Caller sub_438F00 (0x00438F00) is known but was not used in any operation.
}
