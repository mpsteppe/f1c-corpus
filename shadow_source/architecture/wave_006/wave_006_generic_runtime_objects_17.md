# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty-three functions share a coherent set of runtime-object concerns. Eleven structurally identical packed-data decoders (0x00509B8E..0x0050A6E5) expand RGB332, RGB565, RGB10A2, 16-bit luminance/alpha, RGBA16, 8-bit alpha and packed vertex formats into float RGBA using a shared source pointer at +0x18 with row/slice strides at +0x1050/+0x1054 and a texel count at +0x1058, then optionally run a post-decode pass (0x00507845) gated by the +0x10 flag. A copy pair (0x0050AB51, 0x0050AEAE) copies surface regions into an internal float buffer at +0x106C with dirty-rect bounds at +0x1074..+0x1084 and an initialized-state gate at +0x1090, plus a YCbCr-to-RGB path using a nine-global coefficient set. A quantizer (0x0050B27C) round-trips four float color channels at +0x1C..+0x28 against a format id at +0x04, caching max/reciprocal at +0x106C/+0x1070. Math helpers cover Catmull-Rom (3 and 4 component), 4x4 determinant, quaternion normalize/decompose, quaternion SLERP and point-to-unit-box normalization. Three deleting-destructor thunks (0x0050B75F, 0x0050B7AF, 0x0050C026) run class cleanup then conditionally free via 0x00587BCF. All function owners are packet-level UNKNOWN; the class groupings below are GUESS-level proposals, and every global-to-literal scale pairing remains unproven.

## Function roles

