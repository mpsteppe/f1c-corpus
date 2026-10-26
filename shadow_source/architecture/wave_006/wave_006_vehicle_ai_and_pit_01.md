# VehicleAIAndPit

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

DERIVED architecture for the wave_006_vehicle_ai_and_pit_01 packet. The packet contains 25 functions of which a defensible core is vehicle-AI/pit logic: AIDriverRandomTargetReset (0x0042AE20) clears per-driver random targets (this+0x45FC/0x45F8) and recalculates lateral force/torque via LateralForceTorqueCalculation; AIGearSelector (0x0042EAA0) writes a per-wheel gear into a per-driver matrix, gates TrackConfig and EventTriggerOnStateChange on the enable byte this+0x19A5, and raises dirty flags this+0x19A4/this+0x0 on change; TireForceModel (0x00431850 TireSuspensionForceComputation and 0x00447BB0 TireFrictionCurveEval) computes suspension force from compound data selected by the global mode selector dword_8AEEC0 and evaluates a piecewise friction curve from the slip field this+0x19C; SteeringAccumulatorState (0x00414E54) and SteeringInputSmoother (0x004569B0) accumulate steering deltas; ConstraintForceEvaluator (0x00454250) evaluates a per-entry constraint and records outcomes into the dword_7D1490 grid; DampingCurveBuilder (0x004FB5D0) fills two float arrays from a linked list; FailureCategoryNamingRegistry (0x004BB730) maps failure categories 1-9 to component names. The remaining functions are generic runtime/infrastructure binned into this scope by the packet builder, each proposed as a single-method GUESS class. No owner object is labeled by the packet; all class boundaries are GUESS groupings, and equal field offsets on unrelated bases are never merged. Packet-flagged globals absent from raw bodies (dword_59E48C, dword_8AD254, flt_59E670, flt_59EF84, flt_59EF88, flt_59EFA8, flt_59E91C, flt_5ACC84, dbl_5E751C, tbyte_5E7534) are preserved in unresolved_evidence_refs.

## Function roles

