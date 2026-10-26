// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004024F0
// Canonical corpus name: AIWaypointPathCheckerRenderer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIWaypointPathCheckerRenderer_004024f0.c

void UnknownObject::AIWaypointPathCheckerRenderer()
{
    // AI waypoint-path debug renderer. Loads the waypoint-node linked list head from *(this+0x134), walks the +272 next pointers, validates the chain (cycle / 12000-iteration cap), then renders each edge twice: a colored contact patch when either endpoint's surface-grip-derived color is non-white (sub_402220 + sub_4CEFA0 for batch 9) and an always-drawn white wireframe edge (batch 10), with an alpha literal 2.3509886e-38 stored into the color arrays. When no nodes exist it logs an "Incomplete waypoint path" debug message via StringSplitLoop + DebugLogWrite.
    // ASSIGNMENT: Load the list head: result = *(this+0x134), then first node v3 = *(result+272). [field:this:0x00000134, source:raw]
    // LOOP: Cycle-check walk: while v3 != result follow the +272 next pointer; if the counter exceeds 12000 return early. [source:raw]
    // GUARD: When v3 becomes null during the walk (or the head was null) jump to the error path (LABEL_7). [source:raw]
    // CALL: Prepare render batches: ArraySearchByIDWithCleanup(9) and ArraySearchByIDWithCleanup(10). [callee:0x004CF010, source:raw]
    // CALL: Enter the render section via EmptyStubWithFlagCheck(2, 0). [callee:0x0053AC70, source:raw]
    // CALCULATION: Per edge compute vertex colors from surface grip: v5 = 0xFFFFFF - (CRTFtol(*(v3+280) * -254.0) << 24) and the matching value for the next node. [callee:0x00587BDC, source:raw]
    // CALL: When either endpoint color is non-white (not 0xFFFFFF): sub_402220(this, v3, v9, 0), sub_402220(this, next, v8, 0), then sub_4CEFA0(9, v9, v8) for the colored contact patch. [callee:0x00402220, callee:0x004CEFA0, source:raw]
    // CALL: Always draw the white wireframe edge: sub_402220(this, v3, v11, 1), sub_402220(this, next, v10, 1), set alpha slots v11[6] and v10[6] to 2.3509886e-38, then sub_4CEFA0(10, v11, v10). [callee:0x00402220, callee:0x004CEFA0, source:raw]
    // LOOP: Advance v3 = *(v3+272) and repeat until the walk wraps back to the starting node v7. [source:raw]
    // RETURN: Normal completion returns EmptyStubWithFlagCheck(1, 0). [callee:0x0053AC70, source:raw]
    // CALL: Error path: StringSplitLoop(2, aDDevF119992002_14, 839) prepares a device-path string. [callee:0x004D7A50, global:0x005BE41C, source:raw]
    // CALL: Error path: when StringSplitLoop returned true, DebugLogWrite(&dword_8AD25C, aIncompleteWayp) logs the incomplete-waypoint message. [callee:0x004D7AA0, global:0x008AD25C, global:0x005BE400, source:raw]
    // RETURN: Return result (null on the error path when StringSplitLoop was false). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4024F0(int this) {
    //     int head = *(int*)(this + 0x134);
    //     int node = head ? *(int*)(head + 272) : 0;
    //     int n = 0;
    //     if (node) {
    //       while (node != head) { if (++n > 12000) return head; node = *(int*)(node + 272); if (!node) goto err; }
    //       ArraySearchByIDWithCleanup(9); ArraySearchByIDWithCleanup(10);
    //       int start = node; EmptyStubWithFlagCheck(2, 0);
    //       do {
    //         int c0 = 0xFFFFFF - (CRTFtol(*(float*)(node+280) * -254.0) << 24);
    //         int c1 = 0xFFFFFF - (CRTFtol(*(float*)(*(int*)(node+272)+280) * -254.0) << 24);
    //         if (c0 != 0xFFFFFF || c1 != 0xFFFFFF) { sub_402220(this, node, &v9, 0); sub_402220(this, next, &v8, 0); sub_4CEFA0(9, &v9, &v8); }
    //         sub_402220(this, node, &v11, 1); sub_402220(this, next, &v10, 1);
    //         v11[6] = 2.3509886e-38; v10[6] = 2.3509886e-38; sub_4CEFA0(10, &v11, &v10);
    //         node = *(int*)(node + 272);
    //       } while (node != start);
    //       return EmptyStubWithFlagCheck(1, 0);
    //     }
    //   err:
    //     if (StringSplitLoop(2, aDDevF119992002_14, 839)) return DebugLogWrite(&dword_8AD25C, aIncompleteWayp);
    //     return 0;
    //   }
    // UNRESOLVED: Globals flt_59E45C, dword_8ACEA0 and dword_8B8F24 are flagged by the IDB but do not appear as named references in the decompiled body; the existing analysis labels them physics/render constants (DERIVED).
    // UNRESOLVED: Nested pointer-chain fields *(this+0x134):0x110, *(this+0x134):0x118, *(*(this+0x134)+0x110):0x110, *(*(this+0x134)+0x110):0x118 and the deeper *(*(*(this+0x134)+0x110)+0x110):0x110/0x118 refs come from IDB struct annotation, not the decompiled body, and their role is unverified.
    // UNRESOLVED: The concrete rendering role of sub_402220 and sub_4CEFA0 and the meaning of the 2.3509886e-38 alpha sentinel are not established.
    // UNRESOLVED: Callers sub_4CD8D0 and SpecialFX_Init (004cf070) are recorded; frame-path membership is NOT_FOUND.
}
