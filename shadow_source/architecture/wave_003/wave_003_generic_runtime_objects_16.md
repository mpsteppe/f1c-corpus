# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for the generic_runtime_objects slice of Wave 3. The functions cluster into: a UI text element renderer (0x4982C0) that resolves strings through the shared string tables and dispatches via UIMessageDispatch; a render-state store reset (0x4986A0) and a viewport render config initializer (0x498740); the saving-replay overlay renderer (0x4989E0); a UI render-dispatch object (0x4993D0) that clears the surface, draws a clamped rect list through F_10ParamForwarder and dispatches children through their vtable slot 0x44; generic lifecycle helpers (object reset 0x499AF0, recursive tree-node destructor 0x499DA0, rectangle-region forwarder 0x49AA90, linked-list teardown 0x49AF30); a scissored 2D text widget (0x49B370); an engine-wear driver notifier (0x49B9A0); a large family of string-table lookup-and-copy helpers keyed on the off_5CCBxx table pointers into the shared byte_5EC4C0/byte_5EC4CC buffers (0x49BB40, 0x49BCD0, 0x49BDE0, 0x49BF80, 0x49C140, 0x49C600, 0x49C700, 0x49C830, 0x49C8F0); session-time formatters (0x49BBB0, 0x49BD40); an options error reporter (0x4986D0); and a trivial field getter (0x49ADB0). Ownership is largely UNKNOWN at the function-IR level, so most classes are GUESS proposals; the string-table and time-formatter groupings are structural families of free functions sharing global state rather than confirmed object identities.

## Function roles

