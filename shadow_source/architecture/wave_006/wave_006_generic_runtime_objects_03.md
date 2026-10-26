# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Twenty-three functions reconstruct shared runtime computation objects used by the F1C vehicle physics and collision paths. A cluster of suspension/spring functions (PiecewiseFunctionEval 0x00436610, DeltaUpdateTracking 0x0043BB00, QuadFunctionEval 0x0043BB30, QuadraticForceTorqueCalculator 0x0043BB80, SpringDamperCompute 0x0043BBD0, ClampedSpringIntegrator 0x0043E980, DoubleAccumulatorClamp 0x0043EA70) reads and writes overlapping coefficient/accumulator regions of a large per-vehicle state object; a rigid-body cluster (AccumulateAngularImpulse 0x0043E5D0, VelocityDampingFromSpeedError 0x00441AD0, RigidBodyTorqueAccumulation 0x00441BB0, ApplyForceTorqueToRigidBody 0x00441F00, ComputeDamperSpringAndAntiRollForces 0x004432F0, GetBodyMotionState 0x00447100) accumulates forces/torques into body force buffers reachable through this+0x15F0/0x1D4 and reads shared per-vehicle state through this+0x1F00. A geometry/collision cluster (TrigTableLookup 0x00447AB0, Vec3Subtract 0x004484C0, SquaredMagnitudeMixedPrecision 0x004484F0, SpatialTreeInsertion 0x004485D0, DynamicsBVHNodeRecursiveTraversal 0x00448E50, SmallStructCopy 0x00448EC0, TriangleEdgeHalfPlaneComputation 0x00448F00, SATSeparatingAxisTest 0x00448FC0, SegmentIntersection2DTest 0x00449000, VisibilityFrustumTest 0x0044A170) provides trig lookup, mixed-precision vertex records, a 96-byte-node spatial tree, and SAT edge/plane/segment intersection helpers consumed by SATEdgeSeparationTest and TriangleMeshAdjacencyBuilder. Only ClampedSpringIntegrator has a named DERIVED owner from the packet; all other owners are UNKNOWN, and the single-owner class grouping below is a DERIVED/GUESS proposal.

## Function roles

