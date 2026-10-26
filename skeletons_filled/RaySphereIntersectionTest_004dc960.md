## RaySphereIntersectionTest_004dc960 — 3D ray-sphere intersection test

**Summary:** Performs a ray-sphere intersection test: computes squared distance between a point (a2) and a retrieved 3D vector, compares against radius squared (a5), applies viewport clamping via D3D device wrapper, and returns whether the intersection is valid and in front of the camera.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49F870 (0049f870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First component of 3D vector (camera/ray position) |
| this | 0x4 | R | — | Second component of 3D vector |
| this | 0x8 | R | — | Third component of 3D vector |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00542400 | StructFieldArrayCopy | Copy struct/transform field array for intersection calculation |
| 00542460 | TripleFieldGetter_2460 | Retrieve 3-component vector (camera/ray origin) |
| 005424e0 | sub_5424E0 | Compute offset/subtraction for position delta |
| 005425a0 | ViewportPositionClamping | Clamp hit position to viewport bounds |

**Guard conditions:** Two guards: (1) if squared distance `v10 > a5 * a5` (radius squared), return 0 (too far); (2) if `v21 <= 0.0` (behind camera / negative direction), return 0. Both block (miss). PASSES (hit, return 1) when both conditions false.
