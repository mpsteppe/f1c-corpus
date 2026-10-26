// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404460
// Canonical corpus name: MultiPhaseProcessingStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiPhaseProcessingStateMachine_00404460.c

void UnknownObject::VehicleWheelPhaseProcessor()
{
    // Time-sliced three-phase state machine that processes vehicle wheel data across multiple frames. Computes a target grip-derived value v9 = 1.0 - (flt_8AFEE8 + flt_8AFEEC) * 0.5 and enters the processing path when the stored float at this+0x170 differs from v9 beyond tolerance or the index at this+0x174 is not the idle sentinel -1. Each call processes a batch of at most 20 wheels: phase selector this+0x16C == 0 runs friction callback sub_4FB260(v9), == 1 runs suspension callback sub_4FAF60, == 2 runs VehicleProximity; the phase index advances in this+0x174 and a phase transition occurs only when a batch reaches the wheel count at this+0x130. When all wheels are done the machine returns to phase 0 with index -1 (idle).
    // CALCULATION: Compute target value v9 = 1.0 - (flt_8AFEE8 + flt_8AFEEC) * 0.5 from two global grip terms. [global:0x008AFEE8, global:0x008AFEEC, source:raw]
    // GUARD: Enter processing if |float(this+0x170) - v9| > 0.05 or this+0x174 != -1; -1 is the idle sentinel for the phase index. [field:this:0x00000170, field:this:0x00000174, guard:0, guard:1, source:raw]
    // ASSIGNMENT: Re-initialize the machine when idle: set this+0x174 = 0, store v9 into float(this+0x170), and set phase selector this+0x16C = 0. [field:this:0x00000174, field:this:0x00000170, field:this:0x0000016C, source:raw]
    // CALCULATION: Compute batch end bound v3 = min(this+0x174 + 20, wheel count at this+0x130). [field:this:0x00000174, field:this:0x00000130, source:raw]
    // GUARD: Dispatch on phase selector this+0x16C: 0 = friction, 1 = suspension, 2 = proximity. [field:this:0x0000016C, source:raw]
    // LOOP: Phase 0: for each wheel index in [this+0x174, v3) call sub_4FB260(v9) and advance this+0x174. [callee:0x004FB260, field:this:0x00000174, source:raw]
    // STATE_TRANSITION: Phase 0 completion: when v3 reaches this+0x130, set this+0x16C = 1 and reset this+0x174 = 0. [field:this:0x0000016C, field:this:0x00000174, source:raw]
    // LOOP: Phase 1: for each wheel index in [this+0x174, v3) call sub_4FAF60 on wheel array base this+0x134 + 316 * index and advance this+0x174. [callee:0x004FAF60, field:this:0x00000134, field:this:0x00000174, source:raw]
    // STATE_TRANSITION: Phase 1 completion: when v3 reaches this+0x130, set this+0x174 = 0 and this+0x16C = 2. [field:this:0x00000174, field:this:0x0000016C, source:raw]
    // LOOP: Phase 2: for each wheel index in [this+0x174, v3) call VehicleProximity on wheel array base this+0x134 + 316 * index and advance this+0x174. [callee:0x004FB2E0, field:this:0x00000134, field:this:0x00000174, source:raw]
    // STATE_TRANSITION: Phase 2 completion: when v3 reaches this+0x130, set this+0x16C = 0 and this+0x174 = -1, returning the machine to idle. [field:this:0x0000016C, field:this:0x00000174, source:raw]
    // CALL: Invoked from the frame/main-loop paths GamePostMainLoop (0x0042D8A0) and StateTriggerCheck (0x004B8AE0). [caller:0x0042D8A0, caller:0x004B8AE0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_404460(int this) {
    //     float v9 = 1.0f - (flt_8AFEE8 + flt_8AFEEC) * 0.5f;
    //     if (fabs(*(float*)(this + 0x170) - v9) > 0.05f || *(int*)(this + 0x174) != -1) {
    //       if (*(int*)(this + 0x174) == -1) {
    //         *(int*)(this + 0x174) = 0;
    //         *(float*)(this + 0x170) = v9;
    //         *(int*)(this + 0x16C) = 0;
    //       }
    //       int idx = *(int*)(this + 0x174);
    //       int end = idx + 20 < *(int*)(this + 0x130) ? idx + 20 : *(int*)(this + 0x130);
    //       int phase = *(int*)(this + 0x16C);
    //       if (phase == 0) {
    //         while (idx < end) { sub_4FB260(v9); idx = ++*(int*)(this + 0x174); }
    //         if (end == *(int*)(this + 0x130)) { *(int*)(this + 0x16C) = 1; *(int*)(this + 0x174) = 0; }
    //       } else if (phase == 1) {
    //         while (idx < end) { sub_4FAF60(*(int*)(this + 0x134) + 316 * idx); idx = ++*(int*)(this + 0x174); }
    //         if (end == *(int*)(this + 0x130)) { *(int*)(this + 0x174) = 0; *(int*)(this + 0x16C) = 2; }
    //       } else {
    //         while (idx < end) { VehicleProximity(*(int*)(this + 0x134) + 316 * idx); idx = ++*(int*)(this + 0x174); }
    //         if (end == *(int*)(this + 0x130)) { *(int*)(this + 0x16C) = 0; *(int*)(this + 0x174) = -1; }
    //       }
    //     }
    //   }
    // UNRESOLVED: The float at this+0x170 is written with v9 and compared to v9 with a 0.05 tolerance, but its exact meaning (a per-run target grip derived from flt_8AFEE8 + flt_8AFEEC) is not confirmed; existing analysis prose called 0x170 an index, which conflicts with the raw float access.
    // UNRESOLVED: The wheel array element type at base this+0x134 (stride 316) is not confirmed here; sub_4FAF60 and VehicleProximity are treated as suspension and proximity callbacks from existing analysis only.
    // UNRESOLVED: Globals flt_59E43C, flt_59E450 and dbl_59E480 are listed in the packet globals but are not referenced by the raw source text of this function; their role is unclear.
    // UNRESOLVED: The three callee names (friction/suspension/proximity) are DERIVED from existing analysis; only addresses are FACT.
}
