// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004883D0
// Canonical corpus name: UITextBoxRendererWithScrollbar
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UITextBoxRendererWithScrollbar_004883d0.c

void UnknownObject::RenderScrollableTextBox()
{
    // Renders a scrollable UI text-box widget with an optional scrollbar. Acquires a content sub-object via ConditionalDelegation_6460(this, 1), computes the scroll thumb geometry from the scroll position at this+0xE0 and virtual bounds queries, draws the content surface through F_10ParamForwarder, then handles an optional scrollbar sub-object (ConditionalDelegation_6460(this, 2)). Draws up to two text strings (header from this+0xB0, body from this+0xB8, both falling back to byte_5EA438) with centered bitmap placement, and writes an output bounding rectangle through output parameters a2..a5 that encloses all rendered content.
    // CALL: ConditionalDelegation_6460(this, 1) acquires the primary content sub-object v6; the whole content block is skipped when it returns null. [callee:0x00486460, source:raw]
    // GUARD: Guard on v6 non-null wrapping the content-rendering block. [source:raw]
    // ASSIGNMENT: Read the scroll position from this+0xE0 (this[56]) into local v7/v81 and load the vtable pointer from this+0x0. [field:this:0x000000E0, field:this:0x00000000, source:raw]
    // CALCULATION: Query the virtual width bound at vtable+24; when it exceeds this+0xC, extend v7 by the difference and refresh v81. [field:this:0x0000000C, field:this:0x000000E0, field:this:0x00000000, source:raw]
    // GUARD: When v7 > 0 and the byte at this+0xEC is clear, compute the scrollbar thumb geometry. [field:this:0x000000E0, field:this:0x000000EC, source:raw]
    // CALCULATION: Thumb sizing: read vtable+24 and vtable+32 results, form v84 = this+0x10 - this+0xC, then v7 = CRTFtol(scroll fraction) - 2. [field:this:0x00000000, field:this:0x00000004, field:this:0x0000000C, field:this:0x00000010, callee:0x00587BDC, source:raw]
    // CALCULATION: Read the content height v17 as the sub-object vertical extent (v6[3] - v6[2]). [field:obj:0x00000024, source:raw]
    // CALL: GlobalAccessor_5150(&unk_7CDE00) fetches a render-state handle, then F_10ParamForwarder draws the content surface (surface handle dereferenced from the sub-object at v6[8]+12) at the computed x/y/width/height. [callee:0x00495150, callee:0x00494A30, global:0x007CDE00, field:obj:0x00000020, field:this:0x00000004, field:this:0x0000000C, field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Write the content rectangle into the output parameters: a2 = this+0x4, a3 = this+0x4 + v17, a4 = this+0xC, a5 = this+0xC + v7. [field:this:0x00000004, field:this:0x0000000C, source:raw]
    // CALL: Unconditional virtual dispatch at vtable+0xAC (this+172) runs between the content and scrollbar sections. [field:this:0x00000000, field:obj:0x000000AC, source:raw]
    // CALL: ConditionalDelegation_6460(this, 2) acquires the scrollbar sub-object v24; the block is guarded on v24 non-null and the byte at this+0xEC being set. [callee:0x00486460, field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Store scrollbar geometry: this+0xE4 (this[57]) = v24[1] - v24[0], this+0xE8 (this[58]) = v24[3] - v24[2]. [field:this:0x000000E4, field:this:0x000000E8, source:raw]
    // CALCULATION: Position the scrollbar thumb from the scroll position at this+0xE0 and the virtual queries at vtable+24/+28/+36. [field:this:0x000000E0, field:this:0x00000000, source:raw]
    // CALL: F_10ParamForwarder draws the scrollbar surface via the same render-state handle returned by GlobalAccessor_5150. [callee:0x00495150, callee:0x00494A30, global:0x007CDE00, field:obj:0x00000020, field:this:0x000000E0, field:this:0x000000E4, field:this:0x000000E8, source:raw]
    // ASSIGNMENT: Expand the output rectangle a2..a5 to enclose the scrollbar geometry. [field:this:0x000000E4, field:this:0x000000E8, source:raw]
    // GUARD: Header-text section: label pointer from this+0xB0 (this[44]) falls back to byte_5EA438 when null; the section runs only when the string is non-empty. [field:this:0x000000B0, global:0x005EA438, source:raw]
    // CALL: When UIStringAccessor_62c0(this) yields a value it is passed to sub_498560 to set up the header rendering context; TextRenderToSurface then measures the header into v81/v82. [callee:0x004862C0, callee:0x00498560, callee:0x004983B0, field:this:0x000000B0, global:0x005EA438, source:raw]
    // CALCULATION: Center the header: horizontal center from this+0xC/this+0x10 and the measured width v81; vertical anchor this+0x4 minus the measured height v82 minus 1. [field:this:0x00000004, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALL: Draw the header bitmap: when sub_487060(this, 5) >= 0 use BitmapDrawWithAlpha, otherwise use the sub_487060/sub_4870E0 pair with BitmapDraw_81f0. [callee:0x00487060, callee:0x004870E0, callee:0x004982C0, callee:0x004981F0, field:this:0x000000B0, global:0x005EA438, source:raw]
    // ASSIGNMENT: Expand the output rectangle a2..a5 to enclose the header bitmap. [source:raw]
    // GUARD: Body-text section: pointer from this+0xB8 (this[46]) falls back to byte_5EA438 when null; the section runs only when the string is non-empty. [field:this:0x000000B8, global:0x005EA438, source:raw]
    // CALL: UIStringAccessor_62e0 feeds sub_498560; TextRenderToSurface measures the body string into v81/v82. [callee:0x004862E0, callee:0x00498560, callee:0x004983B0, field:this:0x000000B8, global:0x005EA438, source:raw]
    // CALL: Layout via UtilityFunction_7160(this, 3, &v83, &v84); on truthy, UtilityFunction_7160(this, 4, &a2, &v84) then BitmapDraw; otherwise TextRenderToSurface plus BitmapDraw_81f0. [callee:0x00487160, callee:0x004980D0, callee:0x004983B0, callee:0x004981F0, field:this:0x000000B8, global:0x005EA438, source:raw]
    // ASSIGNMENT: Expand the output rectangle a2..a5 to enclose the body rendering. [source:raw]
    // RETURN: Return 0. [function:0x004883D0, source:raw]

    // Conservative worker pseudocode:
    //   v6 = ConditionalDelegation_6460(this, 1);
    //   if (v6) {
    //     scroll = this[56];
    //     if (vtable(this, 24) > this[3]) scroll += vtable(this, 24) - this[3];
    //     if (scroll > 0 && !byte_at(this, 0xEC)) scroll = CRTFtol(fraction) - 2;
    //     F_10ParamForwarder(surface, v6, ..., GlobalAccessor_5150(&unk_7CDE00), ...);
    //     write_rect(a2, a3, a4, a5, this[1], this[1]+height, this[3], this[3]+scroll);
    //   }
    //   vtable(this, 172)();
    //   v24 = ConditionalDelegation_6460(this, 2);
    //   if (v24 && byte_at(this, 0xEC)) { store thumb geometry; draw scrollbar; expand rect; }
    //   draw_text(this[44] or byte_5EA438, centered);
    //   draw_text(this[46] or byte_5EA438, centered);
    //   return 0;
    // UNRESOLVED: field:obj:0x00000018 and field:obj:0x0000001C are listed by the extraction but could not be tied to an explicit line in the available raw body; their exact role in the content surface is not established.
    // UNRESOLVED: The globals dbl_59E420 (0x0059E420) and flt_59E450 (0x0059E450) are referenced by this function per the deterministic facts but do not appear in the available raw body text; their use is unresolved.
    // UNRESOLVED: field:obj:0x000000AC is cited on the unconditional vtable dispatch (vtable slot +0xAC); whether the extractor's base label obj matches this is ambiguous.
    // UNRESOLVED: The output rectangle write order in the raw body is interleaved and the last writer wins per section; the exact precedence between content, scrollbar, header and body is not asserted.
}
