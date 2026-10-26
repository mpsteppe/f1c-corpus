# RuntimeObjectSupport

Scope: `generic_runtime_objects`  
Trust: `GUESS`

This scope groups 26 generic runtime-object functions into defensible clusters. The largest cluster is a zlib-style compression subsystem: CompressionStreamContext (initialize, cleanup, guarded deferred-call teardown, compression-context init) plus the InflateStateMachineDecoder that drives a 14-state inflate wire decoder through a jump table. A codec pipeline cluster (CodecPipelineObject frame encoder + CodecSubObject teardown) shares a cleanup-callback layout with the compression context at this+0x1C/0x24/0x28, suggesting the compression context and codec sub-object may be the same runtime object (unconfirmed). A string-table cluster registers and prunes a 32-entry/132-byte global table. The renderer/font name-lookup family shares a conditional lookup-then-delegate shape over a wide-string linked list. The remaining functions are small math helpers (SLERP, QR decomposition, float-struct/transform setters), resource free helpers, an audio-emitter allocator, and an MAS-loader wrapper. Most owners are UNKNOWN; only the inflate decoder, codec sub-object and quaternion math library have DERIVED owner labels from the packet.

## Function roles

- `0x00535660` **CompressionStreamContext** — Teardown of a guarded deferred-call record: runs a guarded triple-slot vtable dispatch (TripleVTableCall on handler+20) and the stored fastcall callback with (this+0x28, this+0x1C), then clears the handler pointer this+0x1C; returns -2 when this or the stored handler/callback pointer is null, 0 on success. Invoked from file-handle teardown and two other sites.
- `0x005356A0` **CompressionStreamContext** — Stream-context initializer: validates version magic (a113_0[0] at global 0x5DA7A0, a4 == 56), resets the context flag this+0x18, installs default allocator/deallocator callbacks (this+0x20/0x24), allocates the 24-byte work block via the allocator, normalizes/validates the block-size exponent (8..15), allocates the 1<<a2 multi-block buffer, and finalizes via ArithmeticComparison_5620; returns -6/-4/-2 on validation or allocation failure.
- `0x005357E0` **InflateStateMachineDecoder** — zlib-style inflate state-machine driver: dispatches over the per-stream state block through jump table 0x535BCC; validates compression header (method 8, window bound), header checksum (mod 0x1F), optional dictionary-size field and trailer checksum, drives the inflate core sub_537110, and resets the sub-block state via StateResetWithCallback on stream end. Returns inflate status codes (-5/-3/-2/1).
- `0x00535C10` **CompressionStreamContext** — Compression-stream context initializer (zlib-style deflate/inflate): validates version string (off_5DA818, size 56), installs default allocator/deallocator callbacks, normalizes a2 == -1 to level 6 and takes the absolute window-bits value, validates parameters (mem level 1..9, method 8, window bits 8..15, level <= 9, strategy <= 2), allocates the 5809-byte state block and three work buffers via the allocator callback, and finalizes via ConditionalMultiFieldReset; on failure stores the off_5DA834 error token and returns -4.
- `0x00535E80` **CodecPipelineObject** — Frame/chunk encoder: validates the encoder object, operation type (0..4) and buffers; writes big-endian audio header words for codec type 42 and sets codec type 113; copies compressed buffers via BufferCopyWithSizeTracking; dispatches to the codec handler selected from funcs_536014 by 3*(codec+122); completes frames via BitstreamEncoder/BitstreamWriteBits. Returns 0 on success, -2/-5 on validation failure with an error pointer stored at a1+24.
- `0x005361D0` **CodecSubObject** — Codec sub-object teardown: validates this and the sub-object pointer at this+0x1C, requires the mode tag at *(this+0x1C)+0x4 to be 42/113/666, conditionally invokes the cleanup callback at this+0x24 (with this+0x28) for each non-zero flag at *(this+0x1C)+0x8/+0x2E/+0x36/+0x3A, makes one unconditional final cleanup call, zeroes this+0x1C, and returns 0xFD (253) for mode 113 else 0.
- `0x00536E90` **UnknownObject** — CRC-32 computation over a byte buffer using the dword_5B7860 256-entry lookup table; unrolled 8-byte main loop plus byte tail loop, returns the bitwise complement of the final state; null data pointer returns 0.
- `0x0053AB70` **UnknownObject** — Single-field free helper: reads the buffer pointer at this+0xC (this[3]), frees it through FreeWrapper_7bcf and returns that call's result unchanged; unconditional, no branches; called by TwoListCleanup during two-list teardown.
- `0x0053AD50` **UnknownObject** — Multi-field destructor cleanup: restores the destructed-state vtable pointer at this+0x0 to off_5B8910, frees the three heap buffers at this+0x10/0x20/0x30 via FreeWrapper_7bcf, then invokes EmptyStub_0170; called by GlobalResourceCleanup.
- `0x0053B130` **FloatTransformStruct** — Constructor/initializer for a 40-byte float-bearing structure: zeroes the first seven dword fields, sets the last three dword fields to 1.0f, calls Identity44MatrixInit for the embedded 4x4 matrix, and returns the object; called from seven sites including matrix/vertex transform helpers.
- `0x0053B200` **Transform3D** — Per-frame transform setter (thiscall): copies three inputs into primary fields 0x4/0x8/0xC, mirrors them into 0x58/0x5C/0x60, sets 0x64 to 1.0f (bit pattern 1065353216), and returns the middle input; interpreted as position/scale component initialization for a 3D transformation object.
- `0x0053B490` **UnknownObject** — Identity transform (__thiscall): returns the this pointer unchanged with no other effect; no fields, globals, guards or callees of its own; likely a vtable placeholder, no-op hook or deliberately trivial override.
- `0x0053B4A0` **UnknownObject** — Empty void stub (nullsub): no instructions beyond the implicit return; placeholder body for a virtual-table entry or an unimplemented hook point.
- `0x0053B5B0` **QuaternionMathLibrary** — Quaternion spherical linear interpolation (SLERP): 4-component dot product, shortest-path negation when dot is negative, sin-based blend above the 0.02 epsilon (via FloatFunctionPassThrough) else linear blend; writes the interpolated quaternion to this[0..3].
- `0x0053B6F0` **UnknownObject** — QR decomposition of a 3x3 double matrix a1 via Givens rotations over at most 50 iterations: initializes a3 to a 3x3 identity, copies a1 into working buffers and a2, sums off-diagonal magnitudes for early exit, applies rotation tolerances and Givens coefficients, accumulates eigenvector/sum contributions back through a2; used by sub_549470 and BoundingBoxComputationFromVertexData on the per-frame path.
- `0x0053C680` **UnknownObject** — Trivial setter: copies three __stdcall arguments into three consecutive writable globals dword_8B8F08/0C/10 and returns the first argument unchanged; no guards, calls or field access; called by VidMan_Enter.
- `0x0053C6F0` **StringTableRegistry** — String-table registration: guards on empty input and table capacity (32 entries), copies and transforms the input via sub_589901, dedupes by strcmp over 132-byte entry stride, inserts at the front (shifting entries via ArithmeticComparison_c6b0 when needed), sets flag bit 0x4000 on dword_8B5A38 and increments the count dword_8B8E30; called from SceneFileTopLevelParser.
- `0x0053CA00` **StringTableRegistry** — String-table pruning: stages up to 32 entries into a 4224-byte local buffer, compacts surviving entries (flag bit 0x400 clear) back to the front of the global table at dword_8B5A38, zeroes trailing slots up to the boundary dword_8B6AB8, and stores the surviving count into dword_8B8E30; called by StringMatchWithFlagSet.
- `0x0053CAF0` **UnknownObject** — Conditional resource cleanup: runs TwoListCleanup(a1), and when a1 is non-null runs EmptyStub_7470(a1) then FreeWrapper_7bcf(a1); always returns 0; caller ReleaseSceneNode suggests scene-node resource teardown (not established).
- `0x0053CB20` **UnknownObject** — Audio-emitter allocate-and-register: allocates a 60-byte object via OperatorNewNhMallocWrapper, creates an audio emitter via AudioEmitterCreate, stores it at the caller output slot this+0x0, then attempts registration through sub_5429B0(a2,0,0,a3,a4); on registration success (non-zero) discards the emitter (EmptyStub_7470 + FreeWrapper_7bcf) and returns -1, otherwise returns 0 leaving the emitter intact.
- `0x0053CE10` **UnknownObject** — MAS-file loader wrapper: calls sub_53CBC0(a1, a2) and returns its result; on success (result == 0) and a1 non-null, dereferences a1 and sets bit 3 (0x8) in the flags dword at obj+0x114 of the loaded object, marking error-handling state.
- `0x0053D1F0` **UnknownObject** — Wide-string linked-list name lookup: loads the global head pointer dword_8B8E20 and walks nodes via the next pointer at node+2160, comparing each node name at node+20 against the input string (strcmp); returns the first match or 0 when the list is empty, the name is absent, or the chain ends; used by ten renderer/font callers.
- `0x0053D260` **UnknownObject** — Font/surface dispatch: looks up a font surface handle by name via WideStringLinkedListSearch(a1); when non-null applies three setter calls (FieldSetterAt0x48, MaskedFieldSetter, SwitchBasedParameterFieldSetWithFlags whose result is returned); when the lookup fails returns the null lookup result without applying any setter.
- `0x0053D2B0` **UnknownObject** — Guarded delegation: searches the wide-string linked list with WideStringLinkedListSearch(a1); when the search yields non-zero, delegates a2/a3 to TwoFieldSetter_3050 and returns that result, otherwise returns the zero search result; used by sub_4F8D70.
- `0x0053D2E0` **UnknownObject** — Conditional delegate: searches the wide-string linked list for a1; on a match forwards a2..a5 to sub_553070 and returns its result, otherwise returns the search result unchanged; appears to be a UI message/event dispatch shim.
- `0x0053D310` **UnknownObject** — Conditional dispatcher: searches the wide-string linked list with WideStringLinkedListSearch(a1); on success calls sub_5531F0(a2, a3, a4, 0) and returns its result, otherwise returns the zero search result; caller is sub_4F9480.

