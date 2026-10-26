## DualVtableDestructor_004db4e0 — DualVtableDestructor

**Summary:** Two-stage destructor: switches vtable to off_5AD0DC, frees child object pointer at offset 0x10 if non-null, switches vtable to off_5AD06C, then optionally frees self if a2&1. Part of object lifecycle management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer (switched from off_5AD0DC to off_5AD06C during destruction) |
| this | 0x10 | R | — | Pointer to child/sub-object to free during destruction |

**Written-by note (persistence):**
- this 0x0: Written twice (vtable switch); final value is off_5AD06C; persists only until FreeWrapper_7bcf if a2&1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad06c | off_5AD06C | R | AudioFilterVtable [DERIVED] — second/post-destruction vtable |
| 005ad0dc | off_5AD0DC | R | First/destructor-phase vtable, used before child cleanup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Frees heap-allocated memory (child object and optionally self) |

**Guard conditions:**
- Line 4: `this[4]` (child pointer at offset 0x10) is non-null. PASS: call FreeWrapper_7bcf to free child. BLOCK: skip child cleanup.
- Line 7: `(a2 & 1)` is non-zero. PASS: free this object (self-deletion). BLOCK: skip self-free.
