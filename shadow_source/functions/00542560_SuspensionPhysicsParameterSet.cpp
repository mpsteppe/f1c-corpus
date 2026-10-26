// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542560
// Canonical corpus name: SuspensionPhysicsParameterSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SuspensionPhysicsParameterSet_00542560.c

void UnknownObject::SuspensionPhysicsParameterSet()
{
    // Stores a caller-supplied parameter a2 into this->0x19C (this[103]) when a2 is non-zero, then calls sub_542200 (00542200) with the four float/double fields at offsets 0x54, 0x58, 0x64, 0x68 plus flag 1. Returns 0 immediately when a2 is zero, otherwise returns a2. Invoked by sub_409890, sub_548AD0, sub_560FE0.
    // GUARD: If a2 is zero, return 0 immediately without storing the parameter or calling sub_542200. [source:raw]
    // ASSIGNMENT: Store a2 into this[103] (offset 0x19C). [field:this:0x0000019C, source:raw]
    // CALCULATION: Read this[22] (offset 0x58) as a double into v7. [field:this:0x00000058, source:raw]
    // CALCULATION: Read this[21] (offset 0x54) as a float into v6. [field:this:0x00000054, source:raw]
    // CALCULATION: Read this[25] (offset 0x64) as a float into v5. [field:this:0x00000064, source:raw]
    // CALCULATION: Read this[26] (offset 0x68) as a float into v4. [field:this:0x00000068, source:raw]
    // CALL: Call sub_542200 (00542200) with arguments (this, v4, v5, v6, v7, 1) forwarding the four field values and a literal flag of 1. [callee:0x00542200, source:raw]
    // CALL: Invoked by sub_409890 (00409890), sub_548AD0 (00548AD0), sub_560FE0 (00560FE0). [caller:0x00409890, caller:0x00548AD0, caller:0x00560FE0, source:raw]
    // RETURN: Return result = a2 after the parameter store and sub_542200 call on the non-zero path. [source:raw]

    // Conservative worker pseudocode:
    //   result = a2;
    //   if (a2) {
    //     this[103] = a2;
    //     v7 = (double)this[22];
    //     v6 = (float)this[21];
    //     v5 = (float)this[25];
    //     v4 = (float)this[26];
    //     return sub_542200(this, v4, v5, v6, v7, 1);
    //   }
    //   return result;
    // UNRESOLVED: The contract of sub_542200 and the meaning of its four float/double arguments are not documented in this function; the existing-analysis prose labels them viewport dimensions but that is not verifiable from the raw source.
    // UNRESOLVED: Semantics of the parameter stored at offset 0x19C are caller-supplied and unknown here.
}
