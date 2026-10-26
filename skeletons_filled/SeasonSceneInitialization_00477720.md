## SeasonSceneInitialization_00477720 — SeasonSceneInitializer

**Summary:** Orchestrates season scene initialization: performs path-based and name-based scene searches, copies match index, traverses linked list for GameFilterDataPath match, then recalculates viewport layout.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xF0)+0x3C) | 0x0 | R | — | first byte of path string from first list node |
| *(this+0xF0) | 0x3C | R | — | path string pointer from first list node |
| obj | 0xA0 | R | — | unknown field from UtilityFunction_7810 result |
| this | 0x0 | R | — | vtable pointer (virtual call at offset 160) |
| this | 0xF0 | R | — | linked list head pointer |
| this | 0xF8 | RW | — | linked list traversal cursor |
| this | 0xFC | R | — | bound/limit for list |
| this | 0x174 | RW | — | match result index (set by list traversal or SeasonSceneSearchByName) |
| this | 0x184 | RW | — | copied from name search match result (v4[93]) |

**Written-by note (persistence):**
- this 0xF8: set to list head at start, updated each iteration; persists until next call
- this 0x174: set by SeasonSceneSearchByName or list traversal match; persists until next call
- this 0x184: set once from v4[93]; persists until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00476660 | SeasonPathMatchSearch | searches linked list for season path match |
| 00476ec0 | SeasonSceneSearchByName | searches linked list for scene name match |
| 00477810 | UtilityFunction_7810 | retrieves tracked state object for name search |

**Guard conditions:** `dword_7CD8C0` dispatch(20) must return non-null → path search proceeds; `UtilityFunction_7810` must return non-null → name search and index copy proceed; linked list head `this[60]` (offset 0xF0) must be non-null → string comparison traversal proceeds; `strcmp` between node path at offset 0x3C and `dword_7CE64C` must return 0 → store match index
