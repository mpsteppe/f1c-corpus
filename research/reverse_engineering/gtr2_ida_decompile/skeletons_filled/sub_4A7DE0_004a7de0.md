## sub_4A7DE0_004a7de0 — list initializer with single entry (`:00`)

**Summary:** Sibling of the option-list initializer: stores the backing-value pointer (this[210] = &dword_B6FF58) and the numeric parameters 23/0/1/1 at this[212..215], then registers a single labeled entry ":00" via sub_4D3CF0. Returns 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x348 | RW | — | this[210] — pointer to the global backing value dword_B6FF58 |
| this | 0x350 | RW | 23 | this[212] — numeric parameter (count/limit) set to 23 |
| this | 0x354 | RW | 0 | this[213] — initial index/selection set to 0 |
| this | 0x358 | RW | 1 | this[214] — flag set to 1 |
| this | 0x35C | RW | 1 | this[215] — flag set to 1 |

**Written-by note (persistence):**
- this 0x348: written unconditionally each call; pokes overwritten at the next call.
- this 0x350: written unconditionally each call (23); pokes overwritten at the next call.
- this 0x354: written unconditionally each call (0); pokes overwritten at the next call.
- this 0x358: written unconditionally each call (1); pokes overwritten at the next call.
- this 0x35C: written unconditionally each call (1); pokes overwritten at the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ff220 | a00_0 | R | ":00" label string registered as the single list entry |
| 00b6ff58 | dword_B6FF58 | R | Global value whose address is stored in this[210] as the list's backing value |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d3cf0 | sub_4D3CF0 | Registers the ":00" labeled list entry (second argument -1) |

**Guard conditions:** None — no branches or tests; all stores and the single registration call execute unconditionally. Function always returns 0.

**String literals referenced (deterministic):**

- `:00`
