# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposed reconstruction of generic runtime objects in the 0x0055A060..0x0055D900 band. The strongest clusters are: (a) a scene-file parser family sharing a line/token stream (LineReaderFromBuffer 0x00559A70, token query 0x00559E20, float/color readers 0x00559FB0/0x00559F00), with ParseViewElement (DERIVED owner SceneViewParser) plus two GUESS-members (ParseLightSceneProperties, SceneInstanceLinkParser); (b) a vtable-backed render-property object (RenderStateObject) whose six methods (0x0055C070, 0x0055C860, 0x0055C9B0, 0x0055CA40, 0x0055CC20, 0x0055CF50) all drive a sub-device reached through this+0x1100 and share flags at 0x13C4/0x13CC/0x14F0/0x1550; (c) a display-mode node whose construction/cleanup pair (0x0055BB50/0x0055BB70) touches the 0x104..0x120 region and whose list head lives at 0x120, with the string-plus-fields reader 0x0055BE20 reading the same 0x110/0x114 fields; (d) a DirectX display-device wrapper (0x0055C330) querying a device pointer at this+0x10FC via vtable+0x20; (e) a vertex-color fill node (0x0055D900) with source stride 48 / destination stride 64 and a color dword at +24. Six functions remain owner UnknownObject (0x0055BBF0, 0x0055BFC0, 0x0055C040, 0x0055C060, 0x0055D2F0, 0x0055D590). Contradictions preserved: the RenderStateObject vtable slots are only identifiable by dispatch offset (the sub-device class is unnamed); DisplayModeNode's ownership is inferred from overlapping field ranges on the same base 'this'; ParseLightSceneProperties and SceneInstanceLinkParser carry UNKNOWN packet owners and are grouped only by shared token-stream callees. All claims are DERIVED/GUESS; no function in the packet carried a CONFIRMED or FACT owner.

## Function roles

