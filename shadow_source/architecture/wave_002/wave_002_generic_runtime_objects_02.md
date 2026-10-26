# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Evidence-linked reconstruction of generic runtime object support in the F1 Challenge engine, covering: session event and sound message dispatch onto shared text handlers (RaceEventMessageDispatcher 0x00411BF0, SoundEventDispatcher 0x00411E90, SessionStringNameLookup 0x004122C0); commentary channel parameter selection (0x004117B0); standings scoring aggregation and driver-leaderboard insertion (0x0041EB30, 0x00418560); sentinel-record and bulk container initialization (0x004144D0, 0x004186A0); driver-context/time record population (0x004144F0); path probe, null-safe string slot and file enumeration/copy utilities (0x00414900, 0x00415C30, 0x00421B10); global linked-list teardown (0x00414210); lazy audio renderer init (0x004184F0); and the configuration layer that registers directory paths, parses config.ini and writes it back (0x004216F0, 0x00421CD0, 0x00422BE0). Class ownership of the dispatcher objects and of most field semantics is unresolved; every class and field here is a DERIVED or GUESS proposal grounded in packet evidence.

## Function roles

- `0x004117B0` **CommentaryChannelParams** — Selects the commentary channel parameter globals for channel 0 (default) or 1 (TV); returns 1 for an out-of-range channel index without writing outputs.
- `0x00411BF0` **SessionEventDispatch** — Race/event message dispatcher: switches on the event ID at *(a2+12) and routes each case group to a shared text handler invoked as handler(a4, a1, *(a3+16), 1[, flag]); the first case group uses a random even/odd flag from RandLCGRandomNumberGenerator()%2; unrecognized IDs return 0.
- `0x00411E90` **SessionEventDispatch** — Sound event dispatcher: switches on the event ID at *(a2+12) and routes each ID to a dedicated handler invoked as handler(a4, a1, params[i], 0[, flag]) with per-ID params index and flag; default returns 0 and case 0x2C returns the initialized -1.
- `0x004122C0` **SessionStringLookupBuffer** — Session string/name lookup from a session-list node indexed by a3: early vehicle-data path keyed on free-camera flag dword_7D0398 and championship mode dword_7D0410 with base dword_8AC394 + 1060*(node+8), else selector-based string-field selection; writes string and three metadata fields to the output buffer; returns 1 on unpopulated sentinel, -1 when the early path was not taken.
- `0x00414210` **GlobalListTeardownSupport** — Global teardown: runs DrawableResourceCleanup on the list at dword_5EA5E8, walks three global linked lists freeing valid payloads with type-specific destructors plus FreeWrapper_7bcf, then zeroes all list head/tail/counter globals.
- `0x004144D0` **SentinelInitializedRecord** — Constructor/initializer writing sentinel defaults into seven dword fields (-1 at 0x0/0x10/0x14/0x18/0x1C, -1.0f bit pattern at 0x8, 0 at 0xC); returns constant -1.
- `0x004144F0` **DriverContextTimeRecord** — Populates a driver-context/time record from arguments with sentinel-table replacement (a6==-1, a7==-2.0, a8==-2.0 pull defaults from dword_5BF9A0[5*a2], flt_5BF9A8[5*a2], flt_5BF9A4[5*a2]) and computes the base/end times this[2]/this[3].
- `0x00414900` **PathProbeContext** — Builds a candidate path (caller path + 5-byte extension from dword_5BE868/byte_5BE86C), probes existence via ToggleFileReadOnlyAttributeViaWin32API with FILE_ATTRIBUTE_NORMAL; returns 1 on null input or missing file, 0 after reallocating the path copy and resetting this+8/+C/+10.
- `0x00415C30` **NullSafeStringSlot** — Null-safe string accessor: dereferences the char** at this+0 and returns the pointed string, falling back to byte_5EA438 when null.
- `0x004184F0` **AudioRendererLazyInitState** — Lazy one-time audio renderer init: returns 0 when byte this+0xAF0 is already set; creates the audio object via thiscall vtable+96 dispatch on dword_8AC4C4, stores it at this+0xAF4, runs three post-init steps (ThresholdGatedVirtualDispatch, WrapperReturning0, ShortComputation_5090 over dword_5EA5E8), marks this+0xAF0=1 and returns 0; returns 1 on not-ready/failure paths.
- `0x00418560` **DriverLeaderboardTable** — Inserts an 8-DWORD entry into a 20-slot sorted driver table (first slot this+0x86C, 32-byte stride) ordered by empty-slot/time/score, shifting via StructCopy; returns 1 on insert, 0 when the driver id is -1, fails the score-threshold gate, or no insertion position is found.
- `0x004186A0` **SentinelRecordArrayContainer** — Bulk initializer: runs StructInitWithSentinelValues on 20 fixed 32-byte blocks, fills a 0x219-DWORD buffer at byte offset 2808 with -1082130432 (IEEE-754 -1.0f), writes scalar defaults at 2788/2792/2796 and 4956, and returns 0.
- `0x0041EB30` **StandingsAggregator** — Aggregates per-category scores from the standings node at dword_7D2DB0 into a 26-slot accumulator, finds the entry with the highest total with optional name filter, and returns the best entry pointer or 0 on absence/insufficient categories/non-strict ties.
- `0x004216F0` **GameConfigSettings** — Registers a fixed list of config directory path constants via StringCopyWithBufferRealloc and initializes config fields this+0xB8..0xE8 (including path count 22 at 0xC4 and the -1082130432 literal at 0xE8); returns 0.
- `0x00421B10` **FileCopySupport** — Enumerates files matching the scene extension from a source directory and copies each to a destination path in 512-byte chunks, skipping hidden and '.'/'..' entries; returns the linked-list destructor result.
- `0x00421CD0` **GameConfigSettings** — Parses config.ini: handles Windows non-admin per-user relocation (CSIDL 5), opens the config text file with fallback, reads lines and dispatches [Components] (path registrations plus settings fields 0xB8..0xE4), [Install], [Autolaunch] (into dword_5EA43C) and [Version] (float at 0xE8); returns 1 on success, 0 on failure.
- `0x00422BE0` **GameConfigSettings** — Writes config.ini: resolves target path, clears the read-only attribute, opens in write-text mode, streams formatted section groups (directories, hardware, video, install, autolaunch mode/launchtime, version), closes and returns 1.

