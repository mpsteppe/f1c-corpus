## ConditionalDestructorWithVTable_0047a230 — ConditionalDestructorWithVTableReset

**Summary:** Destructor: resets vtable pointer to off_5A6068, calls ObjectInitWithVTableCleanup for virtual cleanup, then conditionally frees object memory when flag bit 0 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer (reset to off_5A6068) |

**Written-by note (persistence):**
- this 0x0: Written once with vtable pointer; persists until object freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a6068 | off_5A6068 | R | Vtable pointer for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048d3e0 | ObjectInitWithVTableCleanup | Performs virtual-call cleanup (likely destructor chain via vtable) |
| 00587bcf | FreeWrapper_7bcf | Frees heap-allocated object memory |

**Guard conditions:** Checks `a2 & 1` — if bit 0 is set, calls FreeWrapper_7bcf (free memory). If clear, skips free.
