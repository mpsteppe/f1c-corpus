// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C5B0
// Canonical corpus name: CameraModeChangeRequest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraModeChangeRequest_0040c5b0.c

void UnknownObject::CameraModeChangeRequest()
{
    // Requests a camera mode change. Reads the mode value at +18580 on both the current-player vehicle (dword_7C54F0[dword_7C54DC]) and the current vehicle (dword_7C54F0[dword_7C54E4]); when they differ, applies the requested mode from this+0xC (-1, 1, or 2) by writing this+0x14 and calling GameActionStateMachine(5, 0). Mode 2 is gated on dword_7CFCC8 (queued-mode flag) being zero; any other requested value returns without applying a change. Called by MainCameraDirectorUpdate (0040CA30).
    // GUARD: Early return when the current-player vehicle (dword_7C54F0[dword_7C54DC] + 18580) holds the same mode value as the current vehicle (dword_7C54F0[dword_7C54E4] + 18580) [global:0x007C54DC, global:0x007C54E4, global:0x007C54F0, source:raw]
    // ASSIGNMENT: v2 = this[3] (offset +0xC), the requested camera mode change value (-1, 1, or 2) [field:this:0x0000000C, source:raw]
    // GUARD: Switch on the requested mode via jump table jpt_40C5E1; values other than -1, 1, or 2 return immediately without applying a change [global:0x0040C600, source:raw]
    // GUARD: For requested mode 2, the change is applied only when dword_7CFCC8 (queued-mode flag) is zero; a non-zero flag leaves the mode unchanged [global:0x007CFCC8, source:raw]
    // ASSIGNMENT: Writes this[5] (offset +0x14) with the requested mode value, recording the pending camera mode change [field:this:0x00000014, source:raw]
    // CALL: Applies the change by calling GameActionStateMachine(5, 0) [callee:0x0040CDE0, source:raw]
    // CALCULATION: result holds v2 + 1 on the switch default path and the value of dword_7CFCC8 on the blocked mode-2 path [global:0x007CFCC8, source:raw]
    // CALL: Invoked by MainCameraDirectorUpdate as the camera-mode-change request path [caller:0x0040CA30, source:raw]
    // RETURN: Returns the prior comparison/status value; on the early-exit guard no mode change is applied [source:raw]

    // Conservative worker pseudocode:
    //   playerMode = *(VehiclePtrArray[CurrentPlayerIndex] + 18580);
    //   currentMode = *(VehiclePtrArray[CurrentVehicleIndex] + 18580);
    //   if (playerMode == currentMode)
    //       return playerMode;
    //   requested = this->requestedMode;   // this[0x0C]
    //   switch (requested) {
    //     case -1:
    //     case 1:
    //       goto apply;
    //     case 2:
    //       if (QueuedModeFlag != 0)
    //           return QueuedModeFlag;
    //       goto apply;
    //     default:
    //       return requested + 1;
    //   }
    //   apply:
    //   this->pendingMode = requested;    // this[0x14]
    //   return GameActionStateMachine(5, 0);
    // UNRESOLVED: Offset 18580 (0x4894) is read on both the player and current vehicle pointers but has no packet field evidence ref; its meaning depends on the vehicle struct layout
    // UNRESOLVED: dword_7CFCC8 gates only mode 2; why only that mode is blocked is unproven
}
