# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Packet wave_007_generic_runtime_objects_14 covers 41 functions in the 0x0050C665..0x0050E540 band. Eleven are straight-line 4-float math helpers (vector cross-product-like combination, cubic Hermite and bilinear interpolation, Euler/axis-angle to quaternion, quaternion multiply/normalize/conjugate/slerp, plane-from-point-normal). The remaining thirty are an indirect-dispatch family: twenty-two wrappers each call the gate sub_50FEA7(1u) and then forward arguments through a distinct global function-pointer slot (0x005D77D4..0x005D78A8), and eight pure thunks forward through the same slots without the gate call. Several slots are shared by a wrapper/thunk pair (0x5D7810, 0x5D7814, 0x5D781C, 0x5D782C, 0x5D7854), indicating the slots are entries of a single runtime-resolved dispatch table. QuadraticBezier consumes the 0x5D7854 slot via the ThunkToFUN0050e174 hop. No function in this packet owns state; all owners are unknown, and the quaternion helpers rely on the shared epsilon test FloatRangeCheck (0x0050C042).

## Function roles

- `0x0050C665` **Float4VectorMath** — Four-component cross-product-like vector helper; straight-line computation writing a1[0..3] from weighted pairwise products of three inputs; returns output buffer.
- `0x0050C762` **IndirectDispatchWrapper** — Indirect-dispatch wrapper: calls gate sub_50FEA7(1u), then forwards six arguments through slot off_5D7898.
- `0x0050C78C` **Float4VectorMath** — Cubic Hermite interpolation of a four-component vector using basis coefficients computed from parameter a6; writes a1[0..3], returns a1.
- `0x0050C85D` **IndirectDispatchWrapper** — Indirect-dispatch proxy: calls gate sub_50FEA7(1u), then forwards six arguments through slot off_5D789C.
- `0x0050C97A` **IndirectDispatchWrapper** — Indirect-dispatch wrapper: calls gate sub_50FEA7(1u), then forwards six arguments through slot off_5D78A0.
- `0x0050C9A9` **Float4VectorMath** — Bilinear interpolation of a four-component float vector; out[i] = (edgeA[i]-base[i])*wA + (edgeB[i]-base[i])*wB + base[i]; returns out pointer.
- `0x0050CBA3` **IndirectDispatchWrapper** — Dispatch pair (cdecl, no args): calls gate sub_50FEA7(1u), then dispatches through slot off_5D77D4.
- `0x0050CDEC` **IndirectDispatchWrapper** — Dispatch pair (cdecl, no args): calls gate sub_50FEA7(1u), then dispatches through slot off_5D785C.
- `0x0050D0AF` **IndirectDispatchWrapper** — Dispatch pair (cdecl, no args): calls gate sub_50FEA7(1u), then dispatches through slot off_5D7810.
- `0x0050D0BC` **IndirectDispatchThunk** — Pure dispatch thunk (no gate): tail-calls the function pointer stored in slot off_5D7810; invoked by caller 0x0050EB73.
- `0x0050D44F` **IndirectDispatchWrapper** — Indirect-dispatch proxy: calls gate sub_50FEA7(1u), then forwards four arguments through slot off_5D784C.
- `0x0050D4D9` **IndirectDispatchWrapper** — Delegation wrapper: calls gate sub_50FEA7(1u) as pre-call hook, then forwards four arguments through slot off_5D7830.
- `0x0050D563` **IndirectDispatchWrapper** — Delegation wrapper: calls gate sub_50FEA7(1u), then forwards two arguments through slot off_5D7840.
- `0x0050D5F9` **IndirectDispatchWrapper** — Delegation wrapper: calls gate sub_50FEA7(1u), then forwards two arguments through slot off_5D7844.
- `0x0050D728` **IndirectDispatchWrapper** — Dispatch thunk: ensures shared table initialized via sub_50FEA7(1u), then tail-calls slot off_5D7870 forwarding three arguments.
- `0x0050D857` **IndirectDispatchThunk** — Pure dispatch thunk (no gate): forwards through slot off_5D7860; called by 0x0050D9A5, 0x0050EDD2, 0x0050EE0B on a transform/skeleton path.
- `0x0050D93F` **IndirectDispatchWrapper** — Dispatch thunk: ensures shared table initialized via sub_50FEA7(1u), then tail-calls slot off_5D7868 forwarding four arguments; performs no arithmetic itself.
- `0x0050D96D` **IndirectDispatchWrapper** — Indirect-dispatch proxy: calls gate sub_50FEA7(1u), then calls slot off_5D7864 with no arguments.
- `0x0050D97E` **IndirectDispatchWrapper** — Dispatch thunk: ensures shared table initialized via sub_50FEA7(1u), then tail-calls slot off_5D786C forwarding five arguments.
- `0x0050DC90` **IndirectDispatchWrapper** — Indirect-call wrapper: calls gate sub_50FEA7(1u), then forwards three arguments through slot off_5D783C.
- `0x0050DD0C` **IndirectDispatchWrapper** — Indirect-call wrapper: calls gate sub_50FEA7(1u), then forwards four arguments through slot off_5D782C.
- `0x0050DD3A` **IndirectDispatchThunk** — Pure dispatch thunk (no gate): forwards four arguments through slot off_5D782C; called by TwoThunkWrapper 0x0050EDD2.
- `0x0050DD40` **QuaternionMath** — Euler-angle to quaternion helper: halves three angles, combines half-angle sin/cos into quaternion (x,y,z,w) written to a1, returns a1.
- `0x0050DE19` **IndirectDispatchWrapper** — Indirect-dispatch proxy: calls gate sub_50FEA7(1u), then calls slot off_5D7814 with no arguments.
- `0x0050DE26` **IndirectDispatchThunk** — Pure dispatch thunk (no gate): tail-calls the function pointer stored in slot off_5D7814; invoked by caller QuaternionSlERP 0x0050F258.
- `0x0050DE2C` **QuaternionMath** — Quaternion Hamilton product: multiplies quaternion a3 by a2 into a1 (x,y,z,w, scalar at index 3), returns a1.
- `0x0050DECF` **QuaternionMath** — Quaternion normalization: unit-normalizes a2 into a1 via squared-norm, FloatRangeCheck(1.0) fast path, 1/sqrt scaling, or zeroing for near-zero norm; returns a1.
- `0x0050DF88` **IndirectDispatchWrapper** — Indirect-dispatch proxy: calls gate sub_50FEA7(1u), then calls slot off_5D7878 with no arguments.
- `0x0050DF9B` **QuaternionMath** — Quaternion conjugate and normalize: writes conjugate (negated vector part) into a1, zeroes output for degenerate norm, renormalizes via squared-norm reciprocal unless FloatRangeCheck(1.0); returns a1.
- `0x0050E04F` **IndirectDispatchThunk** — Pure dispatch thunk (no gate): tail-calls the function pointer stored in slot dword_5D78A4; invoked by caller QuaternionSlERP 0x0050F258.
- `0x0050E0D3` **IndirectDispatchThunk** — Pure dispatch thunk (no gate): calls the function pointer stored in slot dword_5D78A8; reached from QuaternionSlERP 0x0050F258 as an indirect dispatch site.
- `0x0050E0D9` **QuaternionMath** — Axis-angle to quaternion helper: angle = |a2|, writes a1[3]=cos(angle), a1[0..2]=axis*sin(angle)/angle guarded by FloatRangeCheck(sin,0.0); returns a1.
- `0x0050E174` **IndirectDispatchWrapper** — Indirect-call wrapper: calls gate sub_50FEA7(1u), then forwards four arguments through slot off_5D7854.
- `0x0050E198` **IndirectDispatchThunk** — Pure dispatch thunk (no gate): forwards four arguments through slot off_5D7854; the shared dispatch hop used by QuadraticBezier 0x0050E2AB and 0x0050E342.
- `0x0050E19E` **QuaternionMath** — Quaternion spherical linear interpolation between a2 and a3 with factor a4, shortest-path sign flip, near-parallel linear fallback, trig weights otherwise; writes a1, returns a1.
- `0x0050E281` **IndirectDispatchWrapper** — Indirect-dispatch forwarder (DX wrapper layer): calls gate sub_50FEA7(1u), then tail-calls slot off_5D7874 forwarding six arguments.
- `0x0050E2AB` **QuadraticBezierEvaluator** — Quadratic-bezier evaluation helper: builds two intermediate 4-component control vectors and the blend result via three dispatches through ThunkToFUN0050e174 (0x0050E198); returns output pointer.
- `0x0050E313` **IndirectDispatchWrapper** — Indirect-call wrapper: calls gate sub_50FEA7(1u), then forwards six arguments through slot off_5D7858.
- `0x0050E3CD` **IndirectDispatchWrapper** — Indirect-call wrapper: calls gate sub_50FEA7(1u), then calls through slot off_5D781C.
- `0x0050E3DA` **IndirectDispatchThunk** — Pure return thunk (no gate): calls through slot off_5D781C; invoked by F_4x4MatrixReflectionTransform 0x0050F0BF and sub_50F199 0x0050F199.
- `0x0050E540` **PlaneEquationBuilder** — Plane-equation helper: copies normal a3[0..2] into a1+0/+4/+8 and stores negated dot product -(a2 dot a3) at a1+12; returns a1.

