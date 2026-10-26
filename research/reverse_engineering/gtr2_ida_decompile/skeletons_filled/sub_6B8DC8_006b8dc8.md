## sub_6B8DC8_006b8dc8 — fill_window (slide window, read input)

**Summary:** zlib `fill_window()`: computes free space in the window, slides the window when the start position nears the end (memmove plus signed-offset fixups of the head/prev hash tables and the match/bookkeeping counters), reads input bytes from the stream into the window while updating the checksum, refreshes the rolling 2-byte hash, and loops until enough lookahead (262) is available or input is exhausted.

**Called by:** sub_6B8F20 (006b8f20), sub_6B9044 (006b9044), sub_6B92EA (006b92ea)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | RW | — | strm->next_in — input pointer, advanced by the number of bytes read |
| obj | 0x4 | RW | — | strm->avail_in — input bytes remaining; checked each round and decremented by the bytes copied |
| obj | 0x8 | RW | — | strm->total_in — accumulated input byte count |
| obj | 0x1C | R | — | strm->state — read to test the wrapper flag before the checksum update |
| obj | 0x30 | RW | — | strm->adler/checksum word — updated through the checksum routine for the newly read bytes |
| obj | 0x34 | R | — | Reserved stream word; read with no visible use in this listing |
| this | 0x0 | R | — | Back-pointer to the owning stream object (source of next_in/avail_in/checksum) |
| this | 0x24 | R | — | w_size — window size and slide distance |
| this | 0x30 | R | — | window buffer pointer — slide source/destination and match base |
| this | 0x34 | R | — | window_size — free-space computation (window_size - strstart - lookahead) |
| this | 0x38 | R | — | prev hash-chain table — entries decremented on slide (with underflow clamp) |
| this | 0x3C | R | — | head hash table — entries decremented on slide (with underflow clamp) |
| this | 0x40 | RW | — | ins_h — 2-byte rolling hash refreshed when the lookahead reaches 3 |
| this | 0x44 | R | — | hash_size — loop bound for both head and prev index fixups |
| this | 0x4C | R | — | hash_mask — mask applied to the refreshed rolling hash |
| this | 0x50 | R | — | hash_shift — shift applied to the previous hash byte |
| this | 0x54 | RW | — | block_start — shifted down by w_size when the window slides |
| this | 0x64 | RW | — | strstart — current scan position; shifted down by w_size on slide, source of the hash refresh |
| this | 0x68 | RW | — | match_start — shifted down by w_size when the window slides |
| this | 0x6C | RW | — | lookahead — incremented by the bytes read; loop exit when it reaches 262 |

**Written-by note (persistence):**
- obj 0x0: advanced only when bytes are actually read (copied count nonzero); otherwise untouched
- obj 0x4: decremented only when bytes are read; otherwise untouched
- obj 0x8: accumulated only when bytes are read; otherwise untouched
- obj 0x30: rewritten only when the checksum branch runs (bytes read and the state wrapper flag is zero)
- this 0x40: rewritten only when the lookahead has reached at least 3 bytes (hash refresh)
- this 0x54: decremented only inside the window-slide branch
- this 0x64: decremented only inside the window-slide branch
- this 0x68: decremented only inside the window-slide branch
- this 0x6C: incremented whenever bytes are read; exit condition when >= 262

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006d9497 | sub_6D9497 | Running checksum update (adler32/crc style) over the newly read input bytes for the stream checksum word |

**Guard conditions:** Free-space computation `more = window_size - strstart - lookahead`: if 0 with strstart == 0 and lookahead == 0 the fresh-start value becomes w_size; if it computes to -1 it is decremented once (overflow clamp). The window-slide branch runs only when strstart >= w_size + w_size - 262 (positions too close to the window end). Input reading stops (break) when strm->avail_in == 0. The checksum call is gated by the state wrapper field being zero. The rolling hash refresh runs only when the lookahead reaches >= 3. The outer loop repeats while lookahead < 0x106 (262, MIN_LOOKAHEAD) and avail_in != 0.
