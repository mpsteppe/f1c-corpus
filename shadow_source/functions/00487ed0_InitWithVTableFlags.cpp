// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487ED0
// Canonical corpus name: InitWithVTableFlags
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitWithVTableFlags_00487ed0.c

void UnknownObject::InitWithVTableFlags()
{
    // UI-object style initializer: calls ShortComputation_5e30(this), stores the byte flag a2 at this+0xE0 and a3 at this+0xE1, installs the vtable pointer off_5ABAC8 at this+0x0, and zeroes the dword at this+0x84; returns this. Existing analysis (DERIVED) reads off_5ABAC8 as the UIObject vtable. ABI lead name Initializes_struct_with_vtable_and_two_byte_para.
    // CALL: Call ShortComputation_5e30 with the this pointer for initial setup. [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Write the char parameter a2 into the byte at this+0xE0. [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Install the vtable pointer off_5ABAC8 at this+0x0. [field:this:0x00000000, global:0x005ABAC8, source:raw]
    // ASSIGNMENT: Write the char parameter a3 into the byte at this+0xE1. [field:this:0x000000E1, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x84. [field:this:0x00000084, source:raw]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   int InitWithVTableFlags(int this, char a2, char a3) {
    //     ShortComputation_5e30((_DWORD*)this);
    //     *(_BYTE*)(this + 224) = a2;
    //     *(_DWORD*)this = &off_5ABAC8;
    //     *(_BYTE*)(this + 225) = a3;
    //     *(_DWORD*)(this + 132) = 0;
    //     return this;
    //   }
    // UNRESOLVED: ShortComputation_5e30's setup computation is not in the packet; existing analysis labels it an initial setup performed before fields are written.
    // UNRESOLVED: The class identity behind the vtable off_5ABAC8 is unverified; existing analysis labels it VTable_UIObject_BAC8 (DERIVED), which is not packet-confirmed.
    // UNRESOLVED: The meanings of the two byte flags a2 (this+0xE0) and a3 (this+0xE1), and of the zeroed dword at this+0x84, are unknown.
    // UNRESOLVED: Owner is unknown; no owning class is evidenced in the packet.
}
