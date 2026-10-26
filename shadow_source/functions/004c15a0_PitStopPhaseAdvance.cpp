// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C15A0
// Canonical corpus name: PitStopPhaseAdvance
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitStopPhaseAdvance_004c15a0.c

void UnknownObject::PitStopPhaseAdvance()
{
    // Advances a session/pit-stop phase counter at this+0xB14C (byte 0xB150 zeroed on each transition). Cases 1-6 increment the phase (1->2 ... 6->7) and zero byte 0xB150. Case 7 calls RaceStandingsRankingsComputation, then TimerCountdownWithStateTransition whose return value becomes the function result, and falls through to the shared tail that zeros byte 0xB150. Any unhandled phase value also hits the shared tail and returns the uninitialized low byte value.
    // CALCULATION: Compute v2 = *(this + 0xB14C) - 1 from the phase counter. [field:this:0x0000B14C, source:raw]
    // GUARD: Switch on the phase counter at this+0xB14C with cases 1-7; unhandled values fall to the shared LABEL_9 tail. [field:this:0x0000B14C, source:raw]
    // STATE_TRANSITION: Cases 1-6: advance the phase counter this+0xB14C to the next value (1->2 through 6->7) and zero the flag byte at this+0xB150. [field:this:0x0000B14C, field:this:0x0000B150, source:raw]
    // CALL: Case 7: call j_RaceStandingsRankingsComputation to compute race standings and rankings. [callee:0x004C1660, source:raw]
    // CALL: Case 7: call TimerCountdownWithStateTransition and store its low byte as v2, the function return value. [callee:0x004C1670, source:raw]
    // ASSIGNMENT: Shared tail (LABEL_9) reached by case 7 and the default: zero the flag byte at this+0xB150. [field:this:0x0000B150, source:raw]
    // CALL: The switch dispatches through the jump table at 0x004C1644 (jpt_4C15B3). [global:0x004C1644, source:raw]
    // RETURN: Invoked from sub_4A0590 and sub_4A0760; returns v2 (phase-1, or the timer countdown result in case 7). [caller:0x004A0590, caller:0x004A0760, function:0x004C15A0, source:raw]

    // Conservative worker pseudocode:
    //   char PitStopPhaseAdvance(int this) {
    //     int v2 = *(int*)(this + 0xB14C) - 1;
    //     switch (*(int*)(this + 0xB14C)) {
    //       case 1: *(int*)(this + 0xB14C) = 2; *(char*)(this + 0xB150) = 0; break;
    //       case 2: *(int*)(this + 0xB14C) = 3; *(char*)(this + 0xB150) = 0; break;
    //       case 3: *(int*)(this + 0xB14C) = 4; *(char*)(this + 0xB150) = 0; break;
    //       case 4: *(int*)(this + 0xB14C) = 5; *(char*)(this + 0xB150) = 0; break;
    //       case 5: *(int*)(this + 0xB14C) = 6; *(char*)(this + 0xB150) = 0; break;
    //       case 6: *(int*)(this + 0xB14C) = 7; *(char*)(this + 0xB150) = 0; break;
    //       case 7:
    //         j_RaceStandingsRankingsComputation(this);
    //         v2 = TimerCountdownWithStateTransition(this);
    //         /* fall through * /
    //       default:
    //         *(char*)(this + 0xB150) = 0;
    //         break;
    //     }
    //     return v2;
    //   }
    // UNRESOLVED: The concrete meaning of phase values 1-7 (which session stages they map to) is not established; the phase enum is consumed by the callers sub_4A0590 and sub_4A0760.
    // UNRESOLVED: In case 7 the zeroing of byte 0xB150 happens twice (once logically by the case-7 goto path and once at the shared tail), but the byte ends at 0 in every path.
}
