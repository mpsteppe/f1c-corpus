# SessionNetworkRuntime

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED grouping of 21 validated IR functions sharing a session object (phase at +0x3FC4, COM interface at +0x3FB8, slot/entry count at +0x3E14) and a NetComm configuration object. ClearPlayerSlots resets slot bookkeeping arrays (node-ID at +0x3C74, slot dwords at +0x3E18, count at +0x3E14, entries at +0x1D4) and validates entries when the phase is not 3. ServerOpenTrackSignal emits a progress event, marks and dispatches a COM object, sets the +0x29 open-track flag, and appends the opening track name to the +0x1B770 linked list. updateTrackOpeningProgress decays the +0x2C timer and flips the +0x29 flag on expiry. SessionStateAndGlobalFlagCheck and twoStageCheck gate input/team-radio processing on phase 1/2 and global byte_7D1074 / flag bits. DriverEntrantSetupHandler and NetworkEntrantSetupWithIDCheck query the COM interface, set up entrants, and on failure run log-list teardown and state writes. ReorderChampionshipStandings and AssignSelfQualifyingPosition maintain the per-driver position grid dword_5F0730 (stride 4656) with count at +0x3FD9. EnumToEnumTranslator and JoinFailureReasonStringResolver map join errors; UniqueID validates the 128-byte identifier; ParseCommandLine fills NetCommConfig (host/connect flags +0xC5/+0xC6, address +0xC8, max players +0x1AC). Two interfaces are DERIVED: the COM vtable dispatch on +0x3FB8 and the network packet/connection protocol on +0x1B79C. Contradictions kept explicit: equal offsets 0x1AC/0x3FB8/0x3FC4/0x3E14 appear on 'this' and 'obj' bases across functions and are treated as one session object, but offsets 0x380/0x30 are evidenced only by the boot handler and 0xC5/0xC6/0xC8 only by ParseCommandLine; globals 0x008AC368, 0x0059E440-0x0059F0B4 and 0x005C3280 are referenced in the packet but never used in raw source.

## Function roles

