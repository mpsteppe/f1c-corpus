## StackBufferZeroInitWithCallback_005626b0 — InitStackBufferWithAppDirPathAndCallback

**Summary:** Initializes a 1400-byte stack buffer seeded with first byte of default application directory, zero-fills remainder, invokes a path-resolution callback (this+0xC8) to populate the buffer, then delegates to sub_562710 to compose final path into output buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FilePathNameLookup (005622c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC8 | R | — | callback function pointer for path resolution |
| this | 0x100 | R | — | additional argument passed to the path-resolution callback |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00562710 | sub_562710 | composes final path string into output buffer |

**Guard conditions:** none — no conditional branches or early returns.

