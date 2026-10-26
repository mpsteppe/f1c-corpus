# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

A heterogeneous set of runtime objects and packers. PitStallBufferPool (0x004B71E0 init, 0x004B6130 cleanup, 0x004B6190 worker assignment, 0x004B7860 drain-to-list, 0x004B6360 alignment comparator) owns a circular buffer of 176-byte pit-stall entries at +0x9B0 (count +0x9B4 chosen from enum +0x9A4, write/read indices +0x9B8/+0x9BC reset to -1), a file-stream node list at +0x6C0..+0x6D0, a working list at +0x30 and a doubly-linked result list at +0x714..+0x720. A family of float-to-packed-field encoders writes packed color (PackedColorChannelWriter 0x004B21F0), packed vertex shorts (PackedVertexShortWriter 0x004B2310), fixed-point scalars (FixedPointParameterEncoder 0x004B25D0/0x004B2750), indexed bytes/shorts (IndexedFixedPointEncoder 0x004B2840) and three bit ranges of the control dword at +0x2C plus a 10-bit field at +0x30 (PackedBitfieldControlWord 0x004B2930/0x004B29B0/0x004B2A40/0x004B2B10); the shared caller set (0x004B2DD0, 0x004B32A0, 0x004C71C0) suggests a vehicle orientation/lighting parameter object but ownership is UNKNOWN. DeterministicHashPRNG (0x004B3C60) is an LCG/RDTSC/GetTickCount mixing PRNG with accumulator at +0x804. ScaledStreamValueReader (0x004B4360) reads a header, then a raw or scaled float value plus a payload. SmallStructZeroInitializer (0x004B4450/0x004B4460) zeroes a 10-byte struct. GlobalDataInitializedObject (0x004B4F50/0x004B4F70) initializes a sub-object at +0x90 and writes sentinel 0xF49C952E to +0x84/+0x88/+0x8C. SteeringInterpolationObject (0x004B8790 getter, 0x004B87A0 queue peek, 0x004B9A00 mode flag, 0x004B9A10 progress ratio) reads queue fields +0xF30/+0xF34/+0xF38 and the +0xF81 mode flag / +0xF84 offset, feeding SteeringAckermannComputation; AnimationPhaseUpdater (0x004B8C40) dispatches phase updates through FloatGetter. RenderToggleDispatcher (0x004B97E0) forwards a render toggle into sub_4B7500. All packet owners are UnknownObject/UNKNOWN; class groupings here are DERIVED/GUESS synthesis.

## Function roles