## Proposed classes

### CompressionStreamContext

zlib-style deflate/inflate stream context: holds allocator/deallocator callbacks, the current block pointer and work/state-block fields; provides stream initialization (decompression and compression variants), a guarded deferred-call cleanup, and a block-size exponent gate.

Methods: `0x00535660`, `0x005356A0`, `0x00535C10`

- `this+0x00000018` `uint32 ContextFlag` (read_write, GUESS)
- `this+0x0000001C` `void* BlockPointer` (read_write, GUESS)
- `this+0x00000020` `void*(*)(void*,uint32,uint32) AllocatorCallback` (read_write, GUESS)
- `this+0x00000024` `void(*)(void*,void*) DeallocatorCallback` (read_write, GUESS)
- `this+0x00000028` `void* AllocatorContext` (read, GUESS)
- `this+0x0000002C` `int32 BlockSizeExponent` (write, GUESS)
- `this+0x00000030` `void* WorkBufferPointer` (read_write, GUESS)

### InflateStateMachineDecoder

Per-stream inflate state machine (zlib-style): validates the compression header, header checksum, optional dictionary size, drives the inflate core sub_537110, resets the sub-block state on stream end, and checks the trailer checksum; error paths arm one of five message strings.

Methods: `0x005357E0`


### CodecPipelineObject

