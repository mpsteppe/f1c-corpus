## ArithmeticComparison_ad50_004dad50 — WriteLapToCurrentVehicle

**Summary:** Gets current vehicle index via sub_4D1B50, then writes lap/threshold from this+0x24 into that vehicle's offset 0x4034. Part of standings/time-gap calculation pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4DA9E0 (004da9e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d1b50 | sub_4D1B50 | Resolves current vehicle index from ForceFeedbackBase |
| 004dad30 | SingleFunctionCallWrapper_ad30 | Writes lap/threshold to vehicle offset 0x4034 |

**Guard conditions:** None — no conditional branches; always executes both calls.