- `0x0055A060` **SceneViewParser** — Parse a 'View' element from a scene-file token stream: read view/recursion, color, clipplanes, orient, dir, size, center, clear, bgmap and separatesurfac attributes; configure a view object (angles in radians, projection, clip planes, packed color, orientation matrix or negated-direction translation) and tail-insert it into the owning scene list; return 0 on success, -1 on parse/allocation failure.
- `0x0055A500` **SceneFileParser** — Scene-file light parser: read Type, View, Dir, Color, Range, Intensity and Active tokens from a line buffer; map Type to a light kind code (Directional=1, StaticOmni=4, MovingOmni=2); create a scene node via sub_545430; apply directional or omnidirectional setters; publish color/intensity to UI property slots and toggle the active flag. Return 0 on success, -1 on node-creation failure.
- `0x0055A790` **SceneFileParser** — Parse one Instance block from a scene-file line buffer: allocate and initialize a 264-byte node, store the owning scene pointer at node+0x0, read Type/Instance/Light/Link/Adjacent tokens, select a storage flag (64 storage / 128 instance), copy the instance name, append the node to the scene master list and return 0.
- `0x0055BB50` **DisplayModeNode** — Zero-initialize a display-mode node struct (GlobalZeroInit_c2a0) then write the same caller value a2 into fields at offsets 0x104 and 0x108; return the struct pointer. Invoked by sub_55BE80 during node construction.
- `0x0055BB70` **DisplayModeNode** — Partial zero-initializer: zero a dword at offset 0, a byte at offset 4, and six dwords at 0x10C..0x120; leave the intervening range untouched; return 0. Called by sub_55BE80 as part of a larger construction sequence.
- `0x0055BBA0` **DisplayModeNode** — Free a singly-linked list whose head is stored at this+0x120 (per-node next pointer at node+0x20), freeing each node via FreeWrapper_7bcf, then null the head; no-op when the head is null. Return 0.
- `0x0055BBF0` **UnknownObject** — Thin forwarding wrapper: invoke sub_53DB90 with (dword_8B78A0, this, 0) and return that callee's result. Invoked by sub_55BE80.
- `0x0055BE20` **DisplayModeNode** — String-plus-fields reader: when a2 is non-null copy the NUL-terminated string at this+4 into a2; when a3 is non-null write this+0x110 to *a3; when a4 is non-null write this+0x114 to *a4; return a4. Invoked by sub_55F0D0 on a display/audio config accessor path.
- `0x0055BFC0` **UnknownObject** — Trivial getter returning the dword at this+0x4; no guards, no calls, no global reads.
- `0x0055C040` **UnknownObject** — cdecl wrapper forwarding dword_8B78A0 and dword_8B8F0C to RendererResourceCleanup (0x0053EAD0) and returning its result; invoked by VidMan_Exit as part of renderer teardown.
- `0x0055C060` **UnknownObject** — Forwarding wrapper: compute the element this[*this + 2] (runtime-derived index), forward (dword_8B78A0, element, dword_8B8F28) to sub_555E50 and return its result; a2 is unused. Called from StateFlagComputation and VidMan_Enter as a call-through point.
- `0x0055C070` **RenderStateObject** — Bind render resource properties from descriptor a2: when the a2+36 flag bit 2 is clear create a vertex/index buffer via the render-device vtable +144 slot and store it in *this; when the a3 flag bit 0x10 is clear configure render properties (multi-field setter, sub_554790(256), +200 status), sync the resource reference at 0x13CC, walk the descriptor resource list allocating locked buffers and uploading via +340/+284; mark the descriptor processed. Return the last status.
- `0x0055C330` **DisplayDevice** — Query the current display mode from the DirectX device at this+0x10FC via vtable+0x20; store the result code at this+0x0; on failure log the error string and return -1; on success copy two mode fields to optional a2/a3 and, when a4 is provided, set the display mode via sub_55C450 (format 22 special-cased to 21). Invoked by VidMan_Enter.
- `0x0055C860` **RenderStateObject** — Allocate a 64-byte buffer via BufferLockAllocate(this, this+0x1140, 64, 0, 2), copy caller-supplied data, drive vtable property updates (slots 0x88/0xC8/0x118), conditionally set the 0x13C4 init flag to 1, apply via PropertyValueSetterWithRefreshOnChange, and call vtable slot 0x8C when the ready flag at 0x1550 is zero.
- `0x0055C9B0` **RenderStateObject** — Trivial getter returning the ready flag dword at this+0x1550; used by seven callers (ConditionalInit, ConditionalStateReset, sub_53EB70, sub_544740, sub_554F80, sub_5550E0, sub_560FE0) across the object lifecycle.
- `0x0055CA40` **RenderStateObject** — Action-enum dispatch through a virtual call: map a2 (1->256, 2->2, 4->3) to a render-device vtable +0x94 call with (this[0x1100], param, a3) and store the result at this[0]; any other a2 returns (a2-4) without a vtable call.
- `0x0055CC20` **RenderStateObject** — Apply camera/projection configuration read from source struct a2: preliminary sub_55CA90(this, *(a2+412), 0); pack a six-dword config array (a2+84/88/100/104 plus constants 0 and 1.0) into render-device vtable +0xA0; set mode flag 0x13A4 to 3 or 2 by the a2+128 bit and call vtable +0xC8(22, mode); clear bit 2 of 0x1174; when enable flag 0x13D4 is set chain buffer queries (vtable +0x98 ids 256/3/2), thunk processing (0x0050CBB0/0x0050CDF9), and apply via vtable +0x13C.
- `0x0055CF50` **RenderStateObject** — Iterative UI property update driven by control struct a3: one-time init through the render-device sub-object (slots +148/+200) guarded by flags 0x13CC/0x14F0/0x13C4; rebuild the flag word 0x1170 (init 256, OR 0x800/0x400/1 from source flag bits); iterate source rows (cap 0x13B0) dispatching per-row params via the multi-field setter and applying via slots +340/+284; release via slot +200(28,0) when 0x14F0 is set. Single caller sub_558E70.
- `0x0055D2F0` **UnknownObject** — Set or clear bit 7 (0x80) of the flag word at this+0x0 from boolean a2, then call DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, this+0x4, 1); return that call's result. Invoked by sub_4FCEE0 and ParseLightSceneProperties.
- `0x0055D590` **UnknownObject** — Getter reading three consecutive dword fields at this+0x44, this+0x48 and this+0x4C into the corresponding non-null output pointers a2/a3/a4; return a4. Invoked by sub_560C10 and sub_560FE0, consistent with a vector-component accessor.
- `0x0055D900` **VertexFillNode** — Two-path vertex color fill: when bit 0x20 at byte (this+0x4)+156 is set, copy the color dword at +24 per vertex from the source array (this+0xC, stride 48) into the destination array (this+0x20, stride 64); otherwise compute RGBA via D3D-device vtable slots +24/+20 (globals dword_8B8F24/0x8B8F28), scale alpha by 255.0, pack via MMX against qword_8B6C20 and write the single packed color to every destination vertex.

