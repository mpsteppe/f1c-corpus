// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548890
// Canonical corpus name: sub_548890
// Owner: NamedStringList [DERIVED]
// Raw source: functions/sub_548890_00548890.c

void NamedStringList::findNodeByNameCaseInsensitive()
{
    // Normalizes the input string via sub_589901, then walks a linked list of named string nodes returning the first node whose name compares equal to the normalized input. The per-node flag at +0x9C bit 0x200 selects wide-character vs narrow-character string layout. Returns the matching node pointer, or 0 when the list is empty or the name is not found.
    // ASSIGNMENT: Copy the input argument a2 into the local SrcStr buffer with strcpy. [source:raw]
    // CALL: Call sub_589901(SrcStr) to normalize the needle (e.g. case folding) before comparison. [callee:0x00589901, source:raw]
    // ASSIGNMENT: Read the head node pointer into currentNode from this at offset +0x24 (this[9]). [field:this:0x00000024, source:raw]
    // GUARD: Guard: when the head node pointer at this+0x24 is null, return 0 immediately. [field:this:0x00000024, source:raw]
    // LOOP: Traverse the node linked list via the next-node pointer stored at node offset +0xC0, stopping when it becomes null. [field:this:0x000000C0, field:*(this+0xE4):0x000000C0, source:raw]
    // GUARD: Per-node guard: flag at node offset +0x9C with bit 0x200 set selects the wide-character name path; otherwise the narrow-character path is used. [source:raw]
    // ASSIGNMENT: Copy the current node's name string into the local nodeNameBuffer, byte-by-byte (wide or narrow per the flag), then append a null terminator in the wide-character path. [source:raw]
    // CALCULATION: Compare the normalized needle (SrcStr) against the node name byte-by-byte, producing compareResult v10: -1 if less, +1 if greater, 0 if equal. [source:raw]
    // RETURN: Return the current node pointer when the comparison result is 0 (name match). [source:raw]
    // ASSIGNMENT: Advance currentNode to the next node via the next pointer at node offset +0xC0. [field:this:0x000000C0, source:raw]
    // RETURN: Return 0 when the next-node pointer is null (end of list, no match found). [field:this:0x000000C0, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_548890(void* list, const char* needle) {
    //     char normalized[256];
    //     strcpy(normalized, needle);
    //     sub_589901(normalized);
    //     void* node = *(void**)((char*)list + 0x24);
    //     if (!node) return 0;
    //     while (node) {
    //       if (*(unsigned long*)((char*)node + 0x9C) & 0x200) {
    //         // wide-character name compare path
    //       } else {
    //         // narrow-character name compare path
    //       }
    //       int cmp = compare(nodeName, normalized); /* -1 / 0 / +1 * /
    //       if (cmp == 0) return node;
    //       node = *(void**)((char*)node + 0xC0);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Exact normalization performed by sub_589901 is unknown; case-insensitivity of the match therefore depends on node names being stored in the same normalized form.
    // UNRESOLVED: Field this+0x25 appears in the packet fields table but has no corresponding access in the raw decompiled source; it may be a decomposition artifact of the dword read at this+0x24.
    // UNRESOLVED: The wide-character path null-termination writes through v14 indexed by strlen(v15); the exact buffer relationship between v14 and v15 is a decompiler artifact and its layout is not fully resolved.
    // UNRESOLVED: Whether the node name and needle are compared case-sensitively after normalization, or the nodes store mixed case, is unresolved.
}
