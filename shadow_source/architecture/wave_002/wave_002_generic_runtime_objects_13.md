# RuntimeResourceAndSessionManagement

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Derived architecture proposal for 23 validated functions in scope generic_runtime_objects. One packet-DERIVED owner (D3DTextureCopyContext, 0x005063A5) forms a real D3D texture-copy context class holding destination/source surfaces and a surface type, driving a first-success-wins transfer chain and COM-style releases on every exit. The other twenty-two functions have packet-UNKNOWN owners and are grouped conservatively: GUESS classes for the resource-cleanup pair (0x004DCD10/0x004DD000), session objects (0x004E2370 mode config, 0x004EF5A0 session-state manager), the weather writer (0x004FE820), render-resource teardown (0x005064CF/0x00506554), the surface lock-box wrapper (0x00506971), and the renderer vtable dispatcher (0x00519828); GUESS interfaces collect the D3D context factory helpers (0x0050070D/0x005007EF/0x00500B42/0x00506538), resource loader (0x004F9D60), game frame loop (0x004FA7E0), subslot teardown (0x004E0E70), texture resampler (0x00504933), D3D PSGP table initializer (0x0050FEA7) and startup dispatcher (0x0050C27F). Class boundaries are weak: equal base+offset tuples (e.g. field:this:0x00000000) occur on many unrelated objects and are deliberately NOT merged. Vtable method targets for surfaces/render resources are indirect with no static addresses. Session-type enums, state identifiers, flag-bit meanings and a cluster of fact-table globals absent from the decompiled bodies remain unresolved.

## Function roles

