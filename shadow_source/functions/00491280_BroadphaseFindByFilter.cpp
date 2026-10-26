// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491280
// Canonical corpus name: sub_491280
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_491280_00491280.c

void UnknownObject::BroadphaseFindByFilter()
{
    // Iterates a singly-linked collision/broadphase list, applying the sub_491680 filter to each node's AABB coordinate quad. Returns 1 on the first node whose filter test passes, otherwise 0. The iteration cursor at this+0x8 is initialized to the list head and advanced through each node's next pointer; a null head, a null first node value, or a null next node terminates the walk with 0.
    // ASSIGNMENT: Initialize the iteration cursor this[8] to the list head read from this[0]. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // GUARD: Guard on this[0] == 0 (empty list); return 0 immediately when the head is null. [guard:0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Load v4 = *head (the first node's value pointer) and return 0 when it is null. [field:obj:0x00000000, source:raw]
    // LOOP: Loop while sub_491680(v4[0], v4[1], v4[2], v4[3]) returns 0, testing the node AABB coordinate quad at offsets 0, 2, 4 and 6. [callee:0x00491680, field:*(*(*(this+0x8)+0x4)+0x0):0x00000000, field:*(*(*(this+0x8)+0x4)+0x0):0x00000002, field:*(*(*(this+0x8)+0x4)+0x0):0x00000004, field:*(*(*(this+0x8)+0x4)+0x0):0x00000006, source:raw]
    // ASSIGNMENT: Advance the cursor: read the next-node pointer from this[8]+4, store it into this[8], load the new node's value from offset 0, and continue when both are non-null; otherwise fall through to return 0. [field:*(this+0x8):0x00000004, field:*(*(this+0x8)+0x4):0x00000000, field:this:0x00000008, source:raw]
    // RETURN: Return 0 when the walk exhausts the list without a filter match, or 1 on the first match. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_491280(int a1, int a2) {
    //     *(int*)(a1 + 8) = *(int*)a1;
    //     if (*(int*)a1 == 0) return 0;
    //     short* v4 = **(short***)a1;
    //     if (!v4) return 0;
    //     while (!sub_491680(v4[0], v4[1], v4[2], v4[3])) {
    //       int v5 = *(int*)(a1 + 8);
    //       if (v5) {
    //         int* v6 = *(int**)(v5 + 4);
    //         *(int*)(a1 + 8) = v6;
    //         if (v6 && (v4 = *v6)) continue;
    //       }
    //       return 0;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: Parameter a2 is accepted but never referenced in the body; its purpose is unknown.
    // UNRESOLVED: The list-node and value struct layouts beyond offsets 0 and 4 are not established.
    // UNRESOLVED: The exact semantics of sub_491680's filter on the four shorts are caller/callee-defined.
}
