# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Generic runtime-object subsystem reconstructed from 25 validated IR functions. Three clusters carry defensible shared-state evidence: VehicleSurfaceState (per-frame vehicle-surface scalars: brake cooling effectiveness, slip-velocity norm, clamped intensity ratio; contiguous this-field range 0x34A8-0x3D60), ForceAccumulator (a float accumulator with hysteresis clamping plus two per-frame forwarders that dispatch the accumulated value into the physics force-scale and random-weighted audio-mix paths, gated on the same this+0x32BC mode flag), and DDSImageDecoder (DDS header validation, format classification and pixel decode, plus a setjmp/longjmp-protected streaming decoder sharing the format-ID/palette/buffer field block this+0x0..0x40). Remaining functions are lifecycle helpers (tree and linked-list destruction, COM-like vtable destruction chain, struct/table/field initializers), the force-feedback state logger writing into a 432-byte-slot ring buffer, VFX library loading, and thin accessors/forwarders with unknown owners. All owner assignments are DERIVED or GUESS proposals from within-packet call/field evidence only.

## Function roles

- `0x004E5080` **VehicleSurfaceState** — Computes and clamps the per-frame brake cooling effectiveness factor on the vehicle object
- `0x004E9980` **VehicleSurfaceState** — Computes the slip-velocity norm for the particle-effects path
- `0x004ED0F0` **ForceAccumulator** — Accumulates a float input with upper clamp and hysteresis reduction; shared accumulator kernel
- `0x004ED1C0` **ForceAccumulator** — Per-frame forwarder that accumulates a float then dispatches the physics force-scale
- `0x004ED1F0` **ForceAccumulator** — Per-frame forwarder that accumulates a float then dispatches the random-weighted audio mix
- `0x004EF2E0` **ForceFeedbackStateLogger** — Throttled force-feedback state-change logger writing encoded events into a ring buffer
- `0x004F1B10` **VehicleSurfaceState** — Computes an absolute ratio clamped to [0,1] as a normalized intensity
- `0x004F6AB0` **GlobalTableInitializer** — Initializes a 45-entry global table and reallocates a string buffer per entry
- `0x004F6BC0` **StructZeroInitializer** — Zeroes 17 consecutive dwords of a struct
- `0x004F8250` **ObjectDestructorHelper** — COM-like vtable destruction-chain helper that nulls the caller's pointer
- `0x004F8280` **UnknownObject** — Palette-index lookup returning an RGB color triple into output floats
- `0x004F8AB0` **UnknownObject** — Element-parameterized float accessor gated by an enable flag byte
- `0x004F8B50` **VfxModuleLoader** — Loads the VFX dynamic library and resolves/caches its five entry points
- `0x004F9150` **UnknownObject** — Thin wrapper forwarding a global as the argument to a field getter
- `0x004F9190` **UnknownObject** — Nullable accessor returning an object field or the default value 1
- `0x004FC850` **FloatRangeStructInitializer** — Constructor-style initializer zeroing fields and setting two 20.0f defaults
- `0x004FC901` **FloatRangeStructInitializer** — Initializer writing three consecutive dwords, two of them the 20.0f pattern
- `0x004FCA50` **LinkedPointerListContainer** — Releases a linked pointer list, freeing flagged payloads and each node
- `0x004FD6D0` **UnknownObject** — Two-stage cleanup delegating to a sub-object reset and a dual-list destruction
- `0x004FF127` **UnknownObject** — Trivial render-object field setter
- `0x005001B0` **DataBufferWithPositiveSentinel** — Clears a data buffer and writes the positive FLT_MAX sentinel
- `0x00500F55` **TreeListNode** — Recursive tree/list node destructor with ownership-flagged payload frees
- `0x00500FCA` **DDSImageDecoder** — Validates DDS headers and decodes pixel data into a BGRA buffer
- `0x005016E0` **DispatchRecoveryContext** — Vtable callback dispatch guarded by a setjmp/longjmp recovery block
- `0x00501722` **DDSImageDecoder** — State-machine streaming texture decoder (formats 50 and 22)

## Proposed classes

### VehicleSurfaceState

