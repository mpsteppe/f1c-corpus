# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Generic runtime objects in the UI/session layer. The packet is dominated by straight-line UI-element constructors that share a base-field initializer (0x00466D60) and a construction-time virtual dispatch (0x004670E0) while installing per-class vtables at +0 and writing literal flag/ID blocks at +0x324..+0x338 (UiControl). Around them sit: string accessors reading a sub-object at this+0xC8 with a byte_5EA438 fallback (UiStringAccessor), indexed/string linked lists with distinct layouts (IndexedItemList head at +0x90/count at +0x94, StringList head at +0x54/tail at +0x58), a scroll list control converting a scroll index to pixels via CRTFtol (ScrollListControl), season-scene controllers that walk scene lists comparing path strings and invoke a vtable+160 callback (SeasonSceneController), a network session UI that conditionally starts LAN discovery, a telemetry mode switch display, and several isolated formatting/accessor helpers whose owners are unknown. Most function boundaries are clear; ownership and field semantics are only partly grounded.

## Function roles

- `0x0046E5C0` **UnknownObject** — Builds a path with trailing backslash into a 256-byte stack buffer via PathBuilderWithBackslash, validates the vehicle configuration file at that path via ValidateVehicleConfigurationFile(global, path, 1), returns the validation result.
- `0x004715D0` **UiControl** — UiControl constructor: shared base-field init (0x00466D60, flag 1), vtable off_5A0F00 install at +0, data ref dword_7CE850 at +0x31C, literal flags/ID 1,0,1,1,237 at +0x324..+0x334, two linked-list option nodes (off_5BE704, aOn) with value -1, construction-time virtual dispatch (0x004670E0).
- `0x00472040` **UiControl** — UiControl sibling constructor (defaults, no option nodes): shared base init, nulls +0x31C and +0x328, installs vtable off_5A1A40, writes literals 32,1,1,252 at +0x324,+0x32C,+0x330,+0x334.
- `0x00472A80` **UiControl** — UiControl constructor variant: shared base init, vtable off_5A2280, data ref unk_7D1334 at +0x31C, flags 1,0,1,1 at +0x324..+0x330, preset 263 at +0x338, two linked-list option nodes, virtual dispatch.
- `0x00473C40` **UiControl** — UiControl constructor variant: shared base init, vtable off_5A2F40, data ref unk_7CF7D0 at +0x31C, flags 1,0,1,1 at +0x324..+0x330, preset 379 at +0x334, two linked-list option nodes, virtual dispatch.
- `0x00475530` **NetworkSessionController** — Network session UI: resets flag byte_7CD850, refreshes the network browser via sub_475150(this), then conditionally starts LAN discovery (StartNetworkUpdate(dword_7CD25C)) only when dword_7D0E74==0, byte_7D0FAC!=0, and this+0x17C==0; sets this+0x17C=1; returns the guard-dependent result.
- `0x00476F90` **UnknownObject** — Selects the string to copy: when dword_7D0398!=0 and dword_7D0410!=5 the incoming string is replaced by global byte_5EA438, then the selected string is passed to StringCopyWithBufferRealloc and the copy is returned.
- `0x00477720` **SeasonSceneController** — Season-scene setup orchestrator: dispatches virtual command object (literal 20) through dword_7CD8C0 vtable offset +28, runs SeasonPathMatchSearch, queries a scene object via UtilityFunction_7810, runs SeasonSceneSearchByName, copies the search match index (v4[93]) into this+0x184, invokes the vtable+160 callback, walks the linked list at this+0xF0 comparing node+0x3C path strings against dword_7CE64C (byte_5EA438 fallback), records the first matching node index at this+0x174, then tail-calls the viewport layout calculator.
- `0x00477AA0` **SeasonSceneController** — Content filter check with settings-path lookup: loads the content string at this+384, and when a game filter is active (ConditionalDispatch_81f0) compares it with sub_588410, invoking the vtable+160 callback on mismatch or (no filter) on non-empty content; then compares a linked-list element's +260 path field against dword_7CE5EC (byte_5EA438 fallback) and triggers SceneListSearchByPath on mismatch; always returns 0.
- `0x0047BEB0` **UnknownObject** — String cleanup helper: clears the output buffer a2, invokes sub_568910(128), formats the local stack string into a2 with '%s' (global 0x005C2C18), scans backward for a '.' (46) byte and truncates the extension; returns 0 on success, or a1 unchanged when either argument is null.
- `0x0047DBE0` **TelemetryDisplayControl** — Telemetry display dispatcher: switches on the mode selector at this+0xEC (0x1E0 vehicle list via dword_8AB6EC, 0x1E1 lifetime-average delta, 0x1E2 range width, 0x1E3 engine/RPM status built from dword_7C54E0 with a static fallback), formats with '%1.3f'/'%d %s', hands every result to UIStringComparison, returns 0 on all paths.
- `0x0047E3F4` **UnknownObject** — Display trigger for the race-laps string: looks up the season races section (SeasonRacesSectionFinder), searches for the 'racelaps' key via StringKeyedLinkedListSearch, extracts entry data via DataEntryAccessor, feeds UIStringComparison; always returns 0. Prologue is a decompiler artifact (corrupted indirect call with icebp), so the true call graph is uncertain.
- `0x004861A0` **UnknownObject** — Conditional two-channel dispatch: if the low byte of a1 is nonzero, TwinFieldGetter fills v3 from a1 and PositionUpdate runs when both are positive; then if the low byte of a2 is nonzero, TwoChannel16BitReader refills a1/v4/v3/a2 and MultiFieldStructWriter runs if any is nonzero; otherwise returns the trailing value (a2, then a1).
- `0x00486280` **UiStringAccessor** — String accessor: reads the sub-object pointer at this+0xC8, returns the char* at sub-object +0x28, byte_5EA438 fallback when the string is null.
- `0x004862C0` **UiStringAccessor** — String accessor: reads the sub-object pointer at this+0xC8, returns the char* at sub-object +0x40, byte_5EA438 fallback when null; used by UI text-rendering paths (0x004883D0, 0x0048D6F0, 0x0048D9D0, 0x0048FEE0).
- `0x004862E0` **UiStringAccessor** — String accessor: reads the sub-object pointer at this+0xC8, returns the char* at sub-object +0x48, byte_5EA438 fallback when null; UI rendering paths (0x004883D0, 0x0048D9D0).
- `0x00486320` **UnknownObject** — Getter returning the int field at this+0x8C; no side effects; widely reused by list/render/destruction paths (0x00486080, 0x00486660, 0x004866AD, 0x0048741B, 0x00487900, 0x00495980, 0x00498D90, 0x00498F80, 0x00498FB0, 0x00498FE0, 0x00499280, 0x00499360, 0x004993D0).
- `0x00486340` **IndexedItemList** — List node insert/append: copies source fields this+0x40/+0x98/+0x9C into the new node, prepends (flag a3!=0, chaining old head into node+0x8C) or appends (walk to tail via next pointer +0x8C, link via FieldSetterAt0x8c, or becomes first node when empty) to the list rooted at this+0x90, increments the node counter at this+0x94, returns the new count.
- `0x00486580` **StringList** — String list node insert: allocates an 8-byte data buffer (init 0/-1) and a 12-byte node (data ptr, next 0, flag byte 1), copies the source string via StringCopyWithBufferRealloc, appends to the tail (head this+0x54, tail this+0x58, alternate this+0x5C, count this+0x60), returns the new node or 0 on allocation failure.
- `0x00486710` **UnknownObject** — Getter returning the byte at this+0x64; no side effects; UI-oriented callers (UI state/value dispatch paths) suggest a per-object UI state/flag.
- `0x00486830` **AnimatedElementRenderer** — Animated UI element render dispatch: retrieves element bounds via the vtable method at offset 8, computes width/height, then picks the animated path (Accessor + ShortComputation_1c70) or static path (Accessor + ShortComputation_1cb0) based on TimedAnimationTrigger; returns 1 while animating, 2 on static render, 0 otherwise.
- `0x004870E0` **UnknownObject** — Guarded indexed X lookup: reads base X offset at this+0x4, computes the linked-list boundary via ShortComputation_adb0(this+28), and when index a2 is out of bounds additionally requires the guard flag at this+0xC8 before LinkedListIndexedFieldReader runs; returns base offset + the 16-bit value v5, or -1 on failure.
- `0x00488B00` **UiWidget** — UI widget constructor: runs the base initializer ShortComputation_5e30, stores constructor parameters at this+0xE0/+0xE4, installs vtable off_5ABC28 at +0, sets the flag at this+0xE8 to 1; used by seven widget-construction paths including GameOptionsUIConstructor (0x0047E960).
- `0x004894D0` **UnknownObject** — String tail stamp: writes the fixed two-byte global word_5C692C over the two bytes at a1[strlen(a1)] (the terminator position), returns 0, or -1 when a1 is null; used by results/standings/message/HTML writers to stamp a shared value onto name/text buffers.
- `0x00489920` **UnknownObject** — Node text accessor: looks up a node via LinkedListTraversalByIndex, reads the string pointer at node+176 (0xB0), returns it or byte_5EA438 when null, and returns null when the node lookup fails; UI text/screen context.
- `0x00489C60` **IndexedItemList** — Indexed text lookup over the item list (head this+0x90, count this+0x94): when index a2 is in [0, count), walks a2 steps via the node next pointer at +0x8C and returns the string at +0xA0; byte_5EA438 default on out-of-range/missing nodes.
- `0x00489E90` **ScrollListControl** — Scroll index to pixel conversion: converts this+0x14C to this+0x150 via round(scroll_index / max_scroll * display_size) with CRTFtol; skips and clears output when max scroll (this+0x160) is zero.
- `0x00489EE0` **ScrollListControl** — Scroll offset reset: zeros this+0x14C, then when max scroll (this+0x160) is non-zero and display size (this+0x154) cast to double is above 0.0, stores the CRTFtol-truncated display size as the new scroll offset.

