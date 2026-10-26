# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 26 validated functions in scope generic_runtime_objects. Owners are UNKNOWN in the packet for all but 0x0049D150 (HudOverlayManager, GUESS), so every class below is a GUESS grouping anchored on shared this-offset field layouts. Two classes are anchored by common field bases evidenced across multiple methods: ResourceManager owns the surface-resource registry (list head this+0x104, counter this+0x108) shared by 0x004963D0 and 0x00497AD0, and UITextElement owns the text buffer at byte offset this+5400 shared by 0x004981F0, 0x004983B0 and 0x00498560 (source:raw only; no field ref exists for 0x1518). The packet is deliberately left heterogeneous: small forwarding/accessor helpers (0x00494A30, 0x00495150, 0x00498030, 0x0048FEC0) are grouped at interface level only, and offsets 0xF0/0xF8/0xFC appear in both LinkedListCollection and ResourceManager without proven common ownership, so per rule 8 they are kept as separate classes.

## Function roles

- `0x0048B810` **UITextEditControl** — Replace the edit control's text buffer with a2: null and no-change guards return -1; bounded copy via sub_587DD0, forced NUL terminator, truncation at the first validator-rejected char via sub_48B560, cursor reset to buffer start then advanced to the string end, vtable render-update call; returns 0.
- `0x0048D360` **UIListSelector** — Guarded accessor returning this+0x338 when this+0x328 > 0, else -1; interpreted (not packet-proven) as list item count and selected index.
- `0x0048E8D0` **CUBESceneObject** — CUBE scene load entry: resolve directory path (this[56] or byte_5EA438), reject via sub_588410, traverse the child list, init audio via sub_546010; on failure set fallback via SimpleGetter_5020 and dispatch UtilityFunction_1cd0 + sub_541CA0; on success relocate strings and report load errors; returns 1/0.
- `0x0048F590` **LinkedListCollection** — Indexed accessor returning the data pointer of the node at this+0x174: validates the index against the count at this+0xFC, walks from the head this+0xF0 via next-at-+4, returns the matched node's first dword or 0.
- `0x0048FEC0` **UIRenderDispatchHelper** — Dispatch the vtable method pointer at byte offset 0x40 with this and the flag at this[56]; then call UIWindowTypeDetection(this); returns 0. Part of a UI component update path.
- `0x004916E0` **RectShortsWriter** — Write four __int16 arguments into this+0/+2/+4/+6; return the value stored into the third field. Structural twin of RectangleClampConstraint (0x00491600).
- `0x004944A0` **OscScriptEngine** — Initialize and run the OSC script engine: null-guard on a2, copy the script name into this+0xC, store parser flags at 0x198/0x199/0x19A and script data at 0x1A4, open file streams, run the parsers, conditionally load media (eas.bik / legal.bmp / eaintro.bik), then clean up.
- `0x00494A30` **UIRenderDispatchHelper** — __stdcall forwarder: ignore a1, forward a2..a10 unchanged to ClippedRenderRegion (0x00543250) and return its result; used by scrollbar/scroll-view/text-box/text-input/blit render paths.
- `0x00495010` **ResourceManager** — Thin forwarder passing a1 to PhysicsObjectLinkedListRemoval and returning its result; closes a MAS audio handle during resource shutdown.
- `0x00495150` **UIRenderDispatchHelper** — Parameterless accessor returning global dword_7CDE14 unchanged; shared UI render/draw-state flag or cursor used across render and resource-load paths.
- `0x004963D0` **ResourceManager** — Global resource manager teardown: walk four managed lists invoking virtual destructors/release thunks and freeing nodes, zero the list heads, free collision geometry, release this[43]/this[44] resources, clean cursor resources, and close the MAS audio list.
- `0x00497AD0` **ResourceManager** — Load and register a surface resource by name: reject null, check the cache via sub_497BA0, resolve the ID via HashTableIDResolution, format/report a load error, allocate a 20-byte node (flag 1 at +0, +8=-1, ID at +12, next at +16), append it to the this+0x104 list, increment this+0x108, return the node.
- `0x00498030` **UIRenderDispatchHelper** — Configure alpha-blend state: when renderer a1 is non-null, copy flt_7CF2CC into dword_5CC9E0, clamp to [0,1], zero a 12-byte scratch array, dispatch vtable entry 4 with six args; the null-a1 path returns an uninitialized value.
- `0x004981F0` **UITextElement** — Render a text UI element at a horizontally/vertically computed position inside a bounding rectangle: null a2 returns -1; skip when this+5400 is empty; optionally resolve a2 via the string table (sub_423A00 into byte_5EC4CC), measure via sub_494F00, position via a3/a4 centering, dispatch via UIMessageDispatch with the GlobalAccessor_5150 value.
- `0x004983B0` **UITextElement** — Measure the rendered text width/height into a3/a4: zero the outputs, null a2 returns -1, measure only when the this+5400 buffer is non-empty, optionally resolve a2 through the string table.
- `0x00498560` **UITextElement** — Copy a non-empty input string (<=63 chars) into a stack buffer, NUL-terminate, run the string-keyed lookup sub_566810 against dword_5CC79C clearing the first byte of any hit, then strcpy the sanitized buffer into this+5400.
- `0x00499B50` **TwoResourceCleaner** — Conditionally clean two resource fields: release/cascade-clean this+0x30 via sub_5539F0 and clear it; independently, if this+0x2C is non-zero, invoke an object-level cleanup routine; returns the this+0x30 cleanup outcome.
- `0x00499E20` **PathStringProvider** — Return the path string pointer at this+0x10, falling back to global byte_5EA438 when null; used by resource/session path lookup callers.
- `0x0049AB40` **RectShortsWriter** — __thiscall forwarder calling StoreFourShorts (0x004916E0) with the receiver advanced by 18 word elements and four zero arguments, returning the __int16 result; acts as a subsystem initialization shim.
- `0x0049BAB0` **SessionController** — Trivial boolean query: dereference dword_7C54E0, read the dword at offset 16484, return whether it equals 3; queried by three callers as a session disqualification/state flag.
- `0x0049D150` **HudOverlayManager** — Multi-stage overlay teardown: release sub-resources at 0x18/0x1C and list pointers at 0x4/0x8/0xC when non-null, run the four-phase cleanup sequence on five sub-blocks, zero the byte flag at 0x0 and dwords 0x4..0x5C; returns 0.
- `0x0049EC60` **SoundResourceOwner** — Release the resource pointer at this[2] (this+0x8): destructor sub_5502C0, stub sub_557470, free wrapper sub_587BCF, then clear the field; returns the last operation result.
- `0x004A00A0` **SessionController** — Post-loading session/scene init orchestrator: hide the cursor, conditionally load the FIA short BIK (championship mode 4 + session type 7 + timer flag), chain subsystem setup (module dispatch, global resets, camera viewport, current-vehicle binding, game-state/audio dispatch), then scene/camera/collision/telemetry gated on ScoringGateCheck; returns the BIK load result.
- `0x004A0250` **SessionController** — Post-race session transition: clean the D3D resource list, show the cursor, and for race session (7) with championship mode != 6 probe the post-race monitor state and build/dispatch it or set the session-flag path; then tear down resources, advance global state, gate-teardown, per-vehicle state dispatch, and the session dispatch chain; returns 0.
- `0x004A06E0` **SessionController** — Initialize session-wide state: reset the sound system via a vtable method, init a buffer, run a sub-initializer with 4, set the session init flag, set a scoring-gate flag from dword_7D0038, init an array-check structure, and place multiplayer vehicles from tire-wear data; returns 0.
- `0x004A08E0` **SessionController** — Conditionally load/display classification screen data: when DelegatedFieldGetter returns 3, list deref yields a non-null vehicle node, and FixedOffsetReturn is truthy, resolve the scene name and load the winconstructor file when PathFileComparisonCounter == 1 and dword_7D032C == 1; always calls ScoringClassificationDisplay; returns 0.

