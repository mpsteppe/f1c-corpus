## UILayoutDispatchWithDataPrep_004db550 — HUDLayoutDispatcher

**Summary:** Prepares game data (speed, engine RPM) and dispatches to multiple HUD element renderers at specific Y-positions (20, 68, 10). Part of HUD layout system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TripleVirtualCall (004db520)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] — passed to sub_49B7A0 for driver appearance setup |
| 007d0474 | byte_7D0474 | R | UITextEncodingFlag [DERIVED] — selects speed magnitude calculation variant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b7a0 | sub_49B7A0 | Processes DriverAppearanceFlag, returns value for sub_4DB7F0 |
| 0049b8f0 | EngineRevValueAccessor | Returns current engine RPM value for display |
| 0049b900 | SpeedMagnitude | Calculates speed magnitude (variant 1, selected when byte_7D0474 is set) |
| 0049b950 | SpeedMagnitude_b950 | Calculates speed magnitude (variant 2, selected when byte_7D0474 is zero) |
| 004db6f0 | PositionOrderNameDisplay | Renders position and name display at Y=20 |
| 004db7f0 | sub_4DB7F0 | Renders additional HUD element at Y=10 |
| 004db9a0 | UtilityFunction_b9a0 | Renders speed-related HUD element at Y=68 |

**Guard conditions:**
- Line 8: `byte_7D0474` (UI text encoding flag) non-zero. PASS: use SpeedMagnitude() for speed. BLOCK: use SpeedMagnitude_b950().
