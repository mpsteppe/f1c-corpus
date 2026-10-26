## TripleFieldSetter_6280_00456280 — TripleFieldSetter_0x0_0x4_0x8

**Summary:** Sets three consecutive DWORD fields at offsets 0x0, 0x4, and 0x8 from three input parameters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundEmitter (00456170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | first field (element [0]) |
| this | 0x4 | RW | — | second field (element [1]) |
| this | 0x8 | RW | — | third field (element [2]) |

**Written-by note (persistence):**
- this 0x0: always written. External poke survives until next call.
- this 0x4: always written. External poke survives.
- this 0x8: always written. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** unconditional write; no guards.
