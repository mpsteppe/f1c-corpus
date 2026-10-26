## ShortComputation_52d0_004652d0 — Resource slot activation counter

**Summary:** Checks activation byte at base + 560*a2 + 248. If zero (inactive), sets it to 1 and increments resource active count at +0xE40C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TeamRadioNetworkMessageProcessing (0045f710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Base pointer of resource array |
| obj | 0xE40C | R | — | Resource active count (incremented on activation) |
| this | 0x0 | R | — | Pointer to container object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks byte at (560*a2 + *obj + 248). If zero (inactive), activates it and increments count (PASSES). If nonzero (already active), skips (BLOCKED).
