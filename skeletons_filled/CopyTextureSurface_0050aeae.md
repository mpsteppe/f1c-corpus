## CopyTextureSurface_0050aeae — CopyTextureSurfaceToBuffer

**Summary:** Copies a source texture surface into a destination buffer, optionally converting vertex buffer format first. Sets completion flag on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1030 | R | — | Destination line offset index |
| this | 0x1034 | R | — | Source X coordinate passed to sub_50AB51 |
| this | 0x1040 | R | — | Source Y coordinate passed to sub_50AB51 |
| this | 0x1048 | R | — | Format conversion enable flag; if non-zero, converts source via DirectXVertexBufferFormatConversion |
| this | 0x1058 | R | — | Row width in 16-byte units (copy size) |
| this | 0x106C | R | — | Pointer to destination surface data buffer |
| this | 0x1070 | R | — | Destination start index/offset used in memcpy address calc |
| this | 0x1088 | R | — | Comparison value for channel/flip flag passed to sub_50AB51 |
| this | 0x108C | RW | 1 | Completion flag — set to 1 after successful copy |

**Written-by note (persistence):**
- this 0x108C: set to 1 once after successful memcpy; persists until externally cleared

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | Converts source vertex buffer texture format |
| 0050ab51 | sub_50AB51 | Performs surface lock/copy operation for given coordinates |

**Guard conditions:** If this[1042] (offset 0x1048, format conversion flag) is non-zero, the source pointer is replaced by converted output. If sub_50AB51 returns negative, the copy and flag set are skipped entirely.
