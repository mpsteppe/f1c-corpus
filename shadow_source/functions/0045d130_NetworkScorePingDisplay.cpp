// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045D130
// Canonical corpus name: NetworkScorePingDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkScorePingDisplay_0045d130.c

void UnknownObject::NetworkScorePingDisplay()
{
    // Formats per-player network score and ping entries into the output buffer `this`. Reads the player count from the game module manager global (dword_7CD25C), then for each player row fetched via DataTableRowAccessor builds key/value pairs (player_%d, score_%d, ping_%d) with StringFormatWithBufferOverflowCheck and registers them through ShortComputation_ce30. Returns the player count.
    // CALL: result := StructFieldReadAt0x3e14(dword_7CD25C) — read the player count from the game module manager global [callee:0x00462370, global:0x007CD25C, source:raw]
    // LOOP: for (i = result; v4 < i; ++v4) — iterate over each player row [source:raw]
    // CALL: ThunkToFUN00461480(v9) — initialize the per-row working buffer [callee:0x00461470, source:raw]
    // GUARD: if DataTableRowAccessor(v4, v9, v6) is nonzero — fetch the current player row; only non-empty rows produce entries [callee:0x00462410, source:raw]
    // ASSIGNMENT: v7[0] := 0 and v8[0] := 0 — clear the key and value format buffers [source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v7, player_%d literal aPlayerD, v4) — format the player key [callee:0x0058815F, global:0x005C5C60, source:raw]
    // CALL: ShortComputation_ce30(v7, v10, this) — register the player key into the output buffer [callee:0x0045CE30, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v7, score_%d literal aScoreD, v4) — format the score key [callee:0x0058815F, global:0x005C5C54, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v8, "%d", v11) — format the score value [callee:0x0058815F, source:raw]
    // CALL: ShortComputation_ce30(v7, v8, this) — register the score key/value pair into the output buffer [callee:0x0045CE30, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v7, ping_%d literal aPingD, v4) — format the ping key [callee:0x0058815F, global:0x005C5C4C, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v8, "%d", v12) — format the ping value [callee:0x0058815F, source:raw]
    // CALL: ShortComputation_ce30(v7, v8, this) — register the ping key/value pair into the output buffer [callee:0x0045CE30, source:raw]
    // CALL: EmptyStub_0170(v9) — clean up the per-row working buffer after each row [callee:0x004B0170, source:raw]
    // RETURN: return result — the player count read at the start [function:0x0045D130, source:raw]

    // Conservative worker pseudocode:
    //   result = StructFieldReadAt0x3e14(dword_7CD25C);
    //   for (v4 = 0; v4 < result; ++v4) {
    //       ThunkToFUN00461480(v9);
    //       if (DataTableRowAccessor(v4, v9, v6)) {
    //           v7[0] = 0; v8[0] = 0;
    //           StringFormatWithBufferOverflowCheck(v7, "player_%d", v4);
    //           ShortComputation_ce30(v7, v10, this);
    //           StringFormatWithBufferOverflowCheck(v7, "score_%d", v4);
    //           StringFormatWithBufferOverflowCheck(v8, "%d", v11);
    //           ShortComputation_ce30(v7, v8, this);
    //           StringFormatWithBufferOverflowCheck(v7, "ping_%d", v4);
    //           StringFormatWithBufferOverflowCheck(v8, "%d", v12);
    //           ShortComputation_ce30(v7, v8, this);
    //       }
    //       EmptyStub_0170(v9);
    //   }
    //   return result;
    // UNRESOLVED: Where v11 (score) and v12 (ping) are populated relative to the DataTableRowAccessor output buffer is not evidenced in the raw source.
    // UNRESOLVED: Global aD_1 is listed as a config parse token list by existing analysis but is not referenced by any visible operation in the raw source text.
    // UNRESOLVED: No static callers exist (top-level or indirect-only); frame-path and call frequency are unknown.
}