## Proposed classes

### UiControl

Large UI option/switch control. Constructors run a shared base-field initializer (0x00466D60) with flag 1, install a per-class vtable at +0, write a data reference at +0x31C and state/flag literals plus a component identifier at +0x324..+0x338, and (for option variants) attach two linked-list nodes carrying the handles off_5BE704 and aOn with value -1 before running construction-time virtual dispatch (0x004670E0).

Methods: `0x004715D0`, `0x00472040`, `0x00472A80`, `0x00473C40`

- `this+0x00000000` `void* (vtable) vtable` (write, GUESS)
- `this+0x0000031C` `void* dataReference` (read_write, GUESS)
- `this+0x00000324` `int flagLiteral1` (write, GUESS)
- `this+0x00000328` `int flagLiteral2` (read_write, GUESS)
- `this+0x0000032C` `int flagLiteral3` (read_write, GUESS)
- `this+0x00000330` `int flagLiteral4` (read_write, GUESS)
- `this+0x00000334` `int componentId` (read_write, GUESS)
- `this+0x00000338` `int valuePreset` (write, GUESS)

### UiWidget

UI widget object constructed by ConstructorInitVTable: base init (0x00485E30), two constructor parameters stored at +0xE0/+0xE4, vtable off_5ABC28 at +0, active/enabled flag at +0xE8.

