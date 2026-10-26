## UIDestructorWithSelfFree_00494470 — UI object destructor with self-free

**Summary:** Sets vtable pointer, calls base destructor sub_485EB0, and optionally frees the object allocation if the flag parameter has bit 0 set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable/interface pointer (set to off_5AC830) |

**Written-by note (persistence):**
- this 0x0: unconditional, set to vtable address; external poke would corrupt vtable dispatch

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac830 | off_5AC830 | R | UIFuncTable5AC830 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485eb0 | sub_485EB0 | Base UI object destructor (virtual dispatch) |
| 00587bcf | FreeWrapper_7bcf | Frees the object allocation |

**Guard conditions:** Self-free only occurs when a2 & 1 is non-zero. Always sets vtable and calls base destructor regardless.
