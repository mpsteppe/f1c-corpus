// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00557410
// Canonical corpus name: StructZeroInitWithDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructZeroInitWithDefaults_00557410.c

void UnknownObject::initializeStructWithDefaults()
{
    // Constructor/initializer. Calls GlobalZeroInit_c2a0(this), zeroes the first byte of the object (+0x0), zeroes the dword range +0x20..+0x50 and the dwords +0x64/+0x68, initializes three floats to 1.0f (+0x54..+0x5C) and one float to 100.0f (+0x60), then returns this. The 100.0f value suggests a default maximum/range bound.
    // CALL: Call GlobalZeroInit_c2a0(this) to zero-initialize the object before the explicit field writes. [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Zero the first byte of the object at +0x0 via *(_BYTE *)this = 0. [field:this:0x00000000]
    // ASSIGNMENT: Zero dwords +0x20..+0x50 (this[8..20]). [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050]
    // ASSIGNMENT: Set three floats +0x54..+0x5C (this[21..23]) to 1065353216 (1.0f). [field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C]
    // ASSIGNMENT: Set the float at +0x60 (this[24]) to 1120403456 (100.0f). [field:this:0x00000060]
    // ASSIGNMENT: Zero dwords +0x64 and +0x68 (this[25..26]). [field:this:0x00000064, field:this:0x00000068]
    // RETURN: Return the initialized object pointer (this). [function:0x00557410, source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   *(_BYTE *)this = 0;
    //   this[8] = 0; this[9] = 0; this[10] = 0; this[11] = 0; this[12] = 0; this[13] = 0;
    //   this[14] = 0; this[15] = 0; this[16] = 0; this[17] = 0; this[18] = 0;
    //   this[19] = 0; this[20] = 0;
    //   this[21] = 1.0f; this[22] = 1.0f; this[23] = 1.0f;
    //   this[24] = 100.0f;
    //   this[25] = 0; this[26] = 0;
    //   return this;
    // UNRESOLVED: The owning class is unknown; the struct is constructed from the caller sub_559200 but no type identity is established from the packet.
    // UNRESOLVED: The float defaults (1.0f at +0x54..+0x5C and the 100.0f bound at +0x60) suggest a range-limited quantity, but that role is DERIVED, not confirmed.
    // UNRESOLVED: The fields between the zeroed ranges are not written by this function and are not evidenced in the packet.
}
