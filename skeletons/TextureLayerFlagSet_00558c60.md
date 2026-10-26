## TextureLayerFlagSet_00558c60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleCollisionSpark (004cb620), WheelRenderObjectPerFrameUpdate (004cb860), ParticleTrailEmitter (004cbc50), ParticleInstanceUpdate (004cc1d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x20: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053b200 | MultiFieldSetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
