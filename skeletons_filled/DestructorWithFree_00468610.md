## DestructorWithFree_00468610 — DestructorWithConditionalFree

**Summary:** Destructor that sets the vtable pointer, conditionally frees a heap-allocated sub-object at this[93] if non-null, then delegates to another cleanup function. Belongs to object destruction system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDestructorWithCleanup (004685f0), sub_485A90 (00485a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_59F718) |
| this | 0x174 | R | — | pointer to sub-object to free (this[93]); freed if non-null |

**Written-by note (persistence):**
- this 0x0: set to off_59F718 on every call (vtable fixup during destruction).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f718 | off_59F718 | R | RenderEntityVTable_59F718 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated memory (the sub-object at this[93]) |

**Guard conditions:** Checks this[93] (offset 0x174) for null before calling FreeWrapper_7bcf. If null (BLOCKED), skip freeing. Only frees when pointer is non-null (PASSES).