- `0x00460CB0` **SessionObject** — Resets session player-slot bookkeeping: clears the slot count at +0x3E14, sentinel-fills the two 104-entry arrays (node IDs at +0x3C74, slot dwords at +0x3E18) with -1, invokes the interface utility on +0x3FB8, zero-initializes unused slot records, and when the phase at +0x3FC4 is not 3 validates each non-sentinel entry at +0x1D4 by linear search in the node-ID array, reporting and resetting stale slots.
- `0x00460E90` **SessionObject** — Server-side open-track signal handler: emits a progress event, retrieves a COM object from +0x3FB8, marks and dispatches it over the network, sets the +0x29 open-track flag, and appends the opening track name to the track-info linked list (+0x1B770 head / +0x1B774 tail / +0x1B778 end / +0x1B77C count) when the free-camera flag dword_7D0398 is set, else frees the temporary buffer.
- `0x004612E0` **SessionObject** — Per-frame decay of the track-opening progress timer at +0x2C: skipped when the phase at +0x3FC4 is 2 or 1 or the timer is negative; fires a one-time utility call at timer==5.0; clamps the decrement delta from dbl_8AFE90 into [0.01, 0.5]; on expiry sets the +0x29 flag to 1 and writes the expiry literal into +0x2C.
- `0x00461440` **SessionObject** — Session-state predicate: returns true only when the phase int at +0x3FC4 is 1 or 2 AND the global flag byte_7D1074 is non-zero; consumed as an input-command and team-radio message-processing gate.
- `0x00461480` **SlotStateRecord** — Field-wise initializer that zeros a block at +0x0 through +0x88 and seeds sentinel bytes (0x7C=-1, 0x7E=-1) with 0x7D cleared; returns 0. Shared by ArrayInitWithSentinelInLoop, ClearPlayerSlots and a thunk as per-slot state initialization.
- `0x004614C0` **UnknownObject** — Two-bit flag predicate: returns TRUE when FlagBitTest(2) is set and FlagBitTest(4) is clear; used as an input/team-radio gating helper.
- `0x00461D20` **SessionObject** — Frame-path handler that drives the 'You have been booted' disconnect notice: within the session-state gate (0,3] it decrements the float countdown at obj+0x380 by dbl_8AFE90, polls the delegation status via the +0x3FB8 interface, and when zero and the +0x30 not-yet-shown flag is clear renders the boot message through TextLineWrappingAndRendering and sets +0x30.
- `0x00461DC0` **SessionObject** — Thin wrapper over SessionStateCheck: forwards 'this' unchanged and returns TRUE when the returned session state is 2 or 1, else FALSE.
- `0x00461ED0` **SessionObject** — Directory-string lookup and network connect: guards on the network-system pointer at obj+0x1B79C (reached through this+0x0), copies the caller string into a fixed buffer, optionally decodes it against config byte_5C3F6C, resolves a port (seeded from word_7D0FE8), and calls NetworkConnection with fixed literal flags 1 and 5; always returns 1.
- `0x00462300` **SessionObject** — COM-delegate dispatcher: dereferences this+0x0 to the interface object, reads the handler field at +0x3FB8, and forwards it to the single-function wrapper, returning the wrapper's result; unconditional.
- `0x004623B0` **UnknownObject** — Negated vtable boolean test: invokes the vtable-dispatched boolean test with selector 140 and returns true only when the wrapper result is zero; used as a readiness/state query.
- `0x00462530` **UnknownObject** — Samples terrain surface roughness/height through the terrain sampler using the surface buffer at this+0x0 + 107456, the integer part of a2 as the sample coordinate, &a2 as the output slot, and 0.0 bias; returns the sampled value.
- `0x00462550` **SessionObject** — Sets up a driver entrant on the session object: reads the COM interface at obj+0x3FB8, builds a query object, copies the entrant name, applies the entrant count (obj+0x1AC or global default dword_7D0FC4), dispatches a virtual function from the unk_7CD270 stack-frame seed; on failure sets phase +0x3FC4 to 1 or 2, fills the buffer with 0xFFFFFFFF, tears down the log linked list (+0x3FC8..+0x3FD4), appends a directory-path node, triggers a file scan on the +112468 buffer, and invokes vtable slot 0x7C.
- `0x004627C0` **SessionObject** — Network-style entrant setup with a 128-byte sentinel check: queries the COM interface at *(this+0)+0x3FB8, invokes vtable slot 0xC4, copies the caller structure through an on-stack sentinel buffer, stamps bytes at a2+101 (index) and a2+102, conditionally stores a +24 thiscall result into *a3, invokes vtable slot 0x7C, and returns whether the sentinel survived.
- `0x004628A0` **UnknownObject** — Weather-surface / session UI update: initializes a description buffer, returns 0 when UniqueID fails, dispatches a state, builds session config, sends the buffer through BufferSendWithLocks, encodes a progress event seeded with dbl_8AFEA0, creates textures, and issues a system OS API call on unk_7CE24D; returns 1 on success.
- `0x00462A10` **SessionObject** — Re-orders championship standings after a race result: when the entry count at obj+0x3E14 is positive, builds a linked list of sort nodes (driver index from flag-bit selection, value, planned position from dword_5F0730), merge-sorts it, writes fresh sequential positions into the dword_5F0730 grid up to dword_7C9530, writes final positions back at +0x3FD6/+0x3FD9, and frees every node.
- `0x00462D30` **SessionObject** — Join-session error enum translator: gates on a delegation/status call through obj+0x3FB8 (non-zero blocks with return 0), converts the input enum via a callee, then maps intermediate values 0->0, 2->1, 3->2, 5->4 with every other value (including 1 and 4) to 3.
- `0x00462DA0` **UnknownObject** — Maps a join-failure code (a1) to a localized message string via the jump table: 1->Incompatible Game, 2->The Game is Full, 3->Game Closed, 4->Bad Password, 5->Join Timed Out, default->No Join Failure; every input resolves, no failure path.
- `0x00462E20` **SessionObject** — Multiplayer qualifying/standings position assignment for the local player: obtains local identity via the com handler dispatcher, searches the session nodemap for the matching NODEID, records planned positions into dword_5F0730 (stride 4656), and when self is never found falls back to last position by writing dword_5C329C into the player vehicle field at dword_7C54E8+0x4034 and logging the failure.
- `0x004630D0` **SessionObject** — Validates and retrieves a 128-byte unique identifier: queries the sub-object at obj+0x3FB8 (through this+0x0), runs a COM check, copies exactly 128 bytes into the caller buffer, returns true only when the copy consumed the full size, and always releases the queried sub-object via vtable slot 0x7C.
- `0x00463160` **NetCommConfig** — Parses the process command line for NetComm network options (--password, --dedicated, --host, --gamename, --connect, --name, --maxplayers) and populates the NetComm configuration object: host/connect flags, connect address buffer with a defaulted port, game name, player name, and a clamped [2,104] maximum player count; debug logging gated on dword_7C569C.

