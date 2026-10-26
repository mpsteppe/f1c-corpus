// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E8F0
// Canonical corpus name: sub_49E8F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49E8F0_0049e8f0.c

void UnknownObject::ZeroStateStruct()
{
    // State-struct zero-initializer. Writes 0 to 19 consecutive DWORD fields of 'this' at offsets 0x0 through 0x48 (inclusive, 4-byte stride) and returns the original 'this' pointer. No reads, no globals, no callees. Called by MultiCallSequence (0049AFE0) as part of a state setup sequence.
    // ASSIGNMENT: Zero the first block of state fields: this+0x0, this+0x4, this+0x8, this+0xC, this+0x10, this+0x14, this+0x18, this+0x1C, this+0x20, this+0x24 [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Zero the remaining state fields: this+0x28, this+0x2C, this+0x30, this+0x34, this+0x38, this+0x3C, this+0x40, this+0x44, this+0x48 [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, source:raw]
    // CALL: Invoked by MultiCallSequence (0049AFE0) to reset the state struct before further configuration [caller:0x0049AFE0]
    // RETURN: Return the original 'this' pointer as the result [function:0x0049E8F0, source:raw]

    // Conservative worker pseudocode:
    //   result = this;
    //   for (i = 0; i < 19; i++) this[i] = 0;
    //   return result;
    // UNRESOLVED: The concrete type and semantics of the state struct owned by 'this' are unknown; only its 76-byte zeroed footprint (offsets 0x0..0x48) is observable
    // UNRESOLVED: The abi label State_Struct_Zero_Init is LEGACY trust and is not independently corroborated by static or runtime evidence in this packet
}
