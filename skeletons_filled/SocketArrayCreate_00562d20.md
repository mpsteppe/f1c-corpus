## SocketArrayCreate_00562d20 — CreateUdpSocketArray

**Summary:** Creates a pre-allocated array of UDP sockets (AF_INET, SOCK_DGRAM, IPPROTO_UDP) using a 28-byte entry stride, storing each handle at entry+0 and zero-initializing entry+4 and entry+8. Truncates the count if a socket creation fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DeviceInitializationWithStateSetup (00562c90), MultiStageInitializationChainWithErrorChecking (00563020), NetworkConnection (00563260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | pointer to socket array base (28-byte entries) |
| this | 0x6C | RW | — | number of sockets to create; written on early truncation |

**Written-by note (persistence):**
- this 0x6C: written only if socket creation fails mid-loop — set to count of successfully created sockets. Survives as truncation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598648 | socket | create UDP socket (AF_INET=2, SOCK_DGRAM=2, IPPROTO_UDP=17) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x6C | > | 0 | socket count — number of sockets to create |

**Guard interpretation:** this+0x6C > 0 enters the socket creation loop. If <= 0, the function immediately returns 0 (no sockets to create). Also, if socket() returns -1, the loop breaks early and this+0x6C is truncated to the count already created.

