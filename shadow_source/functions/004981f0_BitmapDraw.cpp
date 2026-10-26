// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004981F0
// Canonical corpus name: BitmapDraw_81f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmapDraw_81f0_004981f0.c

void UnknownObject::BitmapDraw()
{
    // Renders a text UI element at a vertical position computed for horizontal centering inside a bounding rectangle. Returns -1 when the element string a2 is null and 0 otherwise; skips the body when this+5400 holds no display text. When a7 is set, a2 is resolved through the string table into the shared message buffer byte_5EC4CC before layout; element dimensions come from ShortComputation_4f00 and the element is dispatched via UIMessageDispatch with a global value from GlobalAccessor_5150.
    // GUARD: If a2 is null, return -1 without rendering. [source:raw]
    // RETURN: Return -1 on null input. [source:raw]
    // CALCULATION: Compute v9 = this + 5400, the base of the UI message object used for layout and dispatch. [source:raw]
    // GUARD: If strlen(this + 5400) is zero, skip the rendering body. [source:raw]
    // GUARD: If a7 is set, resolve a2 through the string table: when BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) matches, copy the found string into byte_5EC4CC and use it as v10; otherwise v10 = a2 directly. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: Call ShortComputation_4f00(v9, v10, v14, &a2) to compute the element dimensions. [callee:0x00494F00, source:raw]
    // CALCULATION: Compute the vertical position v11: left-aligned to a3 when (a4 - a3) <= (int)a2, otherwise centered via a3 + (a4 - a3) / 2 - (int)a2 / 2. [source:raw]
    // ASSIGNMENT: Propagate a7 into v13 as the dispatch flag. [source:raw]
    // CALL: Call GlobalAccessor_5150() to obtain the global dispatch value v12. [callee:0x00495150, source:raw]
    // CALL: Call UIMessageDispatch(v9, v7, a5, v11, v12, v13) to render the element. [callee:0x00494F10, source:raw]
    // RETURN: Return 0 on success. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == NULL) return -1;
    //   if (strlen(this + 5400) == 0) return 0;
    //   if (a7) {
    //     if (BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC))
    //       strcpy(byte_5EC4CC, a2);
    //     text = byte_5EC4CC;
    //   } else {
    //     text = a2;
    //   }
    //   ShortComputation_4f00(this + 5400, text, &tmp, &a2);
    //   if (a4 - a3 <= (int)a2) pos = a3;
    //   else pos = a3 + (a4 - a3) / 2 - (int)a2 / 2;
    //   UIMessageDispatch(this + 5400, a2, a5, pos, GlobalAccessor_5150(), a7);
    //   return 0;
    // UNRESOLVED: Global unk_7CDE00 is listed in the packet but does not appear in the raw source statements; its role in this function is unknown.
    // UNRESOLVED: The semantics of the a5/a7 char parameters and the exact meaning of the v13 dispatch flag are inferred from the dispatch call signature and are DERIVED.
    // UNRESOLVED: strlen/strcpy are implicit CRT calls represented only via source:raw with no callee evidence refs in the packet.
}
