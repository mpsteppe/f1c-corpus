// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599560
// Canonical corpus name: sub_599560
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_599560_00599560.c

void UnknownObject::BufferValidateAndResize()
{
    // Validates and optionally grows a buffer. A boundary marker byte lives at data[-1], where the data pointer is stored at this+4. The requested size arrives through the stack return address slot (retaddr). Overflows above 0xFFFFFFFD are handed to sub_59AD49. Depending on the marker state, the requested size and the a3 flag, the function either decrements the marker and releases a reference via ReferenceCountDecrementWithConditionalFree, zeroes the buffer fields at this+8 and the first data byte, or grows the buffer via BufferAllocationWithSizeRounding. Returns 0 for the cleanup/ok paths and 1 when reallocation is required or the capacity already fits.
    // GUARD: Overflow guard: when the requested size (retaddr) is greater than 0xFFFFFFFD, calls sub_59AD49 to handle the invalid size request [callee:0x0059AD49, source:raw]
    // CALCULATION: Reads the data pointer from this+4 (v4) and, when non-null, the boundary marker byte at data[-1] into v5 [field:this:0x00000004, source:raw]
    // GUARD: When the marker is non-zero and not equal to -1 and the requested size is zero, decrements the marker byte at data[-1], calls ReferenceCountDecrementWithConditionalFree(this, 0), and returns 0 [field:this:0x00000004, callee:0x005993AF, source:raw]
    // STATE_TRANSITION: Cleanup path for a zero requested size: when a3 is set calls ReferenceCountDecrementWithConditionalFree(this, 1); otherwise when the data pointer exists writes zero to this+8 (size) and to the first data byte, then returns 0 [field:this:0x00000008, callee:0x005993AF, source:raw]
    // GUARD: When the requested size is non-zero and a3 is set, accepts the buffer as-is and returns 1 when the capacity at this+12 is at most 0x1F and at least the requested size; otherwise decrements the reference via ReferenceCountDecrementWithConditionalFree(this, 1) and falls through to reallocation [field:this:0x0000000C, callee:0x005993AF, source:raw]
    // CALL: When the capacity at this+12 is below the requested size (or on the fall-through path), calls BufferAllocationWithSizeRounding(retaddr) to grow the buffer and returns 1 [field:this:0x0000000C, callee:0x0059964A, source:raw]
    // RETURN: Returns 0 from the marker-decrement and cleanup paths and 1 when reallocation is needed or the existing capacity already satisfies the request [function:0x00599560, source:raw]

    // Conservative worker pseudocode:
    //   if (retaddr > 0xFFFFFFFD) sub_59AD49(v8);
    //   v4 = this[1];
    //   if (v4) {
    //       v5 = *(v4 - 1);
    //       if (v5 && v5 != -1) {
    //           if (!retaddr) { *(v4 - 1) = v5 - 1; ReferenceCountDecrementWithConditionalFree(this, 0); return 0; }
    //           goto realloc;
    //       }
    //   }
    //   if (!retaddr) {
    //       if (a3) ReferenceCountDecrementWithConditionalFree(this, 1);
    //       else if (v4) { this[2] = 0; *v4 = 0; }
    //       return 0;
    //   }
    //   if (a3) {
    //       v7 = this[3];
    //       if (v7 <= 0x1F && v7 >= retaddr) return 1;
    //       ReferenceCountDecrementWithConditionalFree(this, 1);
    //   }
    //   if (this[3] < retaddr) {
    //   realloc:
    //       BufferAllocationWithSizeRounding(retaddr);
    //   }
    //   return 1;
    // UNRESOLVED: retaddr is recovered from the stack return-address slot (the function has a positive sp value); the source of the requested size is a caller-side stack argument, not a named parameter
    // UNRESOLVED: The semantics of the 0x1F capacity threshold and the -1 (0xFF) marker sentinel are not explained in this packet
    // UNRESOLVED: The -1 comparison is a signed char marker test; the decompiled source does not reveal whether an unallocated block is represented by this+4 being null, the marker being zero, or the marker being -1
    // UNRESOLVED: sub_59AD49's exact handling of the overflow case is defined elsewhere
}
