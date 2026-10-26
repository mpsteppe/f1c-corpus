## ScreenMenuNavigationController_00470040 — MenuNavigationWithModeCheck

**Summary:** Navigates UI menu: reads session flag pointer at 0xE8, checks RaceMode (dword_7D0410), selects UI list index (0/1/2) based on mode and flag value, copies selected string, and dispatches navigation via vtable function. Returns null if session flag pointer is null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | vtable function at offset 64 — navigation dispatch call |
| this | 0x0 | R | — | vtable pointer (read for dispatch) |
| this | 0xE0 | RW | 2 | UI list index selector (set to 0, 1, or 2) |
| this | 0xE8 | R | — | session flag pointer (checked for null before navigation) |

**Written-by note (persistence):**
- this 0xE0: set per navigation selection each call; previous value overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] — compared to 3 and 5 to select navigation branch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | get UI list element by index (0, 1, or 2) |
| 00566650 | StringCopyWithBufferRealloc | copy string into buffer at this+59 with reallocation |

**Guard conditions:** Guard 1: this[58] (offset 0xE8) must be non-null; if null, function returns null early. Guard 2: dword_7D0410 (RaceMode) == 3 or 5 selects the inner navigation branch vs fallback (sets index=2). Guard 3: within inner branch, *result byte at pointer is checked; non-zero → index 1, zero → index 0.
