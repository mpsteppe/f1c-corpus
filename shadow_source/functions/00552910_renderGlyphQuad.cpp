// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00552910
// Canonical corpus name: sub_552910
// Owner: FontGlyphRenderer [DERIVED]
// Raw source: functions/sub_552910_00552910.c

void FontGlyphRenderer::renderGlyphQuad()
{
    // Renders a single font glyph as a textured quad. Validates glyph index a2 against a minimum 0x20 and the glyph count at this+0x44, then either calls ClippedRenderRegion directly when flag bit 0x10000 at this+0x24 is set, or appends six textured vertices (two triangles) to the vertex buffer at this+0x10. Returns a per-glyph attribute byte from the glyph table.
    // GUARD: Reject glyph index a2 below 0x20 or at or above the glyph count stored at this+0x44; both failures return 0. [field:this:0x00000044]
    // CALCULATION: Load glyph advance and width entries from the per-glyph table and compute the render cell size from this+0x34 (width) and this+0x38 (height), each decremented by one. [field:this:0x00000034, field:this:0x00000038]
    // GUARD: Select the render path by flag bit 0x10000 at this+0x24. [field:this:0x00000024]
    // CALL: ClippedRenderRegion path: emit the glyph through the clip-region helper using the texture pointer at this+0x64, the per-glyph geometry, the render parameter at this+0x2C and the cell size derived from this+0x34/this+0x38. [callee:0x00543250, field:this:0x0000002C, field:this:0x00000064]
    // CALCULATION: Normalize glyph UV coordinates by dividing glyph pixel metrics by the source texture width at *(this+0x64)+0x1C and height at *(this+0x64)+0x20. [field:*(this+0x64):0x0000001C, field:*(this+0x64):0x00000020]
    // CALCULATION: Scale the destination cell by this+0x5C and this+0x60 to build the final vertex screen positions. [field:this:0x0000005C, field:this:0x00000060]
    // LOOP: Append six vertices (two triangles) at the current vertex buffer position *(this+0x10): each vertex stores X at +0x0, Y at +0x4, a zero field at +0x8, RHW 1.0f at +0xC, the diffuse color from this+0x48 at +0x10, and U/V at +0x14/+0x18, striding +0x1C per vertex. [field:this:0x00000010, field:*(this+0x10):0x00000000, field:*(this+0x10):0x00000004, field:*(this+0x10):0x00000008, field:*(this+0x10):0x0000000C, field:*(this+0x10):0x00000010, field:*(this+0x10):0x00000014, field:*(this+0x10):0x00000018, field:*(this+0x10):0x0000001C, field:this:0x00000048]
    // ASSIGNMENT: Advance the vertex buffer pointer this+0x10 by 28 bytes and increment the running vertex count at this+0x8 by 6. [field:this:0x00000010, field:this:0x00000008]
    // RETURN: Return the per-glyph attribute byte from the glyph table entry (this plus 8*a2 minus 148). [source:raw]

    // Conservative worker pseudocode:
    //   if (glyphIndex < 0x20 || glyphIndex >= glyphCount) return 0;
    //   if (flags & 0x10000) ClippedRenderRegion(texture, ...); else { emit 6 vertices; advance buffer/count; }
    //   return glyphTable[glyphIndex].flags;
}
