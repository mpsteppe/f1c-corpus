// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040EC70
// Canonical corpus name: StructInitializerWithFloatConstants
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitializerWithFloatConstants_0040ec70.c

void UnknownObject::StructInitializerWithFloatConstants()
{
    // __thiscall initializer on an unknown physics/collision struct: stores a caller-supplied 16-bit value at +0x8, constant 5 at +0x1C, and caller-supplied int a3 at +0x20, builds a local array of six alternating zero and float bit patterns, passes it with 10.0 to CollisionInvMassStore, bulk-sets six float fields via F_6FieldBulkSetter, then conditionally runs ShortComputation_e770(this, a4, 0) when a4 is non-zero.
    // ASSIGNMENT: Store caller-supplied __int16 a2 into this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store constant 5 into this+0x1C. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Store caller-supplied int a3 into this+0x20. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Initialize local six-int array v6 with alternating zero and float bit patterns: 0, 1072693248, 0, 1071644672, 0, 1073217536. [source:raw]
    // CALL: Call CollisionInvMassStore(10.0, v6) to store collision inverse-mass data derived from the local float array. [callee:0x00459950, source:raw]
    // CALL: Call F_6FieldBulkSetter with six literal constants (0, 1085022208, 0, 1078853632, 0x40000000, 1071854387) to bulk-set six float fields on the struct. [callee:0x00459990, source:raw]
    // GUARD: Guard on a4 (4th argument): when a4 is zero the short computation is skipped and a4 is returned unchanged. [source:raw]
    // CALL: When a4 is non-zero, call ShortComputation_e770(this, a4, 0). [callee:0x0040E770, source:raw]
    // RETURN: Return a4 when the a4 guard skips ShortComputation_e770; otherwise return its result. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_40EC70(int this, __int16 a2, int a3, int a4) {
    //     int v6[6] = { 0, 1072693248, 0, 1071644672, 0, 1073217536 };
    //     *(short*)(this + 8) = a2;
    //     *(int*)(this + 28) = 5;
    //     *(int*)(this + 32) = a3;
    //     CollisionInvMassStore(10.0, v6);
    //     F_6FieldBulkSetter(0, 1085022208, 0, 1078853632, 0x40000000, 1071854387);
    //     return a4 ? ShortComputation_e770(this, a4, 0) : a4;
    //   }
    // UNRESOLVED: Object type owning this struct is unknown; owner evidence is absent.
    // UNRESOLVED: Meaning of the constant 5 stored at +0x1C is not established.
    // UNRESOLVED: Semantics of the six float bit patterns (interpreted by CollisionInvMassStore and F_6FieldBulkSetter) are opaque without the callees.
    // UNRESOLVED: Purpose of a3 at +0x20 and of a4 as both flag and computation argument is caller-defined.
}
