# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This packet reconstructs the generic runtime object families exercised by the player-session and network-event paths. The player-file/settings chain (F_5StepInit, SettingsFileInit, PlayerFileEnter, PlayerFileSetup, NoPlayerStringFlagSetter) shares a name/path formatting helper and vehicle-data copy, and touches a dual-list at byte 0x4918, a no-player flag at 0x49AC and a vehicle-data pointer at 0x49B0 (GUESS grouping, ownership not proven). RaceSessionParameters (0x004B1190) loads clamped qualifying/race-laps/race-time defaults overridden from string-keyed season data. A central event dispatcher (0x004B3400) routes framed packets by major type bits 29-31 to domain handlers, fed by a RingBuffer (0x004B3AF0/0x004B3B30/0x004B3B40) whose 432-byte entries are consumed through the blob-copy utility (0x004B3A90). List management is split into SlotListRegistry (104 stride-16 slot records at this+0x40, draining into an output list), ListTransferStation (doubly-linked source at this+0x714 into a singly-linked output at this+0x30) and two node layouts (12-byte data/next/flag and 16-byte data/next/prev/flag). Model-scene file writing (FileStreamReader, FileFormatHeaderReader, sub_4B5040) frames records through a common file backend. Startup also covers the 514-entry noise table and the render init/restart routines gated by StringSplitLoop + DebugLogWrite. Most owners remain UNKNOWN; class groupings and field roles are DERIVED/GUESS and must be verified before use.

## Function roles

