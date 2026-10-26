// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491300
// Canonical corpus name: MultiShortStructWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiShortStructWriter_00491300.c

void UnknownObject::RectOrAABBInitializer()
{
    // Simple struct initializer. Writes four short arguments into a word-aligned layout at this+0x0, this+0x2, this+0x4 and this+0x6 (e.g. AABB/rect coordinates), then zeroes the DWORD at this+0xC. Unconditional and side-effect free apart from those writes. Called by RenderDispatchWithIteration (004993D0).
    // ASSIGNMENT: Store a2 at this+0x0 (first short field) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store a3 at this+0x2 (second short field) [field:this:0x00000002, source:raw]
    // ASSIGNMENT: Store a4 at this+0x4 (third short field) [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store a5 at this+0x6 (fourth short field) [field:this:0x00000006, source:raw]
    // ASSIGNMENT: Zero the DWORD at this+0xC [field:this:0x0000000C, source:raw]
    // RETURN: Return the this pointer as the initialized object [function:0x00491300, source:raw]
    // CALL: Invoked by RenderDispatchWithIteration (004993D0) to initialize a per-item rectangle/AABB record [caller:0x004993D0, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = a2;
    //   this[1] = a3;
    //   this[2] = a4;
    //   this[3] = a5;
    //   *(this + 0xC) = 0;
    //   return this;
    // UNRESOLVED: Whether the four shorts at +0x0..+0x6 are rectangle or AABB coordinates is inferred from caller context only; the raw body just stores the four arguments
}
