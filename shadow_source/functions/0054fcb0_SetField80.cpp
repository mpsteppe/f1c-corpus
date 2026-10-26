// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FCB0
// Canonical corpus name: FieldSetterAt0x80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldSetterAt0x80_0054fcb0.c

void UnknownObject::SetField80()
{
    // Unconditional field setter: stores the second parameter into this+0x80 and returns the parameter unchanged. No guards, no globals, no callees.
    // ASSIGNMENT: Store a2 into this[32] (this+0x80). [field:this:0x00000080, source:raw]
    // RETURN: Return a2 unchanged as result. [source:raw]

    // Conservative worker pseudocode:
    //   int SetField80(this, a2) {
    //     this[32] = a2;
    //     return a2;
    //   }
    // UNRESOLVED: Object owning this+0x80 is unknown; callers are DirectXMeshVertexBufferParsingAndLoading (0x00547B40), D3DTextureResourceCreation (0x00548190), and sub_557CE0 (0x00557CE0).
    // UNRESOLVED: Prelabel cluster-copy marks this as a structural twin of another function; twin identity is not evidenced in the packet.
}