- `0x004B0720` **PlayerFileSession** — Five-step player-file session initialization: formats the object name/path into a 0x100-byte stack buffer, tears down the dual-list at byte offset 0x4918, copies vehicle data fields, dispatches the formatted buffer through the triage helper, runs the closing step sub_4B0C00, and always returns 0.
- `0x004B0930` **PlayerFileSession** — Settings-file initialization: copies vehicle data fields, seeds a path buffer from byte_5EA438, formats the settings path with a 0x100-byte length limit, clears the file read-only attribute with mask 128, reads the career section from the file, and returns 0.
- `0x004B0B10` **PhysicsPathBuilder** — Accessor returning the address of the member (or embedded sub-object) located 20 bytes into this (this + 20); no side effects and no reads beyond computing the address. The member at byte offset 20 is unidentified.
- `0x004B1190` **RaceSessionParameters** — Initializes race-session parameters (qualifying laps, race laps, race time) with clamped defaults, then, when the season races section is found, overrides them from string-keyed data entries with clamping and time-multiplier scaling; also loads recon-pit open/close values into session globals. Returns the season-section result.
- `0x004B1520` **PathRegistry** — Extracts a string from the indexed member slot this[7*a2 + 2609] (falling back to byte_5EA438 when null), copies it into the output buffer with limit a4-1, and when a game-filter string exists and fits, appends the word_5C32D8 extension marker followed by the game filter; returns non-null when the append was performed.
- `0x004B1600` **PathRegistry** — Copies six path-string pointers held in this (offsets 0x1F8C, 0x1F94, 0x1F9C, 0x1A4, 0x1AC, 0x1B4) through a reallocating string copy, falling back to byte_5EA438 on any null; returns the result of the final copy.
- `0x004B17F0` **PlayerFileSession** — Tests whether string a2 contains the global literal aNoplayer (0x005D2328) and, when found, sets the flag at this[4715] (byte offset 0x49AC) to 1; returns the substring-search result.
- `0x004B1820` **PlayerFileSession** — Player-file handler entry: when StringSplitLoop reports verbose debug enabled, logs the 'entered playerf' message via DebugLogWrite into dword_8AD25C; stores the vehicle-data global pointer unk_5EC6D8 into this+0x49B0; returns the player-profile create/read result.
- `0x004B1870` **PlayerFileSession** — Player-file subsystem setup at game start: parses the debug source-path string via StringSplitLoop, logs the 'entered playerf' message on success, then initializes player state via sub_4B0770(this,1) and PlayerFileInit(this,1); returns the BOOL combining both init results.
- `0x004B3400` **CentralEventDispatcher** — Central message/event packet dispatcher: reads the 32-bit header at this+0 and routes on the major type (bits 29-31) and sub-type (bits 18-23), bounds-checking the low-byte vehicle index below 0x68, to domain handlers covering vehicle input/control, vehicle state/position, UI/sound, session/race control (lap completion, pit timer, grid reorder, MIDI) and AI/motion. Called from BufferReset.
- `0x004B3A90` **BinaryRecordCopier** — Copies a variable-length data blob from source a2 into destination this (byte count = 10-bit size field in bits 8-17 of the source header plus 8), then copies the dword at offset 0x1AC from source to destination; returns this. The size guard is effectively unconditional for non-negative sizes.
- `0x004B3AF0` **RingBuffer** — Advances a fixed-size ring-buffer read pointer by one 432-byte entry: when the read pointer (0x6C00C) equals the end/limit pointer (0x6C004) it wraps to the stored start (0x6C008) and returns 0; otherwise it processes the current entry via ArithmeticComparison_3a90, advances by 432 bytes, and returns 1.
- `0x004B3B30` **RingBuffer** — Copies one dword within a session object: reads this[110594] (byte 0x6C008) and writes the same value to this[110595] (byte 0x6C00C), returning the copied value. No branches and no other side effects.
- `0x004B3B40` **RingBuffer** — Drains the ring buffer of pending entries then resets it: while the current pointer (0x6C008) differs from the end pointer (0x6C004), calls sub_4B3400 on each 432-byte entry, advances the pointer, and decrements the pending counter at this+0; finally resets the read/current/end pointers (0x6C00C, 0x6C008, 0x6C004) to base+4 and returns that base pointer.
- `0x004B3BD0` **NoiseTable** — Initializes a 514-entry float noise table: entry 0 set to 0.0, entries 1-256 uniform in [0,1), entries 257-512 uniform in [-1,1), entry 513 receives the RDTSC timestamp; the PRNG is seeded from GetTickCount via the TLS state setter before the fill. Called once during startup by GameFileLoader.
- `0x004B4030` **RenderState** — Render subsystem init: runs StringSplitLoop(2, aDDevF119992002_21, 199) and, when the result's low byte is non-zero, writes the 'Entered Render Init' log via DebugLogWrite into dword_8AD25C and returns its result; otherwise returns the StringSplitLoop result unchanged. Called by Game_Init.
- `0x004B4060` **RenderState** — Render-restart routine: calls StringSplitLoop(2, aDDevF119992002_21, 215) and logs 'Entered Render Restart' when its byte value is non-zero, then fills the 0x68-byte render-state object pointed to by this with byte pattern 0x01 and returns the integer 16843009.
- `0x004B4250` **ModelSceneFileSerialization** — Writes a framed string record to a file stream: emits a 4-byte header, a single length byte, builds a zero-padded string buffer seeded from byte_5EA438, conditionally writes it when the length byte is non-zero, null-terminates it and passes it through a reallocating string copy; always returns 1. Called by ModelSceneFileLoader.
- `0x004B43E0` **ModelSceneFileSerialization** — Reads a 4-byte header word via the file backend, extracts a 10-bit operation id from bits 8-17, and validates the header: bits 29-31 must equal 0x20000000 and bits 17-22 must be zero. Valid headers dispatch operation id+1 through NetworkOperationDispatchByFlag; invalid headers dispatch the raw id; both paths return the dispatch result.
- `0x004B45E0` **CleanupRegistry** — Minimal cleanup-registration wrapper: reads the sub_4B45F0 function pointer (global 0x004B45F0), casts it to an integer, passes it through BooleanToIntConversion, and returns the normalized result. The target cleanup routine's behavior is not evidenced.
- `0x004B5040` **ModelSceneFileSerialization** — Writes a fixed-format binary block through the file backend: a header byte from this, a length byte a2, a2 payload bytes from this+1, null-terminates the payload at this[a2+1], then flushes fixed regions at this+65 (32 bytes), this+97 (32 bytes), this+132 (4 bytes) and this+136 (4 bytes); always returns 1.
- `0x004B50C0` **FloatBoundsFilter** — Bounds predicate on a float parameter a2 against two fields of this: this[33] (+0x84) lower bound and this[34] (+0x88) upper bound, where the sentinel -1.0e32 in either field disables that bound check; returns the conjunction of the applicable comparisons.
- `0x004B5E50` **SlotListRegistry** — Iterates 104 per-slot list records (16 bytes each) starting at this+0x40; for every non-empty slot it drains the linked node list (locate by data pointer, unlink, free node and flagged payload, reinitialize data via StructInitWithGlobalData, allocate a fresh 12-byte node) and prepends each item into the output list at this+0x10. Returns the slot counter.
- `0x004B5F60` **ListTransferStation** — Drains a doubly-linked source list (this+0x714 head / +0x718 tail / +0x71C current / +0x720 count) into a singly-linked output list (this+0x30 head / +0x34 tail / +0x38 current / +0x3C count): per node, unlink, free wrapper and flagged data, reinitialize via SmallStructZeroInit, allocate a fresh 12-byte wrapper and prepend. Returns the source current pointer (null once drained).
- `0x004B72A0` **SlotListRegistry** — Indexes a slot list at this + 64 + 16*a2, copies the slot head into the adjacent +8 slot field, then walks the linked list until the float bounds predicate (UtilityFunction_50c0) accepts a node value against criterion a3; returns the accepted node's value pointer, or null when empty or exhausted.

