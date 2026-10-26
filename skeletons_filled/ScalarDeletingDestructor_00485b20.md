## ScalarDeletingDestructor_00485b20 — ScalarDeletingDestructor

**Summary:** Destructor freeing two dynamically allocated sub-resources (at this+0x174 and this+0x17C) before calling base cleanup, then conditionally deallocating `this` if the scalar-deletion flag is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x174 | R | — | pointer to first dynamically allocated sub-resource to free |
| this | 0x17C | R | — | pointer to second dynamically allocated sub-resource to free |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489440 | FunctionCallWrapper_9440 | call base-class destructor or common cleanup routine |
| 00587bcf | FreeWrapper_7bcf | free/deallocate memory via internal allocator |

**Guard conditions:** checks `this[95]` (offset 0x17C) != NULL → if non-null, frees that resource. Then checks `this[93]` (offset 0x174) != NULL → if non-null, frees that resource. Then checks `a2 & 1` (scalar-deletion flag) → if set, deallocates `this`. Null fields and non-set flag BLOCK the corresponding free paths.
