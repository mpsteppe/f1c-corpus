## ViewportPositionClamping_005425a0 — Project 3D point to screen and clamp to viewport

**Summary:** Transforms a 3D coordinate (a2) to screen space via D3D device wrapper, converts to integer pixel coordinates, then clamps within viewport bounds defined by offsets 0x54, 0x58, 0x64, 0x68.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaySphereIntersectionTest (004dc960)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | R | — | viewport width (end X offset from min) |
| this | 0x58 | R | — | viewport height (end Y offset from min) |
| this | 0x64 | R | — | viewport Y minimum clamp bound |
| this | 0x68 | R | — | viewport X minimum clamp bound |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (float threshold) |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (D3D device wrapper for coordinate transform) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | convert float to integer (truncate) |

**Guard conditions:** None — always executes.
