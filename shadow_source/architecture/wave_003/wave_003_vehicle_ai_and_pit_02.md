# VehicleAIAndPitOperations

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

The packet groups 20 validated functions into four clusters. (1) Pit/AI commentary dispatch: 0x0041B3C0 (pit-zone selection state machine, DERIVED owner) and 0x0041BE60 (pit/race status dispatch) plus 0x0041C0F0 (pit-exit message selection, DERIVED owner) all build 8-DWORD driver-table entries via DriverDataTableLookupAndTimeConversion and append them to the session event table at flt_5EA618, guarded by the race-active flag dword_7D0308 and track-condition flt_7CF3C8. (2) AI behavior and setup: 0x0042ACA0 speed-delta flag write at this+0x4550 with a sub_4A46F0 state-transition trigger, 0x0042B8D0 shift-pattern display label rendering, 0x0047AB35 overtake gap calc over a per-AI-car array. (3) Vehicle/terrain/physics: 0x0043E4B0 rigid-body constraint position solve (FPU control-word preservation, rotation transform, wheel-constraint entry reset), 0x004624E0 terrain roughness height comparison, 0x0049BA50 fuel-weight boolean check over dword_7C54E0 floats. (4) String/path/standings/UI/archive utilities: 0x00421930/0x00421970 twin path-normalize-and-copy helpers (merged into one class per no-merge rule, they are structural twins with identical bodies), 0x00432650 in-place title casser, 0x0041E890 entrant lookup by name in the standings buffer, 0x00471DC0 transmission/AI-difficulty screen setup, 0x00476D70 UI render-chain update, 0x0047F300 scene filename base-path match, 0x0049CA00 cockpit LED gauge one-shot init with MAS archive/BMP/texture/animation allocation, 0x004A24D0 pit-crew animation name-to-enum mapper, plus two low-trust wrappers 0x00461550 and 0x00469857 kept as isolated GUESS classes. Most owners are UNKNOWN in the packet; only the pit-zone and pit-exit dispatchers carry DERIVED ownership, and all other classes are GUESS boundaries derived from single functions.

## Function roles

