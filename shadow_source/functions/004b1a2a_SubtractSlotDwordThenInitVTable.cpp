// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1A2A
// Canonical corpus name: sub_4B1A2A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B1A2A_004b1a2a.c

void UnknownObject::SubtractSlotDwordThenInitVTable()
{
    // Tiny __usercall helper (a1 in ecx, a2 in ebp, a3 in esi): subtracts a1 from the dword stored at the slot address a2 + 8 * a3 - 1, then tail-calls the routine named VTableInitWithDefaults_1a30 with a1 and returns its result. The slot expression suggests indexed access into a structure whose stride is 8 bytes; the callee is treated as an initialization step driven by the same argument.
    // CALCULATION: Subtract a1 from the dword at the computed slot address: *(_DWORD *)(a2 + 8 * a3 - 1) -= a1. [source:raw]
    // CALL: Tail-call the routine named VTableInitWithDefaults_1a30 with a1 as its only observed argument. [source:raw]
    // RETURN: Propagate the value returned by VTableInitWithDefaults_1a30 back to the caller. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B1A2A(int a1, int a2, int a3) {
    //       *(int*)(a2 + 8 * a3 - 1) -= a1;
    //       return VTableInitWithDefaults_1a30(a1);
    //   }
    // UNRESOLVED: Role of a2 (ebp) and a3 (esi): a2 looks like a base pointer and a3 an index over 8-byte elements, but the owning object and slot meaning are not documented by the packet.
    // UNRESOLVED: Identity, address and class of VTableInitWithDefaults_1a30 are not recorded in the packet; only its name appears in the raw source.
    // UNRESOLVED: Whether this helper is a method entry, a callback, or a vtable thunk cannot be determined from this evidence alone.
}
