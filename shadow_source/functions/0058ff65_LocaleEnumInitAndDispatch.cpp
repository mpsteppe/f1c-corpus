// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058FF65
// Canonical corpus name: sub_58FF65
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58FF65_0058ff65.c

void UnknownObject::LocaleEnumInitAndDispatch()
{
    // Initializes locale-matching state and dispatches a system-wide locale enumeration. Marks dword_8D3FA4 when the language string at dword_8D3FA8 has length 3 and dword_8D3F9C when the region string at dword_8D3FAC has length 3 (via Strlen 0058E1B0). Resets Locale (0x008D3F98) to 0, sets charset mode dword_8D3FA0 to 2 for a 3-letter language or to CountAlphabeticalChars (00590616) otherwise, then calls EnumSystemLocalesA with LocaleEnumProc (0x0058FFEC). After enumeration, validates dword_8D3FB0 flags (0x100, 0x200, 0x7) and clears it to 0 on failure. Called by sub_58FD90 (0058FD90).
    // CALL: Strlen (0058E1B0) is called on the language string at dword_8D3FA8; equality with length 3 is stored to dword_8D3FA4 [callee:0x0058E1B0, global:0x008D3FA4, global:0x008D3FA8, source:raw]
    // CALL: Strlen (0058E1B0) is called on the region string at dword_8D3FAC; equality with length 3 is stored to dword_8D3F9C [callee:0x0058E1B0, global:0x008D3F9C, global:0x008D3FAC, source:raw]
    // ASSIGNMENT: Clears the current locale global Locale (0x008D3F98) to 0 before enumeration [global:0x008D3F98, source:raw]
    // ASSIGNMENT: When the language is a 3-letter code (dword_8D3FA4 set), charset mode dword_8D3FA0 is set to 2; otherwise it is set to the CountAlphabeticalChars (00590616) result over dword_8D3FA8 [callee:0x00590616, global:0x008D3FA0, global:0x008D3FA4, global:0x008D3FA8, source:raw]
    // CALL: EnumSystemLocalesA (0x0059E138) is invoked with LocaleEnumProc (0x0058FFEC) as callback and 1 (LOCALE_SORT_DEFAULT style) to enumerate system locales [global:0x0058FFEC, global:0x0059E138, source:raw]
    // CALCULATION: Captures dword_8D3FB0 as the return value; the post-enumeration callback may have populated it [global:0x008D3FB0, source:raw]
    // GUARD: If dword_8D3FB0 lacks any of the 0x100, 0x200 or 0x7 flag bits, it is reset to 0; the captured pre-reset value is still returned [global:0x008D3FB0, source:raw]
    // RETURN: Returns the pre-validation snapshot of dword_8D3FB0 regardless of whether the guard cleared it [global:0x008D3FB0, source:raw]

    // Conservative worker pseudocode:
    //   dword_8D3FA4 = (Strlen(dword_8D3FA8) == 3);
    //   dword_8D3F9C = (Strlen(dword_8D3FAC) == 3);
    //   Locale = 0;
    //   if (dword_8D3FA4) dword_8D3FA0 = 2;
    //   else dword_8D3FA0 = CountAlphabeticalChars(dword_8D3FA8);
    //   EnumSystemLocalesA(LocaleEnumProc, 1);
    //   result = dword_8D3FB0;
    //   if ((dword_8D3FB0 & 0x100) == 0 || (dword_8D3FB0 & 0x200) == 0 || (dword_8D3FB0 & 7) == 0)
    //     dword_8D3FB0 = 0;
    //   return result;
    // UNRESOLVED: The meaning of the validated dword_8D3FB0 flag bits (0x100, 0x200, 0x7) set by LocaleEnumProc is not established in this packet
    // UNRESOLVED: Which enum values LocaleEnumProc writes and whether the callback runs synchronously is not evidenced here
    // UNRESOLVED: The relationship between the length-3 checks and the actual locale matching performed by LocaleEnumProc is not defined
    // UNRESOLVED: The caller sub_58FD90 context (when this init runs) is outside this packet
}
