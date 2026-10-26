## VirtualArrayFill_0051ea5a — Virtual array fill via vtable call

**Summary:** Fills buffer at this+0x1A4 by looping from 0 to this+0x64 and calling vtable method[1] (offset 4) with parameter 2*(this+0x5C)+4. Each call result stored at advancing position in buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CodecModeSelect (0051ea90), ObjectSetupWithBoundsCheck (0051eb6e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | vtable pointer — used to dispatch method at vtable+4 |
| this | 0x8 | R | — | unknown (not directly referenced in this code) |
| this | 0x5C | R | — | size parameter — 2*field+4 passed as arg to vtable call |
| this | 0x64 | R | — | array length — loop count for filling buffer |
| this | 0x1A4 | R | — | output buffer pointer — receives vtable call results |
| this | 0x1E8 | RW | — | unknown (not directly referenced in this code) |

**Written-by note (persistence):**
- this 0x1E8: unknown — R/W access not visible in decompiled code

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x64 | > | 0 | array length / loop count |

**Guard interpretation:** If this+0x64 > 0 → loop runs, filling buffer entries. If <= 0 → loop skipped entirely, function returns buffer pointer unmodified.
