// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D4580
// Canonical corpus name: sub_4D4580
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D4580_004d4580.c

void UnknownObject::StewardUpdateMainDispatch()
{
    // Main race-system dispatch and phase state machine. Accumulates 3D distance checks when the steward object has a source node (this+0xA4), drives the audio DSP with a session-time-dependent parameter when an audio context exists (this+0xA8), and — unless a global enable flag is set — runs the pit timer and dispatches a race-phase machine (session-phase 7). The state machine sets per-phase control flags at this+0xC0 and this+0xC1, checks the FLT_MAX sentinel at this+0xD8 to route the progress-bar path, and delegates scoring via the Delegation global when the scoring gate equals 2.
    // GUARD: Proceed with 3D distance checking only when the pointer at this+0xA4 is non-zero [field:this:0x000000A4, source:raw]
    // CALL: F_3DDistanceCheckAccumulate(v7, dbl_8AFE98) accumulates distance checks using the double at 0x008AFE98 as the parameter [callee:0x004D0B20, global:0x008AFE98, source:raw]
    // GUARD: Proceed with audio update only when the pointer at this+0xA8 is non-zero [field:this:0x000000A8, source:raw]
    // CALL: When dword_8AB6E4 equals 2, Delegation(&dword_8AB6EC) routes scoring to the delegated scorer; otherwise the parameter becomes dbl_8AFEA0 [callee:0x004B9CE0, global:0x008AB6E4, global:0x008AB6EC, global:0x008AFEA0, source:raw]
    // CALL: AudioDSPStateUpdate(this+0xA8, parameter) updates the audio DSP state with the session-time-derived float [callee:0x00448330, field:this:0x000000A8, source:raw]
    // GUARD: The pit-timer and race-phase state machine only run when byte_7C56AC is zero [global:0x007C56AC, source:raw]
    // CALL: PitTimer(a1) updates the pit-timer subsystem [callee:0x004D2E50, source:raw]
    // GUARD: Phase dispatch proceeds when bit 0 of dword_7C56A0 is set (multiplayer flag) and the phase counter dword_7C56A4 is non-negative [global:0x007C56A0, source:raw]
    // CALCULATION: Average of this+0xB0 and this+0xB4 is computed and compared against dbl_8AFEA0 for the low-phase timing check [field:this:0x000000B0, field:this:0x000000B4, global:0x008AFEA0, source:raw]
    // ASSIGNMENT: Set this+0xC0 to literal 1 when the averaged time is <= dbl_8AFEA0 (phase <= 6 and phases 5-8 paths) [field:this:0x000000C0, source:raw]
    // STATE_TRANSITION: Low-phase branch (dword_7C56A4 <= 6): after the timing check, falls into the sub_4D1D80(a1) call that continues the phase pipeline [source:raw]
    // ASSIGNMENT: Set this+0xC1 to literal 1 when the packed flag is read and byte_7CE254 is zero, marking the session-type-7 phase-control state [field:this:0x000000C1, source:raw]
    // STATE_TRANSITION: Session-phase-7 dispatcher: switch on dword_7C56A8 selects between the early-return/registration cases (0,1), the racing-start case (2), the LABEL_11 shared path (3,4), and the looped phase cases (5-8); default returns immediately [source:raw]
    // GUARD: Case 2 racing-start test reads this+0x98 as a threshold: the condition requires the flag at this+0xC1 set and this+0x98 greater than 1.5, or the mode check failing with a session-time bound [field:this:0x00000098, field:this:0x000000C1, source:raw]
    // GUARD: This+0xD8 compared equal to 0x7F7FFFFF (FLT_MAX) is the case-4 sentinel that routes to the shared LABEL_11 progress-bar path instead of returning [field:this:0x000000D8, guard:0, source:raw]
    // CALCULATION: Session-time offsets build the progress-bar record: dbl_8AFEA0 + 300.0 (cases 0/1), dbl_8AFEA0 as-is (case 2), and dbl_8AFEA0 + v12 + 2*v3 + 5.0 with v12 = 2.5 or 3.0 depending on the session-state check, where v3 is read from the flt_8AAE74 table indexed by dword_8AAE70 [global:0x008AFEA0, source:raw]
    // RETURN: No value returned on the early paths; the function is invoked from GamePostMainLoop (0x0042D8A0) and StateTriggerCheck (0x004B8AE0) [caller:0x0042D8A0, caller:0x004B8AE0, source:raw]

    // Conservative worker pseudocode:
    //   if (this->distCheck != 0) F_3DDistanceCheckAccumulate(this->distCheck, dbl_8AFE98);
    //   if (this->audioDsp != 0) {
    //     param = (dword_8AB6E4 == 2) ? (Delegation(&dword_8AB6EC), a2) : dbl_8AFEA0;
    //     AudioDSPStateUpdate(this->audioDsp, param);
    //   }
    //   if (!byte_7C56AC) {
    //     PitTimer(a1);
    //     if ((dword_7C56A0 & 1) && dword_7C56A4 >= 0) {
    //       if (dword_7C56A4 <= 6) {
    //         if ((this->tB + this->tA) * 0.5 <= dbl_8AFEA0) this->flagC0 = 1;
    //         sub_4D1D80(a1);
    //       } else if (dword_7C56A4 == 7) {
    //         if (PackedFlagRead(byte_7CA594, 57) && !byte_7CE254) this->flagC1 = 1;
    //         switch (dword_7C56A8) {
    //           case 0: case 1:
    //             if (!this->flagC1) return;
    //             CollisionProxyUnregister(byte_7CA594, 57, 1.0);
    //             ShortComputation_bde0(&dword_7CD204, a0001, 0);
    //             if (!dword_7CED8C) break;
    //             ProgressBarDataStore(2, dbl_8AFEA0 + 300.0); return;
    //           case 2:
    //             if (!(this->flagC1 && this->t98 > 1.5) &&
    //                 !(!ModeValidationCheck(a1) && this->tB - 300.0 + 1.5 < dbl_8AFEA0)) return;
    //             CollisionProxyUnregister(byte_7CA594, 57, 1.0);
    //             TickUpdateDispatch(a1);
    //             if (dword_7CEE88) { ProgressBarDataStore(3, dbl_8AFEA0); break; }
    //             /* fallthrough to LABEL_11 * /
    //           case 3:
    //             if (!sub_4D2170(a1)) return;
    //             /* fallthrough to LABEL_11 * /
    //           case 4:
    //             if (this->d8 != 0x7F7FFFFF) return;
    //   LABEL_11:
    //             v12 = SessionStateCheckWrapper(dword_7CD25C) ? (dbl_8AFEA0 < 31.0 ? (return) : 2.5) : 3.0;
    //             v2 = dword_8AAE64;
    //             if (dword_83EE60 < 1023) { ++dword_83EE60; dword_8AAE64 += 432; }
    //             ProgressBarEventEncode((_DWORD*)v2, 4, 20, 8, 255, dbl_8AFEA0, 1);
    //             *(float*)(v2 + 8) = dbl_8AFEA0 + v12;
    //             v3 = flt_8AAE74[dword_8AAE70++];
    //             *(float*)(v2 + 12) = dbl_8AFEA0 + v12 + v3 + v3 + 5.0;
    //             break;
    //           case 5: case 6: case 7: case 8:
    //             if ((this->tB + this->tA) * 0.5 <= dbl_8AFEA0) this->flagC0 = 1;
    //             if (!SessionStateCheck(dword_7CD25C) && dword_8AB6E4 != 2 && dword_7CC520) GlobalFlagSetter();
    //             sub_4D1D80(a1);
    //             break;
    //           default: return;
    //         }
    //       }
    //     }
    //   }
    // UNRESOLVED: The packet only lists four callees; the phase state machine also invokes PackedFlagRead, CollisionProxyUnregister, ShortComputation_bde0, ProgressBarDataStore, ModeValidationCheck, TickUpdateDispatch, SessionStateCheckWrapper, SessionStateCheck, GlobalFlagSetter, ProgressBarEventEncode, sub_4D1D80 and sub_4D2170, none of which carry packet evidence refs
    // UNRESOLVED: Many phase-machine globals (dword_7C56A4, dword_7C56A8, byte_7CA594, byte_7CE254, dword_7CD204, dword_7CED8C, dword_7CEE88, dword_8AAE64, dword_83EE60, dword_8AAE70, flt_8AAE74, dword_7CD25C, dword_7CC520) are read by the raw source but are not in the packet globals list
    // UNRESOLVED: The role of the incoming a2 double versus the floats derived from dbl_8AFEA0/dbl_8AFE98 is not fully recoverable from this packet
    // UNRESOLVED: this+0x98 (threshold compared against 1.5 in case 2) has no literal bound in the packet's field facts
}
