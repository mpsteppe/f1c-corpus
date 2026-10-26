## sub_4E3CC0_004e3cc0 — Combined value query (third offset pair)

**Summary:** Another sibling of sub_4E3C80: returns this+0x0C + this+0x1C when any of the fields at 0x14/0x18/0x1C/0x20 differs from the -1 sentinel, otherwise returns -1.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | value added to the 0x1C field in the success result |
| this | 0x14 | R | — | companion field checked against -1 sentinel |
| this | 0x18 | R | — | companion field checked against -1 sentinel |
| this | 0x1C | R | — | secondary value; -1 sentinel means unset, and it is the right operand of the sum |
| this | 0x20 | R | — | companion field checked against -1 sentinel |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | != | 18446744073709551615 | sentinel check (-1 = unset) |
| this | 0x18 | != | 18446744073709551615 | sentinel check (-1 = unset) |
| this | 0x1C | != | 18446744073709551615 | sentinel check (-1 = unset) |
| this | 0x20 | != | 18446744073709551615 | sentinel check (-1 = unset) |

**Guard interpretation:** PASS (return this+0x0C + this+0x1C) when at least one of 0x14/0x18/0x1C/0x20 differs from -1. BLOCKED (return -1) only when all four hold the -1 sentinel, i.e. nothing is initialized.
