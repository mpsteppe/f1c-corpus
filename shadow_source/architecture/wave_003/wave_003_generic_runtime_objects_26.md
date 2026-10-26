# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposes 14 classes over 22 functions. The strongest grouping is TimerDisplay (TimerCountdown 0x004D98A0 + TimerDisplayRender 0x004D9DD0), justified by the packet's caller/callee edge TimerDisplayRender -> TimerCountdown(this). TextureMaterialSelector groups StringCompareCopy (0x004DC450) with its caller AdjustTextureMaterial (0x004DC770). PitCrewSpawner groups zeroInitWrapper (0x004DDF70) and PitCrewInstanceSetupWithPath (0x004E2A60) over the shared dword_8AC394 + 1060*index addressing and the shared PitCrewInstanceSetup callee. RaceInfoOverlayRenderer and SceneGraphUtil are GUESS groupings based on shared helper families only, with no proven common owner. All other classes are single-function. Shared text services (UITextRenderWithScale, BinarySearchInStringTable, safe copy/format, sanitizer, debug log) are exposed as interfaces consumed by the HUD classes.

## Function roles

- `0x004D98A0` **TimerDisplay** — Countdown phase handler: decrements the countdown timer at this+0x10 by the delta-time constant dbl_8AFE98 each call, returns 1 once it drops below 0, and while the current-player pointer is live renders the player's grid-position character, driver name and team/car name HUD block.
- `0x004D99E0` **VenueHudDisplay** — Venue/track-name HUD overlay: timer-gated via this+0x10, resolves a venue name and a secondary string from the race database via StringKeyedLinkedListSearch/DataEntryAccessor, renders them along with a decorative separator character row.
- `0x004D9DD0` **TimerDisplay** — Timer HUD render: delegates countdown handling to TimerCountdown(this), draws a red/green separator pair at (924,858)/(1180,858) and a yellow centered track/venue label at (1052,858); returns the TimerCountdown status.
- `0x004DA9E0` **SessionTimeHudRenderer** — HUD text renderer: produces a lap-count line ('<lap> <LAPS>') for single-lap sessions or a remaining-session-time line ('%.3f' / '%d:%06.3f'), plus a position-suffix character, and renders/stores both texts.
- `0x004DB070` **ThreeFieldStateObject** — Constructor for a 4-field object: installs the vtable off_5AD06C at +0x0, stores the caller identifier a2 at +0x4 and flag byte a3 at +0x8, zeroes +0xC; returns this.
- `0x004DB0E0` **SmallStateObject** — Constructor for a 4-field object: writes type code 1 at +0x4 and flag 1 at +0x8, zeroes +0xC, installs the vtable off_5AD034 at +0x0; returns this.
- `0x004DB6F0` **PositionIndicatorHud** — Renders a position or gear indicator text: resolves localized error/neutral strings or formats the numeric value a1, flips color to red when the appearance-flag mask (sub_49B7A0(...) & 0xF) equals 0xF, and draws via UITextRenderWithScale.
- `0x004DBDE0` **ShadowedTextRenderer** — Renders text twice at the same position for a drop-shadow effect: shadow pass (mode 1, alignment 2) then foreground pass (mode 0, alignment 1), formatting a 64-byte stack buffer via sub_49C8F0/sub_49C960.
- `0x004DBE60` **RaceInfoOverlayRenderer** — Multi-layer race information overlay: the race-distance sentinel dword_8ACF8C selects the primary shadowed layout at (a1+50,10) or a yellow lap-count line at (a1+215,46); two secondary shadowed layers always render at (a1+50,50).
- `0x004DBF90` **RaceInfoOverlayRenderer** — Race-information overlay: renders a yellow lap-count line at (a1+215,46) and two left text rows at (a1+15,10) and (a1+15,90), each drawn white then yellow.
- `0x004DC1A0` **DoublePassTextRenderer** — Drop-shadow text helper structurally identical to RenderTextWithShadow but with its own format helpers (sub_49BB40/sub_49BBB0) and a caller-supplied position (a1,a2).
- `0x004DC450` **TextureMaterialSelector** — Path compare/copy: copies the directory portion of a path into the global path buffer byte_5EA438, matches the filename against a criteria parameter, and conditionally copies the extension-stripped filename when the flag a4 is set.
- `0x004DC770` **TextureMaterialSelector** — Adjusts a texture material assignment: validates inputs and texture-ID resolution, compares the resolved ID against up to three alternative paths via StringCompareCopy, and logs an 'Unable to adjust texture' message on total failure.
- `0x004DCBA0` **TextureRenderObject** — Texture/rendering object init: clears prior state via ResourceCleanup, optionally registers and allocates a 96-byte child object, attempts D3DTextureCreation with a fallback constructor, and stores configuration parameters on failure.
- `0x004DD030` **ClippedTextRenderer** — Renders text with scale, alignment and bounds-aware clipping/truncation: resolves the font from this+0x28, persists positive scale to this+0x30/+0x34, clips against the object anchor, and delegates the final draw to ScaledTextureRender.
- `0x004DD550` **SceneGraphUtil** — Computes a 3D axis-aligned bounding box over a scene-graph node's children: derives a LOD detail threshold, filters children by detail level, and folds packed-array vertex extents into min/max buffers.
- `0x004DDF70` **PitCrewSpawner** — Indexed pit-crew initialization wrapper: computes the element address dword_8AC394 + 1060*a1 in the pit-crew array and forwards a2/a3 with a constant 0 to PitCrewInstanceSetup.
- `0x004DFA60` **VehicleAudioTransform** — Conditional audio/transform setup for a vehicle audio object: stores a parameter at this+0x42, branches on the object pointer at this+0x00, applies dual-matrix transforms or clears the six fields, sets readiness flags, and builds a rotation matrix.
- `0x004E0D70` **ResourceListNode** — Conditionally releases a resource element: when *a1 is non-null and the init flag at a1+0x40 is set, transplants the node from its doubly-linked list, clears the flag and updates the flag field.
- `0x004E1970` **SubsystemReadinessTable** — Startup helper: queries subsystem readiness for indices 0..13 via SubsystemReadyQuery and stores the results into the 14-dword table at this+0xB70.
- `0x004E2A60` **PitCrewSpawner** — Resolves the pit-crew setup inputs for a vehicle skin and instantiates the crew model: computes the crew target from the skin object's vehicle index (+0x4898), selects a skin/path override for the player, and calls PitCrewInstanceSetup.
- `0x004E2D00` **SceneGraphUtil** — Scene-graph vertex clustering for LOD generation: assigns vertices to the nearest of four reference clusters, allocates per-cluster packed arrays, and writes projected normals with a clamped LOD blend weight.

