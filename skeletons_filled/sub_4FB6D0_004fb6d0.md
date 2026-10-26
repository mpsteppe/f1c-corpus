## sub_4FB6D0_004fb6d0 — signed-distance collision/penalty metric

**Summary:** Computes a signed distance metric between a target position and the owning object, considering direction bias, two reference points (sub-structs A and B), and Y-axis displacement. Returns the maximum of several distance-based penalties.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_403640 (00403640)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10C) | 0x0 | R | — | sub-struct A position X |
| *(this+0x10C) | 0x4 | R | — | sub-struct A position Y |
| *(this+0x10C) | 0x8 | R | — | sub-struct A position Z |
| *(this+0x110) | 0x0 | R | — | sub-struct B position X |
| *(this+0x110) | 0x4 | R | — | sub-struct B position Y |
| *(this+0x110) | 0x8 | R | — | sub-struct B position Z |
| this | 0x0 | R | — | own position X |
| this | 0x4 | R | — | own position Y |
| this | 0x8 | R | — | own position Z |
| this | 0x20 | R | — | direction vector component for signed dot product |
| this | 0x24 | R | — | direction vector component for signed dot product |
| this | 0x28 | R | — | direction vector component for signed dot product |
| this | 0x58 | R | — | bias threshold (negative direction) |
| this | 0x5C | R | — | bias threshold (positive direction) |
| this | 0x10C | R | — | pointer to sub-struct A (position reference) |
| this | 0x110 | R | — | pointer to sub-struct B (position reference) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: global frame-rate correction) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If distance to either reference point (A or B) is 0 → returns 10.0 sentinel. Otherwise computes max of signed-direction distance, distance beyond reference spheres, and Y-axis displacement beyond threshold.
