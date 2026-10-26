## DirectoryStringProcessingWithDecode_00461ed0 — NetworkDirectoryLookupAndConnect

**Summary:** Processes a directory string, decodes it via config lookup, resolves port from config, and establishes a network connection.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1B79C | R | — | Network system pointer (checked non-null to proceed) |
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3f6c | byte_5C3F6C | R | Config data for string decode/lookup |
| 007d0fe8 | word_7D0FE8 | R | Session port base (used when config decode yields nothing) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00563260 | NetworkConnection | Establish network connection with decoded params |
| 00587c20 | sub_587C20 | Compare decoded string against config default |
| 00587dd0 | sub_587DD0 | String copy with length limit (63 chars) |
| 00587ece | sub_587ECE | Resolve port number from decoded config value |
| 005897ca | sub_5897CA | Decode/process config string |

**Guard conditions:** Blocked when network system pointer (this+0x1B79C) is null.