## Proposed classes

### SceneViewParser

Parses a 'View' element from a scene-file token stream and constructs a view object (angles, projection, clip planes, packed color, orientation matrix or direction translation) tail-inserted into the owning scene list. Owner DERIVED from the packet's only named owner.

Methods: `0x0055A060`


### SceneFileParser

Scene-file line parser family sharing a line/token stream (LineReaderFromBuffer 0x00559A70, token query 0x00559E20, float/color readers 0x00559FB0/0x00559F00). Member 0x0055A500 parses light blocks into scene nodes; member 0x0055A790 parses Instance blocks into 264-byte nodes appended to the scene master list. Both carry UNKNOWN packet owners and are grouped by the shared token-stream callees only.

Methods: `0x0055A500`, `0x0055A790`


### DisplayModeNode

Display-mode node construction/cleanup object: zero-init via GlobalZeroInit_c2a0 then a same-value pair at 0x104/0x108 (0x0055BB50), a partial zero-init of 0/4 and 0x10C..0x120 (0x0055BB70), a singly-linked-list teardown with head at 0x120 and per-node next at +0x20 (0x0055BBA0), and a string-plus-fields reader reading this+4, 0x110 and 0x114 (0x0055BE20). Ownership inferred from the overlapping 0x104..0x120 field range on the same base 'this' and the shared construction caller sub_55BE80.

Methods: `0x0055BB50`, `0x0055BB70`, `0x0055BBA0`, `0x0055BE20`

- `this+0x00000000` `u32 field_0` (write, GUESS)
- `this+0x00000004` `u8 field_4` (write, GUESS)
- `this+0x00000104` `s32 value_104` (write, GUESS)
- `this+0x00000108` `s32 value_108` (write, GUESS)
- `this+0x0000010C` `u32 field_10C` (write, GUESS)
- `this+0x00000110` `u32 field_110` (read_write, GUESS)
- `this+0x00000114` `u32 field_114` (read_write, GUESS)
- `this+0x00000118` `u32 field_118` (write, GUESS)
- `this+0x0000011C` `u32 field_11C` (write, GUESS)
- `this+0x00000120` `ptr node_list_head` (read_write, DERIVED)
- `this+0x00000140` `u32 field_140` (read, UNKNOWN)

### RenderStateObject

Vtable-backed render-property object: binds render resources from descriptors (0x0055C070), allocates update buffers and drives property updates (0x0055C860), dispatches action enums through the sub-device (0x0055CA40), applies camera/projection configuration (0x0055CC20), runs iterative per-row UI property updates (0x0055CF50) and exposes the ready flag at 0x1550 (0x0055C9B0). All six methods reach a sub-device through this+0x1100 and share state flags at 0x13A4/0x13B0/0x13B8/0x13C4/0x13CC/0x13D4/0x14F0/0x1550.

Methods: `0x0055C070`, `0x0055C860`, `0x0055C9B0`, `0x0055CA40`, `0x0055CC20`, `0x0055CF50`

