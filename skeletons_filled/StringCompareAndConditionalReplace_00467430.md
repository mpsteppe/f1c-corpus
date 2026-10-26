## StringCompareAndConditionalReplace_00467430 — StringCompareAndConditionalReplace

**Summary:** Compares a new string against the current string buffer; if different, copies the new string (with size limit) and updates the position tracking, then calls a vtable method to signal the change. Belongs to menu option text display system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuOptionValueDisplay (004673b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | vtable offset 44: method to invoke after string replacement |
| this | 0x0 | R | — | vtable pointer |
| this | 0x2F0 | R | — | pointer to current string buffer (this[188]) |
| this | 0x2F4 | RW | — | current position pointer in string (updated to end after replace) |
| this | 0x2F5 | R | — | unknown status byte |
| this | 0x2F8 | R | — | buffer size limit (this[190]); used as max copy length minus 1 |

**Written-by note (persistence):**
- this 0x2F4: written to point to start of buffer, then advanced to null terminator. Resets on every replace; external poke would be overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | copies string with size limit into the buffer |

**Guard conditions:** If a2 (new string) is NULL, returns -1 early (BLOCKED). If strcmp shows strings are equal, returns -1 early (BLOCKED). Only proceeds with replacement when strings differ and a2 is non-null (PASSES).
