// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D4C0
// Canonical corpus name: sub_49D4C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49D4C0_0049d4c0.c

void UnknownObject::VehicleStateAudioDispatch()
{
    // Per-state audio dispatch for a vehicle: reads seven audio-source handles from this[12]..this[18] and, depending on the results of the collision check (sub_49B9A0), two state reads (sub_49BA30), the fuel check, the disqualification/pit checks, and two flag checks, either triggers an audio effect via AudioEffectTrigger or fires a random collision event via RandomCollisionEvent. Returns the result of the final AudioEffectTrigger call.
    // CALL: Collision branch: the sub_49B9A0 result selects RandomCollisionEvent (true) or AudioEffectTrigger(0, handle) (false) on the source handle at this[12]. [source:raw, callee:0x0049B9A0, callee:0x0049E520, callee:0x0049E4E0, field:this:0x00000030]
    // CALL: Read a state value via sub_49BA30 and trigger AudioEffectTrigger(state, handle at this[13]). [source:raw, callee:0x0049BA30, callee:0x0049E4E0, field:this:0x00000034]
    // CALL: Read a second state value via sub_49BA30 and trigger AudioEffectTrigger(state == 2, handle at this[14]). [source:raw, callee:0x0049BA30, callee:0x0049E4E0, field:this:0x00000038]
    // CALL: Fuel branch: the FuelWeightComputation result selects RandomCollisionEvent (true) or AudioEffectTrigger(0, handle) (false) on the handle at this[15]. [source:raw, callee:0x0049BA50, callee:0x0049E520, callee:0x0049E4E0, field:this:0x0000003C]
    // CALL: Pit/disqualification branch on the handle at this[16]: DisqualificationCheck selects RandomCollisionEvent; otherwise PitStateFlagCheck selects AudioEffectTrigger(1); otherwise AudioEffectTrigger(0). [source:raw, callee:0x0049BAB0, callee:0x0049BA90, callee:0x0049E520, callee:0x0049E4E0, field:this:0x00000040]
    // CALL: ShortComputation_bad0 returns a flag that drives AudioEffectTrigger(flag, handle at this[17]). [source:raw, callee:0x0049BAD0, callee:0x0049E4E0, field:this:0x00000044]
    // RETURN: Return AudioEffectTrigger(VehicleFlagCheck() result, handle at this[18]). [source:raw, callee:0x0049BB20, callee:0x0049E4E0, field:this:0x00000048]

    // Conservative worker pseudocode:
    //   int sub_49D4C0(int this) {
    //     if (sub_49B9A0()) RandomCollisionEvent(*(int*)(this + 0x30));
    //     else AudioEffectTrigger(0, *(int*)(this + 0x30));
    //     AudioEffectTrigger(sub_49BA30(), *(int*)(this + 0x34));
    //     AudioEffectTrigger(sub_49BA30() == 2, *(int*)(this + 0x38));
    //     if (FuelWeightComputation()) RandomCollisionEvent(*(int*)(this + 0x3C));
    //     else AudioEffectTrigger(0, *(int*)(this + 0x3C));
    //     if (DisqualificationCheck()) RandomCollisionEvent(*(int*)(this + 0x40));
    //     else if (PitStateFlagCheck()) AudioEffectTrigger(1, *(int*)(this + 0x40));
    //     else AudioEffectTrigger(0, *(int*)(this + 0x40));
    //     AudioEffectTrigger(ShortComputation_bad0(), *(int*)(this + 0x44));
    //     return AudioEffectTrigger(VehicleFlagCheck(), *(int*)(this + 0x48));
    //   }
    // UNRESOLVED: unk_7CE234 is reported as read by the facts but does not appear in the raw decompiled body; its role is unknown.
    // UNRESOLVED: A legacy ABI lead (abi:lead) names this function State_Batched_UI_Element_Update; that naming is not corroborated by this packet and is treated only as a lead.
}
