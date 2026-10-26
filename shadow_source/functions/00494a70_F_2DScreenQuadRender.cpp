// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494A70
// Canonical corpus name: F_2DScreenQuadRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DScreenQuadRender_00494a70.c

void UnknownObject::F_2DScreenQuadRender()
{
    // Renders a clipped 2D textured screen quad. Clamps the requested width and height to [0,256], sets up the clipped destination region on the surface global 0x007CDE08, scales the quad size to UV space with a 1/256 factor, configures the four corner UV coordinates via sub_553650, draws the quad via sub_553700, and wraps the draw in a conditional-state init/reset around global 0x008AFE18.
    // CALCULATION: Clamp width argument a4 into [0,256]: negative becomes 0, values above 256 are capped at 256. [source:raw]
    // CALCULATION: Clamp height argument a5 into [0,256]: negative becomes 0, values above 256 are capped at 256. [source:raw]
    // GUARD: Only proceed with rendering when the clamped width is > 0 and the clamped height is > 0; otherwise skip the draw and return the height value. [source:raw]
    // CALL: Set up the clipped render region: ClippedRenderRegion using the destination surface global dword_7CDE08 with the clamped width/height as the region size. [callee:0x00543250, global:0x007CDE08, source:raw]
    // CALCULATION: Convert quad pixel size to UV units by scaling the clamped width and height by 0.00390625 (1/256). [source:raw]
    // CALL: Configure the four corner UV coordinates for the quad via sub_553650 at corners (0,0), (0,h), (w,h), (w,0), passing texture-color arguments a11..a14. [callee:0x00553650, source:raw]
    // CALL: Initialize the conditional state object global unk_8AFE18 via ConditionalInit before drawing. [callee:0x004F9F00, global:0x008AFE18, source:raw]
    // CALL: Perform the actual draw of the quad via sub_553700(a6). [callee:0x00553700, source:raw]
    // CALL: Reset the conditional state object global unk_8AFE18 via ConditionalStateReset after the draw. [callee:0x004F9F30, global:0x008AFE18, source:raw]
    // RETURN: Return the (clamped) height value as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   int F_2DScreenQuadRender(int a1, float a2, float a3, int width, int height, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14) {
    //     if (width < 0) width = 0;
    //     else if (width > 256) width = 256;
    //     if (height < 0) height = 0;
    //     else if (height > 256) height = 256;
    //     if (width > 0 && height > 0) {
    //       ClippedRenderRegion(a2, a3, dword_7CDE08, 0, 0, width, height, 0, 0);
    //       float u = width * 0.00390625;
    //       float v = height * 0.00390625;
    //       sub_553650(0, a7, a8, 1.0, 0.0, 0.0, a11);
    //       sub_553650(1, a7, a8 + a10, 1.0, 0.0, v, a12);
    //       sub_553650(2, a9 + a7, a8 + a10, 1.0, u, v, a13);
    //       sub_553650(3, a9 + a7, a8, 1.0, u, 0.0, a14);
    //       ConditionalInit(&unk_8AFE18);
    //       sub_553700(a6);
    //       ConditionalStateReset(&unk_8AFE18);
    //     }
    //     return height;
    //   }
    // UNRESOLVED: Global flt_5AC988 is listed in the packet but not directly referenced by the visible raw source text; its exact role in UV scaling is not determinable from this function alone.
    // UNRESOLVED: Global dword_7CDE0C is listed in the packet but not directly referenced by the visible raw source text; its role here is unknown.
    // UNRESOLVED: Sub-functions sub_553650 (UV setup) and sub_553700 (draw) have no semantic names in the corpus.
    // UNRESOLVED: Owner object is unknown; the caller UIScrollViewRender supplies the parameter block.
}
