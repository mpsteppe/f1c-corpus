// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004236F0
// Canonical corpus name: StringHashTokenParsing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringHashTokenParsing_004236f0.c

void UnknownObject::StringHashTokenParsing()
{
    // Parses quoted tokens from input string a1 into output buffers a2 and a3. Nullifies delimiter characters located by sub_587C20, returns -1 on a null or empty input, then when the period separator asc_5C30AC is present copies the first quoted substring into a2 and the following quoted substring into a3. Returns 0 on success.
    // GUARD: Return -1 immediately when the input string a1 is null. [source:raw]
    // ASSIGNMENT: Initialize the output indices v3 and v18 to 0. [source:raw]
    // CALL: Locate and nullify the delimiter characters in a1 via sub_587C20 using unk_5C30B8, word_5C30B4, and asc_5C30B0; each found position is set to 0. [callee:0x00587C20, global:0x005C30B8, global:0x005C30B4, global:0x005C30B0]
    // GUARD: Return -1 when a1 is empty (strlen == 0 after delimiter nullification). [source:raw]
    // ASSIGNMENT: Zero-initialize the output buffers a2 and a3 when each is non-null. [source:raw]
    // CALL: Find the period separator asc_5C30AC in a1 via sub_587C20; if not found, skip the entire token parse and return 0. [callee:0x00587C20, global:0x005C30AC]
    // GUARD: If the first character of a1 equals 34 (the '"' literal), parse the quoted content directly; otherwise scan ahead until a quote character is found. [guard:0, field:this:0x00000000]
    // LOOP: Copy the quoted content into a2: walk characters starting at the quote (offsets 0x1, 0x2, ...) until the closing quote or the separator position, then null-terminate a2. [field:this:0x00000001, field:this:0x00000002, source:raw]
    // LOOP: After the separator, scan up to a 256-byte window for the next quote and copy the following quoted content into a3, then null-terminate a3. [source:raw]
    // RETURN: Return 0 on successful token parse. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4236F0(const char *a1, _BYTE *a2, _BYTE *a3) {
    //     if (!a1) return -1;
    //     nullifyDelimiter(a1, &unk_5C30B8);
    //     nullifyDelimiter(a1, &word_5C30B4);
    //     nullifyDelimiter(a1, asc_5C30B0);
    //     if (!*a1) return -1;
    //     if (a2) *a2 = 0;
    //     if (a3) *a3 = 0;
    //     const char *sep = findChar(a1, asc_5C30AC);
    //     if (!sep) return 0;
    //     const char *p = a1;
    //     if (*p == '"') {
    //       copyQuoted(a1, sep, a2);
    //     } else {
    //       while (p != sep && *p != '"') ++p;
    //       copyQuoted(p, sep, a2);
    //     }
    //     copyQuotedAfter(sep, a3);
    //     return 0;
    //   }
    // UNRESOLVED: Whether the quote character 34 delimits both tokens or only the first is not established from this packet alone.
    // UNRESOLVED: The 256-byte window after the separator is an arbitrary bound; its semantic meaning (buffer size vs. scan limit) is unknown.
}
