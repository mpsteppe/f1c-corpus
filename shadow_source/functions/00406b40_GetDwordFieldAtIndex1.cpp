// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406B40
// Canonical corpus name: sub_406B40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_406B40_00406b40.c

void UnknownObject::GetDwordFieldAtIndex1()
{
    // Trivial getter: returns the DWORD stored at this+0x4 (index 1). No side effects, no callees, no callers in the packet. Matches the DERIVED template prelabel 'getter'.
    // RETURN: Return this[1], the DWORD stored at this+0x4, read-only. [field:this:0x00000004, function:0x00406B40, source:raw]

    // Conservative worker pseudocode:
    //   return this[1];
    // UNRESOLVED: No evidence identifies which object owns field +0x4; owner kept UNKNOWN.
    // UNRESOLVED: Field +0x4 is read-only with no writers or callers in the packet to constrain its meaning.
    // UNRESOLVED: No ABI lead and no callers exist for this function.
}