Frame encoding pipeline state: binds the caller object and operation type, writes big-endian audio header words, copies compressed buffers with size tracking, dispatches to per-codec handlers via funcs_536014, and finalizes frames through the bitstream encoder; final-state marker 666.

Methods: `0x00535E80`


### CodecSubObject

Per-codec sub-object with a mode tag (42/113/666) and flagged resource holders; teardown conditionally releases each flagged resource through the owning cleanup callback and makes one unconditional final release of the sub-object itself.

Methods: `0x005361D0`

- `this+0x0000001C` `void* SubObjectPointer` (read_write, GUESS)
- `this+0x00000024` `void(*)(...) CleanupCallback` (read, GUESS)
- `this+0x00000028` `void* CleanupContext` (read, GUESS)
- `*(this+0x1C)+0x00000004` `uint32 CodecModeTag` (read, GUESS)
- `*(this+0x1C)+0x00000008` `uint32 FlaggedParameter` (read, GUESS)
- `*(this+0x1C)+0x0000002E` `uint16 CleanupFlag0x2E` (read, GUESS)
- `*(this+0x1C)+0x00000036` `uint16 CleanupFlag0x36` (read, GUESS)
- `*(this+0x1C)+0x0000003A` `uint16 CleanupFlag0x3A` (read, GUESS)

### QuaternionMathLibrary

Quaternion math helpers: spherical linear interpolation with shortest-path handling and small-angle linearization.

Methods: `0x0053B5B0`

- `this+0x00000000` `float ResultQuaternionW` (write, GUESS)
- `this+0x00000004` `float ResultQuaternionX` (write, GUESS)
- `this+0x00000008` `float ResultQuaternionY` (write, GUESS)
- `this+0x0000000C` `float ResultQuaternionZ` (write, GUESS)

### StringTableRegistry

Global 32-entry string table with 132-byte entries: registration with empty/full guards, sub_589901 transform, strcmp dedup and front insertion with 0x4000 flag, and pruning of flag-0x400 entries with tail clearing to the table boundary.

Methods: `0x0053C6F0`, `0x0053CA00`


### Transform3D

3D transformation object: per-frame setter writes position/scale components into primary fields and mirrored reference fields with an identity-scale (1.0f) default; role of the mirrored pair is inferred from caller context.

