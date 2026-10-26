## FieldFreeCleanup_00478140 — FieldFreeCleanup

**Summary:** Destructor/cleanup: frees child pointer at offset 0xE8 if non-null, runs sub-cleanup, then conditionally frees `this` based on flag bit 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE8 | R | — | child/dynamic pointer checked before free |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485eb0 | sub_485EB0 | sub-cleanup routine on this object |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions:** First guard: this[58] (offset 0xE8) must be non-zero to free it (skips if null). Second guard: (a2 & 1) flag must be set to free `this` (skips if clear).
