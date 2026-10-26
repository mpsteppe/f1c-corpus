## SocketAddressInit_00582110 — Socket address structure initialization

**Summary:** Initializes socket address structure: temporarily sets two sockaddr_in blocks (AF_INET=2, INADDR_ANY, port 0), resets ring buffer at offset 54 via RingBufferHeadTailReset, then zeroes all fields from offset 0 to 0x34. Sets this+0x20 to -1 (0xFFFFFFFF). Returns this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | First DWORD of socket address block; set to AF_INET(2) then zeroed |
| this | 0x2 | RW | — | Port field (WORD) of first sockaddr_in; set via htons(0) then zeroed as part of DWORD clear |
| this | 0x4 | RW | 0 | IP address field (DWORD) of first sockaddr_in; set via htonl(0) then zeroed |
| this | 0x8 | RW | 0 | Unused/zeroed padding or additional fields |
| this | 0xC | RW | 0 | Unused/zeroed padding or additional fields |
| this | 0x10 | RW | 0 | Second sockaddr_in: address family (WORD=2), then zeroed |
| this | 0x12 | RW | — | Second sockaddr_in: port field (WORD), set via htons(0) then zeroed |
| this | 0x14 | RW | 0 | Second sockaddr_in: IP field (DWORD), set via htonl(0) then zeroed |
| this | 0x18 | RW | 0 | Zeroed field |
| this | 0x1C | W | 0 | Zeroed field |
| this | 0x20 | W | -1 | State/identifier initialized to -1 (0xFFFFFFFF); survives as final state |
| this | 0x24 | W | 0 | Zeroed field |
| this | 0x28 | W | 0 | Byte field; zeroed (*((_BYTE *)this + 40) = 0) |
| this | 0x2C | W | 0 | Zeroed field |
| this | 0x30 | W | 0 | Zeroed field |
| this | 0x34 | W | 0 | WORD at offset 52; zeroed as part of final cleanup |

**Written-by note (persistence):**
- this 0x0–0x1C: Set to temporary values then zeroed. Final state = 0.
- this 0x20: Set to -1 once. Persists until modified.
- this 0x24–0x34: Zeroed. Persist until modified.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2d8 | __imp_htonl | R | Convert IP address (0) to network byte order for sockaddr_in |
| 0059e2f4 | __imp_htons | R | Convert port (0) to network byte order for sockaddr_in |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b530 | RingBufferHeadTailReset | Initialize ring buffer head/tail pointers at offset 54 (27 WORDs from start) |

**Guard conditions:** None — unconditional initialization.
