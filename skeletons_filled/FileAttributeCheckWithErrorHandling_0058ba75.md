## FileAttributeCheckWithErrorHandling_0058ba75 — FileAttributeCheckReadOnlyFlag

**Summary:** Checks file attributes via GetFileAttributesA. Returns -1 with error lookup if file does not exist. If file has read-only attribute (bit 0) AND a2's bit 1 is set (a2 & 2), sets TLS error codes (13 and 5) and returns -1. Otherwise returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigIniParser (00421cd0), FileAttributeCheckSequence (005668f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d8 | GetFileAttributesA | R | Win32 API import — retrieve file attributes |
| 0059e188 | GetLastError | R | Win32 API import — get error code when file not found |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058af5c | ErrorIDLookupTable | Map GetLastError code to internal error ID |
| 0058afcf | TLSOffsetGetter | TLS getter — set error code 13 (read-only file rejected) |
| 0058afd8 | TLSOffsetGetter_afd8 | TLS getter — set secondary error code 5 (read-only warning) |

**Guard conditions:**
- `GetFileAttributesA` returns -1 (INVALID_FILE_ATTRIBUTES) → file not found, GetLastError + ErrorIDLookupTable + return -1
- `(FileAttributesA & 1) != 0` AND `(a2 & 2) != 0` → file is read-only AND caller flags (bit 1 of a2) reject read-only → set TLS errors 13 and 5, return -1
- Otherwise → return 0 (success, file is acceptable)
