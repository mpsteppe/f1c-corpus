## SessionStateDispatch_004a0df0 — UIStateDispatchForSession

**Summary:** Dispatches UI handling based on current session state. For session state 3, queries dispatch interface with param 36; for state 2, with param 35. When valid result is returned, processes text input, list selection, and plays UI sound effect.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MouseInputHandler (0045f030), SessionScoringUpdate (004643c0), SessionMessageUICommandHandler (00470490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461cd0 | SessionStateCheck | Checks current session state from module manager |
| 004896c0 | UITextInputHandler | Handles text input in UI context |
| 00489ab0 | UIListSelectionHandler | Handles list/menu selection in UI context |
| 004c8de0 | SoundEffectLoadPlay | Loads and plays UI menu sound effect |

**Guard conditions:** If SessionStateCheck returns 3 → interface query with param 36. If it returns 2 → interface query with param 35. Any other state returns early (no UI processing). After interface query, if result is NULL → returns early without UI handling. When non-NULL, proceeds to UITextInputHandler, UIListSelectionHandler, and SoundEffectLoadPlay.
