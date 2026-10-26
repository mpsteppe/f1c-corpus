## MainMenuTransition_00404f30 — MainMenuTransitionRestore

**Summary:** Handles transition back to main menu: restores previously saved global state (race mode flag, scoring gate flag), applies timeout overrides, resets a flag, and conditionally dispatches a virtual state reset. Mirrors the save logic in RaceModeSetup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionMenuModeSwitch (004a0c60), RestartGate (004a0fd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | R | — | byte activation flag (must be non-zero to enter restore path) |
| obj | 0x20 | R | — | dword must == 1 for restore path (race mode check) |
| obj | 0x50 | R | — | saved previous ScoringGateEnableFlag (dword_7D2E44) to restore |
| obj | 0x54 | R | — | saved previous RaceMode (dword_7D0410) to restore |
| this | 0x0 | R | — | pointer to target object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be708 | aMainMenu | R | Str_MainMenu [DERIVED] |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f10 | ConditionalFlagReturn | checks a condition flag and returns boolean |
| 00497940 | LookupDispatch | dispatches lookup for main menu scene |
| 004a0250 | sub_4A0250 | acquires session critical section lock |
| 004a03f0 | SystemOSAPICall | calls system OS API with session data object |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x20 | == | 1 | dword race mode flag; must be 1 for restore path |

**Guard interpretation:** Field at obj+0x20 == 1 AND byte at obj+0x14 non-zero PASSES (enters restore path: restores dword_7D2E44 and dword_7D0410 from saved values, applies timeout overrides, resets byte_5EA53E, conditionally resets virtual dispatch state). Condition fails -> only runs session lock/critical section operations and optional main menu lookup.
