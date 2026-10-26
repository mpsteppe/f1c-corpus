## NetworkConnectionThread_0057fc80 — network connection thread (TCP+UDP socket init)

**Summary:** Thread entry: calls virtual init, zeros socket handles, initializes Winsock, destroys first linked list (at 0xAC8) under mutex, signals a flag at 0xB38, creates TCP (type=1) and UDP (type=2) sockets, configures both via TCPSocketInit, and marks thread ready (0xA75=1). Returns 0 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xAC8)+0x0)+0x0) | 0x0 | R | — | Head node → data pointer → first DWORD of data (triple indirect) |
| *(*(this+0xAC8)+0x0) | 0x0 | R | — | Head node data pointer (double indirect) |
| *(this+0xAC8) | 0x0 | R | — | Head node first DWORD (data pointer) |
| *(this+0xAC8) | 0x8 | R | — | Head node byte flag at +8 |
| obj | 0x4C | R | — | Vtable entry at +76 (thread init callback) |
| this | 0x0 | R | — | Vtable pointer for thread init dispatch |
| this | 0x938 | RW | -1 (0xFFFFFFFF) | TCP socket handle |
| this | 0x93C | RW | -1 (0xFFFFFFFF) | UDP socket handle |
| this | 0xA75 | RW | 1 | Byte ready flag: 1 = initialized successfully |
| this | 0xAC8 | RW | 0 | First list head pointer (zeroed after destroy) |
| this | 0xACC | RW | 0 | First list tail pointer (zeroed) |
| this | 0xAD0 | RW | 0 | First list cursor (zeroed) |
| this | 0xAD4 | RW | 0 | First list count (zeroed) |
| this | 0xAD8 | R | — | First list mutex handle |
| this | 0xADC | R | — | First list mutex timeout |
| this | 0xB38 | RW | 1 | Thread alive/active flag (set to 1 to signal readiness) |
| this | 0xB3C | R | — | Second mutex handle (protects signal flag) |
| this | 0xB40 | R | — | Second mutex timeout |

**Written-by note (persistence):**
- this 0x938: written with socket handle or -1; invalidated on cleanup
- this 0x93C: written with socket handle or -1; invalidated on cleanup
- this 0xA75: set to 1 on success; cleared to 0 before init; persists across thread life
- this 0xAC8: zeroed after list destroyed; empty until next allocation
- this 0xACC: zeroed after list destroyed
- this 0xAD0: zeroed after list destroyed
- this 0xAD4: zeroed after list destroyed
- this 0xB38: set to 1 on signal; persists until next thread cycle

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on both mutexes during cleanup/signal |
| 0059e1a4 | ReleaseMutex | R | Release both mutexes after operations |
| 0059e2dc | __imp_socket | R | Create TCP (type=1) and UDP (type=2) sockets |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057c860 | TCPSocketInit | Initialize TCP (flag=0) and UDP (flag=1) socket options |
| 0057fb90 | WinsockInit | Initialize Winsock via WSAStartup |
| 00585470 | sub_585470 | Post-init callback |
| 00587bcf | FreeWrapper_7bcf | Free list nodes during first-list destruction |

**Guard conditions:**
- If WinsockInit returns 0 → return 6 (failure)
- If first mutex handle is null or wait fails → skip first list cleanup (v4=0, potential null deref risk)
- If TCP socket (this+0x93C) is INVALID_SOCKET or UDP socket (this+0x938) is INVALID_SOCKET → skip TCPSocketInit
- If either TCPSocketInit fails → skip setting ready flag (0xA75 stays 0)
