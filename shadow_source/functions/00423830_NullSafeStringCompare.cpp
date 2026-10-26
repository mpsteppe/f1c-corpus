// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423830
// Canonical corpus name: sub_423830
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_423830_00423830.c

void UnknownObject::NullSafeStringCompare()
{
    // Null-safe string comparison: reads two char** slots, substitutes the fixed fallback string at byte_5EA438 for either null pointer, and returns the strcmp result of the two resolved strings. Structurally a twin of the null-safe pointer dereference at 00415c30 (prelabel cluster_copy), consistent with callers that compare name/settings strings that may be unset.
    // CALCULATION: Dereference the right char** argument slot to obtain the right string pointer. [source:raw, field:this:0x00000000]
    // GUARD: Guard on the right slot's string pointer being null. [source:raw]
    // CALCULATION: Dereference the left char** argument slot to obtain the left string pointer. [source:raw]
    // GUARD: Guard on the left slot's string pointer being null. [source:raw]
    // CALCULATION: For a null right string, use the fallback default string at byte_5EA438 instead. [source:raw, global:0x005EA438]
    // CALCULATION: For a null left string, use the fallback default string at byte_5EA438 instead. [source:raw, global:0x005EA438]
    // RETURN: Return the strcmp result of the left resolved string against the right resolved string. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_423830(const char **left_slot, const char **right_slot) {
    //     const char *right = *right_slot;
    //     if (!right) right = &byte_5EA438;
    //     const char *left = *left_slot;
    //     if (!left) left = &byte_5EA438;
    //     return strcmp(left, right);
    //   }
    // UNRESOLVED: Content and length of byte_5EA438 (the fallback string) are not established here.
    // UNRESOLVED: Why callers reach strings through char** indirection (shared/mutable slots) is not established by this function alone.
    // UNRESOLVED: strcmp itself is not present in the packet callee list; its identity is inferred from the raw source.
}
