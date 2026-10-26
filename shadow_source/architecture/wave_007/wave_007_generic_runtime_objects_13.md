# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This packet groups 35 loosely-coupled runtime helper functions. Seven texture/vertex decoders (0x00509DE6, 0x00509E85, 0x00509F0C, 0x0050A067, 0x0050A0F0, 0x0050A2B4, 0x0050A34B) share one field layout (source base this+0x18, two strides this+0x1050/0x1054, element count this+0x1058, post-process flag this+0x10) and emit float RGBA with an optional ContactManifoldCleanup pass (0x00507845). Two buffer-read helpers (0x00501711, 0x005020BF) advance/copy through two-dword read trackers held at this+0x14 and this+0x54, with a longjmp underflow error. Three surface-format functions (0x00500680 table lookup, 0x005006A4 FourCC decode, 0x005029E5 BMP header gate) serve DDS/DDSTexture negotiation. ImageBoxFilterCompositor (0x00503533 scalar, 0x00503772 MMX, 0x00503888 function-pointer selector) performs 2x2 box downsampling. Five math helpers (0x0050C042 tolerance gate, 0x0050C0A6, 0x0050C15E, 0x0050C2E3 interpolations, 0x0050C5D0 matrix-vector) are pure computation. ObjectFreeRouter (0x00500FAE, 0x00502C1F, 0x0050B244, 0x0050B425, 0x0050B82B) covers destructor/conditional-free paths through FreeWrapper_7bcf (0x00587BCF) and ComplexDestructorWithLoop (0x00506FD9). DispatchTableRouter (0x0050C134, 0x0050C20D, 0x0050C2A6, 0x0050C2B3, 0x0050C2B9, 0x0050C48C, 0x0050C5BD, 0x0050C636, 0x0050C647) issues a sub_50FEA7(1) preamble then calls a global function-pointer slot (off_5D77E4..off_5D7894) whose target is swapped at runtime. 0x004FB900 is a lone forwarding wrapper. All groupings are DERIVED proposals; per-function owners remain UNKNOWN in the packet.

## Function roles

