## TrackEnvironmentSelect_004ade20 — TrackEnvironmentAndPhysicsSetup

**Summary:** Selects environment type (wet/dry/mixed) based on flags when parameter a2 is set, clamps camera index to valid range, loads track scene, then initializes physics parameters, driving mode, car part visibility, and tire compound.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextFileReader (004b09a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1AEC | RW | 1 | environment selection flag (set to 1 when a2==0) |
| this | 0x1B10 | RW | — | camera index, clamped to valid range |
| this | 0x1B18 | R | — | camera index maximum bound |
| this | 0x1B1C | R | — | camera index minimum bound |

**Written-by note (persistence):**
- this 0x1AEC: written to 1 only when a2==0 (not initializing camera). Survives until next environment select.
- this 0x1B10: written conditionally when current value > 0; clamped to [min, max]. Survives recalc.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec4a8 | dword_5EC4A8 | R | CameraIndexStep [DERIVED] (also: ` — Camera index increment) |
| 007cb710 | byte_7CB710 | R | EnvironmentFlags [DERIVED] (also: ` — Env flag (bit 0 = wet) |
| 007cbb0c | byte_7CBB0C | R | EnvFlagMixed (bit0) [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004adf10 | DrivingModeParameterSetup | initializes driving mode parameters |
| 004ae490 | CarPartVisibilityController | controls car part visibility settings |
| 004ae750 | sub_4AE750 | sets environment type (1=dry, 2=wet, 3=mixed) |
| 004ae9f0 | sub_4AE9F0 | post-environment initialization |
| 004af220 | TireCompoundClamp | clamps tire compound to valid range |
| 004af3a0 | PhysicsParameterInitialization | initializes physics parameters for current track |
| 004b0170 | EmptyStub_0170 | empty stub function |
| 004c55b0 | TrackSceneLoader | loads track scene geometry |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1B10 | > | 0 | camera index field — if >0, recalc and clamp camera index |

**Guard interpretation:** When this[1732] (camera index at offset 0x1B10) is > 0, recalculates camera index from global step value and clamps to [min, max] bounds. If camera index is <= 0, skips camera recalculation entirely.
