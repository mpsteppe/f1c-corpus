## SocketBindPortScan_0057c7b0 — BindSocketWithPortScan

**Summary:** Binds socket to port starting from a2, scanning up to 100 ports forward on non-EINVAL bind failure. Returns bound port on success, -1 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BF00 (0057bf00), NetworkSocketInitializationAndListen (005804a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2d4 | __imp_bind | R | Winsock bind — associate socket with local address |
| 0059e2d8 | __imp_htonl | R | convert IP address to network byte order |
| 0059e2f4 | __imp_htons | R | convert port to network byte order |
| 0059e324 | WSAGetLastError | R | retrieve last Winsock error code |
| ff00000000005430 | byte_FF00000000005430 | W | unknown (direct byte write outside normal data range) |
| ff00000000005431 | byte_FF00000000005431 | W | unknown (direct byte write outside normal data range) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** loop continues while bind fails with error != WSAEINVAL(10022) and v2 < 100 (retry with next port). Returns -1 if EINVAL or max attempts reached. Returns bound port on successful bind.
