## CreateUdpBroadcastSocket_00563080 — CreateUdpBroadcastSocket (self)

**Summary:** Creates a UDP socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP), enables the SO_BROADCAST option, and stores the socket handle at this+0x88. Returns true (failure) if socket() or setsockopt() fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiStageInitializationChainWithErrorChecking (00563020)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x88 | RW | — | UDP broadcast socket handle |

**Written-by note (persistence):**
- this 0x88: set unconditionally to result of socket(). Survives as INVALID_SOCKET or valid handle.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598648 | socket | create UDP datagram socket (AF_INET=2, SOCK_DGRAM=2, IPPROTO_UDP=17) |
| 0059868a | setsockopt | enable SO_BROADCAST (level=0xFFFF/SOL_SOCKET, optname=32/SO_BROADCAST, optval=1) |

**Guard conditions:** none — straight-line creation and option setting. Return value indicates success (0) or failure (1) of socket() or setsockopt().

