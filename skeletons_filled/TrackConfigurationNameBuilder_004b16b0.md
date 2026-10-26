## TrackConfigurationNameBuilder_004b16b0 — TrackConfigurationNameBuilder

**Summary:** If track name at this+0x2D50 is non-empty, calls NameCompareAndFormat to load season data/audio for the track, then copies default directory. If config name at this+0x2D6C is non-empty, copies three additional path strings from object fields at offsets 0x2D5C, 0x2D64, 0x2D6C and default directory into reallocated buffers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionStateByte7CE25FSetter (00464600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2D50 | R | — | track name string (this[11600/4]) |
| this | 0x2D5C | R | — | 2nd path string for config (this[11612/4]) |
| this | 0x2D64 | R | — | 3rd path string for config (this[11620/4]) |
| this | 0x2D6C | R | — | config name string (this[11628/4]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b1410 | NameCompareAndFormat | compares track name, loads season data and audio |
| 00566650 | StringCopyWithBufferRealloc | copies string into reallocated buffer |

**Guard conditions:** Two-level guard:
1. If track name at this+0x2D50 is empty (strlen == 0), skip track name processing entirely.
2. If config name at this+0x2D6C is empty, skip config path string copying and return 0.
Both must have content for their respective processing blocks to execute.
