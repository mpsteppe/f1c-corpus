# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

The packet resolves into twenty-eight defensible classes over thirty-eight functions, with every owner object still UNKNOWN. The DEFLATE complex splits into DeflateTreeCostCalculator (0x00538940: runs RunLengthAnalyzer over the two tree frequency tables at this+0xB12/0xB1E, builds the encoding tree via sub_5383D0, scans code lengths 18..3 through byte_5B7DEC and accumulates the cost 3*result+17 into this+0x169B), DeflateCodeLengthAnalyzer (0x005389B0: run-length frequency analysis with zero-run 138/3 versus non-zero 6/3 or 7/4 thresholds), DeflateBitstreamPacker (0x00538A90, 0x00538CE0: symbol-block writer and run/literal encoder sharing the 16-bit-accumulator flush contract), and FrequencyRatioValidator (0x00539600: sums 7/121/128 word entries and stores (v2 <= (v1>>2)) at this+0x1C). Free math lives in Vector3FloatOps (0x0053BDE0, 0x0053BE60) and ForceScaleComputation (0x0053BCE0). The registration family is CallbackRegistrationThunk (0x0053C150, 0x0053C1B0, 0x0053C210 forwarding target addresses to BooleanToIntConversion 0x00587B3E), OnceGuardedCallback (0x0053C160, 0x0053C220), DelegationWrapper_55EE20 (0x0053ACF0, 0x0053C140) and DirectXSurfaceInitDelegationWrapper (0x0053C200). Global state is handled by GlobalFlagSetter (0x0053D410, 0x0053D430), GlobalBitmaskControl (0x0054A1C0) and ParameterBroadcastChannel (0x0053D450). The list family keeps each distinct node layout separate: GlobalDoublyLinkedList (0x0053C5D0), SceneGraphNodeList (0x00545090), SoundSourceNodeList (0x005459D0), NodeAccumulatingList (0x00548810) and AudioNodeDictionaryList (0x00549380, consuming LinkedStringDictionary 0x0054A2D0). Simple accessors cover this+0x13B0/0x13D8/0xF8/0x110/0x190/0x44/0x6C/0x70 and the float store at this+0x8; InputControlChannelIO (0x00547140, 0x005471D0) groups the two channel-indexed field operations under their shared caller. No class grouping is CONFIRMED; the run-mode threshold state machine and the once-guard latch are the only state machines proposed.

## Function roles