- `0x004DCD10` **DualResourceHolder** — Dual-resource teardown: run secondary-resource destructor/free sequence (this+0x4), then cascade cleanup on primary resource (this+0x0); return the computation-helper result
- `0x004DD000` **DualResourceHolder** — Two-call passthrough on this: run ResourceCleanup_cd10(this) first, then sub_4DCF80(this) and return its result; invoked by DestructorWithResourceCleanup (0x0045B400)
- `0x004E0E70` **SubsystemTeardownService** — Per-index subslot teardown: conditional release of two resource regions (stride 296, slot+81/slot+98), vibration reset via VibrationStateMachine(a2, 0.0), conditional FlagFieldBitManipulation(0,0,0,0)
- `0x004E2370` **MultiplayerSessionConfig** — Multiplayer session-mode configuration: normalize the session-type argument onto this+0xB6C and initialize 4 session-slot entries at this+0x1EC (stride 0x128) to -1
- `0x004EF5A0` **SessionStateManager** — Session state-pointer update at this+0x32BC with transition side effects: position recording on exit-to-NULL (session type 5), cleanup-flag clear + AI speed-delta set + field zeroing on entry-to-state-1
- `0x004F9D60` **ResourceLoadingService** — Named-resource file loader: direct path then default directory (byte_5EA438) + override (dword_5EC408) fallback, timed loading screen (clipped render + present, optional input polling) for a2 seconds, handle release, returns 1/0
- `0x004FA7E0` **GameFrameLoop** — Main per-frame game tick: render display-list configuration from packed flag bits, global-float mode selection, one-shot display init, per-vehicle UI dispatch, session audio dispatch, pause overlay, delta-time accumulation (clamped to 0.5 s), audio-init retry on pending flag
- `0x004FE820` **WeatherConditionSimulator** — Weather-conditions report writer: open config-path file, header, 8-session loop with transition simulation (10.0-unit steps) and linked-list weather-point dump (nodes at +12), close and return 0/-1
- `0x0050070D` **D3DTextureContextFactory** — D3D texture-surface lock+copy context init: lock/copy the surface, fill descriptor, init D3D context, unconditionally tear down render resources and dual-vtable objects; fail-fast with -2005530516 on null args
- `0x005007EF` **D3DTextureContextFactory** — Sound-buffer / D3D-context setup from a parameter block: guard a1/a4/a9, default a10, prepare descriptor via sub_506971, init via D3DContextInit, tear down both helper objects on every exit
- `0x00500B42` **D3DTextureContextFactory** — Sound-buffer/resource init forwarding the descriptor (4 words) plus arguments to AudioSoundBufferSetup (0x005007EF); guarded on a1/a4, wrapped between sub_506538/ThunkToFUN0050653e
- `0x00504933` **TextureResampler** — 3D texture resampling from source to destination dimensions via fixed-point scaling, two 16-byte staging buffers and vtable scanline fetch/write; type-byte guard and SEH frame; returns 0 or failure code
- `0x005063A5` **D3DTextureCopyContext** — D3D texture-copy context init: validate surface type, create source/destination surfaces via the FourCC-dispatched factory, run the first-success-wins transfer chain, release both surfaces through vtable slot 0 on every exit
- `0x005064CF` **RenderResourceContainer** — Render-resource teardown: optional vtable+112 copy when this[1..3] valid and flag bit 0 clear, release this[2]/this[3] via vtable+8, clear all slots, return 0
- `0x00506538` **D3DTextureContextFactory** — Thiscall single-field zero initializer: write 0 to *this and return this for call-chained construction
- `0x00506554` **RenderResourceContainer** — IDA jump thunk: forwards this to RenderResourceTeardown and returns its result unchanged
- `0x0050696C` **Unresolved** — Thunk forwarding this unchanged to a named-but-unaddressed VTableReleaseClear target; returns the delegated result
- `0x00506971` **D3DSurfaceInterface** — Lock a 3D surface sub-region and copy surface info into the a2 descriptor: release stored interface, query description/capabilities, block-align the rect by FourCC, LockBox, fill descriptor, store surface at *this
- `0x0050B830` **Unresolved** — Destructor-style teardown: install vtable off_5ADBB8, color/palette cleanup via VertexColorPackRGBto16, free heap resource at index 1051, release child objects via VtableSetFreeChild
- `0x0050C27F` **StartupDispatcher** — Startup sequencing wrapper: call sub_50FEA7 with literal 1, then dispatch through global function pointer off_5D77C8 and return its result
- `0x0050FEA7` **D3DPSGPFunctionTableInitializer** — D3D PSGP function-table init: copy template off_5D78B0 to off_5D77C8, init via FunctionTableInit, apply registry DisableD3DXPSGP override, patch for detected CPU variant (dword_5D7998 1/2/3) or reset to 0xFFFF
- `0x00512114` **Unresolved** — Null-guarded masked read: return a3 & *(dword*)(a2+8) when a1/a2 non-null, else 0; invoked by sub_50210E
- `0x00519828` **RendererOwner** — Render-subsystem vtable dispatch: read renderer interface at this+0x188, indirect call through interface+4 with object, three zeroed leads and caller args; return result unchanged

## Proposed classes

### D3DTextureCopyContext

Holder of a destination/source D3D surface pair and a surface-type parameter for a texture-copy operation; validates the surface type, creates both surfaces through the FourCC-dispatched surface factory, runs a first-success-wins transfer-method chain, and releases both surfaces through COM vtable slot 0 on every exit path.

Methods: `0x005063A5`

- `this+0x00000000` `IUnknown* (COM surface interface) destination_surface` (read_write, DERIVED)
- `this+0x00000004` `IUnknown* (COM surface interface) source_surface` (read_write, DERIVED)
- `this+0x00000008` `uint32 (1..5, mask 0xFFF00000 excluded) surface_type` (write, DERIVED)
- `*(this+0x4)+0x00000000` `vtable slot 0 (Release) source_surface_vtable_release` (read, DERIVED)
- `obj+0x00000000` `vtable slot 0 (Release) destination_surface_vtable_release` (read, DERIVED)

### RenderResourceContainer

Container of up to three releaseable render interfaces (this+0x4/0x8/0xC) plus a flags word (this+0x0); teardown optionally runs a vtable+112 copy operation, then releases each interface via its vtable+8 method and clears all slots.

Methods: `0x005064CF`, `0x00506554`

