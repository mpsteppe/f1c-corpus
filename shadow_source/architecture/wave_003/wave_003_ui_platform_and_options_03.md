# UIPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

This subsystem reconstructs a UI control platform and options layer. A central UIWidget object (GUESS) owns a string buffer (+0x40), a path string (+0xB8), a text/font resource object pointer (+0xC8), a list head/count (+0x90/+0x94), a render-node pool (+0xEC..+0xF8), dimension arrays (+0x110..+0x14C), layout/count fields (+0x14C..+0x174) and a window-control type (+0x30C). Render dispatch (0x00488F40, 0x00489FD0, 0x0048B030), list selection (0x00489AB0), dimension capture (0x0048EBD0), text-window setup (0x0048F9F0), path-based window classification (0x0048C0E0, 0x004901A0) and click-event forwarding (0x004957A0) all operate on that object. A text input handler (0x004896C0) word-wraps input into per-line menu items, an event shortcut handler (0x0048B600) implements a text-edit field keyboard state, a viewport layout calculator (0x0048F640) computes a tile grid, a renderer (0x0048FEE0) draws a text region in one of three modes, two constructors initialize UI objects (0x0048FC50, 0x0048FD60, 0x0048FE60), an options reader (0x00492160) parses .OSC configuration files, and three helpers dispatch UI messages (0x00494F10), clean up a global UI iterator (0x004950C0), and render a multi-option text dialog (0x00495BD0). A recurring default-string global byte_5EA438 substitutes for null strings throughout.

## Function roles

