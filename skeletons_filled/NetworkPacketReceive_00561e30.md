## NetworkPacketReceive_00561e30 — UdpPacketReceive

**Summary:** Poll UDP socket for incoming packets using select() with zero timeout. For each received packet, null-terminate buffer and dispatch to FilePathNameLookup. Returns select result or this[57] flag check.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Socket handle |
| this | 0xE4 | R | — | Flag: if non-zero, proceed with receive loop |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008cef80 | buf | RW | NetReceiveBuffer [DERIVED] (also: receive buffer (256 bytes) |
| ff00000000005435 | byte_FF00000000005435 | W | unknown |
| ff00000000005436 | byte_FF00000000005436 | W | unknown |
| ff00000000005438 | byte_FF00000000005438 | W | unknown |
| ff00000000005439 | byte_FF00000000005439 | W | unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005622c0 | FilePathNameLookup | Dispatch received packet data |
| 0059864e | recvfrom | Receive UDP packet into buffer |
| 00598654 | select | Poll socket for readability with zero timeout |

**Guard conditions:** this[57] (offset 0xE4) — if zero, skip entire receive loop. select returns -1 or 0 — break loop.
