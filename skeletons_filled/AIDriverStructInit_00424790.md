## AIDriverStructInit_00424790 — AI driver per-frame reset and reinitialization

**Summary:** Per-frame reinitialization of AI driver state fields: resets timers, clears flags, re-seeds spatial search radius, optionally reloads waypoints/command queues, and applies difficulty-scaled traction control/track grip adjustments. Part of the AI driver update system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneRenderUpdate (004c6d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48A4 | R | — | waypoint/track position index read from vehicle struct |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x4 | R | — | vehicle unique ID (negated to compute spatial offset) |
| this | 0x8 | RW | — | spatial search radius (recomputed from scene config + vehicle base) |
| this | 0x396C | R | — | base waypoint index loaded into this+0x44CC |
| this | 0x413C | RW | 2139095039 | NaN sentinel for uninitialized float field |
| this | 0x4140 | RW | 0 | byte flag cleared on init (likely active/inactive marker) |
| this | 0x4144 | RW | 18446744073709551615 | invalid index sentinel (-1) for slot array |
| this | 0x4170 | RW | 2139095039 | NaN sentinel for uninitialized float array entry |
| this | 0x41B4 | RW | 18446744073709551615 | invalid index sentinel (-1) for second slot array |
| this | 0x42D8 | RW | 18446744072710897680 → -999.0f | negative clamp threshold for a driving parameter |
| this | 0x43F8 | RW | 0 | zeroed counter or accumulator |
| this | 0x4400 | RW | — | copy of field from another struct (linked vehicle reference) |
| this | 0x4404 | RW | 18446744072627421184 → -1.0f | default -1.0 sentinel for a normalized parameter |
| this | 0x4410 | RW | 0 | RetiredFlag [FACT] |
| this | 0x4420 | RW | 0 | zeroed state counter/flags field |
| this | 0x442C | RW | 0 | zeroed counter (loop iteration index) |
| this | 0x4430 | RW | 0 | zeroed state field |
| this | 0x443C | RW | 0 | zeroed byte flag |
| this | 0x444C | RW | 0 | clear-state flags via AIClearStateFlags |
| this | 0x4454 | RW | — | computed field from vehicle ID × 7.0 (spatial offset) |
| this | 0x4458 | RW | 18446744073709551615 | invalid index sentinel (-1) |
| this | 0x4460 | RW | 18446744072627421184 → -1.0f | default -1.0 sentinel for second normalized param |
| this | 0x4464 | RW | 1065353216 → 1.0f | scalar multiplier defaulting to 1.0 |
| this | 0x446C | RW | 0 | zeroed state field |
| this | 0x447C | RW | 0 | zeroed accumulator/counter |
| this | 0x4484 | RW | 1232348144 → 999999.0f | upper bound sentinel (effectively infinite) |
| this | 0x44A8 | RW | — | copy from spatial search result (nearest neighbor) |
| this | 0x44AC | RW | 10 | default value 10 (array size or threshold) |
| this | 0x44B0 | RW | 18446744073709551615 | invalid index sentinel (-1) |
| this | 0x44B4 | RW | — | copy from second global config float |
| this | 0x44CC | RW | 1065353216 → 1.0f | waypoint-progress multiplier, defaults to 1.0 |
| this | 0x44F8 | RW | 1065353216 → 1.0f | speed multiplier, defaults to 1.0 |
| this | 0x4508 | RW | 0 | zeroed counter/state field |
| this | 0x450C | RW | 0 | zeroed counter/state field |
| this | 0x4510 | RW | 0 | driverStatus [CONFIRMED] |
| this | 0x4524 | RW | 0 | guard callback result array initialized to 0 |
| this | 0x4534 | RW | 0 | timeOfNextExit [CONFIRMED] |
| this | 0x4538 | RW | 1232348144 → 999999.0f | maxSpeed [CONFIRMED] |
| this | 0x453C | RW | 1065353216 → 1.0f | speed multiplier default 1.0 |
| this | 0x4540 | RW | 1086324736 → 6.0f | default threshold value 6.0 |
| this | 0x4544 | RW | 1 | boolean flag defaulting to true |
| this | 0x4548 | RW | 0 | byte flag cleared on init |
| this | 0x454C | RW | 0 | callToBox [CONFIRMED] |
| this | 0x4550 | RW | 0 | zeroed state field |
| this | 0x4554 | RW | 1065353216 → 1.0f | multiplier defaulting to 1.0 |
| this | 0x4558 | RW | 50 | default integer threshold (e.g. frame count) |
| this | 0x455C | RW | 0 | zeroed accumulator |
| this | 0x4560 | RW | 0 | zeroed delay timer |
| this | 0x4564 | RW | 0 | zeroed state field |
| this | 0x4578 | RW | 1 | boolean flag defaulting to true |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |
| this | 0x45F8 | RW | 0 | zeroed state field |
| this | 0x45FC | RW | 0 | zeroed state field |
| this | 0x461C | RW | 1232348144 → 999999.0f | upper bound sentinel for another parameter |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x413C: recalc every frame — external poke does NOT persist
- this 0x4140: recalc every frame — external poke does NOT persist
- this 0x4144: recalc every frame — external poke does NOT persist
- this 0x4170: recalc every frame — external poke does NOT persist
- this 0x41B4: recalc every frame — external poke does NOT persist
- this 0x42D8: recalc every frame — external poke does NOT persist
- this 0x43F8: recalc every frame — external poke does NOT persist
- this 0x4400: recalc every frame — external poke does NOT persist
- this 0x4404: recalc every frame — external poke does NOT persist
- this 0x4410: recalc every frame — external poke does NOT persist
- this 0x4420: recalc every frame — external poke does NOT persist
- this 0x442C: recalc every frame — external poke does NOT persist
- this 0x4430: recalc every frame — external poke does NOT persist
- this 0x443C: recalc every frame — external poke does NOT persist
- this 0x444C: recalc every frame — external poke does NOT persist
- this 0x4454: recalc every frame — external poke does NOT persist
- this 0x4458: recalc every frame — external poke does NOT persist
- this 0x4460: recalc every frame — external poke does NOT persist
- this 0x4464: recalc every frame — external poke does NOT persist
- this 0x446C: recalc every frame — external poke does NOT persist
- this 0x447C: recalc every frame — external poke does NOT persist
- this 0x4484: recalc every frame — external poke does NOT persist
- this 0x44A8: recalc every frame — external poke does NOT persist
- this 0x44AC: recalc every frame — external poke does NOT persist
- this 0x44B0: recalc every frame — external poke does NOT persist
- this 0x44B4: recalc every frame — external poke does NOT persist
- this 0x44CC: recalc every frame — external poke does NOT persist
- this 0x44F8: recalc every frame — external poke does NOT persist
- this 0x4508: recalc every frame — external poke does NOT persist
- this 0x450C: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4524: recalc every frame — external poke does NOT persist
- this 0x4534: recalc every frame — external poke does NOT persist
- this 0x4538: recalc every frame — external poke does NOT persist
- this 0x453C: recalc every frame — external poke does NOT persist
- this 0x4540: recalc every frame — external poke does NOT persist
- this 0x4544: recalc every frame — external poke does NOT persist
- this 0x4548: recalc every frame — external poke does NOT persist
- this 0x454C: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x4554: recalc every frame — external poke does NOT persist
- this 0x4558: recalc every frame — external poke does NOT persist
- this 0x455C: recalc every frame — external poke does NOT persist
- this 0x4560: recalc every frame — external poke does NOT persist
- this 0x4564: recalc every frame — external poke does NOT persist
- this 0x4578: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist
- this 0x45F8: recalc every frame — external poke does NOT persist
- this 0x45FC: recalc every frame — external poke does NOT persist
- this 0x461C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea2d0 | dword_5EA2D0 | R | AIConfigZeroFloat [DERIVED] |
| 005ea3e8 | flt_5EA3E8 | R | AIInitTractionControl [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403aa0 | SpatialTreeNearestNeighborSearch | find nearest spatial neighbor for AI pathing |
| 00403f70 | ArrayOfStructIndexedFieldCopy | copy field from scene config array by index |
| 00424080 | sub_424080 | load AI driver difficulty/scenario config from data files |
| 00424ac0 | AIDifficultyInterpolation | interpolate AI difficulty based on race context |
| 00424cd0 | AICommandMessageQueueDispatcher | dispatch AI command messages to queue |
| 00429960 | sub_429960 | finalize AI driver init after spatial search |
| 0042ae00 | AIClearStateFlags | reset AI state flags to zero |
| 004a5c10 | GuardedCallWithCheck | guarded vtable dispatch with null/validity check |
| 004f1510 | ScaleAudioPitch | adjust audio pitch based on computed scalar |
| 00587bcf | FreeWrapper_7bcf | free previously allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory (operator new wrapper) |

**Guard conditions:** The parameter `a2` (byte via `LOBYTE(a2)`) gates full initialization: when non-zero, the function performs spatial tree search, waypoint neighbor lookup, command queue dispatch, and full field seeding; when zero, only default sentinel values and basic zeroing are applied (lightweight reset path). Additionally, `dword_5C329C > 0` (VehicleCount) guards the teammate-search loop. Finally, session type != 3,4,5 (non-qualifying/practice modes) gates the traction-control multiplier (`flt_5EA3E8 * v19`), applying a scaling factor only in race sessions.