- `this+0x00000000` `s32 result_status` (read_write, GUESS)
- `this+0x00001100` `ptr render_device_ptr` (read, DERIVED)
- `this+0x00001140` `ptr buffer_handle` (read, GUESS)
- `this+0x00001170` `u32 flag_word` (read_write, GUESS)
- `this+0x00001174` `u32 flag_bits` (read_write, GUESS)
- `this+0x000013A4` `s32 mode_flag` (read_write, GUESS)
- `this+0x000013B0` `s32 row_cap` (read, GUESS)
- `this+0x000013B8` `s32 status_value` (read, GUESS)
- `this+0x000013C4` `s32 init_flag` (read_write, GUESS)
- `this+0x000013CC` `ptr resource_reference` (read_write, GUESS)
- `this+0x000013D4` `s32 enable_flag` (read, GUESS)
- `this+0x000014F0` `s32 enable_flag_14F0` (read, GUESS)
- `this+0x00001550` `s32 ready_flag` (read, GUESS)

### RenderDeviceSubObject

Vtable-backed render device reached at RenderStateObject offset 0x1100; its first dword is a vtable pointer. Dispatch slots 0x90 (create vertex/index buffer), 0x94 (dispatch), 0x98 (query buffer), 0xA0 (set config), 0xC8 (set property), 0x11C (upload), 0x13C (apply), 0x154 (apply resource) sit on the object; slots 0x88/0x8C/0xC8/0x118 sit on its vtable table (base *(*(this+0x1100)+0x0)). No callee identities are resolved; slots are recorded by dispatch offset only.

Methods: 

- `*(this+0x1100)+0x00000000` `ptr vtable_ptr` (read, DERIVED)
- `*(this+0x1100)+0x00000090` `fnptr create_vertex_index_buffer_slot` (read, GUESS)
- `*(this+0x1100)+0x00000094` `fnptr dispatch_slot` (read, GUESS)
- `*(this+0x1100)+0x00000098` `fnptr query_buffer_slot` (read, GUESS)
- `*(this+0x1100)+0x000000A0` `fnptr set_config_slot` (read, GUESS)
- `*(this+0x1100)+0x000000C8` `fnptr set_property_slot` (read, GUESS)
- `*(this+0x1100)+0x0000011C` `fnptr upload_buffer_slot` (read, GUESS)
- `*(this+0x1100)+0x0000013C` `fnptr apply_slot` (read, GUESS)
- `*(this+0x1100)+0x00000154` `fnptr apply_resource_slot` (read, GUESS)
- `*(*(this+0x1100)+0x0)+0x00000088` `fnptr vtable_slot_88` (read, GUESS)
- `*(*(this+0x1100)+0x0)+0x0000008C` `fnptr vtable_slot_8C` (read, GUESS)
- `*(*(this+0x1100)+0x0)+0x000000C8` `fnptr vtable_slot_C8` (read, GUESS)
- `*(*(this+0x1100)+0x0)+0x00000118` `fnptr vtable_slot_118` (read, GUESS)

### DisplayDevice

DirectX display-device wrapper: queries the current display mode from a DirectX device pointer at this+0x10FC via its vtable slot +0x20, stores the result code at this+0x0, and optionally sets the display mode through sub_55C450 (format 22 special-cased to 21). Invoked by VidMan_Enter.

Methods: `0x0055C330`

- `this+0x00000000` `s32 result_code` (read_write, GUESS)
- `this+0x000010FC` `ptr directx_device_ptr` (read, DERIVED)
- `*(this+0x10FC)+0x00000020` `fnptr get_display_mode_slot` (read, GUESS)

### VertexFillNode

Vertex color fill node: a render-state pointer at +0x4 (flag byte at +0x4+156, offset 0xA0), vertex count at +0x8, source vertex array at +0xC (stride 48), destination vertex array at +0x20 (stride 64), color dword at vertex +24. Computed path uses D3D-device globals dword_8B8F24/0x8B8F28 and MMX packing against qword_8B6C20.

Methods: `0x0055D900`

- `this+0x00000004` `ptr render_state_ptr` (read, GUESS)
- `this+0x00000008` `s32 vertex_count` (read, GUESS)
- `this+0x0000000C` `ptr source_vertices_ptr` (read, GUESS)
- `this+0x00000020` `ptr destination_vertices_ptr` (read_write, GUESS)
- `this+0x00000054` `u32 field_54` (read, UNKNOWN)
- `this+0x000000A0` `u32 flag_A0` (read, UNKNOWN)

