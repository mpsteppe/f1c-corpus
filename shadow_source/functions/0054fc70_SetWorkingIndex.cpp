// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FC70
// Canonical corpus name: sub_54FC70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54FC70_0054fc70.c

void UnknownObject::SetWorkingIndex()
{
    // Trivial field setter: stores argument a2 into this[27] (byte offset 0x6C) and returns that same value. No guards, no callees, no globals. Invoked during DirectX mesh vertex-buffer parsing and material-coordinate processing (DirectXMeshVertexBufferParsingAndLoading, sub_54CA00) to track the current working index/slot.
    // ASSIGNMENT: this[27] = a2: unconditionally write the argument into the field at byte offset 0x6C. [field:this:0x0000006C, source:raw]
    // ASSIGNMENT: result = a2: mirror the stored value into the return register. [source:raw]
    // RETURN: Return a2, the value that was just stored. [function:0x0054FC70, source:raw]
    // CALL: Invoked from DirectXMeshVertexBufferParsingAndLoading (0x00547B40) and sub_54CA00 (0x0054CA00) during mesh vertex-buffer and material processing. [caller:0x00547B40, caller:0x0054CA00]

    // Conservative worker pseudocode:
    //   int SetWorkingIndex(_DWORD *this, int a2) {
    //       this[27] = a2;   /* this+0x6C * /
    //       return a2;
    //   }
    // UNRESOLVED: The semantic meaning of the stored field (material slot index vs vertex processing counter) is DERIVED from the caller names; the owning class is unknown.
}
