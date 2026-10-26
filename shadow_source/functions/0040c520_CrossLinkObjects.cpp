// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C520
// Canonical corpus name: sub_40C520
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_40C520_0040c520.c

void UnknownObject::CrossLinkObjects()
{
    // Establishes bidirectional back-references between two objects: writes this+0x1C into offset 8 of the object pointed to by this+0x20, and writes this+0x20 into offset 8 of the object pointed to by this+0x1C. Returns this+0x1C. Called from CamMan_Init (0x0040C920).
    // ASSIGNMENT: Write the first object pointer this+0x1C into offset 8 of the second object (pointed to by this+0x20), linking the second object back to the first. [field:this:0x0000001C, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Write the second object pointer this+0x20 into offset 8 of the first object (pointed to by this+0x1C), completing the reciprocal back-reference. [field:this:0x0000001C, field:this:0x00000020, source:raw]
    // RETURN: Return the first object pointer this+0x1C. [field:this:0x0000001C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_40C520(_DWORD *this) {
    //     *(_DWORD *)(this[8] + 8) = this[7];
    //     *(_DWORD *)(this[7] + 8) = this[8];
    //     return this[7];
    //   }
    // UNRESOLVED: The fields at this+0x24 and this+0x28 are recorded as struct fields but are not accessed by this function.
    // UNRESOLVED: The object type and the semantic meaning of the offset-8 back-reference slot are caller-defined.
}
