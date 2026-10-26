## VertexParticleBufferAllocator_0054f830 — ParticleVertexBufferAllocation

**Summary:** Allocates and initializes a particle vertex buffer: frees old buffer, allocates new descriptor and entry array, copies source position data, computes maximum camera-to-particle distance for LOD culling.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraViewSetupFromVehiclePosition (0045af50), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1E0)+0x8) | 0x0 | RW | 0 | particle entry flags (initially 0) |
| *(*(this+0x1E0)+0x8) | 0x4 | RW | — | particle position X |
| *(*(this+0x1E0)+0x8) | 0x8 | RW | — | particle position Y |
| *(*(this+0x1E0)+0x8) | 0xC | RW | — | particle position Z |
| *(*(this+0x1E0)+0x8) | 0x1C | RW | — | particle secondary vector/UV component |
| *(*(this+0x1E0)+0x8) | 0x20 | RW | — | particle secondary vector/UV component |
| *(*(this+0x1E0)+0x8) | 0x24 | RW | — | particle secondary vector/UV component |
| *(this+0x1E0) | 0x0 | RW | — | descriptor entry count |
| *(this+0x1E0) | 0x8 | RW | — | pointer to particle entry array |
| *(this+0x204) | 0xDC | R | — | camera position X for distance computation |
| *(this+0x204) | 0xE0 | R | — | camera position Y for distance computation |
| *(this+0x204) | 0xE4 | R | — | camera position Z for distance computation |
| this | 0x1E0 | RW | 0 | pointer to particle buffer descriptor |
| this | 0x204 | R | — | pointer to camera position float array |

**Written-by note (persistence):**
- *(*(this+0x1E0)+0x8) 0x0: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0x4: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0x8: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0xC: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0x1C: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0x20: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0x24: recalc every frame — external poke does NOT persist
- *(this+0x1E0) 0x0: recalc every frame — external poke does NOT persist
- *(this+0x1E0) 0x8: recalc every frame — external poke does NOT persist
- this 0x1E0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054eaf0 | ShortComputation_eaf0 | initializes a single particle entry struct |
| 0054eb20 | sub_54EB20 | initializes particle buffer descriptor |
| 0054fa50 | LinkedNodeDestruction | frees previous buffer's linked nodes |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocates heap memory (malloc/new wrapper) |

**Guard conditions:** If *(this+0x1E0) is non-null AND *(*(this+0x1E0)+8) is non-null → free old buffer first. Otherwise skip cleanup. Always proceeds to allocate new buffer.
