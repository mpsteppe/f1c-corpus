## __convertTOStoQNaN_006383ec — Convert signaling TOS value to quiet NaN

**Summary:** Floating-point runtime helper (Borland-style CRT math support) that turns a signaling NaN on the x87 top-of-stack into a quiet NaN by adding 1.0 when the relevant exception flag is clear.

**Called by:** start_0 (00631aed), start_1 (00632f0d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00730870 | dbl_730870 | R | Read-only double constant used as the additive operand (the 1.0 applied to quiet the NaN) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks bit 0x80000 of a1 (the x87 status/exception word passed in EAX). If `(a1 & 0x80000) == 0` → PASSES, returns `result + 1.0` (quiet the signaling NaN). If bit 0x80000 is set → returns `result` unchanged (no adjustment needed).
