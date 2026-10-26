// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E8F0
// Canonical corpus name: StructInitWithFloatConstantsAndSubCalls
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithFloatConstantsAndSubCalls_0040e8f0.c

void UnknownObject::StructInitWithFloatConstantsAndSubCalls()
{
    // Physics collision shape initializer: writes word discriminator a2 at +0x8, zeroes +0x1C, stores a3 at +0x20, fills a local 6-dword float array, stores inverse-mass scalar 2.5 with that array via CollisionInvMassStore, bulk-sets six float constants via F_6FieldBulkSetter, then if a4 is non-zero runs ShortComputation_e770(this, a4, 0) and returns its result, otherwise returns 0.
    // ASSIGNMENT: this+0x8 (word) = a2 (type/discriminator). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: this+0x1C = 0 (subtype/kind constant). [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: this+0x20 = a3 (external pointer/data). [field:this:0x00000020, source:raw]
    // CALCULATION: Initialize local 6-dword float array v6. [source:raw]
    // CALL: CollisionInvMassStore(2.5, v6). [callee:0x00459950, source:raw]
    // CALL: F_6FieldBulkSetter(six float constants). [callee:0x00459990, source:raw]
    // GUARD: If a4 == 0, return 0. [source:raw]
    // CALL: ShortComputation_e770(this, a4, 0). [callee:0x0040E770, source:raw]
    // RETURN: Return result (a4 when a4 == 0, otherwise ShortComputation_e770 return value). [function:0x0040E8F0, source:raw]

    // Conservative worker pseudocode:
    //   *(WORD*)(this+8) = a2;
    //   *(DWORD*)(this+28) = 0;
    //   *(DWORD*)(this+32) = a3;
    //   CollisionInvMassStore(2.5, v6);
    //   F_6FieldBulkSetter(/* six float constants * /);
    //   if (a4) return ShortComputation_e770(this, a4, 0);
    //   return 0;
    // UNRESOLVED: Meaning of the six F_6FieldBulkSetter float constants and the local array is not established; values preserved from raw source without IEEE-754 interpretation.
}
