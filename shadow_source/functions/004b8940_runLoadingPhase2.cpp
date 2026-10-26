// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8940
// Canonical corpus name: LoadingPhase2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LoadingPhase2_004b8940.c

void UnknownObject::runLoadingPhase2()
{
    // Second phase of session loading on a loading/session object: sets the loading phase flag at this+0xF80 to 1, runs a SafeDivisionWithZeroGuard over flt_5EA4E8 and a state-trigger loop that accumulates dbl_8AFE90 until the 0.75*1.5 threshold, then applies AngleClampWrap with the angle value dbl_8AFEA0, sets the angle-clamp mode byte at this+0xF81 to 0 (wrap), and re-runs the state trigger check. If the vehicle count dword_5C329C is positive, iterates the dword_7C54F0 vehicle-pointer array driving SessionStateTransition over the session-state array at this+0x734, UIElementIterateUpdate, visibility propagation (this+0x93C array, audio effect trigger on change), MultiObjectRemove and SetDriverVisibility for each vehicle. Finishes by cleaning the session structure (dword_5EA560), calling GuardedVirtualCall, releasing the loaded resource handle at this+0xF40 via sub_566DB0, setting it to -1, and returning 1.
    // ASSIGNMENT: Set the loading phase flag this[3968] (this+0xF80) to 1. [field:this:0x00000F80, source:raw]
    // CALL: Compute the loop threshold v11 = 0.75 * 1.5 and call SafeDivisionWithZeroGuard((int)&flt_5EA4E8, v11) to normalise the phase against the global flt_5EA4E8. [callee:0x00408450, global:0x005EA4E8, source:raw]
    // LOOP: While the accumulator v10 is below the threshold v11 (initially 0.0, incremented by dbl_8AFE90 each pass), set v13 = 1 and call StateTriggerCheck(&v13), advancing a state counter until the threshold is reached. [callee:0x004B8AE0, global:0x008AFE90, source:raw]
    // ASSIGNMENT: Re-assert the loading phase flag this+0xF80 (this[3968]) to 1 and load the angle value v9 = dbl_8AFEA0. [field:this:0x00000F80, global:0x008AFEA0, source:raw]
    // CALL: Call AngleClampWrap(v1, v9) to configure angle clamping with the dbl_8AFEA0 value, then call StateTriggerCheck(&v13) again with v13 = 1. [callee:0x004B86E0, callee:0x004B8AE0, global:0x008AFEA0, source:raw]
    // ASSIGNMENT: Set the angle clamp mode byte this[3969] (this+0xF81) to 0, selecting wrap mode. [field:this:0x00000F81, source:raw]
    // GUARD: Read the vehicle count v14 = dword_5C329C; the per-vehicle loop runs only while the count is positive. [global:0x005C329C, source:raw]
    // LOOP: Iterate the vehicle-pointer array dword_7C54F0 for dword_5C329C vehicles: for each vehicle SessionStateTransition(*v12, 0) against the session-state array at this+0x734, UIElementIterateUpdate(v5 + 1776) on the vehicle, and compare the stored per-vehicle byte at vehicle+4189 with the phase's state byte read 104 bytes before the visibility entry; when different, write it to vehicle+4189 and call AudioSoundEffectController(*(vehicle+4180)); then MultiObjectRemove(dbl_8AFEA0) and SetDriverVisibility(*v3) from the visibility array at this+0x93C, advancing all three pointers each pass. [callee:0x004EF5A0, callee:0x004E19A0, callee:0x004E0ED0, callee:0x004E3A50, callee:0x004C7AA0, field:this:0x00000734, field:this:0x0000093C, global:0x007C54F0, global:0x005C329C, global:0x008AFEA0, source:raw]
    // CALL: Call SessionStructureCleanup(dword_5EA560) to tear down the session structure identified by the global dword_5EA560. [callee:0x00411120, global:0x005EA560, source:raw]
    // CALL: Call GuardedVirtualCall(1065353216) with the float bit-pattern argument 1065353216 (0x3F800000). [callee:0x004C8DC0, source:raw]
    // CALL: Release the loaded resource handle at this+0xF40 (this[3904]) via sub_566DB0(*(v1 + 3904)). [callee:0x00566DB0, field:this:0x00000F40, source:raw]
    // ASSIGNMENT: Write -1 (the packet's init_literal 18446744073709551615) into the resource handle field this+0xF40 (this[3904]) to mark it released. [field:this:0x00000F40, source:raw]
    // RETURN: Return 1 to signal successful completion of the loading phase. [source:raw]

    // Conservative worker pseudocode:
    //   this[3968] = 1;
    //   threshold = 0.75 * 1.5;
    //   SafeDivisionWithZeroGuard((int)&flt_5EA4E8, threshold);
    //   if (threshold > 0.0)
    //     do { v13 = 1; StateTriggerCheck(&v13); acc += dbl_8AFE90; } while (acc < threshold);
    //   this[3968] = 1;
    //   AngleClampWrap(this, dbl_8AFEA0); StateTriggerCheck(&v13);
    //   this[3969] = 0;
    //   for (i = 0; i < dword_5C329C; i++) {
    //     veh = dword_7C54F0[i];
    //     SessionStateTransition(sessionState[i], 0);
    //     UIElementIterateUpdate(veh + 1776);
    //     if (veh[4189] != stateByte) { veh[4189] = stateByte; AudioSoundEffectController(veh[4180]); }
    //     MultiObjectRemove(dbl_8AFEA0);
    //     SetDriverVisibility(visibility[i]);
    //   }
    //   SessionStructureCleanup(dword_5EA560);
    //   GuardedVirtualCall(1065353216);
    //   sub_566DB0(this[3904]); this[3904] = -1;
    //   return 1;
    // UNRESOLVED: Packet-listed globals flt_59E440, flt_59E8A4, flt_5ACD1C and byte_8AC494 are not visible in the decompiled body shown; they are accounted for but their role is not evidenced here.
    // UNRESOLVED: Semantics of the GuardedVirtualCall argument 1065353216 (a 32-bit float bit pattern for 1.0f) and the exact meaning of the state byte read 104 bytes before the visibility entry are DERIVED, not proven.
    // UNRESOLVED: The 104-byte offset relationship between the this+0x93C visibility array and the state byte read is an x87/codegen artifact of the loop, not a named field.
}
