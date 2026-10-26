## sub_4A0AF0_004a0af0 — GameFilterDispatch

**Summary:** Checks game command dispatch interface for feature availability (vtable+28, param 23). If available, dispatches game filter. Used during multiplayer session joining.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AutoJoinRetryLoop (004637a0), MultiplayerSessionJoinHandler (0046de10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c7130 | aGameFilter | R | GameFilterString [DERIVED] (also: ` — "Game Filter" string constant) |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00476f90 | SingleFunctionDispatch_6f90 | Dispatches a single function call |
| 005681f0 | ConditionalDispatch_81f0 | Conditionally resolves and dispatches based on game filter string |

**Guard conditions:** Vtable call (offset +28) on dword_7CD8C0 with param 23 must return non-zero. If zero (feature not available), returns early and skips game filter dispatch.