- `0x004982C0` **UiTextElementRenderer** — Renders a text UI element with an alpha flag. Returns -1 on a null element string, skips the body when this+0x1518 (5400) holds no text, resolves the string through the global string table (BinarySearchInStringTable over byte_5EC4C0 into the shared buffer byte_5EC4CC) when the alpha flag is set, measures it via ShortComputation_4f00 into a size out-parameter, computes a left-aligned or centered horizontal position within the caller band, and dispatches the element through UIMessageDispatch (0x00494F10) with a global value from GlobalAccessor_5150. Returns 0 on success.
- `0x004986A0` **RenderStateStore** — Resets render state on a __thiscall object: copies a default/empty value into the global string buffer byte_5EA438 via StringCopyWithBufferRealloc, clears the three integer state fields at this+0x1560, this+0x1564 and this+0x1568, and returns 0. Invoked during large-UI render preparation by UILargeRender.
- `0x004986D0` **FreeFunction** — Options error reporter (free __stdcall): when the error code a1 is non-zero, formats it bounded to 127 chars into a local buffer via sub_587DD0, NUL-terminates it, shows it in a MessageBoxA titled 'Options Error', then calls UtilityFunction_9ca4(1) and returns its result; returns a1 immediately when it is zero. Reached from error paths of the options/setup callers.
- `0x00498740` **ViewportRenderConfig** — Initializes viewport/render dimension fields on a __thiscall object: stores the screen-width, scroll-acceleration and constant globals into this+0x64/0x68/0x6C, stores a read-and-cleared contact flag (ContactFlagReadClear) into this+0x70, and computes integer width (this+0x5C) and height (this+0x60) from the font-scale globals times 400/300, returning the height. Shared by crash-damage processing and large-UI render paths.
- `0x004989E0` **SaveReplayUiRenderer** — Renders the 'saving replay' overlay when a non-empty message string is supplied. Static path: looks up the 'saving replay' entry via sub_497AD0, draws a panel sized from the found entry through F_10ParamForwarder (height literal 274), and centers/captions the message via sub_553070 when the 'ftim28blk' wide-string node exists. Animated path (no entry): a roughly 0.45 s QPC-timed loop draws a progress-scaled grayscale box through DelegationWrapper, then renders the message centered on a nominal 800x600 region. Yields between render steps via sub_495080.
- `0x004993D0` **UIRenderDispatchObject** — Render-dispatch method on a UI object: returns -1 when this+0x4C is null; builds the clip rectangle from this+0x4/this+0xC and the sub-struct at *(this+0x58), clears the surface via vtable slot 0x2C, draws each clamped sub-rectangle of the rect list via F_10ParamForwarder when it has positive size, then invokes each child's draw virtual (slot 0x44) on the child list at this+0x44. Returns 0.
- `0x00499AF0` **ResettableObject** — Object reset routine: when the sub-object pointer at this+0x50 is non-null, dispatches its vtable slot 0 with argument 1 (consistent with a virtual destructor), then unconditionally zeroes the whole 0x50-byte object via memset and returns 0. Called by sub_4963D0.
- `0x00499DA0` **TreeNode** — Recursive tree-node destructor: selects the node-pointer slot (caller-supplied a2, or this+0x8 by default), recursively destroys both child-node pointers at node offsets 0x28 and 0x24, runs ConditionalDualCleanup, frees the node via FreeWrapper_7bcf, clears the selected slot and this+0xC, and returns the free result.
- `0x0049AA90` **RectangleRegion** — Thiscall forwarder on a _WORD pointer: calls ShortComputation_16e0 with a destination advanced 18 word elements from 'this', passing a4, a2 and the differences (a5-a4), (a3-a2), returning the __int16 result unchanged. The argument pairing is consistent with a rectangle-region definition (legacy ABI name Rectangle_Region_Constructor); that interpretation is DERIVED.
- `0x0049ADB0` **FreeFunction** — Trivial getter: reads the dword field at this+0xC and returns it with no side effects; used as a small accessor by thirteen callers across settings-copy, UI-scroll, media/audio and object-lookup paths.
- `0x0049AF30` **LinkedList** — Linked-list teardown: walks the singly linked list rooted at *this, freeing each node via FreeWrapper_7bcf and also freeing the node payload when the owns-flag byte at node+8 is set, then zeroes the four list fields at this+0x0..this+0xC. Structural twin of LinkedListDestructor_1db0.
- `0x0049B370` **TextWidgetRenderer** — 2D text rendering bounded by a scissor rectangle: measures the string via sub_5531F0, scales it by the layout divisors at a4+92 and a4+96, renders only when both scaled sizes are positive, emits the text via sub_553070 with the render-device global dword_8B8DC8, draws an optional background widget gated on dword_7CE23C[0] and a time-varied highlight gated on a6 and dword_7CE240, then advances the caller width cursor *a3 by the scaled height plus 8 and returns it. Invoked by the UI render driver sub_49F870.
- `0x0049B9A0` **FreeFunction** — First-time engine-wear notification for the vehicle matching the current player: compares the player vehicle's per-driver value at offset 18580 with the current vehicle's value, and when they match, the wear parameter exceeds the threshold (dbl_7C9174 greater than dbl_7C9204) and wear mode is active, notifies the driver once via sub_41B190 and stores/returns the per-driver present flag (byte_5EC354).
- `0x0049BB40` **StringTableLookup** — String-table lookup and bounded copy (primary, table pointer off_5CCBC4): binary-searches the table (BinarySearchInStringTable) and on a match copies the matched string into the global message buffer byte_5EC4CC (NUL-terminated when the source pointer is null), then copies up to a2-1 bytes into the caller buffer a1 via sub_587DD0 with a NUL at a1[a2-1], returning 0.
- `0x0049BBB0` **SessionTimeFormatter** — Formats elapsed session time as ' MM:SS.FFF' into the output buffer, or writes the default asc_5CCE18 when the preconditions fail. Time = dbl_8AFEA0 minus the base field at dword_7C54E0+16536; two guarded formatting paths share the SpatialGridCell minute/second derivation and the StringFormatWithBufferOverflowCheck formatter.
- `0x0049BCD0` **StringTableLookup** — Secondary string-table lookup variant (table pointer off_5CCBCC): same shape as the primary lookup, binary-searching the secondary table into the shared message buffer byte_5EC4CC and copying up to a2-1 bytes into the caller buffer a1, returning 0.
- `0x0049BD40` **SessionTimeFormatter** — Indexed time formatting: writes the default asc_5CCE18 first, then selects a time source (float-table entry at 4656*index when byte_7CFFF0 bit 0 is set, with the index from sub_4D1B50; otherwise the field at dword_7C54E0+16552) and, when positive, formats it as ' MM:SS.FFF' into the retained destination. Returns 0.
- `0x0049BDE0` **StringTableLookup** — String-table lookup and copy (table pointer off_5CCBE4): binary-searches, copies the matched string into byte_5EC4CC, copies up to a2-1 chars into the caller buffer a1 via sub_587DD0 with NUL termination. Called by UtilityFunction_d8b0 and MultiColorTextRender.
- `0x0049BF80` **StringTableLookup** — Secondary string-table lookup and copy (table pointer off_5CCBCC), structural twin of the secondary lookup at 0x0049BCD0; called by UtilityFunction_d8b0.
- `0x0049C140` **StringTableLookup** — Circular table string selection: reads the selector field at dword_7C54E0+0x4040, increments and wraps it so the dispatch index cycles 0,1,2, selects one of three string tables (off_5CCBF0, off_5CCBE8, off_5CCBEC), performs the shared binary-search-into-byte_5EC4CC step, then copies up to a2-1 bytes into the output buffer a1 and NUL-terminates. Returns 0.
- `0x0049C600` **StringTableLookup** — Season-name string-table lookup (table pointer off_5CCBD0, legacy ABI name Season_Name_Lookup): same lookup-copy shape as the family; called by the UI debug overlay renderer.
- `0x0049C700` **StringTableLookup** — String-table lookup and copy (table pointer off_5CCBD8): same lookup-copy shape as the family; called by sub_49DE40, MultiLayerTextRendering, MultiColorTextRender and the UI debug overlay renderer.
- `0x0049C830` **StringTableLookup** — Event/round name string-table lookup (table pointer off_5CCBDC): same lookup-copy shape as the family; called by sub_49DE40 in session context.
- `0x0049C8F0` **StringTableLookup** — String-table lookup and copy (table pointer off_5CCBF8): same lookup-copy shape as the family; called by three text-rendering paths (TimestampedRenderStringUpdate, TextRenderWithShadow, MultiLayerTextRendering).

