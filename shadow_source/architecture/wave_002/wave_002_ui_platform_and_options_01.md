# UIPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

DERIVED architecture proposal for the ui_platform_and_options scope. The packet covers sixteen functions that split into three layers. (1) UI rendering/session layer: UILargeRender (0x00496930) is the per-frame UI render/dispatch handler gated by a mode flag and a collision-classified element dispatch, UIScreenLoad (0x0048AED0) and UIScreenSoundResourceLoader (0x0048E110) load screen resource and sound data under a default directory with an override prefix, SessionUIElementRenderer (0x0045F2B0) and SessionMessageUICommandHandler (0x00470490) encode and dispatch session UI elements/messages, and NetworkUIUpdate (0x00462848) runs the per-tick session UI update under a serialization lock. (2) Session/options data layer: SessionConfigBuilder (0x00461610) packs a compact session-config packet (scene-derived track/directory names, packed option bytes, bit flags, pit times, clamped penetration), SessionEntryList (0x0046AE60 rebuild + 0x00487010 indexed access) owns a linked list of session entries, PlayerCareerStatsGameOptionsLoader (0x004C18B0) parses career statistics and game options from save data into two linked lists, and TrackConfigurationNameBuilder (0x004B16B0) builds a track-configuration path. (3) Platform layer: WindowsAdminCheck (0x00423250) verifies admin privilege via an ACL/AccessCheck against the LOCAL SYSTEM SID, WindowsMessagePumpWithSleep (0x004A1830) runs the Win32 message pump with optional pacing, and D3DWindowSurfaceCreation (0x0044EE10) creates a D3D window surface through a COM interface. CommentaryTVPWSPathBuilder (0x00414E60) builds commentary TV path candidates under a \tv subdirectory. Ownership of every object is UNKNOWN in the packet except SessionEntryList (DERIVED); class grouping is a GUESS-level interpretation of shared field layouts and call relationships, and equal byte offsets across different 'this' owners are deliberately kept as separate fields.

## Function roles

