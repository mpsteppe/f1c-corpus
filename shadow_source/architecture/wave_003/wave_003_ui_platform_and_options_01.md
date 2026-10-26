# UiPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

DERIVED grouping of 20 validated IR functions covering the UI/platform/options scope. (1) Six UI-list/screen constructors (0x00470670, 0x004706F0, 0x00470850, 0x00470CC0, 0x00470D30, 0x00471B20) plus the value-to-string helper 0x00472CC0 share one screen layout: base initializer, distinct vtable at +0x0 (off_5A03C0/5A0480/5A0540/5A0840/5A0900/5A1680), data-source/type field at +0x31C, four config flags at +0x324/+0x328/+0x32C/+0x330, a component-id literal at +0x334 (405/406/401/408/409/247), and linked-list text-handle entries via LinkedListInsertWithNodeAllocation. (2) Five page builders (0x00468BF0 career results, 0x00469900 player stats, 0x00469FB0 results list, 0x0046BC20 lap-time list, 0x00470190 scene menu) emit UIMenuItemCreator rows with UIListIndexedAccessor labels after StateCleanupNotification, reading the race-results list and the scene-record array. (3) Standalone platform/path helpers: game-mode lookup (0x00404CC0), Windows version detection (0x004230C0), resource path formatter (0x0042ED70), save-path builder (0x0046E600), subsystem virtual dispatch (0x0046FE50), championship/multiplayer entry (0x00463BC0), and DirectX device init (0x0044FA60). Owners are almost entirely UNKNOWN in the packet; only buildRaceResultsPage (GrandPrixResultsHtmlWriter, DERIVED) and UICameraConstructor (UICamera, DERIVED) carry names. Equal offsets on different bases (this+0x17C, this+0x31C) are kept separate or flagged: not proven to share ownership.

## Function roles

