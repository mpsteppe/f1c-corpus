// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00593694
// Canonical corpus name: FontGlyphRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FontGlyphRender_00593694.c

void UnknownObject::FontGlyphRender()
{
    // Font glyph rendering dispatcher driven by an SEH exception-record context. Guards on a TLS flag (index 26), optionally runs an SEH trampoline setup, then walks a five-dword-strided glyph range table returned by a binary interval search, dispatching each matching range through MultiArgRenderingDispatchWithLayout. Returns the final range index or the SEH trampoline result.
    // GUARD: Enter the glyph render path only when TLS index 26 retrieved via TLSValueRetrievalWithInit is non-zero [source:raw, callee:0x0058E0C7]
    // CALL: SEHExceptionHandlerTrampolineSetup(ExceptionRecord, a2, a3, a4, a5, a7, TargetFrame); a zero return falls through to the range-table walk [source:raw, callee:0x0058A42F]
    // CALL: BinaryIntervalSearchForMatchingRange(a5, a7, a6, &v13, &v12) returns the base pointer i of a glyph range table with current index v13 and end bound v12 [source:raw, callee:0x0058A55A]
    // LOOP: Walk the range table in five-dword steps (i += 5) while v13 < v12 [source:raw]
    // GUARD: For each entry accept the range only when a6 falls inside [i[0], i[1]] [source:raw]
    // CALCULATION: Derive the layout address for the matched range: v10 = i[4] + 16 * i[3]; candidate node pointer v11 = *(v10 - 12) [source:raw]
    // GUARD: Dispatch only when v11 is null or the byte at v11 + 8 is zero [source:raw]
    // CALL: MultiArgRenderingDispatchWithLayout(ExceptionRecord, a2, a3, a4, a5, v10 - 16, 0, i, a7, TargetFrame) renders the matched glyph interval [source:raw, callee:0x00593839]
    // RETURN: Return the final range index v13 after the walk; on the early TLS-guard failure path return the SEH trampoline result [source:raw]

    // Conservative worker pseudocode:
    //   if (TLSValueRetrievalWithInit()[26] != 0) {
    //     if (SEHExceptionHandlerTrampolineSetup(ExceptionRecord, a2, a3, a4, a5, a7, TargetFrame) != 0)
    //       return that result;
    //   }
    //   i = BinaryIntervalSearchForMatchingRange(a5, a7, a6, &v13, &v12);
    //   for (; v13 < v12; ++v13, i += 5) {
    //     if (a6 >= i[0] && a6 <= i[1]) {
    //       v10 = i[4] + 16 * i[3];
    //       v11 = *(v10 - 12);
    //       if (v11 == 0 || *(v11 + 8) == 0)
    //         MultiArgRenderingDispatchWithLayout(ExceptionRecord, a2, a3, a4, a5, v10 - 16, 0, i, a7, TargetFrame);
    //     }
    //   }
    //   return v13;
    // UNRESOLVED: The exception-record parameters (ExceptionRecord, a2..a7, TargetFrame) flow to the SEH trampoline and render dispatch; their individual meanings are outside this function's evidence
    // UNRESOLVED: The TLS flag at index 26 and the glyph range-table entry layout (five dwords per entry with interval and layout indirection) are structural only; the underlying glyph table structure is unknown
    // UNRESOLVED: Invoked by sub_5934E1 (005934E1); the caller-side trigger conditions are not visible here
}
