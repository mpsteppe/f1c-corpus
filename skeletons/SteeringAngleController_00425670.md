## SteeringAngleController_00425670 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4354) | 0x94 | R | — | [LLM] |
| *(this+0x4354) | 0x9C | R | — | [LLM] |
| this | 0x34E0 | R | — | [LLM] |
| this | 0x34E4 | R | — | [LLM] |
| this | 0x34E8 | R | — | [LLM] |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F8 | R | — | RenderZ [FACT] |
| this | 0x3500 | R | — | [LLM] |
| this | 0x39FC | R | — | CurrentGear [FACT] (also: gearNumber) |
| this | 0x4354 | R | — | [LLM] |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x446C | RW | 0 | [LLM] |
| this | 0x4470 | RW | — | [LLM] |
| this | 0x4474 | RW | — | [LLM] |
| this | 0x4478 | RW | — | [LLM] |
| this | 0x447C | RW | — | [LLM] |
| this | 0x4510 | RW | 1 | driverStatus [CONFIRMED] |
| this | 0x4558 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x446C: recalc every frame — external poke does NOT persist
- this 0x4470: recalc every frame — external poke does NOT persist
- this 0x4474: recalc every frame — external poke does NOT persist
- this 0x4478: recalc every frame — external poke does NOT persist
- this 0x447C: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059e888 | flt_59E888 | R | TwoPi [DERIVED] (also: ` â€” 2Ï€ (360Â° in radians) |
| 0059e890 | dbl_59E890 | R | YawErrorToleranceRad [DERIVED] (also: ` â€” yaw error tolerance (radians) |
| 0059e898 | dbl_59E898 | R | CamberAngleLimitDeg [DERIVED] (also: ` = 90.0 (camber angle limit, degrees) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ae00 | AIClearStateFlags | [LLM] |
| 004ef930 | RaceStartCountdownStateUpdate | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x39FC | > | 2 | CurrentGear [FACT] |
| this | 0x4510 | == | 6 | driverStatus [CONFIRMED] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