- `0x00404A50` **ObjectSlotAllocator** — Allocate an 88-byte object via OperatorNewNhMallocWrapper and field-initialize it (dwords cleared; +44/+52/+60 set to -1; +24 set to decimal literal 1142292480, interpreted as a float by existing analysis). Store the object pointer at this+0, or null on allocation failure; return this.
- `0x0040B410` **FixedStrideList** — Linear membership test over a fixed-stride list: when a2 is non-zero walk records starting at head this+0x0C advancing 160 bytes per element, bounded by the count this+0x10; return 1 on address match, else 0 (including empty-list and null-argument cases).
- `0x00414E54` **SteeringAccumulatorState** — Accumulate a per-frame steering delta (char a1) into a byte counter at target+51; when the signed add does not set the flag composite, record the target object pointer at state+12 and the delta at state+16. Register-based __usercall ABI (a1 in bl, target in edi, state base in esi); the rcr instruction is decompiler noise.
- `0x0042AE20` **AIDriverRandomTargetReset** — Conditionally reset AI driver random-selection targets: if the incoming index matches the primary target at this+0x45FC, clear it, recalculate lateral force/torque with index 100 via LateralForceTorqueCalculation, and zero this+0x4420; if it matches the secondary target at this+0x45F8, clear that target. Matches nothing otherwise.
- `0x0042EAA0` **AIGearSelector** — Set a per-wheel gear selection in a per-driver/per-wheel matrix (index v5 = (a3 + 11*a2) << 6). Positive a4 clamps the new gear to a4 or maxGear-1 into slot+20; non-positive a4 zeroes the saved-gear slot at index+196. When the enable byte this+0x19A5 is set, runs TrackConfig and EventTriggerOnStateChange; TrackConfig runs again unconditionally. On gear change sets dirty flags this+0x19A4 and this+0x0 to 1. Returns the previously saved gear. Invoked by IndexedCallWith1Increment.
- `0x00431850` **TireForceModel** — Compute tire suspension force: look up the session state value via SessionStateIndexedLookup; return 0 when tire brand data (unk_8ADB88) is unavailable or the compound pointer resolved from this+0xBC4 is null; select a base coefficient from compound fields +384/+56 by the mode selector global dword_8AEEC0 (0 = +384 scaled by 0.98, 1 = blend of +384 and +56, 2 = +56, else 0); scale again by 0.98 and return coefficient * (int this+0x1584 * double this+0x1578 + double this+0x1570) / session value while the coefficient stays positive. Called by sub_475A90.
- `0x00447BB0` **TireForceModel** — Piecewise tire friction curve from the slip double at this+0x19C: return 58.5 at slip >= 4.4 and 0.0 at slip <= 0.0; otherwise clamp the negative ramp v2 = max(slip - 0.4, 0.0) and the upper input v3 = min(slip, 4.0), and return (TrigTableLookup(this) * (v3 * 0.25 - v2 * 0.25) + v2 * 0.25) * 58.5.
- `0x00454250` **ConstraintForceEvaluator** — Evaluate a per-entry constraint force condition: select a field-vector base on this (this+3464, or this+4484 when a3 is non-zero), compute (v[a2*4+920] - v[a2*4+96]) * v[a2*4+64] - input[a2]; return 0 when the result is <= 0.34999999. Otherwise record 1056964608 (float 0.5) when input[a2] >= 0.075000003, else 0, into the dword_7D1490 grid at index 216*a3 + 27*a2, and return 1.
- `0x004569B0` **SteeringInputSmoother** — Smooth a steering input step into two float accumulator fields on a float-array object: choose a multiplier of 2.0 when a3 == 1, else 0.5, negated when the low byte of the float input a2 is zero; add the scaled delta to this+0xA0 and this+0xBC, passing each sum through InterruptDispatch and writing the result back to the same field. No early-return guards.
- `0x004636F0` **PositiveFloatThresholdGuard** — Positive-threshold guard: load the object pointer stored at this+0x0, read the float at obj+0x380, and return whether it is greater than 0.0 (zero threshold folded from flt_59E440). No side effects.
- `0x0046A980` **IDPairRegistryScanner** — Scan the global array of 7-dword entries from dword_7D1B08 up to dword_7D1FD8; when the first two entry dwords match the two dwords of the incoming pair pointer, rewrite the matched entry's first dword to 0 and its second to 89. Return the scan pointer after the array bound. Called from ControllerShifterMapping (0x0046A9C0).
- `0x004869E0` **RegionOffsetContainer** — Offset four stored region bounds (left/right/top/bottom at this+0x4/+0x8/+0xC/+0x10) by deltas a3/a2, redraw the union of old and new bounds via GuardedSubRectangleRenderDispatch, self-notify through vtable slot 44 (obj+0x2C), propagate the same deltas through the child linked list headed at this+0x90 (child next at child+0x8C, recursing into this function), and return the vtable-slot-160 (obj+0xA0) handler result.
- `0x00498D70` **DualListContainer** — Destroy the dual linked list owned by this via DualListDestruction, then conditionally free this through FreeWrapper_7bcf when bit 0 of a2 is set; return the original this pointer.
- `0x004BB730` **FailureCategoryNamingRegistry** — Map a failure category identifier (passed in ecx/this, 1-9) to a human-readable component name string via a jump-table switch: Engine for 1, Gearbox for 2, Clutch for 3 or 7, Suspension for 4, Brakes for 5, Accident for 6, Electronics for 8, Fuel for 9, and a default block for any other value.
- `0x004FB5D0` **DampingCurveBuilder** — Initialize two 8-entry float arrays on this (this+204 and this+236) from a linked-list walk rooted at this+0x110: return untouched when the head is NULL; fill both arrays with 500.0 when the seed float at this+0x3C is >= 500.0; otherwise walk nodes accumulating increments (node+0x3C), filling descending entries while entry index+1 is not below node thresholds (node+0x50 for array one, node+0x54 for array two), stopping at NULL or a self-referencing next (node+0x110). Invoked by ShortComputation_4790.
- `0x00502102` **AssertionFailureHandler** — Assertion-failure handler on the AI subsystem path: longjmp to the caller-supplied setjmp environment (a1) with state value 1 via LongjmpMSVCCRT, then fall back to __debugbreak(); declared noreturn.
- `0x00508E67` **VertexColorTextureEncoder** — Encode two float color channels into packed 32-bit words (each channel scaled by 32768.0, 16-bit per channel): convert the vertex buffer format first via DirectXVertexBufferFormatConversion when this+0x1048 is set; encode this[1046] (+0x1058) vertices with texel base this[11] (+0x2C), after an unconditional UtilityFunction_7473 pre-call; return the conversion-state global dword_8B009C.
- `0x0050DF95` **IndirectFunctionThunk** — Indirect-call thunk on the AI subsystem path: load the function pointer stored in global off_5D7878, call it, and return whatever the callee produced. Its only caller is QuaternionSlERP.
- `0x00513C38` **BoundedReferenceMatcher** — Bounded byte-string comparison against the fixed 8-byte reference buffer at byte_5AF564: return 0 immediately when the requested length is zero or the window start exceeds 7, clamp the length to the 8-byte window, and return the memcmp result for that window. Callers sub_50210E and sub_5119E9.
- `0x0051BAD1` **AudioProcessingDispatcher** — Per-object audio-processing dispatch over the descriptor array at this+0xC4 (84-byte stride): skip when the count at this+0x20 is not positive; select a processing routine by the per-object mode field (1 AudioSampleLookup, 2 AudioFIRConvolutionFilter, 4 FixedPointIDCT, 8 render-variant branch on this+0x44); unsupported modes write error codes 6 and 47 through the error object; write the chosen routine pointer to the output slot and transform the source buffer into the destination when the flag byte and stored-mode conditions permit (word copy, FIR fixed-point pass, or double-precision convolution).
- `0x0052E5E0` **HuffmanPairDecoder** — Decode two Huffman-coded symbols from a bitstream into 16-bit results: read per-symbol code lengths from the code table a3, extract (code length + 1) bits from the bitstream (buffer base this+0x24A4, bit position this+0x24A8) using lookup tables dword_5B4788 and dword_5B4820, advance the bit position per symbol, scale with tables at a4/a6 and a right-shift by 12, and write the two decoded words to the output array a5. Called by CompressedAudioDecoder.
- `0x00546430` **FlagGatedStateReset** — Conditional state reset: zero the dword fields at this+0x94 and this+0x98 when bit 2 of the byte at this+0x9C is clear; otherwise return immediately leaving both fields untouched. Read as a conditional reset rather than an accumulation step.
- `0x00583AA0` **GuardedHandlePairCloser** — Close two kernel handles guarded by per-handle validity flags: close the handle at this+0x1C (gated by flag this+0x24) and the handle at this+0xC (gated by flag this+0x14), clearing each field to 0 on success; return the result of the second CloseHandle attempt.
- `0x00590440` **StaticTableMembershipScanner** — Linear membership scan of a static 16-bit table from unk_5E7204 to off_5E7218 (exclusive): return 0 when the 16-bit argument matches a table word, 1 after the pointer walks past the end bound. Used as a range/validity check by LocaleEnumProc (0x0058FFEC) and sub_59033A (0x0059033A).
- `0x0059136E` **FloatingPointRemainderHelper** — Extended-precision floating-point remainder (x87 FPREM-style) helper: validate the control word of operand a2, classify both operands via byte_5E74FC and exponent masks, reduce a5 modulo a2 by repeated scaled subtraction (iteration count from the exponent-byte gap, divisor scaled by dbl_5E752C) or by direct __FPREM__ when the exponent gap is small, and reload the x87 environment when flag a1 requests it. Reached from DoublePrecisionFloatClassification.

