// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042B8D0
// Canonical corpus name: AIShiftPattern
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIShiftPattern_0042b8d0.c

void UnknownObject::AIShiftPatternDisplay()
{
    // Renders the AI shift-pattern configuration label. When BitmaskStateTest(a1) fails, it builds "[base].HOT" plus the "Disallowed" message text and renders it. When the bitmask passes, it increments the shift-pattern index counter (*a2, this+0x0), wraps it to 0 when it exceeds the state count a3, selects a state string by mode a1 and current index (upshifts/downshifts/on/high/registered-data), appends it to "[base].HOT", renders via TextLineWrappingAndRendering, then runs ShortComputation_bdf0 on a resource dispatch global and BrakeBiasSetup on a race-time global, returning BrakeBiasSetup's result.
    // GUARD: BitmaskStateTest(a1): gates the whole function. Falsy selects the disallowed-message path; truthy selects the shift-pattern state-cycle path. [callee:0x004B15D0, abi:lead, source:raw]
    // GUARD: BinarySearchInStringTable(byte_5EC4C0, a4, byte_5EC4CC): on the disallowed path, checks whether base label a4 exists in the string table; if so, copies a4 (or an empty string) into byte_5EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // LOOP: Copy byte_5EC4CC (base label) into local buffer v17 until NUL terminator. [global:0x005EC4CC, source:raw]
    // CALCULATION: Append word_5C32D8 (16-bit literal, the .HOT extension) immediately after v17's terminating NUL. [global:0x005C32D8, source:raw]
    // GUARD: BinarySearchInStringTable(byte_5EC4C0, aDisallowed, byte_5EC4CC): on the disallowed path, checks whether the Disallowed string exists in the table. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, global:0x005C32CC, source:raw]
    // LOOP: Copy aDisallowed string into byte_5EC4CC until NUL terminator. [global:0x005C32CC, global:0x005EC4CC, source:raw]
    // CALCULATION: strcat(v17, byte_5EC4CC): append the Disallowed text to the base label to form "[base].HOT[Disallowed]". [global:0x005EC4CC, source:raw]
    // CALL: TextLineWrappingAndRendering(v17, 3, 16909060): wrap and render the composed disallowed line; its return value is returned to the caller. [callee:0x0045BD10, source:raw]
    // CALCULATION: Increment shift-pattern index counter: v11 = *a2 + 1, *a2 = v11; if v11 exceeds the state count a3, reset *a2 = 0. [field:this:0x00000000, source:raw]
    // STATE_TRANSITION: Select state string v14 from mode a1 and current index *a2: when a1 == 3, index 1 selects aUpshifts, index 2 selects aDownshifts, other nonzero selects aOn; otherwise index 1 selects aOn when a3 == 1 else off_5C32A4, higher indices select aHigh, and index 0 defaults to off_5BE704. [global:0x005BE704, global:0x005C32A4, global:0x005C32A8, global:0x005C32B0, global:0x005C32BC, global:0x005C32C8, source:raw]
    // GUARD: BinarySearchInStringTable(byte_5EC4C0, a4, byte_5EC4CC): on the main path, checks whether base label a4 exists in the string table; if so, copies a4 (or an empty string) into byte_5EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // LOOP: Copy byte_5EC4CC (base label) into local buffer v17 until NUL terminator. [global:0x005EC4CC, source:raw]
    // CALCULATION: Append word_5C32D8 (16-bit literal, the .HOT extension) immediately after v17's terminating NUL. [global:0x005C32D8, source:raw]
    // GUARD: BinarySearchInStringTable(byte_5EC4C0, v14, byte_5EC4CC): on the main path, checks whether the selected state string v14 exists in the string table. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: Copy v14 (selected state string) into byte_5EC4CC, or clear it to an empty string when v14 is null. [global:0x005EC4CC, source:raw]
    // CALCULATION: strcat(v17, byte_5EC4CC): append the selected state string to the base label to form "[base].HOT[state]". [global:0x005EC4CC, source:raw]
    // CALL: ShortComputation_bdf0(&dword_7CD204): short computation over the resource-dispatch global. [callee:0x0045BDF0, global:0x007CD204, source:raw]
    // CALL: TextLineWrappingAndRendering(v17, 3, 16909060): wrap and render the composed state line. [callee:0x0045BD10, source:raw]
    // RETURN: BrakeBiasSetup(&dbl_7C7428): configure brake bias from the race-time-elapsed global; its result is returned to the caller. [callee:0x00438CC0, global:0x007C7428, source:raw]

    // Conservative worker pseudocode:
    //   int AIShiftPatternDisplay(int a1, int *a2, int a3, const char *a4) {
    //     char v17[128];
    //     if (!BitmaskStateTest(a1)) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, a4, byte_5EC4CC))
    //         strcpy(byte_5EC4CC, a4 ? a4 : "");
    //       copyStr(v17, byte_5EC4CC);
    //       appendWord(v17, word_5C32D8);
    //       if (BinarySearchInStringTable(byte_5EC4C0, aDisallowed, byte_5EC4CC))
    //         copyStr(byte_5EC4CC, aDisallowed);
    //       strcat(v17, byte_5EC4CC);
    //       return TextLineWrappingAndRendering(v17, 3, 16909060);
    //     }
    //     *a2 = (*a2 + 1 > a3) ? 0 : (*a2 + 1);
    //     const char *v14 = selectStateString(a1, *a2, a3);
    //     if (BinarySearchInStringTable(byte_5EC4C0, a4, byte_5EC4CC))
    //       strcpy(byte_5EC4CC, a4 ? a4 : "");
    //     copyStr(v17, byte_5EC4CC);
    //     appendWord(v17, word_5C32D8);
    //     if (BinarySearchInStringTable(byte_5EC4C0, v14, byte_5EC4CC))
    //       strcpy(byte_5EC4CC, v14 ? v14 : "");
    //     strcat(v17, byte_5EC4CC);
    //     ShortComputation_bdf0(&dword_7CD204);
    //     TextLineWrappingAndRendering(v17, 3, 16909060);
    //     return BrakeBiasSetup(&dbl_7C7428);
    //   }
    // UNRESOLVED: byte_7CE498 (0x007CE498) is listed as a read global by the packet but never appears in the decompiled source text; likely a data-adjacency artifact rather than an active operand.
    // UNRESOLVED: Caller sub_42C440 (0x0042C440) is reported as a per-frame ON_FRAME_PATH caller; its exact role and argument provenance are not evidenced by this packet.
    // UNRESOLVED: BinarySearchInStringTable's output-buffer contract is inferred (it writes the matched string into byte_5EC4CC); the read-only spelling of byte_5EC4C0 as the table base is retained as evidenced.
    // UNRESOLVED: 16909060 passed to TextLineWrappingAndRendering is preserved as a decimal literal; its meaning (color/format code) is not evidenced here.
}
