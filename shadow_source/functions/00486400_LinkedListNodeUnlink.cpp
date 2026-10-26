// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486400
// Canonical corpus name: UtilityFunction_6400
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_6400_00486400.c

void UnknownObject::LinkedListNodeUnlink()
{
    // Unlinks a single node (a2) from a singly-linked list managed by this. If the list head at this[36] (offset 0x90) is null, returns 0. If the head is the target, advances the head to its next pointer. Otherwise walks nodes via the next pointer at node+0x8C (base *(this+0x11C)); if the walk reaches null before finding a2, returns 0. On a match the predecessor's next pointer bypasses the removed node, the removed node's next pointer is zeroed (offset 0x8C), the node counter at this[37] (offset 0x94) is decremented, and the removed node is returned.
    // GUARD: If this[36] (list head, offset 0x90) is null, return 0 immediately [field:this:0x00000090, source:raw]
    // GUARD: If the head node equals the target a2, unlink the head by setting this[36] = *(node + 0x8C) (the head's next pointer) [field:this:0x00000090, field:*(this+0x11C):0x0000008C, source:raw]
    // LOOP: Otherwise walk the list: repeatedly follow the next pointer at node+0x8C (base *(this+0x11C)) while tracking the predecessor [field:*(this+0x11C):0x0000008C, field:this:0x0000011C, source:raw]
    // GUARD: During the walk, if the next pointer is null before the target is found, return 0 [field:*(this+0x11C):0x0000008C, source:raw]
    // ASSIGNMENT: On match, bypass the removed node: predecessor next pointer (offset 0x8C) = removed node's next pointer [field:*(this+0x11C):0x0000008C, source:raw]
    // ASSIGNMENT: Detach the removed node: write 0 to its next pointer at offset 0x8C [field:*(this+0x11C):0x0000008C, source:raw]
    // CALCULATION: Decrement the node counter this[37] (offset 0x94) [field:this:0x00000094, source:raw]
    // RETURN: Return the removed node pointer [function:0x00486400, source:raw]

    // Conservative worker pseudocode:
    //   result = this[36];
    //   if (!result) return 0;
    //   if (result == a2) {
    //     this[36] = *(DWORD*)(result + 0x8C);
    //   } else {
    //     do {
    //       result = *(DWORD*)(result + 0x8C);
    //       if (result == a2) break;
    //       if (!result) return 0;
    //     } while (1);
    //     *(DWORD*)(prev + 0x8C) = *(DWORD*)(result + 0x8C);
    //   }
    //   *(DWORD*)(result + 0x8C) = 0;
    //   --this[37];
    //   return result;
    // UNRESOLVED: The exact layout of the node object beyond the next pointer at +0x8C is unknown; the node base is *(this+0x11C)
    // UNRESOLVED: The caller (UIListManagementHandler 0048A3C0) relationship and the meaning of the returned node are not established by this body
    // UNRESOLVED: The concrete type of `this` (list manager object) is unidentified
}
