## VTablePointerSetter_ac3f_0059ac3f — VTable reset to std::locale::facet

**Summary:** Overwrites this->vtable with std::locale::facet vtable pointer. Minimal single-write function used during destructor vtable reset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer, overwritten with facet vtable |

**Written-by note (persistence):**
- this 0x0: Once — vtable pointer written. External poke would survive (trivially reversible).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9d54 | ??_7facet@locale@std@@6B@ | R | VTable_StdfacetLocale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No explicit guard conditions — always executes.
