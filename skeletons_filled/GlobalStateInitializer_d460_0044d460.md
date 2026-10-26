## GlobalStateInitializer_d460_0044d460 — InitializeRainBrakeAndCollisionState

**Summary:** Initializes six globals: sets RainBrakeBiasGlobal to 15 and zeroes five collision/render state variables (CollisionStateCounter, CollisionState_7CCCF8, RenderState_Zero_05, ZeroedCollisionState, Unknown_Zeroed_CCD04). Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cccf0 | dword_7CCCF0 | W | RainBrakeBiasGlobal [DERIVED] |
| 007cccf4 | dword_7CCCF4 | W | CollisionStateCounter [DERIVED] |
| 007cccf8 | dword_7CCCF8 | W | CollisionState_7CCCF8 [DERIVED] |
| 007cccfc | dword_7CCCFC | W | RenderState_Zero_05 [DERIVED] |
| 007ccd00 | dword_7CCD00 | W | ZeroedCollisionState [DERIVED] |
| 007ccd04 | dword_7CCD04 | W | Unknown_Zeroed_CCD04 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
