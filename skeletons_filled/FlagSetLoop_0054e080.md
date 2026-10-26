## FlagSetLoop_0054e080 — Material flag propagation loop

**Summary:** Iterates through a secondary vertex element array, dereferences each element to a material/vertex object, and sets flag bit 0 on objects that already have flag bit 1 set. Called after vertex transform to propagate a completion state flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferTransform (0054c6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x120 | R | — | Secondary element count (guard > 0 for loop) |
| this | 0x124 | R | — | Secondary element array pointer (36-byte stride per entry) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00545f40 | ValueGetter | Retrieves UI root context pointer from global |

**Guard conditions:** If this[72] (element count at +0x120) > 0, PASSES: enters loop, dereferences each element to access its material/vertex object flags at offset +0x9C. If `*(v5+0x9C) & 2` is nonzero, ORs bit 0 into same field. If count <= 0, BLOCKED: entire loop skipped.
