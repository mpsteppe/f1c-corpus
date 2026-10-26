# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This subsystem groups 29 validated functions into 23 conservative class proposals. A buffered writer cluster (BitBufferWriter) flushes pending 2-byte units and writes checksummed byte sequences. An inflate cluster (InflateDecoder, HuffmanTableBuilder, InflateContextLoader, VirtualSlotDispatcher) decodes a Huffman-coded LZ77 stream through a decode-state machine, continuing across calls. A parameter/scale cluster (ParamScalingObject, FieldTripletSource) configures a flagged object whose three scale parameters drive three float groups. Scene-graph facilities (SceneGraphNode, SceneGraphContainer, FrustumCullNode, SceneModeObject, VisibilityMaskFilter) propagate flags, clear node masks, and cull against frustum planes. Two list containers (DListNodeList, DListChain), two global-array initializers (GlobalArrayInitializer), particle-buffer initializers (ParticleBufferObject), geometry helpers (TrianglePointTester, MathVectorOps, SplineCurveGenerator), a scene-state factory (SceneStateManager), a UI state setter (RenderUiStateObject), an audio dispatcher (AudioPlaybackDispatcher), and a packet writer (NetworkPacketBuffer) round out the set. Every owner is UNKNOWN at IR level; class memberships are DERIVED/GUESS proposals from field overlap, shared callers, and call edges.

## Function roles

