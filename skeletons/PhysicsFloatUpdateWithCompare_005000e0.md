## PhysicsFloatUpdateWithCompare_005000e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UtilityFunction_3d50 (00463d50), CollisionTestWithThreshold (00500560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044c4c0 | SpatialGridQuery | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
