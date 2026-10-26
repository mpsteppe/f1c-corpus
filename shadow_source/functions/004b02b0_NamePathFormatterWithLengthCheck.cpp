// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B02B0
// Canonical corpus name: NamePathFormatterWithLengthCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NamePathFormatterWithLengthCheck_004b02b0.c

void UnknownObject::NamePathFormatterWithLengthCheck()
{
    // Formats an output file path by appending a directory path (from the object field at byte offset 0x1F9C, or the default string byte_5EA438 when empty) and the ".bch" extension, stripping any existing extension first. Returns 0 on success and -1 on failure. Fails when the output buffer a2 is NULL, the size a3 is 0, or a3 is too small to hold the directory plus the extension; the fail path empties the buffer.
    // GUARD: Fail-fast guard: if a2 (output buffer) is NULL or a3 (buffer size) is 0, jump to the fail path (LABEL_13). [source:raw]
    // CALL: Calls PathTruncationUtility(a2, a3) to truncate the input path to fit the buffer limit; this path also reads the globals at 0x005D1FE8 (path length limit) and 0x005D1FEC (concatenation buffer). [callee:0x004B0220, global:0x005D1FE8, global:0x005D1FEC, source:raw]
    // ASSIGNMENT: v4 = this[2023] (byte offset 0x1F9C) as the directory path; when v4 is NULL it falls back to the default directory string byte_5EA438. [field:this:0x00001F9C, global:0x005EA438, source:raw]
    // GUARD: Guard: if a3 <= strlen(a2) + strlen(v4) (buffer too small to append the directory), jump to the fail path (LABEL_13). [source:raw]
    // CALL: strcat(a2, v4): appends the directory path onto the output buffer. [source:raw]
    // LOOP: v5 = &a2[strlen(a2)]; scans backward while *v5 != 46 ('.') and v5 > a2; on finding a dot it sets *v5 = 0, stripping the existing extension from the buffer. [source:raw]
    // GUARD: Guard: if a3 > strlen(a2) + 5 (enough room for the suffix), append strcat(a2, ".bch") and return 0; otherwise jump to the fail path. [source:raw]
    // RETURN: Fail path (LABEL_13): set *a2 = 0 and return -1; this is also the early exit for the NULL/zero-size guard. [source:raw]

    // Conservative worker pseudocode:
    //   if (!a2 || !a3) goto fail;
    //   PathTruncationUtility(a2, a3);
    //   dir = this[0x1F9C/4] ? this[0x1F9C/4] : byte_5EA438;
    //   if (a3 <= strlen(a2) + strlen(dir)) goto fail;
    //   strcat(a2, dir);
    //   p = &a2[strlen(a2)];
    //   while (p > a2 && *p != 46) --p;
    //   if (p > a2) *p = 0;
    //   if (a3 > strlen(a2) + 5) { strcat(a2, ".bch"); return 0; }
    //   fail: *a2 = 0; return -1;
    // UNRESOLVED: The exact roles of globals 0x005D1FE8 and 0x005D1FEC are not visible in the raw source of this function; they are read during the PathTruncationUtility call. The existing analysis labels them FilePath_MaxLen and PathConcatBuffer at DERIVED trust, which is not adopted here.
    // UNRESOLVED: The semantics of stripping the extension at the last '.' (ASCII 46) and the ".bch" extension are grounded in the raw source but the caller-facing meaning of the return values (0 / -1) beyond success/failure is an interpretation.
}
