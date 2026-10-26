## UIClassConstructor_004db090 — AudioFilterDestructor

**Summary:** Destructor/disposer for audio filter objects. Sets vtable pointer to off_5AD06C and optionally frees object memory when `a2 & 1` flag is set. Part of object lifecycle management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer set to off_5AD06C (AudioFilterVtable) |

**Written-by note (persistence):**
- this 0x0: Written once (vtable); object freed if `a2 & 1` is set

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad06c | off_5AD06C | R | AudioFilterVtable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Frees heap-allocated object memory |

**Guard conditions:**
- Line 4: `a2 & 1` is non-zero. PASS: call FreeWrapper_7bcf to free object. BLOCK: skip free (object ownership retained by caller).
