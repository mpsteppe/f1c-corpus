// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048C9E0
// Canonical corpus name: IntSetterAt4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IntSetterAt4_0048c9e0.c

void UnknownObject::IntSetterAt4()
{
    // Trivial __thiscall integer field setter: writes argument a2 into the dword at this+0x4 and returns a2. No guards, callees, or globals. Structural twin of IntegerSetter (00406b30) via cluster_copy; called once by LinkedListNodeAppend (0048D2B0).
    // ASSIGNMENT: Seed return value: result = a2. [source:raw]
    // ASSIGNMENT: Write argument into the RW dword at this+0x4: this[1] = a2. [source:raw, field:this:0x00000004]
    // RETURN: Return the stored value a2. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_48C9E0(int* this, int a2) {
    //     int result = a2;
    //     this[1] = a2;
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the dword at this+0x4 (called from LinkedListNodeAppend 0048D2B0); role is not evidenced beyond the raw write.
    // UNRESOLVED: Object type is unknown; owner has no packet evidence.
}
