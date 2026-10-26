// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581820
// Canonical corpus name: LinkedListDestroyCloseHandle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListDestroyCloseHandle_00581820.c

void UnknownObject::LinkedListDestroyCloseHandle()
{
    // Destroys a linked list owned by this. When the byte flag at this+0x18 is set and CloseHandle on the handle at this+0x10 succeeds, the handle is zeroed. Walks the list from the head at this+0x0 via node next-links at node+0x4; per node, when the node free-flag at node+0x8 is set and the data pointer at node+0x0 is non-null, the data is freed via FreeWrapper_7bcf, then the node wrapper itself is freed. Finally zeroes the four list fields at this+0x0 through this+0xC.
    // GUARD: If byte flag at this+0x18 is non-zero and CloseHandle on the handle at this+0x10 succeeds, proceed to clear the handle. [field:this:0x00000018, field:this:0x00000010, global:0x0059E1A8]
    // ASSIGNMENT: Zero the handle field at this+0x10 after a successful CloseHandle. [field:this:0x00000010]
    // LOOP: Walk the linked list from the head pointer at this+0x0, following each node's next-link at node+0x4 until a null pointer is reached. [field:this:0x00000000, field:*(obj+0x4):0x00000004]
    // GUARD: Per node: when the node free-flag at obj+0x8 is set and the data pointer at obj+0x0 is non-null, the node data is freed. [field:obj:0x00000008, field:obj:0x00000000, callee:0x00587BCF]
    // CALL: FreeWrapper_7bcf on the node data pointer read at obj+0x0. [field:obj:0x00000000, callee:0x00587BCF]
    // CALL: FreeWrapper_7bcf on the node wrapper itself, freeing every node unconditionally. [callee:0x00587BCF]
    // ASSIGNMENT: Zero the head pointer at this+0x0 after the list is emptied. [field:this:0x00000000]
    // ASSIGNMENT: Zero the DWORD at this+0x4 (list state field). [field:this:0x00000004]
    // ASSIGNMENT: Zero the DWORD at this+0x8 (list state field). [field:this:0x00000008]
    // ASSIGNMENT: Zero the DWORD at this+0xC (list state field). [field:this:0x0000000C]
    // RETURN: Return void after the list structure is fully reset. [function:0x00581820, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   void sub_581820(int* this) {
    //     if (*(BYTE*)(this + 24) && CloseHandle((HANDLE)this[4]))
    //       this[4] = 0;
    //     int node = *this;
    //     while (node) {
    //       int cur = node;
    //       node = *(DWORD*)(cur + 4);
    //       if (*(BYTE*)(cur + 8) && *(DWORD*)cur)
    //         FreeWrapper_7bcf((LPVOID)*(DWORD*)cur);
    //       FreeWrapper_7bcf((LPVOID)cur);
    //     }
    //     *this = 0;
    //     this[1] = 0;
    //     this[2] = 0;
    //     this[3] = 0;
    //   }
    // UNRESOLVED: The specific roles of this+0x4, this+0x8 and this+0xC (tail/cursor/count per skeleton-fill prose) are DERIVED and not confirmed by this packet.
    // UNRESOLVED: No callers appear in the packet, so the owning list type and destruction call sites are unknown.
}