- `0x004B21F0` **PackedColorChannelWriter** — Packed RGB color writer: clamps three float channels to [-65535.988, 65535.988] (flt_5ACC88/flt_5ACC8C), scales in-range channels by 32768.0 (flt_5ACC84), truncates to int, and packs a 40-bit color across word +0x0, word +0x4 and byte +0x8; returns the top byte of the third channel.
- `0x004B2310` **PackedVertexShortWriter** — Packed vertex short writer: copies three dwords from a2 into this+0x0/+0x4/+0x8, then converts three float inputs into signed 16-bit values at +0xC/+0xE/+0x10 with clamp to -32767/0x7FFF (flt_5ACC90/flt_5ACC94) and scale 2048.0 (flt_59E714); returns the final converted value.
- `0x004B25D0` **FixedPointParameterEncoder** — Float-to-fixed-point converter with clamp: a2[0] to byte +0x24 (scale 20.0 flt_59E8EC, clamp globals flt_5ACCA0/flt_5ACCA4), a2[1] to short +0x26 (scale 500.0 flt_59E91C, clamp globals flt_5ACCA8/flt_5ACCAC), a2[2] to byte +0x25 (returned); out-of-range clamps to signed sentinels.
- `0x004B2750` **FixedPointParameterEncoder** — Float-to-short clamped converter: converts a2[0] (scale 512.0 flt_5ACCB4, clamp flt_5ACCB8/flt_5ACCBC to 0x7FFF/-32767) into short +0x28 and a2[2] into short +0x2A (returned); the middle element a2[1] is not read.
- `0x004B2840` **IndexedFixedPointEncoder** — Indexed fixed-point encoder: clamps a3 to [-0.49599999, 0.49599999], scales by 256.0 and stores a byte at this[a2 + 18]; clamps a4 to [-327.67001, 327.67001], scales by 100.0 and stores a 16-bit value at this[2*a2 + 22]; returns that encoded short. Used by SetupCarLightingAndRender (0x004C71C0).
- `0x004B2930` **PackedBitfieldControlWord** — Bitfield packer (bits 17-31): multiplies the input float by 10.0 (flt_59E5FC), truncates, clamps to [0, 0x7FFF], shifts left 17 and merges into bits 17-31 of the dword at this+0x2C preserving the low 17 bits; returns the packed value.
- `0x004B29B0` **PackedBitfieldControlWord** — Bitfield insert (bits 12-16): multiplies the input float by 31.0 (flt_5ACCD0), truncates to unsigned 8-bit, shifts left 12 and XOR-merges a 5-bit value into bits 12-16 (mask 0x1F000) of the dword at this+0x2C preserving all other bits; returns the computed field value.
- `0x004B2A40` **PackedBitfieldControlWord** — Bitfield encoder (bits 0-6): multiplies the input float by 63.0 (flt_5ACCD8), truncates to unsigned 8-bit, subtracts the 64 bias and masks to 7 bits, then merges the biased signed value into bits 0-6 of the dword at this+0x2C clearing bits 0-6 and preserving bits 7-31; returns the new dword.
- `0x004B2B10` **PackedBitfieldControlWord** — 10-bit packer (bits 22-31): scales the input float by 3.0 (flt_59E478), truncates, shifts left 22 into bits 22-31 of the dword at this+0x30 while preserving the lower 22 bits (mask 0xFF3FFFFF); stores and returns the updated dword. Invoked by SetupCarLightingAndRender (0x004C71C0).
- `0x004B3C60` **DeterministicHashPRNG** — Deterministic entropy-mixing PRNG: updates the multiplicative accumulator at this+0x804 with the LCG step 219837*(this[513]+2), mixes in the RDTSC timestamp (0x0055687B), reads a float noise sample via the auto-incrementing byte counter at this+0x0, combines GetTickCount (0x0059E0D4) via CRTFtol (0x00587BDC), RandLCGRandomNumberGenerator (0x005884ED) and the accumulated timestamp; returns (2*v9+1)*v7+v11.
- `0x004B4360` **ScaledStreamValueReader** — Stream-value reader with conditional scaling: calls FileWriteWithBackendDispatch (0x00566C00) to populate a 4-byte header; based on header bits either stores the incoming float a2 raw or scales a single stream byte by dbl_5ACD28 (0.0001670000056037679) into v3+4; then reads a payload of (header >> 8) & 0x3FF bytes into v3+8 and returns 0.
- `0x004B4450` **SmallStructZeroInitializer** — Pass-through wrapper: invokes SmallStructZeroInit (0x004B4460) with no arguments for its side effect and returns the incoming this pointer unchanged; its four callers (allocation/audio helpers) call it for the zero-init effect.
- `0x004B4460` **SmallStructZeroInitializer** — Unconditional 10-byte struct zero-initializer: writes 0 to the dword at +0x0, the dword at +0x4 and the word at +0x8; always returns 0. Called by the wrapper and buffer-transfer helpers.
- `0x004B4F50` **GlobalDataInitializedObject** — Construction wrapper: initializes the sub-object at this+144 via PassthroughWrapper_f670 (0x004FF670), then calls StructInitWithGlobalData (0x004B4F70) on this and returns this.
- `0x004B4F70` **GlobalDataInitializedObject** — Struct init from global data: delegates sub-struct initialization at this+0x90 to ThunkWithStructInitSubCalls (0x004FFFA0), zeroes four byte fields (+0x0, +0x1, +0x41, +0x61), then writes the sentinel dword -190986834 (0xF49C952E, flt_5ACD10) into +0x84, +0x88 and +0x8C; returns the sentinel.
- `0x004B6130` **PitStallBufferPool** — Overlay/sprite array cleanup: frees the heap array of 176-byte entries stored at this + 0x9B0, reading the count from the header dword at (array - 4), walking backward calling QuadrupleListCleanup (0x004B46F0) per entry, freeing the header block via FreeWrapper_7bcf (0x00587BCF), then zeroing +0x9B0 and +0x9B4; returns the freed pointer value (zero on the normal path).
- `0x004B6190` **PitStallBufferPool** — Pit crew worker allocation for driver a2: skips when the vehicle slot dword_5EF9A0[4656*a2] is inactive (-1); per worker slot (4 iterations) scans the pit-stall circular buffer (176-byte entries at +0x9B0) via CircularBufferCheck/HashTableLookup collecting up to 12 matches, marks with BitfieldSetter_4800, sorts with MultiStageAlignmentComparator (0x004B6360), and assigns via sub_4B4A30 when at least 9 match; returns i + 1.
- `0x004B6360` **PitStallBufferPool** — Multi-stage alignment comparator: validates the header words of *a2 (top-bit tag and reserved bit mask), optionally compares 14 flag bits of a2[2] against a4[2] via BitTest (0x004B2AD0) when the difficulty selector at this+0x9AC is 3 or 4, populates comparison intermediates (0x004B3A90, 0x004B2420), then runs stage 0 (per-component scalar differences through LapSpeedComparisonWithSwitchSelectableThresholds 0x004B66E0) and stage 1 (wrapped per-axis angle differences through SteeringAlignmentToleranceCheck 0x004B67D0); returns 1 when all pass, else 0.
- `0x004B71E0` **PitStallBufferPool** — Buffer-pool reinitialization: transfers the linked buffer (0x004B5F60), runs the companion setup (0x004B5E50), tears down and clears the file-stream node list at +0x6C0..+0x6D0, rebuilds the list at +0xF38/+0xF3C (0x004B52A0), resets write/read indices +0x9B8/+0x9BC to -1, sets the counter at +0xF8C to 5, runs overlay-list cleanup, selects the entry count from the enum at +0x9A4 (0=16, 1=24, 2=32, 3=48, 4=96) into +0x9B4, allocates the 176-byte-entry circular buffer (176*count+4) at +0x9B0 and zero-initializes each 44-byte sub-entry.
- `0x004B7860` **PitStallBufferPool** — Circular-buffer drain to doubly-linked result list: entry guard on the buffer count (+0x9B4), loops the working list at +0x30 feeding the 176-byte slot selected at +0x9B0 by the read index +0x9BC into CollisionObjectListManagement (0x004B4B50), accumulates +0xF24/+0xF28, appends 16-byte result nodes to the list at +0x714..+0x720, synthesizes nodes via the working list when empty, then advances the read index via RingBufferCounterWithWrap (0x004B69D0) and returns 1 (or 0 when the buffer was not ready).
- `0x004B8790` **SteeringInterpolationObject** — Float getter: reads element index 974 (byte offset 0xF38) of the float array referenced by this and returns it as double; no side effects, no branches. Shared field accessor called by eight helpers (StateTriggerCheck, Delegation, FloatAccumulator, ConditionalMultiPathDispatcher and neighbors).
- `0x004B87A0` **SteeringInterpolationObject** — Non-destructive queue peek: copies this[972] (+0xF30) into *a2 and this[973] (+0xF34) into *a3, returns constant 1; never writes the source. Five helpers (0x004B70B0, 0x004B9A10, 0x004B9C80, 0x004B9E40, 0x004BA1F0) read the two queued values.
- `0x004B8C40` **AnimationPhaseUpdater** — Animation/simulation phase update dispatcher: switches on the mode value a2 through jump table global:0x004B8D8C, each mode fetches the base float via FloatGetter (0x004B8790), adds/subtracts the cooling-rate global dbl_8AFE90 with per-mode scalars (1.0, 0.083333336, 3.3399999) or applies a floor clamp, runs AngleClampWrap (0x004B86E0), writes phase identifiers 4-7 and scale factors; modes 0/2/3/4 fall through to ShortComputation_8d70 (0x004C8D70) and GuardedVirtualCall (0x004C8DC0), mode 1 returns ArithmeticComparison_8d60 (0x004C8D60) early.
- `0x004B97E0` **RenderToggleDispatcher** — Render toggle refresh wrapper: forwards the object's first dword and the boolean (dword_7D0038 != 0) into sub_4B7500 and returns the callee's result directly.
- `0x004B9A00` **SteeringInterpolationObject** — Angle clamp mode flag reader: dereferences the pointer at this+0 to reach the object, reads the byte at object offset 0xF81 (3969) and returns it; zero = wrap, non-zero = hard clamp (interpretation from existing analysis, not confirmed by this function).
- `0x004B9A10` **SteeringInterpolationObject** — Normalised progress ratio compute: dereferences this to the object, reads the range lower/upper bounds via QueuePeek (0x004B87A0), branches on the mode flag at obj+0xF81: clamp mode uses dbl_8AFEA0 minus obj+0xF84, wrap mode uses the range width; calls Delegation (0x004B9CE0) and returns (value - v8) / v9, or 0.0 when the range is <= 0. Feeds SteeringAckermannComputation (0x004DB170).

