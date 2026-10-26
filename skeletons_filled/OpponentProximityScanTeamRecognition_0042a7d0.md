## OpponentProximityScanTeamRecognition_0042a7d0 — AI Opponent Proximity Scan & Team Recognition

**Summary:** Scans all vehicles each frame to find the 5 nearest opponents, sorted by distance, then performs team/class recognition by matching team IDs; also applies overtake-direction heuristics. AI opponent awareness system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4174) | 0x4894 | R | — | team/class ID of vehicle referenced in proximity slot (read via v28->offset 0x4894) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x4 | R | — | self vehicle pointer (used for identity comparison) |
| this | 0x34E0 | R | — | self vehicle world position X (used for distance calc) |
| this | 0x34E8 | R | — | self vehicle world position Z (used for distance calc) |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4174 | RW | — | proximity slot 0 active flag / vehicle pointer (init to 0) |
| this | 0x41A8 | RW | 1065353216 → 1.0f | proximity slot 0 squared distance (init to huge sentinel ~999999.0f) |
| this | 0x41B4 | RW | 18446744073709551615 | proximity slot 0 vehicle ptr/id (init to -1 sentinel) |
| this | 0x41B8 | RW | — | proximity slot 1 active flag / vehicle pointer |
| this | 0x41EC | RW | — | proximity slot 1 squared distance |
| this | 0x41FC | RW | — | proximity slot 2 active flag |
| this | 0x4230 | RW | — | proximity slot 2 squared distance |
| this | 0x4240 | RW | — | proximity slot 3 active flag |
| this | 0x4274 | RW | — | proximity slot 3 squared distance |
| this | 0x4284 | RW | — | proximity slot 4 active flag |
| this | 0x42B8 | RW | — | proximity slot 4 squared distance |
| this | 0x42CC | RW | 0 | team recognition slot 0 matched flag (1 = teammate recognized) |
| this | 0x42D0 | R | — | team recognition slot 0 team ID (read from vehicle struct offset 0x4894) |
| this | 0x42DC | RW | 1140457472 → 500.0f | overtake/team-check distance threshold (squared, ~22.36 units) |
| this | 0x4420 | RW | 1075838976 → 2.5f | overtake direction bias value (sign indicates left/right side) |
| this | 0x448C | R | — | self forward direction component Y (for dot product) |
| this | 0x4494 | R | — | self forward direction component X (for dot product) |
| this | 0x4578 | RW | 0 | per-slot team recognition counter / scan reset flag |
| this | 0x45FC | RW | — | post-process override flag (forces distance threshold reset when set) |

**Written-by note (persistence):**
- this 0x4174: recalc every frame — external poke does NOT persist
- this 0x41A8: recalc every frame — external poke does NOT persist
- this 0x41B4: recalc every frame — external poke does NOT persist
- this 0x41B8: recalc every frame — external poke does NOT persist
- this 0x41EC: recalc every frame — external poke does NOT persist
- this 0x41FC: recalc every frame — external poke does NOT persist
- this 0x4230: recalc every frame — external poke does NOT persist
- this 0x4240: recalc every frame — external poke does NOT persist
- this 0x4274: recalc every frame — external poke does NOT persist
- this 0x4284: recalc every frame — external poke does NOT persist
- this 0x42B8: recalc every frame — external poke does NOT persist
- this 0x42CC: recalc every frame — external poke does NOT persist
- this 0x42DC: recalc every frame — external poke does NOT persist
- this 0x4420: recalc every frame — external poke does NOT persist
- this 0x4578: recalc every frame — external poke does NOT persist
- this 0x45FC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e980 | flt_59E980 | R | AISeasonPointsThreshold [DERIVED] |
| 0059e984 | flt_59E984 | R | AIOvertakeDistance [DERIVED] |
| 0059e988 | flt_59E988 | R | AISpatialProximityThreshold [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea2cc | dword_5EA2CC | R | AiOvertakeDistanceThreshold [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce2f0 | unk_7CE2F0 | R | Unknown_AI_Struct_7CE2F0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423ad0 | F_2DVectorDirectionProjection | compute dot product of 2D direction vector and relative position (forward projection) |
| 004a4710 | FindNearestVehicle | locate single nearest vehicle to self (fast-path lookup) |
| 004c7bd0 | sub_4C7BD0 | check whether a vehicle is a valid opponent (not eliminated/lapped out) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x41B4 | == | 18446744073709551615 | closest vehicle slot empty (sentinel, no vehicle assigned) |

**Guard interpretation:** `this+0x41B4 == -1` (sentinel) → slot is empty, meaning no closest vehicle has been found yet. PASSES (==): no vehicle assigned → triggers full scan loop over all vehicles to fill proximity slots. BLOCKED (!=): a vehicle is already assigned (from FindNearestVehicle fast path) → skip the full scan.
