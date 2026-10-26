## WheelTireForceUpdate_004ed810 — wheel tire temperature update with thermal model

**Summary:** Updates per-corner tire temperatures using convection and friction heating model, normalizes to [0,1] range. Part of tire thermal dynamics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8CC | RW | — | wheel struct base pointer for per-corner parameter access |
| this | 0x3500 | R | — | corner Z position value (absolute value used for friction heating) |
| this | 0x35B0 | R | — | friction/slip heat input corner 0/2 (abs) |
| this | 0x35D8 | R | — | friction/slip heat coefficient corner 0/2 |
| this | 0x35DC | RW | — | tire temperature corner 0 |
| this | 0x36A8 | R | — | friction/slip heat input corner 1/3 (abs) |
| this | 0x36D0 | R | — | friction/slip heat coefficient corner 1/3 |
| this | 0x36D4 | RW | — | tire temperature corner 1 |
| this | 0x37A0 | R | — | friction/slip heat input value |
| this | 0x37C8 | R | — | friction/slip heat coefficient |
| this | 0x37CC | RW | — | tire temperature corner 2 |
| this | 0x3898 | R | — | friction/slip heat input value |
| this | 0x38C0 | R | — | friction/slip heat coefficient |
| this | 0x38C4 | RW | — | tire temperature corner 3 |
| this | 0x3A38 | R | — | thermal model convection coefficient |
| this | 0x3A3C | R | — | thermal model convection ambient factor |
| this | 0x3A40 | R | — | thermal model friction heating coefficient |
| this | 0x3A4C | R | — | thermal model convection coefficient 2 |
| this | 0x3A50 | R | — | thermal model ambient temperature factor 2 |
| this | 0x3A54 | R | — | thermal model friction heating coefficient 2 |

**Written-by note (persistence):**
- this 0x8CC: recalc every frame — external poke does NOT persist
- this 0x35DC: recalc every frame — external poke does NOT persist
- this 0x36D4: recalc every frame — external poke does NOT persist
- this 0x37CC: recalc every frame — external poke does NOT persist
- this 0x38C4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059eec0 | dbl_59EEC0 | R | NormalizationScale [DERIVED] |
| 0059eec8 | dbl_59EEC8 | R | NormalizationBias [DERIVED] |
| 005acafc | flt_5ACAFC | R | TemperatureOffset [DERIVED] (also: ` — additive offset) |
| 008afef0 | flt_8AFEF0 | R | TemperatureOffset [CONFIRMED] (also: GlobalForceReference, ` — ambient temperature base) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early-return guards. Temperature normalized (temp-1023.16)*0.004 clamped to [0,1] per corner in loop.