## Proposed classes

### CommentaryChannelParams

Opaque global commentary-channel parameter set: two DWORD values and two pointers per channel, selected by channel index 0 (default) or 1 (TV) in CommentaryChannelParamLookup.

Methods: `0x004117B0`


### SessionEventDispatch

Event-ID-driven text handlers: dispatches the event ID at *(a2+12) to shared name/attribute lookup handlers. Owners of the dispatcher objects are unknown; class grouping is the shared handler-contract, not proven common ownership.

Methods: `0x00411BF0`, `0x00411E90`


### SessionStringLookupBuffer

Output buffer for session string lookups: a string pointer at +0 plus three metadata fields (+8, +C, +10) that SessionStringNameLookup fills and later tests for the unpopulated-sentinel return.

Methods: `0x004122C0`

- `this+0x00000000` `char* string_ptr` (write, GUESS)
- `this+0x00000008` `DWORD meta_field_a` (write, GUESS)
- `this+0x0000000C` `DWORD meta_field_b` (write, GUESS)
- `this+0x00000010` `DWORD meta_field_c` (write, GUESS)

### SentinelInitializedRecord

Small record initialized by StructInitWithSentinelValues with sentinel defaults (-1 dwords, -1.0f at +8, 0 at +C); dword at +4 is deliberately left uninitialized. Owner type unknown.

Methods: `0x004144D0`

- `this+0x00000000` `int sentinel_neg1` (write, GUESS)
- `this+0x00000008` `float sentinel_neg1f` (write, GUESS)
- `this+0x0000000C` `int sentinel_zero` (write, GUESS)
- `this+0x00000010` `int sentinel_neg1_b` (write, GUESS)
- `this+0x00000014` `int sentinel_neg1_c` (write, GUESS)
- `this+0x00000018` `int sentinel_neg1_d` (write, GUESS)
- `this+0x0000001C` `int sentinel_neg1_e` (write, GUESS)

### DriverContextTimeRecord

Driver-context/time record populated by DriverDataLookupAndTimeCalc from arguments a2..a6 plus optional float overrides: context values at +0/+10/+14/+18/+1C, computed base time at +8 and end time at +C. Distinct record from SentinelInitializedRecord; common ownership is not proven.

Methods: `0x004144F0`

