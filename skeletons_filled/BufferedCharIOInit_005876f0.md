## BufferedCharIOInit_005876f0 — Initialize buffer/Tail fields and call global init

**Summary:** Sets DWORD at offset 0x410 to -1 and DWORD at offset 0x414 to 0, then calls FieldConstantsInitialization global init. Likely initializes buffer tail-position tracking fields in a larger struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5837F0 (005837f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x410 | RW | 18446744073709551615 | Buffer tail/index field initialized to -1 |
| this | 0x414 | RW | 0 | Buffer tail/index field initialized to 0 |

**Written-by note (persistence):**
- this 0x410: set to -1 each call; external poke overwrites it
- this 0x414: set to 0 each call; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005879f0 | FieldConstantsInitialization | Global/sub-system init routine called after field assignment |

**Guard conditions:** None — all operations execute unconditionally.
