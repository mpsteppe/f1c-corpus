## sub_4FEDA0_004feda0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5005A0 (005005a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54c0 | dbl_5D54C0 | R | [LLM] |
| 005d54d0 | dbl_5D54D0 | R | [LLM] |
| 005d5b98 | dbl_5D5B98 | R | [LLM] |
| 005d5f68 | dbl_5D5F68 | R | [LLM] |
| 005d5fb8 | dbl_5D5FB8 | R | [LLM] |
| 005d6020 | dbl_5D6020 | R | [LLM] |
| 005fc214 | aName_1 | R | [LLM] |
| 00612540 | aDDevNascar2004_22 | R | [LLM] |
| 0061256c | aFirstDataPoint | R | [LLM] |
| 006125a4 | aNeedAtLeastDDa | R | [LLM] |
| 006125e0 | aTireSlipCurveS | R | [LLM] |
| 00612618 | aSkippingUnexpe | R | [LLM] |
| 00612654 | off_612654 | R | [LLM] |
| 00612658 | asc_612658 | R | [LLM] |
| 0061265c | aData | R | [LLM] |
| 00612664 | aDropofffunctio | R | [LLM] |
| 00612674 | aStep | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 007d7920 | dword_7D7920 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00500f90 | sub_500F90 | [LLM] |
| 00500fe0 | sub_500FE0 | [LLM] |
| 00577b60 | sub_577B60 | [LLM] |
| 00577e50 | sub_577E50 | [LLM] |
| 00578450 | sub_578450 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00579f40 | sub_579F40 | [LLM] |
| 0057a490 | sub_57A490 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005be900 | _strstr | [LLM] |
| 005bf16b | _strtok | [LLM] |
| 005bf71b | _sscanf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | <= | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Name`
- `D:\dev\NASCAR_2004\Source\tire_manager.cpp`
- `D:\dev\NASCAR_2004\Source\tire_manager.cpp`
- `D:\dev\NASCAR_2004\Source\tire_manager.cpp`
- `D:\dev\NASCAR_2004\Source\tire_manager.cpp`
- `First data point must be zero in tire slip curve "%s"`
- `Need at least %d data points found for tire slip curve "%s"`
- `Tire slip curve step must be positive for curve "%s"`
- `Skipping unexpected data point "%s" in tire slip curve "%s"`
- `%lf`
- `DATA:`
- `DropoffFunction`
- `Step`
