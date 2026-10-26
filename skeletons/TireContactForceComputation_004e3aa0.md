## TireContactForceComputation_004e3aa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelForceCalculationSpringDamperTorque (004e5470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0x90 | R | — | [LLM] |
| this | 0xCC | RW | — | [LLM] |
| this | 0xD0 | RW | — | [LLM] |
| this | 0xD4 | RW | — | [LLM] |
| this | 0xE4 | R | — | [LLM] |
| this | 0xE8 | RW | — | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x44: recalc every frame — external poke does NOT persist
- this 0x74: recalc every frame — external poke does NOT persist
- this 0xCC: recalc every frame — external poke does NOT persist
- this 0xD0: recalc every frame — external poke does NOT persist
- this 0xD4: recalc every frame — external poke does NOT persist
- this 0xE8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ad168 | flt_5AD168 | R | DWLimitThreshold [DERIVED] (also: ` — suspension type threshold (double-wishbone limit) |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044c550 | CollisionNormalFromFeature | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
