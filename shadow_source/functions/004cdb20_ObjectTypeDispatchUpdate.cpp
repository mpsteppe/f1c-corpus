// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CDB20
// Canonical corpus name: sub_4CDB20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4CDB20_004cdb20.c

void UnknownObject::ObjectTypeDispatchUpdate()
{
    // Per-frame dispatch by object type: reads the type selector dword at this+4 and routes through the jump table (jpt_4CDB2F at 0x004CDB58 with data at byte_4CDB74 at 0x004CDB74) to a type-specific update handler, forwarding a1 and the @st0 double a2. Types 0-4 route to ParticleInstanceUpdate, 5 to WheelRenderObjectPerFrameUpdate, 6-7 to ScoringGateTimeoutCheck, 8 to TelemetryBarIndicatorRenderer, 12 to ParticleSystemUpdateWithWindAndDamping, 13 to ParticleEffectPhysics. Any other type returns the selector unchanged without updating. Called by WeatherParticleUpdate (004CFCC0).
    // CALCULATION: Read the object type selector dword at this+4; it selects the update path. [field:this:0x00000004, source:raw]
    // STATE_TRANSITION: Switch dispatch through the jump table at global jpt_4CDB2F (0x004CDB58) with its table data at byte_4CDB74 (0x004CDB74). [global:0x004CDB58, global:0x004CDB74, source:raw]
    // CALL: Types 0-4: ParticleInstanceUpdate(a1, a2) updates a particle instance. [source:raw]
    // CALL: Type 5: WheelRenderObjectPerFrameUpdate(a1, a2) updates a wheel render object. [source:raw]
    // CALL: Types 6-7: ScoringGateTimeoutCheck(a1, a2) checks a scoring gate timeout. [source:raw]
    // CALL: Type 8: TelemetryBarIndicatorRenderer(a1, a2) renders a telemetry bar indicator. [source:raw]
    // CALL: Type 12: ParticleSystemUpdateWithWindAndDamping(a1, a2) updates a particle system with wind and damping. [source:raw]
    // CALL: Type 13: ParticleEffectPhysics(a1, a2) runs particle effect physics. [source:raw]
    // RETURN: Default case returns the type selector unchanged without any update; the dispatched results are returned from the dispatch path, and the function is invoked by WeatherParticleUpdate (004CFCC0). [field:this:0x00000004, function:0x004CDB20, caller:0x004CFCC0, source:raw]

    // Conservative worker pseudocode:
    //   int ObjectTypeDispatchUpdate(int a1, double a2) {
    //     int type = *(int*)(a1 + 4);
    //     switch (type) {
    //       case 0: case 1: case 2: case 3: case 4:
    //         return ParticleInstanceUpdate(a1, a2);
    //       case 5:
    //         return WheelRenderObjectPerFrameUpdate(a1, a2);
    //       case 6: case 7:
    //         return ScoringGateTimeoutCheck(a1, a2);
    //       case 8:
    //         return TelemetryBarIndicatorRenderer(a1, a2);
    //       case 12:
    //         return ParticleSystemUpdateWithWindAndDamping(a1, a2);
    //       case 13:
    //         return ParticleEffectPhysics(a1, a2);
    //       default:
    //         return type;
    //     }
    //   }
    // UNRESOLVED: The six dispatch target functions carry decompiler names only; the packet lists no callee entries for them, so their addresses and identities are unverified evidence.
    // UNRESOLVED: The purpose of the @st0 double argument a2 and of the selector return value for the default path is unknown.
    // UNRESOLVED: Type values 9-11 and 14+ have no defined handler in this function.
}
