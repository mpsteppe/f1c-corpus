# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 20 validated functions in scope generic_runtime_objects. One packet-DERIVED owner (0x004A2220 PitCrewAnimationStruct) forms the pit-crew animation struct init/cleanup; the load-setup function 0x004A4900 that allocates its animation objects is grouped under a GUESS PitCrewAnimationManager. The eighteen remaining functions have packet-UNKNOWN owners and are grouped conservatively by shared globals: SessionLifecycleManager (scene video load, race finish, session-UI dispatch, session-type guard, restart gate; all touch dword_7CD8C0 / dword_7C569C / dword_7CE25x), SettingsFileManager (autoload config, profile bootstrap, settings swap-write, environment setup, player-name extraction, name-compare-and-format; all touch byte_5EA438 and the settings/season directory globals), SessionConfigObject (six-slot config activation + state-gated bitmask test; both read this+0x1F78), ConfigTokenScanner (token scan + dual-path teardown), and a GenericRuntimeObject catch-all (progress-bar event encode, screenshot handler, resource-handle registration). The shared dispatch/session-state globals are captured as ISessionDispatch / ISessionState / IProgressBarEventQueue interfaces and the GameActionStateMachine / SessionStateMachine / RestartCountdownStateMachine state machines.

## Function roles

- `0x004A09F0` **SessionLifecycleManager** — Loads the scene .bik video: guard on scene entry (dword_8AC490 + 396*dword_8AC48C) non-null and dword_7D032C==1, extracts directory from scene name, formats base+dir+'.bik', loads via FileLoadWithRetryLoop; returns 1 when the guard fails.
- `0x004A0BA0` **SessionLifecycleManager** — Race-completion handler: per-driver race commentary, advance action state machine to post-race state 5, session-state transition, conditional menu-mode switch on player finish flag + timing expression > 60.0 + session mode != 19, dispatch in-race event 19; always returns 0.
- `0x004A0DF0` **SessionLifecycleManager** — Session-state UI dispatch: SessionStateCheck(dword_7CD25C) -> vtable dispatch (offset 28, args 36/35 for states 3/2), then UITextInputHandler + UIListSelectionHandler + SoundEffectLoadPlay on non-null result; else returns state value.
- `0x004A0E70` **SessionLifecycleManager** — Session-type guard for command dispatch: returns 0 unless dispatch interface dword_7CD8C0 non-null and (session type 2 or 6, or HUD-disable flag byte_7CE254 set); then forwards a2/a3 to sub_4989E0 and returns 1.
- `0x004A0FD0` **SessionLifecycleManager** — Session restart/main-menu gate polled by GamePostMainLoop: mini-restart flag -> cleanup pass + return 4; full-restart flags -> return 6; countdown state machine; session-type/init-guard path; input-action-map menu transition scan; returns session type dword_7C569C.
- `0x004A1B90` **ConfigTokenScanner** — Scans settings-file token stream stripping separators, compares each token against reference path this+0x4 (fallback byte_5EA438), invokes virtual callback through vtable at this+0x0 on match; returns 1 once matched else 0.
- `0x004A1F10` **ConfigTokenScanner** — Runs three dual-path resource lookups: against global path token word_5C30B4, then custom path this[1] (fallback byte_5EA438), then global again; always returns 1.
- `0x004A2220` **PitCrewAnimationStruct** — Init/reinit-cleanup hybrid for the pit crew animation struct: reset word/byte state fields, init this+0x44..0x60 region, release 3D sound source (this+0x64), buffer (this+0x6C) and 28-byte-element array (this+0x74, count at base-4); returns the freed array pointer.
- `0x004A4900` **PitCrewAnimationManager** — Loads pit crew animation MAS files: gate on dword_8AB6E4 != 2 and (target is player vehicle or detail level dword_7CF884 >= 3), builds directory-relative MAS paths, allocates/loads 10sec, normal and player-only pit-director animation objects into this[4]/this[3]/this[5], frees temporaries, returns comparison of argument struct.
- `0x004A7000` **SettingsFileManager** — Trivial wrapper: one-time static initialization of autoload config block byte_7CE498 via StaticInitBulk; returns its result.
- `0x004B03F0` **SettingsFileManager** — Player profile-file bootstrap: iterates settings directory (dword_5EC440 or byte_5EA438), copies an existing profile via StringCopyFileCheckDispatch, else reads the default 'PlayerNameNever...' text file and recurses to create the default profile, setting this+0x49A8/0x49A9 flags.
- `0x004B0770` **SettingsFileManager** — Persists settings file: builds '.tmp' name (extension stripped from byte_5EA438), clears read-only (attr 128) on temp+destination, logs attempt, enumerates dir + vtable dispatch, closes handle, SettingsFileInit + ConfigFileParser into dword_7C73E8, deletes old destination, renames temp over it, logs result; returns 0.
- `0x004B09A0` **SettingsFileManager** — Reads text file and sets up environment: resolves path into receiver buffer, creates every directory level, selects wet/dry environment from byte_7CB710 bit 0, loads AIW scene (dword_8AC488) and vehicle data (dword_8AC390), registers cleanup strings, copies save file, selects track environment, cleans device list, reads settings; returns 0.
- `0x004B0B20` **SettingsFileManager** — Extracts player/.plr filename: module-manager string (NullTerminatedStringLengthAt0x11c(dword_7CD25C)) or object name trimmed after last backslash and at '.plr' suffix; copies with length limit a3-1.
- `0x004B0EF0` **SessionConfigObject** — Activates one of six session config slots: copies per-slot values into active fields, clamps against stored min/max (ClampByRange / ByteClamp / FloatClamp / inline), presets control field this+0x1C54 to 1 or 7 for slots 1/2, applies via sub_4B1190(-1.0); returns 1, or 0 out of range.
- `0x004B1410` **SettingsFileManager** — Compares input name to stored name this+0x1F9C; on match builds season-dir + name path, object-ID lookup, audio load/decode, settings init, buffer copy, 5-step session init; returns 1 on success else 0.
- `0x004B15D0` **SessionConfigObject** — State-gated bitmask test: returns true when state this+0x1F78 != 5, otherwise whether bit (1<<a2) is set in bitmask this+0x2AB4; per-frame predicate for AIShiftPattern / BrakeBiasSetup.
- `0x004B33B0` **GenericRuntimeObject** — Packs progress-bar/session event parameters into a bitfield word from dword_7C56A4 base index (a5 + ((a4 + ((a3 + (base << 6)) << 10)) << 8)), stores it at this+0, secondary payload a6 at this+4, resets flag this+0x1AC to -1; returns packed word.
- `0x004B40A0` **GenericRuntimeObject** — Per-frame screenshot handler: scans input keycode array word_7CB21C (dword_7CB218 entries) for key 88 ('X'), saves screen via sub_551FD0 to season dir dword_5EC478 (fallback byte_5EA438), localizes+renders 'Screen Saved', runs camera viewport setup + vehicle visibility culling; returns sub_557120(dword_8AFE88).
- `0x004B4470` **GenericRuntimeObject** — Resource-handle registration helper: stores ResourceLookupDispatcher(a2) at this+0x4, dispatches 4-byte header (this) and 2-byte sub-field (this+2) via ConditionalDispatch_6bd0; returns 1.

