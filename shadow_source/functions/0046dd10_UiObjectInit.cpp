// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046DD10
// Canonical corpus name: sub_46DD10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_46DD10_0046dd10.c

void UnknownObject::UiObjectInit()
{
    // __thiscall constructor: calls ConstructorWithByteParams(this, 0, 0) to zero-initialize the object, installs the vtable off_59FD68 at offset 0x0, explicitly zeroes the dword field at offset 0xE4 (this[57]), and returns this. ABI legacy label is UI_Object_Init.
    // CALL: Invoke base initializer ConstructorWithByteParams((int)this, 0, 0) to zero-initialize the object with two zero byte parameters. [callee:0x00487220, source:raw]
    // ASSIGNMENT: Install the vtable by writing *this = &off_59FD68 at offset 0x0. [field:this:0x00000000, global:0x0059FD68, source:raw]
    // ASSIGNMENT: Zero the dword field this[57] = 0 at offset 0xE4. [field:this:0x000000E4, source:raw]
    // RETURN: Return the constructed instance pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   DWORD *UiObjectInit(DWORD *this) {
    //     ConstructorWithByteParams((int)this, 0, 0);
    //     *this = &off_59FD68;
    //     this[0xE4 / 4] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Owning class is unidentified; the vtable off_59FD68 has no resolved type.
    // UNRESOLVED: Purpose of the zeroed dword at offset 0xE4 is unknown.
    // UNRESOLVED: The UI_Object_Init abi label is LEGACY trust and is not independently corroborated.
}
