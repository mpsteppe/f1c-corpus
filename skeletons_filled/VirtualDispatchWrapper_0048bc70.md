## VirtualDispatchWrapper_0048bc70 — ActiveFocusAndVTable43

**Summary:** Dispatches active-focus toggle via UIActiveStateToggle then calls vtable[43] virtual method. Simple wrapper with no branching.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xAC | R | — | VTable entry 43 (offset 172) — called after focus toggle |
| this | 0x0 | R | — | VTable pointer (to read obj+0xAC) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048bbe0 | UIActiveStateToggle | Toggles active/focused state of this widget |

**Guard conditions:** No guards — always executes both calls unconditionally.
