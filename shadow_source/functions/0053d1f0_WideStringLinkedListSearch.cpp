// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D1F0
// Canonical corpus name: WideStringLinkedListSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WideStringLinkedListSearch_0053d1f0.c

void UnknownObject::WideStringLinkedListSearch()
{
    // Linked-list name lookup. Reads the global head pointer dword_8B8E20 and, if it is non-null, walks the list node by node via a next-pointer stored at node+2160, comparing each node's name string at node+20 against the input string a1 (strcmp). Returns the first matching node pointer, or 0 when the list is empty, the name is absent, or the chain ends. Called by ten renderer/font callers including FontSurfaceLookupDispatch (0053D260) and SurfaceSizeQuery (004DC600).
    // ASSIGNMENT: Load the global list head pointer dword_8B8E20 into the cursor v1. [global:0x008B8E20, source:raw]
    // GUARD: When the head pointer dword_8B8E20 is null the list is empty; take the empty-list return path. [global:0x008B8E20, source:raw]
    // RETURN: Empty-list early return 0. [source:raw]
    // LOOP: Iterate over linked-list nodes while the current node name does not match a1. [source:raw]
    // CALCULATION: String-compare the current node's name at v1+20 against the input string a1 (strcmp). [source:raw]
    // ASSIGNMENT: On mismatch, advance to the next node through the link pointer stored at v1+2160. [source:raw]
    // GUARD: If the next node pointer is null the requested name is absent; take the not-found return path. [source:raw]
    // RETURN: Return the pointer to the matching node (v1), or 0 when traversal ends without a match. [source:raw]
    // CALL: Invoked by ten renderer/font callers (SurfaceSizeQuery, ScaledTextureRender, FrameRateCounterInitReset, ConditionalInitBranch, FontSurfaceLookupDispatch, GuardedDelegation, sub_53D2E0, ConditionalFontSurfaceCall, sub_4989E0, sub_49F870). [caller:0x004989E0, caller:0x0049F870, caller:0x004DC600, caller:0x004DC660, caller:0x004F8EA0, caller:0x004F8F10, caller:0x0053D260, caller:0x0053D2B0, caller:0x0053D2E0, caller:0x0053D310]

    // Conservative worker pseudocode:
    //   int sub_53D1F0(const char* a1) {
    //     int v1 = dword_8B8E20;
    //     if (!dword_8B8E20) return 0;
    //     while (strcmp((const char*)(v1 + 20), a1)) {
    //       v1 = *(int*)(v1 + 2160);
    //       if (!v1) return 0;
    //     }
    //     return v1;
    //   }
    // UNRESOLVED: Node object layout is unknown: only the name field at offset 20 and the next-node link at offset 2160 are evidenced here.
    // UNRESOLVED: Canonical label is 'WideString' but the raw source uses char* strcmp; the actual string encoding is unverifiable from this packet.
    // UNRESOLVED: Meaning of the returned node pointer (which surface/font object it identifies) depends on the ten caller contexts.
}
