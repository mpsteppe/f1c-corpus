# GenericRuntimeMath

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

The packet covers 21 freestanding SIMD math helpers with UNKNOWN owners. The SSE family computes 3x3 determinants from a 4x4 matrix, constructs/normalizes plane equations from three points, normalizes 3-vectors with Newton-Raphson reciprocal-sqrt refinement, clamps 4-component velocity below a stiction threshold, and composes a quaternion from axis-angle components (calling sub_528CC0). The 3DNow/MMX family computes quaternion products and packed barycentric, bilinear, cubic-Hermite, quartic and quadrilinear interpolations, many with explicit region classification and per-region normalization. Every function writes to a per-call 16-byte output buffer addressed as base 'this' (+0x0..+0xC) and several rely on read-only constant globals for refinement scales and sign-flip masks. Two synthetic classes are proposed (SSE and 3DNow families); ownership and exact global-to-constant bindings remain UNKNOWN.

## Function roles

- `0x0051F7CE` **SSEMathHelpers** — Compute the determinant of the upper-left 3x3 submatrix of a 4x4 row-major matrix via SSE cofactor expansion, with an alignment guard between aligned and unaligned row loads.
- `0x0051F89E` **SSEMathHelpers** — Construct a plane equation (N, D) from three points via SSE edge vectors, cross-product normal, Newton-Raphson reciprocal-sqrt normalization, and sign-flipped distance term.
- `0x0051FD2E` **SSEMathHelpers** — Normalize a 3-component vector using Newton-Raphson reciprocal-length refinement and apply a Z sign-flip mask.
- `0x0052042E` **SSEMathHelpers** — Clamp a 4-component velocity vector: below a squared-length stiction threshold write zeroes, otherwise scale all four components via Newton-Raphson reciprocal-sqrt refinement.
- `0x0052098E` **SSEMathHelpers** — Construct a normalized plane equation from three points with SSE cross product, Newton-Raphson reciprocal-sqrt refinement, and sign-flipped distance component.
- `0x00520E0E` **SSEMathHelpers** — Compose a quaternion from three axis-angle float components, invoking sub_528CC0 as the composition helper and completing with packed sign-mask arithmetic.
- `0x00520ED0` **Packed3DNowMath** — Multiply two quaternions supplied as 3DNow packed half-pairs, forming cross/dot terms with sign-bit XOR and pfacc, then exiting MMX state.
- `0x00521079` **Packed3DNowMath** — 3DNow barycentric interpolation that classifies the query into one of four triangle regions via a packed comparison mask and normalizes the selected edge with Newton-Raphson refinement.
- `0x00521295` **Packed3DNowMath** — 3DNow quad/edge intersection helper using a packed-mask branch to pick one of four regions, each normalizing its edge and writing interpolated and blended attribute vectors.
- `0x005214AA` **Packed3DNowMath** — Multiply two quaternions as 3DNow operand pairs, using PackedFloatingPointMath (sub_5295E0) three times for component setup and a sign-flip XOR constant.
- `0x005261EA` **Packed3DNowMath** — Affine weighted blend over an 8-pair coefficient table driven by three weight scalars, producing two packed output pairs including the a3[6]/a3[7] addend terms.
- `0x0052625B` **Packed3DNowMath** — Non-affine weighted sum over a 6-pair coefficient table driven by three weight scalars; omits the addend terms and stores only the low 32 bits of the second slot.
- `0x00526321` **Packed3DNowMath** — 3DNow bilinear interpolation between a base point and two delta points with two scalar weights, writing a full packed pair and a low-dword scalar.
- `0x00526392` **Packed3DNowMath** — Cubic Hermite spline interpolation over packed control points, building the four standard Hermite basis functions from packed 1.0f/2.0f/3.0f constants.
- `0x00526466` **Packed3DNowMath** — 3DNow interpolation between four packed control points parameterized by a scalar factor, blending first elements and low lanes of second elements and scaling by 0.5.
- `0x00526D9A` **Packed3DNowMath** — Cubic Hermite spline interpolation of packed float pairs using 3DNow SIMD, writing only the full 64-bit packed result to the output.
- `0x00526E32` **Packed3DNowMath** — Packed two-lane bilinear interpolation helper computing a1 = a2 + (a3-a2)*a5 + (a4-a2)*a6 with duplicated weights.
- `0x00526EBE` **Packed3DNowMath** — 3DNow higher-order blend-weight interpolation (quartic basis) over four packed control points scaled by 0.5; caller and true interpolation basis unknown.
- `0x0052704A` **Packed3DNowMath** — Compute a quaternion product from two packed quaternion operands (plus an intermediate input), building cross-product terms and assembling two output halves with sign-flip XOR.
- `0x0052717C` **Packed3DNowMath** — Two-weight barycentric interpolation on two packed float pairs, computing both output component pairs as weighted sums of three inputs.
- `0x005271ED` **Packed3DNowMath** — Straight-line 3DNow cubic Hermite interpolation kernel writing two blended pairs from four control points and a scalar parameter.

## Proposed classes

### SSEMathHelpers

Synthetic grouping of the SSE (non-3DNow) math helpers in this packet: 3x3 determinant from a 4x4 matrix, plane-from-three-points and plane-from-edges construction with Newton-Raphson normalization, 3-vector normalization, velocity friction clamping with stiction threshold, and quaternion composition from axis-angle components. All members write to a per-call 16-byte output buffer at base 'this' and several read normalization/refinement constant globals. The class boundary is inferred from the shared SSE intrinsic flavor and output-buffer convention; no owner evidence exists in the packet.

