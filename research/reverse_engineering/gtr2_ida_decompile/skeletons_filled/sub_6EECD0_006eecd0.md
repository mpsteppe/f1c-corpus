## sub_6EECD0_006eecd0 — Wrapper returning sub_45A210((int)dbl_B68610)

**Summary:** Thin wrapper: reads the global double dbl_B68610, casts it to int, passes that to sub_45A210 and returns the callee's result. Adapter-style entry point exposing sub_45A210 for that global value.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b68610 | dbl_B68610 | R | Value is loaded and cast to int as the argument to sub_45A210; a global double (or float pair) feeding that call. Concrete meaning unknown. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional call, no branches; sub_45A210's result is returned directly.
