## SceneNodePositionGetter_0054b950 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleMainPhysicsUpdate (004441f0), AudioDSPStateUpdate (00448330), VTableDispatchWithNegation (004c8f80), Steward_Init (004d38f0), sub_55D5C0 (0055d5c0), sub_55ED10 (0055ed10), sub_560FE0 (00560fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | [LLM] |
| this | 0x218 | RW | — | [LLM] |
| this | 0x2EC | R | — | [LLM] |
| this | 0x2F0 | R | — | [LLM] |
| this | 0x2F4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x218: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
