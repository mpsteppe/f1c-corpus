## NetCommParseCommandLine_00463160 — NetCommCommandLineParser

**Summary:** Parses command-line arguments (--host, --connect, --dedicated, --gamename, --password, --name, --maxplayers) and populates a NetComm configuration struct with host/client flags, address, port, game name, and player name. Part of the network communication initialization system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC5 | RW | 1 | isHost flag — set to 1 when --host token present |
| obj | 0xC6 | RW | 1 | isClient/connectActive flag — set to 1 when --connect token present with valid port |
| obj | 0xC8 | RW | 0 | connect address string buffer (79 bytes) — populated from --connect argument, port separated by ':' |
| obj | 0x117 | RW | 0 | unknown (not directly accessed in this function's C; init to 0) |
| obj | 0x1AC | RW | 2 | maxPlayers — parsed from --maxplayers argument, clamped to [2, 104] |
| this | 0x0 | R | — | pointer to NetComm configuration struct (dereferenced once for all obj-relative accesses) |

**Written-by note (persistence):**
- obj 0xC5: once, under --host condition; no other writes in this function
- obj 0xC6: once, under --connect-with-port condition; no other writes in this function
- obj 0xC8: once, under --connect condition; string copied once, may persist until next parse
- obj 0x117: once (init to 0); may be overwritten elsewhere
- obj 0x1AC: once, under --maxplayers condition (or default-clamped to 2); may persist across session

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c3f6c | byte_5C3F6C | R | ConfigDefaultValue [DERIVED] (also: Lookup/config data) |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c6350 | aMaxplayers | R | MaxPlayersString [DERIVED] |
| 005c6360 | aNetcommSetNetw | R | NetCommSetNetworkField [DERIVED] |
| 005c6384 | aName_1 | R | Field_Name [DERIVED] |
| 005c638c | aNoPortSpecifie | R | String_NoPortSpecified [DERIVED] |
| 005c63c8 | aNewAddressStri | R | NewAddressString [DERIVED] |
| 005c63e8 | aAutojoinAddres | R | AutojoinAddresString [DERIVED] |
| 005c642c | aNetcommActivat_0 | R | NetcommActivateString [DERIVED] |
| 005c644c | aConnect | R | String_Connect [DERIVED] |
| 005c6458 | aSettingGameNam | R | s_DebugSettingGameName [DERIVED] |
| 005c6474 | aGamename | R | GameName [DERIVED] |
| 005c6480 | aNetcommActivat | R | NetcommActivateString [DERIVED] |
| 005c64a0 | aHost | R | HostString [DERIVED] |
| 005c64a8 | aDedicated | R | DedicatedString [DERIVED] |
| 005c64b4 | aSettingGamePas | R | SettingGamePasString [DERIVED] |
| 005c64d4 | asc_5C64D4 | R | String_DefaultFont [DERIVED] |
| 005c64d8 | aPassword | R | Str_Password [DERIVED] |
| 005c64e4 | aNetcommCheckin | R | StringNetCommCheckin [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007d1004 | word_7D1004 | R | Unknown_Word_7D1004 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00463710 | StringCopyToStructField | copies parsed password string into a struct field |
| 004d7a50 | StringSplitLoop | debug build guard — checks dev split loop condition for conditional logging |
| 004d7aa0 | DebugLogWrite | writes formatted debug log message to output buffer |
| 00566810 | sub_566810 | substring search — finds command-line token (e.g. "--host") in argument string; returns pointer after token or null |
| 00587c20 | sub_587C20 | searches for ':' separator character in address string to split address:port |
| 00587dd0 | sub_587DD0 | bounded string copy — copies substring up to delimiter or max length |
| 00587ece | sub_587ECE | atoi — converts string to integer (used for port number and maxplayers) |
| 0058815f | StringFormatWithBufferOverflowCheck | sprintf with overflow-safe buffer (formats default port as string) |
| 005897ca | sub_5897CA | string cleanup — strips surrounding quotes and default-font marker from string |

**Guard conditions:** No early-return guard on the struct itself. Each configuration section is gated by `sub_566810(a2, <token>)` — if the token is not found in the command-line string, that section is skipped. Debug logging is additionally gated by `dword_7C569C != 5` (only logs when NOT running in dedicated server mode 5). The --host and --connect branches are mutually exclusive via the `!sub_566810(a2, aDedicated)` and `else` structure: if --dedicated is found, both --host and --connect are skipped.