- `0x00414E60` **CommentaryTVPathBuilder** — Builds four commentary TV path candidates (CountryB/CountryE/CircuitB/CircuitE) under a \tv subdirectory, checks each against FilePathExtensionCheck, and on a hit performs a TrackNameDisplayIDLookup for the track display name. Always returns 0.
- `0x00423250` **PlatformServices** — Windows admin-privilege check: impersonates self, opens thread/process token, builds a LOCAL SYSTEM SID ACL in a security descriptor, runs AccessCheck, reverts impersonation, and logs AccessCheck failures. Called by ConfigIniParser.
- `0x0044EE10` **D3DWindowSurface** — D3D window surface creation: zero-initializes part of this, stores the HWND, registers a COM interface and acquires a device object, then creates/configures a surface object through its vtable with mode-derived surface descriptions. Called by HWInput_Setup.
- `0x0045F2B0` **UISessionElement** — Session UI element renderer: encodes a progress-bar/session event (ProgressBarEventEncode) with the current session time, creates a COM UI element via the interface pointer at this+0x3FB8, applies the a2 argument, and dispatches the element over the network.
- `0x00461610` **SessionConfigPacket** — Session-config packet builder: copies global game state into a compact packet (scene-derived track/level file name at this+0x20, directory path at this+0x40, packed option bytes this+0x64..0x6D, bit flags at this+0x76, pit times, clamped penetration), then runs the UtilityFunction_15c0 finalization twice.
- `0x00462848` **SessionNetworkUI** — Per-tick network/UI update: accumulates a2 into counter fields, takes a serialization lock on unk_7CE24C (returns 0 on failure), broadcasts collision events and renders all session UI elements when the session type equals 7, then sets the update-complete byte at obj+0x374 and returns 1.
- `0x0046AE60` **SessionEntryList** — Session entry-list reset and rebuild: notifies state cleanup, frees the node list headed at this+0x44 (walking node+4 next pointers and releasing flagged node sub-objects), zeroes this+0x44..0x50, then rebuilds the list from the ppvOut module-reference array and returns the entry count dword_7D1424.
- `0x00470490` **SessionMessageUIHandler** — Session-message UI command handler: dispatches on the type selector at this+0x304. Types 432/434 copy the message string at this+0x2F0 into a global track buffer; type 435 verifies session state, encodes a progress-bar event, creates a texture, builds a path from byte_5EA438 and dispatches the session state. Every path ends by calling vtable slot +168.
- `0x00487010` **SessionEntryList** — Indexed accessor into the session entry list: validates a2 against the count at this+0x50, walks the node list from this+0x44 via next pointers at +4, and returns the located node data pointer (+0), falling back to byte_5EA438 for out-of-range or null entries.
- `0x0048AED0` **UIScreen** — UI screen resource load: opens the screen resource file (override prefix dword_5EC408 plus screen name at this+0xB0, falling back to byte_5EA438), measures it with seeks, allocates a (pointer,size) buffer, streams the chunks in, frees any prior output buffer, installs the new buffer, and closes the stream.
- `0x0048E110` **UIScreen** — UI screen sound resource loader: frees any existing Bink sound at this+0xE0, creates a sound object at this+0xE4 from the screen path (this+0xB0 or default), normalizes the path, then creates a second sound object with the extra directory dword_5EC3F0 appended and applies the DSP parameter flt_7CF2CC.
- `0x00496930` **UIRenderer** — Per-frame UI render/dispatch handler: sets the mode flag at this+0x28, gates on sub_496E20, resolves the active element at this+0x156C through collision classification, dispatches per-element-type rendering via vtable slots, copies click/key events from word_7CB21C into this+0x159C, dispatches clicks, and copies the viewport rect.
- `0x004A1830` **PlatformServices** — Windows message pump with optional pacing: peeks the message queue, enters a GetMessageA/TranslateMessage/DispatchMessageA loop (returns -1 on WM_QUIT), or sleeps for an InputClamp-derived duration when no message is pending unless suppressed by byte_7CE2E4.
- `0x004A4DB0` **UIComponent** — UI component teardown: resets five byte flags and ~25 numeric/state fields, then conditionally releases three child resources (arrays at this+0xC/0x10 via ArrayResourceCleanup, buffer at this+0x14 via sub_4A3B30/sub_4A2220), nulling each freed pointer.
- `0x004B16B0` **TrackConfiguration** — Track-configuration name builder: reads the track name at this+0x2D50 (default byte_5EA438), runs NameCompareAndFormat on it, and when a non-empty config name exists at this+0x2D6C copies three object-held path strings plus the default directory via StringCopyWithBufferRealloc.
- `0x004C18B0` **PlayerCareerStats** — Player career stats and game options loader: iterates config tokens over unk_8AC1E8, allocates career-season records (45396 bytes) for the primary list and track/directory records for the secondary list, parses career counters, float averages, mechanical-failure, race-condition and game-option values, deduplicates track records, and appends nodes.

## Proposed classes

### CommentaryTVPathBuilder

Builds candidate commentary TV file paths under a \tv subdirectory from the object's directory string plus four extension suffixes, and maps a hit to a track display name.

Methods: `0x00414E60`

- `this+0x00000000` `char* DirectoryNamePtr` (read, GUESS)
- `this+0x00000008` `int TrackDisplayIndex` (read, GUESS)

### PlatformServices

Windows-interop services: admin-privilege detection via ACL/AccessCheck and the Win32 message pump with pacing sleep.

Methods: `0x00423250`, `0x004A1830`


### D3DWindowSurface

Owns a D3D window surface: HWND, created surface pointer, surface description constants, and the COM registration/device-acquisition path that produces the surface object.

Methods: `0x0044EE10`

- `this+0x00000000` `HWND Hwnd` (read_write, GUESS)
- `this+0x00000004` `void* SurfacePtr` (write, GUESS)
- `this+0x0000024C` `int SurfaceDescriptionValue` (write, GUESS)
- `this+0x00000278` `int ModeSelector` (read, GUESS)
- `this+0x0000037C` `byte InitLoopStart` (read_write, GUESS)
- `this+0x00000C7C` `dword SurfaceConst0` (write, GUESS)
- `this+0x00000C80` `dword SurfaceConst1` (write, GUESS)

### UISessionElement

Encodes and dispatches a session UI element over the network: reads the session type and session time, encodes a progress-bar event, creates a COM UI object from the interface pointer at this+0x3FB8, and dispatches it.

Methods: `0x0045F2B0`

- `this+0x00003FB8` `void* ElementInterfacePtr` (read, GUESS)
- `this+0x00003FD9` `byte PayloadByteCount` (read, GUESS)