- `0x00488F40` **UIWidget** — UI render dispatch wrapper: copies a resolved child string (*(this+0xC8)+0x40, default byte_5EA438) into the widget string buffer at this+0x40, then delegates rendering to UILargeRenderDispatcher with the caller's arguments.
- `0x004896C0` **UITextInputHandler** — Word-wraps input text to the available widget width, creating one UI menu item per wrapped line and optionally naming each item; measures text with TextRenderToSurface and finalizes via sub_489D00 and a vtable+44 completion dispatch. Returns -1 on null input.
- `0x00489AB0` **UIWidget** — Validates a 1-based selection against the item count at this+0x94, stores the 0-based selection at this+0x168 (or -1 on invalid input), optionally scrolls the list, then walks the list from this+0x90 and passes four node strings to a vtable display method (obj+0xA8).
- `0x00489FD0` **UIWidget** — Dispatches custom UI render nodes: walks the list from this+0x90, resolves each node name through DriverNameStringHandler/StringArrayMatchSearch against a name array with byte_5EA438 fallback, computes per-node render geometry, dispatches node render through the node vtable slot 52, and accumulates viewport bounds into the caller out-parameters. Returns -1 when row/column counts are invalid.
- `0x0048B030` **UIWidget** — Full UI text render pass with word-wrap: measures the horizontal boundary span, clears the render-node pool (this+0xEC..+0xF8), tokenizes the input text, builds a linked list of one render node per wrapped token, and computes per-line height into this+0x108. No-op on null input.
- `0x0048B600` **UIEventShortcutHandler** — Keyboard/event handler for a text edit field: gated by a master enable byte, walks event codes (backspace on 14, accept on 1/28), translates/filters characters, inserts at the cursor with a width/overflow re-check, refreshes rendered text, and activates the value via vtable dispatch.
- `0x0048C0E0` **UIWidget** — Determines a window control type (0, 1 or 2) stored at this+0x30C by sequentially comparing the path string at this+0xB8 (default byte_5EA438) against three reference strings via sub_588410; last write wins.
- `0x0048EBD0` **UIWidget** — Captures eight dimension values from child widgets via sub_487060 into this+0x110..+0x12C and eight via sub_4870E0 into this+0x130..+0x14C, applies fallback defaults for four negative dimensions, issues a virtual layout call (vtable slot 16 with this+0x104), resolves three delegated dimensions into this+0xE4..+0xEC, calls UIWindowTextSetup, and clears this+0x168.
- `0x0048F640` **UIViewportLayoutCalculator** — Computes a tile-grid layout for a viewport: reads viewport bounds, walks the child list seeded at this+0xF0 accumulating max tile width/height, computes columns/rows and a total/scroll value from layout mode this+0x100 (0 vertical, 1 horizontal), and on overflow resets this+0x104 via a vtable+0x40 virtual call. Always calls UITileGrid and returns the result of a vtable+0x2C call with argument 1.
- `0x0048F9F0` **UIWidget** — Configures a UI text-window object: copies the directory path (this+0xB8, default byte_5EA438), searches token word_5C32D8, loads two resource objects into this+0x154 and this+0x150, and classifies the layout mode written to this+0xE0 (0/1/2) by token comparison.
- `0x0048FC50` **UIObject** — UI control object constructor: calls the base struct initializer UIStructInit_e9e0, zeroes +0x30 and +0x38, stores a -1 sentinel at +0x34, and installs the vtable off_5A4450 at +0x0.
- `0x0048FD60` **UIObject** — UI structure constructor: delegates to the base initializer UIStructInit_e9e0, installs the vtable off_5AC69C at +0x0, and zero-initializes the field at +0x30. Returns the this pointer.
- `0x0048FE60` **UIComponent** — UI component initializer: calls base initializer ShortComputation_5e30, installs the vtable off_5AC6B0, and sets state fields this+0xE0 = 1 and this+0xE4 = 0.
- `0x0048FEE0` **UIRenderer** — Full UI render helper: resolves the render string (this+0xB0, default byte_5EA438), measures it, reads two dimension pairs, clamps the four in-out viewport pointers, and selects one of three draw paths by render-mode flag this+0xE4 (0 full, 1 top, 2 bottom). Returns 0 on every exit.
- `0x004901A0` **UIWidget** — Classifies a UI window by copying its name/path (this+0xB8, default byte_5EA438) into a local 63-byte buffer and comparing it against three tokens, storing a numeric window type 0/1/2 in this+0xE4; returns the outcome of the final comparison.
- `0x00492160` **Options_OSC_Reader** — Parses an options screen configuration (.OSC) file line by line; guarded by the options object pointer at this+0x1A4 (null logs the self-identifying invalid-options error and returns 0). Optionally builds the options screens path, then dispatches each token to handlers for Attributeset, Layer, Gizmo, Dopage, Loadingscreenp, Systemfont, Tooltipfont, tooltip colors, SetSymbol and DisableGizmo.
- `0x00494F10` **UIMessageDispatcher** — Dispatches a UI message via sub_53D2E0; when the a6 flag is set, first looks up the message in the binary string table byte_5EC4C0 via BinarySearchInStringTable, copies it into buffer byte_5EC4CC, and dispatches the buffered string instead.
- `0x004950C0` **UIIteratorLifecycle** — Conditional one-shot UI iterator cleanup: when the global iterator handle dword_7CDE10 is non-zero, passes it to UICleanupIterator and returns that result; otherwise returns the zero handle unchanged.
- `0x004957A0` **UIWidget** — UI click-event dispatch: iterates WORD event codes; event 1 resolves a handler string through this+0x18 -> this+0x68 -> +0x60, event 28 through the same chain to +0x58; a null handler string falls back to byte_5EA438, then sub_4988D0 dispatches the resolved string and the event is forwarded through vtable slot 8.
- `0x00495BD0` **UITextDialog** — Renders a multi-option text dialog: a measure pass and a render pass over four 12-byte entry slots starting at byte offset 5628 of this, drawing a background/shadow for the first entry, dispatching a UI message per entry, and blitting the composed region to the render surface. Returns the active-entry count.

## Proposed classes

### UIWidget

Core UI control object owning the string/path resources, the text/font resource child object, a linked list of named render/list nodes, a render-node pool, dimension and layout fields, and the click-event handler chain. Render dispatch, list selection, dimension capture, text-window setup and window classification all operate on this object. Grouping is GUESS: equal offsets on unrelated 'this' pointers are not proof of common ownership.

Methods: `0x00488F40`, `0x00489AB0`, `0x00489FD0`, `0x0048B030`, `0x0048C0E0`, `0x0048EBD0`, `0x0048F9F0`, `0x004901A0`, `0x004957A0`