Methods: `0x0053B200`

- `this+0x00000004` `float PrimaryX` (write, GUESS)
- `this+0x00000008` `float PrimaryY` (write, GUESS)
- `this+0x0000000C` `float PrimaryZ` (write, GUESS)
- `this+0x00000058` `float MirroredX` (write, GUESS)
- `this+0x0000005C` `float MirroredY` (write, GUESS)
- `this+0x00000060` `float MirroredZ` (write, GUESS)
- `this+0x00000064` `float ScaleOrW` (write, GUESS)

### FloatTransformStruct

40-byte float-bearing structure with an embedded identity 4x4 matrix: initialization zeroes the leading seven dwords and sets the trailing three to 1.0f; the concrete placement of the matrix is not evidenced by this function.

Methods: `0x0053B130`

- `this+0x00000000` `float ZeroedField0` (write, GUESS)
- `this+0x00000004` `float ZeroedField1` (write, GUESS)
- `this+0x00000008` `float ZeroedField2` (write, GUESS)
- `this+0x0000000C` `float ZeroedField3` (write, GUESS)
- `this+0x00000010` `float ZeroedField4` (write, GUESS)
- `this+0x00000014` `float ZeroedField5` (write, GUESS)
- `this+0x00000018` `float ZeroedField6` (write, GUESS)
- `this+0x0000001C` `float IdentityFieldA` (write, GUESS)
- `this+0x00000020` `float IdentityFieldB` (write, GUESS)
- `this+0x00000024` `float IdentityFieldC` (write, GUESS)

## Compatibility contracts

- **StreamInitVersionGate** — Stream context initialization validates a version string whose first byte equals global 0x5DA7A0[0] ('1.13') and requires version size 56; failures return -6. Default allocator (0x536FD0) and deallocator (0x536FF0) callbacks are installed when absent. The block-size exponent must be in 8..15; a 24-byte work block and a 1<<a2 multi-block buffer are allocated through the allocator callback. Compression init uses the off_5DA818 magic and stores the off_5DA834 error token on allocation failure.
- **InflateWireProtocol** — The inflate decoder speaks a zlib-style wire format: CM/FLG header with compression method 8 and a window-size bound, header checksum modulo 0x1F, optional FDICT flag with a 4-byte big-endian dictionary-size field, and a 4-byte stream trailer that must equal the computed checksum. Dispatch is driven by the jump table at 0x535BCC; error strings are armed from globals 0x5DA7A8/0x5DA7B8/0x5DA7D0/0x5DA7E8/0x5DA7FC. Return codes: -5 intermediate, -3 stream error, -2 need dictionary/null handle, 1 stream end.
- **CodecOperationDispatch** — EncodeFrame accepts operation types 0..4. Codec type 42 emits big-endian audio header words (composed from codec+122/38/98, aligned to 0x1F) and sets codec type 113. The handler table funcs_536014 at 0x5B77F0 is indexed by 3*(codec+122); handlers returning 2 or 3 mark codec type as 666 (final state). Validation failures store an error pointer (from globals 0x5DA82C/0x5DA838) at a1+24 and return -2/-5.
- **GlobalStringTableLayout** — Global string table at 0x8B5A38/0x8B5A3C holds up to 32 entries of 132 bytes; the live count is dword_8B8E30 and the flag word dword_8B5A38 bit 0x4000 is set on every insertion. Entries are compared with strcmp at the 132-byte stride. Pruning compacts entries with flag bit 0x400 clear to the front and zeroes the tail up to the table boundary 0x8B6AB8, updating the count.
- **FontSurfaceNameList** — Renderer/font name lookup walks a singly-linked list whose head is global dword_8B8E20; each node carries its name string at +20 and its next-node link at +2160. Lookup failure returns 0 and short-circuits the setter chain. The four LookupThenDelegate shims all consume this list and forward caller arguments to per-name setters on success.
- **HeapReleaseContract** — All heap object/buffer teardown funnels through FreeWrapper_7bcf (0x587BCF); heap allocation uses OperatorNewNhMallocWrapper (0x587C03). Destructors follow a vtable-swap pattern: restore the destructed-state vtable (off_5B8910) before freeing owned buffers. Single/multi-buffer free helpers and the audio-emitter allocator all conform to this contract.
- **CRC32Table** — CRC-32 computed over a byte buffer using the dword_5B7860 256-entry lookup table, seeded from the initial value argument; the result is the bitwise complement of the final state and a null data pointer returns 0.

## Unresolved

