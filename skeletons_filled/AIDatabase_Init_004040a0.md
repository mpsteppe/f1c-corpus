## AIDatabase_Init_004040a0 — AI Difficulty Database Initialization

**Summary:** Initializes AI driving parameters from a database file: loads track-position speed curves, sets difficulty-scaled aggression values from a slider (dword_7D01A0), and opens the AI database file from disk. Part of the AI difficulty configuration system called at game init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | base aggressiveness multiplier (4.75 default) |
| this | 0x4 | RW | — | secondary aggressiveness multiplier (4.3125 default) |
| this | 0x118 | RW | — | computed difficulty-scaled output value |
| this | 0x11C | RW | — | low-difficulty aggression baseline (0.5) |
| this | 0x120 | RW | — | mid-difficulty aggression baseline (1.0) |
| this | 0x124 | RW | — | high-difficulty aggression baseline (1.3) |
| this | 0x130 | RW | — | track-position speed curve value (index 0, default 3.0) |
| this | 0x134 | RW | — | track-position speed curve value (index 1, default 1.0) |
| this | 0x138 | RW | — | track-position speed curve value (index 2, default 2.0) |
| this | 0x148 | RW | — | unused sentinel value (-1.0f) |
| this | 0x15C | RW | 1 | file-open success flag / parameter count |
| this | 0x160 | RW | 104 | config value: max lane offset or speed multiplier |
| this | 0x164 | RW | 52 | config value: mid-range calibration parameter |
| this | 0x168 | RW | 3 | config value: minimum distance threshold |

**Written-by note (persistence):**
- this 0x0: written once during init — external poke does NOT persist
- this 0x4: written once during init — external poke does NOT persist
- this 0x118: written once during init — external poke does NOT persist
- this 0x11C: written once during init — external poke does NOT persist
- this 0x120: written once during init — external poke does NOT persist
- this 0x124: written once during init — external poke does NOT persist
- this 0x130: written once during init — external poke does NOT persist
- this 0x134: written once during init — external poke does NOT persist
- this 0x138: written once during init — external poke does NOT persist
- this 0x148: written once during init — external poke does NOT persist
- this 0x15C: written once during init — external poke does NOT persist
- this 0x160: written once during init — external poke does NOT persist
- this 0x164: written once during init — external poke does NOT persist
- this 0x168: written once during init — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e474 | flt_59E474 | R | PhysicsConstant_59E474 [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 005be41c | aDDevF119992002_14 | R | StrDevicePath [DERIVED] |
| 005be690 | aRt | R | Str_RT [DERIVED] |
| 005be694 | aAiDatabaseFile | R | Key_AIDatabaseFile [DERIVED] |
| 005be6a8 | aEnteredAidatab | R | EnteredAIDatabaseString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce608 | dword_7CE608 | R | optional alternate directory path for AI database file |
| 007d01a0 | dword_7D01A0 | R | AIDifficultySlider [CONFIRMED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00402690 | sub_402690 | parse and load AI database file contents into struct fields |
| 004c58a0 | StringCopyWithValidation | copy the AI database filename into struct buffer with validation |
| 004d7a50 | StringSplitLoop | device path string tokenization (splits path components) |
| 004d7aa0 | DebugLogWrite | write "Entered AI database" debug message to log buffer |
| 00587d02 | FileCloseWithLock | close the AI database file handle |
| 00587db0 | sub_587DB0 | open the AI database file for reading |
| 00587dd0 | sub_587DD0 | construct full file path by combining directory + filename |

**Guard conditions:** The function has no deterministic guard branches on struct fields. The only branching is: if StringCopyWithValidation fails (filename copy), no file path is constructed; if dword_7CE608 is non-null, use it as the directory path, otherwise fall back to byte_5EA438; if dword_7D01A0 > 100, use high-difficulty interpolation formula, otherwise use low-difficulty formula. These are data-flow branches, not access guards.