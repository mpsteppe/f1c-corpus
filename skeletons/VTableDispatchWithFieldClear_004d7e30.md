## VTableDispatchWithFieldClear_004d7e30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** OnScreen_Restart (0049f000), sub_4D8760 (004d8760), VehicleStateUpdate (004d9fe0), ThunkToSub4D7E30 (004db110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
