## sub_6B8BF9_006b8bf9 — Reset deflate state: clear hash, load level parameters

**Summary:** Deflate reset/init (lm_init + hash clear): sets window_size = 2*w_size, zeroes the hash head table (tail entry then memset), loads the four level parameters (good length, max lazy, nice length, max chain) from the per-level configuration tables, and resets the stream/match bookkeeping fields with match lengths seeded to 2 (MIN_MATCH-1). Returns 2.

**Called by:** sub_6B9659 (006b9659)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | w_size — half the window size; source of the window_size computation |
| this | 0x34 | RW | — | window_size — set to 2 * w_size |
| this | 0x3C | R | — | Hash head table pointer — zeroed on reset |
| this | 0x40 | RW | 0 | Match/bookkeeping counter reset to 0 |
| this | 0x44 | R | — | Number of hash head entries — bounds the table clearing |
| this | 0x54 | RW | 0 | Match-state field reset to 0 |
| this | 0x58 | RW | 2 | Match length state seeded to 2 (MIN_MATCH-1) |
| this | 0x60 | RW | 0 | Match-state field reset to 0 |
| this | 0x64 | RW | 0 | strstart — reset to 0 (no pending window data) |
| this | 0x6C | RW | 0 | lookahead — reset to 0 (no buffered uncompressed bytes) |
| this | 0x70 | RW | 2 | Previous match length seeded to 2 (MIN_MATCH-1) |
| this | 0x74 | RW | — | max_chain_length — loaded from the level configuration table |
| this | 0x78 | RW | — | max_lazy_match — loaded from the level configuration table |
| this | 0x7C | R | — | Compression level — indexes the configuration tables (stride 6) |
| this | 0x84 | RW | — | good_match (good length) — loaded from the level configuration table |
| this | 0x88 | RW | — | nice_match (nice length) — loaded from the level configuration table |

**Written-by note (persistence):**
- this 0x34: written unconditionally when this reset routine runs; a poke survives until the next reset
- this 0x40: written unconditionally on each reset; poke survives until the next reset
- this 0x54: written unconditionally on each reset; poke survives until the next reset
- this 0x58: written unconditionally on each reset; poke survives until the next reset
- this 0x60: written unconditionally on each reset; poke survives until the next reset
- this 0x64: written unconditionally on each reset; poke survives until the next reset
- this 0x6C: written unconditionally on each reset; poke survives until the next reset
- this 0x70: written unconditionally on each reset; poke survives until the next reset
- this 0x74: written unconditionally on each reset; poke survives until the next reset
- this 0x78: written unconditionally on each reset; poke survives until the next reset
- this 0x84: written unconditionally on each reset; poke survives until the next reset
- this 0x88: written unconditionally on each reset; poke survives until the next reset

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00745200 | word_745200 | R | Level configuration table: good_match (good length) parameter |
| 00745202 | word_745202 | R | Level configuration table: max_lazy_match parameter |
| 00745204 | word_745204 | R | Level configuration table: nice_match parameter |
| 00745206 | word_745206 | R | Level configuration table: max_chain_length parameter |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branches — every field store runs unconditionally each call. Hash clearing uses the entry count at 0x44; nothing is compared or skipped.
