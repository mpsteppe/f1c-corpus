// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D2CA
// Canonical corpus name: VehicleSelectionCyclicShift
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleSelectionCyclicShift_0040d2ca.c

void UnknownObject::VehicleSelectionCyclicShift()
{
    // Shifts the current player selection index cyclically: index becomes dword_7C54DC + 1 when a1 is set, else dword_7C54DC - 1, wrapping to 0 at the top and to dword_5C329C - 1 at the bottom of the vehicle count. Dispatches game state for the newly selected vehicle via GameStateDispatchChain using the vehicle pointer from dword_7C54F0, then refreshes every vehicle visual entry via sub_4F0D20. Returns the vehicle count dword_5C329C.
    // ASSIGNMENT: Store selection direction a1 into the field at displacement a3 + 1418395647 (decompiler artifact of a large/negative byte offset). [source:raw]
    // CALCULATION: Compute next index v4 = dword_7C54DC + 1 when a1 is set, otherwise dword_7C54DC - 1. [global:0x007C54DC, source:raw]
    // GUARD: Wrap the index cyclically: v4 >= dword_5C329C becomes 0; v4 < 0 becomes dword_5C329C - 1. [global:0x005C329C, source:raw]
    // CALL: GameStateDispatchChain(a2, *(dword_7C54F0[v4] + 18580)) dispatches game state for the newly selected vehicle. [global:0x007C54F0, callee:0x0040D240, source:raw]
    // LOOP: Loop i over [0, dword_5C329C): sub_4F0D20(dword_7C54F0[i] + 12) refreshes each vehicle visual entry. [global:0x007C54F0, global:0x005C329C, callee:0x004F0D20, source:raw]
    // RETURN: Return the vehicle count dword_5C329C. [global:0x005C329C, source:raw]

    // Conservative worker pseudocode:
    //   int VehicleSelectionCyclicShift(int a1, DWORD* a2, int a3, int a4) {
    //     *(DWORD*)(a3 + 1418395647) = a1;
    //     int next = (a1) ? dword_7C54DC + 1 : dword_7C54DC - 1;
    //     if (next >= dword_5C329C) next = 0;
    //     else if (next < 0) next = dword_5C329C - 1;
    //     GameStateDispatchChain(a2, *(DWORD*)(dword_7C54F0[next] + 18580));
    //     for (int i = 0; i < dword_5C329C; ++i)
    //       sub_4F0D20(dword_7C54F0[i] + 12);
    //     return dword_5C329C;
    //   }
    // UNRESOLVED: Displacements 1418395647 and 18580 are decompiler byte offsets; the meaning of the fields they address depends on the unknown owner type.
    // UNRESOLVED: The role of argument a3/a4 beyond the stored direction flag is unknown.
}
