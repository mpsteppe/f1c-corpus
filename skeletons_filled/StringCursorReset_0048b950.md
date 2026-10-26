## StringCursorReset_0048b950 — EditCursorResetWithDefault

**Summary:** Resets edit text cursor. When a2!=0: clears buffer and reloads default string from this+0x1E7. When a2==0: moves cursor to end of current buffer content. Calls vtable[11] update in non-default mode.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | unknown |
| this | 0x0 | R | — | VTable pointer |
| this | 0x2F0 | RW | 0 | Buffer start pointer (set to 0 when clearing in a2!=0 mode) |
| this | 0x2F4 | RW | — | Cursor position pointer (reset to buffer start or end) |

**Written-by note (persistence):**
- this 0x2F0: content at buffer pointer cleared (first byte set to 0). Buffer state.
- this 0x2F4: updated to new cursor position. Volatile — cursor state.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048b810 | EditBufferStringUpdate | Loads default string from this+0x1E7 into edit buffer |

**Guard conditions:** If a2==0: cursor moves to end of current string, vtable[11] update called. If a2!=0: buffer is cleared, cursor reset to start. Then default string at this+0x1E7 is loaded into buffer only if its length != 1 (skip single-char default). No values blocked — both paths execute.
