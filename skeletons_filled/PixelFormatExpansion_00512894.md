## PixelFormatExpansion_00512894 — PixelFormatExpansionInPlace

**Summary:** Expand packed pixel buffer in-place from lower to higher bit depth based on format state fields. Handles 1→2, 1→4, and 1→8 byte-per-pixel expansion with configurable color/alpha fill patterns.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_51389E (0051389e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pixel count (width × height) |
| this | 0x4 | RW | — | expanded byte count, written at end |
| this | 0x8 | R | — | base format indicator (0=original, 2=alternate base) |
| this | 0x9 | R | — | current bit-depth state (8 or 16) |
| this | 0xA | RW | 2 | bytes per pixel after expansion (2 or 4) |
| this | 0xB | RW | 32 | output stride/pitch after expansion (16/32/64) |

**Written-by note (persistence):**
- this 0x4: always at end — overwritten with expanded byte count; survives until next expansion step
- this 0xA: set to 2 or 4 on each pass; survives until overwritten
- this 0xB: set to 16/32/64 on each pass; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 0 | format base — selects 2-byte or 4-byte expansion path |
| this | 0x8 | == | 2 | format base — selects 4-byte or 8-byte expansion path |
| this | 0x9 | == | 8 | bit-depth substate — selects expansion step within base |
| this | 0x9 | == | 16 | bit-depth substate — selects expansion step within base |

| Param | Test | Value | Meaning |
|-------|------|-------|---------|
| a4 | >= 0 | signed char | alpha-channel present flag — selects fill pattern |
| a4 | < 0 | signed char | no alpha channel — selects alternate fill pattern |

**Guard interpretation:** Function dispatches on format field (0x8) then state field (0x9). PASSES when: (0x8==0 && 0x9==8) → 1→2 byte expansion; (0x8==0 && 0x9==16) → 1→4 byte expansion; (0x8==2 && 0x9==8) → 1→4 byte expansion; (0x8==2 && 0x9==16) → 1→8 byte expansion. BLOCKED (early return) when combination unrecognized: (0x8==0 && 0x9 not in {8,16}) or (0x8==2 && 0x9 not in {8,16}) or (0x8==1 or >2).
