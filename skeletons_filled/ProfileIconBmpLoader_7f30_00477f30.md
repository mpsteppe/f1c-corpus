## ProfileIconBmpLoader_7f30_00477f30 — Load ProfileIcon.bmp file path builder

**Summary:** Builds absolute path to "ProfileIcon.bmp" by getting base directory via virtual function + virtual path utility, then appending the BMP filename and storing result via string copy routine.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3C | R | — | virtual function (user data / base path provider) |
| this | 0x0 | R | — | vtable pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6950 | aProfileiconBmp | R | ProfileIconBmpStr [DERIVED] (also: ` — "ProfileIcon.bmp" string) |
| 005c6954 | byte_5C6954 | R | StrProfileIconBmp [DERIVED] |
| 005c6958 | byte_5C6958 | R | StrProfileIconBMP [DERIVED] |
| 005c695c | byte_5C695C | R | String_ProfileIconBmp [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0220 | PathTruncationUtility | compute base directory path (truncated to 128 chars) |
| 00566650 | StringCopyWithBufferRealloc | allocate and copy combined path string |

**Guard conditions:** None — always executes full path construction then exits.
