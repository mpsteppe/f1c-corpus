// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004982C0
// Canonical corpus name: BitmapDrawWithAlpha
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmapDrawWithAlpha_004982c0.c

void UnknownObject::BitmapDrawWithAlpha()
{
    // Renders a text UI element with an alpha flag: returns -1 when the element string a2 is null and 0 otherwise; skips the body when this+5400 holds no display text. When a7 is set, a2 is resolved through the string table into the shared message buffer byte_5EC4CC before layout; element dimensions are produced by ShortComputation_4f00 into the out parameter v15 and the element is dispatched via UIMessageDispatch with an offset argument v11 derived from a6, a horizontal position centered within the a3..a4 band, a global value from GlobalAccessor_5150, and the alpha flag a7.
    // ASSIGNMENT: Copy a2 into v7 as the element string used for string-table resolution and dispatch. [source:raw]
    // GUARD: If a2 is null, return -1 without rendering. [source:raw]
    // RETURN: Return -1 on null input. [source:raw]
    // CALCULATION: Compute v9 and v16 as this + 5400, the base of the UI message object used for layout and dispatch. [source:raw]
    // GUARD: If strlen(this + 5400) is zero, skip the rendering body. [source:raw]
    // GUARD: If a7 is set, resolve a2 through the string table: when BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) matches, copy the found string from v7 into byte_5EC4CC and use byte_5EC4CC as v10; otherwise v10 = a2 directly. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: Call ShortComputation_4f00(v9, (int)v10, (int)&a2, (int)&v15) to compute element dimensions; v15 is the size out parameter. [callee:0x00494F00, source:raw]
    // CALCULATION: Compute the first dispatch argument v11 = a6 - (int)a2, an offset derived from a6 and the pointer value of a2. [source:raw]
    // CALCULATION: Compute the horizontal position v12: left-aligned to a3 when (a4 - a3) <= v15, otherwise centered via a3 + (a4 - a3) / 2 - v15 / 2. [source:raw]
    // ASSIGNMENT: Propagate a7 into v14 as the dispatch alpha flag. [source:raw]
    // CALL: Call GlobalAccessor_5150() and store its result in v13 as the global dispatch value. [callee:0x00495150, source:raw]
    // CALL: Call UIMessageDispatch((int)v16, v7, v11, v12, v13, v14) to render the element with the alpha flag. [abi:lead, callee:0x00494F10, source:raw]
    // RETURN: Return 0 on success. [function:0x004982C0, source:raw]

    // Conservative worker pseudocode:
    //   int BitmapDrawWithAlpha(void *ui, const char *text, int left, int right, int unused, int base, char alpha) {
    //     if (text == NULL) return -1;
    //     char *msg = (char *)ui + 5400;
    //     if (strlen(msg) == 0) return 0;
    //     const char *toLayout;
    //     if (alpha) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, text, byte_5EC4CC))
    //         strcpy(byte_5EC4CC, text);
    //       toLayout = byte_5EC4CC;
    //     } else {
    //       toLayout = text;
    //     }
    //     int dim;
    //     ShortComputation_4f00(msg, (int)toLayout, (int)&text, (int)&dim);
    //     int off = base - (int)text;
    //     int pos = (right - left <= dim) ? left : left + (right - left) / 2 - dim / 2;
    //     UIMessageDispatch((int)msg, text, off, pos, GlobalAccessor_5150(), alpha);
    //     return 0;
    //   }
    // UNRESOLVED: Global unk_7CDE00 is listed in the packet but does not appear in the raw source statements; its role in this function is unknown.
    // UNRESOLVED: Parameter a5 is declared in the signature but never referenced in the body; its intended role is unknown.
    // UNRESOLVED: The expression v11 = a6 - (int)a2 subtracts the pointer value of a2 from a6; the decompiler's pointer arithmetic obscures the intended semantic of this dispatch argument.
    // UNRESOLVED: The semantics of the a7 char flag (used both to select string-table resolution and as the final dispatch argument v14) are inferred from the dispatch call signature and are DERIVED.
    // UNRESOLVED: strlen/strcpy are implicit CRT calls represented only via source:raw with no callee evidence refs in the packet.
}