- `0x0041B3C0` **PitSelectionStateMachine** — Per-frame pit-selection commentary state machine: race-active/track/phase guards, requested zone index from clamped a4, projected zone from player-vehicle distance projection, dispatch on state 0 (deactivate zone, event codes 133/135/137 or 126), 2 (activate zone, preceding-event pairs then commit this[v7+316]=2), 3 (generic event 131), 5 (player pit-entry sub-events 123-125), all emitted into session table flt_5EA618.
- `0x0041BE60` **PitRaceStatusMessageDispatcher** — Pit/race status driver-table message dispatcher: guarded on race-active and track-condition, classifies via sub_4FF130(&unk_8AFEC0) and computes an audio filter parameter via AudioFilterParameterCalculation, then switch-dispatchs on the classification to record/insert messages 506-513 gated by temperature (flt_8AFEF0 > 30.0) and track-grip-average ((flt_8AFEE8 + flt_8AFEEC) * 0.5 > 0.7).
- `0x0041C0F0` **PitExitMessageDispatcher** — Pit-exit commentary dispatcher: locates the car slot by driver number (a2+1) in the vehicle array (dword_5F0738, stride 4656), selects audio message id (default 397, range 516-535) from the slot's relationship classification this[v4] (1/2/3), the player's race position and parity thresholds, championship mode dword_7D0410, and an optional random jump-table remap, then emits via DriverDataTableLookupAndTimeConversion/InsertDriverTableEntry.
- `0x0041E890` **StandingsEntrantNameLookup** — Entrant lookup by name: iterates candidate indices 0..102 in the standings sort buffer dword_7D2DB0, dereferences each node via LinkedListDereference, resolves the per-index entry via ShortComputation_13a0, reads its name pointer at entry offset 0 (fallback byte_5EA438), compares with sub_588410, and returns the matched entry's dword at offset 408, or 0 when exhausted.
- `0x00421930` **PathNormalizingStringCopier** — Path normalization and copy: normalize trailing backslashes via PathTrailingBackslashNormalizer(a1) then return StringCopyWithBufferRealloc(a1); called by ConfigIniParser.
- `0x00421970` **PathNormalizingStringCopier** — Path normalization and copy (structural twin of 0x00421930 with an identical body): normalize trailing backslashes via PathTrailingBackslashNormalizer(a1) then return StringCopyWithBufferRealloc(a1); called by ConfigIniParser.
- `0x0042ACA0` **AISpeedDeltaSetter** — AI speed-delta setter: for allowed inputs a2 in {0, 1} writes a2 to this+0x4550, and when activating (a2 == 1) calls sub_4A46F0(this, 1, 0) to trigger an AI state transition and returns its result; otherwise returns a2 unchanged.
- `0x0042B8D0` **AIShiftPatternDisplay** — AI shift-pattern display: BitmaskStateTest gate selects a disallowed-message path ("[base].HOT" + Disallowed text) or a state-cycle path that increments/wraps the index counter *a2, selects a state string by mode/index (upshifts/downshifts/on/high/registered), composes "[base].HOT[state]", renders via TextLineWrappingAndRendering, and returns BrakeBiasSetup's result.
- `0x00432650` **StringTitleCaser** — In-place title-case conversion of a NUL-terminated byte string: capitalizes the first char if lowercase, then walks from this[1] and uppercases the current char after a non-letter predecessor or lowercases it after a letter predecessor; returns the trailing NUL byte as a loop artifact.
- `0x0043E4B0` **RigidBodyConstraintSolver** — Rigid-body constraint position solve: saves/restores the FPU control word, converts Euler angles to a 3x3 rotation matrix, transforms body position (this+0x15FC/+0x1604/+0x160C), computes the position error against the supplied pose a2, applies the correction via sub_56F100, clears the constraint-enable flag at this+0xB4, and resets four wheel-constraint entries at this+0x3A8 (stride 1124) with -1 / -1048577; per-frame callee of AIVehiclePathPositionTracking (0x004EF7C0).
- `0x00461550` **DelegatingInitializerWrapper** — Delegate-call-return-this wrapper: calls sub_461560() with no visible arguments and returns the original this pointer; shape is consistent with a constructor forwarding to an initializer, but the role is not confirmed.
- `0x004624E0` **TerrainHeightComparator** — Terrain roughness comparison: substitutes the fallback global flt_7D108C for a negative caller threshold, samples the terrain surface buffer behind this+0x0 (byte offset 107456) via TerrainSurfaceRoughnessHeightSampling, and returns whether the threshold is below the absolute sampled height.
- `0x00469857` **ThreeCallChain** — Three-call chain wrapper: makes an indirect call through decompiler artifact MEMORY[0x5746985D](), calls GuardedAccessor(v0), and returns FilenameFromLinkedList(v1, v2); v0's origin (ECX) and effective calling convention are uncertain because of a flagged bad stack value.
- `0x00471DC0` **TransmissionAIDifficultyScreen** — Transmission/AI-difficulty screen parameter initializer: stores race-mode dword_7D0410 at this+0x324 and the address of the audio race-mode flag global dword_7D1FD8 at this+0x320, fetches the UI list item indexed by the flag, formats it, pushes it into the edit buffer, and returns 0 with no guards.
- `0x00476D70` **UIRenderUpdateChain** — UI render-chain update for one frame: optionally ticks the engine interface at dword_5EB10C via vtable+12, re-initializes the render buffer flt_5EA618 with 10f defaults, walks a linked-list accessor for an indexed render entry, and when the entry reports a positive element count re-runs the tick and resolves the team-name display entry via TeamNameDisplayIDLookup.
- `0x0047AB35` **AIOvertakeGapCalculator** — AI overtake gap calculation over an array object a4 (likely per-AI-car state): stores a1 into a4[60], computes a4[64] from a virtual call on a2 minus twice a4[62] minus saved a4[3], and computes a4[69] from virtual calls at byte offsets 36 and 28, with a ConditionalDelegation_6460 gate and negative-gap fallback a3; always returns 0.
- `0x0047F300` **SceneFilenameMatchChecker** — Scene filename base-path match: iterates the scene-file array (dword_8AC490, stride 396) for count dword_8AC488, compares each non-empty filename at entry+4 against the base path dword_7CE5D0 (fallback byte_5EA438) via sub_596C80, breaking with the comparison result on a match, else falling back to AIW(0).
- `0x0049BA50` **FuelWeightChecker** — Fuel-weight boolean check: when fuel quantity dword_7D0B64 is positive, returns whether the quantity converted to weight (times 0.050000001) exceeds the product of two floats read from the structure pointed to by dword_7C54E0 at byte offsets 14724 and 14732; returns false when not positive. Consumed as a boolean by three callers.
- `0x0049CA00` **CockpitDashboardLEDGauge** — One-shot cockpit dashboard LED-gauge HUD widget init: guarded by the byte init flag at this+0x0; creates five LED sub-elements via sub_49CD80, resolves two control strings and eleven UI-manager handles via sub_548890, builds a cmaps archive path from directory globals, loads three BMP textures at this+0x4/0x8/0xC, allocates animation-control memory at this+0x18/0x1C, sets the init flag, and returns an accumulated success flag.
- `0x004A24D0` **PitCrewAnimationStringMapper** — Pit-crew animation string mapper: normalizes the input string via sub_589901, then runs a chain of strcmp comparisons against pit-crew animation string globals (jack, lollipop, fuel, wheels, 10-second crew roles) returning the matched enum ID in 0-24; returns 0 for the first entry or no match.

