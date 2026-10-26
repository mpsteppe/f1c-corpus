// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D90D0
// Canonical corpus name: QuadRenderWithColor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadRenderWithColor_004d90d0.c

void UnknownObject::QuadRenderWithColor()
{
    // Renders a quad by emitting four vertices (triangle strip) through sub_553650, skipping the render entirely when the a2 parameter is 0.0. The base Y position depends on the participant slot field this+0x8: -1 selects 0.0 (top row), any other value selects 140.0. The quad geometry is scaled from this+0xE4 (width factor) and this+0xE8 (height factor) against 1280.0 and 50.0. Invoked by sub_4D8A30 as a HUD quad render helper.
    // GUARD: Skip the entire quad render when a2 == 0.0; the function then returns an uninitialized value. [source:raw]
    // GUARD: Slot guard: when this+0x8 == -1 (0xFFFFFFFF) the base Y is 0.0 (top row); otherwise it is 140.0. [field:this:0x00000008, guard:0, source:raw]
    // CALCULATION: Compute quad geometry from the screen-size fields: v6 = this+0xE4 * 0.0; v9 = ybase * this+0xE8; v8 = this+0xE4 * 1280.0; v7 = this+0xE8 * 50.0. [field:this:0x000000E4, field:this:0x000000E8, source:raw]
    // CALL: sub_553650(0, v6, v9, 1.0, 0.0, 0.0, 0x80000000) emits vertex 0 of the quad. [callee:0x00553650, source:raw]
    // CALCULATION: v10 = v7 + v9 (right-edge Y of the second row). [source:raw]
    // CALL: sub_553650(1, v6, v10, 1.0, 0.0, 1.0, 0x80000000) emits vertex 1 of the quad. [callee:0x00553650, source:raw]
    // CALCULATION: v11 = v8 + v6 (right-edge X). [source:raw]
    // CALL: sub_553650(2, v11, v4, 1.0, 1.0, 1.0, 0x80000000) emits vertex 2 of the quad. [callee:0x00553650, source:raw]
    // RETURN: sub_553650(3, v11, v3, 1.0, 1.0, 0.0, 0x80000000) emits vertex 3 and its result is returned as the function result. [callee:0x00553650, function:0x004D90D0, source:raw]
    // CALL: Invoked by sub_4D8A30 (0x004D8A30) as a HUD quad render helper; the ABI description records quad triangle-strip rendering with colors. [abi:lead, caller:0x004D8A30, source:raw]

    // Conservative worker pseudocode:
    //   int QuadRenderWithColor(int this, float a2) {
    //     if (a2 == 0.0) return result;  // uninitialized in the decompiled form
    //     float ybase = (*(int*)(this + 8) == -1) ? 0.0 : 140.0;
    //     float v6 = *(float*)(this + 228) * 0.0;
    //     float v9 = ybase * *(float*)(this + 232);
    //     float v8 = *(float*)(this + 228) * 1280.0;
    //     float v7 = *(float*)(this + 232) * 50.0;
    //     sub_553650(0, v6, v9, 1.0, 0.0, 0.0, 0x80000000);
    //     float v10 = v7 + v9;
    //     sub_553650(1, v6, v10, 1.0, 0.0, 1.0, 0x80000000);
    //     float v11 = v8 + v6;
    //     sub_553650(2, v11, v10, 1.0, 1.0, 1.0, 0x80000000);
    //     return sub_553650(3, v11, v9, 1.0, 1.0, 0.0, 0x80000000);
    //   }
    // UNRESOLVED: The four read globals flt_59E440 / flt_59E828 / flt_5ACF40 / flt_5ACF44 are recorded as reads, but the packet's raw source renders the geometry constants as literals (0.0, 140.0, 1280.0, 50.0); the mapping of each global to a literal cannot be determined from this packet.
    // UNRESOLVED: sub_553650's argument meaning (vertex index, x, y, then color/alpha or UV channels, and the 0x80000000 flag) is inferred; the exact vertex/UV semantics live outside this packet.
    // UNRESOLVED: The a2 == 0.0 path returns an uninitialized value in the decompiled form.
}
