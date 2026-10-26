# NetSessionRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

DERIVED-source architecture proposal for the multiplayer session runtime. All packet owners are UNKNOWN (except checkAndTransitionSessionState, DERIVED), so the shared-field evidence on the receiver groups eight net-comm/session/input/timing functions into a single GUESS class NetCommSession: NetCommSessionMessageDispatcher (0x0045D890) decodes the session-message header and switches on the event type; SessionSynchronizer (0x0045F950), NetCommPlayerSlotSync (0x0045FC50), ProcessTeamRadioNetworkMessages (0x0045F710), InputCommandDispatchToEntities (0x0045F4A0), ClientGridDisplayTimer (0x00460380), ConditionalRenderStateUpdate (0x00460710) and ParticleSoundEffectSpawner (0x004607A0) all read the same session-phase field at +0x3FC4, the player-entity count at +0x3E14 and the entity arrays at +0x410/+0x3C74. MouseInputHandler (0x0045F030) shares the +0x1B7xx UI region (list head +0x1B770, button list +0x1B780). SessionStateCheck (0x00461CD0) and its boolean wrapper (0x00461DB0) form a DERIVED SessionStateGate over the delegated interface at obj+0x3FB8 and the state at obj+0x3FC4. SessionConfigWriteback (0x00461900) deserializes the received config struct into clamped global settings. FlagBitTest (0x00461530) is a read-only bit test on the +0x88 flag byte. ThunkToFUN00461480 (0x00461470) is a generic initializer thunk with no grounded owner.

## Function roles