## Proposed classes

### ObjectSlotAllocator

Allocate-and-construct helper for an 88-byte object: allocates via OperatorNewNhMallocWrapper, field-initializes (cleared dwords, -1 sentinels at +44/+52/+60, +24 set to a literal), and stores the pointer at this+0 (null on failure). The object type is unlabeled by the packet.

Methods: `0x00404A50`

- `this+0x00000000` `void* AllocatedObjectPtr` (write, GUESS)

### FixedStrideList

Container for fixed-stride records: head at this+0x0C, element count at this+0x10, membership tested by walking the 160-byte-stride chain. Record type and layout are unknown.

Methods: `0x0040B410`

- `this+0x0000000C` `void* RecordHeadPtr` (read, GUESS)
- `this+0x00000010` `int RecordCount` (read, DERIVED)

### SteeringAccumulatorState

Steering state accumulator: adds a per-frame delta (char) into a byte counter and, when the signed add stays clean, records the target object pointer and delta into a state object. The state and target identities, plus the +51/+12/+16 offsets, have no named field mapping in the packet.

Methods: `0x00414E54`


### AIDriverRandomTargetReset

Resets AI driver random-selection targets on a vehicle-sized object: clears the primary target at this+0x45FC (recalculating lateral force/torque with index 100 and zeroing this+0x4420) or the secondary target at this+0x45F8 when the incoming index matches. The meaning of index 100 and of this+0x4420 is unresolved.

