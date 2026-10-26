## DestructorWithSubObjectFree_004698c0 — DestructorWithSubObjectFree

**Summary:** Destructor that conditionally frees a sub-object at this[96] if non-null, calls a cleanup wrapper, then optionally frees the containing object based on a destructor flag. Belongs to object destruction system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x180 | R | — | pointer to sub-object to free (this[96]); freed if non-null |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489440 | FunctionCallWrapper_9440 | performs additional cleanup/deinitialization on this object |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated memory (sub-object at this[96] and optionally this) |

**Guard conditions:** Checks this[96] (offset 0x180) for null before calling FreeWrapper_7bcf (BLOCKED if null, PASSES if non-null). Checks a2 & 1 flag bit; if set (PASSES), frees the containing `this` object after cleanup.
