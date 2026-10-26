// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568910
// Canonical corpus name: sub_568910
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_568910_00568910.c

void UnknownObject::StringEscapeDecoderWithHex()
{
    // String decoder that expands '+~XX' hex-escape sequences while copying all other characters verbatim into an output buffer with a hard length cap. Null input or output pointer returns 0 immediately. The output buffer is reset to an empty string first, then a '+'-prefixed escape is recognized only when at least 4 input bytes remain, the following byte is '~' (126), and the two bytes after it are both valid hex digits; the two hex digits are parsed via StrlenFormatCallWrapper with a '%x' format and the decoded byte is appended. Every append is guarded by a buffer-overflow check against limit a3. Returns 1 on full decode of the input, 0 on null input or overflow. Called from file/path/player-name handling paths.
    // GUARD: Returns 0 immediately when either the input pointer a1 or the output pointer a2 is null [source:raw]
    // ASSIGNMENT: Initializes the output buffer to an empty string by writing 0 to its first byte (the packet maps this buffer head as field this+0x0) [field:this:0x00000000, source:raw]
    // LOOP: Main parse loop walks the input one character at a time until a null terminator is reached [source:raw]
    // GUARD: Escape-candidate test: the current character must equal 43 ('+') and at least 4 input bytes must remain, otherwise the byte is copied verbatim [source:raw]
    // GUARD: Escape-shape test: the byte after '+' must be 126 ('~') and both following bytes must be accepted by sub_589BC6 (hex-digit check); otherwise fall through to verbatim copy [callee:0x00589BC6, source:raw]
    // CALL: Parses the two escape hex digits with StrlenFormatCallWrapper using a '%x' format, producing the decoded byte into v12 [callee:0x005887ED, source:raw]
    // ASSIGNMENT: Stores the decoded byte v12 into the one-byte buffer v18 and advances the input pointer by 4 to consume the full '+~XX' escape [source:raw]
    // CALCULATION: Overflow guard before every append: if strlen(v18) plus strlen of the accumulated output reaches or exceeds the limit a3, the function returns 0 [source:raw]
    // CALL: Appends the decoded (or verbatim) byte v18 to the output buffer a2 via strcat [source:raw]
    // RETURN: Returns 1 once the null terminator of the input is reached; returns 0 on null input or buffer overflow [source:raw]
    // CALL: Consumed by string/path processing callers: DirectoryFileEnumerator (00431db0), PathDirectoryExtractionAndComparison (00433290), PlayerNameNeverUsedProfileNameUniquenessCheck (00469550), FileExtensionStripper (0047beb0) and PlayerFileInit (004b0540) [caller:0x00431DB0, caller:0x00433290, caller:0x00469550, caller:0x0047BEB0, caller:0x004B0540, source:raw]

    // Conservative worker pseudocode:
    //   if (!a1 || !a2) return 0;
    //   a2[0] = 0;
    //   while (c = *a1) {
    //     if (c == 43 && strlen(a1) >= 4 && a1[1] == 126 && ishex(a1[2]) && ishex(a1[3])) {
    //       StrlenFormatCallWrapper(&a1[2], "%x", &v12);
    //       byte = v12; a1 += 4;
    //     } else {
    //       byte = *a1++;
    //     }
    //     v18[0] = byte; v18[1] = 0;
    //     if (strlen(v18) + strlen(a2) >= a3) return 0;
    //     strcat(a2, v18);
    //   }
    //   return 1;
    // UNRESOLVED: Global asc_5E5234 is flagged by packet facts as read but never appears in the raw decompiled source; its DERIVED 'StringEncodingRef' label is unverifiable from this packet
    // UNRESOLVED: sub_589BC6's exact contract (hex-digit predicate) is a DERIVED interpretation from the surrounding '%x' parse, not independently evidenced
    // UNRESOLVED: StrlenFormatCallWrapper's full '%x' semantics and return convention are not resolvable from this packet
    // UNRESOLVED: The '+~XX' escape convention is inferred from the raw literals 43 and 126; no encoding-format documentation exists in this packet
}