## Proposed classes

### PitSelectionStateMachine

Per-frame pit-zone selection commentary: computes a requested zone index (clamped input) and a projected zone index (player distance projection), and dispatches on an event/state argument to deactivate (state 0), activate (state 2), emit a generic event (state 3), or handle player pit entry (state 5), appending driver-table entries to the session event table flt_5EA618.

Methods: `0x0041B3C0`


### PitRaceStatusMessageDispatcher

Dispatches pit/race status driver-table messages (IDs 506-513) when the race is active and the track-condition state is non-zero, classifying via sub_4FF130 on &unk_8AFEC0 and gating on temperature and track-grip-average globals. Packet owner is UNKNOWN; class boundary is GUESS from the single function.

Methods: `0x0041BE60`


### PitExitMessageDispatcher

Emits a pit-exit commentary message for the car whose driver number is leaving the pit lane: locates the vehicle slot in the array (dword_5F0738, stride 4656), selects an audio message id (397 default, 516-535 range) from the slot's relationship classification and the player's relative position/parity, with a championship-mode gate and optional random remap, and appends the entry to the session table.

Methods: `0x0041C0F0`


### StandingsEntrantNameLookup

Searches the standings sort buffer (dword_7D2DB0) for the first entry whose name matches the input, resolving each candidate node/index through LinkedListDereference and ShortComputation_13a0 and comparing names with sub_588410, returning the matched entry's value at offset 408 or 0 when the 103-candidate bound is exhausted.

Methods: `0x0041E890`


### PathNormalizingStringCopier

Normalizes trailing backslashes on a path string via PathTrailingBackslashNormalizer and returns the copy produced by StringCopyWithBufferRealloc. Two structural twins (0x00421930 and 0x00421970) with identical bodies are merged into this one class.

Methods: `0x00421930`, `0x00421970`


### AISpeedDeltaSetter

Writes the AI speed-delta flag at this+0x4550 for allowed inputs 0/1 and, when activating, triggers an AI state transition via sub_4A46F0(this, 1, 0). Packet owner UNKNOWN; class boundary GUESS.

Methods: `0x0042ACA0`

- `this+0x00004550` `int SpeedDeltaFlag` (read_write, DERIVED)

### AIShiftPatternDisplay

Renders the AI shift-pattern configuration label: builds "[base].HOT" plus either the Disallowed message or a state string cycled by an index counter, renders via TextLineWrappingAndRendering, and returns a brake-bias setup result. Packet owner UNKNOWN; class boundary GUESS.

Methods: `0x0042B8D0`

- `this+0x00000000` `int ShiftPatternIndex` (read_write, DERIVED)

### StringTitleCaser

In-place ASCII title-case conversion of a NUL-terminated byte string: capitalizes the first character, then uppercases characters that follow a non-letter and lowercases characters that follow a letter. Packet owner UNKNOWN; class boundary GUESS.

Methods: `0x00432650`

- `this+0x00000000` `char FirstChar` (read_write, DERIVED)
- `this+0x00000001` `char CurrentChar` (read_write, DERIVED)

### RigidBodyConstraintSolver

Rigid-body constraint position solve: preserves the FPU control word, converts Euler angles to a 3x3 rotation matrix, transforms the body position, computes the position error against a supplied pose, applies the correction via sub_56F100, clears the constraint-enable flag, and resets four wheel-constraint entries. Packet owner UNKNOWN; class boundary GUESS from the single function.

Methods: `0x0043E4B0`

- `this+0x000000B4` `int ConstraintEnableFlag` (write, DERIVED)
- `this+0x000003A8` `int WheelConstraintDisableA` (write, DERIVED)
- `this+0x000003AC` `int WheelConstraintDisableB` (write, DERIVED)
- `this+0x000015F0` `void* BodyObject` (read, DERIVED)
- `this+0x000015FC` `double BodyPositionX` (read, DERIVED)
- `this+0x00001604` `double BodyPositionY` (read, DERIVED)
- `this+0x0000160C` `double BodyPositionZ` (read, DERIVED)

