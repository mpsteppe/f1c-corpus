// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553650
// Canonical corpus name: sub_553650
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_553650_00553650.c

void UnknownObject::VertexBufferInsert()
{
    // Inserts one vertex into a UI/2D primitive vertex buffer at index a2 (a2 in 0..15). Writes a 28-byte vertex record into the data array at this[6] (byte offset 0x18): position x computed from renderer constants plus a3, y/z from a4/a5, a constant 1065353216 dword, then a8 and a6/a7. Grows the stored count this[1] when the index exceeds it, and sets dirty flag bit 0x8000 on this[0]. Returns 0 on success; logs a wrong-vertex or too-many-vertices error and returns -1 when a pre-condition fails.
    // GUARD: Guard a2 <= 15 (max 16 vertices); on overflow log aTooManyVertice and return -1. [source:raw, global:0x005DC140]
    // GUARD: Guard this[0] bit 0x2 set (vertex insertion enabled); otherwise log aWrongVertexFor and return -1. [source:raw, field:this:0x00000000, global:0x005DC12C]
    // ASSIGNMENT: Grow the tracked vertex count: when a2 > this[1] - 1 set this[1] = a2 + 1. [source:raw, field:this:0x00000004]
    // CALCULATION: Compute the byte offset into the vertex data array as 28 * a2 (28-byte stride per vertex). [source:raw, field:this:0x00000018]
    // ASSIGNMENT: Write vertex field at +0: flt_8B8CF0 * dword_8B8DD4 + flt_8B8CF4 * a3. [source:raw, field:this:0x00000018, global:0x008B8CF0, global:0x008B8DD4, global:0x008B8CF4]
    // ASSIGNMENT: Write vertex fields at +4 = a4 and +8 = a5. [source:raw, field:this:0x00000018]
    // ASSIGNMENT: Write constant dword 1065353216 at vertex offset +12. [source:raw, field:this:0x00000018]
    // ASSIGNMENT: Write a8 as dword at vertex offset +16 and a6/a7 as floats at +20 and +24. [source:raw, field:this:0x00000018]
    // STATE_TRANSITION: Set dirty flag: this[0] |= 0x8000 after a successful insert. [source:raw, field:this:0x00000000]
    // RETURN: Return 0 on a successful insert. [source:raw]
    // CALL: Error path: sub_53C590(-1, aWrongVertexFor) when the insertion-enabled bit is not set. [source:raw, callee:0x0053C590, global:0x005DC12C]
    // CALL: Error path: sub_53C590(-1, aTooManyVertice) when the index exceeds 15. [source:raw, callee:0x0053C590, global:0x005DC140]
    // CALL: Listed as the vertex-insert routine invoked by 2D quad/rectangle/sparkle and related render helpers. [caller:0x00494690, caller:0x00494A70, caller:0x0049EA10, caller:0x0049EB40, caller:0x0049ED30, caller:0x004D8CF0, caller:0x004D90D0, caller:0x004DCA80]

    // Conservative worker pseudocode:
    //   int sub_553650(_DWORD* this, int index, float a3, float a4, float a5, float a6, float a7, int a8) {
    //     if (index > 15) { sub_53C590(-1, aTooManyVertice); return -1; }
    //     if (!(this[0] & 2)) { sub_53C590(-1, aWrongVertexFor); return -1; }
    //     if (index > this[1] - 1) this[1] = index + 1;
    //     float* v = (float*)((char*)this[6] + 28 * index);
    //     v[0] = flt_8B8CF0 * dword_8B8DD4 + flt_8B8CF4 * a3;
    //     v[1] = a4; v[2] = a5;
    //     *(_DWORD*)(v + 3) = 1065353216;
    //     *(_DWORD*)(v + 4) = a8;
    //     v[5] = a6; v[6] = a7;
    //     this[0] |= 0x8000;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic meaning of the combined renderer constants flt_8B8CF0, flt_8B8CF4 and dword_8B8DD4 in the x-position term is not documented here
    // UNRESOLVED: Field roles (a8 dword, a6/a7 floats, the 1065353216 constant) are inferred from vertex layout only; their UI-specific meaning is unverified
    // UNRESOLVED: Vertex data array pointer this[6] base and 16-slot capacity are not validated against the buffer's real allocation
}
