## VirtualDispatchHelper_0040c870 — VirtualDispatchHelper

**Summary:** Dispatches to a virtual method at vtable+0x18 on a component object, with early-out on cached result. Part of component-based dispatch system used across rendering, physics, and particles.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainCameraDirectorUpdate (0040ca30), ShortComputation_dd80 (0040dd80), ModuleInitializationWithFallback (00434820), VehicleVisibilityCulling (004b3dc0), sub_4CC840 (004cc840), ParticleSpawnFunction (004cce90), ParticleSystemUpdateWithWindAndDamping (004cd220), WeatherParticleUpdate (004cfcc0), F_3DDistanceCheckAccumulate (004d0b20), VehicleStateUpdate_19d0 (004e19d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x18 | R | — | Virtual method at vtable offset 0x18 (7th method) on component object |
| this | 0x8 | R | — | Pointer to component object with vtable for dispatch |
| this | 0x28 | R | — | Cached result value; if non-zero, returned immediately (early-out) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
*(none)*

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
*(indirect via vtable)*

**Guard conditions:** this[10] (offset 0x28) non-zero → return cached value immediately (block further dispatch). this[2] (offset 0x8) non-zero → dispatch to virtual method. this[2] zero → return 0.
