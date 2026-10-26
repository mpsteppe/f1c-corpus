## DestructorWithConditionalFree_fd80_0048fd80 — ConditionalDestructorFree

**Summary:** Destructor that conditionally frees a child pointer and optionally frees self based on a flag. Part of a UI control object lifecycle.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (restored before cleanup) |
| this | 0x4 | R | — | Pointer to child resource to conditionally free |

**Written-by note (persistence):**
- this 0x0: Once — set to vtable pointer; overwritten during destruction.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a443c | off_5A443C | R | VTable_ControlBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation function |

**Guard conditions:** Checks `this[1]` (offset 0x4) — PASSES (calls FreeWrapper_7bcf on it) when non-null, BLOCKED (skips free) when null. Checks `a2 & 1` — PASSES (calls FreeWrapper_7bcf on `this`) when flag bit 0 is set, BLOCKED (skips self-free) when flag bit 0 is clear.
