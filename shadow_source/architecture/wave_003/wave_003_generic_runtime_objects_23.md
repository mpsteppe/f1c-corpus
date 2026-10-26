# RuntimeObjectAndAudioLayer

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED architecture proposal for 21 runtime-object functions. Cluster 1 - driver record (F1CVehicle): SetDriverName (0x004C6980) bounded-copies into this+0x4620 and derives the abbreviation via 0x004C6A10, which resolves an 'Abbreviation' data entry through the string-keyed list and emits a formatted abbreviation NUL-terminated at this+0x4707; NationalityDriverInfoLoader (0x004C78F0) fills the driver-region buffers from the 1060-byte-stride nationality array at dword_8AC394; SetDriverVisibility (0x004C7AA0) toggles bits at this+0x48BC and plays matching engine sounds. Cluster 2 - telemetry (0x004C71C0): a fixed encoder pipeline packs vehicle physics fields into a bitfield packet closed by 0x004B2AE0. Cluster 3 - filter-properties list (0x004C6150): prunes nodes whose built filter name matches any criterion. Cluster 4 - camera tick dispatch (0x004C7DE0): timer + list iteration with a vtable slot-40 dispatch on dword_8AC4C4. Cluster 5 - audio playlist manager (0x004C83B0/0x004C84A0/0x004C8650): teardown/rebuild/scan/playback over a head/tail/cursor/count list. Cluster 6 - scene manager (0x004C8920) and sound-subsystem lifecycle/dispatch helpers (0x004C82C0, 0x004C8AB0..0x004C8D70). Cluster 7 - SpecialFX reset (0x004CA280). No CONFIRMED claim is made about original source names or layout.

## Function roles

