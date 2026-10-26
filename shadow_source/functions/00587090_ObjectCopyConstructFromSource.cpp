// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587090
// Canonical corpus name: ObjectCopyConstructFromSource
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectCopyConstructFromSource_00587090.c

void UnknownObject::ObjectCopyConstructFromSource()
{
    // Copy-construct style object initializer: calls StructInitParse on the source's embedded sub-structure at a2+4, then copies three source fields into this (dword at this+0x10 from *(a2+16), dword at this+0x14 from *(a2+20), byte at this+0x18 from *(a2+24)), clears the flag byte at this+0x19, installs the vtable pointer off_5B8C30 at this+0x0, and returns this. Existing analysis (DERIVED) reads this as a structural twin of ObjectInitWithVTableSetup (00587030), copying configuration from a source object instead of from parameters.
    // CALL: Call StructInitParse on the source sub-structure located at a2+4 (4 bytes into the source object) before any field copy. [callee:0x00587490, source:raw]
    // ASSIGNMENT: Copy the dword at source offset a2+16 into this+0x10 (this[4]). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Copy the dword at source offset a2+20 into this+0x14 (this[5]). [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Copy the byte at source offset a2+24 into the byte at this+0x18. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Clear the flag byte at this+0x19 to 0. [field:this:0x00000019, source:raw]
    // ASSIGNMENT: Install the vtable pointer off_5B8C30 at this+0x0. [field:this:0x00000000, global:0x005B8C30, source:raw]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* ObjectCopyConstructFromSource(_DWORD* this, int a2) {
    //     StructInitParse(a2 + 4);
    //     this[4] = *(_DWORD*)(a2 + 16);
    //     this[5] = *(_DWORD*)(a2 + 20);
    //     *((_BYTE*)this + 24) = *(_BYTE*)(a2 + 24);
    //     *((_BYTE*)this + 25) = 0;
    //     *this = &off_5B8C30;
    //     return this;
    //   }
    // UNRESOLVED: StructInitParse (0x00587490) purpose is not in the packet.
    // UNRESOLVED: Semantics of the copied source fields (a2+16, a2+20, a2+24) and the byte flag at this+0x19 are unknown.
    // UNRESOLVED: The class identity behind the vtable off_5B8C30 is unverified; it is the same vtable ObjectInitWithVTableSetup (00587030) installs.
    // UNRESOLVED: Owner is unknown; no owning class is evidenced in the packet.
}
