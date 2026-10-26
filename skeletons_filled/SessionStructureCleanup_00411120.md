## SessionStructureCleanup_00411120 — ConditionedPhysicsBatchCleanup

**Summary:** Iterates 6 batches of 36-byte objects and conditionally calls ModeDispatchedRenderPhysicsCall with current session time (dbl_8AFEA0). First 3 batches are unconditional (count > 0). Batches 4-6 have VEH state conditions: skip call for objects whose associated VEH data indicates active/alive state (sentinel != -1, non-null state pointer, non-zero byte flag). Used during loading phase to clean up or reinitialize physics state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadingPhase2 (004b8940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | batch 1 count |
| this | 0x28 | R | — | batch 1 base pointer |
| this | 0x30 | R | — | batch 2 count |
| this | 0x34 | R | — | batch 2 base pointer |
| this | 0x3C | R | — | batch 3 count |
| this | 0x40 | R | — | batch 3 base pointer |
| this | 0x48 | R | — | batch 4 count |
| this | 0x4C | R | — | batch 4 base pointer |
| this | 0x54 | R | — | batch 5 count |
| this | 0x58 | R | — | batch 5 base pointer |
| this | 0x60 | R | — | batch 6 count |
| this | 0x64 | R | — | batch 6 base pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] — base for VEH state lookups in batch 4-5 guards |
| 005ed434 | dword_5ED434 | R | VEH[0].0xD5C — state array indexed by 4656*dword stride + 17*subgroup for batch 6 guard |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] — current session time passed to ModeDispatchedRenderPhysicsCall |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f300 | ModeDispatchedRenderPhysicsCall | dispatches render/physics update for a single 36-byte object |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24 | > | 0 | batch 1: skip if count <= 0 |
| this | 0x30 | > | 0 | batch 2: skip if count <= 0 |
| this | 0x3C | > | 0 | batch 3: skip if count <= 0 |
| this | 0x48 | > | 0 | batch 4: skip if count <= 0 |
| this | 0x54 | > | 0 | batch 5: skip if count <= 0 |

**Guard interpretation:** batches 1-3: count > 0 → process all objects. Batches 4-6: count > 0 AND (object index beyond VEH data bounds OR VEH sentinel active OR VEH state null/zero) → call ModeDispatchedRenderPhysicsCall; otherwise (VEH object is alive/active) → skip call (object already live).
