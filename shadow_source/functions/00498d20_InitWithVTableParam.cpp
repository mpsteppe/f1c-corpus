// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498D20
// Canonical corpus name: InitWithVTableParam
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitWithVTableParam_00498d20.c

void UnknownObject::InitWithVTableParam()
{
    // Thiscall constructor. Calls parent constructor ConstructorWith1Sentinels (0x0049A930), writes the vtable pointer off_5AC9E8 to this+0x0, initializes a block of struct fields via MultiFieldStructInit (0x00498DF0), stores constructor argument a2 at this+0x44 (this[17]), and returns this. Called by ConstructorWithVTableAndSubInit_9140 (0x00499140).
    // CALL: Call parent constructor ConstructorWith1Sentinels (0x0049A930) before any member setup. [callee:0x0049A930, source:raw]
    // ASSIGNMENT: Write vtable pointer off_5AC9E8 (0x005AC9E8) into this+0x0. [field:this:0x00000000, global:0x005AC9E8, source:raw]
    // CALL: Call MultiFieldStructInit(this) (0x00498DF0) to initialize a block of struct fields. [callee:0x00498DF0, source:raw]
    // ASSIGNMENT: Store constructor argument a2 at this+0x44 (dword index this[17]). [field:this:0x00000044, source:raw]
    // RETURN: Return the initialized this pointer. [function:0x00498D20, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_498D20(void *this, int a2) {
    //     ConstructorWith1Sentinels();
    //     this[0] = &off_5AC9E8;
    //     MultiFieldStructInit(this);
    //     this[17] = a2;
    //     return this;
    //   }
    // UNRESOLVED: Meaning and purpose of the a2 value stored at offset 0x44 are not established by this packet.
    // UNRESOLVED: Fields written by MultiFieldStructInit are outside this function's evidence.
}
