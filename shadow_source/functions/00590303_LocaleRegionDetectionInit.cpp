// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00590303
// Canonical corpus name: sub_590303
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_590303_00590303.c

void UnknownObject::LocaleRegionDetectionInit()
{
    // Detects whether the locale language region string at dword_8D3FAC is three characters long and stores the comparison result to dword_8D3F9C. Enumerates system locales through EnumSystemLocalesA with callback sub_59033A. When bit 2 of dword_8D3FB0 is clear, resets dword_8D3FB0 to 0. Returns the EnumSystemLocalesA result.
    // ASSIGNMENT: Set dword_8D3F9C to whether Strlen(dword_8D3FAC) equals 3, i.e. whether the locale region string is three characters long. [global:0x008D3F9C, global:0x008D3FAC, callee:0x0058E1B0, source:raw]
    // CALL: Enumerate system locales through EnumSystemLocalesA with callback sub_59033A and flags value 1. [global:0x0059E138, global:0x0059033A, source:raw]
    // ASSIGNMENT: Set result to the return value of EnumSystemLocalesA. [source:raw]
    // GUARD: When bit 2 of dword_8D3FB0 is clear, reset the flags word. [global:0x008D3FB0, source:raw]
    // ASSIGNMENT: Set dword_8D3FB0 to 0. [global:0x008D3FB0, source:raw]
    // RETURN: Return result, the EnumSystemLocalesA return value. [source:raw]

    // Conservative worker pseudocode:
    //   dword_8D3F9C = (Strlen(dword_8D3FAC) == 3);
    //   result = EnumSystemLocalesA(sub_59033A, 1);
    //   if ((dword_8D3FB0 & 4) == 0) {
    //       dword_8D3FB0 = 0;
    //   }
    //   return result;
    // UNRESOLVED: What callback sub_59033A does with each enumerated locale is outside this function and not grounded by the packet.
    // UNRESOLVED: The meaning of bit 2 of dword_8D3FB0 and why the flags word is zeroed when it is clear are not established.
    // UNRESOLVED: The role of the 3-character string-length match stored to dword_8D3F9C (locale region indicator) is DERIVED from the fill, not packet-grounded.
}
