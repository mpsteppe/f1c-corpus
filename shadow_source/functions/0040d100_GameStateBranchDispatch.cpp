// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D100
// Canonical corpus name: GameStateBranchDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameStateBranchDispatch_0040d100.c

void UnknownObject::GameStateBranchDispatch()
{
    // Per-frame game state branch dispatch. Reads the session/camera pointer at this+0x18 and, only when it is non-zero, switches on the global dispatch mode selector dword_7CFDC4 (1-4 plus default) to call ViewCameraModeDispatch and GameActionStateMachine with paired camera-mode and action-id arguments. Returns the result of the selected GameActionStateMachine call; when this+0x18 is zero the function returns without dispatching.
    // GUARD: Read the camera/session pointer at this+0x18 (this[6]); the entire switch dispatch is skipped and the function returns when it is zero [field:this:0x00000018, source:raw]
    // STATE_TRANSITION: Select the dispatch branch from the global mode selector dword_7CFDC4 via the jump table at 0x0040D198, covering cases 1-4 and a default [global:0x007CFDC4, global:0x0040D198, source:raw]
    // CALL: Case 1: ViewCameraModeDispatch(camera, 1, 0, 1) then GameActionStateMachine(this, 1, 0) [callee:0x00409440, callee:0x0040CDE0, source:raw]
    // CALL: Case 2: ViewCameraModeDispatch(camera, 0, 0, 1) then GameActionStateMachine(this, 0, 0) [callee:0x00409440, callee:0x0040CDE0, source:raw]
    // CALL: Case 3: ViewCameraModeDispatch(camera, 3, 0, 1) then GameActionStateMachine(this, 3, 0) [callee:0x00409440, callee:0x0040CDE0, source:raw]
    // CALL: Case 4: ViewCameraModeDispatch(camera, 3, 0, 1) then GameActionStateMachine(this, 5, 0) [callee:0x00409440, callee:0x0040CDE0, source:raw]
    // CALL: Default: ViewCameraModeDispatch(camera, 2, 0, 1) then GameActionStateMachine(this, 2, 0) [callee:0x00409440, callee:0x0040CDE0, source:raw]
    // RETURN: Return the result of the selected GameActionStateMachine call; invoked per-frame by sub_40C140, NetCommPlayerSlotSync, sub_4A00A0, sub_4C6B60 and PitTimer [function:0x0040D100, caller:0x0040C140, caller:0x0045FC50, caller:0x004A00A0, caller:0x004C6B60, caller:0x004D2E50, source:raw]

    // Conservative worker pseudocode:
    //   camera = this[6];
    //   if (camera) {
    //     switch (dword_7CFDC4) {
    //       case 1: ViewCameraModeDispatch(camera, 1, 0, 1); return GameActionStateMachine(this, 1, 0);
    //       case 2: ViewCameraModeDispatch(camera, 0, 0, 1); return GameActionStateMachine(this, 0, 0);
    //       case 3: ViewCameraModeDispatch(camera, 3, 0, 1); return GameActionStateMachine(this, 3, 0);
    //       case 4: ViewCameraModeDispatch(camera, 3, 0, 1); return GameActionStateMachine(this, 5, 0);
    //       default: ViewCameraModeDispatch(camera, 2, 0, 1); return GameActionStateMachine(this, 2, 0);
    //     }
    //   }
    //   return uninitialized result;
    // UNRESOLVED: The exact meaning of the paired second arguments passed to ViewCameraModeDispatch and GameActionStateMachine (mode/action ids) is not documented by this packet
    // UNRESOLVED: Why case 4 reuses camera mode 3 but action id 5 is not explained by any evidence here
}
