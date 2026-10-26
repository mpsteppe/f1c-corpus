# UiPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

The ui_platform_and_options scope reconstructs as a set of loosely coupled clusters with no proven shared ownership. DamageUiRenderer (0x00496E90) is a stateful HUD renderer: it consults CarCrashDamageProcessing first and returns 0 while damage is being processed, otherwise renders/cleans an up-to-8-node damage chain (head this+0x18, next at node+0x68, coordinates via vtable+8), advances a state step at this+0x38 and a UI timer float at this+0x44 that drives a BinarySearchInStringTable message lookup, and with no damage state dispatches a no-draw-stack message and returns -1. OptionsSetupHandler (0x004A0EB0) logs entry, forces or clears setup flags per the init/sub-mode guards, then runs the main setup loop incrementing dword_7CE250 and calling session processing sub_485B90 until byte_7CE25C or a -1/1 result. UiWidgetHierarchy teardown (0x004B5A30) frees guarded buffers and runs four linked-list destructor families. GameOptionsState (0x004C1E80) parses the config stream, building a career-season node list (head this+0, tail this+4) and filling totals/records and race/game-option fields. FilterPropertiesList (0x004C5E50/0x004C5FD0) filters the global 396-byte scene pool into a this+0x8/0xC/0x10/0x14 list. BuildTerrainIniPath (0x004CEEF0) formats the terrain.ini path from season/track globals. startingGridUIDraw (0x004D9420) draws two grid columns or a title/label overlay. UIDebugOverlayRender (0x004DC0B0) renders white text passes at y=10/50/90. UITimerTweenValueUpdate (0x004E0C90) decrements a UI value by dt*0.2 when active. renderDeviceInitialize (0x0053EB70) one-time-configures the D3D device and allocates buffers and a surface. RebuildFilteredNodeArray (0x00545A40) and RebuildSceneInstanceArray (0x00545BB0) rebuild length-prefixed 24-byte-entry arrays from two node lists by matching chain flags.

## Function roles

