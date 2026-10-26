# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs a generic runtime object layer from 28 validated functions, dominated by the steering-wheel HUD frame path (all invoked from 0x0049D070) and by generic container/bitmap/list utilities. Two DERIVED classes are grounded: PooledBuffer (0x004B46B0, owner from caller BufferPoolAllocatorInitialization) and the composite HudTextRenderer (0x0049D440/0x0049D480) which shares the display-context pointer this+0x10 and the flattened this+0x64 value read. GUESS classes cover the race-state HUD dispatcher (0x0049D5D0), text geometry helpers (0x0049F710/0x0049F750), the control-profile UI mode switcher (0x0049F790), pit-operation timer updater (0x004A3570), the pitstop phase-mode state machine (0x004A55E0/0x004A5660), a valid-part count resolver (0x004A57F0), the AI state phase/flag pair (0x004A5E60/0x004A5E80), clamped float parameter slots (0x004B1DE0/0x004B20D0), stream serialization writers (0x004B41E0/0x004B4FB0), a per-row bitmap hash table (0x004B4760/0x004B47A0/0x004B4800/0x004B4840), the vehicle instance summary copy (0x004B51E0), and a field-compare list walker with a nested node record (0x004B5380/0x004B5460). Four functions (0x0049E7B0, 0x0049F530, 0x004B3DB0, 0x004B46F0) have no defensible owner and are left unowned. One GUESS state machine models the pitstop mode register (1 reset / 2 active). Two GUESS interfaces capture the HUD text render sink (sub_553070) and the ConditionalDispatch_6bd0 stream sink.

## Function roles

