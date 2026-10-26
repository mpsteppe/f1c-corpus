## SlotArrayInit_004d7ad0 — SlotArrayInit_3x4

**Summary:** Initializes an interleaved 3-slot array (12 DWORDs total). For each slot, sets two fields to -1 (sentinel) and two to 0. Total struct spans offsets 0x0 through 0x2C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | RW | 0 | third field of first slot (cleared to 0) |
| this | 0x24 | RW | 0 | fourth field of first slot (cleared to 0) |

**Written-by note (persistence):**
- this 0x18: written unconditionally to 0 during init; survives external poke
- this 0x24: written unconditionally to 0 during init; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional 3-iteration loop, no branches.
