## VTablePointerInitializer_0052e6e7 — VTable pointer setter

**Summary:** Sets vtable pointer (first DWORD of object) to global audio buffer vtable at dword_8B0118. C++ constructor helper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (first DWORD of object) |

**Written-by note (persistence):**
- this 0x0: once, constructor writes vtable ptr; persists for object lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b0118 | dword_8B0118 | R | AudioBufferPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branches. Always writes dword_8B0118 to *this and returns this.
