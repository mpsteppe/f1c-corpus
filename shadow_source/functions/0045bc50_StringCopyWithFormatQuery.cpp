// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BC50
// Canonical corpus name: StringCopyWithFormatQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyWithFormatQuery_0045bc50.c

void UnknownObject::StringCopyWithFormatQuery()
{
    // Builds a formatted string plus an appended suffix into a bounded destination buffer. When the suffix a2 is non-null and non-empty, the format string a1 is formatted into a local buffer via StringFormatWrapper, the suffix is appended, the combined text is copied into a3 with a bounded copy of a4 - 1 bytes via sub_587DD0, and a null terminator is forced at a3[a4 - 1]; the function returns 1. Otherwise the destination a3 is cleared to an empty string and the function returns 0.
    // GUARD: Branch on the suffix a2 being non-null and non-empty (strlen(a2) != 0); the else path clears the destination. [source:raw, abi:lead]
    // CALL: Call StringFormatWrapper(a1, v5, 512) to format the format string into the 512-byte local scratch buffer. [callee:0x0045BC10]
    // CALCULATION: Append the suffix a2 to the formatted text in the scratch buffer (strcat). [source:raw]
    // CALL: Call sub_587DD0(a3, v5, a4 - 1) to copy the combined text into the destination with a maximum length of a4 - 1 bytes. [callee:0x00587DD0]
    // ASSIGNMENT: Force a null terminator at the last destination slot a3[a4 - 1]. [source:raw]
    // RETURN: Return 1 on the successful build-and-copy path. [source:raw]
    // ASSIGNMENT: On the empty-suffix path, clear the destination's first byte (*a3 = 0). [source:raw]
    // RETURN: Return 0 when no suffix was supplied. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_45BC50(const char *fmt, const char *suffix, _BYTE *dest, int capacity) {
    //     if (suffix && strlen(suffix)) {
    //       char scratch[512];
    //       StringFormatWrapper(fmt, scratch, 512);
    //       strcat(scratch, suffix);
    //       sub_587DD0(dest, scratch, capacity - 1);
    //       dest[capacity - 1] = 0;
    //       return 1;
    //     }
    //     *dest = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Exact contract of sub_587DD0 (bounded copy length semantics and whether it always pads or truncates) is unproven.
    // UNRESOLVED: The scratch buffer is fixed at 512 bytes while the destination capacity a4 is caller-supplied; overflow interaction between the two is not handled here.
    // UNRESOLVED: Reason for the capacity - 1 bound (reserving one byte for the forced terminator) is inferred, not stated.
}
