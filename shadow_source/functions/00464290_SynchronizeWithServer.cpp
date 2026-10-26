// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464290
// Canonical corpus name: SynchronizeWithServer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SynchronizeWithServer_00464290.c

void UnknownObject::SynchronizeWithServer()
{
    // Synchronizes the multiplayer session with the server. Reads session state at obj+0x3FC4; while non-zero, either resets arrays/player slots (and conditionally runs collision detection when state equals 3) or performs first-time initialization of the session sub-objects. Then, based on state 1/2 versus other values, either configures a byte field on the sub-object at obj+0x3FB8 or sets retry timeout values, clears accumulated session fields, and runs a final array initialization. Legacy ABI name: SynchronizeWithServer.
    // GUARD: Dereference this[0] to obtain the session object (obj) and read session state at obj+0x3FC4; proceed only while state is non-zero. [field:this:0x00000000, field:obj:0x00003FC4, source:raw]
    // GUARD: Branch on the first-time sync byte at obj+0x28: when set, take the reset/re-run path; when clear, take the one-time initialization path. [field:obj:0x00000028, source:raw]
    // CALL: Reset arrays on the session object via ArrayInitWithSentinelInLoop. [callee:0x00460C60]
    // CALL: Clear player slots with keep flag 1 via ClearPlayerSlots. [callee:0x00460CB0]
    // GUARD: If session state at obj+0x3FC4 equals 3, run the collision detection and conditional debug-log path. [guard:0, field:obj:0x00003FC4, source:raw]
    // CALL: When dword_7C569C != 5 and StringSplitLoop succeeds splitting dword_8AD25C with token aDDevF119992002_1 and count 7877, write the entering-synchronize debug message aEnteringSynchr via DebugLogWrite. [callee:0x004D7A50, callee:0x004D7AA0, global:0x007C569C, global:0x008AD25C, global:0x005C5CE4, global:0x005C6634]
    // CALL: Run collision detection over the session via RunCollisionDetectionLoop. [callee:0x0045F390]
    // ASSIGNMENT: First-time path: set the sync byte at obj+0x28 to 1. [field:obj:0x00000028, source:raw]
    // LOOP: First-time path: loop index i from 0 to 22672 stepping 218, initializing each session sub-object slot (starting at (*this)[4192]) via ThunkWithStructInitSubCalls. [callee:0x004FFFA0, source:raw]
    // GUARD: Re-read session state at obj+0x3FC4; states 1 or 2 select the byte-field configuration path, all other values select the timeout/retry path. [field:obj:0x00003FC4, source:raw]
    // CALL: State 1/2 path: call ByteFieldSetterAtOffset0x5d on the sub-object pointer at obj+0x3FB8, writing 0 when dword_7C56A4 == 7 or (byte_7D105C is set and dword_7C56A4 == 5), otherwise writing 1. [callee:0x0057A570, field:obj:0x00003FB8, global:0x007C56A4, global:0x007D105C, source:raw]
    // ASSIGNMENT: Other-state path: set obj+0x14 to 1 (active flag), obj+0x10 to float 5.0, and obj+0x390 to 0x3C23D70A (1008981770, float 0.01). [field:obj:0x00000014, field:obj:0x00000010, field:obj:0x00000390, source:raw]
    // ASSIGNMENT: Clear accumulated session fields: obj+0x388 and obj+0x380 set to 0. [field:obj:0x00000388, field:obj:0x00000380, source:raw]
    // CALL: Final array initialization at this+26864 with keep flag 1 via ArrayInitializationLoop; result feeds the return value. [callee:0x0045C8B0, source:raw]
    // GUARD: If byte at obj+0x1B790 is set and byte at obj+0x1B791 is also set, invoke the follow-up init routine (sub_562AC0 on off_5E4DFC) whose result feeds the return value. [field:obj:0x0001B790, field:obj:0x0001B791, source:raw]
    // RETURN: Return the resulting byte value, threaded through the initialization calls. Legacy ABI names this function SynchronizeWithServer. [function:0x00464290, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   obj = *this;
    //   state = obj->state_3FC4;
    //   if (state != 0) {
    //     if (obj->sync_flag_28) {
    //       ArrayInitWithSentinelInLoop(obj);
    //       ClearPlayerSlots(obj, 1);
    //       if (state == 3) {
    //         if (dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_1, 7877))
    //           DebugLogWrite(dword_8AD25C, aEnteringSynchr);
    //         RunCollisionDetectionLoop(obj);
    //       }
    //     } else {
    //       obj->sync_flag_28 = 1;
    //       for (i = 0; i < 22672; i += 218)
    //         ThunkWithStructInitSubCalls(&(*this)[i + 4192]);
    //     }
    //     if (obj->state_3FC4 == 2 || obj->state_3FC4 == 1) {
    //       if (dword_7C56A4 == 7 || (byte_7D105C && dword_7C56A4 == 5))
    //         ByteFieldSetterAtOffset0x5d(obj->sub_3FB8, 0);
    //       else
    //         ByteFieldSetterAtOffset0x5d(obj->sub_3FB8, 1);
    //     } else {
    //       obj->active_14 = 1;
    //       obj->timeout_10 = 5.0f;
    //       obj->threshold_390 = 0x3C23D70A;
    //     }
    //     obj->accum_388 = 0;
    //     obj->accum_380 = 0;
    //     result = ArrayInitializationLoop(this + 26864, 1);
    //     if (obj->flag_1B790 && obj->flag_1B791)
    //       result = sub_562AC0(off_5E4DFC, 1);
    //   }
    //   return result;
    // UNRESOLVED: The follow-up init routine sub_562AC0 and its operand off_5E4DFC appear in the source but have no evidence entries in this packet; referenced only descriptively.
    // UNRESOLVED: Read-only globals flt_59F0A0 and flt_59F0B8 are listed as accessed but do not appear in the visible body; placement unknown.
    // UNRESOLVED: Caller Game_Restart (0x0042D7A0) invokes this routine but contributes no field evidence here.
}
