## sub_6DA3C4_006da3c4 — Literal-frequency data-type heuristic

**Summary:** Sums the low (Freq) words of the literal-tree entries at 4-byte stride in two groups — symbols 0..6 plus 128..255 versus symbols 7..127 — and stores (and returns) the boolean (middle_sum >> 2) >= outer_sum in the byte at this+0x1C. A text-vs-binary style heuristic over the pending block's symbol frequencies; the written byte is a data-type flag read by callers (item caller compares it against a sentinel value 2 before invoking this).

**Called by:** sub_6DAAC0 (006daac0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | — | result byte: written with the comparison result (0/1); later read by callers as a data-type/mode flag |
| this | 0x8C | R | — | base of the first frequency group: 7 words (symbols 0..6) at 4-byte stride summed into the outer total |
| this | 0xA8 | R | — | base of the middle group: 121 words (symbols 7..127) at 4-byte stride summed into the middle total |
| this | 0x28C | R | — | base of the second frequency group: 128 words (symbols 128..255) at 4-byte stride summed into the outer total |

**Written-by note (persistence):**
- this 0x1C: unconditional — overwritten with the comparison result on every call; an external poke does not survive the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — straight-line sums and one boolean expression. Three fixed-count loops (7, 121 and 128 iterations, reading words at 4-byte stride) and the comparison v1 >> 2 >= v2 form the entire decision; result is stored to this+0x1C and returned. The middle group (7..127) is quarter-weighted against the outer group (0..6 plus 128..255).
