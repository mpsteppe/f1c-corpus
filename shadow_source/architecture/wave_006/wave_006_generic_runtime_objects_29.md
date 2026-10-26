# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from 28 validated functions. A DERIVED AnimationRuntimeManager (0x00550310 timer advance, 0x005503A0 track interpolation update, 0x00556900 channel float feed) groups the three animation-node list walkers, all called from sub_557120, over the animation-block anchor at this+0x110 (channel list head this+0x138, container state at *(this+0x134)) and the interpolation node list at this+0x204. A DERIVED D3DResourceDirtyManager (0x00556CD0, 0x005570C0) pairs the scene-graph traversal with the recursive D3D dirty-mark recursion (0x00556CD0 calls itself and is called by 0x005570C0). A DERIVED HighResolutionTimerAccumulator (0x00556330) models the QPC/RDTSC tick accumulator. Two DERIVED node containers are kept separate: DoublyLinkedNodeContainer (0x005592B0, count at +0x144, head at +0x148) and ListNodeAllocator (0x0055BC00, head at +0x120, count at +0x11C, 36-byte nodes with four-key duplicate detection). A DERIVED LinkedDispatchContext (0x005596E0 + wrapper 0x00559A30) resolves a selector against a linked entry list; a DERIVED InputKeyEventDispatcher (0x0055C7F0 + 0x0055C7B0 + 0x0055C7D0) routes key events through sub_55C450; a DERIVED UIColorGroupState (0x0055D320 + 0x0055D560) shares the three-group colour layout; a DERIVED RGB16BitColorCodec (0x0055CEB0 + 0x0055CEE0) packs RGB565/555. A GUESS PixelBufferTransformKernel (0x00560547, 0x0056068E, 0x005607C1) covers the 16-bit pixel kernels sharing the dword_5DD8xx scratch globals and byte-LUT tables, possibly free functions rather than methods. A GUESS ModeStateMachineSetter (0x005542F0) writes three mode sub-fields and persists the last state. Seven functions lack owner-class evidence and stay unowned (0x0054FDF0, 0x005507D0, 0x00550810, 0x00551800, 0x005573F0, 0x00559350, 0x0055C440).

## Function roles

