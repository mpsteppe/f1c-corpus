// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048B030
// Canonical corpus name: UIFullRenderPass
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIFullRenderPass_0048b030.c

void UnknownObject::UIFullRenderPass()
{
    // Full UI text render pass with word-wrap. When a2 supplies input text, the function measures the renderable width (horizontal boundary span), clears the existing render-node pool (this[59..62]), builds a linked list of one render node per wrapped token/line by scanning the text and measuring each token with TextRenderToSurface, and finally computes a per-line height from the vertical boundary span. With a null a2 the function does nothing.
    // GUARD: Entry guard: all layout work is skipped when a2 (input text pointer) is null. [abi:lead, function:0x0048B030, source:raw]
    // ASSIGNMENT: Initialize measurement outputs textWidth=0, textHeight=0 and the consumed-character position consumedCharPos=0. [source:raw]
    // CALCULATION: Compute lineWidthPx as sub_487060(this, 1) minus sub_487060(this, 0), i.e. the horizontal boundary span (right minus left) available for each text line. [callee:0x00487060, source:raw]
    // CALL: Query both vertical boundary positions with sub_4870E0(this, 1) and sub_4870E0(this, 0); the same pair is re-read later to derive line height. [callee:0x004870E0, source:raw]
    // ASSIGNMENT: inputText = *a2; falls back to the global byte_5EA438 default string when the supplied pointer is empty. [global:0x005EA438, source:raw]
    // CALL: Allocate two 8-byte token-cursor objects via OperatorNewNhMallocWrapper(8); each is initialized {ptr=0, len=-1} and stored in tokenCursor and measureTokenCursor. A failed allocation yields a null cursor. [callee:0x00587C03, source:raw]
    // LOOP: Walk the existing render-node linked list starting at this[59]. Per node read the 0x4 next pointer and the flag byte at +8; when the flag and the node payload are set, free the payload with ConditionalFreeWithBit0Flag(*payload, 1), then free the node itself with FreeWrapper_7bcf. Stops at null next. [callee:0x00404F70, callee:0x00587BCF, field:*(this+0xF0):0x00000004, source:raw]
    // ASSIGNMENT: Reset the render-node pool: this[59] head, this[60] tail, this[61] head copy and this[62] node count are all zeroed in preparation for the new pass. [field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, source:raw]
    // ASSIGNMENT: Read the prefix string source as *(this[50] + 64) (this offset 0xC8, dereferenced +0x40), falling back to byte_5EA438 when null. [field:this:0x000000C8, global:0x005EA438, source:raw]
    // CALL: Pass the resolved prefix string to sub_498560, the per-render-pass prefix parser/renderer. [callee:0x00498560, source:raw]
    // GUARD: The whole token/layout loop runs only when strlen(inputText) is non-zero; otherwise control jumps straight to the final line-height computation. [source:raw]
    // LOOP: Scan input text one byte at a time: per character reset the local decode outputs, fetch the byte, transform it through sub_5665B0(&v30), set isNewline when the byte equals 0x0A (10), and break out of the scan when the byte is a space (0x20) or newline (0x0A). [callee:0x005665B0, source:raw]
    // STATE_TRANSITION: End-of-string handling: when charPosition reaches the final index, first replay the unconsumed characters into the running token, then append a new render node (12 bytes: {prev=tokenCursor, next=0, flag=1}) to the pool. The node is linked as this[60]+4 next when a head exists, otherwise becomes the head and the head copy; this[60] is updated to the new node and this[62] is incremented. [callee:0x00587C03, field:*(this+0xF0):0x00000004, field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, source:raw]
    // CALL: Measure the accumulated token by calling TextRenderToSurface(*measureTokenCursor or byte_5EA438 fallback, &textWidth, &textHeight, 1). [callee:0x004983B0, global:0x005EA438, source:raw]
    // STATE_TRANSITION: Line-wrap decision: when textWidth fits within lineWidthPx the current line is kept. Otherwise the pending token becomes a render node (append + pool bookkeeping), a fresh 8-byte token cursor is allocated, and the new token string is reset via StringCopyWithBufferRealloc(byte_5EA438). [callee:0x00566650, callee:0x00587C03, field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, global:0x005EA438, source:raw]
    // STATE_TRANSITION: Newline handling (isNewline true): append the pending token as a render node, allocate a fresh 8-byte token cursor, and reset the token string with StringCopyWithBufferRealloc(byte_5EA438) before continuing the scan. [callee:0x00566650, callee:0x00587C03, global:0x005EA438, source:raw]
    // LOOP: After a wrap/newline, replay the characters consumed so far back through sub_5665B0 into the new token cursor so the next measurement reflects the rebuilt token; advance consumedCharPos as the characters are replayed. [callee:0x005665B0, source:raw]
    // CALCULATION: Line-height computation at the end of the pass, guarded by a non-zero textHeight: v22 = sub_4870E0(this, 1) - sub_4870E0(this, 0) (vertical span), then this[66] = v22 / textHeight. [callee:0x004870E0, field:this:0x00000108, source:raw]
    // RETURN: Implicit end of the render pass; the null-a2 path returns without touching render state. [function:0x0048B030, source:raw]

    // Conservative worker pseudocode:
    //   void UIFullRenderPass(this, a2) {
    //     if (!a2) return;
    //     textWidth = 0; textHeight = 0; consumedCharPos = 0;
    //     lineWidthPx = sub_487060(this, 1) - sub_487060(this, 0);
    //     sub_4870E0(this, 1); sub_4870E0(this, 0);
    //     inputText = *a2 ? *a2 : defaultText;
    //     tokenCursor = alloc8(); measureTokenCursor = alloc8();
    //     freeNodeList(this[59]);
    //     this[59] = this[60] = this[61] = this[62] = 0;
    //     prefix = *(this[50] + 64) ? *(this[50] + 64) : defaultText;
    //     sub_498560(prefix);
    //     while (strlen(inputText)) {
    //       scan input, breaking at space/newline;
    //       emit node when token overflows lineWidthPx or at newline/end;
    //     }
    //     if (textHeight) this[66] = (sub_4870E0(this,1) - sub_4870E0(this,0)) / textHeight;
    //   }
    // UNRESOLVED: Exact semantics of sub_487060 / sub_4870E0 boundary queries (whether pixel-coordinate or style-driven) are not determined from this function alone.
    // UNRESOLVED: The character transformation performed by sub_5665B0 (UTF-8 decode vs. case folding) is unknown.
    // UNRESOLVED: What sub_498560 does with the prefix string (font/format setup vs. immediate render) is unresolved.
    // UNRESOLVED: Meaning of the 8-byte token-cursor layout {ptr=0, len=-1} and how TextRenderToSurface consumes it is reconstructed but not independently verified.
    // UNRESOLVED: Ownership contract of node payloads freed by ConditionalFreeWithBit0Flag versus nodes freed by FreeWrapper_7bcf is only partially understood.
    // UNRESOLVED: Interplay between consumedCharPos and charPosition in the token rebuild paths was reconstructed from control flow, not from helper semantics.
    // UNRESOLVED: Owner class of the render-state object (this) is unknown; no evidence in the packet identifies it.
}
