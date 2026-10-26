## F_3x3MatrixTransformWithTranslation_004e9bd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionAndWheelPhysics (004e5f60), AIRacingLinePathFollowing (004e9ca0), ParticleEffectUpdateDispatch (004eb430), AIVehiclePathPositionTracking (004ef7c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | R | — | [LLM] |
| this | 0x34D8 | R | — | [LLM] |
| this | 0x34DC | R | — | [LLM] |
| this | 0x3B54 | R | — | [LLM] |
| this | 0x3B58 | R | — | [LLM] |
| this | 0x3B5C | R | — | [LLM] |
| this | 0x3B60 | RW | — | [LLM] |
| this | 0x3B64 | RW | — | [LLM] |
| this | 0x3B68 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x3B60: recalc every frame — external poke does NOT persist
- this 0x3B64: recalc every frame — external poke does NOT persist
- this 0x3B68: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
