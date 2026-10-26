// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041A500
// Canonical corpus name: TimeBasedMessageChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimeBasedMessageChain_0041a500.c

void UnknownObject::TimeBasedMessageChain()
{
    // Time-based race message dispatcher. Gated on a race-active flag (dword_7D0308) and a nonzero track-condition float (flt_7CF3C8). Computes elapsed time v6 = a1 - dbl_8AFEA0 and cumulative time v4 = dbl_8AFE98 + v6; as cumulative time crosses descending thresholds (2700s, 1800s, 900s, 600s, 300s, 180s), selects a message selector (35, 34, 277, 276, 279, 278) and inserts a driver-table entry: struct initialized with sentinel values, populated via driver-data lookup/time conversion with -1 driver indices and -2.0 sentinel floats, then InsertDriverTableEntry into the table rooted at flt_5EA618. When elapsed falls to <= 0.0, invokes a virtual thiscall at vtable offset 12 on dword_5EB10C (labeled SoundSystemPtr, DERIVED) and reinitializes the flt_5EA618 buffer via BufferInitWith10fDefaults. Called by PitTimer (0x004D2E50).
    // GUARD: Race-session gate: proceed only if dword_7D0308 is nonzero. [global:0x007D0308, source:raw]
    // GUARD: Track-condition gate: proceed only if flt_7CF3C8 is not 0.0. [global:0x007CF3C8, source:raw]
    // CALCULATION: Compute elapsed time v6 = a1 - dbl_8AFEA0 (argument time minus stored reference/session-offset time). [global:0x008AFEA0, function:0x0041A500, source:raw]
    // GUARD: If elapsed v6 is not below 2700.0, exit without dispatching. [source:raw]
    // CALCULATION: Compute cumulative time v4 = dbl_8AFE98 + v6 (stored accumulated time plus elapsed). [global:0x008AFE98, source:raw]
    // GUARD: If cumulative v4 >= 2700.0, select the 2700-second milestone message. [source:raw]
    // ASSIGNMENT: Set message selector v3 = 35 for the 2700-second milestone. [source:raw]
    // CALL: Shared dispatch path: StructInitWithSentinelValues(v5); DriverDataTableLookupAndTimeConversion(v5, v3, -1, -1, -1, -1, -2.0, -2.0); InsertDriverTableEntry(flt_5EA618, v5). [callee:0x004144D0, callee:0x004144F0, callee:0x00418560, global:0x005EA618, source:raw]
    // RETURN: Exit after dispatching a message entry. [source:raw]
    // GUARD: If elapsed v6 < 1800.0, continue descending threshold checks. [source:raw]
    // GUARD: If cumulative v4 >= 1800.0, select the 1800-second milestone message. [source:raw]
    // ASSIGNMENT: Set message selector v3 = 34 for the 1800-second milestone. [source:raw]
    // GUARD: If elapsed v6 < 900.0, continue descending threshold checks. [source:raw]
    // GUARD: If cumulative v4 >= 900.0, select the 900-second milestone message. [source:raw]
    // ASSIGNMENT: Set message selector v3 = 277 for the 900-second milestone. [source:raw]
    // GUARD: If elapsed v6 < 600.0, continue descending threshold checks. [source:raw]
    // GUARD: If cumulative v4 >= 600.0, select the 600-second milestone message. [source:raw]
    // ASSIGNMENT: Set message selector v3 = 276 for the 600-second milestone. [source:raw]
    // GUARD: If elapsed v6 < 300.0, continue descending threshold checks. [source:raw]
    // GUARD: If cumulative v4 >= 300.0, select the 300-second milestone message. [source:raw]
    // ASSIGNMENT: Set message selector v3 = 279 for the 300-second milestone. [source:raw]
    // GUARD: If elapsed v6 < 180.0, continue descending threshold checks. [source:raw]
    // GUARD: If cumulative v4 >= 180.0, select the 180-second milestone message. [source:raw]
    // ASSIGNMENT: Set message selector v3 = 278 for the 180-second milestone. [source:raw]
    // GUARD: If elapsed v6 <= 0.0, take the reset/cleanup branch. [source:raw]
    // GUARD: If dword_5EB10C (labeled SoundSystemPtr, DERIVED) is nonzero, invoke its vtable method at offset 12 (thiscall). [global:0x005EB10C, source:raw]
    // CALL: Virtual thiscall dispatch on dword_5EB10C reading the pointer at vtable offset 12 (third virtual method). [global:0x005EB10C, source:raw]
    // CALL: BufferInitWith10fDefaults(flt_5EA618): reinitialize the driver-table/buffer rooted at flt_5EA618 with sentinel defaults. [callee:0x004186A0, global:0x005EA618, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7D0308 && flt_7CF3C8 != 0.0) {
    //       double elapsed = a1 - dbl_8AFEA0;
    //       if (elapsed < 2700.0) {
    //           float cumulative = dbl_8AFE98 + elapsed;
    //           int selector;
    //           if (cumulative >= 2700.0) selector = 35;
    //           else if (elapsed < 1800.0) {
    //               if (cumulative >= 1800.0) selector = 34;
    //               else if (elapsed < 900.0) {
    //                   if (cumulative >= 900.0) selector = 277;
    //                   else if (elapsed < 600.0) {
    //                       if (cumulative >= 600.0) selector = 276;
    //                       else if (elapsed < 300.0) {
    //                           if (cumulative >= 300.0) selector = 279;
    //                           else if (elapsed < 180.0) {
    //                               if (cumulative >= 180.0) selector = 278;
    //                               else if (elapsed <= 0.0) {
    //                                   if (dword_5EB10C) { /* thiscall via vtable offset 12 * / }
    //                                   BufferInitWith10fDefaults(flt_5EA618);
    //                               }
    //                           }
    //                       }
    //                   }
    //               }
    //           }
    //           if (selector selected) {
    //               StructInitWithSentinelValues(entry);
    //               DriverDataTableLookupAndTimeConversion(entry, selector, -1, -1, -1, -1, -2.0, -2.0);
    //               InsertDriverTableEntry(flt_5EA618, entry);
    //           }
    //       }
    //   }
    // UNRESOLVED: Seven packet globals (flt_59E440, flt_59E808, flt_59E80C, flt_59E810, flt_59E814, flt_59E818, flt_59E81C) are listed in the packet globals but do not appear in the decompiled body. Packet existing_analysis labels them as threshold-like values (ZeroThreshold, EngineTempThreshold, PitlaneTimeThreshold, LapTimeThreshold1, OscillationMax, EngineRPMThreshold1, LeadInPositionThreshold), but no direct read/write is visible in this function's raw source, so their role here is ungrounded.
    // UNRESOLVED: Pairwise meaning of dbl_8AFEA0 (subtracted from argument a1) and dbl_8AFE98 (added to elapsed) is only partially determined: they form elapsed/cumulative time windows, but whether they are session offset versus last-message time is not proven by this packet alone.
    // UNRESOLVED: Semantic meaning of the message selectors 35, 34, 277, 276, 279, 278 (commentary/event text ids) is not established by this packet.
    // UNRESOLVED: The virtual method dispatched on dword_5EB10C at vtable offset 12 is not identified; dword_5EB10C is labeled SoundSystemPtr in existing_analysis (DERIVED).
    // UNRESOLVED: flt_5EA618 is passed to InsertDriverTableEntry as a table/buffer base and to BufferInitWith10fDefaults for reinitialization; its exact container type is unknown.
}
