## sub_4FAF60_004faf60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsNodePropagationWithDistanceFalloff (00401c90), SurfaceHeightfieldCollisionCallback (00404250), MultiPhaseProcessingStateMachine (00404460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x110)+0x110)+0x110) | 0x110 | R | — | [LLM] |
| *(*(this+0x110)+0x110) | 0x94 | R | — | [LLM] |
| *(*(this+0x110)+0x110) | 0x9C | R | — | [LLM] |
| *(this+0x10C) | 0xA4 | R | — | [LLM] |
| *(this+0x10C) | 0xA8 | R | — | [LLM] |
| *(this+0x10C) | 0xAC | R | — | [LLM] |
| *(this+0x110) | 0x94 | R | — | [LLM] |
| *(this+0x110) | 0x98 | R | — | [LLM] |
| *(this+0x110) | 0x9C | R | — | [LLM] |
| *(this+0x110) | 0x110 | R | — | [LLM] |
| *(this+0x114) | 0x94 | R | — | [LLM] |
| *(this+0x114) | 0x98 | R | — | [LLM] |
| *(this+0x114) | 0x9C | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x54 | RW | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x6C | RW | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0x98 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA0 | R | — | [LLM] |
| this | 0xA4 | RW | — | [LLM] |
| this | 0xA8 | RW | — | [LLM] |
| this | 0xAC | RW | — | [LLM] |
| this | 0xB8 | RW | 1070141403 → 1.5708f | [LLM] |
| this | 0xBC | RW | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x12C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x54: recalc every frame — external poke does NOT persist
- this 0x68: recalc every frame — external poke does NOT persist
- this 0x6C: recalc every frame — external poke does NOT persist
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xB8: recalc every frame — external poke does NOT persist
- this 0xBC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e660 | flt_59E660 | R | VehicleBodyDamping [DERIVED] |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 005ad274 | flt_5AD274 | R | Suspension_BumpTravel [DERIVED] |
| 005ea2cc | dword_5EA2CC | R | AiOvertakeDistanceThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005894a0 | FloatFunctionPassThrough | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
