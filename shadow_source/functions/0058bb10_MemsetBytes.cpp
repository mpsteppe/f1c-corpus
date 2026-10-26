// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BB10
// Canonical corpus name: sub_58BB10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58BB10_0058bb10.c

void UnknownObject::MemsetBytes()
{
    // memset-style byte filler: writes a3 copies of byte a2 into the buffer a1 and returns a1. With a3 < 4 or a3 == 0 it short-circuits (zero length returns a1 immediately); otherwise it writes an alignment prefix byte-by-byte, fills the bulk via the memset32 intrinsic with the byte replicated across a DWORD, then fills trailing bytes. No fields, globals, guards on data or callee-table calls.
    // GUARD: If length a3 == 0, return a1 unchanged. [source:raw]
    // GUARD: If a3 < 4, skip the aligned bulk path and go straight to the trailing byte loop. [source:raw]
    // CALCULATION: v6 = -(int)a1 & 3: computes the byte count needed to align the buffer pointer to 4 bytes; remaining length v3 = a3 - v6. [source:raw]
    // LOOP: Alignment prefix: writes single bytes of a2 until the pointer is 4-byte aligned. [source:raw]
    // CALCULATION: v4 = 16843009 * a2: replicates a2 across all four bytes of a DWORD; v7 = remaining length, v3 = v7 & 3 (tail bytes), v8 = v7 >> 2 (DWORD count). [source:raw]
    // CALL: Fills the bulk with the replicated pattern via the memset32(v5, v4, v8) intrinsic, advancing v5 by 4 * v8 bytes. [source:raw]
    // LOOP: Trailing bytes: writes remaining v3 bytes of the low byte of v4. [source:raw]
    // RETURN: Returns the original buffer pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   if (a3 == 0) return a1;
    //   p = a1; n = a3;
    //   if (a3 >= 4) { align p; memset32(p, a2*0x01010101, n >> 2); p += (n & ~3); n &= 3; }
    //   while (n--) *p++ = a2;
    //   return a1;
    // UNRESOLVED: memset32 is an intrinsic referenced by the raw source but absent from the packet callees table; no call target address is asserted.
    // UNRESOLVED: ABI lead 'FAIL_58bb10' (LEGACY) carries no semantic signal and is discarded in favor of the raw source.
    // UNRESOLVED: Callers (InitPhysicsTransformIdentity, PhysicsStateZeroInit, SlabBuddyAllocatorInitialization, buffer-append paths) all use it as a zero/pattern filler; consistent with a generic memset but no owner object is evidenced.
}