## Proposed classes

### PlayerFileSession

Player-file and settings session object: owns the player-profile dual-list, the no-player flag, the vehicle-data pointer and the name/path formatting used by the player-file init chain. Grouping is GUESS: the packet does not prove F_5StepInit, SettingsFileInit, PlayerFileEnter, PlayerFileSetup and NoPlayerStringFlagSetter share one base.

Methods: `0x004B0720`, `0x004B0930`, `0x004B17F0`, `0x004B1820`, `0x004B1870`

- `this+0x000049AC` `int32 no_player_flag` (write, DERIVED)
- `this+0x000049B0` `opaque_pointer vehicle_data_ptr` (write, DERIVED)

### PhysicsPathBuilder

Opaque object exposing a member 20 bytes into its body; the packet's caller names suggest a physics-file-path object, but that connection is not evidenced so the owner stays UNKNOWN and the class is a placeholder. The member at byte offset 20 is not promoted to a class field because no allowed field evidence ref covers that base/offset.

Methods: `0x004B0B10`


### RaceSessionParameters

Session object holding race-session parameter slots (qualifying laps, race laps, race time) with per-parameter clamp bounds and a time multiplier, loaded from string-keyed season data.

Methods: `0x004B1190`

- `this+0x00000154` `char* season_section_path` (read, DERIVED)
- `this+0x0000200C` `int32 qualifying_laps` (read_write, DERIVED)
- `this+0x00002014` `int32 qualifying_laps_min` (read, DERIVED)
- `this+0x00002018` `int32 qualifying_laps_max` (read, DERIVED)
- `this+0x00002108` `int32 race_laps` (read_write, DERIVED)
- `this+0x00002110` `int32 race_laps_min` (read, DERIVED)
- `this+0x00002114` `int32 race_laps_max` (read, DERIVED)
- `this+0x00002204` `int32 race_time_minutes` (read_write, DERIVED)
- `this+0x0000220C` `int32 race_time_min` (read, DERIVED)
- `this+0x00002210` `int32 race_time_max` (read, DERIVED)
- `this+0x00002300` `float time_multiplier` (read, DERIVED)

### PathRegistry

