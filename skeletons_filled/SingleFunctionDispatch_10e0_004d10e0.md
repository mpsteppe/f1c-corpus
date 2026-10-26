## SingleFunctionDispatch_10e0_004d10e0 — SingleGridPositionDataRead

**Summary:** Read a single grid position data element from the setup scene. Index is (this[0x4058] - 1), corresponding to the vehicle's allocated grid slot. Calls sub_403CD0 to copy position data to output arrays.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringRacingLineCorrection (0042b0e0), sub_4BC9B0 (004bc9b0), SceneRenderUpdate (004c6d90), sub_4D0110 (004d0110), sub_4D1180 (004d1180)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4058 | R | — | plannedPositionAtStart [CONFIRMED] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always reads. Index must be >= 0 (caller must have allocated a grid position).
