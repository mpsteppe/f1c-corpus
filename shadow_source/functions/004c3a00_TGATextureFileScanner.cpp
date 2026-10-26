// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C3A00
// Canonical corpus name: TGATextureFileScanner
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TGATextureFileScanner_004c3a00.c

void UnknownObject::TGATextureFileScanner()
{
    // TGA texture file scanner. Builds a scan filter from byte_5D3074 into FileName, uses the input path string *this (falling back to byte_5EA438 when null), sets up a directory scan (AllocateStructWithDefaultValues, sub_565EB0, sub_565F80, sub_566380), then iterates directory entries via DirectoryEntryIterator. For each entry it strips the directory and extension, resolves the base name against the requested path, and when it is a match allocates an 8-byte string node (OperatorNewNhMallocWrapper + StringCopyWithBufferRealloc) wrapped in a 12-byte list node that is either appended (exact path match) or prepended (other matches) into the caller result list a2 (a2[0]/a2[1]/a2[2] head/tail, a2[3] count). Returns LinkedListDestructorWithChildCleanup(v24).
    // CALL: AllocateStructWithDefaultValues(v24) initializes the directory-scan working structure. [callee:0x00565DC0, source:raw]
    // ASSIGNMENT: Copy the filter string byte_5D3074 into FileName until a NUL terminator. [global:0x005D3074, source:raw]
    // ASSIGNMENT: Base path: v5 = *this; when *this is null fall back to byte_5EA438, then strcpy into v31. [field:this:0x00000000, global:0x005EA438, source:raw]
    // CALCULATION: Strip the directory portion: from the end of v31 walk back to the last backslash (0x5C = 92), zeroing characters after it. [source:raw]
    // CALL: Configure the scan: sub_565EB0(v24), sub_565F80(FileName, 1, v31, 0) sets the filter, sub_566380(0) commits setup. [callee:0x00565EB0, callee:0x00565F80, callee:0x00566380, source:raw]
    // CALL: LinkedListPopFront_5f50(v24) pops the first directory entry. [callee:0x00565F50, source:raw]
    // LOOP: Iterate directory entries while DirectoryEntryIterator(v24) is non-null. [callee:0x005662D0, source:raw]
    // CALL: Per entry: ReversePathSearchForBackslashSeparator(v24) locates the filename, copied with sub_587DD0(v26, v8, 127); then strip extension by zeroing after the last period (0x2E = 46). [callee:0x00565EF0, callee:0x00587DD0, source:raw]
    // CALCULATION: Second pass: read the full entry again via DirectoryEntryIterator, copy with sub_587DD0(v29, v10, 511), strip trailing backslash-separated directory components, count backslashes to find the second-level path, and memmove the base name into v28. [callee:0x005662D0, callee:0x00587DD0, source:raw]
    // GUARD: Compare stripped base names: when sub_588410(v26, v28) reports a match the entry is skipped (goes to LABEL_54). [callee:0x00588410, source:raw]
    // CALL: Match handling: allocate an 8-byte node with OperatorNewNhMallocWrapper(8), initialize it, copy the entry string with StringCopyWithBufferRealloc(v19), wrap it in a 12-byte list node and link into the caller result list a2. [callee:0x00587C03, callee:0x00566650, source:raw]
    // CALL: Path-match priority: sub_566810(v29, v31) resolves the matched path; exact matches append (goto LABEL_53 after tail link), other matches prepend into the head; on every success increment a2[3] (count). [callee:0x00566810, source:raw]
    // CALL: End of each iteration: LinkedListNodePeek(v24). [callee:0x00565F20, source:raw]
    // RETURN: Return LinkedListDestructorWithChildCleanup(v24), tearing down the scan structure and children. [callee:0x00565E20, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C3A00(const char** this, _DWORD* result) {
    //     char FileName[32]; char dir[512]; char base[128]; char full[511]; char scan[4];
    //     AllocateStructWithDefaultValues(scan);
    //     int i = 0; do { FileName[i] = byte_5D3074[i]; } while (byte_5D3074[i++]);
    //     const char* p = *this ? *this : byte_5EA438; strcpy(dir, p);
    //     // strip trailing path segment after last backslash
    //     sub_565EB0(scan); sub_565F80(FileName, 1, dir, 0); sub_566380(0);
    //     LinkedListPopFront_5f50(scan);
    //     while (DirectoryEntryIterator(scan)) {
    //       const char* e = ReversePathSearchForBackslashSeparator(scan);
    //       sub_587DD0(base, e, 127); base[127] = 0; strip_extension(base);
    //       const char* f = DirectoryEntryIterator(scan); sub_587DD0(full, f, 511); full[511] = 0;
    //       // strip dirs, shift base-name fragment into v28
    //       if (sub_588410(base, v28)) continue;
    //       _DWORD* node = OperatorNewNhMallocWrapper(8);
    //       if (node) { node[0] = 0; node[1] = -1; StringCopyWithBufferRealloc(DirectoryEntryIterator(scan)); }
    //       int matched = sub_566810(full, dir);
    //       if (!matched || sub_588410(matched, dir)) { if (node) link_tail(result, node); }
    //       else if (node) { link_head(result, node); }
    //       LinkedListNodePeek(scan);
    //     }
    //     return LinkedListDestructorWithChildCleanup(scan);
    //   }
    // UNRESOLVED: Exact semantics of the directory-scan helpers sub_565EB0, sub_565F80, sub_566380, sub_566810 and the entry-iterator pair (sub_565EF0 vs sub_565F20 vs sub_565F50) are not established beyond their call-site roles.
    // UNRESOLVED: The result list a2 is treated as a 4-dword head/tail/tail2/count structure (a2[0..3]); its concrete type and ownership are unverified.
    // UNRESOLVED: The byte_5D3074 filter content is read as a string (existing analysis labels it the "*.tga" filter, DERIVED); its bytes are not confirmed here.
    // UNRESOLVED: Single caller FileINILoader (004c38d0) recorded; frame-path membership unknown.
}
