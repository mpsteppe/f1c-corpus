// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042BD60
// Canonical corpus name: SeasonScoringReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonScoringReset_0042bd60.c

void UnknownObject::SeasonScoringReset()
{
    // Resets season/session scoring state: clears the global flag at 0x7C5690, then loops a pointer from unk_5EC6E4 up to dword_7C54E4, calling TeamIDSetter with an increasing index and SessionStateTransition(-1, 0) per iteration. Returns the last SessionStateTransition result.
    // ASSIGNMENT: Clear the global byte byte_7C5690 to 0 (initialization-state flag). [global:0x007C5690, source:raw]
    // ASSIGNMENT: Seed the loop: index v0 = 0 and iteration pointer v1 = &unk_5EC6E4. [global:0x005EC6E4, source:raw]
    // LOOP: do-while loop that advances v1 by 4656 int-sized elements (the per-vehicle stride) and increments v0 until v1 reaches &dword_7C54E4. [global:0x005EC6E4, global:0x007C54E4, source:raw]
    // CALL: Call TeamIDSetter (0x004C6960) with the current index v0 to set the team ID for that vehicle. [callee:0x004C6960, source:raw]
    // CALL: Call SessionStateTransition (0x004EF5A0) with (-1, 0) and store its return value as result. [callee:0x004EF5A0, source:raw]
    // CALCULATION: Increment the vehicle index v0 at the end of each iteration. [source:raw]
    // RETURN: Return result, the SessionStateTransition return value from the last executed iteration. [source:raw]
    // CALL: Called by DynMan_Post (0x0042C9F0) and sub_4A0490 (0x004A0490) to reset season scoring. [caller:0x0042C9F0, caller:0x004A0490, source:raw]

    // Conservative worker pseudocode:
    //   int sub_42BD60() {
    //     byte_7C5690 = 0;
    //     int i = 0;
    //     int* p = (int*)&unk_5EC6E4;
    //     int result;
    //     do {
    //       TeamIDSetter(i);
    //       result = SessionStateTransition(-1, 0);
    //       p += 4656;
    //       ++i;
    //     } while ((int)p < (int)&dword_7C54E4);
    //     return result;
    //   }
    // UNRESOLVED: dword_7C54E4 is treated as the loop terminator pointer; its role as CurrentVehicleIndex is DERIVED in existing analysis and not confirmed by this packet alone.
    // UNRESOLVED: Semantics of the SessionStateTransition(-1, 0) arguments are unknown here.
    // UNRESOLVED: Object type owning this reset routine is unknown.
}
