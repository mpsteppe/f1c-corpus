## SceneTextureApply_0045cf50 — Format network session display string

**Summary:** Builds formatted network session status display string: formats hostname, host port, map name, player count, max players, and game mode (open/closed) into output buffer using ShortComputation_ce30 key-value pairs. Checks network entrant validity before formatting.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c5be0 | aClosedplaying | R | ClosedplayingString [DERIVED] |
| 005c5bf0 | aOpenplaying | R | OpenPlayingString [DERIVED] |
| 005c5bfc | aGamemode | R | Str_GameMode [DERIVED] |
| 005c5c08 | aMaxplayers_0 | R | StringMaxPlayers [DERIVED] |
| 005c5c14 | aNumplayers | R | ConfigKeyNumPlayers [DERIVED] |
| 005c5c20 | aMapname | R | aMapname [DERIVED] |
| 005c5c28 | aHostport | R | HostPortKey [DERIVED] |
| 005c5c34 | aHostname | R | StringHostname [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045ce30 | ShortComputation_ce30 | Sets key-value pair in output string (backslash processing) |
| 00461550 | FAILWRONGDESCRIPTION | Validation/description setup before formatting |
| 004627c0 | NetworkEntrantSetupWithIDCheck | Checks network entrant validity with ID check |
| 00462a00 | SingleFunctionCallWrapper_2a00 | Queries game module state for open/closed playing flag |
| 004b0170 | EmptyStub_0170 | Cleanup/stub after formatting |
| 004c5690 | SceneDataParser | Parses scene data from globals (player counts) |
| 004c5900 | EventNameReader | Reads event/scene name from scene array |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe integer/string formatting |

**Guard conditions:** BLOCKED if NetworkEntrantSetupWithIDCheck returns 0 → skip all formatting, return EmptyStub_0170 result. PASSES only when network entrant setup succeeds.
