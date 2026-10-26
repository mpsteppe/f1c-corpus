// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046E600
// Canonical corpus name: PathBuilderWithBackslash
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PathBuilderWithBackslash_0046e600.c

void UnknownObject::PathBuilderWithBackslash()
{
    // Builds a file path string. Allocates a 128-byte working buffer via OperatorNewNhMallocWrapper and clears it, obtains a base directory path from PathStringCombinator(dword_7C73E0) which is copied into the buffer via StringCopyWithBufferRealloc, and appends a backslash when the buffer does not already end with one (last character compared against 92). It then copies the object-name argument `this` into a 128-byte stack buffer (max 127 chars, NUL-terminated), sanitizes it with ReplaceSpecialCharsWithUnderscoreHyphen, and appends the name, the '.svm' extension, and the extra argument a2. Finally it frees the working buffer. Called by InitWithStackBuffer and ClearBufferAndInit.
    // ASSIGNMENT: Allocate a 128-byte working buffer via OperatorNewNhMallocWrapper and set its first byte to 0 (empty string). [callee:0x00587C03]
    // CALL: PathStringCombinator(dword_7C73E0) produces the base directory path from the module callback table. [callee:0x00432870, global:0x007C73E0]
    // CALL: StringCopyWithBufferRealloc(combined) copies the combined path into the working buffer; the returned pointer is discarded in the decompiled text. [callee:0x00566650]
    // CALCULATION: Compute v6 = strlen(source) + 1, using byte_5EA438 as the source when the buffer pointer is null. [global:0x005EA438]
    // GUARD: When the length is greater than 1 and the character at index v6 - 2 is not the backslash (92), append the backslash string word_5C2AAC via sub_5665B0. [global:0x005C2AAC, callee:0x005665B0]
    // CALL: sub_587DD0(v9, this, 127) copies the object-name argument into the 128-byte stack buffer v9 with a 127-char limit; v9[127] is forced to 0. [callee:0x00587DD0]
    // CALL: ReplaceSpecialCharsWithUnderscoreHyphen(v9) sanitizes the name buffer in place. [callee:0x00568560]
    // CALL: Append the sanitized name v9 to the path via sub_5665B0. [callee:0x005665B0]
    // CALL: Append the '.svm' extension aSvm to the path via sub_5665B0. [callee:0x005665B0, global:0x005C403C]
    // CALL: Append the extra parameter a2 to the path via sub_568620. [callee:0x00568620]
    // RETURN: When the working buffer is non-null, free it via FreeWrapper_7bcf. [callee:0x00587BCF]

    // Conservative worker pseudocode:
    //   char* sub_46E600(this, a2) {
    //     char* buf = OperatorNewNhMallocWrapper(128);
    //     *buf = 0;
    //     path = PathStringCombinator(dword_7C73E0);
    //     buf = StringCopyWithBufferRealloc(path); // assignment lost in decompiled text
    //     len = strlen(buf ? buf : byte_5EA438) + 1;
    //     if (len - 1 > 0 && buf[len - 2] != 92) sub_5665B0(&word_5C2AAC);
    //     char name[128];
    //     sub_587DD0(name, this, 127);
    //     name[127] = 0;
    //     ReplaceSpecialCharsWithUnderscoreHyphen(name);
    //     sub_5665B0(name);
    //     sub_5665B0(aSvm);
    //     sub_568620(a2);
    //     if (buf) return FreeWrapper_7bcf(buf);
    //     return buf;
    //   }
    // UNRESOLVED: The decompiled body discards the return of StringCopyWithBufferRealloc; the combined path text must reach the working buffer some other way, so the exact accumulation point is unresolved.
    // UNRESOLVED: The trailing-backslash check and the appends read and write a shared buffer whose final destination (the output path) is not visible in this function.
    // UNRESOLVED: `this` is used as a plain char* name argument here; the packet lists no typed fields for the object.
    // UNRESOLVED: The final return value is the FreeWrapper_7bcf result, which appears to be a decompiler artifact of freeing the temporary buffer rather than a meaningful path result.
}