## Proposed classes

### UITextEditControl

Edit text control managing a bounded character buffer at this+0x2F0 with a cursor at this+0x2F4 and an end-limit at this+0x2F8; replaces buffer content with field-type filtering and requests render updates.

Methods: `0x0048B810`

- `this+0x000002F0` `char* textBuffer` (read, DERIVED)
- `this+0x000002F4` `char* cursorPointer` (read_write, DERIVED)
- `this+0x000002F8` `int bufferEndLimit` (read, GUESS)

### UIListSelector

Collection-backed selector holding an item count at this+0x328 and a selected index at this+0x338; exposes a guarded selected-index getter.

Methods: `0x0048D360`

- `this+0x00000328` `int itemCount` (read, GUESS)
- `this+0x00000338` `int selectedIndex` (read, GUESS)

### CUBESceneObject

CUBE scene data loader holding a directory path at this+0xE0, a child linked-list head at this+0x40, and audio init state at this+0xE8/this+0xEC with fallback dispatch.

Methods: `0x0048E8D0`

- `this+0x00000040` `void* childListHead` (read, GUESS)
- `this+0x000000E0` `char* directoryPath` (read, GUESS)
- `this+0x000000E8` `int audioInitState` (read, GUESS)
- `this+0x000000EC` `int audioFallbackResult` (write, GUESS)

