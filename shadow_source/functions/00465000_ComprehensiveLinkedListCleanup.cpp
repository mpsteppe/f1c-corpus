// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00465000
// Canonical corpus name: sub_465000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_465000_00465000.c

void UnknownObject::ComprehensiveLinkedListCleanup()
{
    // Teardown of a large heap object pointed to by *this. Walks and frees two big linked lists (heads at obj+0xE5C0 and obj+0xE5B0), freeing each node via ConditionalFreeByFlagCheck followed by FreeWrapper_7bcf and zeroing the four head/trailer/tail/count fields of each list. Then frees a fixed 104-entry static pointer array, then two flag-linked lists whose head pointers live at obj+0x7C and obj+0x6C (each node carries a flag byte at +8, a next pointer at +4, and an optional payload at +0 freed only when the flag is set). Finally zeroes the four fields of each flag-list, calls EmptyStub_0170, and returns FreeWrapper_7bcf(*this), freeing the object itself.
    // GUARD: If *this is nonzero, proceed with the full teardown; the object pointer is read from field this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: v1 = *this: load the large object pointer (obj) from field this+0x0. [field:this:0x00000000, source:raw]
    // LOOP: Walk the linked list whose head is obj+0xE5C0 (v1[14704]); per node read the next pointer at node+4 and advance. [field:obj:0x0000E5C0, source:raw]
    // CALL: Per node of the obj+0xE5C0 list: ConditionalFreeByFlagCheck(node) then FreeWrapper_7bcf(node). [callee:0x00582290, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four fields of the obj+0xE5C0 list: v1[14704..14707] (obj+0xE5C0, +0xE5C4, +0xE5C8, +0xE5CC). [field:obj:0x0000E5C0, field:obj:0x0000E5C4, field:obj:0x0000E5C8, field:obj:0x0000E5CC, source:raw]
    // LOOP: Walk the linked list whose head is obj+0xE5B0 (v1[14700]); per node read the next pointer at node+4 and advance. [field:obj:0x0000E5B0, source:raw]
    // CALL: Per node of the obj+0xE5B0 list: ConditionalFreeByFlagCheck(node) then FreeWrapper_7bcf(node). [callee:0x00582290, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four fields of the obj+0xE5B0 list: v1[14700..14703] (obj+0xE5B0, +0xE5B4, +0xE5B8, +0xE5BC). [field:obj:0x0000E5B0, field:obj:0x0000E5B4, field:obj:0x0000E5B8, field:obj:0x0000E5BC, source:raw]
    // LOOP: Free a fixed 104-entry static pointer array: walk v1+14734 backward by 140 dwords per iteration, reading and freeing each element. [source:raw]
    // CALL: Per element of the 104-entry static array: FreeWrapper_7bcf(element). [callee:0x00587BCF, source:raw]
    // LOOP: Walk the flag-linked list whose head is obj+0x7C (v1[31]); per node read the flag byte at node+8 and the next pointer at node+4, advancing through the list while the head is nonzero. [field:obj:0x0000007C, field:*(obj+0x80):0x00000004, guard:1, source:raw]
    // CALL: Per node of the obj+0x7C flag-list: if the flag byte at node+8 is nonzero, FreeWrapper_7bcf(*node) frees the payload; the node itself is always freed with FreeWrapper_7bcf(node). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four fields of the obj+0x7C flag-list: v1[31..34] (obj+0x7C, +0x80, +0x84, +0x88). [field:obj:0x0000007C, field:obj:0x00000080, field:obj:0x00000084, field:obj:0x00000088, source:raw]
    // LOOP: Walk the flag-linked list whose head is obj+0x6C (v1[27]); per node read the flag byte at node+8 and the next pointer at node+4, advancing through the list while the head is nonzero. [field:obj:0x0000006C, field:*(obj+0x70):0x00000004, guard:0, source:raw]
    // CALL: Per node of the obj+0x6C flag-list: if the flag byte at node+8 is nonzero, FreeWrapper_7bcf(*node) frees the payload; the node itself is always freed with FreeWrapper_7bcf(node). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four fields of the obj+0x6C flag-list: v1[27..30] (obj+0x6C, +0x70, +0x74, +0x78). [field:obj:0x0000006C, field:obj:0x00000070, field:obj:0x00000074, field:obj:0x00000078, source:raw]
    // CALL: Call EmptyStub_0170() with no arguments before freeing the object. [callee:0x004B0170, source:raw]
    // RETURN: Return FreeWrapper_7bcf(v1), freeing the large object itself. [callee:0x00587BCF, field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int ComprehensiveLinkedListCleanup(DWORD* this) {
    //       DWORD* v1 = (DWORD*)*this;
    //       if (!v1) return result;
    //       DWORD* v2 = (DWORD*)v1[14704];
    //       while (v2) { DWORD* v3 = v2; v2 = (DWORD*)v2[1]; ConditionalFreeByFlagCheck(v3); FreeWrapper_7bcf(v3); }
    //       v1[14704] = 0; v1[14705] = 0; v1[14706] = 0; v1[14707] = 0;
    //       DWORD* v4 = (DWORD*)v1[14700];
    //       while (v4) { DWORD* v5 = v4; v4 = (DWORD*)v4[1]; ConditionalFreeByFlagCheck(v5); FreeWrapper_7bcf(v5); }
    //       v1[14700] = 0; v1[14701] = 0; v1[14702] = 0; v1[14703] = 0;
    //       DWORD* v6 = v1 + 14734;
    //       int v7 = 104;
    //       do { void* v8 = (void*)*(v6 - 140); v6 -= 140; FreeWrapper_7bcf(v8); --v7; } while (v7);
    //       int v9 = v1[31];
    //       while (v9) {
    //           LPVOID* v10 = (LPVOID*)v9;
    //           bool v11 = *(BYTE*)(v9 + 8) == 0;
    //           v9 = *(DWORD*)(v9 + 4);
    //           if (!v11) FreeWrapper_7bcf(*v10);
    //           FreeWrapper_7bcf(v10);
    //       }
    //       v1[31] = 0; v1[32] = 0; v1[33] = 0; v1[34] = 0;
    //       int v12 = v1[27];
    //       while (v12) {
    //           LPVOID* v13 = (LPVOID*)v12;
    //           bool v11 = *(BYTE*)(v12 + 8) == 0;
    //           v12 = *(DWORD*)(v12 + 4);
    //           if (!v11) FreeWrapper_7bcf(*v13);
    //           FreeWrapper_7bcf(v13);
    //       }
    //       v1[27] = 0; v1[28] = 0; v1[29] = 0; v1[30] = 0;
    //       EmptyStub_0170();
    //       return FreeWrapper_7bcf(v1);
    //   }
    // UNRESOLVED: The fixed 104-entry static pointer array (walked from v1+14734 backward 140 dwords) has no field evidence ref; its base offset is derived only from the raw source.
    // UNRESOLVED: The node+8 flag byte and node+0 payload fields have no field evidence refs; payload free is conditional on the flag being nonzero (inferred from control flow).
    // UNRESOLVED: The loop guards are recorded against the count fields obj+0x74 and obj+0x84 (== 0), while the raw source loops test the head pointers obj+0x6C and obj+0x7C; the exact relationship between the two is unconfirmed.
    // UNRESOLVED: EmptyStub_0170 is a stub; its semantic role here is unknown.
    // UNRESOLVED: The `result` value returned when *this is null is undefined (uninitialized local in the raw source).
}