## Proposed classes

### PitStallBufferPool

Owns the pit-stall circular buffer of 176-byte entries: initializes it from an entry-count enum and a file-stream node list (0x004B71E0), cleans it up entry-by-entry (0x004B6130), allocates pit crew workers over its entries (0x004B6190), sorts/compares entries through the multi-stage alignment comparator (0x004B6360), and drains a slot into a doubly-linked result list (0x004B7860).

Methods: `0x004B71E0`, `0x004B6130`, `0x004B6190`, `0x004B6360`, `0x004B7860`

- `this+0x00000030` `void* working_list_head` (read_write, DERIVED)
- `this+0x00000034` `void* working_list_next` (read_write, GUESS)
- `this+0x00000038` `void* working_list_current` (read_write, GUESS)
- `this+0x0000003C` `int working_list_count` (read_write, GUESS)
- `this+0x00000040` `void* secondary_list_head` (unknown, UNKNOWN)
- `this+0x000006C0` `void* filestream_list_head` (read_write, DERIVED)
- `this+0x000006C4` `void* filestream_list_tail` (read_write, GUESS)
- `this+0x000006C8` `void* filestream_list_node` (read_write, GUESS)
- `this+0x000006CC` `void* filestream_list_cursor` (read_write, GUESS)
- `this+0x000006D0` `byte filestream_list_flag` (read_write, GUESS)
- `this+0x00000714` `void* result_list_head` (read_write, DERIVED)
- `this+0x00000718` `void* result_list_tail` (read_write, DERIVED)
- `this+0x0000071C` `void* result_list_head_lo` (read_write, GUESS)
- `this+0x00000720` `int result_list_count` (read_write, DERIVED)
- `this+0x000009A4` `int buffer_entry_count_selector` (read, DERIVED)
- `this+0x000009AC` `int difficulty_selector` (read, DERIVED)
- `this+0x000009B0` `void* buffer_array` (read_write, DERIVED)
- `this+0x000009B4` `int buffer_entry_count` (read_write, DERIVED)
- `this+0x000009B8` `int buffer_write_index` (read_write, DERIVED)
- `this+0x000009BC` `int buffer_read_index` (read_write, DERIVED)
- `this+0x00000F24` `int processed_total` (read_write, GUESS)
- `this+0x00000F28` `int processed_count` (read_write, GUESS)
- `this+0x00000F38` `void* rebuilt_list_head` (read_write, DERIVED)
- `this+0x00000F3C` `void* rebuilt_list_tail` (read_write, DERIVED)
- `this+0x00000F8C` `int counter_or_phase` (read_write, GUESS)

