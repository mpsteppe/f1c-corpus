## CollisionEffectDispatch_004ce3e0 — CollisionEffectParticleDispatch

**Summary:** Dispatch collision effects (spark and trail particles) based on collision type. Iterates collision effect slots: type 1 spawns collision spark particles, type 2 spawns trail particles with throttle gating (every 20 ticks), type 0 spawns trail particles from velocity field. Incorporates weather flags for render throttling.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TireSlipForceCalculation (004472b0), sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x4 | R | — | collision effect type ID in each slot |
| this | 0x3C | R | — | effect slot count |
| this | 0x40 | R | — | pointer to effect slot array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 007c5698 | dword_7C5698 | R | SessionTickCounter [DERIVED] |
| 007cf8a8 | dword_7CF8A8 | R | RenderThrottleFrames [DERIVED] |
| 007cf9d4 | byte_7CF9D4 | R | WeatherParticleGate [DERIVED] |
| 007cf9ec | byte_7CF9EC | R | Byte_RendererFlag_F9EC [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9fb0 | ArithmeticComparison_9fb0 | compare scoring gate value |
| 004cb620 | ParticleCollisionSpark | spawn collision spark particle |
| 004cbc50 | ParticleTrailEmitter | spawn collision trail particle |

**Guard conditions:** Outer guard: ArithmeticComparison_9fb0 on scoring gate must pass. Inner guards per slot: velocity field > 0.0 check for each type. For slot type 2: distance-from-previous-position check (> 1.0) to prevent duplicate particles at same location. Render throttled by dword_7CF8A8 <= 2 / tick counter % 20 / weather gate flags.