Methods: `0x0042AE20`

- `this+0x000045FC` `int PrimaryRandomTarget` (read_write, GUESS)
- `this+0x000045F8` `int SecondaryRandomTarget` (read_write, GUESS)
- `this+0x00004420` `int LateralControlReset` (write, GUESS)

### AIGearSelector

Per-driver/per-wheel gear selection matrix: writes a clamped gear into slot+20 (or zeroes the saved slot), gates TrackConfig and EventTriggerOnStateChange on the enable byte this+0x19A5, and raises the dirty flags this+0x19A4/this+0x0 when the gear changes. The 11-row matrix layout and the v9 selector mapping are inferred from index arithmetic only.

Methods: `0x0042EAA0`

- `this+0x000019A5` `byte GearEnableFlag` (read, GUESS)
- `this+0x000019A4` `byte GearDirtyFlag` (write, GUESS)
- `this+0x00000000` `int StateDirtyFlag` (write, GUESS)

### TireForceModel

Tire force computation on a vehicle-sized object: suspension force from compound data selected by the global mode selector dword_8AEEC0 with per-state suspension terms at this+0x1570/0x1578/0x1584 and compound index at this+0xBC4; piecewise friction curve from the slip double at this+0x19C. Common ownership of the two methods is GUESS; the packet labels both owners UnknownObject.

Methods: `0x00431850`, `0x00447BB0`

- `this+0x00000BC4` `int CompoundIndex` (read, GUESS)
- `this+0x00001570` `double SuspensionTerm0` (read, GUESS)
- `this+0x00001578` `double SuspensionTerm1` (read, GUESS)
- `this+0x00001584` `int SuspensionTerm2` (read, GUESS)
- `this+0x0000019C` `double SlipInput` (read, GUESS)

### ConstraintForceEvaluator

Per-entry constraint force condition: selects a field-vector base (this+3464 or this+4484), combines a2-indexed floats, subtracts the input term, and records the 0.5/0 outcome into the global dword_7D1490 grid at index 216*a3 + 27*a2. Grid layout and consumer are unknown.

Methods: `0x00454250`


### SteeringInputSmoother

Steering input smoother: accumulates a scaled steering delta into two float fields (this+0xA0, this+0xBC) with a direction/rate multiplier selected by a3 and the low byte of the input, passing each update through InterruptDispatch. The low-byte direction reading is DERIVED.

Methods: `0x004569B0`

- `this+0x000000A0` `float SteeringAccumulatorPrimary` (read_write, DERIVED)
- `this+0x000000BC` `float SteeringAccumulatorSecondary` (read_write, DERIVED)

### PositiveFloatThresholdGuard

Guard wrapper holding a target-object pointer at this+0x0 and reading the float at obj+0x380 to test positivity. Object type behind this+0x0 and the purpose of the check are unknown.

Methods: `0x004636F0`

- `this+0x00000000` `void* TargetObjectPtr` (read, GUESS)
- `obj+0x00000380` `float PositiveFloatValue` (read, GUESS)

### IDPairRegistryScanner

Scanner over a global array of 7-dword entries (dword_7D1B08..dword_7D1FD8): clears the matched entry to 0/89 when its first two dwords equal the incoming ID pair. Called from ControllerShifterMapping. The meaning of the literal 89 and the entry layout beyond the first two dwords are unknown.