## Proposed classes

### TimerDisplay

Countdown timer state and its HUD rendering: decrements the countdown field at +0x10 by the delta-time constant on each call and renders the driver/position/venue text while the countdown is active. Grouping is justified by the packet edge TimerDisplayRender -> TimerCountdown(this).

Methods: `0x004D98A0`, `0x004D9DD0`

- `this+0x00000010` `float countdownTimer` (read_write, DERIVED)

### VenueHudDisplay

Timer-gated venue/track-name HUD overlay: renders the venue name, a decorative separator character row and a secondary string resolved from the race database via string-keyed search.

Methods: `0x004D99E0`

- `this+0x00000010` `float displayTimer` (read_write, GUESS)

### SessionTimeHudRenderer

HUD text renderer producing a lap-count or remaining-session-time line with a position-suffix character; reads the lap count at this+0x24 and session totals from an external session object (a3).

Methods: `0x004DA9E0`

- `this+0x00000024` `int lapCount` (read, GUESS)

### ThreeFieldStateObject

Small 4-field object constructed with a caller-supplied identifier at +0x4 and a flag byte at +0x8; vtable off_5AD06C. Same slot layout as SmallStateObject but a distinct vtable proves a distinct type.

Methods: `0x004DB070`

- `this+0x00000000` `void* vtable` (write, DERIVED)
- `this+0x00000004` `int identifier` (write, GUESS)
- `this+0x00000008` `byte flagByte` (write, GUESS)
- `this+0x0000000C` `dword reserved` (write, GUESS)

