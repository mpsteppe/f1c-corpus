## StringComparisonWithConstantDispatch_00564530 — StringDispatchCompareOrPing

**Summary:** Compares input string to "ping" constant; if matched, returns ShortToIntFieldGetter on a1 (interprets short as int). Otherwise dispatches via DoubleCallWrapper and returns the callback result from v4[1], or returns default a3 if dispatch returns null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SendJoinRequest (00462c00), sub_563F20 (00563f20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c61ec | aPing | R | Str_Ping [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00564480 | ShortToIntFieldGetter | reads a short field from a1 and zero-extends to int (ping handler) |
| 005644f0 | DoubleCallWrapper | two-argument dispatch wrapper returning pointer |
| 00587f59 | SingleFunctionCallWrapper_7f59 | calls single-argument function pointer returning int |

**Guard conditions:** if a2 equals "ping" (aPing), takes the ping-handler path (ShortToIntFieldGetter). Otherwise: if DoubleCallWrapper returns non-null, returns v4[1] callback result; if null, returns default value a3.