- `0x0045D890` **NetCommSession** — Central netcomm session message dispatcher: validates the message header (v & 0xE0000000) == 0x80000000, switches on (v >> 18) & 0x3F over session events (session start, grid broadcast, server vehicle-data copy, next-track transition, driver boot notifications, color/effect trigger, terrain validation with per-player path construction and mismatch reporting, terrain queue drain/re-fill, session-state-code writes, per-player terrain-height check), and falls back to a staging-buffer tail for unmatched types; returns 1 on handled messages, 0 when the header check fails.
- `0x0045F030` **NetCommSession** — Mouse-input HUD label handler: when the hover timer at this+0x384 reaches the 0.667 threshold and the HUD flag byte_7CE254 is clear, walks input-action entries, maps action codes 4098-4107 to button indices, bounds-checks against the button count at this+0x1B78C, traverses the button-state list headed at this+0x1B780, formats and clamps the label, encodes a progress-bar event, builds and renders the wrapped line into dword_7CD204, and resets the hover timer.
- `0x0045F4A0` **NetCommSession** — Buffered session input-command dispatch to entities: snapshots session data into the command ring buffer at dword_83EE60, walks buffered commands (skipping the 0x10000000 flag), forwards global-state commands to the visibility-grid manager at dword_7CD2A8, and otherwise filters each command per entity against the self index, the phase flag at this+0x3FC4 and a two-stage check, optionally rewriting the entity tag from this+0x410, then dispatching via TextureCreationWrapper; a second global-state pass recomputes the entity visibility grid and pops/emits queued entries.
- `0x0045F710` **NetCommSession** — Team-radio network message processing during active phases (this+0x3FC4 in {1,2}): when global session state is referenced, runs resource-manager frame cleanup and per-vehicle slot refresh; then drains incoming messages via SEH-protected copy off the session interface at this+0x3FB8, resolves the driver index, solves collision contact with the session time, dispatches via NetCommSessionMessageDispatcher, and replays queued session data or runs gated per-entity texture work (raw source truncated at the per-entity loop body).
- `0x0045F950` **NetCommSession** — Per-frame session synchronization and timing: in terrain-sampling phase (this+0x3FC4 in {1,2}) accumulates delta into this+0x38C and every 5.0 seconds bursts per-player terrain-height samples with progress events and per-slot height textures; otherwise runs the countdown timer at this+0x10 (reloaded from this+0xC), fires the one-shot action when the byte at this+0x14 was set, polls for session-index changes and re-places vehicles, and renders a synchronizing-game drift message when client time diverges from the server clock.
- `0x0045FC50` **NetCommSession** — Multiplayer player-slot synchronization: gated on the sync-in-progress byte at this+0x374; pass 1 walks active player slots (base this+0x3C74/this+0x3D0, 140-byte stride, count at this+0x3E14) detecting joins via the vehicle array &unk_5EC6D8, loading each joined vehicle and updating slot metadata; pass 2 walks the whole vehicle array, unloads slots that vanished, trims the session-path linked list at this+0x3FC8/0x3FCC/0x3FD0/0x3FD4, repoints the current player, and rebuilds the active-vehicle pointer array.
- `0x00460380` **NetCommSession** — Timer-driven client grid overlay controller: while the session phase at this+0x3FC4 equals 3, decrements the 7.5-second countdown timer at this+0x1C by the frame delta; on expiry (with a unique session id present) it refreshes scene state, toggles the grid display flag at this+0x20 between hidden and shown, and resets the timer.
- `0x00460710` **NetCommSession** — Conditional render-state update: gated on the session phase at this+0x3FC4; when the phase is not 1, initializes a local state buffer via ThunkToFUN00461480, processes it, sets bit 4 on the render-state flag byte via BitfieldSetClearAt0x88, finalizes and returns the cleanup-stub result; the phase-1 path is skipped entirely.
- `0x004607A0` **NetCommSession** — Particle/sound asset resolution driven by the season/race index bytes at this+0x1B768/this+0x1B769: stores the pair, reports progress, derives a random value, builds candidate paths from global directories with fallbacks, queries file sizes, appends the season/race suffix, formats the final track path, and returns the created texture handle.
- `0x00461470` **UnknownObject** — Initializer thunk: calls StructFieldZeroInitWithDefaults on this and returns this unchanged to support chained initialization; called from many network/session/input/render paths.
- `0x00461530` **FlagBitTestAccessor** — Non-destructive bitmask test: ANDs the incoming mask with the flag byte at offset 0x88 of the receiver and returns whether any bit is set; read-only, no side effects; used as a session/entity flag gate across net-comm dispatch, input dispatch, session sync and slot-sync paths.
- `0x00461900` **SessionConfigDeserializer** — Multiplayer session-config deserialization: parses scene data, AI config and track name, copies byte/short/float fields and a packed bitfield word into clamped global settings (player count, weather mode, tire model, penalties, pit windows, damage, fuel), and applies a clamp after every write.
- `0x00461CD0` **SessionStateGate** — Session-state transition check: reads the session state at obj+0x3FC4 (reached via this[0]); when it equals 4, queries the delegated interface at obj+0x3FB8 and, if that call returns 3, transitions the state to 3; returns the resulting state in both paths; called by fifteen session/multiplayer lifecycle functions.
- `0x00461DB0` **SessionStateGate** — Boolean wrapper around SessionStateCheck: forwards its own receiver to 0x00461CD0 and returns whether the resulting state is non-zero; used as a boolean session-state gate across multiplayer placement, end-condition, debug, UI, simulation and pit paths.

## Proposed classes

### NetCommSession

The multiplayer session object: netcomm message dispatch, input-command routing to session entities, team-radio processing, per-frame synchronization and timing, player-slot join/leave sync, grid-overlay timing, conditional render-state update, particle/sound asset resolution, mouse-hover HUD labels, and the shared text/button list state in the +0x1B7xx region. Identified by the shared phase field at +0x3FC4, player-entity count at +0x3E14, entity arrays at +0x410/+0x3C74, the delegated interface at +0x3FB8 and the session-path list at +0x3FC8.

Methods: `0x0045D890`, `0x0045F030`, `0x0045F4A0`, `0x0045F710`, `0x0045F950`, `0x0045FC50`, `0x00460380`, `0x00460710`, `0x004607A0`

