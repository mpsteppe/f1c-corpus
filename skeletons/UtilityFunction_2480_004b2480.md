## UtilityFunction_2480_004b2480 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleOrientationFromEulerAngles (004b2dd0), sub_4B32A0 (004b32a0), SetupCarLightingAndRender (004c71c0), VehicleContactForceAccumulation (004ebc60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x22 | RW | 32767 | [LLM] |

**Written-by note (persistence):**
- this 0x1E: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x22: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e828 | flt_59E828 | R | FloatOneConstant [DERIVED] (also: ` — float 1.0 constant) |
| 005acc98 | flt_5ACC98 | R | FloatToShortClampMin [DERIVED] |
| 005acc9c | flt_5ACC9C | R | FloatClampHigh [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
