## CameraViewStructInitializer_00405440 — ViewStructDefaultInit

**Summary:** Initializes a view/state struct with default values: sets several fields to -1 or 0, copies a default directory path string, runs virtual cleanup, and zero-fills a trailing block.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_53e0 (004053e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 18446744073709551615 | dword set to -1 (sentinel/ID) |
| this | 0xC | RW | 0 | dword zeroed |
| this | 0x10 | RW | 18446744073709551615 | dword set to -1 |
| this | 0x14 | RW | 0 | dword zeroed |
| this | 0x18 | RW | 0 | dword zeroed |
| this | 0x1C | RW | 18446744073709551615 | dword set to -1 |
| this | 0x20 | RW | 0 | dword zeroed |
| this | 0x24 | RW | 0 | dword zeroed |
| this | 0x28 | RW | 0 | dword zeroed |
| this | 0x2C | RW | 0 | dword zeroed |
| this | 0x38 | RW | 0 | dword zeroed |
| this | 0x70 | RW | 0 | byte zeroed (part of memset trailing range) |

**Written-by note (persistence):**
- this 0x0: set once per init; survives until next init
- this 0xC through 0x70: initialized once; external poke survives until next init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052d990 | VirtualCleanup | virtual-table-backed cleanup on sub-object at offset 0x30 |
| 00566650 | StringCopyWithBufferRealloc | copies default directory path string to struct |

**Guard conditions:** none — unconditional initialization.