### SessionConfigPacket

Packs the compact session-configuration packet copied from global game state: scene-derived names, packed option bytes, bit flags, pit times and clamped penetration, finalized by two utility passes.

Methods: `0x00461610`

- `this+0x00000020` `char[32] TrackFileName` (write, GUESS)
- `this+0x00000040` `char[32] DirectoryPath` (write, GUESS)
- `this+0x00000060` `float UIFloatValue` (write, GUESS)
- `this+0x00000064` `byte OptionByte0` (write, GUESS)
- `this+0x00000065` `byte ReservedByte` (write, GUESS)
- `this+0x00000066` `byte OptionByte2` (write, GUESS)
- `this+0x00000067` `byte OptionByte3` (write, GUESS)
- `this+0x00000068` `byte OptionByte4` (write, GUESS)
- `this+0x00000069` `byte OptionByte5` (write, GUESS)
- `this+0x0000006A` `byte OptionByte6` (write, GUESS)
- `this+0x0000006B` `byte SessionCount` (write, GUESS)
- `this+0x0000006C` `byte OptionByte7` (write, GUESS)
- `this+0x0000006D` `byte OptionByte8` (write, GUESS)
- `this+0x00000074` `word OptionWord` (write, GUESS)
- `this+0x00000076` `word FlagsWord` (write, GUESS)
- `this+0x00000078` `word PitOpenTime` (write, GUESS)
- `this+0x0000007A` `word PitCloseTime` (write, GUESS)
- `this+0x0000007C` `word PenetrationLimitScaled` (write, GUESS)

### SessionNetworkUI

Per-tick session UI update under a serialization lock: accumulates counters, optionally broadcasts collision events, renders all session UI elements, and flags the update as complete.

Methods: `0x00462848`

- `obj+0x00000374` `byte UIUpdateComplete` (write, GUESS)

### SessionEntryList

Owns a linked list of session entry nodes (head/tail/sentinel/count at this+0x44..0x50): frees and rebuilds the list from the ppvOut module-reference array, and provides indexed string access with a fallback default.

Methods: `0x0046AE60`, `0x00487010`

- `this+0x00000044` `void* NodeListHead` (read_write, DERIVED)
- `this+0x00000048` `void* NodeListTail` (read_write, DERIVED)
- `this+0x0000004C` `void* NodeListSentinel` (read_write, DERIVED)
- `this+0x00000050` `int ElementCount` (read, DERIVED)

### SessionMessageUIHandler

Handles session-message UI commands keyed on a type selector: copies message strings into global track buffers (types 432/434) or verifies session state, encodes a progress event, creates a texture, builds a path and dispatches session state (type 435).

Methods: `0x00470490`

- `this+0x00000040` `void* SessionStateOwnerPtr` (read, GUESS)
- `this+0x000002F0` `char* MessageStringPtr` (read, GUESS)
- `this+0x00000304` `int MessageTypeSelector` (read, GUESS)

### UIScreen

Loads UI screen resource data (and its sound resources) from files: builds a resource path from an override prefix plus the per-screen name, streams the data into a (pointer,size) buffer, and creates/normalizes sound objects.

Methods: `0x0048AED0`, `0x0048E110`

- `this+0x000000B0` `char* ScreenNamePtr` (read, GUESS)
- `this+0x000000E0` `void* SoundHandle` (read_write, GUESS)
- `this+0x000000E4` `void* SoundObjectHandle` (read_write, GUESS)

### UIRenderer

Per-frame UI render/dispatch: resolves the active element through collision classification, manages element/viewport lifecycle and fade state, dispatches per-type render through vtable slots, collects click/key events, and dispatches clicks.

Methods: `0x00496930`

