// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005993EB
// Canonical corpus name: ObjectInitWithVTableFlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithVTableFlagSet_005993eb.c

void UnknownObject::ObjectInitWithVTableFlagSet()
{
    // Object field initializer. Zeroes this+0x2C, stores a2 into this+0x28, and sets the flag byte at this+0x30 to 32, then calls StructFieldInitWithConditionalCall. If this+0x28 is null, ORs bit 2 (value 4) into the flag at this+0x4 and calls sub_59A5FE with that value and 0. If the a3 flag is set, calls sub_59A8FA(this) instead of returning the stored result.
    // ASSIGNMENT: Zero this+0x2C [field:this:0x0000002C]
    // ASSIGNMENT: Store a2 into this+0x28 [field:this:0x00000028]
    // ASSIGNMENT: Set the flag byte at this+0x30 to 32 [field:this:0x00000030]
    // CALL: Initialize struct fields via StructFieldInitWithConditionalCall; result saved as the default return value [callee:0x0059A948]
    // GUARD: If this+0x28 is null, OR bit 2 (value 4) into the flag at this+0x4 and call sub_59A5FE with that flag value and 0 [callee:0x0059A5FE, field:this:0x00000004, field:this:0x00000028]
    // GUARD: If a3 is non-zero, call sub_59A8FA(this) and return its result [callee:0x0059A8FA, source:raw]
    // RETURN: Return the saved result from StructFieldInitWithConditionalCall (or sub_59A5FE) when a3 is zero [source:raw]

    // Conservative worker pseudocode:
    //   this->field2C = 0;
    //   this->field28 = a2;
    //   this->field30 = 32;
    //   result = StructFieldInitWithConditionalCall();
    //   if (!this->field28) {
    //     flags = this->field4;
    //     flags = flags | 4;
    //     result = sub_59A5FE(flags, 0);
    //   }
    //   if (a3) return sub_59A8FA(this);
    //   return result;
    // UNRESOLVED: Identity of the owner object and the meaning of the bit-2 flag at this+0x4 are not determined
    // UNRESOLVED: Purpose of the sub_59A5FE null-handle path and the sub_59A8FA finalization path is unknown
    // UNRESOLVED: Semantics of this+0x30 flag byte value 32 is unknown
}
