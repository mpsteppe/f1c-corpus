## ArithmeticComparison_b4a0_0054b4a0 — Triple float field query

**Summary:** Reads three adjacent fields (offsets 0x2C, 0x30, 0x34) and writes them to caller-provided output pointers if non-null. Returns `a4`.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** DualMatrixTransformMultiply (0054b530)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | First value (written to `*a2` if a2 non-null) |
| this | 0x30 | R | — | Second value (written to `*a3` if a3 non-null) |
| this | 0x34 | R | — | Third value (written to `*a4` if a4 non-null) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer (a2, a3, a4) null-checked independently — null skips that write. No early return.
