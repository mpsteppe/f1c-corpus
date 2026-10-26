// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540760
// Canonical corpus name: sub_540760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_540760_00540760.c

void UnknownObject::AudioStreamChainCleanup()
{
    // Multi-list audio resource teardown: guarded by the enable flag at this+0x13DC, walks four linked lists of resource nodes, calls the virtual release slot (vtable +8) on each node's nested sub-object, frees every node payload with FreeWrapper_7bcf, releases the tail object, frees the head nodes, and zeroes the four list slots at this+0x1154/0x115C/0x1164/0x116C. Always returns 0.
    // GUARD: If the enable flag at this+0x13DC is set, run the four-list teardown; otherwise skip straight to the return-0 exit. [field:this:0x000013DC, source:raw]
    // LOOP: Chain 1 rooted at this+0x1154: while a node exists (next pointer at node+28), release the node's nested object by calling vtable slot +8 on the payload reached through node+24 (vtable base at the payload's +0x20, release slot at +0x8), then free the payload with FreeWrapper_7bcf. After the loop release the tail object the same way, free the head node, and zero this+0x1154. [field:this:0x00001154, field:this:0x00001170, field:*(this+0x1170):0x00000018, field:*(this+0x1170):0x00000020, field:*(*(this+0x1170)+0x18):0x00000020, field:*(*(this+0x1170)+0x20):0x00000000, field:*(*(*(this+0x1170)+0x18)+0x20):0x00000000, field:*(*(*(this+0x1170)+0x20)+0x0):0x00000008, field:*(*(*(*(this+0x1170)+0x18)+0x20)+0x0):0x00000008, callee:0x00587BCF, field:this:0x00000000, source:raw]
    // LOOP: Chain 2 rooted at this+0x115C: same pattern as chain 1 (next at node+28, payload at node+24), releasing each node's nested object through the mid-level and leaf vtable paths resolved from the descriptor at this+0x1178 (+0x10 and +0x18 pointers, +0x20 payload link, release slot +0x8), freeing each payload and the head node, and zeroing this+0x115C. [field:this:0x0000115C, field:this:0x00001178, field:*(this+0x1178):0x00000010, field:*(this+0x1178):0x00000018, field:*(this+0x1178):0x00000020, field:*(*(this+0x1178)+0x10):0x00000018, field:*(*(this+0x1178)+0x18):0x00000000, field:*(*(this+0x1178)+0x18):0x00000020, field:*(*(this+0x1178)+0x20):0x00000000, field:*(*(*(this+0x1178)+0x10)+0x18):0x00000000, field:*(*(*(this+0x1178)+0x18)+0x0):0x00000008, field:*(*(*(this+0x1178)+0x18)+0x20):0x00000000, field:*(*(*(this+0x1178)+0x20)+0x0):0x00000008, field:*(*(*(*(this+0x1178)+0x10)+0x18)+0x0):0x00000008, field:*(*(*(*(this+0x1178)+0x18)+0x20)+0x0):0x00000008, callee:0x00587BCF, field:this:0x00000000, source:raw]
    // LOOP: Chain 3 rooted at this+0x1164: uses the alternate node layout (next at node+20, payload at node+16), releasing each node's nested object through vtable slot +8 of the object reached at node+16 (vtable base at +24, resolved via the descriptor at this+0x1180), freeing each payload and the head node, and zeroing this+0x1164. [field:this:0x00001164, field:this:0x00001180, field:*(this+0x1180):0x00000010, field:*(this+0x1180):0x00000018, field:*(*(this+0x1180)+0x10):0x00000018, field:*(*(this+0x1180)+0x18):0x00000000, field:*(*(*(this+0x1180)+0x10)+0x18):0x00000000, field:*(*(*(this+0x1180)+0x18)+0x0):0x00000008, field:*(*(*(*(this+0x1180)+0x10)+0x18)+0x0):0x00000008, callee:0x00587BCF, field:this:0x00000000, source:raw]
    // LOOP: Chain 4 rooted at this+0x116C: identical to chain 3 (next at node+20, payload at node+16, virtual release at vtable +8, payload and head freed with FreeWrapper_7bcf), zeroing this+0x116C. [field:this:0x0000116C, callee:0x00587BCF, field:this:0x00000000, source:raw]
    // RETURN: Always return 0. [source:raw]
    // CALL: Called by sub_53D750 (0x0053D750), ObjectReleaseWithVtableCall (0x0053D850) and AudioNetworkStreamCleanup (0x00544AF0) for audio stream teardown. [caller:0x0053D750, caller:0x0053D850, caller:0x00544AF0, source:raw]

    // Conservative worker pseudocode:
    //   int AudioStreamChainCleanup(this) {
    //     if (this[1271]) {
    //       // chain 1: this[1109], node = { payload:+24, next:+28 }
    //       for (n = this[1109]; n; n = *(int*)(n + 28)) {
    //         obj = *(int*)(*(int*)(n + 24) + 32);
    //         if (obj) this[0] = vtable8(obj);
    //         if (*(int*)(n + 24)) FreeWrapper_7bcf(*(void**)(n + 24));
    //       }
    //       if (*(int*)(n + 32)) this[0] = vtable8(*(int*)(n + 32));
    //       FreeWrapper_7bcf((void*)n);
    //       this[1109] = 0;
    //       // chain 2: same layout at this[1111]
    //       // chain 3: this[1113], node = { payload:+16, next:+20 }
    //       // chain 4: this[1115], same as chain 3
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The packet exposes the chain descriptors at this+0x1170/0x1178/0x1180 but the decompiled body reads only the list-slot indices this[1109]..this[1115]; the exact mapping between list slots and the nested descriptor pointers is inferred from the field bases and is not independently verified.
    // UNRESOLVED: Chain 4 has no nested field evidence in the packet even though its node layout matches chain 3; it is described from the identical code pattern.
}