- `0x0054FDF0` **UnknownObject** — Trivial single-word setter: writes argument a2 into the field at this+0x54 and returns a2 unchanged. The meaning of the stored value is undocumented in this packet; callers DoublyLinkedListNodeInsert (0x00497510) and DirectXMeshVertexBufferParsingAndLoading (0x00547B40) do not establish its semantics.
- `0x00550310` **AnimationRuntimeManager** — Advances per-entry animation timers by a per-frame delta across an animation-node linked list anchored at this+0x110, with container and iteration state read from *(this+0x134). Per entry, a timer below its duration stays running (delta added to the accumulator at +0x1B0, completion flag bit 2 cleared in the +0x1C4 flag word); a timer at or past its duration keeps its value, sets the completion flag bit 2, and dispatches the interrupt callback (0x0058957A) with the timer value. Entry iteration is gated on the entry count (+0x164) and the per-entry threshold counter (+0x1A8); per-node processing is gated on bit 0x400 of the node control flags (+0x168).
- `0x005503A0` **AnimationRuntimeManager** — Advances animation-track interpolation values across the node list headed at this+0x204. Skips nodes lacking flag bit 0x80000 (node+20) or a zero track count (node+280); for each track walks the entry array (37-dword stride) and moves the current value toward its target according to a loop-mode switch (1 wrap, 2 clamp, 3 ping-pong, 4 one-shot) dispatched by the jump table at 0x005504BC. Case 4 (one-shot) calls FlagFieldBitManipulation(this, 0, 0, 1, 0) to clear a flag field on this (this+0x354) and resets the current value to -1. Returns 0.
- `0x005507D0` **UnknownObject** — Trivial no-argument forwarder: calls EmptyStub_b4a0() and returns void. The raw body contains no reference-count arithmetic, so the refcount-release reading implied by the canonical name and ABI lead is unproven. Called once from sub_550F70.
- `0x00550810` **UnknownObject** — Minimal __thiscall forwarding thunk: reads the pointer stored at this+0x4 and passes it to FreeWrapper_7bcf (0x00587BCF), returning the wrapper's int result unchanged. Callers ArrayOfStructDestructorWithCountdown (0x00550820) and sub_550F70 (0x00550F70) suggest a per-element cleanup path, but FreeWrapper's contract (null-check, refcount, or conditional free) is outside this packet, so the free reading is DERIVED from the wrapper name.
- `0x00551800` **UnknownObject** — Conditional delegation on pointer argument a1: when non-null, calls FlagUpdateWithCascade (0x005514A0) with a1 and returns its result; when null, skips the call and returns the uninitialized local result (eax), which is indeterminate. Called from sub_448140.
- `0x005542F0` **ModeStateMachineSetter** — Secondary state-machine transition handler. Guards on the new state a2 being valid (not -1) and different from the last state stored at this+0x28; dispatches a2 (0-4) via the jump table at 0x005544A8 to write the mode sub-fields this+0x18/+0x1C/+0x20 to small integer modes, skipping a write when the field already holds the target value, and notifying the device object dword_8B89A0 through vtable offset +252. Cases 3 and 4 route through EnumToFieldOffsetSetter (0x00554260) instead of direct field writes. Stores a2 back into this+0x28 at the end.
- `0x00556330` **HighResolutionTimerAccumulator** — __thiscall timer tick accumulator. Guards on the initialized/frequency dword at +0x00 and a recorded previous timestamp at +0x30/+0x34; samples the current high-resolution timestamp via QueryPerformanceCounter (mode bit 0 of the flags at +0x48) or RDTSCTimestampRead (0x0055687B, feature byte 0xFF00000000005406), computes the elapsed delta from the +0x30/+0x34 previous timestamp, accumulates it into the running total at +0x28/+0x2C, then clears the previous-timestamp fields. Returns 0 when any entry guard fails.
- `0x00556900` **AnimationRuntimeManager** — Walks the animation channel linked list whose head is dereferenced through the pointer at this+0x110 plus 0x28 (effective this+0x138), advancing through the next pointer at node+0x5C. For each node loads the channel-data pointer at node+0x54; when the flags dword at channel+0x18 has bit 0x400 set, adds argument a2 to the float accumulator at channel+0x38. Returns the list traversal terminator.
- `0x00556CD0` **D3DResourceDirtyManager** — Marks D3D resources dirty for re-upload. Flag guards at +0x44 (unconditional) and +0x4C combined with argument a3 drive self-recursive calls to D3DMarkDirty(a2, 1). Walks the resource-node linked list headed at this+0x204 (node next pointer at node+0x10); per node reads the element count and array pointer (this+0x224 / this+0x228), ORs dirty bit 0x400 into every element's flag at (element_ptr + 56), calls sub_55D720(a2, 1) per element, advances by a 64-byte element stride, and clears bit 0x10000000 on the node's processed-flag field (this+0x368). Returns the last node's element count.
- `0x005570C0` **D3DResourceDirtyManager** — Walks two scene-graph lists of the this object and marks every node dirty for D3D re-upload. First traverses parent nodes rooted at this+0x100, descending into each parent's child-list head at node offset 0xEC and advancing through children via each child's dword index 19; then walks a flat sibling list rooted at this+0x108 the same way. Each node is passed to D3DMarkDirty(node, a2, 0) (0x00556CD0); the last call's return value becomes the function result. Invoked by sub_557120.
- `0x005573F0` **UnknownObject** — Sequential delegation with no return value: calls EmptyStub_b160 (0x0053B160) first, then a second stub EmptyStub_0170 (named in the raw source only), in that order. Invoked by sub_5574B0 (0x005574B0).
- `0x005592B0` **DoublyLinkedNodeContainer** — Removes a specific node a2 from the doubly-linked list rooted at this+0x148 with count at this+0x144. Walks from the list head comparing node pointers until a2 is found; on a match relinks the previous node's +104 forward link to the next node and the next node's +100 back link to the previous node, updates the head at this+0x148 when a2 was the head, runs sub-resource cleanup sub_5574B0 (0x005574B0), calls the no-op EmptyStub_7470 (0x00557470), and frees the node via FreeWrapper_7bcf (0x00587BCF). All paths decrement the node count at this+0x144 and, when that count was 1, clear the head to 0. Returns 0.
- `0x00559350` **UnknownObject** — Initializer (__thiscall): strcpy-copies string parameter a2 into object memory starting at this+0x0, writes parameter a3 into this+0x14, parameter a4 into this+0x18, and zeroes this+0x1C; returns a3. The semantic role of the two stored parameters is unknown.
- `0x005596E0` **LinkedDispatchContext** — Dispatch function invoked on a context object a1. Walks a linked list of dispatch entries seeded from the list pointer at this+0x8; for each entry compares the selector field (+0x14 on the entry object) against the target value held at obj+0x220 and, on a match, guards on the alternate handler-context function pointer (*(this+0x230) + 0x14), writes the call argument (*(this+0x230) + 0x18) into this+0x20, then makes an indirect __thiscall. A fallback path uses the direct handler object at obj+0x220 (function pointer +0x14, argument +0x18) when the walk produced no call.
- `0x00559A30` **LinkedDispatchContext** — Single-argument __stdcall wrapper that forwards its pointer argument a1 to FunctionPointerDispatchViaLinkedTraversal (0x005596E0, named in the raw source but not present in the packet's static callee list) and returns the call result unchanged. A read of global dword_8B8F2C is recorded in the deterministic facts but does not appear in the decompiled body.
- `0x0055BC00` **ListNodeAllocator** — Linked-list node management: searches the list headed at this+0x120 (node counter at this+0x11C) for a node whose four fields (+0x128, +0x12C, +0x134, +0x138) match the arguments a2..a5, returning -3 as a duplicate marker. Otherwise a 36-byte node is allocated via OperatorNewNhMallocWrapper (0x00587C03), initialized by SmallStructInit (0x0055BAF0; status field evidenced as this+0x19C), appended to the tail (next-link at this+0x140, back link at this+0x180), and populated by F_6FieldStructSetter (0x0055BB20) with a stride selected by a4 (6/5 -> 16, 7 -> 24, default 32 unless a4 == 8 which keeps a5). The node counter at this+0x11C is incremented and 0 is returned. Called from sub_53DB90.
- `0x0055C440` **UnknownObject** — Empty stub: ignores its single argument a1 and returns 0 unconditionally. Called by sub_544740 and sub_55BD20; the legacy ABI lead (Empty_Stub_55c440) matches the observed body exactly.
- `0x0055C7B0` **InputKeyEventDispatcher** — Small wrapper: initializes a local output pointer v2 to the current instance, calls sub_55C450(this[1274] at offset 0x13E8, 0, &v2) passing the field at offset 0x13E8 as the first argument, mode 0, and the address of v2 as an output context, then returns v2. Called by KeyEventDispatchToSubHandlers on the key-16 path.
- `0x0055C7D0` **InputKeyEventDispatcher** — Thin __thiscall wrapper around an input-state query: copies the this pointer into a local, passes the dword field read at offset 0x13EC as the handle, a constant zero, and a pointer to the local into sub_55C450 (0x0055C450), then returns the local (which aliases this). Acts as an adapter between the caller and the input-state query routine.
- `0x0055C7F0` **InputKeyEventDispatcher** — Key-event dispatch: prepares a key-event buffer from the field at this+0x1544 via sub_55C650 (0x0055C650), resolves the key state into v4 via sub_55C450, then filters on the event message type a2: only a2 == 0x200000 passes; a2 == 32 routes to InputStateQueryWrapper (0x0055C7D0), a2 == 16 routes to sub_55C7B0 (0x0055C7B0), and every other value is blocked with a -1 return. Called by D3DTextureCreation.
- `0x0055CEB0` **RGB16BitColorCodec** — Trivial __stdcall wrapper that unpacks three low bytes (BYTE2, BYTE1, BYTE0) from packed dword a2 and forwards them, together with a1, to RGBColorSpaceCompactionTo16Bit (0x0055CEE0), returning the compaction result. Used from the 2D surface blit/fill path.
- `0x0055CEE0` **RGB16BitColorCodec** — Packs separate R/G/B colour channels into a single 16-bit word: format selector a1 == 6 produces an RGB565 value (red 5 bits from a2, green 6 bits from a3, blue 5 bits from a4); a1 == 5 produces an RGB555 value (5/5/5). For any other format selector it returns 0.
- `0x0055D320` **UIColorGroupState** — UI colour-group updater. Selects one of three colour groups on this via a2 (1/2/3), converts the byte RGB inputs a3-a5 to floats by scaling with 0.0039215689 and a per-group alpha factor, writes the three components (group 1 at +8/+12/+16 with scale +20; group 2 at +24/+28/+32 with scale +36; group 3 at +40/+44/+48 with scale +52), then pushes the group through DirectXVertexBufferTextureCoordinateSetup (0x005416A0) using the cached vertex-buffer identifier at this+4 and the device global dword_8B78A0. Finally sets the 0x800 dirty bit on the UI context at dword_8B8F28+236 and returns that context pointer.
- `0x0055D560` **UIColorGroupState** — Reads one of three fields of the this object selected by an integer index a2 (1, 2 or 3) and writes it to caller-provided output pointer a3: index 1 reads this[5] (+0x14), index 2 reads this[9] (+0x24), index 3 reads this[13] (+0x34). The write happens only when a3 is non-null; index values outside 1..3 write nothing. Returns a3. The three selected offsets sit at the per-group alpha/scale-factor slots of the colour-group layout shared with ByteColorToFloatWithDXUpdate. Invoked by sub_558E70.
- `0x00560547` **PixelBufferTransformKernel** — Copies 2-byte-per-element image data from a source buffer to a destination buffer, honoring per-row pattern segments. Computes byte offsets into both buffers from row/column indices and stride fields (source stride a1[8] -> dword_5DD82C, destination stride a4[8] -> dword_5DD830), publishes copy-control globals (dword_5DD838 = a8, dword_5DD834 = a7, dword_5DD840 = a8*a7), scans the run-length pattern array a9 to locate the current segment, then runs the main copy loop while dword_5DD840 > 0, copying 2*v20 bytes per segment via qmemcpy, advancing cursors by 2*v20 or rewinding by the strides at segment boundaries, toggling the direction flag dword_5DD83C per segment. Returns an uninitialized stack slot.
- `0x0056068E` **PixelBufferTransformKernel** — Image/texture pixel-processing kernel over a 16-bit pixel buffer. Computes three channel LUT offsets from nibbles packed in parameter a7 (dword_5DD828/5DD824/5DD820, each 32 * (byte >> 4)), sets up a per-row width (dword_5DD814), row stride (dword_5DD81C) and row counter (dword_5DD818), then runs nested do-while loops (a5 rows x a4 pixels) combining byte_5DD8CC clip-table remaps against byte_5DECCC multiply LUT rows selected by dword_5DD878 (32 * a8). Each 16-bit pixel is transformed with rotate operations and written back in place.
- `0x005607C1` **PixelBufferTransformKernel** — Void cdecl function taking eight int arguments. Stores argument-derived setup values into the dword_5DD8xx globals (LUT row bases dword_5DD878 = 32*a8 and dword_5DD898 = a8<<6; row/column counters dword_5DD814 = a4, dword_5DD818 = a5; row stride dword_5DD81C = a6 - 2*a4; channel LUT offsets dword_5DD828/5DD824/5DD820 from the packed value a7), computes a word-pointer base into an image buffer, then runs two nested do-while loops (outer a5 rows, inner a4 columns). Each inner step reads one 16-bit pixel, rebuilds it through rotation (ROR4) and four byte-LUT remaps (byte_5DD8CC, byte_5DDCCC, byte_5DECCC, byte_5E0CCC) with offsets derived from a7 and a8, and writes the transformed word back in place. Likely a 16-bit texture/pixel transform kernel.

## Proposed classes

### AnimationRuntimeManager

Animation runtime object advancing linked lists of animation nodes and channel data. Two families of state are evidenced: an animation-block anchor at this+0x110 whose +0x28 sub-field yields the channel list head (this+0x138; node data pointer at node+0x54, next link at node+0x5C, channel flags at channel+0x18, accumulator at channel+0x38) and whose container state lives at *(this+0x134) (list/iteration data +0x15C, entry count +0x164, per-node control flags +0x168, entries pointer +0x180, per-entry threshold +0x1A8, timer accumulator +0x1B0, duration/timer +0x1C0, completion flag word +0x1C4); and an interpolation node list rooted at this+0x204 with track entries (16-byte track stride, entry array at *(track_base)+168, 37-dword entries, loop-mode switch with jump table at 0x005504BC, one-shot completion flag this+0x354). All three methods are called from sub_557120.

Methods: `0x00550310`, `0x005503A0`, `0x00556900`

- `this+0x00000110` `void* animation_block_anchor` (read, DERIVED)
- `this+0x00000134` `void* animation_container` (read, DERIVED)
- `this+0x00000138` `void* channel_list_head` (read, DERIVED)
- `this+0x00000204` `void* interpolation_node_list` (read, DERIVED)
- `this+0x00000354` `dword one_shot_completion_flag` (read_write, DERIVED)
- `*(this+0x134)+0x0000015C` `void* list_iteration_data` (read, GUESS)
- `*(this+0x134)+0x00000164` `int entry_count` (read, GUESS)
- `*(this+0x134)+0x00000168` `dword node_control_flags` (read, GUESS)
- `*(this+0x134)+0x00000180` `void* entries_pointer` (read, GUESS)
- `*(this+0x134)+0x000001A8` `int entry_threshold_counter` (read, GUESS)
- `*(this+0x134)+0x000001B0` `int timer_accumulator` (read_write, GUESS)
- `*(this+0x134)+0x000001C0` `int entry_duration` (read, GUESS)
- `*(this+0x134)+0x000001C4` `dword completion_flag_word` (read_write, GUESS)

### D3DResourceDirtyManager

Scene/resource object marking D3D buffer resources dirty for re-upload. Owns node lists rooted at this+0x100 (parent chain), this+0x108 (flat sibling chain) and this+0x204 (resource-node list whose elements carry count at this+0x224 and array pointer at this+0x228), plus dirty-mark control flags at +0x44 and +0x4C and a per-node processed flag at this+0x368. Recursively marks nodes via D3DMarkDirty and triggers per-element re-upload via sub_55D720.

Methods: `0x00556CD0`, `0x005570C0`

- `this+0x00000044` `dword mark_unconditional_flag` (read, DERIVED)
- `this+0x0000004C` `dword mark_conditional_flag` (read, DERIVED)
- `this+0x00000100` `void* parent_list_head` (read, DERIVED)
- `this+0x00000108` `void* sibling_list_head` (read, DERIVED)
- `this+0x00000204` `void* resource_node_list` (read, DERIVED)
- `this+0x00000224` `int node_element_count` (read, DERIVED)
- `this+0x00000228` `void* node_element_array` (read, DERIVED)
- `this+0x00000368` `dword node_processed_flag` (read_write, DERIVED)
- `*(this+0x204)+0x000000EC` `void* parent_child_list_head` (read, GUESS)
- `*(this+0x204)+0x00000104` `void* node_next_sibling` (read, GUESS)

### HighResolutionTimerAccumulator

High-resolution timer tick accumulator. Frequency/initialized dword at +0x00, mode flags at +0x48 (bit 0 selects QueryPerformanceCounter over RDTSC), running accumulator at +0x28/+0x2C, previous timestamp at +0x30/+0x34. Each tick computes the elapsed delta from the previous timestamp and clears it afterwards.

Methods: `0x00556330`

- `this+0x00000000` `dword frequency_or_initialized` (read, DERIVED)
- `this+0x00000028` `dword accumulator_low` (read_write, DERIVED)
- `this+0x0000002C` `dword accumulator_high` (read_write, DERIVED)
- `this+0x00000030` `dword prev_timestamp_low` (read_write, DERIVED)
- `this+0x00000034` `dword prev_timestamp_high` (read_write, DERIVED)
- `this+0x00000048` `dword mode_flags` (read, DERIVED)

### DoublyLinkedNodeContainer

Doubly-linked node container with an explicit node count at this+0x144 and list head at this+0x148. Node links are stored at node+0x64 (back) and node+0x68 (forward). Node removal runs sub-resource cleanup via sub_5574B0 (0x005574B0), invokes the no-op EmptyStub_7470 (0x00557470), and frees the node through FreeWrapper_7bcf (0x00587BCF); the head is cleared when the count reaches 1 before decrement.

Methods: `0x005592B0`

- `this+0x00000144` `int node_count` (read_write, DERIVED)
- `this+0x00000148` `void* list_head` (read_write, DERIVED)

### ListNodeAllocator

Linked-list node container with allocation: duplicate detection over four key fields, 36-byte node allocation via OperatorNewNhMallocWrapper, init via SmallStructInit, tail-append with back-link, and six-field population with a caller-selected stride. Head at this+0x120, node counter at this+0x11C, key fields at +0x128/+0x12C/+0x134/+0x138, next link at +0x140, back link at +0x180, status field at this+0x19C. The comparison keys, stride semantics and the heap node-layout mapping are call-supplied and unconfirmed.

Methods: `0x0055BC00`

- `this+0x0000011C` `int node_count` (read_write, DERIVED)
- `this+0x00000120` `void* list_head` (read_write, DERIVED)
- `this+0x00000128` `dword node_key0` (read, DERIVED)
- `this+0x0000012C` `dword node_key1` (read, DERIVED)
- `this+0x00000134` `dword node_key2` (read, DERIVED)
- `this+0x00000138` `dword node_key3` (read, DERIVED)
- `this+0x00000140` `void* node_next` (read_write, DERIVED)
- `this+0x00000180` `void* node_back` (write, DERIVED)
- `this+0x0000019C` `dword node_status` (write, GUESS)

### InputKeyEventDispatcher

Input key-event dispatch adapter. Routes key events through the sub_55C450 input-state query using per-object handle fields at +0x13E8 and +0x13EC and a key-event buffer configured from the field at +0x1544; filters on event message type 0x200000 and key codes 16/32.

Methods: `0x0055C7B0`, `0x0055C7D0`, `0x0055C7F0`

- `this+0x000013E8` `dword query_handle_a` (read, DERIVED)
- `this+0x000013EC` `dword query_handle_b` (read, DERIVED)
- `this+0x00001544` `void* key_buffer_config` (read, DERIVED)

### LinkedDispatchContext

Dispatch context that resolves a target value at obj+0x220 against a linked list of dispatch entries seeded from this+0x8, selecting a handler by selector (entry +0x14) and invoking it indirectly with the alternate handler context at this+0x230 (function pointer +0x14, call argument +0x18) after staging the argument into this+0x20. Falls back to the direct handler object at obj+0x220 when the walk produced no call.

Methods: `0x005596E0`, `0x00559A30`

- `this+0x00000000` `void* root_context` (read, DERIVED)
- `this+0x00000008` `void* dispatch_list_head` (read, DERIVED)
- `this+0x00000020` `void* call_parameter` (write, DERIVED)
- `this+0x00000230` `void* alternate_handler_context` (read, DERIVED)
- `obj+0x00000220` `dword target_value` (read, DERIVED)
- `*(obj+0x220)+0x00000014` `void* fallback_handler_fn` (read, DERIVED)
- `*(obj+0x220)+0x00000018` `void* fallback_handler_arg` (read, DERIVED)
- `*(this+0x230)+0x00000014` `void* alternate_handler_fn` (read, DERIVED)
- `*(this+0x230)+0x00000018` `void* alternate_handler_arg` (read, DERIVED)

### UIColorGroupState

UI colour-group state holding three 16-byte colour groups, each with three scaled float components and a per-group alpha/scale factor (group 1 at +8/+12/+16 with scale at +20, group 2 at +24/+28/+32 with scale at +36, group 3 at +40/+44/+48 with scale at +52) and a cached vertex-buffer identifier at +4. Colour updates push the active group to the DirectX vertex buffer via DirectXVertexBufferTextureCoordinateSetup and mark the UI context (dword_8B8F28) dirty with bit 0x800.

Methods: `0x0055D320`, `0x0055D560`

- `this+0x00000004` `dword vertex_buffer_id` (read, DERIVED)
- `this+0x00000008` `float group1_r` (read_write, DERIVED)
- `this+0x0000000C` `float group1_g` (read_write, DERIVED)
- `this+0x00000010` `float group1_b` (read_write, DERIVED)
- `this+0x00000014` `float group1_scale` (read_write, DERIVED)
- `this+0x00000018` `float group2_r` (read_write, DERIVED)
- `this+0x0000001C` `float group2_g` (read_write, DERIVED)
- `this+0x00000020` `float group2_b` (read_write, DERIVED)
- `this+0x00000024` `float group2_scale` (read_write, DERIVED)
- `this+0x00000028` `float group3_r` (read_write, DERIVED)
- `this+0x0000002C` `float group3_g` (read_write, DERIVED)
- `this+0x00000030` `float group3_b` (read_write, DERIVED)
- `this+0x00000034` `float group3_scale` (read_write, DERIVED)

### RGB16BitColorCodec

16-bit colour-space codec: decomposes a packed 32-bit colour dword into its byte channels (BYTE2/BYTE1/BYTE0) and packs separate R/G/B channels into 16-bit words in RGB565 (format selector 6) or RGB555 (format selector 5) layout. The channel-to-argument mapping is inferred from the bit-width masks.

Methods: `0x0055CEB0`, `0x0055CEE0`


### ModeStateMachineSetter

Secondary mode/state-machine setter writing three mode sub-fields at +0x18/+0x1C/+0x20 selected by a dispatch value 0-4, persisting the accepted value at this+0x28, and notifying a device object (dword_8B89A0) through vtable offset +252. The enum values (2/4/1) and notify modes (4/5/6) have no packet-grounded meaning.

Methods: `0x005542F0`

- `this+0x00000000` `void* vtable` (read, GUESS)
- `this+0x00000018` `int mode_sub_field_0` (read_write, GUESS)
- `this+0x0000001C` `int mode_sub_field_1` (read_write, GUESS)
- `this+0x00000020` `int mode_sub_field_2` (read_write, GUESS)
- `this+0x00000028` `int last_state` (read_write, GUESS)

### PixelBufferTransformKernel

16-bit pixel/image transform kernels sharing the dword_5DD8xx scratch-global family (row counters dword_5DD814/dword_5DD818, row stride dword_5DD81C, channel LUT offsets dword_5DD820/dword_5DD824/dword_5DD828, copy strides and controls dword_5DD82C/dword_5DD830/dword_5DD834/dword_5DD838/dword_5DD83C/dword_5DD840, LUT row bases dword_5DD878/dword_5DD898) and the byte-LUT remap tables byte_5DD8CC, byte_5DDCCC, byte_5DECCC and byte_5E0CCC. The functions may be module-level free functions over shared global scratch rather than methods of one object; ownership is unproven.

Methods: `0x00560547`, `0x0056068E`, `0x005607C1`


## Compatibility contracts

- **AnimationNodeEntryTimerContract** — Animation entries iterate at a 37-dword (148-byte) stride from the entries pointer (+0x180 of the *(this+0x134) container); each entry compares its timer (offset +0x1C0 area) against its duration and on completion sets flag bit 2 in the entry flag word (+0x1C4 area) and dispatches the interrupt callback (0x0058957A) with the timer value. Entry iteration is gated on the entry count (+0x164) and per-entry threshold counter (+0x1A8); per-node processing is gated on bit 0x400 of the node control flags (+0x168).
- **D3DResourceDirtyMarkContract** — D3D resources are marked dirty by OR-ing bit 0x400 into each element's flag at (element_ptr + 56) over a 64-byte element stride and calling sub_55D720(a2, 1) per element; per-node processed flags are cleared of bit 0x10000000 (this+0x368). The scene-graph traversal marks every node via D3DMarkDirty(node, a2, 0), and the flag guards at +0x44 (unconditional) and +0x4C (with argument a3) drive recursive D3DMarkDirty(a2, 1) calls.
- **HighResolutionTimerAccumulatorContract** — The timer accumulates an elapsed delta into the running total at +0x28/+0x2C. The delta is the difference between the current timestamp (QueryPerformanceCounter when mode bit 0 of +0x48 is set, RDTSCTimestampRead otherwise, with feature byte 0xFF00000000005406) and the previous timestamp at +0x30/+0x34, which is cleared after each accumulation. Guards: the frequency/initialized dword at +0x00 and the previous-timestamp dwords must be non-zero.
- **DoublyLinkedNodeRemovalContract** — Removal from the doubly-linked container with count at this+0x144 and head at this+0x148: node links live at node+0x64 (back) and node+0x68 (forward); on removal the previous node's forward link and the next node's back link are relinked around the target, the head is updated when the target was the head, the sub-resources are cleaned via sub_5574B0 (0x005574B0), the no-op EmptyStub_7470 (0x00557470) runs, and the node is freed via FreeWrapper_7bcf (0x00587BCF). The count is decremented and the head cleared to 0 when the count was 1.
- **ListNodeAllocatorDuplicateContract** — The list headed at this+0x120 (counter at this+0x11C) rejects duplicates: a node whose four key fields (+0x128/+0x12C/+0x134/+0x138) all match the arguments returns -3. Otherwise a 36-byte node is allocated (OperatorNewNhMallocWrapper), initialized (SmallStructInit, status field this+0x19C), appended (next at +0x140, back at +0x180) and populated (F_6FieldStructSetter) with a stride selected by argument a4 (6/5 -> 16, 7 -> 24, 8 -> a5, default 32).
- **KeyEventDispatchContract** — Key events are filtered on the event message type argument: only 0x200000 passes; the resolved key code then routes 32 to InputStateQueryWrapper (0x0055C7D0) and 16 to sub_55C7B0 (0x0055C7B0), and every other value is blocked with a -1 return. The key-event buffer is configured from the field at this+0x1544 via sub_55C650 and the key state resolved via sub_55C450.
- **RGB565RGB555PackingContract** — The colour codec packs R/G/B channels into a 16-bit word: format selector 6 yields RGB565 (red 5 bits, green 6, blue 5), format selector 5 yields RGB555 (5/5/5), and any other selector returns 0. The channel-to-argument mapping (which of a2/a3/a4 is red/green/blue) is inferred from the bit-width masks and not proven by call-site evidence.
- **UIColorGroupVertexBufferContract** — The UI colour object holds three colour groups (group 1 at +8/+12/+16 with scale at +20, group 2 at +24/+28/+32 with scale at +36, group 3 at +40/+44/+48 with scale at +52) and a cached vertex-buffer identifier at +4. Byte RGB inputs are scaled by 0.0039215689 and the per-group alpha factor; the active group is pushed through DirectXVertexBufferTextureCoordinateSetup (0x005416A0) and the UI context at dword_8B8F28 has its 0x800 dirty bit set (at +236).
- **LinkedHandlerDispatchContract** — The dispatch context resolves a target value held at obj+0x220 against a linked list of dispatch entries seeded from this+0x8; on a selector match (entry +0x14), the alternate handler context at this+0x230 (function pointer +0x14, call argument +0x18) is invoked indirectly as a __thiscall on a1 after the argument is staged into this+0x20. When the walk produced no call, a fallback dispatches through the direct handler object at obj+0x220 (function pointer +0x14, argument +0x18).
- **PixelLutScratchGlobalContract** — The 16-bit pixel/image kernels share the dword_5DD8xx scratch-global family (row counters dword_5DD814/dword_5DD818, row stride dword_5DD81C, channel LUT offsets dword_5DD820/dword_5DD824/dword_5DD828, copy strides/controls dword_5DD82C/dword_5DD830/dword_5DD834/dword_5DD838/dword_5DD83C/dword_5DD840, LUT row bases dword_5DD878/dword_5DD898) and the byte-LUT remap tables byte_5DD8CC, byte_5DDCCC, byte_5DECCC and byte_5E0CCC. A replacement must treat these globals as shared state or refactor the kernels together; whether they belong to one object or are free functions is unproven.

## Unresolved

- Owners are unknown for seven functions lacking owner-class evidence in this packet: 0x0054FDF0, 0x005507D0, 0x00550810, 0x00551800, 0x005573F0, 0x00559350, 0x0055C440.
- SimpleSetter_fdf0 (0x0054FDF0): the purpose of the stored value at +0x54 is unknown; no reader evidence is present in the packet. The structural twin MenuSelectSetter suggests a generic selection field, but its semantics are not established.
- RefcountDecrement (0x005507D0): the canonical name and ABI lead imply a resource refcount release, but the raw body is a forwarder to EmptyStub_b4a0 with no refcount arithmetic and no parameters; EmptyStub_b4a0's behavior is outside this packet.
- FreeMemberAtOffset4 (0x00550810): the free reading of the FreeWrapper_7bcf call is DERIVED from the wrapper name; the wrapper contract (null-check, refcount, or conditional free) is invisible here, and the caller sub_550F70's cleanup role is not evidenced.
- UpdateFlagIfNonNull (0x00551800): result (eax) is read uninitialized when a1 is null; the entity type of a1 and the meaning of the flag-cascade update are not evidenced.
- AdvanceAnimationTimers (0x00550310): the mapping between decompiler this-relative accesses and the packet's *(this+0x134)-relative field bases (0x15C, 0x164, 0x168, 0x180, 0x1A8, 0x1B0, 0x1C0, 0x1C4) is an extraction attribution, not independently confirmed; the per-entry layout is derived from decompiler index math, not a named struct; caller sub_557120 is not on a confirmed frame path.
- AnimationTrackInterpolationUpdate (0x005503A0): fields this+0x218, this+0x31C and this+0x320 are declared in the packet field table but not referenced by the raw pseudocode; the completion-bit (entry byte at -16, bit 4) and the 0xFFFF000F loop-mode constant space are inferred, not confirmed.
- AnimationRuntimeManager vs D3DResourceDirtyManager both use a this+0x204 list head; they are kept as separate classes because the packet does not prove common ownership of the two objects.
- MarkD3DBuffersDirty (0x00556CD0): the node element count/array mapping (this+0x224/+0x228 as the packet reads them vs node+0x118/+0x11C in the raw source) is unresolved; fields this+0x32C and this+0x330 are adjacent node properties the function neither reads nor writes; argument a2 semantics depend on the caller (0x005570C0) and the resource/device context.
- NestedLinkedListTraversalWithDirtyMark (0x005570C0): field:*(*(this+0x204)+0xEC):0x98 and field:this:0x1A0 are listed in the deterministic field set but not referenced by the decompiled body.
- DoublyLinkedListNodeRemovalByPointer (0x005592B0): fields this+0x214, this+0x218 and this+0x27C are listed in the deterministic facts but not visible in the raw source text; the removed node's object type and the cleanup contract of sub_5574B0 are unknown.
- CallTwoStubs (0x005573F0): EmptyStub_0170 is named in the raw source but has no packet callee evidence reference; both callees are labeled stubs whose behavior is not evidenced here.
- StringCopyFieldInit (0x00559350): the strcpy target at this+0x0 has no packet field evidence for offset 0x0; the semantic role of the two stored parameters (0x14, 0x18) is unknown.
- FunctionPointerDispatchViaLinkedTraversal (0x005596E0): ownership of the dispatch entries, the alternate handler context at this+0x230 and the direct handler object at obj+0x220 is unknown; purpose of alternate-context fields +0x2C and +0x30 (this+0x230 base) and of this+0x22C and this+0x234 is unresolved; the seed offset result[137] has no dedicated packet field entry.
- DispatchViaLinkedTraversal (0x00559A30): the deterministic facts record a read of global dword_8B8F2C (0x008B8F2C) that does not appear in the decompiled source; FunctionPointerDispatchViaLinkedTraversal has no static callee record in this packet, so its identity and argument contract are unresolved.
- ListNodeAllocOrDuplicateCheck (0x0055BC00): the write *(v16 + 32) = 0 uses an uninitialized decompiler variable; the MEMORY[0x1C] = 0 write in the allocation-failure path is not evidenced; the comparison keys a2..a5 and the stride value v15 are call-supplied; the heap-allocated node layout mapping (fields presented as this-relative 0x128..0x140 and 0x180) is not confirmed.
- EmptyStub_c440 (0x0055C440): the purpose of the unused parameter a1 and what the call sites expect from an always-0 result are not grounded by this packet.
- sub_55C7B0 (0x0055C7B0): the semantics of the first argument this[1274] (offset 0x13E8) passed to sub_55C450 and the meaning of the mode constant 0 are unproven; the relationship between this[1274] and the caller's input/display object is unconfirmed.
- InputStateQueryWrapper (0x0055C7D0): the meaning of the constant 0 argument to sub_55C450 is unknown; whether sub_55C450 writes through &v2 and can mutate the returned value is not established; ownership and type of the object containing offset 0x13EC are unknown.
- KeyEventDispatchToSubHandlers (0x0055C7F0): the mapping of key codes 32 and 16 to the space and shift keys is prose from the skeleton fill, not packet evidence; the v2 (ecx) argument passed to the two sub-handlers is uninitialized in the decompiler output; caller D3DTextureCreation (0x00550080) is the only recorded caller and the broader input/UI context is not evidenced.
- RGB16BitColorCodec: the alpha/red/green/blue ordering of the four packed bytes in a2 and the role of a1 are not established from this packet; the channel-to-argument mapping of RGBColorSpaceCompactionTo16Bit is inferred from the bit-width masks.
- ByteColorToFloatWithDXUpdate (0x0055D320): the read-only global flt_59E460 is flagged by packet facts but never referenced in the raw decompiled source, so its relation to the 0.0039215689 scale constant is not evidenced; the exact UI role of the three colour groups is not resolvable from this function alone.
- GetFieldByIndex (0x0055D560): the semantic purpose of the three selected fields (+0x14/+0x24/+0x34) is not determinable from this packet alone; the skeleton fill labels them alpha/scale factors for three colour groups, which is not verifiable from the raw source alone.
- ImagePatternedCopy (0x00560547): the run-length pattern semantics of a9 (segment meaning, and why v20 counts 2-byte units) are not resolvable from this packet; the dword_5DD83C direction toggle implies reversed-copy segments (likely vertical flipping during blit) but the caller context is absent; the returned value v28 is uninitialized; qmemcpy renders as an inline block copy whose concrete primitive is not evidenced.
- TextureDecodePixelKernel_A (0x0056068E): the exact meaning of the byte_5DD8CC (clip/remap) and byte_5DECCC (multiply) table contents and the semantics of parameter a7's nibble packing are unconfirmed; no static callers were found.
- sub_5607C1 (0x005607C1): the per-channel bit widths (5 vs 6 bits) and rotation constants (5/6/21) are not derivable from this packet; whether the dword_5DD8xx scratch globals are thread-safe / shared with other image routines is unknown; the exact pixel format is unknown.
- PixelBufferTransformKernel: the class may actually be a set of free functions sharing global scratch rather than methods of one object; ownership is unproven, so the class is only a GUESS grouping.