String/path registry: six path-string pointers copied en masse, plus the indexed name-slot accessor that appends a game-filter extension. The indexed slot stride (7 dwords per entry, base 2609) and the shared base with the bulk copy are unproven; the .HOT extension reading is DERIVED only.

Methods: `0x004B1520`, `0x004B1600`

- `this+0x00001F8C` `char* path_ptr_1` (read, DERIVED)
- `this+0x00001F94` `char* path_ptr_2` (read, DERIVED)
- `this+0x00001F9C` `char* path_ptr_3` (read, DERIVED)
- `this+0x000001A4` `char* path_ptr_4` (read, DERIVED)
- `this+0x000001AC` `char* path_ptr_5` (read, DERIVED)
- `this+0x000001B4` `char* path_ptr_6` (read, DERIVED)

### CentralEventDispatcher

Parses framed event packets (32-bit header at +0, sub-type bits 18-23, low-byte vehicle index) and routes each major type (bits 29-31) to vehicle input, vehicle state, UI/sound, session/race-control and AI/motion domain handlers. The fields describe the message-entry layout this dispatcher parses.

Methods: `0x004B3400`

- `this+0x00000000` `int32 (major bits 29-31, sub-type bits 18-23, vehicle index low byte) message_header` (read, DERIVED)
- `this+0x00000004` `float payload_float` (read, DERIVED)
- `this+0x00000008` `uint8[6] packed_position_bytes` (read, DERIVED)
- `this+0x0000000E` `int32 position_offset` (read, DERIVED)
- `this+0x00000010` `int32 payload_dword` (read_write, DERIVED)
- `this+0x00000014` `uint8 slot_byte` (read, DERIVED)
- `this+0x00000018` `int32 entry_tail_field` (read, GUESS)

### RingBuffer

Fixed-size ring buffer of 432-byte event entries with end/current/read pointers at this+0x6C004/+0x6C008/+0x6C00C and a pending counter at this+0; entries are drained through centralMessageEventDispatch and advanced through the blob-copy utility. The three pointer-manipulating functions share this base with consistent semantics.

Methods: `0x004B3AF0`, `0x004B3B30`, `0x004B3B40`

- `this+0x00000000` `int32 pending_count` (read_write, DERIVED)
- `this+0x0006C004` `void* end_ptr` (read_write, DERIVED)
- `this+0x0006C008` `void* current_ptr` (read_write, DERIVED)
- `this+0x0006C00C` `void* read_ptr` (read_write, DERIVED)

### BinaryRecordCopier

Copies a variable-length binary blob whose byte count is derived from a 10-bit size field in bits 8-17 of the source header plus 8 bytes, then copies a dword at offset 0x1AC. Used by the ring buffer entry path and many per-frame callers.

Methods: `0x004B3A90`

- `this+0x000001AC` `int32 copied_dword` (read_write, GUESS)

### NoiseTable

Opaque float buffer initialized as a 514-entry noise table by a __thiscall initializer; the table layout (entry 0 zero, [0,1) and [-1,1) fills, RDTSC tail entry) is not independently corroborated.

Methods: `0x004B3BD0`

- `this+0x00000000` `float[514] noise_entries` (write, GUESS)

### RenderState

Render subsystem state: a 0x68-byte block filled by the restart routine; RenderInit is a free startup routine grouped here only by the shared debug-gate pattern and ABI lead names. The fill pattern 0x01 and return value 16843009 are unexplained.

Methods: `0x004B4030`, `0x004B4060`


### ModelSceneFileSerialization

Model-scene record framing: framed string-record writer, header reader that validates and dispatches a 10-bit operation id, and a fixed-format binary-block writer, all driven by ModelSceneFileLoader through a common file-write backend. The on-disk field semantics are largely unnamed; the record's fixed regions (at +65/+97/+132/+136) are not promoted to class fields because no allowed field evidence ref covers those base/offset pairs.

Methods: `0x004B4250`, `0x004B43E0`, `0x004B5040`


### CleanupRegistry

