## ReplayStateCopy_0042ecc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1640 | RW | — | [LLM] |
| this | 0x1680 | RW | — | [LLM] |
| this | 0x1970 | R | — | [LLM] |
| this | 0x1978 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1640: recalc every frame — external poke does NOT persist
- this 0x1680: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042de10 | GearRatioConfigFileReader | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