- `0x00496E90` **DamageUiRenderer** — Per-frame damage/repair UI update and render. Returns 0 immediately when CarCrashDamageProcessing reports active damage processing; otherwise, with a damage-state pointer at this+0x18 set, stores this+0x34 = sub_498E40(head), bails to -1 when dword_5CC9E8 != 5, triggers a redraw flush (ByteGetter0x25 / dword_7CE03C / draw count dword_5CC9E4), fills the 800x600 render surface (Accessor + RenderSurfaceFillCopy), walks up to 8 chained damage nodes (head at this+0x18, next link at node+0x68) invoking the vtable+8 coordinate getter and rendering each damage rectangle via sub_4919C0, destroys the chain (CollisionProxyListBuilder, vtable+52 virtual, LinkedListNodeUnlinkByContent), renders sub-screen (sub_495B60), text dialog (UITextDialogRendering), extra UI (sub_4973D0) and combo list (UIComboListRender), sets the state step at this+0x38 to 2, decrements the UI timer float at this+0x44 via FloatFieldAccessor and processes a string-table message (BinarySearchInStringTable into byte_5EC4CC, then sub_4989E0), then runs SceneEntityCleanup(1). With no damage state it dispatches a no-draw-stack message via UIMessageDispatch (global 0x005CCA30 string) and returns -1. Callers: sub_46BF10, sub_485B90, sub_4977E0.
- `0x004A0EB0` **OptionsSetupHandler** — Options/setup screen handler. Logs entry (DebugLogWrite into dword_8AD25C) when StringSplitLoop detects the options device-path string, then dispatches on session state flags: if byte_7CE260 (init guard) is set it forces byte_7C5690 = 1 and returns 0; else if dword_7CE264 (sub-mode selector) is set it either clears byte_5CCFE4 (setup flag) and returns 0 or reports waiting (returns 1); otherwise it runs the main setup processing loop: (re)initializes the conditional timer state (ConditionalInit/ArithmeticComparison on unk_8AFE18), processes the rate constant dbl_8AFE90 via sub_4537B0, increments the frame counter dword_7CE250, calls session processing sub_485B90(v1, byte_7CE25F), drives text overlay display timing (TextOverlayDisplayTimer), processes the setup-dir suffix (sub_404B60), breaks on byte_7CE25C (exit flag), returns 1 on v2 == -1, 0 on v2 == 1, resets the conditional state (ConditionalStateReset) and processes the session-queue object (sub_4A1830). Always returns 0 on normal loop exit after clearing byte_7CE25C.
- `0x004B5A30` **UiWidgetHierarchy** — Destroys the UI widget hierarchy on this. Calls SpriteOverlayListCleanup (no args), sub_4B5E50(this) and LinkedBufferTransfer(this); frees guarded heap buffers at this+0xF94, +0x72C, +0x724, +0x70C and +0x704 via FreeWrapper_7bcf; runs four linked-list destructor families over the widget sub-hierarchies at this+0x3908/+0x3924/+0x3940 (ListRebuildWithNodeTransfer, LinkedListDestruction, LinkedListDestructionWithRefCountLoop) and the widget-node lists at this+0x6D4 and this+0x6C0 (advancing by the next pointer at node+4), zeroing the four header fields of each list; frees the 104 consecutive list structures below this+0x6C0 with NodeDestructor; runs SubCallWithConditionalFieldFree on this+1764; destroys the remaining child lists at this+48 (LinkedListFree), this+32 (ListFullDestruction) and this+16 (LinkedListDestructorWithCallback) and returns the result of the final linked-list destroy helper on this. The final helper is not in the packet callee table. Single known caller: sub_4B41D0.
- `0x004C1E80` **GameOptionsState** — Game-options and career-stats file parser, gated on *a2 being non-zero. Loops over config tokens dispatched from the shared state object unk_8AC1E8 via ConditionalDispatchBasedOnFlag(256); each token is classified with sub_5651B0 and kinds 1 and 4 stop the parse (return 0). The Careerseason section (sub_587C20 prefix test against the aCareerseason string) allocates (OperatorNewNhMallocWrapper(45396)) and constructs a career-season state object (AudioSubsystemInitializer), reads it with CareerSeasonStateFileReader, wraps it in a 12-byte node (data, next, active flag) and appends it to the this-owned linked list (head this+0, tail this+4, tail-copy this+8, count this+0xC); on read failure the object is cleaned (PitStopMemoryCleanup) and freed. The Playertracksta section delegates to PlayerCareerStatsGameOptionsLoader(this). Any other section default-parses key=value tokens: integer totals/records into this+0x44..0x54, average floats into this+0x68/0x6C, mech-fail rate into this+0x54-adjacent, race-condition and game-option settings through this+0x58..0x8C. Returns 0. Called by the 004C22A0 dispatch.
- `0x004C5E50` **FilterPropertiesList** — Builds a linked list of filter-property entries for scene names that match all caller-supplied criteria. Iterates the global scene entries (count dword_8AC488, stride 396, name pool at dword_8AC490 + 260), skips indices present in the exclusion list (LinkedListKeySearch) and null scene entries, builds a 256-byte Filter Properties <scene> name with StringCopyWithValidation, validates it against every criterion a2[i] via sub_566810, then allocates a 16-byte filter property via sub_4C5C80 and a 12-byte list node via OperatorNewNhMallocWrapper, links it onto the result list (head this+0x8, tail this+0xC, permanent-first this+0x10, count this+0x14) and returns the number of matches. Called by SceneFileFilterBuilder.
- `0x004C5FD0` **FilterPropertiesList** — Builds a linked list of filter-property entries on this. Iterates the global filter-property table (dword_8AC488 entries, 396-byte stride, name copied from the aFilterProperti pool at v12 + dword_8AC490 + 260). Skips keys already present via LinkedListKeySearch and entries whose copied name matches no element of the selection array a2 (sub_566810). For each selected entry allocates a 16-byte node initialized with key v4 and the name via sub_4C5C80, wraps it in a 12-byte list element (element[0] = node, element[4] = next, element[8] = 1) and appends it to the list anchored at this+0x8 (head) / this+0xC (tail), writing this+0x10 for the first element and incrementing the count at this+0x14. Returns the number of appended items; 0 when any guard fails. Packet owner: FilterPropertiesList (DERIVED).
- `0x004CEEF0` **TerrainIniPathBuilder** — Constructs the file path to terrain.ini by formatting the season and track directory globals (dword_5EC3D8, dword_5EC420) into a caller-supplied buffer via StringFormatWithBufferOverflowCheck using the format literal at global 0x005D3930; each directory global falls back to the default application directory (byte_5EA438) when null. Parameter a2 is unused. Returns the result of the format call. Called from scene/particle/telemetry initialization paths (SceneTrackFileLoader 0044C0E0, ParticleSoundEffectSpawner 004607A0, SpecialFX_Init 004CF070, TelemetryDataDump 004D4A80).
- `0x004D9420` **StartingGridOverlay** — Renders the starting-grid HUD overlay. Reads the participant count at this+0x14; when non-zero draws grid car slots in two columns (left slots 2*v1-1/2*v1 via sub_4D95D0 at (100.0, 384.0), right slots 2*v1+1/2*v1+2 at (740.0, 384.0)) and returns. When zero it lazily initializes the shared text buffer (copying the Starting and Grid string constants through BinarySearchInStringTable into byte_5EC4CC), formats them with sub_587DD0 and renders both title lines via UITextRenderWithScale, formats a single position character (byte_5D4AEF) via StringFormatWithBufferOverflowCheck, renders it four times as position labels at y offsets computed from CRTFtol(v11 * -127.65), and finally draws slot pair 1/2 at the right column position. Returns 0.
- `0x004DC0B0` **DebugOverlayRenderer** — Renders a debug overlay by filling a local 64-byte buffer with SeasonNameLookup, then drawing it with UITextRenderWithScale in white (0xFFFFFF) passes at x = a1, y = 10. The lap-count line (sub_49C670) is drawn at the same position, followed by DoubleRenderPass(a1, 50) for the mid overlay row, then two more format/render pairs at y = 90 (sub_49C700 and sub_49C770). Returns the result of the final UITextRenderWithScale call. Structural twin of MultiColorTextRender (004DBF90) per the cluster prelabel.
- `0x004E0C90` **UiTimerTween** — Per-frame UI timer/tween update. When the active flag at this+0x894 is non-zero, fetches three UI element state fields via TripleFieldQuery, computes a decremented value as this+0x930 minus a2 * 0.2 (dt-scaled speed factor; constant associated with flt_59E7E8), and applies it through sub_54B4D0 with two zero float extras. Returns the apply result; returns an uninitialized value when inactive. Called by VehicleGraphicsSceneLoader (004DFCE0) and SteeringForceWithRandom (004F0DD0) on the frame path.
- `0x0053EB70` **RenderDevice** — One-time Direct3D render-device and buffer initializer guarded by the init flag at this+0x13A8 (bit 0x10000000). Configures device render states through the D3D device vtable (device pointer at this+0x1100, vtable slots +0xC8/+0xFC/+0x14C/+0x130), installs an identity transform matrix (vtable slot +0xA8), then allocates and initializes an index buffer (this+0x1140), a vertex buffer (this+0x113C) and a small surface object (this+0x1144), walks an emitter list at this+0x1518 (node next at +0x20) and a surface list at this+0x1580 (node next at +0x870, VertexBufferSurfaceInit), and optionally creates two audio emitters (this+0x151C/0x1520) when a2 is non-null. Sets this+0x13A8 |= 0x10000000 and returns 0 on success, -1 on buffer validation failure. Called from sub_53E070 and sub_555E50.
- `0x00545A40` **FilteredNodeArrayOwner** — Rebuilds a filtered array of 24-byte entries reachable from two linked node lists. Frees the previous array (24-byte stride elements with a 4-byte count header), allocates a new array sized to this+0x13C via the allocation wrapper, then walks a first node list from this+0x100 (forward link at node+0x104) and a second list from this+0x108. For each node it descends a sub-chain at node+0xEC and skips the node unless the sub-chain yields a node whose flags at +0x14 include 0x4000; matching outer nodes are appended at array+16 with a 24-byte stride. The second list appends entries after the first-list run without updating the entry counter. Always returns 0. Called by VertexBufferResourceAllocation (0x00543FA0).
- `0x00545BB0` **SceneInstanceCollection** — Rebuilds a filtered array of 24-byte scene-instance entries on this. When the entry count at this+0x174 is positive, frees the previous length-prefixed array at this+0x178 (per-element teardown via EmptyStub_0170, then FreeWrapper_7bcf), allocates a fresh length-prefixed array sized for the count, initializes each slot via ShortComputation_8e00, then walks two node lists (heads at this+0x100 and this+0x108). Nodes whose chain contains a sub-node carrying flag 0x20000 at +0x14 are appended into the array; nodes with the 0x40 flag at offset 4 are skipped. Always returns 0. Packet owner: SceneInstanceCollection (DERIVED, abi:lead). Called by VertexBufferResourceAllocation (0x00543FA0).

