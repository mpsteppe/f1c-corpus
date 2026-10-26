// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005901F0
// Canonical corpus name: sub_5901F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5901F0_005901f0.c

void UnknownObject::LocaleDetectionInit()
{
    // Locale detection initialization. Computes the length of the language string dword_8D3FA8 via Strlen, records whether it is a three-letter ISO code into dword_8D3FA4, and stores the charset mode into dword_8D3FA0 (2 for a three-letter string, otherwise the CountAlphabeticalChars result of the language string). It then enumerates system locales with EnumSystemLocalesA (import at 0x0059E138) invoking the callback sub_590246, and finally clears dword_8D3FB0 when its bit 4 is not set. Returns the BOOL result of EnumSystemLocalesA.
    // CALL: Strlen(dword_8D3FA8) computes the length of the locale language string. [callee:0x0058E1B0, global:0x008D3FA8]
    // ASSIGNMENT: dword_8D3FA4 = (length == 3) records whether the language string is a three-letter ISO code. [global:0x008D3FA4, callee:0x0058E1B0, global:0x008D3FA8]
    // GUARD: Branch on whether the language string length equals 3 (three-letter ISO code). [source:raw]
    // ASSIGNMENT: dword_8D3FA0 = 2 when the language string is three letters long (fixed charset mode). [global:0x008D3FA0, source:raw]
    // CALL: CountAlphabeticalChars(dword_8D3FA8) counts the alphabetical characters of the language string for the non-three-letter path. [callee:0x00590616, global:0x008D3FA8]
    // ASSIGNMENT: dword_8D3FA0 = CountAlphabeticalChars(dword_8D3FA8) stores the derived charset mode when the string is not three letters long. [global:0x008D3FA0, callee:0x00590616, global:0x008D3FA8]
    // CALL: EnumSystemLocalesA(sub_590246, 1) enumerates system locales invoking the callback sub_590246 for each; the import is reached through the IAT slot at 0x0059E138. [global:0x00590246, global:0x0059E138, source:raw]
    // GUARD: When (dword_8D3FB0 & 4) == 0 the locale validation flags are cleared by writing dword_8D3FB0 = 0. [global:0x008D3FB0, source:raw]
    // RETURN: Return the BOOL result of EnumSystemLocalesA. [source:raw]
    // CALL: Invoked from sub_58FD90 (0x0058FD90) as part of locale detection setup. [caller:0x0058FD90]

    // Conservative worker pseudocode:
    //   BOOL LocaleDetectionInit() {
    //     char* v0 = Strlen(dword_8D3FA8);
    //     dword_8D3FA4 = (v0 == 3);
    //     if (v0 == 3)
    //       dword_8D3FA0 = 2;
    //     else
    //       dword_8D3FA0 = CountAlphabeticalChars(dword_8D3FA8);
    //     BOOL result = EnumSystemLocalesA(sub_590246, 1);
    //     if ((dword_8D3FB0 & 4) == 0)
    //       dword_8D3FB0 = 0;
    //     return result;
    //   }
    // UNRESOLVED: Owner object identity is unknown; this is a global locale-detection routine rather than an object method.
    // UNRESOLVED: The semantic meaning of the dword_8D3FA0 mode values (2 and the alphabetical-character count) and of bit 4 in dword_8D3FB0 is taken from the existing analysis (DERIVED), not stated by the packet.
    // UNRESOLVED: The sub_590246 locale-enumeration callback implementation is outside this packet.
}
