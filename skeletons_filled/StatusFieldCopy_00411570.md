## StatusFieldCopy_00411570 — VEHStatusFieldPropagator

**Summary:** Copies 14 status fields from VEH global array (indexed by a2, 18624-byte stride) into three target groups (this[19], this[22], this[25]) via ShortComputation_e710. If a3 is non-zero, reads source values from VEH; if a3 is zero, writes zeros (reset). Copies 4 fields from VEH+324 (74-dword stride), 2 fields from VEH+377/394 (even/odd), and 8 fields from VEH+1644 (17-dword stride).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleGraphicsSceneLoader (004dfce0), VehicleResetClear (004e09e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | base pointer for group 1 target array (this[19]) |
| this | 0x58 | R | — | base pointer for group 2 target array (this[22]) |
| this | 0x64 | R | — | base pointer for group 3 target array (this[25]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ecdc8 | unk_5ECDC8 | R | VEH[0].0x6F0 — base for VEH array indexed by a2 (18624-byte stride); source of status field values |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e710 | ShortComputation_e710 | stores a single status value into target field |

**Guard conditions:** if a3 == 0 → writes zeros (reset) instead of VEH source values. Always executes all 14 copies regardless of a3.
