## OpponentProximityScanTeamRecognition_0042a7d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4174) | 0x4894 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x4 | R | — | [LLM] |
| this | 0x34E0 | R | — | [LLM] |
| this | 0x34E8 | R | — | [LLM] |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4174 | RW | — | [LLM] |
| this | 0x41A8 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x41B4 | RW | 18446744073709551615 | [LLM] |
| this | 0x41B8 | RW | — | [LLM] |
| this | 0x41EC | RW | — | [LLM] |
| this | 0x41FC | RW | — | [LLM] |
| this | 0x4230 | RW | — | [LLM] |
| this | 0x4240 | RW | — | [LLM] |
| this | 0x4274 | RW | — | [LLM] |
| this | 0x4284 | RW | — | [LLM] |
| this | 0x42B8 | RW | — | [LLM] |
| this | 0x42CC | RW | 0 | [LLM] |
| this | 0x42D0 | R | — | [LLM] |
| this | 0x42DC | RW | 1140457472 → 500.0f | [LLM] |
| this | 0x4420 | RW | 1075838976 → 2.5f | [LLM] |
| this | 0x448C | R | — | [LLM] |
| this | 0x4494 | R | — | [LLM] |
| this | 0x4578 | RW | 0 | [LLM] |
| this | 0x45FC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4174: recalc every frame — external poke does NOT persist
- this 0x41A8: recalc every frame — external poke does NOT persist
- this 0x41B4: recalc every frame — external poke does NOT persist
- this 0x41B8: recalc every frame — external poke does NOT persist
- this 0x41EC: recalc every frame — external poke does NOT persist
- this 0x41FC: recalc every frame — external poke does NOT persist
- this 0x4230: recalc every frame — external poke does NOT persist
- this 0x4240: recalc every frame — external poke does NOT persist
- this 0x4274: recalc every frame — external poke does NOT persist
- this 0x4284: recalc every frame — external poke does NOT persist
- this 0x42B8: recalc every frame — external poke does NOT persist
- this 0x42CC: recalc every frame — external poke does NOT persist
- this 0x42DC: recalc every frame — external poke does NOT persist
- this 0x4420: recalc every frame — external poke does NOT persist
- this 0x4578: recalc every frame — external poke does NOT persist
- this 0x45FC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e980 | flt_59E980 | R | AISeasonPointsThreshold [DERIVED] |
| 0059e984 | flt_59E984 | R | AIOvertakeDistance [DERIVED] |
| 0059e988 | flt_59E988 | R | AISpatialProximityThreshold [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea2cc | dword_5EA2CC | R | AiOvertakeDistanceThreshold [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce2f0 | unk_7CE2F0 | R | Unknown_AI_Struct_7CE2F0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423ad0 | F_2DVectorDirectionProjection | [LLM] |
| 004a4710 | FindNearestVehicle | [LLM] |
| 004c7bd0 | sub_4C7BD0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x41B4 | == | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