### LinkedListCollection

Singly-linked collection storing head at this+0xF0, tail at this+0xF4, cursor at this+0xF8, element count at this+0xFC, and a current index at this+0x174; nodes carry data at +0 and next at +4.

Methods: `0x0048F590`

- `this+0x000000F0` `void* headNode` (read, GUESS)
- `this+0x000000F4` `void* tailNode` (read, GUESS)
- `this+0x000000F8` `void* cursorNode` (read, GUESS)
- `this+0x000000FC` `int elementCount` (read, GUESS)
- `this+0x00000174` `int currentIndex` (read, GUESS)

### UIRenderDispatchHelper

UI render plumbing: vtable render dispatch (0x0048FEC0), 10-arg clipped-region forwarding (0x00494A30), alpha-blend state set (0x00498030), and a global draw-state accessor (0x00495150). Owners are UNKNOWN in the packet; the grouping is GUESS and carries no shared field layout.

Methods: `0x0048FEC0`, `0x00494A30`, `0x00495150`, `0x00498030`

- `this+0x00000000` `void* vtableRoot` (read, GUESS)
- `this+0x000000E0` `byte dispatchFlag` (read, GUESS)
- `obj+0x00000040` `void* dispatchMethodPointer` (read, GUESS)

### RectShortsWriter

Small UI/rectangle component writing four consecutive 16-bit fields at this+0/+2/+4/+6; 0x004916E0 stores four shorts, 0x0049AB40 is a subsystem-init shim forwarding with the receiver advanced by 18 words.

Methods: `0x004916E0`, `0x0049AB40`

- `this+0x00000000` `short shortValue0` (write, GUESS)
- `this+0x00000002` `short shortValue1` (write, GUESS)
- `this+0x00000004` `short shortValue2` (write, GUESS)
- `this+0x00000006` `short shortValue3` (write, GUESS)

### OscScriptEngine

OSC script engine holding the script name at this+0xC, parser flags at this+0x198/0x199/0x19A, and the script-data pointer at this+0x1A4; opens streams, runs parsers, and loads intro media.

Methods: `0x004944A0`

- `this+0x0000000C` `char[12] scriptName` (write, GUESS)
- `this+0x00000198` `byte parserFlagA` (write, GUESS)
- `this+0x00000199` `byte parserFlagB` (write, GUESS)
- `this+0x0000019A` `byte parserFlagC` (write, GUESS)
- `this+0x000001A4` `void* scriptData` (write, GUESS)

### ResourceManager

