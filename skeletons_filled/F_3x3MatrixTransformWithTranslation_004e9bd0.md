## F_3x3MatrixTransformWithTranslation_004e9bd0 — 3x3 rotation + translation transform

**Summary:** Transforms local offset vector by 3x3 rotation matrix, adds body world position, stores world-space result. Standard rigid-body point transform for suspension/contact system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionAndWheelPhysics (004e5f60), AIRacingLinePathFollowing (004e9ca0), ParticleEffectUpdateDispatch (004eb430), AIVehiclePathPositionTracking (004ef7c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B0 | R | — | rotation matrix row 0, column 0 |
| this | 0x34B4 | R | — | rotation matrix row 1, column 0 |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] — rotation matrix row 2, column 0 |
| this | 0x34BC | R | — | rotation matrix row 0, column 1 |
| this | 0x34C0 | R | — | rotation matrix row 1, column 1 |
| this | 0x34C4 | R | — | rotation matrix row 2, column 1 |
| this | 0x34C8 | R | — | rotation matrix row 0, column 2 |
| this | 0x34CC | R | — | rotation matrix row 1, column 2 |
| this | 0x34D0 | R | — | rotation matrix row 2, column 2 |
| this | 0x34D4 | R | — | body world position X (translation) |
| this | 0x34D8 | R | — | body world position Y (translation) |
| this | 0x34DC | R | — | body world position Z (translation) |
| this | 0x3B54 | R | — | local offset vector X (contact point in body frame) |
| this | 0x3B58 | R | — | local offset vector Y (contact point in body frame) |
| this | 0x3B5C | R | — | local offset vector Z (contact point in body frame) |
| this | 0x3B60 | RW | — | result world-space contact point X |
| this | 0x3B64 | RW | — | result world-space contact point Y |
| this | 0x3B68 | RW | — | result world-space contact point Z |

**Written-by note (persistence):**
- this 0x3B60: recalc every frame — external poke does NOT persist
- this 0x3B64: recalc every frame — external poke does NOT persist
- this 0x3B68: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes full rotation+translation transform.
