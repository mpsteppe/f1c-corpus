## UIStringComparison_e250_0048e250 — BinkVideoRenderOrReload

**Summary:** Compares two stored path strings (this+0xB0 and this+0xE8). If they match and resources are loaded, renders a Bink video frame (via BinkVideoFrameRender) and signals update. If paths differ, calls vtable+160 to reload/reinitialize the video.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Vtable offset 44 — signal content changed |
| obj | 0xA0 | R | — | Vtable offset 160 — reload/reinit method |
| this | 0x0 | R | — | Vtable pointer |
| this | 0x4 | R | — | Render destination Y (this[1]) |
| this | 0xC | R | — | Render destination X (this[3]) |
| this | 0xB0 | R | — | Expected path string (this[44]) |
| this | 0xE0 | R | — | Video resource handle (this[56]), checked for non-null |
| this | 0xE4 | R | — | Video resource pointer (this[57]), checked for loaded state |
| this | 0xE8 | R | — | Current/loaded path string (this[58]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00495150 | GlobalAccessor_5150 | Get global render surface/context |
| 00551cf0 | BinkVideoFrameRender | Render a frame of Bink video |

**Guard conditions:** PASS: strcmp(paths match) AND this+0xE4 (pointer) is non-null AND this+0xE0 (handle) is non-null → render frame. BLOCKED: paths don't match → call vtable+160 (reload). BLOCKED path-match but resource not loaded → skip (no render).
