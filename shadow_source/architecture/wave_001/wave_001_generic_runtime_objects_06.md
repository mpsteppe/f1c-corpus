# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Thirty functions grouped into a 'generic runtime objects' proposal: (1) suspension/adjacency geometry (PhysicsSuspensionNode: UpdateContactGeometry 0x004FAF60 and SignedDistancePenaltyMetric 0x004FB6D0 share the linked-node layout at this+0x10C/0x110/0x114 and the local position at this+0x0/0x4/0x8); (2) wheel physics parameter evaluators (WheelCurveEvaluator 0x004F6A50 DERIVED; WheelForceParameterBlock 0x004F6950; RandomizedParameterBlock 0x004F6850/0x004F6880; SuspensionLinkBlock 0x004F8330), all enable-byte gated and called per-frame from SuspensionAndWheelPhysics-family sites; (3) tire-model initialization (TirePhysicsSystem 0x004F2430, TireModelSubBlock 0x004F3040) called from TireModelDataInit/PhysicsTireSystemConstructor; (4) vehicle-setup file parsing (HdvVehicleSetupParser 0x004F3090 fender-aero section reader and 0x004F3490 abs-tuple parse, both from TheSvmHdvVehicleFileParser); (5) curve evaluators (ParameterizedCurve 0x004F6720, DualQuadraticCurve 0x004F3190); (6) per-instance effect/position state (VehiclePhysicsEffectBlock 0x004F17A0/0x004F1890, VehiclePhysicsState 0x004F0050, CullableRenderObject 0x004EFFD0, TeamEffectLoader 0x004F03E0); (7) HUD/feedback (HudElementArray 0x004F87C0, SignedIndexLookupTable 0x004FAE70); (8) buffered file streams (BufferedFileStream 0x005351D0/0x00535390/0x005355A0, wrapper 0x00534B00); (9) parameter accessors (TripleParameterAccessor 0x0054B3B0/0x0054B420/0x0054B4D0); (10) scene-graph access (SceneGraphNode 0x0054C030, SceneNodePositionCache 0x0054B950). Owners, field semantics and curve coefficient meanings remain mostly unproven; the architecture below records the evidenced structure and leaves the uncertain parts explicit in unresolved.

## Function roles

