# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Conservative architecture proposal for 28 validated vehicle-physics functions. 0x004046B0 and 0x00404790 form a DERIVED wheel-contact height-field pair over the same owner: element count at this+0x130, element array at this+0x134 with a 316-byte stride, and a node-type threshold at this+0x10; both are invoked by 0x00404250. 0x004B9780/0x004B9810/0x004B9D80 form a GUESS allocator/dispatch group over a pointer member at this+0x0 (3996-byte car physics state allocation via 0x00587C03 + 0x004B57F0, then load-entries and list-count dispatch). 0x004D24A0 is a session predicate over the dword_7C54F0 active-vehicle array bounded by dword_5C329C. The remaining functions are pure math helpers with no evidenced owning object: a 17-function transform library (interface VectorMatrixTransformMath) writing a shared 4-float output layout at +0x0/+0x4/+0x8/+0xC, and a GUESS quaternion-composition group (0x0050E342 blend, 0x0051FEBE component packing, 0x005267A7 multi-input composition with jump table 0x0052690F). Owners are packet-UNKNOWN except 0x005267A7 (DERIVED). Several prelabel cluster-copy twin assignments (0x0051ECEE/FloatClamp, 0x00526CA8/sub_410AF0, 0x00526D36/FloatClamp) conflict with the raw math and are not adopted.

## Function roles

