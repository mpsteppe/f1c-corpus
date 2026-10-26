## D3DShaderConstantSetup_0044fcc0 — Set up D3D shader constants for force feedback

**Summary:** Polls device state, converts raw state to float shader constants, applies dead zone, clamping, and smoothing for each of 8 force-feedback axes. Writes additional constant data (direction flags and sign bits) for shader use. Called per-frame from the collision update path.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4537B0 (004537b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x80)+0x0) | 0x1C | R | — | Device vtable offset 0x1C (method 7) — reacquire device on lost state |
| *(*(this+0x80)+0x0) | 0x24 | R | — | Device vtable offset 0x24 (method 9) — read device state data (80 bytes) |
| *(*(this+0x80)+0x0) | 0x64 | R | — | Device vtable offset 0x64 (method 25) — poll/flush device |
| *(this+0x80) | 0x0 | R | — | Device vtable pointer |
| this | 0x80 | R | — | Pointer to DirectInput device object |
| this | 0x398 | RW | — | Axis base float values (8 floats, copied from device state) |
| this | 0x39C | RW | — | (part of 0x398 array) |
| this | 0x3A0 | RW | — | (part of 0x398 array) |
| this | 0x3A4 | RW | — | (part of 0x398 array) |
| this | 0x3A8 | RW | — | (part of 0x398 array) |
| this | 0x3AC | RW | — | (part of 0x398 array) |
| this | 0x3B0 | RW | — | (part of 0x398 array) |
| this | 0x3B4 | RW | — | (part of 0x398 array) |
| this | 0x3B8 | RW | — | Axis output shader values (8 floats) |
| this | 0x3E8 | RW | — | Shader constant 4-vector (X) from device state byte 32+ |
| this | 0x3EC | RW | — | Shader constant 4-vector (Y) |
| this | 0x3F0 | RW | — | Shader constant 4-vector (Z) |
| this | 0x3F4 | RW | — | Shader constant 4-vector (W) |

**Written-by note (persistence):**
- this 0x398: written from device state each frame; external overwrites
- this 0x39C–0x3B4: same array as above
- this 0x3B8: computed each frame via smoothing/clamping; external overwrites
- this 0x3E8–0x3F4: written from device state each frame; external overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** BLOCKED if device pointer at 0x80 is null → skip everything. On device-lost error (-2147024884 or -2147024866), reacquires device and retries read; if reacquire fails, returns error. PASSES on successful device poll.
