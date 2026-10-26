// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051B45F
// Canonical corpus name: sub_51B45F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51B45F_0051b45f.c

void UnknownObject::HuffmanDecodeSignedDelta()
{
    // Decodes Huffman-coded delta values with sign adjustment, incrementally modifying existing coefficient values over a position range, with rollback of modified entries on failure.
    // ASSIGNMENT: Compute sign masks from the shift value a1[93] (this+0x174): v36 = 1 << shift and v35 = -1 << shift. [field:this:0x00000174]
    // GUARD: If a1[63] (this+0xFC) is zero the block counter reset is skipped; otherwise, when the decode-state block counter v4[13] (this+0x1C8) is zero, call CounterUpdateWithZero to reset counter state. [guard:0, field:this:0x000000FC, field:this:0x000001C8]
    // CALL: Call CounterUpdateWithZero(a1); if it returns 0, propagate the failure return immediately. [callee:0x0051AEFC]
    // ASSIGNMENT: Capture the bitstream and decode-state snapshot: load the decode-state pointer v4 = a1[101] (this+0x194), read/write pointers from a1[5] (this+0x14 and this+0x18), the saved scalar a1[94] (this+0x178), bit accumulator v4[4] (this+0x1A4), bit count v4[5] (this+0x1A8), remaining count v4[8] (this+0x1B4), and Huffman tree pointer v4[18] (this+0x1DC); also capture loop bounds a1[90] (this+0x168) and a1[91] (this+0x16C) and the output base *a2. [field:this:0x00000194, field:this:0x00000014, field:this:0x00000018, field:this:0x00000178, field:this:0x000001A4, field:this:0x000001A8, field:this:0x000001B4, field:this:0x000001DC, field:this:0x00000168, field:this:0x0000016C]
    // GUARD: If the remaining count v4[8] (this+0x1B4) is nonzero, jump directly to the per-position sign-adjustment loop over the range this+0x168 .. this+0x16C. [field:this:0x000001B4, field:this:0x00000168, field:this:0x0000016C]
    // LOOP: For each position i in the range, resolve the output element v23 = v41 + 2 * dword_5AF778[i] through the global index table; when the element is nonzero, refill the bitstream if needed and apply the sign bit: if ((v46 >> --v8) & 1) add the positive or negative mask (v36 or v35 when the element is negative) to the element. [global:0x005AF778, field:this:0x000001A4, field:this:0x000001A8, field:this:0x00000174]
    // CALL: Call sub_51A794 to refill the bit accumulator when fewer than 1 bit remains; on failure jump to the rollback path. [callee:0x0051A794]
    // STATE_TRANSITION: Decrement the remaining-count state v4[8] (this+0x1B4) once each sign-adjustment pass completes. [field:this:0x000001B4]
    // LOOP: Main decode loop: while the current position does not exceed this+0x16C, take 8 bits (v12 = byte-cast of v46 >> (v8-8)) and index the Huffman table v4[18] (this+0x1DC) at table + 4*v12 + 212; if the table entry is nonzero consume it directly, otherwise fall back to the symbol decoder. [field:this:0x000001DC, field:this:0x000001A4, field:this:0x000001A8]
    // CALL: Call HuffmanArithmeticBitstreamSymbolDecoder for symbols not found in the direct table; a negative result jumps to the rollback path. [callee:0x0051A87E]
    // STATE_TRANSITION: Split the decoded symbol into v14 = symbol >> 4 and v44 = symbol & 0xF; if v44 is zero the decode ends. [source:raw]
    // STATE_TRANSITION: If v44 is neither 0 nor 1, record the invalid extra-bits error by writing 114 to the vtable slot at *a1+20 (this+0x0 vtable, obj+0x14) and invoke the error handler through *a1+4 (obj+0x4) with -1. [field:this:0x00000000, field:obj:0x00000014, field:obj:0x00000004]
    // CALCULATION: Consume one sign bit: v15 = v36 if the bit is set else v35, apply the signed delta to elements reached through dword_5AF778, and record each modified position (v27[v40+1] = dword_5AF778[v16]) plus write the delta value back through the table. [global:0x005AF778, field:this:0x00000174]
    // CALCULATION: If v14 is not 15, compute v43 = 1 << v14, consume v14 more bits when available (v8 >= v14), and combine the read remainder into the next position (v43 += (v21-1) & (v46 >> v8)); if fewer than v14 bits remain, call sub_51A794 to refill first. [field:this:0x00000174]
    // ASSIGNMENT: On successful completion store back the bitstream pointers into a1[5] and a1[5]+4 (this+0x14 and this+0x18), restore a1[94] (this+0x178), decrement the block counter v4[13] (this+0x1C8), and save v46 into v4[4] (this+0x1A4), v43 into v4[8] (this+0x1B4), and v8 into v4[5] (this+0x1A8); return 1. [field:this:0x00000014, field:this:0x00000018, field:this:0x00000178, field:this:0x000001C8, field:this:0x000001A4, field:this:0x000001B4, field:this:0x000001A8]
    // RETURN: On failure, roll back by zeroing every recorded output element v27[j] through the dword_5AF778 table and return 0. [global:0x005AF778]
    // RETURN: Return 1 on success, 0 on bitstream or symbol-decoder failure. [source:raw]

    // Conservative worker pseudocode:
    //   v36 = 1 << a1[93]; v35 = -1 << a1[93];
    //   if (a1[63] == 0 && v4[13] == 0) { if (!CounterUpdateWithZero(a1)) return 0; }
    //   snapshot bitstream + decode state; if (v4[8]) goto sign_adjust_loop;
    //   while (pos <= end) { sym = table lookup or HuffmanArithmeticBitstreamSymbolDecoder; if (sym < 0) goto rollback; split sign/delta; apply signed deltas; record positions; }
    //   success: restore state, decrement v4[13], return 1;
    //   failure: for (j = v40; j > 0; --j) *(_WORD*)(v41 + 2*v27[j]) = 0; return 0;
    // UNRESOLVED: The role of the saved scalar a1[94] (this+0x178) is not clear from this function alone; it is captured and restored without local use.
    // UNRESOLVED: The exact Huffman table layout (direct table at tree+212 and per-symbol table at tree+1236) is only inferred from the two table-index expressions; the tree structure itself is defined by the caller.
    // UNRESOLVED: The dword_5AF778 global index table role is identified as a position mapping for the output coefficient array but its population and layout live outside this function.
}
