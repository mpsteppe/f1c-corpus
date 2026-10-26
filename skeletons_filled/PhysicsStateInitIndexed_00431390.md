## PhysicsStateInitIndexed_00431390 — PhysicsStateInitIndexed

**Summary:** Initializes an indexed physics state value (float array write at 4*a2+7336), clears change flag, sets activation flag, and triggers pressure/force field mapping.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_6c40 (00466c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | Activation flag byte, set to 1 |
| this | 0x19A4 | RW | 0 | Change flag, cleared to 0 |

**Written-by note (persistence):**
- this 0x0: Set to 1 every call.
- this 0x19A4: Set to 0 every call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004313c0 | PressureForceFieldMapping | Update/recompute pressure and force field based on new state value |

**Guard conditions:** No guard — always executes all writes and calls unconditionally.
