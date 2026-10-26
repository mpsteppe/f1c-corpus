# UIPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

Evidence-linked reconstruction of the UI platform and options subsystem. A shared parser controller (UIElementParser) consumes token streams through a per-iteration token reader, constructs layer objects and tree nodes, binds surfaces, gizmos and pages, and appends typed action-command nodes to event chains. A keyword-driven widget factory builds 23 widget types by name. Registry lookup, session-mode page dispatch, the Win32 game window lifecycle, player/settings path construction, HUD warning-icon composition, texture-variant loading and an oscillation sample list builder complete the cluster. Ownership of the parser controller and every concrete widget type is not proven by the packet; class names and responsibilities are DERIVED or GUESS proposals.

## Function roles

- `0x00492460` **UIElementParser** — Parses a UI layer definition: classifies the layer name against normal/modal, constructs the matching layer object (188 bytes), links it into the layer list, and dispatches child tokens (name, sound focus/lost focus, gizmo, page) to element, texture and gizmo handlers.
- `0x00492710` **UIElementParser** — Parses a stream of UI element configuration tokens (name, enter/escape target, location, posWH, location2, surface, gizmo) and builds them into a tree node registered with the owning tree.
- `0x00493480` **UIElementParser** — Parses UI action commands from a token stream: matches command keywords (DoPage 1, DoPageTransition 2..6, TransitionAttr, DoLayer 7, SetSymbol 9, DropPopups 10, ExitGame 11, SimulateClick 12), tags 28-byte nodes, and appends them to the event action chain selected by the Click/Release/Focus/Lostfocus trigger keyword.
- `0x00493E20` **UIElementParser** — Builds a resource file path into a 256-byte buffer by repeating directory prefixes based on the parser nesting depth and appending the filename, and optionally writes the assembled path to the parser write stream.
- `0x00493FC0` **UIWidgetFactory** — Finds an existing UI widget by name through the child container vtable or, on a miss, scans the 23-entry keyword table and dispatches the matched index through a jump table to a per-type constructor; applies a prelink-gizmo label to newly created widgets.
- `0x00495120` **RenderDeviceFieldsAccessor** — Reads two DWORD fields at the global render-device object (offsets +28 and +32) into caller output pointers and returns the global pointer.
- `0x004976C0` **UIWidgetRegistry** — Searches a two-level nested linked list by name: walks outer list nodes, retrieves inner list heads, and compares the inner item name at byte offset 52, returning the last matching item.
- `0x004A0430` **UISessionPageDispatcher** — Dispatches a UI page lookup based on the session mode value: modes 1..4 open the monitor page, mode 5 opens the multiplayer host or client grid page depending on a module-manager state check.
- `0x004A1200` **GameWindowManager** — Creates the main game window: formats a title from the game name and version, fills and registers WNDCLASSEX structs for the cube-realtime class and an optional message-window class, creates the windows, clips the cursor and shows the window.
- `0x004A14E0` **GameWindowManager** — Destroys up to two windows and unregisters their window classes at shutdown, guarding against a double-destroy when both handles are equal, then releases the cursor clip.
- `0x004B01B0` **GameFilePathBuilder** — Builds a full player file path in a caller buffer: copies and re-appends the source name and appends the '.PLR' extension; used by the file-copy dispatch and text-file reader paths.
- `0x004B52A0` **DualListRebuilder** — Rebuilds a target list by transferring every node of a source list: searches, unlinks, optionally frees the node data buffer, and prepends a fresh 12-byte node carrying the same data pointer to the target list.
- `0x004B9830` **GameFilePathBuilder** — Builds a file path by selecting the current directory (falling back to the default application path), copying it with reallocation, and appending the '.vcr' extension.
- `0x004DBA00` **HUDWarningIconComposer** — Composes a HUD warning-icon string from three warning conditions and renders it with scale when any warning is active.
- `0x004E39D0` **UIElementDispatchGroup** — Iterates an array of sub-elements on the receiver and dispatches a float value to each element, returning the element count.
- `0x004FC400` **TextureVariantLoader** — Builds up to four texture-variant paths with a letter suffix (splitting the base name from its extension, defaulting the extension, stripping a trailing A..D letter) and submits each variant to the texture adjuster.
- `0x004FD8B0` **OscillationSampleBuilder** — Rebuilds a linked list of oscillation samples from clamped random-noise and sinusoidal motion, terminating when the accumulated time exceeds the threshold.

## Proposed classes

### UIElementParser

Parses UI definition and command token streams: constructs layer objects and tree nodes, binds surfaces/gizmos/pages, appends typed action-command nodes to event chains, and builds resource paths. Reentrancy is guarded by a parse-depth counter at this+0x194 shared by all four methods.

Methods: `0x00492460`, `0x00492710`, `0x00493480`, `0x00493E20`

