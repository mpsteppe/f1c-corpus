# UiPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

Four clusters are reconstructed for the ui_platform_and_options scope. SceneFileCluster: SceneRegistry tracks 396-byte scene entries (name at +0x104, full path at +0x4, formatted path at +0x188; count dword_8AC488, list base dword_8AC490); TrackFilePathBuilder (0x004C51A0) strips directory and extension from a path, registers the base filename, writes season-races data via 0x004C5AE0 and formats the result via 0x004C5BB0 with constants 115/211; SceneFileFilterBuilder (0x004C6330) rebuilds a this-referenced singly linked list (head +0x8, tail +0xC, cursor +0x10, count +0x14, state +0x18, node next at +0x4) either unfiltered or from AND:/OR:/NOT: token buckets, then splits at the midpoint and merge-sorts with 0x004C5D30. SeasonRacesFilePathBuilder (0x004C5AE0) builds a season-races path on a stack buffer (suffix dword_5C5D24 + byte_5C5D28), gets or creates the 'seasonraces' audio channel (0x00568210 / 0x00567FB0) and loads/decodes the file via 0x00567F40. AudioMixerDeviceInit (0x004C85D0) creates the mixer global dword_8AC4C8 through vtable slot +96 on dword_8AC4C4, applies volume flt_7CF380 via vtable slot +28, marks this+0x10 active and resets this+0x14. UITextRenderWithScale (0x004D7E40) looks up a render context via 0x004D7FA0, scales context fields +92/+96, aligns left (a5==1 via 0x004D7F60) or center (a5==2 via 0x004D7F20), draws via 0x00553070 to render-device global dword_8B8DC8, then restores the fields. CreateUiWidget (0x004DAEA0) dispatches on a type id to allocate 24/20/32/44-byte objects, installs per-type vtables (off_5AD050..off_5ACF70) and common fields, and returns null on unhandled type or allocation failure. AudioRenderSystemInit (0x0053C360) zeroes the entry array 0x008B5A3C..0x008B6ABC at stride 132, resets a batch of enable/counter flags, applies '2'/'3' quality presets from the a5 bitmask, starts audio (0x0053D750) and forward-init (0x0055BE80), allocates a 160-byte network-config object into dword_8B8F04 and a 12-byte render-resource object into dword_8B8F2C. AudioStreamingThreadShutdown (0x0057FDE0) returns 8 when +0xA74 is clear, else dispatches the vtable+0x74 callback, kills the thread, closes two sockets, tears down buffers, waits the mutex +0xAD8/+0xADC, frees the list at +0xAC8 and returns 0 or 9 on network-cleanup (0x0057FBE0) failure. The scene/filter cluster and the audio/network cluster share the scope grouping only; no common ownership is evidenced.

## Function roles

