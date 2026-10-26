# MathAndCollision

Scope: `math_and_collision`  
Trust: `GUESS`

Proposes four class boundaries over the 35 validated functions. GrayscaleTextureDecoder is the strongest (DERIVED): its three members share an identical this-layout (source pointer at +0x18, row stride +0x1050, slice stride +0x1054, pixel count +0x1058, cleanup gate at +0x10) and the same post-decode hook ContactManifoldCleanup (0x00507845). VectorMathUtility (GUESS) groups 11 pure arithmetic functions that share the FloatRangeCheck epsilon test (0x0050C042) and the near-zero/FLT_MIN float globals (flt_5ADE40, flt_59E43C). CollisionDataStore (GUESS) groups four collision-domain functions on domain alone; no common object is evidenced. SlotArrayContainer (GUESS) groups three functions that all operate on a 104-entry dword array at +0x3E18. Fourteen functions stay ownerless (UnknownObject) because the packet evidences no shared layout. Observable contracts: the collision setup message dispatch (types 18/19/20 with the device-create counter toggle) and the bounded driver-name composition return convention (0 on success, required length when too small).

## Function roles

- `0x00404D00` **UnknownObject** — Indexed getter into the global pointer table off_5BE6C4: unguarded dereference of element a1, returned as int; caller 0x00422BE0 owns index validity.
- `0x0041F0F4` **UnknownObject** — Element getter: returns the dword at a2 + 4*a1 + 20, where a2 is the ESI-passed base pointer and a1 the EAX-passed index into a 4-byte-element array at offset 20; no bounds check.
- `0x0042DD72` **UnknownObject** — Single-expression indexed table lookup: reads the array-base pointer at a2 + 12 and returns the dword at base + 8*a1 (8-byte record stride); a3 declared but unused.
- `0x00435406` **UnknownObject** — Writes the ECX-passed value a2 into three consecutive dword array elements at this+0x58, this+0x5C, this+0x60 (array indices 22..24); returns this.
- `0x004363D0` **UnknownObject** — Sub-object clear: memsets the 0x64-byte region at this and returns this; called by DynamicsObjectInitialization (0x00438C10) during dynamics object setup.
- `0x00449A10` **CollisionDataStore** — Collision tree cleanup thunk: forwards the double read from global dbl_7C9360 into CollisionTreeNodeCleanup and returns its result.
- `0x0044C600` **UnknownObject** — Frees 44 backwards-walking pointer-array entries (cursor-8 read, 8-byte step), each freed via FreeWrapper_7bcf when non-null; returns the last pointer read.
- `0x0044ED10` **CollisionDataStore** — Collision setup message dispatch: type 18 acknowledged without copy; type 19 copies payload into global collision struct byte_7CA594 via CollisionStructCopy_efc0; type 20 copies into unk_7CB318 or unk_7CB714 (selected by dword_7CB310) via CollisionDataCopy and increments dword_7CB310; returns 1 for accepted types, 0 otherwise.
- `0x00455BD0` **CollisionDataStore** — Batched collision-result processing: 44 iterations over an 11-float-strided sub-array of this starting at float-element 1736, invoking CollisionResultProcessing (0x00453100) on each; returns the last char result. Called by CollisionConfigurationSync (0x00475D30).
- `0x004579C0` **VectorMathUtility** — Element-wise 3D vector add (this+0x7C/0x80/0x84 plus a2[0..2]) returning the squared length of the sum (v3*v3 + v2*v2 + v4*v4); used by MinimumDistanceSearch (0x0040ACD0) and ShortComputation (0x0040B630) as a distance-squared metric.
- `0x0045BC00` **CollisionDataStore** — Thunk forwarding field 0x0 of this to CollisionDamageDecayProcessor; returns void. The prelabel getter template (return field 0x0) conflicts with the raw body, which forwards the field to a callee; raw source is authoritative.
- `0x0045E5F0` **SlotArrayContainer** — Scans the 104-element dword array at this+0x3E18 for a value equal to a2; returns 1 on match, 0 when the scan exhausts 104 elements.
- `0x00460C30` **SlotArrayContainer** — Linear search over the 104-element dword array at this+0x3E18 for a value equal to a2; returns the 0-based first-match index or sentinel 63 when exhausted.
- `0x00462330` **SlotArrayContainer** — ID-to-index lookup: reads the object pointer from this+0, obtains the target ID via SingleFunctionCallWrapper_a810 on obj+0x3FB8, scans the ID array at obj+0x3E18, and returns the first-match index or -1. Called by NetCommPlayerSlotSync (0x0045FC50) to map a queried ID to a player-slot index.
- `0x0046C710` **UnknownObject** — Scans one of two global 32-bit arrays (dword_7CD2B8..flt_7CD458, or dword_7CD470..flt_7CD610) selected by the flag byte at this+0x174; returns the index of the first negative entry or the full element count when none exists.
- `0x0046C74C` **UnknownObject** — Key-binding array removal with shift-down: selects array base dword_7CD2B8 or dword_7CD470 by bit 2 of a1, ORs a2 into an out-of-range offset literal, reads the slot v5[a5], removes it (reset to -1 when a5 >= 103, otherwise qmemcpy shift-down and v5[103] = -1), and returns the removed binding value.
- `0x00476FC0` **UnknownObject** — Bounded driver-name composition: copies a source string selected from dword_7D0D5C[7*a2] (fallback byte_5EA438) into a3 under capacity a4 via sub_587DD0, then, when the combined length of that copy, the this+0x188 string and a terminator fits a4, appends the two-byte literal word_5C32D8 and strcats the this+0x188 string; returns 0 on success or the required length when too small.
- `0x004C2FC0` **UnknownObject** — Cleanup of a 1060-byte-stride record array rooted at a guarded global pointer (raw name dword_8AC394, evidence unk_8AC388): reads the record count from the 4-byte header at (global-4), cleans each record backwards via MultiFieldCleanup, then frees the allocation base via FreeWrapper_7bcf; void return.
- `0x004D47E0` **UnknownObject** — Thin stream-state read: calls StringStreamReadWithMaskCheck (0x0058801D) with (this, &v2) and returns the dword written into v2; called by StateGetSetWrapper (0x004D4800) as a per-state read on a string-backed stream.
- `0x004D7D90` **UnknownObject** — Thin wrapper over InitializeSlotArray (0x004D7AD0): passes the address of global dword_8AD264 as the slot-array base and returns the initializer's _DWORD* result unchanged; dword_8AD264 read for its address only.
- `0x004F6D60` **UnknownObject** — Counts consecutive non-zero dword entries (max 5) in the array pointed to by this+0x40, storing and returning the count at this+0x0; early-exits on the first zero entry. Consumed by ArithmeticComparison_8370 (0x004F8370).
- `0x00509F70` **GrayscaleTextureDecoder** — Decodes 8-bit grayscale texture data to 32-bit float RGBA: source pixel = this+0x18 + a3*this+0x1054 + a2*this+0x1050, loops this+0x1058 pixels writing byte*0.0039215689 to RGB and 1.0 to A (four floats per pixel); calls ContactManifoldCleanup (0x00507845) on the decoded buffer when this+0x10 is non-zero.
- `0x00509FDE` **GrayscaleTextureDecoder** — Decodes grayscale-plus-alpha texture data (2 bytes per pixel) to 32-bit float RGBA: first byte scaled by 0.0039215689 to RGB, second byte scaled by the same factor to A; same source addressing and the same this+0x10-gated ContactManifoldCleanup (0x00507845) post-step.
- `0x0050A55B` **GrayscaleTextureDecoder** — Decodes unsigned 16-bit grayscale texture data to 32-bit float RGBA: luminance (uint16 * 0.000015259022) written to R=G=B and A=1.0, one float4 per source value; same source addressing and the same this+0x10-gated ContactManifoldCleanup (0x00507845) post-step.
- `0x0050C23C` **VectorMathUtility** — Two-component weighted interpolation over float2-like points: a1[i] = a[i] + a5*(b[i]-a[i]) + a6*(c[i]-a[i]) for i in {0,1}, where a2/a3/a4 are the source corners and a5/a6 the weights; returns the destination pointer a1.
- `0x0050C4BB` **VectorMathUtility** — Three-component bilinear interpolation of base vector a2 against offset vectors a3 and a4 driven by weights a5 and a6: a1[i] = a2[i] + a5*(a3[i]-a2[i]) + a6*(a4[i]-a2[i]); returns the output vector pointer a1.
- `0x0050DCB0` **VectorMathUtility** — Builds a quaternion (x,y,z,w) from an axis resolved via ThunkTo (0x0050C2B3) and an angle a3: half angle v9 = a3*0.5, w (a1+0xC) = cos(v9), and x/y/z (a1+0x0/0x4/0x8) = axis*sin(v9); returns the output buffer a1.
- `0x0050E3E0` **VectorMathUtility** — Normalizes a 4-component vector with a length threshold: three-component squared length v7; FloatRangeCheck(v7, 1.0) short-circuits to a verbatim 4-component copy; otherwise v7 > 1.1754944e-38 scales all four components by 1/sqrt(v7) and v7 <= threshold zeroes them; returns the output pointer a1.
- `0x0050E491` **VectorMathUtility** — Ray-plane intersection: a2 is the plane (XYZ normal + a2[3] distance term), a3 the ray origin, a4 the ray target; computes v4 = dot(normal, origin) and denominator v5 = v4 - dot(normal, target); returns NULL when v5 == 0.0 (parallel) or when ArithmeticComparison_a88f (0x0058A88F) rejects the t-value v7 = (v4 + a2[3]) / v5; otherwise writes the interpolated point into a1 and returns it.
- `0x0050E634` **VectorMathUtility** — 4x4 matrix by 4-component vector multiply: a3 is a 16-float matrix, a2 the vector; computes four dot products (one per row) and writes the four result components to a1; returns a1.
- `0x0050E6D3` **VectorMathUtility** — Normalizes a 2D vector a2 to unit length into a1: verbatim copy when FloatRangeCheck(sq_len, 1.0) passes; otherwise 1/sqrt(sq_len) scaling when sq_len > FLT_MIN and zeroing both components when at or below the threshold; returns a1.
- `0x0050E84B` **VectorMathUtility** — Row vector times 2x2 matrix: writes two floats into a1 computed from a2 (input vector) and a3 (matrix read with a 4-float column stride: a3[0], a3[1], a3[4], a3[5]); returns a1.
- `0x0050E887` **VectorMathUtility** — Normalizes the 3D vector a2 into a1: verbatim copy when FloatRangeCheck(sq_len, 1.0) passes (skipped when a1 == a2); 1/sqrt(sq_len) scaling when above the degenerate threshold and zeroing all three components otherwise; returns a1.
- `0x00513E2D` **VectorMathUtility** — Batch homogeneous-weight scaling: processes exactly 16 consecutive float4 vectors, multiplying each X/Y/Z by that vector's own W and passing W through unchanged; returns 0. Reached from DelegationWithErrorCheck (0x005158AF) and InitProcessWrapper (0x005158E3).
- `0x0051593F` **UnknownObject** — Row-block copy helper: copies a5 rows of a6 bytes from source (a1 + 4*a2) into destination (a3 + 4*a4) via per-row qmemcpy; returns the source pointer advanced past all copied rows (or the initial pointer when a5 is not positive).

