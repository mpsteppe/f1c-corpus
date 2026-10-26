## LoopWithConditionalSkipFunction_00410980 — LoopWithConditionalSkipFunction

**Summary:** Iterates array of scene objects, runs state machine on each; if state machine returns false (fail/unload), removes element and runs conditional cleanup chain. Part of scene object lifecycle / main game tick update.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Count of elements in array (loop bound) |
| this | 0x8 | R | — | Array pointer (this[2]) containing scene object pointers |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f100 | ConditionalCleanupChain | Runs cleanup chain on failed scene object (if ID != -1) |
| 0040f1c0 | SceneObjectLoaderStateMachine | 7-mode state machine for loading/unloading scene objects |
| 004bdfe0 | MatrixClear | Clears matrix (UI widget list) |

**Guard conditions:** Iterates from 0 to this[0]-1. SceneObjectLoaderStateMachine returns 0 (false) → remove element, call ConditionalCleanupChain, decrement index. Returns non-zero → continue.