## Proposed classes

### DamageUiRenderer

In-race crash-damage / repair HUD state and renderer (0x00496E90). Owns a chained damage-node list (head this+0x18), a damage-state value this+0x34, a two-step state step this+0x38 (1 = init/process, 2 = render/process), a message string pointer this+0x3C, a UI timer float this+0x44 that gates the string-table message lookup, and a render-disabled byte this+0x24. Draws into the 800x600 render surface and dispatches a no-draw-stack UI message when no damage state is present. Owner is a GUESS synthesis; the packet owner is UnknownObject/UNKNOWN.

Methods: `0x00496E90`

- `this+0x00000018` `pointer damage_node_head` (read_write, DERIVED)
- `this+0x00000024` `byte render_disabled_byte` (read_write, DERIVED)
- `this+0x00000034` `dword damage_state_value` (read_write, DERIVED)
- `this+0x00000038` `dword state_step` (read_write, DERIVED)
- `this+0x0000003C` `pointer message_string` (read, DERIVED)
- `this+0x00000044` `float ui_timer` (read_write, DERIVED)

### DamageNode

Chained damage rectangle node traversed by DamageUiRenderer: vtable at node+0 (coordinate getter at vtable slot +8, per-node cleanup virtual at vtable +52) and a forward next link at node+0x68. Additional node fields at +0x34 (per static facts) and at +0xD0/+0x130 exist but do not appear in the rendered body. GUESS synthesis.

