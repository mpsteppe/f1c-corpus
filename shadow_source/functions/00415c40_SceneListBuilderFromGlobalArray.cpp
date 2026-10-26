// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00415C40
// Canonical corpus name: SceneListBuilderFromGlobalArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneListBuilderFromGlobalArray_00415c40.c

void UnknownObject::SceneListBuilderFromGlobalArray()
{
    // Rebuilds a linked list of 92-byte scene entries. First frees any existing list whose head is stored at this+0x20, freeing each node (and calling ShortComputation_8cf0(1) when a node has its flag byte at +8 set and a nonzero first dword), then zeroes the four list pointers/counter fields (offsets 0x20, 0x24, 0x28, 0x2C). If the scene count dword_8AC488 is not positive, returns 1. Otherwise, for each of dword_8AC488 entries it allocates a 92-byte node, sets the first dword to 0 and the second to -1, initializes two 5-dword sub-structs at node+12 and node+52 via SmallEntryStructInit, initializes the text-format block via TextFormatStructInitializer_4fe0, calls StringCopyWithBufferRealloc on the source record (global dword_8AC490 with a per-entry stride of 396 plus an offset of 260), stores the entry index at node+8, builds commentary TV/PWS paths via CommentaryTVPWSPathBuilder, then allocates a 12-byte wrapper (fields: node pointer, 0, flag 1) and appends it to the list, updating head this+0x20, tail this+0x24, first-insert this+0x28 and count this+0x2C. Returns 0.
    // LOOP: Traverse the existing scene list starting from the head stored at this[8] (offset 0x20), following the next-pointer at node+4 until null. [field:this:0x00000020, source:raw]
    // CALCULATION: For each visited node read the flag byte at node+8 and the next-pointer at node+4, advancing the traversal. [source:raw]
    // GUARD: If a node's flag byte at node+8 is nonzero and its first dword is nonzero, call ShortComputation_8cf0(1). [callee:0x00418CF0, source:raw]
    // CALL: Call FreeWrapper_7bcf(node) to free each node during cleanup. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list head this[8] (offset 0x20), tail this[9] (offset 0x24), first-insert this[10] (offset 0x28) and count this[11] (offset 0x2C) after cleanup. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // GUARD: If the scene entry count dword_8AC488 is <= 0, return 1 without rebuilding. [global:0x008AC488, source:raw]
    // LOOP: Iterate once per scene entry, from index 0 until the index reaches dword_8AC488. [global:0x008AC488, source:raw]
    // CALL: Call OperatorNewNhMallocWrapper(92) to allocate a 92-byte scene entry node. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: If the allocation succeeded, set node[0] to 0 and node[1] to -1. [source:raw]
    // LOOP: Initialize two 5-dword sub-structs starting at node+12 (v6+3) via SmallEntryStructInit, advancing by 5 dwords each. [callee:0x00415520, source:raw]
    // LOOP: Initialize two 5-dword sub-structs starting at node+52 via SmallEntryStructInit, advancing by 5 dwords each. [callee:0x00415520, source:raw]
    // CALL: Call TextFormatStructInitializer_4fe0(node) to initialize the text-format block of the node. [callee:0x00414FE0, source:raw]
    // CALL: Call StringCopyWithBufferRealloc on the source record address computed as (running per-entry offset v15 + dword_8AC490 + 260). [callee:0x00566650, global:0x008AC490, source:raw]
    // ASSIGNMENT: Store the running entry index into node+8. [source:raw]
    // CALL: Call CommentaryTVPWSPathBuilder(node) to build track TV/PWS commentary paths for the entry. [callee:0x00414E60, source:raw]
    // CALL: Call OperatorNewNhMallocWrapper(12) to allocate the 12-byte list wrapper node. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: If the wrapper allocation succeeded, set wrapper[0] to the scene node, wrapper[1] to 0 and the byte flag wrapper[2] to 1. [source:raw]
    // ASSIGNMENT: Append the wrapper to the list: if head this[8] (offset 0x20) is set, write it into the next-pointer slot at *(this+0x24)+4 of the tail node; otherwise set head this[8] and first-insert this[10] (offset 0x28) to the wrapper. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:*(this+0x24):0x00000004]
    // ASSIGNMENT: Update tail this[9] (offset 0x24) to the new wrapper, increment the count this[11] (offset 0x2C), advance the entry index and add 396 to the running per-entry offset v15. [field:this:0x00000024, field:this:0x0000002C, global:0x008AC490, source:raw]
    // RETURN: Return 0 on successful rebuild of the scene list. [source:raw]

    // Conservative worker pseudocode:
    //   int SceneListBuilderFromGlobalArray(void *this) {
    //     int node = ((DWORD *)this)[8];  // list head, offset 0x20
    //     while (node) {
    //       int cur = node;
    //       char flag = *(BYTE *)(node + 8);
    //       node = *(DWORD *)(node + 4);
    //       if (flag && *(DWORD *)cur) ShortComputation_8cf0(1);
    //       FreeWrapper_7bcf(cur);
    //     }
    //     ((DWORD *)this)[8] = 0;   // offset 0x20
    //     ((DWORD *)this)[9] = 0;   // offset 0x24
    //     ((DWORD *)this)[10] = 0;  // offset 0x28
    //     ((DWORD *)this)[11] = 0;  // offset 0x2C
    //     int count = dword_8AC488;
    //     if (count <= 0) return 1;
    //     int index = 0, stride = 0;
    //     do {
    //       int entry = (int)OperatorNewNhMallocWrapper(92);
    //       if (entry) {
    //         *(DWORD *)entry = 0;
    //         *(DWORD *)(entry + 4) = -1;
    //         int *sub = (int *)(entry + 12);
    //         for (int i = 2; i; --i) { SmallEntryStructInit(sub); sub += 5; }
    //         sub = (int *)(entry + 52);
    //         for (int i = 2; i; --i) { SmallEntryStructInit(sub); sub += 5; }
    //         TextFormatStructInitializer_4fe0((void *)entry);
    //       }
    //       StringCopyWithBufferRealloc(stride + dword_8AC490 + 260);
    //       *(DWORD *)(entry + 8) = index;
    //       CommentaryTVPWSPathBuilder((const char **)entry);
    //       int wrap = (int)OperatorNewNhMallocWrapper(12);
    //       if (wrap) { *(DWORD *)wrap = entry; *(DWORD *)(wrap + 4) = 0; *(BYTE *)(wrap + 8) = 1; }
    //       if (((DWORD *)this)[8]) *(DWORD *)(((DWORD *)this)[9] + 4) = wrap;
    //       else { ((DWORD *)this)[8] = wrap; ((DWORD *)this)[10] = wrap; }
    //       ((DWORD *)this)[9] = wrap;
    //       ++index;
    //       ((DWORD *)this)[11] = index;
    //       stride += 396;
    //     } while (index < count);
    //     return 0;
    //   }
    // UNRESOLVED: The scene entry node layout (92-byte record: two 5-dword sub-structs, entry index at node+8, text-format block) is derived from the allocation and initialization calls only; the concrete type names are not established.
    // UNRESOLVED: The 396-byte stride and the +260 string-copy target imply dword_8AC490 points to an array of fixed-size scene records, but the record layout is not confirmed by this packet alone.
    // UNRESOLVED: The purpose of the ShortComputation_8cf0(1) call during cleanup (node flag byte at +8 set and first dword nonzero) is unknown.
    // UNRESOLVED: StringCopyWithBufferRealloc is called with a computed address rather than a buffer base; whether it copies into the global array or into the new node is unresolved.
}
