## RepeatedCallLoop_f040_004cf040 — RepeatedArrayProcessLoop

**Summary:** Iterates through a strided array (108 bytes per entry) and calls sub_4CB5E0 on each element in sequence. Processes all entries when array count is positive.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FA7E0 (004fa7e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | array element count |
| this | 0x14 | R | — | pointer to first array element |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cb5e0 | sub_4CB5E0 | process/render single array element |

**Guard conditions:** Array count (this[4] / this+0x10) > 0. PASSES: loop through all entries calling sub_4CB5E0 on each. BLOCKED (<= 0): skip entirely, return 0.
