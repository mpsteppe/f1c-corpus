# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

A heterogeneous set of runtime helpers: HUD text renderers that look up labels in the global string table (byte_5EC4C0) and render them through StringFormatAndRender; resource lifecycle wrappers that allocate, flag, release, and free child nodes/handles; an on-screen UI lifecycle (init/restart/post) driven from Game_Init/Game_Restart/Game_Post; and a session/menu state manager manipulating shared globals (dword_7D0410 mode, dword_7C56A4 session type, dword_7C569C session base, dword_7D2DB0 standings buffer, dword_5CC9E8/dword_5CC9E4 state flags). Two free helpers (MergeSort, CleanupRegistration) have no defensible class owner. Function owners are UNKNOWN in the packet; the class groupings here are DERIVED/GUESS synthesis.

## Function roles

- `0x0049D320` **HUDTextRenderer** — Formats the gear indicator text (numeric gear, neutral 'N', or error string) into a bounded stack buffer and renders it at HUD screen position (49, 43) via sub_553070.
- `0x0049DB80` **HUDTextRenderer** — Renders water/oil/brake temperature HUD rows, converting six Kelvin globals to Celsius and stepping the Y position by dword_5CCBBC per row; guarded on the render surface at this+0x8.
- `0x0049E9A0` **ResourceSlotOwner** — Allocates a 96-byte audio-sound node, zero-fills it, stores it at this+0xC, sets flag bit 0 at node+68, and attempts D3D texture creation (2052); frees the node on success and retains it on failure for retry.
- `0x0049EC40` **ResourceSlotOwner** — Releases the resource handle stored at this+0 through ResourceCascadeCleanup and clears the slot to 0; returns the released handle value or the pre-existing value when the slot was null.
- `0x0049ECA0` **ResourceSlotOwner** — Releases the resource handle at this+4 via ResourceCascadeCleanup and clears the field; skips cleanup and returns null when the handle is already null.
- `0x0049ECC0` **ResourceSlotOwner** — Conditionally destroys and frees the sub-object at this+0xC (destructor, empty-stub pass-through, heap free) and nulls the stored pointer; skips entirely when the pointer is null.
- `0x0049EFA0` **OnScreenUiSubsystem** — On-screen UI subsystem initializer: assertion log gate, race-session descriptor init, conditional cockpit LED gauge setup, resource double-delegate dispatch, and sub-initializer tail-call; invoked from Game_Init.
- `0x0049F000` **OnScreenUiSubsystem** — On-screen restart handler: assertion log, resource dispatch computations, session-complete write, resets this+4 to 1 and this+8 to 0, then clears a 25-entry dispatch table via VTableDispatchWithFieldClear; returns the last dispatch result.
- `0x0049F0D0` **OnScreenUiSubsystem** — On-screen post-frame routine: assertion log, session-mode utility call on the race descriptor, multi-stage cleanup of the UI singleton, and StaticArrayCleanup tail-call; invoked from Game_Post.
- `0x0049F1C0` **HUDTextRenderer** — Pit-status HUD renderer: lays out five driver rows, renders the player vehicle pit-repair status, prints each slot's driver name in left/right columns, and draws a selection box around the active slot (this+0x4).
- `0x0049FEB0` **FreeFunction** — Recursive merge sort over a singly linked list (next at node+4, payload at node+0), ascending by the float key at payload+4; returns the new list head; null/short lists returned unchanged.
- `0x0049FFD0` **FreeFunction** — Zero-argument wrapper passing the address of sub_49FFE0 to BooleanToIntConversion and returning its integer result; cleanup-registration semantic not confirmed by packet evidence.
- `0x004A0030` **SessionStateManager** — Championship/race session-state initializer gated on dword_7D0410: modes 1-6 set session state to 1 (modes 1-4 also dispatch the monitor page), then runs the global vtable dispatch and initializes the penalty struct at byte_7C56C0.
- `0x004A03F0` **SessionStateManager** — Shows the OS cursor (busy-wait on ShowCursor), resets global session state to 0, runs a short computation, and initializes the audio mixer device from byte_8AC494; returns 0.
- `0x004A0490` **SessionStateManager** — Session-level scoring/state cleanup and reset: server-mode init block, per-mode handler (profile strings for mode 4, module-manager computation for mode 5, fallback clamp for mode 6), sound interface reset, float-buffer reinit, season scoring reset, and main-menu dispatch.
- `0x004A0590` **SessionStateManager** — Advances the multiplayer session phase (1..6 to 2..7) via a jump table, places vehicles, then in race mode (dword_7D0410 == 4) dereferences the standings buffer and dispatches SessionActiveCheck (phase 7) or PitStopPhaseAdvance.
- `0x004A0690` **SessionStateManager** — Scene clear/reset sequence: array-check init, track scene path selection/load, sound-system virtual reset, float-buffer reinit with defaults, and scene sub-initializer call.
- `0x004A0760` **SessionStateManager** — Race-session-phase initializer: stops audio, resets a config buffer, runs auto-load config check, plays win/windrivers Bink videos when gated, advances pit-stop/season/array state, sets UI element states, resolves season display IDs, and sets session state to 3.
- `0x004A09A0` **SessionStateManager** — Session-active check: dereferences the standings buffer; on an active session resolves a vehicle setup path, loads the track scene (default byte_5EA438 fallback), and runs the scene sub-initializer; returns 0 active / 1 inactive.
- `0x004A0A80` **SessionStateManager** — Transitions the global menu state (dword_5CC9E4) to 2 and dispatches via the global vtable; conditionally runs a championship race-completion update when dword_7D0410 is 2/4 and session type is 7.
- `0x004A0AF0` **SessionStateManager** — Feature-gated dispatch helper: gates on a vtable+28 call on the command interface (dword_7CD8C0), then resolves the game-filter string target and dispatches it; returns 0 when the gate fails.
- `0x004A0B20` **RaceMilestoneEventDispatcher** — Dispatches in-race milestone events 13 and 19 on lap completion, gated on lap modulo 5, driver identity (this+0x4894 vs player vehicle field), and position (this+0x4060); returns 0.
- `0x004A0C60` **SessionStateManager** — Session-to-menu mode switch after race completion: when a shifted byte field of dword_5EA43C is set, forces session type 6 and enters the main menu; otherwise runs the post-race one-time init when dword_7CE814 is zero.
- `0x004A0CF0` **SessionStateManager** — Gate-protected session-state initialization: reads gate byte_7CE254 and, only while zero, runs the init routine sub_4A0250 and resets dword_7CE258; returns the gate or init result.