- `0x00509B8E` **FloatSurfaceDecoder** — Decode packed 16-bit luminance+alpha texels (two half-words per dword) to float RGBA: luminance duplicated into R and G, B = 1.0, alpha = 1.0; optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x00509C20` **FloatSurfaceDecoder** — Decode 8-bit RGB332 blocks to float RGBA (3-3-2 bit split scaled ~1/7 and ~1/3, alpha 1.0); optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x00509CC2` **FloatSurfaceDecoder** — Decode 8-bit alpha-only data to float RGBA (RGB = 0.0, alpha scaled ~1/255 via 0x0059E460); optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x00509D34` **FloatSurfaceDecoder** — Decode packed 16-bit ARGB (RGB332 byte + alpha byte) to float RGBA (3-3-2 channels scaled ~1/7/~1/3, alpha ~1/255); optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x0050A172` **FloatSurfaceDecoder** — Decode 16-bit packed block to float RGBA (two sign-extended 5-bit channels ~1/16, third output 0.0, 6-bit field ~1/63); optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x0050A223` **FloatSurfaceDecoder** — Decode packed 4-byte-per-element vertex/color block to float RGBA (two signed bytes ~1/128, third output 0.0, one unsigned byte alpha ~1/255); optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x0050A3CE` **FloatSurfaceDecoder** — Decode packed 32-bit RGB10A2-style signed texels to float RGBA (three sign-extended 10-bit channels scaled 2^-9/2^-10, alpha 1.0); optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x0050A488` **FloatSurfaceDecoder** — Decode 32-bit packed RGB10A2 data to float RGBA (three sign-extended 10-bit channels scaled ~2^-9, 2-bit alpha ~1/3); optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x0050A5CB` **FloatSurfaceDecoder** — Decode 16-bit luminance-plus-alpha texels to float RGBA (two half-words per texel, scale ~2^-16); optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x0050A659` **FloatSurfaceDecoder** — Decode 16-bit packed vertex positions to float RGBA (three words scaled ~2^-16, alpha 1.0), loop bounded by the +0x1064 byte count; optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x0050A6E5` **FloatSurfaceDecoder** — Decode 64-bit packed RGBA (four uint16 channels per pixel) to float RGBA, first channel produced via 0x0058A870; optional post-decode pass via 0x00507845 when +0x10 flag set.
- `0x0050AB51` **FloatSurfaceCopyUtility** — Copy a dirty-rect region of a packed 16-bit YCbCr surface into the destination float buffer (+0x106C), expanding dirty-rect bounds, converting each YCbCr sample pair to clamped RGB; returns HRESULT-style error -2147024882 when the surface state word (+0x1090) is zero; called by 0x0050AEAE and 0x0050AF57.
- `0x0050AEAE` **FloatSurfaceCopyUtility** — Copy a texture surface from source buffer a4 into the destination surface (this), optionally converting the source format via 0x00506CE2, delegating the region copy to 0x0050AB51, blitting rows via qmemcpy and setting the +0x108C completion flag on success.
- `0x0050B27C` **TextureFormatQuantizer** — Quantize four float RGBA channels (+0x1C..+0x28) to a fixed-point round-trip form (5/6/5 + format-alpha bits) selected by the format id at +0x04, caching channel max and reciprocal at +0x106C/+0x1070; returns the this pointer.
- `0x0050B75F` **UnknownObject** — MSVC deleting-destructor pattern: run cleanup thunk 0x0050B425, then free the object via 0x00587BCF only when the low bit of the flag argument is set; returns the this pointer.
- `0x0050B7AF` **UnknownObject** — Destructor-style cleanup: run cleanup thunk 0x0050B82B with an argument, then free the object via 0x00587BCF only when the low bit of the flag argument is set; returns the object pointer.
- `0x0050C026` **UnknownObject** — Conditional deleting-destructor: run the underlying render-object destructor 0x0050C021, then free the object via 0x00587BCF only when the low bit of the flag argument is set; returns the object pointer.
- `0x0050C3BB` **SplineInterpolationMath** — Evaluate Catmull-Rom spline at parameter a6 for a 3-component vector; blend four control vectors a2..a5 and write a1[0..2]. Unconditional, no globals read in body.
- `0x0050C887` **SplineInterpolationMath** — Evaluate Catmull-Rom spline at parameter a6 for a 4-component vector; blend four control points a2..a5 and write this+0x0..this+0xC.
- `0x0050CAD9` **MatrixAndQuaternionMath** — Compute 4x4 float matrix determinant by cofactor (Laplace) expansion along column 0 over the flat array at this+0x0..this+0x3C; pure read-only.
- `0x0050DAB2` **MatrixAndQuaternionMath** — Normalize a quaternion at this+0x0..this+0xC; write the normalized vector part to a2 and twice the scalar part (2*w) to a3, falling back to identity {1,0,0} and 0.0 below the near-zero norm threshold.
- `0x0050EB73` **PointBoxNormalizationMath** — Normalize three input components from a2 into a1 against a box/range struct at a3 (x/y to [-1,1], z to [0,1]); dispatch optional transform thunks through jump table 0x0050ECF9 based on the a4/a5/a6 flag combination, then always run thunk 0x0050C5BD.
- `0x0050F258` **MatrixAndQuaternionMath** — SLERP-style quaternion blend: load a 4-component quaternion from a6, optionally negate all components for a shortest-path sign, apply offsets read from a7, run a sequence of indirect-thunk float helpers, and write quaternion outputs to a1/a2 and the adjusted source to a3.

## Proposed classes

### FloatSurfaceDecoder

Expands packed texture/vertex pixel formats (16-bit luminance+alpha, RGB332, 8-bit alpha, RGB332A8, RGB565-style, packed 4-byte vertex, RGB10A2, 16-bit luminance+alpha, 16-bit vertex position, RGBA16) into float RGBA using a shared source pointer at +0x18 with row/slice strides at +0x1050/+0x1054 and a texel count at +0x1058, then optionally runs a post-decode pass (0x00507845) gated by the flag at +0x10.

Methods: `0x00509B8E`, `0x00509C20`, `0x00509CC2`, `0x00509D34`, `0x0050A172`, `0x0050A223`, `0x0050A3CE`, `0x0050A488`, `0x0050A5CB`, `0x0050A659`, `0x0050A6E5`

