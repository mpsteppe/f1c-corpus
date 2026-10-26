## ListSelectionClamp_0042eb60 — ListSelectionClamp

**Summary:** Clamps a list selection index (e.g., gear ratio) for AI driver. Sets to clamped value or 0 if negative, marks dirty flags on change. Similar structure to AIGearSelectionSet.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** IndexedCallWith1Increment (00467340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | Activation/dirty flag; set to 1 when selection changes |
| this | 0x19A4 | RW | 1 | Selection change flag; set to 1 when value differs from previous |

**Written-by note (persistence):**
- this 0x0: Set to 1 on selection change. Overwritten each change.
- this 0x19A4: Set to 1 on selection change. Overwritten each change.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e530 | TrackConfig | Configure track parameters for selection (group=4) |

**Guard conditions:** Guard: a3 > 0 → clamp to max(a3, max-1). a3 <= 0 → set to 0 (disabled). Guard: new value != previous value → PASSES (sets dirty flags this[0] = 1, this[6564] = 1).
