## ThrottleBrakeOverride_004ee230 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x77C | RW | — | [LLM] |
| this | 0x790 | RW | — | [LLM] |
| this | 0x7A4 | RW | — | [LLM] |
| this | 0x3570 | R | — | [LLM] |
| this | 0x3994 | R | — | [LLM] |
| this | 0x3998 | R | — | [LLM] |
| this | 0x3D48 | R | — | [LLM] |
| this | 0x3D4C | R | — | [LLM] |
| this | 0x3D50 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x77C: recalc every frame — external poke does NOT persist
- this 0x790: recalc every frame — external poke does NOT persist
- this 0x7A4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005ad1f8 | dbl_5AD1F8 | R | UninitFloatMarker [DERIVED] (also: ` — Sentinel value (likely 0.0 or -1.0, indicating "use dynamic") |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
