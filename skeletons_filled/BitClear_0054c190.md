## BitClear_0054c190 — Clear bits 1 and 2 in flag field

**Summary:** Clears bits 1 (0x2) and 2 (0x4) in the flag field at offset 0x3C using mask 0xFFFFFFF9.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A3390 (004a3390), PerElementConditionalActionDispatcher (004a34a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C | RW | — | Flags field; bits 1 and 2 cleared |

**Written-by note (persistence):**
- this 0x3C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always clears both bits unconditionally.
