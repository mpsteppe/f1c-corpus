// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040BE70
// Canonical corpus name: KeyboardInputActionMapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/KeyboardInputActionMapper_0040be70.c

void UnknownObject::KeyboardInputToCameraActionMapper()
{
    // Maps a table of 16-bit keyboard action codes (word_7CB21C, count dword_7CB218) to camera actions, gated by a disable flag at this+0x24. Each action code is dispatched through a switch: 74/78 target the race leader (CameraTargetRaceLeader 1/0), 156 re-targets the current tracked vehicle (CameraTargetCurrentTrackedVehicle), and 199/201/209/210 invoke camera-mode changes guarded by CameraLockCheck and GameActionStateMachine pairs plus a tracked-vehicle validity check for action 210. If any action fires, v2 is set to 1. Finally, if the one-shot flag at this+0x2C is set, it is cleared and the function returns 1; otherwise it returns v2.
    // ASSIGNMENT: Initialize result flag v2 to 0 before the scan. [source:raw]
    // GUARD: Skip the whole input scan when the disable byte at this+0x24 is non-zero. [field:this:0x00000024, source:raw]
    // LOOP: do-while over dword_7CB218 entries of the 16-bit action code table word_7CB21C. [global:0x007CB218, global:0x007CB21C, source:raw]
    // UNKNOWN: Dispatch on the action code through the jump table jpt_40BEB0 (with nearby byte_40BFE4); cases 74, 78, 156, 199, 201, 209 and 210 are handled, the rest fall through to the default. [global:0x0040BFC4, global:0x0040BFE4, source:raw]
    // CALL: Action 74: target the race leader with CameraTargetRaceLeader(1). [callee:0x0040D290, source:raw]
    // CALL: Action 78: target the race leader with CameraTargetRaceLeader(0). [callee:0x0040D290, source:raw]
    // CALL: Action 156: re-target the current tracked vehicle with CameraTargetCurrentTrackedVehicle(this). [callee:0x0040D340, source:raw]
    // GUARD: Action 199: when CameraLockCheck(4) succeeds and GameActionStateMachine(4, 1) does not consume the action, mark it handled. [callee:0x0040C720, callee:0x0040CDE0, source:raw]
    // GUARD: Action 201: handled when (the flag byte at dword_7C54E0+13388 is clear, or CameraLockCheck(3) succeeds) and GameActionStateMachine(3, 1) does not consume it, or when byte_7CFE88 is set. [global:0x007C54E0, global:0x007CFE88, callee:0x0040C720, callee:0x0040CDE0, source:raw]
    // GUARD: Action 209: handled when CameraLockCheck(5) succeeds and GameActionStateMachine(5, 1) does not consume it. [callee:0x0040C720, callee:0x0040CDE0, source:raw]
    // GUARD: Action 210: read the tracked target pointer from this+0x24; handled when (this+0x8 differs from that pointer, or the target's +0x40 field is clear) and CameraLockCheck(0) succeeds and GameActionStateMachine(0, 1) does not consume it. [field:this:0x00000008, field:this:0x00000018, field:*(this+0x18):0x00000040, callee:0x0040C720, callee:0x0040CDE0, source:raw]
    // ASSIGNMENT: Set result flag v2 = 1 when any handled action fires (shared LABEL_24). [source:raw]
    // GUARD: At exit, when the one-shot byte at this+0x2C is clear return v2; otherwise clear it and return 1. [field:this:0x0000002C, source:raw]
    // RETURN: Return v2 (any action handled) or 1 when the one-shot flag at this+0x2C was consumed. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40BE70(CameraInput* this) {
    //     int handled = 0;
    //     if (!this->disabled /* +0x24 * /) {
    //       for (int i = 0; i < dword_7CB218; ++i) {
    //         switch (word_7CB21C[i]) {
    //           case 74:  CameraTargetRaceLeader(1); handled = 1; break;
    //           case 78:  CameraTargetRaceLeader(0); handled = 1; break;
    //           case 156: CameraTargetCurrentTrackedVehicle(this); handled = 1; break;
    //           case 199: if (CameraLockCheck(4) && !GameActionStateMachine(4, 1)) handled = 1; break;
    //           case 201: if ((!*(BYTE*)(dword_7C54E0 + 13388) || CameraLockCheck(3)) && !GameActionStateMachine(3, 1) || byte_7CFE88) handled = 1; break;
    //           case 209: if (CameraLockCheck(5) && !GameActionStateMachine(5, 1)) handled = 1; break;
    //           case 210: {
    //             int target = *(int*)(this + 24);
    //             if ((*(int*)(this + 8) != target || !*(int*)(target + 64)) && CameraLockCheck(0) && !GameActionStateMachine(0, 1)) handled = 1;
    //             break;
    //           }
    //         }
    //       }
    //     }
    //     if (!this->oneshot /* +0x2C * /) return handled;
    //     this->oneshot = 0;
    //     return 1;
    //   }
    // UNRESOLVED: Semantics of the per-action camera-mode ids (0, 3, 4, 5) and the GameActionStateMachine state transitions.
    // UNRESOLVED: Meaning of the byte at dword_7C54E0+13388 and of byte_7CFE88 in the action-201 gate.
    // UNRESOLVED: What the 16-bit action codes 74/78/156/199/201/209/210 correspond to in the input system; mapping is derived from the case bodies.
    // UNRESOLVED: The tracked-vehicle pointer fields (this+0x8, this+0x18, target+0x40) exact semantics are unconfirmed.
}
