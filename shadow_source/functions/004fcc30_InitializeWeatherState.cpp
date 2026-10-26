// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FCC30
// Canonical corpus name: sub_4FCC30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FCC30_004fcc30.c

void UnknownObject::InitializeWeatherState()
{
    // Weather/environment state initializer run on game restart (called by Game_Restart). Destroys prior weather list state, clears this[7], and takes an early-out path (this[5]=0) when the display-mode flag is unset or dword_8AB6E4 is 2. Otherwise selects a weather parameter mode: either a season-race weather entry found via StringKeyedLinkedListSearch on aWeather_1, a weather.txt file parsed via sub_4FE7C0, or a built-in mode float chosen by a switch on dword_7CF080. Allocates a 4-float parameter array ([0, 1101004800, modeValue, 0]) stored at this[15], feeds its third value to sub_4FDE00, copies derived values into this[9..13], processes the audio ring buffer around a saved copy of this+0x20, initializes per-race flags/words at +0x40..0x52, seeds this+0x104 from a rotation table, calls RangeInterpolationTable, and conditionally resets a name string at this+0x1C4 and calls sub_4FC550.
    // CALL: Call DualLinkedListDestruction() with no arguments at function entry (cleanup of prior list state before re-init). [callee:0x004FD840, source:raw]
    // ASSIGNMENT: Set this[7] = 0. [field:this:0x0000001C]
    // GUARD: Early-out guard: if (dword_7C56A0 & 1) == 0 OR dword_8AB6E4 == 2, skip full weather init. [global:0x007C56A0, global:0x008AB6E4]
    // CALL: Call DisplayModeSetter(0x20000) on the early-out path. [callee:0x00543960]
    // ASSIGNMENT: Set this[5] = 0 on the early-out path. [field:this:0x00000014]
    // RETURN: Return result (DisplayModeSetter return value cast to char*) on the early-out path. [source:raw]
    // GUARD: Branch on byte_7CF17C to choose the initial this float: flt_8ACF9C when set, else 1.0f (1065353216). [global:0x007CF17C]
    // ASSIGNMENT: Set *(float*)this = flt_8ACF9C when byte_7CF17C is nonzero, otherwise *this = 1065353216 (1.0f). [field:this:0x00000000, global:0x008ACF9C]
    // GUARD: Branch on dword_7CF080: nonzero selects the section/file weather path, zero selects the weather.txt file path. [global:0x007CF080]
    // CALL: Call SeasonRacesSectionFinder(0) to locate the current season races section when dword_7CF080 is 1. [callee:0x004C5840]
    // CALL: Call StringKeyedLinkedListSearch(aWeather_1) to find the weather linked-list node for the season races section. [callee:0x005679C0, global:0x005D173C]
    // CALCULATION: Fallback path (LABEL_15): select weather mode constant v13 by switch on dword_7CF080 — case 3: 1059481190; case 4: 1062333317; case 5: 1064346583; default: 1050253722. [global:0x007CF080, source:raw]
    // CALL: Call DualLinkedListDestruction(this) to tear down the weather parameter list before rebuilding. [callee:0x004FD840]
    // CALL: Call OperatorNewNhMallocWrapper(16) to allocate the 4-float weather parameter array (v5). [callee:0x00587C03]
    // CALL: Call FloatArrayInitializer(v5) to initialize the allocated array when v5 is nonzero; else v6 = 0. [callee:0x004FC9A0]
    // ASSIGNMENT: Store this[15] = v6 and fill the array: [0] = 0, [1] = 1101004800, [2] = v13, [3] = 0. [field:this:0x0000003C, source:raw]
    // CALL: Call sub_4FDE00 with the float at this[15]+8 (the selected mode value v13). [callee:0x004FDE00, field:this:0x0000003C]
    // ASSIGNMENT: Set this[10] = this[9] and this[11] = this[9] (propagate the config value into two slots). [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000024]
    // ASSIGNMENT: Set *((float*)this + 12) and *((float*)this + 13) both to the float at this[15]+4 (array[1]). [field:this:0x00000030, field:this:0x00000034, field:this:0x0000003C]
    // CALL: Call sub_4FE350(v2) with the season weather linked-list node v2 (when the section/list search succeeded). [callee:0x004FE350]
    // CALCULATION: Compute base path v4 = dword_5EC438, or byte_5EA438 when dword_5EC438 is 0. [global:0x005EC438, global:0x005EA438]
    // CALL: Call StringFormatWithBufferOverflowCheck(v15, "%sweather.txt", v4) to build the weather file path. [callee:0x0058815F]
    // CALL: Call sub_4FE7C0(v15) to parse the weather.txt file into v3 (parse result). [callee:0x004FE7C0]
    // GUARD: If v3 (parse result) is nonzero, jump to LABEL_15 (fallback weather mode constants). [source:raw]
    // ASSIGNMENT: LABEL_26: save a 24-byte copy of this+0x20 into local v14 before audio processing (qmemcpy(v14, this + 8, 24)). [field:this:0x00000020, source:raw]
    // CALL: Call AudioEventRingBufferProcessing(this) to process the weather audio ring buffer. [callee:0x004FEAF0]
    // ASSIGNMENT: Restore this+0x20 from v14 (qmemcpy of 0x18 bytes), then set this[2] = this[8] and this[14] = this[15] (saved array pointer). [field:this:0x00000020, field:this:0x00000008, field:this:0x00000038]
    // ASSIGNMENT: Set *((_BYTE*)this + 64) = 1 (initialization-complete byte flag). [field:this:0x00000040]
    // ASSIGNMENT: Set this[17] = -8388609 and this[1] = 0. [field:this:0x00000044, field:this:0x00000004]
    // ASSIGNMENT: Initialize word block: word at +36 = 0, +37 = -1, +38 = -1, +39 = 0, +40 = 0x7FFF, +41 = 0x8000. [field:this:0x00000048, field:this:0x0000004A, field:this:0x0000004C, field:this:0x0000004E, field:this:0x00000050, field:this:0x00000052]
    // CALL: Call DisplayModeSetter(0x20000) again after field initialization. [callee:0x00543960]
    // ASSIGNMENT: Set this[5] = (*((float*)this + 11) > 0.0) — a boolean derived from this[11] (field at +0x2C). [field:this:0x00000014, field:this:0x0000002C]
    // CALCULATION: Compute v11 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.050000001 (rotation-table value scaled by 0.05). [global:0x008AB274, global:0x008AAE70]
    // ASSIGNMENT: Set *((float*)this + 65) = v11 (float field at this+0x104). [field:this:0x00000104]
    // CALL: Call RangeInterpolationTable(this) and use its return as result. [callee:0x004FD6F0]
    // GUARD: Final guard: only when (dword_7C56A0 & 1) != 0 AND dword_8AB6E4 != 2, compare the name at this+452 against byte_8ACFA3. [global:0x007C56A0, global:0x008AB6E4]
    // CALL: Call strcmp((const char*)this + 452, byte_8ACFA3) to test whether the stored name string already matches. [global:0x008ACFA3]
    // CALL: On mismatch, call sub_587DD0(this + 113, byte_8ACFA3, 11) to copy byte_8ACFA3 into the name field. [callee:0x00587DD0, global:0x008ACFA3]
    // ASSIGNMENT: Set *((_BYTE*)this + 463) = 0 (null-terminate the name field at this+0x1CF). [field:this:0x000001CF]
    // CALL: Call sub_4FC550((int)(this + 66), 1) and return its result on the name-reset path. [callee:0x004FC550]
    // RETURN: Return result (RangeInterpolationTable or sub_4FC550 return value). [source:raw]

    // Conservative worker pseudocode:
    //   char *InitializeWeatherState(DWORD *this) {
    //     DualLinkedListDestruction();
    //     this[7] = 0;
    //     if ((dword_7C56A0 & 1) == 0 || dword_8AB6E4 == 2) {
    //       result = DisplayModeSetter(0x20000);
    //       this[5] = 0;
    //       return result;
    //     }
    //     *(float*)this = byte_7CF17C ? flt_8ACF9C : 1065353216;
    //     if (dword_7CF080 == 0) {
    //       v4 = dword_5EC438 ? dword_5EC438 : byte_5EA438;
    //       StringFormatWithBufferOverflowCheck(v15, "%sweather.txt", v4);
    //       v3 = sub_4FE7C0(v15);
    //     } else if (dword_7CF080 == 1 && SeasonRacesSectionFinder(0) && (v2 = StringKeyedLinkedListSearch(aWeather_1)) != 0) {
    //       v3 = sub_4FE350(v2);
    //     }
    //     if (v3) {
    //       switch (dword_7CF080) {
    //         case 3: v13 = 1059481190; break;
    //         case 4: v13 = 1062333317; break;
    //         case 5: v13 = 1064346583; break;
    //         default: v13 = 1050253722; break;
    //       }
    //       DualLinkedListDestruction(this);
    //       this[15] = FloatArrayInitializer(OperatorNewNhMallocWrapper(16));
    //       this[15][0] = 0; this[15][1] = 1101004800; this[15][2] = v13; this[15][3] = 0;
    //       sub_4FDE00(*(float*)(this[15] + 8));
    //       this[10] = this[11] = this[9];
    //       *(float*)((char*)this + 0x30) = *(float*)(this[15] + 4);
    //       *(float*)((char*)this + 0x34) = *(float*)(this[15] + 4);
    //     }
    //     qmemcpy(v14, this + 8, 24);
    //     AudioEventRingBufferProcessing(this);
    //     qmemcpy(this + 8, v14, 0x18);
    //     this[2] = this[8];
    //     this[14] = this[15];
    //     *((_BYTE*)this + 64) = 1;
    //     this[17] = -8388609;
    //     this[1] = 0;
    //     *((_WORD*)this + 36) = 0; *((_WORD*)this + 37) = -1; *((_WORD*)this + 38) = -1;
    //     *((_WORD*)this + 39) = 0; *((_WORD*)this + 40) = 0x7FFF; *((_WORD*)this + 41) = 0x8000;
    //     DisplayModeSetter(0x20000);
    //     this[5] = *((float*)this + 11) > 0.0;
    //     *((float*)this + 65) = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.050000001;
    //     result = RangeInterpolationTable(this);
    //     if ((dword_7C56A0 & 1) != 0 && dword_8AB6E4 != 2 && strcmp((const char*)this + 452, byte_8ACFA3)) {
    //       sub_587DD0(this + 113, byte_8ACFA3, 11);
    //       *((_BYTE*)this + 463) = 0;
    //       return sub_4FC550((int)(this + 66), 1);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the initial no-argument DualLinkedListDestruction() call are unclear; a thiscall-style cleanup is invoked with a void cast and no object pointer.
    // UNRESOLVED: The role of the name-string compare at this+0x1C4 (vs byte_8ACFA3) is not established; it likely records a weather/season identifier string but the field's meaning is UNKNOWN.
    // UNRESOLVED: The division of labor between sub_4FE7C0 (weather.txt parse) and sub_4FE350 (season weather entry) is only inferred from call placement.
    // UNRESOLVED: globs flt_59E440, flt_59E448, aSweatherTxt, unk_8AC368 and dword_8AFE88 appear nowhere in the decompiled body; they are likely consumed inside callees such as AudioEventRingBufferProcessing, RangeInterpolationTable, or sub_4FE7C0.
    // UNRESOLVED: Constant 0x20000 passed to DisplayModeSetter is not otherwise interpreted here.
}
