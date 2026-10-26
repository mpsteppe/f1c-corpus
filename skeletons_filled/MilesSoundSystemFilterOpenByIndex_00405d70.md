## MilesSoundSystemFilterOpenByIndex_00405d70 — AudioFilterOpenByIndex

**Summary:** Opens a Miles audio filter by index (0-3) — looks up filter name string via sub_404FA0, enumerates Miles filters to find a match, opens the matching filter via AIL_open_filter, and stores filter handles in struct fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | R | — | Pointer to audio system config (contains filter provider handle at offset 0x90) |
| this | 0x60 | RW | — | Stored filter index (a2 value) after open |
| this | 0x64 | RW | — | Stored Miles filter handle after AIL_open_filter |
| this | 0x68 | RW | — | Stored provider parameter after open |
| this | 0xE4 | R | — | Provider-specific data within this[0x54] config struct |

**Written-by note (persistence):**
- this 0x60: set after successful filter open (persists until overwritten)
- this 0x64: set after successful filter open (persists until overwritten)
- this 0x68: set after successful filter open (persists until overwritten)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3b0 | _AIL_enumerate_filters@12 | R | Enumerate available Miles audio filters |
| 0059e3b4 | _AIL_open_filter@8 | R | Open a Miles audio filter by handle |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404fa0 | sub_404FA0 | Look up filter name string by index (0-3) |

**Guard conditions:** Checks a2 < 4 (valid filter index 0-3). If >= 4 → blocked (returns 0). Then checks sub_404FA0 returns non-null name string. If null → blocked. Then checks AIL_enumerate_filters succeeds. Then iterates strcmp until match found. If no match → blocked. Then checks a2 != -1 (valid filter enum value). Then checks this[21] (offset 0x54) is non-null (config pointer must be valid). If any fails → blocked, returns 0.