- `0x004EFFD0` **CullableRenderObject** — Distance-culling gate on the per-frame render path: applies a 3D transform via F_3DTransformWithMatrixMultiplication (callee 0x004EFB20), issues a guarded render call through the object's render pointer at this+0x0 (callee 0x004D1140), and returns a boolean derived from x87 c0/c2 status flags set by the callees' internal comparisons; the compared quantities are not visible in the packet.
- `0x004F0050` **VehiclePhysicsState** — Projected signed-distance calculator for vehicle physics: fetches a position-monitor struct via PositionChangeMonitor (callee 0x004E9630), forms a direction vector from two monitor position pointers (+268/+272), projects the vehicle offsets this+0x34D4/0x34D8/0x34DC against the monitor origin along the normalized direction plus a stored distance, returns the stored distance on a zero direction, and clamps with flt_5EA3FC[0].
- `0x004F03E0` **TeamEffectLoader** — Dispatch wrapper (legacy name Team_Color_Loader): resolves an object-relative parameter at *this + 0x4894 through UtilityFunction_3d50 (callee 0x00463D50) into a 108-dword local buffer, and only if that returns non-zero calls VehiclePhysicsTimeStep(*this, buffer, a2) (callee 0x004C73F0). The local buffer is the sole data channel between the two calls.
- `0x004F17A0` **VehiclePhysicsEffectBlock** — Effect parameter setter on the vehicle effect object: writes a2 into the slot at 0x3994, a4 into the slot at 0x3570, and (a3 * the multiplier at 0x397C) into the scaled slot at 0x3978; returns a2 unchanged. Called per-frame from VehiclePhysicsTimeStep (0x004C73F0).
- `0x004F1890` **VehiclePhysicsEffectBlock** — Speed value setter with global mirror: writes the float argument into this+0x3978, then mirrors it into the global dbl_7C75C4 only when the rigid-body constraint pointer at this+0x32BC is null; returns the previously read constraint pointer.
- `0x004F1A60` **TireBrushSystem** — Fixed 4-iteration loop driver: calls sub_4F18C0 with (this, i, a2, 0) for i in 0..3, then if the flag argument a3 is non-zero calls TireBrushModelForceSolver (callee 0x004E8010) with (this, 0). Called from five AI/vehicle-physics sites including AIMainUpdate, AISteeringRacingLineCorrection, PitStopOperationTimer and SuspensionAndWheelPhysics.
- `0x004F2430` **TirePhysicsSystem** — Constructor-style zero initializer of a tire physics/data object: runs ConstantsStructInit (callee 0x0040E6A0) over two direct regions (this+12, this+24) and two loop-expanded runs of 7-dword constants structs (starting this+34 x4, this+102 x8), zeroes 20 dword fields via straight-line and loop writes, and returns this.
- `0x004F3040` **TireModelSubBlock** — Zero-initializer for a 0x54-byte sub-object: zeroes a byte at this+0x0 and 20 dwords through this+0x50, returns this. Called once from TireModelDataInit (0x004F34E0), suggesting an embedded tire-model sub-structure.
- `0x004F3090` **HdvVehicleSetupParser** — Fender aerodynamics setup-section reader of a vehicle file: loops over lines via LineInputReader (callee 0x005351D0), uses sub_5651B0 to detect the end of section (break) or skip non-data lines, parses fender center/drag/lift/sideways parameter fields via sub_565AA0 into this-relative slots (this+0x0 set to 1 when FenderCenter parses), and calls CRTMathHelper_e1f0 to fill a per-vehicle indexed flare range/setting block.
- `0x004F3190` **DualQuadraticCurve** — Dual quadratic curve evaluator: evaluates two quadratics a2^2*C2 + a2*C1 + C0 with double coefficients (this+0x4/0xC/0x14 and this+0x1C/0x24/0x2C), writing results to *a3 and *a4; when the enable byte at this+0x0 is zero both outputs are 0.0. Returns a3 when enabled, a4 when disabled.
- `0x004F3490` **HdvVehicleSetupParser** — Parse-and-abs tuple setter: fills a three-value tuple at this+0x90/0x98/0xA0 via sub_565AA0, and on parse success applies fabs to each element; returns the parse result. Called from TheSvmHdvVehicleFileParser (0x004F4270).
- `0x004F6720` **ParameterizedCurve** — Piecewise-linear curve interpolation over a table of (x, y1, y2) triple points at this+0x6C8 (24-byte stride, count at this+0x6C4): finds the segment bracketing a2, linearly interpolates both y outputs into a3/a4, clamps the case where the second output is below the first to their midpoint (dbl_59E880), and handles empty-table and single-point degenerate cases. Called per-frame by brake-temperature, aero and suspension physics.
- `0x004F6850` **RandomizedParameterBlock** — Randomized scale+bias offset calculator: when the enable byte at this+0x56C is zero, calls the randomization helper sub_5881F0(a2) and scales a2 by the double at this+0x578, otherwise uses a2 unscaled; adds the bias double at this+0x570 and returns the result. Called per-frame by sub_43C250 and SuspensionAndWheelPhysics.
- `0x004F6880` **RandomizedParameterBlock** — Second variant of the randomized scale+bias computation: same enable gate at this+0x56C and randomization helper sub_5881F0, but using the parameter pair at this+0x588 (bias) and this+0x590 (scale). Called per-frame by sub_43C250 and SuspensionAndWheelPhysics.
- `0x004F6950` **WheelForceParameterBlock** — Quadratic force/torque model: given input a2 fills torque *a4 and force components a3[0..2] using quadratic polynomials in a2 (coefficient doubles at this+0x314/0x31C/0x324 for torque and this+0x2FC/0x304/0x30C for force) plus two absolute-value force components (this+0x34C, this+0x384); gated by the enable byte at this+0x2F8. Called from WheelForceAggregate, CollisionEnergy and SuspensionAndWheelPhysics.
- `0x004F6A50` **WheelCurveEvaluator** — Enable-flag-guarded quadratic curve evaluator for the wheel curve: when the byte at this+0x4D4 is non-zero writes a2*a2*(this+0x4E8) + a2*(this+0x4F0) + a2*(this+0x4E0) + (this+0x4D8) into *a3, otherwise writes 0.0; returns the flag value. On the per-frame wheel/suspension physics path.
- `0x004F8330` **SuspensionLinkBlock** — Reciprocal positive-difference helper: v1 = float(this+0x80) - float(this+0x84); writes 1.0/v1 to this+0x88 when v1 > 0.0, otherwise writes 0. Per-frame helper called from SuspensionAndWheelPhysics.
- `0x004F87C0` **HudElementArray** — Indexed HUD/feedback element configuration: reads a flag at *(this)+0x32C8 to select the gain source (flt_7CF35C vs flt_7CF338 plus an index increment of 1), selects element result = this + 8*a2, writes gain = v6*a4, writes magnitude a5, sets an enable byte, clamps the index into [0, 3] (or 0 when negative), and clears a byte; returns the element base.
- `0x004FAE70` **SignedIndexLookupTable** — Signed index table lookup: converts float a2 to an integer via CRTFtol (callee 0x00587BDC), then selects a double from two clamped 8-entry regions of a caller-provided float table (indices 59..66 for non-negative input, indices 51..58 for negative input, both clamped to 7).
- `0x004FAF60` **PhysicsSuspensionNode** — Suspension contact-geometry update for a physics node, gated by the distance threshold at this+0x12C against dword_5EA2CC: computes the delta vector from the local reference position to a linked neighbor (primary this+0x110, fallback this+0x10C), derives lateral bounds, combined coordinates, delta magnitude and a secondary distance from the tertiary pointer this+0x114, sets an approach angle from atan2 with pi/2 and +pi special cases, and propagates clamped cosine-similarity values into the this+0xBC array through a chain of up to 4 linked nodes.
- `0x004FB6D0` **PhysicsSuspensionNode** — Signed-distance collision/penalty metric: computes the delta of target a2 against the owner position (this+0x0/0x4/0x8), takes a signed dot product against a direction vector (this+0x20/0x24/0x28), applies directional bias thresholds (this+0x58 negative / this+0x5C positive), projects a2 onto the line segments from the owner position to two reference sub-structs (via *(this+0x110) and *(this+0x10C)) returning 10.0 when either reference has zero length, and returns the maximum of the biased signed distance, both line-projection margins, and abs(Y-delta) minus 3.0.
- `0x00534B00` **UnknownObject** — Call wrapper: invokes sub_534B10 with argument -1 and returns its result unchanged. Callers span file-open, scene/vehicle-file writing and parsing, audio-stream and joint-system load paths, suggesting a shared helper with a -1 sentinel argument.
- `0x005351D0` **BufferedFileStream** — Line input reader over a buffered file stream: reads single bytes via BufferedFileReader (callee 0x00534F90) until newline (0x0A), the length limit a3 is exhausted, or a read fails; null-terminates the line and returns the buffer pointer, or 0 when no data was stored.
- `0x00535390` **BufferedFileStream** — Mode-driven buffered stream read: reads a2 bytes from the stream object; mode a3==0 reads at an absolute offset, a3==1 reads relative to the position at a1+20, a3==2 returns -1. Lazily allocates 0x4000 scratch buffers via MallocWrapperForNhMalloc (callee 0x0058A935) and fills them through BufferFillWithTimeout (callee 0x00535220) or BufferedFileReader loops (callee 0x00534F90), with seek-back via sub_5354E0 (callee 0x005354E0) and sub_587F64; returns -1 on any refused or failed path. Called from file loaders, HDV parsing and resource dispatch.
- `0x005355A0` **BufferedFileStream** — File-stream close/cleanup with an optional write-flush path: returns -2 for a NULL stream; when the mode byte at this+0x5C equals 119 ('w') and FileReadLoop(this, 4) (callee 0x005352D0) returns 0, runs ArithmeticComparison_55f0 (callee 0x005355F0) twice to sync remaining-buffer state between this+0x40/0x4C and this+0x40/0x8; always hands the stream to a file-handle destructor for final cleanup.
- `0x0054B3B0` **TripleParameterAccessor** — Three-field setter: writes a2/a3/a4 into fields at this+0x20/0x24/0x28, then calls a BitmaskClear(this, 64, 0, 0) helper whose address is absent from the packet.
- `0x0054B420` **TripleParameterAccessor** — Three-field query: reads fields at this+0x20/0x24/0x28 and writes each to its corresponding output pointer when non-null; returns a4.
- `0x0054B4D0` **TripleParameterAccessor** — Six-field setter with bitmask clear: stores a2/a3/a4 at this+0x20/0x24/0x28, forwards a5/a6/a7 through InterruptDispatch (callee 0x0058957A) and stores them as floats at this+0x2C/0x30/0x34, then clears the bitmask at this+0x40 via BitmaskClear (callee 0x0054B330).
- `0x0054B950` **SceneNodePositionCache** — Scene-node position getter with lazy transform cache: loads the scene node pointer from this+0x204, and when bit 0x20000000 of the node cache flag at this+0x218 is clear recomputes the world transform via an indirect D3D device wrapper call (dword_8B8F24 vtable+4) and sets the cache bit; conditionally writes the node X/Y/Z coordinates (this+0x2EC/0x2F0/0x2F4) into up to three output pointers; returns the third output pointer.
- `0x0054C030` **SceneGraphNode** — Flag-field bit manipulation with recursive child propagation: manipulates bits 0x2 and 0x4 of the flag field at this+0x3C driven by a2 (1 clears bit 0x2, 0 sets bits 0x2 and 0x4) and a3 (1 clears bit 0x4, 0 sets bit 0x4); when a4==1 propagates the operation recursively to child objects at this+0x44 and (if a5 set and non-null) this+0x4C.