### PackedBitfieldControlWord

Writes the packed bitfield dwords of a per-vehicle render/orientation parameter object: bits 17-31 (15-bit, 0x004B2930), bits 12-16 (5-bit, 0x004B29B0), bits 0-6 (7-bit biased, 0x004B2A40) of the dword at +0x2C, and bits 22-31 (10-bit, 0x004B2B10) of the dword at +0x30.

Methods: `0x004B2930`, `0x004B29B0`, `0x004B2A40`, `0x004B2B10`

- `this+0x0000002C` `dword packed_control_word` (read_write, DERIVED)
- `this+0x00000030` `dword packed_control_word_2` (read_write, DERIVED)

### FixedPointParameterEncoder

Converts float triples/pairs into clamped fixed-point scalar fields of a parameter object (byte +0x24/+0x25, short +0x26/+0x28/+0x2A); called by VehicleOrientationFromEulerAngles, sub_4B32A0 and SetupCarLightingAndRender.

Methods: `0x004B25D0`, `0x004B2750`

- `this+0x00000024` `byte byte_param_a` (read_write, DERIVED)
- `this+0x00000025` `byte byte_param_b` (read_write, DERIVED)
- `this+0x00000026` `short short_param_a` (read_write, DERIVED)
- `this+0x00000028` `short short_param_b` (read_write, DERIVED)
- `this+0x0000002A` `short short_param_c` (read_write, DERIVED)