- `0x004C51A0` **SceneRegistry** — Registers a scene file in the scene registry: strips the extension (last '.') and directory prefix (last '\\') from input a3, copies the base filename into a local buffer via 0x0058815F with format string global 0x005C2C18, searches the registry (dword_8AC488 entries, stride 396, names at entry+260) with sub_588410, creates and appends a new entry when absent, strcpys the full path into entry+4, writes season-races data via 0x004C5AE0, formats the scene path via 0x004C5BB0(a3, 115, 211), stores it at entry+392 and returns it. Parameters a1/a2 are unused in the raw source body.
- `0x004C5AE0` **SeasonRacesAudioLoader** — Builds a season-races file path on a 512-byte stack buffer: seeds with byte_5EA438[0], copies input a1 via 0x00587DD0 with a 511-byte limit, strips the extension at the last '.', appends the suffix dword_5C5D24 + byte_5C5D28, resolves the 'seasonraces' channel (global 0x005D31C8) via AudioChannelStop 0x00568210 or creates it via FileDataProcessor 0x00567FB0, then returns AudioFileLoadDecode 0x00567F40(v6, channel).
- `0x004C6330` **SceneFilterList** — Builds the filtered, merge-sorted scene-file linked list on this (head +0x8, tail +0xC, cursor +0x10, count +0x14, state +0x18). Clears the list via 0x004C62C0, then either copies every non-null registry entry (dword_8AC488 entries at dword_8AC490, stride 396, name at entry+260 via 0x004C58A0) when no filter is given, the filter equals byte_5EA438, or a photo/free-camera mode (dword_7D0398 with dword_7D0410 != 5) is active; or parses a filter expression through 0x005897CA into AND:/OR:/NOT: buckets (OR marker global 0x005D30C0), materializes include (0x004C5E50), AND (0x004C5FD0) and removes NOT (0x004C6150) tokens, then splits at the midpoint and merge-sorts with 0x004C5D30. Returns the accumulated node counter. Invoked by GameFilterSetup 0x00477830.
- `0x004C85D0` **AudioMixerDevice** — Initializes an audio mixer device: short-circuits when the mixer global dword_8AC4C8 is already set or when creation leaves it non-zero, else creates the mixer via the vtable+96 dispatch on the init-status object dword_8AC4C4, sets the volume via the vtable+28 dispatch with flt_7CF380, writes byte 1 to this+0x10 (active), resets this+0x14 to 0, re-applies the volume and returns it. Returns the previously captured result when the guard fails. Called by ConditionalSoundRenderDispatchOnParamCheck 0x00404970, sub_485B90 and SystemOSAPICall 0x004A03F0.
- `0x004D7E40` **TextRenderContext** — Renders UI text with independent horizontal (a7) and vertical (a8) scale factors: looks up the render context via SwitchBasedGlobalLookup 0x004D7FA0(a6), saves and temporarily scales context fields +92 and +96, applies the field setter at offset 0x48 via 0x00552FC0(a4), divides the position by the scale factors (CRTFtol 0x00587BDC), computes left-aligned (a5==1) via 0x004D7F60 or centered (a5==2) via 0x004D7F20 position, draws via 0x00553070 to the render device global dword_8B8DC8, then restores the context fields. Returns the render result or null when the context lookup fails.
- `0x004DAEA0` **UiWidgetFactory** — Factory that allocates and initializes a UI widget from a type id passed in ecx. Dispatches through the switch table global 0x004DB02C; each case allocates 24/20/32/44 bytes via 0x00587C03, installs a per-type vtable (off_5AD050, off_5AD034, off_5AD018, off_5ACFFC, off_5ACFA8, off_5ACF70, off_5ACFE0, off_5ACFC4, off_5ACF8C), sets common fields (dword index 1, byte at +8, dword index 3). Type 7 and type 0x11 run ConstructorVTable3Fields 0x004DB070(1,1) first; type 8 runs SmallStructConstructor_b0e0 0x004DB0E0 first. Returns the constructed object or null on unhandled type id or allocation failure. Called by 0x004D88D0.
- `0x0053C360` **AudioRenderSystemInit** — Global render/audio/network initializer: zeroes the entry-array region 0x008B5A3C..0x008B6ABC in 132-byte strides, resets counters/handles (dword_8B8E30, 8B6AC0, 8B8F14, 8B8EE0=-1, 8B8E34=-1), sets default enable flags (8B6AC4, 8B8E24, 8B8E2C, 8B8E28 = 1), zeroes the render/audio state block (8B8DC4, 8B8DC8, 8B8DCC, 8B8DD0, 8B8F18, 8B8F1C, 8B8F20), then branches on the a5 init bits: bit 1 skips the audio-configuration block; bit 2 applies the '2' preset (dword_8B8CEC=2, flt_8B8CF0/8B8CF4=0.5, StateIntSetter4 0x0053D930(-1,-1,16000,12000)); bit 3 the '3' preset (3, 0.33340001, 0.33340001) before starting audio via 0x0053D750(&dword_8B78A0) and calling 0x0055BE80(a4, a5&1). Then runs ArithmeticComparison_b0d0 0x0053B0D0, InitializeAudioSystemChannels 0x005566D0, allocates a 160-byte network-config object via 0x00587C03/0x0055F080 into dword_8B8F04, runs 0x0055F0D0 and GlobalMemoryStatusWrapper 0x0055F060, and allocates a 12-byte object via 0x00587C03/0x005593B0 into dword_8B8F2C. Always returns 0. Invoked by SystemInitAllocatorWrapper 0x0053D470.
- `0x0057FDE0` **AudioStreamingThread** — Shuts down the audio streaming thread and its sockets: returns 8 when the init flag at +0xA74 is clear; otherwise dispatches the virtual shutdown callback at vtable slot +0x74, terminates the thread (0x00585550), closes both streaming sockets (0x0057C8E0, first with 0 then 1), tears down streaming buffers (0x00585040, 0x00585130), waits on the list mutex (+0xAD8 handle, +0xADC timeout) when present, walks and frees every node of the linked list at +0xAC8 via virtual release plus FreeWrapper_7bcf 0x00587BCF, zeroes the list fields +0xAC8/+0xACC/+0xAD0/+0xAD4, releases the mutex, and runs full network cleanup 0x0057FBE0. Returns 0 on success, 9 when network cleanup fails.

