## VtableMethodShutdown_00434d40 — VtableMethodShutdown

**Summary:** Calls first vtable method (destructor/delete) on a vtable-based object and clears the pointer. Standard RAII-style cleanup for heap-allocated polymorphic object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConstraintSolverParamInit (00434860), sub_4348B0 (004348b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0x0 | R | — | vtable pointer of the sub-object (used to dispatch destructor) |
| this | 0xC | RW | 0 | pointer to vtable-based sub-object (cleared to 0 after deletion) |

**Written-by note (persistence):**
- this 0xC: written once (set to 0) after deletion. Survives (becomes null).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Pointer at `this[3]` (offset 0xC) must be non-null to dispatch destructor. If null, function returns 0 immediately.
