## TireScrubReset_004efae0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionSparkParticleEffects (004ec1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | [LLM] |
| this | 0x3D64 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x3D64: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007cea5c | dword_7CEA5C | R | EngineWearMode (0/2/3) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
