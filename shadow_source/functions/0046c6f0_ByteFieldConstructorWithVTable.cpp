// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046C6F0
// Canonical corpus name: ShortComputation_c6f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_c6f0_0046c6f0.c

void UnknownObject::ByteFieldConstructorWithVTable()
{
    // __thiscall constructor: calls the base/sub-object initializer sub_4893C0 on the instance, stores the byte parameter a2 at offset 0x174 (this[372]), installs the vtable pointer off_59FB58 at offset 0x0, and returns this.
    // CALL: Invoke base/sub-object constructor sub_4893C0((int)this) to initialize the inherited region. [callee:0x004893C0, source:raw]
    // ASSIGNMENT: Store the parameter byte this[372] = a2 at offset 0x174. [field:this:0x00000174, source:raw]
    // ASSIGNMENT: Install the vtable by writing *(DWORD *)this = &off_59FB58 at offset 0x0. [field:this:0x00000000, global:0x0059FB58, source:raw]
    // RETURN: Return the constructed instance pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   BYTE *ByteFieldConstructorWithVTable(BYTE *this, char a2) {
    //     sub_4893C0((int)this);
    //     this[0x174] = a2;
    //     *(DWORD *)this = &off_59FB58;
    //     return this;
    //   }
    // UNRESOLVED: Owning class is unidentified; the vtable off_59FB58 has no resolved type.
    // UNRESOLVED: Semantics of the byte at offset 0x174 (flag/state byte) are unknown.
}