- `this+0x00000000` `fnptr* vtablePtr` (read, DERIVED)
- `this+0x00000004` `float layoutDefault0` (read, GUESS)
- `this+0x00000008` `float layoutDefault1` (read, GUESS)
- `this+0x0000000C` `float layoutDefault2` (read, GUESS)
- `this+0x00000010` `float layoutDefault3` (read, GUESS)
- `this+0x00000018` `object* eventHandlerObject` (read, GUESS)
- `this+0x00000040` `char* stringBuffer` (read_write, DERIVED)
- `this+0x00000068` `object* handlerManager` (read, GUESS)
- `this+0x00000090` `listNode* listHead` (read, DERIVED)
- `this+0x00000094` `int itemCount` (read, DERIVED)
- `this+0x000000B8` `char* pathString` (read, DERIVED)
- `this+0x000000C8` `textResource* textResourcePtr` (read, DERIVED)
- `this+0x000000E0` `int layoutMode` (read_write, DERIVED)
- `this+0x000000E4` `int windowType` (read_write, DERIVED)
- `this+0x000000E8` `int delegatedDim1` (write, GUESS)
- `this+0x000000EC` `renderNode* renderPoolHead` (read_write, DERIVED)
- `this+0x000000F0` `renderNode* renderPoolTail` (read_write, DERIVED)
- `this+0x000000F4` `renderNode* renderPoolHeadCopy` (write, GUESS)
- `this+0x000000F8` `renderNode* renderNodeCursor` (read_write, DERIVED)
- `this+0x000000FC` `int renderElementCount` (read, DERIVED)
- `this+0x00000104` `int layoutStateFlag` (write, DERIVED)
- `this+0x00000108` `int lineHeightField` (write, DERIVED)
- `this+0x00000110` `float dimensionArrayA_0` (read_write, DERIVED)
- `this+0x00000114` `float dimensionArrayA_1` (read_write, DERIVED)
- `this+0x00000118` `float dimensionArrayA_2` (read_write, DERIVED)
- `this+0x0000011C` `float dimensionArrayA_3` (read_write, DERIVED)
- `this+0x00000120` `float dimensionArrayA_4` (read_write, DERIVED)
- `this+0x00000124` `float dimensionArrayA_5` (read_write, DERIVED)
- `this+0x00000128` `float dimensionArrayA_6` (read_write, DERIVED)
- `this+0x0000012C` `float dimensionArrayA_7` (read_write, DERIVED)
- `this+0x00000130` `float dimensionArrayB_0` (read_write, DERIVED)
- `this+0x00000131` `byte mirrorFlagByte` (read, DERIVED)
- `this+0x00000134` `float layoutPosX` (read, GUESS)
- `this+0x00000138` `float dimensionArrayB_4` (read_write, DERIVED)
- `this+0x0000013C` `float layoutOffsetY` (read, GUESS)
- `this+0x00000140` `float dimensionArrayB_5` (read_write, DERIVED)
- `this+0x00000144` `float dimensionArrayB_6` (read_write, DERIVED)
- `this+0x00000148` `float dimensionArrayB_7` (read_write, DERIVED)
- `this+0x0000014C` `int scrollOffset` (read_write, DERIVED)
- `this+0x00000150` `void* field0x150` (read_write, GUESS)
- `this+0x00000154` `void* field0x154` (read_write, GUESS)
- `this+0x00000158` `int rowCount` (read, DERIVED)
- `this+0x00000164` `int visibleCount` (read, DERIVED)
- `this+0x00000168` `int selectionIndex` (read_write, DERIVED)
- `this+0x0000016C` `int columnCount` (read, DERIVED)
- `this+0x00000174` `int resetCounter` (write, DERIVED)
- `this+0x0000030C` `int controlType` (read_write, DERIVED)
- `obj+0x00000018` `fnptr containerQuerySlot` (read, DERIVED)
- `obj+0x00000020` `fnptr eventForwardSlot` (read, DERIVED)
- `obj+0x000000A8` `fnptr displayStringsSlot` (read, DERIVED)
- `*(this+0x68)+0x00000058` `char* event28HandlerString` (read, DERIVED)
- `*(this+0x68)+0x00000060` `char* event1HandlerString` (read, DERIVED)
- `*(this+0xC8)+0x00000040` `char* fontPathString` (read, DERIVED)
- `*(this+0xC8)+0x00000048` `char* fallbackNameString` (read, DERIVED)
- `*(*(this+0x90)+0x8C)+0x00000000` `fnptr* vtablePtr` (read, DERIVED)
- `*(*(*(this+0x90)+0x8C)+0x0)+0x00000034` `fnptr renderVirtualSlot` (read, DERIVED)
- `*(*(this+0x90)+0x8C)+0x0000008C` `listNode* next` (read, DERIVED)
- `*(*(this+0x90)+0x8C)+0x000000A0` `char* nameString` (read, DERIVED)
- `*(*(this+0x90)+0x8C)+0x000000E4` `byte renderFlag` (read_write, DERIVED)
- `*(this+0xF0)+0x00000004` `renderNode* next` (read_write, DERIVED)