- `this+0x00000018` `void* SubElementPtr` (read, GUESS)
- `this+0x00000020` `void* ClickHandlerPtr` (read, GUESS)
- `this+0x00000028` `byte ModeFlag` (write, GUESS)
- `this+0x00000058` `int ViewportRect0` (read, GUESS)
- `this+0x0000005C` `int ViewportRect1` (read, GUESS)
- `this+0x00000060` `int ViewportRect2` (read, GUESS)
- `this+0x00000064` `int ViewportRect3` (read, GUESS)
- `this+0x00000068` `int ViewportRect4` (read, GUESS)
- `this+0x0000006C` `int ViewportRect5` (read, GUESS)
- `this+0x00000074` `int DispatchType` (read, GUESS)
- `this+0x00000078` `int ScratchRect0` (write, GUESS)
- `this+0x0000007C` `int ScratchRect1` (write, GUESS)
- `this+0x00000080` `int ScratchRect2` (write, GUESS)
- `this+0x00000084` `int ScratchRect3` (write, GUESS)
- `this+0x00000088` `int ScratchRect4` (write, GUESS)
- `this+0x0000008C` `int ScratchRect5` (write, GUESS)
- `this+0x00000094` `int ScratchRect6` (write, GUESS)
- `this+0x000000C0` `float FadeStep` (read, GUESS)
- `this+0x000000C4` `float FadeAccumulator` (read_write, GUESS)
- `this+0x000000CC` `float FadeValue` (read_write, GUESS)
- `this+0x000000D0` `float FadeValue0` (read, GUESS)
- `this+0x000000D4` `float FadeValue1` (read, GUESS)
- `this+0x00001558` `char* ElementStringPtr` (read, GUESS)
- `this+0x00001560` `int ElementValue0` (read, GUESS)
- `this+0x00001564` `int ElementValue1` (read, GUESS)
- `this+0x0000156C` `void* ActiveElementPtr` (read_write, GUESS)
- `this+0x00001598` `int EventCount` (write, GUESS)

### UIComponent

UI component object teardown: resets flag and state fields, then conditionally releases array and buffer child resources.

Methods: `0x004A4DB0`

- `this+0x00000008` `void* ObjectPtr` (write, GUESS)
- `this+0x0000000C` `void* ArrayResource0` (read_write, GUESS)
- `this+0x00000010` `void* ArrayResource1` (read_write, GUESS)
- `this+0x00000014` `void* BufferResource` (read_write, GUESS)
- `this+0x00000035` `byte Flag0` (write, GUESS)
- `this+0x00000075` `byte Flag1` (write, GUESS)
- `this+0x000000B5` `byte Flag2` (write, GUESS)
- `this+0x000000F5` `byte Flag3` (write, GUESS)
- `this+0x00000135` `byte Flag4` (write, GUESS)
- `this+0x00000158` `int StateField0` (write, GUESS)
- `this+0x0000015C` `int SentinelField0` (write, GUESS)
- `this+0x00000160` `int SentinelField1` (write, GUESS)
- `this+0x00000184` `int StateField1` (write, GUESS)
- `this+0x00000188` `int StateField2` (write, GUESS)
- `this+0x0000018C` `int StateField3` (write, GUESS)
- `this+0x00000190` `byte StateByte0` (write, GUESS)
- `this+0x00000194` `int StateField4` (write, GUESS)
- `this+0x00000198` `int StateField5` (write, GUESS)
- `this+0x0000019C` `int StateField6` (write, GUESS)
- `this+0x000001A0` `int StateField7` (write, GUESS)
- `this+0x000001A4` `int StateField8` (write, GUESS)
- `this+0x000001A8` `int StateField9` (write, GUESS)
- `this+0x000001AC` `int StateField10` (write, GUESS)
- `this+0x000001B0` `int StateField11` (write, GUESS)
- `this+0x000001B8` `int StateField12` (write, GUESS)
- `this+0x000001BC` `int StateField13` (write, GUESS)
- `this+0x000001C0` `int StateField14` (write, GUESS)
- `this+0x000001C4` `int StateField15` (write, GUESS)
- `this+0x000001C8` `int StateField16` (write, GUESS)
- `this+0x000001CC` `int StateField17` (write, GUESS)

### TrackConfiguration

Builds a track-configuration name path from the track name and up to three object-held config path strings, using the default application directory as fallback.

Methods: `0x004B16B0`

- `this+0x00002D50` `char* TrackNamePtr` (read, GUESS)
- `this+0x00002D5C` `char* ConfigPath0` (read, GUESS)
- `this+0x00002D64` `char* ConfigPath1` (read, GUESS)
- `this+0x00002D6C` `char* ConfigNamePtr` (read, GUESS)

### PlayerCareerStats

Loads player career statistics and game options from save data into two linked lists (career-season records and track/directory records), parsing token streams with shared tuple parsers and deduplicating track entries.

Methods: `0x004C18B0`

