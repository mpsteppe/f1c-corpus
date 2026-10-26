// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560547
// Canonical corpus name: sub_560547
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_560547_00560547.c

void UnknownObject::ImagePatternedCopy()
{
    // Copies 2-byte-per-element image data from a source buffer to a destination buffer, honoring per-row pattern segments. Computes byte offsets into both buffers from row/column indices and stride fields (source stride a1[8] -> dword_5DD82C, destination stride a4[8] -> dword_5DD830). Publishes copy-control globals: dword_5DD838 = a8, dword_5DD834 = a7, dword_5DD840 = a8*a7. Scans the run-length pattern array (a9) to locate the current segment, then runs the main copy loop while dword_5DD840 > 0, copying v20 elements (2*v20 bytes) per segment via qmemcpy, advancing cursors by 2*v20 or rewinding by the strides at segment boundaries, toggling the direction flag dword_5DD83C per segment. Returns an uninitialized stack slot.
    // CALCULATION: Compute byte offsets: source offset v10 = a3 * a1[8] + 2 * a2, destination offset v11 = a6 * a4[8] + 2 * a5, using the stride fields of both image structs. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Publish the strides to globals: dword_5DD82C = a1[8] (source row stride), dword_5DD830 = a4[8] (destination row stride). [field:this:0x00000020, global:0x005DD82C, global:0x005DD830, source:raw]
    // ASSIGNMENT: Set buffer cursors from the data pointers: source cursor v12 = *a1 (buffer base field at offset 0x0) + v10, destination cursor v13 = *a4 + v11. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Publish copy-control globals: dword_5DD838 = a8, dword_5DD834 = a7, dword_5DD840 = a8 * a7 (total elements to process). [global:0x005DD838, global:0x005DD834, global:0x005DD840, source:raw]
    // CALCULATION: Initialize the direction flag dword_5DD83C from the first pattern entry **a9 (a non-zero entry becomes -1); when a10 is zero the value is complemented. [global:0x005DD83C, source:raw]
    // LOOP: Pattern scan: accumulate run-length entries (v18 = *v15, advanced through *v19) into v16 until v16 >= v17 where v17 = v10 >> 1, locating the current segment; complement dword_5DD83C at each iteration. [global:0x005DD83C, source:raw]
    // LOOP: Main copy loop while dword_5DD840 > 0: when the current run v20 is positive and the direction flag dword_5DD83C is set, copy 2*v20 bytes from v12 to v13 (qmemcpy in dword chunks plus a tail remainder), then advance both cursors by 2*v20 or rewind them by the strides dword_5DD82C / dword_5DD830 at segment end; clamp v20 against the remaining dword_5DD834, subtract v20 from dword_5DD840 and break when exhausted; read the next pattern entry and complement dword_5DD83C. [global:0x005DD840, global:0x005DD83C, global:0x005DD834, global:0x005DD82C, global:0x005DD830, field:this:0x00000000, source:raw]
    // RETURN: Return v28, a stack slot never assigned in the decompiled body (decompiler artifact); the routine behaves like a void copy. [function:0x00560547, source:raw]

    // Conservative worker pseudocode:
    //   int ImagePatternedCopy(_DWORD* src, int srcX, int srcY, _DWORD* dst, int dstX, int dstY,
    //                         int count, int repeat, int* pattern, int dirFlag) {
    //     unsigned v10 = srcY * src[8] + 2 * srcX;
    //     unsigned v11 = dstY * dst[8] + 2 * dstX;
    //     dword_5DD82C = src[8];
    //     dword_5DD830 = dst[8];
    //     char* s = (char*)src[0] + v10;
    //     char* d = (char*)dst[0] + v11;
    //     dword_5DD838 = repeat;
    //     dword_5DD834 = count;
    //     dword_5DD840 = repeat * count;
    //     dword_5DD83C = *pattern ? -1 : 0;
    //     if (!dirFlag) dword_5DD83C = ~dword_5DD83C;
    //     // pattern scan + per-segment copy loop with direction toggle per segment
    //     return uninitialized_stack_slot;
    //   }
    // UNRESOLVED: The run-length pattern semantics of a9 (segment meaning, and why v20 counts 2-byte units) are not resolvable from this packet.
    // UNRESOLVED: dword_5DD83C direction toggle implies reversed-copy segments (likely vertical flipping during blit), but the caller context is absent.
    // UNRESOLVED: The returned value v28 is uninitialized; the real return is presumed irrelevant by the caller.
    // UNRESOLVED: qmemcpy renders as an inline block copy; the concrete copy primitive is not evidenced here.
}