## Proposed classes

### Float4VectorMath

Straight-line four-component float vector math helpers operating on a caller-supplied 4-float output buffer (base this): cross-product-like combination, cubic Hermite interpolation, bilinear interpolation. All return the output buffer pointer. Grouping is DERIVED from the identical float[4] buffer pattern; these are free __stdcall functions, not a proven C++ class.

Methods: `0x0050C665`, `0x0050C78C`, `0x0050C9A9`

- `this+0x00000000` `float component_0` (read_write, GUESS)
- `this+0x00000004` `float component_1` (read_write, GUESS)
- `this+0x00000008` `float component_2` (read_write, GUESS)
- `this+0x0000000C` `float component_3` (read_write, GUESS)

### QuaternionMath

Quaternion construction and manipulation helpers operating on a caller-supplied 4-float quaternion buffer (base this, x/y/z/w with scalar at index 3): Euler-angles and axis-angle construction, Hamilton multiply, normalize, conjugate+normalize, spherical linear interpolation. All are free __stdcall functions writing all four output components; the class grouping is inferred from the quaternion arithmetic, not evidenced as a single C++ class.

Methods: `0x0050DD40`, `0x0050DE2C`, `0x0050DECF`, `0x0050DF9B`, `0x0050E0D9`, `0x0050E19E`

