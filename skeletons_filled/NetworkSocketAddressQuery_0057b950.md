## NetworkSocketAddressQuery_0057b950 — QuerySocketAddressWithMetadata

**Summary:** Stores metadata (namelen, a3, a4, a5) into buffer then calls getsockname to retrieve the socket's local address into buffer+16. Returns true on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57CB50 (0057cb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | stored namelen value (metadata) |
| this | 0x4 | RW | — | stored a3 value (metadata) |
| this | 0x8 | RW | — | stored a4 value (metadata) |
| this | 0xC | RW | — | stored a5 value (metadata) |

**Written-by note (persistence):**
- this 0x0: unconditionally overwritten per call; external poke does not survive
- this 0x4: unconditionally overwritten per call; external poke does not survive
- this 0x8: unconditionally overwritten per call; external poke does not survive
- this 0xC: unconditionally overwritten per call; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2d0 | __imp_getsockname | R | Winsock getsockname — retrieve local address of socket |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none on function entry; returns false if getsockname fails (non-zero return).