## Proposed classes

### UIRenderDispatchObject

UI render dispatch object. Owns a render-state pointer (this+0x4C), clip-base offsets (this+0x4, this+0xC), a clip-bounds pair (this+0x54, this+0x5C), an offset sub-struct (this+0x50), a size sub-struct (this+0x58), and a child list (this+0x44). Its draw method clears the surface through vtable slot 0x2C, draws a clamped rect list via F_10ParamForwarder, and dispatches each child's draw virtual (slot 0x44).

Methods: `0x004993D0`

- `this+0x00000000` `pointer vtable` (read, GUESS)
- `this+0x00000004` `int clip_base_y` (read, GUESS)
- `this+0x0000000C` `int clip_base_x` (read, GUESS)
- `this+0x00000044` `pointer child_list_head` (read, DERIVED)
- `this+0x0000004C` `pointer render_state_ptr` (read, DERIVED)
- `this+0x00000050` `pointer offset_sub_struct` (read, GUESS)
- `this+0x00000054` `short clip_bounds_0` (read, GUESS)
- `this+0x00000058` `pointer size_sub_struct` (read, GUESS)
- `this+0x0000005C` `short clip_bounds_1` (read, GUESS)
- `*(this+0x58)+0x0000001C` `short size_width` (read, GUESS)
- `*(this+0x58)+0x00000020` `short size_height` (read, GUESS)
- `*(this+0x44)+0x00000044` `pointer child_draw_vtable_slot` (read, GUESS)
- `obj+0x0000002C` `pointer surface_clear_vtable_slot` (read, GUESS)

### SaveReplayUiRenderer

Renders the 'saving replay' overlay. Selects a static panel path (entry looked up via sub_497AD0, panel drawn through F_10ParamForwarder, caption via sub_553070) or a roughly 0.45 s QPC-timed animated path that draws a progress-scaled box through DelegationWrapper, then centers the message on an 800x600 region. The object field offset +0x1538 used for the wide-string node is not representable with packet field refs.

Methods: `0x004989E0`


### RenderStateStore

Render state object with three integer state fields at this+0x1560, this+0x1564 and this+0x1568 that are cleared on reset. Its reset also refreshes the global string buffer byte_5EA438. Called as part of large-UI render preparation.

Methods: `0x004986A0`

- `this+0x00001560` `int render_state_field_0` (write, DERIVED)
- `this+0x00001564` `int render_state_field_1` (write, DERIVED)
- `this+0x00001568` `int render_state_field_2` (write, DERIVED)

### ViewportRenderConfig

Viewport/render dimension configuration object. Receives the screen-width, scroll-acceleration and constant globals, a read-and-cleared contact flag, and computed integer width/height derived from the font-scale globals. Field semantics (viewport, scroll, contact flag) are proposed from the legacy ABI naming, not confirmed.

Methods: `0x00498740`

- `this+0x0000005C` `int viewport_width` (write, GUESS)
- `this+0x00000060` `int viewport_height` (write, GUESS)
- `this+0x00000064` `int screen_width` (write, GUESS)
- `this+0x00000068` `int scroll_acceleration` (write, GUESS)
- `this+0x0000006C` `int screen_constant` (write, GUESS)
- `this+0x00000070` `int contact_flag` (write, GUESS)

### UiTextElementRenderer