- `this+0x00000000` `pointer methodPointer` (read, DERIVED)
- `this+0x0000000C` `float countdownReloadValue` (read, DERIVED)
- `this+0x00000010` `float countdownTimer` (read_write, DERIVED)
- `this+0x00000014` `byte oneShotActionFlag` (read_write, DERIVED)
- `this+0x0000001C` `float gridCountdownTimer` (read_write, DERIVED)
- `this+0x00000020` `byte gridDisplayFlag` (read_write, DERIVED)
- `this+0x00000374` `byte syncInProgressFlag` (read_write, DERIVED)
- `this+0x00000378` `dword enum sessionStateCode` (write, DERIVED)
- `this+0x00000380` `float terrainHeightThreshold` (read, GUESS)
- `this+0x00000384` `float hoverTimer` (read_write, DERIVED)
- `this+0x00000388` `dword messageCounter` (write, DERIVED)
- `this+0x0000038C` `float terrainSampleAccumulator` (read_write, DERIVED)
- `this+0x00000390` `float terrainRoughnessAdjust` (read_write, GUESS)
- `this+0x00000410` `byte array (140-byte-stride entries) playerEntityFlagArray` (read, GUESS)
- `this+0x00000411` `byte playerEntityByteA` (read, GUESS)
- `this+0x00003C74` `dword array playerEntityIdArray` (read, GUESS)
- `this+0x00003E14` `dword playerEntityCount` (read, DERIVED)
- `this+0x00003FB8` `pointer delegatedInterfacePtr` (read, DERIVED)
- `this+0x00003FC4` `dword enum sessionPhase` (read_write, DERIVED)
- `this+0x00003FC8` `pointer sessionPathListHead` (read_write, DERIVED)
- `this+0x00003FCC` `pointer sessionPathListTail` (read_write, DERIVED)
- `this+0x00003FD0` `pointer sessionPathListIterator` (read, DERIVED)
- `this+0x00003FD4` `dword sessionPathListCount` (read_write, DERIVED)
- `this+0x0001B754` `byte gridInfoByteA` (read, GUESS)
- `this+0x0001B755` `byte gridInfoByteB` (read, GUESS)
- `this+0x0001B768` `byte seasonRaceIndexByteA` (read_write, GUESS)
- `this+0x0001B769` `byte seasonRaceIndexByteB` (read_write, GUESS)
- `this+0x0001B76A` `byte terrainFlagByteA` (read, GUESS)
- `this+0x0001B76B` `byte terrainFlagByteB` (read, GUESS)
- `this+0x0001B76C` `byte terrainFlagByteC` (read, GUESS)
- `this+0x0001B76D` `byte terrainFlagByteD` (read, GUESS)
- `this+0x0001B76E` `byte terrainFlagByteE` (read, GUESS)
- `this+0x0001B770` `pointer messageTextListHead` (read_write, DERIVED)
- `this+0x0001B774` `pointer messageTextListTail` (read_write, GUESS)
- `this+0x0001B778` `pointer messageTextListIterator` (read, GUESS)
- `this+0x0001B77C` `dword messageTextListCount` (read_write, GUESS)
- `this+0x0001B780` `pointer buttonListHead` (read, DERIVED)
- `this+0x0001B78C` `dword buttonCount` (read, DERIVED)

### FlagBitTestAccessor

Read-only bitmask test on the object flag byte at offset +0x88; returns whether any bit of the caller mask is set. Used as a flag gate by net-comm dispatch, input dispatch, session sync and slot-sync paths.

Methods: `0x00461530`

- `this+0x00000088` `byte bitmask flagByte` (read, DERIVED)

### SessionStateGate

Session-state gate over the delegated interface at obj+0x3FB8 and the session-state field at obj+0x3FC4 (the session object reached via this[0]): transitions the state 4 -> 3 when the delegated call returns 3, and exposes a boolean wrapper for lifecycle gating.

Methods: `0x00461CD0`, `0x00461DB0`

- `this+0x00000000` `pointer sessionObjectPtr` (read, DERIVED)
- `obj+0x00003FB8` `pointer delegatedInterfacePtr` (read, DERIVED)
- `obj+0x00003FC4` `dword enum sessionState` (read_write, DERIVED)

### SessionConfigDeserializer

Deserializes the received multiplayer session-config struct into clamped global settings: parses scene/AI/track data, copies byte/short/float fields and a packed bitfield word, applying a range/byte/float clamp after every write.

