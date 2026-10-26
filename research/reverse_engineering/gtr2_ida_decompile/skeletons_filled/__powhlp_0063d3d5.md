## __powhlp_0063d3d5 — CRT _powhlp: pow special-case resolver (infinity/1 operands)

**Summary:** MSVC CRT helper called before the general power evaluation: it resolves the special cases of pow(x, y) involving infinite exponents or infinite/1 bases (y = ±inf, x = ±inf, x = ±1 with infinite y, zero exponents) and stores the result through a3, returning 1 for the |x|==1 with infinite-y case and 0 otherwise. Anything not matched falls through as "unhandled" so the caller can run the full computation.

**Called by:** start_2 (0063346d), _usepowhlp (0063d335)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16a0 | dbl_6F16A0 | R | Constant read by this helper; its role is not visible in the decompiled body |
| 006f16b0 | dbl_6F16B0 | R | Constant read by this helper; its role is not visible in the decompiled body |
| 00913458 | dbl_913458 | R | Result constant used for the infinite-power outcomes (y = ±inf with |x| on the diverging side) — the +infinity result |
| 00913460 | dbl_913460 | R | Result constant used when |x| == 1 and the exponent is ±infinity (the 1.0 result; also the only case where the function returns 1) |
| 00913478 | dbl_913478 | R | Result constant used for (-infinity) raised to a negative odd integer exponent (sign-carrying zero) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0063d367 | __d_inttype | Classifies the exponent y as an odd integer (returns 1 for odd) when the base is -infinity, deciding the sign of the result |

**Guard conditions:**
- y == +INF (HIDWORD(a2) == 2146435072 and low dword == 0): |x| &lt;= 1 → |x| == 1 gives 1.0 (v4 = 1, stored), |x| &lt; 1 gives 0.0; |x| &gt; 1 gives +infinity.
- y == -INF: |x| &lt;= 1 → |x| == 1 gives 1.0 (v4 = 1), |x| &lt; 1 gives +infinity; |x| &gt; 1 gives 0.0.
- x == +INF (HIDWORD(a1) == 2146435072, low dword == 0): y &lt;= 0 → y == 0 gives 1.0, y &lt; 0 gives 0.0; y &gt; 0 gives +infinity.
- x == -INF: `_d_inttype(y)` result used: y == 0 → 1.0; y &lt; 0 → odd integer gives dbl_913478, else 0.0; y &gt; 0 → +infinity, or -infinity when the exponent is an odd integer (v7 == 1).
- Otherwise: no case matches, nothing is written through a3 and the function returns the initial v4 = 0 (fall-through to the caller's general path).
