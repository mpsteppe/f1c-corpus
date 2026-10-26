// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B17F0
// Canonical corpus name: sub_4B17F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B17F0_004b17f0.c

void UnknownObject::NoPlayerStringFlagSetter()
{
    // Tests whether string a2 contains the literal at global aNoplayer via sub_566810 and, when the substring is found, sets the flag at this[4715] (offset 0x49AC) to 1. Returns the substring-search result.
    // CALL: Call sub_566810(a2, aNoplayer) to search a2 for the global literal string. [callee:0x00566810, global:0x005D2328]
    // GUARD: Guard on the search result being non-zero (substring found). [source:raw]
    // ASSIGNMENT: Set this[4715] (offset 0x49AC) to 1 when the guard passes. [source:raw, field:this:0x000049AC]
    // RETURN: Return the substring-search result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B17F0(int *this, const char *s) {
    //     int result = sub_566810(s, aNoplayer);
    //     if (result) this[4715] = 1;
    //     return result;
    //   }
    // UNRESOLVED: Contents of the global literal aNoplayer and the exact semantics of sub_566810 are not defined here.
    // UNRESOLVED: Meaning of the flag at offset 0x49AC depends on the enclosing object; the existing analysis suggests no-player mode.
}
