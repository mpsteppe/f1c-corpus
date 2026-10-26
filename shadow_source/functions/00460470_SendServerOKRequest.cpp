// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00460470
// Canonical corpus name: SendServerOKRequest
// Owner: SessionManager [DERIVED]
// Raw source: functions/SendServerOKRequest_00460470.c

void SessionManager::SendServerOKRequest()
{
    // Sends the server OK/ready request for the current session object. If the session phase stored at this+0x3FC4 is in the active range (1-2), the session immediately marks itself ready via NetComm_SetSelfAsReady(-1). Otherwise it encodes a progress-bar event (type 4, subtype 3) using the session time (dbl_8AFEA0), creates the OK-indication texture via TextureCreationWrapper, and, when the session type (dword_7C569C) is not the server type 5, sanitizes and writes a 'sending server overflow' debug message. Called by SessionScoringUpdate.
    // GUARD: Read session phase from this+0x3FC4 and branch when it is greater than 0 and at most 2 (active phase). [field:this:0x00003FC4]
    // CALL: On the active-phase path, return NetComm_SetSelfAsReady(-1) to mark the session self as ready. [callee:0x00460520, field:this:0x00003FC4]
    // ASSIGNMENT: Load session time from global dbl_8AFEA0 into a local. [global:0x008AFEA0]
    // CALL: Encode progress-bar event ProgressBarEventEncode(4, 3, 0, 0, LODWORD(v3), 1) using the low dword of the session time. [callee:0x004B33B0, global:0x008AFEA0]
    // CALL: Create the OK-indication texture: TextureCreationWrapper(texture_buffer, 2, -1, -1), result stored as the fallback return value. [callee:0x00462250]
    // GUARD: Branch on session type dword_7C569C being different from 5 (non-server session) before debug logging. [global:0x007C569C]
    // CALL: Sanitize the source-device-path string: StringSplitLoop(1, aDDevF119992002_1, 4371), result stored in the return value slot. [callee:0x004D7A50, global:0x005C5CE4]
    // GUARD: When StringSplitLoop returned truthy, return DebugLogWrite(&dword_8AD25C, aSendingServerO) to emit the 'sending server overflow' message. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C5F6C]
    // RETURN: Fall through returning the last call result when no early return was taken. [function:0x00460470, source:raw]

    // Conservative worker pseudocode:
    //   session_phase = this->session_phase;
    //   if (session_phase > 0 && session_phase <= 2) return NetComm_SetSelfAsReady(-1);
    //   session_time = dbl_8AFEA0;
    //   ProgressBarEventEncode(4, 3, 0, 0, (int)session_time, 1);
    //   result = TextureCreationWrapper(texture_buffer, 2, -1, -1);
    //   if (dword_7C569C != 5) {
    //     result = StringSplitLoop(1, aDDevF119992002_1, 4371);
    //     if (result) return DebugLogWrite(&dword_8AD25C, aSendingServerO);
    //   }
    //   return result;
    // UNRESOLVED: Constants have unexplained semantics: NetComm_SetSelfAsReady(-1) sentinel, TextureCreationWrapper dimensions (-1, -1), and StringSplitLoop arguments (1, aDDevF119992002_1, 4371).
    // UNRESOLVED: Globals aErr (0x005C5F90) and aOk (0x005C5F94) appear in the packet but not in the decompiled body; likely reached through code paths the decompiler folded away.
    // UNRESOLVED: dbl_8AFEA0 is read as a double but only its low dword is passed to ProgressBarEventEncode.
}
