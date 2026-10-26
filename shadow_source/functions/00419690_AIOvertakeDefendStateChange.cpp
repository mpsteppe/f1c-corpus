// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00419690
// Canonical corpus name: AIOvertakeDefendStateChange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIOvertakeDefendStateChange_00419690.c

void UnknownObject::AIOvertakeDefendStateChange()
{
    // AI overtake/defend/pit state-change handler for session type 5 (race) and session type 7 (qualifying). Gated by a race-active flag, a track-condition float, and the race phase. For action selector a2==0 it marks a per-driver state-change flag at this[a3+108] and selects a behavior-table lookup index from the target/player relationship (10 or 16 when a3 is the player slot, 3 or 33 otherwise); a2==1 selects the defend index 4, a2==2 the pit index 5, both only for a non-player slot with a positive per-driver lap value outside championship mode; the qualifying path selects outlap indices 72 or 262 when the per-driver lap value is between 1 and total-race-laps minus 1. The chosen entry is resolved through DriverDataTableLookupAndTimeConversion with the per-driver ID and inserted into the driver action table.
    // GUARD: Entry gate: function is a no-op unless dword_7D0308 is nonzero, flt_7CF3C8 != 0.0, and dword_7C56A8 != 8 (race phase guard). [global:0x007D0308, global:0x007CF3C8, global:0x007C56A8, function:0x00419690, source:raw]
    // CALL: Initialize the local 8-float lookup buffer v9 with StructInitWithSentinelValues before any table lookup. [callee:0x004144D0, source:raw]
    // ASSIGNMENT: Seed lookupIndex v5 with the default value 5 (pit lookup index). [source:raw]
    // GUARD: Branch on session type dword_7C56A4: the value 5 selects the race path, the value 7 the qualifying path; otherwise control falls through without inserting an entry. [global:0x007C56A4, source:raw]
    // ASSIGNMENT: Record idIndexSlot v6 = driverSlot a3, used to index the per-driver ID table at the insertion site. [source:raw]
    // GUARD: Race path: dispatch on action selector a2, where 0 sets the state-change flag, 1 is the defend path, and 2 is the pit path. [source:raw]
    // ASSIGNMENT: For a2 == 0, write 1 to this[a3 + 108], the per-driver state-change flag (dword-slot offset (a3 + 108) * 4 bytes on this). [source:raw]
    // GUARD: Compare driver slot a3 against the player vehicle slot read from *(dword_7C54E8 + 18580). [global:0x007C54E8, source:raw]
    // ASSIGNMENT: When a3 is the player slot, select lookup index 10 if a3 == targetSlot a4, otherwise 16. [source:raw]
    // GUARD: When a3 is not the player slot, return early if dword_7D0410 == 5 (championship/race mode). [global:0x007D0410, source:raw]
    // ASSIGNMENT: When a3 is not the player slot, select lookup index 3 if a3 == targetSlot a4, otherwise 33. [source:raw]
    // CALL: Register the candidate overtake lookup indices 10, 16, 3 and 33 on flt_5EA618 via BooleanOROfTwoChecks before the driver-table insertion. [callee:0x00418A20, global:0x005EA618, source:raw]
    // GUARD: Defend path (a2 == 1): require a3 != player slot, per-driver lap value dword_5F0714[4656 * a3] > 0, and dword_7D0410 != 5. [global:0x005F0714, global:0x007C54E8, global:0x007D0410, source:raw]
    // CALL: Defend path: register lookup index 4 via BooleanOROfTwoChecks and set lookupIndex v5 = 4. [callee:0x00418A20, global:0x005EA618, source:raw]
    // GUARD: Pit path (a2 == 2): same preconditions as the defend path (a3 != player slot, lap value dword_5F0714[4656 * a3] > 0, dword_7D0410 != 5). [global:0x005F0714, global:0x007C54E8, global:0x007D0410, source:raw]
    // CALL: Pit path: register lookup index 5 via BooleanOROfTwoChecks, leaving the default lookupIndex. [callee:0x00418A20, global:0x005EA618, source:raw]
    // GUARD: Qualifying path (dword_7C56A4 == 7 and a2 == 0): the per-driver lap value v7 = dword_5F0714[4656 * a3] must be greater than 1 and less than dword_8ACF8C - 1 for the outlap branch to run. [global:0x005F0714, global:0x008ACF8C, source:raw]
    // ASSIGNMENT: Qualifying path: select outlap lookup index 262 when a3 != player slot, otherwise 72. [global:0x007C54E8, source:raw]
    // CALL: Qualifying path: register outlap lookup indices 72 and 262 via BooleanOROfTwoChecks. [callee:0x00418A20, global:0x005EA618, source:raw]
    // CALL: Resolve the behavior entry with DriverDataTableLookupAndTimeConversion(v9, lookupIndex v5, dword_5F0F74[4656 * idIndexSlot v6], -1, -1, -1, -2.0, -2.0), supplying the per-driver ID from dword_5F0F74. [callee:0x004144F0, global:0x005F0F74, source:raw]
    // CALL: Insert the resolved entry into the driver action table via InsertDriverTableEntry(flt_5EA618, v9). [callee:0x00418560, global:0x005EA618, source:raw]
    // CALL: Single static caller is sub_4D1C40 (0x004D1C40), which drives the overtake/defend/pit state-change path. [caller:0x004D1C40, source:raw]

    // Conservative worker pseudocode:
    //   void __thiscall AIOvertakeDefendStateChange(int* this, int actionSelector, int driverSlot, int targetSlot) {
    //     if (!dword_7D0308 || flt_7CF3C8 == 0.0 || dword_7C56A8 == 8) return;
    //     float buffer[8];
    //     StructInitWithSentinelValues(buffer);
    //     int lookupIndex = 5;
    //     if (dword_7C56A4 == 5) {
    //       int idIndex = driverSlot;
    //       if (actionSelector == 0) {
    //         this[driverSlot + 108] = 1;
    //         if (driverSlot == *(int*)(dword_7C54E8 + 18580))
    //           lookupIndex = (driverSlot == targetSlot) ? 10 : 16;
    //         else {
    //           if (dword_7D0410 == 5) return;
    //           lookupIndex = (driverSlot == targetSlot) ? 3 : 33;
    //         }
    //         BooleanOROfTwoChecks(flt_5EA618, 10);
    //         BooleanOROfTwoChecks(flt_5EA618, 16);
    //         BooleanOROfTwoChecks(flt_5EA618, 3);
    //         BooleanOROfTwoChecks(flt_5EA618, 33);
    //       } else if (actionSelector == 1) {
    //         if (driverSlot != *(int*)(dword_7C54E8 + 18580) && dword_5F0714[4656 * driverSlot] > 0 && dword_7D0410 != 5) {
    //           BooleanOROfTwoChecks(flt_5EA618, 4);
    //           lookupIndex = 4;
    //         } else return;
    //       } else if (actionSelector == 2) {
    //         if (driverSlot != *(int*)(dword_7C54E8 + 18580) && dword_5F0714[4656 * driverSlot] > 0 && dword_7D0410 != 5)
    //           BooleanOROfTwoChecks(flt_5EA618, 5);
    //         else return;
    //       } else return;
    //     } else if (dword_7C56A4 == 7 && actionSelector == 0) {
    //       int idIndex = driverSlot;
    //       int lapValue = dword_5F0714[4656 * driverSlot];
    //       if (lapValue <= 1 || lapValue >= dword_8ACF8C - 1) return;
    //       lookupIndex = (driverSlot != *(int*)(dword_7C54E8 + 18580)) ? 262 : 72;
    //       BooleanOROfTwoChecks(flt_5EA618, 72);
    //       BooleanOROfTwoChecks(flt_5EA618, 262);
    //     } else return;
    //     DriverDataTableLookupAndTimeConversion(buffer, lookupIndex, dword_5F0F74[4656 * idIndex], -1, -1, -1, -2.0, -2.0);
    //     InsertDriverTableEntry(flt_5EA618, buffer);
    //   }
    // UNRESOLVED: flt_59E440 is listed among packet globals but is not referenced by the raw source text; its role (ZeroThreshold per prior analysis) is unverified for this function.
    // UNRESOLVED: Semantic meaning of the lookup indices (3/4/5/10/16/33 as overtake/defend/pit and 72/262 as outlap) is DERIVED from prior analysis prose, not established by the raw source alone.
    // UNRESOLVED: The owning class of `this` and the field meaning of this[a3 + 108] (dword offset (a3 + 108) * 4) are unknown; the write of 1 is treated as a per-driver state-change flag on DERIVED grounds.
    // UNRESOLVED: The base types and full layout of the per-driver arrays dword_5F0714 and dword_5F0F74 (indexed with stride 4656 elements) are not evidenced in the packet.
}
