## FlaggedDestructor_00583150 — FlaggedDestructorWithTimerCleanup

**Summary:** Dispatches destruction of an object based on flag bits. When bit 2 is set, treats object as placement-allocated (has prepended count header), calls NTimeCallbackLoopWithSEH with 40-byte entries and sub_57AEF0 callback, then optionally frees from header. When bit 2 is clear, calls sub_57AEF0 directly then optionally frees. Bit 1 controls whether memory is freed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0057aef0 | sub_57AEF0 | R | Destructor/callback function — called per entry or directly on object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057aef0 | sub_57AEF0 | Object destructor — called on each entry or directly |
| 00587bcf | FreeWrapper_7bcf | Free object memory (regular pointer or header pointer) |
| 0058a5f7 | NTimeCallbackLoopWithSEH | Process all entries in placement-allocated callback block with SEH |

**Guard conditions:** Checks a2 bit 2 (placement flag) — if set, uses header-relative addressing and bulk cleanup. If clear, calls destructor directly on pointer.
