## BatchProcessWithFixedStartOffsets_00410890 — BatchedObjectUpdateDispatcher

**Summary:** Dispatches StateDependentUpdateDispatch across 6 batches of objects stored at fixed offsets within a struct. Each batch has a count field and a base pointer field; stride is 36 bytes per object. Batches 4-6 have minimum start indices (416, 208, 832) below which no objects exist. Resets counter at this+0x6C to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Restart (0042c3b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | batch 1 count (number of 36-byte objects) |
| this | 0x28 | R | — | batch 1 base pointer (pointer to first 36-byte object) |
| this | 0x30 | R | — | batch 2 count |
| this | 0x34 | R | — | batch 2 base pointer |
| this | 0x3C | R | — | batch 3 count |
| this | 0x40 | R | — | batch 3 base pointer |
| this | 0x48 | R | — | batch 4 count (min start index 416) |
| this | 0x4C | R | — | batch 4 base pointer |
| this | 0x54 | R | — | batch 5 count (min start index 208) |
| this | 0x58 | R | — | batch 5 base pointer |
| this | 0x60 | R | — | batch 6 count (min start index 832) |
| this | 0x64 | R | — | batch 6 base pointer |
| this | 0x6C | RW | 0 | reset counter, cleared to 0 each call |

**Written-by note (persistence):**
- this 0x6C: set to 0 each call; reset counter

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f130 | StateDependentUpdateDispatch | dispatched to each object in every batch |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x30 | > | 0 | batch 2: skip if count <= 0 |
| this | 0x3C | > | 0 | batch 3: skip if count <= 0 |
| this | 0x48 | > | 416 | batch 4: only process if count exceeds min start index 416 |
| this | 0x54 | > | 208 | batch 5: only process if count exceeds min start index 208 |

**Guard interpretation:** each batch guard is PASS (count > threshold / count > 0) → iterate from threshold to count, calling StateDependentUpdateDispatch on each. BLOCKED (count <= threshold) → skip that batch entirely.
