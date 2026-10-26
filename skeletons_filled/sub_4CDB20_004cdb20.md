## sub_4CDB20_004cdb20 — ObjectTypeDispatchUpdate

**Summary:** Dispatches per-frame update to a type-specific handler based on object type ID at this+4. Routes to particle instance update, wheel render update, scoring timeout check, telemetry bar render, particle system physics, or full wind/damping update depending on type value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WeatherParticleUpdate (004cfcc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | object type ID (dispatch selector) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004cdb58 | jpt_4CDB2F | R | jump table for switch dispatch |
| 004cdb74 | byte_4CDB74 | R | jump table data |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| (dispatch targets) | | one of ParticleInstanceUpdate, WheelRenderObjectPerFrameUpdate, ScoringGateTimeoutCheck, TelemetryBarIndicatorRenderer, ParticleSystemUpdateWithWindAndDamping, ParticleEffectPhysics |

**Guard conditions:** Switch on this+4 value. Cases 0-4 → ParticleInstanceUpdate; 5 → WheelRenderObjectPerFrameUpdate; 6-7 → ScoringGateTimeoutCheck; 8 → TelemetryBarIndicatorRenderer; 12 → ParticleSystemUpdateWithWindAndDamping; 13 → ParticleEffectPhysics. Default → return without update.