- `0x004046B0` **WheelContactHeightField** — Per-node wheel-contact height reconstruction/smoothing over the stride-316 element array (count this+0x130, base this+0x134): below the node-type threshold this+0x10 the +76 contact height is zeroed and rebuilt by walking the +272/+268 ancestor chain accumulating (*(node+268)+76) + (*(node+268)+60); at/above the threshold the height is averaged against a spatial neighbor found via SpatialNearestNeighborQueryWithPlaneTest (0x004038E0).
- `0x00404790` **WheelContactHeightField** — Iterates the same stride-316 element array (count this+0x130, base this+0x134) and calls the unregistered helper 0x004FB5D0 with each element pointer; returns the element count.
- `0x00435280` **PhysicsStateInitializer** — Thin wrapper that forwards the address of the global double dbl_7C7428 to a downstream physics-init routine and returns its result unchanged; the global is addressed but not dereferenced here.
- `0x00465160` **WheelSpeedSetter** — Zero-guarded conversion of two speed inputs (a2, a3) into wheel-speed units (integer formula 1000*x/8), stored into target offsets +0x50 and +0x54 of the object resolved through this+0x0; each store happens only when the promoted input is greater than 0.0.
- `0x004B9780` **CarPhysicsStateAllocator** — Allocates a 3996-byte block via OperatorNewNhMallocWrapper (0x00587C03); on success initializes it with CarPhysicsStateInitializer (0x004B57F0) and stores the returned pointer at this+0x0, otherwise stores 0 at this+0x0; returns this.
- `0x004B9810` **CarPhysicsStateAllocator** — Single-function dispatch wrapper: dereferences this+0x0 and passes the loaded pointer to LoadVehicleEntries, returning the callee result unchanged; no null guard.
- `0x004B9D80` **CarPhysicsStateAllocator** — Single-function dispatch wrapper: dereferences this+0x0 and passes the loaded pointer to VehicleListCountGetter, returning the callee result unchanged; no null guard.
- `0x004D24A0` **SessionEndConditionCheck** — Session predicate over active vehicles: returns true when dword_5C329C is non-positive, or when every one of the first dword_5C329C pointers in the dword_7C54F0 array points to a vehicle whose dword at +0x4064 is nonzero; returns false as soon as one active vehicle's +0x4064 dword is zero.
- `0x0050C525` **VectorMatrixTransformMath** — Column-major 4x4 affine transform of a 3-component input vector (translation in matrix column 3, a3[12..15]) into a 4-component output; branchless, returns the output pointer.
- `0x0050CA2D` **VectorMatrixTransformMath** — Row-major 4x4 matrix times 4-component vector transform; each output component is one matrix row dotted with the input vector; returns the output pointer.
- `0x0050E342` **QuaternionTransformComposition** — Weighted blend of two transforms: total weight v10 = a5 + a6; when FloatRangeCheck (0x0050C042) reports it near zero the source a2 is copied to a1 verbatim, otherwise two intermediates are built via ThunkToFUN0050e174 (0x0050E198) and blended with normalized weight a6/v10.
- `0x0050E760` **VectorMatrixTransformMath** — 2D-affine 4x4 transform: 2-component input (a2[0], a2[1]) treated as [x, y, 0, 1] row-vector times matrix a3, producing a 4-component output; matrix column 2 and input z are unused.
- `0x0050E7CB` **VectorMatrixTransformMath** — 2D-point transform by 4x4 matrix into the homogeneous triple (X, Y, w); perspective-divides X/Y by w when FloatRangeCheck (0x0050C042) reports w is not approximately 1.0.
- `0x0050E927` **VectorMatrixTransformMath** — 3D-point transform by 4x4 matrix into (X, Y, Z, w); perspective-divides X/Y/Z by w when FloatRangeCheck (0x0050C042) reports w is not approximately 1.0.
- `0x005174CB` **VectorMatrixTransformMath** — 2-component vector transform by a row-major 4x4 matrix (translation column a3[12..15]) into a 4-component output; branch-free, returns the output pointer.
- `0x00517569` **VectorMatrixTransformMath** — 3-component point transform by a 4x4 matrix (translation embedded in a3[12..15], implicit homogeneous 1); writes all four output components and returns the output pointer.
- `0x005175F4` **VectorMatrixTransformMath** — 3-component vector transform where each output component is the dot product of the input with one stride-4 matrix column; writes a 3-component output.
- `0x00517653` **VectorMatrixTransformMath** — 4-component vector times row-major 4x4 matrix transform; each output component is one matrix row dotted with the full input vector.
- `0x0051ECEE` **VectorMatrixTransformMath** — SSE 4x4-matrix by 3-component-vector transform; matrix pointer alignment (a3 & 0xF) selects aligned (columns +0/+16/+32/+48) vs unaligned (columns +8/+24/+40/+56) column loads.
- `0x0051FEBE` **QuaternionTransformComposition** — Packs three unsigned component inputs plus constant dword_8D6160 into an SSE vector, applies the channel mask xmmword_8D6150, passes it through RGBAColorSpaceConversion (0x005289E0), then applies a shuffle/multiply/add/xor sequence with sign mask xmmword_8D6140 and writes the __m128 result to the output.
- `0x0051FF8E` **VectorMatrixTransformMath** — SSE 3-component vector transform through a 3x4 matrix (x*row0 + y*row1 + z*row2); matrix alignment dispatches between unaligned 8-byte half-row loads and aligned __m128 row loads.
- `0x0052004E` **VectorMatrixTransformMath** — SSE 3-component vector transform by a matrix with an unweighted translation row, then divides all components by the w lane using an SSE reciprocal refined by one Newton-Raphson iteration.
- `0x0052156F` **VectorMatrixTransformMath** — 3DNow lookup-based scaled transform: queries a 12-byte precomputed entry through 0x005262C2 by selector a2, scales input a3 by 0.5, expands lanes via PackedFloatingPointMath (0x005295E0), and writes the packed __m64 output pair.
- `0x00521712` **VectorMatrixTransformMath** — 3DNow two-stage vector normalization composition: normalizes a3 and a4 relative to base vector a2 with factor (a5+a6), then normalizes the first result relative to the second with scale a6/(a5+a6) using a refined reciprocal; outputs via SIMDVectorNormalization (0x005215DB).
- `0x00526550` **VectorMatrixTransformMath** — 3DNow 4D vector transform: pairs the 4-component input words, accumulates SIMD products against coefficient table a3[0..7], divides through the w component with a refined 3DNow reciprocal, and writes a full __m64 product plus a truncated 32-bit value.
- `0x005267A7` **QuaternionTransformComposition** — Composes a 3D transform from up to three inputs selected by the null-state of a6/a7/a8 (jump table global 0x0052690F), applies the transform to a4 writing a3 via F_4DVectorTransform (0x00526550), then optionally applies an MMX packed-float weight blend from a5 using constants 0x005AF980/0x005AF988/0x005AF990.
- `0x00526CA8` **VectorMatrixTransformMath** — 3DNow 2-component vector transform: duplicates the two input lanes and forms two linear combinations against the 8-slot coefficient matrix a3 (a1[0] = a3[0]*x + a3[2]*y + a3[6], a1[1] = a3[1]*x + a3[3]*y + a3[7]).
- `0x00526D36` **VectorMatrixTransformMath** — 3DNow perspective-style 2-component transform: forms two linear combinations over the packed pairs at a3[0..3]/a3[6..7], uses the second combination's high lane as a reciprocal-approximated divisor, and stores the scaled first combination into the output.

