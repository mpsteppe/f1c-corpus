// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B46F0
// Canonical corpus name: QuadrupleListCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadrupleListCleanup_004b46f0.c

void UnknownObject::QuadrupleListCleanup()
{
    // Cleanup routine that first calls PhysicsObjectListManager (0x004B4E10), then frees four linked lists of physics/collision nodes and zeroes their 4-dword head slots. Each node carries a next pointer at +4 and a type/active byte at +8; nodes with a non-zero type byte also free the buffer pointer at the node base (+0) via FreeWrapper_7bcf, and every node struct is freed. The four 16-byte slots are zeroed across the loop, spanning byte offsets 0x70-0xAC. Returns 0. Called by SpriteOverlayListCleanup (0x004B6130).
    // CALL: PhysicsObjectListManager (0x004B4E10) invoked first to manage/pre-process the physics object list [callee:0x004B4E10, source:raw]
    // CALCULATION: Set up the walk: v2 = this + 44 (dword index 44, byte +0xB0) and outer counter v7 = 4 [source:raw]
    // LOOP: Four iterations total; each iteration reads the list head at *(v2 - 4), advances v2 by 16 bytes, and after the inner walk zeroes the 4-dword slot now at v2 (v2[0]..v2[3]) [source:raw]
    // LOOP: Inner walk: while the node pointer v3 is non-null, read the type byte at node +8 into v5 and the next pointer at node +4, and advance v3 to that next node [source:raw]
    // GUARD: If the node type byte at +8 is non-zero (v5 false), the buffer at the node base (+0) is freed before the node itself [callee:0x00587BCF, source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) invoked to free the node's buffer when the type byte is non-zero, and always to free the node struct itself [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: After each inner walk the 4-dword head slot (v2[0], v2[1], v2[2], v2[3]) is zeroed [source:raw]
    // LOOP: Outer loop decrements v7 from 4 and repeats until v7 equals 1, giving exactly four slot cleanups; the four zeroed slots span byte offsets 0x70-0xAC [source:raw]
    // RETURN: Returns 0 once all four lists are processed [function:0x004B46F0, source:raw]
    // CALL: Called by SpriteOverlayListCleanup (0x004B6130) as part of overlay/sprite list teardown [caller:0x004B6130, source:raw]

    // Conservative worker pseudocode:
    //   PhysicsObjectListManager();
    //   v2 = this + 44;
    //   v7 = 4;
    //   do {
    //     v3 = *(v2 - 4);
    //     v2 -= 4;
    //     while (v3) {
    //       v4 = (LPVOID*)v3;
    //       v5 = (*(_BYTE*)(v3 + 8) == 0);
    //       v3 = *(_DWORD*)(v3 + 4);
    //       if (!v5) FreeWrapper_7bcf(*v4);
    //       FreeWrapper_7bcf(v4);
    //     }
    //     *v2 = 0; v2[1] = 0; v2[2] = 0; v2[3] = 0;
    //     --v7;
    //   } while (v7 != 1);
    //   return 0;
    // UNRESOLVED: The packet fact table reports this-fields at +0xB0/+0xB4/+0xB8/+0xBC, but the decompiled pointer arithmetic (v2 = this + 44, then v2 -= 4 before zeroing v2[0..3]) places the four zeroed 16-byte slots in the +0x70 to +0xAC range; the +0xB0-0xBC group is never written by this function as decompiled, so the fact-table offsets remain unmatched
    // UNRESOLVED: Node layout semantics (+4 next, +8 type/active byte, base buffer pointer) are inferred from the decompile; the exact meaning of the type byte and the four list roles (head/tail/next pointers) is not named by this function
    // UNRESOLVED: The intermediate zeroing order walks the four slots in descending byte order (highest list slot first, lowest last); whether this ordering is meaningful is not established
}
