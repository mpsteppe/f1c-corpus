## ShortComputation_7d40_00407d40 — AudioDirectionTrigFromAngles

**Summary:** Computes sine and cosine of an input angle and stores them alongside 3D position/angle data (3 ints + 3 floats). Audio spatial positioning helper called during sample position/volume setting.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioSamplePositionVolumeSetter (004071f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | first of 3 int values from a2 (position/index data) |
| this | 0x5C | RW | — | second of 3 int values from a2 |
| this | 0x60 | RW | — | third of 3 int values from a2 |
| this | 0x64 | RW | — | first float from a3 (angle component) |
| this | 0x68 | RW | — | second float from a3 (angle used for sin/cos) |
| this | 0x6C | RW | — | third float from a3 (angle component) |
| this | 0x70 | RW | — | cos(a3[1]) — cosine of second angle |
| this | 0x74 | RW | — | zero (compiler-simplified multiply: -sin(a3[0]) * 0.0) |
| this | 0x78 | RW | — | sin(a3[1]) — sine of second angle |

**Written-by note (persistence):**
- this 0x58–0x60: overwritten every call from a2 triple
- this 0x64–0x6C: overwritten every call from a3 triple
- this 0x70–0x78: recomputed from a3[1] every call; external changes don't survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — function always executes unconditionally.
