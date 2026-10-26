// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8AE0
// Canonical corpus name: StateTriggerCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateTriggerCheck_004b8ae0.c

void UnknownObject::StateTriggerCheck()
{
    // Loading/state-transition trigger check: refuses to advance while the target progress field this[0xF34] is not above the current progress this[0xF30] (difference <= 0.0). When the guard passes it ticks a broad set of global subsystems (multi-phase state machine, weather particles, session state, collision broadcast, main game tick, camera, render tick/save, scoring dispatch and two un-named helpers), then returns 1 only if no completion guard trips (dword_7CC4C8 set, PackedFlagRead(byte_7CA594, 1), or FloatGetter(this) already at/above this[0xF34]); otherwise returns 0. Called from LoadingPhase1 and LoadingPhase2 as a per-frame loading gate.
    // ASSIGNMENT: Initialize the return accumulator v3 to 1 before any guard runs. [source:raw]
    // GUARD: Early-return guard: if (this[0xF34] - this[0xF30]) <= 0.0, return 0 (target threshold not yet above current progress). [field:this:0x00000F30, field:this:0x00000F34, source:raw]
    // CALL: Call sub_4B8C40 with the value *a2 and constant 0. [callee:0x004B8C40, source:raw]
    // CALL: ConditionalMultiPathDispatcher on global dword_8AB6E4. [callee:0x004BA180, global:0x008AB6E4, source:raw]
    // CALL: WeatherParticleUpdate on global dword_8ACEA0. [callee:0x004CFCC0, global:0x008ACEA0, source:raw]
    // CALL: MultiPhaseProcessingStateMachine on the object pointer dword_5EA2C0. [callee:0x00404460, global:0x005EA2C0, source:raw]
    // CALL: sub_4D4580 on global dword_8ACEE0. [callee:0x004D4580, global:0x008ACEE0, source:raw]
    // CALL: CollisionGlobalUpdateBroadcast on the global ppvOut pointer. [callee:0x00455E50, global:0x007CA590, source:raw]
    // CALL: MainGameTickUpdate on the global unk_5EC6D0 object. [callee:0x0042C690, global:0x005EC6D0, source:raw]
    // CALL: MainCameraDirectorUpdate on the global dword_5EA510 object. [callee:0x0040CA30, global:0x005EA510, source:raw]
    // CALL: RenderTickUpdate on the global byte_8AC494. [callee:0x004C8B70, global:0x008AC494, source:raw]
    // CALL: RenderScreenSave with the byte value byte_8AB678. [callee:0x004B40A0, global:0x008AB678, source:raw]
    // CALL: ShortComputation_f070 on the global dword_7CE048. [callee:0x0049F070, global:0x007CE048, source:raw]
    // CALL: sub_4FA7E0 on the global unk_8AFE18. [callee:0x004FA7E0, global:0x008AFE18, source:raw]
    // CALL: sub_4A1830 with no arguments. [callee:0x004A1830, source:raw]
    // GUARD: Return-zero guard: if dword_7CC4C8 is set, or PackedFlagRead(byte_7CA594, 1) is true, or FloatGetter(this) >= this[0xF34], return 0. [callee:0x0044F460, callee:0x004B8790, field:this:0x00000F34, global:0x007CA594, global:0x007CC4C8, source:raw]
    // RETURN: Return v3 (=1) when neither guard trips. [source:raw]

    // Conservative worker pseudocode:
    //   char StateTriggerCheck(float *this, float *a2) {
    //     char v3 = 1;
    //     if (this[973] - this[972] <= 0.0f) return 0;
    //     sub_4B8C40(*a2, 0);
    //     ConditionalMultiPathDispatcher(&dword_8AB6E4);
    //     WeatherParticleUpdate(&dword_8ACEA0);
    //     MultiPhaseProcessingStateMachine((int)dword_5EA2C0);
    //     sub_4D4580(&dword_8ACEE0);
    //     CollisionGlobalUpdateBroadcast((float *)&ppvOut);
    //     MainGameTickUpdate(&unk_5EC6D0);
    //     MainCameraDirectorUpdate((int)&dword_5EA510);
    //     RenderTickUpdate(&byte_8AC494);
    //     RenderScreenSave(byte_8AB678);
    //     ShortComputation_f070(&dword_7CE048);
    //     sub_4FA7E0(&unk_8AFE18);
    //     sub_4A1830();
    //     if (dword_7CC4C8 || PackedFlagRead(byte_7CA594, 1) || FloatGetter(this) >= this[973]) return 0;
    //     return v3;
    //   }
    // UNRESOLVED: Global flt_59E440 appears in the packet globals but not in the raw source text; its use here is unclear.
    // UNRESOLVED: Global unk_7CE2A4 appears in the packet globals but not in the raw source text; its use here is unclear.
    // UNRESOLVED: Concrete owner class of the loading/state object behind `this` is not identifiable from this packet; only the two float fields at 0xF30 and 0xF34 are observed.
    // UNRESOLVED: Semantics of the subsystem tick calls are inferred from their legacy names; sub_4B8C40, sub_4D4580, sub_4FA7E0 and sub_4A1830 have unknown behavior.
}
