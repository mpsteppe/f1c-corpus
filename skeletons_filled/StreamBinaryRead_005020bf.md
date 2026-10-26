## StreamBinaryRead_005020bf — StreamBinaryRead

**Summary:** Reads `a3` bytes from a tracked buffer into `a2`, advances read pointer, decrements remaining count. If insufficient bytes remain, triggers error via GuardedCallWithLongjmp.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x0 | RW | — | Current buffer read position (advanced by a3) |
| *(this+0x54) | 0x4 | RW | — | Remaining bytes (decremented by a3) |
| this | 0x54 | R | — | Pointer to buffer tracking struct |

**Written-by note (persistence):**
- *(this+0x54) 0x0: Written each call — advanced by a3; persists until next read
- *(this+0x54) 0x4: Written each call — reduced by a3; persists until next read

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005adb4c | aReadError | R | ReadErrorString [DERIVED] — "read error" string passed to longjmp handler |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00511869 | GuardedCallWithLongjmp | Error handler: longjmp with "read error" message if buffer underflow |

**Guard conditions:** If a3 > remaining bytes (*(v3+4)) → trigger longjmp error via GuardedCallWithLongjmp. Otherwise copy bytes and advance.
