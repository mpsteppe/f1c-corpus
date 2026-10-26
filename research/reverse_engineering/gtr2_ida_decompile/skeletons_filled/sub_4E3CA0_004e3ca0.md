## sub_4E3CA0_004e3ca0 — Combined value query (companion variant)

**Summary:** Sibling of sub_4E3C80: returns this+0x04 + this+0x18 when any of the fields at 0x14/0x18/0x1C/0x20 differs from the -1 sentinel, otherwise returns -1.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | value added to the 0x18 field in the success result |
| this | 0x14 | R | — | companion field checked against -1 sentinel |
| this | 0x18 | R | — | secondary value; -1 sentinel means unset, and it is the right operand of the sum |
| this | 0x1C | R | — | companion field checked against -1 sentinel |
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

**Guard interpretation:** PASS (return this+0x04 + this+0x18) when at least one of 0x14/0x18/0x1C/0x20 differs from -1. BLOCKED (return -1) only when all four hold the -1 sentinel, i.e. nothing is initialized.
