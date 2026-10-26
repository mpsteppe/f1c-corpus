## SockAddrPairInit_0057b910 — InitDualSocketAddresses

**Summary:** Initializes two socket address structures (first at offset 0, second at offset 0x10) with AF_INET family, zero IP and zero port in network byte order. Returns the port value (0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SocketAddressInitialization (0057b8c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 2 | first address family (set to AF_INET) |
| this | 0x2 | RW | — | first port (set to 0 via htons) |
| this | 0x4 | RW | — | first IP address (set to 0 via htonl) |
| this | 0x10 | RW | 2 | second address family (set to AF_INET) |
| this | 0x12 | RW | — | second port (set to 0 via htons) |
| this | 0x14 | RW | — | second IP address (set to 0 via htonl) |

**Written-by note (persistence):**
- this 0x0: unconditionally set to 2 per call; external poke does not survive reinit
- this 0x2: unconditionally set to 0 per call; external poke does not survive reinit
- this 0x4: unconditionally set to 0 per call; external poke does not survive reinit
- this 0x10: unconditionally set to 2 per call; external poke does not survive reinit
- this 0x12: unconditionally set to 0 per call; external poke does not survive reinit
- this 0x14: unconditionally set to 0 per call; external poke does not survive reinit

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2d8 | __imp_htonl | R | convert IP address to network byte order |
| 0059e2f4 | __imp_htons | R | convert port to network byte order |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes unconditionally.