- `0x00538940` **DeflateTreeCostCalculator** — DEFLATE tree-encoding cost accumulation: runs RunLengthAnalyzer (0x005389B0) over the two tree frequency tables at this+0xB12 and this+0xB1E, builds the encoding tree via sub_5383D0(this, this+0xB26), scans the code-length alphabet through byte_5B7DEC from 18 down to 3, breaks at the highest code length whose WORD frequency at this+2676+4*index is non-zero (falling through with result 2 when none), and accumulates the tree-description cost 3*result+17 into the counter at this+0x169B; returns the found code length (2..18).
- `0x005389B0` **DeflateCodeLengthAnalyzer** — Run-length frequency analysis of a deflate code-length sequence: walks the a2 code-length array from element a2+2 with a sentinel -1 written at a2+4*a3+6, tracks consecutive identical values, switches thresholds between zero-run mode (max 138, min 3) and non-zero mode (6/3 or 7/4), and accumulates finished runs into per-value buckets plus a1[1369]/a1[1371]/a1[1373]; returns the remaining loop counter. Sole static caller AccumulateTreeEncodingCost (0x00538940).
- `0x00538A90` **DeflateBitstreamPacker** — Symbol-block bit-buffer writer: serializes the three prefix values (a2-257 as a 5-bit field, a3-1 as a 5-bit field, a4-4 as a 4-bit field) into the 16-bit accumulator, then loops a4 times packing a 3-bit code from the word table at offset 2676 indexed by byte_5B7DEC[i], flushing two accumulator bytes to the output buffer at cursor+20 over base+8 at each threshold, and closes the block with two CompressionBitstreamPacker (0x00538CE0) calls, returning the second result. Invoked by HuffmanBitStreamEncoder (0x005381F0).
- `0x00538CE0` **DeflateBitstreamPacker** — Run-length/literal bitstream encoder: consumes a word stream (initial symbol at a2+2, following words from a2+6), emits short runs (v4 < v7) as repeated literals via the +2674/+2676 code table, non-zero runs via +2738/+2740 with two appended residual bits, and zero runs short (v4-3 via +2742/+2744, three residual bits) or long (v4-11 via +2746/+2748, seven residual bits), through a 16-bit accumulator at +5803 (high byte +5804, bit count +5805) flushed when the count crosses 16; returns the encoder state. Invoked by BitBufferWriter (0x00538A90).
- `0x00539600` **FrequencyRatioValidator** — Frequency-ratio validation: sums 7 word entries at this+0x8A and 128 word entries at this+0x28A into v2, 121 word entries at this+0xA6 into v1, computes (v2 <= (v1 >> 2)), stores that BOOL at this+0x1C and returns it. Called by HuffmanBitStreamEncoder (0x005381F0); the table ranges are presumed Huffman frequency tables but that interpretation is not packet-stated.
- `0x0053ACF0` **DelegationWrapper_55EE20** — Thin __cdecl wrapper: discards its first argument a1 and forwards the remaining three (a2, a3, a4) unchanged to callee 0x0055EE20, returning the callee's result directly.
- `0x0053BCE0` **ForceScaleComputation** — SSE force-scale computation: builds a 255.0f lane constant, assembles per-axis scale lanes from a2[17..19], scales the a1 direction components (this+0x18/0x1C/0x20) by the a1[9] magnitude (this+0x24), and writes the per-lane product into a3 via _mm_mul_ps. Straight-line with no branches, calls or guards.
- `0x0053BDE0` **Vector3FloatOps** — Reversed-order dot product: builds [0, a1[2], a1[1], a1[0]] from this+0x0/0x4/0x8, multiplies lane-wise by the float vector *a2, and horizontally sums the four lanes via shuffle-add; returns the float scalar promoted to the double return type.
- `0x0053BE60` **Vector3FloatOps** — Squared Euclidean distance between two 3D vectors: computes the per-component differences a1[i]-a2[i] over this+0x0/0x4/0x8 and returns the sum of their squares as a double. Pure scalar math with no guards, globals or calls.
- `0x0053C102` **FloatField8Storer** — Stores the double value arriving in x87 register ST(2) as a 32-bit float into the field at offset 0x8 of the this object (__userpurge convention); parameters a3..a6 are unused by the body. Implicit void return.
- `0x0053C140` **DelegationWrapper_55EE20** — Trivial forwarding wrapper: calls the ABI-named Call_FUN_00556220 (callee 0x0055EE20) with the address of global unk_8B6BD0 (0x008B6BD0) as its single argument, and returns the callee's int result unchanged.
- `0x0053C150` **CallbackRegistrationThunk** — Thin adapter: calls BooleanToIntConversion (0x00587B3E) with the address of sub_53C160 (0x0053C160) cast to int and returns the callee's result; if the callee stores the address this is callback registration, which the ABI cluster name Callback_Registration_53c150 supports.
- `0x0053C160` **OnceGuardedCallback** — One-time guarded initialization: when bit 0 of byte_8B8EE4 is clear, latches that bit and calls EmptyStub_7470 with the address of unk_8B6BD0, so the guarded setup runs at most once per process.
- `0x0053C1B0` **CallbackRegistrationThunk** — Thin zero-argument wrapper: casts the code address of sub_53C1C0 (0x0053C1C0) to int and forwards it to BooleanToIntConversion (0x00587B3E), returning that helper's integer result unchanged. Structurally identical to the adjacent sibling thunks.
- `0x0053C200` **DirectXSurfaceInitDelegationWrapper** — Trivial delegation wrapper: calls DirectXDeviceSurfaceInitialization with the address of global dword_8B78A0 (0x008B78A0) as its single argument, and returns the callee's int result unchanged.
- `0x0053C210` **CallbackRegistrationThunk** — Thin zero-argument wrapper: casts the code address of sub_53C220 (0x0053C220) to int and forwards it to the shared helper BooleanToIntConversion (0x00587B3E), returning that helper's integer result unchanged; same shape as the adjacent sibling thunks.
- `0x0053C220` **OnceGuardedCallback** — One-time guarded table registration: while bit 1 (value 1) of flag byte_8B8EE5 is clear, latches that bit, seeds a cursor to unk_8B8C38 and a counter to 8, then walks the cursor backwards in 68-byte steps calling EmptyStub_0170 before each decrement, running exactly 8 iterations at most once per process.
- `0x0053C5D0` **GlobalDoublyLinkedList** — Doubly-linked-list append: links node a1 into the global list headed by dword_8B8F28 using prev/next at node+0x1E4/+0x1E8; when the head is null a1 becomes the head with both links cleared, otherwise the next-pointer chain is walked to the tail, the old tail's next is linked to a1 and a1's prev/next are set to the old tail and 0; returns the old tail, or a1 when the list was empty.
- `0x0053D410` **GlobalFlagSetter** — Global flag setter: computes the truthiness of the integer argument (a1 != 0), stores the resulting BOOL into dword_8B8E2C (0x008B8E2C) and returns it. Called by VidMan_Init (0x004FA320); the flag's consumers are not in this packet.
- `0x0053D430` **GlobalFlagSetter** — Global flag setter, structurally identical to the adjacent setter but writing a different global: computes the truthiness of the integer argument (a1 != 0), stores the BOOL into dword_8B8E24 (0x008B8E24) and returns it. Called by VidMan_Init (0x004FA320).
- `0x0053D450` **ParameterBroadcastChannel** — Guarded broadcast of an integer to a list of per-receiver float state slots: when dword_8B89A0 is nonzero, stages the argument at dword_8B8C50[13], then walks a float table starting at unk_8B8A58 with a 17-dword stride (count bounded by dword_8B8C50[0]), updating each differing entry and calling the object method at vtable offset 252 of *dword_8B89A0 with (object, entry index, 19, staged value), storing the returned int into dword_8B78A0 (0x008B78A0). Returns the loop bound, or 0 when the guard object is null. Called from MainCameraDirectorUpdate.
- `0x005414E0` **Field0x13B0Accessor** — Getter __thiscall returning the integer field at offset 0x13B0 of this; no side effects, guards, globals or callees. Called by VertexBufferResourceAllocation (0x00543FA0), which reads the field during vertex-buffer resource setup.
- `0x005414F0` **Field0x13D8Accessor** — Getter __thiscall returning the integer field at offset 0x13D8 of this; no side effects, guards, globals or callees. Called by sub_55D720 (0x0055D720), which consumes the returned value.
- `0x00541669` **Field0x13D8Accessor** — Trivial __thiscall getter returning the dword at offset 0x13D8 of this; no side effects, branches or calls.
- `0x005424C0` **TwoFieldAccessor** — Two-field getter: reads this+0x6C and this+0x70 and writes them through output pointers a2 and a3, each independently null-guarded, then returns a3. Invoked by sub_5550E0 (0x005550E0).
- `0x00543A60` **Field0x190Accessor** — Conditional __thiscall getter: writes the dword at offset 0x190 of this into the caller-supplied output pointer a2 when a2 is non-null, then returns a2 unchanged.
- `0x00545020` **Field0xF8Accessor** — Trivial __thiscall getter returning the dword at offset 0xF8 of this; no side effects, branches or calls. Single caller CUBESceneLoaderEntry (0x0048E8D0) may indicate a scene-related owner, unverified.
- `0x00545089` **Field0xF8Accessor** — Trivial thiscall getter returning this[62], i.e. the dword at byte offset 0xF8 of the receiver; no side effects and no parameters beyond this.
- `0x00545090` **SceneGraphNodeList** — Doubly-linked-list node removal: unlinks node a2 via its prev/next pointers at node+0x1B4/+0x1B8, and when the removed node is the current head (this+0xF8 == a2) advances the head to node->next and returns it; otherwise returns a2. Called by SceneGraphTreeDestructor (0x00544EF0) during scene-graph teardown.
- `0x005459D0` **SoundSourceNodeList** — Doubly-linked-list node removal: unlinks node a2 via its prev/next pointers at node+0x30/+0x34, and when the removed node is the current head (this+0x15C == a2) advances the head to node->next and returns it; otherwise returns a2. Called by F_3DSoundSourceDestructor (0x00545150) during 3D sound source teardown.
- `0x005461A9` **Field0x110Accessor** — Getter __thiscall with no side effects: reads and returns the DWORD field at offset 0x110 (index 68) of the this object; field purpose and owning type are not identified by the packet.
- `0x00547140` **InputControlChannelIO** — Channel-indexed field dispatch via jump table jpt_54714C (0x005471B0): cases 1-4 each invoke the virtual method at vtable offset 16 of the object dword_8B8F24 with (a3, this+84/68/100/116) as the destination; the default case returns this; otherwise returns the virtual-call result. Invoked by ConstructorInputControlInit (0x00546250).
- `0x005471D0` **InputControlChannelIO** — Channel-indexed float setter: dispatches on index a2 via jump table jpt_5471DA (0x00547224); for a2 in 1..4 stores (double)a3 * 0.0039215689 (flt_59E460, ~1/255) into this+0x60/0x50/0x70/0x80 for channels 1..4; the default case writes nothing. Every path returns a2-1. Called by ConstructorInputControlInit (0x00546250).
- `0x00548810` **NodeAccumulatingList** — List accumulation pass: walks the singly-linked list headed by this+0x24, zeroes the accumulator fields this+0x0 and this+0x4, invokes the per-node cleanup/reset helper 0x00546430 on each node, then accumulates node fields (DWORD indices 37 and 38) into the accumulator slots; returns 0. The accumulation destination pointer is not explicitly initialized in the raw source.
- `0x00549166` **Field0x44Zeroer** — __fastcall helper that unconditionally writes 0 to the DWORD field at offset 0x44 (68) of the object passed as the second argument (a2/EDX); the first and third parameters are unused. No guards, globals or callees; returns void.
- `0x00549380` **AudioNodeDictionaryList** — List walk resolving each node through StringLookupInLinkedDictionary: iterates the linked list from head this+0xF8 following each node's next pointer at node+0x14 until null, calls 0x0054A2D0 on each node and stores the returned dictionary lookup result at node+0x10. Invoked from AudioEngineInitialization-side caller 0x00546010.
- `0x0054A1C0` **GlobalBitmaskControl** — Global bitmask mutation of dword_8B8EE0 (0x008B8EE0): when a2 is non-zero the bits of a1 are OR-ed in (set); otherwise the inverted bits of a1 are AND-ed in (clear); the return value is the new logical state (a1 | global on set, ~a1 on clear). Referenced by VidMan_Init (0x004FA320).
- `0x0054A2D0` **LinkedStringDictionary** — Linear search of a linked string dictionary: loads the chain head from this+0x100 (null returns 0), walks nodes via the next pointer at node+0x104 comparing each node's string at node+8 against the input with strcmp, and returns the matching node pointer or 0. Invoked by LinkedListUpdate (0x00549380) and AudioNodeUpdateWalk (0x00549440).

