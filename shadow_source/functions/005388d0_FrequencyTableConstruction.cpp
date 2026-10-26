// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005388D0
// Canonical corpus name: FrequencyTableConstruction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FrequencyTableConstruction_005388d0.c

void UnknownObject::FrequencyTableConstruction()
{
    // Deflate-style canonical Huffman code assignment (the FrequencyTableConstruction step). Phase 1 builds a per-length next-code table on the stack (v11): a running base code v6 is advanced for each code length by reading the symbol-count histogram at a3 and doubling, producing the next available code value for each length. Phase 2 walks symbols i in [0, a2]: for each symbol whose code length (word at a1 + 4*i + 2) is non-zero, assigns the next code for that length (v11[length+1], post-incremented), transforms it through sub_539670, and writes the code word at a1 + 4*i. Returns the last transformed code value.
    // LOOP: Phase 1, next-code table: for len in [1, 15], v7 = v6 + histogram-count-at-step (word read via (char*)&v11[++len] + a3 - (char*)&v12), then v6 = 2 * v7 and v11[len] = 2 * v7, so each length's next code doubles the accumulated base. [abi:lead, source:raw]
    // LOOP: Phase 2, symbol walk: for i in [0, a2], read the code length word v9 = *(unsigned short*)(a1 + 4*i + 2); the length word is the material evidence at a1+4*i+2. [caller:0x005383D0, source:raw]
    // GUARD: Symbols with a zero code-length word are skipped; only symbols with a non-zero length word receive a code. [source:raw]
    // ASSIGNMENT: For a non-zero-length symbol: v10 = (unsigned short)v11[v9 + 1]++ fetches the next code for that length and advances the table entry; the assigned code word is stored back at a1 + 4*i. [source:raw]
    // CALL: Call sub_539670(v10) to transform the assigned code value (likely bit reversal for canonical ordering) and use its result as the code word written to a1 + 4*i. [callee:0x00539670, source:raw]
    // RETURN: Return the result of the last sub_539670 transformation, which is also the last code word stored. [function:0x005388D0, source:raw]

    // Conservative worker pseudocode:
    //   // Canonical Huffman code assignment from code lengths (FrequencyTableConstruction).
    //   // a3 points at the per-length symbol-count histogram; the read goes through the
    //   // obfuscated v11/v12 stack-layout expression (count[len-1] per iteration).
    //   v6 = 0;
    //   for (len = 1; len <= 15; ++len) {
    //       v7 = v6 + count(len - 1);   // word read at (char*)&v11[len+1] + a3 - (char*)&v12
    //       v6 = 2 * v7;
    //       v11[len] = v6;              // next code for length len
    //   }
    //   for (i = 0; i <= a2; ++i) {
    //       v9 = word(a1 + 4*i + 2);    // code length of symbol i
    //       if (v9 != 0) {
    //           v10 = v11[v9 + 1]++;
    //           word(a1 + 4*i) = sub_539670(v10);
    //       }
    //   }
    //   return result;
    // UNRESOLVED: The histogram read target is only DERIVED: the source's (char*)&v11[++len] + a3 - (char*)&v12 stack-layout expression resolves to a word at a3 + 2*len - 4, i.e. count[len-2] for the first iterations; the exact off-by-one vs. the standard bl_count[len-1] formula is unresolved.
    // UNRESOLVED: sub_539670's identity is unknown; bit reversal to produce canonical code order is a GUESS from the deflate context, not evidenced in the packet.
    // UNRESOLVED: The a1 table layout (code word at +0, length word at +2, stride 4) is DERIVED from the source's 4*i and 4*i+2 indexing and the caller analysis, not independently proven.
    // UNRESOLVED: Owner object is unknown; no vtable, subsystem, or string evidence.
}
