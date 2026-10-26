## QuaternionMultiplySurfaceSample_0052b561 — MMXQuaternionTransformTextureSample

**Summary:** Performs MMX/3DNow! packed 16-bit quaternion rotation and vector transform on 16 lanes of data, then samples a 1024-entry surface lookup table (texture/CLUT) using transformed coordinates. Part of 3D rendering texture-mapping pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderModeBranch (005285a6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | packed 16-bit lane 0 (MMX qword) |
| this | 0x8 | R | — | packed 16-bit lane 1 |
| this | 0x10 | R | — | packed 16-bit lane 2 |
| this | 0x18 | R | — | packed 16-bit lane 3 |
| this | 0x20 | R | — | packed 16-bit lane 4 |
| this | 0x28 | R | — | packed 16-bit lane 5 |
| this | 0x30 | R | — | packed 16-bit lane 6 |
| this | 0x38 | R | — | packed 16-bit lane 7 |
| this | 0x40 | R | — | packed 16-bit lane 8 |
| this | 0x48 | R | — | packed 16-bit lane 9 |
| this | 0x50 | R | — | packed 16-bit lane 10 |
| this | 0x58 | R | — | packed 16-bit lane 11 |
| this | 0x60 | R | — | packed 16-bit lane 12 |
| this | 0x68 | R | — | packed 16-bit lane 13 |
| this | 0x70 | R | — | packed 16-bit lane 14 |
| this | 0x78 | R | — | packed 16-bit lane 15 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b0c70 | qword_5B0C70 | R | packed constant for MMX multiply-accumulate |
| 005b0c78 | qword_5B0C78 | R | packed constant for MMX multiply-accumulate |
| 005b0c80 | qword_5B0C80 | R | packed constant for MMX multiply-accumulate |
| 005b0c88 | qword_5B0C88 | R | packed constant for MMX multiply-accumulate |
| 005b0c90 | qword_5B0C90 | R | packed constant for MMX multiply-accumulate |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — straight-line MMX code with no branches
