// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432650
// Canonical corpus name: StringCapitalizer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCapitalizer_00432650.c

void UnknownObject::StringCapitalizer()
{
    // In-place title-case conversion of a NUL-terminated byte string. Capitalizes the first character if it is lowercase (this[0] in 97..122, subtract 32), then walks from this[1] and, for each character, inspects the previous character: if the previous character is a non-letter (outside 'a'-'z' and 'A'-'Z') the current character is uppercased when lowercase, otherwise the current character is lowercased when uppercase. Other characters pass through unchanged. Returns the trailing NUL byte. Called by SettingsCopySetupFileCopy (00432220).
    // ASSIGNMENT: Read the first character v1 = *this. [field:this:0x00000000, source:raw]
    // GUARD: Guard 0: if *this (this+0x0) is >= 97 ('a') it may be a lowercase letter; combined with the upper bound 122 ('z') the first character is lowercase. [guard:0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Capitalize the first character in place: *this = v1 - 32 (ASCII case delta). [field:this:0x00000000, source:raw]
    // LOOP: Iterate from i = this + 1 while the current character (*i) is non-zero; the result value tracks the current character. [field:this:0x00000001, source:raw]
    // GUARD: Guards 1 and 2: read the previous character v4 = *(i - 1); it is a non-letter when v4 < 97 (not a lowercase letter) and v4 < 65 (not any letter), i.e. outside 'A'-'Z' and 'a'-'z'. [guard:1, guard:2, field:this:0x00000001, source:raw]
    // GUARD: Non-letter predecessor branch: if the current character *i is not in 97..122 ('a'-'z', lowercase) skip it; otherwise it is a lowercase letter to be capitalized. [field:this:0x00000001, source:raw]
    // ASSIGNMENT: Uppercase a lowercase current character: *i = v7 - 32. [field:this:0x00000001, source:raw]
    // GUARD: Letter predecessor branch: if the current character *i is not in 65..90 ('A'-'Z', uppercase) skip it; otherwise it is an uppercase letter to be decapitalized. [field:this:0x00000001, source:raw]
    // ASSIGNMENT: Lowercase an uppercase current character: *i = v5 + 32. [field:this:0x00000001, source:raw]
    // RETURN: Return the trailing NUL byte (result = this[1] initially, updated to *++i as the loop advances); the return value is not used for case conversion. [function:0x00432650, source:raw]

    // Conservative worker pseudocode:
    //   v1 = *this;
    //   if (v1 >= 97 && v1 <= 122)
    //       *this = v1 - 32;
    //   for (i = this + 1; *i; ++i) {
    //       v4 = *(i - 1);
    //       if ((v4 < 97 || v4 > 122) && (v4 < 65 || v4 > 90)) {
    //           v7 = *i;
    //           if (v7 >= 97 && v7 <= 122) *i = v7 - 32;
    //       } else {
    //           v5 = *i;
    //           if (v5 >= 65 && v5 <= 90) *i = v5 + 32;
    //       }
    //   }
    //   return result;
    // UNRESOLVED: Guard literals are ASCII constants from the raw source (97/'a', 122/'z', 65/'A', 90/'Z', delta 32); the case-mask reading (0x20) is not used because no such hex literal is evidenced in the packet.
    // UNRESOLVED: The caller context (SettingsCopySetupFileCopy 0x00432220) suggests the converted string is a settings or copy-file description, but no class ownership is evidenced.
    // UNRESOLVED: The guard table encodes the previous-character checks on the this+0x1 field representative; the loop actually reads *(i-1) relative to the cursor, which may be any position in the string.
    // UNRESOLVED: The return value (trailing NUL) is an artifact of the loop test, not a deliberate result contract.
}