Methods: 

- `*(this+0x18)+0x00000000` `pointer node_vtable` (read, DERIVED)
- `*(this+0x18)+0x00000068` `pointer node_next` (read, DERIVED)

### OptionsSetupHandler

Options/setup screen state machine (0x004A0EB0). No this-fields are evidenced; all state is global: init guard byte_7CE260, sub-mode selector dword_7CE264, init-state flag byte_7C5690, setup flag byte_5CCFE4, exit flag byte_7CE25C, frame counter dword_7CE250 and session-queue object unk_7CE2A4. The loop drives session processing sub_485B90 and overlay timing. GUESS synthesis; packet owner is UnknownObject.

Methods: `0x004A0EB0`


### UiWidgetHierarchy

UI widget container whose teardown (0x004B5A30) frees guarded heap buffers and runs four linked-list destructor families. Holds two widget-node list headers at this+0x6C0 and this+0x6D4 (each head/tail/cursor/count over four consecutive dwords, next link at node+4), guarded buffer pointers at this+0x704/0x70C/0x724/0x72C/0xF94, and child list structures at this+16/+32/+48 and this+0x3908/+0x3924/+0x3940 (offsets cited only via the helper-call callee refs). Packet owner DERIVED by abi:lead.

Methods: `0x004B5A30`