### UITextInputHandler

Text-input widget specialization that word-wraps incoming text into one UI menu item per line. Shares the widget layout field region (this+0x0C, +0x94, +0xC8, +0x140) with UIWidget at GUESS level.

Methods: `0x004896C0`

- `this+0x00000000` `fnptr* vtablePtr` (read, DERIVED)
- `this+0x0000000C` `float leftMargin` (read, DERIVED)
- `this+0x00000094` `int itemCount` (read_write, DERIVED)
- `this+0x000000C8` `textResource* textResourcePtr` (read, DERIVED)
- `this+0x00000108` `int unresolvedReadField` (read, GUESS)
- `this+0x00000140` `float rightMargin` (read, DERIVED)
- `*(this+0xC8)+0x00000040` `char* fontPathString` (read, DERIVED)
- `obj+0x00000018` `fnptr querySlot` (read, UNKNOWN)
- `obj+0x0000002C` `fnptr completionSlot` (read, UNKNOWN)

### UIEventShortcutHandler

Keyboard/event handler for a text edit field: maintains an edit buffer/cursor state, translates and filters key events, and activates the value via vtable dispatch. Field identities in the +0x2F0..+0x2FC range are DERIVED for this object.

Methods: `0x0048B600`

- `this+0x00000000` `fnptr* vtablePtr` (read, DERIVED)
- `this+0x00000040` `char* stringBuffer` (read, DERIVED)
- `this+0x000000A0` `char* lookupSourceString` (read, DERIVED)
- `this+0x000000C8` `textResource* fontResourcePtr` (read, DERIVED)
- `this+0x000000E5` `byte acceptModeByte` (read, DERIVED)
- `this+0x000002EC` `byte masterEnableByte` (read, DERIVED)
- `this+0x000002F0` `char* editBufferStart` (read, DERIVED)
- `this+0x000002F4` `char* editCursorPtr` (read_write, DERIVED)
- `this+0x000002F8` `int editLimit` (read, DERIVED)
- `this+0x000002FC` `object* renderSurface` (read, DERIVED)
- `*(this+0xC8)+0x00000040` `char* fontPathString` (read, DERIVED)
- `*(this+0x2F4)+0x00000000` `byte terminatorByte` (read_write, DERIVED)
- `*(this+0x2F4)+0x00000001` `byte followingByte` (write, DERIVED)
- `obj+0x0000002C` `fnptr updateMethodSlot` (read, DERIVED)
- `obj+0x000000B0` `fnptr enterActivationSlot` (read, DERIVED)

### UIViewportLayoutCalculator

Computes a tile-grid layout (columns, rows, total/scroll) from the maximum child dimensions and the viewport bounds. Layout mode this+0x100 selects vertical (0) or horizontal (1). On viewport overflow it resets state through a vtable slot and invokes UITileGrid.

Methods: `0x0048F640`

- `this+0x00000000` `fnptr* vtablePtr` (read, DERIVED)
- `this+0x000000F0` `tileChild* childListHead` (read, DERIVED)
- `this+0x000000F8` `tileChild* childCursor` (read_write, DERIVED)
- `this+0x000000FC` `int childElementCount` (read, DERIVED)
- `this+0x00000100` `int layoutMode` (read, DERIVED)
- `this+0x00000104` `int overflowStateFlag` (write, DERIVED)
- `this+0x00000120` `float viewportX0` (read, DERIVED)
- `this+0x00000124` `float viewportX1` (read, DERIVED)
- `this+0x00000140` `float viewportY0` (read, DERIVED)
- `this+0x00000144` `float viewportY1` (read, DERIVED)
- `this+0x00000150` `int spacingX` (read, DERIVED)
- `this+0x00000154` `int spacingY` (read, DERIVED)
- `this+0x00000158` `int columnCount` (read_write, DERIVED)
- `this+0x0000015C` `int rowCount` (read_write, DERIVED)
- `this+0x00000160` `int maxTileWidth` (read_write, DERIVED)
- `this+0x00000164` `int maxTileHeight` (read_write, DERIVED)
- `this+0x0000016C` `int totalScroll` (read_write, DERIVED)
- `*(this+0xF0)+0x0000000C` `int width` (read, DERIVED)
- `*(this+0xF0)+0x00000010` `int height` (read, DERIVED)
- `obj+0x0000002C` `fnptr returnMethodSlot` (read, DERIVED)
- `obj+0x00000040` `fnptr resetMethodSlot` (read, DERIVED)