- `0x0049D440` **HudTextRenderer** — Formats a register/state value read through the display-context pointer (this+0x10 dereferenced 84 bytes deep, flattened to this+0x64) into a 16-byte local buffer via sub_49C6D0 (length bound 15), then renders it to the HUD text sink at screen position (4, 0) via sub_553070 and returns the render result. Invoked from the SteeringWheelAnimation frame path.
- `0x0049D480` **HudTextRenderer** — Initializes a 16-byte stack buffer via sub_49C670 (bound 15), then forwards it to sub_553070 at position (4, 21) with the value read as *(this+0x10)+0x54 (packet-flattened nominal target this+0x64) and returns the render result. Companion of 0x0049D440 on the steering-wheel HUD text path.
- `0x0049D5D0` **RaceStateHudDispatcher** — Race-session HUD render dispatcher on the steering-wheel frame path. Guards on render-resource pointer this+0x08 and display contexts A/B at this+0x14/this+0x18, renders a clipped backdrop from display-context-A width via ClippedRectRender, then routes HUD sub-rendering by race session state (dword_7CE048) and session type (dword_7C56A4) to timing/sector (0x0049D8B0), timestamped-string (0x0049DA60), batch-format (0x0049E170), brake/water-temperature (0x0049DB80), and session-specific handlers; session state 2 routes to sub_49DE40, session state 1 to ConditionalDispatch 0x0049E3E0.
- `0x0049E7B0` **UnknownObject** — Renders a colored horizontal bar whose fill proportion and color depend on a normalized per-corner value. Guards on vehicle equality by comparing the +18580 field of VehiclePtrArray[CurrentPlayerIndex] with VehiclePtrArray[CurrentVehicleIndex]; equal vehicles draw a dark background bar and a proportional fill bar colored by the normalized level ((-16711936) > 0.8, (-256) 0.5..0.8, (-65536) otherwise), different vehicles draw a full green bar. Fill width converted via CRTFtol and drawn through RenderDrawOperationWithClipping.
- `0x0049F530` **UnknownObject** — Parameter dispatch that reads a live parameter by mode index 0..4 (0 = SpeedMultiplier, 1/2 = two Kelvin-minus-273.16 temperature sources, 3 = raw dbl_7C919C, 4 = TireFrictionCurveEval on the curve at dbl_7C7428), applies a per-mode clamp range, stores the range width at a2+32, applies unit conversion (modes 1/2 Celsius-style *1.8-40, modes 3/4 *0.14503774), and drives FieldSetterTrigger/GuardedCall/sub_49ED20 on a2 with a3. Invoked from the steering-wheel frame path.
- `0x0049F710` **TextPositioningHelper** — Conditionally computes the difference a2 minus a safety-adjusted value and stores it through a3. When the guard argument a4 is non-zero the raw value is normalized in place via sub_5531F0(a1, &a4, &a1, 0); the stored result is a2 - adjusted_a4 and the adjusted a4 is returned. Invoked by StringFormatAndRender.
- `0x0049F750` **TextPositioningHelper** — Conditionally computes a centered span: when the guard argument a4 is non-zero the span is normalized in place via sub_5531F0(a1, &a4, &a1, 0), halved, stored as a2 minus the half through a3, and the half is returned. Companion of 0x0049F710 on the StringFormatAndRender positioning path.
- `0x0049F790` **ControlProfileModeSwitcher** — UI-mode dispatcher. When feature flag dword_7CC234 is set and the control-profile pointer dword_5EA518 equals the audio-device state dword_5EA528 whose mode field (+52) is 1 or 2, scans enable-mask byte_7CF7AC to select the next enabled mode index above this+0x00 (wrapping to 0) and stores it via FunctionCallWrapper_f150; otherwise stores the boolean (mode != 1). Mode-1 handling consumes input flags dword_7CC28C/dword_7CC2B8 (cyclic index advance via sub_49F170), dword_7CC2E4 (UtilityFunction_5750 on this+0x04), and dword_7CC310 (IndexDecrementWithBoundsWrap on this+0x04).
- `0x004A3570` **PitOperationTimerUpdater** — Dual-mode per-frame updater over an element array (base this+0x10, stride 120 bytes, count this+0x0C). Flag bit 0 at this+0x00 with countdown counter this+0x08 above 0 decrements the counter and resets each element's +68 dword to -1.0f then calls sub_4A2840(element, 0.0); flag bit 1 computes delta a2 - this[1] and runs sub_4A2840(element, delta) on every element. Both modes can run in one tick. Invoked by ConditionalDispatch_55a0.
- `0x004A55E0` **PitstopStateMachineController** — Pitstop phase selector. Reads the selector flag at this+0x2C; when non-zero advances the state machine via PitstopStateTransition on the candidate at this+0x10, otherwise on the candidate at this+0x0C, returning the selected transition result. Shared by the pitstop dispatchers 0x004A5660/0x004A5750/0x004A57A0 and AIStateMachineWithModeDispatch.
- `0x004A5660` **PitstopStateMachineController** — Pitstop mode selector. With input flag a2 zero resets the mode at this+0x28 to 1 and clears both selector flags (this+0x2C, this+0x30); with a2 non-zero transitions the mode to 2 and sets both flags when the mode is not already 2. Every path dispatches through ConditionalDispatch_55e0 and returns its result.
- `0x004A57F0` **ValidPartCountResolver** — Iterates i from 0 calling NthValidPartLookup(i); the loop breaks when the lookup returns 0 and i > 0, stores the terminating index into this+0xA8, and returns the last lookup result. Existing analysis reads the stored index as a count of valid parts.
- `0x004A5E60` **AiStatePhaseFlagController** — Sets AI state phase 4 at this+0x184 and byte flag 1 at this+0x180, then if the sub-object pointer at this+0x14 is non-null calls ShortComputation_3fe0 on it and returns its result (otherwise the return value is left undefined). Called by sub_4C6B60.
- `0x004A5E80` **AiStatePhaseFlagController** — Inverse of the AI state phase setter: clears the dword state at this+0x184 and the byte flag at this+0x180 to 0, then calls the sub-object routine on the pointer at this+0x14 when non-null, returning its result or 0 when null.
- `0x004B1DE0` **ClampedFloatParameter** — Stores a caller-supplied float (bitcast from integer a2) at this+0x14 and clamps it into the interval bounded by this+0x1C (lower) and this+0x20 (upper): the value is overwritten with the upper bound when above it and with the lower bound when below. Runs on vehicle parameter setup paths (DrivingModeParameterSetup, sub_4AE9F0, PhysicsParameterInitialization).
- `0x004B20D0` **ClampedFloatParameter** — Clamp setter structurally twin to 0x004B1DE0: stores the argument at this+0x14, clamps it to the inclusive range [this+0x1C, this+0x20], and returns the lower bound.
- `0x004B3DB0` **UnknownObject** — __thiscall identity pass-through: returns the this pointer unchanged with no calls, guards, field accesses, or state changes. No observable behavior; purpose must come from how the four callers use the returned this pointer.
- `0x004B41E0` **StreamSerializationWriter** — Writes a string through the ConditionalDispatch_6bd0 stream: dispatches a 4-byte container header, a 1-byte string length (strlen of the resolved string at this+0x04 with global byte_5EA438 fallback, overwriting a2), and the string content when the length is non-zero. Returns 1 unconditionally. Called by VehicleForceAerodynamicsComputation.
- `0x004B46B0` **PooledBuffer** — Struct zero-initializer: zeroes 0x34 bytes from byte offset 0x01 and the contiguous 0x34 bytes from 0x35, zeroes the dword at 0x6C, and zeroes sixteen consecutive dwords from byte offset 0x70 (4 iterations of 4 dwords). Returns this. Called by BufferPoolAllocatorInitialization.
- `0x004B46F0` **UnknownObject** — Cleanup routine that first calls PhysicsObjectListManager, then frees four linked lists of physics/collision nodes and zeroes their 4-dword head slots (spanning byte offsets 0x70-0xAC per the decompiled pointer arithmetic). Each node carries a next pointer at +4 and a type/active byte at +8; nodes with a non-zero type byte also free the buffer pointer at node+0 via FreeWrapper_7bcf, and every node struct is freed. Returns 0. Called by SpriteOverlayListCleanup.
- `0x004B4760` **PerRowBitmapTable** — Validated hash-table lookup gate (__stdcall). Rejects immediately when caller context a1 is non-zero, when the candidate dword has any 0xFC0000 bit set, or when the low byte is >= 0x68 (104); otherwise looks the low byte up in HashTableLookup (0x004B4840) seeded with 0, writing the result slot to a1, and returns 1 only on a hit. Called by CollisionObjectInsertion.
- `0x004B47A0` **PerRowBitmapTable** — Set or clear a single bit in a per-row bitmap. Bit index a5==255 is a no-op returning a1; otherwise computes row base v6 = 13*a4 + a1 + 1, sets bit a5%8 of the byte at v6 + a5/8 when a3 is non-zero or clears it (v7 AND NOT bit) when a3 is zero, and returns a5/8. a2 is never read. The 13-byte row stride matches the sibling routines sub_4B4800 and sub_4B4840.
- `0x004B4800` **PerRowBitmapTable** — Set a single bit in a per-row byte bitmap: sets bit a3%8 of the byte at this[13*a2 + 53 + a3/8] and returns a3/8. Row selector a2 picks a 13-byte stride; 53 is a fixed base offset inside the row. Unconditional, no bounds guard.
- `0x004B4840` **PerRowBitmapTable** — Hash-table-style key lookup on a byte-array object. Tests the presence bit (a3%8) at this[13*a2 + a3/8 + 1]; on a hit loads a bucket head from the 16-byte-stride slot this[16*(a2+7)] into the current-pointer slot at +8, walks the node chain comparing each node's low byte against key a3 (advancing via node+4), and on a match writes a secondary flag bit at this[13*a2 + a3/8 + 53] into a4 and returns the matched node pointer. Absence of head, empty node, or end of chain returns 0.
- `0x004B4FB0` **StreamSerializationWriter** — Struct serialization write through ConditionalDispatch_6bd0: emits a leading marker value 1, measures the embedded NUL-terminated string at this+1 with strlen, emits the length and the string bytes, then emits two byte-sized fields at this+65 and this+97 with constant 32 and two fields at this+132 and this+136 with constant 4. Always returns 1. Called by VehicleForceAerodynamicsComputation.
- `0x004B51E0` **VehicleInstanceSummary** — Copies driver/team identity strings and two file path strings from a source struct (a2) into this. Zero-initializes this via StructInitWithGlobalData, copies a 63-byte name from a2+17952 into this+1 (null-terminated at this[64]), extracts the filename after the last backslash of the path at a2+18196 into this+65 (terminated at this[96]), extracts the filename of the path pointer at a2+1920 (with global byte_5EA438 fallback) into this+97 (terminated at this[128]), and copies a flag byte from a2+18580 into this[0]. Returns this. Called from VehicleInstanceListBuilder.
- `0x004B5380` **FieldCompareListWalker** — Walks a linked list anchored at this+0x20 (cursor this+0x28), storing the threshold a2 at this+0x30. Each node is classified by FieldCompareConstant and FloatComparisonCheck; nodes outside the window bounded by node+12 (lower) and node+444 (upper) against a2 take a lower-bound path (ArithmeticComparison_3a90((node+440),(node+8)) then sub_5001B0), an upper-bound path (ArithmeticComparison_3a90((node+8),(node+440)) then VehicleDataBufferClear), or a fallback helper. Returns the final cursor value. Called by sub_4B9000.
- `0x004B5460` **FieldCompareListWalker** — Walks a linked list anchored at this+0x20 (walk position this+0x28). Every node's first DWORD is tested by FieldCompareConstant; the walk returns 0 as soon as a node fails the comparison (user cancel detected), and returns 1 when the list is empty, exhausted, or every node passes. Called by sub_4B9000.

