## Trandisp1_0058da70 — FloatDisplayControlWordAndDispatch

**Summary:** Floating-point display formatting helper. Checks byte at (a1+14) for value 5 to select x87 FPU control word (63 vs 4927), then examines ST0 via `fxam`, performs xlat-based dispatch table lookup, and calls through a virtual function table at (a1+16). Part of CRT float formatting infrastructure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Cintrindisp1 (0059067e), Ctrandisp1CRTFloatDisplayFormat (0059083b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE | R | — | Format mode selector byte — checked against 5 to choose FPU control word |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e6c6c | unk_5E6C6C | R | TransDispTable [DERIVED] — xlat translation table for dispatch byte |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE | == | 5 | Format mode field — selects FPU control word (63 with masked flags) vs default (4927) |

**Guard interpretation:** If field at offset 0xE equals 5, set control word to 63 (0x3F, normal precision/rounding). Else set to 4927 (0x133F, extended precision). This controls how the x87 FPU formats the value in ST0.
