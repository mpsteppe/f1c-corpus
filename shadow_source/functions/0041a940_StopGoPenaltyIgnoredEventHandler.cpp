// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041A940
// Canonical corpus name: sub_41A940
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_41A940_0041a940.c

void UnknownObject::StopGoPenaltyIgnoredEventHandler()
{
    // 'IgnoredStopGoPenalty' commentary emitter. Guarded by the race-active flag dword_7D0308, the nonzero track-condition float flt_7CF3C8, and a non-NULL vehicle pointer a1. When the player vehicle pointer dword_7C54E8 is nonzero and equals a1, and a2 is non-NULL and matches the aIgnoredStopGoP literal, sets event code 149; otherwise, when a2 matches aIgnoredStopGoP on the AI path, sets event code 243. Both paths share one emission sequence: StructInitWithSentinelValues, DriverDataTableLookupAndTimeConversion(v3, v2, *(a1+0x489C), ...), and InsertDriverTableEntry(flt_5EA618, v3) into the session event table.
    // GUARD: Enter only when dword_7D0308 (race active) is nonzero, flt_7CF3C8 (track condition) != 0.0, and a1 (vehicle pointer) is nonzero. [global:0x007D0308, global:0x007CF3C8, source:raw]
    // GUARD: Take the player path when dword_7C54E8 (player vehicle pointer) is nonzero and equals a1. [global:0x007C54E8, source:raw]
    // GUARD: Player path: require a2 to be non-NULL and strcmp(aIgnoredStopGoP, a2) == 0. [global:0x005C2730, source:raw]
    // ASSIGNMENT: Set v2 = 149, the player ignored-stop-go-penalty event code. [source:raw]
    // CALL: StructInitWithSentinelValues(v3) initializes the local 8-float event struct with sentinel values. [callee:0x004144D0, source:raw]
    // CALL: DriverDataTableLookupAndTimeConversion(v3, v2, *(a1+0x489C), -1, -1, -1, -2.0, -2.0) fills the struct with event code v2 and the driver id at a1+0x489C as context. [callee:0x004144F0, field:this:0x0000489C, source:raw]
    // CALL: InsertDriverTableEntry(flt_5EA618, v3) inserts the filled event struct into the session event table. [callee:0x00418560, global:0x005EA618, source:raw]
    // GUARD: AI path (else branch): require a2 to be non-NULL and strcmp(aIgnoredStopGoP, a2) == 0. [global:0x005C2730, source:raw]
    // ASSIGNMENT: Set v2 = 243, the AI ignored-stop-go-penalty event code, then jump to the shared emission sequence (StructInitWithSentinelValues / DriverDataTableLookupAndTimeConversion / InsertDriverTableEntry). [source:raw]
    // CALL: Shared emission sequence for the AI path: StructInitWithSentinelValues(v3); DriverDataTableLookupAndTimeConversion(v3, 243, *(a1+0x489C), -1, -1, -1, -2.0, -2.0); InsertDriverTableEntry(flt_5EA618, v3). [callee:0x004144D0, callee:0x004144F0, callee:0x00418560, field:this:0x0000489C, global:0x005EA618, source:raw]
    // RETURN: Void return; no value. [source:raw]

    // Conservative worker pseudocode:
    //   if (!dword_7D0308 || flt_7CF3C8 == 0.0 || !a1) return;
    //   if (dword_7C54E8 && dword_7C54E8 == a1) {
    //     if (a2 && !strcmp(aIgnoredStopGoP, a2)) {
    //       v2 = 149;
    //       goto EMIT;
    //     }
    //   } else if (a2 && !strcmp(aIgnoredStopGoP, a2)) {
    //     v2 = 243;
    //     goto EMIT;
    //   }
    //   return;
    //   EMIT:
    //   StructInitWithSentinelValues(v3);
    //   DriverDataTableLookupAndTimeConversion(v3, v2, *(a1 + 0x489C), -1, -1, -1, -2.0, -2.0);
    //   InsertDriverTableEntry(flt_5EA618, v3);
    // UNRESOLVED: flt_59E440 is listed as a read global in the packet but never appears in the raw source text; likely a zero-comparison constant folded into the '!= 0.0' guard, unproven.
    // UNRESOLVED: Event codes 149 and 243 are not named in the packet; the player/AI interpretation follows the existing analysis and the player-pointer comparison.
    // UNRESOLVED: The field evidence base is named 'this' while the raw source reads offset 0x489C on the a1 vehicle pointer; the equivalence is inferred from the identical offset.
    // UNRESOLVED: The exact structure of the session event table at flt_5EA618 and the meaning of the -1 / -2.0 lookup arguments are unknown.
}
