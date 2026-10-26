## sub_6A4B6D_006a4b6d — AppendToDynamicArray

**Summary:** Appends the dword a2 to a dynamically grown array: when the element count (a1+0x1C) is a multiple of 8 it allocates a new buffer of count+8 dwords, copies the old contents and swaps the pointer at a1+0x20, then stores a2 and increments the count. Returns 0 on success, -2147024882 on allocation failure.

**Called by:** sub_6A4BC7 (006a4bc7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | current element count; a multiple of 8 triggers buffer growth |
| this | 0x20 | RW | — | pointer to the element buffer; replaced on growth and written through when appending |

**Written-by note (persistence):**
- this 0x20: rewritten only when the count is a multiple of 8 (buffer growth, every 8th append); the appended dword is written to `buffer[count]`. An external poke survives until a growth step or an append through the pointer refreshes it.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00681169 | sub_681169 | allocates the replacement buffer of count+8 dwords; null result → -2147024882 |

**Guard conditions:** When (count & 7) == 0 → grow path: allocation must succeed or return -2147024882 (BLOCK). Otherwise append directly. PASS: a2 is stored at buffer[count] and count is incremented → return 0.