## Proposed classes

### HudTextRenderer

Steering-wheel HUD register/state value text renderer. Reads a display-context pointer at this+0x10, dereferences 84 bytes deep (flattened nominal target this+0x64) to obtain the current register/steering value, formats it into a 16-byte local buffer (length bound 15) via sub_49C670/sub_49C6D0, and renders it to the HUD text sink at fixed screen positions via sub_553070. Both methods are invoked from the SteeringWheelAnimation frame path.

Methods: `0x0049D440`, `0x0049D480`

- `this+0x00000010` `void* display_context_ptr` (read, DERIVED)
- `this+0x00000064` `dword text_value_src` (read, UNKNOWN)

### RaceStateHudDispatcher

Race-session HUD dispatcher on the steering-wheel frame path. Guards on three render resources (render-resource pointer this+0x08, display contexts A/B at this+0x14/this+0x18), renders a clipped backdrop from display-context-A width via ClippedRectRender, and routes HUD sub-rendering by race session state (dword_7CE048) and session type (dword_7C56A4) to timing/sector, timestamped-string, batch-format, brake/water-temperature, and session-specific handlers; three jump tables back the dispatch switches.

Methods: `0x0049D5D0`

- `this+0x00000008` `void* render_resource_ptr` (read, DERIVED)
- `this+0x0000000C` `void* format_string_context` (read, DERIVED)
- `this+0x00000014` `void* display_context_a` (read, DERIVED)
- `this+0x00000018` `void* display_context_b` (read, DERIVED)

