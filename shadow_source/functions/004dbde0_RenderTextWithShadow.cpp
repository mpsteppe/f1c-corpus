// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DBDE0
// Canonical corpus name: TextRenderWithShadow
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextRenderWithShadow_004dbde0.c

void UnknownObject::RenderTextWithShadow()
{
    // Renders a text string twice at the same position to produce a drop-shadow effect. Both passes format a 64-byte stack buffer via sub_49C8F0 / sub_49C960 and call UITextRenderWithScale with color 0xFFFFFF at (a1 + 245, 10) at scale 1.0: first a shadow pass (mode 1, alignment 2), then a foreground pass (mode 0, alignment 1). Returns the foreground render result. No static frame-path callers; not on the tick frame path.
    // CALL: Call sub_49C8F0(v2, 64): prepare the 64-byte text buffer for the shadow pass. [callee:0x0049C8F0]
    // CALL: Call UITextRenderWithScale(v2, a1 + 245, 10, 0xFFFFFF, 1, 2, 1.0, 1.0): shadow render pass with mode 1 and alignment 2. [callee:0x004D7E40]
    // CALL: Call sub_49C960(v2, 64): prepare the 64-byte text buffer for the foreground pass. [callee:0x0049C960]
    // CALL: Call UITextRenderWithScale(v2, a1 + 245, 10, 0xFFFFFF, 0, 1, 1.0, 1.0): foreground render pass with mode 0 and alignment 1. [callee:0x004D7E40]
    // RETURN: Return the integer result of the foreground UITextRenderWithScale call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4DBDE0(int a1) {
    //     int v2[16];
    //     sub_49C8F0((int)v2, 64);
    //     UITextRenderWithScale((int)v2, a1 + 245, 10, 0xFFFFFF, 1, 2, 1.0, 1.0);
    //     sub_49C960((int)v2, 64);
    //     return UITextRenderWithScale((int)v2, a1 + 245, 10, 0xFFFFFF, 0, 1, 1.0, 1.0);
    //   }
    // UNRESOLVED: Meaning of the UITextRenderWithScale mode (1 vs 0) and alignment (2 vs 1) parameters.
    // UNRESOLVED: What the integer argument a1 points to and what the offset +245 selects.
    // UNRESOLVED: Internal behavior of sub_49C8F0 / sub_49C960 beyond formatting a 64-byte buffer.
    // UNRESOLVED: Reason the shadow/foreground passes use different alignment parameters.
}
