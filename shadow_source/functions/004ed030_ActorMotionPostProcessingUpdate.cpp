// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ED030
// Canonical corpus name: ActorMotionPostProcessingUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ActorMotionPostProcessingUpdate_004ed030.c

void UnknownObject::ActorMotionPostProcessingUpdate()
{
    // Per-actor post-processing update for a motion subsystem. Lazily initializes two child subsystems (one anchored at this+3272, one at this+3340), advances an internal state machine, clears a one-shot flag, steps a damping value halfway toward its target, selects one of two force-feedback sources based on tire-contact state, solves tire-brush forces, and conditionally applies velocity clamping driven by a global time reference.
    // ASSIGNMENT: Take local base pointer v2 = this + 1764 (in bytes) used for both lazy-initialization calls. [source:raw]
    // CALL: LazyInitCallback(this + 1764, this + 3272): ensure the first subsystem is initialized with anchor at this + 3272. [callee:0x004E0D00, source:raw]
    // CALL: LazyInitCallback(v2, this + 3340): ensure the second subsystem is initialized; the anchor this + 3340 equals v2 advanced by 394 dword elements. [callee:0x004E0D00, field:this:0x00000D0C, source:raw]
    // CALL: StateTransition(this + 12992, 0): advance the actor state machine with input flag 0. [callee:0x004A56B0, source:raw]
    // GUARD: If the one-shot reset flag at this + 15712 equals 1, it is cleared to 0 so the transition runs once. [guard:0, field:this:0x00003D60, source:raw]
    // ASSIGNMENT: Clear the one-shot flag at this + 15712 to 0. [field:this:0x00003D60, source:raw]
    // GUARD: If the damping value at this + 14956 differs from the target damping at this + 14968, interpolate it. [field:this:0x00003A6C, field:this:0x00003A78, source:raw]
    // CALCULATION: Step the damping value halfway toward its target: this + 14956 = (this + 14968 + this + 14956) * 0.5. [field:this:0x00003A6C, field:this:0x00003A78, source:raw]
    // GUARD: Select the force-feedback source by tire-contact state: non-null contact pointer at this + 3340 with the contact-ready byte at this + 3404 clear takes the active-contact branch. [field:this:0x00000D0C, field:this:0x00000D4C, source:raw]
    // ASSIGNMENT: Copy the selected source into the output value at this + 14960: active-contact source at this + 14976 when contact is present, otherwise the inactive-contact source at this + 14972. [field:this:0x00003A70, field:this:0x00003A80, field:this:0x00003A7C, source:raw]
    // CALL: TireBrushModelForceSolver(this, 0): solve tire-brush force contributions for this actor with flag 0. [callee:0x004E8010, source:raw]
    // GUARD: If the input flag at this + 12988 is zero, enable velocity clamping against the global time reference. [field:this:0x000032BC, global:0x007C7428, source:raw]
    // CALL: PhysicsForceVelocityClamping(&dbl_7C7428): clamp force-derived velocity using the global race-time value. [global:0x007C7428, source:raw]
    // CALL: Invoked by sub_4B3400 (0x004B3400) as the actor motion post-processing update step. [caller:0x004B3400, source:raw]

    // Conservative worker pseudocode:
    //   void ActorMotionPostProcessingUpdate(int this) {
    //     _DWORD *v2 = (_DWORD *)(this + 1764);
    //     LazyInitCallback((_DWORD *)(this + 1764), this + 3272);
    //     LazyInitCallback(v2, (int)(v2 + 394));
    //     StateTransition((_DWORD *)(this + 12992), 0);
    //     if (*(_DWORD *)(this + 15712) == 1) *(_DWORD *)(this + 15712) = 0;
    //     if (*(float *)(this + 14956) != *(float *)(this + 14968))
    //       *(float *)(this + 14956) = (*(float *)(this + 14968) + *(float *)(this + 14956)) * 0.5;
    //     if (*(_DWORD *)(this + 3340) && !*(_BYTE *)(this + 3404))
    //       *(_DWORD *)(this + 14960) = *(_DWORD *)(this + 14976);
    //     else
    //       *(_DWORD *)(this + 14960) = *(_DWORD *)(this + 14972);
    //     TireBrushModelForceSolver(this, 0);
    //     if (!*(_DWORD *)(this + 12988)) PhysicsForceVelocityClamping(&dbl_7C7428);
    //   }
    // UNRESOLVED: The two fields at this + 14956 / this + 14960 are described as damping and selected force-feedback values from surrounding context; their exact semantics are not established in this function alone.
    // UNRESOLVED: The contact-state pointer at this + 3340 and the byte at this + 3404 relate to tire contact readiness but their naming is inferred from the branch structure.
    // UNRESOLVED: The subsystem objects initialized by LazyInitCallback (anchors this + 3272 and this + 3340) are unnamed and their identities are unknown.
}
