// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C440
// Canonical corpus name: EmptyStub_c440
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EmptyStub_c440_0055c440.c

void UnknownObject::EmptyStub_c440()
{
    // Empty stub: ignores its single argument a1 and returns 0 unconditionally. Called by sub_544740 and sub_55BD20. The legacy ABI lead (Empty_Stub_55c440) matches the observed body exactly.
    // RETURN: Return 0 unconditionally; argument a1 is accepted but never read. [source:raw]

    // Conservative worker pseudocode:
    //   int EmptyStub_c440(int a1) {
    //       return 0;
    //   }
    // UNRESOLVED: The purpose of the unused parameter a1 and what the call sites expect from an always-0 result are not grounded by this packet.
    // UNRESOLVED: Whether the stub represents a disabled or unimplemented feature at the call sites in sub_544740 and sub_55BD20 is unknown.
}
