## UtilityFunction_3d50_00463d50 — WheelCollisionAndIntegrationDispatcher

**Summary:** Performs collision test with threshold for a given wheel index; if collision detected, dispatches physics integration step and float state update. Reads per-wheel parameter from global array (unk_5F0708 indexed by a2*4656). Part of vehicle physics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TeamColorLoader (004f03e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Target context pointer (dereferenced for PhysicsIntegrationStep_e620 first arg) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045e620 | PhysicsIntegrationStep_e620 | Perform wheel physics integration step |
| 005000e0 | PhysicsFloatUpdateWithCompare | Update wheel physics float state with comparison |
| 00500560 | CollisionTestWithThreshold | Test wheel collision against threshold at given index |

**Guard conditions:** CollisionTestWithThreshold return: if false (0), BLOCK physics integration and float update. Only PASS and execute physics when collision test succeeds.
