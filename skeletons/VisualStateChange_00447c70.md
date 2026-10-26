## VisualStateChange_00447c70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_42C440 (0042c440), VehicleMainPhysicsUpdate (004441f0), ConditionalBufferCall (004f1c00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C58 | RW | — | [LLM] |
| this | 0x1F00 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1C58: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f87c0 | HUDElementConfig | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