### TextPositioningHelper

Text geometry helpers invoked by StringFormatAndRender (0x0049F6A0). Both gate on a guard argument; when non-zero they normalize the span quantity in place via sub_5531F0 and return an offset relative to a2: SubtractionWithGuard returns a2 minus the adjusted guard, CenterCalc returns a2 minus half the adjusted guard (a centered offset).

Methods: `0x0049F710`, `0x0049F750`


### ControlProfileModeSwitcher

Audio/control-profile UI mode dispatcher. When the feature flag dword_7CC234 is set and the control-profile pointer dword_5EA518 equals the audio-device state dword_5EA528 whose mode field (+52) is 1 or 2, scans the enable-mask byte_7CF7AC to select the next enabled mode index above this+0x00 and stores it; otherwise stores the boolean (mode != 1). Mode-1 handling consumes four input flags to advance or decrement the secondary index at this+0x04.

Methods: `0x0049F790`

- `this+0x00000000` `dword mode_index` (read_write, GUESS)
- `this+0x00000004` `dword secondary_index` (read_write, GUESS)

### PitOperationTimerUpdater

Dual-mode per-frame updater over an element array (base this+0x10, stride 120 bytes, count this+0x0C). Flag bit 0 with countdown counter this+0x08 above 0 decrements the counter and resets every element's +68 slot to -1.0f before sub_4A2840(element, 0.0); flag bit 1 computes the delta a2 - this[1] and runs sub_4A2840(element, delta) on every element. Both modes are independent and can run in one tick. Invoked by ConditionalDispatch_55a0.

