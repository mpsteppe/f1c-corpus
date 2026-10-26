## SocketGracefulClose_0057c8e0 — GracefulSocketClose

**Summary:** Gracefully closes a socket: optionally calls shutdown(SD_SEND) and drains pending recv data, then closes socket and marks handle as -1 (INVALID_SOCKET).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BF00 (0057bf00), sub_57DE30 (0057de30), AudioStreamingThreadShutdown (0057fde0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 18446744073709551615 | SOCKET handle (INVALID_SOCKET = -1) |

**Written-by note (persistence):**
- this 0x0: set to -1 (INVALID_SOCKET) after close; external poke replaced on close

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2e8 | __imp_closesocket | R | Winsock closesocket — close socket handle |
| 0059e304 | __imp_recv | R | Winsock recv — receive/drain pending data |
| 0059e328 | shutdown | R | Winsock shutdown — disable sends (SD_SEND=1) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 18446744073709551615 | SOCKET handle validity check |

**Guard interpretation:** if *a1 (SOCKET) == -1 (INVALID_SOCKET) → blocked (already closed, skip). If valid → passes, shutdown and drain proceed.