- `this+0x000006C0` `pointer widget_list_head_a` (read_write, DERIVED)
- `this+0x000006C4` `pointer widget_list_tail_a` (write, DERIVED)
- `this+0x000006C8` `pointer widget_list_cursor_a` (write, DERIVED)
- `this+0x000006CC` `dword widget_list_count_a` (write, DERIVED)
- `this+0x000006D4` `pointer widget_list_head_b` (read_write, DERIVED)
- `this+0x000006D8` `pointer widget_list_tail_b` (write, DERIVED)
- `this+0x000006DC` `pointer widget_list_cursor_b` (write, DERIVED)
- `this+0x000006E0` `dword widget_list_count_b` (write, DERIVED)
- `this+0x00000704` `pointer buffer_704` (read, DERIVED)
- `this+0x0000070C` `pointer buffer_70C` (read, DERIVED)
- `this+0x00000724` `pointer buffer_724` (read, DERIVED)
- `this+0x0000072C` `pointer buffer_72C` (read, DERIVED)
- `this+0x00000F94` `pointer buffer_F94` (read, DERIVED)
- `*(*(this+0x6C0)+0x4)+0x00000004` `pointer widget_node_next_a` (read, DERIVED)
- `*(*(this+0x6D4)+0x4)+0x00000004` `pointer widget_node_next_b` (read, DERIVED)

### GameOptionsState

Parsed game-options and career-stats container (0x004C1E80). Owns a linked list of career-season state nodes (head this+0, tail this+4, tail-copy this+8, count this+0xC; node next link at +4) and the parsed totals/records fields at this+0x44..0x54 (total races, points, championships, wins, poles), averages at this+0x68/0x6C, plus mech-fail rate and race-condition/game-option settings through this+0x58..0x8C. GUESS synthesis; packet owner is UnknownObject.

Methods: `0x004C1E80`

- `this+0x00000000` `pointer list_head` (read_write, DERIVED)
- `this+0x00000004` `pointer list_tail` (read_write, DERIVED)
- `this+0x00000008` `pointer list_tail_copy` (write, DERIVED)
- `this+0x0000000C` `dword list_count` (write, DERIVED)
- `*(this+0x4)+0x00000004` `pointer node_next` (read_write, DERIVED)
- `this+0x00000044` `dword total_races` (write, DERIVED)
- `this+0x00000048` `dword points_scored` (write, DERIVED)
- `this+0x0000004C` `dword championships` (write, DERIVED)
- `this+0x00000050` `dword wins` (write, DERIVED)
- `this+0x00000054` `dword poles` (write, DERIVED)
- `this+0x00000068` `float avg_start_position` (write, DERIVED)
- `this+0x0000006C` `float avg_finish_position` (write, DERIVED)

### FilterPropertiesList

Linked list of scene filter-property entries built from the global 396-byte scene/filter-property pool (count dword_8AC488, pool base dword_8AC490). Both builder functions (0x004C5E50 by exclusion list + criteria, 0x004C5FD0 by selection array) append 12-byte nodes (node, next, active flag) to the same anchors: head this+0x8, tail this+0xC, permanent-first this+0x10, count this+0x14. Packet names this owner FilterPropertiesList (DERIVED for 0x004C5FD0); the 0x004C5E50 ownership is the same class by identical field layout (GUESS).

Methods: `0x004C5E50`, `0x004C5FD0`

- `this+0x00000008` `pointer list_head` (read_write, DERIVED)
- `this+0x0000000C` `pointer list_tail` (read_write, DERIVED)
- `this+0x00000010` `pointer list_permanent_first` (read_write, DERIVED)
- `this+0x00000014` `dword list_count` (read_write, DERIVED)

### TerrainIniPathBuilder

Formats the terrain.ini path into a caller buffer (0x004CEEF0) from the season/track directory globals dword_5EC3D8/dword_5EC420 with a byte_5EA438 default-directory fallback. Stateless; no class fields proposed. GUESS synthesis; packet owner is UnknownObject.

Methods: `0x004CEEF0`


### StartingGridOverlay

Starting-grid HUD overlay renderer (0x004D9420). Reads the participant count at this+0x14; draws two grid columns through sub_4D95D0, lazily caches the Starting/Grid title strings in the shared byte_5EC4CC buffer and renders title lines and four position labels through UITextRenderWithScale. GUESS synthesis; packet owner is UnknownObject.

Methods: `0x004D9420`

- `this+0x00000014` `dword participant_count` (read, DERIVED)

