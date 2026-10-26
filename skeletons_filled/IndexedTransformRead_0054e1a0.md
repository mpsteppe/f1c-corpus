## IndexedTransformRead_0054e1a0 — Indexed bone/transform vector reader

**Summary:** Reads three 3D vectors (position/rotation/scale or similar) from a structured indexed array. Each 36-byte entry contains three 16-bit sub-indices and a base pointer to a 48-byte-stride transform array. Used for animation/skeleton pose lookups.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AnimationPlaybackSequence (0044acb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x120 | R | — | Array element count (guard < a2 prevents out-of-bounds read) |
| this | 0x124 | R | — | Pointer to 36-byte-stride indexed array (each entry: 3 WORD indices + 1 DWORD base pointer) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `a2 < this[72]` (index within bounds of count at +0x120), PASSES: reads 3 vectors from the indexed array. If `a2 >= this[72]`, BLOCKED: all output pointers left unchanged.