## Proposed classes

### SceneRegistry

Global registry of scene files: registered count dword_8AC488 and list base dword_8AC490, entries of 396 (0x18C) bytes with the base filename at entry+260 (0x104), the full original path at entry+4, and the formatted scene-file path at entry+392 (0x188). TrackFilePathBuilder (0x004C51A0) registers a scene by base filename (create-if-absent) and stores the formatted path; SceneFileFilterBuilder (0x004C6330) consumes the same registry to materialize its filter list. The entry-layout offsets (stride 396, +0x4, +0x104, +0x188) are taken from packet operations but have no packet field refs, so no class field entries are proposed and the layout is only carried in the compatibility contract. The registry base is a4 in 0x004C51A0 and dword_8AC490 in 0x004C6330, which the packet does not prove are the same pointer.

Methods: `0x004C51A0`


### SceneFilterList

This-referenced singly linked list of scene objects produced by SceneFileFilterBuilder (0x004C6330): head +0x8, tail +0xC, cursor +0x10, node count +0x14 and a state counter +0x18; each link cell stores the scene pointer and a next pointer at cell+0x4. Built either unfiltered from the SceneRegistry or from a parsed AND:/OR:/NOT: filter expression, then split at the midpoint and merge-sorted with 0x004C5D30. The node link cell shape is inferred from the two field refs at *(this+0xC)+0x4 and the allocation of 12-byte cells.

Methods: `0x004C6330`

- `this+0x00000008` `pointer list_head` (read_write, DERIVED)
- `this+0x0000000C` `pointer list_tail` (read_write, DERIVED)
- `this+0x00000010` `pointer cursor` (read_write, DERIVED)
- `this+0x00000014` `dword node_count` (read_write, DERIVED)
- `this+0x00000018` `dword state_counter` (write, DERIVED)
- `*(this+0xC)+0x00000004` `pointer node_next` (read_write, DERIVED)

### SeasonRacesAudioLoader

Builds the season-races file path on a local stack buffer (suffix dword_5C5D24 + byte_5C5D28 appended after the extension is stripped), resolves or creates the 'seasonraces' audio data channel (global 0x005D31C8) through 0x00568210 / 0x00567FB0 and loads/decodes the file via 0x00567F40. All buffers are local; no class fields are proposed. Called by TrackFilePathBuilder 0x004C51A0 as part of scene registration.

Methods: `0x004C5AE0`


### AudioMixerDevice

Per-process audio mixer lifecycle: the mixer instance is held in global dword_8AC4C8, created through the vtable+96 dispatch on the init-status object dword_8AC4C4 and given volume flt_7CF380 through the vtable+28 dispatch. this+0x10 is a byte active flag and this+0x14 a dword fade/transition state reset by AudioMixerDeviceInit (0x004C85D0). The class boundary and the +0x14 semantics are synthesis: the packet owner is UnknownObject.

Methods: `0x004C85D0`

