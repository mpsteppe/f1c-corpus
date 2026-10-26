## SetErrorCodeBasedOnInputRange_00591c79 — SetTlsErrorCodeByRange

**Summary:** Maps input integer to a TLS error code: value 1 → error 33, values 2-3 → error 34, other values → no-op. Returns either TLS slot address or input cast as pointer.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalMathWithDAT005e9ad0Flag (0059168f), FloatParsingWithErrorHandling (00591bf1), sub_596175 (00596175)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 34 | TLS error code slot written with error code 33 or 34 |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058afcf | TLSOffsetGetter | retrieve TLS slot address for error code write |

**Guard conditions:** If `a1 == 1` → write error 33. Else if `1 < a1 <= 3` → write error 34. Otherwise → no-op, returns `a1` cast as pointer. Nothing blocked; all paths execute.
