## UDPSocketBind_0057e860 — UDP socket bind with address setup

**Summary:** Builds a sockaddr_in (AF_INET, INADDR_ANY, port 0), copies to struct at this+0xA84 (673 DWORDs), then dispatches to either query-matching or direct bind path based on sub_586CA0 result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2d8 | __imp_htonl | R | Convert INADDR_ANY (0) to network byte order |
| 0059e2f4 | __imp_htons | R | Convert port 0 to network byte order |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b9f0 | Copy4DwordsStructToStruct | Copy 16-byte sockaddr_in to struct field at this+0xA84 |
| 0057d6c0 | sub_57D6C0 | Direct UDP bind path |
| 0057d8d0 | NetworkPacketSendWithQueryMatching | Query-matching UDP bind path |
| 00586ca0 | sub_586CA0 | Check condition to select bind path |

**Guard conditions:** If sub_586CA0(a2) returns non-zero → use NetworkPacketSendWithQueryMatching; else → use sub_57D6C0.
