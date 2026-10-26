// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046CB00
// Canonical corpus name: GlobalSignCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalSignCheck_0046cb00.c

void UnknownObject::GlobalSignCheck()
{
    // Stateless global sign test: reads the signed global dword_7CD2B8 (0x007CD2B8) and returns true when it is negative, otherwise false. No parameters, no callees, no side effects. Called by DriverTableIndexInitialization (0x0046CB10).
    // CALCULATION: Read the signed global dword_7CD2B8 (0x007CD2B8) and test its sign bit (value < 0). [global:0x007CD2B8, source:raw]
    // RETURN: Return the bool result of the sign test. [global:0x007CD2B8, source:raw]
    // CALL: Called by DriverTableIndexInitialization (0x0046CB10) to test the global sign state. [caller:0x0046CB10, source:raw]

    // Conservative worker pseudocode:
    //   bool GlobalSignCheck() {
    //     return dword_7CD2B8 < 0;
    //   }
    // UNRESOLVED: The purpose of the sign bit in dword_7CD2B8 is undefined by this packet; only the '< 0' test is evidenced.
    // UNRESOLVED: The writer of dword_7CD2B8 is not evidenced in this packet.
}
