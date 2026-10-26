// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005574B0
// Canonical corpus name: sub_5574B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5574B0_005574b0.c

void UnknownObject::ResourceNodeCleanup()
{
    // Cleanup/free routine for a resource node object: resolves the UI-root context via ValueGetter, iterates the sub-resource array at this+0x50 (count at this+0x4C, stride 64) freeing entry-owned pointers and optionally audio resources, walks a second array at this+0x34 (count in a header at base-4, stride 128) running DualDelegate per element, dispatches texture-flag cleanup, frees both array header blocks, and frees four standalone pointers (this+0x3C/0x40/0x44/0x48). Called from doubly-linked-list node removal.
    // CALL: Resolve the UI-root context: v2 = ValueGetter(dword_8B8F28), used as the first argument when processing each sub-resource entry. [callee:0x00545F40, global:0x008B8F28]
    // GUARD: Guard on sub-resource array element count at this+0x4C being greater than 0; a non-positive count skips the per-entry cleanup loop. [field:this:0x0000004C, guard:0, source:raw]
    // LOOP: Iterate over the sub-resource array at this+0x50 exactly this+0x4C times, advancing the entry index by stride 64 each iteration. [field:this:0x0000004C, field:this:0x00000050]
    // GUARD: Per entry: if the pointer at entry+4 is non-null, call sub_547710(v2, entry+4) and then clear entry+4 to 0. [field:this:0x00000050, callee:0x00547710]
    // GUARD: Per entry: if bit 3 (mask 8) of the flags byte at this+0x20 is set, release the audio resource via AudioResourceFree(dword_8B78A0, entry_base). [field:this:0x00000020, callee:0x00540CB0, global:0x008B78A0]
    // GUARD: Per entry: if the pointer at entry+20 is non-null, free it with FreeWrapper_7bcf. [field:this:0x00000050, callee:0x00587BCF]
    // GUARD: Per entry: if the pointer at entry+12 is non-null, free it with FreeWrapper_7bcf. [field:this:0x00000050, callee:0x00587BCF]
    // CALL: Dispatch texture-flag test and conditional cleanup: TextureFlagTestWithDispatch(this). [callee:0x00557630, function:0x005574B0]
    // LOOP: Walk the sub-resource array at this+0x50 backward from its last element (count from the header at base-4, stride 64), calling EmptyStub_0170 once per element, then free the header block (base-4) with FreeWrapper_7bcf. [field:this:0x00000050, callee:0x004B0170, callee:0x00587BCF]
    // LOOP: Walk the array at this+0x34 backward from its last element (count from the header at base-4, stride 128), calling DualDelegate once per element, then free the header block (base-4) with FreeWrapper_7bcf. [field:this:0x00000034, callee:0x005573F0, callee:0x00587BCF]
    // GUARD: If the pointer at this+0x40 is non-null, free it with FreeWrapper_7bcf. [field:this:0x00000040, callee:0x00587BCF]
    // GUARD: If the pointer at this+0x3C is non-null, free it with FreeWrapper_7bcf. [field:this:0x0000003C, callee:0x00587BCF]
    // GUARD: If the pointer at this+0x44 is non-null, free it with FreeWrapper_7bcf. [field:this:0x00000044, callee:0x00587BCF]
    // GUARD: If the pointer at this+0x48 is non-null, free it with FreeWrapper_7bcf. [field:this:0x00000048, callee:0x00587BCF]
    // STATE_TRANSITION: Acts as the node cleanup/destructor step invoked from DoublyLinkedListNodeRemovalByPointer while removing a doubly-linked-list node. [caller:0x005592B0]
    // RETURN: Return 0 after all cleanup is complete. [function:0x005574B0, source:raw]

    // Conservative worker pseudocode:
    //   int ResourceNodeCleanup(int this) {
    //     _DWORD* ctx = (_DWORD*)ValueGetter((_DWORD*)dword_8B8F28);
    //     int count = *(int*)(this + 76);
    //     if (count > 0) {
    //       for (int i = 0; i < count; ++i) {
    //         char* e = (char*)(*(int*)(this + 80)) + i * 64;
    //         if (*(_DWORD*)(e + 4)) { sub_547710(ctx, *(_DWORD**)(e + 4)); *(_DWORD*)(e + 4) = 0; }
    //         if ((*(_BYTE*)(this + 32) & 8) != 0) AudioResourceFree(dword_8B78A0, e);
    //         if (*(_DWORD*)(e + 20)) FreeWrapper_7bcf(*(LPVOID*)(e + 20));
    //         if (*(_DWORD*)(e + 12)) FreeWrapper_7bcf(*(LPVOID*)(e + 12));
    //       }
    //     }
    //     TextureFlagTestWithDispatch(this);
    //     if (*(int*)(this + 80)) {
    //       int base = *(int*)(this + 80);
    //       for (int n = *(int*)(base - 4); n > 0; --n) { EmptyStub_0170(); }
    //       FreeWrapper_7bcf((void*)(base - 4));
    //     }
    //     if (*(int*)(this + 52)) {
    //       int base = *(int*)(this + 52);
    //       for (int n = *(int*)(base - 4); n > 0; --n) { DualDelegate(); }
    //       FreeWrapper_7bcf((void*)(base - 4));
    //     }
    //     if (*(int*)(this + 64)) FreeWrapper_7bcf(*(LPVOID*)(this + 64));
    //     if (*(int*)(this + 60)) FreeWrapper_7bcf(*(LPVOID*)(this + 60));
    //     if (*(int*)(this + 68)) FreeWrapper_7bcf(*(LPVOID*)(this + 68));
    //     if (*(void**)(this + 72)) FreeWrapper_7bcf(*(void**)(this + 72));
    //     return 0;
    //   }
    // UNRESOLVED: Class identity of the `this` object is unknown; the owner remains UnknownObject.
    // UNRESOLVED: sub_547710 (0x00547710) purpose is unverified; it is called with the UI-root context and a sub-resource entry pointer immediately before the entry+4 pointer is cleared.
    // UNRESOLVED: EmptyStub_0170 (0x004B0170) is invoked per element in the backward sweep of the sub-resource array; its exact role (likely a no-op placeholder) is not confirmed.
    // UNRESOLVED: The header layout that stores the element count at base-4 of each array block is inferred from the base-4 dereference in the raw arithmetic and is not independently confirmed.
    // UNRESOLVED: The meaning of the flag bit at this+0x20 mask 8 (audio cleanup enable) and of the per-entry fields at entry+4/+12/+20 depends on the unknown sub-resource entry type.
}
