// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046CB10
// Canonical corpus name: DriverTableIndexInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DriverTableIndexInitialization_0046cb10.c

void UnknownObject::DriverTableIndexInitialization()
{
    // Initializes the driver index lookup table. Calls GlobalSignCheck (0x0046CB00) and returns 0 immediately if it fails. Otherwise iterates i from 0 to 103, reading each live driver identifier from dword_7CD470 (0x007CD470); when the identifier is non-negative the driver table entry dword_5F0730 at index 4656*v1 is written with the loop counter i. Returns 1 on success.
    // GUARD: When GlobalSignCheck returns false the function returns 0 immediately [callee:0x0046CB00, source:raw]
    // CALL: GlobalSignCheck is invoked as a precondition; its boolean result gates all table initialization [callee:0x0046CB00, source:raw]
    // LOOP: Iterate i over the range 0..103, reading a driver identifier from dword_7CD470 each pass [global:0x007CD470, source:raw]
    // ASSIGNMENT: v1 = dword_7CD470[i]: read the current driver identifier from the input array [global:0x007CD470, source:raw]
    // GUARD: A negative driver identifier breaks the loop before any table write [source:raw]
    // ASSIGNMENT: Write the loop counter i into the driver table dword_5F0730 at entry 4656*v1 (stride 4656 per driver) [global:0x005F0730, source:raw]
    // RETURN: Return 1 to signal successful initialization [function:0x0046CB10, source:raw]

    // Conservative worker pseudocode:
    //   if (!GlobalSignCheck()) return 0;
    //   for (i = 0; i < 104; dword_5F0730[4656 * v1] = i) {
    //     v1 = dword_7CD470[i];
    //     if (v1 < 0) break;
    //     ++i;
    //   }
    //   return 1;
    // UNRESOLVED: The semantic role of GlobalSignCheck's gate and the meaning of the 4656-byte driver-table stride are not evidenced beyond the raw source; the stride itself is taken from the packet verbatim
}
