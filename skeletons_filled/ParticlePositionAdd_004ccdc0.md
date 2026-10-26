## ParticlePositionAdd_004ccdc0 — ParticlePositionAddWithWind

**Summary:** Computes wind direction from (a3-a2) vector, adds noise from weather noise table, then applies the resulting offset to each particle's position in the array. Finally calls ParticleEffectPhysics for physics update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainCameraDirectorUpdate (0040ca30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | R | — | particle count (this[25]) |
| this | 0x68 | R | — | particle array pointer (this[26]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ccb30 | ParticleEffectPhysics | run physics update after position offsets applied |

**Guard conditions:** None — unconditional; always iterates all particles and applies wind offset.
