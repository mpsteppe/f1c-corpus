// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040EBD0
// Canonical corpus name: UtilityFunction_ebd0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_ebd0_0040ebd0.c

void UnknownObject::PhysicsShapeInitType4()
{
    // Physics collision-shape initializer. Writes a discriminator word at this+8, the subtype constant 4 at this+28, and the external data pointer a3 at this+32, then seeds a six-dword stack vector with raw 0.0/2.0-ish float bit patterns and passes it to CollisionInvMassStore with the literal 10.0, followed by F_6FieldBulkSetter with six float bit-pattern literals. When a4 is non-zero, hands off to ShortComputation_e770(this, a4, 0); otherwise returns a4. Invoked by sub_40FE50.
    // ASSIGNMENT: Write the 16-bit discriminator a2 to this+8 [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the constant 4 to this+28 (physics shape subtype marker) [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Write the external data pointer a3 to this+32 [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Initialize the v6 stack vector with six dword literals (0, 1072693248, 0, 1071644672, 0, 1073217536), kept in their raw bit-pattern spelling [source:raw]
    // CALL: CollisionInvMassStore(10.0, v6) stores the literal inverse-mass 10.0 alongside the six-dword v6 vector into collision data [callee:0x00459950, source:raw]
    // CALL: F_6FieldBulkSetter(0, 1085022208, 0, 1078853632, 0x40000000, 1071854387) bulk-writes six float fields into the collision data structure [callee:0x00459990, source:raw]
    // GUARD: When a4 is non-zero, the function returns ShortComputation_e770(this, a4, 0) instead of falling through [callee:0x0040E770, source:raw]
    // RETURN: Return a4 unchanged when a4 is zero; otherwise return the ShortComputation_e770 result. Called by sub_40FE50 (0040fe50) [function:0x0040EBD0, callee:0x0040E770, caller:0x0040FE50, source:raw]

    // Conservative worker pseudocode:
    //   this+8 (word) = a2;
    //   this+28 = 4;
    //   this+32 = a3;
    //   v6[0..5] = {0, 1072693248, 0, 1071644672, 0, 1073217536};
    //   CollisionInvMassStore(10.0, v6);
    //   F_6FieldBulkSetter(0, 1085022208, 0, 1078853632, 0x40000000, 1071854387);
    //   if (a4) return ShortComputation_e770(this, a4, 0);
    //   return a4;
    // UNRESOLVED: The six dword literals in v6 and the six F_6FieldBulkSetter arguments are float bit patterns whose numeric meaning (beyond CollisionInvMassStore taking 10.0) is not interpreted, per the preserve-raw-literals rule
    // UNRESOLVED: The role of a4 as a continuation trigger and the meaning of the 4 subtype constant are inferred from the surrounding call pattern only
    // UNRESOLVED: The owning collision-shape class is unidentified; the LEGACY abi name General_utility_function carries no semantic information
}