Methods: `0x004A3570`

- `this+0x00000000` `byte flags` (read, DERIVED)
- `this+0x00000004` `float reference_value` (read, GUESS)
- `this+0x00000008` `dword countdown_counter` (read_write, DERIVED)
- `this+0x0000000C` `dword element_count` (read, DERIVED)
- `this+0x00000010` `void* element_array` (read, DERIVED)

### PitstopStateMachineController

Pitstop phase mode controller. Mode field at this+0x28 (1 = reset, 2 = active) plus two selector flags this+0x2C/this+0x30. PitstopModeSelector (0x004A5660) transitions to mode 2 with both flags set when the input flag is non-zero and the mode is not already 2, otherwise resets to mode 1 with flags cleared; both paths dispatch through PitstopTransitionSelector (0x004A55E0), which reads the selector flag at this+0x2C and advances the state machine via PitstopStateTransition (0x004A5600) on the candidate at this+0x0C or this+0x10.

Methods: `0x004A55E0`, `0x004A5660`

- `this+0x0000000C` `void* candidate_state_a` (read, GUESS)
- `this+0x00000010` `void* candidate_state_b` (read, GUESS)
- `this+0x00000028` `dword mode` (read_write, GUESS)
- `this+0x0000002C` `dword selector_flag` (read_write, GUESS)
- `this+0x00000030` `dword selector_flag_2` (read_write, GUESS)

### ValidPartCountResolver

Resolves a count of valid parts by iterating NthValidPartLookup(i) (0x004A5820) from i = 0 and terminating at the first index whose lookup returns 0 (with i > 0), storing the terminating index at this+0xA8 and returning the last lookup result.

Methods: `0x004A57F0`

- `this+0x000000A8` `dword valid_part_count` (write, GUESS)

### AiStatePhaseFlagController

AI state phase/flag pair controller. Setter (0x004A5E60) writes phase 4 at this+0x184 and flag 1 at this+0x180; clearer (0x004A5E80) zeroes both. Each then invokes the sub-object computation on this+0x14 when non-null and returns its result.

Methods: `0x004A5E60`, `0x004A5E80`

- `this+0x00000014` `void* sub_object_ptr` (read, DERIVED)
- `this+0x00000180` `byte phase_flag` (read_write, GUESS)
- `this+0x00000184` `dword phase_state` (read_write, GUESS)

### ClampedFloatParameter

Clamped float parameter slot. Stores a caller-supplied float at this+0x14 and clamps it into the inclusive range bounded by this+0x1C (lower) and this+0x20 (upper). Two structural-twin setter methods (0x004B1DE0, 0x004B20D0) differ only in return value semantics. Runs on vehicle parameter setup paths.

Methods: `0x004B1DE0`, `0x004B20D0`

- `this+0x00000014` `float value` (read_write, DERIVED)
- `this+0x0000001C` `float lower_bound` (read, DERIVED)
- `this+0x00000020` `float upper_bound` (read, DERIVED)

### StreamSerializationWriter

Struct serialization writer emitting length-prefixed fields through the ConditionalDispatch_6bd0 stream sink (0x00566BD0). FilePathStreamWriter (0x004B41E0) emits a 4-byte container header, a 1-byte string length, and the string content (pointer at this+0x04 with global byte_5EA438 default fallback); serializeStructFields (0x004B4FB0) emits a leading marker, an embedded string at this+1 with its length, and four fixed-size fields. Both invoked from VehicleForceAerodynamicsComputation.

Methods: `0x004B41E0`, `0x004B4FB0`

