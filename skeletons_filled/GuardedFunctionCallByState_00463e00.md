## GuardedFunctionCallByState_00463e00 — Particle/Sound Effect Spawner by State

**Summary:** Checks if state at +0x3FC4 equals 3; if so, calls ParticleSoundEffectSpawner on the object. Returns spawner result on match, undefined otherwise.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A00A0 (004a00a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FC4 | R | — | state value; must equal 3 to spawn effects |
| this | 0x0 | R | — | vtable/primary pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x3FC4 | == | 3 | state match for particle/sound spawn |

**Guard interpretation:** If state != 3, BLOCKED — returns uninitialized result (no spawn). PASSES only when state == 3, spawns particle/sound effect.
