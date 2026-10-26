// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004874E0
// Canonical corpus name: UIValueValidator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIValueValidator_004874e0.c

void UnknownObject::UIValueValidator()
{
    // UI value validator with multiple early-exit guards: returns 0 if ByteFieldGetterAt100(this) is nonzero; returns 1 if the byte at v1+225 is zero; loads a string pointer at v1+160 (falling back to global byte_5EA438 when null), normalizes it via StringNormalizeLookup_a460, returns 1 if the normalization yields null, and finally returns 0 if the normalized string is empty else 1.
    // GUARD: If ByteFieldGetterAt100(this) is nonzero, return 0 immediately (validation fails) [callee:0x00486710, source:raw]
    // GUARD: If byte at v1+225 is zero, return 1 immediately (validation passes) [source:raw]
    // ASSIGNMENT: Load string pointer at v1+160; substitute global byte_5EA438 when the pointer is null [global:0x005EA438, source:raw]
    // CALL: Normalize/lookup the string via StringNormalizeLookup_a460(v3) [callee:0x0049A460, source:raw]
    // GUARD: If the normalized string is null, return 1 (validation passes) [callee:0x0049A460, source:raw]
    // GUARD: If the normalized string length is non-zero, return 1; otherwise return 0 [callee:0x0049A460, source:raw]
    // RETURN: Return the final validation result (0 for empty normalized string, 1 otherwise) [function:0x004874E0, source:raw]

    // Conservative worker pseudocode:
    //   int UIValueValidator(this) {
    //     if (ByteFieldGetterAt100(this))
    //       return 0;
    //     if (!*(char*)(this + 225))
    //       return 1;
    //     const char* raw = *(const char**)(this + 160);
    //     if (!raw) raw = (const char*)byte_5EA438;
    //     const char* norm = StringNormalizeLookup_a460(raw);
    //     if (!norm)
    //       return 1;
    //     return strlen(norm) ? 1 : 0;
    //   }
    // UNRESOLVED: Fields at v1+225 and v1+160 are not modeled as field evidence in the packet; their role is inferred from the source text only
    // UNRESOLVED: Exact mapping of the 0/1 result to valid/invalid UI states is not established
    // UNRESOLVED: StringNormalizeLookup_a460 transform on the string is unknown
    // UNRESOLVED: ByteFieldGetterAt100 reads an unmodeled field on this object
}