## Proposed classes

### PitCrewAnimationStruct

Pit crew animation object container initialized and cleaned by 0x004A2220: a 3D sound source, a raw buffer, and a counted array of 28-byte animation elements, plus word/byte state flags and a position/vector region.

Methods: `0x004A2220`

- `this+0x00000000` `int stateWord` (write, DERIVED)
- `this+0x00000002` `byte enabledFlag` (write, DERIVED)
- `this+0x00000003` `byte flagByte_03` (write, DERIVED)
- `this+0x00000004` `byte flagByte_04` (write, DERIVED)
- `this+0x00000044` `float vectorComponent_44` (write, DERIVED)
- `this+0x00000048` `int handleIndex_48` (write, DERIVED)
- `this+0x0000004C` `int regionDword_4C` (write, DERIVED)
- `this+0x00000050` `int regionDword_50` (write, DERIVED)
- `this+0x00000054` `int regionDword_54` (write, DERIVED)
- `this+0x00000058` `int regionDword_58` (write, DERIVED)
- `this+0x0000005C` `int regionDword_5C` (write, DERIVED)
- `this+0x00000060` `int regionDword_60` (write, DERIVED)
- `this+0x00000064` `pointer soundSourcePtr` (read_write, DERIVED)
- `this+0x00000068` `pointer soundPtr_68` (write, DERIVED)
- `this+0x0000006C` `pointer bufferPtr` (read_write, DERIVED)
- `this+0x00000070` `pointer bufferPtr_70` (write, DERIVED)
- `this+0x00000074` `pointer animationArrayPtr` (read_write, DERIVED)

