// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004980D0
// Canonical corpus name: BitmapDraw
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmapDraw_004980d0.c

void UnknownObject::BitmapDraw()
{
    // Centered UI element/bitmap renderer: returns -1 when the element string a2 is null; when the display text at this+5400 is non-empty, optionally resolves a2 through the message display buffer (string-table lookup + copy when a7 is set), computes element dimensions and centers the position within the bounding box a3..a6, dispatches the UI element via UIMessageDispatch with the global accessor value, then fills a background surface rectangle behind it. Returns 0 on success.
    // GUARD: guard: if the element string a2 is null, return -1 immediately [source:raw, function:0x004980D0]
    // GUARD: guard: only run the render body when the display text at this+5400 has non-zero length [source:raw]
    // CALL: when a7 is set, resolve the element string: if BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) finds a2, strcpy the input into byte_5EC4CC and use byte_5EC4CC as the element text; otherwise use a2 directly [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC]
    // CALL: call ShortComputation_4f00(this + 5400, text, &v18, &a2) to compute element/text dimensions, writing width into v18 [callee:0x00494F00]
    // CALCULATION: compute centered positions: horizontal v11 = a5 + (a6 - a5) / 2; vertical v12 = a3 when a4 - a3 <= (int)a2, else a3 + (a4 - a3) / 2 - (int)a2 / 2 [source:raw]
    // CALL: call GlobalAccessor_5150() to retrieve the global context/state value used by the dispatch [callee:0x00495150]
    // CALL: call UIMessageDispatch(this + 5400, a2, v11 - v18 / 2, v12, globalValue, a7) to dispatch the UI element at the centered position [callee:0x00494F10, source:raw]
    // CALL: fetch the render surface via Accessor() and call RenderSurfaceFillCopy(surface, v11, v12, v18 + 20, (int)a2 + 30) to fill the background rectangle behind the element [callee:0x00490920, callee:0x004918D0]
    // RETURN: return 0 on success [source:raw, function:0x004980D0]

    // Conservative worker pseudocode:
    //   if ( !a2 ) return -1;
    //   const char* display = this + 5400;
    //   if ( strlen(display) )
    //   {
    //       const char* text;
    //       if ( a7 )
    //       {
    //           if ( BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) )
    //               strcpy(byte_5EC4CC, a2);
    //           text = byte_5EC4CC;
    //       }
    //       else text = a2;
    //       ShortComputation_4f00(display, (int)text, &v18, &a2);
    //       int x = a5 + (a6 - a5) / 2;
    //       int y = (a4 - a3 <= (int)a2) ? a3 : a3 + (a4 - a3) / 2 - (int)a2 / 2;
    //       UIMessageDispatch((int)display, a2, x - v18 / 2, y, GlobalAccessor_5150(), a7);
    //       RenderSurfaceFillCopy(Accessor(), x, y, v18 + 20, (int)a2 + 30);
    //   }
    //   return 0;
    // UNRESOLVED: unk_7CDE00 is listed as a read global but does not appear in the raw source; it is likely consumed inside Accessor() or GlobalAccessor_5150(), which is not established by this packet.
    // UNRESOLVED: The a2 argument is used both as an element string and cast to int as a width/height input; the exact meaning of that numeric value is unclear.
}
