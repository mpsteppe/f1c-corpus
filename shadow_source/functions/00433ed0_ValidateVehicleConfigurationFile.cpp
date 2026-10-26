// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00433ED0
// Canonical corpus name: ValidateVehicleConfigurationFile
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ValidateVehicleConfigurationFile_00433ed0.c

void UnknownObject::ValidateVehicleConfigurationFile()
{
    // Validates a vehicle configuration by parsing two SVM/HDV files in sequence: first the vehicle's default file (path read from a computed vehicle-array entry), then an override file (a2). Returns 0 only when both parses succeed; 1 otherwise. On success backs up the cost-display mode and clears the parse buffer, and when a3 is set commits the override path into the caller's string slots (this+0 and this+8, with byte_5EA438 fallbacks) via sub_568B00. The vehicle-array entry is computed as dword_8AC394 + 1060 * (index at dword_7C54E8 + 18584).
    // GUARD: If ScoringGateCheck() returns non-zero, proceed with validation; otherwise v4 stays 1 and the function returns 1. [callee:0x0042BC10, function:0x00433ED0, source:raw]
    // CALCULATION: v5 = dword_8AC394 + 1060 * *(_DWORD *)(dword_7C54E8 + 18584); compute a pointer into the vehicle data array using the index stored at dword_7C54E8 + 18584. Guard: continue only if v5 is non-null. [global:0x008AC394, global:0x007C54E8, function:0x00433ED0, source:raw]
    // ASSIGNMENT: dword_7C56C4 = dword_7D0450; back up the current cost-display mode before parsing. [global:0x007C56C4, global:0x007D0450, function:0x00433ED0, source:raw]
    // CALL: sub_42ED70(&byte_7C56C0); reset/initialize the session parse buffer. [callee:0x0042ED70, global:0x007C56C0, function:0x00433ED0, source:raw]
    // ASSIGNMENT: v6 = *(char **)(v5 + 8); if v6 is null use &byte_5EA438 (fallback default-path string). [global:0x005EA438, function:0x00433ED0, source:raw]
    // CALL: If TheSvmHdvVehicleFileParser(v6, &byte_7C56C0, 0) returns 0 the default file parse succeeds. [callee:0x004F4270, global:0x007C56C0, function:0x00433ED0, source:raw]
    // CALL: HistoryBufferShift(&byte_7C56C0); shift the history buffer to make room for the second parse. [callee:0x0042EBC0, global:0x007C56C0, function:0x00433ED0, source:raw]
    // CALL: If TheSvmHdvVehicleFileParser(a2, &byte_7C56C0, 1) returns 0 the override file parse succeeds: v4 = 0 and byte_7C56C0 = 0. [callee:0x004F4270, global:0x007C56C0, function:0x00433ED0, source:raw]
    // ASSIGNMENT: If a3 is set: v7 = this + 2 (destination string slot this+8); StringCopyWithBufferRealloc(a2); v8 = *this (fallback &byte_5EA438); v9 = *v7 (fallback &byte_5EA438); sub_568B00(v9, v8) copies the source path into the destination string slot. [callee:0x00566650, callee:0x00568B00, field:this:0x00000000, field:this:0x00000008, global:0x005EA438, function:0x00433ED0, source:raw]
    // CALL: VehicleStatsEstimationDisplay(&byte_7C56C0); refresh the vehicle stats estimation display after the parse sequence. [callee:0x00430F00, global:0x007C56C0, function:0x00433ED0, source:raw]
    // RETURN: Return v4: 0 when both files parsed (and a3 path committed), 1 otherwise. [function:0x00433ED0, source:raw]

    // Conservative worker pseudocode:
    //   v4 = 1;
    //   if (ScoringGateCheck()) {
    //     v5 = dword_8AC394 + 1060 * *(_DWORD*)(dword_7C54E8 + 18584);
    //     if (v5) {
    //       dword_7C56C4 = dword_7D0450;
    //       sub_42ED70(&byte_7C56C0);
    //       v6 = *(char**)(v5 + 8);
    //       if (!v6) v6 = &byte_5EA438;
    //       if (!TheSvmHdvVehicleFileParser(v6, &byte_7C56C0, 0)) {
    //         HistoryBufferShift(&byte_7C56C0);
    //         if (!TheSvmHdvVehicleFileParser(a2, &byte_7C56C0, 1)) {
    //           v4 = 0;
    //           byte_7C56C0 = 0;
    //           if (a3) {
    //             StringCopyWithBufferRealloc(a2);
    //             v8 = *this ? *this : &byte_5EA438;
    //             v9 = this[2] ? this[2] : &byte_5EA438;
    //             sub_568B00(v9, v8);
    //           }
    //         }
    //         VehicleStatsEstimationDisplay(&byte_7C56C0);
    //       }
    //     }
    //   }
    //   return v4;
    // UNRESOLVED: Globals unk_5EC6D0 and dword_8ADB00 are listed as read in the packet but do not appear in the raw source; their role here is unknown.
    // UNRESOLVED: The owning object is unknown; this method operates on an object whose this+0 and this+8 slots hold source/destination path strings.
    // UNRESOLVED: Callers LoadAIDriverNamesFromConfig (0x004336F0) and InitWithStackBuffer (0x0046E5C0) are known but were not used in any operation.
}
