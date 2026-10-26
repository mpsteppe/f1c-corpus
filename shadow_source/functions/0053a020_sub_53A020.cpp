// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053A020
// Canonical corpus name: sub_53A020
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53A020_0053a020.c

void UnknownObject::sub_53A020()
{
    // Canonical-Huffman table builder plus decoder-node construction. Phase 1 counts the occurrence of each code length (values 1..15) in an array a1 of a2 symbols, computes min/max nonzero lengths, checks for canonical-code overflow (returns -3), builds cumulative length offsets, and orders symbols by code length into a10. Phase 2 walks the code space and constructs a linked table of 16-bit decoder nodes (symbol byte + bit-length byte) written into 8-byte slots, resolving symbol/byte values through lookup tables a4 (dword) and a5 (byte) with base a3, emitting an escape marker when a code is shorter than the min length. Node output accumulates into a6/a9 and aborts at a 0x5A0 entry cap. Returns 0 on clean completion, -4 on fallthrough, -5 on invalid residual state. Callers: sub_539F70 and sub_53A4D0.
    // ASSIGNMENT: Initialize running state: v10 = a2 (symbol count), v65 = a2, v59 = a1, v71 = 0, and zero the 15-dword code-length histogram v72. [source:raw]
    // LOOP: Histogram pass: read each symbol code length *a1++ and increment v72[length - 1], decrementing the count a2 until it reaches zero. [source:raw]
    // GUARD: Early out when the original symbol count is zero: write 0 to *a6 and *a7 and return 0. [source:raw]
    // LOOP: Scan the histogram upward from length 1 to find the first nonzero entry, giving the minimum code length v15 (break at the first nonzero cell). [source:raw]
    // LOOP: Scan the histogram downward from length 15 to find the last nonzero entry, giving the maximum code length v16. [source:raw]
    // CALCULATION: Clamp the initial code-width budget v14 = *a7 into the [min_length, max_length] range; persist the clamped value back to *a7. [source:raw]
    // LOOP: Canonical code accumulation: carry i = 1 << length, subtracting each histogram count (v18 = i - v72[length - 1]); return -3 as soon as a running count goes negative (canonical code overflow). [source:raw]
    // CALCULATION: Final-width adjustment for the maximum length: v20 = i - v72[v16 - 1]; return -3 if it goes negative. [source:raw]
    // LOOP: Build cumulative offsets v74[j] as the running sum of histogram counts below each length, seeding the per-length start index into the symbol ordering. [source:raw]
    // LOOP: Order the symbols by code length: for each symbol, place it at a10[v74[length - 1]] and advance that length's offset, yielding the length-ordered symbol table. [source:raw]
    // LOOP: Decoder-node construction: walk the code space; for each node read the symbol from the a4 dword table at index 4 * (symbol - a3) and a byte from the a5 byte table, encode symbol + bit-length into a 16-bit node, and write it into 8-byte slots at the current node address; emit the escape marker (LOBYTE -64) when no valid table entry applies. [source:raw]
    // GUARD: Node-cap guard: if the running node count *a9 would exceed 0x5A0 entries, abort the construction loop. [source:raw]
    // STATE_TRANSITION: Link completed nodes into the chain: record the node address either into *a6 (first node) or into the previous node's back-reference slot, advancing *a9. [source:raw]
    // RETURN: Return 0 on a clean finish, -4 on fallthrough from the construction loop, or -5 when the residual code space is invalid (v20 nonzero and max length above 1). [source:raw]

    // Conservative worker pseudocode:
    //   // Canonical Huffman code-length table build + table-driven decoder node construction.
    //   // a1: symbol/code-length array (values 1..15), a2: count, a10: symbol ordering output,
    //   // a4: dword symbol table, a5: byte table, a3: symbol base, a6/a9: node-list output and count.
    //   int sub_53A020(int* lengths, int count, unsigned base, int* dtab, int* btab,
    //                   int* out_first, unsigned* out_count, int param8, unsigned* out2, unsigned* order) {
    //     ... histogram, canonical overflow check (return -3), symbol ordering into order, ...
    //     ... node construction bounded at 0x5A0 entries, return 0 / -4 / -5 ...
    //   }
    // UNRESOLVED: Semantic roles of parameters a4, a5, a6, a7, a8, a9, a10 outside the Huffman-table reading are caller-defined; the exact meaning of the 80/96 offsets applied to the a5 byte values and the 0x5A0 cap is not established.
    // UNRESOLVED: The linked node layout (8-byte stride, back-reference slot) is inferred from pointer arithmetic only; no callee evidence corroborates the node structure.
}
