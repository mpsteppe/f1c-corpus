// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D360
// Canonical corpus name: GuardedAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedAccessor_0048d360.c

void UnknownObject::GuardedSelectedIndexGetter()
{
    // Guarded accessor: if the int at this+0x328 is greater than 0, returns the int at this+0x338; otherwise returns -1. The existing analysis interprets this+0x328 as a list/collection item count and this+0x338 as the currently selected index, but that interpretation is not independently evidenced by this packet.
    // GUARD: Guard on this+0x328 > 0; when it holds the getter returns this+0x338, otherwise it returns -1. [field:this:0x00000328, guard:0, source:raw]
    // RETURN: Return the int at this+0x338 (index this[206]) when the guard passes. [field:this:0x00000338, source:raw]
    // RETURN: Return -1 when the guard fails (this+0x328 <= 0). [field:this:0x00000328, source:raw]

    // Conservative worker pseudocode:
    //   int GuardedSelectedIndexGetter(int *this) {
    //     if (this[0x328/4] > 0)
    //       return this[0x338/4];
    //     return -1;
    //   }
    // UNRESOLVED: The meaning of the fields at this+0x328 and this+0x338 (interpreted as list count and selected index) relies on the owning UI list/collection object, which is unknown from this packet.
    // UNRESOLVED: The relation between the guard threshold and the returned field is caller-context dependent and not explainable here.
}
