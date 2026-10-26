// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041AB30
// Canonical corpus name: PitStateSlotActivation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitStateSlotActivation_0041ab30.c

void UnknownObject::PitStateSlotActivation()
{
    // Tracks pit-state slot activation for a slot index a2. Sets the slot's activation flag (2) at this + 0xA44 + a2*4, counts how many of the 4 consecutive slot flags are activated, then emits a driver-table event and inserts it into the session event table. When fewer than 3 slots are active it emits a per-slot event (switch on a2: 94/96/98/100); when 3+ are active it emits the combined event 104. Entire body is gated on race-active (dword_7D0308), track-condition (flt_7CF3C8 != 0.0) and race-phase (dword_7C56A8 != 8) globals.
    // GUARD: Outer activation gate: race active flag dword_7D0308 nonzero, track-condition float flt_7CF3C8 nonzero (compared against the zero constant flt_59E440), and race-phase dword_7C56A8 not equal to 8. The function body runs only when all three conditions hold. [source:raw, function:0x0041AB30, global:0x007D0308, global:0x007CF3C8, global:0x0059E440, global:0x007C56A8]
    // ASSIGNMENT: Mark slot a2 activated: write 2 to the slot flag at this + 0xA44 + a2*4 (DWORD index this + 657). [source:raw, field:this:0x00000A44]
    // CALL: Initialize the local 8-DWORD buffer v6 with sentinel values via StructInitWithSentinelValues. [source:raw, callee:0x004144D0]
    // LOOP: Count activated slots: iterate the 4 consecutive slot flags starting at this + 0xA44 (this + 657); each flag equal to 2 increments the counter (countdown loop of 4 iterations). [source:raw, field:this:0x00000A44, guard:0]
    // STATE_TRANSITION: Branch on the activated-slot count: if fewer than 3 slots are activated, select a per-slot event ID by switch on a2 (0 -> 94, 1 -> 96, 2 -> 98, 3 -> 100) dispatched through jump table jpt_41ABBC (default case performs no call); otherwise select the combined event ID 104. [source:raw, global:0x0041AC3C]
    // CALL: Fill v6 via DriverDataTableLookupAndTimeConversion with the selected event ID and placeholder arguments (-1, -1, -1, -1, -2.0, -2.0): the per-slot ID when few slots are active, or the combined ID 104 otherwise. [source:raw, callee:0x004144F0]
    // CALL: Insert the prepared event entry v6 into the session event table referenced by flt_5EA618 via InsertDriverTableEntry. [source:raw, callee:0x00418560, global:0x005EA618]
    // RETURN: Function returns void; no explicit return value. Activation is recorded only through the session event table insert. [source:raw]

    // Conservative worker pseudocode:
    //   void PitStateSlotActivation(int *this, int a2) {
    //     if (dword_7D0308 && flt_7CF3C8 != 0.0f && dword_7C56A8 != 8) {
    //       this[a2 + 657] = 2;
    //       float v6[8];
    //       StructInitWithSentinelValues(v6);
    //       int v3 = 0;
    //       int v5 = 4;
    //       int *v4 = this + 657;
    //       do { if (*v4 == 2) ++v3; ++v4; --v5; } while (v5);
    //       if (v3 < 3) {
    //         switch (a2) {
    //           case 0: DriverDataTableLookupAndTimeConversion(v6, 94, -1, -1, -1, -1, -2.0f, -2.0f); break;
    //           case 1: DriverDataTableLookupAndTimeConversion(v6, 96, -1, -1, -1, -1, -2.0f, -2.0f); break;
    //           case 2: DriverDataTableLookupAndTimeConversion(v6, 98, -1, -1, -1, -1, -2.0f, -2.0f); break;
    //           case 3: DriverDataTableLookupAndTimeConversion(v6, 100, -1, -1, -1, -1, -2.0f, -2.0f); break;
    //         }
    //       } else {
    //         DriverDataTableLookupAndTimeConversion(v6, 104, -1, -1, -1, -1, -2.0f, -2.0f);
    //       }
    //       InsertDriverTableEntry(flt_5EA618, v6);
    //     }
    //   }
    // UNRESOLVED: Owner class identity is unknown (UnknownObject); the object layout beyond the 4 slot flags at this + 0xA44 is not established.
    // UNRESOLVED: Meaning of the sentinel flag value 2 for an activated slot is not defined by the packet.
    // UNRESOLVED: Semantic mapping of event IDs 94/96/98/100/104 to specific commentary/event names is not present in the packet (inferred role only).
    // UNRESOLVED: flt_59E440 is referenced as the zero-threshold constant for the flt_7CF3C8 nonzero comparison, but its exact use site is not visible in the raw pseudocode.
}
