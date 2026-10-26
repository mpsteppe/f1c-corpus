## StateFlagSetter_2366_00512366 — Set flag byte and output state based on two state values

**Summary:** Sets high bit on byte at offset 0x61, stores a WORD parameter at offset 0x11E, toggles bit 7 on flags byte at 0x5C based on boolean a3, and writes output state (2 or 4) at offset 0x11B depending on state bytes at offsets 0x116 and 0x117.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50210E (0050210e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | RW | — | flags byte; bit 7 set/cleared by a3 |
| this | 0x61 | RW | — | flags byte; bit 7 always set |
| this | 0x116 | R | — | state byte 0; checked for 0 or 2 to select output |
| this | 0x117 | R | — | state byte 1; checked >= 8 when state byte 0 == 0 |
| this | 0x11B | RW | 2 | output state byte; written to 2 or 4 |
| this | 0x11E | RW | — | WORD written with a2 parameter |

**Written-by note (persistence):**
- this 0x5C: bit 7 set or cleared each call; external poke survives until next call
- this 0x61: bit 7 OR-set each call; persists until cleared externally
- this 0x11B: overwritten each call with 2 or 4
- this 0x11E: overwritten each call with a2

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x117 | >= | 8 | state byte 1 threshold |

**Guard interpretation:** When byte at offset 0x116 == 0 AND byte at offset 0x117 >= 8 (PASS), output byte at offset 0x11B is set to 2. When byte at offset 0x116 == 2 (PASS, regardless of 0x117), output is set to 4. In all other combinations, output byte retains its prior value (from previous call or external write).
