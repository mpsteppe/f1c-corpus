// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B19CA
// Canonical corpus name: sub_4B19CA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B19CA_004b19ca.c

void UnknownObject::sub_4B19CA()
{
    // Forwarding helper: writes the dword a1 into the byte address a2 + 8 * a3 - 1 (an 8-byte-strided slot indexed by a3, with a trailing minus-one-byte adjustment), then calls sub_4B19D0(a1) and returns its result.
    // CALCULATION: Compute the destination byte address as a2 + 8 * a3 - 1: base a2 plus a3 scaled by stride 8, then minus one byte. [source:raw]
    // ASSIGNMENT: Store dword a1 at the computed byte address. [source:raw]
    // CALL: Call sub_4B19D0 with a1 as its single argument. [source:raw]
    // RETURN: Return the value returned by sub_4B19D0(a1). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B19CA(int a1 /* ecx * /, int a2 /* ebp * /, int a3 /* esi * /) {
    //       *(int *)(a2 + 8 * a3 - 1) = a1;
    //       return sub_4B19D0(a1);
    //   }
    // UNRESOLVED: The minus-one-byte adjustment makes the destination address potentially unaligned; the underlying slot layout (8-byte stride with trailing byte?) is not evidenced.
    // UNRESOLVED: Ownership of base a2, the meaning of index a3, and the behavior of callee sub_4B19D0 are unknown; the packet lists no callers or callees.
    // UNRESOLVED: Whether the value a1 is a plain dword or a pointer into an indexed structure is unresolved.
}
