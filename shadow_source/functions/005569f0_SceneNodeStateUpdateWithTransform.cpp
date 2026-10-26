// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005569F0
// Canonical corpus name: SceneNodeStateUpdateWithTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneNodeStateUpdateWithTransform_005569f0.c

void UnknownObject::SceneNodeStateUpdateWithTransform()
{
    // Performs a full scene-node state update with world-transform upload, collision detection and optional bone-transform copies. Runs a linked-list timer update on a3, calls sub_54B570 for dispatch setup, computes the mesh bounding box when a2+428 is zero, uploads the world transform through the dword_8B8F24 vtable (slot +4) when the 0x20000000 flag is clear, runs collision contact detection, copies 8 twelve-byte bone transforms through the same vtable when the 0x4 flag is set and 0x8 clear, then optionally runs material/shader processing (sub_55ED10, sub_55D5C0) and finalizes via sub_556D60 when the 0x5 flags are set.
    // CALL: LinkedListTraversalWithConditionalTimerUpdate((_DWORD*)a3) traverses/updates the animation channel linked list with a timer check. [callee:0x00551760]
    // CALL: sub_54B570(this, (float*)a2, a3) performs animation dispatch setup/check for the node. [callee:0x0054B570]
    // GUARD: If *(a2+428) is zero (bounding box not yet computed), call MeshBoundingBoxComputation(a3). [callee:0x0054D9F0, source:raw]
    // GUARD: If the world-transform flag (a3+20 bit 0x20000000) is clear, call the dword_8B8F24 vtable slot +4 to upload the world transform built from this+516 + 220 and this+416 into a3+232, then set the flag. [global:0x008B8F24, field:this:0x00000204, source:raw]
    // CALL: CollisionContactStateDetection(a3, (float*)a2, (float*)(a3+232), 0) detects collision contact state for the node. [callee:0x0054D7A0]
    // GUARD: If (a3+20) has bit 0x4 set and bit 0x8 clear, set bit 0x8 and enter the 8-bone transform copy loop. [source:raw]
    // LOOP: Loop 8 times copying 12-byte bone transforms via the dword_8B8F24 vtable slot +4, walking from a3+28 with stride 12 and the matrix base this+416. [global:0x008B8F24, source:raw]
    // GUARD: If (a3+20) has bit 0x5 set: when bit 0x20 is clear, call sub_55ED10(this, a3, this+276) if **(a3+284) has bit 0x100, and call sub_55D5C0(a2, 0) if (a3+20) has bit 0x100000. [callee:0x0055ED10, callee:0x0055D5C0, source:raw]
    // RETURN: When the 0x5 flags are set, return sub_556D60(a3, a2); otherwise return the unmodified (a3+20) flags word. [callee:0x00556D60, source:raw]

    // Conservative worker pseudocode:
    //   int SceneNodeStateUpdateWithTransform(void *this, int a2, int a3) {
    //     LinkedListTraversalWithConditionalTimerUpdate((_DWORD*)a3);
    //     sub_54B570(this, (float*)a2, a3);
    //     if (!*(_DWORD*)(a2 + 428)) MeshBoundingBoxComputation(a3);
    //     if ((*(_DWORD*)(a3 + 20) & 0x20000000) == 0) {
    //       (*(void(__cdecl**)(int,int,int,int))(*(_DWORD*)dword_8B8F24 + 4))(dword_8B8F24, *(_DWORD*)((int)this + 516) + 220, a3 + 232, (int)this + 416);
    //       *(_DWORD*)(a3 + 20) |= 0x20000000u;
    //     }
    //     CollisionContactStateDetection(a3, (float*)a2, (float*)(a3 + 232), 0);
    //     int flags = *(_DWORD*)(a3 + 20);
    //     if ((flags & 4) != 0 && (flags & 8) == 0) {
    //       *(_DWORD*)(a3 + 20) = flags | 8;
    //       for (int i = 0; i < 8; ++i) {
    //         (*(void(__cdecl**)(int,int,int,int))(*(_DWORD*)dword_8B8F24 + 4))(dword_8B8F24, a3 + 28 + i * 12, a3 + 28 + i * 12 + 96, (int)this + 416);
    //       }
    //     }
    //     flags = *(_DWORD*)(a3 + 20);
    //     if ((flags & 5) != 0) {
    //       if ((flags & 0x20) == 0) {
    //         if ((**(int**)(a3 + 284) & 0x100) != 0) sub_55ED10(this, a3, (int)this + 276);
    //         if ((*(_DWORD*)(a3 + 20) & 0x100000) != 0) sub_55D5C0(a2, 0);
    //       }
    //       return sub_556D60(a3, a2);
    //     }
    //     return flags;
    //   }
    // UNRESOLVED: The dword_8B8F24 vtable slot +4 call target is a scene-manager/D3D wrapper whose concrete function is not identified here.
    // UNRESOLVED: The meaning of the node state word a3+20 bit flags (0x4, 0x8, 0x5, 0x20, 0x100, 0x100000) is inferred from legacy analysis only.
    // UNRESOLVED: dword_8B8F28 appears only in legacy analysis; it has no raw-source grounding in this function.
    // UNRESOLVED: The exact identity of this object (which carries +516, +416, +276 state) is unknown.
}
