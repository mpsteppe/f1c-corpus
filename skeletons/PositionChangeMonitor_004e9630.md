## PositionChangeMonitor_004e9630 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4423B0 (004423b0), CollisionAvoidanceCheck (004a6b80), PitStateUpdateMachine (004a6e50), sub_4D1D80 (004d1d80), sub_4E96C0 (004e96c0), ParticleEffectUpdateDispatch (004eb430), sub_4EE2D0 (004ee2d0), SessionStateTransition (004ef5a0), DistanceProjectionCalc (004f0050), sub_4F01B0 (004f01b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34D4 | R | — | [LLM] |
| this | 0x34D8 | R | — | [LLM] |
| this | 0x34DC | R | — | [LLM] |
| this | 0x3A9C | RW | — | [LLM] |
| this | 0x3AA0 | RW | — | [LLM] |
| this | 0x3AA4 | RW | — | [LLM] |
| this | 0x3AA8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x3A9C: recalc every frame — external poke does NOT persist
- this 0x3AA0: recalc every frame — external poke does NOT persist
- this 0x3AA4: recalc every frame — external poke does NOT persist
- this 0x3AA8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9e0 | flt_59E9E0 | R | ColorChannelScaleFactor [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403640 | sub_403640 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