- `0x00539720` **BitBufferWriter** — Flushes a pending 2-byte unit and its pending-count dword from the writer into the output buffer, clearing the pending state; the flush path is selected by the pending count threshold.
- `0x005397A0` **BitBufferWriter** — Writes a checksummed byte sequence: flushes the sink via UnicodeBufferFlusher, sets a mode field, appends a 4-byte one's-complement integrity trailer for the payload, and copies payload bytes into the growable buffer.
- `0x00539870` **InflateDecoder** — Inflate decode continuation: jump-table dispatch over the decode state machine (literal/length, extra bits, distance, copy, flush, error), decoding symbols via the shared lookup table and copying matches and output bytes.
- `0x00539F60` **VirtualSlotDispatcher** — Generic indirect dispatch thunk: calls the function pointer stored at +0x24 of the receiver with the context pointer at +0x28, returning the callee's result.
- `0x0053A020` **HuffmanTableBuilder** — Canonical-Huffman table builder: counts code lengths, detects canonical overflow (-3), builds cumulative offsets, orders symbols by length, and constructs linked decoder nodes with an escape marker, returning -4/-5 on structural errors.
- `0x0053A630` **InflateContextLoader** — Loads four inflate context globals into caller outputs: values dword_5DA998 and dword_5DA99C, and addresses of unk_5DA9A0 and unk_5DB9A0.
- `0x0053A7B0` **InflateDecoder** — Huffman/LZ77 decode core: walks length/literal and distance trees, refills the bit accumulator, emits literals, copies LZ77 back-references across the window, and reports invalid codes through the error strings into the caller's error slot.
- `0x0053AB80` **SplineCurveGenerator** — Generates a normalized curve lookup table of {t, delta} pairs over the entry count, evaluating the curve function per step and fixing the final entry to t=1.0.
- `0x0053B170` **FieldTripletSource** — Reads three consecutive DWORD fields (+0x4/+0x8/+0xC) into caller outputs, each write gated independently on its output pointer being non-null.
- `0x0053B1D0` **ParamScalingObject** — Reads three consecutive DWORD fields (+0x1C/+0x20/+0x24) into caller outputs, each write gated independently on its output pointer being non-null; returns the third output pointer.
- `0x0053B330` **ParamScalingObject** — Sets bit 1 of the flags word at +0 and stores three parameters into +0x1C/+0x20/+0x24; always executes fully and returns the last parameter.
- `0x0053B350` **ParamScalingObject** — Conditionally applies three scale factors to three float groups, gated on and clearing bit 1 of the flags word; returns the original flags value read at entry.
- `0x0053D930` **RenderUiStateObject** — Conditional state integer quad-setter: writes four consecutive state fields at +0x1508..+0x1514, each stored only when its matching argument is non-negative so a caller can pass -1 to leave a field untouched.
- `0x005401A0` **AudioPlaybackDispatcher** — Audio playback dispatcher: forwards seven arguments to one of three handlers selected by an eighth selector (7 -> sub_5609DE, 8 -> sub_560A82, otherwise sub_560410), returning the selected handler's result.
- `0x00541500` **SceneStateManager** — Scene-state creation: guarded by the flag at +0x13D8, builds a 26-dword parameter block by mode, invokes vtable slot 0xB0 on the factory object at +0x1100, and increments the counter at +0x13B4 on success.
- `0x005452B0` **DListNodeList** — Doubly-linked list node removal: patches prev->next (+76) and next->prev (+72), advancing the head at +0x108 when the removed node is the head.
- `0x00545850` **SceneGraphContainer** — Clears a scene-graph flag on every node of two node lists (heads at +0x100/+0x108) and their sub-nodes via BitmaskClear and SceneGraphFlagPropagation.
- `0x005490B0` **DListChain** — Appends a node to a chain rooted at +0xEC, walking +0x4C next pointers to the tail, linking the new node back through +0x48 and zeroing +0x44/+0x4C.
- `0x0054A0A0` **FrustumCullNode** — Tests an AABB's 8 corners against 6 frustum planes and writes visibility flags to +0x4: bit 0 fully visible, bit 1 fully culled, bit 2 partial.
- `0x0054A160` **SceneModeObject** — Two-valued mode setter rewriting the word at +0xEC with mode bit 0x1000 or 0x2000 (masking the other off), returning a2 for the 4096/other branches and the rewritten word for the 0x2000 branch.
- `0x0054B2C0` **SceneGraphNode** — Propagates flag bits into the node flag at +0x3C, its child-list structure at +0x204, a related node at +0x44 (recursively), and up through parents at +0x4C while the walk flag is set.
- `0x0054C0E0` **VisibilityMaskFilter** — Visibility/permission mask filter: passes unconditionally when its own mask at +0x38 is zero, otherwise only when every set bit of +0x38 is present in the global render mask and the target object's mask.
- `0x0054C2A0` **GlobalArrayInitializer** — Fixed 256-iteration initialization loop walking global unk_8BF740 backward in 104-byte steps, invoking EmptyStub_b160 each iteration.
- `0x0054C300` **GlobalArrayInitializer** — Fixed 256-iteration initialization loop walking global dword_8C5F40 backward in 104-byte steps, invoking EmptyStub_b160 each iteration.
- `0x0054EAF0` **ParticleBufferObject** — Allocation-time initializer: zeroes the leading dwords (+0x0..+0xC, +0x1C..+0x24) and the 0x40-byte block at +0x34, returning the this pointer.
- `0x0054EB20` **ParticleBufferObject** — Allocation-time initializer: zeroes the first five dwords (+0x0..+0x10), returning the this pointer.
- `0x0054EB40` **TrianglePointTester** — Point-in-triangle test over a projected 2D plane with six selector modes; modes 4-5 delegate the three edge tests to F_2DCrossProduct, returning 1 when all edge tests pass.
- `0x0054EE90` **MathVectorOps** — Pure 2D cross-product helper: computes the z-component of the cross product of the edge vectors restricted to two coordinate-axis indices, returned as a double.
- `0x0054FA00` **NetworkPacketBuffer** — Publishes six dwords from a source struct into the entry at a slot index of a fixed-stride (116-byte) packet buffer via the descriptor at +0x1E0, marking the entry dirty through bit 3 of its flags, bounded by the descriptor count.

## Proposed classes

### BitBufferWriter

Buffered byte writer that accumulates a pending 2-byte unit and a pending-count dword, flushes them into an output buffer at a write position, and can precede payload writes with a 4-byte one's-complement checksum trailer.