## Proposed classes

### WheelContactHeightField

Owns the stride-316 wheel-contact element array (count this+0x130, base this+0x134) and the node-type threshold this+0x10; reconstructs per-node contact heights through ancestor chains below the threshold and smooths them via spatial-neighbor averaging at/above it.

Methods: `0x004046B0`, `0x00404790`

- `this+0x00000010` `int node_type_threshold` (read, GUESS)
- `this+0x00000130` `int element_count` (read, DERIVED)
- `this+0x00000134` `pointer elements` (read, DERIVED)

### CarPhysicsStateAllocator

Owns a pointer member at this+0x0 holding a car physics / vehicle-entry state object; allocates and initializes it as a 3996-byte block, then dispatches vehicle-entry loading and vehicle-list count queries through it.

Methods: `0x004B9780`, `0x004B9810`, `0x004B9D80`

- `this+0x00000000` `pointer car_physics_state` (read_write, GUESS)

### SessionEndConditionCheck

Evaluates the all-active-vehicles-satisfy-flag predicate over the global active-vehicle pointer array dword_7C54F0 bounded by dword_5C329C; a vehicle's dword at +0x4064 must be nonzero for a true result.

Methods: `0x004D24A0`


### WheelSpeedSetter

Holds a target-object pointer at this+0x0 and converts two speed inputs to wheel-speed units (1000*x/8) under positive-input guards, storing the results at target offsets +0x50/+0x54.

Methods: `0x00465160`

- `this+0x00000000` `pointer target_object_ptr` (read, GUESS)
- `obj+0x00000050` `int wheel_speed_0` (write, DERIVED)
- `obj+0x00000054` `int wheel_speed_1` (write, DERIVED)

### PhysicsStateInitializer

Initializes global physics state by forwarding the address of the dbl_7C7428 global to a downstream physics-init routine whose target is outside this packet.

Methods: `0x00435280`


### QuaternionTransformComposition

Builds, blends and composes quaternion-style 4-component transform representations: weighted SLERP-like blend (0x0050E342), component packing through color-space conversion (0x0051FEBE), and multi-input composition with an optional packed-float weight blend (0x005267A7).

Methods: `0x0050E342`, `0x0051FEBE`, `0x005267A7`


### Vec4TransformOutput

The 16-byte, 4-float output-vector buffer written by the transform helpers (components at +0x0/+0x4/+0x8/+0xC); an ephemeral write destination, not a long-lived owning object.

Methods: 

- `this+0x00000000` `float x` (write, GUESS)
- `this+0x00000004` `float y` (write, GUESS)
- `this+0x00000008` `float z` (write, GUESS)
- `this+0x0000000C` `float w` (write, GUESS)

## Compatibility contracts

- **WheelContactElementArrayLayout** — The wheel-contact element array lives at this+0x134 with element count at this+0x130 and a fixed 316-byte stride. A replacement must preserve the stride, the node-type threshold at this+0x10, the contact-height rebuild/smoothing behavior of 0x004046B0 (ancestor-chain accumulation below the threshold, spatial-neighbor averaging at/above it via the spatial query 0x004038E0), and the per-element pass of the unregistered helper 0x004FB5D0 by 0x00404790.
- **CarPhysicsStateAllocation** — Car physics state is allocated as a 3996-byte block through the operator-new wrapper 0x00587C03, initialized by CarPhysicsStateInitializer 0x004B57F0, and the resulting pointer stored at this+0x0 (null stored on allocation failure). A replacement must reproduce the allocation size, the init path, and the null-on-failure behavior of 0x004B9780, and must keep the this+0x0 pointer loadable for the vehicle-entry dispatch wrappers 0x004B9810/0x004B9D80.
- **ActiveVehicleFlagPredicate** — Session end-condition evaluation calls 0x004D24A0, which reads the active-vehicle pointer array dword_7C54F0 bounded by the count dword_5C329C and requires every active vehicle's dword at +0x4064 to be nonzero for a true result. A replacement must preserve this predicate and the two globals it consumes.
- **WheelSpeedUnitConversion** — Wheel speeds are converted with the integer formula 1000*x/8 under a positive-input guard and stored at target offsets +0x50/+0x54 of the object resolved through this+0x0. A replacement must reproduce the conversion, the guard (non-positive inputs skip their store), and the two target offsets.
- **TransformOutputVectorLayout** — Vector/matrix transform helpers write a 4-float output at +0x0/+0x4/+0x8/+0xC and return the output pointer; perspective helpers (0x0050E7CB, 0x0050E927, 0x0052004E, 0x00526D36) divide the transformed components by homogeneous w when w is not approximately 1.0 (tolerance supplied by FloatRangeCheck 0x0050C042). A replacement must preserve this output layout and the divide condition.
- **QuaternionCompositionDispatch** — 0x005267A7 selects among up to three transform sources by the null-state combination of three inputs via the jump table at global 0x0052690F (8 cases including identity, passthrough and pairwise/all-three composition through 0x005265DB), applies the selected transform through F_4DVectorTransform (0x00526550), and optionally blends the output with packed-float weights from a5 using constants 0x005AF980/0x005AF988/0x005AF990. A replacement must preserve the case-to-composition mapping and the transform application order.

