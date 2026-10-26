// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495BD0
// Canonical corpus name: UITextDialogRendering
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UITextDialogRendering_00495bd0.c

void UnknownObject::UITextDialogRendering()
{
    // Renders a multi-option text dialog. Two passes over four 12-byte entry slots starting at byte offset 5628 of `this`: a measure pass that counts active entries and accumulates text dimensions, then a render pass that draws a background and shadow for the first entry, renders each entry's text, dispatches a UI message per entry, and finally blits the composed area to the render surface. Returns the active-entry count.
    // CALL: GlobalAccessor_5150() returns the global UI context handle used for drawing and dispatch. [callee:0x00495150]
    // CALL: ShortComputation_8550(this) prepares the dialog state before layout measurement. [callee:0x00498550]
    // LOOP: Measure pass over the 4 entry slots (each 12 bytes, starting at byte offset 5628): FloatThresholdCheck decides slot activity; StringPointerDereference retrieves the slot's string pointer and TextRenderToSurface measures its width and height; total height and max width accumulate and the active-entry count increments. [callee:0x00499A50, callee:0x0049A2B0, callee:0x004983B0, source:raw]
    // CALCULATION: Clamp dialog layout to the 800 by 600 screen: if width+8 exceeds 800 the x offset becomes 794-width; if height+8 exceeds 600 the y offset becomes 594-height. [source:raw]
    // LOOP: Render pass over the active entries; for the first entry only, DelegationWrapper draws the background rectangle and its shadow at the clamped origin. [callee:0x00494BF0, source:raw]
    // CALL: UIMessageDispatch(this+5400, entryString, x, y, uiContext, 1) forwards a UI message for each dialog entry at its computed position. [callee:0x00494F10, source:raw]
    // CALL: Each entry's text is rendered via StringPointerDereference plus TextRenderToSurface into the offscreen surface. [callee:0x0049A2B0, callee:0x004983B0]
    // CALL: Accessor() returns the render surface handle; RenderSurfaceFillCopy blits the composed dialog region (origin and dimensions accumulated above) onto it. [callee:0x00490920, callee:0x004918D0, source:raw]
    // RETURN: When no entries are active (count 0) the function returns the active-entry count without rendering. [source:raw]

    // Conservative worker pseudocode:
    //   for (slot in 4 slots at this+5628) if (FloatThresholdCheck(slot)) { measure; active++; }
    //   if (active > 0) {
    //     clamp origin to screen bounds;
    //     for (i in 0..active) { if (i == 0) drawShadowAndBackground(); renderText(); dispatchMessage(); }
    //     blit(composedRegion);
    //   }
    // UNRESOLVED: unk_7CDE00 is listed as a referenced global but is not directly used in the raw decompiled source; it is likely reached indirectly through GlobalAccessor_5150 or DelegationWrapper.
    // UNRESOLVED: The two color constants passed to DelegationWrapper for the shadow and background are opaque here.
    // UNRESOLVED: The meaning of the FloatThresholdCheck pass or fail threshold and the 12-byte entry slot layout beyond the string pointer are not documented in this packet.
}
