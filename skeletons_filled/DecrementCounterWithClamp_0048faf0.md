## DecrementCounterWithClamp_0048faf0 — ScrollOffsetDecrementClamp

**Summary:** Decrements the scroll offset counter (offset 0x168) by the given amount (or by the value at offset 0x178 if negative), clamps result to minimum 0, then calls UITileGrid to recalculate tile positions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_48F1A0 (0048f1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x168 | RW | 0 | scroll offset / counter to decrement |
| this | 0x178 | R | — | default decrement amount fallback |

**Written-by note (persistence):**
- this 0x168: updated and clamped; survives until next update

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048f870 | UITileGrid | update tile positions after scroll offset change |

**Guard conditions:**
- if (a2 < 0) → PASS (use default decrement value from offset 0x178)
- if (a2 >= 0) → BLOCKED (use provided a2 directly)
- Compute: new_val = current - decrement
- if (new_val < 0) → clamp to 0
