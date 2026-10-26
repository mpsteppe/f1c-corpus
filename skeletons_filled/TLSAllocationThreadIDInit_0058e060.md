## TLSAllocationThreadIDInit_0058e060 — TLSAllocAndThreadIDInit

**Summary:** One-time initialization of thread-local storage for allocation tracking. Calls sub_58DFC1 to init critical sections, allocates TLS index via TlsAlloc, allocates 116-byte per-thread block via sub_58AB58, stores it in TLS via TlsSetValue, initializes it via TwoFieldInitializer_e0b4, and records current thread ID. Returns 1 on success, 0 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_58A19E (0058a19e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e154 | TlsAlloc | R | Win32 API import — allocate TLS index |
| 0059e158 | TlsSetValue | R | Win32 API import — store per-thread value in TLS slot |
| 0059e15c | GetCurrentThreadId | R | Win32 API import — get current thread ID for storage |
| 005e6d40 | dwTlsIndex | RW | TlsIndex [DERIVED] (also: ` — TLS index (used by FUN_0058e0c7) — allocated TLS slot index |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058ab58 | sub_58AB58 | Allocate per-thread block (116 bytes, initialized to zero) |
| 0058dfc1 | sub_58DFC1 | Initialize four critical sections used for allocation synchronization |
| 0058e0b4 | TwoFieldInitializer_e0b4 | Initialize allocated TLS block structure with default values |

**Guard conditions:**
- `TlsAlloc()` returns -1 (TLS_OUT_OF_INDEXES) → return 0 (failure)
- `sub_58AB58(1, 116)` returns NULL → return 0 (failure)
- `TlsSetValue(dwTlsIndex, v0)` returns 0 (failure) → return 0 (failure)
- All steps succeed → store ThreadId in *v0 and -1 in v1[1], return 1
