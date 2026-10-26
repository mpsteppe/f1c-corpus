## SmallStructCopy_00448ec0 — Copy 3-byte type+handle pair into collision body

**Summary:** Copies a 1-byte type field and 2-byte handle word from a source structure into a collision body at offsets 0x19 and 0x1A. A small data field copy used during collision body initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TriangleMeshAdjacencyBuilder (004493a0), CollisionCapsuleShapeCopyToPipeline (0044b040)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x19 | RW | — | Body type field copied from source byte 0 |
| this | 0x1A | RW | — | Handle/index word copied from source bytes 2-3 |

**Written-by note (persistence):**
- this 0x19: Overwritten with source byte each call
- this 0x1A: Overwritten with source word each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional branches — unconditional copy.
