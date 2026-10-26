// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560410
// Canonical corpus name: sub_560410
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_560410_00560410.c

void UnknownObject::KeyedRowCopy()
{
    // Row-wise keyed copy of a6 rows, each 2*a5 bytes wide, from source (stride a2) to destination (stride a4). Stores the key word a7 in global dword_5DD804. When a7 is 0xFFFF and the row width is a multiple of 8 it takes a fast block-copy path; otherwise it copies word-by-word and leaves destination words equal to the key unchanged.
    // ASSIGNMENT: store the key word a7 into global dword_5DD804 [global:0x005DD804, source:raw]
    // CALCULATION: row byte width v10 = 2 * a5; fast path chunks it as 4 * (v10 >> 2) with a (v10 & 3) byte remainder [source:raw]
    // GUARD: when a7 == 0xFFFF and (v10 & 7) == 0 take the fast whole-row block-copy path [source:raw]
    // LOOP: for each of a6 rows, block-copy v10 bytes from a1 to a3 via 4-byte-dword chunks plus the low-3-bytes tail, then advance source by a2 - v10 and dest by a4 - v10 [source:raw]
    // GUARD: otherwise fall through to the general per-row path with comparison key v11 = a7 (or 2 * a5 when a7 == 0xFFFF) [source:raw]
    // LOOP: for each of a6 rows, scan the source two words at a time; copy each word to the destination only when it differs from the key v11, leaving matching destination words untouched [source:raw]
    // ASSIGNMENT: after each general-path row, advance source pointer by a2 and destination pointer by a4 [source:raw]

    // Conservative worker pseudocode:
    //   key = a7;
    //   row_bytes = 2 * a5;
    //   if (key == 0xFFFF && (row_bytes & 7) == 0) {
    //       for (i = 0; i < a6; i++) { block_copy_row(a3, a1, row_bytes); a1 += a2; a3 += a4; }
    //   } else {
    //       if (key == 0xFFFF) key = row_bytes;
    //       for (i = 0; i < a6; i++) {
    //           copy_words_skipping_key(a3, a1, row_bytes / 2, key);
    //           a1 += a2; a3 += a4;
    //       }
    //   }
    // UNRESOLVED: exact purpose of the keyed skip: destination words equal to the key retain prior content (transparency/fill preservation suspected)
    // UNRESOLVED: why a7 == 0xFFFF substitutes 2*a5 as the comparison key in the general path
    // UNRESOLVED: relationship to audio playback (sole caller AudioPlaybackDispatcher) and whether global dword_5DD804 is shared state read elsewhere
}