### PitCrewAnimationManager

GUESS loader/owner of the per-vehicle pit crew animation set: loads and stores the 10sec, normal and (player-only) pit-director animation objects into embedded slots this[3]/this[4]/this[5], gated by player/detail-level conditions.

Methods: `0x004A4900`

- `this+0x00000000` `pointer targetVehiclePtr` (read, GUESS)
- `this+0x0000000C` `pointer normalAnimationPtr` (write, GUESS)
- `this+0x00000010` `pointer tenSecondAnimationPtr` (write, GUESS)
- `this+0x00000014` `pointer pitDirectorAnimationPtr` (write, GUESS)
- `obj+0x00004894` `int carNumber` (read, GUESS)

### SessionLifecycleManager

GUESS grouping of session lifecycle helpers whose packet owners are UNKNOWN: scene video load, race-finish handling, session-state UI dispatch, session-type-gated command dispatch, and the restart/main-menu gate. All five manipulate the shared session-state globals (dword_7CD8C0 dispatch interface, dword_7C569C session type, dword_7CE25x restart flags).

Methods: `0x004A09F0`, `0x004A0BA0`, `0x004A0DF0`, `0x004A0E70`, `0x004A0FD0`


### SettingsFileManager

GUESS grouping of settings-file and player-profile helpers: autoload config init, profile-file bootstrap, settings write-with-backup, environment/file setup, player-name extraction, and name-compare-and-format. All manipulate the default-directory global byte_5EA438 and settings/season directory globals.

Methods: `0x004A7000`, `0x004B03F0`, `0x004B0770`, `0x004B09A0`, `0x004B0B20`, `0x004B1410`

- `this+0x000001B4` `pointer pathStringPtr` (read, GUESS)
- `this+0x00001F9C` `pointer storedNamePtr` (read, GUESS)
- `this+0x000049A8` `byte profileCreatedFlag` (write, GUESS)
- `this+0x000049A9` `byte profileFlag_49A9` (write, GUESS)

### SessionConfigObject

GUESS session configuration object holding six stored configuration slots plus active/current fields: slot activation copies per-slot values into active fields and clamps them against stored per-group min/max bounds (0x004B0EF0), and a state-gated bitmask predicate reads the same slot-index/state field (0x004B15D0).

Methods: `0x004B0EF0`, `0x004B15D0`