Registration hook over a cleanup-routine function pointer; the canonical/abi name suggests cleanup registration (LEGACY trust) but the target routine has no packet evidence describing its behavior.

Methods: `0x004B45E0`


### FloatBoundsFilter

Float range predicate over an object carrying a lower bound at +0x84 and an upper bound at +0x88, with a -1.0e32 sentinel disabling either side; used as the acceptance criterion while walking slot lists.

Methods: `0x004B50C0`

- `this+0x00000084` `float lower_bound` (read, DERIVED)
- `this+0x00000088` `float upper_bound` (read, DERIVED)

### SlotListRegistry

Container with 104 per-slot list records (16 bytes each) at this+0x40 and an output list at this+0x10; drains slot nodes (reinitializing data and allocating fresh 12-byte wrappers) into the output list, and indexes slot records to walk for a filter-accepted node. The stride-16 slot array base at this+0x40 is shared by both methods.

Methods: `0x004B5E50`, `0x004B72A0`

- `this+0x00000010` `void* output_head` (read_write, DERIVED)
- `this+0x00000014` `void* output_tail` (read_write, DERIVED)
- `this+0x00000018` `void* output_current` (read_write, DERIVED)
- `this+0x0000001C` `int32 output_count` (read_write, DERIVED)
- `this+0x00000040` `SlotRecord[104] {head,tail,current,count}, stride 16 slot_records` (read_write, DERIVED)

### ListTransferStation

Container draining a doubly-linked source list (this+0x714..+0x720) into a singly-linked output list (this+0x30..+0x3C), freeing source nodes and reinitializing data before prepending fresh 12-byte wrappers.

Methods: `0x004B5F60`

- `this+0x00000030` `void* output_head` (read_write, DERIVED)
- `this+0x00000034` `void* output_tail` (read_write, DERIVED)
- `this+0x00000038` `void* output_current` (read_write, DERIVED)
- `this+0x0000003C` `int32 output_count` (read_write, DERIVED)
- `this+0x00000714` `void* source_head` (read_write, DERIVED)
- `this+0x00000718` `void* source_tail` (read_write, DERIVED)
- `this+0x0000071C` `void* source_current` (read_write, DERIVED)
- `this+0x00000720` `int32 source_count` (read_write, DERIVED)

### SlotListNode

12-byte node wrapper used by the slot-list container: data pointer at +0, next link at +4, flag byte at +8; +0xC is flagged as read by the packet facts but never appears in the rendered pseudocode. Base is the node object reached via *(this+0x40).

Methods: 

- `*(this+0x40)+0x00000000` `void* data_ptr` (read_write, DERIVED)
- `*(this+0x40)+0x00000004` `void* next` (read_write, DERIVED)
- `*(this+0x40)+0x00000008` `uint8 flag_byte` (read_write, DERIVED)
- `*(this+0x40)+0x0000000C` `int32 reserved_word` (read, GUESS)

### DoublyLinkedNode

16-byte doubly-linked node wrapper used by the source list of LinkedBufferTransfer: data at +0, next at +4, prev at +8, flag at +0xC. Base is the node object reached via *(this+0x718); the nested field refs describe the successor's prev and the predecessor's next relinking.

Methods: 

- `*(this+0x718)+0x00000000` `void* data_ptr` (read_write, DERIVED)
- `*(this+0x718)+0x00000004` `void* next` (read_write, DERIVED)
- `*(this+0x718)+0x00000008` `void* prev` (read_write, DERIVED)
- `*(this+0x718)+0x0000000C` `uint8 flag_byte` (read, DERIVED)

## Compatibility contracts

