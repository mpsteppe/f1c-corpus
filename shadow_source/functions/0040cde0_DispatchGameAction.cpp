// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040CDE0
// Canonical corpus name: GameActionStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameActionStateMachine_0040cde0.c

void UnknownObject::DispatchGameAction()
{
    // Action-driven game state machine. Dispatches on an action id (a2) with cases 0-10, forwarding a camera mode to ViewCameraModeDispatch and triggering AudioSoundEffectController, and recording the last action in this[3] (offset 0xC). Every transition sets the active state pointer this[2] (offset 0x8) from the current session/camera pointer this[6] (offset 0x18). Case 5 additionally runs a virtual method on the active state object and a conditional child transition guarded by the jump table global. Case 3 has a secondary camera/audio transition gated by a global byte flag. Returns 0 on handled cases, 1 on the default path.
    // ASSIGNMENT: Initialize result to 1 (the default/unhandled return value). [source:raw]
    // GUARD: Dispatch on action id a2 via the switch jump table jpt_40CDFC (global 0x0040D050); cases 0-2, 3, 4, 5, 7, 8, 9, 10, and default. [global:0x0040D050, source:raw]
    // ASSIGNMENT: Cases 0-2: copy this[6] (offset 0x18, session/camera pointer) into the active state pointer this[2] (offset 0x8). [field:this:0x00000008, field:this:0x00000018, source:raw]
    // CALCULATION: Cases 0-2: derive the camera mode v8 from the action id (0, 1, or 2). [source:raw]
    // CALL: Cases 0-2: call ViewCameraModeDispatch with the session pointer, derived mode v8, flag 1, and a4 = 0 when a3 set else 1. [callee:0x00409440, source:raw]
    // STATE_TRANSITION: Cases 0-2: record the dispatched action id into this[3] (offset 0xC) and set result to 0. [field:this:0x0000000C, source:raw]
    // CALCULATION: Case 3: when a3 set, compute v3 = (this[2] == this[6]) comparing the previous active state pointer with the session pointer. [field:this:0x00000008, field:this:0x00000018, source:raw]
    // STATE_TRANSITION: Case 3: assign this[2] = this[6], call AudioSoundEffectController(0), then ViewCameraModeDispatch(this[6], 3, v3, 0). [field:this:0x00000008, field:this:0x00000018, callee:0x004E0ED0, callee:0x00409440, source:raw]
    // GUARD: Case 3: conditional secondary transition gated on the byte at dword_7C54E0 + 13388 being set and byte_7CFE88 (global 0x007CFE88) clear. [global:0x007C54E0, global:0x007CFE88, source:raw]
    // CALL: Case 3 secondary path: AudioSoundEffectController(0) and ViewCameraModeDispatch(this[6], 2, 0, 0). [callee:0x004E0ED0, callee:0x00409440, field:this:0x00000018, source:raw]
    // STATE_TRANSITION: Case 3 secondary path: set this[5] (offset 0x14) to 3 and this[3] (offset 0xC) to 2, marking the fallback transition; otherwise record a2 into this[3]. [field:this:0x00000014, field:this:0x0000000C, source:raw]
    // STATE_TRANSITION: Case 4: same pattern as case 3 (this[2] = this[6]) then dispatch mode 4 and record a2 into this[3]. [field:this:0x00000008, field:this:0x00000018, field:this:0x0000000C, callee:0x004E0ED0, callee:0x00409440, source:raw]
    // GUARD: Case 5: progression guard when either int at (this[8]+16) (offset 0x30) or int at (this[7]+16) (offset 0x2C) is greater than zero. [field:this:0x00000030, field:this:0x0000002C, field:this:0x00000020, field:this:0x0000001C, guard:0, guard:1, source:raw]
    // ASSIGNMENT: Case 5: set this[2] (offset 0x8) to this[8] (offset 0x20) unless sub_40D080 (global 0x0040D080) is nonzero and this[7] (offset 0x1C) is nonzero and equals the current this[2]. [global:0x0040D080, field:this:0x00000008, field:this:0x00000020, field:this:0x0000001C, source:raw]
    // CALL: Case 5: invoke the virtual method at vtable+0x10 (5th method) on the active state object *(this+0x8). [field:*(this+0x8):0x00000010, field:this:0x00000008, source:raw]
    // CALL: Case 5: AudioSoundEffectController(0) after the virtual dispatch, then record a2 into this[3] (offset 0xC). [callee:0x004E0ED0, field:this:0x0000000C, source:raw]
    // STATE_TRANSITION: Cases 7, 8, 9, 10: assign this[2] = this[6], call AudioSoundEffectController(0), dispatch camera modes 5, 6, 7, 8 respectively via ViewCameraModeDispatch, and record a2 into this[3]. [field:this:0x00000008, field:this:0x00000018, field:this:0x0000000C, callee:0x004E0ED0, callee:0x00409440, source:raw]
    // RETURN: Return result (0 for handled cases, 1 for the default case). [source:raw]

    // Conservative worker pseudocode:
    //   int DispatchGameAction(GameActionStateMachine* this, int action, bool fromInput) {
    //     int result = 1;
    //     switch (action) {
    //       case 0: case 1: case 2:
    //         this->activeState = this->session;
    //         int mode = (action == 0) ? 0 : (action == 1) ? 1 : 2;
    //         ViewCameraModeDispatch(this->session, mode, 1, fromInput ? 0 : 1);
    //         this->lastAction = action; result = 0; break;
    //       case 3:
    //         bool same = fromInput && (this->activeState == this->session);
    //         this->activeState = this->session;
    //         AudioSoundEffectController(0);
    //         ViewCameraModeDispatch(this->session, 3, same, 0);
    //         if (*(BYTE*)(dword_7C54E0 + 13388) && !byte_7CFE88) {
    //           AudioSoundEffectController(0);
    //           ViewCameraModeDispatch(this->session, 2, 0, 0);
    //           this->field14 = 3; this->lastAction = 2;
    //         } else { this->lastAction = action; }
    //         result = 0; break;
    //       case 4:
    //         bool same4 = fromInput && (this->activeState == this->session);
    //         this->activeState = this->session;
    //         AudioSoundEffectController(0);
    //         ViewCameraModeDispatch(this->session, 4, same4, 0);
    //         this->lastAction = action; result = 0; break;
    //       case 5:
    //         int target = this->third;
    //         if (*(int*)(target + 16) > 0 || *(int*)(this->second + 16) > 0) {
    //           if (!sub_40D080 || this->second == 0 || this->activeState != this->second)
    //             this->activeState = target;
    //           (*(void (__thiscall**)(void*))(*(DWORD*)this->activeState + 16))(this->activeState);
    //         }
    //         AudioSoundEffectController(0);
    //         this->lastAction = action; result = 0; break;
    //       case 7: case 8: case 9: case 10:
    //         this->activeState = this->session;
    //         AudioSoundEffectController(0);
    //         ViewCameraModeDispatch(this->session, action - 2, 0, 0);
    //         this->lastAction = action; result = 0; break;
    //       default: break;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the byte at dword_7C54E0 + 13388 and its interaction with byte_7CFE88 is unknown.
    // UNRESOLVED: Identity and semantics of sub_40D080 (used only as a guard predicate in case 5) are unknown.
    // UNRESOLVED: The virtual method invoked at vtable+0x10 on the case-5 state object is not identified.
    // UNRESOLVED: The exact meaning of the camera mode values (0-8) passed to ViewCameraModeDispatch is unverified.
    // UNRESOLVED: Why a4 of ViewCameraModeDispatch is inverted (0 vs 1) by a3 in cases 0-2 but always 0 elsewhere is unclear.
}
