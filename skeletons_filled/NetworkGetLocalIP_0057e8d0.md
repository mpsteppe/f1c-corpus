## NetworkGetLocalIP_0057e8d0 — get local IP address as string

**Summary:** Initializes an in_addr to INADDR_ANY, copies address struct to network context, converts to dotted-decimal string via inet_ntoa, copies result to output buffer with null terminator. Returns 1 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2d8 | __imp_htonl | R | Convert INADDR_ANY to network byte order |
| 0059e2f4 | __imp_htons | R | Convert port to network byte order |
| 0059e310 | __imp_inet_ntoa | R | Convert in_addr to dotted-decimal string |
| ff00000000005983 | byte_FF00000000005983 | RW | unknown (indirect, not referenced in this function's code) |
| ff00000000005990 | byte_FF00000000005990 | RW | unknown (indirect, not referenced in this function's code) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b9f0 | Copy4DwordsStructToStruct | Copy 16-byte address struct to context at this+673 |
| 00587dd0 | sub_587DD0 | Copy string with size limit to output buffer |

**Guard conditions:** If inet_ntoa returns NULL → return 0 (failure).