## Proposed classes

### HUDTextRenderer

Formats and renders HUD text rows (gear indicator, water/oil/brake temperatures, pit-status driver list) from string-table entries onto a render surface.

Methods: `0x0049D320`, `0x0049DB80`, `0x0049F1C0`

- `this+0x00000008` `void* render_surface` (read, DERIVED)
- `this+0x00000004` `int active_slot_index` (read, GUESS)
- `this+0x00000010` `void* render_context_a` (read, GUESS)
- `this+0x00000014` `void* render_context_b` (read, GUESS)

### ResourceSlotOwner

Owns child resource handles and sub-objects (render/audio resources): allocates and flags (bit 0 at node+0x44) a 96-byte node, and conditionally releases/clears or destroys/frees the owned handles.

Methods: `0x0049E9A0`, `0x0049EC40`, `0x0049ECA0`, `0x0049ECC0`

- `this+0x00000000` `void* resource_handle` (read_write, DERIVED)
- `this+0x00000004` `void* resource_handle_secondary` (read_write, DERIVED)
- `this+0x0000000C` `void* child_node` (read_write, DERIVED)

### OnScreenUiSubsystem

Lifecycle (init/restart/post) of the on-screen UI subsystem, including resource delegate dispatch, session descriptor setup, and cleanup of the UI singleton and its dispatch table.

Methods: `0x0049EFA0`, `0x0049F000`, `0x0049F0D0`

- `this+0x00000004` `int active_flag` (write, GUESS)
- `this+0x00000008` `bool bool_state` (write, GUESS)

### SessionStateManager

Owns global session lifecycle state (mode flag, session type, session base, standings buffer, menu/session state flags) and advances it through race, championship, scene, audio, and menu transitions.

Methods: `0x004A0030`, `0x004A03F0`, `0x004A0490`, `0x004A0590`, `0x004A0690`, `0x004A0760`, `0x004A09A0`, `0x004A0A80`, `0x004A0AF0`, `0x004A0C60`, `0x004A0CF0`


### RaceMilestoneEventDispatcher

Dispatches in-race milestone events on lap completion, gated on lap number, driver identity, and position.

Methods: `0x004A0B20`

