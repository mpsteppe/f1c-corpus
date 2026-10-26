// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495150
// Canonical corpus name: GlobalAccessor_5150
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalAccessor_5150_00495150.c

void UnknownObject::GlobalAccessor_5150()
{
    // Parameterless accessor that returns the current value of the read-only global dword_7CDE14 unchanged. Heavily used across UI rendering paths (drawing, scrollbars, text boxes, bitmap blits, dialogs) and resource file loaders.
    // RETURN: Return the current value of the global dword_7CDE14 unchanged. Called from a broad set of UI render and resource-load paths, including ConditionalDraw, F_2DRectangleDrawingWithOutline, ScrollbarAreaRendering, UIScrollViewRender, UITextBoxRendererWithScrollbar, TextInputRender, BitmapBlitWithClipping, UITextDialogRendering, RenderDispatchWithIteration, MediaBufferPlaybackManager and ResourceFileLoader. [global:0x007CDE14, caller:0x00475C80, caller:0x00475D90, caller:0x004868C0, caller:0x00486AC0, caller:0x004881F0, caller:0x004883D0, caller:0x0048B9C0, caller:0x0048CCB0, caller:0x0048D9D0, caller:0x0048E250, caller:0x0048E4B0, caller:0x0048F0B0, caller:0x0048FCA0, caller:0x00495BD0, caller:0x00495DC0, caller:0x00496E90, caller:0x004972B0, caller:0x004973D0, caller:0x004980D0, caller:0x004981F0, caller:0x004982C0, caller:0x004989E0, caller:0x004993D0, caller:0x004F9480, caller:0x004F9D60, function:0x00495150, source:raw]

    // Conservative worker pseudocode:
    //   int GlobalAccessor_5150() {
    //     return dword_7CDE14;
    //   }
    // UNRESOLVED: The purpose and type of global dword_7CDE14 are unknown from this packet; its caller set (UI render plus resource load) suggests a shared UI/draw state flag or cursor, but that is not provable here.
    // UNRESOLVED: The LEGACY ABI lead provides no owner identity or additional semantic signal.
}
