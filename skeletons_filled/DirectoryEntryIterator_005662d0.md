## DirectoryEntryIterator_005662d0 — build full path from directory entry

**Summary:** Constructs full file path by concatenating base directory (at data+0x144) with entry name (at data+48) into buffer at list_head+16. If flag at list_head+0x218 is set, normalizes path via sub_566810. Returns pointer to constructed path or 0. File/resource enumeration subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceListCleanup (00404d50), Game_Enter (0042d370), sub_45C0C0 (0045c0c0), PlayerProfileScanner (00468ee0), ProfileBitmapBrowser (00477cb0), PlayerNameNeverUsedProfileFileCreateRead (004b03f0), TGATextureFileScanner (004c3a00), VehicleFileLoader (004c3d80), SceneFileLoader (004c52c0), sub_4C84A0 (004c84a0), TireBrandLoader (004d7660), ReversePathSearchForBackslashSeparator (00565ef0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x8)+0x0) | 0x144 | R | — | base directory path from entry data |
| *(obj+0x8) | 0x0 | R | — | entry data pointer (directory entry info) |
| obj | 0x8 | R | — | current node pointer (enumeration cursor) |
| obj | 0x210 | R | — | additional path/filter string pointer |
| obj | 0x218 | R | — | flag: whether to normalize path via sub_566810 |
| this | 0x0 | R | — | pointer to list head structure |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | "%s%s" format string for path concatenation |
| 005ea438 | byte_5EA438 | R | default application directory (fallback base path) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566810 | sub_566810 | path normalization / relative path resolution |
| 0058815f | StringFormatWithBufferOverflowCheck | safe string concatenation with overflow protection |

**Guard conditions:** If node pointer (obj+0x8) == NULL → return 0. If data pointer *(obj+0x8) == NULL → return 0. If flag at list_head+0x218 == 0 → skip path normalization, return buffer directly. If sub_566810 returns 0 → return 0.
