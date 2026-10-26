// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1A4A
// Canonical corpus name: sub_4B1A4A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B1A4A_004b1a4a.c

void UnknownObject::OrSlotDwordThenInitSentinel()
{
    // Tiny __usercall helper (a1 in ecx, a2 in ebp, a3 in esi): bitwise-ORs a1 into the dword stored at the slot address a2 + 8 * a3 - 1, then tail-calls the routine named InitWithSentinelPattern with a1 and returns its result. The slot expression suggests indexed access into a structure whose stride is 8 bytes; the OR implies flag/bitfield accumulation into that slot.
    // CALCULATION: Bitwise-OR a1 into the dword at the computed slot address: *(_DWORD *)(a2 + 8 * a3 - 1) |= a1. [source:raw]
    // CALL: Tail-call the routine named InitWithSentinelPattern with a1 as its only observed argument. [source:raw]
    // RETURN: Propagate the value returned by InitWithSentinelPattern back to the caller. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B1A4A(int a1, int a2, int a3) {
    //       *(int*)(a2 + 8 * a3 - 1) |= a1;
    //       return InitWithSentinelPattern(a1);
    //   }
    // UNRESOLVED: Role of a2 (ebp) and a3 (esi): a2 looks like a base pointer and a3 an index over 8-byte elements, but the owning object and slot meaning are not documented by the packet.
    // UNRESOLVED: Identity, address and class of InitWithSentinelPattern are not recorded in the packet; only its name appears in the raw source.
    // UNRESOLVED: Whether this helper is a method entry, a callback, or a vtable thunk cannot be determined from this evidence alone.
}
