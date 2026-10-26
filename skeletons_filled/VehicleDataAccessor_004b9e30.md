## VehicleDataAccessor_004b9e30 — VehicleDataAccessor

**Summary:** Reads a DWORD at offset 0xF8C from a vehicle object pointer obtained via double indirection through `this`, returning an integer vehicle data field.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TelemetryDisplaySwitch (0047dbe0), ArithmeticComparison_9fb0 (004b9fb0), RenderTickUpdate (004c8b70), sub_4CC970 (004cc970), ParticleEffectPhysics (004ccb30), ParticleSpawnFunction (004cce90), ParticleSystemUpdateWithWindAndDamping (004cd220), WheelContactParticle (004cd6c0), WeatherParticleUpdate (004cfcc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xF8C | R | — | vehicle data field (e.g. speed or gear) |
| this | 0x0 | R | — | pointer to vehicle object pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always returns the dereferenced value.
