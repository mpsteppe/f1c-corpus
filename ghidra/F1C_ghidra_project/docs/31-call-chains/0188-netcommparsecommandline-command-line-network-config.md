# Chain 187: NetCommParseCommandLine — Command-Line Network Config

Seed: FUN_00463160  |  System: docs/09-track-system.md  |  Depth: 1  |  Functions: 8

---

## Overview

Parses command-line arguments for network session configuration. Reads the command line tokenizing tokens, then matches known flags: `/password`, `/connect`, `/gamename`, `/maxplayers`. Sets password via FUN_00463710, stores server address with autojoin flag, sets autohost with game name, and clamps max players to [2, 104]. All paths guard trace output against SessionType5 == 5 (server mode).

## Call Tree

```
FUN_00463160 — NetComm::ParseCommandLine  [called once at startup from cmd line parsing]
  +-- FUN_004d7a50 — String Split Loop (trace gate)  [guards debug output]
  +-- FUN_004d7aa0 — Debug Log Write  [trace logging]
  +-- FUN_00566810 — [unnamed — file/token reader]  [reads command line tokens]
  +-- FUN_00587c20 — [unnamed — string utility]  [string manipulation]
  +-- FUN_00587ece — [unnamed — file/string]  [buffer management]
  +-- FUN_0058815f — String Format with Buffer Overflow Check  [safe string format]
  +-- FUN_005897ca — File Read/Tokenizer  [tokenizer for command line]
  +-- FUN_00463710 — String Copy to Struct Field  [stores password value]
```

## Step-by-Step Trace

### Level 0: FUN_00463160 — NetComm::ParseCommandLine

**Trigger:** Called once at game startup during command-line argument processing.

**Called by:** Game initialization dispatch (callers.json shows 1 caller).

**Purpose:** Parses command-line arguments for network session configuration. Extracts password, autojoin/autohost settings, game name, network name, and max player count.

**Key actions:**
1. Reads command line via FUN_00566810 repeatedly, looking for known flags
2. `/password <value>` → calls FUN_00463710 to store password
3. `/connect <host:port>` → stores server address at param_1+200, extracts port, sets autojoin flag at +0xc6, appends local address
4. `/gamename <name>` → sets autohost flag at +0xc5, stores game name at +0x16c
5. `/maxplayers N` → stores at +0x1ac, clamps to [2, 104]
6. All paths guard trace output against DAT_007c569c (SessionType5 == 5, server mode)

**Data passed to callees:** param_1 (network config struct), token values, parsed values

### Level 1: Callees

**FUN_004d7a50 — String Split Loop (trace gate)**
- Leaf function (docs/20-math-utilities.md)
- Guards debug/trace output based on server mode
- Prevents verbose logging in server (SessionType5==5)

**FUN_004d7aa0 — Debug Log Write**
- Leaf function (docs/06-session-race-logic.md)
- Writes trace/diagnostic output
- Conditionally executed based on trace gate

**FUN_00566810 — [unnamed — file/token reader]**
- Leaf function (docs/06-session-race-logic.md)
- Reads command line tokens sequentially
- Returns next token string for flag matching

**FUN_00587c20 — [unnamed — string utility]**
- Leaf function (docs/06-session-race-logic.md)
- String/buffer utility for command line parsing

**FUN_00587ece — [unnamed — file/string]**
- Leaf function (docs/08-file-formats.md)
- Buffer/string management helper

**FUN_0058815f — String Format with Buffer Overflow Check**
- Leaf function (docs/08-file-formats.md)
- Formats path/address strings with overflow protection
- Used for building server address strings

**FUN_005897ca — File Read/Tokenizer**
- Leaf function (docs/08-file-formats.md)
- Tokenizer for parsing command line
- Handles whitespace-delimited token extraction

**FUN_00463710 — String Copy to Struct Field**
- Leaf function (docs/20-math-utilities.md)
- Copies password value string to param_1 network config field
- Used by `/password` flag handler

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00566810 | command line | Read token | Token string |
| `/password` match | token | Compare string | Password flag |
| FUN_00463710 | password value | Copy to struct | Password stored at param_1 |
| `/connect` match | token + address | Parse host:port | Server addr + autojoin flag |
| `/gamename` match | token + name | Store game name | Autohost flag + game name |
| `/maxplayers N` | token + N | Clamp to [2,104] | Max players stored |

## Globals Read

| Global | Name | Used by | Purpose |
|--------|------|---------|---------|
| DAT_007c569c | SessionType5 | FUN_00463160 | Guard trace output in server mode |

## Notes

- All 8 callees are leaf functions — this is a pure flat dispatch chain
- Only `/password` has a dedicated handler (FUN_00463710); other flags store directly to struct fields
- The autojoin/autohost flags at +0xc6 and +0xc5 control network session startup behavior
- Max players clamped to [2, 104] ensures valid range

---
