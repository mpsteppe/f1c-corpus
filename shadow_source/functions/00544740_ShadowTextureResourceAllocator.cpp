// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00544740
// Canonical corpus name: sub_544740
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_544740_00544740.c

void UnknownObject::ShadowTextureResourceAllocator()
{
    // Manages the lifecycle of a shadow-texture resource array on this: destroys existing items before reallocation, allocates a 96-byte-per-item array (leading dword count header) via the malloc wrapper, names each item "SHADOWTEXnnn" and creates its texture surface, submits the finished array to the renderer, and then drains two dependent-object priority queues plus a flag-check list. A 0x100000 flag at this+0xEC marks whether the shadow resources are currently loaded; allocation only runs when the flag is clear and the requested count at this+0x158 is positive.
    // GUARD: Deallocation gate: the teardown block runs only when the field getter StructFieldGetter on global dword_8B78A0 is non-null AND flag bit 0x100000 of this+0xEC is set; the later (re)allocation block only runs while that bit is clear [field:this:0x000000EC, global:0x008B78A0, callee:0x0055C9B0, source:raw]
    // GUARD: guard:0 — allocation count this+0x158 (this[86]) must be greater than 0; when it is <= 0 the whole shadow-map allocation block is skipped to LABEL_54 [guard:0, field:this:0x00000158, source:raw]
    // GUARD: guard:1 — when a previous allocation exists (item count this+0x160, this[88], is > 0) each 96-byte item of the array at this+0x164 is destructed before reallocation [guard:1, field:this:0x00000160, field:this:0x00000164, source:raw]
    // LOOP: Destruct every previously allocated item: DestructorWithConditionalFreeFlagClear strides 96 bytes over this[88] items starting at the array base this[89] (this+0x164) [callee:0x005502C0, field:this:0x00000164, field:this:0x00000160, source:raw]
    // CALL: Teardown: DoublyLinkedListNodeRemovalWithArrayCleanup(this[89]) removes the array node, item count this[88] and array pointer this[89] are zeroed, SubBufferFree(dword_8B78A0) releases the dword_8B78A0 sub-buffer, and flag bit 0x100000 of this+0xEC is cleared [callee:0x005478B0, callee:0x00541420, global:0x008B78A0, field:this:0x00000160, field:this:0x00000164, field:this:0x000000EC, source:raw]
    // CALL: EmptyStub_c440(this) is invoked on the allocation path; its body contributes no observable operation in this function [callee:0x0055C440, source:raw]
    // ASSIGNMENT: Allocation count selection: when the StructFieldGetter on dword_8B78A0 is non-null the count is this+0x158 (this[86]) and its saved copy v31 is kept; otherwise a fallback count of 1 is used (still gated on this[86] > 0) [global:0x008B78A0, callee:0x0055C9B0, field:this:0x00000158, source:raw]
    // STATE_TRANSITION: Release one of the two prior stream handles before allocating: if dword_8B8DBC is non-zero it is cleaned by sub_542E50, emptied by EmptyStub_7470, freed by FreeWrapper_7bcf and nulled; else the same is done to dword_8B8DC0 [global:0x008B8DBC, global:0x008B8DC0, callee:0x00542E50, callee:0x00557470, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Array allocation: OperatorNewNhMallocWrapper(96 * count + 4) reserves a count-header dword plus count items of 96 bytes; the header stores the count, each item is zero-filled via StructInitWithZeroFill (24-dword step), and the item base is stored at this+0x164 (this[89]) [callee:0x00587C03, callee:0x0054FE10, field:this:0x00000164, source:raw]
    // LOOP: Per-item naming: StringFormatWithBufferOverflowCheck fills v32 with "SHADOWTEX%.3d" from global format string aShadowtex3d (0x005DBE0C), then sub_54FE50 queries the formatted name; a non-zero result aborts the item loop [callee:0x0058815F, callee:0x0054FE50, global:0x005DBE0C, source:raw]
    // CALL: Texture-surface creation: UtilityFunction_2950 initializes the item's surface pointer (item + 84) with dword_8B8DF4 (twice), dword_8B8DF8 and flag literal 262152; on failure the created items 0..i-1 are destructed by DestructorWithConditionalFreeFlagClear, the array node is removed by DoublyLinkedListNodeRemovalWithArrayCleanup and the array pointer is nulled (LABEL_45) [callee:0x00542950, global:0x008B8DF4, global:0x008B8DF8, callee:0x005502C0, callee:0x005478B0, field:this:0x00000164, source:raw]
    // CALL: After each surface is created, sub_5435C0 sets its fill/clear color to 16711935 (0xFF00FF magenta); the loop then advances the index and the 96-byte stride, continuing until the count is reached [callee:0x005435C0, source:raw]
    // LOOP: Duplicate-name abort path: items 0..i-1 are destructed by DestructorWithConditionalFreeFlagClear, the count header is read back from array-4, the array is walked backward 96 bytes per item calling EmptyStub_7470 on each, the whole block is freed with FreeWrapper_7bcf, and this+0x164 is nulled [callee:0x005502C0, callee:0x00557470, callee:0x00587BCF, field:this:0x00000164, source:raw]
    // CALL: Render submission: sub_547860(this[89]) hands the finished shadow-texture array to the renderer, then TextureSurfaceAllocation(dword_8B78A0, 2048) creates the texture surface; on failure the items are destructed, the array node removed and this+0x164 nulled [callee:0x00547860, callee:0x00541340, global:0x008B78A0, callee:0x005502C0, callee:0x005478B0, field:this:0x00000164, source:raw]
    // ASSIGNMENT: Commit: when the array survived, item count this+0x160 (this[88]) is set to the allocation count and flag bit 0x100000 of this+0xEC is set, marking shadow resources loaded [field:this:0x00000160, field:this:0x000000EC, source:raw]
    // LOOP: First dependent-object queue: from the list head this+0x100 follow each node's +260 next pointer; for a node with a non-zero +236 sub-pointer, PriorityQueueRecursiveProcess(sub, 0) is called and the function returns -1 the moment it reports non-zero (otherwise descend +76 and retry) [field:this:0x00000100, callee:0x00544DB0, source:raw]
    // LOOP: Second dependent-object queue: from the list head this+0x108 apply the same PriorityQueueRecursiveProcess walk with +76 descent and +260 list advance, returning -1 on the first non-zero result [field:this:0x00000108, callee:0x00544DB0, source:raw]
    // LOOP: Flag-check list: walk the list headed at this+0x148, following the +104 next pointer of each node, and call FlagCheckWithConditionalPathDispatch on every node [field:this:0x00000148, callee:0x005575F0, source:raw]
    // RETURN: Returns 0 after both dependent-object queues and the flag-check list are drained; returns -1 when a priority-queue node reports failure. The function is invoked by sub_53EB70 (0x0053EB70) and VertexBufferResourceAllocation (0x00543FA0) [function:0x00544740, caller:0x0053EB70, caller:0x00543FA0, source:raw]

    // Conservative worker pseudocode:
    //   if (StructFieldGetter(dword_8B78A0) && (this[59] & 0x100000)) {
    //       if (this[88] > 0) {
    //           for (i = 0; i < this[88]; ++i) DestructorWithConditionalFreeFlagClear(this[89] + i*96);
    //           DoublyLinkedListNodeRemovalWithArrayCleanup(this[89]);
    //           this[88] = 0; this[89] = 0;
    //           SubBufferFree(dword_8B78A0);
    //       }
    //       this[59] &= ~0x100000;
    //   }
    //   EmptyStub_c440(this);
    //   if (!(this[59] & 0x100000) && this[86] > 0) {
    //       count = StructFieldGetter(dword_8B78A0) ? this[86] : 1;
    //       free prior handle dword_8B8DBC else dword_8B8DC0 (sub_542E50, EmptyStub_7470, FreeWrapper_7bcf, null);
    //       block = OperatorNewNhMallocWrapper(96*count + 4);
    //       if (block) { block[0] = count; zero-fill each 96-byte item via StructInitWithZeroFill; this[89] = block+1; }
    //       for (i = 0; i < count; ++i) {
    //           StringFormatWithBufferOverflowCheck(buf, "SHADOWTEX%.3d", i);
    //           if (sub_54FE50(buf)) { destruct 0..i-1; backward free block; this[89] = 0; break; }
    //           if (UtilityFunction_2950(item+84, dword_8B8DF4, dword_8B8DF4, dword_8B8DF8, 262152)) {
    //               destruct 0..i-1; DoublyLinkedListNodeRemovalWithArrayCleanup(this[89]); this[89] = 0; break;
    //           }
    //           sub_5435C0(item+84, 16711935);
    //       }
    //       if (this[89]) {
    //           sub_547860(this[89]);
    //           if (TextureSurfaceAllocation(dword_8B78A0, 2048)) { destruct all; DoublyLinkedListNodeRemovalWithArrayCleanup(this[89]); this[89] = 0; }
    //           if (this[89]) { this[88] = count; this[59] |= 0x100000; }
    //       }
    //   }
    //   drain dependent queue 1 (this[64], PriorityQueueRecursiveProcess) else return -1;
    //   drain dependent queue 2 (this[66], PriorityQueueRecursiveProcess) else return -1;
    //   for (i = this[82]; i; i = *(i + 104)) FlagCheckWithConditionalPathDispatch(i);
    //   return 0;
    // UNRESOLVED: Four dereferenced-field facts from the deterministic store are not visible in the raw decompiled text of this function: *(*(this+0x1EC)+0x4C), *(this+0x154)+0x4C, *(this+0x1B0)+0x68 and *(this+0x204)+0x104. The last resembles the +104 next-pointer walk of the flag-check list, but its base (this+0x204) differs from the list head at this+0x148, so it is not assigned to an operation.
    // UNRESOLVED: The identity of global dword_8B78A0 (fill labels it SoundManager, DERIVED) is unverified; it is only an opaque object whose field getter gates the allocator and whose sub-buffer is freed.
    // UNRESOLVED: Globals dword_8B8DF4/dword_8B8DF8 passed to UtilityFunction_2950 (fill labels them shadow-map dimensions and flags, DERIVED) have no confirming evidence in this packet.
}