Resource manager owning the surface-resource registry (list head this+0x104, counter this+0x108) shared by 0x004963D0 and 0x00497AD0, plus managed object lists, the MAS audio list, and cursor/collision resources torn down at shutdown; 0x00495010 is the MAS-close forwarder.

Methods: `0x004963D0`, `0x00497AD0`, `0x00495010`

- `this+0x00000004` `void* managedListHead1` (write, GUESS)
- `this+0x00000008` `void* managedListHead2` (write, GUESS)
- `this+0x0000000C` `void* managedListHead3` (write, GUESS)
- `this+0x00000010` `void* managedListHead4` (write, GUESS)
- `this+0x0000001C` `void* secondListHead` (write, GUESS)
- `this+0x000000AC` `void* resource43` (read_write, GUESS)
- `this+0x000000B0` `void* resource44` (read_write, GUESS)
- `this+0x000000F0` `void* masAudioListHead` (read, GUESS)
- `this+0x000000F8` `void* masAudioIterator` (read_write, GUESS)
- `this+0x000000FC` `void* masAudioEnd` (read, GUESS)
- `this+0x00000104` `void* surfaceListHead` (read_write, GUESS)
- `this+0x00000108` `int surfaceCount` (read_write, GUESS)
- `this+0x0000010C` `void* fourthListHead` (read, GUESS)
- `this+0x00000114` `void* surfaceNodeNextBase` (read, GUESS)

### UITextElement

Text UI element whose message buffer lives at byte offset this+5400 (0x1518); renders it (0x004981F0), measures it (0x004983B0), and replaces it with a string-table-sanitized copy (0x00498560). The 0x1518 buffer is evidenced only via source:raw, so it is documented in responsibility/unresolved rather than as a class field.

Methods: `0x004981F0`, `0x004983B0`, `0x00498560`


### TwoResourceCleaner

Helper holding two resource pointers at this+0x2C and this+0x30; conditionally cascade-cleans this+0x30 and invokes an object-level cleanup for this+0x2C.

Methods: `0x00499B50`

- `this+0x0000002C` `void* resourceB` (read_write, GUESS)
- `this+0x00000030` `void* resourceA` (read_write, GUESS)

### SoundResourceOwner

Owner of a sound/vehicle-node resource pointer at this[2] (this+0x8); 0x0049EC60 conditionally destructs, stubs, frees and clears the pointer.

Methods: `0x0049EC60`

- `this+0x00000008` `void* soundResource` (read_write, GUESS)

### PathStringProvider

Object holding a path string pointer at this+0x10 with a default-path fallback to global byte_5EA438; used by resource-path and session lookup callers.

Methods: `0x00499E20`

- `this+0x00000010` `char* pathString` (read, GUESS)

### HudOverlayManager

On-screen overlay manager (owner GUESS per packet): holds list pointers at 0x4/0x8/0xC and sub-resources at 0x18/0x1C, with a byte flag at 0x0 and dword fields 0x10..0x5C; 0x0049D150 performs the multi-stage teardown.

Methods: `0x0049D150`

- `this+0x00000000` `byte activeFlag` (write, GUESS)
- `this+0x00000004` `void* listPointer1` (read_write, GUESS)
- `this+0x00000008` `void* listPointer2` (read_write, GUESS)
- `this+0x0000000C` `void* listPointer3` (read_write, GUESS)
- `this+0x00000010` `dword dword10` (write, GUESS)
- `this+0x00000014` `dword dword14` (write, GUESS)
- `this+0x00000018` `void* subResource1` (read_write, GUESS)
- `this+0x0000001C` `void* subResource2` (read_write, GUESS)
- `this+0x00000020` `dword dword_0020` (write, GUESS)
- `this+0x00000024` `dword dword_0024` (write, GUESS)
- `this+0x00000028` `dword dword_0028` (write, GUESS)
- `this+0x0000002C` `dword dword_002C` (write, GUESS)
- `this+0x00000030` `dword dword_0030` (write, GUESS)
- `this+0x00000034` `dword dword_0034` (write, GUESS)
- `this+0x00000038` `dword dword_0038` (write, GUESS)
- `this+0x0000003C` `dword dword_003C` (write, GUESS)
- `this+0x00000040` `dword dword_0040` (write, GUESS)
- `this+0x00000044` `dword dword_0044` (write, GUESS)
- `this+0x00000048` `dword dword_0048` (write, GUESS)
- `this+0x0000004C` `dword dword_004C` (write, GUESS)
- `this+0x00000050` `dword dword_0050` (write, GUESS)
- `this+0x00000054` `dword dword_0054` (write, GUESS)
- `this+0x00000058` `dword dword_0058` (write, GUESS)
- `this+0x0000005C` `dword dword_005C` (write, GUESS)

