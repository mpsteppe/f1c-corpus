## ShortComputation_7e10_00407e10 — TripleDwordGetterFromStruct

**Summary:** Reads three consecutive DWORDs from struct offsets 0x94/0x98/0x9C and writes them to three output pointers. Simple inline getter for a triple of related values.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_6100 (00406100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x94 | R | — | first of three DWORDs read from struct |
| this | 0x98 | R | — | second of three DWORDs read from struct |
| this | 0x9C | R | — | third of three DWORDs read from struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — function always executes unconditionally.
