// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005817A0
// Canonical corpus name: sub_5817A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5817A0_005817a0.c

void UnknownObject::LinkedListNodeRemovalByValue()
{
    // Singly-linked-list removal by node value. Walks the list from *this (head) matching the node whose +0x0 value equals a2, splices it out (updating head, tail at this[1], and current-cursor this[2]), decrements the count at this[0xC], optionally clears the +0x8 byte, frees the node value if that +0x8 byte is set, then frees the node itself via FreeWrapper_7bcf and returns 1. Returns 0 when a2 is zero, the list is empty, or no node matches.
    // GUARD: If a2 (the value to remove) is zero, return 0 immediately without touching the list. [source:raw]
    // ASSIGNMENT: Initialize walker v4 = *this (head node) and previous-pointer v5 = 0. [field:this:0x00000000, source:raw]
    // GUARD: If *this (head) is null, the list is empty; return 0. [field:this:0x00000000, source:raw]
    // LOOP: Traverse the chain: while the current node's +0x0 value differs from a2, advance v5 = v4 and v4 = *(v4 + 4) (next pointer); if v4 becomes null, the value is absent and the function returns 0. [field:*(obj+0x4):0x00000000, field:*(obj+0x4):0x00000004, source:raw]
    // ASSIGNMENT: If the matched node is the current cursor this[2], move the cursor to the node's next pointer. [field:this:0x00000008, field:*(obj+0x4):0x00000004, source:raw]
    // ASSIGNMENT: Splice out the matched node: capture its next pointer, link previous node's +0x4 to it; if there is no previous node, update the head *this to the next pointer. [field:this:0x00000000, field:*(obj+0x4):0x00000004, source:raw]
    // ASSIGNMENT: If the matched node is the tail this[1], move the tail back to the previous node v5 (which is 0 when removing the only element). [field:this:0x00000004, field:obj:0x00000004, source:raw]
    // CALCULATION: Decrement the node count at this[0xC]. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: If the a3 flag is zero, clear the matched node's +0x8 byte. [field:*(obj+0x4):0x00000008, source:raw]
    // GUARD: If the matched node's +0x8 byte is set and its +0x0 value is non-null, free the value via FreeWrapper_7bcf before freeing the node itself. [field:*(obj+0x4):0x00000008, field:*(obj+0x4):0x00000000, callee:0x00587BCF, source:raw]
    // CALL: Free the matched node itself via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return 1 to signal a successful removal (and 0 on all early-exit paths). [function:0x005817A0, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return 0;
    //   v5 = 0;
    //   v4 = *this;
    //   if (!v4) return 0;
    //   while (*(DWORD*)v4 != a2) {
    //       v5 = v4;
    //       v4 = *(DWORD*)(v4 + 4);
    //       if (!v4) return 0;
    //   }
    //   if (v4 == this[2]) this[2] = *(DWORD*)(v4 + 4);
    //   v6 = *(DWORD*)(v4 + 4);
    //   if (v5) *(DWORD*)(v5 + 4) = v6;
    //   else *this = v6;
    //   if (this[1] == v4) this[1] = v5;
    //   --this[3];
    //   if (!a3) *(BYTE*)(v4 + 8) = 0;
    //   if (*(BYTE*)(v4 + 8) && *(DWORD*)v4)
    //       FreeWrapper_7bcf(*(LPVOID*)v4);
    //   FreeWrapper_7bcf((LPVOID)v4);
    //   return 1;
    // UNRESOLVED: Owner object is unknown; this is a structural twin of LinkedListNodeRemovalByValue (00491d30) per the prelabel, so the class name is not recovered from this packet alone.
    // UNRESOLVED: The +0x8 byte on a node gates whether the +0x0 value is freed; whether it marks an owned-pointer value or something else is not stated by the packet.
    // UNRESOLVED: field:obj:0x00000004 is a packet-emitted access on a distinct base obj that the raw source renders through this[1]; the base naming is an encoder artifact and not resolvable here.
    // UNRESOLVED: The ABI has no lead prototype; __thiscall is the decompiler's annotation.
}