- `this+0x00000010` `int postDecodeEnabledFlag` (read, DERIVED)
- `this+0x00000018` `unsigned char* sourcePixelData` (read, DERIVED)
- `this+0x00001050` `int rowPitchBytes` (read, DERIVED)
- `this+0x00001054` `int sliceStrideBytes` (read, DERIVED)
- `this+0x00001058` `int texelCount` (read, DERIVED)
- `this+0x00001064` `int sourceByteCount` (read, GUESS)

### FloatSurfaceCopyUtility

Copies rectangular regions of a packed 16-bit surface into an internal destination float buffer at +0x106C, maintaining dirty-rect bounds at +0x1074/+0x107C/+0x1080/+0x1084, gating on the initialized state word at +0x1090, converting YCbCr 4:2:2 sample pairs to clamped RGB, and setting the copy-complete flag at +0x108C; also exposes the top-level texture copy that optionally converts the source format via 0x00506CE2.

Methods: `0x0050AB51`, `0x0050AEAE`

- `this+0x00001030` `int copyRowIndex` (read, GUESS)
- `this+0x00001034` `int sourceXOffset` (read, GUESS)
- `this+0x00001040` `int sourceYOffset` (read, GUESS)
- `this+0x00001048` `int formatConversionEnabled` (read, GUESS)
- `this+0x00001050` `int rowPitchBytes` (read, DERIVED)
- `this+0x00001054` `int sliceStrideBytes` (read, DERIVED)
- `this+0x00001058` `int rowCount` (read, GUESS)
- `this+0x0000106C` `float* destinationFloatBuffer` (write, DERIVED)
- `this+0x00001070` `int copyStartOffset` (read, GUESS)
- `this+0x00001074` `int dirtyRectLeft` (read_write, DERIVED)
- `this+0x00001078` `int dirtyRectMaxElementCount` (read, GUESS)
- `this+0x0000107C` `int dirtyRectRight` (read_write, DERIVED)
- `this+0x00001080` `int dirtyRectTop` (read_write, DERIVED)
- `this+0x00001084` `int dirtyRectBottom` (read_write, DERIVED)
- `this+0x00001088` `int sourceChannelIndex` (read, GUESS)
- `this+0x0000108C` `int copyCompleteFlag` (write, DERIVED)
- `this+0x00001090` `int surfaceStateWord` (read, GUESS)
- `this+0x00001094` `int lumaShift` (read, GUESS)
- `this+0x00001098` `int chromaShift` (read, GUESS)
- `*(this+0x106C)+0x00000000` `float destChannel0` (write, DERIVED)
- `*(this+0x106C)+0x00000004` `float destChannel1` (write, DERIVED)
- `*(this+0x106C)+0x00000008` `float destChannel2` (write, DERIVED)
- `*(this+0x106C)+0x0000000C` `float destChannel3` (write, DERIVED)
- `*(this+0x106C)+0x00000010` `float destChannel4` (write, DERIVED)
- `*(this+0x106C)+0x00000014` `float destChannel5` (write, DERIVED)
- `*(this+0x106C)+0x00000018` `float destChannel6` (write, DERIVED)
- `*(this+0x106C)+0x0000001C` `float destChannel7` (write, DERIVED)

### TextureFormatQuantizer

Quantizes four float color channels at +0x1C..+0x28 to a fixed-point round-trip representation (5/6/5 + format-selected alpha depth) selected by the format id at +0x04, caching the channel maximum at +0x106C and its reciprocal at +0x1070.

Methods: `0x0050B27C`

- `this+0x00000004` `unsigned int formatIdentifier` (read, DERIVED)
- `this+0x0000001C` `float redChannel` (read_write, DERIVED)
- `this+0x00000020` `float greenChannel` (read_write, DERIVED)
- `this+0x00000024` `float blueChannel` (read_write, DERIVED)
- `this+0x00000028` `float alphaChannel` (read_write, DERIVED)
- `this+0x0000106C` `float channelMax` (write, DERIVED)
- `this+0x00001070` `float channelMaxReciprocal` (write, DERIVED)

### SplineInterpolationMath