Methods: `0x00461900`

- `this+0x00000060` `float settingFloat` (read, DERIVED)
- `this+0x00000064` `byte settingByte0` (read, DERIVED)
- `this+0x00000066` `byte settingByte1` (read, DERIVED)
- `this+0x00000067` `byte settingByte2` (read, DERIVED)
- `this+0x00000068` `byte settingByte3` (read, DERIVED)
- `this+0x00000069` `byte settingByte4` (read, DERIVED)
- `this+0x0000006A` `byte settingByte5` (read, DERIVED)
- `this+0x0000006B` `byte settingByte6` (read, DERIVED)
- `this+0x0000006C` `byte settingByte7` (read, DERIVED)
- `this+0x0000006D` `byte settingByte8` (read, DERIVED)
- `this+0x00000074` `short settingShortA` (read, DERIVED)
- `this+0x00000076` `word bitmask packedOptionWord` (read, DERIVED)
- `this+0x00000078` `short settingShortB` (read, DERIVED)
- `this+0x0000007A` `short settingShortC` (read, DERIVED)
- `this+0x0000007C` `short scaledShortValue` (read, DERIVED)

## Compatibility contracts

- **SessionPhaseValueSpace** — The session-phase field at this+0x3FC4 holds an integer phase used to gate most session runtime paths: 1 (race/active), 2 (qualifying), 3 (grid-display phase), 4 (gated initial state that checkAndTransitionSessionState transitions to 3 when the delegated interface returns 3). The separate field at this+0x378 is written 2 (case 0x28) or 3 (case 0x29) by NetCommSessionMessageDispatcher as a session-state code.
- **SessionMessageHeaderFormat** — Netcomm session messages carry a header word whose high bits are masked: (v & 0xE0000000) == 0x80000000 marks a valid message; the event type is (v >> 18) & 0x3F; case 6 additionally decodes (v >> 8) & 0x3FF as a payload length and the tail tests byte3 & 7. A staging tail forwards unmatched raw messages into the 432-byte command ring buffer via ArithmeticComparison_3a90.
- **SessionPathListLayout** — The session-path queue lives at this+0x3FC8 (head), this+0x3FCC (tail), this+0x3FD0 (iterator) and this+0x3FD4 (count). Nodes carry the path string at offset +0, the next pointer at +4 and a free-flag byte at +8; comparison is via sub_588410 and removal frees the node via FreeWrapper_7bcf when the flag at +8 is set.
- **MessageTextListLayout** — Text messages (boot, removed-from-session, join/leave, terrain mismatch) are appended to the linked list at this+0x1B770 via DoublyLinkedListAppend with 8-byte nodes (next pointer at node+4) allocated by OperatorNewNhMallocWrapper, copied with StringCopyWithBufferRealloc, and trimmed by LinkedListPurgeByThreshold.
- **VehicleArrayLayout** — The vehicle array base is &unk_5EC6D8 with per-slot stride 18624 (0x48C0); the active-vehicle pointer array is dword_7C54F0 with count dword_5C329C and array end bound byte_7C54D8. A slot is inactive when its int32 at +3250 equals -1; the driver name is stored at slot+17952 (byte +0x4620) and the slot's grid index at +18580. Slots are refreshed from flt_5F0774 up to flt_7C9574 by stride 4656 in the server-data copy path.
- **SessionConfigBitfieldContract** — The packed option word at this+0x76 drives guarded writes into clamped global settings: bit0 -> byte_7CE874 = (word & 0x40) != 0; bit1 -> byte_7CE88C = (word & 0x80) != 0; bit2 -> dword_7CE958 = (word & 0x100) >> 8; bit3 -> byte_7CE97C = (word & 0x200) != 0; bit4 of the byte -> flt_7D108C = (double)*(unsigned short*)(this+0x7C) * 0.001; unconditionally dword_7CED44 = (word & 0x400) >> 10, dword_7CEE40 = (word & 0x800) >> 11, dword_7CEF3C = (word & 0x1000) >> 12. Every write is followed by a clamp.
- **DelegatedSessionInterface** — The session object holds a delegated interface pointer at obj+0x3FB8 (reached via this[0]); checkAndTransitionSessionState queries it via SingleDelegationCall_a900 and treats a return value of 3 as the readiness signal that moves the session state from 4 to 3.