### UIRenderer

Text region renderer that measures a render string, clamps in-out viewport pointers, and draws the region in one of three modes selected by this+0xE4 (0 full, 1 top, 2 bottom). Owner identity is GUESS.

Methods: `0x0048FEE0`

- `this+0x000000B0` `char* renderString` (read, DERIVED)
- `this+0x000000E4` `int renderMode` (read, DERIVED)

### Options_OSC_Reader

Line-oriented parser for options screen (.OSC) configuration files. Guarded by the options object pointer at this+0x1A4; dispatches recognized tokens (Attributeset, Layer, Gizmo, Dopage, Loadingscreenp, Systemfont, Tooltipfont, tooltip colors, SetSymbol, DisableGizmo) to dedicated handlers. The tooltip font buffer and tooltip color offsets inside the options object (+5432, +180, +184) are described in prose only and have no allowed field evidence in this packet.

Methods: `0x00492160`

- `this+0x0000019A` `byte buildResourcePathFlag` (read, DERIVED)
- `this+0x000001A4` `object* optionsObjectPtr` (read, DERIVED)

### UIMessageDispatcher

Global UI message dispatch helper. With the a6 lookup flag set it performs a binary search of the message against the global binary string table byte_5EC4C0 and dispatches the buffered result from byte_5EC4CC. Operates on globals, not on a 'this' object.

Methods: `0x00494F10`


### UIIteratorLifecycle

Conditional one-shot cleanup of the global UI iterator handle dword_7CDE10 through UICleanupIterator. Owner class identity is GUESS; the function may be a free helper rather than a method.

Methods: `0x004950C0`


### UITextDialog

Multi-option text dialog renderer: two passes (measure and render) over four 12-byte entry slots starting at byte offset 5628 of this, per-entry UI message dispatch, and a final blit of the composed region. The entry-slot region has no allowed field evidence in this packet.

Methods: `0x00495BD0`


### UIObject

Base UI object construction. Two constructors share the base initializer UIStructInit_e9e0 and a zeroed +0x30 field but install distinct vtables (off_5A4450 vs off_5AC69C), so they likely construct different derived UI object types; the shared-class relationship is GUESS.

Methods: `0x0048FC50`, `0x0048FD60`

- `this+0x00000000` `fnptr* vtablePtr` (write, DERIVED)
- `this+0x00000030` `int stateField0` (write, DERIVED)
- `this+0x00000034` `int sentinelIndex` (write, DERIVED)
- `this+0x00000038` `int stateField1` (write, DERIVED)

### UIComponent

UI component initializer using the base routine ShortComputation_5e30 and vtable off_5AC6B0; sets the +0xE0 and +0xE4 state fields. These equal offsets on a different base than UIWidget/UIEventShortcutHandler are not proven common fields.

Methods: `0x0048FE60`

- `this+0x00000000` `fnptr* vtablePtr` (write, DERIVED)
- `this+0x000000E0` `int stateFieldE0` (write, DERIVED)
- `this+0x000000E4` `int stateFieldE4` (write, DERIVED)

## Compatibility contracts

