// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FA7E0
// Canonical corpus name: sub_4FA7E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FA7E0_004fa7e0.c

void UnknownObject::MainGameFrameTick()
{
    // Main per-frame game tick: configures the render display list from packed flag bits, selects a global-float mode based on session state and flag-bit combinations, performs a one-shot display/UI initialization, dispatches per-vehicle UI updates, runs session audio dispatch, renders the pause overlay, accumulates frame delta time (clamped to 0.5 s), and on a pending audio-init flag clears it and retries audio initialization plus the scene-setup render.
    // GUARD: If packed flags 29 and 33 are both set in byte_7CA594, enter the display-list branch selection. [callee:0x0044F460, global:0x007CA594, source:raw]
    // GUARD: Select ConditionalInitBranch mode 0 or 2 on dword_8AFCA8 depending on whether dword_8AFCAC is nonzero. [callee:0x004F8F10, global:0x008AFCA8, global:0x008AFCAC, source:raw]
    // CALL: sub_4F8F50 processes the render display list dword_8AFCA8 using device dword_8B8DC8. [callee:0x004F8F50, global:0x008AFCA8, global:0x008B8DC8, source:raw]
    // GUARD: If the session is in a blocking state (SessionStateCheckWrapper on dword_7CD25C) or scoring gate dword_8AB6E4 equals 2, take the GlobalFloatSetter(0) path. [callee:0x00461DB0, global:0x007CD25C, global:0x008AB6E4, source:raw]
    // CALL: GlobalFloatSetter(0) selects the fallback global float mode. [callee:0x004F9F70, source:raw]
    // GUARD: If packed flags 29 and 34 are set in byte_7CA594, select GlobalFloatSetter(2) when dbl_5D6D70 equals 1.0, otherwise GlobalFloatSetter(0). [callee:0x0044F460, global:0x007CA594, global:0x005D6D70, callee:0x004F9F70, source:raw]
    // GUARD: If packed flags 29 and 20 are set in byte_7CA594, select GlobalFloatSetter(1) when dbl_5D6D70 equals 1.0, otherwise fall back to the GlobalFloatSetter(0) path. [callee:0x0044F460, global:0x007CA594, global:0x005D6D70, callee:0x004F9F70, source:raw]
    // GUARD: If one-shot initialization flag byte_8AFE70 is already set, skip the display-init block. [global:0x008AFE70, source:raw]
    // ASSIGNMENT: Set byte_8AFE70 to 1 to mark the display-init block as run. [global:0x008AFE70, source:raw]
    // CALL: sub_4F8D70 initializes the display list dword_8AFCA8 with mode 4 and the screen width dword_5D6D64 minus 48. [callee:0x004F8D70, global:0x008AFCA8, global:0x005D6D64, source:raw]
    // GUARD: ConditionalInitBranch selects mode 2 on dword_8AFCA8 when dword_7CE264 equals 1, otherwise mode 0. [callee:0x004F8F10, global:0x008AFCA8, global:0x007CE264, source:raw]
    // GUARD: Choose the render configuration call: sub_545D00(0, 6144) when dword_7CFC68 is 0, sub_545D00(0, 4096) when it is 1, and no call otherwise. [callee:0x00545D00, global:0x007CFC68, source:raw]
    // GUARD: When dword_7CF860 is 0, issue sub_545D00(0, 256). [callee:0x00545D00, global:0x007CF860, source:raw]
    // LOOP: For each of the dword_5C329C vehicles, call UIWidgetRecursiveStateUpdate(0, 1, 0). [callee:0x0054C1B0, global:0x005C329C, source:raw]
    // GUARD: Dispatch on dword_7CF860: 0 and 1 run the full per-vehicle UI loop, 2 runs the guarded per-vehicle loop, other values skip the UI loop. [global:0x007CF860, source:raw]
    // LOOP: Guarded per-vehicle loop for dword_7CF860 equal to 2: for each vehicle index under dword_5C329C, call UIWidgetRecursiveStateUpdate(0, 1, 0) only when the slot data pointer at dword_7C54F0[v2] plus 13000 is nonzero. [callee:0x0054C1B0, global:0x005C329C, global:0x007C54F0, source:raw]
    // GUARD: If dword_7CFB90 is at most 1, issue sub_545D00(0, 256). [callee:0x00545D00, global:0x007CFB90, source:raw]
    // GUARD: If HUD-disabled flag byte_7CE254 is clear, run StateFlagComputation(0). [callee:0x004F9B30, global:0x007CE254, source:raw]
    // GUARD: Dispatch session audio when dword_7CC4F4 is nonzero, the session is not blocking (SessionStateCheckWrapper on dword_7CD25C), scoring gate dword_8AB6E4 is not 2, and (dword_7C56A4 is not 7 or HUD flag byte_7CE254 is clear). [global:0x007CC4F4, callee:0x00461DB0, global:0x007CD25C, global:0x008AB6E4, global:0x007C56A4, global:0x007CE254, source:raw]
    // CALL: sub_42D210 dispatches session audio using dword_7C569C and the enabled-state byte_7C56AC (passed as a zero-test boolean). [callee:0x0042D210, global:0x007C569C, global:0x007C56AC, source:raw]
    // CALL: Run the audio helper: ArithmeticComparison_8d60 when byte_7C56AC is set, otherwise ShortComputation_8d70. [callee:0x004C8D60, callee:0x004C8D70, global:0x007C56AC, source:raw]
    // GUARD: If byte_7C56AC is set, build and render the pause overlay. [global:0x007C56AC, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aPaused, byte_5EC4CC) looks up the pause string against the string table into the scratch buffer. [callee:0x00423A00, global:0x005EC4C0, global:0x005C35C8, global:0x005EC4CC, source:raw]
    // LOOP: Copy the aPaused string into the scratch buffer byte_5EC4CC. [global:0x005C35C8, global:0x005EC4CC, source:raw]
    // CALL: TextLineWrappingAndRendering renders the pause text from byte_5EC4CC with mode 3 and color 16909060 using render context dword_7CD204. [callee:0x0045BD10, global:0x005EC4CC, global:0x007CD204, source:raw]
    // ASSIGNMENT: Increment the per-frame counter dword_8AFE84. [global:0x008AFE84, source:raw]
    // CALL: EmptyStubWithFlagCheck(2, 0) marks the timing fence entry. [callee:0x0053AC70, source:raw]
    // ASSIGNMENT: dbl_8AFE90 receives the raw delta-time value returned by sub_556730(0). [global:0x008AFE90, callee:0x00556730, source:raw]
    // CALCULATION: Accumulate raw delta time into the running total dbl_8AFEA8 (dbl_8AFEA8 += dbl_8AFE90). [global:0x008AFEA8, global:0x008AFE90, source:raw]
    // GUARD: When byte_7C56AC is set, zero the frame delta dbl_8AFE98. [global:0x007C56AC, global:0x008AFE98, source:raw]
    // CALCULATION: When dbl_5D6D70 equals 1.0: set dbl_8AFE98 to the raw delta, add it to session time dbl_8AFEA0, reset the performance-counter timer via TimerResetUsingQueryPerformanceCounter(this), and clamp dbl_8AFE98 to 0.5. [global:0x005D6D70, global:0x008AFE98, global:0x008AFEA0, global:0x008AFE90, callee:0x00568C60, source:raw]
    // CALCULATION: Otherwise scale the delta by dbl_5D6D70, clamp the result to 0.5, and accumulate it into dbl_8AFEA0. [global:0x005D6D70, global:0x008AFE90, global:0x008AFE98, global:0x008AFEA0, source:raw]
    // CALL: EmptyStubWithFlagCheck(1, 0) marks the timing fence exit. [callee:0x0053AC70, source:raw]
    // GUARD: If byte_8AFE72 was set on entry, clear it and run the audio-init retry chain. [global:0x008AFE72, source:raw]
    // CALL: RepeatedCallLoop_f040 retries audio initialization on dword_8ACEA0. [callee:0x004CF040, global:0x008ACEA0, source:raw]
    // CALL: Run the scene-setup render path AIWaypointPathCheckerRenderer using dword_5EA2C0. [global:0x005EA2C0, source:raw]
    // RETURN: Return the prior value of byte_8AFE72 (or the result of the scene-setup render call when the retry ran). [global:0x008AFE72, source:raw]

    // Conservative worker pseudocode:
    //   char MainGameFrameTick(this) {
    //     if (PackedFlagRead(byte_7CA594, 29) && PackedFlagRead(byte_7CA594, 33))
    //       ConditionalInitBranch(&dword_8AFCA8, dword_8AFCAC ? 0 : 2);
    //     sub_4F8F50((float*)&dword_8AFCA8, dword_8B8DC8);
    //     if (SessionStateCheckWrapper(dword_7CD25C) || dword_8AB6E4 == 2) { GlobalFloatSetter(0); }
    //     else if (PackedFlagRead(byte_7CA594, 29) && PackedFlagRead(byte_7CA594, 34))
    //       GlobalFloatSetter(dbl_5D6D70 == 1.0 ? 2 : 0);
    //     else if (PackedFlagRead(byte_7CA594, 29) && PackedFlagRead(byte_7CA594, 20))
    //       GlobalFloatSetter(dbl_5D6D70 == 1.0 ? 1 : 0);
    //     if (!byte_8AFE70) {
    //       byte_8AFE70 = 1;
    //       sub_4F8D70(&dword_8AFCA8, 4, dword_5D6D64 - 48);
    //       ConditionalInitBranch(&dword_8AFCA8, dword_7CE264 == 1 ? 2 : 0);
    //       if (dword_7CFC68 == 0) sub_545D00(0, 6144);
    //       else if (dword_7CFC68 == 1) sub_545D00(0, 4096);
    //       if (dword_7CF860 == 0 || dword_7CF860 == 1)
    //         for (i = 0; i < dword_5C329C; ++i) UIWidgetRecursiveStateUpdate(0, 1, 0);
    //       else if (dword_7CF860 == 2)
    //         for (v2 = 0; v2 < dword_5C329C; ++v2)
    //           if (*(int*)(dword_7C54F0[v2] + 13000)) UIWidgetRecursiveStateUpdate(0, 1, 0);
    //     }
    //     if (dword_7CFB90 <= 1) sub_545D00(0, 256);
    //     if (!byte_7CE254) StateFlagComputation(0);
    //     if (dword_7CC4F4 && !SessionStateCheckWrapper(dword_7CD25C) && dword_8AB6E4 != 2 && (dword_7C56A4 != 7 || !byte_7CE254)) {
    //       sub_42D210(&dword_7C569C, byte_7C56AC == 0);
    //       if (byte_7C56AC) ArithmeticComparison_8d60(); else ShortComputation_8d70();
    //     }
    //     if (byte_7C56AC) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, aPaused, byte_5EC4CC)) copy aPaused to byte_5EC4CC;
    //       TextLineWrappingAndRendering(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
    //     }
    //     ++dword_8AFE84;
    //     EmptyStubWithFlagCheck(2, 0);
    //     dbl_8AFE90 = sub_556730(0);
    //     dbl_8AFEA8 += dbl_8AFE90;
    //     if (byte_7C56AC) dbl_8AFE98 = 0.0;
    //     else if (dbl_5D6D70 == 1.0) { dbl_8AFE98 = dbl_8AFE90; dbl_8AFEA0 += dbl_8AFE90;
    //       TimerResetUsingQueryPerformanceCounter(this); if (dbl_8AFE98 > 0.5) dbl_8AFE98 = 0.5; }
    //     else { dbl_8AFE98 = dbl_5D6D70 * dbl_8AFE90; if (dbl_8AFE98 > 0.5) dbl_8AFE98 = 0.5; dbl_8AFEA0 += dbl_8AFE98; }
    //     EmptyStubWithFlagCheck(1, 0);
    //     result = byte_8AFE72;
    //     if (byte_8AFE72) { byte_8AFE72 = 0; RepeatedCallLoop_f040(&dword_8ACEA0);
    //       return AIWaypointPathCheckerRenderer((int)dword_5EA2C0); }
    //     return result;
    //   }
    // UNRESOLVED: Globals dbl_59E420, dbl_59E880, byte_8AC494, dword_8AFE64, dword_8AFE88, byte_8AFE94, byte_8AFE9C, and dword_8B8F24 are listed as accessed by the fact table but do not appear in the decompiled body; their roles in the frame tick are unknown.
    // UNRESOLVED: The callee AIWaypointPathCheckerRenderer appears in the raw source but has no callee evidence in the packet, so no call evidence reference is emitted for it.
    // UNRESOLVED: dbl_5D6D70 doubles as both a 1.0 integration-enabled marker and a delta-time scaling factor; the exact intended semantics of values other than 1.0 are unresolved.
    // UNRESOLVED: Meaning of the bit indices 20, 29, 33, 34 in byte_7CA594 and the mode/color constants (3, 16909060) passed to the text renderer are not established.
}
