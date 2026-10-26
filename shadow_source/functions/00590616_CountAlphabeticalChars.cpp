// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00590616
// Canonical corpus name: CountAlphabeticalChars
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CountAlphabeticalChars_00590616.c

void UnknownObject::CountAlphabeticalChars()
{
    // Scans the input string a1 from its start and counts the leading run of ASCII letters before the first non-letter character, returning that count. Each iteration reads the next character, increments the counter, and breaks when the character is outside both the A-Z range (65..90) and the a-z range (97..122).
    // LOOP: Iterate over the characters of a1 from the start, reading one character into v3 and advancing the pointer each iteration. [source:raw]
    // GUARD: Break the loop when the current character v3 is outside both ASCII ranges A-Z (65..90) and a-z (97..122), ending the count at the first non-letter. [source:raw]
    // CALCULATION: Increment result once per alphabetical character consumed before the break. [source:raw]
    // RETURN: Return result, the number of leading alphabetical characters in a1. [function:0x00590616, source:raw]
    // CALL: Invoked by sub_58FF65, sub_5901F0 and sub_59045F, likely as a name/token length helper; the callers are not analyzed in this packet. [caller:0x0058FF65, caller:0x005901F0, caller:0x0059045F]

    // Conservative worker pseudocode:
    //   result = 0;
    //   while (true) {
    //     v3 = *a1++;
    //     if ((v3 < 65 || v3 > 90) && (v3 < 97 || v3 > 122)) break;
    //     result++;
    //   }
    //   return result;
    // UNRESOLVED: The purpose of the count (e.g. a name/token prefix length) is not derivable from this packet; callers sub_58FF65, sub_5901F0 and sub_59045F are not analyzed here.
    // UNRESOLVED: Owner object identity is not established by the packet.
}
