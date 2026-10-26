## CursorResourceCleanup_0044f5f0 — Destroy cursor handles and reset state

**Summary:** Destroys all loaded cursor handles via DestroyCursor, clears handle array entries, resets cursor count, and sets the active cursor to null. Called on input exit and cleanup paths.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HWInput_Exit (00455f00), sub_4963D0 (004963d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | RW | 0 | Cursor handle array (6 slots, 20 bytes each, first dword = HCURSOR) |
| this | 0xA8 | RW | 0 | Cursor image count/index |

**Written-by note (persistence):**
- this 0x30: loop zeroes all 6 handle slots unconditionally; external poke overwrites
- this 0xA8: unconditional reset to 0; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2ac | DestroyCursor | R | Windows DestroyCursor import — frees cursor resource |
| 0059e2b0 | SetCursor | R | Windows SetCursor import — sets/clears active cursor |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always runs; no conditional early exit
