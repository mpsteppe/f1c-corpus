// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040A680
// Canonical corpus name: FilePathListSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FilePathListSearch_0040a680.c

void UnknownObject::FilePathListSearch()
{
    // Searches a hybrid file-path list for an entry whose string matches a2. First checks eight fixed entries (slots at this+0x10, +0x14, +0x18, +0x1C and +0x24, +0x28, +0x2C, +0x30; index 4 is skipped), then walks a variable-length array whose base is this+0x20, byte stride 200, entry count this+0x38. Every entry is a small object whose path string is a pointer at object+4, defaulting to byte_5EA438 when null; sub_588410 returns 0 on a match, and the matching entry pointer is returned. Returns 0 when a2 is null or no entry matches.
    // GUARD: Null search-key guard: when a2 is null the function returns 0 without inspecting any entry [source:raw]
    // CALL: Fixed entries 0-3: for each of the entry pointers at this+0x10, this+0x14, this+0x18, this+0x1C, if non-null load its path string at +4 (falling back to byte_5EA438 when null) and test it against a2 with sub_588410; a zero return matches and yields the entry pointer as the result [callee:0x00588410, global:0x005EA438, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // CALL: Fixed entries 5-8 (slot index 4 is skipped): same per-entry test for the entry pointers at this+0x24, this+0x28, this+0x2C, this+0x30, each string at +4 defaulting to byte_5EA438, compared with sub_588410 [callee:0x00588410, global:0x005EA438, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // LOOP: Variable-length array scan: while the count this+0x38 is greater than 0 (packet guard), walk the array whose base is this+0x20 with byte stride 200; for each entry load its path string at +4 (fallback byte_5EA438), test with sub_588410, and on a match return base + 200 * index [callee:0x00588410, global:0x005EA438, field:this:0x00000020, field:this:0x00000038, guard:0, source:raw]
    // RETURN: No-match return: when a2 was null, the count this+0x38 was not greater than 0, or the loop ended without a match, the function returns 0 [source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return 0;
    //   for slot in {0x10, 0x14, 0x18, 0x1C, 0x24, 0x28, 0x2C, 0x30}:
    //     if (entry = *(this+slot)) {
    //       s = *(entry+4) ? *(entry+4) : byte_5EA438;
    //       if (sub_588410(s, a2) == 0) return entry;
    //     }
    //   idx = 0;
    //   while (idx < *(this+0x38)) {
    //     entry = *(this+0x20) + idx * 200;
    //     s = *(entry+4) ? *(entry+4) : byte_5EA438;
    //     if (sub_588410(s, a2) == 0) return entry;
    //     ++idx;
    //   }
    //   return 0;
    // UNRESOLVED: Field this+0x34 (dword index 13) is flagged by packet facts but never referenced in the raw decompiled source; its role (possibly a reserved or unused entry pointer) is unverifiable here
    // UNRESOLVED: The sub_588410 comparison semantics (0 meaning equal) are inferred from the branch usage only; the exact compare is not shown in this packet
    // UNRESOLVED: The variable-length array stride (200 bytes per entry) and the layout of the per-entry object (pointer at +4) are structural facts without field-level documentation
}