- `this+0x00001F78` `int slotIndexOrState` (read_write, GUESS)
- `this+0x00001F80` `int slotBound_1F80` (read, GUESS)
- `this+0x00001F84` `int slotBound_1F84` (read, GUESS)
- `this+0x000005C4` `int activeParam_5C4` (read_write, GUESS)
- `this+0x000005CC` `int paramBound_5CC` (read, GUESS)
- `this+0x000005D0` `int paramBound_5D0` (read, GUESS)
- `this+0x000007F8` `int activeParam_7F8` (read_write, GUESS)
- `this+0x00000800` `int paramBound_800` (read, GUESS)
- `this+0x00000804` `int paramBound_804` (read, GUESS)
- `this+0x000008F4` `int activeParam_8F4` (read_write, GUESS)
- `this+0x000008FC` `int paramBound_8FC` (read, GUESS)
- `this+0x00000900` `int paramBound_900` (read, GUESS)
- `this+0x000009F0` `int activeParam_9F0` (read_write, GUESS)
- `this+0x000009F8` `int paramBound_9F8` (read, GUESS)
- `this+0x000009FC` `int paramBound_9FC` (read, GUESS)
- `this+0x00000AEC` `int activeParam_AEC` (read_write, GUESS)
- `this+0x00000AF4` `int paramBound_AF4` (read, GUESS)
- `this+0x00000AF8` `int paramBound_AF8` (read, GUESS)
- `this+0x00000BE8` `int activeParam_BE8` (read_write, GUESS)
- `this+0x00000BF0` `int paramBound_BF0` (read, GUESS)
- `this+0x00000BF4` `int paramBound_BF4` (read, GUESS)
- `this+0x00000CE4` `byte byteParam_CE4` (read_write, GUESS)
- `this+0x00000CE6` `byte byteBound_CE6` (read, GUESS)
- `this+0x00000CE7` `byte byteBound_CE7` (read, GUESS)
- `this+0x00001C54` `int controlParam` (write, GUESS)
- `this+0x00001C5C` `int controlBound_1C5C` (read, GUESS)
- `this+0x00001C60` `int controlBound_1C60` (read, GUESS)
- `this+0x0000200C` `int activeParam_200C` (read_write, GUESS)
- `this+0x00002014` `int paramBound_2014` (read, GUESS)
- `this+0x00002018` `int paramBound_2018` (read, GUESS)
- `this+0x00002108` `int activeParam_2108` (read_write, GUESS)
- `this+0x00002110` `int paramBound_2110` (read, GUESS)
- `this+0x00002114` `int paramBound_2114` (read, GUESS)
- `this+0x00002204` `int activeParam_2204` (read_write, GUESS)
- `this+0x0000220C` `int paramBound_220C` (read, GUESS)
- `this+0x00002210` `int paramBound_2210` (read, GUESS)
- `this+0x00002300` `float floatParam_2300` (read_write, GUESS)
- `this+0x00002308` `float floatBound_2308` (read, GUESS)
- `this+0x0000230C` `float floatBound_230C` (read, GUESS)
- `this+0x000023FC` `float inlineParam_23FC` (read_write, GUESS)
- `this+0x00002404` `float inlineBound_2404` (read, GUESS)
- `this+0x00002408` `float inlineBound_2408` (read, GUESS)
- `this+0x000024F8` `int activeParam_24F8` (read_write, GUESS)
- `this+0x00002500` `int paramBound_2500` (read, GUESS)
- `this+0x00002504` `int paramBound_2504` (read, GUESS)
- `this+0x000026CC` `int activeParam_26CC` (read_write, GUESS)
- `this+0x000026D4` `int paramBound_26D4` (read, GUESS)
- `this+0x000026D8` `int paramBound_26D8` (read, GUESS)
- `this+0x000027C8` `float inlineParam_27C8` (read_write, GUESS)
- `this+0x000027D0` `float inlineBound_27D0` (read, GUESS)
- `this+0x000027D4` `float inlineBound_27D4` (read, GUESS)
- `this+0x00002AB4` `int bitmask` (read, GUESS)

### ConfigTokenScanner

GUESS scanner object that walks settings-file token streams through a resource lookup handle, strips separators, compares tokens against a reference path (this+0x4), and invokes a virtual callback on match; the same receiver runs the three-lookup dual-path file teardown.

Methods: `0x004A1B90`, `0x004A1F10`

- `this+0x00000000` `pointer vtablePtr` (read, GUESS)
- `this+0x00000004` `pointer customPathPtr` (read_write, GUESS)
- `obj+0x00000004` `pointer linkedListNodePtr` (read, GUESS)

### GenericRuntimeObject

GUESS catch-all for the remaining single-method runtime helpers with UNKNOWN owners: progress-bar/session event bitfield encoding, the per-frame screenshot handler, and resource-handle registration. Each operates on its own small this-layout; kept separate from the other classes because their fields have no shared ownership evidence.