- `this+0x00000000` `void* SeasonListHead` (read_write, GUESS)
- `this+0x00000004` `void* SeasonListTail` (read_write, GUESS)
- `this+0x00000008` `void* SeasonListSentinel` (read_write, GUESS)
- `this+0x0000000C` `int SeasonListCount` (write, GUESS)
- `this+0x00000010` `void* TrackListHead` (read_write, GUESS)
- `this+0x00000014` `void* TrackListTail` (read_write, GUESS)
- `this+0x00000018` `void* TrackListSentinel` (read_write, GUESS)
- `this+0x0000001C` `int TrackListCount` (write, GUESS)
- `this+0x00000044` `float AvgStartPosition` (write, GUESS)
- `this+0x00000048` `float AvgFinishPosition` (write, GUESS)
- `this+0x0000004C` `float AvgRaceDistance` (write, GUESS)
- `this+0x00000050` `float AvgOpponentStrength` (write, GUESS)
- `this+0x00000054` `int MechanicalFailureRate` (write, GUESS)
- `this+0x00000068` `int RaceConditionWeather` (write, GUESS)
- `this+0x0000006C` `byte TimescaleFlag` (write, GUESS)

## Compatibility contracts

- **AdminPrivilegeDetection** — A replacement must determine admin status the same observable way: impersonate self, open the thread (falling back to process) token, build a LOCAL SYSTEM SID access-allowed ACL in a self-relative security descriptor, run AccessCheck with the GENERIC_MAPPING, revert impersonation on success, and return the AccessStatus BOOL. AccessCheck failure is logged via the FileOpWithGlobalBuffer path with the 'AccessCheck() failed with error %lu' format.
- **WindowsMessagePumpSemantics** — A replacement must keep the message-pump contract: PeekMessageA to test the queue, a GetMessageA/TranslateMessage/DispatchMessageA loop that returns -1 when GetMessageA returns 0 (WM_QUIT), and, when no message is pending, a return of 0 after a Sleep of an InputClamp-derived duration unless suppressed by byte_7CE2E4.
- **CommentaryTVPathLayout** — Commentary path candidates must be built as '<directory-name><dir2><dir3>\tv<name>_' followed by one of the extensions CountryB/CountryE/CircuitB/CircuitE, each checked with FilePathExtensionCheck; a hit maps to a track display ID via TrackNameDisplayIDLookup using the display-index field this[2].
- **SessionConfigPacketLayout** — The packed session-config packet must keep its field layout and finalization: scene-derived track file name at this+0x20, directory path at this+0x40, float UI value at this+0x60, packed option bytes at this+0x64..0x6D, flags word at this+0x76, pit times at this+0x78/0x7A, clamped thousand-scaled penetration at this+0x7C, and two finalization passes through UtilityFunction_15c0 (second pass flagged by dword_7D0134).
- **SessionEntryListContract** — The session entry list must expose the observed layout: head/tail/sentinel/count at this+0x44/0x48/0x4C/0x50, nodes with data at +0, next at +4 and a flag byte at +8, rebuild from the ppvOut module-reference array (insert value -1), and indexed access returning the node data or the byte_5EA438 fallback for out-of-range/null entries.
- **UIScreenResourceLoad** — UI screen resources are loaded from a file whose path is the override prefix dword_5EC408 concatenated with the per-screen name at this+0xB0 (both falling back to byte_5EA438), opened through the AudioStreamOpen stream API, measured by seek/position, streamed into a freshly allocated (pointer,size) buffer, and installed as the caller's output pointer after freeing any prior buffer.
- **SessionUIElementNetworkDispatch** — Session UI elements are encoded and dispatched over the network: when the session type dword_7C56A4 equals 7 a variable payload (byte count at this+0x3FD9, data at this+0x3FDA) is copied, a progress-bar event is encoded with the current session time dbl_8AFEA0, a COM UI object is created via the interface at this+0x3FB8, and the element is dispatched through NetworkSendDispatch with a size derived from ((v7 >> 8) & 0x3FF) + 8.

## Unresolved

