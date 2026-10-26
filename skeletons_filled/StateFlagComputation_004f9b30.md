## StateFlagComputation_004f9b30 — StateFlagComputation

**Summary:** Computes state flags from sub_4F9B20 result, optionally sets HUD-disable bit. Dispatches via CallWrapper_c060; if result is -2, sets audio init success flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiStepInitSequence (00495020), sub_495080 (00495080), SceneEntityCleanup (00497100), sub_4FA7E0 (004fa7e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe72 | byte_8AFE72 | W | AudioInitSuccessFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f9b20 | sub_4F9B20 | Returns base value for flag computation |
| 0055c060 | CallWrapper_c060 | Dispatches with computed flag value; returns status code |

**Guard conditions:** Sets flag bit 4 if `a1` (parameter) is non-zero OR `byte_7CE254` (DisableHUDFlag) is set. If dispatch returns -2, sets `byte_8AFE72` (AudioInitSuccessFlag) to 1.