- `this+0x00000000` `int driver_id` (write, GUESS)
- `this+0x00000008` `float base_time` (write, GUESS)
- `this+0x0000000C` `float end_time` (write, GUESS)
- `this+0x00000010` `int context_a3` (write, GUESS)
- `this+0x00000014` `int context_a4` (write, GUESS)
- `this+0x00000018` `int context_a5` (write, GUESS)
- `this+0x0000001C` `int context_a6` (write, GUESS)

### PathProbeContext

Caller-supplied output struct for FilePathExtensionCheck: fields this+8 and this+C reset to -1 and this+10 to 0 after a successful file-existence probe. The caller struct itself is not identified.

Methods: `0x00414900`

- `this+0x00000008` `int probe_field_a` (write, GUESS)
- `this+0x0000000C` `int probe_field_b` (write, GUESS)
- `this+0x00000010` `int probe_field_c` (write, GUESS)

### NullSafeStringSlot

Shared/mutable char** slot dereferenced by NullSafePointerDereference with a byte_5EA438 fallback for null; used by callers building name lists and loading settings.

Methods: `0x00415C30`

- `this+0x00000000` `char** string_slot` (read, GUESS)

### GlobalListTeardownSupport

Global teardown helper: cleans the drawable-resource list head and walks three global linked lists (heads 0x005EA5E8/0x005EA5F8/0x005EA608) freeing valid payloads with type-specific destructors, then zeroes every head/tail/counter global.

Methods: `0x00414210`


### AudioRendererLazyInitState

Audio renderer lazy-initialization state: initialized flag byte at +0xAF0 and stored audio-object handle at +0xAF4, managed by LazyRendererAudioInitCheck through a vtable+96 create dispatch on the init-status global.

Methods: `0x004184F0`

- `this+0x00000AF0` `BYTE initialized_flag` (read_write, GUESS)
- `this+0x00000AF4` `DWORD audio_object` (read_write, GUESS)

### DriverLeaderboardTable

20-slot sorted driver leaderboard table starting at this+0x86C with 32-byte (8-DWORD) stride; entries ordered by empty-slot/time/score with the comparison field at this+0x880. Inserted by InsertDriverTableEntry from a wide set of scoring callers.

Methods: `0x00418560`

- `this+0x0000086C` `DWORD[8]*20 entry_array` (read_write, DERIVED)
- `this+0x00000880` `float/int time_score_field` (read_write, GUESS)

### SentinelRecordArrayContainer

Large object bulk-initialized by BufferInitWith10fDefaults: 20 sentinel blocks at byte offset 2148 with 32-byte stride, a 0x219-DWORD (-1.0f) buffer at byte offset 2808, and scalar defaults at 2788/2792/2796/4956. Field offsets are not representable as schema fields because the packet only exposes field:this refs below 0x1000.

Methods: `0x004186A0`


### StandingsAggregator

Reads the standings node (global dword_7D2DB0) through linked-list helpers and aggregates per-category scores to select the best entry with optional name filtering and strict-tie handling.

Methods: `0x0041EB30`


### GameConfigSettings

Configuration state: default config path and per-subsystem directory paths (+0/+0x40/+0x68/+0x70/+0xA8), hardware/video settings fields (0xB8..0xE8) parsed from [Components], and version float at 0xE8. Shared by path registration, config.ini parse and config.ini write. Field-name semantics derive from the config token names in the packet; the 0xC4 dual use (path count vs gridsize) is a recorded contradiction.

Methods: `0x004216F0`, `0x00421CD0`, `0x00422BE0`

- `this+0x00000000` `char* config_path` (read, GUESS)
- `this+0x00000040` `char* replay_dir` (read, GUESS)
- `this+0x00000068` `char* log_dir` (read, GUESS)
- `this+0x00000070` `char* save_dir` (read, GUESS)
- `this+0x000000A8` `char* base_path_prefix` (read, GUESS)
- `this+0x000000B8` `int videodriver` (read_write, GUESS)
- `this+0x000000BC` `int videomode` (read_write, GUESS)
- `this+0x000000C0` `int videorefresh` (read_write, GUESS)
- `this+0x000000C4` `int gridsize_or_path_count` (read_write, GUESS)
- `this+0x000000C8` `int cpurating` (read_write, GUESS)
- `this+0x000000CC` `int systemram` (read_write, GUESS)
- `this+0x000000D0` `int videoram` (read_write, GUESS)
- `this+0x000000D4` `BYTE windowedmode` (read_write, GUESS)
- `this+0x000000D5` `BYTE runbenchmarks` (read_write, GUESS)
- `this+0x000000D6` `BYTE vsync` (read_write, GUESS)
- `this+0x000000D8` `int objdetail` (read_write, GUESS)
- `this+0x000000DC` `int texdetail` (read_write, GUESS)
- `this+0x000000E0` `int fsaa` (read_write, GUESS)
- `this+0x000000E4` `int vbstrategy` (read_write, GUESS)
- `this+0x000000E8` `float version` (read_write, GUESS)