## Compatibility contracts

- **SceneFileTokenStreamProtocol** — The scene-file parser family consumes a line-oriented token stream: LineReaderFromBuffer (0x00559A70) returns status codes 1 (end), 2 (skip) and 3 (EOF) stored at the stream head; token query 0x00559E20 matches attribute-name strings against the stream; 0x00559FB0/0x00559F00 read float and packed-color attribute values seeded from per-token globals. A replacement parser must preserve the status-code semantics and the token-name globals (view, bgmap, separatesurfac, Type, Instance, Light, Link, Adjacent, Directional, StaticOmni, MovingOmni, Active, Range, Intensity, Color, Dir, clear, orient, size, center).
- **RenderDeviceDispatchSlotOffsets** — RenderStateObject carries a vtable-backed render device at this+0x1100 whose first dword is a vtable pointer. Call sites require object slots at offsets 0x90, 0x94, 0x98, 0xA0, 0xC8, 0x11C, 0x13C and 0x154, plus vtable-table slots at 0x88, 0x8C, 0xC8 and 0x118 (base *(*(this+0x1100)+0x0)). A replacement render device must keep these dispatch offsets and the caller-visible argument shapes (buffer creation, property set with (id, value), upload element counts).
- **DisplayModeQueryContract** — DirectX display-mode query: the device pointer lives at this+0x10FC and its vtable slot +0x20 returns a mode struct (two fields) plus a result code stored at this+0x0. A non-zero result triggers an error log of the string at global 0x005DBCAC and return -1. Setting the mode goes through sub_55C450 with the read format, substituting format 21 when the read format equals 22.
- **VertexFillLayout** — Vertex color fill: the source vertex array (this+0xC) has stride 48 and the destination vertex array (this+0x20) stride 64, both holding the color dword at vertex +24; the vertex count is at this+0x8. The computed path scales alpha at (this+0x4)+80 by 255.0 (constant 0x0059FEC8), queries D3D-device globals dword_8B8F24/0x8B8F28 and MMX-packs RGBA against qword_8B6C20.
- **DisplayModeNodeLayout** — The display-mode node struct is zero-initialized (GlobalZeroInit_c2a0) before a same-value pair is written to 0x104/0x108; a partial zero-init clears offsets 0, 4 and 0x10C..0x120; a string is stored at this+4 and read back with fields 0x110/0x114; a singly-linked list of nodes (per-node next at +0x20) is anchored at this+0x120 and freed by walking and nulling the head.
- **RenderStateFlagSemantics** — RenderStateObject state flags: 0x13C4 is a one-time init flag (set to 1 alongside render-device call (136, 1)); 0x14F0 is an enable/release flag (gates call (28, 1) on entry and (28, 0) on exit); 0x1550 is a ready flag read by seven callers and gating vtable slots 0x88/0x8C; 0x13CC is a resource reference synced against descriptor state and logged on change.

## Unresolved

