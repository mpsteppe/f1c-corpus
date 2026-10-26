## ScalePropagate_004e2ca0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleRespawnReset (004e0800), sub_4F0D20 (004f0d20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x44 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x970 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x970: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e2a00 | SceneGraphChildVelocityScaling | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