### DebugOverlayRenderer

White-pass debug overlay renderer (0x004DC0B0): formats season name / lap count / secondary fields into a 64-byte buffer and renders them at y = 10 / 50 / 90 via UITextRenderWithScale and DoubleRenderPass. Structural twin of the MultiColorTextRender (004DBF90) cluster copy. Stateless; no class fields proposed. GUESS synthesis; packet owner is UnknownObject.

Methods: `0x004DC0B0`


### UiTimerTween

Per-frame UI timer/tween driver (0x004E0C90): when the active flag at this+0x894 is set it decrements the value field at this+0x930 by dt * 0.2 and applies the interpolated triple via sub_54B4D0. GUESS synthesis; packet owner is UnknownObject.

Methods: `0x004E0C90`

- `this+0x00000894` `byte active_flag` (read, DERIVED)
- `this+0x00000930` `float tween_value` (read_write, DERIVED)

### RenderDevice

Direct3D render device wrapper initialized by 0x0053EB70. Holds the D3D device object pointer at this+0x1100, an index buffer at this+0x1140, a vertex buffer at this+0x113C, a surface at this+0x1144, an init flag at this+0x13A8 (bit 0x10000000), loop/config state around this+0x13B0..0x13D0, an emitter list head at this+0x1518 and a surface list head at this+0x1580, plus optional audio emitters at this+0x151C/0x1520 with teardown state at this+0x1554/0x1558. GUESS synthesis; packet owner is UnknownObject.

Methods: `0x0053EB70`

- `this+0x00001100` `pointer device_ptr` (read, DERIVED)
- `this+0x0000113C` `pointer vertex_buffer` (read_write, DERIVED)
- `this+0x00001140` `pointer index_buffer` (read_write, DERIVED)
- `this+0x00001144` `pointer surface` (read_write, DERIVED)
- `this+0x000013A8` `dword init_flags` (read_write, DERIVED)
- `this+0x000013B0` `dword loop_bound` (read, DERIVED)
- `this+0x00001174` `dword init_literal_256` (write, DERIVED)
- `this+0x000013BC` `dword init_literal_65538` (write, DERIVED)
- `this+0x000013C0` `dword init_literal_63` (write, DERIVED)
- `this+0x000013D0` `dword reset_field` (write, DERIVED)
- `this+0x00001518` `pointer emitter_list_head` (read, DERIVED)
- `this+0x00001580` `pointer surface_list_head` (read, DERIVED)

### RenderDeviceVtable

Virtual interface of the D3D device object at this+0x1100 (vtable pointer at +0x0): render-state setter at vtable slot +0xC8 (device field +0x0FC for the loop), transform install at slot +0xA8, clear at slot +0x130 and present at slot +0x14C. GUESS synthesis; concrete D3D method identities are not resolvable from the packet.

Methods: 

- `*(this+0x1100)+0x00000000` `pointer device_vtable` (read, DERIVED)
- `*(*(this+0x1100)+0x0)+0x000000C8` `pointer set_render_state` (read, DERIVED)
- `*(*(this+0x1100)+0x0)+0x000000FC` `pointer render_state_loop` (read, DERIVED)
- `*(*(this+0x1100)+0x0)+0x000000A8` `pointer set_transform` (read, DERIVED)
- `*(*(this+0x1100)+0x0)+0x00000130` `pointer clear_state` (read, DERIVED)
- `*(*(this+0x1100)+0x0)+0x0000014C` `pointer present` (read, DERIVED)

### FilteredNodeArrayOwner

Owner of a length-prefixed array of 24-byte filtered node entries rebuilt by 0x00545A40: entry count at this+0x13C, array pointer at this+0x140, and two source node lists at this+0x100 and this+0x108 whose nodes carry flags at +0x4 and sub-chain heads at +0xEC; chain nodes are selected when flags at +0x14 include 0x4000. GUESS synthesis; packet owner is UnknownObject.

Methods: `0x00545A40`

