// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044FC20
// Canonical corpus name: CollisionParameterClampAndStore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionParameterClampAndStore_0044fc20.c

void UnknownObject::CollisionParameterClampAndStore()
{
    // Clamps three float collision parameters into [0.0, 1.0] / non-negative ranges and stores them into the object at float indices a2+8 (byte 0x20 + 4*a2), a2+190 (byte 0x2F8 + 4*a2) and a2 (byte 4*a2). a4 and a5 are clamped to [0.0, 1.0]; a3 is clamped at 0.0 lower bound. Both branches then call D3DTextureStage(this) and return its result.
    // GUARD: Clamp a4 to lower bound 0.0 (zero-threshold constant) [global:0x0059E440, source:raw]
    // GUARD: Clamp a4 to upper bound 1.0 (one-threshold constant) [global:0x0059E43C, source:raw]
    // ASSIGNMENT: Store clamped a4 at float index a2+8 (byte 0x20 + 4*a2) [source:raw]
    // GUARD: Clamp a3 to lower bound 0.0 (zero-threshold constant) [global:0x0059E440, source:raw]
    // ASSIGNMENT: Store clamped a3 at float index a2+190 (byte 0x2F8 + 4*a2) [source:raw]
    // GUARD: Clamp a5: if a5 < 0.0 use 0.0, else clamp to upper bound 1.0 [global:0x0059E43C, global:0x0059E440, source:raw]
    // ASSIGNMENT: Store clamped a5 at float index a2 (byte 4*a2) [source:raw]
    // CALL: Call D3DTextureStage(this) in both branches; role within this collision-parameter function is unclear [callee:0x0044F8F0, source:raw]
    // RETURN: Return the D3DTextureStage call result on both paths [callee:0x0044F8F0, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionParameterClampAndStore(float* this, int slot, float a3, float a4, float a5) {
    //       float v5 = clamp(a4, 0.0f, 1.0f);
    //       this[slot + 8] = v5;
    //       float v6 = a3 < 0.0f ? 0.0f : a3;
    //       this[slot + 190] = v6;
    //       float v7 = a5 < 0.0f ? 0.0f : (a5 > 1.0f ? 1.0f : a5);
    //       this[slot] = v7;
    //       return D3DTextureStage((int)this);
    //   }
    // UNRESOLVED: The D3DTextureStage call inside this clamp-and-store function is suspicious and likely a decompiler artifact; the function's core role is clamping and storing.
    // UNRESOLVED: Semantic meaning of the three stored parameters at float offsets 4*a2, 0x20 + 4*a2 and 0x2F8 + 4*a2 is unconfirmed.
    // UNRESOLVED: flt_59E43C and flt_59E440 are treated as the 1.0 / 0.0 clamp constants the raw source inlines as literals; identities DERIVED from packet context, not confirmed.
}
