// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC1A0
// Canonical corpus name: DoubleRenderPass
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoubleRenderPass_004dc1a0.c

void UnknownObject::DoubleRenderPass()
{
    // Structural twin of RenderTextWithShadow: renders a text string twice at caller-supplied position (a1, a2) to create a drop-shadow effect. Both passes format a 64-byte stack buffer via sub_49BB40 / sub_49BBB0 and call UITextRenderWithScale with color 0xFFFFFF at scale 1.0: first a shadow pass (mode 1, alignment 2), then a foreground pass (mode 0, alignment 1). Returns the foreground render result. Called by DrawDebugTextOverlay and UIDebugOverlayRender; not on the tick frame path.
    // CALL: Call sub_49BB40(v3, 64): prepare the 64-byte text buffer for the shadow pass. [callee:0x0049BB40]
    // CALL: Call UITextRenderWithScale(v3, a1, a2, 0xFFFFFF, 1, 2, 1.0, 1.0): shadow render pass at position (a1, a2) with mode 1 and alignment 2. [callee:0x004D7E40]
    // CALL: Call sub_49BBB0(v3, 64): prepare the 64-byte text buffer for the foreground pass. [callee:0x0049BBB0]
    // CALL: Call UITextRenderWithScale(v3, a1, a2, 0xFFFFFF, 0, 1, 1.0, 1.0): foreground render pass at position (a1, a2) with mode 0 and alignment 1. [callee:0x004D7E40]
    // RETURN: Return the integer result of the foreground UITextRenderWithScale call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4DC1A0(int a1, int a2) {
    //     char v3[64];
    //     sub_49BB40((int)v3, 64);
    //     UITextRenderWithScale((int)v3, a1, a2, 0xFFFFFF, 1, 2, 1.0, 1.0);
    //     sub_49BBB0(v3, 64);
    //     return UITextRenderWithScale((int)v3, a1, a2, 0xFFFFFF, 0, 1, 1.0, 1.0);
    //   }
    // UNRESOLVED: Meaning of the UITextRenderWithScale mode (1 vs 0) and alignment (2 vs 1) parameters.
    // UNRESOLVED: Semantics of the caller-supplied position (a1, a2) and their coordinate space.
    // UNRESOLVED: Internal behavior of sub_49BB40 / sub_49BBB0 beyond formatting a 64-byte buffer.
    // UNRESOLVED: Whether this text helper shares state with its structural twin RenderTextWithShadow despite its distinct format helpers.
}
