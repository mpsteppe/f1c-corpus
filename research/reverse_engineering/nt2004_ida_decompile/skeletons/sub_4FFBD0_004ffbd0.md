## sub_4FFBD0_004ffbd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5005A0 (005005a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0xC | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x10 | RW | 15 | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x218 | R | — | [LLM] |
| this | 0x220 | R | — | [LLM] |
| this | 0x228 | R | — | [LLM] |
| this | 0x230 | R | — | [LLM] |
| this | 0x350 | R | — | [LLM] |
| this | 0x418 | R | — | [LLM] |
| this | 0x420 | R | — | [LLM] |
| this | 0x428 | R | — | [LLM] |
| this | 0x430 | R | — | [LLM] |
| this | 0x550 | R | — | [LLM] |
| this | 0x618 | R | — | [LLM] |
| this | 0x620 | R | — | [LLM] |
| this | 0x628 | R | — | [LLM] |
| this | 0x630 | R | — | [LLM] |
| this | 0x750 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5d40 | dbl_5D5D40 | R | [LLM] |
| 005d5e48 | dbl_5D5E48 | R | [LLM] |
| 005d5f10 | dbl_5D5F10 | R | [LLM] |
| 005ea898 | dbl_5EA898 | R | [LLM] |
| 005ea8a0 | dbl_5EA8A0 | R | [LLM] |
| 005ea8a8 | dbl_5EA8A8 | R | [LLM] |
| 005ea8b0 | dbl_5EA8B0 | R | [LLM] |
| 005fc214 | aName_1 | R | [LLM] |
| 0061267c | aTractivecurve | R | [LLM] |
| 0061268c | aBrakingcurve | R | [LLM] |
| 0061269c | aLatcurve | R | [LLM] |
| 006126a8 | aGriptemppress | R | [LLM] |
| 006126b8 | aTempandpressgr | R | [LLM] |
| 006126cc | aOptimumpressur_1 | R | [LLM] |
| 006126e0 | aOptimumpressur_0 | R | [LLM] |
| 006126f4 | aOptimumpressur | R | [LLM] |
| 00612704 | aTemperatures | R | [LLM] |
| 00612714 | aOptimumtemp | R | [LLM] |
| 00612720 | aAiwear | R | [LLM] |
| 00612728 | aAipeakslip | R | [LLM] |
| 00612734 | aAigripmult | R | [LLM] |
| 00612740 | aAisens | R | [LLM] |
| 00612748 | aSoftness | R | [LLM] |
| 00612754 | aWearrate | R | [LLM] |
| 00612760 | aAirtreadrate | R | [LLM] |
| 00612770 | aHeatdistrib | R | [LLM] |
| 0061277c | aTransfer | R | [LLM] |
| 00612788 | aHeating | R | [LLM] |
| 00612790 | aRollingresista | R | [LLM] |
| 006127a4 | aCamberlatlong | R | [LLM] |
| 006127b4 | aLongpeak | R | [LLM] |
| 006127c0 | aLatpeak | R | [LLM] |
| 006127c8 | aLoadsens | R | [LLM] |
| 006127d4 | aSpeedeffects | R | [LLM] |
| 006127e4 | aLobesperrev | R | [LLM] |
| 006127f0 | aLobezeroliftrp | R | [LLM] |
| 00612800 | aLobedwell | R | [LLM] |
| 0061280c | aLobepeak | R | [LLM] |
| 00612818 | aLobelift | R | [LLM] |
| 00612824 | aDamper_0 | R | [LLM] |
| 0061282c | aSpringkpa | R | [LLM] |
| 00612838 | aSpringbase | R | [LLM] |
| 00612844 | aWidth | R | [LLM] |
| 0061284c | aRadiusrpm | R | [LLM] |
| 00612858 | aRadius | R | [LLM] |
| 00612860 | aWetlatlong | R | [LLM] |
| 0061286c | aDrylatlong | R | [LLM] |
| 00612878 | aAll | R | [LLM] |
| 00612880 | aRight | R | [LLM] |
| 00612888 | aLeft | R | [LLM] |
| 00612890 | aRear | R | [LLM] |
| 00612898 | aFront | R | [LLM] |
| 006128a0 | aRearright_0 | R | [LLM] |
| 006128ac | aRearleft_0 | R | [LLM] |
| 006128b8 | aFrontright_0 | R | [LLM] |
| 006128c4 | aFrontleft_0 | R | [LLM] |
| 006128d0 | aNone_2 | R | [LLM] |
| 006128d8 | aWetweather | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ff780 | sub_4FF780 | [LLM] |
| 004ffaa0 | sub_4FFAA0 | [LLM] |
| 00577b60 | sub_577B60 | [LLM] |
| 00577e50 | sub_577E50 | [LLM] |
| 00578110 | sub_578110 | [LLM] |
| 00578450 | sub_578450 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 0057a490 | sub_57A490 | [LLM] |
| 005be8bc | __ftol | [LLM] |
| 005be900 | _strstr | [LLM] |
| 005beab0 | _strncpy | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Name`
- `TractiveCurve`
- `BrakingCurve`
- `LatCurve`
- `GripTempPress`
- `TempAndPressGrip`
- `OptimumPressureMult`
- `OptimumPressureBase`
- `OptimumPressure`
- `Temperatures`
- `OptimumTemp`
- `AIWear`
- `AIPeakSlip`
- `AIGripMult`
- `AISens`
- `Softness`
- `WearRate`
- `AirTreadRate`
- `HeatDistrib`
- `Transfer`
- … +31 more
