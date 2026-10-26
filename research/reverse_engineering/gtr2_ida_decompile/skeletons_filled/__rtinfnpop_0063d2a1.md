## __rtinfnpop_0063d2a1 — CRT exp overflow return helper

**Summary:** MSVC CRT x87 math helper: unconditionally loads the overflow return constant from tbyte_913320, records exception code 3 (overflow) in the trandisp frame byte at ebp-144, and returns the loaded value in st0. Used by exp/pow-style code as the "result too large" completion path.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00913320 | tbyte_913320 | R | Long-double constant used as the overflow return value (the saturated magnitude the CRT yields when the true result exceeds the double range) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branches. The function always loads `tbyte_913320`, writes literal 3 into the byte at ebp-144 (the pending-exception code consumed by the cintrin/tran exit path, 3 = overflow), and returns the constant in st0.
