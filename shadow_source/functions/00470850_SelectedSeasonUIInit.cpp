// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00470850
// Canonical corpus name: SelectedSeasonUIInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SelectedSeasonUIInit_00470850.c

void UnknownObject::SelectedSeasonUIInit()
{
    // Constructor for the selected-season UI list object (__thiscall). Calls the base UI list constructor sub_48C070 with flag 1, installs the vtable off_5A0540, sets field 0x31C to 401, inserts four linked-list entries (a UI handle at off_5BE704, then the "Normal", "TimeScaled" and "SelectedSeason" strings) via LinkedListInsertWithNodeAllocation with -1 (append), then runs SessionSetupScreenSetup on the object and returns it.
    // CALL: Call base UI list constructor sub_48C070(this, 1) before any field initialization. [callee:0x0048C070, source:raw]
    // ASSIGNMENT: Install the vtable: write off_5A0540 to the vtable pointer field this[0]. [field:this:0x00000000, global:0x005A0540, source:raw]
    // ASSIGNMENT: Initialize the numeric field at this[199] (byte offset 0x31C) to 401, the type/identifier literal. [field:this:0x0000031C, source:raw]
    // CALL: Insert the first linked-list entry holding the UI handle off_5BE704, appending with -1. [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Insert a linked-list entry holding the "Normal" string aNormal_0, appending with -1. [callee:0x00486F30, global:0x005C6E74, source:raw]
    // CALL: Insert a linked-list entry holding the "TimeScaled" string aTimeScaled, appending with -1. [callee:0x00486F30, global:0x005C6E68, source:raw]
    // CALL: Insert a linked-list entry holding the "SelectedSeason" string aSelectedSeason, appending with -1. [callee:0x00486F30, global:0x005C6E58, source:raw]
    // CALL: Run SessionSetupScreenSetup(this) after the list entries are in place to configure the session setup screen. [callee:0x00470960, source:raw]
    // RETURN: Return the initialized this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   void* SelectedSeasonUIInit(void* this_) {
    //     sub_48C070(this_, 1);
    //     this_[0]   = off_5A0540;
    //     this_[199] = 401;
    //     LinkedListInsertWithNodeAllocation(this_, off_5BE704, -1);
    //     LinkedListInsertWithNodeAllocation(this_, aNormal_0, -1);
    //     LinkedListInsertWithNodeAllocation(this_, aTimeScaled, -1);
    //     LinkedListInsertWithNodeAllocation(this_, aSelectedSeason, -1);
    //     SessionSetupScreenSetup(this_);
    //     return this_;
    //   }
    // UNRESOLVED: Object/class identity is unknown; it is a UI list used by the session setup flow.
    // UNRESOLVED: Role of field 0x31C (initialized to 401) is not established; it is likely a type/category identifier.
    // UNRESOLVED: Meaning of off_5BE704 entry (UI handle) versus the three string entries is unknown.
}
