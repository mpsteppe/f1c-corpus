## ConditionalDelegation_0040dd30 — ConditionalDelegation

**Summary:** If this[34] pointer and its +4 field are non-zero and ShortComputation_adb0 succeeds on both, delegates to RaceCommentaryDirectorSystem with the computed value. Otherwise returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40DE60 (0040de60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x88 | R | — | pointer to sub-object, checked for null |
| this | 0x8C | R | — | field at sub-object+4, checked before delegation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d4c0 | RaceCommentaryDirectorSystem | run race commentary director system |
| 0049adb0 | ShortComputation_adb0 | validation/computation function returning non-zero on success |

**Guard conditions:** this[34] null → return 0 early. *(this[34]+4) null or ShortComputation_adb0 fails → return 0 early.
