## StateTransition_004a56b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopDecisionTireCompound (0042a3d0), PitPartStateCopy (004a5330), CollisionSparkParticleEffects (004ec1a0), ActorMotionPostProcessingUpdate (004ed030), RepairServiceStateDispatcher (004ed250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x128 | RW | 1 | [LLM] |
| this | 0x12C | RW | 0 | [LLM] |
| this | 0x130 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x128: recalc every frame — external poke does NOT persist
- this 0x12C: recalc every frame — external poke does NOT persist
- this 0x130: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x128 | != | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
