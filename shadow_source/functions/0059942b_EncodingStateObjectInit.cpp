// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059942B
// Canonical corpus name: sub_59942B
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59942B_0059942b.c

void UnknownObject::EncodingStateObjectInit()
{
    // Initializes an encoding-state object: stores the a2 argument at offset 0x0, zeroes offsets 0x8 and 0xC, runs the locale encoding initialization routine sub_59A54D on a2, stores the CRT global dword_8D5A6C into offset 0x10, then runs the locale encoding cleanup routine sub_59A5E9 on a2. Returns the this pointer.
    // ASSIGNMENT: Write the a2 argument into the object at byte offset 0x0 (this[0]). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the dword at byte offset 0x8 (this[2]). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero the dword at byte offset 0xC (this[3]). [field:this:0x0000000C, source:raw]
    // CALL: Call sub_59A54D with the address of a2 as argument; locale/encoding initialization step. [callee:0x0059A54D, source:raw]
    // ASSIGNMENT: Store the CRT global value dword_8D5A6C into byte offset 0x10 (this[4]). [field:this:0x00000010, global:0x008D5A6C, source:raw]
    // CALL: Call sub_59A5E9 with the address of a2 as argument; locale/encoding cleanup or finalization step. [callee:0x0059A5E9, source:raw]
    // RETURN: Return the this pointer (object is used as an output). [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *EncodingStateObjectInit(_DWORD *this, int a2) {
    //     this[0] = a2;
    //     this[2] = 0;
    //     this[3] = 0;
    //     sub_59A54D(&a2);
    //     this[4] = dword_8D5A6C;
    //     sub_59A5E9(&a2);
    //     return this;
    //   }
    // UNRESOLVED: The sub_59A54D and sub_59A5E9 calls take the address of a local copy of a2, not of the stored object field; the object/reference relationship between a2 and the encoding state is unclear.
    // UNRESOLVED: Roles of dword_5B9CD8 and dword_5B9CDC are not visible in the raw source of this function.
    // UNRESOLVED: dword_8D5A6C provides the initial value for offset 0x10 but its meaning (e.g. locale id, code page) is unresolved.
}