### DelegatingInitializerWrapper

Thin thiscall wrapper that calls sub_461560() with no visible arguments and returns the original this pointer; shape is consistent with a constructor body forwarding to an initializer, but the role and sub_461560's identity are unconfirmed. Owner UNKNOWN.

Methods: `0x00461550`


### TerrainHeightComparator

Samples the terrain surface roughness height at a grid position through the sampling buffer behind this+0x0 (byte offset 107456) and returns whether the absolute sampled height exceeds a threshold, substituting the fallback global flt_7D108C for a negative caller-supplied threshold. Owner UNKNOWN.

Methods: `0x004624E0`

- `this+0x00000000` `void* SamplingBufferBase` (read, DERIVED)

### SceneFilenameMatchChecker

Iterates the scene-file array (dword_8AC490, stride 396) for a held count, compares each non-empty entry filename against a base path (dword_7CE5D0, fallback byte_5EA438) via sub_596C80, returning the match result or the AIW(0) fallback when exhausted. Owner UNKNOWN.

Methods: `0x0047F300`


### TransmissionAIDifficultyScreen

Initializes transmission/AI-difficulty screen parameters: stores the race-mode value dword_7D0410 at this+0x324 and the audio race-mode flag address dword_7D1FD8 at this+0x320, fetches and formats the UI list item, pushes it into the edit buffer, and returns 0. Owner UNKNOWN.

Methods: `0x00471DC0`

- `this+0x00000320` `int* RaceModeFlagPtr` (write, DERIVED)
- `this+0x00000324` `int RaceModeValue` (write, DERIVED)

### UIRenderUpdateChain

Updates the UI render chain for one frame: optionally ticks the engine interface at dword_5EB10C via a vtable+12 call, re-initializes the render buffer flt_5EA618 with 10f defaults, walks a linked-list accessor for an indexed render entry, and resolves the team-name display entry when the entry reports a positive element count. Owner UNKNOWN.

Methods: `0x00476D70`


### AIOvertakeGapCalculator

Calculates an AI overtake gap over an array object a4 (likely per-AI-car state): stores the input into a4[60], computes gap values into a4[64] and a4[69] from virtual calls with threshold fallbacks, always returning 0. Owner UNKNOWN; a4 layout class-specific.

Methods: `0x0047AB35`


### FuelWeightChecker

Boolean fuel-weight check in the pit subsystem: returns whether the fuel quantity dword_7D0B64 converted to weight exceeds the product of two floats at dword_7C54E0+14724/+14732, returning false when the quantity is not positive. Consumed as a boolean by three callers. Owner UNKNOWN.

Methods: `0x0049BA50`


### CockpitDashboardLEDGauge

One-shot initialization of the cockpit dashboard LED-gauge HUD widget: guarded by the byte init flag at this+0x0; creates five LED sub-elements, resolves control strings and UI-manager handles, builds a cmaps archive path, loads three BMP textures, allocates animation-control memory, sets the init flag, and returns an accumulated success flag. Owner UNKNOWN.

Methods: `0x0049CA00`

- `this+0x00000000` `char InitFlag` (read_write, DERIVED)
- `this+0x00000004` `void* TextureHandleA` (write, DERIVED)
- `this+0x00000008` `void* TextureHandleB` (write, DERIVED)
- `this+0x0000000C` `void* TextureHandleC` (write, DERIVED)
- `this+0x00000010` `char* PrimaryControlString` (write, DERIVED)
- `this+0x00000014` `char* SecondaryControlString` (read_write, DERIVED)
- `this+0x00000018` `void* AnimationControlA` (write, DERIVED)
- `this+0x0000001C` `void* AnimationControlB` (write, DERIVED)
- `this+0x00000020` `void* UIManagerHandle0` (write, DERIVED)
- `this+0x00000024` `void* UIManagerHandle1` (write, DERIVED)
- `this+0x00000028` `void* UIManagerHandle2` (write, DERIVED)
- `this+0x0000002C` `void* UIManagerHandle3` (write, DERIVED)
- `this+0x00000030` `void* UIManagerHandle4` (write, DERIVED)
- `this+0x00000034` `void* UIManagerHandle5` (write, DERIVED)
- `this+0x00000038` `void* UIManagerHandle6` (write, DERIVED)
- `this+0x0000003C` `void* UIManagerHandle7` (write, DERIVED)
- `this+0x00000040` `void* UIManagerHandle8` (write, DERIVED)
- `this+0x00000044` `void* UIManagerHandle9` (write, DERIVED)
- `this+0x00000048` `void* UIManagerHandle10` (write, DERIVED)

