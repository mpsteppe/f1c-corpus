## NetworkGetPort_0057bcb0 — GetNetworkPort

**Summary:** Reads network port from offset 0x12C and converts from network to host byte order via ntohs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x12C | R | — | network port in network byte order (u_short) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2cc | __imp_ntohs | R | convert port from network to host byte order |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes unconditionally.
