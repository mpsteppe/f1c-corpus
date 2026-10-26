// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568560
// Canonical corpus name: ReplaceSpecialCharsWithUnderscoreHyphen
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ReplaceSpecialCharsWithUnderscoreHyphen_00568560.c

void UnknownObject::ReplaceSpecialCharsWithUnderscoreHyphen()
{
    // Thiscall string sanitizer: walks the input string in place. First pass replaces path separator characters ('.', '/', '\') with underscore '_' (ASCII 95). Second pass replaces any character where StringPrefixPatternCheck returns nonzero with hyphen '-' (ASCII 45). Both passes are skipped when the string pointer or its first byte is null. Used by profile/path handling to sanitize strings for use as file or directory names.
    // GUARD: Guard on the this pointer: when it is null the function does nothing. [source:raw]
    // GUARD: Guard on the first byte of the string (field this+0x0): when it is NUL both iteration passes are skipped. [field:this:0x00000000, source:raw]
    // LOOP: First pass: do-while iteration over every character of the string from the first byte (field this+0x0) until the NUL terminator. [field:this:0x00000000, source:raw]
    // GUARD: Per-character guard (packet guard 0, this+0x0): character value >= 46 (0x2E) and (<= 47 or == 92), which selects '.' (46), '/' (47) and '\' (92). [guard:0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Replace the matched path separator character in-place with ASCII 95 ('_'). [field:this:0x00000000, source:raw]
    // LOOP: Second pass: do-while iteration over every character of the string from the first byte (field this+0x0) until the NUL terminator. [field:this:0x00000000, source:raw]
    // CALL: Call StringPrefixPatternCheck (0x005685B0) on the current character position; a nonzero return selects that character for hyphen replacement. [callee:0x005685B0, source:raw]
    // ASSIGNMENT: Replace the matched character in-place with ASCII 45 ('-'). [field:this:0x00000000, source:raw]
    // CALL: Called by ProfileAlreadyExistsPageHandler (0x0046CB50) and PathBuilderWithBackslash (0x0046E600) to sanitize strings into safe file/directory names. [caller:0x0046CB50, caller:0x0046E600, source:raw]

    // Conservative worker pseudocode:
    //   void sub_568560(char *s) {
    //     char *p;
    //     if (!s) return;
    //     if (*s) {
    //       p = s;
    //       do {
    //         if (*p >= 46 && (*p <= 47 || *p == 92)) *p = 95;
    //       } while (*++p);
    //     }
    //     if (*s) {
    //       p = s;
    //       do {
    //         if (StringPrefixPatternCheck(p)) *p = 45;
    //       } while (*++p);
    //     }
    //   }
    // UNRESOLVED: Semantics of StringPrefixPatternCheck (which prefix patterns select the hyphen replacement) are not present in this packet.
    // UNRESOLVED: The two passes can both act on the same character; the exact interplay between underscore and hyphen replacement is not resolved.
}
