## CursorLoadImageALoaderWithHandleStorage_0044f540 — Load cursor image and store handle

**Summary:** Loads a cursor image file from disk using LoadImageA and stores the resulting handle in a slot-indexed array. Constructs full path from application directory + cursor filename, then appends handle to the cursor array with associated metadata zeros.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44F4E0 (0044f4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | R | — | Cursor image count/index — selects slot in handle array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2a8 | LoadImageA | R | Windows LoadImageA import — loads cursor bitmap from file |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec408 | dword_5EC408 | R | OverridePathPtr [DERIVED] (also: ` — override path pointer (docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | Builds full cursor path via sprintf-like format with overflow guard |

**Guard conditions:** none — no conditional early exit; path built and image loaded unconditionally. Handle storage guarded only by LoadImageA success.
