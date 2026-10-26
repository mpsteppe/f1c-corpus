## ArraySlotCompactionWithGapFilling_00418ac0 — OverlaySlotArrayCompact

**Summary:** Iterates 20 overlay display slots (32 bytes each). Phase 1: resets expired slots (current time > stored expiry float with non-sentinel value). Phase 2: compacts array by shifting filled slots left to fill gaps. Maintains contiguous active slot list.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextOverlayDisplayTimer (004186f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x864 | R | — | Slot 0 ID field (-1 = empty); used in compaction gap detection |
| this | 0x870 | R | — | Slot 0 expiry float (checked vs -1.0f sentinel and current time) |
| this | 0x884 | R | — | Slot 1 ID field (-1 = empty); used in compaction gap detection |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afea8 | dbl_8AFEA8 | R | InputAxisDeadZone [DERIVED] (also: ` — axis threshold (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Resets slot struct to empty/default state (sets ID to -1, expiry to -1.0f sentinel) |
| 004145c0 | StructCopy | Copies slot data (32 bytes) between array positions during compaction |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x864 | == | 18446744073709551615 | Slot 0 ID == -1 (empty) |
| this | 0x870 | != | 18446744072627421184 → -1.0f | Slot 0 expiry float != -1.0f sentinel (has real expiry) |
| this | 0x884 | == | 18446744073709551615 | Slot 1 ID == -1 (empty) |

**Guard interpretation:** Phase 1: when slot's float (offset +0xC) is not -1.0f (non-sentinel) AND current time > float value, slot is expired and reset — PASSES expiry check. Phase 2: when first empty slot index < last filled slot index, compaction proceeds — shifts filled slots left into gaps. If no gaps or no fill-after-gap, compaction skipped.