- `0x004FB900` **UnknownObject** — Forwarding wrapper: calls sub_4FCA50 with the global unk_8AFEC0 as its argument and returns the result; no local state, guards, or control flow.
- `0x00500680` **DDSTextureFormatResolver** — Linear search over a stride-9-element ID table (flt_5AD508..off_5D7150) returning the matched entry pointer or the fallback unk_5AD4E0 when empty/not-found; serves DDSTextureSurfaceCreation.
- `0x005006A4` **DDSTextureFormatResolver** — FourCC-to-format-identifier decoder: maps 909200416->50, 909200449->51, 909201952->20, 909201985->21, identity otherwise; used by DirectXSurfaceFormatNegotiation.
- `0x00500FAE` **ObjectFreeRouter** — Conditional teardown helper: calls ArithmeticComparison_0f55(this) then FreeWrapper_7bcf(this) when bit 0 of a2 is set; returns this.
- `0x00501711` **BufferedStreamReader** — Buffer read-track advance: loads the tracker pointer at this+0x14, increments its +0 dword by a2, decrements its +4 dword by a2, returns the tracker.
- `0x005020BF` **BufferedStreamReader** — Tracked binary read: copies a3 bytes from the tracker at this+0x54 into a2, raising a longjmp 'read error' via GuardedCallWithLongjmp on underflow; advances tracker and returns a3.
- `0x005029E5` **DDSTextureFormatResolver** — BMP header gate: on valid header (len>=14, 0x4D42 signature, declared size<=len) hands payload at +14 (len-14) to DDSTextureFormatValidationDecoding; otherwise returns error -2147467259.
- `0x00502C1F` **ObjectFreeRouter** — Trivial forwarding wrapper: dereferences this[0] and passes it to FreeWrapper_7bcf, returning that call's result.
- `0x00503533` **ImageBoxFilterCompositor** — Scalar 2x2 box-average image compositor (channel-separated byte math, rounding 131074, carry base 0x00800080); misalignment fallback of the MMX wrapper.
- `0x00503772` **ImageBoxFilterCompositor** — MMX-vectorized 2x2 box-average compositor; dispatches to scalar ImageBlendingCompositing (0x00503533) when the row width is not 4-byte aligned.
- `0x00503888` **ImageBoxFilterCompositor** — Function-pointer selector: installs sub_503772 into off_5D76C0/off_5D76C4 when sub_50FC7D() is true, else ImageBlendingCompositing/F_2DImageBoxFilter (0x0050368A); then calls the primary pointer off_5D76C0.
- `0x00509DE6` **TextureDecodeFormat** — Decodes 4-bit-per-channel packed color texels to float RGBA using the shared layout fields; optional ContactManifoldCleanup post-process gated by this+0x10.
- `0x00509E85` **TextureDecodeFormat** — Decodes 8-bit palette-indexed vertex color with an 8-bit alpha byte to float RGBA; alpha scaled by 0.0039215689 (flt_59E460); optional post-process gated by this+0x10.
- `0x00509F0C` **TextureDecodeFormat** — Converts 8-bit palette-indexed pixels to float RGBA via the struct's embedded palette table; optional post-process gated by this+0x10.
- `0x0050A067` **TextureDecodeFormat** — Unpacks nibble-paired byte stream to float RGBA (low nibble to RGB, high nibble to alpha, scaled 0.06666667); optional post-process gated by this+0x10.
- `0x0050A0F0` **TextureDecodeFormat** — Decompresses packed 8-bit XY vertex positions to float RGBA (X,Y scaled 0.0078125, Z=0, A=1); optional post-process gated by this+0x10.
- `0x0050A2B4` **TextureDecodeFormat** — Decompresses packed 4-byte-per-element vertex data to float RGBA (each byte scaled 0.0078125); optional post-process gated by this+0x10.
- `0x0050A34B` **TextureDecodeFormat** — Decodes signed int16 XY vertex pairs to float RGBA (X,Y scaled 0.000030517578, Z=0, A=1); optional post-process gated by this+0x10.
- `0x0050B244` **ObjectFreeRouter** — Mixed teardown (__userpurge): runs ComplexDestructorWithLoop over a2 then conditionally frees a1 via FreeWrapper_7bcf when bit 0 of a3 is set; returns a1.
- `0x0050B425` **ObjectFreeRouter** — Thunk trampoline forwarding the this pointer to VtableSetFreeChild; invoked from DestructorWithSelfFree (0x0050B75F).
- `0x0050B82B` **ObjectFreeRouter** — Thunk trampoline (__usercall, a1 in EBP) forwarding a1 to ComplexDestructorWithLoop; invoked from DtorWithCleanup (0x0050B7AF).
- `0x0050C042` **MathUtil** — Float near-zero tolerance check: returns TRUE when the double-precision difference of a1,a2 lies inside [-1.1920929e-7, +1.1920929e-7]; used as a pre-normalize gate by normalization/rotation routines.
- `0x0050C0A6` **MathUtil** — 2-component cubic Hermite interpolation (four standard basis functions, endpoint/tangent pairs in a2..a5, t=a6); no branches or callees.
- `0x0050C134` **DispatchTableRouter** — Dispatch trampoline: sub_50FEA7(1) preamble then indirect call through off_5D7884 with six args forwarded; returns the callee's result.
- `0x0050C15E` **MathUtil** — Catmull-Rom Hermite cubic spline for a 2-component vector (four control points a2..a5, t=a6, 0.5 scale); no branches or callees.
- `0x0050C20D` **DispatchTableRouter** — Dispatch trampoline: sub_50FEA7(1u) preamble then indirect call through off_5D7888 with six args forwarded; returns the callee's result.
- `0x0050C2A6` **DispatchTableRouter** — Dispatch wrapper (cdecl, no args): sub_50FEA7(1u) preamble then indirect call through off_5D77E4; returns the callee's result.
- `0x0050C2B3` **DispatchTableRouter** — Bare thunk: indirect call through the global function pointer off_5D77E4 with no forwarded args; invoked by rotation-matrix and plane geometry routines.
- `0x0050C2B9` **DispatchTableRouter** — Dispatch trampoline: sub_50FEA7(1u) preamble then indirect call through off_5D788C with six args forwarded; returns the callee's result.
- `0x0050C2E3` **MathUtil** — 3-component cubic Hermite/Bezier interpolation (four basis coefficients, four input vectors a2..a5, t=a6); no branches or callees.
- `0x0050C48C` **DispatchTableRouter** — Dispatch trampoline: sub_50FEA7(1u) preamble then indirect call through off_5D7894 with six args forwarded; returns the callee's result.
- `0x0050C5BD` **DispatchTableRouter** — Forwarding thunk: indirect call through the global function pointer off_5D77F0 with no args; called by color-matrix/blend routines.
- `0x0050C5D0` **MathUtil** — Transformed-vector computation: each output component is a three-term sum of products over stride-4 matrix elements of a3 against a2; writes a1[0..2], returns a1.
- `0x0050C636` **DispatchTableRouter** — Dispatch wrapper (cdecl, no args): sub_50FEA7(1u) preamble then indirect call through off_5D7800; returns the callee's result.
- `0x0050C647` **DispatchTableRouter** — Dispatch wrapper (cdecl, no args): sub_50FEA7(1u) preamble then indirect call through off_5D7804; returns the callee's result.

