// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005697A0
// Canonical corpus name: StructCopyWithReciprocalDivision
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructCopyWithReciprocalDivision_005697a0.c

void UnknownObject::StructCopyWithReciprocalDivision()
{
    // Copies a 0x18-byte (3 doubles) inertia-tensor diagonal region from a2 into this+188, then writes the reciprocals 1.0 / a2[0..2] into this+0xD4/0xDC/0xE4 (each using the 1.0 base constant dbl_59E420), then calls InertiaTensorWorldSpaceTransform(this) to refresh the world-space transform. Unconditional: no guards. Called by SuspensionSetupSectionReader, PhysicsCollisionDamageDNFDetection, VehiclePhysicsInitializer, sub_43C250 and CollisionInvMassStore.
    // CALL: qmemcpy copies 0x18 bytes (3 doubles) from a2 into this+188, staging the raw inertia diagonal values before reciprocal computation [source:raw]
    // ASSIGNMENT: Writes 1.0 / a2[0] into this+0xD4; the 1.0 numerator comes from the base double constant dbl_59E420 [field:this:0x000000D4, global:0x0059E420, source:raw]
    // ASSIGNMENT: Writes 1.0 / a2[1] into this+0xDC; the 1.0 numerator comes from the base double constant dbl_59E420 [field:this:0x000000DC, global:0x0059E420, source:raw]
    // ASSIGNMENT: Writes 1.0 / a2[2] into this+0xE4; the 1.0 numerator comes from the base double constant dbl_59E420 [field:this:0x000000E4, global:0x0059E420, source:raw]
    // CALL: Calls InertiaTensorWorldSpaceTransform(this) to transform the updated inertia into world space after the diagonal values are set [callee:0x00569410, source:raw]
    // RETURN: Returns void to its callers SuspensionSetupSectionReader (00435410), PhysicsCollisionDamageDNFDetection (00438690), VehiclePhysicsInitializer (00439210), sub_43C250 (0043C250) and CollisionInvMassStore (00459950) [function:0x005697A0, caller:0x00435410, caller:0x00438690, caller:0x00439210, caller:0x0043C250, caller:0x00459950, source:raw]

    // Conservative worker pseudocode:
    //   qmemcpy(this + 188, a2, 0x18);
    //   *(double *)(this + 212) = 1.0 / a2[0];
    //   *(double *)(this + 220) = 1.0 / a2[1];
    //   *(double *)(this + 228) = 1.0 / a2[2];
    //   InertiaTensorWorldSpaceTransform(this);
    // UNRESOLVED: The 0x18-byte copied region at this+188 is only described by the raw source; the packet tracks the reciprocal outputs (0xD4/0xDC/0xE4) but not the staged source region as a separate field
    // UNRESOLVED: The role of dbl_59E420 as the 1.0 numerator is DERIVED from the existing analysis; the raw source shows the literal 1.0 without naming the global
}