## Unresolved

- Element struct layout of the stride-316 wheel-contact array (offsets +60, +76, +268, +272, +276, +300) is only partially understood; the +268 parent/back and +272 next-node pointer roles are inferred from the walk pattern, not proven.
- Meaning of the node-type threshold this+0x10 and the node-type enum at element +300 is not established by the packet.
- The unregistered helper 0x004FB5D0 is undocumented (FAILNODOCENTRY); its per-element effect is unknown.
- The helper 0x004038E0 (SpatialNearestNeighborQueryWithPlaneTest) is outside this packet and its query semantics are not detailed here.
- LoadVehicleEntries and VehicleListCountGetter are named only in the decompiled source text; their target addresses are absent from the packet callee list, so those two calls are evidenced by source text alone.
- The physics-init callee of 0x00435280 is absent from the packet callee list; the call target cannot be confirmed, and the type/role of the global double dbl_7C7428 is unestablished.
- Global flt_59E440 (0x0059E440) does not appear in the raw source of 0x00465160; its role as the zero-threshold constant is DERIVED from prior analysis, not confirmed.
- Global flt_59E450 (0x0059E450) is listed in the packet globals but is not referenced in the raw source of 0x004046B0; its role is unresolved.
- The +0x4064 per-vehicle dword read by 0x004D24A0 is unnamed here; a nonzero value likely flags a completed/retired state but that is not evidenced.
- dword_5C329C is treated as the count of active slots because it bounds the dword_7C54F0 scan; its exact semantics are inferred, not named.
- CarPhysicsStateAllocator is a GUESS grouping: 0x004B9780, 0x004B9810 and 0x004B9D80 share the this+0x0 pointer-member pattern but their callers are not fully proven common, and the 3996-byte object type is unconfirmed.
- Whether CarPhysicsStateInitializer (0x004B57F0) returns its argument or a different pointer is not evidenced.
- Caller 0x00463F70 (SessionTypeSetter) mentioned in the 0x00465160 summary is not in the allowed evidence set and was not used as a fact.
- Row-major vs column-major matrix orientation is not provable for several transform helpers; the stride-4 layout with translation in m[12..15] is certain, the orientation is not.
- QuaternionTransformComposition is a GUESS grouping inferred from ABI-lead naming (Quaternion_SLERP, QuaternionConstructionTransform); 0x0051FEBE's use of RGBAColorSpaceConversion (0x005289E0) and color channel/sign masks is unexplained for a quaternion role.
- The 0x005267A7 packed-float blend formula (which a3 components are weighted and how a5 integers map to an interpolation factor) is opaque in the MMX/3DNow intrinsics; which constant each of 0x005AF980/0x005AF988/0x005AF990 holds is not confirmed.
- Composition ordering semantics for the all-three-present case (case 7) of 0x005267A7 are unverified.
- Global qword_5AF990 appears in the deterministic facts of 0x0052156F but is absent from its raw source; the 12-byte lookup entry layout produced by 0x005262C2 is undocumented.
- The 0x00526550 a1[1] 32-bit truncation suggests a fixed-point or screen-space result, but the interpretation is unconfirmed.
- The prelabel cluster-copy twin assignments for 0x0051ECEE (FloatClamp 0x004646C0), 0x00526CA8 (sub_410AF0) and 0x00526D36 (FloatClamp 0x004646C0) conflict with the raw transform math and were not adopted.
- No caller evidence links the transform helpers to a specific owning class; owners stay UnknownObject/UNKNOWN and the VectorMatrixTransformMath interface is a synthesis.
