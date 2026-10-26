// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B3BA0
// Canonical corpus name: IterateVehicles
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IterateVehicles_004b3ba0.c

void UnknownObject::IterateVehicles()
{
    // Vehicle-subsystem driver called from GamePostMainLoop: iterates i from 0 while i < dword_5C329C (vehicle count), passing the i-th element of the pointer array at dword_7C54F0 to TireTemperatureSimStep each pass, then returns the vehicle count. Advances the per-vehicle tire-temperature simulation one step for every active vehicle.
    // LOOP: Loop counter i starts at 0 and increments each pass while i < dword_5C329C (the vehicle count). [global:0x005C329C, source:raw]
    // CALL: For each index, call TireTemperatureSimStep with the i-th element of the pointer array at dword_7C54F0 (dword_7C54F0[i]), i.e. one vehicle pointer per iteration. [callee:0x004C77D0, global:0x007C54F0, source:raw]
    // RETURN: Return the vehicle count dword_5C329C as the result. [global:0x005C329C, source:raw]

    // Conservative worker pseudocode:
    //   int IterateVehicles() {
    //       for (int i = 0; i < dword_5C329C; ++i)
    //           TireTemperatureSimStep(dword_7C54F0[i]);
    //       return dword_5C329C;
    //   }
    // UNRESOLVED: dword_5C329C is read as the vehicle count but the packet records no writers for it.
    // UNRESOLVED: dword_7C54F0 is indexed as a dword (4-byte stride) pointer array; the packet does not bound its length.
    // UNRESOLVED: TireTemperatureSimStep's per-vehicle thermal model is not described by this packet.
    // UNRESOLVED: Owner is unknown; the only recorded caller is GamePostMainLoop (0x0042D8A0) and no owning class is evidenced.
}
