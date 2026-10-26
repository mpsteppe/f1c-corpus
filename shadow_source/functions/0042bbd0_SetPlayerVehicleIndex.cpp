// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042BBD0
// Canonical corpus name: SetPlayerVehicleIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetPlayerVehicleIndex_0042bbd0.c

void UnknownObject::SetPlayerVehicleIndex()
{
    // Player-vehicle selector (stdcall, arg a1 = vehicle index): stores the computed player vehicle pointer (vehicle array base unk_5EC6D8 + stride 18624 * a1) into dword_7C54E0, then scans dword_7C54F0 (vehicle pointer array) for an entry equal to that pointer. On match it records the matching array index in dword_7C54DC and returns it; if the array is exhausted (104 entries) without a match, it returns 104. Vehicle-subsystem helper used by dispatch and network/session paths.
    // CALCULATION: Compute the player vehicle pointer = (int)&unk_5EC6D8 + 18624 * a1 (stride 18624 = vehicle array element size) and write it to dword_7C54E0 as the current player vehicle pointer. [source:raw, global:0x005EC6D8, global:0x007C54E0]
    // ASSIGNMENT: Initialize the array search index result = 0. [source:raw]
    // LOOP: Linear search over dword_7C54F0 (vehicle pointer array) from index 0, comparing each entry against the computed player vehicle pointer. [source:raw, global:0x007C54F0]
    // GUARD: Loop continues while dword_7C54F0[result] != computed player vehicle pointer; on equality the loop exits to the match handling. [source:raw, global:0x007C54F0]
    // GUARD: Exhaustion guard: if ++result >= 104 (array limit), return result (not-found path) immediately without recording an index. [source:raw]
    // ASSIGNMENT: On a match, store the found array index into dword_7C54DC (current player vehicle array index). [source:raw, global:0x007C54DC]
    // RETURN: Return the matching array index, or 104 when no array entry equals the computed player vehicle pointer. [source:raw]
    // CALL: Called from GameStateDispatchChain (0x0040D240), sub_40DE60 (0x0040DE60), DynMan_Init (0x0042C1A0), NetCommPlayerSlotSync (0x0045FC50), sub_4B9890 (0x004B9890) and sub_4BA1F0 (0x004BA1F0) to select the player vehicle. [caller:0x0040D240, caller:0x0040DE60, caller:0x0042C1A0, caller:0x0045FC50, caller:0x004B9890, caller:0x004BA1F0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_42BBD0(int a1) {
    //     dword_7C54E0 = (int)&unk_5EC6D8 + 18624 * a1;
    //     int result = 0;
    //     while (dword_7C54F0[result] != (void *)((char *)&unk_5EC6D8 + 18624 * a1)) {
    //       if (++result >= 104)
    //         return result;
    //     }
    //     dword_7C54DC = result;
    //     return result;
    //   }
    // UNRESOLVED: Semantics of dword_7C54E0 (fill prose: postProcessInput) and dword_7C54DC (fill prose: CurrentPlayerIndex) come from higher-tier analysis, not this packet; only the writes are grounded here.
    // UNRESOLVED: Meaning of a return of 104 (array not found) for the caller - the caller-side handling is not visible in this packet.
}
