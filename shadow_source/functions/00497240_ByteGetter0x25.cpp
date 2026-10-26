// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497240
// Canonical corpus name: ByteGetter0x25
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteGetter0x25_00497240.c

void UnknownObject::ByteGetter0x25()
{
    // Trivial __thiscall byte getter: returns the byte field at offset 0x25 of this. No side effects, no guards, globals, or callees. Called by sub_496E90 (0x00496E90), which consumes the byte in an unknown context.
    // RETURN: Return the byte field at offset 0x25 of this (this[0x25]). Read-only access; no side effects. [source:raw, field:this:0x00000025, function:0x00497240]

    // Conservative worker pseudocode:
    //   char __thiscall sub_497240(_BYTE *this) {
    //     return this[0x25];
    //   }
    // UNRESOLVED: Semantic role of the byte field at offset 0x25 (state flag vs. mode selector) is not determinable from this function alone.
    // UNRESOLVED: Object type owning this getter is unknown; the single caller sub_496E90 must be analyzed to infer context.
}
