// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051A794
// Canonical corpus name: sub_51A794
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51A794_0051a794.c

void UnknownObject::BitstreamReaderWithEscape()
{
    // Reads bytes from a buffer into a bit accumulator, handling 0xFF escape sequences (start-code emulation) and refilling the buffer through a callback vtable when the current buffer runs out. The accumulator a2 is built by shifting left 8 bits and OR-ing each consumed byte; the bit count a3 advances by 8 per byte. When the bit count reaches the 25-bit capacity, or the output bit budget a4, the current cursor and accumulators are flushed back into the state object and 1 is returned. On a failed refill the function returns 0. An escape-underflow condition (a 0xFF run interrupted by a null byte) signals an error once through the parent context vtable (113 written into the error slot, error callback invoked with -1) and latches the this+0x20 flag.
    // ASSIGNMENT: Save the current buffer cursor state: v4 = a1[1] (bytes remaining in the current buffer) and v5 = *a1 (current byte pointer). [field:this:0x00000000, field:this:0x00000004]
    // GUARD: Top-of-loop capacity check: when the bit count a3 >= 25 the accumulator is full and the state is flushed (LABEL_20). [source:raw]
    // ASSIGNMENT: State flush (LABEL_20): write the bit accumulator into a1[3], the bit count into a1[6], restore *a1 = v5 and a1[1] = v4, then return 1. [field:this:0x0000000C, field:this:0x00000018, field:this:0x00000000, field:this:0x00000004, source:raw]
    // GUARD: When the saved escape byte a1[2] is non-zero, skip the byte-reading path and emit it directly (goto LABEL_14). [field:this:0x00000008, source:raw]
    // LOOP: Infinite byte-consumption loop; it terminates only through the a3 >= 25 / a3 >= a4 flushes, a failing refill (return 0), or a successful break-and-resume path. [source:raw]
    // CALCULATION: Read one byte: v7 = *v5, then decrement v4 (bytes remaining) and advance v5. [source:raw]
    // GUARD: 0xFF escape handling: while the consumed byte is 255 the reader consumes the escape run; when v4 reaches zero it refills the buffer by calling the refill callback (entry +12 of the refill table, modeled by the deterministic fields as the table reachable through this+0x30 with the call entry at +0xC and the double-indirected function pointer at *(this+0x30)+0x0) and returns 0 when that callback reports failure. [field:*(this+0x1C):0x00000014, field:*(this+0x30):0x0000000C, field:*(*(this+0x30)+0x0):0x00000000, source:raw]
    // ASSIGNMENT: After a non-255 byte v9 terminates the escape run, save it as the pending byte a1[2] for the next iteration (or force v7 = 255 when v9 is a null byte, i.e. an unterminated escape run). [field:this:0x00000008, source:raw]
    // GUARD: Output budget check: when the bit count a3 >= a4 the accumulated bits must be flushed immediately (goto LABEL_20). [source:raw]
    // ASSIGNMENT: Escape-underflow error signaling: when the error flag *a1[8] is unset, write 113 into the parent-context error slot (the deterministic field *(this+0x1C)+0x14), invoke the parent-context error callback (vtable entry at *(this+0x1C)+0x4) with argument -1, and set *a1[8] = 1 so the signal fires only once. [field:this:0x0000001C, field:*(this+0x1C):0x00000014, field:*(this+0x1C):0x00000004, field:this:0x00000020, source:raw]
    // CALCULATION: Bit accumulation: on the normal emit path v7 is 0 (the 255-forced null-escape case keeps 255), then a3 += 8 and a2 = v7 | (a2 << 8), packing the consumed byte into the accumulator. [source:raw]
    // STATE_TRANSITION: Buffer-exhausted path: when v4 is zero and no pending escape byte exists, call the refill callback; on success reload v5 = *v8 and v4 = v8[1] from the refill table and resume byte reading (goto LABEL_6), on failure return 0. [field:*(this+0x30):0x0000000C, source:raw]
    // RETURN: Return 1 after a successful state flush, or 0 when the refill callback reports failure. [source:raw]

    // Conservative worker pseudocode:
    //   remaining = a1[1]; cur = *a1;
    //   loop:
    //     if (a3 >= 25) { a1[3] = a2; a1[6] = a3; *a1 = cur; a1[1] = remaining; return 1; }
    //     if (a1[2]) goto emit;
    //     if (remaining == 0) { if (!refill()) return 0; }
    //     byte = *cur; remaining--; cur++;
    //     if (byte != 255) goto emit;
    //     do {
    //       if (remaining == 0) {
    //         if (!refill()) return 0;
    //         cur = *table; remaining = table[1];
    //       }
    //       byte = *cur; remaining--; cur++;
    //     } while (byte == 255);
    //     if (byte == 0) { byte = 255; goto emit; }
    //     a1[2] = byte;
    //   emit:
    //     if (a3 >= a4) { a1[3] = a2; a1[6] = a3; *a1 = cur; a1[1] = remaining; return 1; }
    //     if (!*a1[8]) {
    //       *(*(a1[7]) + 20) = 113;
    //       (*(void(**)(void*,int))(*(a1[7]) + 4))(a1[7], -1);
    //       *a1[8] = 1;
    //     }
    //     byte = 0;
    //     a3 += 8;
    //     a2 = byte | (a2 << 8);
    //     goto loop;
    // UNRESOLVED: The raw source resolves the refill table through the parent-context double indirection (*((_DWORD*)a1[7] + 5) + 12, i.e. the table pointer at parent+0x14 and entry +12), while the deterministic fields model the same refill table as fields of this+0x30 (entries at +0x0, +0x4, +0xC plus the double-indirect function pointer at *(this+0x30)+0x0). The exact relationship between the parent+0x14 table and the this+0x30 table is not resolved by the packet.
    // UNRESOLVED: The field obj+0x0 is not directly referenced by the raw source and its role is unknown.
    // UNRESOLVED: The legacy ABI name 'Unidentified_Logic_51a794' (abi:lead) is not meaningful; the proposed name follows the existing analysis fill (BitstreamReaderWithEscape).
    // UNRESOLVED: The parent-context class (a1[7]) and the concrete refill/error callback identities are not evidenced by the packet.
}
