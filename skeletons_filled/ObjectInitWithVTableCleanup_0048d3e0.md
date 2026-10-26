## ObjectInitWithVTableCleanup_0048d3e0 — VTableResetAndCleanup

**Summary:** Resets the vtable pointer to off_5AC1D0 (UIWidgetVTable), then calls sub_485EB0 for further cleanup/teardown. Appears in destructor sequences.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithVTableReset (00479e50), ConditionalDestructorWithVTable (0047a230), DestructorWithSubCallAndConditionalFree_c7f0 (0047c7f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer, reset to off_5AC1D0 |

**Written-by note (persistence):**
- this 0x0: set every call; survives external poke (vtable restoration in destructor)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac1d0 | off_5AC1D0 | R | UIWidgetVTable_5AC1D0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes.