## Unresolved

- Exact wire-protocol layout: header bits 0xE0000000, (v >> 18) & 0x3F, (v >> 8) & 0x3FF and (byte3 & 7) are raw decode masks; per-case message semantics are inferred only.
- String globals aSS (0x005BE860), aSSS_2 (0x005C5D0C), aSS_2 (0x005C5D30), byte_45E528 (0x0045E528) and unk_8AC388 are flagged by the IDB but do not appear in the decompiled bodies; they are likely jump-table-adjacent or pointer-pool data.
- Float globals flt_59E440, flt_59E444, flt_59E448, flt_59E450, flt_59E87C, flt_59F094, flt_59F0AC, flt_59F0B0, flt_59F0B8, flt_59F108, flt_59F114, flt_59F11C, flt_59E7EC, flt_59E84C, flt_59E874, flt_59E600 and dbl_59EA08 are extracted as reads but absent from the decompiled bodies; their roles are unknown.
- The qmemcpy target this+16344 and the stride-4656 vehicle-slot write target layout in NetCommSessionMessageDispatcher are not named in the fact tables.
- MouseInputHandler is folded into NetCommSession because it reads the +0x1B7xx UI region (button list +0x1B780, count +0x1B78C) adjacent to the message-text list at +0x1B770; whether the mouse HUD state is a separate object on the same base is not proven by the packet.
- The obj base in checkAndTransitionSessionState is the session object reached by dereferencing this[0]; obj+0x3FC4 is semantically the same session-phase field as NetCommSession.this+0x3FC4 but the base identity is not proven, so they are kept as separate fields (rule: do not merge equal offsets from different bases without proof).
- ThunkToFUN00461480 (0x00461470) forwards to StructFieldZeroInitWithDefaults (0x00461480); the receiver type and the exact field defaults applied are unknown, so its owner stays UnknownObject.
- The meaning of the individual bits in the +0x88 flag byte and whether it belongs to the session object or a shared base class is unknown; FlagBitTest callers outside the session set (0x004613E0, 0x004614C0, 0x00462380, 0x00462A10) are not explained by this packet.
- ProcessTeamRadioNetworkMessages raw source is truncated inside the per-entity loop; the texture-rendering body and the final dispatch tail are not fully visible. dword_7D0E98 (threshold > 8) and dword_7D0F04 (net-comm state flag) are consumed in the truncated tail. CollisionContactSolver target offset 0x68F0 is not in the packet field evidence.
- The numeric session-state space is only partially evidenced: 4 is the gate value and 3 the transition target in checkAndTransitionSessionState; the meaning of other values (1, 2, 5+) is not in the packet. The return-value semantics of the delegated interface (beyond '3 = ready') are not named.
- The semantic identity of each clamped session setting (player count, weather mode, tire model, penalties, pit windows, damage, fuel) is not provable from SessionConfigWriteback alone; existing-analysis names are prose, not facts. Many neighbor globals sharing the clamp buffers are absent from the raw source.
- The producer of the session-index value consumed by SessionSynchronizer change detection is not identified; the 140-byte player-slot entry layout (base +0x3C74 vs +0x3D0) is unconfirmed.
- The input-command flags 0x10000000 and 0x8000000 and TwoStageCheck's two-stage gate are not stated by packet facts; the phase-3 interaction with FlagBitTest is DERIVED from source structure.
- Vehicle-slot offsets reached through &unk_5EC6D8 + 18624*slot (e.g. +1780, +3250, +4645, +16436, +17952, +18016) are read/written but not enumerated as packet fields; only the linked-list node fields are packet-flagged.
- Several globals are listed in the packet material but have no grounded use: dword_7CD25C, dword_7CD8C0, unk_8AC368, unk_8AC494, dword_8ACEA0, byte_8AFF00, dword_8ACEE0 and the abi:lead / guard:2 / caller refs for functions not in this packet.
