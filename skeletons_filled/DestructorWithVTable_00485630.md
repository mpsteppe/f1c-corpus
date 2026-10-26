## DestructorWithVTable_00485630 — Dtor_5AB080

**Summary:** Destructor for object with vtable at 0x5AB080: sets vtable, calls InitWithVTableCleanup for common cleanup, then optionally frees self if a2 & 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer set to off_5AB080 |

**Written-by note (persistence):**
- this 0x0: set at entry; overwritten by InitWithVTableCleanup chain

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ab080 | off_5AB080 | R | vtable pointer for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487250 | InitWithVTableCleanup | common destructor/cleanup dispatcher, resets vtable and frees sub-objects |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions:** No field-based guards; only the a2 flag controls self-deallocation.