## Proposed classes

### BufferedStreamReader

Buffered binary stream read helper: advances a two-dword read tracker and copies bytes out with a longjmp underflow error path. Grouping proposal; the two tracker pointers sit at different offsets on the same this base.

Methods: `0x00501711`, `0x005020BF`

- `this+0x00000014` `void* read_tracker_ptr` (read, GUESS)
- `this+0x00000054` `void* read_tracker_ptr_b` (read, GUESS)

### BufferReadTracker

Two-dword buffer read tracker: current read position at +0, remaining byte count at +4. Same layout at two different owner slots (this+0x14 and this+0x54); offsets are kept per-base and not merged.

Methods: 

- `*(this+0x14)+0x00000000` `dword read_position` (read_write, GUESS)
- `*(this+0x14)+0x00000004` `dword remaining_bytes` (read_write, GUESS)
- `*(this+0x54)+0x00000000` `dword read_position` (read_write, GUESS)
- `*(this+0x54)+0x00000004` `dword remaining_bytes` (read_write, GUESS)

### TextureDecodeFormat

Owns source-texture layout (source base at +0x18, two strides at +0x1050/+0x1054, element count at +0x1058) and a post-process flag at +0x10 for packed color/vertex decoders that emit float RGBA. Shared field set evidenced across seven decoders.

Methods: `0x00509DE6`, `0x00509E85`, `0x00509F0C`, `0x0050A067`, `0x0050A0F0`, `0x0050A2B4`, `0x0050A34B`

- `this+0x00000010` `dword post_process_flag` (read, DERIVED)
- `this+0x00000018` `void* source_data_ptr` (read, DERIVED)
- `this+0x00001050` `int stride_a2` (read, GUESS)
- `this+0x00001054` `int stride_a3` (read, GUESS)
- `this+0x00001058` `int element_count` (read, GUESS)

### DDSTextureFormatResolver

Texture/surface format negotiation helpers: ID lookup over a stride-9-element table with a fallback pointer, FourCC-to-format decoding, and a BMP header gate that forwards payloads to DDSTextureFormatValidationDecoding.

Methods: `0x00500680`, `0x005006A4`, `0x005029E5`


### ImageBoxFilterCompositor

2x2 box-average image downsampling with scalar (0x00503533) and MMX (0x00503772) variants, plus a runtime function-pointer pair selector (0x00503888) that installs off_5D76C0/off_5D76C4.

Methods: `0x00503533`, `0x00503772`, `0x00503888`


### MathUtil

Pure math helpers: near-zero tolerance gate, Hermite/Catmull-Rom/Bezier interpolation, and a stride-4 3x3 matrix-vector transform. Output vector floats written at +0/+4/+8 of the output pointer.

Methods: `0x0050C042`, `0x0050C0A6`, `0x0050C15E`, `0x0050C2E3`, `0x0050C5D0`

- `this+0x00000000` `float out_x` (write, GUESS)
- `this+0x00000004` `float out_y` (write, GUESS)
- `this+0x00000008` `float out_z` (write, GUESS)

### DispatchTableRouter

Runtime dispatch trampolines: sub_50FEA7(1) preamble followed by an indirect call through a global function-pointer slot (off_5D77E4/off_5D77F0/off_5D7800/off_5D7804/off_5D7884/off_5D7888/off_5D788C/off_5D7894); targets are assigned at runtime and may be swapped.

Methods: `0x0050C134`, `0x0050C20D`, `0x0050C2A6`, `0x0050C2B3`, `0x0050C2B9`, `0x0050C48C`, `0x0050C5BD`, `0x0050C636`, `0x0050C647`


