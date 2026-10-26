// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053A4D0
// Canonical corpus name: sub_53A4D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53A4D0_0053a4d0.c

void UnknownObject::HuffmanLiteralDistTableBuild()
{
    // Builds the literal/length and distance Huffman decode tables used by DEFLATE-style decompression. Allocates a 288-entry working table through a vtable allocator on the context object a9, invokes sub_53A020 twice (once for literal/length codes with a 0x101 symbol cap, once for distance codes), and maps every failure code to a descriptive error string stored on the context at offset 24. Returns 0 on success or a negative error code.
    // ASSIGNMENT: Initialize the local symbol count v19 to 0 and stash the second symbol count a2 before allocating. [source:raw]
    // CALL: Allocate a 288-entry working table of 4-byte entries through the context vtable allocator at offset 32, passing the allocator handle stored at offset 40. [source:raw]
    // GUARD: If the allocation returns NULL, fail immediately with -4. [source:raw]
    // CALL: First sub_53A020 invocation builds the literal/length Huffman decode table from a3, capped at 0x101 symbols, using the code-length metadata arrays unk_5B8718 and unk_5B8798; the literal count is written through a4. [callee:0x0053A020, global:0x005B8718, global:0x005B8798, source:raw]
    // GUARD: If the first build returns -3 (oversubscribed literal/length codes), store the error string aOversubscribed_4 on the context, free the working table through the context vtable at offset 36, and return -3. [global:0x005DBB0C, source:raw]
    // GUARD: If the first build returns -4, fall through to the shared cleanup path which returns the retained error code. [source:raw]
    // ASSIGNMENT: Any other nonzero first-build result, or a zero literal count *a4, is treated as an incomplete table: store the error string aIncompleteLite_0 on the context and coerce the result to -3. [global:0x005DBAEC, source:raw]
    // GUARD: Proceed to the distance table only when the first build succeeded and the literal count *a4 is nonzero. [source:raw]
    // CALL: Second sub_53A020 invocation builds the distance Huffman decode table from &a3[a1] using the metadata arrays unk_5B8818 and unk_5B8890; the distance count is written through a5. [callee:0x0053A020, global:0x005B8818, global:0x005B8890, source:raw]
    // GUARD: On distance-build success (case 0), if the distance count *a5 is nonzero or the symbol limit a1 is at most 0x101, free the working table and return 0. [source:raw]
    // GUARD: If the distance build returns -3 (oversubscribed distance codes), store the error string aOversubscribed_3 on the context, free the working table, and return -3. [global:0x005DBB70, source:raw]
    // GUARD: If the distance build returns -5 (incomplete distance codes), store the error string aIncompleteDist_0 on the context and coerce the result to -3. [global:0x005DBB54, source:raw]
    // GUARD: Any other nonzero distance-build result that is not -4 is treated as an empty distance table: store the error string aEmptyDistanceT_0 on the context and coerce the result to -3. [global:0x005DBB30, source:raw]
    // RETURN: The shared cleanup path frees the working table through the context vtable at offset 36 and returns the retained error code. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_53A4D0(unsigned int lit_limit, unsigned int dist_limit, int *lengths,
    //                  unsigned int *lit_count, unsigned int *dist_count, ...)
    //   {
    //     unsigned int *work = ctx->vtable_alloc(ctx->allocator, 288, 4);
    //     if (!work) return -4;
    //     int r = sub_53A020(lengths, lit_limit, 0x101, &unk_5B8718, &unk_5B8798,
    //                        a6, lit_count, a8, &v19, work);
    //     if (r) {
    //       if (r == -3) { ctx->error = &aOversubscribed_4; ctx->vtable_free(ctx->allocator, work); return -3; }
    //       if (r == -4) return cleanup(r);
    //       ctx->error = &aIncompleteLite_0; return cleanup(-3);
    //     }
    //     if (!*lit_count) { ctx->error = &aIncompleteLite_0; return cleanup(-3); }
    //     r = sub_53A020(&lengths[lit_limit], dist_limit, 0, &unk_5B8818, &unk_5B8890,
    //                    a7, dist_count, a8, &v19, work);
    //     if (r == 0) {
    //       if (*dist_count || lit_limit <= 0x101) { ctx->vtable_free(ctx->allocator, work); return 0; }
    //       ctx->error = &aEmptyDistanceT_0; return cleanup(-3);
    //     }
    //     if (r == -3) { ctx->error = &aOversubscribed_3; ctx->vtable_free(ctx->allocator, work); return -3; }
    //     if (r == -5) { ctx->error = &aIncompleteDist_0; return cleanup(-3); }
    //     if (r != -4) { ctx->error = &aEmptyDistanceT_0; return cleanup(-3); }
    //     return cleanup(r);
    //   }
    // UNRESOLVED: The context object a9 (vtable allocator at offset 32, free at offset 36, error string at offset 24, allocator handle at offset 40) has no identified type; the owner stays unknown.
    // UNRESOLVED: The exact meaning of the 0x101 symbol cap and the a1 limit parameter relative to the DEFLATE literal/length alphabet is not established.
    // UNRESOLVED: The internal layout of the tables built by sub_53A020 and the metadata arrays unk_5B8718/unk_5B8798/unk_5B8818/unk_5B8890 is not specified here.
}
