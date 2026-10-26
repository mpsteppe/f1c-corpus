// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487F70
// Canonical corpus name: UIFieldRenderer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIFieldRenderer_00487f70.c

void UnknownObject::RenderField()
{
    // Renders a UI field with text and an optional centered bitmap. Validates the label string at this+0xB0 (fallback byte_5EA438) and the visibility flag at this+0xC8, selects the rendering context via ShortComputation_6720 and ByteFieldGetterAt100, binds it through sub_498560, and measures the label with TextRenderToSurface. Computes a centered position from the bound fields this+0x4..this+0x10 and the optional sub-structures at this+0x98/this+0x9C (using their +0x4 and +0xC offsets), then renders with BitmapDraw_81f0 and writes the final rectangle to output parameters a2..a5. Returns 0 on success, -1 when no label/layout is available.
    // GUARD: Load the label pointer from this+0xB0, falling back to byte_5EA438 when null; return 0 early when the string is empty or when the visibility flag at this+0xC8 is clear. [field:this:0x000000B0, field:this:0x000000C8, global:0x005EA438, source:raw]
    // CALL: ShortComputation_6720(this) selects the context branch; combined with ByteFieldGetterAt100(this) it picks the context string from the obj-relative slots +0x18/+0x1C, defaulting to byte_5EA438. [callee:0x00486720, callee:0x00486710, field:obj:0x00000018, field:obj:0x0000001C, global:0x005EA438, source:raw]
    // CALL: sub_498560(*(this+0x40), context) binds the selected context to the render base stored at this+0x40. [callee:0x00498560, field:this:0x00000040, source:raw]
    // CALL: TextRenderToSurface(*(this+0x40), label, &v32, &v31, 1) measures the label into width v31 and height v32; if either dimension is non-positive return 0. [callee:0x004983B0, field:this:0x00000040, field:this:0x000000B0, global:0x005EA438, source:raw]
    // CALCULATION: Vertical centering against the virtual bound query (vtable+24) and the sub-structure at this+0x9C (its +0xC and +0x4 fields); when the bounds do not fit, fall back to the raw vtable+24 result. [field:this:0x00000000, field:this:0x0000009C, field:*(this+0x9C):0x0000000C, field:*(this+0x9C):0x00000004, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALCULATION: Horizontal centering against the virtual bound query (vtable+28) and the this+0x4/this+0x8 bounds; when the bounds do not fit, fall back to the raw vtable+28 result. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: When this+0x9C is null, repeat the vertical centering using the alternate sub-structure at this+0x98 (its +0xC and +0x4 fields) and the vtable+24/+28 queries. [field:this:0x00000098, field:*(this+0x98):0x0000000C, field:*(this+0x98):0x00000004, field:this:0x00000000, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALL: BitmapDraw_81f0(*(this+0x40), label, x, x + width, y, y + height, 1) renders the field bitmap at the centered rectangle. [callee:0x004981F0, field:this:0x00000040, field:this:0x000000B0, global:0x005EA438, source:raw]
    // ASSIGNMENT: Write the final rectangle into output parameters a2..a5 (left, right, top, bottom) from the centered positions and measured dimensions. [source:raw]
    // RETURN: Return 0 on success; -1 when no label or layout is available. [function:0x00487F70, source:raw]

    // Conservative worker pseudocode:
    //   label = this[44] or byte_5EA438;
    //   if (!label[0] || !this[200]) return 0;
    //   mode = ShortComputation_6720(this);
    //   ctx = (mode == 0 || mode == 2) ? (ByteFieldGetterAt100(this) ? base[72] : base[64]) : base[72];
    //   if (!ctx) ctx = byte_5EA438;
    //   if (!ctx) return 0;
    //   sub_498560(this[64], ctx);
    //   TextRenderToSurface(this[64], label, &height, &width, 1);
    //   if (width <= 0 || height <= 0) return 0;
    //   if (this[0x9C]) { vertical = center_vert(sub at 0x9C); }
    //   else if (this[0x98]) { vertical = center_vert(sub at 0x98); }
    //   else return -1;
    //   horizontal = center_horiz();
    //   BitmapDraw_81f0(this[64], label, horizontal, horizontal + width, vertical, vertical + height, 1);
    //   *a2 = horizontal; *a3 = horizontal + width; *a4 = vertical; *a5 = vertical + height;
    //   return 0;
    // UNRESOLVED: The exact meaning of the context-selection branch (ShortComputation_6720 / ByteFieldGetterAt100) and the obj-relative context slots +0x18/+0x1C is not established beyond their role in choosing the render context.
    // UNRESOLVED: The sub-structures at this+0x98 and this+0x9C are layout/position objects; their +0x4 and +0xC fields participate in centering but their full type is unknown.
    // UNRESOLVED: The virtual queries at vtable+24 and vtable+28 are bound-query methods on the UI object; their exact semantics are not asserted.
}