Per-frame vehicle-surface scalar state: brake cooling effectiveness computation, slip-velocity norm for particle effects, and a clamped normalized intensity ratio. Membership is inferred from a shared `this` base and contiguous field range in the vehicle-struct region (0x34A8-0x3D60), not independently proven.

Methods: `0x004E5080`, `0x004E9980`, `0x004F1B10`

- `this+0x000034A8` `float referenceTemperature` (read, DERIVED)
- `this+0x000034B0` `float rotationMatrixRow0X` (read, GUESS)
- `this+0x000034B4` `float rotationMatrixRow0Y` (read, GUESS)
- `this+0x000034B8` `float rotationMatrixRow0Z` (read, GUESS)
- `this+0x000034BC` `float rotationMatrixRow1X` (read, GUESS)
- `this+0x000034C0` `float rotationMatrixRow1Y` (read, GUESS)
- `this+0x000034C4` `float rotationMatrixRow1Z` (read, GUESS)
- `this+0x000034C8` `float rotationMatrixRow2X` (read, GUESS)
- `this+0x000034CC` `float rotationMatrixRow2Y` (read, GUESS)
- `this+0x000034D0` `float rotationMatrixRow2Z` (read, GUESS)
- `this+0x000034D4` `float positionX` (read, GUESS)
- `this+0x000034D8` `float positionY` (read, GUESS)
- `this+0x000034DC` `float positionZ` (read, GUESS)
- `this+0x00003570` `float brakeCoolingEffectiveness` (read_write, DERIVED)
- `this+0x000035B0` `float wheelCoolingValueA` (read, GUESS)
- `this+0x000036A8` `float wheelCoolingValueB` (read, GUESS)
- `this+0x000037A0` `float wheelCoolingValueC` (read, GUESS)
- `this+0x00003898` `float wheelCoolingValueD` (read, GUESS)
- `this+0x00003964` `float ratioNumerator` (read, DERIVED)
- `this+0x00003968` `float ratioDenominator` (read, DERIVED)
- `this+0x00003990` `float directCoolingSource` (read, GUESS)
- `this+0x00003994` `float coolingOffsetConstant` (read, GUESS)
- `this+0x000039B4` `int coolingMode` (read, GUESS)
- `this+0x000039EC` `byte coolingDirectEnable` (read, GUESS)
- `this+0x000039F0` `int coolingSelectorCopy` (write, GUESS)
- `this+0x00003A04` `float temperatureDelta` (read_write, DERIVED)
- `this+0x00003A08` `int coolingSelector` (read, DERIVED)
- `this+0x00003B60` `float slipReferencePointX` (read, GUESS)
- `this+0x00003B64` `float slipReferencePointY` (read, GUESS)
- `this+0x00003B68` `float slipReferencePointZ` (read, GUESS)
- `this+0x00003B6C` `float slipNormThreshold` (read, GUESS)

### ForceAccumulator

Float accumulator with an upper clamp and two hysteresis reduction thresholds, plus two per-frame forwarders that feed the accumulated value into the physics force-scale and random-weighted audio-mix dispatches. The three methods are linked within the packet by the AccumulatorClamp call chain and the shared this+0x32BC dispatch gate.

Methods: `0x004ED0F0`, `0x004ED1C0`, `0x004ED1F0`

- `this+0x000032BC` `dword dispatchModeFlag` (read, DERIVED)
- `this+0x00003A6C` `float floatAccumulator` (read_write, DERIVED)
- `this+0x00003A70` `float accumulatorOutput` (read_write, GUESS)
- `this+0x00003A78` `float accumulatorCapBase` (read, GUESS)
- `this+0x00003A80` `float accumulatorSource` (read, GUESS)
- `this+0x00003D60` `dword accumulatorFlag` (read_write, GUESS)

### ForceFeedbackStateLogger

Throttled force-feedback state-change logger. Compares a stored 18-byte FF snapshot against the live state on a 0.125s debounce window, force-logs after 4.0s, and writes encoded events (kind 6 or 18) with object id and session time into a 432-byte-slot ring buffer.

Methods: `0x004EF2E0`