### PitCrewAnimationStringMapper

Maps a pit-crew animation name string to an integer enum ID in 0-24: normalizes the input via sub_589901, then runs a chain of strcmp comparisons against pit-crew animation string globals (jack, lollipop, fuel, wheels, 10-second crew roles), returning the matched enum value or 0. Owner UNKNOWN.

Methods: `0x004A24D0`


### ThreeCallChain

Thin wrapper chain: makes an indirect call through a decompiler artifact address, calls GuardedAccessor on the ECX pointer, and returns FilenameFromLinkedList with the original pointer and the accessor result. v0's origin and the calling convention are uncertain due to a flagged bad stack value. Owner UNKNOWN.

Methods: `0x00469857`


## Compatibility contracts

- **SessionDriverTableAppendContract** — A replacement must preserve the sentinel-guarded append into the session event table at flt_5EA618 via InsertDriverTableEntry, with 8-DWORD entries initialized by StructInitWithSentinelValues and filled by DriverDataTableLookupAndTimeConversion using -1 sentinels and -2.0 default arguments; the first entry field (LODWORD(v13[0]) == -1) gates insertion.
- **PitSelectionZoneEventContract** — Preserve the per-zone activation flag semantics (this[v7 + 316] cleared on deactivate, set to 2 on activate) and the emitted event codes: 123-125 (player pit-entry sub-events for a6 1/2/3), 126 (zone-matching re-entry), 131 (generic event), 133-138 (zone deactivate/activate codes 137/134, 133/136, 135/138). Event-code semantics are inferred from call signatures and remain unverified.
- **PitExitMessageSelectionContract** — A replacement must locate the pit-exit car slot in the vehicle array (dword_5F0738, stride 4656) by its first dword against driver number a2+1, select the audio message id (default 397, range 516-535) from the slot's relationship classification this[v4] (1/2/3), the player's race position at dword_7C54E8+16480, position-fraction thresholds on dword_5C329C, parity and championship mode dword_7D0410, and apply the random jump-table remap (528->526, 529->527, 531->530, 534->532, 535->533) when RandLCGRandomNumberGenerator returns odd.
- **AISpeedDeltaContract** — A replacement must write the speed-delta flag at this+0x4550 only for inputs 0/1 and, when activating (a2 == 1), trigger the AI state transition via sub_4A46F0(this, 1, 0), returning its result; inputs outside {0, 1} must pass through unchanged.
- **RigidBodyConstraintLayoutContract** — The constraint-solver object must keep the constraint-enable flag at this+0xB4, the body object pointer at this+0x15F0, the body position doubles at this+0x15FC/+0x1604/+0x160C, and four wheel-constraint entries starting at this+0x3A8 with stride 1124 initialized to -1 / -1048577.
- **CockpitDashboardLEDGaugeLayoutContract** — The LED-gauge widget object must keep the init flag byte at this+0x0, three BMP texture handles at this+0x4/+0x8/+0xC, the resolved primary/secondary control strings at this+0x10/+0x14, the two animation-control allocations at this+0x18/+0x1C, and eleven UI-manager handles at this+0x20..this+0x48.
- **TransmissionAIDifficultyScreenLayoutContract** — The transmission/AI-difficulty screen object must keep the race-mode value at this+0x324 and a pointer to the audio race-mode flag global at this+0x320; setup must fetch the UI list item indexed by dword_7D1FD8, format it via StringFormatWithBufferOverflowCheck and push it into the edit buffer via EditBufferStringUpdate.
- **StringTitleCaseContract** — A replacement must perform in-place ASCII title-casing on a NUL-terminated string: uppercase the first character when it is a lowercase letter, then for each subsequent character uppercase it when the previous character is a non-letter (outside 'A'-'Z'/'a'-'z') or lowercase it when the previous character is a letter.

## Unresolved