## Proposed classes

### PhysicsSuspensionNode

Per-node suspension contact geometry and signed-distance penalty metric for adjacent physics nodes: local position, direction, bias thresholds, reference position, delta vector, bounds/combined coordinates, distances, approach angle, a cosine-similarity neighbor array, and three linked-node pointers (primary 0x110, alternative 0x10C, tertiary 0x114). Owner identity is DERIVED from the shared linked-node layout used by both 0x004FAF60 and 0x004FB6D0; the LEGACY ABI name AI_Opponent_Relative_Positioning is contradicted by the evidence.

Methods: `0x004FAF60`, `0x004FB6D0`

- `this+0x00000000` `float localPositionX` (read, DERIVED)
- `this+0x00000004` `float localPositionY` (read, DERIVED)
- `this+0x00000008` `float localPositionZ` (read, DERIVED)
- `this+0x00000020` `float directionX` (read, DERIVED)
- `this+0x00000024` `float directionY` (read, DERIVED)
- `this+0x00000028` `float directionZ` (read, DERIVED)
- `this+0x0000002C` `float basePositionX` (read, DERIVED)
- `this+0x00000030` `float basePositionY` (read, DERIVED)
- `this+0x0000003C` `float deltaMagnitude` (write, DERIVED)
- `this+0x00000040` `float secondaryDistance` (write, DERIVED)
- `this+0x00000050` `float lowerLateralBound` (write, DERIVED)
- `this+0x00000054` `float upperLateralBound` (write, DERIVED)
- `this+0x00000058` `float negativeSideBias` (read, DERIVED)
- `this+0x0000005C` `float positiveSideBias` (read, DERIVED)
- `this+0x00000060` `float combinedOffsetX` (read, DERIVED)
- `this+0x00000064` `float combinedOffsetY` (read, DERIVED)
- `this+0x00000068` `float combinedCoordinateX` (write, DERIVED)
- `this+0x0000006C` `float combinedCoordinateY` (write, DERIVED)
- `this+0x00000094` `float referencePositionX` (read, DERIVED)
- `this+0x00000098` `float referencePositionY` (read, DERIVED)
- `this+0x0000009C` `float referencePositionZ` (read, DERIVED)
- `this+0x000000A0` `float halfWidth` (read, DERIVED)
- `this+0x000000A4` `float deltaX` (read_write, DERIVED)
- `this+0x000000A8` `float deltaY` (read_write, DERIVED)
- `this+0x000000AC` `float deltaZ` (read_write, DERIVED)
- `this+0x000000B8` `float approachAngle` (write, DERIVED)
- `this+0x000000BC` `float[4] neighborCosines` (write, DERIVED)
- `this+0x0000010C` `void* alternativeNeighborPtr` (read, DERIVED)
- `this+0x00000110` `void* primaryNeighborPtr` (read, DERIVED)
- `this+0x00000114` `void* tertiaryNeighborPtr` (read, DERIVED)
- `this+0x0000012C` `float distanceThresholdState` (read, DERIVED)
- `*(this+0x110)+0x00000000` `float neighborPositionX` (read, GUESS)
- `*(this+0x110)+0x00000004` `float neighborPositionY` (read, GUESS)
- `*(this+0x110)+0x00000008` `float neighborPositionZ` (read, GUESS)
- `*(this+0x110)+0x00000094` `float neighborReferencePositionX` (read, GUESS)
- `*(this+0x110)+0x00000098` `float neighborReferencePositionY` (read, GUESS)
- `*(this+0x110)+0x0000009C` `float neighborReferencePositionZ` (read, GUESS)
- `*(this+0x110)+0x00000110` `void* nextNeighborPtr` (read, GUESS)
- `*(*(this+0x110)+0x110)+0x00000094` `float chainNeighborReferencePositionX` (read, GUESS)
- `*(*(this+0x110)+0x110)+0x0000009C` `float chainNeighborReferencePositionZ` (read, GUESS)
- `*(*(*(this+0x110)+0x110)+0x110)+0x00000110` `void* chainNextNeighborPtr` (read, GUESS)
- `*(this+0x10C)+0x00000000` `float alternativePositionX` (read, GUESS)
- `*(this+0x10C)+0x00000004` `float alternativePositionY` (read, GUESS)
- `*(this+0x10C)+0x00000008` `float alternativePositionZ` (read, GUESS)
- `*(this+0x10C)+0x000000A4` `float alternativeDeltaX` (read, GUESS)
- `*(this+0x10C)+0x000000A8` `float alternativeDeltaY` (read, GUESS)
- `*(this+0x10C)+0x000000AC` `float alternativeDeltaZ` (read, GUESS)
- `*(this+0x114)+0x00000094` `float tertiaryReferencePositionX` (read, GUESS)
- `*(this+0x114)+0x00000098` `float tertiaryReferencePositionY` (read, GUESS)
- `*(this+0x114)+0x0000009C` `float tertiaryReferencePositionZ` (read, GUESS)

