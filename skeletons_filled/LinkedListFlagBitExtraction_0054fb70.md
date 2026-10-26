## LinkedListFlagBitExtraction_0054fb70 — Linked list node flag bit extractor

**Summary:** Extracts bit 6 (0x40) from a flag byte at offset +0x14 of a linked list node pointed to by this+0x204. Returns 0 or 1 as a boolean value. Used during scene extent computation to query a property flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40FE50 (0040fe50), SceneExtentComputation (004bdc10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | Pointer to a linked list/scene node containing a flag byte at +0x14 |
| this | 0x218 | R | — | unknown |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — unconditionally returns the extracted bit value (0 or 1).