### SessionController

Session lifecycle controller driving global session state (session manager object dword_5EA510, session type dword_7C56A4, championship mode dword_7D0410, active-vehicle array dword_7C54F0): session init (0x004A06E0), post-loading scene init (0x004A00A0), post-race transition (0x004A0250), classification-screen load (0x004A08E0), and a disqualification query (0x0049BAB0). These are global-orchestrator functions rather than instance methods; the class is a behavioral grouping, not an object layout.

Methods: `0x0049BAB0`, `0x004A00A0`, `0x004A0250`, `0x004A06E0`, `0x004A08E0`


## Compatibility contracts

- **EditBufferLayout** — UITextEditControl stores its text buffer at this+0x2F0, the cursor pointer at this+0x2F4 and a buffer end-limit at this+0x2F8; EditBufferStringReplace copies at most this[190]-1 bytes, always writes a NUL at v4[end-1], filters characters via the field-type validator sub_48B560, then repositions the cursor at the string end and requests a render update through vtable+44. A replacement must preserve this layout and the field-type filtering.
- **LinkedListNodeLayout** — List nodes are records with the data pointer at +0 and the next pointer at +4; LinkedListIndexedAccessor (0x0048F590) validates its index against the count at this+0xFC, walks from the head at this+0xF0 via the +4 next links, and returns the matched node's first dword or 0. A replacement must preserve this node stride.
- **SurfaceResourceNodeLayout** — Surface-registration nodes are 20 bytes: flag byte 1 at +0, +4 cleared, +8 preset to -1, resolved string ID at +12, next link at +16; they are appended to the singly-linked list rooted at this+0x104 (walking the +16 next links to the tail) while the counter at this+0x108 is incremented. A replacement must preserve the node size and the list head/counter offsets.
- **TextBufferAt5400** — The text UI element stores its message buffer at byte offset this+5400 (0x1518); render (0x004981F0), measure (0x004983B0) and buffer-replace (0x00498560) all key off this buffer, with optional string-table resolution through byte_5EC4C0/byte_5EC4CC via sub_423A00 and lookup sub_566810 against dword_5CC79C. The offset is evidenced only by source:raw.
- **MASAudioListLayout** — ResourceManager's MAS audio list is rooted at this+0xF0 with the iterator start copied from this[60] into this[62] (0xF8) and end at this+0xFC; nodes hold the MAS handle at +8 and the next pointer at +4; each node is closed via MASCloseWrapper (0x00495010) during shutdown. A replacement must preserve the node offsets.
- **SessionStateGlobals** — Session lifecycle code drives global state through the session manager object dword_5EA510, session type dword_7C56A4 (7 = race), championship mode dword_7D0410 (4 = championship intro, 6 = excluded from post-race monitor path), intro/timer flag dword_7D032C, the active-vehicle pointer array dword_7C54F0 with index dword_7C54E4, and the scoring gate sub_42BC10. A replacement must keep these global anchors and value conventions.
- **CUBESceneLoadContract** — CUBESceneLoaderEntry resolves a directory path (this[56] or byte_5EA438), rejects invalid paths via sub_588410, traverses the child list at this[16], and initializes audio via AudioEngineInitialization(this+58, path, 0); on failure it stores SimpleGetter_5020() into this[59] and dispatches UtilityFunction_1cd0(0,0,0.0,0,0,0) + sub_541CA0(0). A replacement must preserve the failure-fallback sequence.

