// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DA820
// Canonical corpus name: StateBlockInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateBlockInitializer_004da820.c

void UnknownObject::StateBlockInitializer()
{
    // Initializes a state block: zeros dwords this+0x10, this+0x18, this+0x1C, this+0x20 and this+0x24, sets dword this+0x14 to 1114636288 (the packet's init_float 60.0), zeros byte this+0x28, and returns 0. No reads, no globals, no callees. Matches the template prelabel category ctor_init.
    // ASSIGNMENT: Zero the dword field this+0x10. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Set the dword field this+0x14 to 1114636288, which the packet records as the float value 60.0. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Zero the dword fields this+0x18, this+0x1C, this+0x20 and this+0x24. [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Zero the byte field this+0x28 (written as a _BYTE). [field:this:0x00000028, source:raw]
    // RETURN: Return 0. [function:0x004DA820, source:raw]

    // Conservative worker pseudocode:
    //   *(dword*)(this+0x10) = 0;
    //   *(dword*)(this+0x14) = 1114636288; /* float 60.0 * /
    //   *(dword*)(this+0x18) = 0; *(dword*)(this+0x1C) = 0;
    //   *(dword*)(this+0x20) = 0; *(dword*)(this+0x24) = 0;
    //   *(byte*)(this+0x28) = 0;
    //   return 0;
    // UNRESOLVED: The role of the 60.0f default at this+0x14 (a rate, timer or scale value) is not evidenced.
    // UNRESOLVED: The owning object type is unknown; no callers or class evidence exist in the packet.
    // UNRESOLVED: The proposed name follows the legacy ABI lead 'State_Block_Initializer', which is descriptive only.
}