- `0x00436610` **PiecewiseResponseCurve** — Evaluate a two-input piecewise response curve: a3 selects one of three linear segments by sign and threshold, a2 scales the segment result, and a boundary-excess correction pair applies when a2 falls outside the [lower,upper] window.
- `0x0043BB00` **VehiclePhysicsState** — Per-frame delta accumulator: store incoming value, scale the frame delta by a smoothing factor, and accumulate it on the frame path.
- `0x0043BB30` **VehiclePhysicsState** — Evaluate two quadratic curves a*x^2+b*x+c from per-curve coefficient triples and write both results plus the input back to the state object.
- `0x0043BB80` **VehiclePhysicsState** — Store the input value and evaluate two quadratics into force/torque output slots (interpreted, DERIVED) for a vehicle dynamics evaluation.
- `0x0043BBD0` **VehiclePhysicsState** — Evaluate three linear curves y = a2*slope + intercept from per-curve coefficient pairs and write results to the three output slots.
- `0x0043E5D0` **VehiclePhysicsState** — Accumulate a contact impulse and the cross-product torque it produces around the contact point into the state's impulse and torque triples, then forward both to the shared collision-impulse accumulator.
- `0x0043E980` **ClampedSpringIntegrator** — Integrate two spring accumulator slots with fixed rates, clamp each into a window around its reference, and dispatch spring/damper curve evaluation.
- `0x0043EA70` **VehiclePhysicsState** — Accumulate a scaled input into the clamp accumulator and clamp it into the window derived from a reference field.
- `0x00441AD0` **VehiclePhysicsState** — Compute an aerodynamic velocity-damping force from the body speed error, guarded by shared-state enable/mode flags and a global flag, and accumulate it into the body force buffer.
- `0x00441BB0` **VehiclePhysicsState** — Accumulate a torque-like contribution between the source body and the target body: rotate a local vector, form a lever arm, scale by body/state parameters, and add into the target body force buffer.
- `0x00441F00` **VehiclePhysicsState** — Apply per-wheel force/torque through a 3x4 inertia-tensor matrix into the four wheel-slot output vectors, gated by an active byte.
- `0x004432F0` **VehiclePhysicsState** — Per-corner suspension and anti-roll bar force computation for one axle: clamp travel averages, write damper force, solve 6x6 couplings, accumulate torque into the chassis body, optional helper-spring abutment force, wheel-ground contact solves, and two anti-roll bar coupling blocks.
- `0x00447100` **VehiclePhysicsState** — Query accessor: compute suspension spring/damper force and torque into two result vectors and copy them into the caller-supplied output arrays.
- `0x00447AB0` **UnknownObject** — Linear-interpolated lookup into a 256-entry single-precision trig table using a scaled, byte-wrapped table index.
- `0x004484C0` **TriangleVertexRecord** — Element-wise subtract of two mixed-precision 16-byte records (float/double/float), writing into this and returning the source pointer.
- `0x004484F0` **TriangleVertexRecord** — Squared magnitude of a mixed-precision three-component record (float/double/float) as the sum of squared components.
- `0x004485D0` **SpatialTreeNode** — Insert or locate a node in a 96-byte-node spatial tree keyed by (float, double, float), allocating new nodes and descending chain/branch slots.
- `0x00448E50` **SpatialTreeNode** — Recursive traversal of a dynamics BVH node chain: process the linked-list payload, recurse into four child slots, and advance through the sibling pointer.
- `0x00448EC0` **CollisionBody** — Copy a collision-body type byte and handle word pair into this during collision-body initialization.
- `0x00448F00` **SATCollisionHelpers** — Compute inward-facing half-plane (nx, ny, d) coefficient triples for all three triangle edges with a small outward bias, into the caller's output buffer.
- `0x00448FC0` **SATCollisionHelpers** — Test a point against consecutive half-plane coefficient triples beginning at a1+0x10; true only when the point lies beyond all three planes.
- `0x00449000` **SATCollisionHelpers** — 2D line-segment intersection test over four point triples with endpoint-sharing/vertical/parallel rejection and an endpoint skin tolerance.
- `0x0044A170` **UnknownObject** — Compute a coverage/overlap metric between two vertex batches into a this-side accumulator, with optional vertex chain linking.

## Proposed classes

### VehiclePhysicsState

Large per-vehicle physics state object: suspension/spring coefficient region, damper force output, clamp accumulators, per-wheel solver buffers, shared-state pointer (this+0x1F00), body pointer (this+0x15F0), target body pointer (this+0x1D4), and impulse/torque accumulation triples. Assumed owner of the suspension and rigid-body force evaluation methods; the single-owner grouping is DERIVED, not proven by the packet.

Methods: `0x0043BB00`, `0x0043BB30`, `0x0043BB80`, `0x0043BBD0`, `0x0043E5D0`, `0x0043EA70`, `0x00441AD0`, `0x00441BB0`, `0x00441F00`, `0x004432F0`, `0x00447100`

- `this+0x00000D4C` `double smoothedDeltaAccumulator` (read_write, DERIVED)
- `this+0x00001428` `double previousTrackedValue` (read_write, DERIVED)
- `this+0x00001430` `double deltaSmoothingFactor` (read, DERIVED)
- `this+0x000015F0` `RigidBody* bodyPtr` (read, DERIVED)
- `this+0x000015F4` `double wheelDampingMultiplier` (read, GUESS)
- `this+0x00001724` `byte forceApplicationActive` (read_write, GUESS)
- `this+0x00001BC0` `double clampAccumulator` (read_write, DERIVED)
- `this+0x00001C30` `double clampReference` (read, DERIVED)
- `this+0x00001C00` `double quadraticInput` (write, DERIVED)
- `this+0x00001C38` `double forceTorqueInput` (write, GUESS)
- `this+0x00001B9C` `double damperForceOutput` (write, GUESS)
- `this+0x00001900` `byte antiRollBar1Enable` (read, GUESS)
- `this+0x00001A08` `byte antiRollBar2Enable` (read, GUESS)
- `this+0x00001EF0` `int directionSignSelector` (read, GUESS)
- `this+0x00000048` `float directionScalar` (read, GUESS)
- `this+0x00001F00` `SharedVehicleState* sharedStatePtr` (read, GUESS)
- `this+0x000001D4` `RigidBody* targetBodyPtr` (read, GUESS)
- `this+0x000001D8` `double torqueScaleA` (read, GUESS)
- `this+0x000001E0` `double torqueScaleB` (read, GUESS)
- `this+0x00001F04` `double linearImpulseX` (read_write, GUESS)
- `this+0x00001F0C` `double linearImpulseY` (read_write, GUESS)
- `this+0x00001F14` `double linearImpulseZ` (read_write, GUESS)
- `this+0x00001F1C` `double torqueX` (read_write, GUESS)
- `this+0x00001F24` `double torqueY` (read_write, GUESS)
- `this+0x00001F2C` `double torqueZ` (read_write, GUESS)

