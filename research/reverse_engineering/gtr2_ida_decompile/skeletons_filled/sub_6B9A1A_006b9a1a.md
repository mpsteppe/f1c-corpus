## sub_6B9A1A_006b9a1a — inflate (decompression state machine)

**Summary:** zlib `inflate()`: the decompression state machine. It consumes header bytes (method/CINFO checks, FCHECK, dictionary id, gzip TIME accumulator), runs the block decoder over the window object, reads and verifies the trailing 32-bit checksum, and returns the zlib status codes (0 = need more input/output data, 1 = stream end, -2 stream error / need dictionary, -3 data error, -4/-5 buffer-related).

**Called by:** sub_67AC9B (0067ac9b), sub_6BAE2D (006bae2d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | strm->next_in — input pointer, advanced one byte per consumed byte |
| this | 0x0 | R | — | Back-pointer to the owning stream (source of next_in) |
| this | 0x4 | RW | — | strm->avail_in — decremented per consumed byte; zero forces an early return with the current status |
| this | 0x8 | R | — | strm->total_in — input byte counter, incremented per consumed byte |
| this | 0x18 | RW | — | strm->msg — set to the specific error string on every failure path |
| this | 0x1C | RW | 12 | state pointer (read); flattened state+0 mode word (written): 12 = done, 13 = bad |
| this | 0x20 | RW | 0 | Nested state+4 check word: initially the first header byte (CMF for the FCHECK test), then the running checksum; cleared on the dictionary-error path and compared against the assembled trailer |
| this | 0x24 | RW | — | Nested state+8 accumulator: assembles big-endian 32-bit header/trailer values (TIME/OS fields and trailing check) byte by byte |
| this | 0x28 | R | — | Nested state+0xC wrap flag: zero → read and verify the trailer check; nonzero → skip to done |
| this | 0x2C | R | — | Nested state+0x10 window bits: header CINFO nibble + 8 is validated against it (invalid window size) |
| this | 0x30 | RW | — | Nested state+0x14 window/block-decoder object pointer passed to the decode routine |

**Written-by note (persistence):**
- this 0x4: decremented once per consumed byte while input remains; poke overwritten as soon as decoding consumes anything
- this 0x18: written only on failure paths (error strings); survives while succeeding
- this 0x1C: mode transitions written on each state-machine step (12/13 at the end); recalculated constantly while decoding
- this 0x20: rewritten as header/trailer bytes are assembled; cleared on the dictionary-error path
- this 0x24: accumulated byte runs during header/trailer reads; constantly recalculated while in those states
- this 0x30: pointer written only where the stream is set up (elsewhere); read here for the decode call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006b9d45 | jpt_6B9A57 | R | Jump table selecting the handler for the current mode word |
| 0072ee24 | aNeedDictionary | R | Error string "need dictionary" stored to strm->msg in the DICT state |
| 0072ee34 | aIncorrectDataC | R | Error string "incorrect data check" for trailer mismatch |
| 0072ee4c | aIncorrectHeade | R | Error string "incorrect header check" for the FCHECK failure |
| 0072ee64 | aInvalidWindowS | R | Error string "invalid window size" when CINFO+8 exceeds the configured window bits |
| 0072ee78 | aUnknownCompres | R | Error string "unknown compression method" when the method nibble is not 8 |
| 016c9784 | off_16C9784 | R | Indirect error-return helper invoked with (strm, status) when a header/trailer check fails |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006daca9 | sub_6DACA9 | Checksum routine for the decoded data; updates the value pointed to by the third argument (state+4 here) |
| 006dad8d | sub_6DAD8D | Block decoder over the window object; returns -3 on data error, 1 at a block/stream boundary, 0 otherwise |

**Guard conditions:** Mode dispatch via jump table. Every raw byte-read step blocks (returns the current status) when strm->avail_in == 0. Hard failures: method nibble != 8 → msg "unknown compression method", mode 13; CINFO+8 > configured window bits → "invalid window size", mode 13; FCHECK ((second header byte + first<<8) % 31 != 0) → "incorrect header check", mode 13; dictionary flag set → mode 2 (dictionary id), and the DICT state stores "need dictionary", clears the check word, returns -2 with mode 13. The decode step (mode 7): -3 → bad (mode 13); return 1 → checksum fold, then either trailer read (wrap flag zero) or done; trailer mismatch → "incorrect data check"; final states: done (12) returns 1, bad (13) returns -3. A NULL stream, NULL state or NULL next_in returns -2 up front.
