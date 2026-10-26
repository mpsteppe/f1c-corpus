## FieldSetterTrigger_0049ed00 — FieldSetterTrigger

**Summary:** Stores parameter a2 into this+0x1C then triggers UISparkleEffect. Simple field setter with side-effect call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ParamRangeClampedLerp (0049f530)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | — | Receives normalized (value - range_min) float-as-int from caller; consumed by UISparkleEffect |

**Written-by note (persistence):**
- this 0x1C: Written once per call with a2; survives in parent struct until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049ed30 | UISparkleEffect | Reads the stored field plus other struct fields to render sparkle overlay |

**Guard conditions:** None unconditional — stores a2 and calls UISparkleEffect every invocation