### ClampedSpringIntegrator

Named DERIVED owner of 0x0043E980 from the packet: integrates two spring accumulator slots with fixed rates and clamps each into a window around a reference, then dispatches spring/damper curve evaluation via SpringDamperCompute. Operates on the same suspension coefficient region as VehiclePhysicsState; whether it is a distinct object or a component view of the same state object is unresolved.

Methods: `0x0043E980`

- `this+0x00001808` `double springAccumulatorA` (read_write, DERIVED)
- `this+0x00001818` `double springAccumulatorB` (read_write, DERIVED)
- `this+0x00001C18` `double springDamperInput` (read_write, DERIVED)
- `this+0x00001C20` `double springReferenceA` (read, DERIVED)
- `this+0x00001C28` `double springReferenceB` (read, DERIVED)

### PiecewiseResponseCurve

GUESS owner of 0x00436610: a two-input piecewise response curve built from fifteen coefficient fields (three sign/threshold-selected linear segments plus a boundary correction pair). Interpreted per existing analysis as a spring/damper response curve; the class identity is not proven by the packet.

Methods: `0x00436610`

- `this+0x00000000` `double inputScaleTerm` (read, GUESS)
- `this+0x00000008` `double highPositiveSlope` (read, GUESS)
- `this+0x00000010` `double lowPositiveSlope` (read, GUESS)
- `this+0x00000018` `double lowPositiveThreshold` (read, GUESS)
- `this+0x00000020` `double highPositiveIntercept` (read, GUESS)
- `this+0x00000028` `double lowNegativeSlope` (read, GUESS)
- `this+0x00000030` `double highNegativeSlope` (read, GUESS)
- `this+0x00000038` `double highNegativeThreshold` (read, GUESS)
- `this+0x00000040` `double lowNegativeIntercept` (read, GUESS)
- `this+0x00000048` `double correctionLine1Intercept` (read, GUESS)
- `this+0x00000050` `double correctionLine1Slope` (read, GUESS)
- `this+0x00000058` `double correctionLine2Intercept` (read, GUESS)
- `this+0x00000060` `double correctionLine2Slope` (read, GUESS)
- `this+0x00000068` `double lowerBoundary` (read, GUESS)
- `this+0x00000070` `double upperBoundary` (read, GUESS)

### RigidBody

Rigid-body object reached through VehiclePhysicsState.bodyPtr (this+0x15F0) and VehiclePhysicsState.targetBodyPtr (this+0x1D4): position, orientation matrix, velocity, and the force/angular-momentum accumulators that force producers write into. Layout beyond the evidenced fields is not confirmed.

Methods: 

- `*(this+0x15F0)+0x00000004` `double positionX` (read, GUESS)
- `*(this+0x15F0)+0x0000000C` `double positionY` (read, GUESS)
- `*(this+0x15F0)+0x00000014` `double positionZ` (read, GUESS)
- `*(this+0x15F0)+0x00000064` `double velocityX` (read, GUESS)
- `*(this+0x15F0)+0x0000006C` `double velocityY` (read, GUESS)
- `*(this+0x15F0)+0x00000074` `double velocityZ` (read, GUESS)
- `*(this+0x15F0)+0x00000134` `double forceBufferX` (read_write, GUESS)
- `*(this+0x15F0)+0x0000013C` `double forceBufferY` (read_write, GUESS)
- `*(this+0x15F0)+0x00000144` `double forceBufferZ` (read_write, GUESS)
- `*(this+0x15F0)+0x0000014C` `double angularMomentumX` (read_write, GUESS)
- `*(this+0x15F0)+0x00000154` `double angularMomentumY` (read_write, GUESS)
- `*(this+0x15F0)+0x0000015C` `double angularMomentumZ` (read_write, GUESS)
- `*(this+0x1D4)+0x00000134` `double targetForceBufferX` (read_write, GUESS)
- `*(this+0x1D4)+0x0000013C` `double targetForceBufferY` (read_write, GUESS)
- `*(this+0x1D4)+0x00000144` `double targetForceBufferZ` (read_write, GUESS)
- `*(this+0x1D4)+0x000000AC` `double stiffnessParameter` (read, GUESS)

