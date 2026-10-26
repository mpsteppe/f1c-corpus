// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545150
// Canonical corpus name: F_3DSoundSourceDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DSoundSourceDestructor_00545150.c

void UnknownObject::F_3DSoundSourceDestructor()
{
    // Destructor for a 3D sound source object (a2) owned by an audio manager (this): recursively destroys sub-sources, aborts with -1 when the object is still attached to the scene graph, frees an optional buffer resource at offset 0x230, unregisters the object from the manager's 24-byte-strided registration array, removes it from the linked list, runs the destructor chain and frees the object memory.
    // GUARD: if ( a2[17] ) then recursively destroy the child sub-source F_3DSoundSourceDestructor(a2[17]) and null a2[17]. [callee:0x00545150, source:raw]
    // GUARD: if ( a2[16] && a2[19] ) then recursively destroy a2[19] and null a2[19]. [callee:0x00545150, source:raw]
    // GUARD: if ( SceneGraph(a2) ) then return -1, aborting destruction while the object is still registered in the scene graph. [callee:0x0054A770, source:raw]
    // GUARD: if ( a2[140] ) then run the buffer-resource teardown path. [source:raw]
    // CALL: MultiFieldObjectDestructorWithCleanupCalls() tears down the buffer resource at offset 0x230. [callee:0x00560E50, source:raw]
    // GUARD: When a2[16] is set and its +560 field is nonzero, unlink the resource with DoublyLinkedListNodeUnlink_0f10(a2[140]); otherwise use LinkedListRemove_59d0(a2[140]). [callee:0x00560F10, callee:0x005459D0, source:raw]
    // CALL: StateFlagSetterCleanup(a2[140]) then FreeWrapper_7bcf(a2[140]) release the buffer resource. [callee:0x00560C00, callee:0x00587BCF, source:raw]
    // LOOP: Scan the manager's registration array (base this[0x150], count this[0x14C], stride 24) and null any entry whose object pointer equals a2. [field:this:0x00000150, field:this:0x0000014C, guard:0, source:raw]
    // CALL: LinkedListRemove(a2) detaches the object from the linked list. [callee:0x005452B0, source:raw]
    // CALL: TwoFunctionCallChain(a2) runs the object destructor/cleanup chain. [callee:0x0054A710, source:raw]
    // CALL: FreeWrapper_7bcf(a2) frees the object memory. [callee:0x00587BCF, source:raw]
    // RETURN: return 0 on the completed destruction path. [source:raw]

    // Conservative worker pseudocode:
    //   int F_3DSoundSourceDestructor(_DWORD *this, _DWORD *a2) {
    //     if ( a2[17] ) { F_3DSoundSourceDestructor(a2[17]); a2[17] = 0; }
    //     if ( a2[16] && a2[19] ) { F_3DSoundSourceDestructor(a2[19]); a2[19] = 0; }
    //     if ( SceneGraph(a2) ) return -1;
    //     if ( a2[140] ) {
    //       MultiFieldObjectDestructorWithCleanupCalls();
    //       if ( a2[16] && *(_DWORD *)(a2[16] + 560) ) DoublyLinkedListNodeUnlink_0f10(a2[140]);
    //       else LinkedListRemove_59d0(a2[140]);
    //       StateFlagSetterCleanup(a2[140]); FreeWrapper_7bcf(a2[140]);
    //     }
    //     for ( int v6 = 0, v7 = 0; v6 < this[83]; ++v6, v7 += 24 )
    //       if ( *(_DWORD **)(this[84] + v7 + 16) == a2 ) *(_DWORD **)(this[84] + v7 + 16) = 0;
    //     LinkedListRemove(a2);
    //     TwoFunctionCallChain(a2);
    //     FreeWrapper_7bcf(a2);
    //     return 0;
    //   }
    // UNRESOLVED: Meanings of the a2 sub-object slots (a2[16], a2[17], a2[19], a2[140]) and the buffer-resource field at +560 unknown beyond being cleanup targets.
    // UNRESOLVED: Semantics of the SceneGraph(a2) check (scene-graph membership guard) and of the -1 early return contract unverified.
    // UNRESOLVED: Manager registration array layout (base this[0x150], count this[0x14C], stride 24, entry object at +16) inferred from the loop; structure of the entries not fully mapped.
}
