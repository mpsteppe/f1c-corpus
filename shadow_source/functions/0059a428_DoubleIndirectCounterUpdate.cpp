// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A428
// Canonical corpus name: DoubleIndirectCounterUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoubleIndirectCounterUpdate_0059a428.c

void UnknownObject::DoubleIndirectCounterUpdate()
{
    // Adjusts two external counters through double-indirect pointers. Decrements the dword pointed to by *(this+0x30) (remaining write-buffer space) by a2, then increments the dword pointed to by *(this+0x20) (write-buffer position) by 2*a2, returning the pointer at this+0x20. Consistent with the caller's context of advancing a write-buffer position by a2 wide (2-byte) characters.
    // CALCULATION: Decrement the dword pointed to by *(this+0x30) (remaining write-buffer space counter) by a2. [field:*(this+0x30):0x00000000, field:this:0x00000030, source:raw]
    // CALCULATION: Increment the dword pointed to by *(this+0x20) (write-buffer position) by 2*a2. [field:*(this+0x20):0x00000000, field:this:0x00000020, source:raw]
    // RETURN: Return the pointer stored at this+0x20. [field:this:0x00000020, source:raw]

    // Conservative worker pseudocode:
    //   *(*(this + 0x30)) -= a2;
    //   result = *(this + 0x20);
    //   *result += 2 * a2;
    //   return result;
    // UNRESOLVED: Semantic roles of the two counters (remaining-space counter vs position counter) are inferred from the caller's write-buffer context, not proven by evidence in this packet.
    // UNRESOLVED: Ownership and concrete type of the object holding this+0x20/0x30 are unknown; no class evidence is present.
    // UNRESOLVED: The decrement unit (a2) and the increment unit (2*a2) are taken verbatim from the raw source; the wide-character (2-byte) interpretation is DERIVED from the caller relationship.
    // UNRESOLVED: Exactly one static caller (sub_599DD9) is recorded; no frame-path or call-frequency evidence exists.
}