### FileCopySupport

File enumeration and copy utility: enumerates directory entries matching the scene extension and copies each into a destination path in 512-byte chunks with lock-protected I/O wrappers.

Methods: `0x00421B10`


## Compatibility contracts

- **CommentaryChannelLookupContract** — CommentaryChannelParamLookup (0x004117B0) must return 0 and write the two DWORDs and two pointers for channel 0 (globals 0x005BF8C8/0x005BF8CC/0x005BF8D8/0x005BF8E0) or channel 1 (globals 0x005BF8D0/0x005BF8D4/0x005BF8E8/0x005BF8F0); any channel index greater than 1 must return 1 and write nothing.
- **SessionEventRoutingContract** — RaceEventMessageDispatcher (0x00411BF0) must route the event ID read at *(a2+12) through its case table to one of the shared handlers invoked as handler(a4, a1, *(a3+16), 1[, flag]); unrecognized IDs must return 0. The first case group uses a random even/odd flag computed as RandLCGRandomNumberGenerator() % 2.
- **SoundEventRoutingContract** — SoundEventDispatcher (0x00411E90) must route the event ID at *(a2+12) to its handlers as handler(a4, a1, params[i], 0[, flag]) with the per-ID params index and trailing flag; the default case returns 0 and case 0x2C returns the initialized -1.
- **SessionStringLookupSentinelContract** — SessionStringNameLookup (0x004122C0) must return 1 when the output buffer is unpopulated (string equals byte_5EA438, +8 == -1, +C == -1, +10 == 0), -1 when the early vehicle-data path was not taken, otherwise delegate to LinkedListIndexScannerWithValidation and TextAttributeLookup_34d0.
- **DriverTableInsertionContract** — InsertDriverTableEntry (0x00418560) must maintain the 20-slot, 32-byte-stride sorted table at this+0x86C ordered by empty-slot/time/score, shift the intervening block via StructCopy, and return 1 on insert; return 0 when the driver id is -1, when it fails the score-threshold gate, or when no insertion position is found.
- **GlobalListTeardownContract** — GlobalListTripleCleanupWithTimerRemoval (0x00414210) must run DrawableResourceCleanup on the list at dword_5EA5E8, walk the three global lists (heads 0x005EA608/0x005EA5F8/0x005EA5E8) freeing valid payloads with their type-specific destructors plus FreeWrapper_7bcf, and zero every list head/tail/counter global 0x005EA5E8..0x005EA614.
- **ConfigIniParseContract** — ConfigIniParse (0x00421CD0) must perform the Windows non-admin per-user relocation when the OS is XP/NT/2000 and WindowsAdminCheck fails, open the config text file with the alternate-source fallback, dispatch [Components]/[Install]/[Autolaunch]/[Version] into GameConfigSettings fields 0xB8..0xE8 and the autolaunch struct dword_5EA43C, and return 1 on success or 0 on failure.
- **ConfigIniWriteContract** — ConfigFileWriter (0x00422BE0) must write back the directory, hardware, video, install, autolaunch mode/launchtime and version section groups using the same token names, and return 1 on success or 0 when the file cannot be opened; it must clear the read-only attribute first.
- **RendererAudioLazyInitContract** — LazyRendererAudioInitCheck (0x004184F0) must return 0 when the byte at this+0xAF0 is already set or after a successful creation (thiscall vtable+96 dispatch on dword_8AC4C4, stored at this+0xAF4, followed by the three post-init calls and this+0xAF0=1); return 1 when this+0xAF4 is non-null, dword_8AC4C4 is null, or object creation failed.
- **BestScoringEntryContract** — FindBestScoringEntry (0x0041EB30) must return the standings entry with the highest accumulated per-category total, honoring the optional name filter and the strict-tie flag a2, and return 0 when the standings node at dword_7D2DB0 is absent, the category count is below 2, or a tie is not resolved by the strict flag.