## Proposed classes

### DeflateTreeCostCalculator

DEFLATE-style Huffman tree-encoding cost estimator: runs run-length frequency analysis over two tree frequency tables, builds the encoding tree via sub_5383D0, scans the code-length alphabet through byte_5B7DEC, and accumulates the tree-description bit cost 3*result+17 into the counter at this+0x169B.

Methods: `0x00538940`

- `this+0x00000B12` `ptr first_tree_frequency_table_pointer` (read, DERIVED)
- `this+0x00000B1E` `ptr second_tree_frequency_table_pointer` (read, DERIVED)
- `this+0x0000169B` `word tree_description_bit_cost_counter` (read_write, DERIVED)

### DeflateCodeLengthAnalyzer

Run-length frequency analysis of a deflate code-length sequence: tracks consecutive identical values with zero-run (138/3) versus non-zero (6/3 or 7/4) thresholds, terminates the scan with a sentinel -1, and accumulates finished runs into per-value frequency buckets.

Methods: `0x005389B0`

- `this+0x00000002` `dword first_code_length_value` (read, DERIVED)
- `this+0x00000006` `dword code_length_stream_continuation` (read, DERIVED)

### DeflateBitstreamPacker

Bit-buffer symbol-block writer and run/literal bitstream encoder sharing one flush contract: a 16-bit accumulator at offset 5803 (high byte 5804) with a bit-count dword at 5805, flushing two buffered bytes to the output buffer at cursor+20 over base+8 whenever the accumulated bit count crosses the field threshold.