### SmallStateObject

Small 4-field object constructed with a fixed type code 1 at +0x4 and a fixed flag 1 at +0x8; vtable off_5AD034. Distinct from ThreeFieldStateObject because of the different vtable and different constructor constants.

Methods: `0x004DB0E0`

- `this+0x00000000` `void* vtable` (write, DERIVED)
- `this+0x00000004` `int typeCode` (write, GUESS)
- `this+0x00000008` `byte flag` (write, GUESS)
- `this+0x0000000C` `dword reserved` (write, GUESS)

### PositionIndicatorHud

Renders a position or gear indicator text at screen coordinates, resolving localized error/neutral strings or formatting the numeric value; color flips to red when the appearance-flag mask (sub_49B7A0(...) & 0xF) equals 0xF.

Methods: `0x004DB6F0`


### ShadowedTextRenderer

Renders text twice at the same position for a drop-shadow effect: shadow pass (mode 1, alignment 2) then foreground pass (mode 0, alignment 1), formatting a 64-byte stack buffer via sub_49C8F0/sub_49C960.

Methods: `0x004DBDE0`


### RaceInfoOverlayRenderer

Race-information HUD overlay renderers producing multi-layer shadowed text or white/yellow double-pass rows, with the primary layout selected by the race-distance sentinel dword_8ACF8C. GUESS grouping: both functions share the 0x49Cxxx format-helper family and identical double-pass rendering pattern, but no common `this` is proven.

Methods: `0x004DBE60`, `0x004DBF90`


### DoublePassTextRenderer

Drop-shadow text helper that renders a caller-supplied string twice at a caller position (shadow then foreground) with its own format helpers sub_49BB40/sub_49BBB0.

Methods: `0x004DC1A0`


### TextureMaterialSelector

Texture material resolution and adjustment: compares a resolved texture ID against up to three alternative path strings (StringCompareCopy) and logs a debug message when no alternative matches.

Methods: `0x004DC450`, `0x004DC770`


### TextureRenderObject

Texture/rendering object initialization: clears prior state, optionally registers and allocates a 96-byte child object, attempts D3D texture creation with a fallback constructor, and stores configuration parameters on failure.

Methods: `0x004DCBA0`

- `this+0x00000004` `void* childObject` (write, DERIVED)
- `this+0x00000014` `int configA` (write, GUESS)
- `this+0x00000018` `int configB` (write, GUESS)
- `this+0x0000001C` `int configC` (write, GUESS)

### ClippedTextRenderer

Renders text with scale, alignment and bounds-aware clipping/truncation: resolves the font from this+0x28, persists positive scale to this+0x30/+0x34, clips against the object anchor, and delegates the final draw to ScaledTextureRender.

Methods: `0x004DD030`

- `this+0x00000028` `char* fontSlot` (read, GUESS)
- `this+0x00000030` `float scaleX` (write, GUESS)
- `this+0x00000034` `float scaleY` (write, GUESS)

### SceneGraphUtil

Scene-graph traversal utilities for LOD: computes an AABB over a node's children and clusters vertices into LOD groups using packed arrays. GUESS grouping: both functions share the scene-graph child and packed-array accessor family, but no common owner is proven.

Methods: `0x004DD550`, `0x004E2D00`

