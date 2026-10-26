## TickCountComparisonHandleInactivityTimeout_00561ed0 — InactivityTimeoutHandler

**Summary:** Track inactivity timeout using GetTickCount. If last activity timestamp is non-zero and elapsed time is within valid range (<=300s), check 30s threshold to increment retry counter (capped at 10). On timeout, reset through sub_562AC0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringLengthCheckDispatch (0045d4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Identifier/socket field: if -1, skip timeout check |
| this | 0xD8 | R | — | Last activity timestamp (GetTickCount value) |
| this | 0xE8 | RW | 0 | Retry counter (incremented on timeout, capped at 10) |

**Written-by note (persistence):**
- this 0xE8: incremented on each timeout event, reset to 0 when flag at 0xE8 is >0 on entry

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00562ac0 | sub_562AC0 | Reset/resend action on timeout (called with arg 0) |
| 00564640 | GetTickCount | Get current system tick count |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | != | -1 (0xFFFFFFFF) | Socket/connection is valid; skip check if invalid |

**Guard interpretation:** this[1] (offset 0x4) must not be -1 to proceed with timeout logic. When -1, no timeout tracking is performed.
