## PointerStorePair2_00542540 — Store two pointer values at 0x1A4, 0x1A8

**Summary:** Stores a2 at offset 0x1A4 and a3 at offset 0x1A8. Returns a2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_409890 (00409890), ConditionalRenderPipelineDispatch (00409970)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A4 | RW | — | first pointer, written with a2 |
| this | 0x1A8 | RW | — | second pointer, written with a3 |

**Written-by note (persistence):**
- this 0x1A4: overwritten with a2 each call.
- this 0x1A8: overwritten with a3 each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes.
