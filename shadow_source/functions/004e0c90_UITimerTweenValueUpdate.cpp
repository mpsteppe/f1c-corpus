// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E0C90
// Canonical corpus name: UITimerTweenUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UITimerTweenUpdate_004e0c90.c

void UnknownObject::UITimerTweenValueUpdate()
{
    // Per-frame UI timer/tween update. When the active flag at this+0x894 is non-zero, fetches three UI element state fields via TripleFieldQuery, computes a decremented value as this+0x930 minus dt * 0.2 (dt-scaled speed factor), and applies it through sub_54B4D0 with two zero float extras. Returns the apply result; returns an uninitialized value when inactive. Called by VehicleGraphicsSceneLoader (004DFCE0) and SteeringForceWithRandom (004F0DD0) on the frame path.
    // GUARD: Guard on the active flag this+0x894: when zero the whole update is skipped and the function returns uninitialized. [field:this:0x00000894, source:raw]
    // CALL: TripleFieldQuery(&v4, &v5, &v6) fetches the three UI element state fields/IDs to be written. [callee:0x0054B420, source:raw]
    // CALCULATION: Compute the new value v4 = *(float*)(this + 0x930) - a2 * 0.2; the 0.2 factor corresponds to the time-scaling constant flt_59E7E8. [field:this:0x00000930, global:0x0059E7E8, source:raw]
    // CALL: sub_54B4D0(v4, v5, v6, 0.0, 0.0, a2) applies the computed interpolated value to the UI element state and returns its result. [callee:0x0054B4D0, source:raw]
    // RETURN: Return the result of sub_54B4D0 when active; return uninitialized result when the active-flag guard fails. [source:raw]
    // CALL: Invoked per frame by VehicleGraphicsSceneLoader (004DFCE0) and SteeringForceWithRandom (004F0DD0). [caller:0x004DFCE0, caller:0x004F0DD0, function:0x004E0C90]

    // Conservative worker pseudocode:
    //   int sub_4E0C90(int this, float dt) {
    //     if (*(int*)(this + 0x894) == 0) return uninitialized;
    //     int v4, v5, v6;
    //     TripleFieldQuery(&v4, &v5, &v6);
    //     *(float*)&v4 = *(float*)(this + 0x930) - dt * 0.2f;
    //     return sub_54B4D0(v4, v5, v6, 0.0f, 0.0f, dt);
    //   }
    // UNRESOLVED: The identity and layout of the three fields returned by TripleFieldQuery are unknown here.
    // UNRESOLVED: Whether flt_59E7E8 is the source of the 0.2 speed factor is inferred, not shown in the raw text; the 0.2 appears as an inlined literal.
    // UNRESOLVED: The exact role of the two zero float arguments to sub_54B4D0 is not documented.
    // UNRESOLVED: Returning an uninitialized value when the guard fails is a decompiler artifact.
}
