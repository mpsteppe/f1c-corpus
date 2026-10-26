// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00422FD0
// Canonical corpus name: StringFormatReplaceOperation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringFormatReplaceOperation_00422fd0.c

void UnknownObject::StringFormatReplaceOperation()
{
    // Prepends a base directory path to the caller-supplied string a2, writing the composed path back into a2's buffer. The base path is read from this[32] (field offset 0x80); when that pointer is null it falls back to the global default path byte_5EA438. Returns 0 when a2 is null or when the resolved base path equals the default global byte_5EA438 (no replacement needed); otherwise formats the base path and the original string into a2 and returns 1. Called by FileLoadWithRetryLoop.
    // GUARD: Resolve base path: use this[32] (field offset 0x80) when non-null, otherwise fall back to the global default path byte_5EA438. [field:this:0x00000080, global:0x005EA438]
    // GUARD: Early-out guard: return 0 when a2 is null or when sub_588410 reports the resolved base path already equals the default global byte_5EA438 (string equality helper returns 0 on match). [callee:0x00588410, global:0x005EA438, source:raw]
    // CALL: Copy a2 into the 1024-byte local buffer v5 via strcpy, preserving the original string before it is overwritten. [source:raw]
    // CALL: Call StringFormatWithBufferOverflowCheck(a2, format, basePath, v5) to build the composed path into a2's buffer, using the format-specifier global aSS at 0x005BE860. [callee:0x0058815F, global:0x005BE860]
    // RETURN: Return 1 on success; the guard path above returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_422FD0(_DWORD* this, const char* a2, int a3) {
    //     const char* base = this[32] ? (const char*)this[32] : &byte_5EA438;
    //     if (!a2 || !sub_588410(base, &byte_5EA438)) return 0;
    //     char v5[1024]; strcpy(v5, a2);
    //     StringFormatWithBufferOverflowCheck(a2, aSS, base, v5);
    //     return 1;
    //   }
    // UNRESOLVED: Parameter a3 is present in the prototype but unused by the body; its role is unknown.
    // UNRESOLVED: The pairing of the format call with the global aSS (0x005BE860) as the "%s%s" literal is DERIVED from the raw source's inline format string.
    // UNRESOLVED: Whether the 1024-byte v5 copy preserves the original string for a caller contract or guards a fixed-size a2 constraint is not stated by the evidence.
}
