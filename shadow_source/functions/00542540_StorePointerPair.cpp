// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542540
// Canonical corpus name: PointerStorePair2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PointerStorePair2_00542540.c

void UnknownObject::StorePointerPair()
{
    // Trivial __thiscall setter: stores argument a2 at this+0x1A4 (this[105]) and argument a3 at this+0x1A8 (this[106]), returning a2. Used by AI/graphics dispatch callers to record a pair of pointer values on the receiver.
    // ASSIGNMENT: Store a2 into this+0x1A4 (this[105]). [field:this:0x000001A4, source:raw]
    // ASSIGNMENT: Store a3 into this+0x1A8 (this[106]). [field:this:0x000001A8, source:raw]
    // RETURN: Return a2, the first stored value. [source:raw]
    // CALL: Called by sub_409890 (0x00409890) and ConditionalRenderPipelineDispatch (0x00409970) to record a pair of pointer values on the receiver. [caller:0x00409890, caller:0x00409970, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall StorePointerPair(DWORD *this, int a2, int a3) {
    //     this[105] = a2;  // this+0x1A4
    //     this[106] = a3;  // this+0x1A8
    //     return a2;
    //   }
    // UNRESOLVED: Role of the two stored pointers (e.g. callback/context pair) and the identity of the owning object are unknown here; only the callers reveal usage.
}
