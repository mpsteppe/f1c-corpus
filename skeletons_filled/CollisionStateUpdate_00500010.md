## CollisionStateUpdate_00500010 — CollisionSurfaceStateUpdate

**Summary:** Updates collision surface contact state with new value and 3-bit type. Skips redundant updates when new value is within tolerance of current state and type matches. Depending on flag bits, either converts Euler angles to vehicle orientation or performs arithmetic comparison.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionParameterDispatch (00463d10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Current collision contact value (float) |
| this | 0x4 | RW | — | Current collision type (3-bit, from v5 & 7) |

**Written-by note (persistence):**
- this 0x0: Written on update (when early return skipped), persists until next update
- this 0x4: Written on update (when early return skipped), persists until next update

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad358 | flt_5AD358 | R | VertexCacheTolerance [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b2dd0 | VehicleOrientationFromEulerAngles | Convert Euler angles to vehicle orientation matrix |
| 004b32a0 | sub_4B32A0 | Alternative orientation/state update path |
| 004b3a90 | ArithmeticComparison_3a90 | Compare and store collision data for non-orientation updates |
| 005001f0 | FloatComparisonCheck | Check if float value passes threshold/tolerance test |

**Guard conditions:** Early return 0 (skip update) if v13 in [current_value - 5.0, current_value] AND (v5 & 7) matches current type AND FloatComparisonCheck passes. Otherwise proceeds with update. If flags (a3+0) & 0xFC0000 != 0 → orientation path (VehicleOrientationFromEulerAngles or sub_4B32A0). Else → ArithmeticComparison_3a90 path.
