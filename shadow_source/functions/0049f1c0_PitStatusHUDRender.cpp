// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F1C0
// Canonical corpus name: sub_49F1C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49F1C0_0049f1c0.c

void UnknownObject::PitStatusHUDRender()
{
    // Pit-status HUD renderer. Given non-null render-surface parameters a5 and a6, it measures the 'Wijs' label width via sub_5531F0 to lay out five driver rows, renders the pit-repair status display for the player vehicle (dword_7C54E8 + 13004), prints each of the five slots' driver name (fetched by sub_4A47E0, looked up via BinarySearchInStringTable into byte_5EC4CC) into left/right text columns through StringFormatAndRender, and draws a selection box around the active slot (this[1], field +0x4) when that slot has more than one entry. Returns 0 after rendering; returns the initial value 1 when the render surface is absent.
    // GUARD: Return-early guard: if either render-surface parameter a5 or a6 is null, skip the whole HUD render and return the initial result 1. [source:raw]
    // CALL: Measure the 'Wijs' label string: sub_5531F0(aWijs, &v27, &v30, 0) fills v27 (character count) and v30 (advance width). [callee:0x005531F0, global:0x005CCFC4, source:raw]
    // CALCULATION: Derive the text column positions: v27 /= 4; v32 = a2 + 11*v27 + v27/2 (right column); v31 = a2 + 11*v27 - v27/2 (left column); v28 = v30 + 1 (line stride). [source:raw]
    // CALCULATION: Resolve the player vehicle pointer: v8 = v25 = dword_7C54E8 + 13004. [global:0x007C54E8, source:raw]
    // CALL: Render the pit-repair status display for the player vehicle: PitRepairStatusDisplay(dword_7C54E8 + 13004). [callee:0x004A58B0, global:0x007C54E8, source:raw]
    // GUARD: Guard on the slot's entry count: if *(int*)((this[1] << 6) + v8 + 40) <= 1, the currently selected slot has at most one entry. [field:this:0x00000004, source:raw]
    // CALL: Advance the selected slot index to the next valid entry: sub_49F170(this, 1). [callee:0x0049F170, source:raw]
    // LOOP: Iterate five HUD slots (v9 = 0..4); each iteration renders one driver line and, for the active slot, a selection box. [source:raw]
    // CALL: Fetch the driver name string for slot index v9: v22 = sub_4A47E0(v9). [callee:0x004A47E0, source:raw]
    // GUARD: Guard on the name lookup: BinarySearchInStringTable(byte_5EC4C0, v22, byte_5EC4CC) must find v22 in the string table. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: Copy the found name v22 into byte_5EC4CC; when v22 is null, clear byte_5EC4CC[0] instead. [global:0x005EC4CC, source:raw]
    // CALL: Copy the display buffer into the bounded stack buffer v42: sub_587DD0(v42, byte_5EC4CC, 31) then v43 = 0. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // CALL: Render the left-column (position) text: StringFormatAndRender(v42, v31, v21, a5, a6, 1). [callee:0x0049F6A0, source:raw]
    // CALL: Render the right-column (label) text: StringFormatAndRender(v42, v32, v21, a5, a6, 0). [callee:0x0049F6A0, source:raw]
    // GUARD: Guard on the active slot: when v9 == this[1], draw the selection box for the current slot. [field:this:0x00000004, source:raw]
    // CALCULATION: Compute box coordinates from the scaled screen dimensions: v12 = CRTFtol(a2 * *(float*)(a5 + 92)); v23 = CRTFtol(a3 * *(float*)(a5 + 96)); v13 = CRTFtol(v28 * *(float*)(a5 + 96)). [callee:0x00587BDC, source:raw]
    // GUARD: Height guard on the render surface: if *(int*)(a6 + 28) >= 300 use a 1000-pixel offset, otherwise a 250-pixel offset for the box top. [source:raw]
    // CALL: Emit the selection-box edges: six FloatToIntConversionChain(&v36, a4) calls convert float coordinate pairs to screen integers. [callee:0x00553A20, source:raw]
    // CALCULATION: Advance per-line layout state: v21 += v28; v26 += 64 (next line's label buffer offset). [source:raw]
    // RETURN: After all five slots, return 0 (success); the null-surface path returns the initial value 1. [source:raw]

    // Conservative worker pseudocode:
    //   if (a5 && a6) {
    //     v21 = a3;
    //     sub_5531F0(aWijs, &v27, &v30, 0);
    //     v27 /= 4;
    //     v32 = a2 + 11*v27 + v27/2;
    //     v31 = a2 + 11*v27 - v27/2;
    //     v28 = v30 + 1;
    //     v8 = v25 = dword_7C54E8 + 13004;
    //     PitRepairStatusDisplay(dword_7C54E8 + 13004);
    //     if (*(int*)((this[1] << 6) + v8 + 40) <= 1)
    //       sub_49F170(this, 1);
    //     v26 = v25 + 54;
    //     v29 = 0; v9 = 0;
    //     do {
    //       v22 = sub_4A47E0(v9);
    //       if (BinarySearchInStringTable(byte_5EC4C0, v22, byte_5EC4CC)) {
    //         if (v22) strcpy(byte_5EC4CC, v22); else byte_5EC4CC[0] = 0;
    //       }
    //       sub_587DD0(v42, byte_5EC4CC, 31); v43 = 0;
    //       StringFormatAndRender(v42, v31, v21, a5, a6, 1);
    //       sub_587DD0(v42, v26, 31); v43 = 0;
    //       StringFormatAndRender(v42, v32, v21, a5, a6, 0);
    //       if (v9 == this[1]) {
    //         v12 = CRTFtol(a2 * *(float*)(a5 + 92));
    //         v23 = CRTFtol(a3 * *(float*)(a5 + 96));
    //         v13 = CRTFtol(v28 * *(float*)(a5 + 96));
    //         v14 = v12 + (*(int*)(a6 + 28) >= 300 ? 1000 : 250);
    //         v15 = v23 + v9 * v13;
    //         v16 = v23 + v13 * (v9 + 1);
    //         FloatToIntConversionChain(&v36, a4); /* six box edges * /
    //         v29 = v9;
    //       }
    //       v21 += v28; v29 = ++v9; v26 += 64;
    //     } while (v9 < 5);
    //     return 0;
    //   }
    //   return 1;
    // UNRESOLVED: The scaled-coordinate arithmetic (scale factors at a5 + 92 / a5 + 96, height threshold at a6 + 28) is described from the raw source but not independently confirmed.
    // UNRESOLVED: byte_5EC4C0 as the string-table haystack base and byte_5EC4CC as the display buffer are DERIVED names from the existing analysis.
    // UNRESOLVED: The five-slot loop models five HUD driver rows; the slot semantics (grid position, driver order) are DERIVED.
    // UNRESOLVED: Callers ConditionalDispatch (0049E3E0) and DrawYellowTextAtFixedScreenPosition (004DC250) invoke this renderer; their triggering context is not in this packet's source.
}