- `this+0x00000004` `dword objectId` (read, DERIVED)
- `this+0x00001018` `float lastLogTimestamp` (read_write, DERIVED)
- `this+0x0000101C` `dword ffSnapshotWord0` (read_write, GUESS)
- `this+0x00001020` `dword ffSnapshotWord1` (read_write, GUESS)
- `this+0x00001024` `dword ffSnapshotWord2` (read_write, GUESS)
- `this+0x00001028` `dword ffSnapshotWord3` (read_write, GUESS)
- `this+0x0000102C` `word ffSnapshotWord4` (read_write, GUESS)

### DDSImageDecoder

DDS/texture decoder. decodeDdsTexture validates headers and bounds, classifies the pixel format into an internal format ID, and decodes pixel rows (palette expansion, RLE, bit/nibble unpacking, byte copy) into a BGRA buffer. ImageTextureDecompressor is a setjmp/longjmp-protected streaming decoder (formats 50 and 22) sharing the same field block and one common caller (0x00502A15).

Methods: `0x00500FCA`, `0x00501722`

- `this+0x00000000` `int internalFormatId` (read_write, DERIVED)
- `this+0x00000004` `pointer pixelBuffer` (read_write, DERIVED)
- `this+0x00000008` `pointer paletteBuffer` (read_write, GUESS)
- `this+0x0000000C` `int width` (write, DERIVED)
- `this+0x00000010` `int height` (write, DERIVED)
- `this+0x00000014` `int topDownFlag` (write, GUESS)
- `this+0x00000030` `int rowStride` (write, DERIVED)
- `this+0x00000034` `int zeroFlag` (write, GUESS)
- `this+0x00000038` `int bufferOwned` (read_write, DERIVED)
- `this+0x0000003C` `int paletteExpanded` (read_write, GUESS)
- `this+0x00000040` `int paletteOnlyRequest` (read, DERIVED)

### DispatchRecoveryContext

Recovery thunk installed as vtable entry 0 of the texture decoder's setjmp/longjmp dispatch block. Calls a vtable callback, longjmps on a recovery buffer past the vtable base, and restores two context words when execution continues past the longjmp.

Methods: `0x005016E0`

- `this+0x00000000` `pointer vtableBase` (read, DERIVED)
- `this+0x00000014` `pointer recoveryContext` (read, DERIVED)
- `this+0x00000018` `dword contextWord1` (write, GUESS)
- `this+0x00000030` `dword contextWord7` (read, GUESS)
- `this+0x00000034` `dword contextWord8` (read, GUESS)
- `obj+0x00000008` `function_pointer dispatchCallback` (read, DERIVED)

### TreeListNode

Recursive tree/list node. Data pointers at +0x4 and +0x8 are freed via FreeWrapper only when their ownership flags at +0x38/+0x3C are set; child node pointers at +0x4C/+0x50 are recursively destroyed then freed.

Methods: `0x00500F55`

- `this+0x00000004` `pointer dataPointerA` (read, DERIVED)
- `this+0x00000008` `pointer dataPointerB` (read, DERIVED)
- `this+0x00000038` `dword ownershipFlagA` (read, DERIVED)
- `this+0x0000003C` `dword ownershipFlagB` (read, DERIVED)
- `this+0x0000004C` `pointer childNodeA` (read, DERIVED)
- `this+0x00000050` `pointer childNodeB` (read, DERIVED)

### LinkedPointerListContainer

Container holding a singly linked list of nodes at this+0x54; release walks the list, frees each node's payload through FreeWrapper only when the node flag byte at +0x8 is non-zero, frees each node, and zeroes the four tracking fields.

Methods: `0x004FCA50`

- `this+0x00000054` `pointer listHead` (read, DERIVED)
- `this+0x00000058` `pointer listCurrent` (write, GUESS)
- `this+0x0000005C` `dword listCount` (write, GUESS)
- `this+0x00000060` `dword listState` (write, GUESS)
- `*(this+0x58)+0x00000004` `pointer nextNodePointer` (read, DERIVED)

### ObjectDestructorHelper

COM-like destruction helper: guards the object pointer at the caller's slot, runs the vtable destruction chain (slot 2 release, slot 6 cleanup, slot 0 delete with argument 1), then nulls the caller's pointer.

