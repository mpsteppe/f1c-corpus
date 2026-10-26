## NetworkCleanup_fbe0_0057fbe0 — full network subsystem cleanup

**Summary:** Performs network shutdown: drains both mutexes (first at 0xAD8, second at 0xAF4), destroys all linked lists (two lists cleared via flush+destroy calls), calls virtual method at vtable+48, then calls WSACleanup if Winsock was initialized. Returns 1 if WSACleanup was called.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BCE0 (0057bce0), AudioStreamingThreadShutdown (0057fde0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x30 | R | — | Vtable entry at +48 (virtual cleanup method) |
| this | 0x0 | R | — | Vtable pointer (dispatched for virtual cleanup) |
| this | 0xA74 | RW | 0 | WSAStartup flag: 1 = WSACleanup needed, cleared after |
| this | 0xAD8 | R | — | First list mutex handle (drained then released) |
| this | 0xADC | R | — | First list mutex timeout |
| this | 0xAF4 | R | — | Second list mutex handle (drained then released) |
| this | 0xAF8 | R | — | Second list mutex timeout |

**Written-by note (persistence):**
- this 0xA74: cleared to 0 after WSACleanup; no further init expected

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Drain (wait then release) both mutexes before destruction |
| 0059e1a4 | ReleaseMutex | R | Release both mutexes after wait |
| 0059e318 | __imp_WSACleanup | R | Winsock cleanup if WSAStartup was called |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057e570 | sub_57E570 | Subsystem-specific cleanup step |
| 0057e6e0 | ThreadSafeLinkedListDestructionWithMutex | Thread-safe linked list destruction |
| 0057e760 | MutexProtectedLinkedListFlushDestroy | Flush and destroy first mutex-protected list |
| 0057e7e0 | MutexProtectedLinkedListDestruction | Destroy second mutex-protected list |

**Guard conditions:**
- If this+0xA74 (WSA flag) is 0 → skip WSACleanup, return 0
