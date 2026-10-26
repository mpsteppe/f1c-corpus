// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041A6B0
// Canonical corpus name: DisplayMessage0x113
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DisplayMessage0x113_0041a6b0.c

void UnknownObject::DisplayMessage0x113()
{
    // Displays fixed race message ID 275 through the shared driver-data table. Guarded by the race-active flag dword_7D0308 and the track-condition state flt_7CF3C8; when both allow it, a vtable method at offset 12 on the sound/system pointer dword_5EB10C is called, the shared buffer flt_5EA618 is reset to 10.0f defaults, a driver table record v0 is populated with message ID 275 and placeholder arguments, and that record is inserted into the table.
    // GUARD: Run the main body only when dword_7D0308 is non-zero and flt_7CF3C8 is not 0.0; otherwise do nothing. [source:raw, global:0x007D0308, global:0x007CF3C8]
    // GUARD: Call the engine-interface method only when the interface pointer dword_5EB10C is non-null. [source:raw, global:0x005EB10C]
    // CALL: Invoke the __thiscall vtable method at offset 12 on the dword_5EB10C object (audio/system reset). [source:raw, global:0x005EB10C]
    // CALL: Reset the shared driver-data buffer flt_5EA618 to 10.0f defaults via BufferInitWith10fDefaults. [source:raw, callee:0x004186A0, global:0x005EA618]
    // CALL: Populate the stack record v0 with message ID 275 and placeholder driver indices and time via DriverDataTableLookupAndTimeConversion(v0, 275, -1, -1, -1, -1, -2.0, -2.0). [source:raw, callee:0x004144F0]
    // CALL: Insert the populated record v0 into the shared driver-data table at flt_5EA618 via InsertDriverTableEntry. [source:raw, callee:0x00418560, global:0x005EA618]
    // CALL: Invoked by PitTimer (0x004D2E50). [caller:0x004D2E50]

    // Conservative worker pseudocode:
    //   void sub_41A6B0() {
    //     if (dword_7D0308 && flt_7CF3C8 != 0.0) {
    //       if (dword_5EB10C) {
    //         (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
    //       }
    //       BufferInitWith10fDefaults(flt_5EA618);
    //       float v0[8];
    //       DriverDataTableLookupAndTimeConversion(v0, 275, -1, -1, -1, -1, -2.0, -2.0);
    //       InsertDriverTableEntry(flt_5EA618, v0);
    //     }
    //   }
    // UNRESOLVED: flt_59E440 (0x0059E440) is listed as a referenced global but does not appear in the raw source.
    // UNRESOLVED: Meaning of message ID 275 and the -1 / -2.0 placeholder arguments depends on DriverDataTableLookupAndTimeConversion.
    // UNRESOLVED: Identity of the vtable slot method invoked at offset 12 on dword_5EB10C is unresolved.
}
