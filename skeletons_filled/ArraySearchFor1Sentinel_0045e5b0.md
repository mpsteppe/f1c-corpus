## ArraySearchFor1Sentinel_0045e5b0 — ArraySentinelSearch

**Summary:** Searches a DWORD array starting at this+0x1D4 for the first element equal to -1 (sentinel). Returns index of match, or -1 if not found within 104 elements.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890), NetComm_SetSelfAsReady (00460520)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1D4 | R | — | Start of DWORD array; each element compared to -1 sentinel |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1D4 | != | 18446744073709551615 | Array element compared to -1 sentinel |

**Guard interpretation:** 
- Loop walks array starting at this+0x1D4. Element == -1 → stop, return count (index).
- Element != -1 → continue; if count reaches 104 without finding -1 → return -1 (not found).
