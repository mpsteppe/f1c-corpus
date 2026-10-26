// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BFCD0
// Canonical corpus name: VehicleArrayIndexAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleArrayIndexAccessor_004bfcd0.c

void UnknownObject::VehicleArrayIndexAccessor()
{
    // Indexed lookup into the global vehicle-file entry array. Walks a singly-linked list from head (*this) for a2 steps (following the next pointer at node+4), caching the current node in this[2]; reads the vehicle-file index from the node's data pointer (*(this+0x8)+0) and, if it is below the vehicle-file count dword_8AC390, returns dword_8AC394 + 1060 * index (stride 0x424). Returns 0 when a2 is out of range (a2 >= this[3] list count), when a2 is negative (this[2] reset to 0), when the walk hits a null node early, or when the resolved index is out of range. Called by GameFilterDataLoader (004C0DB0).
    // GUARD: If a2 >= this[3] (the linked-list element count at this+0xC) return 0; the index is out of range. [field:this:0x0000000C, source:raw]
    // GUARD: If a2 < 0, set this[2] (this+0x8) to 0 instead of walking the list; the negative index yields no node. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: For a2 >= 0, initialize the current-node cursor this[2] = *this (head of the linked list). [field:this:0x00000000, field:this:0x00000008, source:raw]
    // LOOP: Walk the list a2 steps: read the current node v4 from this[2]; break if null; decrement the step counter v2 and advance this[2] to the next node via the pointer at v4 + 4. Iterate while v2 > 0. [field:this:0x00000008, source:raw]
    // CALCULATION: Resolve the node's data pointer: v5 = this[2]; v6 = *v5 if the node exists, else 0; then read the vehicle-file index v7 = *v6. [field:*(this+0x8):0x00000000, source:raw]
    // GUARD: If the vehicle-file index v7 >= dword_8AC390 (the vehicle-file entry count), return 0; index is out of range. [global:0x008AC390, source:raw]
    // CALCULATION: Compute the target entry address: dword_8AC394 (vehicle-file entry array base) + 1060 * v7, the 0x424-byte stride scaled by the index. [global:0x008AC394, source:raw]
    // RETURN: Return the resolved vehicle-file entry pointer, or 0 on any out-of-range path. [function:0x004BFCD0, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (a2 < this[3]) {
    //       if (a2 < 0) {
    //           this[2] = 0;
    //       } else {
    //           this[2] = *this;
    //           v2 = a2;
    //           while (v2 > 0) {
    //               v4 = this[2];
    //               if (!v4) break;
    //               --v2;
    //               this[2] = *(int *)(v4 + 4);
    //           }
    //       }
    //       v5 = this[2];
    //       v6 = v5 ? *v5 : 0;
    //       v7 = *v6;
    //       if (v7 < dword_8AC390)
    //           return dword_8AC394 + 1060 * v7;
    //   }
    //   return result;
    // UNRESOLVED: The vehicle-file index stored at the node's data pointer (*(this+0x8)+0) has no named field meaning; it is used only as a stride-0x424 index into dword_8AC394.
    // UNRESOLVED: The linked-list node layout (data pointer at +0, next pointer at +4) is implied only by the raw source walk; no type/class evidence identifies the node or the owner of `this`.
    // UNRESOLVED: The 0x424 stride and the 'vehicle file entry' semantics of dword_8AC394 come from existing_analysis prose (DERIVED); the packet provides no independent writer evidence for the two globals.
    // UNRESOLVED: this[2] is a mutable iteration cursor; per existing_analysis an external poke corrupts the list walk, so it is not a safe mod target.
    // UNRESOLVED: The edge case where the resolved node exists but its data pointer v6 is null reads *v6 on a null v6; the raw source guards v5 but not the resulting v6 dereference.
}
