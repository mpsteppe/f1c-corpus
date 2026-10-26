## NetworkSocketArrayCleanup_00563dc0 — CloseSocketArray

**Summary:** Iterates over the socket array (28-byte stride, count at this+0x6C, base at this+0x8) and closes each socket via closesocket().

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_563AB0 (00563ab0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | pointer to socket array base (28-byte stride, entry+0 = socket handle) |
| this | 0x6C | R | — | number of socket entries in array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059865a | closesocket | close each UDP socket handle |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x6C | > | 0 | socket count |

**Guard interpretation:** this+0x6C > 0 enters the loop to close all sockets. If <= 0, skip (no sockets to close).

