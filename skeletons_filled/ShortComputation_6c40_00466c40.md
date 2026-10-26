## ShortComputation_6c40_00466c40 — PhysicsInitAndDisplayForIndexedParam

**Summary:** Calls PhysicsStateInitIndexed with byte_7C56C0 and indexed float/int from this+0x104/0x108, then calls VehicleStatsEstimationDisplay. Clears byte at this+0x100 to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x100 | RW | 0 | byte flag cleared to 0 (done) |
| this | 0x104 | R | — | field 66 — float parameter for physics init |
| this | 0x108 | R | — | field 67 — int parameter for physics init |

**Written-by note (persistence):**
- this 0x100: conditional (cleared). External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00430f00 | VehicleStatsEstimationDisplay | display vehicle stats estimation |
| 00431390 | PhysicsStateInitIndexed | init physics state with indexed parameters |

**Guard conditions:** None — unconditional.
