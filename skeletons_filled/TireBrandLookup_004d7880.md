## TireBrandLookup_004d7880 — TireBrandNameSearcher

**Summary:** Searches a tire brand name table for a matching string. Iterates up to *this entries at this[1] with 36-byte stride, comparing each brand name via sub_588410. Returns pointer to matching entry, or 0 if not found (with optional debug log, gated by session type).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleSetupValueFormatter (0042f470), sub_430750 (00430750), BrakeTemperatureFadeModel (00430a50), TireSuspensionForceComputation (00431850), VehiclePhysicsInitializer (00439210), sub_43C250 (0043c250), PitPartStateCopy (004a5330), SuspensionAndWheelPhysics (004e5f60), TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | count of tire brand entries |
| this | 0x4 | R | — | pointer to array of brand entries (36-byte stride, first member is brand name string pointer) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d45e4 | aDDevF119992002_4 | R | SourcePath_F1_1999_2002_4 [DERIVED] |
| 005d49e4 | aNonExistentTir | R | NonExistentTireString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | validates debug source path before logging |
| 004d7aa0 | DebugLogWrite | writes non-existent tire error to debug log |
| 00588410 | sub_588410 | string comparison function |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | <= | 0 | entry count — if zero or negative, skip table and go to error |

**Guard interpretation:** If *this <= 0 (empty brand table), skips straight to error handling — returns 0 without searching. Error log is additionally gated by dword_7C569C != 5 (suppressed on server sessions).
