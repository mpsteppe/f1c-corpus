// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052A426
// Canonical corpus name: sub_52A426
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_52A426_0052a426.c

void UnknownObject::InflateBuildCodeLengthTree()
{
    // DEFLATE dynamic-block code-length tree builder. Allocates a 19-entry workspace through the stream allocator, calls HuffmanCodingFrequencyTable (0x0052A0A1) with the 19 code lengths and max-code-bit count 0x13 to build the code-length Huffman table, remaps the two tree-construction failure results onto the zlib-style error strings 'oversubscribed dynamic bit lengths tree' / 'incomplete dynamic bit lengths tree' written into the stream error slot, frees the workspace through the stream deallocator, and returns 0 on success, -4 on allocation failure, or -3 on tree error. Called by sub_527752 (InflateDecompress) from the dynamic-block code-length reading state.
    // ASSIGNMENT: Initialize the by-ref status slot v10 = 0 before calling the tree builder. [source:raw]
    // CALL: Allocate the workspace via the stream allocator: v6 = (a5+32)(a5+40, 19, 4) i.e. allocator(owner, 19 elements, 4 bytes); the 19 * 4-byte size matches the 19 code lengths (0x13). [source:raw]
    // GUARD: If the allocator returned null (v6 == 0), return -4 (memory failure). [source:raw]
    // CALL: Call HuffmanCodingFrequencyTable(a2, a1, 0x13u, 0x13u, 0, 0, a3, a4, &v10, v6) to build the code-length Huffman decode table from the 19 code lengths; the return code is captured in v8/v9. [callee:0x0052A0A1, source:raw]
    // GUARD: If the tree builder returned -3, write the error string 'oversubscribed dynamic bit lengths tree' (global aOversubscribed, 0x005B0A8C) into the stream error slot a5+24. [global:0x005B0A8C, source:raw]
    // GUARD: Otherwise, if the tree builder returned -5 or the produced bit count *a2 is zero, write the error string 'incomplete dynamic bit lengths tree' (global aIncompleteDyna, 0x005B0A68) into the stream error slot a5+24 and force the return code to -3. [global:0x005B0A68, source:raw]
    // CALL: Release the workspace through the stream deallocator: (a5+36)(a5+40, v11) i.e. deallocator(owner, workspace). [source:raw]
    // RETURN: Return v9: 0 on success, -3 on a tree-construction error, -4 on allocation failure. [function:0x0052A426, source:raw]

    // Conservative worker pseudocode:
    //   // Build the DEFLATE code-length Huffman tree (19 lengths).
    //   // a1 = code lengths, a2 = bit count in/out, a3 = output table,
    //   // a4 = max code bits, a5 = stream (a5[6] error slot, a5[8] alloc,
    //   // a5[9] dealloc, a5[10] owner).
    //   int BuildCodeLengthTree(a1, a2, a3, a4, a5) {
    //     status = 0;
    //     work = a5[8](a5[10], 19, 4);   // alloc workspace
    //     if (!work) return -4;
    //     r = HuffmanCodingFrequencyTable(a2, a1, 0x13, 0x13, 0, 0, a3, a4, &status, work);
    //     if (r == -3) {
    //       a5[6] = "oversubscribed dynamic bit lengths tree";
    //     } else if (r == -5 || !*a2) {
    //       a5[6] = "incomplete dynamic bit lengths tree";
    //       r = -3;
    //     }
    //     a5[9](a5[10], work);           // free workspace
    //     return r;
    //   }
    // UNRESOLVED: The exact argument contract of HuffmanCodingFrequencyTable (0x0052A0A1) is caller-side here; the parameter ordering is preserved verbatim from the raw call (a2 first, a1 second) but the callee's own signature and the meaning of its constant 0x13 / 0x13 and two zero arguments are not in this packet.
    // UNRESOLVED: The stream-object slot roles (a5[6] error string, a5[8] allocator, a5[9] deallocator, a5[10] owner) are inferred from how a5+24/a5+32/a5+36/a5+40 are used; the same object layout is corroborated by the caller sub_527752 (InflateDecompress) but not proven by this packet alone.
    // UNRESOLVED: The !*a2 (zero bit count) check is treated as an incomplete-tree condition matching the 'incomplete dynamic bit lengths tree' message, but the exact failure semantics of the -5 return code are established only by the callee's own reconstruction.
}
