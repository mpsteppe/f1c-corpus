// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DBB60
// Canonical corpus name: DrawDebugTextOverlay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DrawDebugTextOverlay_004dbb60.c

void UnknownObject::DrawDebugTextOverlay()
{
    // Renders a debug text overlay: clears a 64-byte stack buffer, formats several fields into it with four formatter helpers, and draws them as colored lines at screen-relative X offsets derived from a1 (one line in yellow at a1+50, the remaining white lines at a1+325 at Y positions 50 and 90, each drawn twice with swapped alignment flags), plus one secondary overlay element via DoubleRenderPass.
    // CALL: Clear the 64-byte text buffer: sub_49C6D0(v2, 64) [callee:0x0049C6D0, source:raw]
    // CALL: Render the first (yellow) line: UITextRenderWithScale(v2, a1 + 50, 46, 16776960, 2, 0, 0.75, 1.0) draws the buffer at X = a1+50, Y = 46 with yellow colour and 0.75 scale [callee:0x004D7E40, source:raw]
    // CALL: Render a secondary overlay element: DoubleRenderPass(a1 + 325, 10) [callee:0x004DC1A0, source:raw]
    // CALL: Format debug field 1 into the buffer: sub_49C310(v2, 64) [callee:0x0049C310, source:raw]
    // CALL: Render field 1: UITextRenderWithScale(v2, a1 + 325, 50, 0xFFFFFF, 1, 2, 1.0, 1.0) [callee:0x004D7E40, source:raw]
    // CALL: Format debug field 2 into the buffer: sub_49C370(v2, 64) [callee:0x0049C370, source:raw]
    // CALL: Render field 2 with swapped alignment: UITextRenderWithScale(v2, a1 + 325, 50, 0xFFFFFF, 0, 1, 1.0, 1.0) [callee:0x004D7E40, source:raw]
    // CALL: Format debug field 3 into the buffer: sub_49C490(v2, 64) [callee:0x0049C490, source:raw]
    // CALL: Render field 3: UITextRenderWithScale(v2, a1 + 325, 90, 0xFFFFFF, 1, 2, 1.0, 1.0) [callee:0x004D7E40, source:raw]
    // CALL: Format debug field 4 into the buffer: sub_49C4E0(v2, 64) [callee:0x0049C4E0, source:raw]
    // RETURN: Render field 4 with swapped alignment and return its result: UITextRenderWithScale(v2, a1 + 325, 90, 0xFFFFFF, 0, 1, 1.0, 1.0) [callee:0x004D7E40, source:raw]

    // Conservative worker pseudocode:
    //   char buf[64];
    //   sub_49C6D0(buf, 64);
    //   UITextRenderWithScale(buf, a1 + 50, 46, 16776960, 2, 0, 0.75, 1.0);
    //   DoubleRenderPass(a1 + 325, 10);
    //   sub_49C310(buf, 64); UITextRenderWithScale(buf, a1 + 325, 50, 0xFFFFFF, 1, 2, 1.0, 1.0);
    //   sub_49C370(buf, 64); UITextRenderWithScale(buf, a1 + 325, 50, 0xFFFFFF, 0, 1, 1.0, 1.0);
    //   sub_49C490(buf, 64); UITextRenderWithScale(buf, a1 + 325, 90, 0xFFFFFF, 1, 2, 1.0, 1.0);
    //   sub_49C4E0(buf, 64);
    //   return UITextRenderWithScale(buf, a1 + 325, 90, 0xFFFFFF, 0, 1, 1.0, 1.0);
    // UNRESOLVED: The read-only global unk_7CE234 is flagged by packet facts but appears nowhere in the raw decompiled source text
    // UNRESOLVED: The exact meaning of the numeric render parameters (colour 16776960/0xFFFFFF, alignment flags 0/1/2, scales 0.75/1.0) is taken literally from the decompiled call; screen layout is inferred
}