### SharedVehicleState

Shared per-vehicle state reached through VehiclePhysicsState.sharedStatePtr (this+0x1F00): suspension enable/mode flags, wheel contact point, and front/rear linked-object pointers used by the anti-roll bar guards.

Methods: 

- `*(this+0x1F00)+0x0000344C` `byte dampingEnable` (read, GUESS)
- `*(this+0x1F00)+0x00003450` `int dampingMode` (read, GUESS)
- `*(this+0x1F00)+0x00003A64` `float wheelContactPointX` (read, GUESS)
- `*(this+0x1F00)+0x00003A68` `float wheelContactPointY` (read, GUESS)
- `*(this+0x1F00)+0x00003A6C` `float wheelContactPointZ` (read, GUESS)
- `*(this+0x1F00)+0x00000CD4` `pointer frontLinkedObjectPtr` (read, GUESS)
- `*(this+0x1F00)+0x00000D18` `pointer rearLinkedObjectPtr` (read, GUESS)

### TriangleVertexRecord

GUESS owner of the mixed-precision 16-byte record used by the collision triangle-edge subdivision helpers: float at +0x0, double at +0x4, float at +0xC. The single-owner grouping of the two helpers is a proposal, not proven.

Methods: `0x004484C0`, `0x004484F0`

- `this+0x00000000` `float componentA` (read_write, GUESS)
- `this+0x00000004` `double componentB` (read_write, GUESS)
- `this+0x0000000C` `float componentC` (read_write, GUESS)

### SpatialTreeNode

GUESS owner of the 96-byte-node spatial-tree insertion and the BVH node-chain traversal: key fields (float +0, double +4, float +0xC), a four-way child region beginning at +0x4C, and a chain/sibling pointer at +0x5C. The child-slot versus branch-slot layout at +0x4C..+0x58 is ambiguous and may represent two different node types.

Methods: `0x004485D0`, `0x00448E50`

- `this+0x00000000` `float keyA` (read, GUESS)
- `this+0x00000004` `double keyB` (read, GUESS)
- `this+0x0000000C` `float keyC` (read, GUESS)
- `this+0x0000004C` `pointer childSlot0` (read, GUESS)
- `this+0x0000005C` `pointer nextChainPtr` (read, GUESS)

### CollisionBody

GUESS owner of the collision-body initialization pair written by SmallStructCopy: a body-type byte at +0x19 and a handle/index word at +0x1A. The owning collision-body class is not evidenced beyond these two fields.

Methods: `0x00448EC0`

- `this+0x00000019` `byte bodyType` (write, GUESS)
- `this+0x0000001A` `word bodyHandle` (read_write, GUESS)

### SATCollisionHelpers

GUESS owner of the SAT edge-separation geometry helpers consumed by SATEdgeSeparationTest: half-plane computation for triangle edges, point-vs-plane-triple testing, and 2D segment intersection. The class grouping is a proposal; the helpers may be free functions.

Methods: `0x00448F00`, `0x00448FC0`, `0x00449000`

- `this+0x00000010` `double[3] halfPlaneTriples` (read, GUESS)
- `this+0x00000000` `float pointX` (read, GUESS)
- `this+0x0000000C` `float pointY` (read, GUESS)

## Compatibility contracts

