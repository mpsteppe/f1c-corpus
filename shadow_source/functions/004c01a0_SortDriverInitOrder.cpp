// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C01A0
// Canonical corpus name: sub_4C01A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C01A0_004c01a0.c

void UnknownObject::SortDriverInitOrder()
{
    // Assigns grid/starting positions to vehicles sorted by a stored score. Builds a 104-slot index-to-score map from each vehicle pointer in dword_7C54F0 (reading the sort/slot index field at +18580 and the score field at +18192), then selection-sorts the map and, in ascending score order, calls ConditionalFieldSetter on VEH[v4] at offset 0x4034 (unk_5F070C + 18624*v4) with the running position i. Called from DynMan_Init and MultiplayerVehiclePlacement.
    // ASSIGNMENT: Initialize the 104-entry local index map v9 to 0xFF (-1 sentinel) via memset. [source:raw]
    // ASSIGNMENT: Read the vehicle count v0 from dword_5C329C. [global:0x005C329C, source:raw]
    // LOOP: First pass: for result in [0, v0), take v3 = dword_7C54F0[result] and set v9[*(v3 + 18580)] = *(v3 + 18192), mapping each vehicle's sort/slot-index field to its score field. [global:0x007C54F0, source:raw]
    // LOOP: Outer pass: for j in [0, v0), locate the minimal-score slot remaining in the map. [global:0x005C329C, source:raw]
    // LOOP: Inner scan: for k in [0, 104), track the smallest v9[k] with v9[k] != -1 (v5 starts at 999, v4 records the slot index). [source:raw]
    // GUARD: Guard: only assign a position when a valid minimum was found (v5 != 999 and v4 != -1). [source:raw]
    // CALL: Call ConditionalFieldSetter on VEH[v4] (unk_5F070C + 18624*v4, the per-vehicle grid-field slot at offset 0x4034) with the running position i. [global:0x005F070C, callee:0x004BC2F0, source:raw]
    // ASSIGNMENT: Mark slot v4 as consumed (v9[v4] = -1), increment i, and refresh v0 from dword_5C329C. [global:0x005C329C, source:raw]
    // RETURN: Return the number of processed positions (j + 1 at outer-loop exit). [function:0x004C01A0, source:raw]

    // Conservative worker pseudocode:
    //   memset(index_score, 0xFF, sizeof(index_score));
    //   v0 = dword_5C329C;
    //   i = 1;
    //   for (r = 0; r < v0; r++) {
    //       v3 = dword_7C54F0[r];
    //       index_score[*(dword*)(v3 + 18580)] = *(dword*)(v3 + 18192);
    //   }
    //   for (j = 0; j < v0; j++) {
    //       best = 999; best_slot = -1;
    //       for (k = 0; k < 104; k++)
    //           if (index_score[k] != -1 && index_score[k] < best) { best = index_score[k]; best_slot = k; }
    //       if (best != 999 && best_slot != -1) {
    //           ConditionalFieldSetter(unk_5F070C + 18624*best_slot, i);
    //           index_score[best_slot] = -1;
    //           i++;
    //           v0 = dword_5C329C;
    //       }
    //   }
    //   return j + 1;
    // UNRESOLVED: Semantics of the two vehicle fields (+18192 score, +18580 sort index) and the exact meaning of the value i written by ConditionalFieldSetter are inferred from call context only.
    // UNRESOLVED: unk_5F070C is read as the base of the per-vehicle grid-field array at VEH[0]+0x4034; the field's type and range are not confirmed.
}
