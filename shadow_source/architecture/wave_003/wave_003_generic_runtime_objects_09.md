# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 24 validated functions in scope generic_runtime_objects. Two packet-DERIVED owners anchor classes: AudioChannel (0x0045D530 constructor, ~112KB struct) and SessionManager (0x00460470 SendServerOKRequest; 0x00460520 SetSelfAsReady, 0x0045EB50 NodeIDToPlayerNameLookup, 0x0045D500 GuardedInitCall and 0x0045CF50 network-session display formatter grouped under it as GUESS by shared session-phase field this+0x3FC4 / session-type globals). The remaining UNKNOWN-owner functions are grouped conservatively by shared structure: SessionMessageListManager (two linked lists at this+0x1B770 and this+0x1B780, head/tail/iterator/count), TextLineRegistry (fixed-size text-line record pool), FileScanner (directory-entry list populate + scene-file name match, shared head/tail at this+0x4/this+0x8), ParserDispatcherObject (selector byte at this+1 driving UtilityFunction_8a60), FloatShortConverter (two scaled 16-bit conversions), RenderableSceneObjectConfig (parsed config block written to this+0x30..0x98), and a GenericRuntimeObject catch-all for the remaining single-purpose helpers. Interfaces capture the token-parser dispatch, the zero-on-match string compare (sub_588410), the text-line record sink, the BooleanToIntConversion helper and the debug-log sink.

## Function roles