Methods: `0x00488B00`

- `this+0x00000000` `void* (vtable) vtable` (write, GUESS)
- `this+0x000000E0` `int parameterA` (write, GUESS)
- `this+0x000000E4` `int parameterB` (write, GUESS)
- `this+0x000000E8` `bool activeFlag` (write, GUESS)

### UiStringAccessor

String accessor over a sub-object pointer at this+0xC8. Returns a char* read at sub-object +0x28/+0x40/+0x48 depending on the variant, substituting the global default string byte_5EA438 when the pointer is null.

Methods: `0x00486280`, `0x004862C0`, `0x004862E0`

- `this+0x000000C8` `void* subObject` (read, DERIVED)

### IndexedItemList

Owns an indexed item list: head at this+0x90, node count at this+0x94, node next pointer at +0x8C, node text at +0xA0. Supports inserting/appending a node that copies three source fields (this+0x40/+0x98/+0x9C) and fetching an item's text by index.

Methods: `0x00486340`, `0x00489C60`

- `this+0x00000040` `int copiedSourceField1` (read, GUESS)
- `this+0x00000090` `void* listHead` (read_write, GUESS)
- `this+0x00000094` `int itemCount` (read_write, GUESS)
- `this+0x00000098` `int copiedSourceField2` (read, GUESS)
- `this+0x0000009C` `int copiedSourceField3` (read, GUESS)
- `this+0x0000008C` `void* nodeNext` (read_write, GUESS)
- `*(this+0x11C)+0x0000008C` `void* nodeNextIndirect` (read, UNKNOWN)
- `*(this+0x11C)+0x000000A0` `char* nodeTextIndirect` (read, UNKNOWN)

