// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047FBD0
// Canonical corpus name: LinkedListDestroyAt0x444
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListDestroyAt0x444_0047fbd0.c

void UnknownObject::LinkedListDestroyAt0x444()
{
    // Destructor for a linked list whose head lives at this+0x444. Walks nodes through their next pointers at node+4, and for each node whose flag byte at node+8 is set, frees a double-indirect data buffer: the outer buffer pointer stored at node+0, its inner pointer (if non-null), then the node itself. Clears the four list header fields this+0x444..0x450, chains to LinkedListDestructor(this) for additional cleanup, and finally frees this when bit 0 of a2 is set.
    // ASSIGNMENT: Load the list head pointer from this+0x444 into the traversal cursor. [field:this:0x00000444]
    // LOOP: Traverse nodes while the cursor is non-null, advancing through the next pointer at node+4 before processing the current node. [field:*(this+0x448):0x00000004]
    // GUARD: Read the node flag byte at node+8; only when it is non-zero is the node's embedded data buffer released. [source:raw]
    // CALL: When the outer buffer pointer at node+0 is non-null: free its inner pointer if non-null, then free the outer buffer. [field:*(this+0x444):0x00000000, callee:0x00587BCF]
    // CALL: Free the current node unconditionally on every iteration. [callee:0x00587BCF]
    // STATE_TRANSITION: Zero the four list header fields this+0x444, this+0x448, this+0x44C and this+0x450 after traversal. [field:this:0x00000444, field:this:0x00000448, field:this:0x0000044C, field:this:0x00000450]
    // CALL: Chain to the base LinkedListDestructor(this) for additional cleanup. [callee:0x0048CA50]
    // GUARD: Free this itself when bit 0 of the a2 flag is set (conditional self-delete). [source:raw, function:0x0047FBD0]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_47FBD0(_DWORD *this, char a2) {
    //     int cursor = this[273];
    //     while (cursor) {
    //       LPVOID **node = (LPVOID **)cursor;
    //       char flag = *(_BYTE *)(cursor + 8);
    //       cursor = *(_DWORD *)(cursor + 4);
    //       if (flag) {
    //         LPVOID *buf = *node;
    //         if (buf) {
    //           if (*buf) FreeWrapper_7bcf(*buf);
    //           FreeWrapper_7bcf(buf);
    //         }
    //       }
    //       FreeWrapper_7bcf(node);
    //     }
    //     this[273] = 0; this[274] = 0; this[275] = 0; this[276] = 0;
    //     LinkedListDestructor(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Identity of the object owning the list at this+0x444 and the meaning of the flag byte at node+8.
    // UNRESOLVED: Purpose of the double-indirect buffer (outer node+0 pointer containing an inner pointer).
    // UNRESOLVED: Role of the two extra header fields this+0x44C and this+0x450.
    // UNRESOLVED: What the chained LinkedListDestructor(0x0048CA50) performs beyond this function.
    // UNRESOLVED: Meaning of a2 bits other than bit 0.
}
