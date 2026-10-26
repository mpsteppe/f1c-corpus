// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A9CA
// Canonical corpus name: sub_59A9CA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59A9CA_0059a9ca.c

void UnknownObject::AssignStringBufferRange()
{
    // Assigns a subrange [a3, a3+v5) of the source string buffer a2 into destination `this`. Bounds-checks a3 against the source used-length (sub_59AF68 on failure). On self-assignment, truncates via two BufferTruncationShrink calls. Otherwise, when the copy is the full source length, attempts reference-counted buffer sharing (falling back to an empty-string sentinel); any partial/empty case goes to the alloc path: sub_599560 capacity ensure + MemoryCopy_cc00 + NUL termination. Called by the CExceptionInitHandler and exception-object-construction paths (0059a69a, 0059a781, 0059ada3, 0059ae7d).
    // GUARD: Bounds check: if the source used-length a2[2] is smaller than the start offset a3, call sub_59AF68 (out-of-range/throw path). [source:raw, callee:0x0059AF68]
    // CALCULATION: Compute the copy length v5 = a2[2] - a3, clamped to a4 (v5 = min(a4, a2[2] - a3)). [source:raw]
    // GUARD: If destination `this` equals source a2 (self-assignment), take the in-place truncation path. [source:raw]
    // CALL: BufferTruncationShrink(this, a3 + v5, 0xFFFFFFFF): trim the buffer tail past the assigned subrange. [callee:0x00599348]
    // CALL: BufferTruncationShrink(this, 0, a3): trim the buffer head before the assigned subrange. [callee:0x00599348]
    // GUARD: On the non-self path, if v5 is zero or v5 != a2[2] (partial or empty copy), fall through to the allocation/copy path (LABEL_22). [source:raw]
    // CALCULATION: Full-length share path: load the source data pointer a2[1], falling back to the empty-string sentinel unk_5B9D34 when null, and test the refcount byte stored immediately before the data. [source:raw, global:0x005B9D34]
    // CALL: ReferenceCountDecrementWithConditionalFree(this, 1): release the current destination buffer reference before sharing. [callee:0x005993AF]
    // ASSIGNMENT: Adopt the shared buffer: set this[1] (data pointer) to the source data, this[2] (used length) to a2[2], this[3] (capacity) to a2[3], and increment the refcount byte before the data. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // CALL: sub_599560(this, v5, 1): ensure the destination buffer has capacity for the copy. [callee:0x00599560]
    // CALL: MemoryCopy_cc00(this[1], &source_data[a3], v5): copy the subrange bytes into the destination buffer. [callee:0x0058CC00]
    // ASSIGNMENT: Set this[2] (used length) to v5 and NUL-terminate the buffer at this[1] + v5. [field:this:0x00000008]
    // RETURN: Return `this` as the assignment result. [source:raw]

    // Conservative worker pseudocode:
    //   if (src->usedLen < start) throw_out_of_range();          // sub_59AF68
    //   n = min(a4, src->usedLen - start);
    //   if (dst == src) {
    //       BufferTruncationShrink(dst, start + n, 0xFFFFFFFF);
    //       BufferTruncationShrink(dst, 0, start);
    //   } else if (n != 0 && n == src->usedLen) {
    //       data = src->data ? src->data : &null_sentinel;
    //       if (refcount(data - 1) < 0xFE) {
    //           ReferenceCountDecrementWithConditionalFree(dst, 1);
    //           dst->data = data; dst->usedLen = src->usedLen; dst->capacity = src->capacity;
    //           ++refcount(data - 1);
    //       }
    //   } else if (sub_599560(dst, n, 1)) {
    //       MemoryCopy_cc00(dst->data, src->data + start, n);
    //       dst->usedLen = n;
    //       ((char*)dst->data)[n] = 0;
    //   }
    //   return dst;
    // UNRESOLVED: dword_5B9C38 (global:0x005B9C38) is flagged as read by this function but never appears as an explicit operand in the raw body; possibly consumed inside an inlined helper. No role asserted.
    // UNRESOLVED: Source-buffer fields a2[1..3] are accessed as raw offset reads but the packet carries no a2 field evidence refs; they are described from source:raw only.
}