Methods: `0x004B33B0`, `0x004B40A0`, `0x004B4470`

- `this+0x00000000` `int packedEventWord` (write, GUESS)
- `this+0x00000004` `int eventDataWord` (write, GUESS)
- `this+0x000001AC` `int eventFlag` (write, GUESS)
- `this+0x00000000` `int fileHeaderWord` (write, GUESS)
- `this+0x00000002` `word fileSubFieldWord` (write, GUESS)
- `this+0x00000004` `pointer resourceHandlePtr` (write, GUESS)

## Compatibility contracts

- **BinkVideoSceneLoad** — BinkVideoLoader (0x004A09F0) runs only when the scene entry at dword_8AC490 + 396*dword_8AC48C is non-null and dword_7D032C == 1; the .bik path is built as base (dword_5EC418, or byte_5EA438 when null) + the scene directory component + '.bik' ('%s%s%s' via 0x0058815F) and loaded through FileLoadWithRetryLoop (0x004F9B70). A replacement must preserve the 396-byte scene stride, the format, and the backslash directory-extraction rule.
- **SessionConfigSlotLayout** — SessionConfigSlotActivate (0x004B0EF0) manages six configuration slots (a2 in 1..6): per-slot values live at 36-byte stride with a 24-byte byte group (0xCE4) and a 4*(9*a2+369) group (0x5C4); every active field is copied then clamped against its stored min/max via ClampByRange (0x0047F1F0), ByteClamp (0x00464720) or FloatClamp (0x004646C0), with two inline clamps (0x23FC, 0x27C8); slots 1/2 preset the control field this+0x1C54 to 1/7. A replacement must preserve slot strides, the active-field anchors and the clamp semantics.
- **SettingsFileSwapWrite** — SettingsFileWriteWithBackup (0x004B0770) writes a '.tmp' sibling (extension stripped from byte_5EA438, 'tmp' appended), clears the read-only attribute (value 128) on both temp and destination, enumerates the directory and dispatches vtable callbacks, then runs SettingsFileInit + ConfigFileParser into dword_7C73E8, deletes the old destination and renames the temp over it. A replacement must reproduce the temp-then-rename swap and attribute handling.
- **ProfileFileBootstrap** — PlayerNameNeverUsedProfileFileCreateRead (0x004B03F0) scans the settings directory (dword_5EC440, or byte_5EA438 when null) for an existing profile entry; on a hit it formats base+entry and copies the file via StringCopyFileCheckDispatch (0x004B04E0), on a miss it reads the default 'PlayerNameNever...' text file (0x004B09A0) and recurses (0x004B03F0) to create the default profile, setting this+0x49A8/0x49A9. The directory iterator is torn down before the result is returned.
- **PitCrewAnimationArrayLayout** — PitCrewAnimStructInitAndCleanup (0x004A2220) owns a counted array at this+0x74 whose element count is stored in the dword at allocation_base-4, with 28-byte elements destructed via ShortComputation_d4d0 (0x004DD4D0) and freed via FreeWrapper_7bcf (0x00587BCF); a 3D sound source lives at this+0x64 (destroyed via F_3DSoundSourceDestructor 0x00545150 when the subsystem-liveness guard dword_8AFE88 is set) and a buffer at this+0x6C. A replacement must preserve the count-at-base-minus-4 header and 28-byte element stride.
- **RestartRequestReturnValues** — RestartGate (0x004A0FD0) exposes a fixed request encoding to GamePostMainLoop: 4 = mini-restart (vehicle cleanup pass over dword_5C329C active vehicles dword_7C54F0 via FieldCopy_c330, then return), 6 = full restart (returned when byte_7CE25E or byte_7CE260 is set, when dword_7CE258 is 1 under the dword_7CE264==1 gate, or when sub_485B90 yields -1 or 3), otherwise the effective session type dword_7C569C. A replacement must preserve these return codes and the cleanup iteration.
- **RaceFinishFlow** — RaceFinishHandler (0x004A0BA0) triggers per-driver race commentary (0x00419C50), then advances the action state machine to post-race state 5 (0x0040CDE0) and the session state to 1 (0x004EF5A0) unless the driver already finished or the qualifying-DSQ switch dword_7CE814 is set; on player finish it conditionally switches to menu mode and finally dispatches in-race event 19 (0x004D8760). A replacement must preserve the guard ordering.
- **ScreenshotKeyAndSavePath** — RenderScreenSave (0x004B40A0) triggers on input keycode 88 ('X') in the action-key array word_7CB21C (dword_7CB218 entries), saves the screen via sub_551FD0 with screen dimensions dword_8B8DD4/dword_8B8DD8 into directory dword_5EC478 (or byte_5EA438), localizes 'Screen Saved' (aScreenSaved 0x005D240C) via the string table (byte_5EC4C0) into byte_5EC4CC and renders it through the text render target dword_7CD204 (0x0045BD10), then always runs camera viewport setup (0x004FBD70 on unk_8AFFC8) and vehicle visibility culling (0x004B3DC0), returning sub_557120(dword_8AFE88).
- **ProgressBarEventBitfieldEncoding** — ProgressBarEventEncode (0x004B33B0) packs event parameters into a single bitfield word: result = a5 + ((a4 + ((a3 + ((dword_7C56A4 + 8*(a7 + 4*a2)) << 6)) << 10)) << 8), stores it at this+0, a secondary payload at this+4, and resets this+0x1AC to -1. A replacement must preserve the shift/accumulate order for identical UI event encoding.
- **ConfigTokenStreamFormat** — ScanSettingsTokensForPathMatch (0x004A1B90) reads a settings-file token stream through the resource-lookup handle (0x00566E20 / line reader 0x00566CC0), checks leading bytes against the delimiter unk_5C30B8 (via sub_596C80), and truncates on substring tokens word_5C30B4 / asc_5C30B0 (via sub_587C20); the teardown path reuses the same global path token (0x00566CF0) in FileStreamCleanup (0x004A1F10). A replacement must preserve the token/separator globals and the strip-compare callback protocol.
- **PitCrewAnimationMASPathBuild** — PitCrewAnimationLoadSetup (0x004A4900) builds directory-relative MAS paths from byte_5EA438 with per-track subdirectories (0x0053CBC0 assembles the MAS names; StringRegistry 0x0053C800 registers the directory; 0x00587C03/0x00566650/0x005665B0 copy and join path components), using the MAS-suffix string globals (aTeamMas 0x005CD5D8, aPitsMas 0x005CD5CC, aCdbMas 0x005CD5C4, aCmapsMas 0x005CCEB0, aPits10secPitcr 0x005CD5AC, aPitcrew10sec02 0x005CD598, aPitcrewnormal0 0x005CD554, aPitsNormalPitc 0x005CD568 / aPitsLeftPitcre 0x005CD580 selected by byte_5EA3EC, aPitdirector0 0x005CD544, aPits 0x005CD5E4) and season-directory globals dword_5EC3D8 / dword_5EC420 / dword_5EC428. The load runs only when the scoring gate dword_8AB6E4 is not 2 and either the target is the player vehicle (dword_7C54E8) or the detail level dword_7CF884 is >= 3. A replacement must keep the MAS file-name formats, the byte_5EA3EC left/normal selection, and the load gate.
- **NameCompareAndFormatFlow** — NameCompareAndFormat (0x004B1410) compares the input name to the stored name this+0x1F9C (via 0x00588410); on match it formats the season-directory + name path ('%s%s' format global aSS 0x005BE860, season dir dword_5EC3D8), performs an object-ID lookup (0x005684A0), loads/decodes the audio file (0x00567F40), re-runs settings-file init (0x004B0930), copies the buffer, and runs the 5-step session init (0x004B0720). A replacement must keep the path-format and lookup ordering.
- **SettingsEnvironmentBootstrap** — ReadTextFileAndSetupEnvironment (0x004B09A0) creates every directory level of the resolved path (CreateDirectoryAWrapper 0x00589671, prefix builder 0x00587DD0), selects the wet/dry environment from byte_7CB710 bit 0 (via sub_4AE750), loads the AIW scene when dword_8AC488 is non-zero (AIW 0x004C54F0) and vehicle data when dword_8AC390 is non-zero (CurrentVehicleAccessor 0x004C4080 on unk_8AC388), registers the receiver's 0x1B4 path string for cleanup (0x00415730 on dword_5EA5E8), then copies the save file, selects the track environment, cleans the device list (dword_7C73E8) and reads settings.
- **DebugLogSink** — SettingsFileWriteWithBackup (0x004B0770) writes debug messages to the debug-log buffer dword_8AD25C via DebugLogWrite (0x004D7AA0) gated by StringSplitLoop (0x004D7A50) with the source-file string globals aDDevF119992002_20 (0x005D22E0) and the message strings aAttemptingToSa (0x005D22C4) / aRetcodeDForRen (0x005D1FF4). A replacement must preserve the debug-sink global and the format-argument source-file identity for matching diagnostics.
- **AutoloadConfigBlock** — AutoLoadConfigFileInit (0x004A7000) performs a one-time static initialization of the autoload configuration block byte_7CE498 via StaticInitBulk and returns its result; the same block is passed to PlayerFile_Restart in the game restart path. A replacement must keep the byte_7CE498 block and the single-shot init semantics.