Methods: `0x00538A90`, `0x00538CE0`

- `this+0x00000002` `dword first_symbol_word` (read, DERIVED)
- `this+0x00000006` `dword symbol_stream_continuation` (read, DERIVED)

### FrequencyRatioValidator

Frequency-ratio validation: sums 7 word entries at this+0x8A and 128 at this+0x28A against a quarter of the 121-entry sum at this+0xA6, stores the boolean comparison result at this+0x1C and returns it. The three table ranges are presumed Huffman frequency tables, but that interpretation is not packet-stated.

Methods: `0x00539600`

- `this+0x0000008A` `word frequency_table_short_7_entries` (read, DERIVED)
- `this+0x000000A6` `word frequency_table_mid_121_entries` (read, DERIVED)
- `this+0x0000028A` `word frequency_table_long_128_entries` (read, DERIVED)
- `this+0x0000001C` `byte ratio_threshold_result_flag` (read_write, DERIVED)

### ForceScaleComputation

SSE force-scale computation: scales the a1 direction components (this+0x18/0x1C/0x20) by the a1[9] magnitude (this+0x24), multiplies per axis by a2[17..19] scale lanes and a fixed 255.0f constant, and writes the per-lane product to the a3 output vector. Physics role is ABI-lead only.

Methods: `0x0053BCE0`

- `this+0x00000018` `float direction_component_x` (read, DERIVED)
- `this+0x0000001C` `float direction_component_y` (read, DERIVED)
- `this+0x00000020` `float direction_component_z` (read, DERIVED)
- `this+0x00000024` `float direction_magnitude_scale` (read, DERIVED)

### Vector3FloatOps

Free 3-float vector math routines: a reversed-order integer/float dot product (0x0053BDE0) and a squared-Euclidean-distance routine (0x0053BE60), both reading the three components at this+0x0/+0x4/+0x8. Grouping is DERIVED from the shared vector layout; a common owner class is unproven.

Methods: `0x0053BDE0`, `0x0053BE60`

