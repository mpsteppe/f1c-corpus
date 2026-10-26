## CircularBufferSlotAlloc_004cb540 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleCollisionSpark (004cb620), ParticleTrailEmitter (004cbc50), sub_4CC970 (004cc970), ParticleSpawnFunction (004cce90), WheelContactParticle (004cd6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x60 | RW | 0 | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x60: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00558a30 | sub_558A30 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
