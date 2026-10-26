// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00516531
// Canonical corpus name: RingBufferWriteWithBoundsCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RingBufferWriteWithBoundsCheck_00516531.c

void UnknownObject::ringBufferWrite()
{
    // Writes a range [a3, a3+a4) into a ring buffer described by a2 (capacity at +4, max write size at +12, element size at +8, write position at +24, written bound at +28, plus reprocess/zero-fill flag bytes at +32/+33/+34). Validates capacity and write-size, repositions and dispatches stale regions via sub_51641E, optionally zero-fills new elements via MemoryZeroFill, and returns a pointer into the buffer array at the target element index. Failure paths raise error codes 20 or 68 through the object's virtual error handler at obj+0x14.
    // CALCULATION: Compute v5 = a3 + a4 as the end of the requested range. [source:raw]
    // GUARD: Validate the request: end of range (a3+a4) must not exceed capacity at a2+4, write size a4 must not exceed max write size at a2+12, and the buffer pointer at a2+0 must be non-null. [source:raw]
    // ASSIGNMENT: Seed v6 with a1 in both branches of the capacity check. [source:raw]
    // ASSIGNMENT: On validation failure, raise error code 20 by writing it to the error slot obj+0x14 and invoke the virtual error handler at the object vtable. [field:obj:0x00000014, source:raw]
    // CALCULATION: Read the current write position v7 = *(a2+24) for the window check. [source:raw]
    // GUARD: If the range falls outside the current window (a3 < v7, or v5 > v7 + buffer size at a2+16), enter the reposition path. [source:raw]
    // GUARD: On the reposition path, if the reprocess flag at a2+34 is clear, raise error code 68 through obj+0x14 and the virtual error handler. [field:obj:0x00000014, source:raw]
    // CALL: If the pending-reprocess flag at a2+33 is set, dispatch the stale region by calling sub_51641E(a2, v6, 1), then clear the flag. [callee:0x0051641E, source:raw]
    // ASSIGNMENT: Compute and store the new write position at a2+24: starts from a3, or from v5 minus buffer size at a2+16 when a3 is at or before the current write position, clamped to zero. [source:raw]
    // CALL: Dispatch the out-of-bounds remainder by calling sub_51641E(a2, v6, 0). [callee:0x0051641E, source:raw]
    // GUARD: Read the written-position bound v9 = *(a2+28); if it is below the range end v5, the bound must be advanced. [source:raw]
    // ASSIGNMENT: When advancing the bound: keep the current bound at a2+28 as the start when it already covers a3, otherwise use a3 as the start. [source:raw]
    // ASSIGNMENT: If the a5 flag is set, write the new written-position bound v5 into a2+28. [source:raw]
    // LOOP: If the zero-fill flag at a2+32 is set, walk every element index from v10-v11 to v5-v11 and call MemoryZeroFill on each element pointer (buffer base at a2+0 plus index times 4) with the element size v15 from a2+8. [callee:0x005159A8, source:raw]
    // GUARD: In the non-zero-fill branch, if the a5 flag is clear, raise error code 20 through obj+0x14 and the virtual error handler. [field:obj:0x00000014, source:raw]
    // STATE_TRANSITION: When the a5 flag is set, mark the pending-reprocess flag at a2+33 as 1 before returning. [source:raw]
    // RETURN: Return the buffer base at a2+0 plus 4 times the offset of the target element index (a3 minus the write position at a2+24). [source:raw]

    // Conservative worker pseudocode:
    //   v5 = a3 + a4;
    //   if (v5 <= buf->capacity && a4 <= buf->maxWrite && buf->base) {
    //     v6 = a1;
    //   } else {
    //     v6 = a1;
    //     error(20);
    //   }
    //   v7 = buf->writePos;
    //   if (a3 < v7 || v5 > v7 + buf->bufSize) {
    //     if (!buf->reprocessAllowed) error(68);
    //     if (buf->pendingReprocess) { sub_51641E(buf, v6, 1); buf->pendingReprocess = 0; }
    //     buf->writePos = (a3 <= v7) ? max(v5 - buf->bufSize, 0) : a3;
    //     sub_51641E(buf, v6, 0);
    //   }
    //   if (buf->writtenBound < v5) {
    //     v10 = (buf->writtenBound >= a3) ? buf->writtenBound : a3;
    //     if (a5) buf->writtenBound = v5;
    //     if (buf->zeroFill) {
    //       for (i = v10 - buf->writePos; i < v5 - buf->writePos; i++)
    //         MemoryZeroFill(buf->base[4*i], buf->elemSize);
    //     } else {
    //       if (!a5) error(20);
    //     }
    //   }
    //   if (a5) buf->pendingReprocess = 1;
    //   return buf->base + 4 * (a3 - buf->writePos);
    // UNRESOLVED: The buffer object type at a2 (which carries capacity at +4, element size at +8, max write size at +12, size at +16, write position at +24, written bound at +28, and flag bytes at +32/+33/+34) is not evidenced beyond this function's access pattern.
    // UNRESOLVED: Error codes 20 and 68 and the exact meaning of the a5 flag and reprocess/zero-fill flag bytes are DERIVED from existing analysis, not independently evidenced.
    // UNRESOLVED: The element pointers are indexed as 4-byte dwords from the buffer base at a2+0; the true element stride is assumed from that indexing.
}
