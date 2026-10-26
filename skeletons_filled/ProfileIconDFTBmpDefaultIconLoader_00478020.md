## ProfileIconDFTBmpDefaultIconLoader_00478020 — Load default profile icon BMP with fallback

**Summary:** Loads profile icon BMP from custom path (or default directory), falls back to "ProfileIcon_DFT.bmp" if first load fails, stores loaded object, then sets success/failure status via virtual notification function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3C | R | — | virtual notification function (set success=1 / failure=0) |
| this | 0x0 | R | — | vtable pointer |
| this | 0x40 | R | — | pointer to file-system/loader sub-object |
| this | 0x144 | R | — | loaded-object handle (non-zero = load succeeded) |
| this | 0x158 | R | — | custom icon file path override (null = use default dir) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c66f8 | aProfileiconDft | R | DefaultProfileIconPath [DERIVED] (also: ` — "ProfileIcon_DFT.bmp" default icon) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00497ad0 | sub_497AD0 | load BMP resource from file path |
| 00499b80 | ObjectFieldInitWithIndirectLookup | store loaded object reference into instance field |

**Guard conditions:** this+0x158 (custom path) — if non-null use it, else use byte_5EA438. If sub_497AD0 returns null with first path, retry with aProfileiconDft. If this+0x144 (loaded handle) is non-zero after loading, virtual notification with arg=1 (success); else arg=0 (failure).