Methods: `0x00539720`, `0x005397A0`

- `this+0x00000008` `byte* outBuffer` (read_write, GUESS)
- `this+0x00000014` `int outPosition` (read_write, GUESS)
- `this+0x000016AB` `uint8 pendingByteLow` (read_write, GUESS)
- `this+0x000016AC` `uint8 pendingByteHigh` (read_write, GUESS)
- `this+0x000016AD` `int pendingCount` (read_write, GUESS)

### InflateDecoder

Stateful inflate decoder that consumes a Huffman-coded bitstream with LZ77 back-references, continuing across calls via the decode state at +0, the remaining-match-length at +4, the bit accumulator at +8, and the bit count at +0x18; invalid codes surface error strings.

Methods: `0x00539870`, `0x0053A7B0`

- `this+0x00000000` `int decodeState` (read_write, DERIVED)
- `this+0x00000004` `int remainingMatchLength` (read_write, DERIVED)
- `this+0x00000008` `uint32 bitAccumulator` (read_write, DERIVED)
- `this+0x00000018` `int bitCount` (read_write, DERIVED)

### HuffmanTableBuilder

Builds canonical Huffman tables from per-symbol code lengths: counts lengths, checks canonical overflow, orders symbols, and constructs linked 16-bit decoder nodes with escape markers and a node-count cap.

Methods: `0x0053A020`


### InflateContextLoader

Provides the four static inflate context globals (two value dwords and two table addresses) to the pipeline's frame path via caller outputs.

Methods: `0x0053A630`


### VirtualSlotDispatcher

Generic indirect dispatch thunk: calls the function pointer at +0x24 with the context pointer at +0x28 of the receiver, forwarding one pass-through argument.

Methods: `0x00539F60`

- `this+0x00000024` `void* fnPointer` (read, GUESS)
- `this+0x00000028` `void* context` (read, GUESS)

### SplineCurveGenerator

Generates a normalized curve lookup table of {t, delta} pairs over the entry count at +0, storing a curve parameter at +8 and filling the buffer at +0xC by evaluating the curve function per step.

Methods: `0x0053AB80`

- `this+0x00000000` `int entryCount` (read, GUESS)
- `this+0x00000008` `float curveParameter` (write, GUESS)
- `this+0x0000000C` `float* buffer` (read_write, GUESS)
- `this+0x00000010` `int bufferWord2` (write, GUESS)

### ParamScalingObject

Parameterized object with an enable flag bit at +0, three scale parameters at +0x1C/+0x20/+0x24, and three groups of three float values at +0x28..+0x50 that are scaled when the flag bit is set; also exposes its three parameters for read-back.

Methods: `0x0053B1D0`, `0x0053B330`, `0x0053B350`

- `this+0x00000000` `uint32 flags` (read_write, DERIVED)
- `this+0x0000001C` `float scaleA` (read_write, DERIVED)
- `this+0x00000020` `float scaleB` (read_write, DERIVED)
- `this+0x00000024` `float scaleC` (read_write, DERIVED)
- `this+0x00000028` `float groupA0` (read_write, GUESS)
- `this+0x0000002C` `float groupA1` (read_write, GUESS)
- `this+0x00000030` `float groupA2` (read_write, GUESS)
- `this+0x00000038` `float groupB0` (read_write, GUESS)
- `this+0x0000003C` `float groupB1` (read_write, GUESS)
- `this+0x00000040` `float groupB2` (read_write, GUESS)
- `this+0x00000048` `float groupC0` (read_write, GUESS)
- `this+0x0000004C` `float groupC1` (read_write, GUESS)
- `this+0x00000050` `float groupC2` (read_write, GUESS)

### FieldTripletSource

Exposes three consecutive DWORD fields at +0x4/+0x8/+0xC to caller-provided output pointers, each gated on its pointer being non-null.

Methods: `0x0053B170`

