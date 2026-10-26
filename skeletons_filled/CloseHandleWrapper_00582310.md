## CloseHandleWrapper_00582310 — Conditional handle close wrapper

**Summary:** Checks byte flag at this+0x18. If set, calls CloseHandle on handle at this+0x10. On success, zeros the handle field. Returns the CloseHandle result (0=fail, non-zero=success).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BCE0 (0057bce0), sub_583AE0 (00583ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | 0 | Handle field; closed via CloseHandle then zeroed on success |
| this | 0x18 | R | — | Byte flag: non-zero means CloseHandle should be attempted |

**Written-by note (persistence):**
- this 0x10: Zeroed after successful CloseHandle. Survives unchanged if flag is 0 or CloseHandle fails.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a8 | CloseHandle | R | Close the handle at this+0x10 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks byte at this+0x18. If zero, skips CloseHandle entirely and returns the flag value. If non-zero, calls CloseHandle(this+0x10); zeros handle only if CloseHandle returns success (non-zero).
