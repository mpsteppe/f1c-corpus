## ObjectReleaseWithVtableCall_0053d850 — Sub-object release via vtable call

**Summary:** Calls cleanup helper sub_540760, then if this+0x10FC is non-null, calls vtable method[2] (offset 8) on it for release, stores return to *this, and nulls this+0x10FC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GlobalResourceCleanup (0053c4d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10FC) | 0x8 | R | — | vtable slot[2] — release/destroy method on sub-object |
| this | 0x0 | RW | — | stores return value from vtable release call |
| this | 0x10FC | RW | 0 | sub-object pointer — read before release, set to 0 after |

**Written-by note (persistence):**
- this 0x0: written once per call, overwritten each call
- this 0x10FC: set to 0 after release — becomes null until re-allocated externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540760 | sub_540760 | cleanup helper called unconditionally before sub-object release |

**Guard conditions:** if this[1087] (offset 0x10FC) non-null → proceed with vtable release call and null the pointer. If null → skip, return 0.