### WheelCurveEvaluator

Enable-flag-guarded quadratic force/torque curve evaluator for the wheel curve (coefficients C0 at 0x4D8, C1 at 0x4E0, C2 at 0x4E8, C3 at 0x4F0; enable byte at 0x4D4). Owner trust DERIVED from the caller evidence (wheel/suspension physics sites).

Methods: `0x004F6A50`

- `this+0x000004D4` `uint8_t curveEnableFlag` (read, DERIVED)
- `this+0x000004D8` `double quadraticCoeffC0` (read, DERIVED)
- `this+0x000004E0` `double quadraticCoeffC1a` (read, DERIVED)
- `this+0x000004E8` `double quadraticCoeffC2` (read, DERIVED)
- `this+0x000004F0` `double quadraticCoeffC1b` (read, DERIVED)

### WheelForceParameterBlock

Quadratic force/torque parameter block for a wheel: enable byte at 0x2F8, force polynomial coefficients at 0x2FC/0x304/0x30C, torque polynomial coefficients at 0x314/0x31C/0x324, and two absolute-value force components at 0x34C/0x384. Physical meaning of each coefficient is caller-dependent and unproven.

Methods: `0x004F6950`

- `this+0x000002F8` `uint8_t forceEnableFlag` (read, GUESS)
- `this+0x000002FC` `double forceCoeffC0` (read, GUESS)
- `this+0x00000304` `double forceCoeffC1` (read, GUESS)
- `this+0x0000030C` `double forceCoeffC2` (read, GUESS)
- `this+0x00000314` `double torqueCoeffC0` (read, GUESS)
- `this+0x0000031C` `double torqueCoeffC1` (read, GUESS)
- `this+0x00000324` `double torqueCoeffC2` (read, GUESS)
- `this+0x0000034C` `double absForceComponentA` (read, GUESS)
- `this+0x00000384` `double absForceComponentB` (read, GUESS)

### SuspensionLinkBlock

Reciprocal positive-difference helper state for a suspension link: two float operands at 0x80/0x84 and the reciprocal result at 0x88, recalculated every frame (external pokes do not persist).

Methods: `0x004F8330`

- `this+0x00000080` `float linkMinuend` (read, GUESS)
- `this+0x00000084` `float linkSubtrahend` (read, GUESS)
- `this+0x00000088` `float reciprocalResult` (write, GUESS)

### RandomizedParameterBlock

Randomized scale+bias parameter pair block: a shared enable byte at 0x56C selects the randomization path (helper sub_5881F0), and two bias/scale pairs (0x570/0x578 and 0x588/0x590) feed the two scale+bias variants 0x004F6850 and 0x004F6880. Grouping is GUESS based on the shared enable byte and identical randomization structure.

Methods: `0x004F6850`, `0x004F6880`

- `this+0x0000056C` `uint8_t randomizationEnableFlag` (read, GUESS)
- `this+0x00000570` `double biasVariantA` (read, GUESS)
- `this+0x00000578` `double scaleVariantA` (read, GUESS)
- `this+0x00000588` `double biasVariantB` (read, GUESS)
- `this+0x00000590` `double scaleVariantB` (read, GUESS)

### VehiclePhysicsEffectBlock

Per-instance vehicle physics effect/speed state: a rigid-body constraint pointer at 0x32BC gating a global mirror, and effect parameter slots at 0x3570, 0x3978, 0x397C, 0x3994. Grouping is GUESS on the shared 0x3978 speed slot written by both 0x004F17A0 and 0x004F1890.