- `this+0x00000000` `uint32 (bit 0 gates copy path) flags` (read, DERIVED)
- `this+0x00000004` `IUnknown* render_interface_a` (read_write, DERIVED)
- `this+0x00000008` `IUnknown* render_interface_b` (read_write, DERIVED)
- `this+0x0000000C` `IUnknown* render_interface_c` (read_write, DERIVED)
- `*(this+0x8)+0x00000008` `vtable slot 8 (Release) interface_b_vtable_release` (read, DERIVED)
- `*(this+0x8)+0x00000028` `vtable slot 40 (copy) interface_b_vtable_copy_selected` (read, DERIVED)
- `*(this+0xC)+0x00000008` `vtable slot 8 (Release) interface_c_vtable_release` (read, DERIVED)
- `*(this+0xC)+0x00000070` `vtable slot 112 (copy) interface_c_vtable_copy` (read, DERIVED)

### D3DSurfaceInterface

COM-style D3D surface wrapper: stores a locked surface pointer at this+0x0, releases a previously stored interface, and exposes lock/description/capability vtable methods (slots +28/+32/+36) used to block-align a requested rect by FourCC and lock it.

Methods: `0x00506971`

- `this+0x00000000` `IUnknown* (locked surface) stored_surface` (read_write, DERIVED)

### DualResourceHolder

Holds a primary resource (this+0x0) and a secondary resource (this+0x4); teardown runs the secondary destructor/free sequence, cascade-cleans the primary resource, and returns a computed result.

Methods: `0x004DCD10`, `0x004DD000`

- `this+0x00000000` `void* primary_resource` (read, DERIVED)
- `this+0x00000004` `void* secondary_resource` (read_write, DERIVED)

### MultiplayerSessionConfig

Stores the multiplayer session mode at this+0xB6C (normalized from a session-type argument, cases 4/5/6 to 1/2/3, cases 1/2/3 to 0, default raw) and initializes a 4-entry session-slot array at this+0x1EC (stride 0x128) to -1.

Methods: `0x004E2370`

- `this+0x00000B6C` `uint32 session_mode` (read_write, GUESS)
- `this+0x000001EC` `int32[4] (stride 0x128) session_slots` (write, GUESS)

### SessionStateManager

Session-state holder: session object pointer at this+0x0, current session-state pointer at this+0x32BC, last-recorded position at this+0x34EC/0x34F0/0x34F4; runs transition side effects (position/time recording on exit, cleanup-flag clear and AI speed-delta update on entry).

Methods: `0x004EF5A0`

- `this+0x00000000` `void* (session object) session_object` (read, DERIVED)
- `this+0x000032BC` `void* (session state pointer) session_state` (read_write, DERIVED)
- `this+0x000034EC` `float last_position_x` (read, DERIVED)
- `this+0x000034F0` `float last_position_y` (read, DERIVED)
- `this+0x000034F4` `float last_position_z` (read, DERIVED)

### WeatherConditionSimulator

Weather-condition runtime: current/start iterator pointers (this+0x38/0x3C) over a linked list of weather data points chained at node+12, a pointed-to value (this+0x44); writes per-session weather reports and steps weather transitions in fixed 10.0-unit intervals.

Methods: `0x004FE820`

- `this+0x00000038` `void* (linked-list node) weather_iterator_current` (read_write, DERIVED)
- `this+0x0000003C` `void* (linked-list node) weather_iterator_start` (read, DERIVED)
- `this+0x00000044` `void* weather_data_ptr` (read, GUESS)
- `*(this+0x44)+0x00000000` `float weather_data_value` (read, GUESS)

### RendererOwner

Object holding a renderer interface pointer at this+0x188; dispatches render-subsystem calls through the function pointer at interface+4, passing the object, three zeroed leading arguments and the caller arguments.

Methods: `0x00519828`

- `this+0x00000188` `void* (renderer interface) renderer_interface` (read, DERIVED)
- `*(this+0x188)+0x00000004` `function pointer (vtable slot 4) renderer_method` (read, DERIVED)

