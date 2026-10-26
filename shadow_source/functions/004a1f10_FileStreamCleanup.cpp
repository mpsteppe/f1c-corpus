// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1F10
// Canonical corpus name: FileStreamCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileStreamCleanup_004a1f10.c

void UnknownObject::FileStreamCleanup()
{
    // Runs a dual-path resource lookup three times: first and last against the global path token word_5C30B4, and in between against the custom path pointer at this[1] (this+0x4) when non-null, falling back to the global byte_5EA438 when it is NULL. Always returns 1.
    // CALL: First dual-path resource lookup against the global word_5C30B4 path token [callee:0x00566CF0, global:0x005C30B4, source:raw]
    // ASSIGNMENT: v3 = this[1]: load the custom path pointer from this+0x4 [field:this:0x00000004, source:raw]
    // GUARD: When v3 is NULL, substitute the global byte_5EA438 path pointer as the fallback [field:this:0x00000004, global:0x005EA438, source:raw]
    // CALL: Second dual-path resource lookup against the resolved path v3 (custom or fallback) [callee:0x00566CF0, field:this:0x00000004, global:0x005EA438, source:raw]
    // CALL: Third dual-path resource lookup against the global word_5C30B4 path token again [callee:0x00566CF0, global:0x005C30B4, source:raw]
    // RETURN: Always return 1 (success) regardless of lookup outcomes [function:0x004A1F10, source:raw]

    // Conservative worker pseudocode:
    //   ResourceLookupWithDualPath(&word_5C30B4);
    //   v3 = this[1];
    //   if (!v3) v3 = byte_5EA438;
    //   ResourceLookupWithDualPath(v3);
    //   ResourceLookupWithDualPath(&word_5C30B4);
    //   return 1;
    // UNRESOLVED: What word_5C30B4 and byte_5EA438 actually point to (file names vs directory paths) is not established here
    // UNRESOLVED: The function ignores a2, which is unused in the raw source despite being declared
    // UNRESOLVED: No static caller is recorded, so the role of the three lookups within a cleanup/teardown flow is inferred only from the canonical name
    // UNRESOLVED: The return value 1 is constant; the two lookup results are discarded
}