Methods: `0x004F8250`

- `this+0x00000000` `pointer objectSlot` (write, DERIVED)
- `obj+0x00000000` `pointer objectPtr` (read, DERIVED)
- `*(obj+0x0)+0x00000000` `function_pointer vtableDeleteSlot` (read, DERIVED)
- `*(obj+0x0)+0x00000008` `function_pointer vtableReleaseSlot` (read, DERIVED)
- `*(obj+0x0)+0x00000018` `function_pointer vtableCleanupSlot` (read, DERIVED)

### FloatRangeStructInitializer

Constructor-style initializer of a 6-dword object: zeroes the first four dwords and sets both trailing floats to 20.0f (FloatFieldInitWithDefaults), or writes offset 0xC from a parameter plus the two 20.0f floats (InitThreeFloatFields). Both methods write the same 0x10/0x14 defaults.

Methods: `0x004FC850`, `0x004FC901`

- `this+0x00000000` `dword field0` (write, GUESS)
- `this+0x00000004` `dword field1` (write, GUESS)
- `this+0x00000008` `dword field2` (write, GUESS)
- `this+0x0000000C` `dword field3` (write, GUESS)
- `this+0x00000010` `float defaultFloatA` (write, DERIVED)
- `this+0x00000014` `float defaultFloatB` (write, DERIVED)

### StructZeroInitializer

Zeroes 17 consecutive dwords (offsets 0x0 through 0x40): the header dword, the dword at index 16, and a 5-iteration loop over dword indices 1..15.

Methods: `0x004F6BC0`

- `this+0x00000000` `dword headerDword` (write, GUESS)
- `this+0x00000008` `dword fieldIndex2` (write, GUESS)
- `this+0x0000000C` `dword fieldIndex3` (write, GUESS)
- `this+0x00000040` `dword fieldIndex16` (write, GUESS)

### DataBufferWithPositiveSentinel

Clears a 0x1B0-byte data region at this+0x8 to zero and writes the positive FLT_MAX sentinel at this+0xC; always returns 0. Used during list-iteration reset.

Methods: `0x005001B0`

- `this+0x0000000C` `float positiveSentinel` (write, DERIVED)

### GlobalTableInitializer

Initializes a 45-entry global table centered on dword_8AF8F8 (5 dwords per entry), resetting sentinel fields, and calls StringCopyWithBufferRealloc(byte_5EA438) per entry, discarding the result.

Methods: `0x004F6AB0`


### VfxModuleLoader

Loads the VFX dynamic library, caches the module handle, resolves and caches five entry points (VFXOpen, VFXClose, VFXZeroSet, VFXSetVideoMode, VFXGetTracking), and returns 1 on load failure, 4 on missing exports, else calls VFXOpen() and returns 0.

Methods: `0x004F8B50`


## Compatibility contracts

- **VfxLibraryExportContract** — A replacement executable that loads the VFX library must provide a DLL exposing exactly the five exports VFXOpen, VFXClose, VFXZeroSet, VFXSetVideoMode and VFXGetTracking, each resolvable by GetProcAddress from the module handle. The loader returns 1 on load failure, 4 when any export is missing, and 0 after calling the cached VFXOpen pointer on success.
- **DdsDecodeInputContract** — The DDS decoder accepts a DDS header (buffer at least 0x28 bytes; header size field and the pixel-format marker WORD at header+12 must equal 1; pixel-data offset must not exceed the buffer) and returns -2147467259 (E_FAIL) on malformed/truncated input and -2147024882 (E_OUTOFMEMORY) on allocation failure. When this+0x40 is zero the call is a format query only; otherwise the decoder allocates and fills a pixel buffer (BGRA rows, stride at this+0x30).
- **ForceFeedbackEventLogContract** — The force-feedback logger reads session time from dbl_8AFEA0 and emits events through ProgressBarEventEncode into a ring buffer whose write pointer is dword_8AAE64, count dword_83EE60 (ceiling 1023), and slot stride is 432 bytes. Each event carries the object id (field +0x4), session time, and an 18-byte force-feedback state payload (four dwords plus a 16-bit word) at slot+8; the event kind is 6 when the state zero-test passes, else 18.
- **VtableDestructionChainContract** — Object destruction follows a vtable-driven chain: slot 2 (vtable+8) release, slot 6 (vtable+24) cleanup, then slot 0 (vtable+0) delete with argument 1, after which the caller's pointer is nulled. A replacement object type used in this path must implement these three vtable slots.

