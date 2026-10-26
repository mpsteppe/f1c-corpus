// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9E30
// Canonical corpus name: VehicleDataAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleDataAccessor_004b9e30.c

void UnknownObject::VehicleDataAccessor()
{
    // Reads a DWORD vehicle data field through a double indirection: loads the vehicle object pointer stored at this+0x0, then reads the DWORD at vehicle object offset 0xF8C and returns it as an int. No guard, no callee. Invoked on the per-frame path by telemetry, render, particle and weather systems to sample a live vehicle scalar.
    // ASSIGNMENT: Read the vehicle object pointer stored at this+0x0 (double-indirection base for the accessor) [field:this:0x00000000, source:raw]
    // RETURN: Dereference the vehicle object pointer and return the DWORD at vehicle object offset 0xF8C as an integer [field:obj:0x00000F8C, function:0x004B9E30, source:raw]
    // CALL: Per-frame data accessor sampled by TelemetryDisplaySwitch (0047DBE0), ArithmeticComparison_9fb0 (004B9FB0), RenderTickUpdate (004C8B70), sub_4CC970 (004CC970), ParticleEffectPhysics (004CCB30), ParticleSpawnFunction (004CCE90), ParticleSystemUpdateWithWindAndDamping (004CD220), WheelContactParticle (004CD6C0) and WeatherParticleUpdate (004CFCC0) [caller:0x0047DBE0, caller:0x004B9FB0, caller:0x004C8B70, caller:0x004CC970, caller:0x004CCB30, caller:0x004CCE90, caller:0x004CD220, caller:0x004CD6C0, caller:0x004CFCC0, source:raw]

    // Conservative worker pseudocode:
    //   obj = *(this + 0x0);
    //   return *(obj + 0xF8C);
    // UNRESOLVED: The exact meaning of the field at vehicle object offset 0xF8C (speed, gear, or another scalar) is not documented in this packet
    // UNRESOLVED: The owner object type behind this+0x0 is unlabeled
}
