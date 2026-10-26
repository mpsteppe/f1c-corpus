## UICameraModeDispatchWithVehicleDataRead_0040f550 — UICameraModeDispatchWithVehicleDataRead

**Summary:** Mode-based dispatch: integrates physics state and sets flag for modes 0-5, or reads vehicle telemetry position from sub-object for mode 6. Part of UI/camera/vehicle data integration system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectUpdateDispatch (004eb430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x34D4 | R | — | Sub-object field at offset 13524 → copied to position X (case 6) |
| *(this+0x20) | 0x34D8 | R | — | Sub-object field at offset 13528 → copied to position Y (case 6) |
| *(this+0x20) | 0x34DC | R | — | Sub-object field at offset 13532 → copied to position Z (case 6) |
| this | 0xA | RW | 1 | Activity flag byte set to 1 after physics integration (modes 0-5) |
| this | 0xC | RW | — | Position X component (this[3]) |
| this | 0x10 | RW | — | Position Y component (this[4]) |
| this | 0x14 | RW | — | Position Z component (this[5]) |
| this | 0x1C | R | — | Mode selector (this[7], values 0-6) |
| this | 0x20 | R | — | Sub-object pointer (this[8]) with vehicle telemetry data |

**Written-by note (persistence):**
- this 0xA: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f5dc | jpt_40F55B | R | Jump table for 7-case mode dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00459a40 | PhysicsStateIntegration | Integrates physics state into position fields |
| 004ec080 | VehicleTelemetryPositionAccumulator | Accumulates vehicle telemetry position data |

**Guard conditions:** this[7] (mode) 0-5 → PhysicsStateIntegration + set flag at +0xA. Mode 6 → VehicleTelemetryPositionAccumulator + copy position from sub-object. default → skip.