- `this+0x00000000` `float vector_x_component` (read, DERIVED)
- `this+0x00000004` `float vector_y_component` (read, DERIVED)
- `this+0x00000008` `float vector_z_component` (read, DERIVED)

### FloatField8Storer

Stores the double arriving in x87 ST(2) (__userpurge) as a 32-bit float into the field at this+0x8; parameters a3..a6 are unused. Owning object and field meaning are unknown.

Methods: `0x0053C102`

- `this+0x00000008` `float stored_float_field` (write, DERIVED)

### DelegationWrapper_55EE20

Thin __cdecl delegation wrappers around the same callee 0x0055EE20: 0x0053ACF0 drops its first argument and forwards a2/a3/a4; 0x0053C140 passes the address of global unk_8B6BD0 as a single argument. Both return the callee's result unchanged.

Methods: `0x0053ACF0`, `0x0053C140`


### DirectXSurfaceInitDelegationWrapper

Trivial delegation wrapper: calls DirectXDeviceSurfaceInitialization with the address of global dword_8B78A0 (0x008B78A0) as its single argument and returns the callee's int result. Callee identity is not resolved in this packet.

Methods: `0x0053C200`


### CallbackRegistrationThunk

Family of thin zero-argument thunks that cast a target function's code address to int and forward it to the shared helper BooleanToIntConversion (0x00587B3E), returning the helper's integer result. If the helper stores the address this is callback registration, supported by the ABI cluster name.

Methods: `0x0053C150`, `0x0053C1B0`, `0x0053C210`


### OnceGuardedCallback

One-time guarded initializers: a bit-flag guard on a global byte is latched before the guarded pass runs so it executes at most once per process. 0x0053C160 guards bit 0 of byte_8B8EE4 and calls EmptyStub_7470 with unk_8B6BD0; 0x0053C220 guards bit 1 of byte_8B8EE5 and walks a table below unk_8B8C38 in 68-byte strides for 8 iterations calling EmptyStub_0170.

Methods: `0x0053C160`, `0x0053C220`


### GlobalDoublyLinkedList

Doubly-linked list headed by the global dword_8B8F28; appends nodes whose prev/next links live at node+0x1E4/+0x1E8, walking the chain to the tail and returning the old tail (or the node itself when the list was empty).

Methods: `0x0053C5D0`

- `this+0x000001E4` `ptr node_prev_link` (read_write, DERIVED)
- `this+0x000001E8` `ptr node_next_link` (read_write, DERIVED)

### GlobalFlagSetter

Trivial global flag setters called from VidMan_Init: compute (a1 != 0), store the BOOL into dword_8B8E2C (0x0053D410) or dword_8B8E24 (0x0053D430), and return it. The relationship between the two flags is not established.

Methods: `0x0053D410`, `0x0053D430`


### ParameterBroadcastChannel

Guarded broadcast of an integer value to a list of per-receiver float slots: when the object dword_8B89A0 is non-null, walks a 17-dword-stride float table and dispatches the value to each differing entry through the object method at vtable offset 252, storing the returned int into dword_8B78A0. Called from MainCameraDirectorUpdate.

Methods: `0x0053D450`


### Field0x13B0Accessor

Getter __thiscall returning the integer field at this+0x13B0; called by VertexBufferResourceAllocation (0x00543FA0). Field meaning and owning type unknown.

Methods: `0x005414E0`

- `this+0x000013B0` `dword field_0x13B0` (read, DERIVED)

### Field0x13D8Accessor

Getter __thiscall pair returning the integer field at this+0x13D8 (0x005414F0 called by sub_55D720, and 0x00541669). Field meaning and owning type unknown.

Methods: `0x005414F0`, `0x00541669`

- `this+0x000013D8` `dword field_0x13D8` (read, DERIVED)

### TwoFieldAccessor

Getter that reads this+0x6C and this+0x70 and writes them through output pointers a2 and a3, each independently null-guarded; returns a3. Field types (dword vs float) are unverified.

Methods: `0x005424C0`

- `this+0x0000006C` `dword field_0x6C` (read, GUESS)
- `this+0x00000070` `dword field_0x70` (read, GUESS)

### Field0x190Accessor

Conditional getter that writes the dword at this+0x190 into *a2 when a2 is non-null and returns a2; called by sub_4FCAA0 (0x004FCAA0).

Methods: `0x00543A60`

- `this+0x00000190` `dword field_0x190` (read, DERIVED)

### Field0xF8Accessor

Getter __thiscall pair returning the dword at this+0xF8 (0x00545020 called by CUBESceneLoaderEntry, and 0x00545089). Field meaning and owning type unknown.

Methods: `0x00545020`, `0x00545089`

- `this+0x000000F8` `dword field_0xF8` (read, DERIVED)

### SceneGraphNodeList

