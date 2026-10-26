## WheelSpringDamperForceAndSteering_004e3d00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelForceCalculationSpringDamperTorque (004e5470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x54 | RW | — | [LLM] |
| this | 0x58 | RW | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x70 | R | — | [LLM] |
| this | 0x90 | R | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xBC | R | — | [LLM] |
| this | 0xC0 | R | — | [LLM] |
| this | 0xC4 | RW | — | [LLM] |
| this | 0xC8 | RW | — | [LLM] |
| this | 0xD8 | RW | — | [LLM] |
| this | 0xDC | RW | — | [LLM] |
| this | 0xE0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x48: recalc every frame — external poke does NOT persist
- this 0x4C: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x54: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0xC4: recalc every frame — external poke does NOT persist
- this 0xC8: recalc every frame — external poke does NOT persist
- this 0xD8: recalc every frame — external poke does NOT persist
- this 0xDC: recalc every frame — external poke does NOT persist
- this 0xE0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 005ad148 | flt_5AD148 | R | ContactProximityThreshold [DERIVED] |
| 005ad168 | flt_5AD168 | R | DWLimitThreshold [DERIVED] (also: ` — suspension type threshold (double-wishbone limit) |
| 005ad16c | flt_5AD16C | R | TrackCamberFactor1 [DERIVED] |
| 005ad170 | flt_5AD170 | R | PhysicsCamberFactor [DERIVED] (also: ` — track/camber factors) |
| 005ad178 | dbl_5AD178 | R | CasterAngleThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xBC | == | 1065353216 → 1.0f | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
