## EffectParameterSetter_004f17a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3570 | RW | — | [LLM] |
| this | 0x3978 | RW | — | [LLM] |
| this | 0x397C | R | — | tireChoice [CONFIRMED] |
| this | 0x3994 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x3570: recalc every frame — external poke does NOT persist
- this 0x3978: recalc every frame — external poke does NOT persist
- this 0x3994: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
