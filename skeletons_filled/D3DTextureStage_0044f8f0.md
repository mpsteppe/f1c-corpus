## D3DTextureStage_0044f8f0 — Configure D3D texture stage for force-feedback

**Summary:** Sets up Direct3D texture stage parameters for force-feedback collision rendering: polls device state, configures stage flags based on axis count, and calls CollisionResponseCompute for up to 8 axes when enabled. Called from device init and parameter clamp paths.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXDeviceInitialization (0044fa60), CollisionParameterClampAndStore (0044fc20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x80)+0x0) | 0xC | R | — | Device vtable offset 0xC (method 3) — get device caps/state |
| *(*(this+0x80)+0x0) | 0x24 | R | — | Device vtable offset 0x24 (method 9) — read device state data |
| *(*(this+0x80)+0x0) | 0x64 | R | — | Device vtable offset 0x64 (method 25) — device poll/flush |
| *(this+0x80) | 0x0 | R | — | Device vtable pointer |
| this | 0x80 | R | — | Pointer to DirectInput/DirectX device object |
| this | 0x2CC | R | — | Capability flags (bit 0 = force-feedback enabled for 8 axes) |
| this | 0x2DC | R | — | Axis count — used to set stage flag bits |
| this | 0x3F8 | RW | 6271 | Texture stage control flags (initial 0x187F, OR'd with axis bits) |

**Written-by note (persistence):**
- this 0x3F8: reset to 0 then set to 6271 each call, with OR'd axis bits; external overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0044fa40 | jpt_44F9BB | R | Jump table for stage configuration cases |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044f7f0 | CollisionResponseCompute | Computes range/response params for each force-feedback axis stage |

**Guard conditions:** BLOCKED if device pointer at offset 0x80 is null → returns -1. BLOCKED if device state read fails → returns -1. BLOCKED if caps query fails → returns -1. PASSES: axes processed only when offset 0x2CC bit 0 is set (force-feedback enabled).
