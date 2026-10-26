// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C9E0
// Canonical corpus name: CamMan_Restart
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CamMan_Restart_0040c9e0.c

void UnknownObject::CameraManagerRestart()
{
    // Resets camera-manager state for a restart: optionally logs an entry message when the StringSplitLoop gate on the startup string passes, re-initializes the camera state machine from the global constant block flt_5EA4E8, clears the stored player/entity id at this+0x38 to -1 and the byte flag at this+0x2E to 0, and returns the state-init result.
    // GUARD: If StringSplitLoop(2, aDDevF119992002_15, 3656) returns non-zero, the camera-manager restart debug message is logged. [callee:0x004D7A50, global:0x005BE958, source:raw]
    // CALL: StringSplitLoop gates the debug-log block on a startup source-string check. [callee:0x004D7A50, global:0x005BE958, source:raw]
    // CALL: DebugLogWrite writes the aEnteredCammanR string into the debug message buffer dword_8AD25C. [callee:0x004D7AA0, global:0x005BE980, global:0x008AD25C, source:raw]
    // CALL: StateInitWithGlobalConstants re-initializes the camera state machine from the global constant block flt_5EA4E8; its return value becomes this function's result. [callee:0x00408290, global:0x005EA4E8, source:raw]
    // ASSIGNMENT: Resets the stored player/entity id at this+0x38 to -1 so the next tick detects a player change. [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Clears the byte flag at this+0x2E to 0. [field:this:0x0000002E, source:raw]
    // RETURN: Returns the result produced by StateInitWithGlobalConstants. [function:0x0040C9E0, callee:0x00408290, source:raw]

    // Conservative worker pseudocode:
    //   int CameraManagerRestart(cameraManager* this) {
    //     if (StringSplitLoop(2, aDDevF119992002_15, 3656))
    //       DebugLogWrite(&dword_8AD25C, aEnteredCammanR);
    //     int result = StateInitWithGlobalConstants(&flt_5EA4E8);
    //     this->playerId = -1;
    //     this->flagByte = 0;
    //     return result;
    //   }
    // UNRESOLVED: The exact semantics of byte flag this+0x2E and stored id this+0x38 are not evidenced beyond the restart-reset behavior.
    // UNRESOLVED: StringSplitLoop's role as a debug gate and the meaning of the constants 2 and 3656 are not interpretable from this packet.
}
