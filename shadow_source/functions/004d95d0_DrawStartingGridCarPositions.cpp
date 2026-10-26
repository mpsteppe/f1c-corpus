// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D95D0
// Canonical corpus name: sub_4D95D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D95D0_004d95d0.c

void UnknownObject::DrawStartingGridCarPositions()
{
    // Scans the live vehicle pointer array (dword_7C54F0, count dword_5C329C) for up to two vehicle ids: the primary id a1 and the secondary id a2, each read from vehicle+16480. When the primary id matches it draws a marker for that vehicle via sub_4D9690 at (a3, a4+160.0); when the secondary id matches it draws a marker via sub_4D9690 at (a3+64.0, a4-32.0). Returns 0 on every exit path, normally after both markers have been drawn or the scan is exhausted. Called from StartingGridUIDraw (004d9420), consistent with a starting-grid position-marker renderer.
    // ASSIGNMENT: Precompute the primary marker Y position v10 = a4 + 160.0 before the vehicle scan starts. [source:raw]
    // GUARD: Vehicle-count guard: if dword_5C329C <= 0 the scan is skipped entirely and the function returns 0. [source:raw, global:0x005C329C]
    // LOOP: Scan the vehicle pointer array dword_7C54F0 from index 0 upward while the index is below dword_5C329C. [source:raw, global:0x007C54F0, global:0x005C329C]
    // ASSIGNMENT: Read the vehicle id dword at offset +16480 of the current vehicle pointer into v8. [source:raw]
    // GUARD: If v8 == a1 (primary id match), break out of the loop to draw the primary marker. [source:raw]
    // GUARD: If v8 == a2 (secondary id match), draw the secondary marker at an offset position. [source:raw]
    // CALCULATION: Compute the secondary marker position: v12 = a3 + 64.0 and v11 = a4 - 32.0. [source:raw]
    // CALL: Call sub_4D9690(vehiclePtr, secondaryX, secondaryY) to draw the secondary marker at (a3+64.0, a4-32.0). [source:raw, callee:0x004D9690]
    // ASSIGNMENT: Set v4 = 1 to record that the secondary marker was drawn. [source:raw]
    // CALL: After the primary id match breaks the loop, call sub_4D9690(vehiclePtr, a3, primaryY) to draw the primary marker at (a3, a4+160.0). [source:raw, callee:0x004D9690]
    // ASSIGNMENT: Set v13 = 1 to record that the primary marker was drawn. [source:raw]
    // STATE_TRANSITION: If the secondary marker was already drawn (v4 set), return 0; otherwise resume scanning for the secondary id. [source:raw]
    // RETURN: Return 0 when the scan index passes the vehicle count (scan exhausted) and on every other exit path. [source:raw, global:0x005C329C]

    // Conservative worker pseudocode:
    //   int sub_4D95D0(int a1, int a2, float a3, float a4) {
    //     float primaryY = a4 + 160.0f;
    //     int primaryFound = 0, secondaryFound = 0;
    //     if (vehicleCount <= 0) return 0;
    //     for (int i = 0; i < vehicleCount; ++i) {
    //       int veh = vehiclePtrArray[i];
    //       int id = *(int *)(veh + 16480);
    //       if (id == a1) {
    //         sub_4D9690(veh, a3, primaryY);
    //         primaryFound = 1;
    //       } else if (id == a2) {
    //         sub_4D9690(veh, a3 + 64.0f, a4 - 32.0f);
    //         secondaryFound = 1;
    //       }
    //       if (primaryFound && secondaryFound) return 0;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The vehicle id dword at offset +16480 is read but its exact meaning (car id vs driver id) is not established; the packet fields list is empty.
    // UNRESOLVED: The three read-only globals flt_59E708, flt_59EC20 and flt_5ACF68 are listed in the packet globals but do not appear in the raw source text; their role in this function is unclear.
    // UNRESOLVED: The caller StartingGridUIDraw (004d9420) is recorded but the relationship is not independently verified.
    // UNRESOLVED: If multiple vehicles shared the secondary id, each would be drawn, since the loop only returns once both flags are set; whether duplicate ids occur is unknown.
}
