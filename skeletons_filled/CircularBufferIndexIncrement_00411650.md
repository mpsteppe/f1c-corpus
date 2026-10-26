## CircularBufferIndexIncrement_00411650 — CircBufIndexIncrementWithWrap

**Summary:** Classic circular buffer index increment. Reads capacity (this[0]) and current index (this[1]), increments index, wraps to 0 if index reaches capacity, returns old index value. No-op if capacity <= 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_1a50 (00411a50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | circular buffer capacity (must be >1 for operation) |
| this | 0x2 | RW | 0 | current read/write index; incremented and wrapped |

**Written-by note (persistence):**
- this 0x2: updated every call (increment + conditional wrap); persists as circular buffer position

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 1 | capacity check: if capacity <= 1, skip increment and return 0 |

**Guard interpretation:** capacity > 1 → PASS: increment index, wrap if >= capacity, return old index. capacity <= 1 → BLOCKED: return 0 without modifying index.