- `this+0x00000004` `void* WriteStream` (read, DERIVED)
- `this+0x00000014` `void* ActionChainTail` (read_write, GUESS)
- `this+0x00000194` `int ParseDepthCounter` (read_write, DERIVED)
- `this+0x0000019A` `byte WriteModeFlag` (read, DERIVED)
- `this+0x0000019C` `unsigned short ResourcePathDepth` (read, DERIVED)
- `this+0x000001A8` `void* CurrentLayer` (read_write, DERIVED)
- `this+0x000001AC` `void* CurrentTreeNode` (read_write, DERIVED)

### UIWidgetFactory

Creates UI widgets by name: reuses an existing widget from the child container or constructs one of 23 keyword-table widget types through per-index constructors (228..772 bytes), installing dedicated vtables on some types, and applying a prelink-gizmo label to new widgets.

Methods: `0x00493FC0`

- `this+0x000001A4` `void* ChildWidgetContainer` (read, GUESS)

### UIWidgetRegistry

Searches a two-level nested linked list of named UI widgets, returning the last item whose name matches the query.

Methods: `0x004976C0`

- `this+0x00000004` `void* OuterListHead` (read, GUESS)
- `this+0x0000000C` `void* TraversalCursor` (read_write, GUESS)

### UISessionPageDispatcher

Selects the UI page to open from the global session-mode value and the module-manager multiplayer state, routing all lookups through the dispatch interface.

Methods: `0x004A0430`


### GameWindowManager

Creates and destroys the main game windows: registers/unregisters the cube-realtime window class and an optional message-window class, formats the title, creates the windows into the global handles, and manages cursor clipping. All state is in process globals rather than a this-object.

Methods: `0x004A1200`, `0x004A14E0`


### GameFilePathBuilder

Free-standing file path construction helpers that produce player files ('.PLR') and settings files ('.vcr'), selecting the current directory with a default-path fallback.

Methods: `0x004B01B0`, `0x004B9830`


### DualListRebuilder

Rebuilds a target list by transferring nodes from a source list: search/unlink/free and prepend fresh 12-byte nodes carrying the same data pointers, maintaining head/tail/anchor/count fields on both lists.

Methods: `0x004B52A0`

- `this+0x00000010` `void* TargetHead` (read_write, GUESS)
- `this+0x00000014` `void* TargetTail` (read_write, GUESS)
- `this+0x00000018` `void* TargetAnchor` (read_write, GUESS)
- `this+0x0000001C` `int TargetCount` (read_write, GUESS)
- `this+0x00000020` `void* SourceHead` (read_write, GUESS)
- `this+0x00000024` `void* SourceTail` (read_write, GUESS)
- `this+0x00000028` `void* SourceCursor` (read_write, GUESS)
- `this+0x0000002C` `int SourceCount` (read_write, GUESS)
- `this+0x00000030` `int Sentinel` (write, GUESS)

### RenderDeviceFieldsAccessor

Reads two DWORD fields from the global render-device object into caller-supplied outputs and returns the global pointer. Field meaning as viewport/surface dimensions is carried from existing analysis only.

Methods: `0x00495120`


### HUDWarningIconComposer

Queries three warning conditions (general, fuel/low-fuel, two-state indicator) and composes a short icon string rendered with scale into the scene.

Methods: `0x004DBA00`


### UIElementDispatchGroup

Dispatches a float value to each sub-element in an array of 748-byte-stride elements, gated by the element count field.

Methods: `0x004E39D0`

- `this+0x00000BA8` `int ElementCount` (read, DERIVED)

### TextureVariantLoader

Builds up to four texture-variant paths with a letter suffix (A..D), splitting the base name from its extension and defaulting the extension when absent, and registers each variant with the texture adjuster.

Methods: `0x004FC400`


### OscillationSampleBuilder

Rebuilds a linked list of oscillation samples driven by clamped random-noise and sinusoidal motion, storing per-node float outputs and a next link; terminates when accumulated time exceeds a threshold.

Methods: `0x004FD8B0`

- `this+0x00000038` `void* TraversalCursor` (read_write, GUESS)
- `this+0x0000003C` `void* ListHead` (read_write, GUESS)
- `this+0x00000040` `float SnapThreshold` (read, GUESS)
- `this+0x00000044` `void* HeadNodePtr` (read, GUESS)

## Compatibility contracts

