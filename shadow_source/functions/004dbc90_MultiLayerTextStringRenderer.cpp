// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DBC90
// Canonical corpus name: MultiLayerTextStringRenderer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiLayerTextStringRenderer_004dbc90.c

void UnknownObject::MultiLayerTextStringRenderer()
{
    // Six-layer text overlay renderer. Each layer fills a shared 64-byte stack buffer via a distinct string-builder sub-function (sub_49C6D0, sub_49BB40, sub_49BBB0, sub_49BCD0, sub_49BD40, sub_49C0B0) and immediately renders it with UITextRenderWithScale at a screen position derived from the a1 base offset. The first layer renders at (a1+50, 46) in red at scale 0.75; the remaining five render at (a1+245, 10/50/90) alternating white (0xFFFFFF) and red (16776960) at scale 1.0. The last render's result is returned. Structural twin of DrawDebugTextOverlay (004dbb60) per the prelabel.
    // CALL: sub_49C6D0(v2, 64): fill the 64-byte string buffer with the first layer's text. [callee:0x0049C6D0, source:raw]
    // CALL: UITextRenderWithScale(v2, a1+50, 46, red 16776960, alignment 2, style 0, scale 0.75, 1.0): render layer 1. [callee:0x004D7E40, source:raw]
    // CALL: sub_49BB40(v2, 64): fill the buffer with layer 2 text. [callee:0x0049BB40, source:raw]
    // CALL: UITextRenderWithScale(v2, a1+245, 10, white 0xFFFFFF, alignment 1, style 2, scale 1.0, 1.0): render layer 2. [callee:0x004D7E40, source:raw]
    // CALL: sub_49BBB0(v2, 64): fill the buffer with layer 3 text. [callee:0x0049BBB0, source:raw]
    // CALL: UITextRenderWithScale(v2, a1+245, 10, red 16776960, alignment 0, style 1, scale 1.0, 1.0): render layer 3. [callee:0x004D7E40, source:raw]
    // CALL: sub_49BCD0(v2, 64): fill the buffer with layer 4 text. [callee:0x0049BCD0, source:raw]
    // CALL: UITextRenderWithScale(v2, a1+245, 50, white 0xFFFFFF, alignment 1, style 2, scale 1.0, 1.0): render layer 4. [callee:0x004D7E40, source:raw]
    // CALL: sub_49BD40(v2, 64): fill the buffer with layer 5 text. [callee:0x0049BD40, source:raw]
    // CALL: UITextRenderWithScale(v2, a1+245, 50, red 16776960, alignment 0, style 1, scale 1.0, 1.0): render layer 5. [callee:0x004D7E40, source:raw]
    // CALL: sub_49C0B0(v2, 64): fill the buffer with layer 6 text. [callee:0x0049C0B0, source:raw]
    // CALL: UITextRenderWithScale(v2, a1+245, 90, red 16776960, alignment 0, style 1, scale 1.0, 1.0): render layer 6; its result is the function return value. [callee:0x004D7E40, source:raw]
    // RETURN: Return the result of the final UITextRenderWithScale call. [function:0x004DBC90, source:raw]

    // Conservative worker pseudocode:
    //   char buf[64];
    //   sub_49C6D0(buf, 64); UITextRenderWithScale(buf, a1 + 50, 46, 16776960, 2, 0, 0.75, 1.0);
    //   sub_49BB40(buf, 64); UITextRenderWithScale(buf, a1 + 245, 10, 0xFFFFFF, 1, 2, 1.0, 1.0);
    //   sub_49BBB0(buf, 64); UITextRenderWithScale(buf, a1 + 245, 10, 16776960, 0, 1, 1.0, 1.0);
    //   sub_49BCD0(buf, 64); UITextRenderWithScale(buf, a1 + 245, 50, 0xFFFFFF, 1, 2, 1.0, 1.0);
    //   sub_49BD40(buf, 64); UITextRenderWithScale(buf, a1 + 245, 50, 16776960, 0, 1, 1.0, 1.0);
    //   sub_49C0B0(buf, 64);
    //   return UITextRenderWithScale(buf, a1 + 245, 90, 16776960, 0, 1, 1.0, 1.0);
    // UNRESOLVED: unk_7CE234 is listed as a packet global but is not read anywhere in this function's raw source; it is recorded here.
    // UNRESOLVED: The seven sub_49XXXX callees build strings into the buffer; their text content and purpose are not exposed by this function.
    // UNRESOLVED: The alignment/style/scale parameter roles of UITextRenderWithScale are inferred from the callee contract (see 0x004D7E40), not from this packet.
}