Renders a text UI element with an alpha flag. Resolves the element string through the global string table when the flag is set, measures it, computes a horizontal position within the caller band, and dispatches the element via UIMessageDispatch. The embedded UI message object at this+0x1518 (5400) is used for layout and dispatch.

Methods: `0x004982C0`


### ResettableObject

Generic 0x50-byte resettable object. Holds a sub-object pointer at this+0x50 that is torn down through its vtable slot 0 when non-null; the whole object is then zeroed via memset.

Methods: `0x00499AF0`

- `this+0x00000050` `pointer sub_object` (read, DERIVED)
- `*(this+0x50)+0x00000000` `pointer sub_object_vtable` (read, GUESS)

### TreeNode

Tree node container with a default node-pointer slot at this+0x8 and a dword at this+0xC cleared on destruction. Its recursive destructor frees both child nodes (offsets 0x28 and 0x24), runs a dual cleanup, and frees the node block.

Methods: `0x00499DA0`

- `this+0x00000008` `pointer node_slot` (read_write, DERIVED)
- `this+0x0000000C` `int cleared_dword` (write, GUESS)

### RectangleRegion

Word-based rectangle-region object. Its forwarder delegates to ShortComputation_16e0 with a destination advanced 18 word elements from 'this' and two coordinate pairs reduced to differences. The rectangle-region interpretation is DERIVED from the legacy ABI name only.

Methods: `0x0049AA90`


### LinkedList

Singly linked list control block with four dwords at this+0x0..this+0xC (head and three bookkeeping fields). Its teardown walks the list freeing each node (and the payload when the node owns-flag byte at +8 is set) via FreeWrapper_7bcf, then zeroes the control block.

Methods: `0x0049AF30`

- `this+0x00000000` `pointer head` (read_write, DERIVED)
- `this+0x00000004` `pointer tail` (write, GUESS)
- `this+0x00000008` `pointer aux` (write, GUESS)
- `this+0x0000000C` `int count` (write, GUESS)

### LinkedListNode

12-byte singly linked-list node: payload pointer at +0x0, next pointer at +0x4, owns-payload flag byte at +8. Node layout is caller/allocator-side and shared with the structural twin LinkedListDestructor_1db0.

Methods: 

- `obj+0x00000000` `pointer payload_ptr` (read, DERIVED)
- `*(obj+0x4)+0x00000004` `pointer next_ptr` (read, DERIVED)
- `obj+0x00000008` `byte owns_payload_flag` (read, DERIVED)

### TextWidgetRenderer

Scissor-bounded 2D text widget renderer. Uses anchor centers at this+0x8 and this+0xC, a caller layout descriptor (fields at +72, +92, +96) and the render-device global dword_8B8DC8; draws optional background and time-varied highlight widgets gated on global UI flags.

Methods: `0x0049B370`

- `this+0x00000008` `int anchor_x` (read, GUESS)
- `this+0x0000000C` `int anchor_y` (read, GUESS)

### StringTableLookup

Family of free functions performing keyed lookup in the global string tables and bounded copy into a caller buffer. They share the table root byte_5EC4C0, the shared message buffer byte_5EC4CC, the BinarySearchInStringTable callee (0x00423A00) and the bounded copy helper sub_587DD0; they differ only in the off_5CCBxx table pointer they consult. One member (0x0049C140) rotates the selected table with a circular index.

Methods: `0x0049BB40`, `0x0049BCD0`, `0x0049BDE0`, `0x0049BF80`, `0x0049C140`, `0x0049C600`, `0x0049C700`, `0x0049C830`, `0x0049C8F0`


### SessionTimeFormatter

Family of free functions formatting session time as ' MM:SS.FFF' with a default-string fallback. Shares the base session object pointer dword_7C54E0, the default asc_5CCE18, the SpatialGridCell minute/second derivation (0x0049B630) and the StringFormatWithBufferOverflowCheck formatter (0x0058815F).

Methods: `0x0049BBB0`, `0x0049BD40`


## Compatibility contracts

