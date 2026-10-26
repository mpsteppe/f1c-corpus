## ParticleEffectWorldTransform_004e16f0 — ParticleEffectWorldTransform

**Summary:** Transforms 17 particle emitter positions from local space to world space using a 3x3 rotation matrix and translation vector, then spawns particles. Part of particle effect rendering system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x998 | R | — | Emitter local direction/offset X component |
| this | 0x99C | R | — | Emitter local direction/offset Y component |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008aceb8 | dword_8ACEB8 | R | PhysicsFlagCounter [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cce90 | ParticleSpawnFunction | Spawns a particle at the computed world-space position |

**Guard conditions:** Checks dword_8ACEB8 (global particle system instance). If zero, returns immediately. Checks byte at this+0x978 (emitter active flag) for each of 17 emitter slots; if zero, skips that emitter's particle spawn.
