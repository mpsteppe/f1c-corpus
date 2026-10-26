## VidMan_Exit_004fad00 — VidManExitCleanup

**Summary:** Video manager exit handler — logs exit, shuts down collision system, dispatches race time delta handle, runs cleanup subroutines, and frees race time delta memory if allocated.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameExit (0042db20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d6dc4 | aDDevF119992002_26 | R | PathPrefix [DERIVED] |
| 005d6ee8 | aEnteredVidmanE_0 | R | EnteredVidManEString [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe64 | dword_8AFE64 | RW | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00494900 | CollisionSystemShutdownCleanup | shut down collision detection system |
| 004a14e0 | sub_4A14E0 | unknown cleanup routine |
| 004a1830 | sub_4A1830 | unknown cleanup routine (called twice) |
| 004d7a50 | StringSplitLoop | format message string with path prefix |
| 004d7aa0 | DebugLogWrite | write debug log message |
| 0053d4c0 | TestAndFreeWrapper | test pointer for non-null and free allocated memory |
| 0055c040 | GlobalDispatch | dispatch/dispose a global handle or resource |

**Guard conditions:** StringSplitLoop returns 0 → skip debug log. dword_8AFE64 == 0 → skip TestAndFreeWrapper (nothing to free).