Doubly-linked list owned by this with its head at this+0xF8; node removal unlinks via node prev/next at +0x1B4/+0x1B8 and advances the head when the removed node is the head. Used during scene-graph tree teardown by SceneGraphTreeDestructor (0x00544EF0).

Methods: `0x00545090`

- `this+0x000000F8` `ptr list_head_pointer` (read_write, DERIVED)

### SoundSourceNodeList

Doubly-linked list owned by this with its head at this+0x15C; node removal unlinks via node prev/next at +0x30/+0x34 and advances the head when the removed node is the head. Used during 3D sound source teardown by F_3DSoundSourceDestructor (0x00545150).

Methods: `0x005459D0`

- `this+0x0000015C` `ptr list_head_pointer` (read_write, DERIVED)

### Field0x110Accessor

Getter __thiscall returning the DWORD field at offset 0x110 (index 68) of this; no side effects. Purpose and owning type unknown.

Methods: `0x005461A9`

- `this+0x00000110` `dword field_0x110` (read, DERIVED)

### InputControlChannelIO

Channel-indexed input-control field operations called by ConstructorInputControlInit (0x00546250): 0x00547140 dispatches via jump table jpt_54714C invoking the virtual at vtable offset 16 of dword_8B8F24 with one of this+84/68/100/116 as destination; 0x005471D0 dispatches via jpt_5471DA storing a3 * (1/255) into this+0x60/0x50/0x70/0x80 for channels 1..4. Common ownership is inferred from the shared caller, not proven.

Methods: `0x00547140`, `0x005471D0`

- `this+0x00000050` `float channel_2_float_field` (write, DERIVED)
- `this+0x00000060` `float channel_1_float_field` (write, DERIVED)
- `this+0x00000070` `float channel_3_float_field` (write, DERIVED)
- `this+0x00000080` `float channel_4_float_field` (write, DERIVED)

### NodeAccumulatingList

Singly-linked list headed by this+0x24: zeroes the accumulators this+0x0 and this+0x4, invokes the per-node cleanup/reset helper 0x00546430 on each node, and accumulates node fields into the accumulator slots; returns 0. The accumulation destination pointer is not explicitly initialized in the raw source.

Methods: `0x00548810`

- `this+0x00000000` `dword first_accumulator` (read_write, DERIVED)
- `this+0x00000004` `dword second_accumulator` (read_write, DERIVED)
- `this+0x00000024` `ptr list_head_pointer` (read, DERIVED)

### Field0x44Zeroer

__fastcall helper that unconditionally writes 0 to the DWORD field at offset 0x44 of the a2 object; a1 and a3 are accepted but unused. Returns void.

Methods: `0x00549166`

- `this+0x00000044` `dword field_zeroed` (write, DERIVED)

### AudioNodeDictionaryList

Linked-list walk that resolves each node through LinkedStringDictionary: iterates from head this+0xF8 following each node's next pointer at node+0x14, calls StringLookupInLinkedDictionary (0x0054A2D0) on each node and stores the result at node+0x10. Invoked from AudioEngineInitialization-side caller 0x00546010.

Methods: `0x00549380`

- `this+0x000000F8` `ptr list_head_pointer` (read, DERIVED)
- `*(this+0x10C)+0x00000010` `ptr dictionary_lookup_result` (write, DERIVED)
- `*(this+0x10C)+0x00000014` `ptr node_next_pointer` (read, DERIVED)

### LinkedStringDictionary

Linear-search linked dictionary keyed by string: loads the chain head from this+0x100 (null returns 0), walks nodes via the next pointer at node+0x104 comparing each node's string at node+8 with strcmp, and returns the matching node pointer or 0.

Methods: `0x0054A2D0`

- `this+0x00000100` `ptr chain_head_pointer` (read, DERIVED)
- `*(this+0x204)+0x00000104` `ptr node_next_pointer` (read, DERIVED)

### GlobalBitmaskControl

Global bitmask mutation of dword_8B8EE0 (0x008B8EE0): set path ORs a1 in (returns a1 | global), clear path ANDs ~a1 in (returns ~a1). Referenced by VidMan_Init (0x004FA320).

Methods: `0x0054A1C0`


## Compatibility contracts

