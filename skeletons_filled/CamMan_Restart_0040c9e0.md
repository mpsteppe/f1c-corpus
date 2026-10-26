## CamMan_Restart_0040c9e0 — CameraManagerRestart

**Summary:** Resets camera manager state for restart: logs entry, reinitializes state via global constants, clears stored player ID and byte flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2E | RW | 0 | byte flag reset to 0 on restart |
| this | 0x38 | RW | 18446744073709551615 | stored player entity ID reset to -1 (no previous player) |

**Written-by note (persistence):**
- this 0x2E: written to 0 once on restart; persists until next restart or external modification
- this 0x38: written to -1 once on restart; cleared so next tick detects player change

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be958 | aDDevF119992002_15 | R | AssertStr_SourcePath_15 [DERIVED] |
| 005be980 | aEnteredCammanR | R | EnteredCamManReset [DERIVED] — debug log string |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] — passed to state init |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408290 | StateInitWithGlobalConstants | reinitializes camera state using global constants |
| 004d7a50 | StringSplitLoop | debug log gating |
| 004d7aa0 | DebugLogWrite | writes "entered CamMan_Restart" debug message |

**Guard conditions:** if StringSplitLoop returns non-zero, writes debug log
