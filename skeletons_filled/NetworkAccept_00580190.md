## NetworkAccept_00580190 — NetworkAccept

**Summary:** Accepts incoming TCP connections on a listen socket (select + accept), stores accepted sockets in a mutex-guarded linked list, applies TCP_NODELAY, and processes pending connections from an internal queue. Returns a boolean activity flag indicating whether any connection event occurred.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAB4)+0x4) | 0x0 | R | — | connection list node data pointer (derefed from mutex-guarded queue head) |
| *(this+0xAAC) | 0x0 | R | — | pending connection list head pointer (checked for null to guard processing loop) |
| *(this+0xAB4) | 0x4 | R | — | pointer to next node in connection list (offset +4 from head node) |
| this | 0x938 | R | — | listen socket handle (SOCKET, used for select() and accept()) |
| this | 0x93C | R | — | secondary socket handle (passed to sub_57CB50 for per-connection processing) |
| this | 0xAAC | R | — | pending connection linked list head (v18 base address) |
| this | 0xAB4 | RW | — | mutex synchronization handle for connection queue access (may be replaced after allocation) |
| this | 0xABC | R | — | timeout value (milliseconds) for WaitForSingleObject on connection queue mutex |
| this | 0xAC0 | R | — | additional timeout/flag for connection queue mutex WaitForSingleObject |
| this | 0xBEC | R | — | mutex handle for accept-section critical section (WaitForSingleObject target) |
| this | 0xBF0 | R | — | timeout value for accept-section mutex WaitForSingleObject |

**Written-by note (persistence):**
- this 0xAB4: conditional (may be written via OperatorNewNhMallocWrapper chain during new node allocation); external poke survives until next allocation replaces it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ca69 | SEH_580190 | R | structured exception handler registration for this function |
| 0059e1a0 | WaitForSingleObject | R | Win32 WaitForSingleObject import (mutex wait) |
| 0059e1a4 | ReleaseMutex | R | Win32 ReleaseMutex import (mutex release) |
| 0059e2d8 | __imp_htonl | R | Winsock htonl import (IP address byte-order conversion) |
| 0059e2e4 | __imp_select | R | Winsock select import (socket readiness check) |
| 0059e2f4 | __imp_htons | R | Winsock htons import (port byte-order conversion) |
| 0059e308 | __imp_setsockopt | R | Winsock setsockopt import (TCP_NODELAY) |
| 0059e31c | getpeername | R | Winsock getpeername import (remote peer address) |
| 0059e32c | accept | R | Winsock accept import (accept incoming connection) |
| ff00000000005430 | byte_FF00000000005430 | RW | SEH frame variable (try-level / scope tracking byte 0) |
| ff00000000005431 | byte_FF00000000005431 | RW | SEH frame variable (try-level / scope tracking byte 1) |
| ff00000000005435 | byte_FF00000000005435 | W | SEH frame variable (try-level / scope tracking byte 5) |
| ff00000000005436 | byte_FF00000000005436 | W | SEH frame variable (try-level / scope tracking byte 6) |
| ff00000000005438 | byte_FF00000000005438 | W | SEH frame variable (try-level / scope tracking byte 8) |
| ff00000000005439 | byte_FF00000000005439 | W | SEH frame variable (try-level / scope tracking byte 9) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004979c0 | Setter | store accepted socket handle into connection node |
| 0057b6a0 | PointerAdvance | advance buffer pointer for sockaddr storage (getpeername buffer) |
| 0057b6b0 | OffsetGetter | extract socket handle from connection list node |
| 0057cb50 | sub_57CB50 | check/process a socket connection (returns activity flag) |
| 0057dc10 | sub_57DC10 | post-accept connection setup/registration |
| 00582eb0 | LinkedListNodeRemovalWithCleanupCallback | dequeue a node from the connection list with cleanup |
| 005830c0 | ObjectAllocationWithSEH | allocate and initialize a new connection node with SEH protection |
| 00583530 | ZeroFillMemoryRegionWithStep | zero-initialize the connection queue region after node allocation |
| 00587bcf | FreeWrapper_7bcf | free temporary linked list nodes after processing |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory with no-throw new (returns null on failure) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAAC | == | 0 | pending connection list head pointer null check |

**Guard interpretation:** *(this+0xAAC) != 0 → connection list has pending nodes, enter processing loop; == 0 → no pending connections, skip list processing (only accept section may have run).