Methods: `0x0046A980`

- `this+0x00000000` `int IDPairFirst` (read, GUESS)
- `this+0x00000004` `int IDPairSecond` (read, GUESS)

### RegionOffsetContainer

UI region object with stored bounds (left/right/top/bottom at this+0x4/+0x8/+0xC/+0x10), a vtable pointer at this+0x0, and a child list at this+0x90: offsets bounds by deltas, redraws the damaged union via GuardedSubRectangleRenderDispatch, self-notifies through vtable slot 44 (obj+0x2C), recurses into children (next at child+0x8C), and returns the vtable-slot-160 (obj+0xA0) handler result. Vtable slots are indirect with no static callee.

Methods: `0x004869E0`

- `this+0x00000004` `int RegionLeft` (read_write, DERIVED)
- `this+0x00000008` `int RegionRight` (read_write, DERIVED)
- `this+0x0000000C` `int RegionTop` (read_write, DERIVED)
- `this+0x00000010` `int RegionBottom` (read_write, DERIVED)
- `this+0x00000000` `void* VTablePtr` (read, DERIVED)
- `this+0x00000090` `void* ChildListHead` (read, DERIVED)
- `obj+0x0000002C` `void(*)(void*, int) VTableNotifySlot44` (read, GUESS)
- `obj+0x000000A0` `void*(*)(void*) VTableHandlerSlot160` (read, GUESS)
- `*(this+0x11C)+0x0000008C` `void* ChildNextPtr` (read, DERIVED)

### DualListContainer

Container owning a dual linked list: tears the list down via DualListDestruction and frees the object via FreeWrapper_7bcf when bit 0 of the caller flag is set. Outer allocation ownership is not evidenced here.

Methods: `0x00498D70`


### FailureCategoryNamingRegistry

Maps failure category identifiers 1-9 to component-name string globals via a jump-table switch (Engine, Gearbox, Clutch for 3/7, Suspension, Brakes, Accident, Electronics, Fuel, plus a default). The category value arrives in the ecx/this register.

Methods: `0x004BB730`


### DampingCurveBuilder

Builds two 8-entry float arrays on this (this+204, this+236) from a linked list rooted at this+0x110: seed at this+0x3C >= 500.0 fills everything with 500.0, otherwise per-node accumulation with fill thresholds at node+0x50/node+0x54 and increments at node+0x3C. The 8-entry array bounds are a DERIVED reading of the loop counts.

Methods: `0x004FB5D0`

- `this+0x00000110` `void* ListNodeHeadPtr` (read, DERIVED)
- `this+0x0000003C` `float SeedFillValue` (read, GUESS)
- `*(this+0x110)+0x0000003C` `float NodeIncrement` (read, DERIVED)
- `*(this+0x110)+0x00000050` `int ArrayOneFillThreshold` (read, GUESS)
- `*(this+0x110)+0x00000054` `int ArrayTwoFillThreshold` (read, GUESS)
- `*(*(this+0x110)+0x110)+0x00000110` `void* NodeNextPtr` (read, DERIVED)

### AssertionFailureHandler

Assertion-failure handler on the AI subsystem path: unwinds to the caller-supplied setjmp state via LongjmpMSVCCRT with state 1, falling back to __debugbreak(); noreturn. The setjmp environment a1 is not otherwise established.

Methods: `0x00502102`


### VertexColorTextureEncoder

Texture vertex color encoder: scales two float channels by 32768.0 into packed 16-bit halves, converting the vertex buffer format first when this+0x1048 is set, over this+0x1058 vertices with texel base this+0x2C. Returns the conversion-state global dword_8B009C.

Methods: `0x00508E67`

- `this+0x00001048` `int ConvertVertexFormatFlag` (read, GUESS)
- `this+0x0000002C` `void* TexelBlockBase` (read, GUESS)
- `this+0x00001058` `int VertexCount` (read, GUESS)

### IndirectFunctionThunk

Thunk dispatching through the function pointer stored in global off_5D7878, returning the callee's result. The concrete target is unresolved.

