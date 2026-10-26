// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00552BA0
// Canonical corpus name: sub_552BA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_552BA0_00552ba0.c

void UnknownObject::FontTextureSheetAnalyzer()
{
    // Analyzes a font texture sheet surface to derive glyph cell layout and rewrite the pixel transparency mask. Reads the surface object at this+0x64 (width +0x20, height +0x1C, pitch +0x28, pixel format +0x30, flags +0x18), accesses its 16-bit pixel data via ThunkWithArgReorder, scans for sentinel colors to find the horizontal and vertical cell divisions, stores the three key colors at this+0x28/0x2C/0x30 and the cell counts/pitches at this+0x34..0x40, computes total cell count into this+0x44, builds an 8-byte per-cell lookup table at this+0x6D, then walks every pixel and rewrites the alpha-mask bits (clearing them for key-color pixels and setting the +0x18 surface flag 0x800, OR-ing them otherwise). Finalizes the surface through ArgumentReorderWrapper_3230.
    // GUARD: Guard on the pixel-format field at *(this+0x64)+0x30: if it is not 5 the alpha-mask value v36 is 0, otherwise it is 0x8000. [field:*(this+0x64):0x00000030, guard:0, source:raw]
    // CALL: Load the surface object pointer at this+0x64, read its flags field +0x18, and call ThunkWithArgReorder(surface, flags, 0) to obtain the 16-bit pixel data pointer. [field:this:0x00000064, field:*(this+0x64):0x00000018, callee:0x00543210, source:raw]
    // CALCULATION: Read surface width (+0x20), height (+0x1C) and pitch (+0x28); compute the probe index height + (pitch/2)*(width-2) and store three sentinel 16-bit words from the pixel data into this+0x28, this+0x2C and this+0x30. [field:*(this+0x64):0x00000020, field:*(this+0x64):0x0000001C, field:*(this+0x64):0x00000028, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // LOOP: Scan the pixel row at cell stride for the first sentinel value equal to this+0x28; record the horizontal cell count at this+0x34 and the horizontal cell pitch at this+0x3C. [field:this:0x00000034, field:this:0x0000003C, source:raw]
    // LOOP: Scan down the column at cell stride for the first sentinel value equal to this+0x28; record the vertical cell count at this+0x38 and the vertical cell pitch at this+0x40. [field:this:0x00000038, field:this:0x00000040, source:raw]
    // CALCULATION: Compute total cell count v17 = vertical pitch * horizontal pitch and store it plus 32 overhead at this+0x44. [field:this:0x00000044, source:raw]
    // LOOP: If v17 > 0, build the per-cell lookup table at this+0x6D: for each cell, scan the 16-bit pixels at the computed cell offset until the key color (this+0x30) is found and store an 8-byte record (grid column, row, cell offset x, cell offset y). [field:this:0x0000006D, field:this:0x00000030, source:raw]
    // LOOP: If surface width * height > 0, walk every 16-bit pixel of the sheet: if the pixel equals any of the three key colors (this+0x30, this+0x28 or this+0x2C), clear the alpha-mask bits with v36 and set the surface flags at +0x18 with the 0x800 pixel-modified flag; otherwise OR the alpha-mask value v36 into the pixel. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:*(this+0x64):0x00000018, source:raw]
    // ASSIGNMENT: Clear the alpha-mask bits (v36) from the stored second key color this+0x2C. [field:this:0x0000002C, source:raw]
    // RETURN: Call ArgumentReorderWrapper_3230(surface object, surface flags at +0x18, 0) to finalize the surface and return its result. [field:this:0x00000064, field:*(this+0x64):0x00000018, callee:0x00543230, source:raw]

    // Conservative worker pseudocode:
    //   surface = *(this+0x64);
    //   mask = surface[0x30] != 5 ? 0 : 0x8000;
    //   pixels = ThunkWithArgReorder(surface, surface[0x18], 0);
    //   w = surface[0x20]; h = surface[0x1C]; pitch = surface[0x28] >> 1;
    //   probe = h + pitch*(w-2);
    //   this+0x28 = pixels[probe-1]; this+0x2C = pixels[probe-2]; this+0x30 = pixels[probe-3];
    //   scan row for first == this+0x28 -> this+0x34 (count), this+0x3C (pitch);
    //   scan column for first == this+0x28 -> this+0x38 (count), this+0x40 (pitch);
    //   total = this+0x40 * this+0x3C; this+0x44 = total + 32;
    //   if total > 0: build 8-byte per-cell table at this+0x6D (keyed on this+0x30);
    //   if surface[0x1C]*surface[0x20] > 0:
    //       for each pixel:
    //           if pixel == this+0x30 or pixel == this+0x28 or pixel == this+0x2C: pixel &= ~mask; surface[0x18] |= 0x800
    //           else: pixel |= mask
    //   this+0x2C &= ~mask;
    //   return ArgumentReorderWrapper_3230(surface, surface[0x18], 0)
    // UNRESOLVED: Meanings of the three key colors (this+0x28/0x2C/0x30), the cell layout fields (this+0x34..0x40) and the 8-byte cell-record structure at this+0x6D are DERIVED from the pixel-scan behavior; the packet carries no field names for this type.
    // UNRESOLVED: The semantic roles of ThunkWithArgReorder / ArgumentReorderWrapper_3230 (surface pixel-data access and finalize) are inferred from usage and are DERIVED.
    // UNRESOLVED: The second key color this+0x2C retains the sentinel value read from the pixel probe rather than a user-set color; whether the final mask-clear on it is intentional or residual is unresolved.
}
