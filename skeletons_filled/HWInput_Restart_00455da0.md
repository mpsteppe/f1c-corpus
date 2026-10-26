## HWInput_Restart_00455da0 — HWInput_Restart

**Summary:** Restarts HWInput state: sets up frustum viewport, initializes BVH tree node array, optionally reinitializes audio subsystem if audio quality is enabled, then scans device array at +0x1F98 for active entries to set active flag at +0x2428.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1F98 | R | — | pointer to device entry in the array (each entry 11 DWORDs) |
| this | 0x1F9C | R | — | second DWORD of first device entry (guarded against 89) |
| this | 0x2428 | RW | 1 | active flag: 1 = active, 0 = inactive (no working device found) |

**Written-by note (persistence):**
- this 0x2428: always written. Set to 0 initially, then 1 if any device entry's second DWORD != 89. External poke survives until next restart.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c56a4 | aDDevF119992002_13 | R | SourcePathFormatString |
| 005c5700 | aEnteredHwinput_2 | R | debug log entry string |
| 005d6d60 | dword_5D6D60 | R | screen width |
| 005d6d64 | dword_5D6D64 | R | screen height |
| 007c569c | dword_7C569C | R | SessionType (5=server, guards debug logging) |
| 007d1ffc | dword_7D1FFC | R | audio quality level (nonzero enables audio reinit) |
| 008ad25c | dword_8AD25C | R | debug message buffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044f0a0 | BVHTreeNodeArrayInit | initializes BVH tree node array at this+4 |
| 0044f680 | FrustumViewportSetup | sets up frustum viewport dimensions |
| 0044ff50 | sub_44FF50 | reinitializes audio subsystem |
| 004d7a50 | StringSplitLoop | checks debug-log enable condition |
| 004d7aa0 | DebugLogWrite | writes restart-entry message |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1F9C | == | 89 | second DWORD of first device entry (uninitialized/present sentinel) |

**Guard interpretation:** Iterates device entries (11 DWORD stride). PASSES (loop continues) when entry's first DWORD is 0 AND second DWORD == 89 — means entry is empty/uninitialized. BLOCKED (loop exits, active flag=1) when any entry has first DWORD nonzero OR second DWORD != 89 — means a device is present.