## Unresolved

- Owner objects of the dispatcher functions (0x00411BF0, 0x00411E90) are unknown; the meanings of arguments a1..a4 and the event-ID enum at *(a2+12) (which IDs map to which message text) are not established by the packet.
- The parameter contract between RaceEventMessageDispatcher (0x00411BF0) and its callers SceneGraphQuery and GlobalVTableDispatchWithQuery is not resolved; why the random flag applies only to the first case group is not determinable from this packet.
- Purpose of the second discarded RandLCGRandomNumberGenerator() call and of the variant flag in SoundEventDispatcher (0x00411E90) is not established.
- Mapping of SessionStringNameLookup selectors (a2, a4, a5) to concrete string kinds (driver, track, vehicle) and the semantics of the early-path index arithmetic dword_8AC394 + 1060*(node+8) are unconfirmed.
- Owners of the three global lists torn down by GlobalListTripleCleanupWithTimerRemoval (0x00414210) are not established; the canonical name mentions timer removal but no timer-specific calls appear in the body.
- Object type targeted by StructInitWithSentinelValues (0x004144D0) and the semantic meaning of each sentinel field are unknown; the dword at offset 0x4 is deliberately not initialized.
- Globals flt_59E670, flt_59E7E8, flt_59E7EC, flt_59E7F0 are read per the packet but absent from the DriverDataLookupAndTimeCalc body; placement is unknown (likely used by callers or an inlined path).
- Globals aSS (0x005BE860), aS_4 (0x005C2C18), aSSS_1 (0x005C2D5C), aSS_3 (0x005C2D64), dword_5EC3D0 (0x005EC3D0) and asc_5C2AB4 are listed as read but absent from the decompiled bodies; presumed referenced through helper/inlined paths.
- The exact extension bytes in dword_5BE868/byte_5BE86C and the caller struct of FilePathExtensionCheck (0x00414900) are not established; its this+8/+C/+10 fields are written but never read inside the function.
- Literal contents of the config token-name and format strings referenced by address are not present in the packet; their meanings rest on the packet names alone.
- CONTRADICTION: ConfigDirectoryPathRegistration (0x004216F0) writes this+0xC4 = 22 (registered path count) while ConfigIniParse (0x00421CD0) parses aGridsize into this[49] = field 0xC4 (clamped to 0..104); the same offset is used as both path count and grid size unless the registration defaults are overwritten by parsing.
- CONTRADICTION: legacy ABI name BufferInitWith10fDefaults claims a 1.0f fill, but the literal -1082130432 is the IEEE-754 bit pattern for float -1.0f; the ABI label is treated as lower trust than the raw source.
- dword_8AC4C4 identity (InitStatus) is DERIVED from skeleton prose only; its vtable slot +96 target is unknown, and the roles of flt_7CF3C8, WrapperReturning0 (0x004116B0) and ShortComputation_5090 (0x00415090) in the post-init sequence are unconfirmed.
- Semantics of dword_5BF9B0 (team/owner lookup vs other indexed table) and the 5-word stride of the per-driver tables are unconfirmed; driver-table entry fields 2 (time) and 7 (score) are inferred from sort ordering only.
- The exact object layout destroyed by the third walk of 0x00414210 (TextFormatStructInitializer plus four ArrayDestructorIterator passes with stride 20) is unknown; the 20-block array, 0x219-dword buffer and scalar defaults of 0x004186A0 sit at byte offsets 0x864/0xAE4/0xAE8/0xAEC/0xAF8/0x135C that are not representable as schema fields.
- How FlagsGetter's category count and IndexedFieldGetter's indices map to standings columns in FindBestScoringEntry (0x0041EB30); the strict-flag a2 tie semantics are rendered directly from code but not independently confirmed.
- The default/empty path global byte_5EA438 is registered three times in ConfigDirectoryPathRegistration (0x004216F0); whether this is intended or dead repetition is unresolved.
- The directory-path dispatch stubs (NameRegistrationDelegation, StringCopyRealloc, etc.) and the section comparison sub_587C20 have only their packet names; their internal registration semantics are not modeled here.
