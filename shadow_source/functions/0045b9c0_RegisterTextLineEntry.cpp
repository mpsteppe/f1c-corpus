// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B9C0
// Canonical corpus name: UtilityFunction_b9c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_b9c0_0045b9c0.c

void UnknownObject::RegisterTextLineEntry()
{
    // Registers or reuses a fixed-size text-line record. Rejects empty keys (return 0). If the string already exists via StringArrayComparisonSearch, returns 1 without allocating. Otherwise finds a free record slot with RotatingIndexSearchWithThreshold against a5, resets the slot with PerIndexStructFieldResetter, copies the key with sub_587DD0(record+60, a2, 79), NUL-terminates the 79-byte string at record+139, and stores a5/a3/a4 into record+148/+140/+144. Returns 1 on success, 0 on empty input or no free slot. Structural twin of sub_45B5C0 (cluster-copied prelabel). On the frame path; invoked by TextLineWrappingAndRendering.
    // GUARD: If a2 is null or strlen(a2) == 0, return 0 without touching the pool [source:raw]
    // CALL: Dedup check: StringArrayComparisonSearch(this, a2); if it reports the string present, return 1 [callee:0x0045B480, source:raw]
    // CALL: Slot lookup: RotatingIndexSearchWithThreshold(this, a5) returns a slot index v7; if the index is negative, return 0 [callee:0x0045B500, source:raw]
    // CALL: PerIndexStructFieldResetter(v8, v7) resets the chosen slot's fields (receiver v8 is left uninitialized in the decompiled source) [callee:0x0045B430, source:raw]
    // ASSIGNMENT: Record pointer v10 = this + 92*v9, where v9 aliases the returned slot index v7 [source:raw]
    // CALL: String copy: sub_587DD0(v10 + 60, a2, 79) writes the key into the record at offset 60 with an explicit 79-byte length cap [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: NUL terminator for the capped string: byte v10[139] = 0 (the 79-byte field spans offsets 60..138, with offset 139 as its terminator byte) [source:raw]
    // ASSIGNMENT: Store parameters into the record: *(record + 148) = a5, *(record + 140) = a3, *(record + 144) = a4 [source:raw]
    // RETURN: Returns 1 after a successful registration [source:raw]
    // CALL: Invoked by TextLineWrappingAndRendering (0045BD10); on the frame path [caller:0x0045BD10, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2 || strlen(a2) == 0) return 0;
    //   if (StringArrayComparisonSearch(this, a2)) return 1;
    //   slot = RotatingIndexSearchWithThreshold(this, a5);
    //   if (slot < 0) return 0;
    //   PerIndexStructFieldResetter(??, slot);
    //   rec = this + 92*slot;
    //   Copy(rec + 60, a2, 79);
    //   rec[139] = 0;
    //   *(rec + 148) = a5; *(rec + 140) = a3; *(rec + 144) = a4;
    //   return 1;
    // UNRESOLVED: PerIndexStructFieldResetter receives an uninitialized first argument (v8); whether this is a decompiler artifact or a genuine quirk cannot be resolved from this packet
    // UNRESOLVED: The record stride (92) conflicts with fields stored at +140/+144/+148 unless the record is wider than 92 bytes, so the element layout is ambiguous
    // UNRESOLVED: The NUL byte at +139 overlaps the low byte of the a3 dword at +140, suggesting a packed string-plus-fields record whose exact layout is not defined here
    // UNRESOLVED: a3, a4, a5 field roles (value versus threshold) are inferred from call order only
}