## Proposed classes

### GrayscaleTextureDecoder

Decodes grayscale texture data (8-bit, 8-bit+alpha, and 16-bit variants) into 32-bit float RGBA output buffers. All three members share the same source-addressing layout on `this` (source pointer +0x18, row stride +0x1050, slice stride +0x1054, pixel count +0x1058), the same 1/255-style scale literals, and the same post-decode hook ContactManifoldCleanup (0x00507845) gated by the +0x10 flag. This is the best-evidenced class boundary in the packet.

Methods: `0x00509F70`, `0x00509FDE`, `0x0050A55B`

- `this+0x00000010` `int32 cleanupEnabledFlag` (read, DERIVED)
- `this+0x00000018` `uint8_t* sourceDataPtr` (read, DERIVED)
- `this+0x00001050` `int32 rowStride` (read, DERIVED)
- `this+0x00001054` `int32 sliceStride` (read, DERIVED)
- `this+0x00001058` `int32 pixelCount` (read, DERIVED)

### VectorMathUtility

Free-standing vector and matrix arithmetic primitives: squared-length 3D vector add, two- and three-component bilinear interpolation, quaternion construction from axis/angle, thresholded 4D/3D/2D vector normalization, ray-plane intersection, 4x4-matrix-by-vector multiply, 2x2 transform, and homogeneous-weight (W) batch scaling. Grouping rests on arithmetic kind plus the shared FloatRangeCheck epsilon test (0x0050C042) and the near-zero/FLT_MIN float globals (flt_5ADE40, flt_59E43C). The this-based offsets these functions write are output-buffer slots, not evidenced object state.

