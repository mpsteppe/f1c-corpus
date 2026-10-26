// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0390
// Canonical corpus name: NameComparisonAt0x1b4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NameComparisonAt0x1b4_004b0390.c

void UnknownObject::PathLastBackslashExtractor()
{
    // Extracts the substring after the last backslash from the path string at this[109] (offset 0x1B4), falling back to the global byte_5EA438 when the field is null, copies it to a2 via sub_587DD0 with length limit a3-1, and null-terminates the copy. Always returns 1.
    // ASSIGNMENT: Load the source string pointer from this[109] (offset 0x1B4). [source:raw, field:this:0x000001B4]
    // ASSIGNMENT: Fall back to the global byte_5EA438 when the field pointer is null. [source:raw, global:0x005EA438]
    // CALCULATION: Advance a scan pointer to the end of the source string using strlen. [source:raw]
    // GUARD: Guard on the scan pointer being beyond the start of the string before scanning backward. [source:raw]
    // LOOP: Scan backward until the character equals the backslash literal 92 (0x5C), stopping when the scan pointer reaches the string start. [source:raw]
    // CALCULATION: Advance the pointer past the backslash so the copy starts at the filename component. [source:raw]
    // CALL: Call sub_587DD0 to copy from the extracted position into a2 with length limit a3 - 1. [callee:0x00587DD0]
    // ASSIGNMENT: Null-terminate the copied string at a2 + (a3 - 1). [source:raw]
    // RETURN: Return constant 1. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4B0390(char **this, char *out, int limit) {
    //     const char *src = this[109] ? (const char*)this[109] : (const char*)byte_5EA438;
    //     const char *p = &src[strlen(src)];
    //     if (p > src) {
    //       while (*p != 0x5C) { if (--p <= src) break; }
    //       ++p;
    //     }
    //     sub_587DD0(out, p, limit - 1);
    //     out[limit - 1] = 0;
    //     return 1;
    //   }
    // UNRESOLVED: Semantics of the length limit a3 and the copy primitive sub_587DD0 are not defined here.
    // UNRESOLVED: Content and role of the default-path global byte_5EA438 depend on its initializer elsewhere.
}