## Unresolved

- Common text buffer at this+0x1518 (decimal 5400) shared by BitmapDraw, TextRenderToSurface and CopyStringToStructBuffer is evidenced only through source:raw; no field: evidence ref exists for 0x1518, so it is documented in prose, not as a class field.
- Offsets 0xF0/0xF8/0xFC appear both in LinkedListCollection (head/cursor/end) and ResourceManager (MAS audio list); per rule 8 they are NOT merged without proven common ownership and are kept as separate classes.
- Nested-base field refs (field:*(this+0x4):0x00000000, field:*(this+0x8):0x00000004, field:*(this+0x1C):0x00000000, field:*(this+0xA8):0x0000008C, field:*(this+0xF0):0x00000008, field:*(this+0xFC):0x00000000, field:*(this+0x114):0x00000010, field:*(*(this+0x4)+0x0):0x00000000, field:*(*(this+0x114)+0x10):0x00000010) describe list-node next/data and sub-object members whose owning node class is not established; left unresolved.
- Globals 0x008AFE64, 0x007CDE00, 0x005EB978, 0x005EC6D0, 0x007CE498, 0x008AD298, 0x008AFE18, 0x008B78A0 are listed in packet facts but never appear in any raw decompiled body; their roles are unverifiable from this packet.
- The DERIVED label aSS (global 0x005BE860) as the '%s%s' path-format string and the dword_5EC418/byte_5EA438 path-base fallback are DERIVED, not independently confirmable from raw source.
- The RendererAlphaBlendSetter fixed literal 1065353216 (= 1.0f bit pattern) used as the clamp cap and dispatch argument has asserted semantics only as a float upper bound.
- 0x0049D150's five cleanup sub-block indices 24/43/62/81/100 are dword-indexed in the raw source (this+24 words), not byte offsets; the HudOverlayManager byte positions of the sub-blocks remain unproven.
- Field refs field:this:0x00000110, field:this:0x000001B4, field:this:0x000002F5, field:obj:0x0000002C and field:obj:0x00000004 are read but have no visible use in their function bodies; roles unknown.
- MASCloseWrapper (0x00495010) and DisqualificationCheck (0x0049BAB0) owners are GUESS by caller context (0x004963D0 / HUD flag renderers), not packet-proven.
- The owner of the this+0x328/0x338 fields interpreted as list count / selected index (0x0048D360) relies on an owning UI list/collection object unknown from this packet.
- 0x004A00A0 uses literal vehicle-struct offsets 13024 and 13388 and 0x0049BAB0 uses offset 16484 as source-text literals; the vehicle struct layout is not established in this packet.
- The SessionController class groups global-orchestrator functions rather than instance methods on a shared object; it is a behavioral grouping, not an object layout.
- The a2 vtable entry +12 call in OscScriptEngineInitialize has no resolved callee symbol; the script-name copy is evidenced only by source:raw.
- The vtable entry 4 dispatch in RendererAlphaBlendSetter (0x00498030) and the vtable entry 0x40 dispatch in ShortComputation_fec0 (0x0048FEC0) have no resolved callee symbols.
- 0x0049EC60 calls DestructorWithConditionalFreeFlagClear (0x005502C0) with no visible argument in raw source; the natural receiver this[2] is inferred, and the return value on the null-this[2] path is uninitialized.
- The StringPointerAccessor (0x00499E20) default string global byte_5EA438 is forwarded only; its content/role is not defined in this packet.
- 0x004A0250's dispatch through the virtual slot on dword_7CD8C0 (vtable slot 28 with argument 33) has no resolved callee symbol.
- SubsystemInitThunk (0x0049AB40) advances the receiver by 18 word elements before forwarding to StoreFourShorts; the target field's identity and purpose are unknown.
- The classification-screen value 3 returned by DelegatedFieldGetter and the dword_7D032C == 1 condition in 0x004A08E0 are not documented in this packet.