- PitSelectionStateMachine (0x0041B3C0): packet globals flt_59E440, flt_59E824, flt_59E828, dword_8ACEE0, dword_8AD264 do not appear in the decompiled source; per-zone flag this[v7+316] and player-vehicle offsets 13388/+12 have no field entries; the semantics of event codes 123-138 and of BooleanOROfTwoChecks/ArraySearchReturningIndex argument shapes are inferred, not confirmed.
- PitRaceStatusMessageDispatcher (0x0041BE60): read-only floats flt_59E440, flt_59E450, flt_59E468, dbl_59E830 are absent from the body (likely folded constants); the meaning of the v0 classification cases and v1 values 2/3/4/5 is inferred from call sites only.
- PitExit (0x0041C0F0): globals flt_59E440, flt_59E450, flt_59E800, dbl_59E838 are unobserved (prose labels them physics-related thresholds); audio message ids 397 and 516-535 are not verified against a message/emitter table; this[v4] classification semantics (player/rival/constructor-rival) and offsets +16480/+18588 are unconfirmed.
- AIEntrantLookupByName (0x0041E890): the meaning of the returned entry offset-408 value is not proven; sub_588410 comparison semantics (equality vs prefix) are undefined; byte_5EA438 fallback content and the 103-entry bound are unexplained; abi:lead and caller 0x00418EE0 are recorded but unverified.
- AISpeedDeltaSetter (0x0042ACA0): global 0x007CE2F0 is not visible in the raw source; the sub_4A46F0 (1, 0) transition arguments are only caller-visible.
- AIShiftPatternDisplay (0x0042B8D0): byte_7CE498 is a data-adjacency artifact; caller sub_42C440's frame-path role is unproven; BinarySearchInStringTable's output-buffer contract is inferred; the decimal literal 16909060 meaning is not evidenced.
- StringCapitalizer (0x00432650): guard literals are ASCII constants from raw source; caller SettingsCopySetupFileCopy (0x00432220) context is unverified; the return value is a loop-test artifact.
- RigidBodyConstraintSolve (0x0043E4B0): the physical meaning of the -1 / -1048577 wheel-constraint initializers is undocumented; sub_56F100 is not inlined so the error-vector effect resolves only at the callee.
- DelegatingInitializerWrapper (0x00461550): whether this is a constructor body, a forwarding wrapper, or a generic delegating method cannot be determined; sub_461560's identity is unknown.
- TerrainHeightComparison (0x004624E0): flt_59E440's role is unconfirmed; the layout of the sampling buffer behind this+0x0 (+107456) is undefined; the sample position a2 meaning (grid index vs world coordinate) is unknown.
- ThreeCallChain (0x00469857): the indirect call MEMORY[0x5746985D]() has unknown target and signature; v0 originates from ECX but the signature/convention are undefined (flagged bad stack value); no callers recorded.
- TransmissionAIDifficultyScreen (0x00471DC0): ABI record is FAIL_471dc0; the owning object and the pointer stored at this+0x320 are unestablished; consumption of 0x320/0x324 elsewhere is unproven.
- UIRenderUpdateChain (0x00476D70): the vtable+12 method identity on dword_5EB10C is unknown; list-entry offsets +72 (count), +60 (pointer table) and +60 (team display handle) are unnamed; global 0x005EB978 is absent from the body.
- AIOvertakeGapCalc (0x0047AB35): a4 array layout and the dword indices 3/60/62/64/69/70 are class-specific; virtual methods at byte offsets 24/28/36 and the threshold constant 20 are unknown.
- SceneFilenameMatch (0x0047F300): the scene array entry structure (stride 396, filename at +4) is inferred from indexing; sub_596C80 comparison/return semantics are undocumented; the AIW(0) fallback meaning and global 0x008AC368 are unresolved.
- FuelWeightComputation (0x0049BA50): flt_59E448 may hold the folded 0.050000001 factor but the link is unproven; offsets 14724/14732 on dword_7C54E0 have no field names; the three callers' HUD/UI usage is not described.
- CockpitDashboardLEDGaugeSetup (0x0049CA00): dword_8AFE64 is absent from the body; the sub-element layout at this+0x60/0xAC/0xF8/0x144/0x190 and the float bit-pattern literals (1133969408, 1118437376, 1129447424, 1134886912) are unverified; contracts of sub_49CD80/sub_53CBC0/sub_53CFE0/sub_548890 are grounded only in the naming signal; texture flag 67585 and the eleven UI-manager handle purposes are unresolved; callers NetCommPlayerSlotSync (0x0045FC50) and OnScreen_Init (0x0049EFA0) are recorded but the function is not on a frame path.
- PitCrewAnimationStringMapper (0x004A24D0): the returned enum values are sequential IDs without concrete pit-crew animation meanings; sub_589901's normalization side effect is invisible; the __thiscall prototype reads no this-relative field so the owning class is unresolved.
