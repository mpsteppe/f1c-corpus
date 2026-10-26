// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059033A
// Canonical corpus name: sub_59033A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59033A_0059033a.c

void UnknownObject::LocaleRegionEnumCallback()
{
    // __stdcall callback that parses a locale ID string with HexStringToIntParser, then queries locale information through the function pointer at dword_8D3FB8 using the parsed ID and a flag word built from dword_8D3F9C. On a successful query it compares the returned region string against dword_8D3FAC via sub_588410; when they match and ShortInRangeCheckAgainstStaticTable validates the ID, it sets the matched-region flag dword_8D3FB0 |= 4, records the ID in dword_8D3FB4 and Locale, and returns the validation-flag bit test result. On a failed query it clears dword_8D3FB0 and returns 1.
    // CALL: Parse the incoming locale ID string a1 to an integer v1 via HexStringToIntParser. [callee:0x005905DD]
    // CALCULATION: Build the flag word v2: -(dword_8D3F9C != 0), then LOWORD(v2) &= 0xF005; the constant flags come from the nonzero state of dword_8D3F9C. [global:0x008D3F9C]
    // CALL: Indirect call through the function pointer at dword_8D3FB8 with (v1, v2 + 4098, local buffer v4, 120) to query locale information; the return value decides the branch. [global:0x008D3FB8]
    // GUARD: When the locale-info query returns nonzero (success), continue the match checks; otherwise set dword_8D3FB0 = 0 and return 1. [global:0x008D3FB0]
    // CALL: Compare the queried region buffer v4 against the stored region pointer dword_8D3FAC via sub_588410; proceed only when the comparison returns zero (match). [callee:0x00588410, global:0x008D3FAC]
    // GUARD: ShortInRangeCheckAgainstStaticTable(v1) validates that the parsed locale ID falls within a known region range before committing it. [callee:0x00590440]
    // ASSIGNMENT: Set the matched-region flag: dword_8D3FB0 |= 4. [global:0x008D3FB0]
    // ASSIGNMENT: Record the parsed locale ID in dword_8D3FB4. [global:0x008D3FB4]
    // ASSIGNMENT: Store the parsed locale ID into the Locale global at 0x008D3F98. [global:0x008D3F98]
    // RETURN: Return ((~dword_8D3FB0 >> 2) & 1) on the success path, testing the matched-region flag bit. [global:0x008D3FB0, function:0x0059033A]
    // RETURN: Return 1 on the failure path, after clearing dword_8D3FB0 to 0. [global:0x008D3FB0]

    // Conservative worker pseudocode:
    //   unsigned int LocaleRegionEnumCallback(LPSTR a1) {
    //     int v1 = HexStringToIntParser(a1);
    //     int v2 = -(dword_8D3F9C != 0);
    //     LOWORD(v2) = v2 & 0xF005;
    //     _BYTE buf[120];
    //     if (dword_8D3FB8(v1, v2 + 4098, buf, 120)) {
    //       if (!sub_588410((_BYTE *)dword_8D3FAC, buf)) {
    //         if (ShortInRangeCheckAgainstStaticTable(v1)) {
    //           dword_8D3FB0 |= 4;
    //           dword_8D3FB4 = v1;
    //           Locale = v1;
    //         }
    //       }
    //       return ((unsigned int)~dword_8D3FB0 >> 2) & 1;
    //     } else {
    //       dword_8D3FB0 = 0;
    //       return 1;
    //     }
    //   }
    // UNRESOLVED: Meaning of the flag word v2 (mask 0xF005) and the +4098 argument offset to the locale-info call is not evidenced in this packet.
    // UNRESOLVED: Semantics of the return value ((~dword_8D3FB0 >> 2) & 1) relative to the callback contract are unconfirmed.
    // UNRESOLVED: Owner of the locale globals and the identities of the function pointer at dword_8D3FB8 and region pointer at dword_8D3FAC are unproven; caller is unknown.
}
