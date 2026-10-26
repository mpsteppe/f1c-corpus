// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479ED0
// Canonical corpus name: CallFlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallFlagSet_00479ed0.c

void UnknownObject::CallFlagSet()
{
    // Straight-line flag clear: calls Return0Stub (reported no-op) with no arguments, clears the byte field at offset 0x100 to 0, and returns 0. Existing analysis describes it as the inverse of FlagSetInit_00479eb0 (flag activation vs deactivation); the flag/enable interpretation is DERIVED from that prose only.
    // CALL: Call Return0Stub with no arguments; reported as a no-op stub. [callee:0x0047ABB0]
    // ASSIGNMENT: Clear the byte flag at offset 0x100 (this[256]) to 0. [field:this:0x00000100]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int CallFlagSet(_BYTE* this) {
    //     Return0Stub();
    //     this[256] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Owning object type is unknown; packet provides no owner evidence.
    // UNRESOLVED: Return0Stub is reported as a no-op by the fill; its actual behavior is unverified in this packet.
    // UNRESOLVED: Whether the byte at offset 0x100 is an enable/active flag (and whether CallFlagSet is truly the inverse of FlagSetInit_00479eb0) is DERIVED from prose, not proven here.
}