- ParseViewElement (0x0055A060): packet globals dbl_59E420, flt_59E450 and flt_59E65C are not referenced by the raw body; the source uses the literals 0.01745433 and 1.0 instead.
- ParseViewElement (0x0055A060): the view object field layout is not exposed (the bgmap surface is allocated at +104 words on the parsed object, but no field: evidence ref exists for it); the nested-view recursion (self call) and the exact scene-list insertion semantics of LinkedListInsertTail vs DoublyLinkedListTailInsertion are caller-supplied.
- ParseLightSceneProperties (0x0055A500): token-name strings (aType, aDir, aColor, aRange, aIntensity, aActive, aTrue, aFalse, directional/staticomni/movingomni) come from the DERIVED analysis layer; token-type codes 2/3 at *v3 are inferred; sub_545430 return semantics and a2 (scene context) role are unestablished; which member the UI property setters and BitFlagSetterWithDXUpdate address (light object vs scene UI context) is unproven; the View/off_5DC230 set appears redundant with SetUIPropertyGroupWithChainUpdate.
- SceneInstanceLinkParser (0x0055A790): status-code semantics of LineReaderFromBuffer, the exact structure of the 264-byte node, the meaning of storage flags 64/128, and the behaviors of sub_5491D0 and sub_548E20 are unknown.
- DualFieldSetToSameValue (0x0055BB50): why both fields at 0x104/0x108 hold the same caller value is caller-dependent (sub_55BE80 stores an entry index); owner type unknown.
- PartialStructZeroInit (0x0055BB70): the object type and layout meaning of the zeroed fields are unknown; the returned 0 is likely ignored.
- LinkedListFreeWithTraversalAndNulling (0x0055BBA0): field this+0x140 is flagged as read in the facts but not referenced in the body; node layout beyond the next pointer at +0x20 is unknown.
- DisplayModeEnumeratorWrapper (0x0055BBF0): semantics of sub_53DB90 and its three arguments unknown; dword_8B78A0 is read as a plain integer global (object pointer vs handle unproven); why the caller needs the wrapper is unclear.
- StringAndTwoFieldReader (0x0055BE20): semantics of the dword fields 0x110/0x114 unknown; the concrete type of this (display mode vs audio config) is unproven; the a2 destination buffer size contract is unknown (unbounded copy).
- ReadDwordField4 (0x0055BFC0): object type and meaning of this+0x4 unknown; caller set spans unrelated subsystems.
- GlobalDispatch (0x0055C040): role/type of globals dword_8B78A0 and dword_8B8F0C; RendererResourceCleanup return semantics unproven.
- CallWrapper_c060 (0x0055C060): identity of sub_555E50 is absent from the packet; meaning of dword_8B78A0/dword_8B8F28; the this[*this+2] object layout is a runtime-derived index; parameter a2 is unused.
- RenderResourcePropertyBinder (0x0055C070): the render-device vtable slot interfaces are unresolved beyond dispatch offsets; the descriptor a2 layout (flag byte at +36, source pointer at +12, resource-list header at +24) is inferred; the v11/v15 index arithmetic (16-dword entry stride, v15-2 vs v15/3 counts) is only partially evident.
- DirectXDisplayModeGetCurrent (0x0055C330): v8 is read but never assigned (likely a decompiler artifact of the mode format field); the vtable+0x20 identity as GetDisplayMode and the roles of v7[0]/v7[1] as width/height come from analysis prose; the format-22-to-21 rule is not independently proven; owner type unknown.
- BufferAllocateUpdateProperties (0x0055C860): meaning of vtable slots 0x88/0x8C/0xC8/0x118; the 64-byte buffer slot layout is unverified; the two near-identical this+0x1550 checks may be a duplicated decompiler artifact.
- StructFieldGetter (0x0055C9B0): semantic meaning of the ready flag at this+0x1550 is unknown; no initializer/writer evidence in the packet.
- mapEnumToVTableCall (0x0055CA40): the semantic meaning of a2 values (1/2/4) and mapped parameters (256/2/3) is unknown without the vtable contract; this[0] role as status storage is inferred from the write only.
- ConfigUpdateFromSourceStruct (0x0055CC20): vtable entries identified by call-site offset only; meaning of the three thunk calls (0x0050CBB0 x2, 0x0050CDF9) and the buffer ids (256, 3, 2) not established.
- IterativePropertyUpdateWithFlags (0x0055CF50): the vtable-backed sub-object behind this+0x1100 is unnamed; a3 control-struct flag bits are caller-defined; destination rows at &this[17*v11 + 1118] (17-dword stride) are a UI element array whose element type is not visible.
- BitFlagSetterWithDXUpdate (0x0055D2F0): purpose of bit 7 and of the field at this+0x4; role of global dword_8B78A0 inferred from call order only.
- TripleFieldGetter_d590 (0x0055D590): whether the three fields are floats or integers is not provable from this packet; the counterpart store sub_55D460 is asserted only by existing analysis.
- VertexColorPackWithMMX (0x0055D900): fields this+0x54 and this+0xA0 are listed by static extraction but not accessed in the body; the two indirect D3D vtable calls (+24/+20) through dword_8B8F24 have no resolved callee; the direct-copy path meaning when bit 0x20 is set is not proven.
