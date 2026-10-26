## ShortComputation_a9c0_0049a9c0 — QuadFieldSetter

**Summary:** Stores four parameters into fields at offsets 0x04, 0x08, 0x0C, and 0x10. Returns the third parameter (a4).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UILargeRenderDispatcher (00488be0), UICustomRenderDispatch (00489fd0), sub_492460 (00492460), sub_492710 (00492710), sub_492A40 (00492a40), NodeInsertionIntoTree (00498e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | field set to a2 |
| this | 0x8 | RW | — | field set to a3 |
| this | 0xC | RW | — | field set to a4 (also returned) |
| this | 0x10 | RW | — | field set to a5 |

**Written-by note (persistence):**
- this 0x4: written unconditionally; external poke survives
- this 0x8: written unconditionally; external poke survives
- this 0xC: written unconditionally; external poke survives
- this 0x10: written unconditionally; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — straight-line stores, no branches.