- **DeflateTreeEncodingCostFormula** — Tree-encoding cost accumulation must run run-length analysis over the two tree frequency tables (this+0xB12, this+0xB1E), build the encoding tree via sub_5383D0, scan code lengths 18 down to 3 through byte_5B7DEC, break at the highest code length whose WORD frequency at this+2676+4*index is non-zero (falling through with result 2 when none), add 3*result+17 to the counter at this+0x169B, and return the found code length.
- **CodeLengthRunThresholds** — Run-length code-length processing must select thresholds per run value: zero runs use max 138 / min 3; non-zero runs use 6/3 when the next value equals the previous and 7/4 otherwise. The analyzer terminates the scan with a sentinel -1 at a2+4*a3+6; the packer emits short runs as literals and non-zero/zero runs with run counts reduced by 3 (non-zero and short zero) or 11 (long zero) plus 2/3/7 residual bits through the +2674/+2738/+2742/+2746 code tables.
- **BitBufferFlushContract** — Both bit writers must keep a 16-bit accumulator (offset 5803, high byte 5804) with a bit-position dword at 5805, packing (code << bitpos) and flushing the two buffered bytes to the output buffer at cursor+20 over base+8 whenever the accumulated bit count crosses the field threshold (11/11/12/13/16 by field width), advancing the cursor by two and rebasing the accumulator.
- **FrequencyRatioValidation** — Frequency-ratio validation must sum 7 word entries at this+0x8A and 128 word entries at this+0x28A into v2, 121 word entries at this+0xA6 into v1, compute (v2 <= (v1 >> 2)), store the BOOL at this+0x1C and return it.
- **LinkedStringDictionaryLookup** — Linked string dictionary lookup must load the chain head at this+0x100 (return 0 when null), walk nodes via the next pointer at node+0x104 comparing each node's string at node+8 with strcmp, and return the matching node pointer or 0.
- **DoublyLinkedListUnlinkContract** — Doubly-linked-list node removal must unlink the node via its prev/next pointers (scene-graph variant: node+0x1B4/+0x1B8 with head this+0xF8; sound-source variant: node+0x30/+0x34 with head this+0x15C), and when the removed node is the head advance the head to node->next and return it, otherwise return the node.
- **GlobalDoublyLinkedListAppendContract** — Append to the global list headed by dword_8B8F28 must link the node via prev/next at node+0x1E4/+0x1E8: when the head is null the node becomes the head with both links cleared; otherwise the next-pointer chain is walked to the tail, the old tail's next is linked to the node and the node's prev/next set to the old tail and 0; return the old tail (or the node itself when the list was empty).
- **GlobalFlagSetterContract** — The two video-manager flag setters must store (a1 != 0) as a BOOL into their global dword_8B8E2C / dword_8B8E24 and return the stored value; both are invoked by VidMan_Init (0x004FA320).
- **GlobalBitmaskSetClearContract** — The global bitmask dword_8B8EE0 must be mutated as: a2 non-zero -> dword_8B8EE0 |= a1 (return a1 | dword_8B8EE0); a2 zero -> dword_8B8EE0 &= ~a1 (return ~a1).
- **ChannelFloatSetterContract** — The channel-indexed float setter must map index 1..4 to this+0x60/0x50/0x70/0x80 and store (double)a3 * 0.0039215689 (flt_59E460, ~1/255) into the selected field, write nothing for other indices, and return a2-1 on every path.
- **OnceGuardedInitializationContract** — One-time guarded initialization must latch a global flag bit before running (byte_8B8EE4 bit 0 for the unk_8B6BD0 pass; byte_8B8EE5 bit 1 for the 68-byte table pass below unk_8B8C38), so the guarded pass executes at most once per process.
- **Vector3SquaredDistanceContract** — Squared Euclidean distance must compute the per-component differences over the 3-float vector (this+0x0/+0x4/+0x8) and return the sum of their squares as a double.
- **AudioNodeDictionaryResolveContract** — The audio node list walk must iterate from head this+0xF8 following each node's next pointer at node+0x14 until null, resolve each node via StringLookupInLinkedDictionary and store the returned dictionary lookup result at node+0x10.

## Unresolved

