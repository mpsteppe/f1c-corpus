// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1890
// Canonical corpus name: SpeedValueSetterWithGlobalMirror
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpeedValueSetterWithGlobalMirror_004f1890.c

void UnknownObject::SpeedValueSetterWithGlobalMirror()
{
    // Sets a per-instance speed value at this+0x3978 from the float argument, then mirrors that value into the global dbl_7C75C4 when the rigid-body constraint pointer at this+0x32BC is null. Returns the (previously read) constraint pointer value.
    // ASSIGNMENT: Write the float argument a2 into the local speed field (this+0x3978). [field:this:0x00003978, source:raw]
    // CALCULATION: Load the rigid-body constraint pointer (this+0x32BC) into result. [field:this:0x000032BC, source:raw]
    // GUARD: Mirror to the global only when the constraint pointer (this+0x32BC) is null. [field:this:0x000032BC, source:raw]
    // ASSIGNMENT: Write the float argument a2 into the global dbl_7C75C4. [global:0x007C75C4, source:raw]
    // RETURN: Return result (the mirror gate value read from this+0x32BC). [source:raw]

    // Conservative worker pseudocode:
    //   this->local_speed_field = a2;
    //   int result = this->rigid_body_constraint_ptr;
    //   if (result == 0)
    //     dbl_7C75C4 = a2;
    //   return result;
}
