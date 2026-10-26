## FileStreamWriter_004b41e0 — FilePathStreamWriter

**Summary:** Writes a file path string through conditional dispatch system: dispatches this struct header (4 bytes), then string length (1 byte), then string content. Falls back to default application directory path if no custom path set. Called from VehicleForceAerodynamicsComputation for aerodynamics debug logging.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleForceAerodynamicsComputation (004b6a10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | File path string pointer (may be null, falls back to default) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default application directory path (fallback when this[1] is null) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566bd0 | ConditionalDispatch_6bd0 | Dispatch data block (header, length, or string content) through conditional output system |

**Guard conditions:** 
1. If this[1] (path pointer) is null, uses byte_5EA438 (default application dir) instead.
2. Only dispatches string content if length byte (a2/strlen result) is non-zero.
