## FileOpenWrapperWithModeCheck_00491ee0 — Open audio file read/write streams

**Summary:** Opens file read stream ("rb" mode) and optionally write stream ("wt" mode) for audio buffering. If write mode flag at this+410 is set but write stream creation fails, clears the flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4944A0 (004944a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Read stream handle |
| this | 0x4 | RW | — | Write stream handle |
| this | 0x19A | RW | 0 | Write-mode enable flag (byte at offset 410) |

**Written-by note (persistence):**
- this 0x0: unconditional, set to result of sub_534B00 (file open)
- this 0x4: conditional, set to write stream only if flag at this+0x19A is set
- this 0x19A: conditional, cleared to 0 if write flag set but write stream creation failed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |
| 005c302c | aWt | R | ModeString_wt [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534b00 | sub_534B00 | Opens file with specified mode, returns read stream handle |
| 00535390 | AudioStreamBufferRead | Reads/initializes audio stream buffer from read stream |
| 00587db0 | sub_587DB0 | Opens file with specified mode, returns write stream handle |
| 00587f64 | sub_587F64 | Configures write stream (seeks or sets buffer position) |

**Guard conditions:** If byte at this+0x19A is zero, write stream creation is skipped entirely. If read stream handle (this[0]) is null, AudioStreamBufferRead is skipped.
