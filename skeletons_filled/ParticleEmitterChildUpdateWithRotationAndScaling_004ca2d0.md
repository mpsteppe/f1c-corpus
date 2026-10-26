## ParticleEmitterChildUpdateWithRotationAndScaling_004ca2d0 — ParticleChildRotateAndScale

**Summary:** Updates child particle positions by applying a 2D rotation (sin/cos from time-varying angle) and scaling to offset components. Loops over children, writing transformed X/Z positions. Clears a visibility flag on the linked list display object afterward.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WeatherParticleUpdate (004cfcc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Time accumulator (incremented by a2 each frame) |
| this | 0x18 | R | — | Base value for scale computation (combined with RainFadeCoeff) |
| this | 0x1C | R | — | Scale multiplier for child position offset |
| this | 0x20 | R | — | Rotation speed/frequency (multiplied by accumulated time for angle) |
| this | 0x24 | R | — | Rotation basis X first component (sin coefficient for v20) |
| this | 0x28 | R | — | Rotation basis Y first component (sin coefficient for v21) |
| this | 0x2C | R | — | Rotation basis X second component (cos coefficient for v20) |
| this | 0x30 | R | — | Rotation basis Y second component (cos coefficient for v21) |
| this | 0x34 | R | — | Child count (number of child particle entries to update) |
| this | 0x38 | R | — | Pointer to child array (each entry 20 bytes: target ptr, X, Y, Z offsets, weight) |

**Written-by note (persistence):**
- this 0x14: Written every call with accumulated time. Persists frame-to-frame as running time counter.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ace98 | flt_5ACE98 | R | ParticleDampingFactor [DERIVED] |
| 008afee4 | flt_8AFEE4 | R | RainFadeCoeff [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c230 | LinkedListIndexedAccessor_c230 | Retrieves a linked list/display object to clear its rendering flag (bitmask 0xFEFFFFDF) |

**Guard conditions:** Checks flags condition at function entry — if true, skips entire body (no child update). Body executes only when flags condition is false.
