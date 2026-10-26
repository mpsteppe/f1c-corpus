## sub_4E5AE0_004e5ae0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStateMachine (004e4e60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34A8 | R | — | [LLM] |
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | RW | — | [LLM] |
| this | 0x34D8 | RW | — | [LLM] |
| this | 0x34DC | RW | — | [LLM] |
| this | 0x34EC | RW | — | [LLM] |
| this | 0x34F0 | RW | — | RenderX [FACT] |
| this | 0x34F4 | RW | — | RenderY [FACT] |
| this | 0x34F8 | RW | — | RenderZ [FACT] |
| this | 0x34FC | RW | — | [LLM] |
| this | 0x3500 | RW | — | [LLM] |
| this | 0x3504 | RW | — | [LLM] |
| this | 0x3508 | RW | — | [LLM] |
| this | 0x350C | RW | — | [LLM] |
| this | 0x3518 | R | — | [LLM] |
| this | 0x3528 | R | — | [LLM] |
| this | 0x352C | R | — | [LLM] |
| this | 0x3530 | R | — | [LLM] |
| this | 0x3534 | RW | — | [LLM] |
| this | 0x3538 | RW | — | [LLM] |
| this | 0x353C | RW | — | [LLM] |
| this | 0x3540 | RW | — | [LLM] |
| this | 0x3544 | RW | — | [LLM] |
| this | 0x3548 | RW | — | [LLM] |
| this | 0x354C | R | — | [LLM] |
| this | 0x3550 | R | — | [LLM] |
| this | 0x3554 | R | — | [LLM] |
| this | 0x3558 | R | — | [LLM] |
| this | 0x355C | R | — | [LLM] |
| this | 0x3560 | R | — | [LLM] |
| this | 0x3564 | R | — | [LLM] |
| this | 0x3568 | R | — | [LLM] |
| this | 0x356C | R | — | [LLM] |
| this | 0x3570 | R | — | [LLM] |
| this | 0x35B0 | R | — | [LLM] |
| this | 0x36A8 | R | — | [LLM] |
| this | 0x37A0 | R | — | [LLM] |
| this | 0x3898 | R | — | [LLM] |
| this | 0x3964 | RW | — | [LLM] |
| this | 0x3978 | R | — | [LLM] |
| this | 0x398C | R | — | [LLM] |
| this | 0x3990 | R | — | fuelConsumptionFactor [CONFIRMED] |
| this | 0x3994 | RW | 0 | [LLM] |
| this | 0x3998 | R | — | [LLM] |
| this | 0x399C | R | — | [LLM] |
| this | 0x39A0 | R | — | EngineRPM [CONFIRMED] |
| this | 0x39B4 | R | — | [LLM] |
| this | 0x39C8 | R | — | [LLM] |
| this | 0x39EC | R | — | [LLM] |
| this | 0x39F0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist
- this 0x34EC: recalc every frame — external poke does NOT persist
- this 0x34F0: recalc every frame — external poke does NOT persist
- this 0x34F4: recalc every frame — external poke does NOT persist
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x3504: recalc every frame — external poke does NOT persist
- this 0x3508: recalc every frame — external poke does NOT persist
- this 0x350C: recalc every frame — external poke does NOT persist
- this 0x3534: recalc every frame — external poke does NOT persist
- this 0x3538: recalc every frame — external poke does NOT persist
- this 0x353C: recalc every frame — external poke does NOT persist
- this 0x3540: recalc every frame — external poke does NOT persist
- this 0x3544: recalc every frame — external poke does NOT persist
- this 0x3548: recalc every frame — external poke does NOT persist
- this 0x3964: recalc every frame — external poke does NOT persist
- this 0x3994: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e43d0 | sub_4E43D0 | [LLM] |
| 00567120 | sub_567120 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