- `0x004585E0` **RenderableSceneObjectConfig** — parseRenderableObjectConfig: parses a named config block for a renderable scene object / environment effect from a tokenised source. ConditionalDispatchBasedOnFlag(v60, 384) gates the token loop (sub_5651B0 advance, sub_565870 float/vector tokens, sub_565760 integer tokens, sub_565520 string tokens) against a hardcoded-defaults path; reads known keys (Position, Orientation, Color, Clipplanes, Lodmultiplier, Size, Center, Mipmaplodbias, Flags1, Flags2, Clear, Activationlocation, Activationradius, Trackingrate, Movementrate, Movementpath) and writes the assembled config into this+0x30..0x98 with a 100.0 default radius; movement path at this+176 (0xB0) parsed by 0x00458050; called from MainView.
- `0x00459990` **GenericRuntimeObject** — SetSixFieldsFromArgs: trivial bulk setter writing six arguments a2..a7 into six consecutive dword fields this[10]..this[15] (byte offsets 0x28..0x3C) and returning a6 (the value stored into this[14]).
- `0x0045B310` **GenericRuntimeObject** — AtexitStyleCleanupRegistration: zero-argument wrapper taking the address of data object unk_45B320 and passing it as the single argument to BooleanToIntConversion (0x00587B3E), returning that helper's integer result. Atexit/cleanup-registration semantics are LEGACY-trust only; no caller or side-effect evidence exists in the packet.
- `0x0045B9C0` **TextLineRegistry** — RegisterTextLineEntry: registers or reuses a fixed-size text-line record. Rejects empty keys (0), dedups via StringArrayComparisonSearch (0x0045B480), finds a free slot with RotatingIndexSearchWithThreshold (0x0045B500), resets it with PerIndexStructFieldResetter (0x0045B430), copies the key (sub_587DD0, 79-byte cap at record+60, NUL at +139), stores a5/a3/a4 at +148/+140/+144. On the frame path; invoked by TextLineWrappingAndRendering.
- `0x0045BC10` **GenericRuntimeObject** — StringFormatWrapper: formats a label prefix into a caller-provided buffer and forces null termination. Null prefix a1 substitutes the global byte_5EA438; StringFormatProcessingWithNullTerm (0x0058969D) writes '%s: ' (global 0x005C5B60), last buffer byte forced to 0; returns true iff the format call returned non-negative.
- `0x0045BDE0` **GenericRuntimeObject** — StringMatchWrapper: thin __thiscall wrapper loading the pointer at field 0x0 of this and forwarding it with a string a2 and a char flag a3 to a case-sensitive/case-insensitive string matching routine. No result produced here; the matcher address is not in the packet callee list.
- `0x0045BDF0` **GenericRuntimeObject** — ShortComputation_bdf0: thiscall circular-buffer full reset. Dereferences this to obtain buffer object v3, resets the write cursor at byte offset 0x31C (v3[199]) to 0, then iterates eight entries calling PerIndexStructFieldResetter(v3, index); returns the last resetter result. Used as an init/full-flush path by AIShiftPattern, BrakeBiasAdjustmentControl, OnScreen_Restart and PitTimer.
- `0x0045BF60` **GenericRuntimeObject** — CallbackRegistrationForCleanup: zero-argument wrapper taking the address of function sub_45BF70 and passing it as the single argument to BooleanToIntConversion (0x00587B3E), returning that helper's integer result. Cleanup-callback registration semantics are LEGACY-trust only; no caller or side-effect evidence exists in the packet.
- `0x0045C030` **GenericRuntimeObject** — ResetDefaults: initializer zeroing twelve DWORD fields at this+0x8..0x34, then writing float constants 10.0 (0x4... 1092616192) at this+0x0 and 6.325 (1087006310) at this+0x4; returns 0. Called by NetCommPlayerSlotSync (0x0045FC50), consistent with resetting per-player slot state.
- `0x0045C0C0` **FileScanner** — FileScannerPopulate: iterates directory entries from the global iterator list at 0x008AD3B0, builds a full path for each ('%s%s', format 0x005BE860), dispatches to a filter check selected by a4 (0x0045C400 for 1, 0x0045C650 for 2, or UtilityFunction_8a60 via mode byte this+1), trims to the final path component, and appends accepted entries as 12-byte linked-list nodes (data at +0, next at +4, flag byte at +8) to the caller struct whose head/tail live at this+4/this+8 with cached tail this+0xC and count this+0x10. Returns the last iterated entry pointer.
- `0x0045C320` **FileScanner** — SceneFileMatchByName: searches a linked list of scene-file entries for a node whose name matches the filename portion of path a2. Initializes an iterator at this+0xC from list head this+0x4, compares each node's string pointer (fallback global byte_5EA438) against the path filename via sub_588410 (0 = match); on match writes node data at +8 to output a3 and returns 1, else sets a3=0 and returns 0.
- `0x0045C3D0` **ParserDispatcherObject** — ParserDispatchWrapper: dispatches a parameter parse using the selector byte at this+1, calling UtilityFunction_8a60(this[1], a3); returns 1 on success, zeroes *a3 and returns 0 on failure. Called by ParticleSoundEffectSpawner (0x004607A0).
- `0x0045C650` **ParserDispatcherObject** — DataFileCheckSizeQuery: data-file size query. Optionally adds a value extracted by UtilityFunction_8a60 using the selector byte at this+0x1, copies the input path into a bounded buffer, strips a trailing '.' extension, then scans the global array dword_8AC490 (stride 396, entry count dword_8AC488) for an entry whose name at offset 4 matches; on match adds the entry's size field at offset 392 to the accumulator. Returns a success flag. Scene-descriptor interpretation is DERIVED from prior analysis, not proven here.
- `0x0045C7A0` **FloatShortConverter** — FloatToShortViaFtol: converts a float to a 16-bit unsigned value: scales input by flt_59E450 (~999.99994) plus rounding offset flt_59F0BC (~0.5), converts via CRTFtol (0x00587BDC), stores through output word pointer a2 and returns the raw integer conversion.
- `0x0045C7C0` **FloatShortConverter** — ShortToFloatConversion: converts a 16-bit signed value a1 into a float scaled by 0.001 (flt_59E600) stored through output pointer a2, and returns the sign-extended integer form of a1. Used on terrain roughness/height sampling paths.
- `0x0045CF50` **SessionManager** — SceneTextureApply (name conflicts with body): builds a formatted network session display string - hostname, host port, map name, player count, max players, game mode (open/closed). Validates the network entrant via NetworkEntrantSetupWithIDCheck (0x004627C0); each field is emitted as a key-value pair through ShortComputation_ce30 (0x0045CE30) with this as the output context. Map name from the current scene entry (dword_8AC490 + 396*dword_8AC48C) via EventNameReader (0x004C5900), session-open state via SingleFunctionCallWrapper_2a00 (0x00462A00) on dword_7CD25C; cleanup via EmptyStub_0170 (0x004B0170).
- `0x0045D500` **SessionManager** — GuardedInitCall: conditional initialization wrapper reading the global byte_7CE260; when zero it calls BooleanFlagResetWithSideEffects(this) and returns that call's result, otherwise returns the non-zero flag unchanged. ABI lead: Call_init_function_if_global_flag_is_zero. Only known caller is SessionStateByte7CE25FSetter (0x00464600).
- `0x0045D530` **AudioChannel** — AudioChannelInit: one-time construction of an AudioChannel object (struct size ~112KB). Runs FAILWRONGDESCRIPTION (0x00461550), zeroes/invalidates core handle fields (this+0xB4..0xC0, this+0x1AC), initializes two arrays of 104 sub-objects (140-byte stride via ThunkToFUN00461480 0x00461470; 872-byte stride via PassthroughWrapper_f670 0x004FF670), stores interface pointer off_59F0CC at this+0x3FBC, runs WrapperWithConstant (0x0045C750), ZeroInit5FloatStruct (0x0045C0A0), StructInitializer_cd50 (0x0045CD50), fills the leading buffer with 0xFFFFFFFF (0x0045E590), writes default timing/gain values (1/24 sample-rate divisor, 15.0/15.0 gain pair, 30.0, -1.0 sentinel), stores the owner handle from a2 at this+0x0 and returns this.
- `0x0045EB50` **SessionManager** — NodeIDToPlayerNameLookup: __thiscall lookup of a player-name string by node ID in a session player array. Reads the active entry count from this[3973] (offset 0x3E14), linearly searches the node-ID array at this + 3869 (offset 0x3C74) for a2, and on a match returns the name entry pointer &this[35*v3 + 230]. On failure returns the empty name asc_5C5DBC and optionally logs a 'could not find name' debug message (gated on dword_7C569C != 5). Called from NetCommSessionMessageDispatcher.
- `0x0045EBD0` **SessionMessageListManager** — LinkedListPurgeByThreshold: purges excess nodes from a linked list once its count (this+0x1B77C) exceeds 64. Computes purge_count = count - 64 and removes that many nodes from the head, unlink-fixing head (this+0x1B770), iterator (this+0x1B774), tail (this+0x1B778) and count, freeing each node (and its data when the node's +8 flag is set) via FreeWrapper_7bcf (0x00587BCF). Invoked from NetCommSessionMessageDispatcher.
- `0x0045ECD0` **SessionMessageListManager** — AutoChatSpeechDataLoader: loads auto-chat speech data from an audio stream file into a manager-held linked list. Frees any existing autochat list (head this+0x1B780, tail this+0x1B784, first-inserted backup this+0x1B788, count this+0x1B78C), rebuilds the stream file name from the current directory plus a constant suffix (globals 0x005C5E60..0x005C5E70), opens the stream (0x00566B20), scans chunks (0x00566CC0 / 0x005651B0) and for each chunk whose label matches one of autochat01..autochat10 (0x005C5DE8..0x005C5E54) builds a (label buffer, list node) pair appended to the list, stopping at 10 entries. Called by SessionTypeSetter (0x00463F70).
- `0x00460470` **SessionManager** — SendServerOKRequest: sends the server OK/ready request for the current session object. When the session phase stored at this+0x3FC4 is in the active range 1-2, marks the session ready via NetComm_SetSelfAsReady(-1) (0x00460520); otherwise encodes a progress-bar event (type 4, subtype 3) with session time dbl_8AFEA0 (0x004B33B0), creates the OK-indication texture (0x00462250), and when session type dword_7C569C is not 5 writes a 'sending server overflow' debug message. Called by SessionScoringUpdate.
- `0x00460520` **SessionManager** — SetSelfAsReady (NetComm_SetSelfAsReady): updates session readiness flags on the object, assigns a free slot via array search (0x0045E5B0) when the session phase this[4081] (0x3FC4) is active (1 or 2) and no slot is yet assigned, records the caller-provided or searched slot, manipulates bitfield flags via BitfieldSetClearAt0x88 (0x004614F0), and emits source-gated debug log messages (StringSplitLoop 0x004D7A50 / DebugLogWrite 0x004D7AA0). Wrapped in a local state buffer (0x00461470 / 0x004623E0) torn down via ShortComputation_23b0 (0x004623B0) and EmptyStub_0170 (0x004B0170). Invoked by NetCommSessionMessageDispatcher (0x0045D890) and SendServerOKRequest (0x00460470).
- `0x00460770` **GenericRuntimeObject** — HashChecksumComputation: computes an affine hash checksum from two byte inputs, the global seed dword_7C56B8 and two constants: 304444136*a1 - 79767*a2 + dword_7C56B8 + 468717489; result returned as int.

## Proposed classes

### RenderableSceneObjectConfig

GUESS config object for a renderable scene object / environment effect, populated by parsing a named token block (0x004585E0). Holds orientation/clip-plane floats, near/far planes, LOD/size/center floats, a clear-enable byte, color integers, flags/counters, an activation radius (default 100.0) and its square, and position integers; the assembled values are written into this+0x30..0x98 with a movement path parsed into this+0xB0.

Methods: `0x004585E0`

- `this+0x00000030` `float clipPlaneFloat_30` (write, DERIVED)
- `this+0x00000034` `float clipPlaneFloat_34` (write, DERIVED)
- `this+0x00000038` `float clipPlaneFloat_38` (write, DERIVED)
- `this+0x0000003C` `float clipPlaneFloat_3C` (write, DERIVED)
- `this+0x00000040` `float nearPlane` (write, DERIVED)
- `this+0x00000044` `float farPlane` (write, DERIVED)
- `this+0x00000048` `float lodMultiplier` (write, DERIVED)
- `this+0x0000004C` `float lodField_4C` (write, DERIVED)
- `this+0x00000050` `float sizeFloat_50` (write, DERIVED)
- `this+0x00000054` `float sizeFloat_54` (write, DERIVED)
- `this+0x00000058` `float centerFloat_58` (write, DERIVED)
- `this+0x0000005C` `float centerFloat_5C` (write, DERIVED)
- `this+0x00000060` `byte clearEnableByte` (write, DERIVED)
- `this+0x00000064` `int colorInt_64` (write, DERIVED)
- `this+0x00000068` `int colorInt_68` (write, DERIVED)
- `this+0x0000006C` `int colorInt_6C` (write, DERIVED)
- `this+0x00000070` `int flagsFixedTo2` (write, DERIVED)
- `this+0x00000074` `int flagCounter_74` (write, DERIVED)
- `this+0x00000078` `int flagCounter_78` (write, DERIVED)
- `this+0x0000007C` `int flagCounter_7C` (write, DERIVED)
- `this+0x00000080` `int flagCounter_80` (write, DERIVED)
- `this+0x00000084` `int flagCounter_84` (write, DERIVED)
- `this+0x00000088` `float activationRadius` (write, DERIVED)
- `this+0x0000008C` `float activationRadiusSquared` (write, DERIVED)
- `this+0x00000090` `int positionInt_90` (write, DERIVED)
- `this+0x00000094` `int positionInt_94` (write, DERIVED)
- `this+0x00000098` `int positionInt_98` (write, DERIVED)

### AudioChannel

Large (~112KB) audio channel object constructed once by 0x0045D530: two arrays of 104 sub-objects (140-byte and 872-byte strides), an interface pointer at this+0x3FBC, default timing/gain state (1/24 sample-rate divisor, 15.0/15.0 gain pair, 30.0, -1.0 sentinels, enabled flag at +0x29), a leading buffer filled with 0xFFFFFFFF, and flag/list-header regions zeroed during construction.

Methods: `0x0045D530`

- `this+0x00000000` `int ownerHandle` (write, DERIVED)
- `this+0x00000004` `float sampleRateDivisor` (write, DERIVED)
- `this+0x00000008` `int field_08` (write, DERIVED)
- `this+0x0000000C` `float defaultGain` (write, DERIVED)
- `this+0x00000010` `float ceilingGain` (write, DERIVED)
- `this+0x00000014` `int stateDword_14` (write, DERIVED)
- `this+0x00000018` `int stateDword_18` (write, DERIVED)
- `this+0x0000001C` `int stateDword_1C` (write, DERIVED)
- `this+0x00000020` `int stateDword_20` (write, DERIVED)
- `this+0x00000021` `byte stateFlagByte_21` (write, DERIVED)
- `this+0x00000024` `float defaultValue_24` (write, DERIVED)
- `this+0x00000028` `int field_28` (write, DERIVED)
- `this+0x00000029` `byte enabledFlag` (write, DERIVED)
- `this+0x0000002C` `float sentinelMinusOne` (write, DERIVED)
- `this+0x00000030` `int field_30` (write, DERIVED)
- `this+0x000000B4` `int handleField_B4` (write, DERIVED)
- `this+0x000000B8` `int invalidHandleSentinel_B8` (write, DERIVED)
- `this+0x000000BC` `int handleField_BC` (write, DERIVED)
- `this+0x000000C0` `int invalidHandleSentinel_C0` (write, DERIVED)
- `this+0x000000C4` `byte flagByte_C4` (write, DERIVED)
- `this+0x000000C5` `byte flagByte_C5` (write, DERIVED)
- `this+0x000000C6` `byte flagByte_C6` (write, DERIVED)
- `this+0x000000C7` `byte flagByte_C7` (write, DERIVED)
- `this+0x000000C8` `byte flagByte_C8` (write, DERIVED)
- `this+0x0000011C` `int field_11C` (write, DERIVED)
- `this+0x0000016C` `int field_16C` (write, DERIVED)
- `this+0x000001AC` `int invalidHandleSentinel_1AC` (write, DERIVED)
- `this+0x000001B0` `int field_1B0` (write, DERIVED)
- `this+0x000001D0` `int field_1D0` (write, DERIVED)
- `this+0x00000374` `byte flagBlock_374` (write, DERIVED)
- `this+0x00000378` `int flagBlock_378` (write, DERIVED)
- `this+0x0000037C` `int flagBlock_37C` (write, DERIVED)
- `this+0x00000380` `int flagBlock_380` (write, DERIVED)
- `this+0x00000384` `int flagBlock_384` (write, DERIVED)
- `this+0x00000388` `int flagBlock_388` (write, DERIVED)
- `this+0x0000038C` `int flagBlock_38C` (write, DERIVED)
- `this+0x00000390` `int flagBlock_390` (write, DERIVED)
- `this+0x00003E14` `int countField_3E14` (write, DERIVED)
- `this+0x00003FB8` `int interfaceField_3FB8` (write, DERIVED)
- `this+0x00003FBC` `pointer interfacePtr` (write, DERIVED)
- `this+0x00003FC0` `int interfaceField_3FC0` (write, DERIVED)
- `this+0x00003FC4` `int phaseField_3FC4` (write, DERIVED)
- `this+0x00003FC8` `int interfaceField_3FC8` (write, DERIVED)
- `this+0x00003FCC` `int interfaceField_3FCC` (write, DERIVED)
- `this+0x00003FD0` `int interfaceField_3FD0` (write, DERIVED)
- `this+0x00003FD4` `int interfaceField_3FD4` (write, DERIVED)
- `this+0x00003FD8` `byte byte_3FD8` (write, DERIVED)
- `this+0x00003FD9` `byte byte_3FD9` (write, DERIVED)
- `this+0x0001B768` `byte listRegion_1B768` (write, DERIVED)
- `this+0x0001B769` `byte listRegion_1B769` (write, DERIVED)
- `this+0x0001B76A` `byte listRegion_1B76A` (write, DERIVED)
- `this+0x0001B76B` `byte listRegion_1B76B` (write, DERIVED)
- `this+0x0001B76C` `byte listRegion_1B76C` (write, DERIVED)
- `this+0x0001B76D` `byte listRegion_1B76D` (write, DERIVED)
- `this+0x0001B76E` `byte listRegion_1B76E` (write, DERIVED)

### SessionManager

GUESS session/netcomm manager grouping functions that share the session-phase field this+0x3FC4 (SendServerOKRequest packet-DERIVED, SetSelfAsReady), the session player-array layout (this+0x3C74 node-ID array, this+0x3E14 count, name records), the readiness flag (dword_7D0E50), and the session-type global dword_7C569C; also hosts the session display-string formatter (0x0045CF50) and the flag-gated init wrapper (0x0045D500).

Methods: `0x0045CF50`, `0x0045D500`, `0x0045EB50`, `0x00460470`, `0x00460520`

- `this+0x00003C74` `array_of_int nodeIDArray` (read, DERIVED)
- `this+0x00003E14` `int entryCount` (read, DERIVED)
- `this+0x00003FB8` `int interfaceArg` (read, DERIVED)
- `this+0x00003FC4` `int sessionPhase` (read_write, DERIVED)

### SessionMessageListManager

GUESS session message/autochat list holder: maintains two adjacent linked lists at this+0x1B770 (head/iterator/tail/count at +0x1B770/+0x1B774/+0x1B778/+0x1B77C) and this+0x1B780 (head/tail/first-inserted-backup/count at +0x1B780/+0x1B784/+0x1B788/+0x1B78C); nodes carry data at +0, next at +4 and an owns-data flag byte at +8. 0x0045EBD0 purges nodes over a 64-entry threshold, 0x0045ECD0 loads up to 10 autochat speech entries from an audio stream.

Methods: `0x0045EBD0`, `0x0045ECD0`

- `this+0x0001B770` `pointer messageListHead` (read_write, DERIVED)
- `this+0x0001B774` `pointer messageListIterator` (read_write, DERIVED)
- `this+0x0001B778` `pointer messageListTail` (read_write, DERIVED)
- `this+0x0001B77C` `int messageListCount` (read_write, DERIVED)
- `this+0x0001B780` `pointer autochatListHead` (read_write, DERIVED)
- `this+0x0001B784` `pointer autochatListTail` (read_write, DERIVED)
- `this+0x0001B788` `pointer autochatFirstBackup` (read_write, DERIVED)
- `this+0x0001B78C` `int autochatEntryCount` (read_write, DERIVED)
- `*(this+0x1B770)+0x00000000` `pointer messageNodeDataPtr` (read, DERIVED)
- `*(this+0x1B774)+0x00000000` `pointer iteratorNodeDataPtr` (read, DERIVED)
- `*(this+0x1B780)+0x00000000` `pointer autochatNodeDataPtr` (read, DERIVED)
- `*(this+0x1B784)+0x00000004` `pointer autochatNodeNextPtr` (read, DERIVED)

### TextLineRegistry

GUESS pool of fixed-size text-line records managed by 0x0045B9C0 on the frame path: each record holds a 79-byte key (NUL-terminated at +139) plus three dword parameters at +140/+144/+148 (per source text; no packet field evidence), a rotating index search finds free slots, a string-array search dedups keys, and a per-index resetter clears reused slots. Record stride and element count are not established by the packet.

Methods: `0x0045B9C0`


### FileScanner

GUESS directory/file scanner: 0x0045C0C0 populates a linked list of accepted file entries (head/tail at this+0x4/this+0x8, cached tail this+0xC, count this+0x10, mode byte this+1) from a global directory iterator, and 0x0045C320 searches that list by filename. Node layout: data at +0, next at +4; the populate path adds an owns-data flag byte at +8.

Methods: `0x0045C0C0`, `0x0045C320`

- `this+0x00000001` `byte filterModeByte` (read, DERIVED)
- `this+0x00000004` `pointer listHead` (read_write, DERIVED)
- `this+0x00000008` `pointer listTail` (read_write, DERIVED)
- `this+0x0000000C` `pointer tailCacheOrIterator` (read_write, DERIVED)
- `this+0x00000010` `int entryCount` (write, DERIVED)
- `*(this+0x8)+0x00000004` `pointer tailNodeNextPtr` (write, DERIVED)
- `*(this+0xC)+0x00000008` `pointer matchedNodeDataPtr` (read, DERIVED)

### ParserDispatcherObject

GUESS small dispatcher object whose selector byte at this+1 selects a shared parser/extractor (UtilityFunction_8a60 0x00568A60): 0x0045C3D0 runs a single parameter parse and zeroes the output on failure, 0x0045C650 additionally performs a data-file size query over the scene-descriptor array dword_8AC490 (stride 396, name at +4, size at +392).

Methods: `0x0045C3D0`, `0x0045C650`

- `this+0x00000001` `byte selectorByte` (read, DERIVED)

### FloatShortConverter

GUESS pair of scaled 16-bit conversions: 0x0045C7A0 scales a float by ~999.99994 plus ~0.5 rounding offset and stores the ftol-converted 16-bit result through an out pointer; 0x0045C7C0 scales a signed short by 0.001 into a float out pointer. Both return the raw integer form. Used on terrain roughness/height sampling paths.

Methods: `0x0045C7A0`, `0x0045C7C0`


### GenericRuntimeObject

GUESS catch-all for the remaining single-purpose runtime helpers with UNKNOWN packet owners: the six-field bulk setter (0x00459990), two BooleanToIntConversion registration wrappers (0x0045B310, 0x0045BF60), the label-prefix format wrapper (0x0045BC10), the string-match forwarder (0x0045BDE0), the circular-buffer full reset (0x0045BDF0), the per-player-slot defaults reset (0x0045C030) and the affine hash checksum (0x00460770). Each operates on its own small this-layout (or none); fields are kept separate because the packet does not prove common ownership.

Methods: `0x00459990`, `0x0045B310`, `0x0045BC10`, `0x0045BDE0`, `0x0045BDF0`, `0x0045BF60`, `0x0045C030`, `0x00460770`

- `this+0x00000000` `pointer storedStringPtr` (read, DERIVED)
- `this+0x00000000` `pointer bufferObjectPtr` (read, DERIVED)
- `obj+0x0000031C` `int writeCursor` (write, DERIVED)
- `this+0x00000000` `float defaultValue_10_0` (write, DERIVED)
- `this+0x00000004` `float defaultValue_6_325` (write, DERIVED)
- `this+0x00000008` `int zeroedDword_08` (write, DERIVED)
- `this+0x0000000C` `int zeroedDword_0C` (write, DERIVED)
- `this+0x00000010` `int zeroedDword_10` (write, DERIVED)
- `this+0x00000014` `int zeroedDword_14` (write, DERIVED)
- `this+0x00000018` `int zeroedDword_18` (write, DERIVED)
- `this+0x0000001C` `int zeroedDword_1C` (write, DERIVED)
- `this+0x00000020` `int zeroedDword_20` (write, DERIVED)
- `this+0x00000024` `int zeroedDword_24` (write, DERIVED)
- `this+0x00000028` `int sixFieldGroup_28` (write, DERIVED)
- `this+0x0000002C` `int sixFieldGroup_2C` (write, DERIVED)
- `this+0x00000030` `int sixFieldGroup_30` (write, DERIVED)
- `this+0x00000034` `int zeroedDword_34` (write, DERIVED)
- `this+0x00000038` `int sixFieldGroup_38` (write, DERIVED)
- `this+0x0000003C` `int sixFieldGroup_3C` (write, DERIVED)

## Compatibility contracts

- **RenderableSceneObjectConfigLayout** — parseRenderableObjectConfig (0x004585E0) parses a token block gated by ConditionalDispatchBasedOnFlag (0x00566CC0) over a 384-byte buffer, reads named tokens (Position, Orientation, Color, Clipplanes, Lodmultiplier, Size, Center, Mipmaplodbias, Flags1, Flags2, Clear, Activationlocation, Activationradius, Trackingrate, Movementrate, Movementpath - string globals 0x005C5798..0x005C5AD8), and writes the assembled config into this+0x30..0x98: orientation/clip-plane floats at +0x30..0x3C, near/far plus LOD/size/center at +0x40..0x5C, clear-enable byte at +0x60, colors at +0x64..0x6C, flags/counters at +0x70..0x84 (+0x70 fixed to 2), radius 100.0 at +0x88 with its square at +0x8C, position at +0x90/0x94/0x98, and a movement path parsed by 0x00458050 into this+0xB0. A replacement must preserve the token names, defaults (100.0 radius, 1.0 LOD multiplier) and this field layout.
- **AudioChannelInitialization** — AudioChannelInit (0x0045D530) constructs a ~112KB object: stores the owner handle at this+0x0, writes timing/gain defaults (1/24 sample-rate divisor at +0x4, 15.0/15.0 gain pair at +0xC/+0x10, 30.0 at +0x24, enabled byte at +0x29, -1.0 sentinel at +0x2C), invalidates handles with -1 at +0xB8/+0xC0/+0x1AC, stores the interface pointer off_59F0CC at +0x3FBC, fills the leading buffer with 0xFFFFFFFF (0x0045E590), and initializes two arrays of 104 sub-objects (140-byte stride via 0x00461470, 872-byte stride via 0x004FF670). A replacement must reproduce the default constants, handle sentinels and array strides.
- **SessionPhaseBitfieldContract** — The netcomm readiness path keys on the session-phase field this+0x3FC4: SendServerOKRequest (0x00460470) marks the session ready via NetComm_SetSelfAsReady(-1) when the phase is in the active range 1..2, otherwise encodes a progress-bar OK event (0x004B33B0, type 4 subtype 3) with session time dbl_8AFEA0 and creates the OK texture (0x00462250); SetSelfAsReady (0x00460520) branches on phase !=1 (setting bitfield pair (2,1) and clearing (4,0) via 0x004614F0) and on the active branch (1 or 2) assigns a free slot via ArraySearchFor1Sentinel (0x0045E5B0). Session-type global dword_7C569C != 5 gates the debug logging. A replacement must preserve the phase encoding and flag semantics.
- **NetCommMessageListLayout** — Session message lists live in two adjacent headers at this+0x1B770 (head/iterator/tail/count) and this+0x1B780 (head/tail/first-inserted-backup/count). LinkedListPurgeByThreshold (0x0045EBD0) removes nodes while count (this+0x1B77C) exceeds 64, unlinking head/iterator/tail and freeing nodes (with their +8-flagged data) via FreeWrapper_7bcf (0x00587BCF). AutoChatSpeechDataLoader (0x0045ECD0) frees the autochat list and rebuilds it from an audio stream, appending up to 10 entries. Node layout is data@+0, next@+4, owns-data flag@+8. A replacement must preserve the list headers, the 64-entry purge threshold and the node layout.
- **SceneFileSearchContract** — FileScannerPopulate (0x0045C0C0) iterates the global directory-iterator list 0x008AD3B0, builds full paths ('%s%s' format 0x005BE860), filters entries via 0x0045C400 (a4==1), DataFileCheckSizeQuery 0x0045C650 (a4==2) or UtilityFunction_8a60 on the mode byte this+1, trims to the final path component, and appends 12-byte nodes (data@+0, next@+4, flag@+8) to a list whose head/tail are at this+4/this+8. SceneFileMatchByName (0x0045C320) searches the same list by comparing node names (node+0, fallback byte_5EA438) against the path filename via sub_588410 (0 = match), returning node data at +8. DataFileCheckSizeQuery (0x0045C650) scans the dword_8AC490 array (stride 396, name@+4, size@+392, count dword_8AC488), stripping a trailing '.' extension before the name compare. A replacement must preserve the list header offsets, node layout, scene-array stride and extension-strip rule.
- **DebugLogSink** — Session-path functions write debug messages to the buffer dword_8AD25C via DebugLogWrite (0x004D7AA0), gated by StringSplitLoop (0x004D7A50) with the source-file string global 0x005C5CE4 and the session-type guard dword_7C569C != 5. A replacement must preserve the debug-sink global and the source-file identity used for matching diagnostics.
- **PlayerSlotResetDefaults** — ResetDefaults (0x0045C030) writes float constants 10.0 at this+0x0 and 6.325 at this+0x4, zeroes this+0x8..0x34, and returns 0; it is invoked by NetCommPlayerSlotSync (0x0045FC50) as part of per-player-slot state setup. A replacement must preserve the two leading default constants and the zeroed field range.
- **FloatShortConversionScales** — FloatToShortViaFtol (0x0045C7A0) scales a float by flt_59E450 (~999.99994) plus rounding offset flt_59F0BC (~0.5), converts via CRTFtol (0x00587BDC) and stores a 16-bit result through the out pointer; ShortToFloatConversion (0x0045C7C0) scales a signed short by 0.001 (flt_59E600) into a float out pointer. A replacement must preserve the two scale constants and the ftol/out-store behavior.

## Unresolved

- parseRenderableObjectConfig (0x004585E0): tokenizer return-code semantics (sub_5651B0: 0 = more tokens, 2 = stop, 4 = end-of-stream) are inferred from control flow, not from a packet-visible callee body; the owning class is unknown (target struct spans at least 0x30..0xA8 plus movement path at +0xB0); sub_458050's movement-path storage format is unverified.
- SetSixFieldsFromArgs (0x00459990): the role and meaning of the six written fields and why a6 specifically is returned are unexplained by the packet.
- AtexitStyleCleanupRegistration (0x0045B310) / CallbackRegistrationForCleanup (0x0045BF60): atexit/cleanup-registration semantics are LEGACY-trust ABI names only; neither function has callers or side-effects in the packet, and BooleanToIntConversion's internal behavior (0x00587B3E) is not derived here.
- RegisterTextLineEntry (0x0045B9C0): PerIndexStructFieldResetter receives an uninitialized first argument (decompiler artifact or genuine quirk is unresolvable); the record stride (92) conflicts with fields at +140/+144/+148 unless the record is wider; the NUL at +139 overlaps the low byte of the a3 dword at +140, suggesting a packed string-plus-fields record whose layout is undefined here; a3/a4/a5 roles are inferred from call order.
- StringFormatWrapper (0x0045BC10): contents of byte_5EA438 are unknown (null-prefix default only); buffer ownership/max-length contract is caller-imposed.
- StringMatchWrapper (0x0045BDE0): the string-matching routine is named only in decompiled source text and has no callee evidence ref, so its address/identity are unverified; semantics of field 0x0 and flag a3 are unknown; multiple callers (PitTimer 0x004D2E50 and four sub_* functions) share no established object type.
- ShortComputation_bdf0 (0x0045BDF0): identity of the 8-entry buffer and PerIndexStructFieldResetter semantics are unproven; whether *this is the buffer itself or a container is unknown; the write-cursor reading of offset 0x31C is DERIVED from existing analysis.
- ResetDefaults (0x0045C030): meaning of the two leading float constants (10.0, 6.325) and the caller's use of the 0 return value are unknown.
- FileScannerPopulate (0x0045C0C0): sub_565F80's argument tuple and the state it establishes in the global iterator list 0x008AD3B0 are unknown; the byref check output v12 (size, handle or id) and why it is stored at v9[2] are unknown; the mode-byte role at this+1 in the fallback path is unresolved.
- SceneFileMatchByName (0x0045C320): semantics of the returned data at node +8 and of the field at this+0x10 are unknown; sub_588410 identity/behavior is assumed from the zero-on-match contract.
- DataFileCheckSizeQuery (0x0045C650): the scene-descriptor interpretation of the dword_8AC490 array and offset 392 as a file size are DERIVED, not independently proven; the UtilityFunction_8a60 extraction semantics (selector byte this+0x1) and how v10 relates to a file size are unresolved; no class-ownership evidence from callers.
- FloatToShortViaFtol (0x0045C7A0): the mapping of the two float globals to scale/rounding literals is not stated explicitly by the packet; signedness of the 16-bit out value is unspecified.
- ShortToFloatConversion (0x0045C7C0): the physical meaning of the 0.001 scale and whether callers use the integer return are unknown; the two callers are unverified-name functions.
- Session display formatter (0x0045CF50): its packet name 'SceneTextureApply' contradicts the observed body (network session display string); raw source does not reference aD_1 (0x005C3280) or unk_8AC368 (0x008AC368); the player-count bytes v12[68]/v12[69]/v12[70] derivation comes from call order, not proven fields; parameter a2 is unused; the meaning of 'this' as the ShortComputation_ce30 output context is unknown.
- GuardedInitCall (0x0045D500): BooleanFlagResetWithSideEffects identity is unknown and absent from the packet callee list; meaning of byte_7CE260 and the object type behind this are not established.
- AudioChannelInit (0x0045D530): four read-only globals (flt_59E43C, flt_59F098, dword_59F09C, dword_59F0A4) appear in packet facts but nowhere in the raw decompiled source; several callees run on sub-region pointers whose base offsets are not in the field list; the two 104-element array element semantics are not defined by this packet; the zeroed region this+0x1B768..0x1B78C overlaps the list headers used by SessionMessageListManager and this+0x3FB8/0x3FC4/0x3E14 overlap SessionManager offsets - separate bases, so common ownership is NOT proven.
- NodeIDToPlayerNameLookup (0x0045EB50): the node-ID array at this+3869 and name records at this[35*v3+230] (stride 35 dwords, base index 230) are DERIVED from prior analysis, not confirmed by a struct definition; aDDevF119992002_1's role is not established.
- LinkedListPurgeByThreshold (0x0045EBD0): node layout (data@0, next@4, +8 flag) and the owns-data semantics are DERIVED from the access pattern; threshold 64 and iterator-maintenance rules are inferred from control flow; the final return value is not meaningful.
- AutoChatSpeechDataLoader (0x0045ECD0): the autochat file-name suffix globals 0x005C5E60..0x005C5E70 and the audio stream chunk format are not verifiable here; the node+8 flag meaning is inferred; byte_7CE498 is flagged by packet globals but absent from the raw source.
- SendServerOKRequest (0x00460470): unexplained constants (NetComm_SetSelfAsReady(-1) sentinel, TextureCreationWrapper(-1,-1), StringSplitLoop(1, aDDevF119992002_1, 4371)); globals aErr (0x005C5F90) and aOk (0x005C5F94) appear in the packet but not the decompiled body; dbl_8AFEA0 is read as double but only its low dword is passed to the event encoder.
- SetSelfAsReady (0x00460520): the readiness flag dword_7D0E50 copied into local v11 is never observed again; flag-bit semantics of BitfieldSetClearAt0x88 and the role of SingleFunctionCallWrapper_a810's return are not grounded beyond call shapes.
- HashChecksumComputation (0x00460770): the meaning of the constants (304444136, 79767, 468717489) and the use of the two byte inputs are not established.
- Cross-cutting: most packet owners are UNKNOWN, so all class groupings except AudioChannel (DERIVED) are GUESS; equal offsets on different this bases (notably 0x3FC4/0x3FB8/0x3E14 across AudioChannel and SessionManager, 0x1B7xx across AudioChannelInit and SessionMessageListManager, and 0x0/0x4 across GenericRuntimeObject members) are kept separate because the packet does not prove common ownership.
- Cross-cutting: several globals are flagged by packet facts but never appear in any raw body (flt_59E43C, flt_59F098, dword_59F09C, dword_59F0A4, aD_1 0x005C3280, unk_8AC368, byte_7CE498, aErr 0x005C5F90, aOk 0x005C5F94); treated as unresolved evidence, not semantics.
