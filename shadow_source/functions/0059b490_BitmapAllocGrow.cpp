// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B490
// Canonical corpus name: sub_59B490
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59B490_0059b490.c

void UnknownObject::BitmapAllocGrow()
{
    // Grows a bitmap/buffer allocation when the requested bit capacity (a2 + this[0x10]) exceeds 8 * the current byte size (this[0x4]). Grows geometrically by stride this[0x18] with a hard cap of 128000 bytes (0x1F400), allocates a new buffer, copies the old contents, frees the old buffer, and updates this[0x0] and this[0x4]. Returns 1 on success and on the no-growth path; returns 0 only when the allocation fails.
    // ASSIGNMENT: Pre-set result to 1 (success default) before the growth check. [source:raw]
    // CALCULATION: Compute needed bit capacity v5 = a2 + this[0x10] and current bit capacity 8 * this[0x4] (8 bits per byte). [field:this:0x00000010, field:this:0x00000004, source:raw]
    // GUARD: If needed bit capacity (a2 + this[0x10]) is not greater than 8 * this[0x4], return 1 without reallocating. [field:this:0x00000010, field:this:0x00000004, source:raw]
    // CALCULATION: Compute new byte size v7 = this[0x18] + this[0x4], then grow in this[0x18] strides (each adding 8 * this[0x18] bits) until 8 * v7 covers the need, stopping when v7 reaches 128000 (0x1F400). [field:this:0x00000018, field:this:0x00000004, source:raw]
    // CALL: Allocate the new v7-byte buffer via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // GUARD: If the allocation returns null, return 0 (failure, no realloc). [callee:0x00587C03, source:raw]
    // CALL: Copy this[0x4] bytes from the old buffer this[0x0] into the new buffer (qmemcpy), then free the old buffer via FreeWrapper_7bcf. [field:this:0x00000000, field:this:0x00000004, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Store the new buffer pointer in this[0x0] and the new byte size in this[0x4]. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // RETURN: Return 1 on success (both the no-growth and grown paths); 0 only when the allocation failed. [source:raw]

    // Conservative worker pseudocode:
    //   char BitmapAllocGrow(int this, unsigned int need) {
    //     unsigned int cur = *(this + 4);
    //     unsigned int required = need + *(this + 16);
    //     if (required <= 8 * cur) return 1;
    //     unsigned int stride = *(this + 24);
    //     unsigned int new_size = stride + cur;
    //     do {
    //       if (8 * new_size >= required) break;
    //       new_size += stride;
    //     } while (new_size < 0x1F400);
    //     void *p = OperatorNewNhMallocWrapper(new_size);
    //     if (!p) return 0;
    //     qmemcpy(p, *(void **)this, cur);
    //     FreeWrapper_7bcf(*(void **)this);
    //     *(void **)this = p;
    //     *(this + 4) = new_size;
    //     return 1;
    //   }
    // UNRESOLVED: Exact meaning of a2 (caller byte or bit requirement) and of the this[0x10] base is DERIVED from the caller contract, not confirmed.
    // UNRESOLVED: Origin of the 128000 (0x1F400) growth cap constant is unknown.
    // UNRESOLVED: Owner object type is UNKNOWN; only the caller BitmapAllocationTracker (0x0059B5C0) is known.
}