- `this+0x00000010` `byte active_flag` (write, DERIVED)
- `this+0x00000014` `dword fade_state` (write, DERIVED)

### TextRenderContext

Render context / font structure looked up by id via SwitchBasedGlobalLookup 0x004D7FA0, whose +92 and +96 fields are temporarily scaled by UITextRenderWithScale (0x004D7E40) for per-axis text scaling, with a field setter applied at offset 0x48. Text is drawn through 0x00553070 to the render-device global dword_8B8DC8. The +92/+96 offsets come from the raw source only and have no packet field evidence refs, so no class field entries are proposed and the layout is only described here as GUESS.

Methods: `0x004D7E40`


### UiWidgetFactory

Allocation factory that builds a UI widget from a type id in ecx (0x004DAEA0): switch table at 0x004DB02C, per-type sizes 24/20/32/44 bytes, per-type vtable from the table at 0x005ACF70..0x005AD050, and per-type constructor steps (0x004DB070 for types 7/0x11, 0x004DB0E0 for type 8). Returns null on unhandled type or allocation failure. The packet already assigns this DERIVED UiWidgetFactory owner.

Methods: `0x004DAEA0`


### UiWidget

Common layout of the widget objects allocated by CreateUiWidget (0x004DAEA0): a per-type vtable at +0, a dword kind index at +4 (2 for type 0, 1 for the other simple types), a byte flag at +8 and a dword at +0xC, plus per-type constructor steps. The concrete widget class behind each vtable is not resolvable from this packet and the packet carries no field refs for this object, so the layout is a GUESS synthesis in this responsibility text and no class field entries are proposed.

Methods: 


### AudioStreamingThread

Network audio streaming worker with a WSA init flag at this+0xA74, a vtable at +0, a mutex handle/timeout at +0xAD8/+0xADC, and a singly linked list at +0xAC8 (tail +0xACC, cursor +0xAD0, count +0xAD4) whose nodes carry an embedded next pointer at node+0, a release flag byte at node+8 and an opaque payload released through its first vtable slot. AudioStreamingThreadShutdown (0x0057FDE0) tears the whole structure down. Socket handles are stored as dword indices 590/591 without dedicated packet field refs.

Methods: `0x0057FDE0`

- `this+0x00000000` `pointer vtable` (read, DERIVED)
- `this+0x00000A74` `dword wsa_init_flag` (read, DERIVED)
- `this+0x00000AC8` `pointer list_head` (read_write, DERIVED)
- `this+0x00000ACC` `pointer list_tail` (write, DERIVED)
- `this+0x00000AD0` `pointer list_cursor` (write, DERIVED)
- `this+0x00000AD4` `dword list_count` (write, DERIVED)
- `this+0x00000AD8` `pointer list_mutex` (read, DERIVED)
- `this+0x00000ADC` `dword mutex_timeout` (read, DERIVED)
- `obj+0x00000074` `pointer vtable_slot_0x74` (read, DERIVED)
- `*(this+0xAC8)+0x00000000` `pointer node_next` (read, DERIVED)
- `*(this+0xAC8)+0x00000008` `byte release_flag` (read, DERIVED)
- `*(*(this+0xAC8)+0x0)+0x00000000` `pointer data_object_ptr` (read, GUESS)
- `*(*(*(this+0xAC8)+0x0)+0x0)+0x00000000` `pointer release_virtual_slot` (read, GUESS)

### AudioRenderSystemInit

Global one-time render/audio/network initializer (0x0053C360): zeroes the entry array 0x008B5A3C..0x008B6ABC, resets the enable/counter flag batch (0x008B6AC0, 0x008B6AC4, 0x008B8E24, 0x008B8E28, 0x008B8E2C, 0x008B8E30, 0x008B8E34, 0x008B8EE0), zeroes the render/audio state block 0x008B8DC4..0x008B8DD0 and 0x008B8F18..0x008B8F20, applies '2'/'3' quality presets through 0x008B8CEC/0x008B8CF0/0x008B8CF4 and 0x0053D930, starts audio (0x0053D750 on 0x008B78A0) and forward init (0x0055BE80), and allocates the 160-byte network-config object into dword_8B8F04 and the 12-byte render-resource object into dword_8B8F2C. All state is global; no this-fields are proposed. Most global names are DERIVED fill names rather than raw-source symbols.