## Compatibility contracts

- **SessionStatePointerAndTransitionContract** — A session manager must store the active session-state pointer at this+0x32BC; exiting to NULL while session type dword_7C569C == 5 must record the position at this+0x34EC..0x34F4 and race elapsed time via transform helpers and sub_447780; entering state 1 must query the position-change monitor, clear session cleanup flags, set the AI speed delta and zero session dwords +17236/+17240.
- **ResourceFileLoadContract** — A named resource must first be attempted via a direct path; on failure it is retried with the default directory (byte_5EA438) + override (dword_5EC408) formatted as "%s%s"; a timed loading screen runs for a2 seconds (input polling breaks early when dword_7CB218 > 0); returns 1 on success and 0 on failure.
- **FrameTickTimeIntegrationContract** — Each frame the raw delta time (sub_556730) is accumulated; when dbl_5D6D70 == 1.0 the session clock (dbl_8AFEA0) advances by the delta and the delta is clamped to 0.5 s; when byte_8AFE72 was set, the audio-init retry chain (RepeatedCallLoop_f040 on dword_8ACEA0) and the scene-setup render run.
- **D3DTextureCopyContextLifecycleContract** — A D3D texture-copy context holds a destination surface (this+0x0), a source surface (this+0x4) and a surface type (this+0x8); both surfaces are created through the FourCC-dispatched surface factory and must be released through COM vtable slot 0 on every exit path; the transfer chain is first-success-wins.
- **WeatherReportWriterContract** — A weather-conditions writer must produce a report over exactly 8 session types; per session it writes the session name, simulated duration, and iterates a linked list of weather points chained at node+12, stopping when (*point - duration) * 0.016666668 > 150.0; returns 0 on success and -1 on open failure (with DebugLogWrite logging).
- **D3DApiFailureMarkerContract** — D3D setup/init routines fail fast with -2005530516 on null arguments or invalid surface types, propagate negative HRESULT-style results from lock/init calls, and use -2147467259 (generic failure) and -2147024882 (failed allocation) for their respective error paths.

## Unresolved

- The exact session-type enum semantics and session state identifiers (NULL exit, state 1 entry) are not grounded in the packet; only the numeric mappings are locked.
- D3D vtable method targets are all indirect: surface slots +28/+32/+36 (SurfaceLockBoxCopy), render-resource slots +8/+40/+112, texture scanline slots +4/+8, renderer interface slot +4; none has a static address in the packet.
- Offsets +17236/+17240 of the session object and v7+300 of the position-monitor result belong to objects absent from the packet field table; semantics of those writes are unknown.
- dword_7C569C == 5, dword_7CB218 as an input count, dbl_5D6D70 dual use (1.0 integration marker vs scaling factor), and the bit indices 20/29/33/34 in byte_7CA594 are unestablished beyond the raw guards.
- The weather linked-list +12 next-node layout is inferred from call shape only; this+0x44 and *(this+0x44) appear in the field table but not in the raw decompiled body.
- The VTableReleaseClearThunk (0x0050696C) target address is named but not evidenced in the packet; the underlying VTableReleaseClear behavior is unknown.
- The final computation helper (ShortComputation_cb70) of ResourceCleanup_cd10 and the purpose of the EmptyStub_7470 call in the free sequence are unverified.
- A cluster of fact-table globals does not appear in the decompiled bodies (0x0059E420, 0x0059E440, 0x0059E5FC, 0x0059E6F8, 0x0059E880, 0x0059E9C0, 0x005ACB08, 0x008AC494, 0x008AFE88, 0x008AFE94, 0x008AFE9C, 0x008B8F24, 0x008AFE64, 0x007CDE00); their roles are unknown.
- Ownership classes of most functions remain packet-UNKNOWN; all class/interface boundaries here are DERIVED/GUESS and must not be promoted without independent evidence.
- Meaning of the 296-byte subslot stride, the two released regions (slot+81/slot+98), the four -1-initialized session slots (stride 0x128), and the 524292 default flag is not established.
