## WinsockInit_0057fb90 — Winsock startup (WSAStartup) initializer

**Summary:** One-time Winsock initialization: checks flag at this+0xA74, calls WSAStartup(2.2) if not yet initialized, stores WSADATA at this+0x778. Sets flag on success, calls error handler on failure. Returns current flag state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkConnectionThread (0057fc80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA74 | RW | 0 | Byte flag: 1 = WSAStartup succeeded, 0 = not initialized / failed |

**Written-by note (persistence):**
- this 0xA74: set to 1 once on success; cleared to 0 on failure; persists across calls (prevents re-init)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e314 | __imp_WSAStartup | R | Winsock initialization with version 2.2 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057d400 | sub_57D400 | Error handler called on WSAStartup failure |

**Guard conditions:**
- If this+0xA74 byte is non-zero (already initialized) → return 1 immediately, skip WSAStartup
- If WSAStartup returns non-zero (failure) → set flag to 0, call error handler, return 0
