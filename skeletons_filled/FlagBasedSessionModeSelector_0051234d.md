## FlagBasedSessionModeSelector_0051234d — Select single or multi session mode by flag

**Summary:** Returns 1 (single session mode) when the selector byte at offset 0x113 is zero; otherwise sets bit 2 on flags DWORD and returns 7 (multi-session mode count).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_511F23 (00511f23)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | — | flags DWORD; bit 2 set when multi-session mode active |
| this | 0x113 | R | — | session mode selector byte (0 = single, non-zero = multi) |

**Written-by note (persistence):**
- this 0x60: OR-write sets bit 2 when entering multi-session mode; persists until cleared

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks byte at offset 0x113. If 0 (PASS to single mode), returns 1 without modifying flags. If non-zero (multi mode), sets bit 2 on flags and returns 7.