Methods: `0x0050DF95`


### BoundedReferenceMatcher

Bounded compare of a caller buffer against the fixed 8-byte reference at byte_5AF564, clamping length to the 8-byte window. Reference content and buffer identity are unknown.

Methods: `0x00513C38`


### AudioProcessingDispatcher

Per-object audio-processing dispatch: iterates the descriptor array at this+0xC4 (84-byte stride), selects a routine by the per-object mode field (1/2/4/8, mode 8 sub-branches on this+0x44), writes the routine pointer to the output slot and transforms the buffer when the flag and stored-mode conditions permit. Unsupported modes raise errors 6/47. Routine identities are corpus labels.

Methods: `0x0051BAD1`

- `this+0x00000020` `int ObjectCount` (read, GUESS)
- `this+0x00000198` `int DispatchState` (read, GUESS)
- `this+0x000000E8` `int ModeField` (read, GUESS)
- `this+0x000000C4` `void* DescriptorArrayPtr` (read, DERIVED)
- `this+0x00000044` `int RenderVariantSelector` (read, GUESS)
- `this+0x000000F4` `byte TransformFlag` (read, GUESS)
- `this+0x000001C4` `int StoredMode` (read, GUESS)
- `this+0x00000110` `void* SourceBufferPtr` (read, DERIVED)
- `this+0x00000114` `void* DestinationBufferPtr` (read, DERIVED)
- `this+0x00000000` `void* VTablePtr` (read, DERIVED)
- `obj+0x00000000` `void* ObjVTablePtr` (read, DERIVED)
- `obj+0x00000014` `int ErrorCodeField` (write, GUESS)
- `obj+0x00000018` `int ErrorModeField` (write, GUESS)
- `*(this+0x114)+0x00000000` `void* OutputRoutineSlot` (write, GUESS)

### HuffmanPairDecoder

Bitstream Huffman decoder: reads per-symbol code lengths, extracts variable-width codes from the bitstream (base this+0x24A4, bit position this+0x24A8) via dword_5B4788/dword_5B4820 tables, scales with the a4/a6 tables, and emits two 16-bit results. Table layouts and the negative-shift rendering are unresolved.

Methods: `0x0052E5E0`

- `this+0x000024A4` `void* BitstreamBase` (read, DERIVED)
- `this+0x000024A8` `int BitPosition` (read_write, DERIVED)

### FlagGatedStateReset

Conditional counter reset: zeroes the dword fields at this+0x94 and this+0x98 when bit 2 of the flag byte at this+0x9C is clear. The canonical name implies accumulation but the body only zeroes; called by LinkedListAccumulation.

Methods: `0x00546430`

- `this+0x00000094` `int CounterFieldA` (write, GUESS)
- `this+0x00000098` `int CounterFieldB` (write, GUESS)
- `this+0x0000009C` `byte ResetGateFlags` (read, GUESS)

### GuardedHandlePairCloser

Closes two kernel handles guarded by per-handle validity flags: handle at this+0x1C gated by this+0x24, handle at this+0xC gated by this+0x14; each field cleared on successful CloseHandle. The kernel object type is unknown.

Methods: `0x00583AA0`

- `this+0x0000000C` `void* HandleTwo` (read_write, GUESS)
- `this+0x00000014` `int HandleTwoValidFlag` (read, GUESS)
- `this+0x0000001C` `void* HandleOne` (read_write, GUESS)
- `this+0x00000024` `int HandleOneValidFlag` (read, GUESS)

### StaticTableMembershipScanner

Scans a static 16-bit table (unk_5E7204..off_5E7218) for a value, returning 0 on match and 1 past the end bound. Used as a range/validity filter by LocaleEnumProc and sub_59033A. Table domain is unknown.

Methods: `0x00590440`


### FloatingPointRemainderHelper

x87 FPREM-style extended-precision remainder helper: validates the control word of operand a2, classifies operands via byte_5E74FC and exponent masks, reduces a5 modulo a2 by repeated scaled subtraction or direct __FPREM__ by exponent gap, optionally reloading the x87 environment. Reached from DoublePrecisionFloatClassification.

Methods: `0x0059136E`


