## ShortComputation_4d30_00404d30 — FieldAtOffset18Setter

**Summary:** Sets the dword at offset 0x18 on the object pointed to by this to the value of parameter a2, returning the object pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigIniParser (00421cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | RW | — | dword field set to parameter a2 |
| this | 0x0 | R | — | pointer to target object |

**Written-by note (persistence):**
- obj 0x18: written once per call with caller-supplied value; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional write.