## Proposed classes

### SessionObject

Session-wide bookkeeping and multiplayer lifecycle object: player-slot bookkeeping arrays, session-phase field, COM interface handle at +0x3FB8, network-system pointer at +0x1B79C, track-info and log linked lists, and qualifying/standings count. Identified by the recurrent +0x3FC4 phase field and +0x3FB8 interface across 14 packet functions; per-field trusts stay GUESS where evidenced by a single function. Equal offsets under 'this' and 'obj' bases are treated as one object because the packet derefs this+0x0 to the same object.

Methods: `0x00460CB0`, `0x00460E90`, `0x004612E0`, `0x00461440`, `0x00461D20`, `0x00461DC0`, `0x00461ED0`, `0x00462300`, `0x00462550`, `0x004627C0`, `0x00462A10`, `0x00462D30`, `0x00462E20`, `0x004630D0`

- `this+0x00000000` `void* object_ptr` (read, GUESS)
- `this+0x00000029` `byte open_track_flag` (write, GUESS)
- `this+0x0000002C` `float opening_progress_timer` (read_write, GUESS)
- `obj+0x00000030` `byte boot_message_shown_flag` (read_write, GUESS)
- `obj+0x000001AC` `int entrant_count` (read, GUESS)
- `this+0x000001D4` `int[104] player_slot_entries` (read_write, GUESS)
- `obj+0x00000380` `float boot_countdown_timer` (read_write, GUESS)
- `this+0x00003C74` `int[104] node_id_array` (read_write, GUESS)
- `this+0x00003E14` `int slot_count` (read_write, DERIVED)
- `this+0x00003E18` `int[104] slot_dword_array` (write, GUESS)
- `this+0x00003FB8` `interface* com_interface_ptr` (read, DERIVED)
- `this+0x00003FC4` `int session_phase` (read_write, DERIVED)
- `obj+0x00003FC8` `node* log_list_head` (read_write, GUESS)
- `obj+0x00003FCC` `node* log_list_tail` (read_write, GUESS)
- `obj+0x00003FD0` `node* log_list_secondary` (read_write, GUESS)
- `obj+0x00003FD4` `int log_list_count` (read_write, GUESS)
- `obj+0x00003FD9` `byte standings_position_count` (read_write, GUESS)
- `this+0x0001B770` `node* track_info_list_head` (read_write, GUESS)
- `this+0x0001B774` `node* track_info_list_tail` (read_write, GUESS)
- `this+0x0001B778` `node* track_info_list_end` (read_write, GUESS)
- `this+0x0001B77C` `int track_info_list_count` (read_write, GUESS)
- `obj+0x0001B79C` `void* network_system_ptr` (read, GUESS)

### SlotStateRecord

Per-slot state record (140-byte stride, offsets 0x0..0x88) initialized by StructFieldZeroInitWithDefaults: zeroed fields with sentinel bytes at +0x7C/-1 and +0x7E/-1. Owner is UnknownObject in the packet; this is a semantic grouping over the offsets the initializer stamps.

Methods: `0x00461480`

- `this+0x00000000` `dword leading_dword` (write, GUESS)
- `this+0x00000004` `byte field_byte_04` (write, GUESS)
- `this+0x00000024` `byte field_byte_24` (write, GUESS)
- `this+0x0000003C` `byte field_byte_3C` (write, GUESS)
- `this+0x0000005C` `byte field_byte_5C` (write, GUESS)
- `this+0x0000007C` `byte sentinel_byte_7C` (write, GUESS)
- `this+0x0000007D` `byte sentinel_byte_7D` (write, GUESS)
- `this+0x0000007E` `byte sentinel_byte_7E` (write, GUESS)
- `this+0x00000080` `word word_field_80` (write, GUESS)
- `this+0x00000082` `word word_field_82` (write, GUESS)
- `this+0x00000084` `word word_field_84` (write, GUESS)
- `this+0x00000086` `word word_field_86` (write, GUESS)
- `this+0x00000088` `byte field_byte_88` (write, GUESS)

### NetCommConfig

NetComm network configuration object populated from the process command line by ParseCommandLine: host/connect flag bytes, connect address buffer, game name and player name buffers, and a clamped maximum player count. The packet names the owner NetComm at DERIVED trust.

Methods: `0x00463160`

- `obj+0x000000C5` `byte host_flag` (write, GUESS)
- `obj+0x000000C6` `byte connect_flag` (write, GUESS)
- `obj+0x000000C8` `char[80] connect_address_buffer` (read_write, GUESS)
- `obj+0x000001AC` `int max_player_count` (write, GUESS)

