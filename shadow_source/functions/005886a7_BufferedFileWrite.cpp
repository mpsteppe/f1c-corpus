// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005886A7
// Canonical corpus name: sub_5886A7
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5886A7_005886a7.c

void UnknownObject::BufferedFileWrite()
{
    // Buffered writer over a file/stream context (a4). Writes a3 elements of a2 bytes each from a1, returning the number of elements actually written. Chooses a block size of 4096, or the context's own block field at ctx+24 when the buffered flag (ctx+12 & 0x10C) is set. Fills the internal buffer (ctx+0) through MemoryCopy_cc00 up to the pending count at ctx+4 when the write-back flag (ctx+12 & 0x108) is active, byte-aligns via sub_58CF35, flushes via BufferFlushWrite, and falls back to a direct raw write through sub_58E22B on the handle at ctx+16, setting error flag 0x20 in ctx+12 on failure. Returns the count of fully written elements (total minus remaining, divided by element size). Called by FileReadWrapperWithLock (00588678) and StringWriteToFile (0058BABB) on the frame path.
    // CALCULATION: v4 = v5 = a3 * a2 computes the total byte count; when it is zero the function returns 0 immediately. [source:raw]
    // CALCULATION: Select the block size v13: ctx+24 when the flag word (ctx+12 & 0x10C) is non-zero, otherwise the default 4096. [source:raw]
    // GUARD: When the write-back flag (ctx+12 & 0x108) is set and the pending count at ctx+4 is non-zero, drain into the internal buffer. [source:raw]
    // CALL: MemoryCopy_cc00(*(DWORD*)ctx, a1, v9) copies min(remaining, pending) bytes from a1 into the internal buffer at ctx+0. [callee:0x0058CC00, field:this:0x00000000, source:raw]
    // CALCULATION: Advance the write state: ctx+4 -= v9, ctx+0 += v9, v5 -= v9, a1 += v9; if v5 reaches zero return a3 (all elements written). [source:raw]
    // LOOP: Byte-alignment loop: while v5 < v13, consume bytes through sub_58CF35 until the remaining count reaches a block boundary. [source:raw]
    // CALL: sub_58CF35(*a1, ctx) processes the next byte; a return of -1 branches to the error path. [callee:0x0058CF35, source:raw]
    // CALCULATION: After each consumed byte, refresh v13 = ctx+24 and clamp it to a minimum of 1. [source:raw]
    // RETURN: When v5 reaches zero inside the loop, return a3 (complete element count). [source:raw]
    // CALL: BufferFlushWrite(ctx) flushes pending buffered bytes; when the write-back flag is clear or the flush fails, fall through to a direct raw write. [callee:0x0058A05A, source:raw]
    // CALCULATION: v10 = v5 - v5 % v13 (or v5 when v13 is zero) sizes the direct-write chunk as a multiple of the block size. [source:raw]
    // CALL: sub_58E22B(*(DWORD*)(ctx + 16), a1, v10) writes the chunk directly through the file handle at ctx+16. [callee:0x0058E22B, source:raw]
    // STATE_TRANSITION: On failure (v11 == -1 or a short write where v11 < v10) set the error flag: ctx+12 |= 0x20, and return the partially written element count (v4 - v5) / a2. [source:raw]
    // RETURN: Error path returns the number of elements fully written so far: (v4 - v5) / a2. [source:raw]
    // CALL: Invoked by FileReadWrapperWithLock (00588678) and StringWriteToFile (0058BABB). [caller:0x00588678, caller:0x0058BABB, function:0x005886A7]

    // Conservative worker pseudocode:
    //   unsigned int sub_5886A7(char *a1, unsigned int elem_size, int count, void *ctx) {
    //     unsigned int total = (unsigned int)count * elem_size;
    //     unsigned int remaining = total;
    //     if (total == 0) return 0;
    //     unsigned int block = (*(unsigned short*)(ctx + 12) & 0x10C) != 0 ? *(unsigned int*)(ctx + 24) : 4096;
    //     while (1) {
    //       if ((*(unsigned int*)(ctx + 12) & 0x108) != 0) {
    //         unsigned int pending = *(unsigned int*)(ctx + 4);
    //         if (pending != 0) {
    //           unsigned int n = remaining < pending ? remaining : pending;
    //           MemoryCopy_cc00(*(unsigned int*)ctx, a1, n);
    //           *(unsigned int*)(ctx + 4) -= n;
    //           *(unsigned int*)ctx += n;
    //           remaining -= n; a1 += n;
    //           if (remaining == 0) return count;
    //         }
    //       }
    //       if (remaining >= block) break;
    //       if (sub_58CF35(*a1, ctx) == -1) goto error;
    //       ++a1; --remaining;
    //       block = *(unsigned int*)(ctx + 24);
    //       if (block <= 0) block = 1;
    //       if (remaining == 0) return count;
    //     }
    //     if ((*(unsigned int*)(ctx + 12) & 0x108) == 0 || !BufferFlushWrite(ctx)) {
    //       unsigned int chunk = block != 0 ? remaining - remaining % block : remaining;
    //       unsigned int written = sub_58E22B(*(unsigned int*)(ctx + 16), a1, chunk);
    //       if (written == -1 || (a1 += written, remaining -= written, written < chunk)) {
    //         *(unsigned int*)(ctx + 12) |= 0x20;
    //         return (total - remaining) / elem_size;
    //       }
    //       if (remaining == 0) return count;
    //     }
    //   error:
    //     return (total - remaining) / elem_size;
    //   }
    // UNRESOLVED: The prelabel's cluster_copy note names ConditionalStateDispatch (00463760) as a structural twin, but the raw body is clearly a buffered write/flush routine; the label was not applied because the source text outranks it.
    // UNRESOLVED: The exact contract of sub_58CF35 (byte-processing step) and sub_58E22B (raw write) is not documented.
    // UNRESOLVED: The meaning of the flag bits 0x108/0x10C/0x20 in ctx+12 is inferred from observed control flow, not confirmed.
    // UNRESOLVED: The object type behind ctx (a4) is unknown.
}