### StringList

Linked list of strings: head at this+0x54, tail at this+0x58, alternate pointer at +0x5C, node count at +0x60. LinkedListNodeInsert allocates an 8-byte data buffer and a 12-byte node (data pointer, next, flag byte), copies the source string in, and appends the node.

Methods: `0x00486580`

- `this+0x00000054` `void* head` (read_write, GUESS)
- `this+0x00000058` `void* tail` (read_write, GUESS)
- `this+0x0000005C` `void* alternatePointer` (write, GUESS)
- `this+0x00000060` `int nodeCount` (read_write, GUESS)

### ScrollListControl

Scrollable list control: converts the scroll index at +0x14C to a pixel position at +0x150 using display size (+0x154) and max scroll (+0x160) via round(index/max*display) with CRTFtol; resets the offset during list refresh.

Methods: `0x00489E90`, `0x00489EE0`

- `this+0x0000014C` `float scrollIndex` (read_write, GUESS)
- `this+0x00000150` `int pixelPosition` (write, GUESS)
- `this+0x00000154` `float displaySize` (read, GUESS)
- `this+0x00000160` `float maxScroll` (read, GUESS)

### SeasonSceneController

Season-scene UI controller: dispatches a virtual command object, searches the season scene by name, records match indices (this+0x174, this+0x184), walks a scene-item list (head at this+0xF0, cursor at +0xF8) comparing node path strings at node+0x3C against path globals (dword_7CE64C/dword_7CE5EC with byte_5EA438 fallback), triggers scene-list search, and runs a vtable+160 content callback.

Methods: `0x00477720`, `0x00477AA0`

- `this+0x00000000` `void* (vtable) vtable` (read, GUESS)
- `this+0x000000F0` `void* sceneListHead` (read, GUESS)
- `*(this+0xF0)+0x0000003C` `char** nodePath` (read, GUESS)
- `this+0x000000F8` `void* listCursor` (read_write, GUESS)
- `this+0x00000174` `int matchIndex` (write, GUESS)
- `this+0x00000184` `int searchMatchIndex` (write, GUESS)
- `obj+0x000000A0` `void* (fn ptr) virtualCallback160` (unknown, GUESS)

### NetworkSessionController

Network session/browser UI controller: resets a network flag (global byte_7CD850), refreshes the browser list, and conditionally starts LAN discovery (StartNetworkUpdate with global dword_7CD25C) when the guards pass, marking the started flag at +0x17C.

Methods: `0x00475530`

- `this+0x0000017C` `bool discoveryStarted` (read_write, GUESS)

### AnimatedElementRenderer

Animated UI element renderer: retrieves element bounds through the vtable method at offset 8, computes width/height, and dispatches to an animated render helper (0x00491C70) or a static render helper (0x00491CB0) based on TimedAnimationTrigger (0x00486730).

Methods: `0x00486830`

- `this+0x00000000` `void* (vtable) vtable` (read, GUESS)
- `obj+0x00000008` `void* (fn ptr) boundsMethod` (unknown, GUESS)

### TelemetryDisplayControl

Telemetry display UI control: dispatches vehicle telemetry data to a text element based on a mode selector at +0xEC (vehicle list, lifetime-average delta, range width, engine/RPM status), reading accessors on global dword_8AB6EC and post-process data at global dword_7C54E0.

Methods: `0x0047DBE0`

- `this+0x000000EC` `int modeSelector` (read, GUESS)

## Compatibility contracts