## Compatibility contracts

- **SessionPhaseField** — The session object exposes a phase/state int at +0x3FC4 where values 1 and 2 gate active play (SessionStateAndGlobalFlagCheck accepts them; updateTrackOpeningProgress skips them) and value 3 disables slot validation in ClearPlayerSlots. A replacement must preserve the writes of 1 or 2 made on the entrant-setup failure path and the phase checks.
- **PlayerSlotBookkeeping** — The session keeps 104-entry slot bookkeeping: node-ID array at +0x3C74, slot-dword array at +0x3E18, count at +0x3E14, per-slot entries at +0x1D4; empty entries use the -1 sentinel. Slot records (140-byte stride) are initialized by StructFieldZeroInitWithDefaults (0x00461480), which zeroes offsets 0x0..0x88 and seeds sentinels at +0x7C and +0x7E.
- **SessionComInterfaceSlot** — A COM-style interface pointer at session+0x3FB8 supports query-with-stack-buffer (0x0057A880), release/cleanup at vtable+0x7C (0x0057A8B0), dispatch at vtable+0xC4 (0x0057A8E0), per-slot dispatch (0x0057A800), boolean test (0x0057A830), delegation/status (0x0057A900), and virtual dispatch with stack frames (0x0057A4F0). A 128-byte unique-id copy contract runs through ByteAlignedMemoryCopyFromStruct (0x0057A230).
- **JoinFailureMessageTable** — Join-failure codes 1..5 resolve to distinct message strings via the jump table at 0x00462DE4: 1->Incompatible Game (0x005C6274), 2->The Game is Full (0x005C6260), 3->Game Closed (0x005C6250), 4->Bad Password (0x005C6240), 5->Join Timed Out (0x005C6230), default->No Join Failure (0x005C621C). Every code resolves; a replacement must preserve the mapping.
- **NetCommCommandLineTokens** — The process command line is parsed for --password (0x005C64D8), --dedicated (0x005C64A8), --host (0x005C64A0), --gamename (0x005C6474), --connect (0x005C644C), --name (0x005C6384), --maxplayers (0x005C6350) into a NetComm config object: host flag byte at +0xC5, connect flag byte at +0xC6, connect address buffer at +0xC8 (default port word_7D1004), max player count clamped to [2,104] at +0x1AC.
- **ChampionshipStandingsGrid** — Per-driver position grid at dword_5F0730 with stride 4656 dwords and end pointer dword_7C9530; standings position count byte at session+0x3FD9. ReorderChampionshipStandings builds and merge-sorts driver sort nodes (LinkedListMergeSort_47d0) and writes sequential positions; AssignSelfQualifyingPosition records planned grid positions by nodemap index.
- **DebugLogInfrastructure** — Dev debug logging requires the global log target dword_8AD25C, the session-type gate dword_7C569C != 5, and StringSplitLoop(1 or 2, aDDevF119992002_1 at 0x005C5CE4, line-id) before DebugLogWrite (0x004D7AA0). Many session paths use distinct line ids; a replacement must reproduce the gating or remove the writes.
- **FrameTimeGlobals** — Frame-step double dbl_8AFE90 (0x008AFE90) drives per-frame timer decay (opening progress in updateTrackOpeningProgress, boot countdown in YouHaveBeenBootedHandler); session-time double dbl_8AFEA0 (0x008AFEA0) seeds progress-bar events (ProgressBarEventEncode 0x004B33B0) and the opening-progress utility call.

## Unresolved

