## PlacementDeleteDispatcher_005831b0 — PlacementDeleteDispatcherWithVTable

**Summary:** Dispatches destruction based on flag bits. When bit 2 is set, treats object as placement-allocated with count header, calls NTimeCallbackLoopWithSEH with 308-byte entries and SingleVTablePointerSet callback, then optionally frees from header. When bit 2 is clear, calls SingleVTablePointerSet directly then optionally frees. Bit 1 controls memory deallocation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0057bc70 | SingleVTablePointerSet | R | Destructor/callback — sets vtable pointer or processes single entry |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057bc70 | SingleVTablePointerSet | Process object destructor per entry or directly |
| 00587bcf | FreeWrapper_7bcf | Free object memory (regular pointer or header pointer) |
| 0058a5f7 | NTimeCallbackLoopWithSEH | Process all entries in placement-allocated block with SEH |

**Guard conditions:** Checks a2 bit 2 (placement flag) — if set, uses header-relative addressing and bulk NTimeCallbackLoopWithSEH. If clear, calls SingleVTablePointerSet directly on pointer.
