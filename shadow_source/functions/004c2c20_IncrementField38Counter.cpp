// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2C20
// Canonical corpus name: SimpleCounterIncrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SimpleCounterIncrement_004c2c20.c

void UnknownObject::IncrementField38Counter()
{
    // Increments the caller's int32 field at +0x38 (this[14]) by one and returns nothing. A void thiscall counter increment with no guard, no callee, and no return value. Invoked from SeasonScoringInfoUpdater (0x004C2A80).
    // ASSIGNMENT: Pre-increment the counter field: ++this[14], i.e. add 1 to the int32 field at offset +0x38. [field:this:0x00000038, source:raw]
    // CALL: Invoked by SeasonScoringInfoUpdater (0x004C2A80) as a counter-advance step. [caller:0x004C2A80, abi:lead, function:0x004C2C20, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4C2C20() {
    //     ++this[14];
    //   }
    // UNRESOLVED: What the counter at +0x38 counts (races, sessions, attempts) is not evidenced; the legacy 'Simple_Counter_Increment' ABI name (abi:lead) is adopted but not independently confirmed.
}
