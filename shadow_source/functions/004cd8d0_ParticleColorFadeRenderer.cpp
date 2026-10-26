// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CD8D0
// Canonical corpus name: sub_4CD8D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4CD8D0_004cd8d0.c

void UnknownObject::ParticleColorFadeRenderer()
{
    // Renders a particle set with a color fade derived from input a2. When (int)(a2 * 254.0) is nonzero it optionally triggers AIWaypointPathCheckerRenderer, then writes a packed color/alpha value into all four pixel attributes of every element in the pointer array at this[26] (count from this[25]). When the scaled input is zero it delegates to sub_4CB5E0 if elements exist.
    // CALCULATION: Scale the fade input: v8 = a2 * 254.0 and v3 = (int)v8; the 254.0 scale constant corresponds to flt_5ACEC4. [global:0x005ACEC4, source:raw]
    // GUARD: If v3 is nonzero run the fade-render path. [source:raw]
    // GUARD: If this[22] > 0 and this[25] == 0 trigger the waypoint checker render. [guard:0, field:this:0x00000058, field:this:0x00000064]
    // CALL: AIWaypointPathCheckerRenderer((int)dword_5EA2C0) renders the AI waypoint path checker visualization. [callee:0x004024F0, global:0x005EA2C0]
    // ASSIGNMENT: result = this[25] (element count) and v5 = (v3 << 24) + 0xFFFFFF (packed alpha plus full color). [field:this:0x00000064, source:raw]
    // LOOP: Loop over the element array: for i = 0 .. this[25] - 1. [source:raw]
    // ASSIGNMENT: v7 = *(_DWORD **)(this[26] + 4 * i): read the i-th element pointer from the array at this[26]. [field:this:0x00000068, source:raw]
    // CALL: PixelAttributeWriteToTexture(*v7, 0, v5) through PixelAttributeWriteToTexture(*v7, 3, v5): write the packed value into the element's four pixel attributes. [callee:0x00558DC0, source:raw]
    // GUARD: Else branch: when v3 == 0 and this[25] > 0 delegate to sub_4CB5E0(this). [callee:0x004CB5E0, field:this:0x00000064]
    // RETURN: Return result (the last read element count, or the result of sub_4CB5E0). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4CD8D0(_DWORD *this, float a2) {
    //     int v3 = (int)(a2 * 254.0f);
    //     if (v3) {
    //       if ((int)this[22] > 0 && !this[25]) AIWaypointPathCheckerRenderer((int)dword_5EA2C0);
    //       int result = this[25];
    //       int v5 = (v3 << 24) + 0xFFFFFF;
    //       for (int i = 0; i < result; ++i) {
    //         _DWORD *v7 = *(_DWORD **)(this[26] + 4 * i);
    //         PixelAttributeWriteToTexture(*v7, 0, v5);
    //         PixelAttributeWriteToTexture(*v7, 1, v5);
    //         PixelAttributeWriteToTexture(*v7, 2, v5);
    //         PixelAttributeWriteToTexture(*v7, 3, v5);
    //         result = this[25];
    //       }
    //       return result;
    //     }
    //     int result = this[25];
    //     if (result > 0) return sub_4CB5E0(this);
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the four per-element pixel attributes (0..3) is not established beyond 'written to texture'.
    // UNRESOLVED: Whether the 254.0 scale is loaded from flt_5ACEC4 or an inlined literal is unresolved.
    // UNRESOLVED: The fallback sub_4CB5E0 behavior for the zero-fade case is unknown.
}
