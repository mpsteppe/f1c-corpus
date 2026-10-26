// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041AC50
// Canonical corpus name: sub_41AC50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_41AC50_0041ac50.c

void UnknownObject::GearBasedEventDispatch()
{
    // Dispatches race-commentary driver-table events for AI vehicles during championship weekend (session type 7). Event type a2 selects the event code: 0 = generic vehicle event (208), 2 = gear-specific events (211-217 chosen from current gear a1[3711] via jump table), 3 = retirement event (220). Fills a local event entry struct and appends it to the session event table. Proceeds only while the race is active, track condition is nonzero, the session gate holds, and the target vehicle is neither the player vehicle nor finished.
    // GUARD: Guard: race-active flag dword_7D0308 must be nonzero before any event dispatch. [global:0x007D0308, source:raw]
    // GUARD: Guard: track condition state flt_7CF3C8 must be nonzero, tested against the ~0.0f literal constant flt_59E440. [global:0x007CF3C8, global:0x0059E440, source:raw]
    // GUARD: Guard: driver pointer a1 must be non-null. [source:raw]
    // GUARD: Guard: session gate — race phase dword_7C56A8 must not be 8 and session type dword_7C56A4 must be 7 (championship weekend). [global:0x007C56A8, global:0x007C56A4, source:raw]
    // CALL: Call StructInitWithSentinelValues(v3) to initialize the local 8-element event-entry struct v3. [callee:0x004144D0, source:raw]
    // GUARD: Guard: vehicle is not the player vehicle (dword_7C54E8 null or not equal to a1) and finish state a1[4121] at field this+0x4064 is zero. [global:0x007C54E8, field:this:0x00004064, source:raw]
    // ASSIGNMENT: Event-code selection for a2 == 0: v2 = 208 (generic vehicle event). [source:raw]
    // CALCULATION: For a2 == 2, switch on current gear a1[3711] at field this+0x39FC through jump table jpt_41ACE9 (0x0041AD60): gears 0-1 map to 212, 2 to 213, 3 to 214, 4 to 215, 5 to 216, 6 to 217, default to 211. [field:this:0x000039FC, global:0x0041AD60, source:raw]
    // ASSIGNMENT: Event-code selection for a2 == 3: v2 = 220 (retirement event). [source:raw]
    // RETURN: If a2 is not 0, 2 or 3, return early without inserting any event entry. [source:raw]
    // CALL: Call DriverDataTableLookupAndTimeConversion(v3, v2, a1[4647], -1, -1, -1, -2.0, -2.0) to fill the event entry struct with the selected event code and the driver-context index a1[4647] at field this+0x489C. [callee:0x004144F0, field:this:0x0000489C, source:raw]
    // CALL: Call InsertDriverTableEntry(flt_5EA618, v3) to append the completed entry to the session event table referenced by flt_5EA618. [callee:0x00418560, global:0x005EA618, source:raw]

    // Conservative worker pseudocode:
    //   void sub_41AC50(_DWORD *a1, int a2) {
    //     float v3[8]; int v2;
    //     if (!dword_7D0308) return;
    //     if (flt_7CF3C8 == 0.0) return;
    //     if (!a1) return;
    //     if (dword_7C56A8 == 8 || dword_7C56A4 != 7) return;
    //     StructInitWithSentinelValues(v3);
    //     if (dword_7C54E8 && (_DWORD *)dword_7C54E8 == a1) return;
    //     if (a1[4121]) return;
    //     if (a2 == 0) v2 = 208;
    //     else if (a2 == 2) {
    //       switch (a1[3711]) {
    //         case 0: case 1: v2 = 212; break;
    //         case 2: v2 = 213; break;
    //         case 3: v2 = 214; break;
    //         case 4: v2 = 215; break;
    //         case 5: v2 = 216; break;
    //         case 6: v2 = 217; break;
    //         default: v2 = 211; break;
    //       }
    //     }
    //     else if (a2 == 3) v2 = 220;
    //     else return;
    //     DriverDataTableLookupAndTimeConversion(v3, v2, a1[4647], -1, -1, -1, -2.0, -2.0);
    //     InsertDriverTableEntry(flt_5EA618, v3);
    //   }
    // UNRESOLVED: Exact in-game meaning of event codes 208, 211-217 and 220 (gear-change and retirement commentary) is DERIVED from the existing analysis fill, not proven by this packet.
    // UNRESOLVED: Role of flt_59E440 as the zero-threshold constant in the flt_7CF3C8 comparison is inferred; the packet does not show its load site.
    // UNRESOLVED: Structure of jump table jpt_41ACE9 at 0x0041AD60 and the exact switch-case layout for the gear event selection are not recoverable from this packet alone.
    // UNRESOLVED: Field at this+0x489C (a1[4647]) is consumed as the driver-context index for the event lookup; its precise semantic role beyond 'driver id' is not evidenced here.
}
