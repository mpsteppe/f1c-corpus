// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041A200
// Canonical corpus name: AIPitStrategyState
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/AIPitStrategyState_0041a200.c

void F1CVehicle::AIPitStrategyState()
{
    // AI pit-strategy event handler, restricted to the player vehicle during an active race. If dword_7D0308 (race active) is nonzero, flt_7CF3C8 (track condition) is nonzero, dword_7C56A8 (race phase) is not 8, and the player vehicle's driver ID (at dword_7C54E8 + 18580) matches the vehicle's a1[4645] (this+0x4894), then: when pitting status a1[3348] (this+0x3450) equals 1, selects an event type (52 if this+0x4040 is 2 or -1, else 42), fills a local record via DriverDataTableLookupAndTimeConversion, and inserts it into the session event table via InsertDriverTableEntry(flt_5EA618, record). Otherwise fires BooleanOROfTwoChecks(flt_5EA618, 42).
    // GUARD: Combined gate: proceed only if dword_7D0308 is nonzero AND flt_7CF3C8 != 0.0 AND dword_7C56A8 != 8 AND the dword at (dword_7C54E8 + 18580) equals a1[4645] (this+0x4894). [global:0x007D0308, global:0x007CF3C8, global:0x007C56A8, global:0x007C54E8, field:this:0x00004894, source:raw]
    // GUARD: Branch on pitting status: a1[3348] (this+0x3450) == 1. [field:this:0x00003450, guard:0, source:raw]
    // CALCULATION: Read v1 = a1[4112] (this+0x4040); default v3 = 42; if v1 == 2 or v1 == -1, set v3 = 52. [field:this:0x00004040, source:raw]
    // CALL: If pitting: fill the local event record via DriverDataTableLookupAndTimeConversion(v4, v3, -1, -1, -1, -1, -2.0, -2.0). [callee:0x004144F0, source:raw]
    // CALL: If pitting: insert the event record into the session event table via InsertDriverTableEntry(flt_5EA618, v4). [callee:0x00418560, global:0x005EA618, source:raw]
    // CALL: If not pitting: fire the Boolean OR check BooleanOROfTwoChecks(flt_5EA618, 42). [callee:0x00418A20, global:0x005EA618, source:raw]

    // Conservative worker pseudocode:
    //   void AIPitStrategyState(dword* a1) {
    //     if (dword_7D0308 && flt_7CF3C8 != 0.0 && dword_7C56A8 != 8
    //         && *(dword*)(dword_7C54E8 + 18580) == a1[4645]) {
    //       if (a1[3348] == 1) {
    //         v1 = a1[4112];
    //         v3 = 42;
    //         if (v1 == 2 || v1 == -1)
    //           v3 = 52;
    //         DriverDataTableLookupAndTimeConversion(v4, v3, -1, -1, -1, -1, -2.0, -2.0);
    //         InsertDriverTableEntry(flt_5EA618, v4);
    //       } else {
    //         BooleanOROfTwoChecks(flt_5EA618, 42);
    //       }
    //     }
    //   }
    // UNRESOLVED: Global flt_59E440 is listed as read (zero-threshold constant) but does not appear in the raw source; its role here is unclear.
    // UNRESOLVED: The dereference (dword_7C54E8 + 18580) reads the player vehicle's driver-ID slot; offset 18580 is spelled only in the raw source and has no packet field evidence reference.
    // UNRESOLVED: The semantics of the 42/52 event types and of the DriverDataTableLookupAndTimeConversion arguments are DERIVED from the existing analysis, not proven by the packet.
    // UNRESOLVED: The caller AIStateMachineWithModeDispatch (004A5D10) invokes this on mode change; the triggering context is not described by this packet's source.
}