## Compatibility contracts

- **AudioProcessingModeDispatchContract** — AudioProcessingModeDispatch reads the per-object mode field at this+0xE8 and the render-variant selector at this+0x44 to choose a processing routine for each 84-byte descriptor starting at this+0xC4: mode 1 AudioSampleLookup, mode 2 AudioFIRConvolutionFilter, mode 4 FixedPointIDCT, mode 8 one of three render variants, and any other mode writes error code 6 (with the offending mode at obj+0x18) or 47 through the error object at obj+0x14. The chosen routine pointer is written to the output slot at *(this+0x114)+0x0 and the buffer is transformed from this+0x110 to this+0x114 when flag this+0xF4 and stored-mode this+0x1C4 permit. A replacement must preserve the mode encoding and the error contract.
- **AIGearSelectionDirtyFlagContract** — AIGearSelectionSet writes a gear into slot+20 of the per-driver/per-wheel matrix (row (a3 + 11*a2) << 6), clamping to a4 or maxGear-1, or zeroes the saved-gear slot at index+196 for non-positive a4. When the enable byte this+0x19A5 is set, TrackConfig and EventTriggerOnStateChange run; when the new gear differs from the saved value, dirty flags this+0x19A4 and this+0x0 are set to 1. The previously saved gear is returned. A replacement must preserve the enable gate, the dirty-flag signaling and the returned previous gear.
- **AIDriverTargetResetContract** — ResetRandomDriverSelection clears the primary random target at this+0x45FC when the incoming index matches it, then recalculates lateral force/torque with index 100 via LateralForceTorqueCalculation and zeroes this+0x4420; a match on the secondary target at this+0x45F8 clears only that target. A replacement must preserve the per-target reset semantics and the recalc index 100.
- **TireForceComputationContract** — TireSuspensionForceComputation returns 0 when tire brand data (unk_8ADB88) or the compound pointer resolved from this+0xBC4 is unavailable; the mode selector global dword_8AEEC0 selects the coefficient (0 = compound field +384 scaled by 0.98, 1 = blend of +384 and +56, 2 = field +56, else 0), which is scaled by 0.98 again and combined with the per-state suspension terms (int this+0x1584 times double this+0x1578 plus double this+0x1570) divided by the session value, only while positive. TireFrictionCurveEval saturates the slip (this+0x19C) to 58.5 at >= 4.4 and to 0.0 at <= 0.0 with a TrigTableLookup-blended ramp between. A replacement must preserve the saturation bounds and the 0.98/0.5 scaling constants.
- **DampingCoefficientFillContract** — InitLinkedDampingCoefficients fills two float arrays (this+204, this+236) from a linked list rooted at this+0x110: bail when the head is NULL; fill all entries with 500.0 when the seed float at this+0x3C is >= 500.0; otherwise walk nodes accumulating the increment at node+0x3C and filling descending entries while entry index+1 is not below the thresholds at node+0x50 (array one) and node+0x54 (array two), stopping at NULL or a self-referencing next at node+0x110. A replacement must preserve the node layout and the 500.0 saturation.
- **FailureCategoryEnumContract** — FailureCategoryNameLookup maps a failure category identifier (passed in the ecx/this register) to a component name string via the jump table at jpt_4BB778: 1 Engine, 2 Gearbox, 3 and 7 Clutch, 4 Suspension, 5 Brakes, 6 Accident, 8 Electronics, 9 Fuel, with a default block for any other value. A replacement must preserve the category-to-name mapping and the default fallback.
- **GuardedHandlePairCloseContract** — CloseGuardedHandlePair closes two kernel handles guarded by per-handle validity flags: the handle at this+0x1C is closed only when the flag at this+0x24 is set, and the handle at this+0xC only when the flag at this+0x14 is set; each field is cleared to 0 only when its CloseHandle call succeeds. A replacement must preserve the per-handle gating and the clear-on-success behavior.
- **RegionOffsetRedrawContract** — AccumulateRegionOffsetAndDispatch offsets the four stored region bounds (left/right/top/bottom at this+0x4/+0x8/+0xC/+0x10) by the deltas, redraws the union of old and new bounds via GuardedSubRectangleRenderDispatch, self-notifies through vtable slot 44 (obj+0x2C), propagates the same deltas through the child list headed at this+0x90 (next at child+0x8C), and returns the vtable-slot-160 (obj+0xA0) handler result. A replacement must preserve the bounds field layout, the redraw-on-offset behavior and the child-list propagation.

