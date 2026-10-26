// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00434460
// Canonical corpus name: CarSelectionStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CarSelectionStateMachine_00434460.c

void UnknownObject::updateCarSelectionStateMachine()
{
    // Pre-race car selection / grid camera state machine. The function is driven by a byte init flag at this+0x0 and a phase dword at this+0x4 (states 0=init, 1=countdown, 2=wait, 3/4=advance, 5=end countdown). On first call it runs ModuleInitializationWithFallback; otherwise it advances two timers (this[9] countdown and this[10] accumulator) by the frame delta dbl_8AFE98, walks a score gate (ScoreThresholdGateCheck 520) and a state flag check (StateFlagCheck_5240), advances a vehicle-slot counter at this+0x18, scans the active vehicle-pointer array dword_7C54F0 for the next grid position (comparing slot struct byte 16480), triggers IteratorCheck / PitExit, and then always finishes in a camera block that feeds session-object parameters through StridedArrayElementPointer, SteeringInterpolationCameraFollow, UtilityFunction_1cd0, DualFieldGetter, ShortComputation_6080, sub_542050, TwoFieldSetterCall and ConditionalFloatSetter.
    // GUARD: Read the initialization-complete byte at this+0x0; when it is zero the state machine is uninitialized and the initialization path runs. [field:this:0x00000000, guard:0, source:raw]
    // CALL: First-run path: call ModuleInitializationWithFallback() and store its result as the return value (v2/v22). [callee:0x00434820, source:raw]
    // STATE_TRANSITION: State 0 to 1: call sub_4D8760(2, 1), set the phase field at this+0x4 to 1, clear the accumulator this[10] (float index 10, byte 0x28) and arm the countdown timer this[9] (float index 9, byte 0x24) with 3.0. [callee:0x004D8760, field:this:0x00000004, field:this:0x00000024, field:this:0x00000028, source:raw]
    // CALCULATION: State 1 countdown: decrement this[9] by the frame delta dbl_8AFE98; when it reaches 0 or below, transition to state 2 and re-arm this[9] with 2.0. [field:this:0x00000024, field:this:0x00000004, global:0x008AFE98, source:raw]
    // CALCULATION: Accumulator update reached by several paths: this[10] (byte 0x28) is increased by the frame delta dbl_8AFE98 each tick. [field:this:0x00000028, global:0x008AFE98, source:raw]
    // STATE_TRANSITION: State 5 (end countdown): when this[9] reaches 0 or below the machine is finished (return value 1); otherwise keep decrementing this[9] by dbl_8AFE98. [field:this:0x00000024, global:0x008AFE98, source:raw]
    // GUARD: In the general (non-init, non-state-1, non-state-5) path the camera-follow flag byte v21 is set to 1, and the score gate ScoreThresholdGateCheck(520) is tested before advancing. [callee:0x00418B90, source:raw]
    // GUARD: When the score gate passes, StateFlagCheck_5240(this) is tested to decide whether the vehicle-advance block runs. [callee:0x00435240, source:raw]
    // ASSIGNMENT: Advance block: increment the vehicle-slot counter at this+0x18 (v6 = counter + 1) and store v6 + 3 into the target field at this+0x2C. [field:this:0x00000018, field:this:0x0000002C, source:raw]
    // LOOP: If the new counter v6 is below the grid-size bound dword_5C329C, scan the active vehicle-pointer array dword_7C54F0 for the entry whose slot struct field at byte 16480 equals v6 + 1; record the matching index into this+0x1C. [field:this:0x0000001C, global:0x005C329C, global:0x007C54F0, source:raw]
    // CALL: After the scan succeeds, call IteratorCheck(&dword_8AD298) and PitExit(dword_5EB978, counter at this+0x18) to trigger the next car's pit exit. [callee:0x004D88B0, callee:0x0041C0F0, global:0x008AD298, global:0x005EB978, field:this:0x00000018, source:raw]
    // STATE_TRANSITION: If the counter reaches the grid bound: set state 5, roll the counter back to v6 - 1 and re-arm this[9] with 3.0. [field:this:0x00000004, field:this:0x00000018, field:this:0x00000024, source:raw]
    // STATE_TRANSITION: Score gate fails: while the wait timer this[13] (byte 0x34) is positive it is decremented by dbl_8AFE98; when it hits 0 the timer is re-armed with 2.25 and the same vehicle-advance block runs (counter + 1, target + 3, scan of dword_7C54F0, this+0x1C index, IteratorCheck, or state 5 rollback). [field:this:0x00000034, field:this:0x00000018, field:this:0x0000002C, field:this:0x0000001C, global:0x008AFE98, global:0x005C329C, global:0x007C54F0, callee:0x004D88B0, source:raw]
    // STATE_TRANSITION: State 2 (wait): set the target field at this+0x2C to 1; when StateFlagCheck_5240(this) is true transition to state 4 and call sub_4D8760(0, 1). [field:this:0x0000002C, field:this:0x00000004, callee:0x00435240, callee:0x004D8760, source:raw]
    // GUARD: Camera block gate: read the session/camera object pointer at this+0xC (v14); if it is null or its validity byte at offset 0xB0 is zero, return the saved result. [field:this:0x0000000C, field:*(this+0xC):0x000000B0, source:raw]
    // CALL: Read the target value at this+0x2C into v20 and the threshold float at object offset 0xBC (byte 188) into v23; resolve v20 through StridedArrayElementPointer and, when the resolved element's float at byte 24 exceeds v23, call SteeringInterpolationCameraFollow with the camera-follow flag byte v21. [field:this:0x0000002C, field:*(this+0xC):0x000000BC, callee:0x004582A0, callee:0x00434D60, source:raw]
    // CALL: Call ShortComputation_c910(&dword_5EA510) to update the shared camera/selection state. [callee:0x0040C910, global:0x005EA510, source:raw]
    // ASSIGNMENT: Re-read the object pointer at this+0xC (v16); when null return the saved result. Otherwise publish it to dword_5EA538 and set the byte_5EA535 flag to 1. [field:this:0x0000000C, global:0x005EA538, global:0x005EA535, source:raw]
    // CALL: Call UtilityFunction_1cd0 with six fields of the session object: dword +12, dword +16, float +20, dword +24, dword +28 and dword +32. [callee:0x00541CD0, field:*(this+0xC):0x0000000C, field:*(this+0xC):0x00000010, field:*(this+0xC):0x00000014, field:*(this+0xC):0x00000018, field:*(this+0xC):0x0000001C, field:*(this+0xC):0x00000020, source:raw]
    // CALL: Read two derived values via DualFieldGetter(&v21, &v23) and ShortComputation_6080(&v25, &v24). [callee:0x00456060, callee:0x00456080, source:raw]
    // CALCULATION: Convert degrees to radians by scaling v21 and v23 by 0.01745433, then call sub_542050(v18, v19, 0) with the two scaled angles. [callee:0x00542050, source:raw]
    // CALL: Call TwoFieldSetterCall(v25, v24) with the two derived values from ShortComputation_6080. [callee:0x005423C0, source:raw]
    // CALL: Call ConditionalFloatSetter with the session object's float at offset 0x48 (byte 72). [callee:0x00542680, field:*(this+0xC):0x00000048, source:raw]
    // RETURN: Return the stored result v22 (the module-init result on the first-run path, otherwise the value computed during the state walk). [source:raw]

    // Conservative worker pseudocode:
    //   int updateCarSelectionStateMachine(float *this) {
    //     int result = 0;
    //     if (!*(char*)this) {
    //       result = ModuleInitializationWithFallback();
    //       flagByte = 0;
    //       goto cameraBlock;
    //     }
    //     int state = *((int*)this + 1);  // this+0x4 phase field
    //     if (!state) {
    //       sub_4D8760(2, 1);
    //       *((int*)this + 1) = 1;
    //       this[10] = 0.0f;
    //       this[9] = 3.0f;
    //       goto cameraBlock;
    //     }
    //     if (state == 1) {
    //       if (this[9] <= 0.0f) { *((int*)this + 1) = 2; this[9] = 2.0f; }
    //       else this[9] -= dbl_8AFE98;
    //       goto accumulate;
    //     }
    //     flagByte = 1;
    //     if (state != 2) {
    //       if (state == 5) {
    //         if (this[9] <= 0.0f) result = 1;
    //         else this[9] -= dbl_8AFE98;
    //         goto cameraBlock;
    //       }
    //       if (ScoreThresholdGateCheck(520)) {
    //         if (StateFlagCheck_5240(this)) {
    //           int v6 = *((int*)this + 6) + 1;
    //           *((int*)this + 6) = v6;
    //           *((int*)this + 11) = v6 + 3;
    //           if (v6 < dword_5C329C) {
    //             for (int i = 0; i < dword_5C329C; i++) {
    //               this[7] = 0.0f;
    //               if (*(int*)(dword_7C54F0[i] + 16480) == v6 + 1) { *((int*)this + 7) = i; break; }
    //             }
    //             IteratorCheck(&dword_8AD298);
    //             PitExit(dword_5EB978, *((int*)this + 6));
    //           } else {
    //             *((int*)this + 1) = 5;
    //             *((int*)this + 6) = v6 - 1;
    //             this[9] = 3.0f;
    //           }
    //         }
    //       } else if (this[13] > 0.0f) {
    //         this[13] -= dbl_8AFE98;
    //       } else {
    //         this[13] = 2.25f;
    //         int v10 = *((int*)this + 6) + 1;
    //         *((int*)this + 6) = v10;
    //         *((int*)this + 11) = v10 + 3;
    //         if (v10 < dword_5C329C) {
    //           for (int j = 0; j < dword_5C329C; j++) {
    //             this[7] = 0.0f;
    //             if (*(int*)(dword_7C54F0[j] + 16480) == v10 + 1) { *((int*)this + 7) = j; break; }
    //           }
    //           IteratorCheck(&dword_8AD298);
    //         } else {
    //           *((int*)this + 1) = 5;
    //           *((int*)this + 6) = v10 - 1;
    //           this[9] = 3.0f;
    //         }
    //       }
    //       result = savedResult;
    //       goto accumulate;
    //     }
    //     *((int*)this + 11) = 1;
    //     if (StateFlagCheck_5240(this)) { *((int*)this + 1) = 4; sub_4D8760(0, 1); }
    //   accumulate:
    //     this[10] += dbl_8AFE98;
    //   cameraBlock:
    //     int* session = (int*)*((int*)this + 3);  // this+0xC
    //     if (!session || !*(int*)((char*)session + 176)) return result;
    //     int target = *((int*)this + 11);
    //     float threshold = *(float*)((char*)session + 188);
    //     int* elem = StridedArrayElementPointer(target);
    //     if (elem && *(float*)((char*)elem + 24) > threshold) SteeringInterpolationCameraFollow(flagByte);
    //     ShortComputation_c910(&dword_5EA510);
    //     if (!session) return result;
    //     dword_5EA538 = session;
    //     byte_5EA535 = 1;
    //     UtilityFunction_1cd0(session[3], session[4], *(float*)((char*)session + 20), session[6], session[7], session[8]);
    //     DualFieldGetter(&flagByte, &threshold);
    //     ShortComputation_6080(&out1, &out2);
    //     float angle1 = threshold * 0.01745433f;
    //     float angle2 = flagByte * 0.01745433f;
    //     sub_542050(angle2, angle1, 0);
    //     TwoFieldSetterCall(out1, out2);
    //     ConditionalFloatSetter(*(float*)((char*)session + 72));
    //     return savedResult;
    //   }
    // UNRESOLVED: The read-only globals flt_59E440, flt_59E65C and flt_5EA618 are recorded by the packet but do not appear in the raw Hex-Rays text; their role in this function is unknown (possible extraction artifact or an access the decompiler collapsed).
    // UNRESOLVED: States 3 and 4 both fall through to the score-gate advance block, while state 2 transitions into state 4 with sub_4D8760(0, 1) and state 0 calls sub_4D8760(2, 1); the exact semantic difference between the two first arguments (0 vs 2) is not established by this packet.
    // UNRESOLVED: The packet records init_literal 4 for the phase field at this+0x4, but no assignment of 4 appears in the raw text; the value may be written by a constructor outside this function.
    // UNRESOLVED: dword_5C329C acts as the grid-size bound and dword_7C54F0 as an array of active vehicle slot pointers in the scan loop, but their global role is only DERIVED from this packet's usage.
    // UNRESOLVED: Owner is unknown; no packet evidence names a class for this float-based state machine.
}