## Unresolved

- BinkVideoLoader (0x004A09F0): aBik_0 (0x005CD02C) and aSSS_0 (0x005C6784) are the '.bik' suffix and '%s%s%s' format per the fills (DERIVED); strlen is an implicit CRT call; literals 396/4/92 are source-only; the dword_7D032C==1 and scene-index semantics of dword_8AC48C are DERIVED.
- BinkVideoLoader: unk_8AFE18 (0x008AFE18) is listed in the packet globals but has no raw-source access; its fill role (GameRacePhaseTimer) is not evidenced here.
- RaceFinishHandler (0x004A0BA0): globals flt_59F118, dword_5EB978, dword_7C54E8 and dword_8ACEE0 are listed but unused in the raw source; driver-relative indexing (a2[3250], a2[4120]) and vehicle indices (4121, 4142) refer to caller record layouts not resolved here; the session-mode gate 19 meaning is not derivable.
- SessionStateDispatch (0x004A0DF0): the vtable method offset 28 and what arguments 36/35 select are unidentified; field v2[37] of the dispatched UI object is unnamed; literal 1065353216 is preserved verbatim; byte_8AC494 is flagged as read but never appears in the raw body.
- SessionTypeGuard (0x004A0E70): parameter a1 is unused; the meanings of session-type values 2 and 6 and the exact role of byte_7CE254 are not grounded; sub_4989E0's message/command format is unknown.
- RestartGate (0x004A0FD0): the 16436-byte vehicle stride and FieldCopy_c330's copy semantics are not established; globals flt_59E440, unk_5EC6D0 and unk_7CE24C are listed but do not appear in the raw source.
- ScanSettingsTokensForPathMatch (0x004A1B90): field obj+0x4 is the caller's linked-list node pointer whose role inside the scanner is not evidenced; the success path latches the return flag even when the callback fails or the match count is not exactly one (ambiguous intended semantics).
- FileStreamCleanup (0x004A1F10): what word_5C30B4 and byte_5EA438 point to is not established; a2 is unused; no static caller is recorded so the cleanup/teardown role is inferred from the canonical name; the return 1 is constant and both lookup results are discarded.
- PitCrewAnimStructInitAndCleanup (0x004A2220): purpose of the 3D sound source and freed buffer is not established; dword_8AFE88's subsystem-liveness role is inferred from guard shape; the 28-byte element layout is unknown.
- PitCrewAnimationLoadSetup (0x004A4900): dword_8AFE64 is referenced per the IDB but absent from the decompiled text; sub_4A1F60 / sub_4A51C0 / ArithmeticComparison_1f80 semantics are unresolved; owner class is UNKNOWN (name DERIVED from existing analysis).
- AutoLoadConfigFileInit (0x004A7000): StaticInitBulk has no callee evidence (address unknown); byte_7CE498 ownership/layout is unknown and it is also passed to PlayerFile_Restart (0x0042D7A0).
- PlayerNameNeverUsedProfileFileCreateRead (0x004B03F0): sub_565F80 and sub_566380(2) semantics unknown (the constant 2 uninterpreted); StringCopyFileCheckDispatch return meaning unconfirmed; the v8 directory-iterator layout unknown; off_5D1FF0/aPlr format components and the aSS ('%s%s') relation not established; flag bytes 0x49A8/0x49A9 meaning beyond 'set on default creation' unknown; recursion termination unverified.
- SettingsFileWriteWithBackup (0x004B0770): attribute value 128 and the sub_5665B0 / sub_566940 semantics are not established; FreeWrapper_7bcf is in the callee list but not called in the raw body.
- ReadTextFileAndSetupEnvironment (0x004B09A0): unk_8AC368 (0x008AC368) is listed but absent from the raw source; sub_4B0180/sub_4B01B0, sub_568620, sub_587DD0, AIW, CurrentVehicleAccessor, sub_4ADD50 and ShortComputation_5730 semantics are unestablished; the wet=2/dry=1 mapping is drawn from existing analysis, not named in the source.
- PlayerNameOrModulePathExtractor (0x004B0B20): the self-referential copy loop is DERIVED as copying the object name into a local buffer; the byte 92 (backslash) identity is an observation; the exact type copied in the v4-non-zero branch is not fully resolvable.
- SessionConfigSlotActivate (0x004B0EF0): the meaning of each copied group (engine, gear, tyre, aero, etc.) is not determinable from this function alone; the inline clamps at 0x27C8/0x23FC mirror ClampByRange semantics but have no helper call; the divergent slot strides (36-byte, 24-byte, 4*(9*a2+369)) are evidence-only.
- NameCompareAndFormat (0x004B1410): dword_8AD3B4 is in the globals table (R) but absent from the raw body (fill role GameDataDir, DERIVED); aSS (0x005BE860) is the path format per the fill; memset is implicit; literals 255/0xFC and index 2023 are source/field-table only.
- BitmaskStateTest (0x004B15D0): meaning of state value 5 and of the bitmask at this+0x2AB4 is caller/object specific; the bit-index role of a2 depends on the calling AIShiftPattern / BrakeBiasSetup context.
- ProgressBarEventEncode (0x004B33B0): the exact bit positions of a2/a3/a4/a5/a7 within the packed word and the meaning of the dword_7C56A4 index are not derivable; this+0x1AC's reader-side semantics are outside this function.
- RenderScreenSave (0x004B40A0): sub_557120 (called with dword_8AFE88 and returned) is not in the packet callee list so its address cannot be recorded; the literal 16909060 and the keycode-88-to-'X' mapping are ASCII-inferred; dword_8B8DC8 is listed but absent from the raw source.
- FileHandleCloseRegistration (0x004B4470): the meanings of the dispatched 4-byte header and 2-byte sub-field are unknown; a2 is used only as a lookup key with unknown type.
- Cross-cutting: most packet owners are UNKNOWN, so all class groupings except PitCrewAnimationStruct are GUESS; equal offsets on different this bases (notably this+0x0 and this+0x4 across PitCrewAnimationManager, ConfigTokenScanner and GenericRuntimeObject) are kept separate because the packet does not prove common ownership.
- Cross-cutting: the dispatch interface dword_7CD8C0 and session-state globals dword_7CD25C/dword_7C569C are shared across SessionLifecycleManager methods (ISessionDispatch / ISessionState), but the vtable offset-28 method identity and the argument encoding are not proven.
- Cross-cutting: several globals are flagged read by the IDB but never appear in any raw body (flt_59E440, unk_5EC6D0, unk_7CE24C, unk_8AFE18, unk_8AC368, dword_8AD3B4, dword_8B8DC8, dword_8AFE64, dword_8ACEE0, dword_5EB978, dword_59F118); treated as unresolved evidence, not semantics.
