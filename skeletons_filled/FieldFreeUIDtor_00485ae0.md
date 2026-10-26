## FieldFreeUIDtor_00485ae0 — FieldFreeUIDtor

**Summary:** Destructor for an object with a dynamically allocated sub-resource at this+0x174. Frees the sub-resource if present, calls base cleanup, then conditionally deallocates `this` when the scalar-deletion flag is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x174 | R | — | pointer to dynamically allocated sub-object or resource to free |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489440 | FunctionCallWrapper_9440 | call base-class destructor or common cleanup routine |
| 00587bcf | FreeWrapper_7bcf | free/deallocate memory via internal allocator |

**Guard conditions:** checks `this[93]` (offset 0x174) != NULL → if non-null, frees that resource via FreeWrapper_7bcf. Then checks `a2 & 1` (scalar-deletion flag) → if set, deallocates `this` via FreeWrapper_7bcf. Non-null sub-resource and scalar-deletion flag both PASS the respective frees; null sub-resource and non-set flag BLOCK the corresponding free path.