Methods: `0x004F17A0`, `0x004F1890`

- `this+0x000032BC` `void* rigidBodyConstraintPtr` (read, GUESS)
- `this+0x00003570` `float effectParameterSlotA` (write, GUESS)
- `this+0x00003978` `float speedValue` (write, GUESS)
- `this+0x0000397C` `float effectScaleMultiplier` (read, GUESS)
- `this+0x00003994` `float effectParameterSlotB` (write, GUESS)

### TirePhysicsSystem

Tire physics/data object with constructor-style zero initialization: twelve leading dword fields, five dwords at 0x4C..0x5C, three at 0x7C..0x84, and loop-written regions around 0x118 and 0x140, plus 7-dword constants structs initialized via ConstantsStructInit (callee 0x0040E6A0). Owner is GUESS; callers PhysicsTireSystemConstructor and TireModelDataInit suggest the tire model but do not name it.

Methods: `0x004F2430`

- `this+0x00000000` `uint32_t initField0` (write, UNKNOWN)
- `this+0x00000004` `uint32_t initField1` (write, UNKNOWN)
- `this+0x00000008` `uint32_t initField2` (write, UNKNOWN)
- `this+0x0000000C` `uint32_t initField3` (write, UNKNOWN)
- `this+0x00000010` `uint32_t initField4` (write, UNKNOWN)
- `this+0x00000014` `uint32_t initField5` (write, UNKNOWN)
- `this+0x00000018` `uint32_t initField6` (write, UNKNOWN)
- `this+0x0000001C` `uint32_t initField7` (write, UNKNOWN)
- `this+0x00000020` `uint32_t initField8` (write, UNKNOWN)
- `this+0x00000024` `uint32_t initField9` (write, UNKNOWN)
- `this+0x00000028` `uint32_t initField10` (write, UNKNOWN)
- `this+0x0000002C` `uint32_t initField11` (write, UNKNOWN)
- `this+0x0000004C` `uint32_t initField19` (write, UNKNOWN)
- `this+0x00000050` `uint32_t initField20` (write, UNKNOWN)
- `this+0x00000054` `uint32_t initField21` (write, UNKNOWN)
- `this+0x00000058` `uint32_t initField22` (write, UNKNOWN)
- `this+0x0000005C` `uint32_t initField23` (write, UNKNOWN)
- `this+0x0000007C` `uint32_t initField31` (write, UNKNOWN)
- `this+0x00000080` `uint32_t initField32` (write, UNKNOWN)
- `this+0x00000084` `uint32_t initField33` (write, UNKNOWN)
- `this+0x00000118` `uint32_t loopZeroField70Region` (write, UNKNOWN)
- `this+0x00000140` `uint32_t loopZeroField80Region` (write, UNKNOWN)

### TireModelSubBlock

0x54-byte embedded tire-model sub-structure zeroed by 0x004F3040: a byte at 0x0 and 20 dwords through 0x50. Called once from TireModelDataInit; the parent linkage is not confirmed.

Methods: `0x004F3040`

- `this+0x00000000` `uint8_t subFlagByte` (write, UNKNOWN)
- `this+0x00000004` `uint32_t subDword1` (write, UNKNOWN)
- `this+0x00000008` `uint32_t subDword2` (write, UNKNOWN)
- `this+0x0000000C` `uint32_t subDword3` (write, UNKNOWN)
- `this+0x00000010` `uint32_t subDword4` (write, UNKNOWN)
- `this+0x00000014` `uint32_t subDword5` (write, UNKNOWN)
- `this+0x00000018` `uint32_t subDword6` (write, UNKNOWN)
- `this+0x0000001C` `uint32_t subDword7` (write, UNKNOWN)
- `this+0x00000020` `uint32_t subDword8` (write, UNKNOWN)
- `this+0x00000024` `uint32_t subDword9` (write, UNKNOWN)
- `this+0x00000028` `uint32_t subDword10` (write, UNKNOWN)
- `this+0x0000002C` `uint32_t subDword11` (write, UNKNOWN)
- `this+0x00000030` `uint32_t subDword12` (write, UNKNOWN)
- `this+0x00000034` `uint32_t subDword13` (write, UNKNOWN)
- `this+0x00000038` `uint32_t subDword14` (write, UNKNOWN)
- `this+0x0000003C` `uint32_t subDword15` (write, UNKNOWN)
- `this+0x00000040` `uint32_t subDword16` (write, UNKNOWN)
- `this+0x00000044` `uint32_t subDword17` (write, UNKNOWN)
- `this+0x00000048` `uint32_t subDword18` (write, UNKNOWN)
- `this+0x0000004C` `uint32_t subDword19` (write, UNKNOWN)
- `this+0x00000050` `uint32_t subDword20` (write, UNKNOWN)

### HdvVehicleSetupParser

Vehicle-setup parse targets of the HDV vehicle file parser (TheSvmHdvVehicleFileParser): fender aerodynamics section output (0x0 parsed flag plus drag/lift/sideways/center destination slots) and an abs-tuple at 0x90/0x98/0xA0. Both methods are called from 0x004F4270; the grouping is GUESS on the shared caller and this-relative output convention.

Methods: `0x004F3090`, `0x004F3490`

- `this+0x00000000` `uint32_t fenderCenterParsedFlag` (write, GUESS)
- `this+0x00000090` `double absTupleA` (write, GUESS)
- `this+0x00000098` `double absTupleB` (write, GUESS)
- `this+0x000000A0` `double absTupleC` (write, GUESS)

### DualQuadraticCurve

