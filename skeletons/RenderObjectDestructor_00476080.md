## RenderObjectDestructor_00476080 — HUDTextNodeDestructor

**Summary:** Destructor for a HUD text/render node: transitions vtable to child type, frees child node at 0x30, transitions to base control vtable, frees resource at 0x4, and optionally frees self if destructor flag bit 0 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer (switched twice during destruction) |
| this | 0x4 | R | — | Owned resource/child pointer to free |
| this | 0x30 | R | — | Child node pointer to free before base cleanup |

**Written-by note (persistence):**
- this 0x0: vtable swapped during destructor; object invalid after

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a443c | off_5A443C | R | VTable_ControlBase [DERIVED] |
| 005a4450 | off_5A4450 | R | VTable_HUDTextNode [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper (free with null check) |

**Guard conditions:** Free of child at 0x30 PASSES only if this[12] is non-null. Free of resource at 0x4 PASSES only if this[1] is non-null. Self-deallocation PASSES only if (a2 & 1) != 0 (destructor flag).
