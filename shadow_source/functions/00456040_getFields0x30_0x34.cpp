// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456040
// Canonical corpus name: DoubleFieldGetterAt0x300x34
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoubleFieldGetterAt0x300x34_00456040.c

void UnknownObject::getFields0x30_0x34()
{
    // Getter: copies fields this+0x30 and this+0x34 into caller-supplied output pointers a2 and a3 when those pointers are non-null, then returns a3.
    // GUARD: Branch on output pointer a2 being non-null before writing. [source:raw]
    // ASSIGNMENT: Copy field this+0x30 (element [12]) into *a2 when a2 is non-null. [field:this:0x00000030, source:raw]
    // GUARD: Branch on output pointer a3 being non-null before writing. [source:raw]
    // ASSIGNMENT: Copy field this+0x34 (element [13]) into *a3 when a3 is non-null. [field:this:0x00000034, source:raw]
    // RETURN: Return output pointer a3. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2) *a2 = this[12];
    //   if (a3) *a3 = this[13];
    //   return a3;
    // UNRESOLVED: Identity of the source object and the meaning of fields this+0x30 and this+0x34 unknown.
    // UNRESOLVED: Whether the two fields form a semantically paired quantity (position/transform pair) is not established.
}