Methods: `0x004579C0`, `0x0050C23C`, `0x0050C4BB`, `0x0050DCB0`, `0x0050E3E0`, `0x0050E491`, `0x0050E634`, `0x0050E6D3`, `0x0050E84B`, `0x0050E887`, `0x00513E2D`


### CollisionDataStore

Collision data lifecycle pathway: cleanup of a collision tree identified by the global dbl_7C9360, dispatch of collision setup messages (types 18/19/20) into the global collision struct byte_7CA594 or the two device data buffers, batched collision-result processing over a strided sub-array, and forwarding of the this+0x0 object to the collision damage-decay processor. Grouping is domain-only; no single shared object or field layout is evidenced across the four members.

Methods: `0x00449A10`, `0x0044ED10`, `0x00455BD0`, `0x0045BC00`

- `this+0x00000000` `void* ownedCollisionObject` (read, GUESS)

### SlotArrayContainer

Holder of a 104-entry dword ID/slot array plus a query-ID value source, searched by three lookup helpers. Grouping rests on the shared 104-element array layout at +0x3E18; whether the direct this-based accessors (0x0045E5F0, 0x00460C30) and the this+0->obj-indirected accessor (0x00462330) operate on the same object instance is not proven.

Methods: `0x0045E5F0`, `0x00460C30`, `0x00462330`