- `this+0x00000004` `dword field0` (read, GUESS)
- `this+0x00000008` `dword field1` (read, GUESS)
- `this+0x0000000C` `dword field2` (read, GUESS)

### RenderUiStateObject

UI-render state object exposing four consecutive conditionally-settable state integers at +0x1508..+0x1514; each is written only when the matching argument is non-negative.

Methods: `0x0053D930`

- `this+0x00001508` `int state0` (read_write, GUESS)
- `this+0x0000150C` `int state1` (read_write, GUESS)
- `this+0x00001510` `int state2` (read_write, GUESS)
- `this+0x00001514` `int state3` (read_write, GUESS)

### AudioPlaybackDispatcher

Dispatches an audio playback request to one of three handlers selected by an eight-argument selector, forwarding seven arguments unchanged.

Methods: `0x005401A0`


### SceneStateManager

Creates scene-state objects through a vtable-bearing factory at +0x1100 (slot 0xB0), gated by the flag at +0x13D8, parameterized by a 26-dword block, and counted at +0x13B4.

Methods: `0x00541500`

- `this+0x00000000` `dword sceneStateHandle` (write, GUESS)
- `this+0x00001100` `void* sceneFactory` (read, DERIVED)
- `this+0x000013B4` `int sceneStateCounter` (read_write, DERIVED)
- `this+0x000013D8` `dword guardFlag` (read, GUESS)

### DListNodeList

Doubly-linked list container whose head is at +0x108; nodes link backward through +72 and forward through +76, and removal advances the head when the head node is removed.

Methods: `0x005452B0`

- `this+0x00000108` `Node* head` (read_write, GUESS)

### SceneGraphContainer

Container holding two scene-graph node lists (heads at +0x100/+0x108) whose nodes and sub-nodes carry flags cleared via BitmaskClear and SceneGraphFlagPropagation.

Methods: `0x00545850`

- `this+0x00000100` `Node* listHeadA` (read, GUESS)
- `this+0x00000108` `Node* listHeadB` (read, GUESS)

### DListChain

Node chain rooted at +0xEC; nodes link forward through +0x4C, backward through +0x48, with an extra zeroed word at +0x44 on every append.

Methods: `0x005490B0`

- `this+0x000000EC` `Node* head` (read_write, GUESS)

### FrustumCullNode

Cullable scene object carrying an AABB (8 corners of 3 floats at +0x24) and a visibility flag word at +0x4 updated from signed-plane tests against the camera frustum.

Methods: `0x0054A0A0`

- `this+0x00000004` `uint32 visibilityFlags` (read_write, GUESS)
- `this+0x00000024` `float[24] aabbCorners` (read, GUESS)

### SceneModeObject

Object with a two-valued mode word at +0xEC selecting mode 0x1000 or 0x2000; used by camera viewport and scene-file parsing paths.

Methods: `0x0054A160`

- `this+0x000000EC` `uint32 modeWord` (read_write, GUESS)

### SceneGraphNode

Scene-graph node that propagates flag bits to itself (flags at +0x3C), its child-list structure at +0x204, a related node at +0x44, and upward through parents at +0x4C.

Methods: `0x0054B2C0`

- `this+0x0000003C` `uint32 flags` (read_write, DERIVED)
- `this+0x00000044` `SceneGraphNode* relatedNode` (read, GUESS)
- `this+0x0000004C` `SceneGraphNode* parentNode` (read, DERIVED)
- `this+0x00000204` `void* childList` (read, DERIVED)

### VisibilityMaskFilter

Visibility filter that passes when its own mask at +0x38 is a subset of the global render mask and the target object's mask, or passes unconditionally when the own mask is zero.

Methods: `0x0054C0E0`

- `this+0x00000038` `uint32 mask` (read, GUESS)

### GlobalArrayInitializer

Runs a fixed 256-iteration per-element initialization over a global array, stepping backward 104 bytes per element and invoking the empty stub each iteration; two sibling instances target unk_8BF740 and dword_8C5F40.