- `0x004C6150` **FilterPropertiesList** — Remove nodes from a filter-properties linked list whose built filter name matches any of the given criteria strings; unlink, optionally free node data, return the remaining count.
- `0x004C6980` **F1CVehicle** — Set the driver full name: bounded copy into the 64-byte name buffer at this+0x4620, force NUL at this+0x465F, derive and return the abbreviated name via DriverAbbreviationNameFormatter.
- `0x004C69E0` **FilenamePathHelper** — Extract the filename component of an embedded C-string path at a1+0x4714 by scanning backwards for the last backslash (0x5C); return the character after it.
- `0x004C6A10` **F1CVehicle** — Derive an abbreviated driver display name from the full-name field; primary path looks up the 'Abbreviation' data section, fallback path uses an initial-dot '%c. %-.11s' form; store at this+0x46F8 with NUL at this+0x4707.
- `0x004C71C0` **VehicleTelemetryPacketEncoder** — Encode a per-vehicle telemetry packet into buffer a2: header marker via ProgressBarEventEncode, then a fixed sequence of bitfield/short/fixed-point encoders for position, speed, wheels, RPM, throttle, gear, clutch, subsystem-ready bits and packed flag word; close via 0x004B2AE0.
- `0x004C78F0` **F1CVehicle** — Load nationality/career driver info for driver a2 from the nationality array (stride 1060): set full name, fill nationality/short/long description buffers, set abbreviation code, copy flag path to this+0x4714, store driver index at this+0x4898.
- `0x004C7AA0` **F1CVehicle** — Set driver visibility bits (1 and 2) at this+0x48BC and play/stop the matching engine sound via AudioSoundEffectController, gating the own-vehicle sound on the session state.
- `0x004C7DE0` **CameraTickAndDispatchList** — Render-tick routine: decrement a timer at this+0x4 by dbl_8AFE98 and on expiry call UpdateCameraFOV(0.4); when dword_8AC4C4 is set issue an indirect vtable call (slot 40), then iterate a linked list at this+0xC calling 0x004C8FC0 per node.
- `0x004C82C0` **SoundSubsystem** — One-shot init helper: unconditional side-effect call, delegate with literal 1 to 0x004C7C10, store the status into global dword_8AC4C4, report success as status == 0.
- `0x004C83B0` **AudioPlaylistManager** — Reinitialise the audio scene: destroy the playlist list (free node data when the alive flag at obj+0x8 is set), clear list state, rebuild .wav and .mp3 playlists via 0x004C84A0, random-start the cursor, and on empty playlist dispatch a scene-index load through the dword_8AC4C4 vtable+72.
- `0x004C84A0` **AudioPlaylistManager** — Scan a directory for files matching an extension filter and append each hit to the caller list as a node {0,-1} plus an entry {node,0,1}; iterate via DirectoryEntryIterator, tear down the iterator on exit.
- `0x004C8650` **AudioPlaylistManager** — Per-frame audio playback manager: ramp the active stream volume (fade-in state 1 clamped at flt_7CF380, else fade-out clamped at 0.0, resetting fade state at this+0x14), or when the mixer is not playing select the next track from the playlist cursor or the scene-indexed table dword_5ACDEC[dword_8AC4C0], submit it through the mixer vtable+4 and refresh.
- `0x004C8920` **AudioSceneManager** — One-shot audio-scene path and DSP setup invoked from the render tick: when the scene manager dword_8AC4CC reports inactive, submit a '<path base>PitPitsoundsMp' buffer via vtable+4 and apply DSP wetness via vtable+28.
- `0x004C8AB0` **SoundSubsystem** — Sound-setup entry point: parse a config token via StringSplitLoop(2, aDDevF119992002_24, 683) and write 'Entered sound setup' through DebugLogWrite when the low byte is non-zero.
- `0x004C8AE0` **SoundSubsystem** — Sound-init step: parse a config token via StringSplitLoop(2, ..., 688), log 'Entered sound init' on success, then dispatch a network message referencing the scene-camera parameter flt_8AC4B0. Called from Game_Init.
- `0x004C8B20` **SoundSubsystem** — Sound-restart routine: conditional 'entered sound restart' log, reset virtual dispatch state via 0x004C8630, zero flt_8AC4B0, then reinitialise the audio buffer from flt_5EA618.
- `0x004C8CA0` **SoundSubsystem** — Post-cleanup for the sound system called from Game_Post: optional debug log, guarded virtual dispatch on the init-status global, clear flt_8AC4B0, reset one global-object slot and up to 20 stride-8 table entries in the (0,291) validity window.
- `0x004C8D00` **SoundSubsystem** — Sound-system exit routine called from GameExit: optional 'entered sound exit' log, two global vtable dispatches (query 1 and 0), short computation on flt_5EA618, reset virtual dispatch state, return a final arithmetic helper result.
- `0x004C8D60` **SoundSubsystem** — Thin dispatch helper: when dword_8AC4C4 is non-null, call the method at vtable offset 20 as a __thiscall and return its result.
- `0x004C8D70` **SoundSubsystem** — Thin dispatch helper: when dword_8AC4C4 is non-null, call the method at vtable offset 24 as a __thiscall and return its result.
- `0x004CA280` **SpecialFXState** — Reset/cleanup of a 15-dword object: zero all dwords this[0..0x38], free the owned pointer at this+0x38 via FreeWrapper_7bcf, return the saved pointer value.

## Proposed classes

### FilterPropertiesList

Filter-properties linked list with head at this+0x8, tail at this+0xC, current-cursor at this+0x10 and count at this+0x14. Nodes carry a scene index at +0x0, a cleanup flag byte at +0x8 and a next pointer; FilterPropertiesListNodeRemover prunes nodes whose built filter name matches a criterion.

Methods: `0x004C6150`

- `this+0x00000008` `FilterPropertyNode* head` (read_write, DERIVED)
- `this+0x0000000C` `FilterPropertyNode* tail` (read_write, DERIVED)
- `this+0x00000010` `FilterPropertyNode* current` (read_write, DERIVED)
- `this+0x00000014` `int count` (read_write, DERIVED)

### F1CVehicle

Vehicle/driver record. Driver-region fields: full name buffer (64 bytes starting this+0x4620, NUL forced at +0x465F), 23-byte nationality buffer (NUL at +0x4677), short/long description buffers (NUL at +0x46B7 / +0x46F7), abbreviation output buffer (NUL at +0x4707), state dword at +0x4894, driver index at +0x4898, and visibility flag word at +0x48BC. The packet explicitly tags only NationalityDriverInfoLoader (0x004C78F0) as F1CVehicle; the other driver-region methods are aggregated here on shared field evidence.

Methods: `0x004C6980`, `0x004C6A10`, `0x004C78F0`, `0x004C7AA0`

