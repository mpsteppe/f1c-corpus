## DestructorWithVTableReset_aa80_0047aa80 — SeasonDBObjectDestructor

**Summary:** Destructor for season database object: resets vtable to off_5A66E0, calls sub_485EB0 for cleanup, then conditionally frees object memory when flag bit 0 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer (reset to off_5A66E0) |

**Written-by note (persistence):**
- this 0x0: Written once with vtable pointer; persists until object freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a66e0 | off_5A66E0 | R | Vtable pointer for this season database object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485eb0 | sub_485EB0 | Performs cleanup (likely destructor chain or resource release) |
| 00587bcf | FreeWrapper_7bcf | Frees heap-allocated object memory |

**Guard conditions:** Checks `a2 & 1` — if bit 0 is set, calls FreeWrapper_7bcf (free memory). If clear, skips free.
