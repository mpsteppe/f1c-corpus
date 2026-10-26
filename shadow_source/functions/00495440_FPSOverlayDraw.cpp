// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495440
// Canonical corpus name: FPSOverlayDraw
// Owner: FPSOverlayState [DERIVED]
// Raw source: functions/FPSOverlayDraw_00495440.c

void FPSOverlayState::FPSOverlayDraw()
{
    // Draws the FPS overlay. Scans the configuration WORD array (count at this+0x1598, data at this+0x159C) for sentinel 4129 (0x1021); on a match toggles the enable flag at this+0xE0 and, when toggled off, clears the overlay counters at +0xE4/+0xE8/+0xEC. While enabled, increments the per-frame counter at +0xE8 and accumulates per-frame delta time into the float at +0xEC from FloatFieldAccessor; when the accumulator passes a float-compare threshold, converts it with CRTFtol into +0xE4 and resets +0xEC/+0xE8. If the integer at +0xE4 is non-negative, formats it via StringFormatWithBufferOverflowCheck, renders it into a text surface (this+5740) through TextRenderToSurface, draws it with BitmapDraw_81f0, and copies the region to the display surface with RenderSurfaceFillCopy. Called from UILargeRender (0x00496930).
    // GUARD: Read config array count at this+0x1598; only proceed to scan when count > 0. [field:this:0x00001598, source:raw]
    // LOOP: Scan the config WORD array starting at this+0x159C for sentinel value 4129 (0x1021), advancing by WORD and bounded by the count at this+0x1598. [field:this:0x0000159C, field:this:0x00001598, guard:1, source:raw]
    // STATE_TRANSITION: On sentinel match, toggle the overlay enable flag at this+0xE0: new value is (old value == 0). [field:this:0x000000E0, guard:0, source:raw]
    // ASSIGNMENT: When the flag was toggled off, reset FPS value at this+0xE4, per-frame counter at this+0xE8, and float time accumulator at this+0xEC to 0. [field:this:0x000000E4, field:this:0x000000E8, field:this:0x000000EC, source:raw]
    // GUARD: If the overlay enable flag at this+0xE0 is nonzero, perform the draw update. [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Increment the per-frame counter at this+0xE8. [field:this:0x000000E8, source:raw]
    // CALCULATION: Accumulate frame delta time: float at this+0xEC += FloatFieldAccessor(this). [field:this:0x000000EC, callee:0x00498730, source:raw]
    // GUARD: If the FPU condition-code flags C0|C3 are clear after the accumulation (raw decompiler condition !(v7 | v8)), the accumulated time has passed a threshold; exact comparison semantics are not explicit in the packet. [source:raw]
    // ASSIGNMENT: On threshold: store CRTFtol(accumulator) into the integer at this+0xE4, then reset float accumulator at this+0xEC and frame counter at this+0xE8 to 0. [field:this:0x000000E4, field:this:0x000000EC, field:this:0x000000E8, callee:0x00587BDC, source:raw]
    // GUARD: Only draw when the integer value at this+0xE4 is >= 0. [field:this:0x000000E4, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(textBuffer, "%d", value at this+0xE4) formats the integer value into the local text buffer. [callee:0x0058815F, field:this:0x000000E4, source:raw]
    // CALL: TextRenderToSurface(this+5740, &v14, &v13, 1) renders the text into a text surface at this+5740 and reports the rendered width into v14 and height into v13. [callee:0x004983B0, source:raw]
    // GUARD: Proceed to blit only if rendered width v14 > 0 and height v13 > 0. [source:raw]
    // CALL: sub_498560(this+5740) prepares the text surface before the bitmap draw; exact behavior is unknown. [callee:0x00498560, source:raw]
    // CALL: BitmapDraw_81f0(textBuffer, 0, v13, 0, v14, 1) draws the formatted text buffer using the rendered dimensions. [callee:0x004981F0, source:raw]
    // CALL: RenderSurfaceFillCopy(Accessor(), 0, 0, v14, v13) copies the filled/copied region of width v14 and height v13 into the render surface returned by Accessor. [callee:0x004918D0, callee:0x00490920, source:raw]
    // RETURN: Return the last status byte in v3; this is a __thiscall member of the overlay state object (canonical name FPSOverlayDraw). [abi:lead, function:0x00495440, source:raw]

    // Conservative worker pseudocode:
    //   count = *(int*)(this + 0x1598);
    //   if (count > 0) {
    //       scan WORD array at this + 0x159C for value 4129;
    //       if (found) {
    //           this->flag0xE0 = (this->flag0xE0 == 0);
    //           if (!this->flag0xE0) { this->int0xE4 = 0; this->int0xE8 = 0; this->flt0xEC = 0; }
    //       }
    //   }
    //   if (this->flag0xE0) {
    //       this->int0xE8 += 1;
    //       this->flt0xEC += FloatFieldAccessor(this);
    //       if (threshold) { this->int0xE4 = CRTFtol(this->flt0xEC); this->flt0xEC = 0; this->int0xE8 = 0; }
    //       if (this->int0xE4 >= 0) {
    //           StringFormatWithBufferOverflowCheck(buf, "%d", this->int0xE4);
    //           TextRenderToSurface(this + 5740, &w, &h, 1);
    //           if (w > 0 && h > 0) {
    //               sub_498560(this + 5740);
    //               BitmapDraw_81f0(buf, 0, h, 0, w, 1);
    //               RenderSurfaceFillCopy(Accessor(), 0, 0, w, h);
    //           }
    //       }
    //   }
    //   return status;
    // UNRESOLVED: The raw decompiler condition !(v7 | v8) is expressed via FPU condition-code flags c0/c3; the exact comparison against the accumulated float is not explicit in the packet and is interpreted only as a threshold test.
    // UNRESOLVED: Semantics of the stored value at this+0xE4: existing analysis names it integer FPS, but the raw code stores CRTFtol of the accumulated time (seconds), so its exact relationship to frames-per-second is not derivable from the packet alone.
    // UNRESOLVED: this+5740 (0x166C) is passed to TextRenderToSurface and sub_498560 as a text-surface sub-object offset; it is not present in the packet fields list and is described from raw source only.
    // UNRESOLVED: Exact behavior of sub_498560 (0x00498560) before the bitmap draw is unknown.
    // UNRESOLVED: Exact argument roles of BitmapDraw_81f0 (coordinate/order interpretation of 0, v13, 0, v14, 1) are uncertain.
    // UNRESOLVED: Stack locals v11/v12 mirror v13/v14 immediately before RenderSurfaceFillCopy and have no independent semantic role.
    // UNRESOLVED: Globals flt_59E450 (0x0059E450) and aD_1 (0x005C3280) are not referenced directly in this function's raw source; existing analysis attributes their reads to callees.
    // UNRESOLVED: The owner class name FPSOverlayState is inferred from the offset cluster and caller; no class symbol is present in the packet.
}
