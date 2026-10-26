## ShortComputation_bad0_0049bad0 — distance-projection threshold check

**Summary:** Computes a distance projection from postProcessInput, then checks if either a ring buffer access or indexed float array lookup at that distance equals 2. Returns true if either matches.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D4C0 (0049d4c0), HUDFlagRendererMain (004d82d0), GlobalFlagSetterViaFunctionCall (0059d948)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d1cf0 | RingBufferAccessWithWrap | read a value from a ring buffer with wrap-around indexing |
| 004d1d40 | IndexedFloatArrayLookup | retrieve a float from an indexed array by index |
| 004f0050 | DistanceProjectionCalc | compute a distance or projection value from input data |

**Guard conditions:** None — function always computes and returns the OR of two equality checks. No early-exit branches.
