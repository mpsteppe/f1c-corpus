## SmallStructInit_9a00_00499a00 — String copy init with field zero

**Summary:** Copies global path string (byte_5EA438) via StringCopyWithBufferRealloc, then zeroes field at this+0x8. Part of struct initialization with path/default directory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_495B60 (00495b60), sub_4999E0 (004999e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | field zeroed after string copy |

**Written-by note (persistence):**
- this 0x8: written once unconditionally during init; persists for object lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory / path string source |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies string with dynamic buffer allocation |

**Guard conditions:** none — unconditional init sequence