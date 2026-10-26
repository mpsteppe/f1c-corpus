// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00459A40
// Canonical corpus name: PhysicsStateIntegration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsStateIntegration_00459a40.c

void UnknownObject::PhysicsStateIntegration()
{
    // Frame-path vehicle physics integrator: scales body-state velocity components (a2[11..13]) by a factor a2[2], adds each result into the position/displacement accumulator doubles at this[27..29] (offsets 0xD8/0xE0/0xE8), writes the three accumulated doubles back, emits the integrated displacement as floats to output array a3, and forwards the three values to ThreeFieldSetterWithSubCall (0x0054B3B0). Called by UICameraModeDispatchWithVehicleDataRead (0x0040F550) and VehiclePhysicsVelocityAngularVelocityIntegrator (0x00459AE0).
    // ASSIGNMENT: Read a2[2] as the scale factor for the state/velocity integration. [source:raw]
    // CALCULATION: Multiply state components a2[11], a2[12], a2[13] by the scale factor to form scaled velocity components. [source:raw]
    // CALCULATION: Add each scaled component to the position/displacement accumulator doubles at this[27], this[28], this[29] (offsets 0xD8, 0xE0, 0xE8). [source:raw, field:this:0x000000D8, field:this:0x000000E0, field:this:0x000000E8]
    // ASSIGNMENT: Copy the three accumulated doubles (0x18 bytes) back into this+27, completing a read-modify-write of the 0xD8/0xE0/0xE8 accumulator. [source:raw, field:this:0x000000D8, field:this:0x000000E0, field:this:0x000000E8]
    // ASSIGNMENT: Write the three integrated components as floats into a3[0], a3[1], a3[2]. [source:raw]
    // CALL: Forward the three float output values to ThreeFieldSetterWithSubCall. [source:raw, callee:0x0054B3B0]
    // RETURN: Return the result of ThreeFieldSetterWithSubCall. [source:raw, callee:0x0054B3B0]

    // Conservative worker pseudocode:
    //   int sub_459A40(double* this, float* a2, float* a3) {
    //     double v3 = a2[2];
    //     double d0 = a2[11] * v3 + this[27];
    //     double d1 = a2[12] * v3 + this[28];
    //     double d2 = a2[13] * v3 + this[29];
    //     this[27] = d0; this[28] = d1; this[29] = d2;
    //     a3[0] = (float)d0; a3[1] = (float)d1; a3[2] = (float)d2;
    //     return ThreeFieldSetterWithSubCall(a3[0], a3[1], a3[2]);
    //   }
    // UNRESOLVED: a2 is a per-vehicle state/velocity array (indices 2, 11, 12, 13) whose exact layout is not captured by this packet.
    // UNRESOLVED: The semantic of the scale factor a2[2] is not confirmed by the packet.
    // UNRESOLVED: Downstream meaning of the a3 float outputs consumed by ThreeFieldSetterWithSubCall is outside this function.
}