## Unresolved

- VehicleSurfaceState membership for BrakeCoolingPostTreatment, ComputeSlipVelocityNorm and RatioComputationWithClamping is inferred from a shared `this` base and contiguous field ranges in the vehicle-struct region; the packet does not independently prove common ownership.
- The exact binding of the six globals flt_59E43C/59E440/59E444/59E450/59E7F8/59E828 to the compiled constants (50.0, 0.0099999998, 0.5, 0.25) is not determinable from this packet.
- The two brake-cooling lookup tables indexed by this+0x3A08 (base 14796, base 18464, each element 4 bytes, split at index 7) have no per-slot meaning here; what the selector at 0x3A08 encodes (cooling profile, brake circuit, axle index) is unconfirmed.
- TireBrushModelForceSolver is called by AccumulatorClamp per the raw source but no callee address is recorded in the packet; its identity is unconfirmed.
- The mode flag at this+0x32BC suppresses the physics/audio dispatches when non-zero; its setters are unknown.
- Force-feedback event kinds 6 and 18 have no confirmed semantic meaning, and the reader of the 432-byte-slot ring buffer (dword_8AAE64, count dword_83EE60) is unknown.
- Globals flt_59E46C and flt_59E4E0 (logger) and flt_59E450, flt_59E868, flt_59E8B4, flt_59E8FC, flt_5ACEE8 (accumulator) are flagged as accessed but appear nowhere in the raw decompilation; their binding is unverifiable here.
- The 3.2 bias and the clamp threshold at this+0x3B6C in ComputeSlipVelocityNorm are DERIVED from caller context; the relationship between global flt_5AD1D8 (named CollisionRadiusBias in prior analysis) and the folded literal is unconfirmed.
- The ratio fields at 0x3964/0x3968, the enable flag at element+180 of FlaggedFloatAccessor, and the +FLT_MAX sentinel consumers have no confirmed semantic roles; the result<0 branch in RatioComputationWithClamping is dead code (fabs can never yield a negative).
- The 45-entry global table centered on dword_8AF8F8 extends 8 bytes before it (writes at v0-2 and v0-1 reach 0x8AF8F8-8 and -4); table start, entry field layout, and the discarded StringCopyWithBufferRealloc return are unknown.
- The setjmp/longjmp dispatch blocks in the texture decoders (state-61 init, 424-byte buffer, recovery vtable at entry 0) rely on decoder-internal state values (v28 1 and 3); DDS internal format ID enum semantics and the byte-exact RLE op-code behavior are not validated against real data.
- StructZeroInitializer and FloatRangeStructInitializer both use base `this` with overlapping low offsets (0x8, 0xC) but different extents (17 dwords vs 6 dwords); whether they initialize the same struct is not evidenced.
- DualLinkedListDestruction (named by ResetThenDestroyList) and the sub-object at this+264 have no packet addresses or field evidence.
- ObjectDestructorHelper vtable slot targets are indirect, so slot 2/6/0 call identities and the meaning of the delete argument 1 are not statically resolved.
- ColorPaletteLookupByIndex's returned component value is caller-dependent (consumer sub_4F70C0 not analyzed here) and the palette globals' owner module is unknown.
- VfxModuleLoader resolves five exports whose signatures/calling conventions are not evidenced; the library filename is external.
- The decode-only-when-this+0x40-nonzero behavior in the DDS decoder implies a format-query/decode dual contract whose caller side is unconfirmed.
- ForwardGlobalToFieldGetter's callee SimpleFieldGetter_bfc0 and the caller MultiTableCoordinateSearch of 0x004F9150/0x004F9190 are not in this packet's allowed references.
- The default branch v5 = *(float*)&a1 in BrakeCoolingPostTreatment reads the low dword of `this`; this is interpreted as a decompiler artifact of a register spill, but its exact origin is not confirmed.
