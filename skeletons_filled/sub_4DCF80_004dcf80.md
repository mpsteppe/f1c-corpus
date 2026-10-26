## sub_4DCF80_004dcf80 — Initialize object with default scale and path buffer

**Summary:** Initializes two scale factor fields at offsets +0x30 and +0x34 to 1.0f, copies the global path buffer via StringCopyWithBufferRealloc, and returns ShortComputation_cb70 result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_b360 (0045b360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | RW | 1065353216 → 1.0f | Scale X factor (this[12]); initialized to 1.0 |
| this | 0x34 | RW | 1065353216 → 1.0f | Scale Y factor (this[13]); initialized to 1.0 |

**Written-by note (persistence):**
- this 0x30: written each call to 1.0f; persists until overwritten
- this 0x34: written each call to 1.0f; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Global path buffer copied into object context |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copy path string with buffer reallocation |

**Guard conditions:** None — function executes unconditionally.
