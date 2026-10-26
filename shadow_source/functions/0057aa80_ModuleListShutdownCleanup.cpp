// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057AA80
// Canonical corpus name: sub_57AA80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57AA80_0057aa80.c

void UnknownObject::ModuleListShutdownCleanup()
{
    // One-shot module-list teardown. Guarded by a re-entry flag at byte_8D3BFB bit 0: when clear, the flag is set and the module init list (head dword_8D3BFC) is walked by following the next pointer at node+4. Each node whose flag byte at node+12 is set and whose first dword is non-zero has that sub-object destroyed through its vtable via VTableDestructorThenNullPointer and then freed via FreeWrapper_7bcf; every node is freed at the end of its iteration. After the walk the list head and the three trailing state globals (dword_8D3C00, dword_8D3C04, dword_8D3C08) are reset to 0. Returns constant 1 on both paths.
    // GUARD: Re-entry guard: when bit 0 of byte_8D3BFB is set the entire cleanup is skipped and the function returns 1 immediately; otherwise the bit is set to 1 to mark cleanup in progress [global:0x008D3BFB, source:raw]
    // LOOP: Walk the module init list from head dword_8D3BFC, advancing via the next pointer stored at node+4 until a null node terminates the iteration [global:0x008D3BFC, source:raw]
    // GUARD: Per-node destruction only when the flag byte at node+12 is set and the node's first dword (the sub-object pointer) is non-zero [source:raw]
    // CALL: Destroy the sub-object pointer stored at node+0 through its vtable destructor, then null the pointer, via VTableDestructorThenNullPointer [callee:0x0057A4C0, source:raw]
    // CALL: Free the captured sub-object pointer v3 with FreeWrapper_7bcf after its vtable destruction [callee:0x00587BCF, source:raw]
    // CALL: Free the current node v2 with FreeWrapper_7bcf at the end of each iteration (evaluation of the original for-loop increment expression) [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Reset the list head dword_8D3BFC to 0 after the traversal completes [global:0x008D3BFC, source:raw]
    // ASSIGNMENT: Reset the three trailing list-state globals dword_8D3C00, dword_8D3C04 and dword_8D3C08 to 0 after the traversal completes [global:0x008D3C00, global:0x008D3C04, global:0x008D3C08, source:raw]
    // RETURN: Return constant 1 on both the guarded and the cleanup path [function:0x0057AA80, source:raw]

    // Conservative worker pseudocode:
    //   result = 1;
    //   if ((byte_8D3BFB & 1) == 0) {
    //     byte_8D3BFB |= 1;
    //     node = dword_8D3BFC;
    //     while (node) {
    //       next = *(node + 4);
    //       if (*(byte*)(node + 12)) {
    //         sub = *(void**)(node + 0);
    //         if (sub) {
    //           VTableDestructorThenNullPointer(sub);
    //           FreeWrapper_7bcf(sub);
    //         }
    //       }
    //       FreeWrapper_7bcf(node);
    //       node = next;
    //     }
    //     dword_8D3BFC = 0;
    //     dword_8D3C00 = 0;
    //     dword_8D3C04 = 0;
    //     dword_8D3C08 = 0;
    //   }
    //   return result;
    // UNRESOLVED: The roles of the three reset globals dword_8D3C00, dword_8D3C04 and dword_8D3C08 (tail/counter) are labelled DERIVED in prior analysis and cannot be confirmed from this packet alone
    // UNRESOLVED: The exact identity of the list (module init list) and the meaning of the per-node flag byte at node+12 are inferred from the guard structure only
    // UNRESOLVED: No callers are exposed in the packet and on_frame_path is false, so the function's call-site context is unknown
    // UNRESOLVED: The constant return value 1 has no established caller-visible semantic
}
