## sub_4FBF10_004fbf10 — nearest-key lookup over pair table, writes matched value to this+0xAC

**Summary:** Scans the object's pair table (array of `this[170..]`, entries as key/value pairs) and finds the entry whose key is closest to `a2` in absolute distance, storing that entry's value into `this[43]` (offset 0xAC). The scan runs from the last entry down to the first and keeps the best (smallest distance) match.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAC | RW | — | Output slot (this[43]): receives the value half of the closest-matching entry; only written when a closer match (distance < 255) is found. |
| this | 0x2A4 | R | — | Entry count (this[169]); determines the scan range, entries live at this[2*i+170]/this[2*i+171]. |

**Written-by note (persistence):**
- this 0xAC: [LLM: written once/conditional/recalc every frame? would an external poke survive?] — Conditional write, at most once per better match inside the loop; if no entry has `abs32(a2 - key) < 255` the field is left untouched, so an external poke survives calls whose nearest distance is >= 255. Call frequency is not determinable from this function alone.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop guarded by `result = this[169] - 1; if (result >= 0)` — i.e. scan only when the entry count is > 0; with 0 entries the function returns the -1 sentinel and never touches this[43]. Within the loop, `this[43] = *v4` executes only when `abs32(a2 - *(v4-1)) < v3` (starting v3 = 255), so matches with distance >= 255 are BLOCKED from updating the field.