Two-quadratic evaluation block with a shared enable byte at 0x0 and two coefficient triples (C0/C1/C2 at 0x4/0xC/0x14 and 0x1C/0x24/0x2C). The dual-purpose return convention (a3 when enabled, a4 when disabled) is unusual and its intent is unconfirmed.

Methods: `0x004F3190`

- `this+0x00000000` `uint8_t curveEnableFlag` (read, GUESS)
- `this+0x00000004` `double quadraticAC0` (read, GUESS)
- `this+0x0000000C` `double quadraticAC1` (read, GUESS)
- `this+0x00000014` `double quadraticAC2` (read, GUESS)
- `this+0x0000001C` `double quadraticBC0` (read, GUESS)
- `this+0x00000024` `double quadraticBC1` (read, GUESS)
- `this+0x0000002C` `double quadraticBC2` (read, GUESS)

### ParameterizedCurve

Piecewise-linear curve table: point count at 0x6C4 and triple points (x, y1, y2) at 0x6C8 with a 24-byte stride, interpolated by 0x004F6720 for brake-temperature, aero and suspension physics. Owner identity unknown; the LEGACY ABI name Parameterized_Curve_Interpolation names the routine, not a class.

Methods: `0x004F6720`

- `this+0x000006C4` `uint32_t curvePointCount` (read, GUESS)
- `this+0x000006C8` `double curvePointTableX0` (read, GUESS)
- `this+0x000006D0` `double curvePoint0Y1Lo` (read, GUESS)
- `this+0x000006D4` `double curvePoint0Y1Hi` (read, GUESS)
- `this+0x000006D8` `double curvePoint0Y2Lo` (read, GUESS)
- `this+0x000006DC` `double curvePoint0Y2Hi` (read, GUESS)

### VehiclePhysicsState

Vehicle physics position state consumed by the projected-distance calculator 0x004F0050: the vehicle position offsets 0x34D4/0x34D8/0x34DC projected against a position-monitor origin. Owner is GUESS; the offsets lie in the vehicle-struct region.

Methods: `0x004F0050`

- `this+0x000034D4` `float vehiclePositionX` (read, GUESS)
- `this+0x000034D8` `float vehiclePositionY` (read, GUESS)
- `this+0x000034DC` `float vehiclePositionZ` (read, GUESS)

### CullableRenderObject

Render object whose 3D transform is applied and whose render call is distance-guarded by 0x004EFFD0: a render-object pointer at this+0x0 is passed to the guarded render call. Semantics of the returned boolean are unresolved.

Methods: `0x004EFFD0`

- `this+0x00000000` `void* renderObjectPtr` (read, GUESS)

### TeamEffectLoader

Dispatch wrapper object for a per-object parameter resolved into a local buffer and handed to VehiclePhysicsTimeStep: reads an object field at *this+0x4894 (base obj). Whether it truly relates to team color is only a legacy ABI label.

Methods: `0x004F03E0`

- `this+0x00000000` `void* targetObjectPtr` (read, GUESS)
- `obj+0x00004894` `uint32_t parameterSourceField` (read, GUESS)

### TireBrushSystem

Tire brush-model driver: runs a fixed 4-iteration sub_4F18C0 loop per this object and conditionally invokes TireBrushModelForceSolver (callee 0x004E8010) based on a flag argument. Purpose of the loop and of the flag is not established; owner object unconfirmed.

Methods: `0x004F1A60`


### HudElementArray

Indexed HUD/feedback element array: a gain-source flag at *(this)+0x32C8 (base obj) selects between two gain globals, and elements are 8-float stride sub-blocks written by 0x004F87C0. Specific HUD semantics of the gain/magnitude/index fields are not established.

Methods: `0x004F87C0`

- `obj+0x000032C8` `uint32_t gainSourceFlag` (read, GUESS)
- `this+0x00000000` `void* flagOwnerPtr` (read, GUESS)

### SignedIndexLookupTable

Caller-provided float table (two 8-entry double regions at indices 51..58 and 59..66) selected by the sign of a float-converted index; the element stride and owner are not evidenced by packet fields.

Methods: `0x004FAE70`


### BufferedFileStream

Buffered file stream with byte-at-a-time line reading, mode-driven bulk reads, and close/cleanup with a write-flush path. Packet-evidenced fields: file context 0x0, stream position 0x8, read handle 0x40, buffer field 0x4C, mode byte 0x5C. The wider a1 layout (0/4/8/20/56/64/68/72/88/92) is transcribed from raw source and not packet-evidenced.

Methods: `0x005351D0`, `0x00535390`, `0x005355A0`

- `this+0x00000000` `void* fileContextPtr` (read, GUESS)
- `this+0x00000008` `uint32_t streamPosition` (read_write, GUESS)
- `this+0x00000040` `uint32_t readHandle` (read_write, GUESS)
- `this+0x0000004C` `uint32_t remainingBufferField` (read_write, GUESS)
- `this+0x0000005C` `uint8_t modeByte` (read, GUESS)

### TripleParameterAccessor

Accessor over a triple of fields at 0x20/0x24/0x28 plus optional float members at 0x2C/0x30/0x34 and a bitmask at 0x40: setter 0x0054B3B0, query 0x0054B420, and the six-field setter with interrupt dispatch 0x0054B4D0. Grouping is GUESS on the shared 0x20/0x24/0x28 layout.

Methods: `0x0054B3B0`, `0x0054B420`, `0x0054B4D0`