- `this+0x0000465F` `char driverFullNameTerminator` (write, DERIVED)
- `this+0x00004677` `char nationalityTerminator` (write, DERIVED)
- `this+0x000046B7` `char shortDescriptionTerminator` (write, DERIVED)
- `this+0x000046F7` `char longDescriptionTerminator` (write, DERIVED)
- `this+0x00004707` `char abbreviationOutputTerminator` (write, DERIVED)
- `this+0x00004894` `int stateDword` (read, DERIVED)
- `this+0x00004898` `int driverIndex` (write, DERIVED)
- `this+0x000048BC` `int visibilityFlags` (read_write, DERIVED)

### VehicleTelemetryPacketEncoder

Per-vehicle telemetry packet encoder (__thiscall on the vehicle struct, output buffer a2). Reads vehicle physics/state fields (position, wheel suspension, RPM, throttle, clutch, gear, brake factor, steering and per-index flag bytes) and packs them into a bitfield DWORD array via a fixed sequence of packing subroutines. The packet marks its owner UNKNOWN; grouping is DERIVED from the shared this+0x4894 state dword and the player-vehicle globals.

Methods: `0x004C71C0`

- `this+0x0000073C` `float bodyOffsetFloat` (read, DERIVED)
- `this+0x0000105D` `byte driverModelVisibleFlag` (read, DERIVED)
- `this+0x00001067` `byte flagByte1067` (read, DERIVED)
- `this+0x00001069` `byte flagByte1069` (read, DERIVED)
- `this+0x0000344C` `byte flagByte344C` (read, DERIVED)
- `this+0x0000357C` `float throttleFactor` (read, DERIVED)
- `this+0x00003580` `float clutchEngagement` (read, DERIVED)
- `this+0x00003584` `float brakeFactor` (read, DERIVED)
- `this+0x000035BC` `float[4] wheelStateArray` (read, DERIVED)
- `this+0x000039A0` `float engineRpm` (read, DERIVED)
- `this+0x000039FC` `int currentGear` (read, DERIVED)
- `this+0x00004024` `byte flagByte4024` (read, DERIVED)
- `this+0x00004028` `float steering` (read, DERIVED)

### FilenamePathHelper

Free helper: returns the filename component of an embedded C-string path buffer at a1+0x4714 by scanning back to the last backslash. Owning object type is not established by the packet.

Methods: `0x004C69E0`


### CameraTickAndDispatchList

Render-tick object holding a timer float at this+0x4 and a linked-list handle at this+0xC whose +0x8 slot is the cursor. On timer expiry it resets the camera FOV and, when the global dword_8AC4C4 is set, dispatches vtable slot 40 and iterates list nodes calling 0x004C8FC0 per node.

Methods: `0x004C7DE0`

- `this+0x00000004` `float timer` (read_write, DERIVED)
- `this+0x0000000C` `void** dispatchList` (read, DERIVED)
- `*(this+0xC)+0x00000000` `void* listHeadNode` (read, DERIVED)
- `*(this+0xC)+0x00000008` `void* listCursor` (read_write, DERIVED)
- `*(*(this+0xC)+0x0)+0x00000000` `void* headNodeFirstField` (read, GUESS)
- `*(*(this+0xC)+0x8)+0x00000000` `void* cursorNodeValue` (read, GUESS)
- `*(*(this+0xC)+0x8)+0x00000004` `void* cursorNodeNext` (read, GUESS)

### AudioPlaylistManager

Audio playlist state: head at this+0x0, tail at this+0x4, cursor at this+0x8, count at this+0xC, active flag at this+0x10, fade state at this+0x14 and fade speed at this+0x18. Rebuilt by ScanDirectoryIntoPlaylist, destroyed by AudioSceneReinit, and consumed by SoundAudioPlayback for per-frame track selection and volume fading.

Methods: `0x004C83B0`, `0x004C84A0`, `0x004C8650`

- `this+0x00000000` `PlaylistEntry* head` (read_write, DERIVED)
- `this+0x00000004` `PlaylistEntry* tail` (read_write, DERIVED)
- `this+0x00000008` `PlaylistEntry* cursor` (read_write, DERIVED)
- `this+0x0000000C` `int count` (read_write, DERIVED)
- `this+0x00000010` `int active` (read, DERIVED)
- `this+0x00000014` `int fadeState` (read_write, DERIVED)
- `this+0x00000018` `float fadeSpeed` (read, DERIVED)
- `*(this+0x8)+0x00000000` `void* cursorEntryData` (read, GUESS)
- `*(this+0x8)+0x00000004` `void* cursorEntryNext` (read, GUESS)
- `*(*(this+0x8)+0x0)+0x00000000` `char** trackFilenamePtr` (read, GUESS)

