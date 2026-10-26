## UtilityFunction_84b0_004184b0 — StructureWithBuffersInit

**Summary:** Initializes a large structure: zeroes short array at start, initializes sub-struct at 0x864 with sentinel values, zeros two fields at 0xAF0/0xAF4, fills buffer region with 0x10F defaults via callee. Returns this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAF0 | RW | 0 | Byte flag/counter, zeroed during init |
| this | 0xAF4 | RW | 0 | Dword data field, zeroed during init |

**Written-by note (persistence):**
- this 0xAF0: unconditional write, set to 0 each time this function runs
- this 0xAF4: unconditional write, set to 0 each time this function runs

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00411680 | ShortArrayInit | Initializes short array at start of struct |
| 004144d0 | StructInitWithSentinelValues | Fills sub-struct with sentinel/default values |
| 004186a0 | BufferInitWith10fDefaults | Fills buffer region with 0x10F byte pattern |
| 004b0170 | EmptyStub_0170 | No-op stub placeholder |

**Guard conditions:** None — unconditional sequential initialization; no branches or early returns.
