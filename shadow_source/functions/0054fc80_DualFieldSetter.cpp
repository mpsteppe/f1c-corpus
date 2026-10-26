// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FC80
// Canonical corpus name: DualFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualFieldSetter_0054fc80.c

void UnknownObject::DualFieldSetter()
{
    // Trivial __thiscall pair-setter: saves argument a2 as the return value, stores a2 into this[28] (byte offset 0x70), stores a3 into this[29] (byte offset 0x74), then returns the saved a2. No guard, no globals, no callees. Called by five render-state setup helpers (sub_546F70, sub_546FE0, ConditionalRenderStateSetup, GuardedRenderStateSet, DirectXMeshVertexBufferParsingAndLoading); the owning object and the meaning of the two consecutive dword fields are not established by this packet.
    // ASSIGNMENT: Save the first argument a2 into result so it can be returned after the field writes. [source:raw]
    // ASSIGNMENT: Write a2 into this[28], the first of two consecutive dword fields. [field:this:0x00000070, source:raw]
    // ASSIGNMENT: Write a3 into this[29], the second of two consecutive dword fields. [field:this:0x00000074, source:raw]
    // RETURN: Return the saved copy of a2. [function:0x0054FC80, source:raw]

    // Conservative worker pseudocode:
    //   int DualFieldSetter(void *this, int a2, int a3) {
    //     int result = a2;
    //     this[28] = a2;
    //     this[29] = a3;
    //     return result;
    //   }
    // UNRESOLVED: Owning object type unknown; this packet identifies the object only as UnknownObject.
    // UNRESOLVED: Semantic meaning of the fields at 0x70/0x74 is owned by the five calling render-state setup helpers, none of which are analyzed here.
    // UNRESOLVED: Why a2 is returned (rather than a3 or void) is caller convention, not visible from this function alone.
}