- `this+0x00000004` `char* string_ptr` (read, DERIVED)

### PooledBuffer

Pooled buffer slot struct zero-initializer. Zeroes two contiguous 0x34-byte blocks at byte offsets 0x01 and 0x35, the dword at this+0x6C, and sixteen consecutive dwords from byte offset 0x70 (4 loop iterations of 4 dwords). Returns this. Owner is DERIVED from the caller BufferPoolAllocatorInitialization.

Methods: `0x004B46B0`

- `this+0x0000006C` `dword header_dword` (write, DERIVED)
- `this+0x00000070` `dword zeroed_dword_0` (write, GUESS)
- `this+0x00000074` `dword zeroed_dword_1` (write, GUESS)
- `this+0x00000078` `dword zeroed_dword_2` (write, GUESS)
- `this+0x0000007C` `dword zeroed_dword_3` (write, GUESS)

### PerRowBitmapTable

Per-row bitmap and bucket hash table on a byte-array object. Bitmap rows are 13 bytes apart: BitmapFlagSetClear (0x004B47A0) and BitfieldSetBit (0x004B4800) set/clear bit a%8 of the byte at 13*a + 1 (or +53). HashTableLookup (0x004B4840) tests the presence bit, loads a bucket head from the 16-byte-stride slot at 16*(a2+7), walks the node chain comparing each node's key low byte, and writes a secondary flag at +53. lookupHashTableKey (0x004B4760) is the validated gate (rejects key space >= 0x68 or the 0xFC0000 high mask) before the lookup.

Methods: `0x004B4760`, `0x004B47A0`, `0x004B4800`, `0x004B4840`


### VehicleInstanceSummary

Vehicle instance identity/path summary struct. DriverNameTeamPathCopy (0x004B51E0) zero-initializes the destination via StructInitWithGlobalData, copies a 63-byte driver/team name into this+1 (null terminator at this+0x40), extracts the filename after the last backslash of two path strings into this+65 (terminator at this+0x60) and this+97 (terminator at this+0x80), and copies a flag byte from the source at a2+18580 into this[0]. Invoked by VehicleInstanceListBuilder.

Methods: `0x004B51E0`

- `this+0x00000000` `byte driver_flag` (write, GUESS)
- `this+0x00000040` `byte name_string_end` (write, DERIVED)
- `this+0x00000060` `byte filename1_string_end` (write, DERIVED)
- `this+0x00000080` `byte filename2_string_end` (write, DERIVED)

### FieldCompareListWalker

Linked-list walker with per-node field comparison. Both methods anchor the list at this+0x20 with a walk cursor at this+0x28. FloatComparisonListIteration (0x004B5380) stores a threshold at this+0x30, classifies each node via FieldCompareConstant/FloatComparisonCheck, and takes lower/upper/fallback bound actions on nodes outside the [node+12, node+444] window. ListWalkWithUserCancelCheck (0x004B5460) returns 0 when FieldCompareConstant on a node's first dword is false (user cancel), 1 on empty/exhausted lists. Both invoked by sub_4B9000.

Methods: `0x004B5380`, `0x004B5460`

- `this+0x00000020` `void* list_head` (read, DERIVED)
- `this+0x00000028` `void* cursor` (read_write, DERIVED)
- `this+0x00000030` `float threshold` (write, GUESS)

### FieldCompareListNode

Node record walked by FieldCompareListWalker: first dword tested by FieldCompareConstant, next pointer at +4, per-node flag byte at +8, and float window bounds at +12 (lower) and +444 (upper). Layout is derived from the walker indexing only.

Methods: 

- `*(this+0x20)+0x00000000` `dword first_field` (read, GUESS)
- `*(this+0x28)+0x00000004` `void* next_ptr` (read, GUESS)
- `*(this+0x28)+0x00000008` `byte node_flag` (read, GUESS)
- `*(*(this+0x20)+0x0)+0x0000000C` `float lower_window_value` (read, GUESS)
- `*(*(this+0x20)+0x0)+0x000001BC` `float upper_window_value` (read, GUESS)

