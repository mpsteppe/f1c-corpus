## sub_6CCFC8_006ccfc8 — dispatch event code 14 with sourced argument block

**Summary:** Wrapper that gathers four dwords via the base value at this[64] (byte offset 0x100) and forwards event code 14 together with those values plus two zero arguments to sub_6CCB66.

**Called by:** sub_6A1C41 (006a1c41), sub_6B0326 (006b0326)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x100 | R | — | Base dword used to source the argument tuple passed to sub_6CCB66 |
| this | 0x104 | R | — | Argument read from (value at 0x100)+4; passed as a pointer argument to sub_6CCB66 |
| this | 0x108 | R | — | Argument read from (value at 0x100)+8; passed as a pointer argument to sub_6CCB66 |
| this | 0x10C | R | — | Argument read from (value at 0x100)+12; passed as the dword argument to sub_6CCB66 |
| this | 0x110 | R | — | Argument read from (value at 0x100)+16; passed as a pointer argument to sub_6CCB66 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006ccb66 | sub_6CCB66 | Event handler that receives the selector (14) plus four sourced arguments and two trailing zeroes |

**Guard conditions:** None — no branches; unconditionally forwards to sub_6CCB66(this, 14, ...sourced args..., 0, 0).