- `this+0x0000013C` `dword entry_count` (read, DERIVED)
- `this+0x00000140` `pointer array_ptr` (read_write, DERIVED)
- `this+0x00000100` `pointer first_list_head` (read, DERIVED)
- `this+0x00000108` `pointer second_list_head` (read, DERIVED)

### SceneInstanceCollection

Collection of scene instances owned by a renderer (0x00545BB0): entry count at this+0x174, length-prefixed 24-byte-entry array at this+0x178, and two source node lists at this+0x100 and this+0x108; nodes are filtered by sub-chain flag 0x20000 at +0x14 and skipped on the 0x40 byte flag at +0x4. Packet names this owner SceneInstanceCollection (DERIVED).

Methods: `0x00545BB0`

- `this+0x00000174` `dword entry_count` (read, DERIVED)
- `this+0x00000178` `pointer array_ptr` (read_write, DERIVED)
- `this+0x00000100` `pointer first_list_head` (read, DERIVED)
- `this+0x00000108` `pointer second_list_head` (read, DERIVED)

## Compatibility contracts

- **DamageUiRenderSequence** — A replacement for 0x00496E90 must first call CarCrashDamageProcessing and return 0 while it reports active processing; with a damage-state head at this+0x18 it must render into the 800x600 surface, walk up to 8 chained nodes (next at node+0x68) using the vtable+8 coordinate getter and sub_4919C0 for each rectangle, destroy the chain, render the sub-screen/text-dialog/combo overlays, set this+0x38 to 2 and process the timed string-table message; with no damage state it must dispatch the no-draw-stack message (global 0x005CCA30) via UIMessageDispatch and return -1. Guard on dword_5CC9E8 == 5 and redraw gates on ByteGetter0x25 / dword_7CE03C / dword_5CC9E4 must be preserved.
- **OptionsSetupLoop** — A replacement for 0x004A0EB0 must log options entry, force init state (byte_7C5690=1) when byte_7CE260 is set, handle the sub-mode selector dword_7CE264, and otherwise loop: increment dword_7CE250, call sub_485B90(v1, byte_7CE25F), drive overlay timing, break on byte_7CE25C and return 1 for a -1 result, 0 for a 1 result, and 0 on normal exit after clearing byte_7CE25C.
- **UiWidgetHierarchyTeardown** — A replacement for 0x004B5A30 must call SpriteOverlayListCleanup, sub_4B5E50(this) and LinkedBufferTransfer, free the guarded buffers at this+0xF94/+0x72C/+0x724/+0x70C/+0x704, run the four linked-list destructor families over the widget sub-hierarchies at this+0x3908/+0x3924/+0x3940 and the node lists at this+0x6D4/+0x6C0, free the 104 consecutive list structures below this+0x6C0, destroy the child lists at this+48/+32/+16 and return the result of the final linked-list destroy helper on this.
- **GameOptionsFileFormat** — A replacement for 0x004C1E80 must parse the config stream gated on *a2, stop on token kinds 1/4 (return 0), append Careerseason state nodes to the this-list (head this+0, tail this+4, tail-copy this+8, count this+0xC), delegate Playertracksta to PlayerCareerStatsGameOptionsLoader, and default-fill totals (this+0x44..0x54), averages (this+0x68/0x6C) and race/game-option settings from the 0x005D29xx..0x005D2Bxx string-table token globals.
- **FilterPropertiesListBuild** — A replacement for 0x004C5E50/0x004C5FD0 must iterate the global 396-byte scene/filter-property pool (dword_8AC488 count, dword_8AC490 base, name at +260), skip excluded keys via LinkedListKeySearch, validate names against criteria (sub_566810) or a selection array, and append 12-byte nodes (node, next, active flag) to the this+0x8/0xC/0x10/0x14 list, returning the match count and 0 when any guard fails.
- **TerrainIniPathFormat** — A replacement for 0x004CEEF0 must format the format string at global 0x005D3930 into the caller buffer a1 using the season directory (dword_5EC3D8) and track directory (dword_5EC420), each falling back to byte_5EA438 when null, and return the formatting result.
- **StartingGridOverlayRender** — A replacement for 0x004D9420 must draw left/right grid columns via sub_4D95D0 when the participant count at this+0x14 is non-zero, and otherwise lazily cache the Starting/Grid strings into byte_5EC4CC, render two title lines and four position labels via UITextRenderWithScale, and draw slot pair 1/2 at the right column position.
- **RenderDeviceInitSequence** — A replacement for 0x0053EB70 must skip entirely when the init flag at this+0x13A8 already has bit 0x10000000; otherwise configure the D3D device (this+0x1100) render states through its vtable, install an identity matrix, allocate and fill the index/vertex buffers (this+0x1140/0x113C) and surface (this+0x1144), walk the emitter (this+0x1518) and surface (this+0x1580) lists, optionally create two audio emitters when a2 is non-null, set the init flag and return 0 (-1 on buffer validation failure).
- **FilteredNodeArrayRebuild** — A replacement for 0x00545A40/0x00545BB0 must, when the entry count is positive, free the previous length-prefixed 24-byte-entry array, allocate a new one, walk the node lists at this+0x100 and this+0x108 (sub-chains at node+0xEC, chain forward link at +0x10, chain flags at +0x14), append nodes carrying the required flag (0x4000 for the filtered array, 0x20000 for scene instances), skip nodes with the 0x40 byte flag at +0x4, and return 0.

