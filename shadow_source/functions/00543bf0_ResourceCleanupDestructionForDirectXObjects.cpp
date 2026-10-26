// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543BF0
// Canonical corpus name: ResourceCleanupDestructionForDirectXObjects
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceCleanupDestructionForDirectXObjects_00543bf0.c

void UnknownObject::ResourceCleanupDestructionForDirectXObjects()
{
    // Teardown of a DirectX/render resource owner object. Walks each owned linked list and calls the per-node destructor (scene graph nodes, render objects, 3D sound sources, three resource arrays, and a doubly-linked node list), then frees counted arrays (528-byte and 56/24-byte element pools) element-by-element and releases their backing block, zeroes the emptied owner pointers, performs an audio-network-stream cleanup, and returns -1 early if the exit-checked list walk aborts. Invoked by MutexSemaphoreCleanup (005461b0) during shutdown.
    // GUARD: Scene graph gate: proceed only if this[0xF8] (scene graph list head) is non-null [field:this:0x000000F8, source:raw]
    // LOOP: Walk scene graph nodes via next pointer at node+0x1B8 (440); for each child node pass *(node+0x1B4) (436) to SceneGraphTreeDestructor before destroying the parent [callee:0x00544EF0, field:*(this+0x2B0):0x000001B4, source:raw]
    // CALL: SceneGraphTreeDestructor on the final scene graph node (list head) [callee:0x00544EF0, source:raw]
    // ASSIGNMENT: Clear this[0xF8] to 0 after scene graph destruction [field:this:0x000000F8, source:raw]
    // GUARD: Render object gate: proceed only if this[0x100] (render object list head) is non-null [field:this:0x00000100, source:raw]
    // LOOP: Walk render object nodes via next pointer at node+0x104 (260); pass *(node+0x100) (256) to DestroyFree per node [callee:0x0054A240, field:*(this+0x204):0x00000100, source:raw]
    // CALL: DestroyFree on the final render object node (list head) [callee:0x0054A240, source:raw]
    // ASSIGNMENT: Clear this[0x100] to 0 after render object destruction [field:this:0x00000100, source:raw]
    // GUARD: 3D sound gate: proceed only if this[0x108] (sound source list head) is non-null [field:this:0x00000108, source:raw]
    // LOOP: Walk sound source nodes via next pointer at node+0x4C (76); pass *(node+0x48) (72) to F_3DSoundSourceDestructor per node [callee:0x00545150, field:*(this+0x154):0x00000048, source:raw]
    // CALL: F_3DSoundSourceDestructor on the final sound source node (list head) [callee:0x00545150, source:raw]
    // ASSIGNMENT: Clear this[0x108] to 0 after sound source destruction [field:this:0x00000108, source:raw]
    // GUARD: Exit-check gate: evaluate only if this[0x110] (audio network stream handle) is non-null [field:this:0x00000110, source:raw]
    // CALL: LinkedListWalkWithExitCheck() walks a list and reports whether the walk may abort [callee:0x005487E0, source:raw]
    // RETURN: Return -1 (abort the whole cleanup) when LinkedListWalkWithExitCheck returns non-zero [function:0x00543BF0, source:raw]
    // CALL: AudioNetworkStreamCleanup(this) releases the audio network stream resources tied to this object [callee:0x00544AF0, field:this:0x00000110, source:raw]
    // GUARD: First resource array gate: proceed only if this[0x120] is non-null [field:this:0x00000120, source:raw]
    // LOOP: Walk first resource array nodes via next pointer at node+0x6C (108); pass *(node+0x68) (104) to sub_5454A0 per node [callee:0x005454A0, field:*(this+0x18C):0x00000068, source:raw]
    // CALL: sub_5454A0 on the final node of the first resource array (list head) [callee:0x005454A0, source:raw]
    // ASSIGNMENT: Clear this[0x120] to 0 after first resource array destruction [field:this:0x00000120, source:raw]
    // GUARD: Second resource array gate: proceed only if this[0x128] is non-null [field:this:0x00000128, source:raw]
    // LOOP: Walk second resource array nodes via next pointer at node+0x6C (108); pass *(node+0x68) (104) to sub_5454A0 per node [callee:0x005454A0, field:*(this+0x194):0x00000068, source:raw]
    // CALL: sub_5454A0 on the final node of the second resource array (list head) [callee:0x005454A0, source:raw]
    // ASSIGNMENT: Clear this[0x128] to 0 after second resource array destruction [field:this:0x00000128, source:raw]
    // GUARD: Third resource array gate: proceed only if this[0x130] is non-null [field:this:0x00000130, source:raw]
    // LOOP: Walk third resource array nodes via next pointer at node+0x6C (108); pass *(node+0x68) (104) to sub_5454A0 per node [callee:0x005454A0, field:*(this+0x19C):0x00000068, source:raw]
    // CALL: sub_5454A0 on the final node of the third resource array (list head) [callee:0x005454A0, source:raw]
    // ASSIGNMENT: Clear this[0x130] to 0 after third resource array destruction [field:this:0x00000130, source:raw]
    // GUARD: Selective-free gate: proceed only if this[0x1AC] flag is non-zero [field:this:0x000001AC, source:raw]
    // CALL: ConditionalFreeOfStructField(this) performs a flag-gated partial free of a struct field [callee:0x00560B30, source:raw]
    // GUARD: First 528-byte pool gate: proceed only if this[0x1B8] is non-null [field:this:0x000001B8, source:raw]
    // CALCULATION: Counted array header: element count = *(array - 4); pool spans 528 bytes per element (array + 0x210 * count), iterated from the tail backward [field:this:0x000001B8, source:raw]
    // LOOP: Per-element CleanupFunction(elem) over the 528-byte stride until the count is exhausted [callee:0x00557280, source:raw]
    // CALL: FreeWrapper_7bcf(array - 4) releases the pool allocation including its count header [callee:0x00587BCF, source:raw]
    // GUARD: Second 528-byte pool gate: proceed only if this[0x1C0] is non-null [field:this:0x000001C0, source:raw]
    // LOOP: Per-element CleanupFunction(elem) over the 528-byte stride using the *(array - 4) element count [callee:0x00557280, field:this:0x000001C0, source:raw]
    // CALL: FreeWrapper_7bcf(array - 4) releases the second 528-byte pool allocation [callee:0x00587BCF, source:raw]
    // GUARD: Third 528-byte pool gate: proceed only if this[0x1C8] is non-null [field:this:0x000001C8, source:raw]
    // LOOP: Per-element CleanupFunction(elem) over the 528-byte stride using the *(array - 4) element count [callee:0x00557280, source:raw]
    // CALL: FreeWrapper_7bcf(array - 4) releases the third 528-byte pool allocation [callee:0x00587BCF, source:raw]
    // GUARD: Fourth 528-byte pool gate: proceed only if this[0x1D0] is non-null [field:this:0x000001D0, source:raw]
    // LOOP: Per-element CleanupFunction(elem) over the 528-byte stride using the *(array - 4) element count [callee:0x00557280, source:raw]
    // CALL: FreeWrapper_7bcf(array - 4) releases the fourth 528-byte pool allocation [callee:0x00587BCF, source:raw]
    // GUARD: 56-byte pool gate: proceed only if this[0x138] is non-null [field:this:0x00000138, source:raw]
    // CALCULATION: Counted array header: element count = *(array - 4); elements 56 bytes each, iterated backward from the tail [field:this:0x00000138, source:raw]
    // LOOP: Per-element EmptyStub_0170() over the 56-byte stride until the count is exhausted [callee:0x004B0170, source:raw]
    // CALL: FreeWrapper_7bcf(array - 4) releases the 56-byte pool allocation [callee:0x00587BCF, source:raw]
    // GUARD: First 24-byte pool gate: proceed only if this[0x150] is non-null [field:this:0x00000150, source:raw]
    // CALCULATION: Counted array header: element count = *(array - 4); stride of 3 dwords (24 bytes) per element, iterated backward from array + 8 * (3 * count) [field:this:0x00000150, source:raw]
    // LOOP: Per-element EmptyStub_0170() over the 24-byte stride until the count is exhausted [callee:0x004B0170, source:raw]
    // CALL: FreeWrapper_7bcf(array - 4) releases the first 24-byte pool allocation [callee:0x00587BCF, source:raw]
    // GUARD: Global render-resource gate: proceed only if dword_8B8F2C is non-zero [global:0x008B8F2C, source:raw]
    // CALL: sub_5593D0() releases the global render resource identified by dword_8B8F2C [callee:0x005593D0, source:raw]
    // GUARD: Second 24-byte pool gate: proceed only if this[0x140] is non-null [field:this:0x00000140, source:raw]
    // LOOP: Per-element EmptyStub_0170() over the 24-byte stride using the *(array - 4) element count [callee:0x004B0170, source:raw]
    // CALL: FreeWrapper_7bcf(array - 4) releases the second 24-byte pool allocation [callee:0x00587BCF, source:raw]
    // GUARD: Third 24-byte pool gate: proceed only if this[0x178] is non-null [field:this:0x00000178, source:raw]
    // LOOP: Per-element EmptyStub_0170() over the 24-byte stride using the *(array - 4) element count [callee:0x004B0170, source:raw]
    // CALL: FreeWrapper_7bcf(array - 4) releases the third 24-byte pool allocation [callee:0x00587BCF, source:raw]
    // GUARD: Doubly-linked node-list gate: proceed only if this[0x118] is non-null [field:this:0x00000118, source:raw]
    // LOOP: Walk nodes via next pointer at node+0x30 (48); pass *(node+0x2C) (44) to DoublyLinkedListNodeRemoval_19e0 per node [callee:0x005519E0, field:*(this+0x148):0x0000002C, source:raw]
    // CALL: DoublyLinkedListNodeRemoval_19e0 on the final node (list head) [callee:0x005519E0, source:raw]
    // ASSIGNMENT: Clear this[0x118] to 0 after the node list is emptied [field:this:0x00000118, source:raw]
    // RETURN: Return 0 on the normal completion of the full resource teardown [function:0x00543BF0, source:raw]

    // Conservative worker pseudocode:
    //   if (this[0xF8]) { walk scene graph nodes by next@+0x1B8; SceneGraphTreeDestructor(child@+0x1B4) each; SceneGraphTreeDestructor(head); this[0xF8] = 0; }
    //   if (this[0x100]) { walk nodes by next@+0x104; DestroyFree(child@+0x100) each; DestroyFree(head); this[0x100] = 0; }
    //   if (this[0x108]) { walk nodes by next@+0x4C; F_3DSoundSourceDestructor(child@+0x48) each; F_3DSoundSourceDestructor(head); this[0x108] = 0; }
    //   if (this[0x110] && LinkedListWalkWithExitCheck()) return -1;
    //   AudioNetworkStreamCleanup(this);
    //   for (head in {0x120, 0x128, 0x130}) if (this[head]) { walk by next@+0x6C; sub_5454A0(child@+0x68) each; sub_5454A0(head); this[head] = 0; }
    //   if (this[0x1AC]) ConditionalFreeOfStructField(this);
    //   for (head in {0x1B8, 0x1C0, 0x1C8, 0x1D0}) if (this[head]) { count = *(this[head]-4); for (e = this[head]+528*count; e != this[head]; e -= 528) CleanupFunction(e); FreeWrapper_7bcf(this[head]-4); }
    //   if (this[0x138]) { count = *(this[0x138]-4); for (e = this[0x138]+56*count; e != this[0x138]; e -= 56) EmptyStub_0170(); FreeWrapper_7bcf(this[0x138]-4); }
    //   for (head in {0x150, 0x140, 0x178}) if (this[head]) { count = *(this[head]-4); for (e = this[head]+24*count; e != this[head]; e -= 24) EmptyStub_0170(); FreeWrapper_7bcf(this[head]-4); }
    //   if (dword_8B8F2C) sub_5593D0();
    //   if (this[0x118]) { walk nodes by next@+0x30; DoublyLinkedListNodeRemoval_19e0(child@+0x2C) each; DoublyLinkedListNodeRemoval_19e0(head); this[0x118] = 0; }
    //   return 0;
    // UNRESOLVED: Seven this-relative offsets (0x148, 0x154, 0x18C, 0x194, 0x19C, 0x204, 0x2B0) appear in the packet field facts as base-pointer reads but never as this[N] accesses in the raw decompiled source; the paired node-relative facts (*(this+0x148)+0x2C, *(this+0x154)+0x48, *(this+0x18C)+0x68, *(this+0x194)+0x68, *(this+0x19C)+0x68, *(this+0x204)+0x100, *(this+0x2B0)+0x1B4) do match the list-walk offsets in the source, so these are likely the IDB's names for the sub-object bases, but the mapping is not directly reconcilable from this packet
    // UNRESOLVED: Node-relative next/child offsets 440 (0x1B8), 260 (0x104), 76 (0x4C), 108 (0x6C), 48 (0x30) and the counted-array strides 528/56/24 with the *(array - 4) element-count header are carried only by source:raw; no packet field reference names them
    // UNRESOLVED: EmptyStub_0170 (0x004B0170) is invoked per element of several counted pools but is a stub; whether it performs any real per-element destruction is not verifiable from this packet
    // UNRESOLVED: The object base (this) is an UnknownObject; the type of the owner class and the meaning of the global dword_8B8F2C are not established here
}
