## StaticArrayCleanup_0049b1c0 — UIRenderWidgetArrayCleanup

**Summary:** Iterates the four-element dword_7CE23C widget pointer array, destructing and freeing each non-null entry, then zeroing the slot. Called during UI shutdown/teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** OnScreen_Post (0049f0d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce23c | dword_7CE23C | R | UIRenderFlags [DERIVED] |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dcd10 | ResourceCleanup_cd10 | Widget/UI resource destructor |
| 00587bcf | FreeWrapper_7bcf | Heap deallocation for widget object |

**Guard conditions:** Entry at [v0] is NULL → BLOCKED from cleanup, skip to next entry. Non-null → PASSES: double ResourceCleanup_cd10 + FreeWrapper_7bcf + zero.
