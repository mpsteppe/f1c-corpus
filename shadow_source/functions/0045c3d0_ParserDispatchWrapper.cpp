// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C3D0
// Canonical corpus name: ParserDispatchWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParserDispatchWrapper_0045c3d0.c

void UnknownObject::ParserDispatchWrapper()
{
    // Dispatches a parameter parse using the selector byte at this+1: calls UtilityFunction_8a60(this[1], a3) and returns 1 when it succeeds; on failure zeroes the output through a3 and returns 0. Called by ParticleSoundEffectSpawner (004607A0) as part of particle/sound parameter parsing.
    // CALL: UtilityFunction_8a60(this[1], a3) runs the parser selected by the byte at this+1 with the caller-provided output pointer [field:this:0x00000001, callee:0x00568A60, source:raw]
    // GUARD: If UtilityFunction_8a60 returns non-zero (parse success), return 1 immediately [function:0x0045C3D0, source:raw]
    // ASSIGNMENT: *a3 = 0 zeroes the output when the parse failed [source:raw]
    // RETURN: Return 0 on parse failure [source:raw]
    // CALL: Invoked by ParticleSoundEffectSpawner (004607A0) to validate a particle/sound parameter through the shared parser [caller:0x004607A0, source:raw]

    // Conservative worker pseudocode:
    //   if (UtilityFunction_8a60(this[1], a3)) return 1;
    //   *a3 = 0;
    //   return 0;
    // UNRESOLVED: The semantics of the this+1 selector byte and the set of parser kinds UtilityFunction_8a60 accepts are not defined in this packet
    // UNRESOLVED: The meaning of a3's value on the success path is unknown because the decompiled frame does not read it
}
