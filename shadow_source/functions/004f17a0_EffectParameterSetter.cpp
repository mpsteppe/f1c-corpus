// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F17A0
// Canonical corpus name: EffectParameterSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EffectParameterSetter_004f17a0.c

void UnknownObject::EffectParameterSetter()
{
    // Sets three effect parameters on the vehicle effect object: writes a2 to the parameter slot at 0x3994, writes a4 to the parameter slot at 0x3570, and writes (a3 * the multiplier read from 0x397C) to the scaled parameter slot at 0x3978. Returns a2 unchanged. Called per-frame from VehiclePhysicsTimeStep.
    // CALCULATION: Compute v5 = a3 * (float)*(this + 0x397C), reading the multiplier from the field at 0x397C. [field:this:0x0000397C, source:raw]
    // ASSIGNMENT: Write a2 into (DWORD)*(this + 0x3994), the throttle/climb effect parameter slot. [field:this:0x00003994, source:raw]
    // ASSIGNMENT: Write a4 into (DWORD)*(this + 0x3570), the effect parameter slot. [field:this:0x00003570, source:raw]
    // ASSIGNMENT: Write v5 (the scaled value) into (float)*(this + 0x3978). [field:this:0x00003978, source:raw]
    // RETURN: Return a2 (result) unchanged. [function:0x004F17A0, source:raw]

    // Conservative worker pseudocode:
    //   int EffectParameterSetter(int this, int a2, float a3, int a4) {
    //       float v5 = a3 * *(float *)(this + 0x397C);
    //       *(int *)(this + 0x3994) = a2;
    //       *(int *)(this + 0x3570) = a4;
    //       *(float *)(this + 0x3978) = v5;
    //       return a2;
    //   }
    // UNRESOLVED: Semantic role of the three parameter slots (0x3570, 0x3978, 0x3994) is not established; only raw writes are evidenced.
}
