## AudioStreamingThreadShutdown_0057fde0 — audio streaming thread shutdown and cleanup

**Summary:** Shuts down audio streaming thread: calls virtual shutdown callback, terminates thread, gracefully closes TCP and UDP sockets, destroys first linked list (at 0xAC8) freeing nodes via virtual delete, then calls full network cleanup. Returns 0 on success, 8 if not initialized, 9 if NetworkCleanup fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xAC8)+0x0)+0x0) | 0x0 | R | — | Head node → data pointer → first DWORD (triple indirect) |
| *(*(this+0xAC8)+0x0) | 0x0 | R | — | Head node data pointer (double indirect) |
| *(this+0xAC8) | 0x0 | R | — | Head node first DWORD (data pointer) |
| *(this+0xAC8) | 0x8 | R | — | Head node byte flag |
| obj | 0x74 | R | — | Vtable entry at +116 (shutdown callback) |
| this | 0x0 | R | — | Vtable pointer for shutdown dispatch |
| this | 0xA74 | R | — | WSAStartup flag (must be 1 to proceed) |
| this | 0xAC8 | RW | 0 | First list head pointer (zeroed after destroy) |
| this | 0xACC | RW | 0 | First list tail pointer (zeroed) |
| this | 0xAD0 | RW | 0 | First list cursor (zeroed) |
| this | 0xAD4 | RW | 0 | First list count (zeroed) |
| this | 0xAD8 | R | — | First list mutex handle |
| this | 0xADC | R | — | First list mutex timeout |

**Written-by note (persistence):**
- this 0xAC8: zeroed after list destroyed; no surviving state
- this 0xACC: zeroed after list destroyed
- this 0xAD0: zeroed after list destroyed
- this 0xAD4: zeroed after list destroyed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on mutex before list destruction |
| 0059e1a4 | ReleaseMutex | R | Release mutex after list destruction |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057c8e0 | SocketGracefulClose | Gracefully close TCP (flag=1) and UDP (flag=0) sockets |
| 0057fbe0 | NetworkCleanup_fbe0 | Full network subsystem cleanup (WSACleanup, list destroy) |
| 00585040 | sub_585040 | Pre-cleanup step |
| 00585130 | sub_585130 | Pre-cleanup step |
| 00585550 | ThreadTerminationWithWaitCleanup | Wait for thread termination and clean up |
| 00587bcf | FreeWrapper_7bcf | Free list nodes during destruction |

**Guard conditions:**
- If WSA flag (this+0xA74) is 0 → return 8 (not initialized)
- If mutex handle (this+0xAD8) is 0 → skip list destruction entirely
- If mutex wait fails (non-zero, non-128) → skip list destruction
- If head pointer (this+0xAC8) is 0 → skip node traversal
- If NetworkCleanup_fbe0 returns 0 → return 9 (cleanup failed)
