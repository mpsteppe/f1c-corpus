// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C6D0
// Canonical corpus name: sub_49C6D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C6D0_0049c6d0.c

void UnknownObject::FormatPositionAndVehicleCount()
{
    // Formats the current race position and total vehicle count into the caller-provided output buffer a1 as " %d/%d" using StringFormatWithBufferOverflowCheck (0058815F). The position numerator is read from dword_7C54E0 + 16480 and the vehicle-count denominator from dword_5C329C. Returns 0. Called by FormatRegisterDispatch (0049D440), DrawDebugTextOverlay (004DBB60) and MultiLayerTextStringRenderer (004DBC90).
    // CALCULATION: Read the current race position value stored at dword_7C54E0 + 16480 (a dword dereference through the global pointer). [source:raw, global:0x007C54E0]
    // CALCULATION: Read the total vehicle count from dword_5C329C. [source:raw, global:0x005C329C]
    // CALL: Call StringFormatWithBufferOverflowCheck(a1, " %d/%d", position, vehicle_count) to write the formatted text into the output buffer. [source:raw, callee:0x0058815F]
    // CALL: Invoked by FormatRegisterDispatch (0049D440), DrawDebugTextOverlay (004DBB60) and MultiLayerTextStringRenderer (004DBC90). [caller:0x0049D440, caller:0x004DBB60, caller:0x004DBC90]
    // RETURN: Return 0. [function:0x0049C6D0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_49C6D0(int a1, int a2) {
    //     StringFormatWithBufferOverflowCheck(a1, " %d/%d", *(_DWORD *)(dword_7C54E0 + 16480), dword_5C329C);
    //     return 0;
    //   }
    // UNRESOLVED: Semantic identity of the position field at dword_7C54E0 + 16480 is inferred from the format string and callers only.
    // UNRESOLVED: aDD_1 (005CCE80) is listed by packet facts as read but appears nowhere in the raw decompiled source.
}
