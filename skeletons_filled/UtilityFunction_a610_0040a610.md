## UtilityFunction_a610_0040a610 — Sub-Object Array Accessor

**Summary:** Returns the sub-object pointer at this[4+index] for index 0-8, or 0 for out-of-range indices. Simple array-like accessor function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ModeDispatchedSubsystemCall (0040d0b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | Sub-object pointer array entry [0] |
| this | 0x14 | R | — | Sub-object pointer array entry [1] |
| this | 0x18 | R | — | Sub-object pointer array entry [2] |
| this | 0x1C | R | — | Sub-object pointer array entry [3] |
| this | 0x20 | R | — | Sub-object pointer array entry [4] |
| this | 0x24 | R | — | Sub-object pointer array entry [5] |
| this | 0x28 | R | — | Sub-object pointer array entry [6] |
| this | 0x2C | R | — | Sub-object pointer array entry [7] |
| this | 0x30 | R | — | Sub-object pointer array entry [8] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040a658 | jpt_40A61B | R | Jump table for switch on a2 index |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 index must be 0-8 (case values 0 through 8). Default case returns 0 for out-of-range indices.
