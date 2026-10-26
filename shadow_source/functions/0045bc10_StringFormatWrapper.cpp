// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BC10
// Canonical corpus name: StringFormatWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringFormatWrapper_0045bc10.c

void UnknownObject::StringFormatWrapper()
{
    // Formats a label prefix into a caller-provided buffer and forces null termination. If the prefix argument a1 is null, the global byte_5EA438 is substituted. Calls StringFormatProcessingWithNullTerm(a2, a3, "%s: ", prefix), forces the last byte of the buffer (a2 + a3 - 1) to 0, and returns true iff the format call returned non-negative.
    // ASSIGNMENT: Select the prefix source: a1 if non-null, otherwise the global byte_5EA438 placeholder. [global:0x005EA438, source:raw]
    // CALL: Call StringFormatProcessingWithNullTerm(a2, a3, "%s: ", prefix) to write the formatted prefix into the buffer. [callee:0x0058969D, global:0x005C5B60, source:raw]
    // ASSIGNMENT: Force the last byte of the buffer at a2 + a3 - 1 to 0, guaranteeing null termination. [source:raw]
    // RETURN: Return true iff the format call returned a non-negative value. [source:raw, function:0x0045BC10]

    // Conservative worker pseudocode:
    //   bool StringFormatWrapper(const char *prefix, int buf, int len) {
    //     const char *src = prefix ? prefix : byte_5EA438;
    //     int result = StringFormatProcessingWithNullTerm(buf, len, "%s: ", src);
    //     *(_BYTE *)(buf + len - 1) = 0;
    //     return result >= 0;
    //   }
    // UNRESOLVED: Contents of byte_5EA438 are unknown; it is only used as the null-prefix default.
    // UNRESOLVED: Buffer ownership and maximum length contract between a2/a3 and the forced termination byte are caller-imposed and not checked here.
}