- `obj+0x00003E18` `int32[104] slotIdArray` (read, GUESS)
- `obj+0x00003FB8` `int32 queryIdSource` (read, GUESS)
- `this+0x00000000` `void* objectSelfRef` (read, GUESS)

## Compatibility contracts

- **CollisionSetupMessageDispatch** — Incoming collision setup messages must be dispatched by numeric type: type 18 is acknowledged without copying payload; type 19 copies the payload into the global collision struct (byte_7CA594) via CollisionStructCopy_efc0; type 20 copies into one of two device data buffers (unk_7CB318 / unk_7CB714) selected by the dword_7CB310 counter, which is incremented after the copy so the next type-20 message selects the alternate buffer; accepted types return 1 and any other type returns 0.
- **BoundedDriverNameComposition** — Driver-name composition into a caller-provided buffer (a3, capacity a4) must copy the selected source string under a length limit, return 0 on a successful append, and return the required length when the combined content does not fit a4; it must never write past the a4 capacity.
- **RayPlaneIntersectResult** — Ray-plane intersection must return NULL when the ray is parallel to the plane (zero denominator) or when the computed t-value is rejected by ArithmeticComparison_a88f, and otherwise write the interpolated intersection point into the destination and return it.

## Unresolved

- Owner identity is UNKNOWN for 14 functions (0x00404D00, 0x0041F0F4, 0x0042DD72, 0x00435406, 0x004363D0, 0x0044C600, 0x0046C710, 0x0046C74C, 0x00476FC0, 0x004C2FC0, 0x004D47E0, 0x004D7D90, 0x004F6D60, 0x0051593F); no shared object or field layout is evidenced for them, so they are left without class membership rather than forced into a clean design.
- Whether the this-based array accessors (0x0045E5F0, 0x00460C30 using this+0x3E18) and the obj-indirected accessor (0x00462330 reading obj from this+0 then obj+0x3E18/0x3FB8) operate on the same container instance is unproven; field:this:0x00003E18 and field:obj:0x00003E18 are kept as distinct evidence.
- VectorMathUtility membership is GUESS: the this-based offsets written by its members are output-buffer slots, not evidenced object state, so no class fields are asserted for it.
- CollisionDataStore membership is GUESS and domain-only; no shared object exists across CleanupCollisionTree (global dbl_7C9360), CollisionDataSetupDispatch (global collision structs), CollisionResultBatchLoop (this-strided sub-array) and ForwardToCollisionDamageDecayProcessor (this+0x0).
- The float globals flt_59E43C (FLT_MIN literal 1.1754944e-38), flt_59E440, flt_59E450 (degrees-to-radians candidate), flt_59E460 (1/255 fold), flt_5AD290 (16-bit luminance scale 0.000015259022) and flt_5ADE40 (near-zero epsilon) are folded into inline literals in the raw sources; which global backs which literal is DERIVED, not proven.
- The KeyBindingArrayRemoveShift OR-target offset literal 1149960185 (0x448AFFF9 as u32) is unusually large and may be a decompiler artifact of a negative offset; no alternate spelling is evidenced.
- The two global arrays scanned by GlobalArrayScanForNegative and edited by KeyBindingArrayRemoveShift (dword_7CD2B8 and dword_7CD470, bounds flt_7CD458 / flt_7CD610) are described as read-only (rw R) yet written through; the write classification is left to static/runtime review, and the meaning of a negative entry (empty/invalid slot) is DERIVED only.
- The slot-ID array at +0x3E18 (104 entries) and the query-ID source at +0x3FB8 belong to an unidentified class; the sentinel values 63 (LinearSearchIn104ElementArray) and -1 (IDLookupInArray) differ and their caller meaning is unknown.
- SetupArrayElementSetter writes three consecutive array slots at this+0x58/0x5C/0x60 with no semantic role established and no static callers recorded.
- The 0x64-byte region cleared by DoubleArrayZero is not an integral number of 8-byte doubles; the DoubleArrayZero legacy name may misdescribe the element type.
- F_2DArrayBlockCopy treats rows as flat a6-byte memory blocks with 4-byte start-offset strides; element type and 2D array structure are caller-supplied and unknown here.
- The FreePointerArray base is ambiguous (packet global ppvOut 0x7CA590 vs raw-source walk rooted at unk_7CC9A0), and what the freed pointers represent is unknown.
- The CollisionDataSetupDispatch message types 18/19/20 and the byte_7CA594 global collision struct layout are DERIVED from usage only; no in-function documentation and no recorded static callers establish the entry path.
- RayPlaneIntersect sign convention of the plane-distance term a2[3] and the exact accepted range of ArithmeticComparison_a88f are unproven.
- F_44Matrix4VectorMultiply row-major versus column-major storage convention of the 16-float matrix is unresolved.
- RotationMatrixFromAxisAndAngle axis-selection semantics of a2 and whether a3 is degrees or radians are not grounded; global flt_59E450 is a candidate degrees-to-radians scale but is absent from the raw body.
- ContactManifoldCleanup (0x00507845) is a corpus-assigned name; its actual post-decode effect is not evidenced from the texture functions alone.
- StringStreamReadWithMaskCheck (0x0058801D) 'MaskCheck' behavior is unverified from ArrayStateRead alone.