- `this+0x0000403C` `int lap_number` (read, DERIVED)
- `this+0x00004060` `int position` (read, DERIVED)
- `this+0x00004894` `int driver_id` (read, DERIVED)

## Compatibility contracts

- **StringTableDisplayContract** — HUD renderers locate label strings via binary search in the global string table (byte_5EC4C0) and copy matches into the shared display buffer byte_5EC4CC before formatting (StringFormatWithBufferOverflowCheck, sub_587DD0 bounded copy) and rendering (StringFormatAndRender at 0x0049F6A0, sub_553070).
- **SessionStateGlobalContract** — Session lifecycle writes global markers: dword_5CC9E8 = 3 marks session active/ready, dword_5CC9E4 = 2 marks the menu state, dword_7D0410 selects championship/race mode, dword_7C56A4 holds the session type, and phase advance maps types 1..6 to successors 2..7.
- **SoundEngineResetContract** — During session, scene, and race-phase transitions the audio engine interface (global dword_5EB10C) is invoked through its vtable (slot +12) to stop/reset audio, guarded on the pointer being non-null.
- **ResourceHandleReleaseContract** — Resource handles stored in owner slots (offsets 0x0 and 0x4) are released through ResourceCascadeCleanup (0x005539F0) and the slot cleared to 0; a null handle skips the cleanup.

## Unresolved

- All packet function owners are UnknownObject/UNKNOWN; the class groupings (HUDTextRenderer, ResourceSlotOwner, OnScreenUiSubsystem, SessionStateManager, RaceMilestoneEventDispatcher) are worker synthesis at DERIVED/GUESS, not packet evidence. Equal byte offsets on distinct this-bases (e.g. this+0x4/this+0x8 on HUDTextRenderer vs OnScreenUiSubsystem, this+0xC on ResourceSlotOwner) are NOT merged; common ownership is unproven.
- MergeSort (0x0049FEB0) and CleanupRegistration (0x0049FFD0) are kept as free functions: no defensible class owner. CleanupRegistration's registration semantic is unsupported (no callers, no side-effect, ABI name LEGACY).
- MergeSort packet field refs field:this:0x00000008, field:this:0x0000000C and field:*(this+0x8):0x00000004 are not read by the raw body (only node+0 payload and node+4 next are touched); the sort-key meaning (float at payload+4) is caller-context derived.
- FormatGearIndicatorText packet lists an unused field (this+0x64) and unused globals (aD_1 at 0x005C3280, unk_7CE234); they are absent from its raw body.
- BrakeWaterTemperatureHUDDisplay packet lists an unused field (this+0x68) and unused globals (0x0059EAC8, 0x005ACAFC, 0x007CE048); they are absent from its raw body.
- Globals dword_8AFE64 (ResourceHandleCascadeRelease, SingleFieldFreeWrapper), 0x007CE24D/0x008AC494 (ChampionshipSessionInit), 0x008AC368 (SceneClearReset, SessionActiveCheck), 0x005EB978/0x005EC6D0/0x008AFE18 (RaceSessionPhaseInit), 0x008AD3B4 (GameFilterDispatch), 0x008AD298 (OnScreen_Restart, LapModuloEventDispatcher), 0x007CE24C (ConditionalInitGuard), and 0x005EC6D0/0x007CE498/0x007CE64C/0x007CE668/0x008AC388 (SessionScoringCleanupAndReset) are listed in packet evidence but absent from their raw bodies.
- Meaning of the StringFormatAndRender trailing int parameter (0/1) is unknown.
- D3DTextureCreation literal 2052, flag bit 0 at node+68, and the a2 argument type are uninterpreted.
- The 2616/2635/2688 assertion tokens passed to StringSplitLoop are opaque.
- Semantics of session-type values 1..7 (beyond 7 as final phase), dword_7D0410 mode enum, and dword_7C569C base structure are DERIVED from prior analysis, not evidenced here.
- What *(this[4]+84) and *(this[5]+84) point to (display/render context) is unknown.
- SoundEngineInterface vtable slot +12 and CommandDispatchInterface vtable+28 targets have no resolved callee addresses.
- Whether ResourceHandleCascadeRelease's already-released handle value is returned intentionally is unknown.
- CreateAudioSoundNodeWithTexture sets flag bit 0 at node+0x44 via source:raw only; the packet exposes no allowed evidence ref field:node:0x00000044, so the node flag is NOT modeled as a class field.