- `0x00404CC0` **UnknownObject** — Game-mode lookup: scans the 5-entry mode-name pointer array off_5BE6C4 comparing each entry against configuration argument a1 via sub_588410; returns the first index whose entry matches, and 0 when the array is exhausted (identical to a match at index 0 - the caller disambiguates). ConfigIniParser (0x00421CD0) is the caller.
- `0x00415C40` **SceneList** — Rebuilds the scene-entry linked list owned by the container (head this+0x20, tail this+0x24, first-insert this+0x28, count this+0x2C): frees existing nodes via FreeWrapper_7bcf (invoking ShortComputation_8cf0(1) when a node's flag byte at +8 is set with a nonzero first dword), zeroes the four list fields, then rebuilds one 92-byte node per record in the global array dword_8AC490 (stride 396, count dword_8AC488): node[0]=0, node[1]=-1, two 5-dword sub-structs at +12 and +52, the text-format block, the per-entry string (base + 260), entry index at +8, commentary TV/PWS paths, wrapped in a 12-byte list entry (node, 0, flag 1).
- `0x004230C0` **UnknownObject** — Windows platform detection: queries the OS version via GetVersionExA (156-byte OSVERSIONINFOA, retrying with 148 bytes) and selects the platform-name string (Win32s / Windows 95/98/Me / Windows NT/2000/XP by dwPlatformId and major/minor) into a local buffer, copying it into the caller's output argument when non-null and returning the string length. Caller ConfigIniParser (0x00421CD0).
- `0x0042ED70` **PathFormatObject** — Resource-path formatter: resolves string components through BinarySearchInStringTable against the global table byte_5EC4C0 into the working buffer byte_5EC4CC and writes formatted paths into the object: base component always to this+40; when the format selector at this+4 is nonzero, components at this+8/this+24 and formatted paths at this+56 ("%s/%s") and this+72 ("%s/%s/%s") plus this+88; when zero, an alternate component set produces the same two paths and a single string. Returns a pointer into byte_5EC4CC on the alternate branch.
- `0x0044FA60` **RenderDeviceManager** — Rendering-device setup: seeds two constant arrays in an 8-iteration loop, optionally re-enumerates the device via the ppvOut object (global 0x007CA590) when the capability/version field at this+0x2F4 differs from 20, creates the device (stored at this+0x80) through the interface vtable slot 0 with &unk_5AD490, configures the device through its vtable slots (0xC with the parameter block at this+0x2C8, 0x18, 0x1C, 0x20, 0x2C with &unk_5B108C, 0x34), then returns D3DTextureStage(this); every failure path returns -1. Called by HWInput_Setup (0x00455C60).
- `0x00463BC0` **GameModeSelectorEntry** — Championship/multiplayer entry handler: when the enable flag byte at obj+0xC5 is non-zero, sets championship mode dword_7D0410 to 5 (with overrides dword_7D0418/dword_7D041C), sets the flag byte_7D0F94 to 1, invokes SingleFunctionCallWrapper_a920 on the sub-object at obj+0x3FB8, then dispatches the 'Select Circuit' (0x005C65EC) or 'Multiplayer Create' (0x005C6600) prompt via LookupDispatch depending on sub_463C60; returns 1 on the taken path, 0 when the flag is clear. Caller sub_485B90.
- `0x00468BF0` **GrandPrixResultsHtmlWriter** — Career race-results page builder: syncs the global track name dword_7CE668 from this+0x17C, walks the race-result list (head dword_7D2DC0, cursor dword_7D2DC8), resolves each entry's grand-prix name via SeasonRacesSectionFinder / StringKeyedLinkedListSearch / DataEntryAccessor, formats the race number (node+16) and lap time (node+20 float, "%i:%06.3f"), and emits one UI menu item per column with labels from UIListIndexedAccessor(10/11/12). Caller 0x00468A00.
- `0x00469900` **UiPageBuilder** — Player-stats display page builder: seeds buffers from word_5C694C and byte_5EA438, updates the global track-name string dword_7CE668 from this+0x180 when they differ, walks the race-result list (dword_7D2DC0/dword_7D2DC8), formats grand-prix name, race number and lap time per entry, and emits UI menu items prefixed by the path buffer with column labels from UIListIndexedAccessor(0/1/2), with a blank separator item before every list entry.
- `0x00469FB0` **UiPageBuilder** — Results page menu builder: calls StateCleanupNotification, walks the race-results list (dword_7D2DC0/dword_7D2DC8), skips entries whose path matches the settings path (dword_7CE5EC), resolves the track name via SeasonRacesSectionFinder under the aTrackname key, formats race number and lap time, and emits rows via UIMenuItemCreator with column headers from UIListIndexedAccessor(1/2). ABI label Results_Page_Builder is LEGACY-only and unverified.
- `0x0046BC20` **UiPageBuilder** — Lap-time list builder for a vehicle: resolves the slot this+0x178 into the global vehicle array (0x005EC6D8, stride 18624), resets this[94] to -1 when the slot is inactive (vehicle +3250 == -1) or has no laps (lap count at +4111 < 1), otherwise copies the two 47-char vehicle names (offsets 17952 and 18104), walks up to min(lap count, display limit at +4143) rows formatting per-lap flag (byte list at +4146), lap number, lap time (float at +4145) and gap-to-best (best lap at +4135), records the best-lap row into this+0x168, applies the display filter this+0x17C, and emits each row via UIMenuItemCreator; returns the row count or -1.
- `0x0046E600` **UnknownObject** — Save-path builder: allocates a 128-byte working buffer, obtains the base directory from PathStringCombinator(dword_7C73E0), appends a backslash when the buffer does not end with one, copies the object-name argument (max 127 chars), sanitizes it via ReplaceSpecialCharsWithUnderscoreHyphen, appends the sanitized name, the '.svm' extension (0x005C403C) and the extra argument a2, then frees the working buffer. Callers InitWithStackBuffer and ClearBufferAndInit.
- `0x0046FE50` **UnknownObject** — Straight-line UI-subsystem dispatch: runs ShortComputation_fec0, sets a boolean flag true via BooleanFlagSetterVirtualCall(1), dispatches vtable slot +28 of the object at dword_7CD8C0 with argument 13, and when the returned object is non-null compares its name against the `this` argument via ObjectNameComparison; always returns 0.
- `0x00470190` **UiPageBuilder** — Scene-list UI menu builder: calls StateCleanupNotification, then for each of the dword_8AC488 scene records (array base dword_8AC490, stride 396; string fields at +260 and +324) formats a scene label with "%s, %s%s%s%s%i" (separator word_5C692C, time format aI063f) and emits one UI menu item via UIMenuItemCreator; returns the scene count. Called by SetupFileLoadAndFinalize.
- `0x00470670` **UiScreen** — UI screen constructor: runs the base initializer ShortComputation_6d60(this, 1), installs the vtable off_5A03C0 at +0x0, points +0x31C at the data source unk_7D1250, sets flags +0x324/+0x328/+0x32C/+0x330 to 1/0/1/1 and +0x334 to 405, inserts two linked-list entries (off_5BE704 and the 'On' string aOn) via LinkedListInsertWithNodeAllocation(this, handle, -1), runs SwitchOnActionIDVirtualCall, and returns this.
- `0x004706F0` **UiScreen** — UI list-options constructor: runs the base UI-list constructor sub_48C070(this, 1), installs the vtable off_5A0480 at +0x0, writes 406 at +0x31C, inserts a linked-list node for off_5BE704 with index -1, runs RaceModeScreenSetup, and returns this.
- `0x00470850` **UiScreen** — Selected-season UI list constructor: calls the base UI-list constructor sub_48C070(this, 1), installs the vtable off_5A0540 at +0x0, sets +0x31C to 401, inserts four linked-list entries (off_5BE704, 'Normal', 'TimeScaled', 'SelectedSeason') with append index -1, runs SessionSetupScreenSetup, and returns this.
- `0x00470CC0` **UiScreen** — UI-list constructor: runs the base initializer ShortComputation_6d60(this, 1), installs the vtable off_5A0840 at +0x0, stores the external reference unk_7CF014 at +0x31C, sets flags +0x324..+0x330 to 1/0/1/1 and +0x334 to 408, inserts two linked-list entries (off_5BE704 and aOn) with index -1, and returns this.
- `0x00470D30` **UiScreen** — UI camera constructor: runs base init ShortComputation_6d60(this, 1), installs the vtable off_5A0900 at +0x0, stores the data pointer dword_7CF038 at +0x31C, sets flags +0x324..+0x330 to 1/0/1/1 and +0x334 to 409, inserts two linked-list entries (off_5BE704 and aOn) with index -1, and returns this. Packet labels the owner UICamera (DERIVED); folded into the shared UiScreen layout because the field/flag/link pattern is identical to the other constructors.
- `0x00471B20` **UiScreen** — UI component constructor: runs base init ShortComputation_6d60(this, 1), installs the vtable off_5A1680 at +0x0, stores the data-source pointer dword_7CE6F4 at +0x31C, sets flags +0x324..+0x330 to 2/0/1/1 and +0x334 to 247, inserts three linked-list nodes (off_5BE704, off_5C32A4, aHigh), runs SwitchOnActionIDVirtualCall, and returns this.
- `0x00472CC0` **UiScreen** — UI value-to-string pipeline: reads an index through the pointer at this+0x31C, retrieves the indexed value via UIListIndexedAccessor, formats it into a local buffer with StringFormatWithBufferOverflowCheck, and pushes it to the edit/display buffer via EditBufferStringUpdate, returning that update's result.

## Proposed classes

### UiScreen

UI screen/list base layout shared by the six constructors and the value-to-string helper: vtable pointer at +0x0, data-source/type field at +0x31C, four configuration flag words at +0x324/+0x328/+0x32C/+0x330, a component identifier literal at +0x334, and a linked list of text-handle entries registered via LinkedListInsertWithNodeAllocation. Each constructor installs a distinct vtable (off_5A03C0/5A0480/5A0540/5A0840/5A0900/5A1680), so the concrete types differ; this class captures the shared layout only (GUESS grouping - the packet leaves owners UNKNOWN, except UICamera for 0x00470D30).

Methods: `0x00470670`, `0x004706F0`, `0x00470850`, `0x00470CC0`, `0x00470D30`, `0x00471B20`, `0x00472CC0`

- `this+0x00000000` `void** vtbl` (read_write, DERIVED)
- `this+0x0000031C` `void* dataSourceOrTypeId` (read_write, DERIVED)
- `this+0x00000324` `int configFlag0` (write, GUESS)
- `this+0x00000328` `int configFlag1` (write, GUESS)
- `this+0x0000032C` `int configFlag2` (write, GUESS)
- `this+0x00000330` `int configFlag3` (write, GUESS)
- `this+0x00000334` `int componentId` (write, GUESS)

### UiPageBuilder

UI page builders that emit menu rows over the shared race-results list walk (head dword_7D2DC0, cursor dword_7D2DC8) and the global scene-record array (dword_8AC490): career results, player stats, results list, lap-time list and scene-list menu. They share track-name handling (this+0x180, this+0x17C, global dword_7CE668), vehicle-slot selection (this+0x178), best-lap row capture (this+0x168), and emission via UIMenuItemCreator with UIListIndexedAccessor labels after StateCleanupNotification. GUESS grouping: the packet leaves owners UNKNOWN for all but buildRaceResultsPage (GrandPrixResultsHtmlWriter) and does not prove these objects share one class.

Methods: `0x00468BF0`, `0x00469900`, `0x00469FB0`, `0x0046BC20`, `0x00470190`

- `this+0x00000168` `int bestLapRowIndex` (write, GUESS)
- `this+0x00000178` `int vehicleSlotIndex` (read, GUESS)
- `this+0x0000017C` `int/char* displayFilterOrTrackName` (read, GUESS)
- `this+0x00000180` `char* trackName` (read, GUESS)

### SceneList

Container for a linked list of 92-byte scene entry nodes wrapped in 12-byte list entries: head at +0x20, tail at +0x24, first-insert at +0x28, count at +0x2C, and the tail wrapper's next link at +0x4 (base *(this+0x24)). Rebuilt by SceneListBuilderFromGlobalArray from the global scene-record array (dword_8AC490, stride 396, count dword_8AC488).

Methods: `0x00415C40`

- `this+0x00000020` `void* head` (read_write, DERIVED)
- `this+0x00000024` `void* tail` (read_write, DERIVED)
- `this+0x00000028` `void* firstInsert` (read_write, DERIVED)
- `this+0x0000002C` `int count` (read_write, DERIVED)
- `*(this+0x24)+0x00000004` `void* tailNodeNextLink` (read_write, GUESS)

### PathFormatObject

Object that accumulates formatted resource-path strings: a format-selector flag at +0x4 selects between two component sets; resolved components land at this+8/+24/+40 and formatted paths at this+56 ('%s/%s'), this+72 ('%s/%s/%s') and this+88, all resolved through BinarySearchInStringTable against the global table byte_5EC4C0 into byte_5EC4CC. Only +0x4 is declared as a field: the buffer offsets beyond +0x4 carry no packet field evidence refs (carried from the packet summary text only, GUESS), so they are documented here and in unresolved rather than declared as fields.

Methods: `0x0042ED70`

- `this+0x00000004` `int formatSelector` (read, DERIVED)

### RenderDeviceManager

Front-end rendering-device owner for the input/HW module: device pointer at +0x80, capability/version field at +0x2F4 (20 selects the current path), device parameter block at +0x2C8, and the device vtable base at +0x0 of the device object. Creates and configures the device through its vtable (see RenderDeviceInterface) and ends with D3DTextureStage. Called from HWInput_Setup.

Methods: `0x0044FA60`

- `this+0x00000080` `void* devicePtr` (read_write, DERIVED)
- `this+0x000002C8` `int[11] deviceParamBlock` (read, GUESS)
- `this+0x000002F4` `int capabilityVersion` (read, DERIVED)
- `*(this+0x80)+0x00000000` `void** deviceVtbl` (read, DERIVED)

### RenderDeviceInterface

Vtable contract of the rendering device created by DirectXDeviceInitialization: the six slots observed to be invoked (0x0C parameter-block setup, 0x18, 0x1C, 0x20, 0x2C preset configuration with &unk_5B108C, 0x34 two-argument call) plus creation through vtable slot 0 with &unk_5AD490. Slots are exercised only through function pointers; exact Direct3D/DirectDraw interface identities are not established.

Methods: 

- `*(*(this+0x80)+0x0)+0x0000000C` `fn ptr vtableSlot0C` (read, GUESS)
- `*(*(this+0x80)+0x0)+0x00000018` `fn ptr vtableSlot18` (read, GUESS)
- `*(*(this+0x80)+0x0)+0x0000001C` `fn ptr vtableSlot1C` (read, GUESS)
- `*(*(this+0x80)+0x0)+0x00000020` `fn ptr vtableSlot20` (read, GUESS)
- `*(*(this+0x80)+0x0)+0x0000002C` `fn ptr vtableSlot2C` (read, GUESS)
- `*(*(this+0x80)+0x0)+0x00000034` `fn ptr vtableSlot34` (read, GUESS)

### GameModeSelectorEntry

Entry-handler object that switches into championship/multiplayer mode and dispatches the 'Select Circuit' or 'Multiplayer Create' prompt. Enable flag byte at obj+0xC5, sub-object at obj+0x3FB8 reached through the primary pointer at this+0x0.

Methods: `0x00463BC0`

- `obj+0x000000C5` `byte enableFlag` (read, DERIVED)
- `obj+0x00003FB8` `void* subObject` (read, DERIVED)

## Compatibility contracts

- **PlatformVersionStringDetection** — DetectWindowsVersionString (0x004230C0) fills a caller-provided buffer with a platform-name string (Win32s / Windows 95/98/Me / Windows NT/2000/XP) using GetVersionExA, retrying with a 148-byte OSVERSIONINFOA after the 156-byte attempt; ConfigIniParser (0x00421CD0) consumes the result during config parsing. A replacement must produce the same platform naming and buffer contract (output copied only when non-null, length returned).
- **ResultsListMenuEmissionContract** — UI page builders (0x00468BF0, 0x00469900, 0x00469FB0, 0x0046BC20, 0x00470190) emit menu rows via UIMenuItemCreator (0x00489600) using text composed by StringFormatWithBufferOverflowCheck (0x0058815F), with column labels from UIListIndexedAccessor (0x00487010) after StateCleanupNotification (0x00489CB0). A replacement menu system must expose these behaviors and honor the shared race-results walk state (head dword_7D2DC0, cursor dword_7D2DC8) so page order and list advancement are preserved.
- **SceneEntryArrayLayout** — SceneListBuilderFromGlobalArray (0x00415C40) and SceneListUIMenuBuilder (0x00470190) read scene records from the global array at dword_8AC490 with a 396-byte stride and count dword_8AC488, using string fields at +260 and +324; scene nodes are 92-byte allocations with two 5-dword sub-structs and an entry index at +8, wrapped in 12-byte list entries appended head/tail/count at this+0x20/0x24/0x28/0x2C. A replacement must preserve the stride and the +260/+324 string offsets to keep saved scene data readable.
- **VehicleLapDataLayout** — LapTimeListDisplayBuilder (0x0046BC20) reads the vehicle array at 0x005EC6D8 (stride 18624) using this+0x178 as the slot index, validating the slot live flag at +3250, lap count at +4111, display limit at +4143, per-lap flag bytes at +4146, lap-time floats at +4145 and the best lap at +4135, and copies the two 47-char name strings at +17952 and +18104. A replacement must preserve these offsets for the UI to read lap data.
- **SaveGamePathFormat** — PathBuilderWithBackslash (0x0046E600) builds '<base_dir>\<sanitized_name>.svm<extra>' where the base directory comes from PathStringCombinator (0x00432870) reading dword_7C73E0, the name is sanitized via ReplaceSpecialCharsWithUnderscoreHyphen (0x00568560), and a trailing backslash is appended when missing. Save-game compatibility requires identical path construction.
- **RenderDeviceInterfaceContract** — DirectXDeviceInitialization (0x0044FA60) creates a rendering device whose interface (obtained through ppvOut, global 0x007CA590) must support vtable slots 0x0C/0x18/0x1C/0x20/0x2C/0x34 as invoked (parameter block at this+0x2C8, preset &unk_5B108C, two-argument call), stores the device at this+0x80, re-enumerates when the capability field this+0x2F4 differs from 20, and ends with D3DTextureStage (0x0044F8F0). Called from HWInput_Setup (0x00455C60). Interface identities are not proven (GUESS).

## Unresolved

- The six UI constructors each install a distinct vtable (off_5A03C0/5A0480/5A0540/5A0840/5A0900/5A1680), so UiScreen is a layout grouping, not a proven single class; the packet's DERIVED owner UICamera for 0x00470D30 is folded into the grouping and the divergence is not resolved.
- The buffer offsets of PathFormatObject beyond +0x4 (component strings at this+8/+24/+40, formatted paths at this+56/+72, single string at this+88) are carried from the packet summary text only; the packet provides no matching field evidence refs (only field:this:0x00000004), so they are documented in the class responsibility and unresolved rather than declared as fields.
- The meaning of the flag words +0x324/+0x328/+0x32C/+0x330 (1/0/1/1 in five constructors, 2/0/1/1 in 0x00471B20) and of the component identifier literals at +0x334 (405, 406, 401, 408, 409, 247) is not established; the labels (config flags, component id) are GUESS.
- The race-results list node layout (string at +0, link at +4, race number at +16, lap-time float at +20) is inferred from the page builders' access pattern only, not struct-confirmed.
- The scene record layout (stride 396, string fields at +260 and +324) and the 92-byte scene node layout (two 5-dword sub-structs, entry index at +8, text-format block) are derived from allocation/initialization calls, not from a confirmed record definition.
- Equal offsets recur on different bases: this+0x17C is a track-name source in buildRaceResultsPage but a display filter in LapTimeListDisplayBuilder; this+0x31C is a data-source pointer in the constructors but an index pointer in UIStringFormatDisplay. They are kept as separate field entries and are not proven to share ownership (worker rule 8).
- The DirectX interface identities (ppvOut, global 0x007CA590; device at this+0x80) are exercised only through vtable slots; exact Direct3D/DirectDraw identities are not established. The 8-iteration loop writes this[8..15] and this[190..197], offsets absent from the packet field table; the literal constants 1028443341 and 1065353216 are kept in packet spelling.
- The exact byte contents of the format-template globals (aSSS at 0x005C374C, aSS_1 at 0x005C3760, aD_1 at 0x005C3280, aI063f at 0x005C6930, aSSSSSI at 0x005C6E1C, aSSS_0 at 0x005C6784) are not stated in the packet; matching them to the inline literals ("%d", "%s/%s", "%s/%s/%s", "%i:%06.3f", "%s, %s%s%s%s%i", "%s%s%s") is DERIVED from argument order and address adjacency, not directly evidenced.
- Packet-listed globals flagged by facts but absent from the raw source of one or more functions: aD_1 (0x005C3280), 0x005C3310, 0x005C6784, 0x005C6930, 0x005C6984, 0x005C6AB0, flt_59E440 (0x0059E440), flt_59E9C0, dbl_59E9C8 and unk_8AC368 (0x008AC368); their binding is unknown.
- The four 0xFF... globals (0xFF00000000005370..374) in DetectWindowsVersionString are decompiler mis-analysis artifacts of invalid pointer arithmetic, not real data accesses; the return value for dwPlatformId values outside 0..2 (dwPlatformId - 2) is likewise a decompiler artifact. The actual string content of the platform-name globals is not visible in this packet.
- sub_588410's contract is not in this packet; corpus-side IR identifies it as a case-insensitive string compare returning strcmpi order (DERIVED reading, not packet evidence). Under that reading QuickRace returns the first array entry matching a1, and 0 means no match within five; a no-match returns 0, identical to a match at index 0 - the caller (ConfigIniParser) disambiguates, but its config-token context is not in the packet.
- The vtable slots invoked through ppvOut/v11 (offsets 0, 8, 12, 16) and the subsystem-dispatch vtable slot +28 of dword_7CD8C0 have no packet field evidence and are described from source:raw only; dword_7CD8C0 is an unnamed singleton/manager whose identity is unproven, and in EnterMultiplayerOrCircuitSelection it appears as a transitive read not directly referenced in that function's raw source.
- PlayerStatsDisplayBuilder's path-prefix assembly from byte_5EA438[0] and the clearing of the v30 terminator high byte are inferred; SceneListUIMenuBuilder reads integer argument v5 uninitialized in the raw source, whose source and role are unknown.
- PathBuilderWithBackslash discards the return of StringCopyWithBufferRealloc; the exact accumulation point of the combined path is unresolved, and the trailing-backslash check/appends write a shared buffer whose final destination is not visible in this function.
- StringCopyWithBufferRealloc in SceneListBuilderFromGlobalArray is called with a computed global address (dword_8AC490 + 260 + 396*i); whether it copies into the global array or into the new node is unresolved.
- The label strings returned by UIListIndexedAccessor indices 0/1/2/10/11/12 are defined elsewhere; their content is unknown.
- The meaning of the 'On' handle (aOn, 0x005C32C8), the off_5BE704 UI handle, and the insertion key -1 passed to LinkedListInsertWithNodeAllocation is unverified.
- dword_7D0418/dword_7D041C are override sources for the championship mode value whose exact semantics are not established; the meaning of the enable flag at obj+0xC5 and the sub-object at obj+0x3FB8 is unknown.
- Most function owners are UNKNOWN in the packet; the class groupings (UiScreen, UiPageBuilder) are semantic GUESS groupings, not proven object boundaries.
- GetVersionExA retry sizing (156 then 148 bytes) and the memset zeroing of OSVERSIONINFOA before each call are observed behavior; the OS-version branches themselves are standard Win32 semantics inferred from dwPlatformId values 0/1/2.