### PackedColorChannelWriter

Packs three float color channels into a 40-bit RGB representation spread across word +0x0, word +0x4 and byte +0x8, with clamp to [-65535.988, 65535.988] and scale 32768.0.

Methods: `0x004B21F0`

- `this+0x00000000` `word packed_word_0` (read_write, DERIVED)
- `this+0x00000004` `word packed_word_1` (read_write, DERIVED)
- `this+0x00000008` `byte packed_byte_2` (read_write, DERIVED)

### PackedVertexShortWriter

Copies three dwords verbatim into +0x0/+0x4/+0x8 then converts three floats into clamped signed 16-bit values at +0xC/+0xE/+0x10 (scale 2048.0); candidate packed vertex/vector writer.

Methods: `0x004B2310`

- `this+0x00000000` `dword copied_dword_0` (write, DERIVED)
- `this+0x00000004` `dword copied_dword_1` (write, DERIVED)
- `this+0x00000008` `dword copied_dword_2` (write, DERIVED)
- `this+0x0000000C` `short short_0` (read_write, DERIVED)
- `this+0x0000000E` `short short_1` (read_write, DERIVED)
- `this+0x00000010` `short short_2` (read_write, DERIVED)

### IndexedFixedPointEncoder

Encodes a clamped/scaled byte and short into an index-offset buffer (byte at this[a2+18], short at this[2*a2+22]) for indexed parameter packing by SetupCarLightingAndRender.

Methods: `0x004B2840`


### DeterministicHashPRNG

Entropy-mixing pseudo-random DWORD generator: LCG step over the accumulator at +0x804 mixed with RDTSC, a float noise table sample indexed by the byte counter at +0x0, GetTickCount and an internal LCG call.

Methods: `0x004B3C60`

- `this+0x00000000` `byte sample_byte_counter` (read_write, DERIVED)
- `this+0x00000804` `dword accumulator` (read_write, DERIVED)

### ScaledStreamValueReader

Reads a header then either a raw float or a byte scaled by dbl_5ACD28 plus a payload block from a backend stream (0x00566C00), writing header/value/payload into a caller buffer.

Methods: `0x004B4360`


### SmallStructZeroInitializer

Zeroes a 10-byte struct (dword +0x0, dword +0x4, word +0x8); 0x004B4460 is the zero-initializer proper, 0x004B4450 a pass-through wrapper invoking it for its side effect on behalf of allocation/audio callers.

Methods: `0x004B4460`, `0x004B4450`

- `this+0x00000000` `dword dword_field_0` (write, DERIVED)
- `this+0x00000004` `dword dword_field_1` (write, DERIVED)
- `this+0x00000008` `word word_field` (write, DERIVED)

### GlobalDataInitializedObject

Initializes an object from global data: construction wrapper 0x004B4F50 initializes the sub-object at +0x90 (via 0x004FF670) then runs 0x004B4F70, which initializes the sub-struct at +0x90 (via 0x004FFFA0), zeroes byte fields +0x0/+0x1/+0x41/+0x61 and writes sentinel 0xF49C952E (flt_5ACD10) to +0x84/+0x88/+0x8C.

Methods: `0x004B4F50`, `0x004B4F70`

- `this+0x00000000` `byte enable_flag` (read_write, DERIVED)
- `this+0x00000001` `byte flag_byte_1` (write, DERIVED)
- `this+0x00000041` `byte flag_byte_2` (write, DERIVED)
- `this+0x00000061` `byte flag_byte_3` (write, DERIVED)
- `this+0x00000084` `dword sentinel_dword` (write, DERIVED)
- `this+0x00000088` `dword sentinel_dword_2` (write, DERIVED)
- `this+0x0000008C` `dword sentinel_dword_3` (write, DERIVED)

### SteeringInterpolationObject

Steering/animation interpolation state: exposes the float at +0xF38 (0x004B8790), two queued range values at +0xF30/+0xF34 (0x004B87A0), the angle clamp mode flag at obj+0xF81 (0x004B9A00) and the normalised progress ratio over that range (0x004B9A10, feeding SteeringAckermannComputation).

Methods: `0x004B8790`, `0x004B87A0`, `0x004B9A00`, `0x004B9A10`

