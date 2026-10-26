// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D130
// Canonical corpus name: StringCompareLinkedListSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCompareLinkedListSearch_0053d130.c

void UnknownObject::RegistryMatchAndCleanupNode()
{
    // Walks the registry linked list headed by dword_8B8E20 comparing each node's name string (offset 0x14) with a1's name (a1+20) via strcmp. On match, unlinks a1 from the list with DoublyLinkedListNodeRemoval_d3a0, calls AudioResourceCleanup, and, if a1 is non-null, calls EmptyStub_7470 then frees the node via FreeWrapper_7bcf. Returns early (no cleanup) when the head is null or the list end is reached without a match.
    // ASSIGNMENT: Load the registry list head: v1 = dword_8B8E20. [global:0x008B8E20, source:raw]
    // GUARD: If the list head dword_8B8E20 is non-null, traverse the list. [global:0x008B8E20, source:raw]
    // LOOP: while strcmp((const char *)(v1 + 20), a1 + 20): walk nodes until the name at offset 0x14 equals a1's name. [abi:lead, source:raw]
    // CALCULATION: Advance to the next node: v1 = *(_DWORD *)(v1 + 2160); the node's next pointer lives at offset 2160. [source:raw]
    // GUARD: If the next pointer v1 becomes null (end of list), return without any cleanup. [source:raw]
    // CALL: DoublyLinkedListNodeRemoval_d3a0(a1): unlink the matching node from the registry linked list. [callee:0x0053D3A0, source:raw]
    // CALL: AudioResourceCleanup(a1): release audio resource fields owned by the node. [callee:0x00552760, source:raw]
    // GUARD: Proceed to stub and free only if a1 is non-null. [source:raw]
    // CALL: EmptyStub_7470(a1): call the empty stub on the node. [callee:0x00557470, source:raw]
    // CALL: FreeWrapper_7bcf(a1): heap-free the node. [callee:0x00587BCF, source:raw]
    // RETURN: Implicit return when the list ends before a name match (next pointer null). [source:raw]

    // Conservative worker pseudocode:
    //   void sub_53D130(char *node) {
    //     int cur = dword_8B8E20;
    //     if (dword_8B8E20) {
    //       while (strcmp((const char *)(cur + 20), node + 20)) {
    //         cur = *(_DWORD *)(cur + 2160);
    //         if (!cur) return;
    //       }
    //       DoublyLinkedListNodeRemoval_d3a0(node);
    //       AudioResourceCleanup(node);
    //       if (node) { EmptyStub_7470(node); FreeWrapper_7bcf(node); }
    //     }
    //   }
    // UNRESOLVED: The ABI lead names the search 'matching wide string', but the code compares narrow strings with strcmp; the discrepancy is unresolved.
    // UNRESOLVED: Node type and meaning of the name field at offset 0x14 and the next pointer at offset 2160 are inferred from usage and not independently confirmed.
}
