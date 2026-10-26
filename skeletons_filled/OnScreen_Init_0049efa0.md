## OnScreen_Init_0049efa0 — OnScreen_Init

**Summary:** OnScreen initialization called during Game_Init. Runs assertion log, initializes race session with constants, conditionally sets up cockpit LED gauge based on vehicle count, dispatches resource delegate, and calls sub-initializer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ccf10 | aDDevF119992002_16 | R | AssertStr_SourcePath_16 [DERIVED] |
| 005ccf54 | aEnteredOnscree_1 | R | EnteredOnScreenString [DERIVED] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007ce058 | dword_7CE058 | R | Unknown_UI_Singleton [DERIVED] (also: ` — UI context object) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bbe0 | DoubleDelegateCall_bbe0 | Double delegate dispatch on resource manager |
| 0049b0a0 | sub_49B0A0 | OnScreen sub-initializer |
| 0049ca00 | CockpitDashboardLEDGaugeSetup | Sets up cockpit LED gauge UI |
| 004d7a50 | StringSplitLoop | Assertion check parsing source path string (arg 2616) |
| 004d7aa0 | DebugLogWrite | Writes debug log message when assertion passes |
| 004d8220 | RaceInitWithConstants | Initializes race session mode with constants |

**Guard conditions:** Checks StringSplitLoop return != 0 (assertion log gate); checks dword_5C329C > 0 (only init LED gauge if vehicles exist)