### ObjectFreeRouter

Destructor/free wrappers: conditional release through FreeWrapper_7bcf and thunks into ComplexDestructorWithLoop/VtableSetFreeChild. The grouping is a proposal; a2/a3 ownership flags are not resolved.

Methods: `0x00500FAE`, `0x00502C1F`, `0x0050B244`, `0x0050B425`, `0x0050B82B`

- `this+0x00000000` `void* release_target` (read, GUESS)

## Compatibility contracts

- **FourCCSurfaceFormatDispatch** — 0x005006A4 must map FourCC values 909200416->50, 909200449->51, 909201952->20, 909201985->21 and pass every other 32-bit value through unchanged; it is consumed by DirectXSurfaceFormatNegotiation (0x00502A15).
- **BMPHeaderGate** — 0x005029E5 must accept a buffer only when the length is >= 14, the leading 16-bit value is 0x4D42 ('BM'), and the declared file size at +2 is <= length; on success it forwards (buffer+14, length-14) to DDSTextureFormatValidationDecoding (0x00500FCA) and on failure returns the error -2147467259.
- **BufferReadUnderflowLongjmp** — 0x005020BF must raise a longjmp 'read error' (via GuardedCallWithLongjmp 0x00511869 with the string at 0x005ADB4C) when the requested read length exceeds the remaining count in the tracker at this+0x54; otherwise it copies a3 bytes, advances the tracker, and returns a3.
- **IDTableLookupFallback** — 0x00500680 must linearly search the stride-9-element table spanning flt_5AD508..off_5D7150 matching the first DWORD of each entry against the ID and return the matching entry pointer, or the fallback pointer unk_5AD4E0 when the table is empty or the ID is not found.
- **NearZeroToleranceGate** — 0x0050C042 must return nonzero exactly when |a1 - a2| <= 1.1920929e-7 (double-precision symmetric band) and zero otherwise; eleven normalization/rotation routines rely on it as the pre-normalize near-zero gate.

## Unresolved

- unk_8AFEC0 (0x008AFEC0) is unnamed; sub_4FCA50 has no callee address or contract in the packet, so 0x004FB900's target is unresolvable statically.
- Meaning of the unk_5AD4E0 fallback entry and the stride-9 entry layout beyond the first DWORD are unknown.
- The concrete DirectX surface formats behind the four FourCC constants and their non-contiguous 20/21/50/51 mapping are not documented.
- The a2 bit-0 flag in 0x00500FAE and the a3 ownership flag in 0x0050B244 are not semantically resolved.
- Buffer tracker struct layout beyond the two dwords, and the units of the advance/count amounts, are caller responsibilities and unresolved here.
- The longjmp guard error frame context for 0x005020BF is established elsewhere.
- The role of 'this' in 0x005029E5 and the assumption that the BMP payload is a DDS/embedded texture decoded by 0x00500FCA are unproven.
- Identity of the source/destination image surfaces for the compositors (0x00503533/0x00503772) and the truncated tail of the MMX pass are unproven.
- What sub_50FC7D measures and the downstream consumer of the secondary pointer off_5D76C4 are unknown.
- Decode channel ordering (which nibble/byte is red vs green vs blue) is inferred, and the true role of the 'ContactManifoldCleanup' (0x00507845) post-process is unresolved.
- The embedded palette table base (indexed via this[4*index+12]) is inferred from source only; no packet field covers it.
- Whether the 4-byte-per-vertex decode 0x0050A2B4 emits color or a position/tangent stream is not deterministically evidenced.
- Global flt_59E780 (0x0059E780) cannot be confirmed as the 0.000030517578 scale in 0x0050A34B.
- The spline constant globals (flt_59E43C, flt_59E450, flt_59E46C, flt_59E478, flt_59E7EC, flt_59E800) are not pinned to specific literals.
- The runtime targets of the function-pointer slots (off_5D77E4/off_5D77F0/off_5D7800/off_5D7804/off_5D7884/off_5D7888/off_5D788C/off_5D7894) are unknown and swapped at runtime.
- The stride-4 matrix storage order in 0x0050C5D0 is unconfirmed.
- Self-references callee:0x0050C134/0x0050C20D/0x0050C2B9/0x0050C48C likely reflect dispatch-table aliases rather than recursion.
- Endpoint/tangent and control-point roles of interpolation arguments are DERIVED, not stated by the source.