- **StringTableMessageBufferContract** — The global byte_5EC4CC is a shared message/result buffer: every string-table lookup helper binary-searches the table rooted at byte_5EC4C0, writes the matched string into byte_5EC4CC, then copies up to a2-1 bytes into the caller buffer and NUL-terminates at a1[a2-1]. A replacement must preserve this write-then-copy handoff semantics and the shared-buffer lifetime.
- **VehicleArrayAccessContract** — The engine-wear notifier reads the vehicle array at base 0x5EC6D8 with stride 0x48C0 (18624), indexes it via the current-player slot and the VehiclePtrArray slot pointers (0x7C54DC/0x7C54F0), and keys a per-driver present flag (byte_5EC354) on the value at vehicle offset 18580. A replacement must keep these offsets, stride and indexing semantics compatible.
- **RenderDispatchVtableContract** — The render-dispatch object clears the surface through vtable slot 0x2C and dispatches each child through its vtable slot 0x44; the object also dereferences sub-structs at this+0x50 and this+0x58 (offsets 0x1C/0x20). A replacement must preserve these vtable slot and sub-struct offset semantics.
- **UiTextRenderGateContract** — 2D text rendering uses the render-device global dword_8B8DC8 and gates the background widget on dword_7CE23C[0] and the highlight widget on dword_7CE240 plus an argument flag. A replacement must preserve these global UI flag gates and the render-device global.
- **OptionsErrorReportingContract** — Configuration errors are reported by formatting the error code bounded to 127 chars, showing a MessageBoxA captioned 'Options Error' (import thunk global 0x0059E2A4, caption global 0x005CCAE4), then running a cleanup call (0x00589CA4). A replacement must preserve this reporting flow.

## Unresolved

- The owners of most functions are UNKNOWN at the function-IR level; the class grouping above is a GUESS/DERIVED proposal, not a confirmed identity.
- StringTableLookup and SessionTimeFormatter are free-function families sharing global state, not proven to share an owning object; the class grouping is structural.
- The string-table roles of byte_5EC4C0 (search root/key) and byte_5EC4CC (shared message buffer) and the argument ordering of BinarySearchInStringTable are DERIVED from the call pattern, not proven.
- sub_587DD0 semantics (plain copy versus concatenation, length handling) live in the callee and are not confirmed by this packet.
- The dword_7C54E0 session base object fields (offsets 16536, 16444, 16532, 16484, 16552 and the selector at +0x4040) have unresolved meanings.
- The compared value at vehicle offset 18580 (driver id versus team id) in the engine-wear notifier is not established.
- The purpose of argument a2 in both session-time formatters is unknown.
- The exact roles of the cleared fields at 0x1560/0x1564/0x1568 in the render-state object and the written viewport fields at 0x5C..0x70 are DERIVED prose, not packet-confirmed.
- ResettableObject's dispatch of vtable slot 0 with argument 1 as a virtual destructor is inferred, not proven.
- TreeNode child-node offsets 0x28 and 0x24 (left/right sibling versus parent/child) are not established.
- RectangleRegion interpretation is DERIVED from the legacy ABI name only; ShortComputation_16e0 semantics and the meaning of the +18 word-element offset are unknown.
- Field0xCGetter's semantic role (index, handle or count) is not established by the packet.
- SaveReplayUiRenderer: the a2 parameter is never referenced; the 'ftim28blk' token meaning and the 274/281 screen-space literals are not further evidenced.
- UiTextElementRenderer: the a5 parameter is unused and the expression v11 = a6 - (int)a2 obscures the intended dispatch argument semantics through decompiler pointer arithmetic.
- ErrorCodeToMessageBox: the semantics and side effects of UtilityFunction_9ca4 are unknown.
- LinkedListFree: FreeWrapper_7bcf (0x00587BCF) identity as free() versus an internal heap wrapper is unresolved.
- TextWidgetRenderer: the two FloatToIntConversionChain constants (-2002081110 and -1999844148) and the layout descriptor a4 fields at +72/+92/+96 have unknown meanings.
- The screen-space meaning of the FixedRenderRect width/height literals and the interpretation of the flag byte_7CFFF0 bit 0 in the indexed time formatter are unresolved.
- Fifteen globals flagged by packet facts appear nowhere in the raw decompiled source and are recorded in unresolved_evidence_refs (0x59E420, 0x59E43C, 0x59E440, 0x59E4DC, 0x59E8FC, 0x59E9B0, 0x59EE8C, 0x59FEC8, 0x5AC9D8, 0x5AC9E0, 0x5CCE24, 0x5EB978, 0x7CDE00, 0x8ACEE0, 0x8AFE64).
- The relationship between the primary (off_5CCBC4) and secondary (off_5CCBCC) string-table lookup variants is not established; they differ only in the table pointer global.
- The exact layout of the sub-struct at *(this+0x58) (offsets 0x1C/0x20) and of the clip-bounds fields this+0x54/0x5C in the render-dispatch object is inferred from the rect clamp usage, not independently evidenced.
- The F_10ParamForwarder parameter meaning is derived from the two trailing zero arguments and the rect values, not from a prototype.
