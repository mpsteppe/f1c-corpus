## BVHTreeNodeArrayInit_0044f0a0 — BVH tree node array initialization

**Summary:** Clears BVH tree node arrays: a 256-entry dword array at 0x87C, a 256-entry byte array at 0x37C, a count field at 0xC84, and 48 bytes at 0xC88. Called from HWInput_Restart to reset collision tree state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HWInput_Restart (00455da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x87C | RW | 0 | BVH tree node dword array (256 entries) |
| this | 0xC84 | RW | 0 | Node count/index field |

**Written-by note (persistence):**
- this 0x87C: unconditional loop clear of all 256 entries; external poke overwrites
- this 0xC84: unconditional clear; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — no conditional branches; always performs full clear
