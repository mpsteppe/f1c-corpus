## unknown_libname_3_0063b420 — CRT denormal-aware long-double divide helper

**Summary:** MSVC CRT math-support routine that computes an extended-precision (long double) quotient (a2 divided by a1) while detecting denormal/special operands: it rescales the denominator in a normalization loop and, when the operands remain subnormal, applies a scaled-division correction using CRT float constants. Used by several sibling CRT helpers (unknown_libname_4/5/6/15/16) as the shared division primitive.

**Called by:** unknown_libname_4 (0063b537), unknown_libname_5 (0063b9d6), unknown_libname_6 (0063b9e9), unknown_libname_15 (0063bbfc), unknown_libname_16 (0063bc11)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 009131b0 | byte_9131B0 | R | 16-entry byte lookup table indexed by `(2*DWORD1(a1) ^ 0xE000000) >> 28`; nonzero entry authorizes the scaled-division path, zero forces plain divide |
| 009131c0 | flt_9131C0 | R | Scale constant applied to both numerator and denominator in the final correction branch (default case) |
| 009131c4 | flt_9131C4 | R | Alternative scale constant used in the final correction branch when the denominator exponent field equals 1 |
| 009131c8 | flt_9131C8 | R | Rescale factor multiplied into the denominator (v3) on each iteration of the normalization loop |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- Outer loop runs while doubling the denominator mantissa word does NOT carry (`!__CFADD__(DWORD1(a1), DWORD1(a1))`, i.e. bit 31 of DWORD1(a1) clear). Inside it: if `*(_QWORD *)&a1 == 0` or `(HIWORD(a1) & 0x7FFF) != 0` (denominator zero or normalized exponent) → return plain `v2 / v3`. If a2 has a nonzero exponent: exponent `0x7FFF` (inf/NaN) or mantissa carry → plain divide. If a2 exponent is zero and its mantissa doubling carries → plain divide. Otherwise the denominator is rescaled by `flt_9131C8` and the loop repeats.
- After the loop exits (mantissa carry case): `v4 = (2*DWORD1(a1)) ^ 0xE000000`; if `(v4 & 0xE000000) != 0` → plain divide; if `byte_9131B0[v4 >> 28] == 0` → plain divide.
- Then: if `(HIWORD(a1) & 0x7FFF)` is 0 or 0x7FFF (denormal/zero or inf/NaN exponent) → plain divide.
- Final branch: if `(HIWORD(a2) & 0x7FFF) == 1` → return `v2 * flt_9131C4 / (v3 * flt_9131C4)`; otherwise → return `v2 * flt_9131C0 / (v3 * flt_9131C0)`.
