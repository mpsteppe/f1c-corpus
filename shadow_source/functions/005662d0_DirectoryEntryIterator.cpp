// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005662D0
// Canonical corpus name: DirectoryEntryIterator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectoryEntryIterator_005662d0.c

void UnknownObject::DirectoryEntryIterator()
{
    // Builds a full file path from a directory entry: concatenates the base directory string (entry data +0x144) with the entry name (+0x30) into a path buffer at object +0x10 using an overflow-checked formatter. When the normalize flag at object +0x218 is set, resolves/normalizes the path against an additional path string (object +0x210) via sub_566810 and advances to the end of the final name (handling a trailing backslash). Returns a pointer to the constructed path, or 0 when the enumeration node, entry data, or normalization result is missing.
    // GUARD: Return 0 when the current enumeration node pointer (object +0x8) is null. [field:obj:0x00000008, source:raw]
    // GUARD: Return 0 when the directory entry data pointer (node +0x0) is null. [field:*(obj+0x8):0x00000000, source:raw]
    // CALCULATION: Read the base directory string from the entry data at +0x144; fall back to the default application-directory global byte_5EA438 when it is null. [field:*(*(obj+0x8)+0x0):0x00000144, global:0x005EA438, source:raw]
    // CALL: Concatenate base directory and entry name (entry data +0x30) with the '%s%s' format string into the path buffer at object +0x10 via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005BE860, field:this:0x00000000, source:raw]
    // GUARD: If the normalize flag byte at object +0x218 is clear, return the pointer to the constructed path buffer at object +0x10. [field:obj:0x00000218, field:this:0x00000000, source:raw]
    // CALCULATION: Read the additional path/filter string from object +0x210; fall back to the default application-directory global byte_5EA438 when it is null. [field:obj:0x00000210, global:0x005EA438, source:raw]
    // CALL: Normalize/resolve the constructed path buffer against the additional path string via sub_566810. [callee:0x00566810, source:raw]
    // GUARD: Return 0 when the path normalization call returned a null pointer. [callee:0x00566810, source:raw]
    // CALCULATION: Advance past the appended additional path using strlen(additional path) + 1; include the trailing backslash byte (0x5C) when the character at that position equals 0x5C. [global:0x005EA438, field:obj:0x00000210, source:raw]
    // RETURN: Return a pointer to the final constructed path (or 0 on any failure path). [function:0x005662D0, source:raw]

    // Conservative worker pseudocode:
    //   node = *(*this + 8);
    //   if (!node || !*node) return 0;
    //   base = *(char**)(*node + 0x144); if (!base) base = byte_5EA438;
    //   StringFormatWithBufferOverflowCheck(*this + 0x10, "%s%s", base, (char*)*node + 0x30);
    //   if (!*(byte*)(*this + 0x218)) return *this + 0x10;
    //   extra = *(char**)(*this + 0x210); if (!extra) extra = byte_5EA438;
    //   out = sub_566810(*this + 0x10, extra); if (!out) return 0;
    //   len = strlen(*(char**)(*this + 0x210)) + 1;
    //   return out + len - 1 + (*(byte*)(out + len - 1) == 0x5C);
    // UNRESOLVED: Exact layout/meaning of the additional path at object +0x210 and the normalize flag at object +0x218 is not confirmed beyond path construction use.
    // UNRESOLVED: Relationship between this iterator and the Directory_Entry_Iterator ABI name (LEGACY) is unverified.
}
