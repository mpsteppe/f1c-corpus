// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052A4A5
// Canonical corpus name: sub_52A4A5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_52A4A5_0052a4a5.c

void UnknownObject::InflateHuffmanTreeBuild()
{
    // Builds the Huffman decoding tables for the DEFLATE literal/length and distance code classes during inflate decompression setup. Allocates a 288-entry work buffer through an allocator function pointer on the inflate state object (a9), runs HuffmanCodingFrequencyTable once per code class using the static base/extra-bit tables (unk_5B0878/unk_5B08F8 for literal/length, unk_5B0978/unk_5B09F0 for distance), and writes DEFLATE error strings into the state object when the code-length data is oversubscribed, incomplete, or empty. Returns 0 on success, -4 on allocation failure, -3 on tree build errors.
    // ASSIGNMENT: Initialize the local code-count/result accumulator v14 to 0 before any table build. [source:raw]
    // CALL: Allocate the 288 * 4 byte work table by calling the allocator function pointer stored at state offset a9+32 with the owner object at a9+40. [source:raw]
    // GUARD: If the allocation returned NULL, return -4 immediately (no work buffer available). [source:raw]
    // CALL: Call HuffmanCodingFrequencyTable for the literal/length tree: code-length array a4, codes a3, count a1, 0x101u, base table unk_5B0878, extra-bits table unk_5B08F8, output table a6, extra arg a8, temp v14, and the freshly allocated work buffer v10. [callee:0x0052A0A1, global:0x005B0878, global:0x005B08F8, source:raw]
    // GUARD: Branch on the first table-build result v12; a non-zero return enters the literal/length error handling path. [source:raw]
    // ASSIGNMENT: If v12 == -3, write the error string "oversubscribed literal/length tree" into the state error slot at a9+24 and go to cleanup. [global:0x005B0AD4, source:raw]
    // ASSIGNMENT: For any other failure (including -4 and the incomplete case), write "incomplete literal/length tree" into a9+24 and normalize the result to -3. [global:0x005B0AB4, source:raw]
    // GUARD: If the literal/length code-count *a4 is zero, treat the tree as incomplete literal/length and enter the error path. [source:raw]
    // CALL: Call HuffmanCodingFrequencyTable for the distance tree: code-length array a5, codes &a3[a1] (after the literal block), count a2, offset 0, base table unk_5B0978, extra-bits table unk_5B09F0, output table a7, extra arg a8, temp v14, and the same work buffer v15. [callee:0x0052A0A1, global:0x005B0978, global:0x005B09F0, source:raw]
    // GUARD: Switch on the distance table-build result v12: -3, -4, -5 and a default case each select a distance-tree error string. [source:raw]
    // ASSIGNMENT: On -3, write "oversubscribed distance tree" into the state error slot at a9+24. [global:0x005B0B38, source:raw]
    // ASSIGNMENT: On -5, write "incomplete distance tree" into a9+24 and force the result to -3. [global:0x005B0B1C, source:raw]
    // ASSIGNMENT: On the default case, write "empty distance tree with lengths" into a9+24 and force the result to -3. [global:0x005B0AF8, source:raw]
    // GUARD: If the distance code-count *a5 is zero while a1 exceeds 0x101, treat the tree as an empty distance tree with lengths. [source:raw]
    // ASSIGNMENT: Success path: set the result v13 to 0. [source:raw]
    // CALL: Release the work buffer by calling the deallocator function pointer at state offset a9+36 with the owner object at a9+40. [source:raw]
    // RETURN: Return v13 (0 on success, -4 on allocation failure, -3 on any tree build error). [source:raw]

    // Conservative worker pseudocode:
    //   int InflateHuffmanTreeBuild(unsigned len, unsigned dlen, int *codes,
    //                               unsigned int *llen, unsigned int *dlen_arr,
    //                               int *ll_table, int *d_table, int extra, int state) {
    //     int *work = ((void *(*)(void*, int, int))(state + 32))(*(void **)(state + 40), 288, 4);
    //     if (!work) return -4;
    //     int r = HuffmanCodingFrequencyTable(llen, codes, len, 0x101,
    //           &unk_5B0878, &unk_5B08F8, ll_table, extra, &n, work);
    //     if (r) {
    //       if (r == -3) { *(int*)(state+24) = "oversubscribed literal/length tree"; goto done; }
    //       if (r != -4) { *(int*)(state+24) = "incomplete literal/length tree"; r = -3; }
    //       goto done;
    //     }
    //     if (!*llen) { *(int*)(state+24) = "incomplete literal/length tree"; r = -3; goto done; }
    //     r = HuffmanCodingFrequencyTable(dlen_arr, codes + len, dlen, 0,
    //           &unk_5B0978, &unk_5B09F0, d_table, extra, &n, work);
    //     if (r) {
    //       switch (r) {
    //         case -3: *(int*)(state+24) = "oversubscribed distance tree"; break;
    //         case -4: break;
    //         case -5: *(int*)(state+24) = "incomplete distance tree"; r = -3; break;
    //         default: *(int*)(state+24) = "empty distance tree with lengths"; r = -3;
    //       }
    //     } else if (!*dlen_arr && len > 0x101) {
    //       *(int*)(state+24) = "empty distance tree with lengths"; r = -3;
    //     }
    //   done:
    //     ((void (*)(void*, void*))(state + 36))(*(void **)(state + 40), work);
    //     return r;
    //   }
    // UNRESOLVED: a9 is an inflate state object whose allocator/deallocator and error-string call conventions (offsets +32, +36, +40, +24) are caller-defined and unverified here.
    // UNRESOLVED: Meaning of a8 and the exact count semantics of a1/a2 vs the *a4/*a5 count values depend on the calling inflate context (sub_527752).
}
