// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431390
// Canonical corpus name: PhysicsStateInitIndexed
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsStateInitIndexed_00431390.c

void UnknownObject::PhysicsStateInitIndexed()
{
    // Unconditional physics-state initializer: clears the change-flag byte at this+0x19A4, sets the activation-flag byte at this+0x0 to 1, writes a float value a3 into an indexed float slot at byte offset 4*a2+7336, then triggers pressure/force-field remapping for the vehicle state.
    // ASSIGNMENT: Clear change-flag byte at this+0x19A4 to 0. [field:this:0x000019A4, source:raw]
    // ASSIGNMENT: Set activation-flag byte at this+0x0 to 1. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write float a3 to the indexed float slot at byte offset 4*a2+7336 of the state array. [source:raw]
    // CALL: Call PressureForceFieldMapping on this to recompute pressure/force fields from the updated state. [callee:0x004313C0, source:raw]

    // Conservative worker pseudocode:
    //   this[0x19A4] = 0;
    //   this[0x0] = 1;
    //   *(float*)&this[4*a2 + 7336] = a3;
    //   return PressureForceFieldMapping(this);
}
