## NetworkSocketAddressInit_0057f0c8 — socket address init and connection attempt

**Summary:** Initializes sockaddr_in struct (AF_INET), parses IP string via inet_addr, sets port from context field, constructs network packet, and issues thread-safe connection call. Returns 1 on invalid IP (error path via vtable).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48 | R | — | Pointer passed to NetworkPacketConstructor (context/socket field) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2d8 | __imp_htonl | R | Convert INADDR_ANY to network byte order |
| 0059e2f0 | __imp_inet_addr | R | Parse IP address string to binary |
| 0059e2f4 | __imp_htons | R | Convert port to network byte order |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057afa0 | NetworkPacketConstructor | Construct connection packet from address |
| 00584c70 | ThreadSafeCallWithMutex | Issue thread-safe connection call |

**Guard conditions:**
- If `a3` (sockaddr buffer) is NULL → skip init, a3 stays 0
- If inet_addr returns -1 (invalid IP string) → call error handler via vtable+92 and return 1 (error path)