Methods: `0x0054C2A0`, `0x0054C300`


### ParticleBufferObject

Fixed-size particle-buffer object whose leading dwords (+0x0..+0x10, +0x1C..+0x24) and the 0x40-byte block at +0x34 are zeroed at allocation time; grouped from two initializers sharing the VertexParticleBufferAllocator caller.

Methods: `0x0054EAF0`, `0x0054EB20`

- `this+0x00000000` `dword field0` (read_write, GUESS)
- `this+0x00000004` `dword field1` (read_write, GUESS)
- `this+0x00000008` `dword field2` (read_write, GUESS)
- `this+0x0000000C` `dword field3` (read_write, GUESS)
- `this+0x00000010` `dword field4` (read_write, GUESS)
- `this+0x0000001C` `dword field7` (read_write, GUESS)
- `this+0x00000020` `dword field8` (read_write, GUESS)
- `this+0x00000024` `dword field9` (read_write, GUESS)

### TrianglePointTester

Point-in-triangle test over a projected 2D plane: reads the point at +0x0/+0x4/+0x8, reads three triangle vertex pointers from the triangle object (+0x0/+0x4/+0x8), dispatches on a six-mode selector, and returns inside/outside via signed-area edge tests.

Methods: `0x0054EB40`

- `this+0x00000000` `float pointX` (read, GUESS)
- `this+0x00000004` `float pointY` (read, GUESS)
- `this+0x00000008` `float pointZ` (read, GUESS)
- `obj+0x00000000` `float* vertex0` (read, GUESS)
- `obj+0x00000004` `float* vertex1` (read, GUESS)
- `obj+0x00000008` `float* vertex2` (read, GUESS)

### MathVectorOps

Pure 2D cross-product helper computing the z-component of the cross product of two edge vectors restricted to two coordinate-axis indices, consumed for signed-area point-in-triangle tests.

Methods: `0x0054EE90`


### NetworkPacketBuffer

Publishes six-dword state entries into a fixed-stride (116-byte) packet buffer behind a descriptor at +0x1E0, bounded by the element count and marking entries dirty via bit 3 of their flags.

Methods: `0x0054FA00`

- `this+0x000001E0` `void* descriptorPtr` (read, DERIVED)
- `this+0x000001E4` `int elementCount` (read, GUESS)
- `this+0x000001E8` `void* dataArrayPtr` (read, DERIVED)

## Compatibility contracts

- **InflateDecodeStateMachineContract** — The inflate decoder must preserve the decode-state field at +0 and the jump-table dispatch semantics (copy/literal, length, extra bits, distance, copy, flush, error) so multi-call continuation works across the pipeline; invalid literal and distance codes must surface the error strings aInvalidLiteral_0 / aInvalidDistanc_0.
- **ChecksummedByteWriteContract** — WriteChecksummedBytes flushes pending bytes through UnicodeBufferFlusher and appends a 4-byte integrity trailer ordered low, high, one's-complement low, one's-complement high; a replacement writer must reproduce this byte order for compatible output.
- **PacketEntryDirtyFlagContract** — Packet entries use a 116-byte stride with a flags word whose bit 3 marks an entry dirty; the descriptor count bounds the slot index. A replacement must keep the entry layout and the dirty-bit protocol.
- **SceneGraphFlagPropagationContract** — Flag propagation must OR node flags at +0x3C, child-list flags, related-node flags at +0x44, and walk parents at +0x4C, terminating when the parent chain ends.

## Unresolved

