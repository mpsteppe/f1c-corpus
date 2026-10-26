// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7C00
// Canonical corpus name: ArrayAccessAt0xcIndex4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayAccessAt0xcIndex4_004d7c00.c

void UnknownObject::OffsetIndexedDwordRead()
{
    // Trivial offset indexed dword read: returns the array element this[a2 + 3], i.e. a dword 3 elements (12 bytes) beyond the a2-selected element. No guards, globals, fields or callees. Called by ScoringGateSelector on the frame path; the LEGACY ABI lead names the 0xc displacement with element index 4.
    // CALCULATION: Advance the element index by 3 dwords (a 12-byte byte displacement from this[a2]) to form this[a2 + 3]. [source:raw]
    // ASSIGNMENT: Read the dword at this[a2 + 3]. [function:0x004D7C00, source:raw]
    // RETURN: Return the dword read from this[a2 + 3]; invoked by ScoringGateSelector as an offset gate/score lookup. [caller:0x004D1AD0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D7C00(_DWORD* this, int a2) {
    //     return this[a2 + 3];
    //   }
    // UNRESOLVED: What the 3-element offset (0xc displacement) selects relative to the a2 element is not evidenced by this packet; it depends on the unknown owning object's layout.
    // UNRESOLVED: The owner class is unidentified; the LEGACY ABI lead names only the displacement and index pattern, not an object.
}
