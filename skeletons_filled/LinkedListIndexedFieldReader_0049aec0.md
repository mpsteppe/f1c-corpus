## LinkedListIndexedFieldReader_0049aec0 — LinkedListIndexedFieldReader

**Summary:** Reads a pair of 16-bit values from a linked list node at a given index. Walks the list from head following next pointers at offset +4. If the index is out of range or the node/data is null, zeros the output parameters and returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_487060 (00487060), sub_4870E0 (004870e0), UtilityFunction_7160 (00487160), TwoChannel16BitReader (00499f00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | List head pointer |
| this | 0x8 | RW | 0 | Current node pointer during traversal |
| this | 0xC | R | — | List length bound |

**Written-by note (persistence):**
- this 0x8: set to 0 on out-of-bounds, or updated to traversed node during walk; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Index a2 < 0 or a2 >= this[0xC] (list length) → BLOCKED: sets this[0x8] = 0, skips traversal. If this[0x8] is NULL after traversal or the node's first word pointer (*v7) is NULL → BLOCKED from reading: zeros output params and returns 0. Otherwise PASSES: reads two words into *a3 and *a4, returns 1.
