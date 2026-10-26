## ConditionalAudioParamSetup_004dfa60 — ConditionalAudioTransformSetup

**Summary:** Stores audio parameter byte at offset 0x42, then conditionally configures audio-physics transforms. If object pointer at offset 0x0 is valid: optionally mixes audio via AudioPhysicsMixWithLerp, computes dual-matrix transforms, sets flag bytes. Otherwise zeroes six DWORD fields and clears flags. Always computes Euler rotation matrix at end. Vehicle audio setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleGraphicsSceneLoader (004dfce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | object pointer, controls which path executes |
| this | 0x4 | RW | 0 | audio parameter 1, zeroed in else branch |
| this | 0x8 | RW | 0 | audio parameter 2, zeroed in else branch |
| this | 0xC | RW | 0 | audio parameter 3, zeroed in else branch |
| this | 0x10 | RW | 0 | audio parameter 4, zeroed in else branch |
| this | 0x14 | RW | 0 | audio parameter 5, zeroed in else branch |
| this | 0x18 | RW | 0 | audio parameter 6, zeroed in else branch |
| this | 0x40 | RW | 0 | transform-ready flag (1 = ready, 0 = not) |
| this | 0x41 | RW | 0 | bit-reader result flag |
| this | 0x42 | RW | — | audio parameter a2, stored unconditionally |

**Written-by note (persistence):**
- this 0x4: set to 0 in else branch; unchanged in if branch; external poke partially survives
- this 0x8: set to 0 in else branch; unchanged in if branch; external poke partially survives
- this 0xC: set to 0 in else branch; unchanged in if branch; external poke partially survives
- this 0x10: set to 0 in else branch; unchanged in if branch; external poke partially survives
- this 0x14: set to 0 in else branch; unchanged in if branch; external poke partially survives
- this 0x18: set to 0 in else branch; unchanged in if branch; external poke partially survives
- this 0x40: overwritten each call (1 or 0); no persistence
- this 0x41: overwritten each call; no persistence
- this 0x42: set to a2 each call; no persistence across calls with different a2

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e2b0 | AudioPhysicsMixWithLerp | mix audio physics parameter with linear interpolation |
| 0054b530 | DualMatrixTransformMultiply | multiply pair of 3x3 rotation/transform matrices |
| 0054c0b0 | BitFlagReader | read bit flag from a3 param into a2 |
| 00566e40 | EulerToRotationMatrix | convert Euler angles to 3x3 rotation matrix |

**Guard conditions:** If this+0x0 (object ptr) is non-null, execute full transform path (PASS). If null, zero fields and clear flags (else branch). Both paths compute Euler rotation matrix.
