## LoadPathGetter_004765f0 — LoadPathStringAccessor

**Summary:** Accesses a path string pointer from offset 0x04 of an object. Returns global default directory path if internal path is null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | load path string pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `this[1]` (offset 0x04) == NULL → returns `byte_5EA438`; non-NULL → returns internal path pointer
