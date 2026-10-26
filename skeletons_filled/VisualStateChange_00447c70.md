## VisualStateChange_00447c70 — HUD element visual state transition with noise

**Summary:** Updates byte at this+0x1C58 when incoming `a2` differs from current. If HUD element activation flag at this+0x1F00 is non-zero and `a3` is 0, indexes two noise/trig tables to compute modulated alpha and scale values, then calls HUDElementConfig(40, 2, ...) to configure a HUD element with weather-influenced transparency.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_42C440 (0042c440), VehicleMainPhysicsUpdate (004441f0), ConditionalBufferCall (004f1c00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C58 | RW | — | visual state byte — current displayed/interpolated value |
| this | 0x1F00 | R | — | HUD element activation flag (non-zero = element active) |

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
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also:  random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f87c0 | HUDElementConfig | configures a HUD display element — called with (elementId=40, subType=2, alpha=v7, scale=v8) to apply noise-modulated visual properties |

**Guard conditions:** Guard 1: if byte at this+0x1C58 == a2, early return `a2` (state unchanged, no update). Guard 2: if dword at this+0x1F00 == 0, skip HUDElementConfig (HUD element inactive). Guard 3: if a3 != 0, skip HUDElementConfig (caller-skip flag set).
