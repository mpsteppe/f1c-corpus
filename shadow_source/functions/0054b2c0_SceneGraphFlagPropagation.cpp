// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054B2C0
// Canonical corpus name: SceneGraphFlagPropagation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneGraphFlagPropagation_0054b2c0.c

void UnknownObject::SceneGraphFlagPropagation()
{
    // Propagates flag bits through a scene-graph hierarchy. ORs flag a2 into the current node flag field (this+0x3C), and when a3 is non-zero ORs flag a3 into the head child flag field (+0x14) of the child-list structure read at this+0x204 and into every child reached through the +0x10 next pointers. Recurses with a4=1 when the this+0x44 pointer is non-null, then walks up to the parent pointer (this+0x4C) while a4 is non-zero.
    // ASSIGNMENT: Loop body: OR flag bits a2 into the current node flag field this[15] (byte offset 0x3C) [field:this:0x0000003C, source:raw]
    // GUARD: If a3 is non-zero, propagate the child flags; otherwise skip the child propagation block [source:raw]
    // ASSIGNMENT: Load v6 = this[129], the child-list structure pointer at byte offset 0x204 [field:this:0x00000204, source:raw]
    // GUARD: If the child-list structure pointer v6 is non-null, proceed to OR the child flags [field:this:0x00000204, source:raw]
    // ASSIGNMENT: OR flag bits a3 into the head child flag field at v6 + 0x14 [field:*(*(this+0x214)+0x10):0x00000014, source:raw]
    // LOOP: Iterate the child linked list from the next pointer at v6 + 0x10, following +0x10 next pointers, ORing a3 into the +0x14 flag field of every child node [field:*(*(this+0x214)+0x10):0x00000010, field:*(*(this+0x214)+0x10):0x00000014, source:raw]
    // GUARD: If this[17] (byte offset 0x44) is non-null, recurse to propagate the same flags through that related node [field:this:0x00000044, source:raw]
    // CALL: Recursive call SceneGraphFlagPropagation(a2, a3, 1) to propagate flags through the related node pointed to at this+0x44 [callee:0x0054B2C0, field:this:0x00000044, source:raw]
    // GUARD: If a4 is zero, break out of the walk-up loop; otherwise step up to the parent [source:raw]
    // ASSIGNMENT: Walk up: this = this[19], the parent pointer at byte offset 0x4C [field:this:0x0000004C, source:raw]
    // GUARD: If the parent pointer at this+0x4C is null, break out of the loop [field:this:0x0000004C, source:raw]
    // STATE_TRANSITION: Set a4 = 1 so the next iteration walks further up the hierarchy [source:raw]

    // Conservative worker pseudocode:
    //   // propagate flag bits a2 (node) and a3 (children) up the scene-graph hierarchy
    //   while (true) {
    //     this[15] |= a2;
    //     if (a3) {
    //       v6 = this[129];
    //       if (v6) {
    //         *(DWORD*)(v6 + 20) |= a3;
    //         for (i = *(DWORD*)(v6 + 16); i; i = *(DWORD*)(i + 16))
    //           *(DWORD*)(i + 20) |= a3;
    //       }
    //     }
    //     if (this[17])
    //       SceneGraphFlagPropagation(a2, a3, 1);
    //     if (!a4) break;
    //     this = (DWORD*)this[19];
    //     if (!this) break;
    //     a4 = 1;
    //   }
    // UNRESOLVED: Fields this+0x214 and this+0x218 are listed by the deterministic extractor but do not appear in the raw source; their role in the traversal is unclear.
    // UNRESOLVED: The exact meaning of flag bits a2 and a3 (dirty/visible) is not grounded in this packet.
    // UNRESOLVED: The object class owning the scene-graph node is unknown.
}
