// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046A980
// Canonical corpus name: IDPairMatchAndClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IDPairMatchAndClear_0046a980.c

void UnknownObject::IDPairMatchAndClear()
{
    // Scans a global array of 7-dword entries from dword_7D1B08 up to but excluding dword_7D1FD8. For each entry whose first two dwords match the two dwords of the incoming pair pointer, the matched entry is rewritten to 0 and 89. Returns the scan pointer after the array bound. Called from ControllerShifterMapping at 0x0046A9C0.
    // LOOP: Iterate scan pointer from dword_7D1B08 to dword_7D1FD8, advancing 7 dwords per entry [global:0x007D1B08, global:0x007D1FD8]
    // GUARD: Match when *result == *a1 and result[1] == a1[1] [field:this:0x00000000, field:this:0x00000004]
    // ASSIGNMENT: Clear matched entry first dword: *result = 0 [global:0x007D1B08]
    // ASSIGNMENT: Set matched entry second dword: result[1] = 89 [global:0x007D1B08]
    // RETURN: Return the scan pointer, now one past the last scanned entry [global:0x007D1FD8]

    // Conservative worker pseudocode:
    //   result = dword_7D1B08;
    //   do {
    //       if (result[0] == a1[0] && result[1] == a1[1]) {
    //           result[0] = 0;
    //           result[1] = 89;
    //       }
    //       result += 7;
    //   } while ((int)result < (int)&dword_7D1FD8);
    //   return result;
    // UNRESOLVED: Meaning of the literal 89 written into the second dword of a matched entry
    // UNRESOLVED: Structure of the 7-dword array entries beyond the first two ID dwords
    // UNRESOLVED: Why the first two entry dwords are cleared to 0/89 rather than fully removed
}
