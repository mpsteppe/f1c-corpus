## AIGearSelectionSet_0042eaa0 — AIGearSelectionSet

**Summary:** Sets target gear for an AI driver's specific wheel in a multi-dimensional indexed structure. Clamps to valid gear range, triggers event on state change, and marks dirty flags when gear changes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** IndexedCallWith1Increment (00467340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | Activation/dirty flag; set to 1 on gear change |
| this | 0x19A4 | RW | 1 | Gear change flag; set to 1 when gear value changes |
| this | 0x19A5 | R | — | Enable flag for event/state-change trigger |

**Written-by note (persistence):**
- this 0x0: Set to 1 when selected gear differs from current gear. Overwritten on change.
- this 0x19A4: Set to 1 when gear changes. Overwritten on change.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e470 | EventTriggerOnStateChange | Fire event/notification when AI gear selection state changes |
| 0042e530 | TrackConfig | Configure track-related parameters for AI driver/wheel |

**Guard conditions:** Guard: a4 > 0 → set gear to clamp(a4, 0, maxGear-1). a4 <= 0 → set gear to 0 (neutral/disabled). Guard: this[6565] (offset 0x19A5) must be non-zero to enable EventTriggerOnStateChange call. Guard: new gear != previous gear → PASSES (sets dirty flags at this[0] and this[6564] to 1).
