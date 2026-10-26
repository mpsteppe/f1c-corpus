## NetworkSocketInitializationAndListen_005804a0 — bind both sockets, listen TCP, store IP config

**Summary:** Initializes network listener: calls virtual init, binds UDP socket to port and TCP socket to port+50, copies IP string to config buffer, configures byte flags, starts TCP listen with large backlog, then dispatches post-listen callbacks. Returns 0 on success, 6 if bind fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48 | R | — | Vtable entry at +72 (init callback) |
| obj | 0x90 | R | — | Vtable entry at +144 (post-listen callback) |
| this | 0x0 | R | — | Vtable pointer for dispatch |
| this | 0x910 | R | — | Base port number (WORD) for socket bind |
| this | 0x938 | R | — | TCP socket handle (bound to port+50) |
| this | 0x93C | R | — | UDP socket handle (bound to port) |
| this | 0x967 | RW | 0 | Byte flag (cleared to 0) |
| this | 0x968 | RW | 1 | Byte flag (set to 1 — enabled/ready) |
| this | 0x96A | RW | 1 | Byte flag (set to 1 — enabled/ready) |
| this | 0x96B | RW | — | Byte flag (set from parameter a3) |

**Written-by note (persistence):**
- this 0x967: cleared to 0 once; survives until next init
- this 0x968: set to 1 once; persists as enabled flag
- this 0x96A: set to 1 once; persists as enabled flag
- this 0x96B: set from a3 parameter; persists across calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ca8b | SEH_5804A0 | R | SEH handler registration |
| 0059e330 | listen | R | Windows listen() syscall on TCP socket |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057c7b0 | SocketBindPortScan | Bind UDP socket to port and TCP socket to port+50 |
| 00585680 | ThreadResumeWithMutexWait | Resume thread with mutex wait synchronization |
| 005857c0 | MutexProtectedFieldWrite | Write field under mutex protection |
| 00585cd0 | ThreadSafeWriteWithMutex | Thread-safe write via mutex |
| 00587dd0 | sub_587DD0 | Copy IP string (a2) to config buffer at this+0x948 |

**Guard conditions:**
- If SocketBindPortScan fails for UDP socket (at port) OR TCP socket (at port+50) → set v4=0; after config setup, return 6 (bind failure)
