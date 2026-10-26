// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048CA26
// Canonical corpus name: IntFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IntFieldSetter_0048ca26.c

void UnknownObject::IntFieldSetter()
{
    // Trivial __thiscall integer field setter: writes argument a2 into the dword at this+0x4 and returns a2. No guards, callees, globals, or callers in the packet. Structural twin of IntegerSetter (00406b30) via cluster_copy.
    // ASSIGNMENT: Seed return value: result = a2. [source:raw]
    // ASSIGNMENT: Write argument into the RW dword at this+0x4: this[1] = a2. [source:raw, field:this:0x00000004]
    // RETURN: Return the stored value a2. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_48CA26(int* this, int a2) {
    //     int result = a2;
    //     this[1] = a2;
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the dword at this+0x4; no caller evidence is present in the packet.
    // UNRESOLVED: Object type is unknown; owner has no packet evidence.
}