## Compatibility contracts

- **SteeringWheelHudTextRenderSink** — sub_553070 renders a formatted string to the HUD text sink at a screen position. Both HudTextRenderer methods call it with a 16-byte formatted buffer (length bound 15) at positions (4, 0) and (4, 21), passing the register/steering value read through this+0x10 as the text argument. A replacement executable must preserve the buffer/length convention and the two fixed positions.
- **ConditionalDispatchStreamSink** — ConditionalDispatch_6bd0 serializes (pointer, byte-count) segments: a 4-byte container header, a 1-byte length, N content bytes, and fixed-width fields (two byte-sized fields dispatched with constant 32 and two fields with constant 4). A replacement executable must reproduce the header/width/length framing observed in FilePathStreamWriter and serializeStructFields.
- **PitstopPhaseModeContract** — The pitstop mode register at this+0x28 takes values 1 (reset) and 2 (active); the active transition sets both selector flags (this+0x2C, this+0x30) and only fires when the mode is not already 2; both paths re-dispatch through the phase selector (0x004A55E0), which reads the selector flag at this+0x2C and advances PitstopStateTransition on the candidate at this+0x0C or this+0x10.
- **BitmapHashTableLayout** — Object-relative bitmap and bucket hash layout: 13-byte bitmap row stride with flag bits at base+1 and +53, 16-byte bucket stride at 16*(a2+7), node key low byte at node+0 with next pointer at node+4, and a key space 0..103 (reject low byte >= 0x68 and the 0xFC0000 high-bit mask).
- **FieldCompareListWalkContract** — List walkers anchored at this+0x20 with cursor at this+0x28 walk nodes whose next pointer is at node+4. FloatComparisonListIteration classifies nodes on the [node+12, node+444] window against a threshold stored at this+0x30; ListWalkWithUserCancelCheck returns 0 when FieldCompareConstant on a node's first dword is false, 1 on empty/exhausted lists.
- **VehicleInstanceSummaryLayout** — Vehicle instance summary struct layout inferred from the copy widths of DriverNameTeamPathCopy: 1-byte flag at this[0], 63-byte driver/team name (null terminator at this+0x40), 31-byte first filename (terminator at this+0x60), 31-byte second filename (terminator at this+0x80).

## Unresolved

