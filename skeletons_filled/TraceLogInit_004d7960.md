## TraceLogInit_004d7960 — TraceLogInit

**Summary:** Initializes trace logging to "trace.txt" in weather/season directory. Clamps trace level (this+0x0) to max 2, opens file for writing, writes header line with level. If file already open, just writes header. Called by sub_4D7A00.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D7A00 (004d7a00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | trace level (clamped to 0-2; 0 = disabled) |
| this | 0x4 | RW | — | file handle/pointer to open trace.txt file |

**Written-by note (persistence):**
- this 0x0: conditionally set to 0 if file open fails, clamped to max 2 otherwise
- this 0x4: conditionally set to file handle on successful open

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c680c | aW | R | file mode string "w" (write) |
| 005d4a04 | aTraceLevelD | R | header format string "trace level %d" |
| 005d4a18 | aStraceTxt | R | path format string "%strace.txt" |
| 005ea438 | byte_5EA438 | R | default application directory (fallback) |
| 005ec438 | dword_5EC438 | R | weather/season directory path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587db0 | sub_587DB0 | file open function (mode "w") |
| 0058815f | StringFormatWithBufferOverflowCheck | safe snprintf for path construction |
| 005887b1 | StringFormatWithNestedIO | formatted write to file (fprintf-like, writes header) |
| 00589671 | CreateDirectoryAWrapper | creates directory for trace file if not exists |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | trace level enabled flag |

**Guard interpretation:** PASSES (init proceeds) when this+0x0 > 0 — trace enabled. BLOCKED (early return, no file created) when this+0x0 <= 0 — trace disabled.
