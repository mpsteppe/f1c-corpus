// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057EC10
// Canonical corpus name: sub_57EC10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57EC10_0057ec10.c

void UnknownObject::lookupByIndexAcrossLists()
{
    // Two-phase mutex-protected lookup bridging two linked lists. Phase 1 walks the first list (head at this+0xAC8) up to index a2 (bounded by the count at this+0xAD4) under mutex this+0xAD8, then derives an id from the chosen node's data+0x1C via sub_4B3DB0. Phase 2 searches the second list (head at this+0xB00) under mutex this+0xB10 for a node whose data[0] equals that id, and stores data[1] into *a3. Returns 1 when a match is stored, 0 otherwise.
    // GUARD: If the first list mutex handle at this+0xAD8 is null, return 0 immediately. [field:this:0x00000AD8, source:raw]
    // CALL: Wait on the first list mutex (WaitForSingleObject) with timeout at this+0xADC. [global:0x0059E1A0, field:this:0x00000AD8, field:this:0x00000ADC, source:raw]
    // GUARD: If the wait failed with a status other than 128 (WAIT_ABANDONED), release nothing and return 0. [global:0x0059E1A0, source:raw]
    // LOOP: Walk the first list from head *(this+0xAC8) to index a2, bounded by a2 in [0, count at this+0xAD4), following each node's next pointer at node+4. [field:this:0x00000AC8, field:this:0x00000AD4, field:*(this+0xAC8):0x00000000, source:raw]
    // CALL: Derive the lookup id from the selected first-list node's data+0x1C via sub_4B3DB0. [callee:0x004B3DB0, field:*(*(this+0xAC8)+0x0):0x0000001C, source:raw]
    // GUARD: If the derived id is -1, skip the second-list search. [callee:0x004B3DB0, source:raw]
    // CALL: Release the first list mutex (ReleaseMutex). [global:0x0059E1A4, field:this:0x00000AD8, source:raw]
    // GUARD: If the second list mutex handle at this+0xB10 is non-null, wait on it with timeout at this+0xB14 (WAIT_OBJECT_0 or WAIT_ABANDONED accepted). [global:0x0059E1A0, field:this:0x00000B10, field:this:0x00000B14, source:raw]
    // LOOP: Search the second list from head *(this+0xB00), following node->next at node+4, for a node whose data[0] equals the derived id; node data is read through the head node's next. [field:this:0x00000B00, field:*(this+0xB00):0x00000004, field:*(*(this+0xB00)+0x4):0x00000000, source:raw]
    // ASSIGNMENT: On a match, set the output flag and store the matched node's data[1] into *a3. [field:*(*(this+0xB00)+0x4):0x00000004, source:raw]
    // CALL: Release the second list mutex (ReleaseMutex). [global:0x0059E1A4, field:this:0x00000B10, source:raw]
    // RETURN: Return 1 if a match was stored in *a3, otherwise 0. [function:0x0057EC10, source:raw]

    // Conservative worker pseudocode:
    //   v16 = 0;
    //   if (!*(void**)(this + 0xAD8)) return 0;
    //   if (WaitForSingleObject(*(void**)(this + 0xAD8), *(DWORD*)(this + 0xADC)) not in {0, 128}) return 0;
    //   node = *(int**)(this + 0xAC8);
    //   if (a2 >= 0 && a2 < *(DWORD*)(this + 0xAD4)) {
    //     n = a2;
    //     while (node && --n > 0) node = (int*)node[1];
    //   }
    //   data = node ? (int*)*node : 0;
    //   id = data ? *((DWORD*)sub_4B3DB0(*(void**)(data + 28)) + 1) : -1;
    //   if (*(void**)(this + 0xAD8)) ReleaseMutex(*(HANDLE*)(this + 0xAD8));
    //   if (id != -1 && *(void**)(this + 0xB10)) {
    //     if (WaitForSingleObject(*(void**)(this + 0xB10), *(DWORD*)(this + 0xB14)) in {0, 128}) {
    //       node2 = *(_DWORD**)(this + 0xB00);
    //       while (node2 && (!*node2 || *(_DWORD*)*node2 != id)) node2 = (_DWORD*)node2[1];
    //       if (node2 && *node2) { v16 = 1; *a3 = (*(_DWORD*)*node2)[1]; }
    //     }
    //     if (*(void**)(this + 0xB10)) ReleaseMutex(*(HANDLE*)(this + 0xB10));
    //   }
    //   return v16;
    // UNRESOLVED: Both linked-list node headers carry a one-byte flag at node+8 (evidence refs for the first and second list heads); that byte is not read by this function, so its role in the list implementation is unresolved.
    // UNRESOLVED: The meaning of the derived id (produced by sub_4B3DB0 from data+0x1C) and the roles of data[0]/data[1] in the second list are not determined from this packet alone.
    // UNRESOLVED: WAIT_ABANDONED (128) is accepted as a successful wait in both phases; the game's handling of abandoned mutex state is not further specified.
}
