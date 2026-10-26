## CloseHandlePairWrapper_00583aa0 — CloseTwoHandlesWithFlags

**Summary:** Closes two kernel handles (guarded by per-handle validity flags), clearing each handle field to 0 on success. Thin wrapper around CloseHandle API.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | second HANDLE (cleared to 0 after close) |
| this | 0x14 | R | — | flag: second handle is valid (= non-zero) |
| this | 0x1C | RW | 0 | first HANDLE (cleared to 0 after close) |
| this | 0x24 | R | — | flag: first handle is valid (= non-zero) |

**Written-by note (persistence):**
- this 0xC: cleared to 0 if flag at 0x14 non-zero AND CloseHandle succeeds
- this 0x1C: cleared to 0 if flag at 0x24 non-zero AND CloseHandle succeeds

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a8 | CloseHandle | R | kernel32 CloseHandle function pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Flag at this+0x24 must be non-zero to attempt closing first handle. Flag at this+0x14 must be non-zero to attempt closing second handle. Each close also guards on CloseHandle return (non-zero = success) before clearing handle field to 0.
