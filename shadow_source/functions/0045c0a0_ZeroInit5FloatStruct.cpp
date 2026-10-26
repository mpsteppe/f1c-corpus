// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C0A0
// Canonical corpus name: ZeroInit5FloatStruct
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroInit5FloatStruct_0045c0a0.c

void UnknownObject::ZeroInit5FloatStruct()
{
    // Straight-line initializer that zeroes six fields of the object: the first two bytes at this+0x0 and this+0x1, then the dwords at this+0x4, this+0x8, this+0xC and this+0x10. Returns this. Called once by AudioChannelInit (0045D530).
    // ASSIGNMENT: Zero the byte at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the byte at this+0x1. [field:this:0x00000001, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero the dword at this+0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x10. [field:this:0x00000010, source:raw]
    // RETURN: Return the this pointer. [source:raw]
    // CALL: Invoked by AudioChannelInit (0045D530) during audio channel setup. [caller:0x0045D530, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_45C0A0(void* this) {
    //     *(BYTE*)this = 0;
    //     *((BYTE*)this + 1) = 0;
    //     ((DWORD*)this)[1] = 0;
    //     ((DWORD*)this)[2] = 0;
    //     ((DWORD*)this)[3] = 0;
    //     ((DWORD*)this)[4] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Object identity and the semantic role of the six zeroed fields are unknown; the prelabel name suggests float fields but is DERIVED and unverified.
    // UNRESOLVED: The byte writes at this+0x0 and this+0x1 overlap the low bytes of the dword at this+0x0, so the total layout is two byte fields followed by four dword fields (or six overlapping fields); the true member layout is unconfirmed.
}
