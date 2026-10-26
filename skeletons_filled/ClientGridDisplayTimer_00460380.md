## ClientGridDisplayTimer_00460380 — ClientGridDisplayTimer

**Summary:** Timer-driven client grid overlay controller. Decrements a 7.5-second timer each call; on expiry, evaluates scene state and toggles the grid display flag. Resets timer after evaluation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | 1089470464 → 7.5f | PhysX [FACT] — countdown timer in seconds, reset to 7.5f |
| this | 0x20 | RW | 1 | PhysY [FACT] — grid display toggle flag (1 = show, 0 = hide) |
| this | 0x3FC4 | R | — | Session phase (must equal 3 for timer to run) |

**Written-by note (persistence):**
- this 0x1C: decremented each call by dbl_8AFE98 (frame delta); reset to 7.5f when expired
- this 0x20: toggled between 0 and 1 when timer expires; persists between calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059f0ac | dword_59F0AC | R | NetTimeoutInterval [DERIVED] — float constants |
| 005c5f5c | aMpclientgrid | R | MpClientGrid [DERIVED] — "mpclientgrid" lookup string |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] — session data object |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] — scene/module index for change detection |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] — frame delta subtracted from timer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461550 | FAILWRONGDESCRIPTION | Create/generate unique ID for scene check |
| 00461900 | SessionConfigWriteback | Write back session configuration |
| 004630d0 | UniqueID | Check if unique ID is valid |
| 00497940 | LookupDispatch | Dispatch "mpclientgrid" lookup with command |
| 004a0030 | sub_4A0030 | Process session transition with critical section |
| 004a0dc0 | SystemOSAPICall_0dc0 | System/OS API call for session transition |
| 004b0170 | EmptyStub_0170 | Empty stub (cleanup) |
| 004c54f0 | AIW | AIW call (scene/data writeback) |
| 004c5690 | SceneDataParser | Parse current scene data |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3FC4 | == | 3 | Session phase |

**Guard interpretation:**
- this+0x3FC4 (phase) != 3 → skip entirely.
- Phase == 3 → decrement timer (this+0x1C) by dbl_8AFE98.
- Timer >= 0.0 → no action yet.
- Timer < 0.0 (expired):
  - Create unique ID via FAILWRONGDESCRIPTION.
  - If UniqueID(v4) returns nonzero:
    - Parse scene data.
    - If this+0x20 (flag) == 1 → call SessionConfigWriteback, AIW, SystemOSAPICall_0dc0, check HUD flag, call sub_4A0030 and LookupDispatch("mpclientgrid", -1), then set flag to 0.
    - Else if scene index changed (v3 != dword_8AC48C) → set flag to 1.
    - Reset timer to 7.5f.
  - Cleanup via EmptyStub_0170.