Methods: `0x0053C360`


## Compatibility contracts

- **SceneRegistryEntryLayout** — A replacement for 0x004C51A0 must treat scene entries as 396-byte records with the base filename at +0x104, the full original path at +0x4, and the formatted scene path stored at +0x188, with the registered count in dword_8AC488. Registration matches by base filename (sub_588410 returning 0 meaning match) and creates a new empty entry when the search is exhausted. The magic stride 396, the offsets and the constants 115/211 passed to 0x004C5BB0 are packet-observed but unexplained.
- **SeasonRacesPathSuffixAndChannel** — A replacement for 0x004C5AE0 must build the path by copying the input through 0x00587DD0 (511-byte limit), truncating at the last '.', then appending dword_5C5D24 followed by byte_5C5D28; it must resolve the 'seasonraces' channel (0x005D31C8) via 0x00568210, create it via 0x00567FB0 when absent, and return the result of 0x00567F40 on the built path and channel handle.
- **SceneFilterListShape** — A replacement for 0x004C6330 must rebuild the this-referenced list (head +0x8, tail +0xC, cursor +0x10, node count +0x14, state counter +0x18, node next pointer at cell+0x4) from the registry (dword_8AC488 entries at dword_8AC490) either unfiltered or from a filter expression with AND:/OR:/NOT: buckets, split it at the midpoint and merge-sort with 0x004C5D30, resetting this+0x18 to 0, and return the accumulated node counter. The unfiltered path depends on the byte_5EA438 default string and the mode flags dword_7D0398 / dword_7D0410.
- **AudioMixerDeviceLifecycle** — A replacement for 0x004C85D0 must create the mixer instance into dword_8AC4C8 through the vtable+96 dispatch on dword_8AC4C4 when creation is needed, set the volume through the vtable+28 dispatch with flt_7CF380, write 1 to this+0x10, reset this+0x14 to 0, and re-apply the volume (vtable+28) as the return value, preserving the guard short-circuit and the previously captured result otherwise.
- **AudioStreamingThreadShutdownSequence** — A replacement for 0x0057FDE0 must return 8 when the init flag at +0xA74 is clear, and otherwise perform, in order: vtable slot +0x74 callback, thread termination (0x00585550), two socket closes (0x0057C8E0), buffer teardown (0x00585040, 0x00585130), mutex wait (+0xAD8 handle, +0xADC timeout, status 0 or 128 to proceed), free of every list node at +0xAC8 via its payload's first-vtable-slot release and 0x00587BCF, zeroing of +0xAC8/+0xACC/+0xAD0/+0xAD4, mutex release, and network cleanup 0x0057FBE0 returning 0 or 9.
- **RenderUISystemGlobalInitSequence** — A replacement for 0x0053C360 must zero the entry array 0x008B5A3C..0x008B6ABC in 132-byte strides, reset the counter/handle batch (0x008B8E30, 0x008B6AC0, 0x008B8F14, 0x008B8EE0=-1, 0x008B8E34=-1), set the enable flags 0x008B6AC4/0x008B8E24/0x008B8E2C/0x008B8E28=1, zero the render/audio block 0x008B8DC4/0x008B8DC8/0x008B8DCC/0x008B8DD0/0x008B8F18/0x008B8F1C/0x008B8F20, honor the a5 bitmask (bit1 skips audio config, bit2 '2' preset with 0.5/0.5, bit3 '3' preset with 0.33340001) with 0x0053D930(-1,-1,16000,12000), start audio via 0x0053D750(&dword_8B78A0), call 0x0055BE80(a4, a5&1), run 0x0053B0D0 and 0x005566D0, allocate the 160-byte network-config object into dword_8B8F04 and the 12-byte render-resource object into dword_8B8F2C, and return 0.
- **UiWidgetFactoryDispatch** — A replacement for 0x004DAEA0 must dispatch on a type id in ecx and allocate 24 (types 0/0x11), 20 (types 1/2/6/7/8), 32 (type 0xD) or 44 (type 0x13) bytes, install the matching vtable from 0x005ACF70..0x005AD050, fill the common fields (dword index 1, byte +8, dword index 3), run 0x004DB070(1,1) for types 7/0x11 and 0x004DB0E0 for type 8, and return null on unhandled type or allocation failure.
- **UITextScaleAndAlignRender** — A replacement for 0x004D7E40 must look up the render context via 0x004D7FA0(a6), temporarily scale the context fields at +92 and +96 by a7/a8, apply the field setter at offset 0x48 via 0x00552FC0(a4), divide the position by the scale factors via 0x00587BDC, align left (a5==1) via 0x004D7F60 or center (a5==2) via 0x004D7F20, draw via 0x00553070 to the render device global dword_8B8DC8, and restore the original +92/+96 values.

