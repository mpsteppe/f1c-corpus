// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A330
// Canonical corpus name: CharToIndexConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CharToIndexConversion_0049a330.c

void UnknownObject::CharToIndexConversion()
{
    // __stdcall helper that converts the first character of a string to an index: passes the string to sub_589901, then computes result = first_char - 65 ('A'). Returns -1 when result >= 0x1A (26), i.e. the first character is outside A-Z; otherwise returns the 0-based index (A -> 0, Z -> 25). Used by hash/resource lookup paths.
    // CALL: Call sub_589901 (0x00589901) with the string argument lpSrcStr before indexing; its purpose is unknown but it may validate or normalize the string. [callee:0x00589901, source:raw]
    // CALCULATION: Dereference the first character (byte at the string base, field this+0x0) and subtract 65 to form a candidate 0-based index. [field:this:0x00000000, source:raw]
    // GUARD: Guard on result >= 0x1A (26): when the first character is not an uppercase letter A-Z, return -1. [source:raw]
    // RETURN: Return -1 for an out-of-range (non A-Z) first character. [source:raw]
    // RETURN: Return the validated 0-based index (first_char - 65) for an A-Z character. [source:raw]
    // UNKNOWN: Called by HashTableSearch (0x0049A360), ResourceLookupOrCreate (0x0049A3B0) and sub_49A520 (0x0049A520), indicating a role in key/index derivation for hash or resource lookups. [caller:0x0049A360, caller:0x0049A3B0, caller:0x0049A520, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int CharToIndexConversion(LPCSTR s) {
    //     sub_589901(s);
    //     unsigned int idx = (unsigned char)s[0] - 65;
    //     if (idx >= 26) return (unsigned int)-1;
    //     return idx;
    //   }
    // UNRESOLVED: Purpose of sub_589901 is unknown; it may trim or check the string, but no evidence links it to the conversion.
    // UNRESOLVED: The first-character range A-Z and the use of the index by callers are inferred from the arithmetic, not confirmed by named fields.
    // UNRESOLVED: The packet base for the dereferenced byte is labelled 'this' although the function takes the string as its argument.
    // UNRESOLVED: The prelabel cluster name ConditionalFreeWithBit0Flag (00404f70) does not match the raw-source semantics and was not adopted.
}