- `this+0x00000020` `uint32_t tripleFieldA` (read_write, GUESS)
- `this+0x00000024` `uint32_t tripleFieldB` (read_write, GUESS)
- `this+0x00000028` `uint32_t tripleFieldC` (read_write, GUESS)
- `this+0x0000002C` `float floatMemberA` (write, GUESS)
- `this+0x00000030` `float floatMemberB` (write, GUESS)
- `this+0x00000034` `float floatMemberC` (write, GUESS)
- `this+0x00000040` `uint32_t bitmaskField` (write, GUESS)

### SceneNodePositionCache

Scene-node position accessor with a lazy transform cache: node pointer at 0x204, a cache flag bit 0x20000000 at 0x218, and node coordinates 0x2EC/0x2F0/0x2F4 read out on demand, recomputing the world transform through an indirect D3D device wrapper call when the cache bit is clear.

Methods: `0x0054B950`

- `this+0x00000204` `void* sceneNodePtr` (read, GUESS)
- `this+0x00000218` `uint32_t transformCacheFlag` (read_write, GUESS)
- `this+0x000002EC` `float cachedNodeX` (read, GUESS)
- `this+0x000002F0` `float cachedNodeY` (read, GUESS)
- `this+0x000002F4` `float cachedNodeZ` (read, GUESS)

### SceneGraphNode

Scene-graph node with a flag field at 0x3C (bits 0x2 and 0x4) and up to two child pointers at 0x44 and 0x4C; flag manipulation propagates recursively to children when enabled. Semantic meaning of the flag bits is not established.

Methods: `0x0054C030`

- `this+0x0000003C` `uint32_t flagField` (read_write, GUESS)
- `this+0x00000044` `void* childAPtr` (read, GUESS)
- `this+0x0000004C` `void* childBPtr` (read, GUESS)

## Compatibility contracts

- **BufferedStreamReadContract** — A replacement executable must preserve the buffered-file-stream behavior: read at absolute (mode 0) or relative (mode 1) offsets, return -1 for refused or failed reads, lazily allocate 0x4000 scratch buffers on first use, track the position at a1+8/a1+20, and gate reads on the stream state at a1+56 and the mode byte 'w' at a1+92.
- **BufferedStreamWriteFlushCloseContract** — Stream teardown must keep the write-flush path gated on the mode byte 'w' at this+0x5C and FileReadLoop returning 0, sync the remaining-buffer state between the read handle (this+0x40) and the buffer fields (this+0x4C, this+0x8), and return -2 for a NULL stream.
- **VehicleFileFenderAeroSectionContract** — A replacement must parse the fender-aerodynamics section of a vehicle file the same way: read lines until an end-of-section marker (sub_5651B0 returning 1), skip non-data lines, parse the fender center/drag/lift/sideways parameter fields through the 5-argument tuple parser sub_565AA0, and fill the per-vehicle indexed flare range/setting block via CRTMathHelper_e1f0 with the index arithmetic (a2<<6 + a5 + 2992).
- **SuspensionNodeAdjacencyContract** — A replacement must keep the linked-node adjacency semantics: the whole geometry update runs only when the node distance at this+0x12C is below dword_5EA2CC; the delta vector prefers the primary neighbor (this+0x110) and falls back to the alternative (this+0x10C); cosine-similarity values propagate through a chain of up to 4 linked nodes into the this+0xBC array; the 10.0 sentinel and 3.0 Y-margin of the penalty metric must be preserved.

## Unresolved

