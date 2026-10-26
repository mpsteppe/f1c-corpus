## StringFieldSetter_00499a30 — String copy and field setter

**Summary:** Copies string from parameter a2 via StringCopyWithBufferRealloc, then sets field at this+0x8 to a3. Part of string/resource field assignment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpriteTextureEnumeration (00498950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | field set to parameter a3 after string copy |

**Written-by note (persistence):**
- this 0x8: written once with a3 parameter; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies string from a2 with buffer reallocation |

**Guard conditions:** none — unconditional setter
