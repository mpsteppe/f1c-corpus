// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9890
// Canonical corpus name: sub_4B9890
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B9890_004b9890.c

void UnknownObject::LoadingPhaseOrchestrator()
{
    // Orchestrates the session loading sequence when the disable flag byte_7CE254 is clear: temporarily forces the session-type global dword_7C569C to 1, decodes the current phase, runs LoadingPhase1, clamps the time offset to [10.0, 180.0], polls the key-priority chain while advancing the game state machine, sets the player vehicle index, runs LoadingPhase2, then restores the session type and returns a dispatcher result via ArithmeticComparison_8d60 or ShortComputation_8d70.
    // ASSIGNMENT: Dereference the this pointer to reach the object used for the dword-indexed fields at +0xF84 and +0xF88. [field:this:0x00000000, source:raw]
    // GUARD: Initialize result from the disable flag byte_7CE254; when it is nonzero the entire loading body is skipped and its value is returned. [global:0x007CE254, source:raw]
    // ASSIGNMENT: Save the enable flag byte_7C56AC into a local before mutating the session-type global. [global:0x007C56AC, source:raw]
    // CALL: sub_42D210(&dword_7C569C, 1) forces the session-type global to 1 for the loading phase. [callee:0x0042D210, global:0x007C569C, source:raw]
    // CALL: SessionPhaseDecode(&dword_5EA510) decodes the current session phase from the session-manager global. [callee:0x0040CD60, global:0x005EA510, source:raw]
    // CALCULATION: Read an int from the active vehicle pointer: dword_7C54F0 indexed by dword_7C54DC, plus 18580 bytes. [global:0x007C54F0, global:0x007C54DC, source:raw]
    // ASSIGNMENT: Write 2 into the caller's out-parameter a3 to mark the loading state. [source:raw]
    // ASSIGNMENT: Store the incoming float a2 into the object dword index 993 (byte offset +0xF84). [field:obj:0x00000F84, source:raw]
    // CALL: LoadingPhase1(*this) begins the first loading phase; all following work runs only when it returns nonzero. [callee:0x004B87C0, source:raw]
    // GUARD: Clamp the incoming time value into [10.0, 180.0] before computing the delta. [source:raw]
    // CALCULATION: Compute the float delta dbl_8AFEA0 minus the clamped time value. [global:0x008AFEA0, source:raw]
    // CALL: SingleCallWrapper_9cd0(delta) applies the computed time delta. [callee:0x004B9CD0, source:raw]
    // CALL: Delegation(this) returns a result that is stored into the object dword index 994 (byte offset +0xF88). [callee:0x004B9CE0, field:obj:0x00000F88, source:raw]
    // CALL: GameActionStateMachine(&dword_5EA510, 5, 0) advances the game state machine to phase 5. [callee:0x0040CDE0, global:0x005EA510, source:raw]
    // LOOP: Poll loop: read the key-priority chain via KeyPriorityChain() and play SoundAudioPlayback(-1.0) while StateTriggerCheck(*this, &keyValue) returns true. [callee:0x004B8BD0, callee:0x004C8650, callee:0x004B8AE0, source:raw]
    // CALL: SingleCallWrapper_9cd0(dbl_8AFEA0) restores the session time after the poll loop. [callee:0x004B9CD0, global:0x008AFEA0, source:raw]
    // CALL: SetPlayerVehicleIndex(v6) re-selects the player's vehicle using the index read earlier. [callee:0x0042BBD0, source:raw]
    // CALL: GameActionStateMachine(&dword_5EA510, decodedPhase, 0) advances to the decoded session phase. [callee:0x0040CDE0, global:0x005EA510, source:raw]
    // CALL: LoadingPhase2(*this) finishes the loading sequence. [callee:0x004B8940, source:raw]
    // ASSIGNMENT: Write 1 into the caller's out-parameter a3 to mark the completed state. [source:raw]
    // CALL: sub_42D210(&dword_7C569C, savedFlag) restores the session-type global to its saved value. [callee:0x0042D210, global:0x007C569C, source:raw]
    // RETURN: Return ArithmeticComparison_8d60(&byte_8AC494) when the saved flag is set, otherwise ShortComputation_8d70(&byte_8AC494). [callee:0x004C8D60, callee:0x004C8D70, global:0x008AC494, source:raw]
    // RETURN: Return the original byte_7CE254 value when the disable flag was set at entry. [global:0x007CE254, source:raw]

    // Conservative worker pseudocode:
    //   char LoadingPhaseOrchestrator(float** this, float time, int* outState) {
    //     char result = byte_7CE254;
    //     if (!byte_7CE254) {
    //       char saved = byte_7C56AC;
    //       sub_42D210(&dword_7C569C, 1);
    //       int phase = SessionPhaseDecode(&dword_5EA510);
    //       int vehIndex = *(int*)(dword_7C54F0[dword_7C54DC] + 18580);
    //       *outState = 2;
    //       (*this)[993] = time;
    //       if (LoadingPhase1((int)*this)) {
    //         double t = time;
    //         if (t < 10.0) t = 10.0;
    //         else if (t > 180.0) t = 180.0;
    //         SingleCallWrapper_9cd0((float)(dbl_8AFEA0 - t));
    //         (*this)[994] = Delegation(this);
    //         GameActionStateMachine(&dword_5EA510, 5, 0);
    //         do {
    //           time = (float)KeyPriorityChain();
    //           SoundAudioPlayback(-1.0);
    //         } while (StateTriggerCheck(*this, &time));
    //         SingleCallWrapper_9cd0((float)dbl_8AFEA0);
    //         SetPlayerVehicleIndex(vehIndex);
    //         GameActionStateMachine(&dword_5EA510, phase, 0);
    //         LoadingPhase2(*this);
    //       }
    //       *outState = 1;
    //       sub_42D210(&dword_7C569C, saved);
    //       return saved ? ArithmeticComparison_8d60(&byte_8AC494)
    //                    : ShortComputation_8d70(&byte_8AC494);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: flt_59E5FC and flt_59E808 are listed as accessed globals but do not appear in the raw source; their role is unknown.
    // UNRESOLVED: unk_5EC6D0 is listed as an accessed global but does not appear in the raw source.
    // UNRESOLVED: The semantic meaning of the value read at the active vehicle pointer + 18580 bytes and the two object fields +0xF84 / +0xF88 depends on the session object layout.
}
