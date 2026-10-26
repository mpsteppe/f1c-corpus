## ArithmeticComparison_8370_004f8370 — StructReinitHelper

**Summary:** Resets struct state: frees double buffers, reinitializes tire slots, resets two array counters, clears field at 0x94, and sets active flag at offset 4 to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehgenScnFileLoader (004c6c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 1 | Active flag (set to 1 on init) |
| this | 0x94 | RW | 0 | Clear/reset counter field (set to 0 on init) |

**Written-by note (persistence):**
- this 0x4: Set to 1 each reinit; external poke overwrites
- this 0x94: Set to 0 each reinit; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f6d60 | ArrayNonZeroCounter | Resets and counts non-zero entries in two internal arrays |
| 004f70c0 | sub_4F70C0 | Reinitializes tire slot substructs |
| 004f83b0 | DoubleBufferFree | Frees double-buffered object arrays |

**Guard conditions:** None (all operations unconditional).
