// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498F60
// Canonical corpus name: ShortComputation_8f60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_8f60_00498f60.c

void UnknownObject::GetDwordField0x4C()
{
    // Trivial getter: returns the dword at this+0x4C (this[19]). No side effects, no guards, no callees. Invoked by ShortComputation_58d0 (004958D0), ObjectSearchWithDoubleIteration (00495980) and DualListDestruction (00498D90).
    // RETURN: Return the dword stored at this+0x4C (index 19 of the dword array this) [field:this:0x0000004C, source:raw]
    // CALL: Invoked by ShortComputation_58d0 (004958D0), ObjectSearchWithDoubleIteration (00495980) and DualListDestruction (00498D90) to read the field at this+0x4C [caller:0x004958D0, caller:0x00495980, caller:0x00498D90]

    // Conservative worker pseudocode:
    //   int GetDwordField0x4C(DWORD *this) {
    //     return this[19];
    //   }
    // UNRESOLVED: Meaning of the field at this+0x4C and the owning object type are unknown
    // UNRESOLVED: Why three unrelated callers read the same offset is not resolvable from this packet (equal offsets on unrelated this pointers are not proof of identical classes)
}