- **VehicleConfigValidation** — The replacement must provide a validation routine taking (global state pointer, null-terminated path with trailing backslash, literal flag 1) and returning a boolean result; the path is produced by a path builder that fills a 256-byte stack buffer ending in a backslash.
- **UiControlConstruction** — A constructed UI control must: run the shared base-field initializer (0x00466D60) with flag 1, install a class vtable at +0, write a data reference at +0x31C and flag/ID literals at +0x324..+0x338, and (option variants) insert two linked-list nodes carrying the handles off_5BE704 and aOn with value -1 before running construction-time virtual dispatch at 0x004670E0.
- **FixedWordTailStamp** — StrlenOverwrite stamps the fixed two-byte word at global 0x005C692C over the NUL terminator and the byte after it of a caller-owned name/text buffer; callers must treat the buffer as a fixed-size field rather than a C string afterwards.
- **DefaultStringFallback** — UI string accessors must substitute the global default string byte_5EA438 whenever the primary string pointer (sub-object string at this+0xC8 or node text) is null.
- **SeasonSceneCallback160** — Season-scene objects expose a vtable callback at slot +160 (vtable object base 'obj'), reached through the vtable pointer at +0, invoked during scene initialization and content filtering.
- **NetworkDiscoveryStart** — LAN network discovery starts only when dword_7D0E74 is zero, byte_7D0FAC is non-zero, and the object's started-flag at +0x17C is zero; the start call receives global dword_7CD25C and sets +0x17C to 1.

## Unresolved

- this+0xC8 carries different apparent roles across functions: sub-object pointer in the string accessors (0x00486280/0x004862C0/0x004862E0) vs an out-of-bounds guard flag in XOffsetLinkedLookupWithGuard (0x004870E0); not proven to be the same field.
- GetItemTextByIndex (0x00489C60) addresses node next/text fields through base *(this+0x11C) in the deterministic field facts while the raw body seeds the walk from this+0x90; whether these denote the same list storage is not proven.
- StructFieldAccessor (0x00486320) reads receiver +0x8C directly as an int, while 0x00486340/0x00489C60 treat +0x8C as a node next pointer; the relationship between these uses is unproven.
- Telemetry mode constants 0x1E0/0x1E1/0x1E2/0x1E3 and the byte offsets 16480/17952 inside the dword_7C54E0 structure are inferred from usage, not independently evidenced.
- GameContentFilterCheck (0x00477AA0) filter comparison semantics (0 == match) are inferred from the skip/callback control flow, not proven.
- RaceLapsStringLoadOnTrigger (0x0047E3F4) prologue is a decompiler artifact (a2+95 increment, corrupted indirect call with icebp, bad/positive stack pointer); its true call graph is uncertain.
- ResolveStringAndCopy (0x00476F90) guard dword_7D0410 != 5 is an unexplained mode constant; byte_5EA438's exact contents are not established.
- sub_568910(128) semantics and the origin of the local stack string in StripFileExtension (0x0047BEB0) are not established.
- The value and purpose of word_5C692C are unknown; the StrlenOverwrite write lands on the NUL terminator position.
- Semantics of the dword_7CD8C0 +28 virtual command dispatch (literal 20) and of the vtable+160 callback are not established.
- Owner classes of the ten UnknownObject functions (0x0046E5C0, 0x00476F90, 0x0047BEB0, 0x0047E3F4, 0x004861A0, 0x00486320, 0x00486710, 0x004870E0, 0x004894D0, 0x00489920) are unknown; no static callers grounded in this packet.
- UiControl's literal block at +0x324..+0x338 (flags vs min/max vs ID) and the two option-node handles off_5BE704/aOn are unverified semantics.
- StringList's node flag byte at node offset 8 and the -1 value at data-buffer offset 4 are unexplained.
- The invalid/missing dword_7D0398/dword_7D0410 guard pair and the 'a2'/'a1' return transition in ConditionalMultiParamDispatch (0x004861A0) are unmodeled.
- Fields this+0xF0 (GetSubobjectString), this+0x108 (GetCachedStringWithFallback), this+0x110 (GetSubObjectString), this+0x11C/this+0x234 (LinkedListNodeInsertOrAppend), this+0xFC (SeasonSceneInitialization) are present in the struct layout but never accessed by their function bodies.
