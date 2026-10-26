## MultiPhaseDestructorWithVTableSwitching_004761e0 — UIGameFilterDestructor

**Summary:** Multi-phase destructor for a game filter UI object: transitions through three vtables (game filter -> HUD text -> control base), freeing owned child resources at each phase, then optionally frees self.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer (switched through 3 vtables during destruction) |
| this | 0x4 | R | — | Owned resource/child pointer to free (control base phase) |
| this | 0x30 | R | — | Child HUD text node pointer to free |
| this | 0x40 | R | — | Game filter child resource pointer to free |

**Written-by note (persistence):**
- this 0x0: vtable swapped during destructor; object invalid after

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a443c | off_5A443C | R | VTable_ControlBase [DERIVED] |
| 005a4450 | off_5A4450 | R | VTable_HUDTextNode [DERIVED] |
| 005a4478 | off_5A4478 | R | VTable_5A4478 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper (free with null check) |

**Guard conditions:** Free of resource at 0x40 (phase 1) PASSES only if this[16] != 0. Free of HUD node at 0x30 (phase 2) PASSES only if this[12] != 0. Free of resource at 0x4 (phase 3) PASSES only if this[1] != 0. Self-free PASSES only if (a2 & 1) != 0.