- GuardedFunctionCallCleanup record semantics are DERIVED: this+0x1C is read as a handler/context pointer, this+0x24 as a stored callback and this+0x28 as its first argument; the packet flags it as a structural twin of sub_5179A2, consistent but not confirmed. On the stream context this+0x1C/0x24/0x28 double as block pointer / deallocator / allocator context.
- The field this+0x30 is read by GuardedFunctionCallCleanup per the packet but does not appear in its raw body; the purpose is unknown. Work-block sub-offsets are flattened by the pipeline as this+0x28/0x2C/0x30, overlapping the allocator-context field at this+0x28; the concrete work-block layout is unknown.
- CompressionStreamContext and CodecSubObject share the this+0x1C/0x24/0x28 field layout, and CompressionStreamInitializer's failure path calls CodecSubObjectTeardown on the same receiver; the compression context and codec sub-object may be the same runtime object, but common ownership is not proven.
- The InflateStream role of the state+12 flag consumed after StateResetWithCallback versus the window-size field at state+16 is not fully determined; the a2 flush-mode contract is under-specified (only value 4 is evidenced).
- The semantic roles of ArithmeticComparison_5620 (reset after allocation) and GuardedFunctionCallCleanup (teardown) are inferred from position in this flow; callers sub_534B10 and ArgumentReorderWrapper frame 0x5356A0 as a stream initializer but their usage is outside this function.
- EncodeFrame codec field layout (codec+4/20/24/30/38/58/66/98/106/122), the a1 caller-buffer offsets (12/16/24/48/50), the funcs_536014 handler-slot layout, and codec constants 42/113/666 are named by role only; no owner or field evidence is available. Callee 0x536300 (DecompressionBufferFlush) is recorded but does not appear as an explicit call in the body.
- The content of the off_5DA834 error pointer and of off_5DA82C/off_5DA838 is not established.
- QRDecompose3x3 read-only globals (0x59E420/0x59E430/0x59E880/0x59EA20/0x5B8970) have no visible direct use in the body; the exact meaning of each output matrix (eigenvalues vs eigenvectors) and the convergence-tolerance constants are not independently grounded.
- QuaternionSphericalInterpolation read-only globals (0x59E43C/0x59E440/0x59E6EC) are flagged by packet facts but appear nowhere in the raw body; the 0.02 epsilon and 1.0 constants match the small-angle cut-off but are not evidenced.
- The mirrored field pair of SetPositionScaleAndOne (0x4/0x58, 0x8/0x5C, 0xC/0x60) and whether the 1.0f at 0x64 is a scale or a homogeneous w component cannot be decided from this packet.
- FloatStructInitializer's embedded 4x4 matrix placement is not shown; Identity44MatrixInit is called with no visible argument. The F_10 prefix suggests a class-scoped identifier, unconfirmed.
- String-table entry internal layout (132 bytes) is inferred from the strcmp stride and the 33-DWORD copy step; whether dword_8B5A38 and byte_8B5A3C alias the same allocation is not confirmed. The 0x400/0x4000 flag meanings and the differing return-value contract by path are unresolved.
- cleanupResourceWithConditionalFree: why a null a1 still receives TwoListCleanup while the free path is null-guarded is unexplained; TwoListCleanup (0x547420) and EmptyStub_7470 (0x557470) semantics and the a1 object type are unknown.
- AudioEmitterAllocTryRegister frees the freshly created emitter on registration success and keeps it on failure, the inverse of a typical init-on-failure pattern; the intended lifecycle and the meaning of the two zero literals passed to sub_5429B0 are unverifiable.
- ErrorHandlerSet: the object sub_53CBC0 allocates into *a1 and the meaning of the bit-3 flag at obj+0x114 (error-handling state) are inferred from prior analysis.
- WideStringLinkedListSearch node layout is unknown beyond the name at +20 and the next link at +2160; the 'WideString' canonical label conflicts with the raw char* strcmp, so the actual string encoding is unverifiable.
- IdentityThis (0x53B490) and EmptyStub (0x53B4A0) have unknown purposes: vtable placeholders, intentionally empty callbacks, or stripped bodies.
- GuardedDelegation/ConditionalStringDelegate/FontSurfaceLookupDispatch setter target objects and the parameter semantics of the setter callees (0x552FC0/0x552FD0/0x552FF0/0x553050/0x553070/0x5531F0) are not evidenced in this packet; the UI message-delegate role of 0x53D2E0 is inferred from its callers.
- CRC-32 generator polynomial for the dword_5B7860 table is not evidenced; QR decomposition relies on FPU/runtime helpers only.
- ThreeGlobalSetter: purpose and consumers of the consecutive globals 0x8B8F08/0C/10 and the return-value semantics are caller-defined.
