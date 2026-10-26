// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004560A0
// Canonical corpus name: DualFieldGetter_60a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualFieldGetter_60a0_004560a0.c

void UnknownObject::getFields0x4C_0x50()
{
    // Getter: copies fields this+0x4C and this+0x50 into caller-supplied output pointers a2 and a3 when those pointers are non-null, then returns a3.
    // GUARD: Branch on output pointer a2 being non-null before writing. [source:raw]
    // ASSIGNMENT: Copy field this+0x4C (element [19]) into *a2 when a2 is non-null. [field:this:0x0000004C, source:raw]
    // GUARD: Branch on output pointer a3 being non-null before writing. [source:raw]
    // ASSIGNMENT: Copy field this+0x50 (element [20]) into *a3 when a3 is non-null. [field:this:0x00000050, source:raw]
    // RETURN: Return output pointer a3. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2) *a2 = this[19];
    //   if (a3) *a3 = this[20];
    //   return a3;
    // UNRESOLVED: Identity of the source object and the meaning of fields this+0x4C and this+0x50 unknown.
    // UNRESOLVED: Whether the two fields form a semantically paired quantity is not established.
}
