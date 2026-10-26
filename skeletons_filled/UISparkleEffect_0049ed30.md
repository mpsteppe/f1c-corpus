## UISparkleEffect_0049ed30 — UISparkleEffectRender

**Summary:** Renders a 4-point sparkle/star graphic around a center position using angular interpolation and color-coded vertices. Reads rotation mode, angle, speed/duration ratios, and center coordinates from the struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FieldSetterTrigger (0049ed00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Non-null guard flag: skips entire render if zero |
| this | 0x10 | R | — | Rotation mode (0 = clockwise, 1 = counterclockwise) |
| this | 0x14 | R | — | Current angle (degrees) of sparkle |
| this | 0x18 | R | — | Target angle boundary for interpolation |
| this | 0x1C | R | — | Rotation speed numerator |
| this | 0x20 | R | — | Rotation speed denominator (divides step) |
| this | 0x3C | R | — | Center X position (pixels) |
| this | 0x40 | R | — | Center Y position (pixels) |
| this | 0x44 | R | — | Sparkle extent magnitude (half-width/height) |
| this | 0x48 | R | — | Sparkle extent magnitude (second axis) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e65c | flt_59E65C | R | CameraShakeMultiplier [DERIVED] (also: ` — camera shake multiplier / conversion factor (docs/09, 19) |
| 005acb0c | flt_5ACB0C | R | Flt_ViewportConstant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553650 | sub_553650 | Renders a colored quad/line for one sparkle vertex |
| 00587bdc | CRTFtol | Converts float to int (CRT floor) |
| 00588570 | FloatConvertWrapper | Float conversion helper |

**Guard conditions:** Checks this+0x4 != 0 — non-null PASSES (render sparkle), zero BLOCKS (skip entire body)
