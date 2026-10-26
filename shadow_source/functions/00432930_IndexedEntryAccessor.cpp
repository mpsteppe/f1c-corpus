// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432930
// Canonical corpus name: IndexedEntryAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedEntryAccessor_00432930.c

void UnknownObject::IndexedEntryAccessor()
{
    // Bounds-checked indexed accessor structurally identical to IndexedListEntryAccessor (00432820) but reading a different container layout: the container reached through *this holds a linked-list head at +0x30 and an entry count at +0x3C. If index a2 is out of range the function returns 0; otherwise it walks the list from the head via next pointers at node+4 to the Nth node, then returns the first char* in the entry data (entry data pointer at node+0, first string at data+0). Null node, null entry data, or null first string return 0, except that a null string value falls back to the address of the global byte_5EA438. Invoked by ExtensionStripperForAllListEntries (0046f170).
    // GUARD: Bounds check: if a2 < 0 or a2 >= count at *(this)+0x3C, return 0. [field:this:0x00000000, field:obj:0x0000003C, source:raw]
    // ASSIGNMENT: Load the list head v3 from *(this)+0x30. [field:this:0x00000000, field:obj:0x00000030, source:raw]
    // LOOP: When a2 > 0, walk nodes via the next pointer at node+4, decrementing v2 until it reaches 0; a premature null node returns 0. [field:*(*(obj+0x30)+0x4):0x00000004, source:raw]
    // GUARD: After resolving the target node, a null node pointer v3 returns 0. [field:*(*(obj+0x30)+0x4):0x00000000, source:raw]
    // ASSIGNMENT: Load the entry data pointer v4 from node+0. [field:*(*(obj+0x30)+0x4):0x00000000, source:raw]
    // GUARD: A null entry data pointer v4 returns 0. [field:*(*(obj+0x30)+0x4):0x00000000, source:raw]
    // ASSIGNMENT: Read the first string result = *v4 from entry data+0. [field:*(*(*(obj+0x30)+0x4)+0x0):0x00000000, source:raw]
    // RETURN: Return the first string result, or fall back to the address of the global byte_5EA438 when result is null. [global:0x005EA438, source:raw]
    // RETURN: Return 0 for every rejected guard path (out-of-range, null node, null entry data). [source:raw]
    // CALL: Invoked by ExtensionStripperForAllListEntries (0046f170) to fetch a list entry string. [caller:0x0046F170, source:raw]

    // Conservative worker pseudocode:
    //   v2 = a2;
    //   if (a2 < 0 || a2 >= *(dword*)(*(dword*)this + 60)) return 0;
    //   v3 = *(dword*)(*(dword*)this + 48);
    //   if (a2 > 0) {
    //     while (v3) {
    //       v3 = *(dword*)(v3 + 4);
    //       if (--v2 <= 0) goto LABEL_6;
    //     }
    //     return 0;
    //   }
    //   LABEL_6:
    //   if (!v3) return 0;
    //   v4 = *(char***)v3;
    //   if (!v4) return 0;
    //   result = *v4;
    //   if (!result) return &byte_5EA438;
    //   return result;
    // UNRESOLVED: The semantic role of the returned char* (existing analysis suggests a directory/file path) is inferred from the caller and global, not established by this function.
    // UNRESOLVED: The container type behind *this and the meaning of the count at +0x3C are unnamed; layout is inferred from dereferences.
    // UNRESOLVED: byte_5EA438 is used as a default returned string; its content and purpose are unknown here.
    // UNRESOLVED: The container offsets (head at +0x30, count at +0x3C) differ from those of the sibling accessor at 00432820; whether these are two field groups of the same class or two different classes is unresolved.
}