- `this+0x00000150` `float[3][] clusterReference` (read, GUESS)
- `this+0x000001F4` `void*[] clusterArray` (read_write, GUESS)
- `this+0x000001F8` `dword[] clusterSlot` (read_write, GUESS)
- `this+0x00000890` `void* sceneNode` (read, DERIVED)
- `this+0x000008E4` `void* workingChild` (write, DERIVED)

### PitCrewSpawner

Pit-crew model instantiation: computes the crew instance target in the 1060-byte-strided array at dword_8AC394 and forwards setup arguments/paths to PitCrewInstanceSetup. Grouping justified by the shared addressing scheme and shared callee.

Methods: `0x004DDF70`, `0x004E2A60`

- `this+0x00000000` `void* skinObject` (read, GUESS)
- `this+0x00000090` `char* pathSlot` (read, GUESS)
- `obj+0x00004898` `int vehicleIndex` (read, DERIVED)

### VehicleAudioTransform

Vehicle audio/transform setup object: stores a parameter byte, branches on an object pointer, mixes audio physics, applies dual-matrix transforms across six fields, sets readiness flags and builds a rotation matrix.

Methods: `0x004DFA60`

- `this+0x00000000` `void* objectPtr` (read, GUESS)
- `this+0x00000004` `dword matrixField0` (read_write, GUESS)
- `this+0x00000008` `dword matrixField1` (read_write, GUESS)
- `this+0x0000000C` `dword matrixField2` (read_write, GUESS)
- `this+0x00000010` `dword matrixField3` (read_write, GUESS)
- `this+0x00000014` `dword matrixField4` (read_write, GUESS)
- `this+0x00000018` `dword matrixField5` (read_write, GUESS)
- `this+0x00000040` `byte transformReady` (write, GUESS)
- `this+0x00000041` `byte flagByte` (write, GUESS)
- `this+0x00000042` `byte paramByte` (write, DERIVED)

### ResourceListNode

Resource slot element: releases the element by transplanting its node from a doubly-linked list when the init flag at +0x40 is set, then updates the flag field.

Methods: `0x004E0D70`

- `this+0x00000000` `void* elementPtr` (read, DERIVED)
- `this+0x00000040` `byte initFlag` (read_write, DERIVED)

### SubsystemReadinessTable

Startup helper object holding a 14-dword subsystem-readiness table at this+0xB70, populated from SubsystemReadyQuery for indices 0..13.

Methods: `0x004E1970`

- `this+0x00000B70` `int[14] readinessTable` (write, DERIVED)

## Compatibility contracts

- **HudTextRenderSignature** — All HUD text passes call UITextRenderWithScale (0x004D7E40) with a text buffer, integer x/y screen positions, a 24-bit color literal, a font/alignment selector and scale X/Y; call sites in this packet use a consistent argument ordering, e.g. (buffer, 924, 858, 16711680, 0, 3, 1.0, 1.0) and (buffer, 210, 818, ..., 1.0).
- **CountdownTimerSemantics** — The countdown object field at +0x10 is decremented by the delta-time constant dbl_8AFE98 on each call; the object reports active (returns 0) while the timer is >= 0 and expired (returns 1) once it drops below 0.
- **StringTableDisplayBufferPair** — String lookup uses BinarySearchInStringTable (0x00423A00) with the table buffer byte_5EC4C0 and the working/display buffer byte_5EC4CC; matched strings are copied into byte_5EC4CC before rendering.
- **PlayerHudStrings** — While the current-player vehicle pointer (dword_7C54E0) is non-null, HUD reads a grid index at vehicle+0x4060 (16480) and ASCII name strings at vehicle+0x46F8 (18168, driver name) and vehicle+0x46B8 (18104, team/car name). Names are inferred from rendering positions, not proven.
- **PitCrewArrayStride** — Pit-crew instances are stored in an array based at dword_8AC394 with a per-entry stride of 1060 bytes; setup writes into dword_8AC394 + 1060 * vehicleIndex, where vehicleIndex is read from the skin object at +0x4898.
- **SceneGraphChildAccess** — A scene-graph node exposes a child count (SceneGraphChildCount), indexed child access (LinkedListIndexedAccessor) and per-child packed vertex arrays (PackedArrayTotalSize / PackedArrayIndexLookup); a per-child float at child+0xF4 (244) participates in LOD detail filtering.

