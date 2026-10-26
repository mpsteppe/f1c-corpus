## UIElementMultiDispatch_004e39d0 — UIElementMultiDispatch

**Summary:** Iterates array of sub-elements at stride 748 bytes (starting from offset 0xBAC), dispatching float value a2 to each via sub_4DF030. Count from field at offset 0xBA8. UI/scene element update dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xBA8 | R | — | count of sub-elements to iterate |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004df030 | sub_4DF030 | create typed LRU cache entry with given float value |

**Guard conditions:** If count (this+0xBA8) > 0, iterate sub-elements (PASS). If <= 0, skip loop (BLOCKED).
