// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042BC40
// Canonical corpus name: SetPlayerVehicleIndex_bc40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetPlayerVehicleIndex_bc40_0042bc40.c

void UnknownObject::SetPlayerVehicleIndex_bc40()
{
    // Computes the player vehicle pointer as vehicle-array base unk_5EC6D8 plus 18624 * a1, stores it in dword_7C54E8, then scans dword_7C54F0 (the 104-entry vehicle pointer array) for a matching entry. On a match stores the index in dword_7C54E4 and returns it; if the array is exhausted without a match returns 104.
    // ASSIGNMENT: Store dword_7C54E8 = (int)unk_5EC6D8 + 18624 * a1: the player vehicle pointer computed as vehicle-array base plus stride times slot index. [source:raw, global:0x007C54E8, global:0x005EC6D8]
    // ASSIGNMENT: Initialize the search index result = 0. [source:raw]
    // LOOP: while dword_7C54F0[result] != (unk_5EC6D8 + 18624 * a1): scan the vehicle pointer array until the computed player pointer is found. [source:raw, global:0x007C54F0]
    // GUARD: if (++result >= 104) return result: the array was exhausted without a match, so return 104. [source:raw]
    // ASSIGNMENT: On match, store dword_7C54E4 = result: record the found index as the current player vehicle index. [source:raw, global:0x007C54E4]
    // RETURN: Return the matched index, or 104 when no entry matched. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_42BC40(int slotIndex) {
    //     int playerPtr = (int)&unk_5EC6D8 + 18624 * slotIndex;
    //     dword_7C54E8 = playerPtr;
    //     int i = 0;
    //     while (dword_7C54F0[i] != playerPtr) {
    //       if (++i >= 104) return i;
    //     }
    //     dword_7C54E4 = i;
    //     return i;
    //   }
    // UNRESOLVED: No branch verifies a1 is a valid slot index before computing the pointer; behavior for out-of-range a1 is unproven.
    // UNRESOLVED: dword_7C54E4 (CurrentVehicleIndex) is written but never read inside this function; downstream consumers are not visible here.
    // UNRESOLVED: All caller relationships (DynMan_Init, NetCommPlayerSlotSync, sub_4BA1F0) are recorded as evidence only; their expectations of the return value are unconfirmed.
}
