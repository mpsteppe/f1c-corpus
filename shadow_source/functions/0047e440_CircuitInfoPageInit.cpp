// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047E440
// Canonical corpus name: sub_47E440
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47E440_0047e440.c

void UnknownObject::CircuitInfoPageInit()
{
    // Constructor for a circuit-info page object. Runs base-class initialization sub_4893C0, installs the vtable off_5A6BC8 at this+0, then inserts six category label strings (circuit name, location, first grand prix, circuit length, lap record, race laps 100%) into a linked list via LinkedListInsertWithNodeAllocation with tag -1, and returns this.
    // CALL: Run base-class/embedded-object initialization sub_4893C0 before any member work. [callee:0x004893C0, source:raw]
    // ASSIGNMENT: Install the class vtable: *this = &off_5A6BC8. [field:this:0x00000000, global:0x005A6BC8, source:raw]
    // CALL: Insert the circuit-name category string aCircuitName into the linked list with tag -1. [callee:0x00486F30, global:0x005C74A0, source:raw]
    // CALL: Insert the location category string aLocation_0 into the linked list with tag -1. [callee:0x00486F30, global:0x005C7494, source:raw]
    // CALL: Insert the first-grand-prix category string aFirstGrandPrix into the linked list with tag -1. [callee:0x00486F30, global:0x005C7480, source:raw]
    // CALL: Insert the circuit-length category string aCircuitLength into the linked list with tag -1. [callee:0x00486F30, global:0x005C7470, source:raw]
    // CALL: Insert the lap-record category string aLapRecord into the linked list with tag -1. [callee:0x00486F30, global:0x005C7464, source:raw]
    // CALL: Insert the race-laps-at-100% category string aRaceLaps100 into the linked list with tag -1. [callee:0x00486F30, global:0x005C7450, source:raw]
    // RETURN: Return this, completing the constructor contract. [function:0x0047E440, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_47E440(_DWORD *this) {
    //     sub_4893C0();
    //     *this = &off_5A6BC8;
    //     LinkedListInsertWithNodeAllocation(aCircuitName, -1);
    //     LinkedListInsertWithNodeAllocation(aLocation_0, -1);
    //     LinkedListInsertWithNodeAllocation(aFirstGrandPrix, -1);
    //     LinkedListInsertWithNodeAllocation(aCircuitLength, -1);
    //     LinkedListInsertWithNodeAllocation(aLapRecord, -1);
    //     LinkedListInsertWithNodeAllocation(aRaceLaps100, -1);
    //     return this;
    //   }
    // UNRESOLVED: sub_4893C0 is called with no arguments here; whether it is a base-class constructor or an embedded list-initializer is defined by its own body, not this packet.
    // UNRESOLVED: The linked-list head and node layout are internal to LinkedListInsertWithNodeAllocation; the tag -1 role is not documented in this packet.
    // UNRESOLVED: The exact UI role of the six inserted strings (label rows of the circuit-info page) is inferred from their names and is DERIVED only.
}
