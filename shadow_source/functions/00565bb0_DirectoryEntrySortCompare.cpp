// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565BB0
// Canonical corpus name: sub_565BB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_565BB0_00565bb0.c

void UnknownObject::DirectoryEntrySortCompare()
{
    // Sort comparator for two directory-entry objects (this vs a2). Reads a sort-mode selector from the type object at [*this]+544 (0x220): mode 1 returns true when strcmp(this+48, a2+48) > 0, mode 2 returns true when CompareFileTime(this+24, a2+24) > 0, mode 3 returns true when CompareFileTime(this+24, a2+24) < 0, and the default mode returns true when strcmp(this+48, a2+48) < 0. String fields are compared at byte offset 48; file times are compared at byte offset 24 via the imported CompareFileTime.
    // GUARD: Switch on the sort-mode selector read as *(DWORD*)(*(DWORD*)this + 544): dereference the type pointer at this+0x0 then read the selector 544 bytes (0x220) into the pointed-to object [field:this:0x00000000, field:obj:0x00000220, source:raw]
    // RETURN: Mode 1 (alphabetical): v4 = strcmp((char*)this+48, (char*)a2+48); return true iff v4 > 0 (this name lexicographically greater), expressed via the signum idiom -(v4<0) - ((v4<0)-1) > 0 [source:raw]
    // RETURN: Mode 2 (file time): return CompareFileTime((FILETIME*)this+3, (FILETIME*)(a2+24)) > 0; both operands read the 8-byte FILETIME at byte offset 24 [global:0x0059E214, source:raw]
    // RETURN: Mode 3 (file time): return CompareFileTime((FILETIME*)this+3, (FILETIME*)(a2+24)) < 0; inverse comparison of the same byte-offset-24 file times [global:0x0059E214, source:raw]
    // RETURN: Default mode (alphabetical): v2 = strcmp((char*)this+48, (char*)a2+48); return true iff v2 < 0 (this name lexicographically smaller) [source:raw]
    // CALL: Invoked as a sort comparator by sub_566380 (00566380) and sub_5664A0 (005664A0) to order directory entries [caller:0x00566380, caller:0x005664A0]

    // Conservative worker pseudocode:
    //   switch (*(DWORD*)(*(DWORD*)this + 544)) {
    //     case 1: return strcmp((char*)this+48, (char*)a2+48) > 0;
    //     case 2: return CompareFileTime((FILETIME*)this+3, (FILETIME*)(a2+24)) > 0;
    //     case 3: return CompareFileTime((FILETIME*)this+3, (FILETIME*)(a2+24)) < 0;
    //     default: return strcmp((char*)this+48, (char*)a2+48) < 0;
    //   }
    // UNRESOLVED: Whether 'true' means this sorts before or after a2 is not proven; the predicate math says mode 1 is greater-than and default is less-than, which is the reverse of the ascending/descending labels in the existing skeleton fill
    // UNRESOLVED: strcmp is referenced in the raw source but is not listed as a callee in the packet; treated as an intrinsic/inlined call
    // UNRESOLVED: The directory-entry object type and the meaning of the sort-mode values are inferred only (DERIVED), not confirmed
}