## Unresolved

- The magic scene-entry stride 396, the entry name offset 260, the result offset 392, and the constants 115/211 passed to SceneFilePathFormatter 0x004C5BB0 have no explanatory evidence in the packet.
- sub_588410 returning 0 to mean 'match found' is inferred from the loop shape (break on zero); the same branch-polarity question applies to the filter-token prefix tests in 0x004C6330.
- TrackFilePathBuilder parameters a1 and a2 are unused in the raw source body; their roles are unknown.
- The registry base in 0x004C51A0 is parameter a4 while 0x004C6330 reads dword_8AC490; the packet does not prove these are the same pointer, so the shared SceneRegistry is an inference.
- Semantics of the dword_5C5D24 / byte_5C5D28 suffix constants (e.g. file-extension fragment) are unconfirmed; the return contract of AudioFileLoadDecode and whether the FileDataProcessor handle is a valid channel substitute are unconfirmed; global 0x008AD3B4 is listed in the packet globals but absent from the raw source.
- The filter token bookkeeping uses several overlapping dword-indexed buffers (v32/v33/v34/v30 as both counters and indices); exact element semantics of the include/AND/NOT buckets are not fully derivable, and the AND/OR marker strings (v37, v38, dword_5D30C0-backed) are inferred from branch order only.
- The audio mixer and init-status object types, and the exact role of the vtable methods at byte offsets 96 and 28, are inferred only from the raw dispatch pattern; the meaning of flt_7CF380 and the +0x14 fade semantics are DERIVED from the fill, not proven; why the volume dispatch runs twice on the creation path is unexplained.
- TextRenderContext fields at +92/+96 have no packet field evidence entries; roles of a1, a4 and a6 in 0x004D7E40 are inferred from helper names and call sites; the 21 callers are evidence only.
- The concrete widget class behind each CreateUiWidget vtable (off_5ACF70..off_5AD050) is not resolved from this function alone; the metadata byte near the switch table (byte_4DB054) is not referenced by the visible source body.
- Most touched globals in 0x0053C360 (entry-array region, preset scale factors) come from the fill's DERIVED layer, not the raw source; the entry-array stride 132 and the allocated-object sizes 160/12 are observed from literals only; the a5 bitmask semantics are inferred from branch structure; parameters a2 and a3 are never referenced.
- Identity of the virtual shutdown callback at vtable slot +0x74 is not resolvable from this packet; the payload object stored in each AudioStreamingThread list node is opaque here; sub_585040 and sub_585130 semantics are inferred from naming only; the SOCKET array indices 590/591 have no dedicated packet field references.
- The scene/filter cluster (0x004C51A0, 0x004C6330, 0x004C5AE0) and the audio/network cluster (0x004C85D0, 0x0057FDE0, 0x0053C360) plus the UI cluster (0x004D7E40, 0x004DAEA0) share only the ui_platform_and_options scope grouping; no common ownership is evidenced, and class boundaries here are synthesis.
