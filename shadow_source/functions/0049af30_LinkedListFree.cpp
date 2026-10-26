// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049AF30
// Canonical corpus name: LinkedListFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListFree_0049af30.c

void UnknownObject::LinkedListFree()
{
    // Linked-list teardown: walks the singly linked list rooted at *this. Each node is freed via FreeWrapper_7bcf(node); if the node flag byte at +8 is set, the node's first dword (payload pointer) is also freed via FreeWrapper_7bcf. After the walk, zeroes the four list fields at this+0x0..this+0xC. Structural twin of LinkedListDestructor_1db0 (00491db0).
    // LOOP: Walk the list starting from i = *this (head pointer at this+0x0), continuing while i is non-null. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Save the current node v3 = i for freeing. [source:raw]
    // ASSIGNMENT: Read the owns-payload flag v4 = *(BYTE*)(i + 8) from the node (field obj+0x8). [field:obj:0x00000008]
    // ASSIGNMENT: Advance i to the next node: i = *(DWORD*)(i + 4) (field *(obj+0x4)). [field:*(obj+0x4):0x00000004]
    // GUARD: Guard on the owns-payload flag v4; when set, free the node payload. [source:raw]
    // CALL: Free the node payload pointer *v3 (field obj+0x0) via FreeWrapper_7bcf when the flag is set. [field:obj:0x00000000, callee:0x00587BCF]
    // CALL: Free the node itself v3 via FreeWrapper_7bcf as the loop step. [callee:0x00587BCF]
    // ASSIGNMENT: Zero the list head: *this = 0. [field:this:0x00000000]
    // ASSIGNMENT: Zero list field this[1] (this+0x4). [field:this:0x00000004]
    // ASSIGNMENT: Zero list field this[2] (this+0x8). [field:this:0x00000008]
    // ASSIGNMENT: Zero list field this[3] (this+0xC). [field:this:0x0000000C]
    // RETURN: Return the last FreeWrapper_7bcf result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49AF30(int *this) {
    //     int result = 0;
    //     for (int i = *this; i; result = FreeWrapper_7bcf(v3)) {
    //       LPVOID *v3 = (LPVOID *)i;
    //       char v4 = *(BYTE*)(i + 8);
    //       i = *(DWORD*)(i + 4);
    //       if (v4)
    //         FreeWrapper_7bcf(*v3);
    //     }
    //     *this = 0; this[1] = 0; this[2] = 0; this[3] = 0;
    //     return result;
    //   }
    // UNRESOLVED: Node payload layout and the meaning of the owns-payload flag at +8 are caller/allocator-side.
    // UNRESOLVED: The list owner class and whether FreeWrapper_7bcf (0x00587BCF) is free() or an internal heap wrapper are unresolved.
}