- ClearPlayerSlots: the semantic distinction between the node-ID array (+0x3C74) and the slot-dword array (+0x3E18) is inferred from the validation lookup; both are bulk-initialized to -1 here, and the slot-index arithmetic (35*count+229 dwords, 140-byte stride) is from the fill, not proven.
- ClearPlayerSlots: global dbl_8AFEA0 (0x008AFEA0) is listed as read but has no visible role in the raw source; likely a debug timestamp on the debug-log path.
- ServerOpenTrackSignal: object identity of 'this' is unknown (owner UNKNOWN); the meaning of the byte set at obj+4 and the network packet layout built from v10 are not grounded here.
- ServerOpenTrackSignal: global unk_8AC368 (0x008AC368) is listed as a read global but never referenced by raw source; role unplaced.
- updateTrackOpeningProgress: read-only globals flt_59E440, flt_59E444, flt_59E450, flt_59F0B4 are packet evidence but absent from the raw source; the expiry literal -1082130432 written into the timer and the role of the dbl_8AFEA0 argument to UtilityFunction_e570 are unexplained.
- SessionStateAndGlobalFlagCheck: concrete meaning of phase values 1 and 2 and of the global flag byte_7D1074 is not established.
- SlotStateRecord: the object type owning offsets 0x0-0x88 is unidentified; the -1 sentinels at +0x7C/+0x7E and the untouched bytes between +0x5C and +0x7C are undocumented.
- twoStageCheck: semantics of flag bits 2 and 4, and which global flag store FlagBitTest (0x00461530) reads, are unresolved; the input/team-radio gating role is suggested by callers only.
- YouHaveBeenBootedHandler: labels (boot countdown for +0x380, message-shown flag for +0x30, disconnected/booted status for the delegation result) come from existing-analysis prose, not packet raw source; literal 16909060 passed to TextLineWrappingAndRendering is unexplained.
- StateCheckWrapper: meaning of the accepted session-state constants 1 and 2, and which callers depend on each, is unresolved.
- DirectoryStringProcessingWithDecode: the sub_587C20/sub_5897CA decode-compare chain, what byte_5C3F6C config data represents, and the two fixed NetworkConnection literal arguments (1, 5) are not grounded here.
- DispatchComHandlerCall: identity/layout of the COM interface behind the offset-0 this pointer, whether +0x3FB8 is a stable interface field or a per-instance handler slot, and the single-function wrapper contract are external/unknown.
- VTableBooleanTestNegated: meaning of selector literal 140 is unknown; callers (NetComm_SetSelfAsReady, ConditionalRenderStateUpdate, SessionTypeSetter) suggest a readiness query but this is not evidenced.
- SampleTerrainRoughnessHeight: the 107456 displacement and the 0.0 argument semantics are unknown; the DERIVED prelabel 'structural twin of ConditionalFreeWithBit0Flag' does not match the raw source (sampling, not a conditional free), so the prelabel is not adopted.
- DriverEntrantSetupHandler: the COM interface at obj+0x3FB8 and its vtable+0x7C contract, the 12-dword unk_7CD270 dispatch seed, and the obj+52 / obj+112468 buffers are not established; the ABI name Driver_Entrant_Setup_Entry is Legacy-trust and does not confirm an owning class.
- NetworkEntrantSetupWithIDCheck: meaning of output bytes a2+101/a2+102 and the returned sentinel boolean depend on the caller contract; prelabel cluster_copy (structural twin of BufferSendWithLocks) is DERIVED and does not confirm ownership.
- WeatherSurfaceUpdate: description-buffer and texture-array layouts, the progress-bar event parameters (type 4, stage 5), and the semantics of unk_7CE24D are unknown.
- ReorderChampionshipStandings: the object behind *this is unnamed; per-entry flag offset 916, driver-index offset 1040, value-table offset 15476 and stride 140 are from loop arithmetic only; dword_5F0730 stride 4656 is not independently confirmed.
- EnumToEnumTranslator: semantics of the sub_57A590 conversion and of the SingleDelegationCall_a900 guard state are unknown; caller links to AutoJoinRetryLoop (0x004637A0) and MultiplayerSessionJoinHandler (0x0046DE10) come from existing analysis only.
- AssignSelfQualifyingPosition: nodemap bounds (15896..16312), dword_5F0730 stride 4656, the player-vehicle field at dword_7C54E8+0x4034 (no dedicated field evidence ref), and byte_5EA438 semantics are unverified.
- UniqueID: identity/payload of the 128-byte unique identifier, the exact meaning of the COMVTableCallVia0xc4 result, whether VTableCallViaOffset0x7c performs a release, and the caller buffer-size contract are unresolved.
- ParseCommandLine: sub_566810 token-search return convention is inferred; StringCopyToStructField (0x00463710) writes the password into an offset not visible here; separator literals asc_5C64D4/byte_5C3F6C and default port word_7D1004 are unconfirmed; game-name/player-name write offsets 364/284 are not in the packet field list; global aD_1 (0x005C3280) and field obj+0x117 are unused by raw source.
- Field refs under 'obj' base at +0x30/+0x380 are evidenced only by YouHaveBeenBootedHandler and +0xC5/+0xC6/+0xC8 only by ParseCommandLine; the equality of the underlying object with the session object seen elsewhere is inferred from the shared +0x3FB8/+0x3FC4 deref pattern, not proven.
- Equal offsets 0x1AC (entrant count vs max player count) appear on SessionObject and NetCommConfig; the packet does not prove common ownership, so they are kept as separate fields.