- All owner objects remain UnknownObject; every class in this proposal is a DERIVED/GUESS grouping and no field, enum or vtable identity should be treated as CONFIRMED without independent static or runtime corroboration.
- AccumulateTreeEncodingCost: the legacy ABI label 'Performance_Sector_Time_Accumulator' (abi:lead) is inconsistent with the raw source, which performs frequency/tree cost analysis; the prior fill's claim that the minimum result is 3 does not match the raw source (the for-loop exits with result == 2 when no entry is non-zero, so the minimum cost is 3*2+17).
- The exact contents and layout of byte_5B7DEC (a code-length-to-index lookup) and of the WORD frequency table at this+2676 are unknown; this+0xB26 passed to sub_5383D0 is not declared as a packet field and has no field evidence ref.
- DeflateBitstreamPacker: the contents of the code/length tables at +2674/+2738/+2742/+2746 and the residual-bit counts (2, 3, 7) are inferred from bit-position arithmetic and subtraction constants, not independently evidenced; the accumulator pair at +5803/+5805 and the buffer layout (base+8, cursor+20) have no named field evidence; parameter a4 is used both as the packed 4-bit value and as the symbol-loop count.
- RunLengthFrequencyAnalyzer: the bucket layout a1[2*v9+1337], a1[1369], a1[1371], a1[1373] is taken verbatim from the raw source but its structural meaning is DERIVED; the caller's legacy name suggests a sector-timing context that does not obviously match deflate code-length frequency analysis (static caller relationship only).
- FrequencyRatioValidator: the three table ranges are presumed Huffman frequency tables per the prior fill but the packet provides no symbol meaning; the threshold divisor 4 and the meaning of the stored boolean at this+0x1C are inferred.
- ForceScaleCalculation: globals flt_59E440 and flt_59FEC8 are listed as read by the static facts but absent from the raw decompilation (every scale constant is an immediate); the meaning of the fixed 255.0f constant and the constant fourth lane (255.0f cubed) is unknown.
- FourElementReversedDotProduct: global flt_59E440 is absent from the raw source; the physics-constraint use and the double-return promotion of a single-precision value are unverified.
- FloatStoreFromX87ST: the value arrives via x87 ST(2), an artifact of the __userpurge calling convention; parameters a3..a6 are unused and their purpose is caller-determined.
- OnceGuardedCallback: the stubs EmptyStub_7470 and EmptyStub_0170 have no callee address evidence in this packet and whether the walking cursor v0 is passed to EmptyStub_0170 is unproven; why the guard is a bit-flag on a byte rather than a dedicated boolean is unresolved.
- RegisterTableBelowOnce: dword_8B78A0 (0x008B78A0) is recorded in the packet facts as read but does not appear in the raw body; the 68-byte element layout below unk_8B8C38 is not evidenced.
- DelegationWrapper_55EE20: the callee 0x0055EE20 is not resolved in this packet; the grouping of 0x0053ACF0 and 0x0053C140 rests on the shared callee reference only.
- DirectXSurfaceInitDelegationWrapper: the callee DirectXDeviceSurfaceInitialization is not resolved; the content and role of global dword_8B78A0 are unknown.
- CallbackRegistrationThunk: BooleanToIntConversion (0x00587B3E) is decompiler-named; whether it registers, stores or merely converts the forwarded address is not evidenced, and no caller of these thunks is recorded.
- GlobalDoublyLinkedList: the node type behind offsets +0x1E4/+0x1E8 and the owner of list head dword_8B8F28 are caller-defined; the asymmetric return (old tail vs the node itself) and the caller AudioEngineInitialization's use of it are not evidenced.
- GlobalFlagSetter: the meaning of dword_8B8E24/dword_8B8E2C and their consumers are not in this packet; the relationship between the two adjacent setters is not established.
- ParameterValueBroadcast: the indirect call at vtable offset 252 of the dword_8B89A0 object is unresolvable here (no direct callee recorded); the 17-dword stride, the bound at dword_8B8C50[0] and the constant 19 argument are unknown.
- Simple getters (Field0x13B0Accessor, Field0x13D8Accessor, Field0xF8Accessor, Field0x110Accessor, Field0x190Accessor, TwoFieldAccessor, Field0x44Zeroer): owning object types and field meanings are unidentified; writers are not present in the packet.
- SceneGraphNodeList / SoundSourceNodeList: the node link offsets (+0x1B4/+0x1B8 and +0x30/+0x34 respectively) are read/written only inside each removal function and have no packet field evidence refs; the owner class of each list is unknown.
- LinkedListAccumulation: the accumulation destination pointer is not explicitly initialized in the raw decompiler text, so the real target of the node-field additions is ambiguous; the node structure (DWORD indices 37/38/48) belongs to another type.
- AudioNodeDictionaryList: the node base pointer is reported as *(this+0x10C); whether that is a single node or an intermediate object holding the list head is unresolved; the semantics of the StringLookupInLinkedDictionary return value (ID vs pointer) are unresolved.
- IndexedFieldCopy: the virtual callee at object dword_8B8F24 vtable offset 16 is unresolved (no callee entry recorded); the destination fields this+84/68/100/116 are not in the packet field list.
- InputControlChannelIO: common ownership of 0x00547140 and 0x005471D0 is inferred from the shared caller ConstructorInputControlInit (0x00546250), not proven; the four channel-float fields are labeled color/alpha channels by the prior fill (DERIVED) and the constant 0.0039215689 equals approximately 1/255.
- Vector3FloatOps: grouping FourElementReversedDotProduct and F_3DSquaredDistance on the shared 3-float base is DERIVED; a common owner class is unverified.
- The subsystem is a heterogeneous cluster of unrelated helper families; boundaries are MEDIUM at best and several class groupings are convenience groupings over UnknownObject owners.
- FloatStoreFromX87ST offset 0x8 and LinkedListAccumulation offsets 0x0/0x4 coincide with vector-math offsets on different bases; no common ownership is implied (rule: equal offsets on unrelated this pointers are not proof of shared classes).