- 0x004EFFD0: the exact quantities compared by the callees (which set the x87 c0/c2 status flags) are not visible, so the returned boolean's semantics and its 'distance' interpretation are unknown; globals flt_59E46C and dword_8ACEE0 are listed as read but do not appear in the raw function text (presumably referenced inside a callee).
- 0x004F0050: the role of globals flt_59E43C and flt_59E440 is unconfirmed (extraction/analysis mismatch); semantic labels (TrackRefSpeed for flt_5EA3FC, position-monitor offsets, stored distance) are DERIVED prose, the raw source shows only arithmetic.
- 0x004F03E0: contents and layout of the 108-dword local buffer v3 are not in the packet (it is the sole data channel between UtilityFunction_3d50 and VehiclePhysicsTimeStep); the meaning of float argument a2 is unknown; the object field at *this+0x4894 is read as a pointer-sized value only; whether this really relates to team color is a legacy ABI label not stated in the raw source.
- 0x004F17A0: the semantic role of the three parameter slots (0x3570, 0x3978, 0x3994) is not established; only raw writes are evidenced.
- 0x004F1A60: purpose of the 4-iteration sub_4F18C0 loop (per-wheel or per-subsystem setup), the meaning of argument a2 and constant 0, and why TireBrushModelForceSolver runs only when flag a3 is set, are all unknown; owner object is unconfirmed (thiscalls convention only).
- 0x004F2430: object type is unknown (callers PhysicsTireSystemConstructor and TireModelDataInit suggest a tire physics/data model but do not name it); intermediate offsets written inside the final zeroing loop are not enumerated in the packet field list; the semantic role of the 7-dword constants structs initialized via ConstantsStructInit is not described.
- 0x004F3040: owner object identity is not established; the sole caller TireModelDataInit suggests an embedded sub-structure of the tire model data, but that is not confirmed.
- 0x004F3090: offset destinations this+4..this+76 (drag/lift/sideways/center outputs) appear in the raw source but are not in the packet field table (only this+0x0 has a field ref); the role of a4 (section marker) and the CRTMathHelper_e1f0 index arithmetic (a2<<6 + a5 + 2992) are not confirmed; sub_5651B0 is invoked twice per line (once for the break check, once for the data-line check).
- 0x004F3190: the ABI lead name suggests 2nd/3rd-order evaluation but only quadratic terms are present; the dual-purpose return value (a3 when enabled, a4 when disabled) is an unusual convention with unconfirmed intent.
- 0x004F3490: field element stride and long double element size are ambiguous in the raw source (packet fields are 0x90, 0x98, 0xA0); the purpose of argument a2 is not evidenced.
- 0x004F6720: owner identity is unknown (LEGACY ABI lead names the routine, not a class); dbl_59E880 is attributed as the 0.5 HalfStep constant DERIVED from analysis because the global does not appear by name in the raw source.
- 0x004F6850: the return value of sub_5881F0 is not captured in the decompiled body, so it is unresolved whether the helper randomizes via side effect or via a return value lost by the decompiler; owner identity is unknown.
- 0x004F6880: same sub_5881F0 return-value ambiguity as 0x004F6850; the ABI lead is the failure marker FAIL_4f6880 and provides no owner class.
- 0x004F6950: coefficients are read as doubles from this+0x2FC..0x384; the physical meaning of each coefficient (enable byte, quadratic terms, absolute-value terms) is unproven and caller-dependent.
- 0x004F6A50: the physical meaning of the four coefficients as force vs torque, and the meaning of input a2, are DERIVED from callers not proven by the packet; why the linear term is split across two coefficients (0x4E0 and 0x4F0) is not explained.
- 0x004F8330: globals flt_59E43C/flt_59E440 are listed as read but do not appear in the raw source; semantic purpose (reciprocal distance/stiffness factor) is prose-only; this+0x88 is recalculated every frame so an external poke does not persist.
- 0x004F87C0: element stride (8 floats per index) is inferred from the indexed writes; element structure layout beyond the written slots and the specific HUD semantics of the gain/magnitude/index fields are not established.
- 0x004FAE70: global double dbl_59E430 is read per packet facts but does not appear in the decompiled body; likely a constant consumed by CRTFtol or adjacent compiler-emitted code.
- 0x004FAF60: the meaning of the propagated cosine-similarity array this+0xBC (up to 4 entries) is DERIVED and its consumer is not evidenced; the identities of the primary/alternative/tertiary linked objects are not named; the exact mapping of the five float constant globals (0x59E43C, 0x59E440, 0x59E660, 0x59E8A4, 0x5AD274) to the inline literals is not established; the LEGACY ABI name AI_Opponent_Relative_Positioning is contradicted by the analysis.
- 0x004FB6D0: the ABI lead Unidentified_Logic_Collision_Impulse_Response_Co was not usable for naming; four globals (0x59E43C, 0x59E440, 0x59E478, 0x59E5FC) are listed by extraction as read but never appear in the raw source; the two sub-struct pointers at this+0x110/0x10C are unnamed; the 10.0 sentinel and 3.0 Y-margin are unexplained; the direction vector and bias thresholds at this+0x20..0x28, 0x58, 0x5C are read-only here with external writers.
- 0x00534B00: identity and semantics of callee sub_534B10 are unknown; the meaning of the -1 argument (likely a sentinel/resource id) is not evidenced; seven diverse callers hint at a generic shared helper but do not establish its role.
- 0x00535390: no field offsets are asserted as packet evidence (the packet field list is empty); the object layout (a1+0/4/8/20/56/64/68/72/88/92) and the meaning of mode a3 (0/1/2) and byte 'w' at a1+92 are structural, not semantically proven; the structural twin with MemoryAllocation_5160 (00405160) is DERIVED and unverified.
- 0x005355A0: the file-handle destructor is called in the final return but its address is absent from the packet callees, so no evidence ref binds it; the copy/sync semantics of ArithmeticComparison_55f0 cannot be verified; the -2 return for a NULL stream and the mode != 'w' bypass path are undocumented; FileReadLoop is named as a read loop yet gates a write-mode flush (ambiguous under the legacy name).
- 0x0054B3B0: the semantics of the BitmaskClear arguments (64, 0, 0) and the location of the bitmask it clears are unknown; BitmaskClear is not listed among the packet's callees.
- 0x0054B420: semantic meaning of the three read fields (0x20, 0x24, 0x28) and of the returned pointer a4 is unknown; owning object type is unknown.
- 0x0054B4D0: global dbl_5B8960 is listed as referenced but does not appear in the raw source text; InterruptDispatch at 0x0058957A receives each float before it is stored; its effect on the value or side-effects on the object are unknown.
- 0x0054B950: identity of the indirect transform function behind D3DDeviceWrapperPtr vtable+4 is not resolved; the transform destination (this+104) conflicts with the field table's interpretation of this+0x218 as cached position data; the node+220 (0xDC) transform input and the coordinate origin/space of 0x2EC/0x2F0/0x2F4 are unknown.
- 0x0054C030: the semantic meaning of bits 0x2 and 0x4 in the flag field at 0x3C is not established; the exact role of a2/a3 as an action/enable pair is not evidenced beyond the raw bit operations.
- General: class groupings for WheelForceParameterBlock, SuspensionLinkBlock, RandomizedParameterBlock, VehiclePhysicsEffectBlock, TirePhysicsSystem, TireModelSubBlock, HdvVehicleSetupParser, DualQuadraticCurve, ParameterizedCurve, VehiclePhysicsState, CullableRenderObject, TeamEffectLoader, TireBrushSystem, HudElementArray, SignedIndexLookupTable, BufferedFileStream, TripleParameterAccessor, SceneNodePositionCache and SceneGraphNode are GUESS (shared-layout or shared-caller inference, not packet-proven ownership). Rule 8 respected: equal offsets from different bases are not merged; dereferenced bases keep their pointer-chain identity.
- Worker agreement cannot create CONFIRMED facts; every name and grouping here is at best DERIVED.
