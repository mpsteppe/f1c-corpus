// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517F58
// Canonical corpus name: sub_517F58
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_517F58_00517f58.c

void UnknownObject::CRC32UpdateBlock()
{
    // Dispatches an event to registered callbacks with null safety, then conditionally updates a CRC32 accumulator (this+0x100) from the incoming data block (a2, a3). The CRC update is skipped under two flag combinations: when this+0x10C bit 5 is clear and this+0x5D bit 3 is set, or when this+0x10C bit 5 is set and (this+0x5C & 0x300) == 0x300. Returns the this pointer (a1).
    // CALL: Dispatch a callback with a null guard, forwarding the three arguments (a1, a2, a3) unchanged. [callee:0x00513BD1, source:raw]
    // GUARD: Branch on this+0x10C bit 5 (mask 0x20): when clear, the skip decision uses the low-byte flag at this+0x5D bit 3; when set, it uses the 0x300 mask at this+0x5C. [field:this:0x0000010C, field:this:0x0000005D, field:this:0x0000005C, source:raw]
    // GUARD: Early-skip path: if (this+0x5D & 8) != 0, return immediately without updating the CRC accumulator. [field:this:0x0000005D, source:raw]
    // GUARD: Mismatch path: if (this+0x5C & 0x300) != 0x300, fall through to the CRC update; if the mask equals 0x300, the accumulator is left unchanged. [field:this:0x0000005C, source:raw]
    // CALCULATION: Compute the CRC32 over the data block (a2, a3) seeded from the current accumulator value stored at this+0x100. [field:this:0x00000100, source:raw]
    // ASSIGNMENT: Store the newly computed CRC32 result back into this+0x100, replacing the prior accumulator value. [field:this:0x00000100, source:raw]
    // RETURN: Return the this pointer (a1) on both the early-skip path and the CRC-update path. [function:0x00517F58, source:raw]

    // Conservative worker pseudocode:
    //   CallbackDispatchWithNullGuard(a1, a2, a3);
    //   if ((*(BYTE*)(a1 + 0x10C) & 0x20) == 0) {
    //       if ((*(BYTE*)(a1 + 0x5D) & 8) != 0) return a1;
    //   } else if ((*(DWORD*)(a1 + 0x5C) & 0x300) == 0x300) {
    //       return a1;
    //   }
    //   *(DWORD*)(a1 + 0x100) = CRC32Computation(*(DWORD*)(a1 + 0x100), a2, a3);
    //   return a1;
    // UNRESOLVED: The CRC32Computation operation appears in the raw source text but has no corresponding entry in the packet callee list, so no callee evidence reference is asserted for it.
    // UNRESOLVED: The exact semantics of the flag combinations at this+0x5D bit 3 and this+0x5C bits 8-9 (skip conditions) are unknown; only their effect on the CRC update is evidenced.
}
