// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00507079
// Canonical corpus name: sub_507079
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_507079_00507079.c

void UnknownObject::PixelQuadAccumulateAndFlush()
{
    // Software-rasterizer sub-pixel quad accumulation. Wraps the body in an SEH handler, then advances the X/Y accumulation cursors (a1[2]/a1[3], backing fields this+0x8/0xC). Lazily allocates the slot grid (8 bytes per element) when the grid pointer is null, and derives the slot address for the current position from the grid base and cursor arithmetic. On a first write to a slot, allocates a 16-byte-element staging buffer, size 16 x (16*count), initializes its elements with sub_5008C2 using sub_5007EC as element constructor, and links the buffer into the slot. Fills the slot's sub-pixel rows from the source surface (or via the surface-row callback), copies the incoming 4-dword quad into the staging buffer, sets the sub-pixel occupancy bitfield, and when all four sub-pixels are present (bitfield == 15) flushes the completed quad through the row callback, then either frees the staging buffer (FreeWrapper_7bcf) or recycles it. Optionally runs the vertex format through DirectXVertexBufferFormatConversion when the format code is non-zero.
    // CALL: SEHHandlerInit installs the structured exception handler that frames the whole body [callee:0x0058A5D8, source:raw]
    // CALCULATION: Advance the accumulation cursors: a1[2] gains the state X step and a1[3] gains the state Y step [field:this:0x00000008, field:this:0x0000000C, source:raw]
    // GUARD: If the slot grid pointer is null, allocate it with OperatorNewNhMallocWrapper (8 * count_x * count_y bytes) and zero-fill it; on allocation failure return immediately [callee:0x00587C03, source:raw]
    // CALCULATION: Compute the slot address v9 = grid base + 8 * (((x_cursor - x_origin) >> 2) + count_x * (y_cursor - y_origin)) and store it into the a1-4 slot (field this+0x10) [field:this:0x00000010, source:raw]
    // GUARD: If the slot's buffer pointer (v9+4) is null, allocate the staging buffer: element count = 16 * state count (stored to a1-6 / this+0x8), buffer size = 16 * that count via OperatorNewNhMallocWrapper (stored to a1-5 / this+0xC), initialize the elements with sub_5008C2 using sub_5007EC as the element constructor, then link the buffer into the slot and bump the allocated-slot counter; on failure return [callee:0x00587C03, callee:0x005008C2, global:0x005007EC, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000014, source:raw]
    // GUARD: When the slot's occupancy bitfield (v9+0) is clear and the sub-pixel column falls outside the surface bounds, fill the slot's rows from the source surface via the surface-row callback using the stride-addressed row address; otherwise copy the row data directly (packet guard: this+0x10 field used as the 4-iteration sub-pixel counter) [field:this:0x00000010, guard:0, source:raw]
    // CALL: If the state format code is non-zero, convert the vertex/source pointer through DirectXVertexBufferFormatConversion [callee:0x00506CE2, source:raw]
    // LOOP: Copy loop: for each sub-pixel row of the surface span, copy four dwords from the source quad into the staging buffer element selected by (column & 3) | (4 * (column | column & ~3)) [field:this:0x00000010, source:raw]
    // STATE_TRANSITION: Set the sub-pixel occupancy bit: when a per-pixel mask is enabled, OR in the bit for each sub-pixel matching the column classification (4 iterations on a1[4]/this+0x10); otherwise OR in a single bit for the computed sub-pixel index [field:this:0x00000010, guard:0, source:raw]
    // STATE_TRANSITION: When all four sub-pixels are present (bitfield == 15), flush the quad: iterate the four rows through the flush callback on the staging buffer, advancing row address and staging pointer; then either free the staging buffer with FreeWrapper_7bcf and decrement the allocated-slot counter, or recycle the buffer into the slot's recycle field [callee:0x00587BCF, field:this:0x00000010, source:raw]
    // RETURN: Return the final bitfield/result value computed during occupancy bookkeeping [function:0x00507079, source:raw]

    // Conservative worker pseudocode:
    //   SEHHandlerInit();
    //   a1[2] += state[1037]; a1[3] += state[1040];
    //   if (!state[1072]) { state[1072] = malloc(8 * state[1067] * state[1066]); if (!state[1072]) return; memset(state[1072], 0, 8*state[1067]*state[1066]); }
    //   slot = state[1072] + 8 * (((a1[2]-state[1060])>>2) + state[1066]*(a1[3]-state[1063]));
    //   a1[-4] = slot;
    //   if (*(slot+4) == 0) {
    //     a1[-6] = 16 * state[1065];
    //     a1[-5] = malloc(16 * a1[-6]);  a1[-1] = 0;
    //     if (a1[-5]) sub_5008C2(a1[-5], 16, a1[-6], sub_5007EC);
    //     a1[-1] = -1;  *(slot+4) = a1[-5];  if (!a1[-5]) return;
    //     *(slot+0) = 0;  ++state[1071];
    //   }
    //   if (*(slot+0) == 0) { /* fill sub-pixel rows via surface callback or direct copy * / }
    //   if (state[1042]) a1[4] = DirectXVertexBufferFormatConversion(state, a1[4]);
    //   /* copy 4 dwords into staging element * /
    //   set occupancy bit for sub-pixel column;
    //   if (*(slot+0) == 15) { flush rows via callback; free or recycle staging buffer; }
    //   return result;
    // UNRESOLVED: The high state-array indices (state[1036]..state[1072]) correspond to offsets beyond the packet's four declared fields (this+0x8/0xC/0x10/0x14); the grid dimensions, strides and callback pointers they hold are not individually named evidence here
    // UNRESOLVED: Global loc_59C548 (SEH jump target) is flagged as read but never appears in the raw decompiled source; it is the function's exception-handling label and its exact role is unverifiable from this packet
}