### PlaylistNode

Playlist entry node: data pointer at +0x0, next pointer at +0x4 and an alive/cleanup flag byte at +0x8. Freed via FreeWrapper_7bcf; node data is conditionally freed via 0x00404F70 when the alive flag is set.

Methods: 

- `obj+0x00000000` `void* data` (read_write, GUESS)
- `obj+0x00000004` `PlaylistNode* next` (read_write, GUESS)
- `obj+0x00000008` `byte aliveFlag` (read, GUESS)
- `*(obj+0x4)+0x00000004` `void* nextNodeNext` (read, GUESS)

### AudioSceneManager

Audio scene manager behind global dword_8AC4CC. Accessed only through vtable slots: +8 scene-active query, +4 path submission, +28 DSP wetness setter. No this-relative fields were recovered.

Methods: `0x004C8920`


### SoundSubsystem

Sound-subsystem lifecycle and global dispatch helpers. Game-lifecycle entry points (setup/init/restart/post-cleanup/exit) each gate a DebugLogWrite on a StringSplitLoop parse and share the debug buffer dword_8AD25C. The init-status global dword_8AC4C4 holds a sound-system object that is written by 0x004C82C0 and dispatched through vtable slots +20 (0x004C8D60) and +24 (0x004C8D70); no this-relative fields were recovered.

Methods: `0x004C82C0`, `0x004C8AB0`, `0x004C8AE0`, `0x004C8B20`, `0x004C8CA0`, `0x004C8D00`, `0x004C8D60`, `0x004C8D70`


### SpecialFXState

SpecialFX object with fifteen 4-byte slots (offsets 0x0..0x38). resetAndFreePointer zeroes every slot and releases the one owned allocation held at this+0x38.

Methods: `0x004CA280`

- `this+0x00000000` `unsigned int dword_0` (write, DERIVED)
- `this+0x00000004` `unsigned int dword_1` (write, DERIVED)
- `this+0x00000008` `unsigned int dword_2` (write, DERIVED)
- `this+0x0000000C` `unsigned int dword_3` (write, DERIVED)
- `this+0x00000010` `unsigned int dword_4` (write, DERIVED)
- `this+0x00000014` `unsigned int dword_5` (write, DERIVED)
- `this+0x00000018` `unsigned int dword_6` (write, DERIVED)
- `this+0x0000001C` `unsigned int dword_7` (write, DERIVED)
- `this+0x00000020` `unsigned int dword_8` (write, DERIVED)
- `this+0x00000024` `unsigned int dword_9` (write, DERIVED)
- `this+0x00000028` `unsigned int dword_10` (write, DERIVED)
- `this+0x0000002C` `unsigned int dword_11` (write, DERIVED)
- `this+0x00000030` `unsigned int dword_12` (write, DERIVED)
- `this+0x00000034` `unsigned int dword_13` (write, DERIVED)
- `this+0x00000038` `void* ownedPointer` (read_write, DERIVED)

## Compatibility contracts

