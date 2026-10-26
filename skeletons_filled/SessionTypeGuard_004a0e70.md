## SessionTypeGuard_004a0e70 — SessionTypeGuardDispatch

**Summary:** Guards a dispatch call against session type and HUD-disable flag. Only dispatches when GameCommandDispatchInterface exists and session type is 2 (race) or 6 (menu), or HUD is disabled. Used for forwarding network/session messages.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890), sub_4B7500 (004b7500), sub_4B7DE0 (004b7de0), sub_4BA1F0 (004ba1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004989e0 | sub_4989E0 | Dispatches message/command on the game dispatch interface |

**Guard conditions:** Guard fails (returns 0) if GameCommandDispatchInterface (dword_7CD8C0) is NULL, OR if SessionType5 is NOT 2 AND NOT 6 AND HUD is not disabled (!byte_7CE254). Guard passes when interface exists AND (session type is 2 or 6 OR HUD is disabled). When passed, calls sub_4989E0 and returns 1.
