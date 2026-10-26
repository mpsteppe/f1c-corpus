// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448EC0
// Canonical corpus name: SmallStructCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SmallStructCopy_00448ec0.c

void UnknownObject::SmallStructCopy()
{
    // Copies a small data pair from source a2 into the this object: one byte from a2+0 into this+0x19, and the word at a2+2 into this+0x1A. Returns the copied word. No branches, no calls. Existing analysis (DERIVED) reads the pair as a collision body type field + handle/index word used during collision body initialization.
    // ASSIGNMENT: Copy source byte into body type field: *(BYTE*)(this+25) = *(BYTE*)a2. [field:this:0x00000019, source:raw]
    // ASSIGNMENT: Read the source word at a2+2 and store it into the handle field: *(WORD*)(this+26) = *(WORD*)(a2+2). [field:this:0x0000001A, source:raw]
    // RETURN: Return the copied word from the handle field (this+0x1A). [field:this:0x0000001A, source:raw]
    // CALL: Called by TriangleMeshAdjacencyBuilder (0x004493A0) and CollisionCapsuleShapeCopyToPipeline (0x0044B040) to initialize collision-body fields. [caller:0x004493A0, caller:0x0044B040]

    // Conservative worker pseudocode:
    //   __int16 SmallStructCopy(int this, int a2) {
    //     *(_BYTE*)(this + 25) = *(_BYTE*)a2;
    //     __int16 result = *(_WORD*)(a2 + 2);
    //     *(_WORD*)(this + 26) = result;
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the copied byte+word pair are only DERIVED from prose (collision body type + handle); the owning collision-body class is unknown.
    // UNRESOLVED: Whether the returned word is consumed by the callers is not established.
}
