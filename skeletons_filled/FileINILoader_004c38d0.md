## FileINILoader_004c38d0 — TextureFilenameProcessor

**Summary:** Extracts the filename from a file path, strips the extension, appends ".tga", and scans for matching TGA texture files via TGATextureFileScanner. Stores the scanner result at this+0x420. Cleans up scanner's linked list output. Handles null paths with default directory fallback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehFileParser (004c3200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | input file path string pointer, read to extract filename |
| this | 0x420 | RW | — | TGA texture scanner result value, written after scan |

**Written-by note (persistence):**
- this 0x420: set to scanner result unconditionally — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d306c | dword_5D306C | R | ExtensionSuffixData [DERIVED] |
| 005d3070 | byte_5D3070 | R | FileExtensionDot [DERIVED] — "." used to find extension delimiter |
| 005ea438 | byte_5EA438 | R | default application directory, fallback when input path is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c3a00 | TGATextureFileScanner | scan for TGA texture files matching filename |
| 00587bcf | FreeWrapper_7bcf | deallocate memory (scanner output list nodes) |

**Guard conditions:** If input path pointer at this+0 is null, falls back to default directory. Filename extraction loops have bounds checks (don't go before buffer start). Scanner output linked list is cleaned up if non-null; each node's data pointer at node+0 and ownership flag at node+8 guard the per-node cleanup.