- **FramedEventRecordHeader** — A framed event record begins with a 32-bit header: bits 29-31 carry the major type, bits 18-23 the sub-type, bits 8-17 a 10-bit size or operation id, and the low byte a vehicle index bounded below 0x68. Handlers must parse this layout before payload access; the central dispatcher routes on it.
- **RingBufferEntryStride** — The ring buffer uses fixed 432-byte (0x6C0) entries with a pending counter at this+0, an end/limit pointer at this+0x6C004, a current pointer at this+0x6C008 and a read pointer at this+0x6C00C; draining resets all three pointers to base+4.
- **ModelSceneRecordFraming** — Model-scene records are framed as a 4-byte header plus a 1-byte length plus a zero-padded payload plus trailing fixed regions (32/32/4/4 bytes at +65/+97/+132/+136). The header validity tag is bits 29-31 == 0x20000000 with bits 17-22 zero; valid headers dispatch operation id+1, invalid ones dispatch the raw id.
- **SlotRecordArrayLayout** — Containers with per-slot lists keep 104 slot records of 16 bytes starting at this+0x40; each record is {head, tail, current, count} and the slot head is copied to the slot current at iteration start. A 12-byte node wrapper holds {data, next, flag}.
- **VehicleSlotStateGating** — Event dispatch is gated on the target vehicle slot's state: value 2 (active) gates vehicle-input and AI handling, value 2 or 3 gates lap completion; slot state 3 is written to the grid-adjacent dword_5F073C array entry.

## Unresolved

- The exact semantics of FAILWRONGTRIAGECATEGORY (0x004C22A0) and sub_4B0C00 (0x004B0C00) are not evidenced within this packet.
- The PlayerFileSession object identity is a GUESS grouping: the packet does not prove that F_5StepInit, SettingsFileInit, PlayerFileEnter, PlayerFileSetup and NoPlayerStringFlagSetter share one `this` base; the dual-list target at byte 0x4918 is unidentified.
- RaceSessionParameters, PathRegistry and PhysicsPathBuilder may all be faces of one large session object; common ownership is not proven, so their fields are kept on separate GUESS classes and must not be merged on offset equality alone.
- The name/path metadata (F_5StepInit, the structural twin to MemoryAllocation_5160, Settings_File_Init, and the word_5C32D8 .HOT extension reading) is DERIVED prelabel metadata, not evidenced by the raw bodies.
- Global byte_5EA438 serves as a default path/string fallback across many functions; its producer and exact content are unverified.
- Thirteen globals listed for centralMessageEventDispatch do not appear in its raw body (jump-table neighbors and float constants); their role here is unverified.
- The entry field at this+0x18 is listed as read by centralMessageEventDispatch but no access appears in the raw body; it is likely read inside a callee such as LapCompletion or PitTimerStateInit.
- dword_8AD3B4 appears in the packet global list for IndexedNameExtractorWithGameFilterAppend but is not referenced by its raw source.
- flt_59E43C is listed as read by RandomNoiseTableInitialization but only two scale constants appear in its raw body; the scale-literal pairing is DERIVED only.
- flt_59E440, flt_59E448, flt_59E450 and unk_8AC368 are listed as read by RaceSessionParameterLoader but have no visible role in its source.
- flt_5ACD10 is listed as read by UtilityFunction_50c0 but does not appear in its raw source.
- The 0x68-byte render-state object memset by Render_Restart has no accessed fields; the 0x01 fill pattern and the return value 16843009 are unexplained.
- Ring-buffer capacity ((end - start) / 432) and the owning object's identity are unknown; the 432-byte entry layout is not evidenced.
- LinkedBufferTransfer's source node and output wrapper have different layouts (data/next/prev/flag versus 12-byte data/next/flag), so node+8 is the prev link in the source list but the flag byte in the output wrapper.
- LinkedListTraversalWithFilter uses an unassigned v7 in its loop body; the next-node advancement and relink are a decompiler artifact, so the real node layout is uncertain.
- The exact effect of attribute mask 128 in ToggleFileReadOnlyAttributeViaWin32API (likely FILE_ATTRIBUTE_NORMAL) is not established from this packet.
- The semantic intent behind the differing race-laps scaling (floor of 1) versus race-time scaling (round via +0.5) is inferred, not evidenced.
