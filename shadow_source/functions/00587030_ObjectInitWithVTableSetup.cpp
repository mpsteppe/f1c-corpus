// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587030
// Canonical corpus name: ObjectInitWithVTableSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithVTableSetup_00587030.c

void UnknownObject::ObjectInitWithVTableSetup()
{
    // Object initializer: calls sub_587460(0), then writes the four parameter-derived fields this[4]=a4 (0x10), this[5]=a2 (0x14), byte this+0x18=a3 and byte this+0x19=0, and installs the vtable pointer off_5B8C30 at this+0x0; returns this. Existing analysis (DERIVED) reads this as a TaskBase-derived task-object init. ABI lead name Object_Init_with_VTable_Setup.
    // CALL: Call sub_587460 with argument 0 before any field assignment. [callee:0x00587460, source:raw]
    // ASSIGNMENT: Write a4 into the dword at this+0x10 (this[4]). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write a2 into the dword at this+0x14 (this[5]). [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write the char parameter a3 into the byte at this+0x18. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Clear the byte at this+0x19 to 0. [field:this:0x00000019, source:raw]
    // ASSIGNMENT: Install the vtable pointer off_5B8C30 at this+0x0. [field:this:0x00000000, global:0x005B8C30, source:raw]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* ObjectInitWithVTableSetup(_DWORD* this, int a2, char a3, int a4) {
    //     sub_587460(0);
    //     this[4] = a4;
    //     this[5] = a2;
    //     *((_BYTE*)this + 24) = a3;
    //     *((_BYTE*)this + 25) = 0;
    //     *this = &off_5B8C30;
    //     return this;
    //   }
    // UNRESOLVED: sub_587460's purpose is not in the packet; existing analysis labels it a subroutine init called with parameter 0.
    // UNRESOLVED: The class identity behind the vtable off_5B8C30 is unverified; existing analysis labels it VTable_TaskBase (DERIVED), which is not packet-confirmed.
    // UNRESOLVED: The semantics of the stored parameters a2, a3 and a4 (config fields at 0x10, 0x14, 0x18) are unknown.
    // UNRESOLVED: Owner is unknown; no owning class is evidenced in the packet.
}
