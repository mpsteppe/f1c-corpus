// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046A900
// Canonical corpus name: ConstructorFieldsVTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorFieldsVTable_0046a900.c

void UnknownObject::ConstructorFieldsVTable()
{
    // __thiscall constructor. Calls base/sub-object constructor sub_4893C0, initializes fields at offsets 0x1F4/0x1F8/0x1FC/0x200/0x208 to 0 and byte at 0x174 to 0, sets field at 0x204 to constant 89, then installs vtable off_59F9E8 at offset 0. Returns the object pointer.
    // CALL: Call base/sub-object constructor sub_4893C0 on this. [callee:0x004893C0]
    // ASSIGNMENT: Zero field at offset 0x1F4. [field:this:0x000001F4]
    // ASSIGNMENT: Zero field at offset 0x1F8. [field:this:0x000001F8]
    // ASSIGNMENT: Zero field at offset 0x1FC. [field:this:0x000001FC]
    // ASSIGNMENT: Zero field at offset 0x200. [field:this:0x00000200]
    // ASSIGNMENT: Set field at offset 0x204 to constant 89. [field:this:0x00000204]
    // ASSIGNMENT: Zero byte at offset 0x174. [field:this:0x00000174]
    // ASSIGNMENT: Zero field at offset 0x208. [field:this:0x00000208]
    // ASSIGNMENT: Install vtable pointer off_59F9E8 at offset 0. [field:this:0x00000000, global:0x0059F9E8]
    // RETURN: Return this (constructed object pointer). [source:raw]

    // Conservative worker pseudocode:
    //   void *ConstructorFieldsVTable(void *this) {
    //     sub_4893C0(this);
    //     *(int*)((char*)this + 0x1F4) = 0;
    //     *(int*)((char*)this + 0x1F8) = 0;
    //     *(int*)((char*)this + 0x1FC) = 0;
    //     *(int*)((char*)this + 0x200) = 0;
    //     *(int*)((char*)this + 0x204) = 89;
    //     *((char*)this + 0x174) = 0;
    //     *(int*)((char*)this + 0x208) = 0;
    //     *(int*)this = (int)&off_59F9E8;
    //     return this;
    //   }
    // UNRESOLVED: Semantic meaning of the constant 89 at offset 0x204 and the zeroed fields is caller-unknown.
    // UNRESOLVED: Identity of the constructed object type depends on the vtable off_59F9E8, not resolved here.
}
