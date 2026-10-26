## StartNetworkUpdate_00461de0 — NetworkStartInit

**Summary:** Initializes network connection based on type (internet vs LAN): calls direct display mode init, then either InitWrapper (internet) or MultiStageInitializationChain (LAN) with port range.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateResetAndConditionalInit (00475530)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1B79C | R | — | Network system pointer (checked non-null to proceed) |
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c616c | aStartingIntern | R | "Starting internet update" debug string |
| 005c6194 | aStartingLanUpd | R | "Starting LAN update" debug string |
| 007c569c | dword_7C569C | R | Session type (5=server) — guards dev logging |
| 007d0e74 | dword_7D0E74 | R | Network type (0=LAN, 1=Internet) |
| 007d0fe8 | word_7D0FE8 | R | Session port base for LAN init |
| 008ad25c | dword_8AD25C | R | Debug message buffer pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Guard check for dev logging verbosity |
| 004d7aa0 | DebugLogWrite | Write network start debug message |
| 00562c80 | InitWrapper | Initialize internet network mode |
| 00563020 | MultiStageInitializationChainWithErrorChecking | Initialize LAN network with port range |
| 00563df0 | SetFlagIfPointerNonNull | Set flag on network system pointer |
| 00563e00 | DirectDrawDisplayModeInit | Initialize DirectDraw display mode on network system |
| 00563e70 | sub_563E70 | Network capability query (non-zero = can init) |

**Guard conditions:** Blocked when network system pointer (this+0x1B79C) is null. Blocked when sub_563E70 returns 0 (network not available). DebugLogWrite blocked when dword_7C569C==5 (server session) or StringSplitLoop returns 0.