- `this+0x00000F30` `float queue_value_lower` (read, DERIVED)
- `this+0x00000F34` `float queue_value_upper` (read, DERIVED)
- `this+0x00000F38` `float float_field` (read, DERIVED)
- `obj+0x00000F81` `byte mode_flag_byte` (read, DERIVED)
- `obj+0x00000F84` `float offset_float` (read, DERIVED)

### AnimationPhaseUpdater

Dispatches an animation/simulation phase update by a mode value: adjusts the base float read via FloatGetter by the cooling-rate global dbl_8AFE90 with per-mode scalars, clamps the angle, and writes phase identifiers and scale factors; mode 1 returns early via ArithmeticComparison_8d60.

Methods: `0x004B8C40`


### RenderToggleDispatcher

Thin wrapper forwarding the object's first dword and the dword_7D0038 boolean into sub_4B7500 as a render toggle / scene refresh operation.

Methods: `0x004B97E0`

- `this+0x00000000` `dword first_dword` (read, DERIVED)

## Compatibility contracts

- **PackedColorFormatContract** — The 40-bit packed color output must preserve the channel encoding of 0x004B21F0: each of three float channels clamped to [-65535.988, 65535.988] (flt_5ACC88/flt_5ACC8C) with INT_MIN/INT_MAX saturation, scaled by 32768.0 (flt_5ACC84), then bit-packed as word +0x0, word +0x4 and byte +0x8; the top byte of the third channel is the function result.
- **PitStallBufferLayoutContract** — The pit-stall buffer pool must keep its circular buffer of 176-byte entries at +0x9B0 with the entry count at +0x9B4 selected from the enum at +0x9A4 (0=16, 1=24, 2=32, 3=48, 4=96), write/read indices at +0x9B8/+0x9BC reset to -1 on init, allocation size 176*count+4 with the count header at (array-4), and cleanup walking the entries backward via QuadrupleListCleanup before freeing the header block.
- **BitfieldControlWordContract** — The packed control dword at +0x2C must preserve three independently written bit ranges: bits 0-6 hold a 64-biased 7-bit value (0x004B2A40), bits 12-16 a 5-bit value (0x004B29B0), bits 17-31 a 15-bit value (0x004B2930); the dword at +0x30 carries a 10-bit field at bits 22-31 with mask 0xFF3FFFFF (0x004B2B10). Writers preserve the bits they do not own.
- **InitSentinelContract** — Object initialization must zero the byte fields at +0x0/+0x1/+0x41/+0x61, initialize the sub-object at +0x90 (via 0x004FF670 and ThunkWithStructInitSubCalls 0x004FFFA0), and write the sentinel 0xF49C952E (flt_5ACD10) into the three consecutive dwords at +0x84/+0x88/+0x8C.
- **SmallStructZeroContract** — The 10-byte struct cleared by SmallStructZeroInitializer must have its dwords at +0x0 and +0x4 and its word at +0x8 zeroed; 0x004B4460 is the unconditional initializer, 0x004B4450 the pass-through wrapper invoking it.
- **StreamValueHeaderContract** — The stream-value reader (0x004B4360) must preserve the header/value/payload buffer contract: a 4-byte header read from the backend at v3, a float value at v3+4 (either a2 raw or a stream byte scaled by dbl_5ACD28 = 0.0001670000056037679 plus a2), and a payload of (header >> 8) & 0x3FF bytes read into v3+8.

## Unresolved

