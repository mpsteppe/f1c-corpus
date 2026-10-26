// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E520
// Canonical corpus name: RandomCollisionEvent
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomCollisionEvent_0049e520.c

void UnknownObject::RandomCollisionEvent()
{
    // Dispatches an interrupt with the double value dbl_8AFEA0 via InterruptDispatch (0058957A), then triggers one of two audio-effect states on the handle a1 depending on whether that value is <= 0.5 or > 0.5: AudioEffectTrigger(0, a1) on the low path and AudioEffectTrigger(1, a1) on the high path. Invoked by sub_49D4C0 (0049D4C0).
    // CALCULATION: Load the double dbl_8AFEA0 into v1. [global:0x008AFEA0, source:raw]
    // CALL: Call InterruptDispatch (0058957A) with dbl_8AFEA0 as its argument. [callee:0x0058957A, global:0x008AFEA0, source:raw]
    // GUARD: Branch on v1: the <= 0.5 path calls AudioEffectTrigger with flag 0; the > 0.5 path calls AudioEffectTrigger with flag 1. [source:raw]
    // CALL: Return AudioEffectTrigger(0, a1) on the v1 <= 0.5 path. [callee:0x0049E4E0, source:raw]
    // CALL: Return AudioEffectTrigger(1, a1) on the v1 > 0.5 path. [callee:0x0049E4E0, source:raw]
    // CALL: Invoked by sub_49D4C0 (0049D4C0). [caller:0x0049D4C0, source:raw]

    // Conservative worker pseudocode:
    //   v1 = dbl_8AFEA0;
    //   InterruptDispatch(dbl_8AFEA0);
    //   if (v1 <= 0.5)
    //     return AudioEffectTrigger(0, a1);
    //   else
    //     return AudioEffectTrigger(1, a1);
    // UNRESOLVED: dbl_59E420 and dbl_59E880 are flagged as read globals by packet facts but do not appear in the raw decompiled source; existing-analysis prose derives them as a 1.0 constant and a 0.5 threshold, but their role is not verifiable here.
    // UNRESOLVED: The 0.5 threshold and dbl_8AFEA0 are interpreted by existing-analysis prose as session time; that reading is DERIVED and not confirmed by the raw source.
    // UNRESOLVED: Meaning of a1 (audio-source handle) is caller-supplied and only inferred from the AudioEffectTrigger call.
}
