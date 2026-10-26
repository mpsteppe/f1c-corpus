// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041C090
// Canonical corpus name: DisplayMessage0x202
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DisplayMessage0x202_0041c090.c

void UnknownObject::DisplayMessage0x202()
{
    // Display-message helper gated by two globals: when dword_7D0308 (0x007D0308) is non-zero and flt_7CF3C8 (0x007CF3C8) is not equal to 0.0, it fills an 8-float stack buffer via DriverDataTableLookupAndTimeConversion (0x004144F0) with message code 514 and sentinel arguments (-1, -1, -1, -1, -2.0, -2.0), then passes that buffer together with the global at 0x005EA618 to InsertDriverTableEntry (0x00418560). Called only from sub_40DE60 (0x0040DE60). The 0x202 in the canonical name equals the decimal 514 passed to the lookup (514 = 0x202).
    // GUARD: Outer enable guard: proceed only when the global dword at 0x007D0308 (dword_7D0308) is non-zero. [global:0x007D0308, source:raw]
    // GUARD: Nested guard: proceed only when the global float at 0x007CF3C8 (flt_7CF3C8) is not equal to 0.0. [global:0x007CF3C8, source:raw]
    // CALL: DriverDataTableLookupAndTimeConversion(v0, 514, -1, -1, -1, -1, -2.0, -2.0): fill the 8-float local buffer v0 with a driver-table lookup/time-converted record, passing message code 514, four -1 sentinels and two -2.0 default values. [callee:0x004144F0, source:raw]
    // CALL: InsertDriverTableEntry(flt_5EA618, v0): hand the lookup-filled buffer and the global float value at 0x005EA618 to the driver-table entry insert helper. [callee:0x00418560, global:0x005EA618, source:raw]
    // CALL: Invoked only from sub_40DE60 (0x0040DE60) as the sole static caller. [caller:0x0040DE60, source:raw]

    // Conservative worker pseudocode:
    //   void DisplayMessage0x202() {
    //     float v0[8];
    //     if (dword_7D0308) {
    //       if (flt_7CF3C8 != 0.0) {
    //         DriverDataTableLookupAndTimeConversion(v0, 514, -1, -1, -1, -1, -2.0, -2.0);
    //         InsertDriverTableEntry(flt_5EA618, v0);
    //       }
    //     }
    //   }
    // UNRESOLVED: The packet lists a read of global flt_59E440 (0x0059E440) but the raw source text contains no reference to it; its role in this function is unexplained.
    // UNRESOLVED: The meaning of the 514 message code and the -1/-2.0 sentinel arguments to DriverDataTableLookupAndTimeConversion is not established here.
    // UNRESOLVED: How InsertDriverTableEntry uses the float global at 0x005EA618 (as an index/key versus a data value) is not verifiable from this packet.
    // UNRESOLVED: The semantics of the two guard globals (dword_7D0308 enable flag and flt_7CF3C8 non-zero float) are unknown.
    // UNRESOLVED: The owner is unknown; the prelabel cluster-copy relationship to DisplayMessage0x11c (0041a4a0) is DERIVED from structure, not proven.
}
