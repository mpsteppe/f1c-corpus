## WeatherSurfaceUpdate_004628a0 — Weather Surface Update (session UI progress)

**Summary:** Updates weather surface display during session: validates ID, dispatches state, builds session config, sends buffer, encodes progress bar event, creates textures, and calls OS API for session transition flag. Returns 1 on success, 0 if ID invalid.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461550 | FAILWRONGDESCRIPTION | validates description/format before processing |
| 00461610 | SessionConfigBuilder | builds session configuration data from description |
| 00462250 | TextureCreationWrapper | creates or updates texture resources for weather display |
| 00462760 | BufferSendWithLocks | sends prepared buffer with lock synchronization |
| 004630d0 | UniqueID | validates unique identifier; early-return if zero |
| 00463760 | ConditionalStateDispatch | dispatches state conditionally (arg 0) |
| 004a0dc0 | SystemOSAPICall_0dc0 | calls OS/system API on transition flag |
| 004b33b0 | ProgressBarEventEncode | encodes progress bar event (type 4, stage 5) using session time |

**Guard conditions:** `UniqueID(v2)` check on description buffer: if UniqueID returns 0 (invalid), function BLOCKED, returns 0 immediately. PASSES when UniqueID returns non-zero (valid ID), continues to full update sequence.