- `this+0x00000000` `float x` (read_write, GUESS)
- `this+0x00000004` `float y` (read_write, GUESS)
- `this+0x00000008` `float z` (read_write, GUESS)
- `this+0x0000000C` `float w` (read_write, GUESS)

### PlaneEquationBuilder

Builds a plane equation (ax+by+cz+d=0) from a point-on-plane vector and a normal: copies the three normal components to this+0/+4/+8 and stores the negated dot product at this+0xC as the signed plane constant. Free __stdcall helper; class identity not evidenced.

Methods: `0x0050E540`

- `this+0x00000000` `float normal_x` (read_write, GUESS)
- `this+0x00000004` `float normal_y` (read_write, GUESS)
- `this+0x00000008` `float normal_z` (read_write, GUESS)
- `this+0x0000000C` `float distance` (write, GUESS)

### IndirectDispatchWrapper

Indirect-dispatch entry points that first call the shared gate sub_50FEA7(1u) (lazy initialization / enable of the version-adaptive function table) and then forward their arguments unchanged through a distinct runtime-resolved function-pointer slot (0x005D77D4..0x005D78A8), returning the indirect call's result. The wrappers share the gate+slot shape, not a proven class hierarchy.

Methods: `0x0050C762`, `0x0050C85D`, `0x0050C97A`, `0x0050CBA3`, `0x0050CDEC`, `0x0050D0AF`, `0x0050D44F`, `0x0050D4D9`, `0x0050D563`, `0x0050D5F9`, `0x0050D728`, `0x0050D93F`, `0x0050D96D`, `0x0050D97E`, `0x0050DC90`, `0x0050DD0C`, `0x0050DE19`, `0x0050DF88`, `0x0050E174`, `0x0050E281`, `0x0050E313`, `0x0050E3CD`


### IndirectDispatchThunk

Thin forwarding thunks that read a runtime-resolved function-pointer slot (0x005D7810..0x005D78A8) and tail-call it without the sub_50FEA7 gate. Several slots are shared with a gate-calling wrapper (0x5D7810, 0x5D7814, 0x5D781C, 0x5D782C, 0x5D7854), so each slot is an entry of the shared dispatch table reachable via both a gate-ensured and a plain path.

Methods: `0x0050D0BC`, `0x0050D857`, `0x0050DD3A`, `0x0050DE26`, `0x0050E04F`, `0x0050E0D3`, `0x0050E198`, `0x0050E3DA`


### QuadraticBezierEvaluator

Quadratic-bezier evaluation helper that composes two intermediate 4-component control vectors and a blend result by dispatching through the shared math slot ThunkToFUN0050e174 (0x0050E198 / off_5D7854). Class identity is a GUESS grouping of a single function; the dispatched target's semantics live behind the slot.

Methods: `0x0050E2AB`


