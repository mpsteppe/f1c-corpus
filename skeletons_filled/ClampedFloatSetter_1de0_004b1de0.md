## ClampedFloatSetter_1de0_004b1de0 — Clamped float value setter

**Summary:** Stores a float value (passed as int a2) at this+0x14, then clamps it between lower bound (this+0x1C as float) and upper bound (this+0x20 as float). If value < lower bound, snaps to lower bound. If value > upper bound, snaps to upper bound.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DrivingModeParameterSetup (004adf10), sub_4AE9F0 (004ae9f0), PhysicsParameterInitialization (004af3a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Float value being set (destination field) |
| this | 0x1C | R | — | Lower bound float for clamping |
| this | 0x20 | R | — | Upper bound float for clamping |

**Written-by note (persistence):**
- this 0x14: written unconditionally with a2 (bitcast float), then clamped; overwrites any previous value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always writes a2 then clamps. If value < lower bound -> clamped to lower bound. If value > upper bound -> clamped to upper bound. If within bounds -> value unchanged after initial write.
