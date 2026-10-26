## AudioPanUpdate_005438b0 — AudioPanSetter

**Summary:** Sets left/right audio pan values and marks the UI for update. Stores left pan (a2) at offset 0x194 if non-negative. Sets right pan (offset 0x198) to left-pan value when a3 < left, otherwise to a3.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | — | flags/state field; bit 0x10000 set to signal UI update needed |
| this | 0x194 | RW | — | left audio pan value (float) |
| this | 0x198 | RW | — | right audio pan value (float) |

**Written-by note (persistence):**
- this 0xEC: bit 0x10000 OR'd in each call; other bits survive
- this 0x194: overwritten with a2 when a2 >= 0.0
- this 0x198: overwritten with either left pan (when a3 < left) or a3 (otherwise)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | zero constant (~0.0) for boundary comparison |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 must be >= 0.0 to update left-pan at offset 0x194 (negative values rejected). The right-pan always updates (either mirrors left or stores a3), and flag 0x10000 always set.
