// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046BC20
// Canonical corpus name: sub_46BC20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_46BC20_0046bc20.c

void UnknownObject::LapTimeListDisplayBuilder()
{
    // Builds a UI list of lap times for a vehicle. Resolves the vehicle record from this[94] into the global vehicle array (stride 18624); if the slot is inactive or has no laps, resets this[94] to -1. Otherwise it copies the vehicle's two 47-char name strings, walks up to min(lap count, display limit) rows, formats per-lap flag, lap number, lap time and gap-to-best columns, assembles each composite row and creates a menu item per row via UIMenuItemCreator.
    // ASSIGNMENT: Resolve the vehicle record: v2 = &unk_5EC6D8 + 18624 * this[94] [global:0x005EC6D8, field:this:0x00000178, source:raw]
    // GUARD: Invalid vehicle: if the slot is inactive (int at vehicle offset 3250 == -1) or the lap count (int at vehicle offset 4111) is less than 1, set this[94] = -1 and return -1 [global:0x005EC6D8, field:this:0x00000178, source:raw]
    // CALL: Notify the state machine via StateCleanupNotification(this) before rebuilding the list [callee:0x00489CB0, source:raw]
    // CALL: Copy two 47-char strings from the vehicle record (offsets 17952 and 18104) into v32 and v33 via sub_587DD0, NUL-terminating each [callee:0x00587DD0, global:0x005EC6D8, source:raw]
    // CALCULATION: Row count: v27 = min(lap count at vehicle offset 4111, display limit at vehicle offset 4143) [global:0x005EC6D8, source:raw]
    // LOOP: For each lap row v6 in 0..v27-1 build the formatted row and create the menu item [source:raw]
    // CALL: Format the per-lap flag string v31 with "%d" from the vehicle byte list at offset 4146 and the lap number v34 with "%d" via StringFormatWithBufferOverflowCheck [callee:0x0058815F, global:0x005EC6D8, source:raw]
    // CALCULATION: Lap time column: read the lap float at vehicle offset 4145 for row v6; when > 0.0 dispatch it via InterruptDispatch, convert to minutes with CRTFtol(lap * 0.016666668), and format v35 as "%d:%06.3f"; otherwise copy the empty filler asc_5C6A94 [callee:0x0058957A, callee:0x00587BDC, global:0x005EC6D8, global:0x005C6A94, source:raw]
    // CALCULATION: Gap column: when the lap time is positive and the best-lap float (vehicle offset 4135) is positive, compute delta v25 = lap - best, pick the sign prefix asc_5C6ABC or byte_5EA438 for a negative delta, convert minutes via CRTFtol, and format v36 as "%s%d:%06.3f"; when the delta is exactly 0.0 record the best-lap row index into this[90] (offset 0x168); otherwise copy the empty filler asc_5C6A94 [callee:0x00587BDC, global:0x005EC6D8, global:0x005C6ABC, global:0x005EA438, field:this:0x00000168, source:raw]
    // CALCULATION: Assemble the composite row: copy v31 into v37, then append up to five 48-byte column buffers (v32..v36) inserting the delimiter word_5C692C, honouring the display filter this[95] (offset 0x17C) which when equal to 1 keeps only columns 1 and 4 [global:0x005C692C, field:this:0x0000017C, source:raw]
    // CALL: Create the menu row: UIMenuItemCreator(v37, 0, 0, 0, 0) [callee:0x00489600, source:raw]
    // RETURN: Return the number of rows displayed (result, -1 when the vehicle was invalid) [function:0x0046BC20, source:raw]

    // Conservative worker pseudocode:
    //   v2 = (char*)&unk_5EC6D8 + 18624 * this[94];
    //   result = -1;
    //   if (*(int*)(v2 + 4 * 3250) == -1 || *(int*)(v2 + 4 * 4111) < 1) {
    //     this[94] = -1;
    //   } else {
    //     StateCleanupNotification(this);
    //     sub_587DD0(v32, v2 + 17952, 47); v32[47] = 0;
    //     sub_587DD0(v33, v2 + 18104, 47); v33[47] = 0;
    //     v27 = min(*(int*)(v2 + 4 * 4111), *(int*)(v2 + 4 * 4143));
    //     result = v27;
    //     for (v6 = 0; v6 < v27; v6++) {
    //       StringFormatWithBufferOverflowCheck(v31, "%d", *(char*)(v2 + 4 * 4146 + v6));
    //       StringFormatWithBufferOverflowCheck(v34, "%d", v6 + 1);
    //       v24 = *(float*)(v2 + 4 * 4145 + 4 * v6);
    //       if (v24 > 0.0) {
    //         InterruptDispatch(v24);
    //         StringFormatWithBufferOverflowCheck(v35, "%d:%06.3f", CRTFtol(v24 * 0.016666668), v24);
    //       } else { copy asc_5C6A94 into v35; }
    //       if (v24 <= 0.0 || *(float*)(v2 + 4 * 4135) <= 0.0) { copy asc_5C6A94 into v36; }
    //       else {
    //         v25 = v24 - *(float*)(v2 + 4 * 4135);
    //         StringFormatWithBufferOverflowCheck(v36, "%s%d:%06.3f", v25 < 0.0 ? byte_5EA438 : asc_5C6ABC, CRTFtol(v25 * 0.016666668), v25);
    //         if (v25 == 0.0) this[90] = v6;
    //       }
    //       assemble v37 from v31 + columns v32..v36 with word_5C692C delimiters;
    //       result = UIMenuItemCreator(v37, 0, 0, 0, 0);
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Six packet globals never appear in the raw source: flt_59E440 (fill: zero threshold), flt_59E9C0 (fill: time conversion factor), dbl_59E9C8, aD_1, aD063f and aSD063f; some may back the "%d" / "%d:%06.3f" format literals or constants the decompiler inlined (e.g. 0.016666668), but the binding is not visible here
    // UNRESOLVED: The exact meaning of the display filter this[95] and of the two 47-char vehicle strings at offsets 17952 and 18104 is not established by this function alone
}
