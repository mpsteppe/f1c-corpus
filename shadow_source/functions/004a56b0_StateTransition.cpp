// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A56B0
// Canonical corpus name: StateTransition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateTransition_004a56b0.c

void UnknownObject::StateTransition()
{
    // Mode/flag switch with a return code. With a2 == 0 it resets this+0x128 to 1 and clears this+0x12C/0x130 to 0, returning 0. With a2 non-zero, if this+0x128 is already 2 it returns 2 without changing state (redundant-activation guard); otherwise it sets this+0x128 to 2, this+0x12C to 1, this+0x130 to 1 and returns 1. Called by PitStopDecisionTireCompound, PitPartStateCopy, CollisionSparkParticleEffects, ActorMotionPostProcessingUpdate and RepairServiceStateDispatcher.
    // GUARD: Branch on the activation request a2: when zero the reset path runs, otherwise the activation path [source:raw]
    // ASSIGNMENT: Reset path: writes this+0x128 = 1, this+0x12C = 0, this+0x130 = 0 and sets the result to 0 [field:this:0x00000128, field:this:0x0000012C, field:this:0x00000130, source:raw]
    // GUARD: Redundant-activation guard (this+0x128 != 2): when the mode is already 2 the state-change block is skipped and the result is 2 [field:this:0x00000128, guard:0, source:raw]
    // ASSIGNMENT: Activation path: writes this+0x128 = 2, this+0x12C = 1, this+0x130 = 1 and sets the result to 1 [field:this:0x00000128, field:this:0x0000012C, field:this:0x00000130, source:raw]
    // RETURN: Returns 0 (reset), 1 (activated) or 2 (already active); called by PitStopDecisionTireCompound (0042A3D0), PitPartStateCopy (004A5330), CollisionSparkParticleEffects (004EC1A0), ActorMotionPostProcessingUpdate (004ED030) and RepairServiceStateDispatcher (004ED250) [function:0x004A56B0, caller:0x0042A3D0, caller:0x004A5330, caller:0x004EC1A0, caller:0x004ED030, caller:0x004ED250, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (a2) {
    //     result = 2;
    //     if (this[74] != 2) {
    //       this[74] = 2; result = 1;
    //       this[75] = 1; this[76] = 1;
    //     }
    //   } else {
    //     this[74] = 1; this[75] = 0; this[76] = 0;
    //   }
    //   return result;
    // UNRESOLVED: The semantic meaning of mode values 1/2 and the two status flags (operation mode versus status flags) is DERIVED from the existing analysis; the raw source only shows the writes and the return codes
    // UNRESOLVED: The wider state machine this function participates in (per its five callers) is not visible from this packet
}