- **TelemetryPacketLayout** — A replacement must reproduce the per-vehicle telemetry packet: a header/progress marker written by ProgressBarEventEncode (0x004B33B0) from the state dword at this+0x4894 and the session-time double dbl_8AFEA0, followed by the fixed encode sequence (0x004B2310 position pair, 0x004B2480 speed short, 0x004B25D0 fixed-point, 0x004B2750 clamped short, four wheel entries via 0x004B2840, RPM 0x004B2930, throttle 0x004B29B0, gear 0x004B2A10, clutch 0x004B2A40, 14 subsystem-ready bits 0x004B2AA0, flag word, steering 0x004B2B10, player-state merge 0x004B2B60) and the close 0x004B2AE0.
- **DriverNameBufferBounds** — The driver full-name buffer is 64 bytes starting at this+0x4620; SetDriverName copies at most 63 characters via bounded copy 0x00587DD0 and forces the final byte (this+0x465F) to NUL. The abbreviation output buffer at this+0x46F8 is NUL-terminated at this+0x4707 with a 15-character bound. A replacement must preserve these bounds.
- **FilterPropertiesListInvariants** — The filter-properties list keeps head at this+0x8, tail at this+0xC, current at this+0x10 and count at this+0x14. Removal unlinks a fully matched node, updates current/tail/head as needed, decrements count, conditionally frees node data (node+0x8 flag) via 0x00414370 and always frees the node via FreeWrapper_7bcf.
- **SoundLifecycleSequence** — The sound subsystem is entered from Game_Init (Sound_Init), the render tick (TickCameraTimerAndDispatch, SoundSceneDSPConfigUpdate), Sound_Setup/Sound_Restart during the game, SoundPostCleanup from Game_Post and Sound_Exit from GameExit. Each lifecycle function gates a DebugLogWrite into dword_8AD25C on a StringSplitLoop(2, aDDevF119992002_24, N) parse of the same configuration string.
- **SoundInitStatusObject** — The sound-system object behind global dword_8AC4C4 is created/status-stored by 0x004C82C0 and then dispatched through vtable slots +20, +24, +40 and +72. Every dispatch site guards on the pointer being non-null; a replacement must keep that null-guard contract.

## Unresolved

- Only NationalityDriverInfoLoader (0x004C78F0) is packet-tagged F1CVehicle; SetDriverName, DriverAbbreviationNameFormatter and SetDriverVisibility are aggregated onto F1CVehicle on shared driver-region field evidence. The vehicle-identity aggregation is DERIVED, not confirmed.
- VehicleTelemetryPacketEncoder (0x004C71C0) packet owner is UNKNOWN; its fields are grouped on the vehicle struct via the shared this+0x4894 state dword and the player-vehicle globals dword_7C54F0 / dword_7C54DC.
- The scene array dword_8AC490 stride 396 and its name field at +260 (FilterPropertiesListNodeRemover) come from raw arithmetic and are not independently named.
- node+0x8 is described as a cleanup/flag byte in FilterPropertiesListNodeRemover and AudioSceneReinit but its exact meaning is unverified.
- StringCopyWithValidation return semantics (nonzero treated as skip) are inferred from branch placement only.
- AudioChannelStop (0x00568210) is reused as an object/field validity probe gating the abbreviation and nationality lookups; its real audio semantics are unexplained.
- The word_5C32D8 marker matched by sub_587C20 and the '%c. %-.11s' initial-dot abbreviation format are observed but not semantically established.
- sub_589901 post-processing of the formatted abbreviation output is unknown.
- Globals 0x008AC368, 0x008AD3B4, 0x0059E440, 0x0059E444, 0x0059E8C8 are listed by packet facts as read but do not appear in the decompiled bodies; roles unresolved.
- The concrete class of the mixer behind dword_8AC4C8 (volume float at +4, vtable slots +4/+8/+24/+28) and the scene manager behind dword_8AC4CC are unknown.
- The scene-indexed track table dword_5ACDEC[dword_8AC4C0] (wraps at 4) and the pair off_5D325C / dword_5D3254 are inferred from existing analysis, not proven.
- Sound_Init's NetworkMessageReceiveAndDispatch callee has no packet callee address; flt_8AC4B0 as a scene-camera parameter is DERIVED prose.
- The final buffer-reinitialisation callees in Sound_Restart and Sound_Exit and the ArithmeticComparison_8350 callee in Sound_Exit have no packet callee entries.
- The (0,291) validity window and 20-entry stride-8 table reset in SoundPostCleanup have unconfirmed semantics.
- DispatchGlobalVtableSlot20 / DispatchAudioSystem return an uninitialized local when dword_8AC4C4 is null (undefined behavior); caller contract on that path is unknown.
- Playlist node layout ({data,next,aliveFlag} for teardown vs {0,-1} node plus {node,0,1} entry for ScanDirectoryIntoPlaylist) is GUESS-level; the two layouts are not proven identical.
- The vtable slot numbers (20/24/40/72 on dword_8AC4C4, 4/8/28 on dword_8AC4CC, 4/8/24/28 on dword_8AC4C8) are observed call offsets, not independently documented.
- The embedded path buffer offset 18196 (0x4714) in PathFilenameExtractor is byte-derived; the owning object type is unknown.