- All packet owners are UnknownObject/UNKNOWN; every class grouping (PitStallBufferPool, PackedBitfieldControlWord, FixedPointParameterEncoder, SteeringInterpolationObject, etc.) is worker synthesis at DERIVED/GUESS, not packet evidence. Equal byte offsets on distinct this bases are NOT merged into one class unless the shared layout is argued.
- PitStallBufferPool is formed by merging 0x004B71E0, 0x004B6130, 0x004B6190, 0x004B6360 and 0x004B7860 on the shared circular-buffer fields (+0x9B0/+0x9B4/+0x9B8/+0x9BC/+0x9A4) and the direct call chain 0x004B71E0->SpriteOverlayListCleanup and 0x004B6190->0x004B6360; this union is defensible but the class name and the pit-stall meaning of the 176-byte stride are inferred, not proven.
- Offset overlaps on distinct this objects remain unmerged: +0xF38 is read as a float by FloatGetter (0x004B8790) yet cleared as a rebuilt-list head by BufferPoolAllocatorInitialization (0x004B71E0); +0xF8C is set to 5 by 0x004B71E0 while AnimationPhaseUpdater (0x004B8C40) writes phase identifiers at object+3980 (decimal 0xF8C) via uninitialized register bases. Common ownership is unproven, so SteeringInterpolationObject, PitStallBufferPool and AnimationPhaseUpdater stay separate.
- PackedColorChannelWriter (+0x0/+0x4/+0x8) and PackedVertexShortWriter (+0x0/+0x4/+0x8) share equal offsets on the same this base; two classes are retained because 0x004B21F0 writes +0x8 as a byte while 0x004B2310 copies a dword there, so a common layout is not proven.
- The bitfield packers 0x004B2930/0x004B29B0/0x004B2A40 share the +0x2C dword and are grouped; whether they share the object with 0x004B2B10 (+0x30), the fixed-point writers (+0x24..+0x2A), the color writer or the vertex writer is unknown - all are UNKNOWN-owner singletons or small groups in one parameter-object hypothesis.
- In 0x004B71E0 the named calls SpriteOverlayListCleanup, OperatorNewNhMallocWrapper and StructZeroInit_46b0 have no callee records; the SpriteOverlayListCleanup call is mapped to 0x004B6130 only through the caller:0x004B71E0/function:0x004B6130 pair, not a direct callee ref.
- The pit stall entry layout (176 bytes) and the worker-slot meaning of the 4-iteration loop in 0x004B6190 are inferred from caller names; the collection-size thresholds 9 and 12 and the sort comparator semantics of 0x004B6360 are not evidenced in this packet.
- In 0x004B6360 the jump table jpt_4B6380 and the double dbl_59E890 are recorded as read but appear nowhere in the raw body; the a2/a4 header-word semantics, the 14-bit flag comparison, the misattributed AudioSamplePlaybackWithPitchModulationAndStereoP call, and the dword-indexed sub-object offsets +734/+736/+626/+628 (0xB78/0xB80/0x9C8/0x9D0) are unresolved.
- In 0x004B3C60: flt_5ACCF4 is a listed read global absent from the raw text; RandLCGRandomNumberGenerator is called with an uninitialized v8 seed; the constants 219837 and -3499.01 are unexplained; and the float noise table read lands at an offset inside this computed from the counter, not a packet field.
- In 0x004B4360 the callee is named FileWriteWithBackendDispatch yet reads stream data here; the bitmask selection (0xE0000000 vs 0x20000000, 0xFC0000) between raw-float and scaled-byte storage is only structurally inferred; the header/value/payload buffer meaning, the unused a1 parameter and the 0x3FF (max 1023) payload size are unknown.
- In 0x004B8C40 the +3976/+3980 writes use uninitialized register-sourced base pointers, so the target object and field offsets are not established; phase identifiers 4-7 and scale factors 1065353216/1056964608/1070973583 are numeric literals whose semantics are inferred; the role of byte_8AC494 and the ArithmeticComparison_8d60 vs ShortComputation_8d70 distinction are undocumented; flt_5ACB58 and flt_5ACD64 are flagged reads absent from the raw body.
- 0x004B8790 returns double while the read is an element of a float array at +0xF38: whether +0xF38 holds a true double member or two adjacent floats re-read as 8 bytes is unresolved.
- 0x004B87A0 returns the constant 1 rather than a value derived from the source; the meaning of the two queued values (+0xF30/+0xF34) is unknown.
- 0x004B9A00 reaches the flag byte at obj+0xF81 through a double dereference; the flag semantics (wrap vs hard clamp) rest on existing-analysis prose and are not proven by the accessor itself.
- The global clamp/scale constants for 0x004B2840 (flt_59E6F8, flt_59F10C, flt_5ACCC0, flt_5ACCC4, flt_5ACCC8, flt_5ACCCC) and the read-only globals flt_5ACB58/flt_5ACD64 (0x004B8C40), flt_5ACD38 (0x004B6190), flt_5ACCF4 (0x004B3C60), flt_59E440 (0x004B9A10) are flagged by packet facts but do not appear in the raw decompiled sources; their bindings are unverifiable from this packet.
