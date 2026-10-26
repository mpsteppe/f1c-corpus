## SendServerOKRequest_00460470 — SendServerOKRequest

**Summary:** Sends server ready/OK signal based on session phase. During active phases (1-2), marks self as ready via NetComm. Otherwise encodes progress event and creates texture for OK indication.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3FC4 | R | — | Session phase (1-2 = active, triggers ready signal) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c5f6c | aSendingServerO | R | SendingServerOverflow [DERIVED] — "Sending server overflow" debug string |
| 005c5f90 | aErr | R | String_Err [DERIVED] |
| 005c5f94 | aOk | R | s_OK [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] — guards debug logging |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] — used for progress bar encoding |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00460520 | NetComm_SetSelfAsReady | Set self as ready in network communication state |
| 00462250 | TextureCreationWrapper | Create texture for OK indication |
| 004b33b0 | ProgressBarEventEncode | Encode progress bar event (type 4, subtype 3) |
| 004d7a50 | StringSplitLoop | Sanitize debug message string |
| 004d7aa0 | DebugLogWrite | Write debug log entry |

**Guard conditions:**
- this[0x3FC4/4] (phase) > 0 && <= 2 → early return with NetComm_SetSelfAsReady(-1).
- Phase < 1 or > 2 → encode progress bar event (4, 3), create texture.
- Debug logging: "Sending server overflow" logged only if dword_7C569C != 5 (not server).
