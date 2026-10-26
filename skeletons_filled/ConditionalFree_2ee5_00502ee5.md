## ConditionalFree_2ee5_00502ee5 — ConditionalFreeWithFlag

**Summary:** Conditionally frees memory based on flag bits in a2. Bit 2 selects mode: loop-free via NTimeCallbackLoopWithSEH or direct free. Bit 1 controls secondary free.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_502F31 (00502f31), sub_506003 (00506003)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First data element pointer (freed directly when a2&2 clear, or iterated via callback when a2&2 set) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00502c1f | FreeWrapper | R | Free callback function (passed to NTimeCallbackLoopWithSEH for loop-mode free) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free heap memory block |
| 0058a5f7 | NTimeCallbackLoopWithSEH | Iterate array and call FreeWrapper on each element with SEH protection |

**Guard conditions:** a2 & 2: if set → NTimeCallbackLoopWithSEH iterates elements *(this-1) times, then optionally frees this-1. If clear → frees *this, then optionally frees this. a2 & 1 controls secondary free in both paths.
