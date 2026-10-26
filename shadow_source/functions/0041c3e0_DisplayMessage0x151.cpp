// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041C3E0
// Canonical corpus name: DisplayMessage0x151
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DisplayMessage0x151_0041c3e0.c

void UnknownObject::DisplayMessage0x151()
{
    // Emits fixed session event message ID 337 through the shared driver-data table when the race is active and the track condition is valid. Guarded by the race-active flag dword_7D0308 and the track-condition state flt_7CF3C8; when both allow it, a local record v0 is populated with message ID 337 and placeholder driver/time arguments by DriverDataTableLookupAndTimeConversion, then that record is inserted into the session table at flt_5EA618 by InsertDriverTableEntry. Structural twin of the function DisplayMessage0x11c, which emits message ID 284 through the same guarded path.
    // GUARD: Run the body only when dword_7D0308 is non-zero and flt_7CF3C8 is not 0.0; otherwise do nothing. [source:raw, global:0x007D0308, global:0x007CF3C8]
    // CALL: Populate the stack record v0 with message ID 337 and placeholder driver indices and time via DriverDataTableLookupAndTimeConversion(v0, 337, -1, -1, -1, -1, -2.0, -2.0). [source:raw, callee:0x004144F0]
    // CALL: Insert the populated record v0 into the shared driver-data table at flt_5EA618 via InsertDriverTableEntry. [source:raw, callee:0x00418560, global:0x005EA618]
    // CALL: Invoked by sub_40DE60. [caller:0x0040DE60]
    // RETURN: Void return once the guarded table insert completes. [function:0x0041C3E0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_41C3E0() {
    //     if (dword_7D0308 && flt_7CF3C8 != 0.0) {
    //       float v0[8];
    //       DriverDataTableLookupAndTimeConversion(v0, 337, -1, -1, -1, -1, -2.0, -2.0);
    //       InsertDriverTableEntry(flt_5EA618, v0);
    //     }
    //   }
    // UNRESOLVED: flt_59E440 (0x0059E440) is listed as a referenced global but does not appear in the raw source.
    // UNRESOLVED: Meaning of message ID 337 and the -1 / -2.0 placeholder arguments depends on DriverDataTableLookupAndTimeConversion.
}