- **DefaultStringFallback** — A null string pointer at many widget fields (this+0x40, +0xB0, +0xB8, child +0x40/+0x48, list node +0xA0, edit lookup source) is substituted with the global default string byte_5EA438 before copy/render/dispatch. A replacement executable must reproduce this null-to-default substitution in the same paths or dependent layout/rendering changes.
- **EventCodeSemantics** — UI event codes are WORD codes with fixed meanings at these call sites: 14 = backspace, 1 and 28 = accept/enter, all others = character input. Handlers dispatch handler strings (event 1 -> handler+0x60, event 28 -> handler+0x58) and forward through vtable slots. A replacement must keep these event-code meanings for the text edit and click dispatch paths.
- **WindowTypeClassification** — Window and window-control types 0/1/2 are selected by comparing the widget path (this+0xB8) against three reference strings (byte_5CC21C, aC_0, aR) with sub_588410; comparisons run sequentially and the last match wins. Results are stored at this+0x30C (control) and this+0xE4 (window). A replacement must preserve the three-way classification and its storage offsets for matching layout behavior.
- **TextRegionRenderModes** — The render-mode flag at this+0xE4 selects the drawn text region: 0 draws the full measured region (BitmapDraw_81f0), 1 draws the top, 2 draws the bottom, and any other value returns 0 without drawing. Viewport pointers a2/a3/a4/a5 are clamped with mode-dependent min/max. A replacement must reproduce the three modes and the empty-string early return.
- **OSCConfigTokenFormat** — The options screen reader parses lines and dispatches the tokens Attributeset, Layer, Gizmo, Dopage, Loadingscreenp, Systemfont, Tooltipfont, tooltip colors (aTooltipColorFi/aTooltipColorEd), SetSymbol and DisableGizmo to specific handlers. A replacement must recognize this token set for .OSC files to load options screens equivalently.
- **StringTableMessageLookup** — UIMessageDispatch with the a6 flag set performs a binary search of the message in the binary string table byte_5EC4C0 via BinarySearchInStringTable, remaps the message through the byte_5EC4CC buffer, and dispatches the buffered string. A replacement must preserve the lookup-on-flag behavior so message identity survives the translation path.

## Unresolved

- Exact content and purpose of the default string byte_5EA438 are not established beyond its role as a null-string fallback.
- Semantics of sub_498560 (prefix/resource string processing) and sub_4988D0 (handler dispatch) are not derivable from this packet.
- UIWidget is a GUESS grouping: several functions with UNKNOWN owners share field offsets (e.g. +0x40, +0xC8, +0xE4, +0x168) but equal offsets on unrelated 'this' pointers are not proof of identical classes.
- this+0x150 and this+0x154 are interpreted as spacing terms by UIViewportLayoutCalculator but as resource-object slots by SetupTextWindowConfig; the conflicting interpretation is unresolved.
- this+0x158/+0x16C read as row/column counts by UICustomRenderDispatch overlap in offset with the calculator's columnCount/totalScroll; whether they are the same fields is unproven.
- The list node layout (next +0x8C, strings +0xA0/+0xA8/+0xB0/+0xB8, flag +0xE4, vtable +0x0) is DERIVED only from this packet's raw source; no independent node-struct evidence exists.
- The render-node pool fields (+0xEC..+0xF8) and the child-list walk in UIViewportLayoutCalculator (+0xF0/+0xF8/+0xFC) use overlapping offsets with different per-field meanings; the two node families were kept as separate classes.
- sub_588410's return convention (whether a zero means equal) is not established here and must be corroborated at 0x00588410.
- Exact meaning of window/control types 0, 1 and 2 and their downstream effect is not defined by this packet.
- The aR and aC_0 token labels are not accompanied by literal string contents in this packet.
- The -1 sentinel at +0x34 and the zeroed fields at +0x30/+0x38 in UIObject constructors have undocumented roles.
- UIObject and UIComponent install distinct vtables and base initializers; their relationship (base/derived or unrelated) is GUESS.
- sub_487060 and sub_4870E0 (two dimension accessor families) differ only by index/result here; their semantic distinction is unknown.
- The virtual calls through vtable slots 8/24/44/0x2C/0x40/0xA8/0xB0 resolve to runtime-dispatched targets outside this packet.
- The hard-coded 5772-byte offset into *(this+0x40) used by StringReverseCopyLookup in UIEventShortcutHandler has unknown meaning.
- The tooltip font buffer and tooltip color offsets inside the options object at this+0x1A4 (+5432, +180, +184) have no allowed field evidence in this packet.
- Exact meaning of the integer argument (1) to the vtable+44 completion dispatch in UITextInputHandler is unconfirmed.
- Whether sub_489D00 merely resets state or also releases resources is unconfirmed.
- The global UI iterator handle dword_7CDE10 and UICleanupIterator's return meaning (success flag vs status) are not established.
- byte_5EC4CC and the BinarySearchInStringTable fill contract are unknown; the buffer may be a localization/translation buffer.
- The meaning of event codes beyond 1, 14 and 28 is caller-side and not derivable here.
