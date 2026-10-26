// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004919C0
// Canonical corpus name: sub_4919C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4919C0_004919c0.c

void UnknownObject::PoolNodeAppendToList()
{
    // __thiscall: obtains a pool node for an AABB (a2-a5) via ResourcePoolNodeAllocDealloc, wraps it in a freshly allocated 12-byte list node, and appends the node to a linked list embedded at offset 12 of the object pointed to by *this. Returns 1 on success, 0 when no pool node is available.
    // CALL: Request a pool node for the AABB described by a2-a5 via ResourcePoolNodeAllocDealloc; store the result in v6. [callee:0x00490940, source:raw]
    // ASSIGNMENT: Resolve the list header block as the object pointed to by *this plus offset 12: v7 = *this + 12. [field:this:0x00000000, field:obj:0x0000000C, source:raw]
    // GUARD: When v6 (the pool node) is null, skip the append and fall through to return 0. [source:raw]
    // CALL: Allocate a 12-byte list node via OperatorNewNhMallocWrapper(12); store in v9. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialise the new node: node[0] = v6 (the pool node), node[4] = 0, node[8] = 0. When the allocation returned null, v9 is forced to 0. [source:raw]
    // GUARD: When the list head at obj+0xC is non-null, link the new node after the tail: tail->next (offset +4 of the current tail) = v9. [field:obj:0x0000000C, source:raw]
    // ASSIGNMENT: When the list was empty, set head at obj+0xC = v9 and the iteration/current pointer at obj+0x14 = v9. [field:obj:0x0000000C, field:obj:0x00000014, source:raw]
    // ASSIGNMENT: Set the tail pointer at obj+0x10 = v9 so the new node is the new tail, and increment the node count at obj+0x18. [field:obj:0x00000010, field:obj:0x00000018, source:raw]
    // RETURN: Return 1 after a successful append; return 0 when no pool node was available. [source:raw]
    // CALL: Called by sub_496E90 (0x00496E90) to append a pool-backed node to this list. [caller:0x00496E90, source:raw]

    // Conservative worker pseudocode:
    //   char PoolNodeAppendToList(DWORD *this, short a2, short a3, short a4, short a5) {
    //     int node = ResourcePoolNodeAllocDealloc(a2, a3, a4, a5);
    //     DWORD *list = (DWORD *)(*this + 12);
    //     if (node) {
    //       DWORD *item = OperatorNewNhMallocWrapper(12);
    //       if (item) { item[0] = node; item[1] = 0; *(BYTE *)(item + 2) = 0; }
    //       else { item = 0; }
    //       if (list[0]) { *(DWORD *)(list[1] + 4) = item; }
    //       else { list[0] = item; list[2] = item; }
    //       list[1] = item;
    //       ++list[3];
    //       return 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of a2-a5 (nominally AABB extents) and the pool-node resource type are caller/callee specific; no evidence here names them.
    // UNRESOLVED: Object type holding the list at offset 12 is unknown; owner remains UnknownObject.
}