Methods: `0x0051F7CE`, `0x0051F89E`, `0x0051FD2E`, `0x0052042E`, `0x0052098E`, `0x00520E0E`

- `this+0x00000000` `float output_first_lane` (read_write, DERIVED)
- `this+0x00000004` `float output_second_lane` (read_write, DERIVED)
- `this+0x00000008` `float output_third_lane` (read_write, DERIVED)
- `this+0x0000000C` `float output_fourth_lane` (write, DERIVED)
- `this+0x00000010` `float[4] matrix_row2` (read, DERIVED)
- `this+0x00000020` `float[4] matrix_row3` (read, DERIVED)
- `this+0x00000030` `float[4] matrix_row4` (read, DERIVED)

### Packed3DNowMath

Synthetic grouping of the 3DNow/MMX packed math kernels in this packet: quaternion products (three variants), barycentric interpolation with region classification, quad/edge intersection, weighted point blends/sums, and bilinear, cubic-Hermite, quartic and quadrilinear interpolation over packed __m64 control points. Members share the packed-float idiom, the read-only 3DNow constant-table globals (0x005AF8F0..0x005AF9A0), the two __m64 output-half convention at this+0x0/this+0x8, and _m_femms state hygiene. The class boundary is inferred from the shared 3DNow intrinsic flavor; no owner evidence exists in the packet.

Methods: `0x00520ED0`, `0x00521079`, `0x00521295`, `0x005214AA`, `0x005261EA`, `0x0052625B`, `0x00526321`, `0x00526392`, `0x00526466`, `0x00526D9A`, `0x00526E32`, `0x00526EBE`, `0x0052704A`, `0x0052717C`, `0x005271ED`

- `this+0x00000000` `__m64 (packed_float2) output_low_half` (read_write, DERIVED)
- `this+0x00000008` `__m64 (packed_float2) output_high_half` (read_write, DERIVED)

## Compatibility contracts

- **3DNowStateHygiene** — The 3DNow/MMX kernels emit _m_femms on entry and before returning. A replacement must preserve this state discipline so x87 floating-point code running after these helpers is not corrupted.
- **OutputBuffer16ByteLayout** — All helpers write results into a per-call 16-byte output buffer addressed as base 'this': SSE helpers fill a four-float quad at +0x0..+0xC, 3DNow helpers write two __m64 halves at +0x0 and +0x8 (some only the low half or a low-dword scalar). A replacement must keep the same output addressing so callers observe results at the expected offsets.
- **NewtonRaphsonReciprocalRefinement** — The plane/vector-normalization and stiction-clamp helpers refine the reciprocal length with Newton-Raphson steps driven by read-only constant globals (refinement coefficient 0.5 and scale constants). A replacement must honor these constant roles to reproduce equivalent normalization and threshold behavior.

## Unresolved

- All 21 functions have UNKNOWN owners; the classes SSEMathHelpers and Packed3DNowMath are synthetic groupings inferred from the shared SIMD flavor and output-buffer convention, not attested objects.
- Base 'this' in the packet denotes a per-call output pointer, not a shared object. Equal byte offsets across functions (e.g. this+0x0 in every helper) are not proof of a common struct; the two classes must not be read as owning a single layout.
- field:this:0x00000004 is read by 0x0051F89E and 0x0052098E without an explicit explanation in the raw SSE text; likely a decompiler artifact of the returned pointer rather than a real semantic read.
- The exact binding between the 3DNow constant globals (0x005AF8F0, 0x005AF900, 0x005AF910, 0x005AF918, 0x005AF920, 0x005AF968, 0x005AF980, 0x005AF988, 0x005AF990, 0x005AF998, 0x005AF9A0) and the inline __m64 literals (1.0f, 2.0f, 3.0f, 0.5f, sign-flip masks) is not recoverable from this packet; Hex-Rays folds the read globals into immediates.
- Exact values of the SSE normalization/refinement globals 0x005D8AD0, 0x005D8AE0, 0x005D8AF0, 0x005D8C30, 0x005D8C40, 0x005D8C50 and the velocity-clamp constants 0x008D618C, 0x008D6190, 0x008D6194 are not evidenced; only their roles (sign flip, 0.5 refinement, scale, threshold) are DERIVED.
- For 0x00520E0E the composition globals 0x008D62A0/0x008D62B0/0x008D62C0 are read but their values and exact roles (sign mask, scale, axis-angle packing constant) are unverified; the role of sub_528CC0 is unknown beyond address.
- No static callers are evidenced for any helper, so the consumption contexts (terrain heightfield, camera path, vehicle physics, collision geometry) are unknown; the plane-from-points and velocity/stiction interpretations rest on legacy ABI names.
- The packed-lane to w/x/y/z mapping for the quaternion products (0x00520ED0, 0x005214AA, 0x0052704A) is not recoverable from any single function.
- qword_5AF918 is listed as a read global by 0x00520ED0 but is absent from the raw decompiled text; its role (an MMX packed constant) is unproven.
- Callees 0x00528CC0 and 0x005295E0 are referenced by this packet but are outside its function set, so their semantics and the exact composition/product math they contribute are unresolved.
- Plane helpers mix double inputs (const double* points) with float output quads; the low 64-bit lanes of loaded points are left uninitialized by _mm_loadh_ps and do not contribute to the stored plane.
- The barycentric region-classification masks (v13 & 1, 0xFF00FF00, 0x10000 in 0x00521079; 0xCC, 0x10 in 0x00521295) are inferred as triangle-region splits from the structural twin relationship; not proven identical.
- Input tables a2/a3 (vertex-component blocks and coefficient tables) of the 3DNow interpolation kernels have no identity in the fact table; only the output base 'this' is recorded.
