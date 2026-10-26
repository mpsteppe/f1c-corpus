// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057CA10
// Canonical corpus name: sub_57CA10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57CA10_0057ca10.c

void UnknownObject::ParseConfigStringToOutputBuffer()
{
    // Parses a configuration/command string using two delimiter types into a 5-byte output record: copies the input string a1 into a local buffer, walks delimited segments via sub_5897CA using the primary delimiter byte_5C3F6C (bounded copies into v12 and v11 via sub_587DD0), then walks sub-segments with the secondary delimiter word_5BEB48, converting each segment to a byte via sub_587ECE. The word result is stored at a2 + 2 and the four byte results at a2 + 4 through a2 + 7. Returns 1 when every segment lookup succeeds; any null segment result returns 0 early.
    // ASSIGNMENT: NUL-terminate local buffer v13 and copy the input string a1 into it with strcpy. [function:0x0057CA10, source:raw]
    // CALL: Parse the first delimited segment of the copied string with sub_5897CA(v13, byte_5C3F6C), using the primary delimiter byte_5C3F6C. [callee:0x005897CA, global:0x005C3F6C, source:raw]
    // GUARD: When the first segment result is null, return 0 immediately. [source:raw]
    // CALL: Copy up to 0x1F characters of the first segment into v12 via sub_587DD0 and force v12[31] to NUL. [callee:0x00587DD0, source:raw]
    // CALL: Parse the next delimited segment with sub_5897CA(0, byte_5C3F6C); when it returns null, return 0 immediately. [callee:0x005897CA, global:0x005C3F6C, source:raw]
    // CALL: Copy up to 7 characters of the second segment into v11 via sub_587DD0 and force v11[7] to NUL. [callee:0x00587DD0, source:raw]
    // CALL: Parse the first sub-segment within v12 with sub_5897CA(v12, &word_5BEB48) using the secondary delimiter word_5BEB48; when null, return 0 immediately. [callee:0x005897CA, global:0x005BEB48, source:raw]
    // CALL: Convert the first sub-segment to a byte with sub_587ECE and retain it in v14. [callee:0x00587ECE, source:raw]
    // CALL: Parse a second sub-segment with sub_5897CA(0, &word_5BEB48); when null, return 0 immediately, then convert it to a byte with sub_587ECE into v10. [callee:0x005897CA, callee:0x00587ECE, global:0x005BEB48, source:raw]
    // CALL: Parse a third sub-segment with sub_5897CA(0, &word_5BEB48); when null, return 0 immediately, then convert it to a byte with sub_587ECE into v7. [callee:0x005897CA, callee:0x00587ECE, global:0x005BEB48, source:raw]
    // CALL: Parse a fourth sub-segment with sub_5897CA(0, &word_5BEB48); when null, return 0 immediately, then convert it to a byte with sub_587ECE for direct storage at a2 + 7. [callee:0x005897CA, callee:0x00587ECE, global:0x005BEB48, source:raw]
    // ASSIGNMENT: Write the parsed results into the output record: a word from sub_587ECE(v11) at a2 + 2, and bytes v14, v10, v7, and the a2 + 7 value at a2 + 4 through a2 + 7. [callee:0x00587ECE, source:raw]
    // RETURN: Return 1 when all segment lookups succeeded; return 0 on any null segment lookup. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_57CA10(const char *a1, int a2) {
    //     v13[0] = 0; strcpy(v13, a1);
    //     char *v2 = sub_5897CA(v13, byte_5C3F6C);
    //     if (!v2) return 0;
    //     v12[0] = 0; sub_587DD0(v12, v2, 0x1F); v12[31] = 0;
    //     char *v3 = sub_5897CA(0, byte_5C3F6C);
    //     if (!v3) return 0;
    //     v11[0] = 0; sub_587DD0(v11, v3, 7); v11[7] = 0;
    //     char *v4 = sub_5897CA(v12, &word_5BEB48); if (!v4) return 0; char v14 = sub_587ECE(v4);
    //     char *v5 = sub_5897CA(0, &word_5BEB48); if (!v5) return 0; char v10 = sub_587ECE(v5);
    //     char *v6 = sub_5897CA(0, &word_5BEB48); if (!v6) return 0; char v7 = sub_587ECE(v6);
    //     char *v8 = sub_5897CA(0, &word_5BEB48); if (!v8) return 0;
    //     *(_BYTE *)(a2 + 7) = sub_587ECE(v8);
    //     *(_BYTE *)(a2 + 4) = v14;
    //     *(_BYTE *)(a2 + 5) = v10;
    //     *(_BYTE *)(a2 + 6) = v7;
    //     *(_WORD *)(a2 + 2) = sub_587ECE(v11);
    //     return 1;
    //   }
    // UNRESOLVED: The exact semantics of sub_5897CA (delimited segment iteration), sub_587ECE (segment-to-byte conversion), and sub_587DD0 (bounded string copy) are inferred from usage, not independently evidenced.
    // UNRESOLVED: The layout and purpose of the 5-byte output record (word at a2 + 2, bytes at a2 + 4..a2 + 7) are unresolved; the config-parse interpretation is DERIVED from the fill.
    // UNRESOLVED: The delimiter values and formats behind byte_5C3F6C and word_5BEB48 are unresolved.
    // UNRESOLVED: No callers appear in the packet, so the invocation context and what consumes the parsed record are unknown.
}