- Owner of almost every object is UNKNOWN in the packet; only SessionEntryList carries a DERIVED owner. Class grouping in this proposal is GUESS-level and may split or merge when independent class evidence arrives.
- Equal byte offsets across different owners are kept as separate fields (rule: base+offset identifies a field): e.g. this+0x0 is CommentaryTVPathBuilder.DirectoryNamePtr, D3DWindowSurface.Hwnd and PlayerCareerStats.SeasonListHead; this+0x18 is UIRenderer.SubElementPtr and PlayerCareerStats.TrackListSentinel; this+0x60/0x64/0x6C appear in both SessionConfigPacket and UIRenderer/PlayerCareerStats. No shared ownership is proven.
- CommentaryTVPWSPathBuilder: the pointer-array entries this+3, this+8, this+13, this+18 are used as file-extension string pointers but have no packet field records; the semantics of the final two TrackNameDisplayIDLookup arguments (pairs 0/1, 0/0, 1/1, 1/0) are unknown; the constant 0 return is uninterpreted.
- WindowsAdminCheck: the exact API contracts behind the Win32 IAT globals (token, SID, ACL, AccessCheck) are implied by call position only; the byte_FF0000000000xxxx read/write globals are TEB-region style addresses outside the process image and are treated as SEH/thread-context artifacts, not program data.
- D3DWindowSurfaceCreation: the DirectDraw/D3D interface contracts behind ppvOut (0x007CA590) and the unk_5AD3F0/unk_5AD490/unk_5B0E84 data blobs are not resolvable from this packet; the v13 block {20,16,0,0,1024} and the this+0x0 != 1 mode discriminator are undocumented; the init_literal writes at this+0xC7C/0xC80 have no asserted float interpretation.
- SessionConfigBuilder: semantics of the packed bytes and bit flags (weather, options, damage) are inferred from field position only; the counter/directory globals flt_59E440, flt_59E874, flt_59F120 and unk_8AC368 are read but absent from the raw body and are likely accessed inside UtilityFunction_15c0.
- SessionUIElementRenderer: the local v7 used for the NetworkSendDispatch size is never written in the raw source, so the message id ((v7 >> 8) & 0x3FF) + 8 and its size are unresolved; the COM object lifetime is not evidenced.
- NetworkUIUpdate: the counter fields at (a3 - 80) and (a4 - 62) are reached through caller-provided register pointers with no field evidence; sub_4A0590 is not confirmed to be a critical section.
- UILargeRender: the meaning of the this+0x74 enum values (1,2,3,4,5,6,7,8,12,13) is inferred from dispatch behavior only; vtable slots 0x80/0x84 on the resolved element and the destination buffer at this+5532 (event array base) are not in the packet field list; the switch tables jpt_49698B/jpt_496A74/byte_496DE0 and float constants flt_59E440/flt_5AC994 are flagged but absent from the raw source.
- UIComponentCleanup: the prelabel template classified the five flag bytes and -1 sentinels as ctor_init, but the resource-releasing tail indicates cleanup; the roles of the three child resources and the sub_4A2220 vs sub_4A3B30 distinction are unknown.
- SessionMessageUICommandHandler: globals dword_7CD204, unk_7CE24D and byte_7CE498 are flagged as read but absent from the raw body; semantics of vtable slot +168 and the byte_7CD84D/byte_7CD87F flags are not provable here.
- UIScreenLoad: the meaning of the ConditionalDispatchBasedOnFlag flag arguments (1 then 2) and the chunk buffer format consumed by sub_5665B0 are unknown; whether the resource is a UI screen description or a generic container is unproven; the (pointer,size) output struct format is inferred.
- UIScreenSoundResourceLoader: the rollback semantics of ObjectCreationWithRollbackOnFailure on field 0xE0 are not visible; global dword_8AFE64 is read per static analysis but absent from the raw body.
- PlayerCareerStatsGameOptionsLoader: token-dispatch semantics of sub_5651B0/sub_587C20 and the loop-break discriminator values are unknown; the recursion passes a2 as the receiving object whose structure is unresolved; the 45396-byte season record layout is unknown; the career counter and game-option scalar offsets are not asserted; the two-list distinction is DERIVED from token names, not packet evidence.
- TrackConfigurationNameBuilder: byte_5EA438 as the default application directory is DERIVED from prior analysis and not verifiable from this packet; the returned buffer-copy result (pointer vs count) is undocumented.
- WindowsMessagePumpWithSleep: byte_7CE2E4 sleep-suppression semantics and the InputClamp input/output relationship are DERIVED from skeleton analysis, not independently confirmed.
