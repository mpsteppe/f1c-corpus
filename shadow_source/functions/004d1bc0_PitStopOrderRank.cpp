// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1BC0
// Canonical corpus name: PitStopOrderRank
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitStopOrderRank_004d1bc0.c

void UnknownObject::PitStopOrderRank()
{
    // Computes a driver's race position by counting how many active drivers rank ahead of the queried driver according to DriverStandingComparator, then returns rank+1. When the session type is 7, returns a direct position value read from the vehicle array instead, skipping the comparator walk.
    // GUARD: If dword_7C56A4 (session type) equals 7, return the stored position value at dword_5F0738[4656 * a2] immediately. [global:0x007C56A4, global:0x005F0738, source:raw]
    // RETURN: Direct-position early return from the vehicle array for session type 7. [global:0x005F0738, source:raw]
    // GUARD: If dword_5C329C (vehicle count) is greater than zero, iterate over all vehicles to count drivers ranked ahead. [global:0x005C329C, source:raw]
    // LOOP: Loop v4 from 0 while v4 < dword_5C329C, incrementing the rank counter v5 when a driver ranks ahead. [global:0x005C329C, source:raw]
    // ASSIGNMENT: Read the driver-index byte of each vehicle from the vehicle pointer array dword_7C54F0[v4] at offset 18580. [global:0x007C54F0, source:raw]
    // CALL: Call DriverStandingComparator on the current driver index and the queried index a2; a negative result means the current driver ranks ahead. [callee:0x004D0C20, source:raw]
    // CALCULATION: Increment the rank counter when the compared driver is ahead, skipping the queried driver itself. [source:raw]
    // RETURN: Return the rank: number of drivers ahead plus one, or the direct stored position for session type 7. [source:raw]

    // Conservative worker pseudocode:
    //   int PitStopOrderRank(unsigned __int8 driverIdx) {
    //     if (sessionType == 7)
    //       return vehiclePositionArray[4656 * driverIdx];
    //     int rank = 1;
    //     for (int i = 0; i < vehicleCount; ++i) {
    //       unsigned __int8 other = *(BYTE*)(vehiclePtrs[i] + 18580);
    //       if (other != driverIdx && DriverStandingComparator(&other, &driverIdx) < 0)
    //         ++rank;
    //     }
    //     return rank;
    //   }
    // UNRESOLVED: Semantics of the offset 18580 (+0x4894) into each vehicle and how the byte maps to a driver index.
    // UNRESOLVED: Meaning of session type 7 and the layout/stride of the dword_5F0738 position array.
    // UNRESOLVED: Exact ordering contract of DriverStandingComparator beyond its negative-return meaning.
}
