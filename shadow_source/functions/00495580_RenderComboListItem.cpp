// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495580
// Canonical corpus name: UIComboListRender
// Owner: UIComboBoxObject [DERIVED]
// Raw source: functions/UIComboListRender_00495580.c

void UIComboBoxObject::RenderComboListItem()
{
    // Renders one combo-box / dropdown list item: guarded by the enable byte at this+5512, the scroll float at this+204 being at least the threshold at this+208, and a non-null current-object pointer at this+5484. It measures the item label from the object's +192 string with TextRenderToSurface, lazily (re)computes the centered, 800x600-clamped position when the object at this+5484 changes from the cached this+5488, then fills the background rect either full-size or animated-scaled by the scroll delta at this+212. On guard failure it clears the cached pointer at this+5488. Called by sub_496E90 (0x00496E90).
    // GUARD: Render only when the enable byte at this+5512 is non-zero, the float at this+204 is >= the float at this+208, and the current-object pointer at this+5484 is non-zero; otherwise reset the cached pointer this+5488 to 0 and return. Called by sub_496E90 (0x00496E90). [field:this:0x00001588, field:this:0x000000CC, field:this:0x000000D0, field:this:0x0000156C, field:this:0x00001570, caller:0x00496E90, source:raw]
    // ASSIGNMENT: Read the item label string from the current object at this+5484 offset 192, falling back to byte_5EA438 when null; proceed only when the string is non-empty. [field:*(this+0x156C):0x000000C0, field:this:0x0000156C, global:0x005EA438, source:raw]
    // CALL: Prepare the display name: when the buffer at this+5432 is non-empty run DriverNameStringHandler and then sub_498560 on it; otherwise run ShortComputation_8550 on this. [callee:0x00497EC0, callee:0x00498560, callee:0x00498550, source:raw]
    // CALL: Measure the label with TextRenderToSurface(label, &v23, &v24, 1), obtaining the text width in v23 and height in v24. [callee:0x004983B0, source:raw]
    // GUARD: Change detection: when the cached pointer this+5488 differs from the current object this+5484, recompute the rendered origin as X = this+92 - (v23 + 8) / 2 and Y = (v24 + 4) / 2 + 4, cache the current object into this+5488, invoke the object's layout virtual, and clamp X into [0, 800 - (v23 + 8)] and Y into [0, 600 - (v24 + 4)]. The clamped results are stored in this+5516 (X) and this+5520 (Y). [field:this:0x00001570, field:this:0x0000156C, field:this:0x0000005C, field:this:0x0000158C, field:this:0x00001590, source:raw]
    // CALL: Invoke the layout virtual at vtable slot 8 of the current object (indirect call through the object's vtable at *(this+5484)) with the four layout/scratch parameter buffers. [field:*(this+0x156C):0x00000000, field:*(*(this+0x156C)+0x0):0x00000008, field:this:0x0000156C, source:raw]
    // CALCULATION: Compute the scroll delta as float(this+204) minus float(this+208). When float(this+212) minus the delta is still positive, the item is animating: derive a scale factor from the delta over float(this+212), square it, and convert with CRTFtol; when that squared size exceeds 2, fill an animated-scaled background rect. [field:this:0x000000D4, field:this:0x000000CC, field:this:0x000000D0, callee:0x00587BDC, source:raw]
    // CALL: Draw the background: in the animated case use RenderSurfaceFillCopy on the accessor surface with the scaled rect size (s+1 by s+2); in the settled case fill the full rect at this+5516/this+5520 sized (v23 + 8 + 10) by (v24 + 4 + 10). [callee:0x004918D0, callee:0x00490920, field:this:0x0000158C, field:this:0x00001590, source:raw]

    // Conservative worker pseudocode:
    //   if (!this[5512] || *(float*)(this+204) < *(float*)(this+208) || !this[5484]) { this[5488] = 0; return; }
    //   label = *(char**)(this[5484] + 192) ? *(char**)(this[5484] + 192) : defaultStr;
    //   if (strlen(label)) {
    //     if (strlen(this+5432)) { DriverNameStringHandler(this+5432); sub_498560(this+5432); }
    //     else { ShortComputation_8550(this); }
    //     measure(label, &w, &h, 1);
    //     if (this[5488] != this[5484]) {
    //       this[5516] = this[92] - (w + 8) / 2;
    //       this[5488] = this[5484];
    //       obj->vtable[8](this[5484], &a, &b, &c, &d);
    //       clamp this[5516] into [0, 800 - (w + 8)];
    //       clamp this[5520] into [0, 600 - (h + 4)];
    //     }
    //     delta = *(float*)(this+204) - *(float*)(this+208);
    //     if (*(float*)(this+212) - delta > epsilon) {
    //       s = CRTFtol((delta / *(float*)(this+212)) * (delta / *(float*)(this+212)));
    //       if (s > 2) RenderSurfaceFillCopy(surface(), this[5516], this[5520], s + 1, s + 2);
    //     } else {
    //       RenderSurfaceFillCopy(surface(), this[5516], this[5520], (w + 8) + 10, (h + 4) + 10);
    //     }
    //   }
    // UNRESOLVED: Global 0x005AC9C0 is listed as a packet read but does not appear in the raw function text; its role is unknown.
    // UNRESOLVED: The exact meaning of the floats at this+204/this+208/this+212 (scroll progress, threshold, smoothing factor) is inferred from the animated-scale branch, not independently evidenced.
    // UNRESOLVED: The concrete class behind the current-object vtable (slot 8 layout virtual) and of `this` itself is not named by the packet.
    // UNRESOLVED: The layout buffer parameters passed to the slot-8 virtual are not further interpreted.
}
