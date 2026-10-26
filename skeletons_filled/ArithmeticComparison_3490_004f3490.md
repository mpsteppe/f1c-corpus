## ArithmeticComparison_3490_004f3490 — triple absolute-value normalizer

**Summary:** Reads three long double values via string parser, then enforces non-negativity by applying fabs to each. Used during vehicle file parsing to normalize parameter tuples.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x90 | RW | — | first value of 3-element tuple, made absolute |
| this | 0x98 | RW | — | second value of 3-element tuple, made absolute |
| this | 0xA0 | RW | — | third value of 3-element tuple, made absolute |

**Written-by note (persistence):**
- this 0x90: recalc every frame — external poke does NOT persist
- this 0x98: recalc every frame — external poke does NOT persist
- this 0xA0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00565aa0 | sub_565AA0 | parses string input into 3 long double output values |

**Guard conditions:** sub_565AA0 must return non-zero (parse success) to apply absolute values. Parse failure skips fabs and returns 0.
