## ShortComputation_a820_0057a820 — MutexGuardedComputation

**Summary:** Acquires mutex at obj+0x640 with timeout from obj+0x644 (WaitForSingleObject). On acquire (WAIT_OBJECT_0 or WAIT_ABANDONED), runs ShortComputation_7210 on sub-struct at obj+0x624. Always releases mutex. Returns computed result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SingleFunctionForward (00462310)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x640 | R | — | mutex handle passed to WaitForSingleObject |
| obj | 0x644 | R | — | timeout (ms) for WaitForSingleObject |
| this | 0x0 | R | — | context pointer; *this yields base address for field offsets |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Mutex handle at obj+0x640 non-null → enter wait path. WaitForSingleObject returns 0 or 128 (WAIT_OBJECT_0 / WAIT_ABANDONED) → PASSES (compute on sub-struct). Else v5=0 → ShortComputation_7210 called with null.