- HudTextRenderer: the this+0x64 reading is a packet-flattened nominal target of the raw *(this+0x10)+0x54 access; the extractor's this+0x64 vs raw this[4]+84 discrepancy is unresolved, and the meaning of the +84 subfield of the pointed-to display object is unknown.
- HudTextRenderer: equal this+0x10 offsets in other classes (element array, candidate pointer) are NOT evidence of a shared field; per-base ownership is unproven.
- RaceStateHudDispatcher: field this+0x68 is listed in the packet but unreferenced by the raw body; the display-context object behind this[5]+84 used as the clipped-rect width source is unresolved; the a2 flag that suppresses the sub-dispatch is caller-specific.
- RaceStateHudDispatcher: the three jump tables at 0x0049D6AC, 0x0049D6C0 and 0x0049D6D4 back the dispatch switches; exact case layouts follow Hex-Rays and are not asserted here.
- RaceValueBarRenderer (0x0049E7B0): the a1-indexed per-corner value, the +18580 vehicle-field equality comparison, and the 1124-stride data region are unproven; the six read-only globals (flt_59E43C/59E440/59E450, dbl_59E7D8, flt_59E8CC, dbl_59EA60) are absent from the raw body.
- ParamRangeClampedLerp (0x0049F530): the a2 object type and the meaning of its field at +32 (clamp range width) are unknown; the 0.14503774 scale and the Celsius-style transform coefficients for modes 1/2 are literal-only inferences; jump-table globals 0x0049F670/0x0049F684 and helper constants 0x0059EAB0/0x0059EAB8/0x0059EAC0/0x005ACAFC/0x005ACB10 do not appear in the raw source text.
- DriverAppearanceFlag: the read-only global unk_7CE234 (0x007CE234) is flagged by packet facts for 0x0049D440, 0x0049D480 and 0x0049F530 but appears in no raw body; its role is unknown.
- TextPositioningHelper: sub_5531F0's in-place normalization semantics are not established; whether a2 is a left or right edge for the centered span is not determinable; both results are returned uninitialized when the guard fails.
- ControlProfileModeSwitcher: dword_7C54E8 (0x007C54E8) is listed as a read global but absent from the raw body; the exact mode set indexed by this+0x00 and the enable-mask semantics of byte_7CF7AC bits 1/2/4 are inferred from the scan loop, not independently confirmed.
- PitOperationTimerUpdater: the element type and the meaning of each element's +68 slot are established only by callee sub_4A2840; the object owning the this+0x10 array is unknown.
- PitstopStateMachineController: this+0x2C is evidenced only as zero versus non-zero, not as a boolean or mode; the pitstop phases advanced by PitstopStateTransition are owned by the callee; the a2 active/reset semantics are call-context derived.
- ValidPartCountResolver: the this+0xA8 value as a valid-part count comes from existing DERIVED analysis, not the raw source; the loop is unbounded if NthValidPartLookup never returns 0.
- AiStatePhaseFlagController: phase value 4 at this+0x184 and the flag at this+0x180 are DERIVED from existing analysis; ShortComputation_3fe0 has no callee evidence ref in this packet; the null-pointer path returns an undefined value.
- ClampedFloatParameter: the float reinterpretation of the integer argument is a decompiler artifact; the structural-twin relation between 0x004B1DE0 and 0x004B20D0 (differing return semantics) is DERIVED, not independently verified.
- StreamSerializationWriter: ConditionalDispatch_6bd0's output target and buffering semantics are outside the packet; the 4-byte header includes the string pointer at this+0x04 so the pointer is serialized both as header and as content; a2 is unconditionally overwritten by strlen.
- PooledBuffer: the owner is DERIVED only from the caller BufferPoolAllocatorInitialization; why the memset blocks begin at byte offsets 0x01 and 0x35 rather than the struct base is unresolved; the relationship between the 0x6C dword and the dword block at 0x70 is unknown.
- QuadrupleListCleanup (0x004B46F0): the packet fact table reports this-fields at +0xB0/+0xB4/+0xB8/+0xBC, but the decompiled pointer arithmetic (v2 = this + 44, then v2 -= 4 before zeroing v2[0..3]) places the four zeroed 16-byte slots in the +0x70..+0xAC range, so the +0xB0-0xBC group is never written by this function and remains unmatched; node layout semantics (+4 next, +8 type/active byte, base buffer pointer) and the four list roles are unproven.
- PerRowBitmapTable: the hash-table node layout (key low byte at node[0], next at +4) is derived from decompiler indexing, not a confirmed struct; the secondary flag written at +53 and the dual role of a3 as both bitmap bit index and node key byte are inferred; parameter a2 is never read by BitmapFlagSetClear.
- VehicleInstanceSummary: the meaning of the flag byte copied from a2+18580 into this[0] is unestablished; the source struct layout (fixed offsets 17952, 18196, 18580, 1920) is not defined here.
- FieldCompareListNode: the fallback handler in FloatComparisonListIteration (unk_500170) has no callee evidence ref in the packet; the float quantities at +12/+444 are directional window bounds only; the exact role of the cursor flag byte at +8 in the dispatch is unresolved.
- IdentityPassThrough (0x004B3DB0): no observable behavior; its role depends on how the four callers (ThreadSafeLinkedListLookupWithMutexDataCopy, SoundPlayDispatchWithStateChangeCheck, sub_57E0A0, sub_57EC10) use the returned this pointer.
- Unknown owners: 0x0049E7B0, 0x0049F530, 0x004B3DB0 and 0x004B46F0 lack a defensible owning type in this packet and are left unowned.
- Equal this-relative byte offsets across different classes (e.g. this+0x14 as display context vs sub-object pointer vs value slot; this+0x10 as display context vs element array vs candidate pointer) are NOT proof that the fields or classes are identical; per-base ownership is unproven.