- Meaning of the count threshold (8) in the pending-count branch of UnicodeBufferFlusher is not grounded; both branches clear the pending state identically.
- WriteChecksummedBytes operates on an untyped growable buffer (v5[2] base, v5[5] cursor) and a mode field at this+0x16A7; buffer capacity and the field semantics are not evidenced.
- Whether the flushed byte stream is genuine UTF-16/Unicode or a byte protocol named after the flusher is unresolved.
- The raw source of InflateHuffmanDecodeCont is truncated mid-function, so the full per-state bit orders and copy loops are not fully evidenced.
- The exact Huffman table encoding behind dword_5DBB90 is not evidenced in this packet.
- The 0x20 terminal flag and the window-base/boundary roles of a5[10]/a5[11] in HuffmanLZ77Decode are DERIVED-level interpretations; the a1/a2 mask-table indices are unresolved.
- HuffmanLZ77Decode threads its bit/output state through caller-supplied structures (a5[7]/a5[8]/a5[13], a6[0..2]) rather than a stable this; those offsets are not attached to the InflateDecoder class fields.
- VirtualSlotDispatcher's receiver object and the concrete virtual method at vtable slot +0x24 are unknown; the callee is indirect so the callgraph lists no static callee.
- sub_53A020's parameters a4/a5/a6/a7/a8/a9/a10 outside the Huffman-table reading, the 80/96 offsets applied to the a5 byte values, and the 0x5A0 node cap are not established.
- The spline curve parameter at SplineCurveGenerator+0x8, the endpoint words at +8/+12 of the final slot, and the curve data layout are unproven.
- ParamScalingObject's three float groups and the returned-flags contract with caller sub_558E70 have no named semantics; the un-scaled float slots between groups are untouched.
- ThreeFieldBatchGetter (0x0053B170) reads +0x4/+0x8/+0xC and shares caller sub_558E70 with ParamScalingObject, but common ownership with the +0x1C/+0x20/+0x24 object is not proven, so it is kept as a separate class.
- RenderUiStateObject's four state fields at +0x1508..+0x1514 have no named role beyond being dword state slots.
- DispatchAudioPlayback's selector (a8) is present but absent from each callee's signature; the selector likely encodes a playback mode consumed indirectly. Argument semantics are unevidenced.
- SceneStateManager's 26-dword parameter block layout, the three mode groups, and the guard flag at +0x13D8 are unknown; the literals 1065353216/-1082130432 are not decoded per evidence rules.
- DListNodeList (+0x108 head, node links +72/+76) and DListChain (+0xEC head, node links +0x48/+0x4C) both serve caller ArithmeticComparison_9170 but use different node layouts; whether they are the same list type is unproven.
- FrustumCullNode's frustum plane layout at a2+260 is inferred from pointer arithmetic only; the +0x4 visibility bit meanings are proposed from existing analysis, not independently confirmed.
- SceneModeObject's mode bits at +0xEC have no reader evidence in the packet; the field is only written by 0x0054A160 within this packet.
- SceneGraphNode fields +0x214/+0x218 are listed by the deterministic extractor but do not appear in the raw source; their role in the traversal is unclear.
- Bitmask_Permission_Check reads the target mask at a2+132 without a field evidence entry; the global render-mask role of dword_8B8E34 is proposed from existing analysis.
- GlobalArrayInitializer's stepped pointer is never passed to EmptyStub_b160; whether the callee reads it via another path or the pointer is vestigial is unknown, and the 104-byte stride semantics are unproven.
- ParticleBufferObject merges two initializers (0x0054EAF0, 0x0054EB20) based on the shared VertexParticleBufferAllocator caller (0x0054F830); same-class ownership is a grouping proposal, not proven.
- TrianglePointTester's projection plane and winding direction per selector are DERIVED; packet-listed fields this+0xC/+0x10 are never read in the raw source.
- NetworkPacketBuffer's six copied dwords and the dirty-bit-3 protocol semantics depend on an unevidenced network/state protocol.
- The two FixedArrayInitializationLoop sibling loops (0x0054C2A0 over unk_8BF740, 0x0054C300 over dword_8C5F40) are grouped as one class by identical shape; their relationship is unproven.
- LoadFourGlobalPtrs accepts an unused parameter a5 and the semantic role of the four globals (constants vs table pointers) is not established.
