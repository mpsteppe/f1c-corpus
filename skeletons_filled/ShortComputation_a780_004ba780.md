## ShortComputation_a780_004ba780 — Pointer dereference guard

**Summary:** If this[0] is non-null, dereferences it as a pointer and returns the pointed DWORD. Always copies this[0] to this[2]. Returns 0 if this[0] is null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_490D00 (00490d00), CollisionObjectInsertion (004b48e0), ModelSceneFileLoader (004b6c90), sub_4B7860 (004b7860), sub_57BF00 (0057bf00), NetworkPacketQueueReader (005805c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Value pointed to by this[0] (dereferenced when non-null) |
| this | 0x0 | R | — | Pointer to resolve (or 0) |
| this | 0x8 | RW | — | Saved copy of this[0] |

**Written-by note (persistence):**
- this 0x8: written every call with this[0]; persists until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | Null pointer check |

**Guard interpretation:** BLOCKS (returns 0) when this[0]==0. PASSES (dereferences and returns pointed value) when this[0]!=0.
