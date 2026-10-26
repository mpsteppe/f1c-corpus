## StructInitWithSubCall_004527e0 — Initialize collision property struct

**Summary:** Initializes a small collision property structure: zeros the first field at 0x0, swaps and reinitializes fields at 0x4/0x8 with new values via SwapAndReinit, then zeros fields at 0x1C and 0x20.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_30a0 (004530a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Collision property guard/state field |
| this | 0x1C | RW | 0 | Collision property associated value B |
| this | 0x20 | RW | 0 | Collision property associated value C |

**Written-by note (persistence):**
- this 0x0: reset to 0 unconditionally; external poke overwrites
- this 0x1C: reset to 0 unconditionally; external poke overwrites
- this 0x20: reset to 0 unconditionally; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00452740 | SwapAndReinit | Swaps stored values and reinitializes collision node property at offset 0x4/0x8 |

**Guard conditions:** none — always initializes all fields