- **SpatialTree96ByteNodeLayout** — Spatial-tree nodes are 96 bytes with keys at +0x0 (float), +0x4 (double) and +0xC (float), a four-way child region at +0x4C..+0x58, and a chain/sibling pointer at +0x5C. Insertion allocates new nodes of this size via OperatorNewNhMallocWrapper.
- **RigidBodyAccumulatorOffsets** — A rigid body exposes its accumulated force at +0x134/+0x13C/+0x144 and its angular-momentum accumulator at +0x14C/+0x154/+0x15C; force/torque producers (damping, coupling torque, anti-roll bars) must write these offsets. The same +0x134/+0x13C/+0x144 force offsets are used for both the source body (this+0x15F0) and the target body (this+0x1D4).
- **MixedPrecisionVertexRecordLayout** — Triangle collision-edge records are 16 bytes: float at +0x0, double at +0x4, float at +0xC. Subtraction and squared-magnitude helpers operate on this layout; collision-mesh edge subdivision consumes them.
- **TrigTable256Layout** — A 256-entry single-precision table at 0x8AAE74 is indexed with byte wrap and linear interpolation; the input double is scaled by 4.0 minus 0.5 before the byte index truncation.

## Unresolved

- Single-owner grouping of the suspension/rigid-body functions into VehiclePhysicsState is DERIVED; the packet does not prove that one class owns all of them, and most packet owners are UNKNOWN.
- ClampedSpringIntegrator and VehiclePhysicsState share the suspension coefficient region (0x1808, 0x1818, 0x1C18, 0x1C28); the packet's evidence that ClampedSpringIntegrator calls SpringDamperCompute with the same this object supports common ownership of that region but does not resolve whether they are one object or a component view.
- Offset 0x48 is read as a direction scalar by VelocityDampingFromSpeedError and as a correction-line intercept by PiecewiseFunctionEval. These are kept as separate fields on different (hypothetical) classes and are not merged.
- The spatial-tree node slots 0x4C..0x58 are branch slots under computed indexing in SpatialTreeInsertion but a fixed four-child region in DynamicsBVHNodeRecursiveTraversal; whether these are two node types or one layout is unresolved.
- RigidBody and SharedVehicleState layouts beyond the evidenced fields (e.g. the full orientation matrix rows +0x1C..+0x5C, contact struct at this+0x15F0) are not confirmed.
- ApplyForceTorqueToRigidBody's per-slot velocity sources at v7[716..718] and the term at this + 8*(index+1) + 5920 have no dedicated field evidence refs and are grounded in raw source only.
- The per-constant pairing of module double globals is unresolved: 0x0059EB28/0x0059EB50/0x0059EB58/0x0059EC78 to the 0.23/0.18 rates and 0.25/0.2 clamps in ClampedSpringIntegrator; 0x0059E430/0x0059ED40/0x0059ED48 to the 8.0 reference speed and 93.75 gain in VelocityDampingFromSpeedError; 0x0059EC80/0x0059EC88 to the 0.37/0.4 constants in DoubleAccumulatorClamp.
- Globals listed as read by the deterministic fact table but absent from the raw decompiled body: 0x007CBB10 (AccumulateAngularImpulse), 0x0059EC80 and 0x0059EC88 (DoubleAccumulatorClamp), 0x0059E440 (ApplyForceTorqueToRigidBody, flt_59E440), 0x0059E7D8 and 0x0059E880 (TrigTableLookup), 0x0059E43C and 0x0059E440 (VisibilityFrustumTest), 0x0059E420/0x0059E430/0x0059E880 (ComputeDamperSpringAndAntiRollForces). Their roles are unknown.
- Fields *(this+0x1F00)+0xD14 and +0xD58 are read per the fact table but absent from the decompiled body of ComputeDamperSpringAndAntiRollForces; their role in suspension/ARB state is unknown.
- Whether the anti-roll-bar linked-object null/flag guards mean 'no linked car' or 'linked car ready' is ambiguous.
- The force/torque interpretation of QuadraticForceTorqueCalculator outputs and the spring/damper curve semantics of SpringDamperCompute and the helper-spring block are DERIVED from prose, not proven by packet arithmetic alone.
- TrigTableLookup and VisibilityFrustumTest have no defensible owning class in the packet; they are modeled as free helpers with UNKNOWN owners.
- The exact component mapping of triangle vertices to x/z in TriangleEdgeHalfPlaneComputation and the role of the 0.001 normal-length bias (plane thickness vs edge tolerance) are inferred, not stated.
