// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00552D70
// Canonical corpus name: sub_552D70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_552D70_00552d70.c

void UnknownObject::AnalyzeFontTextureSheet32()
{
    // 32-bit RGBA font texture sheet analyzer. Locks the texture surface via ThunkWithArgReorder, derives horizontal/vertical cell divisions by scanning the pixel buffer for key-color sentinels, builds a per-cell glyph lookup table at this+0x6D, then rewrites every pixel: key colors become 0xF0F0F0 with the surface modification flag set, non-key pixels get forced alpha 0xFF000000. Stores the default key color at this+0x2C and unlocks the surface via ArgumentReorderWrapper_3230.
    // CALL: Lock the texture surface: call ThunkWithArgReorder with the surface pointer stored at this+0x64 and its pixel-data pointer at surface+0x18; the returned buffer is the locked pixel array. [callee:0x00543210, field:this:0x00000064, field:*(this+0x64):0x00000018]
    // ASSIGNMENT: Read the locked surface dimensions used for all cell arithmetic: width at surface+0x1C, height at surface+0x20 and row pitch at surface+0x28. [field:*(this+0x64):0x0000001C, field:*(this+0x64):0x00000020, field:*(this+0x64):0x00000028]
    // ASSIGNMENT: Recover the three key-color sentinels from the tail of the pixel buffer (the sentinel row written after the glyph grid) and store them at this+0x28, this+0x2C and this+0x30. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030]
    // LOOP: Scan the pixel buffer along the row stride looking for the first pixel equal to the key color at this+0x28; the scan distance yields the horizontal cell count, stored at this+0x34. [field:this:0x00000034, field:this:0x00000028]
    // CALCULATION: Derive the horizontal cell pitch as the surface width (surface+0x1C) divided by the horizontal cell count and store it at this+0x3C. [field:this:0x0000003C, field:*(this+0x64):0x0000001C]
    // LOOP: Scan the pixel buffer along the pitch stride (surface+0x28) looking for the next key-color pixel; the scan distance yields the vertical cell count, stored at this+0x38. [field:this:0x00000038, field:*(this+0x64):0x00000028]
    // CALCULATION: Derive the vertical cell pitch as the surface height (surface+0x20) divided by the vertical cell count and store it at this+0x40; compute the total cell count plus 32 overhead entries and store it at this+0x44. [field:this:0x00000040, field:this:0x00000044, field:*(this+0x64):0x00000020]
    // LOOP: For every cell, resolve the glyph pixel index by walking the column/row strides and matching the key color; write the 8-byte cell metadata record at this+0x6D (u/v stride indices plus glyph index), advancing 8 bytes per cell. [field:this:0x0000006D, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040]
    // LOOP: Rewrite every pixel (width x height): if it equals one of the three key colors (this+0x28, this+0x2C, this+0x30) set it to 15790320 (0xF0F0F0) and OR the surface modification flag at surface+0x18 with 0x800; otherwise force the alpha channel by ORing the pixel with 0xFF000000. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:*(this+0x64):0x00000018]
    // ASSIGNMENT: Store the default key color 15790320 (0xF0F0F0) into this+0x2C as the canonical transparency color. [field:this:0x0000002C]
    // RETURN: Unlock the surface by returning the result of ArgumentReorderWrapper_3230 called with the same surface pointer (this+0x64) and pixel-data pointer arguments. [callee:0x00543230, field:this:0x00000064]

    // Conservative worker pseudocode:
    //   unsigned* lock = ThunkWithArgReorder(surface, surface->pixels, 0);
    //   int w = surface->w, h = surface->h, pitch = surface->pitch;
    //   keyA = lock[tail-1]; keyB = lock[tail-2]; keyC = lock[tail-3];
    //   cols = scan_horizontal_for(keyA, w); this->hcount = cols;
    //   this->hpitch = w / cols;
    //   rows = scan_vertical_for(keyA, pitch); this->vcount = rows;
    //   this->vpitch = h / rows; this->total = vpitch*hpitch + 32;
    //   for each cell: metadata[this->cells + 8*i] = {u, v, glyph_index};
    //   for each pixel: if is_key(pix) pix = 0xF0F0F0, surface->flags |= 0x800; else pix |= 0xFF000000;
    //   this->keyB = 0xF0F0F0;
    //   return ArgumentReorderWrapper_3230(surface, surface->pixels, 0);
    // UNRESOLVED: The exact semantics of the 8-byte cell metadata record fields (glyph index, u/v stride positions) are inferred from the write pattern, not confirmed against a glyph consumer.
    // UNRESOLVED: Caller TexturePathParsingAndDimensionCalculation (0x00552F20) determines when the 32-bit variant is used; the relationship to the 8-bit/other-format analyzers is not established here.
}
