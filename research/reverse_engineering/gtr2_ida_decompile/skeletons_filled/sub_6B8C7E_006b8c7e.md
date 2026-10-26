## sub_6B8C7E_006b8c7e — longest_match (walk hash chain for longest match)

**Summary:** zlib `longest_match()`: given an initial hash-chain position (a2), walks the prev-table chain comparing window bytes against the current scan position (strstart) to find the longest match, honoring the chain/good/nice limits, records the winning position at this+0x68 (match_start), and returns the best length clamped to the lookahead.

**Called by:** sub_6B9044 (006b9044), sub_6B92EA (006b92ea)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | w_size — used to compute the match search limit (strstart - 262 boundary) |
| this | 0x2C | R | — | w_mask — masks the chain position for the prev-table lookup |
| this | 0x30 | R | — | window buffer pointer — base for all match comparisons |
| this | 0x38 | R | — | prev chain table pointer — holds the next chain position per window index (u16 entries) |
| this | 0x64 | R | — | strstart — current scan position in the window |
| this | 0x68 | RW | — | match_start — records the window position of the best match found |
| this | 0x6C | R | — | lookahead — caps the returned match length |
| this | 0x70 | R | — | prev_length — starting best length (also used to seed the end-byte checks) |
| this | 0x74 | R | — | max_chain_length — chain walk budget; shifted right by 2 when the previous length reaches good_match |
| this | 0x84 | R | — | good_match — threshold that shortens the chain search |
| this | 0x88 | R | — | nice_match — early-exit length; clamped to the lookahead |

**Written-by note (persistence):**
- this 0x68: written only when a longer match is found during the walk (conditional); an external poke survives only until the next successful match hit

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Outer search loop (over chain positions a2): a chain entry is only byte-compared when `match[prev_length] == scan_end` AND `match[prev_length-1] == scan_end1` AND `*match == *scan` — otherwise the entry is skipped (continue to the next chain link). A second gate requires `match[1] == scan[1]` before the long comparison starts. Walk terminates when the next chain position is <= the computed limit (a2 <= limit → break), when the chain budget counter reaches 0 (`--v24` → exit), or early when a match length >= nice_match (clamped to lookahead) is found. When prev_length >= good_match the chain budget is quartered (`>>= 2`). Return: best length if <= lookahead, otherwise the lookahead.
