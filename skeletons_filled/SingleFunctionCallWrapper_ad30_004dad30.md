## SingleFunctionCallWrapper_ad30_004dad30 — LapCountToVehicleWriter

**Summary:** Writes lap/threshold value from this+0x24 into vehicle struct at offset 0x4034 via sub_4BC270. Synchronizes lap counter into vehicle data for time gap calculation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4DA9E0 (004da9e0), ArithmeticComparison_ad50 (004dad50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | Lap/threshold value written into vehicle's offset 0x4034 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bc270 | sub_4BC270 | Stores integer value into vehicle struct field at given offset |

**Guard conditions:** None — no conditional branches; always executes sub_4BC270.