Pure Catmull-Rom spline evaluation over contiguous float control vectors: 3-component (0x0050C3BB) and 4-component (0x0050C887) variants blend four control points with basis coefficients derived from the scalar parameter and write the result to the output pointer.

Methods: `0x0050C3BB`, `0x0050C887`

- `this+0x00000000` `float outputComponent0` (write, DERIVED)
- `this+0x00000004` `float outputComponent1` (write, DERIVED)
- `this+0x00000008` `float outputComponent2` (write, DERIVED)
- `this+0x0000000C` `float outputComponent3` (write, GUESS)

### MatrixAndQuaternionMath

Float matrix and quaternion helpers: 4x4 matrix determinant by cofactor expansion (0x0050CAD9), quaternion normalize-and-decompose (0x0050DAB2), and a SLERP-style quaternion blend using indirect-thunk float helpers (0x0050F258).

Methods: `0x0050CAD9`, `0x0050DAB2`, `0x0050F258`

- `this+0x00000000` `float quaternionX` (read_write, DERIVED)
- `this+0x00000004` `float quaternionY` (read_write, DERIVED)
- `this+0x00000008` `float quaternionZ` (read_write, DERIVED)
- `this+0x0000000C` `float quaternionW` (read_write, DERIVED)
- `this+0x00000010` `float matrixRow0Element1` (read, DERIVED)
- `this+0x00000014` `float matrixRow0Element2` (read, DERIVED)
- `this+0x00000018` `float matrixRow0Element3` (read, DERIVED)
- `this+0x0000001C` `float matrixRow1Element0` (read, DERIVED)
- `this+0x00000020` `float matrixRow1Element1` (read, DERIVED)
- `this+0x00000024` `float matrixRow1Element2` (read, DERIVED)
- `this+0x00000028` `float matrixRow1Element3` (read, DERIVED)
- `this+0x0000002C` `float matrixRow2Element0` (read, DERIVED)
- `this+0x00000030` `float matrixRow2Element1` (read, DERIVED)
- `this+0x00000034` `float matrixRow2Element2` (read, DERIVED)
- `this+0x00000038` `float matrixRow2Element3` (read, DERIVED)
- `this+0x0000003C` `float matrixRow3Element0` (read, DERIVED)

### PointBoxNormalizationMath

Normalizes three input components into a caller-provided output vector against a box/range descriptor, centering x/y to [-1,1] and z to [0,1], and dispatching optional transform thunks through a jump table before a final always-run transform.

Methods: `0x0050EB73`

- `this+0x00000000` `float normalizedOutputX` (write, DERIVED)
- `this+0x00000004` `float normalizedOutputY` (write, DERIVED)
- `this+0x00000008` `float normalizedOutputZ` (write, DERIVED)

## Compatibility contracts

- **PackedSurfaceFloatDecodeContract** — A replacement must decode the packed pixel formats observed here into float RGBA using the same per-format scale factors materialized in the raw bodies (1/255, 1/128, 1/63, 1/31, 1/16, 1/7, 1/3, 2^-16, 2^-9, 2^-10), emit four floats per source element with the alpha last, and preserve the +0x10-gated post-decode pass over the output buffer.
- **SurfaceCopyDirtyRectContract** — A replacement must model the dirty-rect bookkeeping at +0x1074/+0x107C/+0x1080/+0x1084, the destination float buffer pointer at +0x106C, the initialized-state gate at +0x1090 (zero produces the -2147024882 error), and the copy-complete flag write at +0x108C.
- **YCbCrColorConversionContract** — A replacement must reproduce the YCbCr-to-RGB conversion of the 16-bit packed sample pairs (luma offset 16.0, chroma offsets 128.0, per-channel clamp to [0,1]) producing two RGBA pixels per 4-byte pair, using the observed coefficient globals read by 0x0050AB51.
- **DeletionDestructorContract** — A replacement must preserve the MSVC deleting-destructor behavior: run the class cleanup body, then release the object allocation via the free wrapper only when the low bit of the caller-supplied flag is set, returning the object pointer.

