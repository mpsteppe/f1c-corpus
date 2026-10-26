## FloatClamp_004646c0 — Float clamp to [lower, upper]

**Summary:** Clamps float value to range [a2, a3]. If value below a2, set to a2. If above a3, set to a3. Otherwise unchanged.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionConfigWriteback (00461900), DrivingModeParameterSetup (004adf10), CarPartVisibilityController (004ae490), sub_4AE9F0 (004ae9f0), PhysicsParameterInitialization (004af3a0), sub_4B0C00 (004b0c00), sub_4B0EF0 (004b0ef0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Float value being clamped |

**Written-by note (persistence):**
- this 0x0: overwritten when out of bounds; survives if within [a2, a3]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always clamps. If < a2 set to a2; if > a3 set to a3.
