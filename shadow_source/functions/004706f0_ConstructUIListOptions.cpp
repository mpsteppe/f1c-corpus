// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004706F0
// Canonical corpus name: UIListOptionsConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListOptionsConstructor_004706f0.c

void UnknownObject::ConstructUIListOptions()
{
    // UI list-options constructor: runs the base UI-list constructor sub_48C070 with flag 1, installs vtable off_5A0480, writes the numeric field 406 at this+0x31C, inserts a linked-list node using the off_5BE704 text handle with index -1, runs RaceModeScreenSetup, and returns the initialized this.
    // CALL: Run the base UI-list constructor sub_48C070 on this with flag 1. [callee:0x0048C070, source:raw]
    // ASSIGNMENT: Install the vtable pointer off_5A0480 at this+0x0. [field:this:0x00000000, global:0x005A0480, source:raw]
    // ASSIGNMENT: Initialize the numeric field at this+0x31C (this[199]) to 406. [field:this:0x0000031C, source:raw]
    // CALL: Insert a linked-list node for this using the off_5BE704 handle with index -1. [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Run race-mode screen setup on this. [callee:0x004707C0, source:raw]
    // RETURN: Return the initialized this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   int* UIListOptionsConstructor(int* this) {
    //     sub_48C070(this, 1);
    //     this[0] = &off_5A0480;
    //     this[199] = 406;
    //     LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //     RaceModeScreenSetup(this);
    //     return this;
    //   }
    // UNRESOLVED: The exact meaning of the numeric field 406 at this+0x31C (type or menu identifier) is not established.
    // UNRESOLVED: The role of the -1 insertion index and the layout of the off_5BE704 handle are unverified.
}
