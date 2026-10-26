// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00557670
// Canonical corpus name: sub_557670
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_557670_00557670.c

void UnknownObject::ParticleVertexBufferSetup()
{
    // Particle-system vertex/index buffer initializer. Gates on bit 8 of the source flag byte at a2+32, allocates a 572-byte particle object (OperatorNewNhMallocWrapper + sub_54A600), validates a name string via SelfCopyStringWithValidation against aPtemp, then reads the particle-object linked list head through LinkedListIndexedAccessor_c230. When the head's flag byte (v6[5]) bit 7 is set it runs VertexBufferTransform, guards against a global registration failure (ValueGetter + LinkedListWalkInterlockedDec against dword_8B8F28), copies the source data block into this, and builds the full vertex/group structure: element-count and group-count arrays at this+0x34 / this+0x50 (StructInitWithVTableColor / GlobalZeroInit_c2a0 initializers), per-group allocation and vertex/index-fill loops, audio registration via sub_540940(dword_8B78A0), ConditionalFieldSetter_0d40/ConditionalBitmaskCleanup, and an AudioResourceFree teardown loop, then returns 0. Failure paths free the object and report via sub_53C590 with aSomeMtsInitErr or aParticleMustBe, returning -1.
    // GUARD: Entry guard on source flag: if (*(a2+32) & 8) == 0 return 0 immediately without doing any work. [source:raw]
    // ASSIGNMENT: Allocate a 572-byte particle object via OperatorNewNhMallocWrapper(572); on success construct it with sub_54A600, else keep null; store as v4/v73. [callee:0x00587C03, callee:0x0054A600, source:raw]
    // CALL: SelfCopyStringWithValidation(v4, aPtemp, a2+56) copies a source string into the particle object; a true (failure) result enters the error path. [callee:0x0054A730, global:0x005DC19C, source:raw]
    // STATE_TRANSITION: Error path after string-copy failure: if the object exists run TwoFunctionCallChain then FreeWrapper_7bcf(v4); then sub_53C590(-1, aSomeMtsInitErr) logs the init error and the function returns -1. [callee:0x0054A710, callee:0x00587BCF, callee:0x0053C590, global:0x005DC188, source:raw]
    // CALL: v6 = LinkedListIndexedAccessor_c230(v4, 0) reads the index-0 linked-list node from the particle object. [callee:0x0054C230, source:raw]
    // GUARD: Test flag byte (BYTE1(v6[5]) & 0x80); when bit 7 is clear fall through to the end-of-function failure path (SceneGraph, free, aParticleMustBe). [source:raw]
    // CALL: VertexBufferTransform(v6, 0) transforms the node's vertex data before setup. [callee:0x0054C6C0, source:raw]
    // CALL: Registration guard: ValueGetter(dword_8B8F28) fetches a root pointer; if it is non-null and LinkedListWalkInterlockedDec returns nonzero, run SceneGraph(v4), release v4 (TwoFunctionCallChain + FreeWrapper_7bcf) and return -1. [callee:0x00545F40, callee:0x005487A0, global:0x008B8F28, callee:0x0054A770, callee:0x0054A710, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Copy the source data block at a2 into this (strcpy(this, a2)); then this+0x2C = *(a2+36) stores the element/instance count. [field:this:0x0000002C, source:raw]
    // CALL: Allocate (elementCount << 7) + 4 bytes via OperatorNewNhMallocWrapper; loop elementCount times calling StructInitWithVTableColor on each 128-byte entry, then store the array pointer at this+0x34. [callee:0x00587C03, callee:0x005573A0, field:this:0x00000034, source:raw]
    // ASSIGNMENT: this+0x4C = v6[70] records the group (sub-element) count from the linked-list node. [field:this:0x0000004C, source:raw]
    // CALL: Allocate (groupCount << 6) + 4 bytes via OperatorNewNhMallocWrapper; loop groupCount times calling GlobalZeroInit_c2a0 on each 64-byte entry, store the pointer at this+0x50, then memset the whole array to 0 (size = this+0x4C << 6). [callee:0x00587C03, callee:0x0053C2A0, field:this:0x00000050, source:raw]
    // ASSIGNMENT: Option flags from source: if (a2+32 & 0x10) != 0 set this+0x20 = 16; if (a2+32 & 0x20) != 0 set this+0x20 = 32. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Allocate two count buffers of 4 * elementCount bytes via OperatorNewNhMallocWrapper, store them at this+0x3C and this+0x40; then this+0x20 |= 8, this+0x24 = 0 and this+0x28 = 0 (accumulators cleared). [callee:0x00587C03, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, source:raw]
    // LOOP: Outer group loop gated by group count this+0x4C > 0. For each group at this+0x50 (64-byte stride) clear bit 0x10, copy the count pointers from the source group data (v6[71]), call TwoCounterIncrements on the group count pointer, compute vertex/index counts as elementCount * source counts, and accumulate them into this+0x24 and this+0x28. [callee:0x005473C0, field:this:0x00000050, field:this:0x00000024, field:this:0x00000028, source:raw]
    // CALL: Per group allocate the vertex array (36 * count bytes, stored at group+12) and the index array (2 * indexCount bytes, stored at group+20) via OperatorNewNhMallocWrapper. [callee:0x00587C03, field:this:0x00000050, source:raw]
    // LOOP: Vertex-fill loop, two branches on the sign of the a2+32 byte. When bit 7 is clear, copy position/index triplets from the source group and write color as source|0xFF000000; when set, set this+0x20 |= 0x80 and repeat the same fill elementCount times against the base source group. [field:this:0x00000020, field:this:0x00000050, source:raw]
    // ASSIGNMENT: Per group store group+56 = (source byte a2+32 < 0) ? 32 : 34 as a per-group literal tag. [field:this:0x00000050, source:raw]
    // CALL: sub_540940(dword_8B78A0, groupPtr) registers the group with the audio/rendering subsystem; a true result returns -1 immediately. [callee:0x00540940, global:0x008B78A0, field:this:0x00000050, source:raw]
    // CALL: After registration run ConditionalFieldSetter_0d40(groupPtr, 12), and near the end of each group iteration run ConditionalBitmaskCleanup(groupPtr, 12) to conditionally set and then clear a field/bitmask. [callee:0x00540D40, callee:0x00540DA0, field:this:0x00000050, source:raw]
    // GUARD: Element-count guard: if this+0x2C > 0 the per-element vertex-fill, element-array and index-buffer loops run; when the count is zero those loops are skipped. [guard:0, field:this:0x0000002C, source:raw]
    // LOOP: Fill the element/instance array at this+0x34 (128-byte entries, elementCount iterations): write instance offsets into entry+4 and copy per-group source attribute pairs (32/36 within each 48-byte source stride) into entry+36 onward. [field:this:0x00000034, field:this:0x00000050, source:raw]
    // LOOP: Index-buffer fill: for each element write into group+20 an offset = elementIndex * groupVertexCount + sourceIndex; when the group's +40 buffer is present, qmemcpy it from the +20 buffer for 2 * elementCount * indexCount bytes. [field:this:0x00000050, field:this:0x0000002C, source:raw]
    // LOOP: Teardown loop over group count v6[70] > 0: for each source group AudioResourceFree(dword_8B78A0, groupPtr) releases its audio resource, then FreeWrapper_7bcf(v6) frees the linked-list node and FreeWrapper_7bcf(v73) frees the particle object. [callee:0x00540CB0, global:0x008B78A0, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Final allocations: this+0x44 = OperatorNewNhMallocWrapper(4 * this+0x4C) and this+0x48 = OperatorNewNhMallocWrapper(4 * this+0x4C) prepare the group-count output buffers. [callee:0x00587C03, field:this:0x00000044, field:this:0x00000048, source:raw]
    // RETURN: Success path returns 0 after all group and buffer setup completes. [source:raw]
    // STATE_TRANSITION: End-of-function failure path (flag bit 7 clear on the node): SceneGraph(v4), release v4 (TwoFunctionCallChain + FreeWrapper_7bcf), sub_53C590(-1, aParticleMustBe) logs the particle-requirement error and the function returns -1. [callee:0x0054A770, callee:0x0054A710, callee:0x00587BCF, callee:0x0053C590, global:0x005DC16C, source:raw]
    // CALL: Dispatched from FlagConditionalBranchDispatch (00557480) with this object and source data pointer a2. [caller:0x00557480]

    // Conservative worker pseudocode:
    //   int ParticleVertexBufferSetup(int this, int a2) {
    //     if ((*(BYTE*)(a2+32) & 8) == 0) return 0;
    //     void* v4 = OperatorNewNhMallocWrapper(572);
    //     if (v4) sub_54A600(v4);
    //     if (SelfCopyStringWithValidation(v4, aPtemp, a2+56)) {
    //       if (v4) { TwoFunctionCallChain(); FreeWrapper_7bcf(v4); }
    //       sub_53C590(-1, aSomeMtsInitErr); return -1;
    //     }
    //     int* v6 = LinkedListIndexedAccessor_c230(v4, 0);
    //     if ((BYTE1(v6[5]) & 0x80) == 0) goto fail;
    //     VertexBufferTransform((int)v6, 0);
    //     if (ValueGetter(dword_8B8F28) && LinkedListWalkInterlockedDec(ValueGetter(dword_8B8F28))) {
    //       SceneGraph(v4); if (v4) { TwoFunctionCallChain(); FreeWrapper_7bcf(v4); } return -1;
    //     }
    //     strcpy((char*)this, (const char*)a2);
    //     this[0x2C] = *(int*)(a2+36);
    //     this[0x34] = alloc_element_array(this[0x2C]);   // StructInitWithVTableColor per 128-byte entry
    //     this[0x4C] = v6[70];
    //     this[0x50] = alloc_group_array(this[0x4C]);     // GlobalZeroInit_c2a0 per 64-byte entry + memset
    //     if (*(BYTE*)(a2+32) & 0x10) this[0x20] = 16;
    //     if (*(BYTE*)(a2+32) & 0x20) this[0x20] = 32;
    //     this[0x3C] = OperatorNewNhMallocWrapper(4 * this[0x2C]);
    //     this[0x40] = OperatorNewNhMallocWrapper(4 * this[0x2C]);
    //     this[0x20] |= 8; this[0x24] = 0; this[0x28] = 0;
    //     for (g = 0; g < this[0x4C]; g++) {
    //       int group = this[0x50] + g*64;
    //       group &= ~0x10; group+4 = srcgroup+4; TwoCounterIncrements(group+4);
    //       group+8 = this[0x2C] * srcgroup+8; group+16 = this[0x2C] * srcgroup+16;
    //       this[0x24] += group+8; this[0x28] += group+16;
    //       group+12 = OperatorNewNhMallocWrapper(36 * srcgroup+8);
    //       group+20 = OperatorNewNhMallocWrapper(2 * group+16);
    //       fill_vertices(group, a2, v6);  // copy triplets, color | 0xFF000000, sign-branch on a2+32
    //       group+56 = (*(char*)(a2+32) < 0) ? 32 : 34;
    //       if (sub_540940(dword_8B78A0, group)) return -1;
    //       if (*(char*)(a2+32) >= 0) { group+8 = srcgroup+8; group+16 = srcgroup+16; }
    //       ConditionalFieldSetter_0d40(group, 12);
    //       fill_element_array(this, group, v6, g);   // this[0x34] 128-byte entries
    //       fill_index_buffer(this, group, v6, g);    // group+20 words + group+40 qmemcpy
    //       ConditionalBitmaskCleanup(group, 12);
    //     }
    //     for (g = 0; g < v6[70]; g++) AudioResourceFree(dword_8B78A0, v6[71] + g*64);
    //     FreeWrapper_7bcf(v6);
    //     if (v4) { TwoFunctionCallChain(); FreeWrapper_7bcf(v4); }
    //     this[0x44] = OperatorNewNhMallocWrapper(4 * this[0x4C]);
    //     this[0x48] = OperatorNewNhMallocWrapper(4 * this[0x4C]);
    //     return 0;
    //   fail:
    //     SceneGraph(v4); if (v4) { TwoFunctionCallChain(); FreeWrapper_7bcf(v4); }
    //     sub_53C590(-1, aParticleMustBe); return -1;
    //   }
    // UNRESOLVED: Exact semantics of the a2+32 flag bits (8 gate, 0x10/0x20 option selectors, sign bit 7 choosing the vertex-fill branch) and of the per-group literal tag group+56 (32 vs 34) are not established.
    // UNRESOLVED: The concrete roles of sub_54A600, VertexBufferTransform, TwoFunctionCallChain and the ValueGetter/LinkedListWalkInterlockedDec guard against dword_8B8F28 are inferred from packet names, not proven.
    // UNRESOLVED: The strcpy(this, a2) copies a2's data block into this; the exact size and layout of that source block are unknown.
    // UNRESOLVED: The relationship between the particle object v4 (572 bytes) and the linked-list node returned by LinkedListIndexedAccessor_c230 is inferred, not confirmed.
    // UNRESOLVED: Caller FlagConditionalBranchDispatch (00557480) is recorded; frame-path membership is NOT_FOUND and call frequency is UNKNOWN.
}
