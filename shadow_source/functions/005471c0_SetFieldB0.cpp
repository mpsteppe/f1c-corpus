// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005471C0
// Canonical corpus name: SimpleSetter_71c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SimpleSetter_71c0_005471c0.c

void UnknownObject::SetFieldB0()
{
    // Unconditional field setter: stores the second parameter into this+0xB0 and returns the parameter unchanged. No guards, no globals, no callees.
    // ASSIGNMENT: Store a2 into this[44] (this+0xB0). [field:this:0x000000B0, source:raw]
    // RETURN: Return a2 unchanged as result. [source:raw]

    // Conservative worker pseudocode:
    //   int SetFieldB0(this, a2) {
    //     this[44] = a2;
    //     return a2;
    //   }
    // UNRESOLVED: Object owning this+0xB0 is unknown; callers are DirectXMeshVertexBufferParsingAndLoading (0x00547B40) and D3DTextureResourceCreation (0x00548190).
}
