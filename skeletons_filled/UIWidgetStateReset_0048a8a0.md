## UIWidgetStateReset_0048a8a0 — Widget state/reset zeroing

**Summary:** Resets widget state: zeros 3 byte fields (0x144-0x146), zeroes integer field at 0x148, calls vtable method at offset 64 to disable/hide, then calls vtable method at offset 156 for refresh.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | vtable method offset 64 — disable/hide widget (called with arg 0) |
| obj | 0x9C | R | — | vtable method offset 156 — refresh/update after reset |
| this | 0x0 | R | — | vtable pointer |
| this | 0x144 | RW | 0 | byte flag 1 — zeroed on every call |
| this | 0x145 | RW | 0 | byte flag 2 — zeroed on every call |
| this | 0x146 | RW | 0 | byte flag 3 — zeroed on every call |
| this | 0x148 | RW | 0 | this[82] — state integer field, zeroed on every call |

**Written-by note (persistence):**
- this 0x144: zeroed on every call unconditionally
- this 0x145: zeroed on every call unconditionally
- this 0x146: zeroed on every call unconditionally
- this 0x148: zeroed on every call unconditionally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — runs unconditionally every call.
