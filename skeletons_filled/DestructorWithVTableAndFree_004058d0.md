## DestructorWithVTableAndFree_004058d0 — DestructorWithVTableSetAndConditionalFree

**Summary:** Sets vtable to swap vtable, frees child allocation at offset 0x4, and conditionally frees this object itself when flag bit 0 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (set to SwapVTable) |
| this | 0x4 | R | — | Pointer to child allocation, checked before free |

**Written-by note (persistence):**
- this 0x0: once (vtable set, survives as final value)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e4b4 | off_59E4B4 | R | VTable_0059e490_Swap [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free child allocation at this[1] if non-null; also free this if flag set |

**Guard conditions:** Two checks: (1) if `this[1]` (offset 0x4) is non-null → frees child allocation. (2) if `(a2 & 1) != 0` (deallocation flag bit 0 set) → also frees this object itself via FreeWrapper_7bcf.
