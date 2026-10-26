## StateHandlerDispatch_004f7010 — dual-table state handler dispatch

**Summary:** Selects one of two handler tables based on a flag byte, iterates up to 45 handler objects calling each via vtable method at offset 8. Updates the flag byte after dispatch.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A0250 (004a0250), AudioSoundEffectController (004e0ed0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0 | RW | — | flag byte: non-zero selects table A (0x694), zero selects table B (0x6D8) |
| this | 0x694 | R | — | pointer to handler table A (45 entries, 4 bytes each) |
| this | 0x6D8 | R | — | pointer to handler table B (45 entries, 4 bytes each) |

**Written-by note (persistence):**
- this 0xB0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Byte at 0xB0 selects handler table pointer. If selected pointer is null → skip handler iteration, only update flag. For each non-null handler entry in table → calls vtable+8 method.
