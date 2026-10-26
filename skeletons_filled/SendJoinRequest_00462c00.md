## SendJoinRequest_00462c00 — Send Join Request to Multiplayer Host

**Summary:** Sends a multiplayer join request to a remote host. Reads session entry by index, formats IP:port string, optionally logs "Sending join request", resets join retry flag at +0x378, and delegates to CollisionSpatialQuery. Returns 0 if session entry not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiplayerPasswordValidation (0046dd30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x378 | RW | 0 | join retry/reset flag; zeroed before sending |
| obj | 0x1B79C | R | — | session entry array pointer for index bounds-checked read |
| this | 0x0 | R | — | vtable/primary pointer |

**Written-by note (persistence):**
- obj 0x378: written once per call (set to 0); external poke would survive if no other call overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5c28 | aHostport | R | HostPortKey [DERIVED] |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c61f4 | aSendingJoinReq | R | SendingJoinRequestString [DERIVED] |
| 005c6214 | aSD_2 | R | String_SD [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00462ce0 | CollisionSpatialQuery | executes spatial/network query with formatted address and parameter a3 |
| 004d7a50 | StringSplitLoop | splits/dev-check for debug logging guard |
| 004d7aa0 | DebugLogWrite | writes "Sending join request" debug message |
| 00563e80 | IndexBoundsCheckedArrayRead | reads session entry from array at offset +0x1B79C by index a2 |
| 00564490 | IPAddressToString | converts session entry to IP address string |
| 00564530 | StringComparisonWithConstantDispatch | string comparison for dev-mode detection (arg 0) |
| 0058815f | StringFormatWithBufferOverflowCheck | formats "%s:%d" IP:port string into buffer |

**Guard conditions:** `IndexBoundsCheckedArrayRead` returns null (session entry not found): BLOCKED, return 0 immediately. Otherwise PASSES — formats, logs, resets flag, and sends.