## Unresolved

- The packet mixes a defensible vehicle-AI/pit core (AI target reset, gear selection, tire force, steering, constraint force, damping curves, failure naming) with generic runtime/infrastructure functions (object factory, list membership, dual-list teardown, handle close, thunk, reference compare, assertion handler, texture encode, audio dispatch, Huffman decode, locale range scan, FPU remainder, UI region offset). No owning class is evidenced; the binning is the packet builder's.
- Every packet owner is UnknownObject; all class boundaries are GUESS groupings, and common ownership of vehicle-size this offsets (0x4420, 0x45F8, 0x45FC, 0x19A4, 0x19A5, 0xBC4, 0x1570-0x1584, 0x19C) is not proven. Equal offsets on unrelated bases (e.g. this+0x0 as pointer in FloatComparisonAgainstThreshold versus dirty flag in AIGearSelectionSet) are not merged.
- Globals flagged by the packet as read but absent from their raw decompiled bodies are unresolved: dword_59E48C (0x0059E48C) for FAILWRONGTRIAGE, dword_8AD254 (0x008AD254) for TireSuspensionForceComputation, flt_59E670/flt_59EF84/flt_59EF88/flt_59EFA8 for SteeringInputSmoothingWithSaturation, flt_59E91C (0x0059E91C) for InitLinkedDampingCoefficients, flt_5ACC84 (0x005ACC84) for TextureEncode16BitPair, dbl_5E751C and tbyte_5E7534 for FloatingPointRemainder.
- The pairing of folded float literals (0.98, 0.5, 4.4, 4.0, 0.4, 0.25, 58.5, 32768.0) to the read-only constant globals (dbl_59EA70, dbl_59E880, dbl_59E430, flt_59E440, dbl_59E7D8, dbl_59EB50, dbl_59EC80, flt_59EF00, dbl_59EF08, dbl_59EF10) is DERIVED from existing analysis, not visible in the raw bodies.
- The dword_7D1490 constraint grid (index 216*a3 + 27*a2) and its consumer are unknown; the a2-indexed float row (+920/+96/+64) semantics in ConstraintForceEvaluator are unknown.
- RegionOffsetContainer uses vtable slots 44 (obj+0x2C) and 160 (obj+0xA0); these are indirect calls with no static callee record and are labeled self-notify/end-state handler only as DERIVED. The child-node layout beyond the next pointer at child+0x8C is unknown.
- InitLinkedDampingCoefficients writes two arrays at this+204 and this+236 with no packet field evidence; the 8-entry bounds are a DERIVED reading of the 7-to-0 loop counts.
- AssertionFailureHandler's a1 (the setjmp environment) is only forwarded to LongjmpMSVCCRT; its identity and the caller are not established.
- AudioProcessingDispatcher routine identities (AudioSampleLookup, AudioFIRConvolutionFilter, FixedPointIDCT, RenderModeBranch, AudioMixing, RenderingBranchOnDAT005d79dc) and the global buffers unk_5B0508/word_5B0588/dbl_5B05C8 are corpus labels, not runtime-proven; no static callers are recorded.
- The literal 89 written into matched entries by IDPairMatchAndClear and the 7-dword entry layout beyond the first two dwords are unexplained.
- The decimal literal 1142292480 written at +24 of the 88-byte object by FAILWRONGTRIAGE is interpreted as a float by existing analysis (DERIVED only); the -1 sentinel fields' meaning is unknown.
- PlayerSteeringUpdate records the target pointer at state+12 and the delta at state+16 and accumulates into a byte counter at target+51; these offsets have no named field mapping because the packet carries no field evidence for them.
- The callers flagged unresolved in the packet (0x00454350, 0x0049F070, 0x00548810) are preserved in unresolved_evidence_refs; their relationship to the cited functions is not otherwise evidenced.
