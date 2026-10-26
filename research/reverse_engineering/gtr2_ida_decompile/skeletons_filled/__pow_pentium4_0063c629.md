## __pow_pentium4_0063c629 — SSE2 pow(x,y) implementation (VC8 libm conduit)

**Summary:** The VC8/Intel libm software power routine: computes x^y entirely with SSE2 instructions — an extended-precision log2(x) evaluated from table-driven polynomial approximations, multiplied by y in double-double arithmetic, followed by a 2^t reconstruction with overflow/underflow classification. Exceptional cases (NaN/inf/zero/signed results, over/underflow) are handed off to the shared libm error dispatcher sub_63C1AB with a numeric error code.

**Called by:** __CIpow_pentium4 (0063c610)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|--------|-----|------|
| 00731e00 | qword_731E00 | R | 256-entry double table (stride 4) indexed by the top mantissa bits of x; supplies the leading log2(1+f) term / first table factor |
| 00732210 | xmmword_732210 | R | Paired __m128d correction table (stride 8) indexed by the same mantissa index; supplies the log improvement constant added to the running log accumulator |
| 00732a20 | qword_732A20 | R | Second-stage double table (stride 4) indexed by the shifted exponent/mantissa class; rescales both log accumulators a4/a6 |
| 00732e30 | xmmword_732E30 | R | Paired __m128d correction table (stride 8) indexed by the same second-stage index; added to the log accumulator |
| 00733640 | qword_733640 | R | Third-stage double table (stride 4) indexed by the exponent of the scaled value; multiplies the accumulators and the value |
| 00733e50 | xmmword_733E50 | R | Paired __m128d correction table (stride 8) indexed by the same third-stage index; added to the log accumulator |
| 00734e60 | xmmword_734E60 | R | First polynomial coefficient pair for the log1p series term (mul with v34) |
| 00734e70 | xmmword_734E70 | R | Second polynomial coefficient pair for the log1p series (mul with v34*v34) |
| 00735680 | qword_735680 | R | Constant-pool entry in the pow constant cluster; role not individually visible in the decompiled body |
| 00735690 | xmmword_735690 | R | Mask constant used to strip/normalize fields of the working __m128d (`a5 = (a5 & mask) | other`), part of the exponent-reconstruction constant pair |
| 007356a0 | xmmword_7356A0 | R | OR-constant paired with xmmword_735690 in the same normalization sequence |
| 007356b0 | xmmword_7356B0 | R | Mantissa extraction mask used with a 0x34 right-shift to classify y (and x) as integer/mantissa patterns |
| 007356c0 | xmmword_7356C0 | R | Polynomial coefficient multiplied with the squared reconstruction argument in the final exp series |
| 007356d0 | xmmword_7356D0 | R | Polynomial coefficient added in the final exp series (`xmmword_7356D0 + c*x`) |
| 007356e0 | qword_7356E0 | R | Constant-pool entry in the pow constant cluster; role not individually visible in the decompiled body |
| 007356e8 | qword_7356E8 | R | Constant-pool entry in the pow constant cluster; role not individually visible in the decompiled body |
| 007356f0 | qword_7356F0 | R | Constant-pool entry in the pow constant cluster; role not individually visible in the decompiled body |
| 007356f8 | qword_7356F8 | R | Constant-pool entry in the pow constant cluster; role not individually visible in the decompiled body |
| 00735700 | dbl_735700 | R | Constant-pool double in the pow constant cluster; role not individually visible in the decompiled body |
| 00735708 | dbl_735708 | R | Constant-pool double in the pow constant cluster; role not individually visible in the decompiled body |
| 00735710 | qword_735710 | R | Constant-pool entry in the pow constant cluster; role not individually visible in the decompiled body |
| 00735718 | qword_735718 | R | Constant-pool entry in the pow constant cluster; role not individually visible in the decompiled body |
| 00735720 | qword_735720 | R | Constant-pool entry in the pow constant cluster; role not individually visible in the decompiled body |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0063c1ab | sub_63C1AB | Shared libm error dispatcher: called with the computed value, the y argument and an error code (24=overflow, 25=underflow, 26/27/28/29/1006 = domain/special cases) to invoke the registered math handler and set errno |

**Guard conditions:**
- x class window: `((32751 - epi16) | (epi16 - 16)) < 0x80000000` (epi16 = sign+exponent word of x) — only when both differences are non-negative (16 &lt;= epi16 &lt;= 32751) does evaluation skip the special paths and go directly to BACK_MAIN; otherwise the y-side checks run first.
- y inf/NaN: if `|y|` high dword `>= 0x7FF00000`: x inf/NaN (or x==+/-inf with zero mantissa) → Y_INF_NAN; x finite → X_NAN (error code 1006 with value 2x).
- y == +/-0 (`v58|v56 == 0`): x mantissa zero and exponent non-special → return 1.0; x exponent-only value 0x3FF00000 (x==1) → return 1.0 (`RET_ONE` otherwise goes to error code 28); x==-1 → returns 1.0 for y=+0, error 1006 for y=-0; x NaN/inf → error codes 26/29.
- x==0 path (ZERO_X): if y is integer (mantissa-class test) and x negative → error code 27; result is +/-0 depending on y's parity/sign bits.
- Very large exponent gap `v63 >= 0x7FF0` (overflow-scale y): if y mantissa is zero and x==1: returns 0.0 or INFINITY depending on y's sign and |x| vs 1.0; with y integrality test the result is -INFINITY / -0.0 / 0.0 / INFINITY.
- y not integral in the large-gap case (`v62 != 255`): x==1 → 1.0; x != 1 → error code 28 with NAN.
- Final result exponent classification: `v97/v96 = (result exponent & 0x7FF0)`: `== 32752` (all-ones, overflow) → error code 24 with +/-INFINITY; `== 0` (underflow) → error code 25 with a denormal-scaled value; other values → return finite result directly (via v102).
- Early exit in the 2^t reconstruction: when the exponent field lands outside the safe window the function returns either `v16|0x1FF80` shifted (saturated denormal) or falls into RET_INF_OF (error 24) / RET_ZERO_UF (error 25) depending on the sign of the exponent offset.