## Unresolved

- The this object types of DamageUiRenderer, OptionsSetupHandler, GameOptionsState, TerrainIniPathBuilder, StartingGridOverlay, DebugOverlayRenderer, UiTimerTween, RenderDevice and FilteredNodeArrayOwner are unknown; the packet owners are UnknownObject/UNKNOWN and no RTTI or constructor evidence was provided.
- Virtual dispatch targets for the damage node (vtable+8 coordinate getter, vtable+52 per-node cleanup) and the D3D device (slots +0xA8/+0xC8/+0xFC/+0x130/+0x14C) are not resolvable from the packet; concrete receiver types are unknown.
- Damage-node fields at *(*(this+0x18)+0x68)+0x34 and at *(this+0x18)+0xD0/+0x130 are read per static facts but do not appear in the rendered body; flt_59E440 and unk_7CDE00 are referenced by static facts but absent from the body.
- The final linked-list destroy helper whose result 0x004B5A30 returns has no entry in the packet callee table, so its address cannot be cited.
- Several UiWidgetHierarchy child-list offsets (this+16/+32/+48/+1764/+1812/+3908/+3924/+3940) have no packet field evidence refs; only the helper-call callee refs are citable for them.
- GameOptionsState field widths (int vs float) for this+32..140 and the 12-byte career-node layout (0/4/8) are grounded in raw source only, not in the deterministic fact table; semantics of dispatch objects unk_8AC050/unk_8AC1E8 are unknown.
- FilterPropertiesList: the 16-byte filter property layout from sub_4C5C80 and the element[8] active-flag meaning are unproven; global unk_8AC368 is read per facts but absent from the body.
- RebuildFilteredNodeArray: the extraction-listed second-list field paths rooted at this+0x30C and this+0x154 do not map one-to-one onto the raw C node traversal; the second list appends without incrementing the entry counter (whether intentional is unknown); the 24-byte entry layout and the 0x4000 flag meaning are unconfirmed.
- RebuildSceneInstanceArray: whether flag 0x20000 selects renderable instances or another visibility class is unknown; the 24-byte entry slot start at +16 and the 0x40 skip flag are inferred.
- StartingGridOverlay: association of flt_5ACF64 with the 384.0 column y and of global 0x005CCEF0 with the %c format are per existing analysis and not verifiable from the packet alone.
- UITimerTweenValueUpdate: the identity/layout of the three TripleFieldQuery fields and the meaning of the two zero float arguments to sub_54B4D0 are unknown; flt_59E7E8 as the 0.2 speed-factor source is inferred.
- UIDebugOverlayRender: global unk_7CE234 is declared but never referenced in the body; the UITextRenderWithScale parameter tuples (alignment/style/alpha enums) are not derivable here.
- The ui_platform_and_options grouping across the 13 functions is scope-level only; no common ownership is evidenced and most class boundaries are synthesis on top of the packet operations.