## Unresolved

- Every function owner is packet-level UNKNOWN; the proposed classes (FloatSurfaceDecoder, FloatSurfaceCopyUtility, TextureFormatQuantizer, SplineInterpolationMath, MatrixAndQuaternionMath, PointBoxNormalizationMath) are GUESS-level groupings of structurally similar bodies and are not confirmed C++ classes.
- The decoder family (0x00509B8E..0x0050A6E5) and the copy family (0x0050AB51, 0x0050AEAE) share the source-addressing fields at +0x18, +0x1050, +0x1054 and +0x1058; the packet does not prove they are the same object, so they are modelled as separate classes.
- 0x00507845 ('ContactManifoldCleanup' in the corpus) is called by every decoder over the decoded float buffer when the +0x10 flag is set, but its actual purpose is unknown; the name is a legacy mislabel and the flag's meaning beyond gating the pass is unproven.
- The mapping of the read-only float globals to the inlined scale literals is not proven for any decoder (e.g. 0x005AD290/0x005ADB14 vs 0.000015259022, 0x005AD210/0x0059E98C vs 0.14285715/0.33333334, 0x0059E9E0/0x005ACCDC vs 0.0625/0.015873017, 0x0059E774/0x0059E460 vs 0.0078125/0.0039215689); Hex-Rays folded the constants into literals.
- Sign-extension tricks ((char)(8*x)>>3, (__int16)(32*(w>>21))>>5, (__int16)(*(_WORD*)w<<6)>>6) imply signed channel semantics and a [-1,1] float range; an unsigned interpretation is not ruled out by the packet.
- The three destructors (0x0050B75F, 0x0050B7AF, 0x0050C026) follow the MSVC deleting-destructor pattern but belong to unidentified object classes; bit-0-of-flag as the delete indicator and the __userpurge register ABI are DERIVED/decompiler-artifact readings.
- NormalizePointToUnitBox (0x0050EB73): the flag switch through jump table 0x0050ECF9 selects up to two transform thunks before normalization; the thunk identities, arguments and which operands they transform are unresolved. The a3 box/range struct mixes unsigned-int origins/scales with float z bounds per the raw source.
- QuaternionSlERP (0x0050F258): the register/stack state at each indirect-thunk call site is lost to indirect-jump decompilation; whether a1/a2 receive interpolated quaternions or quaternion derivatives is unresolved.
- TextureDecodeRGB16 (0x0050A6E5) reuses the this parameter as scratch (low byte = 32) inside the loop; the contract of callee 0x0058A870 and the uint16 channel ordering inside the packed DWORD pair are unproven.
- The format identifiers 844388420 and 861165636 used by QuantizeColorChannelsToTextureFormat are opaque; their FourCC-like selection of alpha depth (15.0 vs 255.0 maximum) is inferred, not evidenced.
- The surface owner of the +0x106C/+0x1070 offsets carries conflicting readings across classes (destination float buffer / copy start offset in FloatSurfaceCopyUtility versus channel max / reciprocal in TextureFormatQuantizer); because the packet never proves common ownership, the offsets are kept distinct per class.
- The scale/coefficient constants flagged by packet facts but absent from the raw bodies (0x0059E450, 0x0059E46C, 0x0059E478, 0x0059E7EC, 0x0059E800, 0x0059E8D8, 0x0059FEC8, 0x005ACCD0, 0x005ACCD4, 0x005ACCD8, 0x005ADE40, 0x005ADE48) may back hoisted float literals in the functions that claim them; they are recorded as unresolved.
- No state machine is evidenced: the jump-table dispatch in NormalizePointToUnitBox and the YCbCr copy flag are control-flow selections, not state machines.
- The YCbCr sample interpretation (two 4:2:2 pixels per 4 bytes, luma/chroma split via +0x1094/+0x1098 shift fields) is DERIVED from the fill and raw arithmetic, not independently evidenced; the -2147024882 error constant interpretation is likewise not packet-confirmed.