## Unresolved

- All packet owners are UNKNOWN at the source-class level; class groupings are DERIVED from call edges and shared callee families, not from a confirmed class hierarchy.
- ThreeFieldStateObject and SmallStateObject share the identical slot layout (vtable +0x0, code +0x4, flag +0x8, reserved +0xC) but distinct vtables (off_5AD06C vs off_5AD034) and different constants prove distinct types; the shared layout must not be read as shared ownership.
- dword_7C54E0 (current player vehicle) and dword_7C54E8 differ by one dword; their relationship (player vehicle vs current slot) is not proven by this packet.
- The driver-name and team/car-name strings at vehicle+0x46F8/+0x46B8 are inferred from their HUD rendering positions; no field-naming evidence exists in the packet.
- RaceInfoOverlayRenderer is a GUESS grouping: 0x004DBE60 and 0x004DBF90 share the 0x49Cxxx format-helper family and the double-pass pattern but no proven common `this`.
- SceneGraphUtil is a GUESS grouping: 0x004DD550 and 0x004E2D00 share the scene-graph child and packed-array accessor family but have no proven common owner; the a2 min / a3 max buffers of 0x004DD550 are caller-owned outputs, not instance fields (packet labels field:this:0x0/0x4/0x8 for them).
- The exact layout of the 74-dword cluster entry at vertexCluster+0x150 is inferred (center positions at dwords 82..84, transform rows at dwords 88..96); only +0x150 is listed as a packet field.
- The BitFlagReader output byte this+0x41 in VehicleAudioTransform is unknown beyond the observable (a2 != 0) store.
- The EulerToRotationMatrix destination at this+0x1C in VehicleAudioTransform is reachable only through the this+7 dword index and is not enumerated as a packet field.
- UITextRenderWithScale mode/alignment/alpha parameters (0, 1, 2, 3) are not decoded by this packet.
- sub_587DD0 semantics (bounded string copy, max length parameter) and sub_589901 (sanitizer) are taken from corpus naming and call-site usage, not proven here.
- StringCompareCopy references callee 0x00587BCF (FreeWrapper) and global dword_8AFE64 which do not appear in the raw decompiled source.
- The layout and full semantics of the 1060-byte pit-crew instance struct behind dword_8AC394 are not in the packet; the stride is DERIVED from the visible *1060 addressing.
- The exact text content produced by the 0x49Cxxx / 0x49Bxxx format helpers is not established; their names (lap count, overlay fields) are inferred from render call context.
- The semantics of sub_49B7A0's return mask 0xF and which appearance state it indicates are derived, not confirmed.
- The purpose of the byte_5EC4C0 / byte_5EA438 / byte_5EC4CC triplet beyond the string-table search pattern rests on existing corpus naming (EmptyStringBuffer / default directory / MessageDisplayBuffer), not on evidence in this packet.
- Raw session/vehicle offsets used by RenderLapTimePositionText (a3+16480 total laps, a3+18168 suffix storage slot) are read/written directly with no named-field evidence.
- The meaning of global 0x005CCEF0 (aC, the '%c' format literal) in the StringCompareCopy/RenderLapTimePositionText contexts is unresolved; only the TimerDisplay usage is clear.
- Global unk_7CE234 (existing analysis label DriverAppearanceFlag, DERIVED) appears in several function fact lists but is absent from the raw decompiled sources; it is preserved here without a confirmed role.
- Whether DoublePassTextRenderer shares state with its structural twin ShadowedTextRenderer despite its distinct format helpers is unproven.