## Compatibility contracts

- **SharedDispatchTableSlotLayout** — A replacement executable must preserve the set of runtime-resolved function-pointer slots at 0x005D77D4..0x005D78A8 and the forwarding shape of the wrappers/thunks that read them. Slots are shared across a gate-ensured wrapper and a plain thunk (0x5D7810, 0x5D7814, 0x5D781C, 0x5D782C, 0x5D7854), so both paths must resolve the same per-slot target.
- **DispatchGateBeforeSlotForward** — Gate wrappers must invoke sub_50FEA7 with the constant 1 before dispatching through their slot; the gate lazily initializes / enables the shared function table on first call. Preserving the gate-before-forward ordering is required for the table to be usable on the wrapper path.
- **QuaternionFloat4Layout** — Quaternion helpers read and write a caller-supplied 4-float buffer in x,y,z,w order with the scalar term at index 3 (this+0x0..0xC). All output components are written unconditionally on every path, so a consumer cannot rely on stale output bytes; an external poke to the output does not persist.
- **FloatRangeEpsilonGuard** — Near-zero / unit-length decisions route through the shared FloatRangeCheck at 0x0050C042. Quaternion normalization treats squared norm within tolerance of 1.0 as already-unit, below 1.1754944e-38 as zero-fill, and conjugate+normalize treats squared norm at or below 1.0842022e-19 as degenerate (zero output). A replacement must preserve these thresholds and the all-four-components-written invariant.
- **MathHelperOutputPointerConvention** — The straight-line math helpers (vector interpolation, quaternion construction, plane equation, bezier) are __stdcall/free helpers that return the caller-supplied output buffer pointer a1; the output buffer is not owned by the helper. Callers must supply valid output storage and treat the returned pointer as the result address.

## Unresolved

- Purpose and side effects of the gate sub_50FEA7(1u) call are unknown from this packet; the constant 1 is described as an enable flag only by the packet summary, not evidenced.
- The runtime targets stored in the dispatch slots (0x005D77D4..0x005D78A8) are assigned elsewhere at runtime and are not statically resolvable; the owner that installs them is unknown.
- The callee entries callee:0x0050C762, callee:0x0050C85D, callee:0x0050C97A, callee:0x0050D44F, callee:0x0050D4D9, callee:0x0050D563, callee:0x0050D5F9, callee:0x0050D728, callee:0x0050D93F, callee:0x0050D97E, callee:0x0050DC90, callee:0x0050DD0C, callee:0x0050E174, callee:0x0050E281 and callee:0x0050E313 are packet-generation self-reference artifacts (each equals its function's own address) and are not genuine recursive calls.
- Read-only math constants flt_59E43C, flt_59E440, flt_59E450, flt_59E478, flt_5AC9C0, flt_5ADE40 and flt_5ADE44 are listed as read globals but the raw source renders their loads as folded literals (1.0, 0.0, degrees-to-radians scale, 0.00000011920929, 1.1754944e-38, 1.0842022e-19); the global-to-literal mapping is DERIVED and unproven.
- The math-helper classes (Float4VectorMath, QuaternionMath, PlaneEquationBuilder, QuadraticBezierEvaluator) group free __stdcall functions by their float[4] buffer arithmetic; common ownership of the this+0x0..0xC buffers across vector, quaternion, and plane objects is not proven (rule: equal offsets on unrelated this pointers are not proof of identical objects).
- AxisAngleToQuaternion (0x0050E0D9) degenerate near-zero-angle branch copies a1[0..2] from an uninitialized register-derived pointer v2; the intended copy source is unresolved.
- QuaternionSlerp (0x0050E19E) records no callees, so the trigonometric library functions (sin, cos, sqrt, atan2) it invokes are not evidenced in this packet.
- QuadraticBezier (0x0050E2AB) reads its blend factor as (1.0-a6)*a6 + (1.0-a6)*a6 in the raw source, an unusual doubling of the (1-t)*t weight; preserved verbatim, not rewritten to canonical 2*(1-t)*t.
- Which weight (a5 vs a6) pairs with which edge corner (a3 vs a4) in BilinearInterp4Component (0x0050C9A9) is inferred from formula symmetry, not independently evidenced.
- FloatRangeCheck's exact epsilon literals are defined in 0x0050C042, not in this packet; only its use as a near-zero/unit-length guard is evidenced here.
- Rotation order implied by EulerAnglesToQuaternion (0x0050DD40) cross-term composition is not confirmed against any caller's convention; no static callers are recorded for the math helpers.
