## SwitchBasedFloatProcessing_0040eec0 — SwitchBasedFloatProcessing

**Summary:** Processes 7-element float array through mode-based dispatch (0-5): stores collision inverse mass and bulk-sets 6 float fields. Part of collision/physics data pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ShortComputation_1330 (00411330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | Mode selector (this[7], values 0-5 trigger processing) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040ef54 | jpt_40EF07 | R | Jump table for mode switch (6 cases + default) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00459950 | CollisionInvMassStore | Stores collision inverse mass from first float element |
| 00459990 | F_6FieldBulkSetter | Sets 6 float fields from remaining float array elements |

**Guard conditions:** this[7] (mode) must be 0-5 → process collision data. default (mode 6+) → skip/return.
