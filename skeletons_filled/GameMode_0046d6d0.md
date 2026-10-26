## GameMode_0046d6d0 — Game mode dispatcher

**Summary:** Dispatches game-mode-specific setup based on ChampionshipMode value: modes 1-3 show circuit selection prompt, mode 4 resumes session scene, mode 5 sets up multiplayer session (network entrants, config, scene loading). Part of game mode initialization/transition system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | passed to LookupDispatch for UI lookup (multiplayer client grid) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0046d7d0 | jpt_46D704 | R | jump table for ChampionshipMode switch dispatch |
| 005c5f5c | aMpclientgrid | R | "mpclientgrid" — UI element name for multiplayer client grid |
| 005c65ec | aSelectcircuitp | R | "selectcircuitprompt" — UI element name for circuit selection |
| 005c6bf8 | aChResume | R | resume string identifier for session resume |
| 005cc9e8 | dword_5CC9E8 | W | multiplayer active flag (set to 1 for multiplayer mode) |
| 005ea618 | flt_5EA618 | W | input buffer initialized with default values |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr — engine interface for sound system update |
| 007cd25c | dword_7CD25C | R | GameModuleManager — passed to SessionStateCheck and NetworkEntrantSetupWithIDCheck |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface — vtable interface for command dispatch |
| 007ce24c | unk_7CE24C | R | Session data object — passed to SessionSceneInitChain |
| 007d0410 | dword_7D0410 | R | ChampionshipMode — determines which game mode path to execute |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004186a0 | BufferInitWith10fDefaults | initializes input buffer with default values |
| 00461550 | FAILWRONGDESCRIPTION | handles failed/wrong description scenario |
| 00461900 | SessionConfigWriteback | writes session configuration to state |
| 00461cd0 | SessionStateCheck | checks session manager state; returns 3 if ready for multiplayer setup |
| 004627c0 | NetworkEntrantSetupWithIDCheck | sets up network entrants with identity verification |
| 00477640 | SeasonSceneNameAccessor | accesses/retrieves season scene name |
| 00477680 | TrackSceneConfigLoader | loads track scene configuration |
| 00486aa0 | GuardedFunctionDispatch | dispatches to guarded UI function by string identifier |
| 00497940 | LookupDispatch | dispatches UI lookup by string identifier |
| 004a0630 | SessionSceneInitChain | initializes session scene/data chain |
| 004b0170 | EmptyStub_0170 | empty/stub function call |

**Guard conditions:** If dword_5EB10C (SoundSystemPtr) non-null, calls vtable method 12. Switch on dword_7D0410 (ChampionshipMode): case 1/2/3 → show circuit prompt, return -1. Case 4 → init session scene, show resume, return -1. Case 5 → if SessionStateCheck != 3, skip entire multiplayer block and return -1; if == 3, execute lookup, failure handling, entrant setup, config writeback, scene loading, set dword_5CC9E8=1, call stub, return -1. Default → return 0.