- **ui_layer_definition_grammar** — A layer definition stream must be parseable as: a layer name classified against the normal/modal literals (unknown types format 'undefined layer type %s' into byte_7CDCF0 and are reported), followed by child tokens name (path-resolved when the parser write flag is set and the path depth is below 4), sound focus / sound lost focus (copied into the layer at byte offsets 108 and 148 and texture-loaded), gizmo (prelinked) and page. The token stream terminates at the asc_5CC4F4 end-marker.
- **ui_action_command_grammar** — Action commands are 28-byte nodes tagged with a type 1..12 (DoPage 1, DoPageTransition variants 2..6, DoLayer 7, SetSymbol 9, DropPopups 10, ExitGame 11, SimulateClick 12) holding a copy of the token string, appended to the event action chain selected by the Click/Release/Focus/Lostfocus trigger keyword matched against the event spec.
- **ui_widget_keyword_table** — A 23-entry keyword table off_5CC270 maps widget names to per-index construction paths (allocations of 228..772 bytes and type-specific constructors, with dedicated vtables on some indices); index 14 produces no widget and construction fails for it. Widget creation is a lookup-then-create protocol against the child container.
- **resource_path_construction** — Resource paths are built into a 256-byte buffer by repeating the directory prefix word_5C406C (word_5C32D8 beyond four repeats) four-times-per-nesting-depth, appending the filename and the two-byte terminator word_5C30B4; when the write-mode flag is set and the write stream exists the path is written via StringFormatWithNestedIO.
- **player_and_settings_file_extensions** — Player files are built by normalizing/re-appending the player name and appending the '.PLR' extension; settings/stream paths select the current directory (falling back to the default application path) and append the '.vcr' extension.
- **game_window_lifecycle** — Window creation registers the 'CubeRealTime' window class (and an optional ClassName message-window class), creates the window(s) into the globals at 0x7CE2DC/0x7CE2E0, clips the cursor and shows the window. Shutdown destroys and unregisters both windows, guarding the equal-handle double-destroy case, and releases the cursor clip. Class registration failures abort with a non-zero result.
- **session_mode_page_mapping** — A session mode value at dword_7D0410 of 1..4 opens the monitor page; a value of 5 opens either the multiplayer host grid or client grid page depending on the module-manager state check. All page opens go through the dispatch interface at dword_7CD8C0 with a -1 flag.
- **oscillation_sample_format** — Oscillation samples are 16-byte linked-list nodes: node+4 holds the vertical amplitude output, node+8 the clamped (0.0..1.0) lateral snap output (snapped to 0.625/0.6 within a narrow band), node+12 the next link, and the head data slot accumulates time; list building stops when the accumulated time exceeds the threshold argument.

## Unresolved

- buildOscillationSampleList has a direct ABI conflict: its ABI lead names Rain_Drop_Spray_Particle_Generator (LEGACY) while existing analysis labels it CameraOscillationGenerator; the packet cannot decide whether the sample list drives rain spray or camera sway.
- The owner object of UIElementParser (this+0x194 depth, this+0x19A flag, this+0x19C depth, this+0x1A8 layer, this+0x1AC node, this+0x14 chain tail, this+0x4 write stream) is never identified; every function owner is UnknownObject in the packet. Class membership is inferred from the shared field offsets plus the direct caller link 0x00492460 -> 0x00492710.
- The token buffer writes at layer byte offsets 108 and 148 are decompiler pointer arithmetic; the exact field semantics of those two strings are unknown.
- The semantics of the action-command node type tags 1..12 beyond command identity are unknown; the 28-byte / 7-field sentinel node layout is not further interpreted.
- The semantics of the widget field at byte offset 140 (non-zero suppresses the prelink label) and of the color-like constants 3289650 / 789516 at widget byte offsets 228 and 232 are unknown.
- Keyword index 14 in the widget table has no switch case and produces no widget; the reason is unresolved.
- The exact stream/token framing protocol of sub_491FB0 is not evidenced in the packet; loop termination and token framing semantics are DERIVED.
- unk_7CD9D8 appears in the packet global table but is not referenced by any visible raw source; its role is unaccounted for.
- The relationship between the parser depth counter at this+0x194 and callers' reentrancy guarantees is unresolved.
- The meaning of the -51331646 sentinel written to DualListRebuilder this+0x30 and of the per-node flag byte at node+8 that gates the data-buffer free are unknown.
- The exact visual/modal role of the secondary message window created in the message-window mode path is inferred, not confirmed.
- The role of the read-only constants dword_8B8DC8+28 / +32 as viewport or render-surface dimensions comes only from existing analysis; the raw source proves only two unconditional reads of an unvalidated global pointer.
- The mapping of individual read-only constant-pool globals (flt_59E*, flt_5AD*) to the specific arithmetic literals in the oscillation math is not established from this packet alone.
- The exact pairing of the format-string globals aSS/aSC/aSCS with the '%s%c%s' / '%s%s' / '%s%c' literals in TextureVariantPathBuilder is inferred, not directly evidenced.
- The on-screen meaning of the four warning icon bytes (-126, 68, -116, -115) and of the two state codes (1 and 2) in UIMessageCompose is DERIVED from existing analysis only.
- Sub-element layout behind UIElementMultiDispatch (748-byte stride array at this[747]) and the effect of sub_4DF030 on each element are unknown.
