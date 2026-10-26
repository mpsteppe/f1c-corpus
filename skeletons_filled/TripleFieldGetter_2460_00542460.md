## TripleFieldGetter_2460_00542460 — Get three fields (position/orientation X, Y, Z)

**Summary:** Reads values at offsets 0x24, 0x28, 0x2C and writes them through output pointers a2, a3, a4 respectively. Each output pointer is individually null-guarded.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainCameraDirectorUpdate (0040ca30), RaySphereIntersectionTest (004dc960), CameraViewportRenderSetup (004fbd70), TwoCallDelegation_2420 (00542420)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | position/orientation X |
| this | 0x28 | R | — | position/orientation Y |
| this | 0x2C | R | — | position/orientation Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer (a2, a3, a4) individually guarded: if null, that field is skipped. Non-null → write the field value.
