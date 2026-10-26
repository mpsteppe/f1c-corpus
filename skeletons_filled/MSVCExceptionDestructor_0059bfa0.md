## MSVCExceptionDestructor_0059bfa0 — MSVCExceptionDestructor

**Summary:** Destructor for MSVC exception object: frees owned string buffer if refcount is non-zero; skips free if string is borrowed/shared (refcount == 0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ExceptionCleanupWithDestructorCall (0059a728), DestructorWithSEHVTableReset (0059a7de), ExceptionDestructorSEHWrapper (0059ae24), ExceptionDestructor (0059aeda), ExceptionObjectDestructorWithSEH (0059afc2), ExceptionDestructorWithFlag (0059befd)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (restored to exception::`vftable') |
| this | 0x4 | R | — | String buffer pointer (freed if owned) |
| this | 0x8 | R | — | Refcount/ownership flag (0 = borrowed, non-zero = owned) |

**Written-by note (persistence):**
- this 0x0: written once (vtable restored before destruction)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9dc0 | ??_7exception@@6B@ | R | ExceptionVTable [DERIVED] — MSVC exception vtable |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free owned string buffer at this+0x4 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 0 | Refcount/ownership flag |

**Guard interpretation:** If this[2] == 0 (refcount zero — borrowed/shared string), free is skipped and destructor returns immediately. If non-zero (owned string), FreeWrapper_7bcf is called on this[1].
