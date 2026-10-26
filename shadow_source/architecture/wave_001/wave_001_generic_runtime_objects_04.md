# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

38 functions reconstructed as a small collection of short-lived runtime objects. (1) UIControlWindowInitialization (0x004A70E0) builds a UI sub-control tree via a family of 3- and 5-dword thiscall constructors, each storing a distinct vtable/interface global at +0x0 and seeding 0/-1 value pairs; a zero-initializer clears a 21-dword UI block. (2) PlayerOptionsInitializer (0x004AA270) configures a player-options struct through setters that copy label strings via StringCopyWithBufferRealloc, write option fields at +0x14..+0x20 (int/byte/short variants over overlapping offsets), flag-gate extra writes, and always end by delegating to ShortComputation_1b70. (3) VehiclePhysicsTimeStep (0x004C73F0) per frame decodes packed physics fields at +0x24..+0x26 and bit-packed dwords at +0x2C/+0x30 through trivial getters with fixed scale constants. (4) A session lap-data struct is constructed (sentinels + zero block) and its per-lap float/byte arrays allocated and sentinel-filled. (5) Standalone helpers: game-mode-to-path-prefix formatter, candidate-path file finder, and a validated resource-string copier. Class identity of every object is UNKNOWN; all groupings are DERIVED or GUESS.

## Function roles

- `0x004A7010` **PlayerOptionsStruct** — PlayerOptionsStruct initializer: stores paired option values a3/a4 at mirrored offsets +0xC/+0x14 and +0x10/+0x18, copies label string a2 via StringCopyWithBufferRealloc, delegates to ShortComputation_1b70.
- `0x004A8AF0` **UiMultiRangeControl** — UiMultiRangeControl constructor: stores vtable/interface global off_5ACBF0 at +0x0 and seeds three alternating 0/-1 pairs at +0x4..+0x18.
- `0x004A8B10` **UiStateSentinelControl** — UiStateSentinelControl constructor: stores vtable/interface global off_5ACC08 at +0x0, state field +0x4 = 0, handle/index +0x8 = -1.
- `0x004A8B30` **UiStateSentinelControl** — UiStateSentinelControl constructor: stores vtable/interface global off_5ACBFC at +0x0, state field +0x4 = 0, handle/index +0x8 = -1.
- `0x004AA1E0` **unknown** — Game-mode index (0-6) to path-prefix formatter: jump-table dispatch selects one of seven prefix globals and formats '%s%s' via StringFormatWithBufferOverflowCheck; returns 1 on recognized mode, else empty buffer and 0.
- `0x004B0170` **unknown** — Empty no-op stub (nullsub) shared placeholder; no reads, writes, calls or guards.
- `0x004B1950` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACBE4 at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B1970` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACBD8 at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B1990` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACBCC at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B19B0` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACC20 at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B19D0` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACC2C at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B19F0` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACC38 at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B1A10` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACC44 at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B1A30` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACC50 at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B1A50` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACC5C at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B1A70` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACC68 at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B1A90` **UiRangePairControl** — UiRangePairControl constructor: stores vtable/interface global off_5ACC74 at +0x0, seeds two 0/-1 range pairs at +0x4..+0x10.
- `0x004B1AB0` **PlayerOptionsStruct** — PlayerOptionsStruct identity pass-through: returns `this` unchanged; likely a vtable-slot placeholder or adapter stub.
- `0x004B1AC0` **PlayerOptionsStruct** — PlayerOptionsStruct multi-field setter (int widths): copies string a2, stores a3/a4/a5 at +0x18/+0x1C/+0x20, flag-gated copy of a6 and flag-gated write of +0x14, then delegates to ShortComputation_1b70.
- `0x004B1C20` **PlayerOptionsStruct** — PlayerOptionsStruct multi-field setter (byte widths): copies string a2, stores bytes at +0x15/+0x16/+0x17, flag-gated copy of a6 and flag-gated byte write of +0x14, then delegates to ShortComputation_1b70.
- `0x004B1D90` **PlayerOptionsStruct** — PlayerOptionsStruct multi-field setter: structural twin of 0x004B1AC0 with same field set and different write order, then delegates to ShortComputation_1b70.
- `0x004B1F50` **PlayerOptionsStruct** — PlayerOptionsStruct multi-field setter (short widths): copies string a2, stores shorts at +0x16/+0x18/+0x1A, flag-gated copy of a6 and flag-gated short write of +0x14, then delegates to ShortComputation_1b70.
- `0x004B26D0` **PackedPhysicsFieldCarrier** — Packed scalar decoder on PackedPhysicsFieldCarrier: unpacks byte +0x24 (x0.05), int16 +0x26 (x0.002), byte +0x25 (x0.05) into float outputs through CRTFtol truncation; returns the third truncated int.
- `0x004B28F0` **IndexedPackedFieldContainer** — Indexed packed-field decoder: scales byte at entry index a2+18 by 0.00390625 into *a3 and int16 at 2*a2+22 by 0.0099999998 into *a4; returns raw int16.
- `0x004B2980` **PackedPhysicsFieldCarrier** — Bitfield decoder on PackedPhysicsFieldCarrier: extracts bits 17-31 of the dword at +0x2C, scales by 0.1, returns double.
- `0x004B29F0` **PackedPhysicsFieldCarrier** — Bitfield decoder on PackedPhysicsFieldCarrier: extracts 5-bit field (bits 12-16) of +0x2C, scales by 0.032258064 (1/31), returns double.
- `0x004B2A30` **PackedPhysicsFieldCarrier** — Bitfield getter on PackedPhysicsFieldCarrier: extracts 4-bit nibble (bits 8-11) of +0x2C and returns it minus 1.
- `0x004B2A80` **PackedPhysicsFieldCarrier** — Bitfield decoder on PackedPhysicsFieldCarrier: extracts low 7 bits of +0x2C, subtracts bias 64, scales by 0.015873017 (1/63), returns double.
- `0x004B2AD0` **PackedPhysicsFieldCarrier** — Bit test getter on PackedPhysicsFieldCarrier: reads dword at +0x30, returns (value >> a2) & 1.
- `0x004B2B00` **PackedPhysicsFieldCarrier** — Bitfield getter on PackedPhysicsFieldCarrier: returns bits 28-30 of the dword at +0x30.
- `0x004B2B40` **PackedPhysicsFieldCarrier** — Bitfield decoder on PackedPhysicsFieldCarrier: extracts 2-bit field (bits 22-23) of +0x30, scales by 0.33333334 (1/3), returns double.
- `0x004B2B80` **PackedPhysicsFieldCarrier** — Bitfield getter on PackedPhysicsFieldCarrier: returns bits 15-21 of the dword at +0x30.
- `0x004B3CE0` **NoiseValueGenerator** — Gaussian-approximation noise generator: popcount of a hash-based PRNG result as a binomial term combined with a noise-table float, centered and scaled.
- `0x004BB7A0` **SessionLapData** — SessionLapData constructor/initializer: zeroes an 8-dword block at +0x40 and fields +0x0/+0x30/+0x8C/+0x90/+0x94/+0xA4, sets sentinels -1 at +0x4/+0x24/+0x2C and float -1.0 at +0x28, then delegates to StructResetReinitializer.
- `0x004BB810` **SessionLapData** — SessionLapData per-lap array allocator: resets via StructResetReinitializer, sets mode flags +0xC/+0x60 from session type dword_7C56A4, caps lap count from dword_8ACF8C at 128 into +0x88, allocates two float arrays (+0x8C/+0x90) and one byte array (+0x94) via OperatorNewNhMallocWrapper, records count +0x98, fills all with float -1.0 sentinels / 0.
- `0x004C16B0` **UiWindowBlock** — UiWindowBlock zero-initializer: zeroes 21 consecutive dwords (+0x0..+0x50) of the receiver and returns it.
- `0x004C40D0` **unknown** — Candidate-path file finder for season/race data files: appends extension when needed, probes custom/season/common directories, closes and copies the first openable path (return 0), otherwise guarded debug log and return -1.
- `0x004C58A0` **unknown** — Validated resource-string copier: checks SeasonRacesSectionFinder and StringKeyedLinkedListSearch, fetches entry via DataEntryAccessor, copies into caller buffer with capacity a2-1 via sub_587DD0, null-terminates; returns 0 on success, 1 on section/key failure.

## Proposed classes

### PlayerOptionsStruct

Player-options configuration object configured by PlayerOptionsInitializer (0x004AA270): stores paired option values, label strings copied via StringCopyWithBufferRealloc, and flag-gated sub-fields; every mutating path ends by delegating to the shared finalizer ShortComputation_1b70. Widths of the +0x14..+0x20 fields differ across the setter variants (int/byte/short), implying overlapping or union-interpreted storage; identity and true layout are unconfirmed.

Methods: `0x004A7010`, `0x004B1AB0`, `0x004B1AC0`, `0x004B1C20`, `0x004B1D90`, `0x004B1F50`

- `this+0x0000000C` `int32 option_value_a` (write, DERIVED)
- `this+0x00000010` `int32 option_value_b` (write, DERIVED)
- `this+0x00000014` `union_int8_int16_int32 flag_gated_field_14` (write, GUESS)
- `this+0x00000015` `uint8 byte_field_15` (write, DERIVED)
- `this+0x00000016` `uint8_or_int16_low_byte byte_short_field_16` (write, GUESS)
- `this+0x00000017` `uint8 byte_field_17` (write, DERIVED)
- `this+0x00000018` `int32_or_int16 option_b_duplicate_field_18` (write, GUESS)
- `this+0x0000001A` `int16 short_field_1A` (write, DERIVED)
- `this+0x0000001C` `int32 int_field_1C` (write, DERIVED)
- `this+0x00000020` `int32 int_field_20` (write, DERIVED)

### UiRangePairControl

Generic 5-dword UI sub-control block constructed by UIControlWindowInitialization (0x004A70E0): vtable/interface slot at +0x0 followed by two (min=0, max=-1) range-bound pairs at +0x4/+0x8 and +0xC/+0x10. Each of the eleven instances stores a distinct vtable global (0x005ACBCC..0x005ACC74), so the concrete UI widget types are likely distinct but are unidentifiable from this packet; the class is a defensible grouping of structurally identical constructors, not a proven common type.

Methods: `0x004B1950`, `0x004B1970`, `0x004B1990`, `0x004B19B0`, `0x004B19D0`, `0x004B19F0`, `0x004B1A10`, `0x004B1A30`, `0x004B1A50`, `0x004B1A70`, `0x004B1A90`

- `this+0x00000000` `void_ptr vtable_interface_slot` (write, GUESS)
- `this+0x00000004` `int32 range_pair_1_min` (write, DERIVED)
- `this+0x00000008` `int32 range_pair_1_max` (write, DERIVED)
- `this+0x0000000C` `int32 range_pair_2_min` (write, DERIVED)
- `this+0x00000010` `int32 range_pair_2_max` (write, DERIVED)

### UiStateSentinelControl

Small 3-dword UI sub-control block constructed by UIControlWindowInitialization (0x004A70E0): vtable/interface slot at +0x0, a state/counter field seeded 0 at +0x4, and a handle/index seeded -1 (invalid) at +0x8. Two instances with distinct vtable globals (0x005ACBFC, 0x005ACC08); concrete type identity unknown.

Methods: `0x004A8B10`, `0x004A8B30`

- `this+0x00000000` `void_ptr vtable_interface_slot` (write, GUESS)
- `this+0x00000004` `int32 state_counter` (write, DERIVED)
- `this+0x00000008` `int32 handle_index` (write, DERIVED)

### UiMultiRangeControl

7-dword UI sub-control block constructed by UIControlWindowInitialization (0x004A70E0): vtable/interface slot at +0x0 followed by three 0/-1 pairs at +0x4..+0x18. Single instance storing global off_5ACBF0; whether this is a third-range variant of UiRangePairControl or a distinct type is unknown.

Methods: `0x004A8AF0`

- `this+0x00000000` `void_ptr vtable_interface_slot` (write, GUESS)
- `this+0x00000004` `int32 pair_1_min` (write, DERIVED)
- `this+0x00000008` `int32 pair_1_max` (write, DERIVED)
- `this+0x0000000C` `int32 pair_2_min` (write, DERIVED)
- `this+0x00000010` `int32 pair_2_max` (write, DERIVED)
- `this+0x00000014` `int32 pair_3_min` (write, DERIVED)
- `this+0x00000018` `int32 pair_3_max` (write, DERIVED)

### UiWindowBlock

21-dword UI memory block cleared by a straight-line zero-initializer invoked from UIControlWindowInitialization (0x004A70E0). No vtable slot is written, so this may be the enclosing UI window object or a data-only sub-block; the semantics of each zeroed dword are unknown.

Methods: `0x004C16B0`

- `this+0x00000000` `int32 zeroed_dword_00` (write, UNKNOWN)
- `this+0x00000004` `int32 zeroed_dword_04` (write, UNKNOWN)
- `this+0x00000008` `int32 zeroed_dword_08` (write, UNKNOWN)
- `this+0x0000000C` `int32 zeroed_dword_0C` (write, UNKNOWN)
- `this+0x00000010` `int32 zeroed_dword_10` (write, UNKNOWN)
- `this+0x00000014` `int32 zeroed_dword_14` (write, UNKNOWN)
- `this+0x00000018` `int32 zeroed_dword_18` (write, UNKNOWN)
- `this+0x0000001C` `int32 zeroed_dword_1C` (write, UNKNOWN)
- `this+0x00000020` `int32 zeroed_dword_20` (write, UNKNOWN)
- `this+0x00000024` `int32 zeroed_dword_24` (write, UNKNOWN)
- `this+0x00000028` `int32 zeroed_dword_28` (write, UNKNOWN)
- `this+0x0000002C` `int32 zeroed_dword_2C` (write, UNKNOWN)
- `this+0x00000030` `int32 zeroed_dword_30` (write, UNKNOWN)
- `this+0x00000034` `int32 zeroed_dword_34` (write, UNKNOWN)
- `this+0x00000038` `int32 zeroed_dword_38` (write, UNKNOWN)
- `this+0x0000003C` `int32 zeroed_dword_3C` (write, UNKNOWN)
- `this+0x00000040` `int32 zeroed_dword_40` (write, UNKNOWN)
- `this+0x00000044` `int32 zeroed_dword_44` (write, UNKNOWN)
- `this+0x00000048` `int32 zeroed_dword_48` (write, UNKNOWN)
- `this+0x0000004C` `int32 zeroed_dword_4C` (write, UNKNOWN)
- `this+0x00000050` `int32 zeroed_dword_50` (write, UNKNOWN)

### PackedPhysicsFieldCarrier

Vehicle-physics packed-field carrier read per frame by VehiclePhysicsTimeStep (0x004C73F0) and related paths: three compact scalar fields at +0x24..+0x26 decoded with fixed scales, and two bit-packed dwords at +0x2C and +0x30 exposing typed subfields through trivial thiscall getters. Concrete owner object unidentified; grouping is DERIVED from the shared caller and the two bitfield source dwords.

Methods: `0x004B26D0`, `0x004B2980`, `0x004B29F0`, `0x004B2A30`, `0x004B2A80`, `0x004B2AD0`, `0x004B2B00`, `0x004B2B40`, `0x004B2B80`

- `this+0x00000024` `int8 packed_byte_field_24` (read, DERIVED)
- `this+0x00000025` `int8 packed_byte_field_25` (read, DERIVED)
- `this+0x00000026` `int16 packed_short_field_26` (read, DERIVED)
- `this+0x0000002C` `uint32_bitpacked packed_bitfield_2C` (read, DERIVED)
- `this+0x00000030` `uint32_bitpacked packed_bitfield_30` (read, DERIVED)

### IndexedPackedFieldContainer

Indexed container of packed per-entry fields decoded by 0x004B28F0: a byte field at entry byte-index a2+18 scaled by 0.00390625 and a signed int16 at entry byte-index 2*a2+22 scaled by 0.0099999998. The entry stride is derived from the index math, but no fixed base offsets can be declared from this packet, so the field set is deliberately empty.

Methods: `0x004B28F0`


### NoiseValueGenerator

Per-frame noise source producing an approximately normal distribution: a hash-based PRNG result is popcounted into a binomial term, combined with a float from a noise table indexed by a byte counter stored at +0x0, then centered and scaled. The noise-table array base (this+257 dwords) is visible in the raw source but its absolute offset is outside the packet's allowed evidence, so no table field is declared.

Methods: `0x004B3CE0`

- `this+0x00000000` `uint8 noise_table_index` (read_write, GUESS)

### SessionLapData

Session/race-timing struct with per-lap storage. Constructor 0x004BB7A0 zeroes a block at +0x40 and a set of scalars, plants -1 / float -1.0 sentinels, and delegates to StructResetReinitializer. Allocator 0x004BB810 sets session-mode flags (+0xC/+0x60) from global session type dword_7C56A4, stores a lap count (capped 128) at +0x88, allocates two float arrays (+0x8C/+0x90) and one byte array (+0x94) and fills them with -1.0f/0 sentinels. The allocator was previously mislabeled Vehicle_Array_Buffer_Allocator (legacy ABI lead name); owner class remains UnknownObject.

Methods: `0x004BB7A0`, `0x004BB810`

- `this+0x00000000` `int32 scalar_field_00` (write, DERIVED)
- `this+0x00000004` `int32 sentinel_field_04` (write, DERIVED)
- `this+0x0000000C` `int32 session_mode_flag_C` (write, DERIVED)
- `this+0x00000024` `int32 sentinel_field_24` (write, DERIVED)
- `this+0x00000028` `float32 float_minus_one_field_28` (write, DERIVED)
- `this+0x0000002C` `int32 sentinel_field_2C` (write, DERIVED)
- `this+0x00000030` `int32 zeroed_field_30` (write, DERIVED)
- `this+0x00000040` `int32 zero_block_start_40` (write, DERIVED)
- `this+0x00000044` `int32 zero_block_44` (write, DERIVED)
- `this+0x00000060` `int32 session_mode_flag_60` (write, DERIVED)
- `this+0x00000088` `int32 lap_count` (write, DERIVED)
- `this+0x0000008C` `float_ptr float_array_8C` (write, DERIVED)
- `this+0x00000090` `float_ptr float_array_90` (write, DERIVED)
- `this+0x00000094` `uint8_ptr_or_int32 byte_array_count_94` (write, DERIVED)
- `this+0x00000098` `int32 element_count_98` (write, DERIVED)
- `this+0x000000A4` `int32 zeroed_field_A4` (write, DERIVED)

## Compatibility contracts

- **PlayerOptionsStructLayout** — Player-options object must expose writable option fields at +0x0C/+0x10 (paired values, mirrored to +0x14/+0x18) and flag-gated storage at +0x14..+0x20 written by int/byte/short setter variants, plus a string buffer fed by StringCopyWithBufferRealloc; every mutator path must end by calling the finalizer at 0x004A1B70 and returning its result.
- **UiRangePairControlLayout** — UI sub-control blocks seeded by UIControlWindowInitialization keep a vtable/interface pointer at +0x0 followed by (min=0, max=-1) pairs at 0x4/0x8 and 0xC/0x10; a 3-pair variant extends the pattern to +0x14/+0x18, and a 3-dword variant carries a state field +0x4 and handle/index +0x8. Each instance is distinguished by the vtable global stored at +0x0.
- **SessionLapDataLayout** — Session lap-data struct must keep a capped lap count at +0x88, two float arrays at +0x8C/+0x90 and a byte array at +0x94 (with count +0x98), session-mode flags at +0xC/+0x60 keyed off global dword_7C56A4, and -1 / -1.0 sentinels; all arrays are allocated through 0x00587C03 and filled with -1.0f/0.
- **PackedPhysicsBitfieldLayout** — Vehicle physics carrier keeps scaled scalar fields at +0x24 (byte, 0.05), +0x25 (byte, 0.05) and +0x26 (int16, 0.002), plus two bit-packed dwords: +0x2C with subfields at bits 0-6 (biased 7-bit /63), 8-11 (nibble -1), 12-16 (5-bit /31) and 17-31 (15-bit /10), and +0x30 with a per-bit test, bits 15-21 (/0x7F), 22-23 (2-bit /3) and 28-30 (3-bit).
- **FileFinderContract** — File finder probes candidates in order (custom dir a3; else season dir/name with byte_5EA438 fallback; else 'common' variant), returns 0 on the first openable path (closing the handle and copying the resolved path), and returns -1 with a guarded debug log when nothing opens.
- **StringCopyValidationContract** — Resource-string copier validates a season-races section and a string key, copies the entry into the caller buffer with capacity a2-1 and null-terminates it; returns 0 on success and 1 on section/key lookup failure.
- **GameModePathPrefixMapping** — Game-mode index 0-6 maps to a path-prefix string global (0x005CD6FC..0x005CD6CC) that is combined with a suffix via '%s%s'; any other index leaves the output buffer empty and returns 0.

## Unresolved

- Every object owner is UnknownObject; no live reference or RTTI evidence identifies a concrete game class.
- The 14 distinct vtable/interface globals (0x005ACBCC, 0x005ACBD8, 0x005ACBE4, 0x005ACBF0, 0x005ACBFC, 0x005ACC08, 0x005ACC20, 0x005ACC2C, 0x005ACC38, 0x005ACC44, 0x005ACC50, 0x005ACC5C, 0x005ACC68, 0x005ACC74) imply distinct UI sub-control types; common ownership of the UiRangePairControl field layout is NOT proven and the grouping is a GUESS.
- Meaning of the 0/-1 value pairs is not confirmed: state/counter vs range (min,max) bounds vs sentinel handles are competing DERIVED interpretations.
- Why 0x004A7010 stores a3/a4 twice at mirrored offsets (+0xC/+0x14, +0x10/+0x18) is unexplained; duplicate-field semantics unknown.
- The PlayerOptionsStruct string buffer location is not exposed; setter variants copy strings via StringCopyWithBufferRealloc but the destination offset is unrecorded.
- Int/byte/short widths overlap at +0x14..+0x20 across the setter variants (0x004B1AC0 int, 0x004B1C20 byte, 0x004B1F50 short); union/bit-packed interpretation is a GUESS, distinct-object alternative not excluded.
- Game-mode index enum (0..6) meaning undefined; prefix globals' actual string contents are legacy/DERIVED labels only.
- 0x004B1AB0 identity body purpose unknown: getter-style adapter, virtual-slot placeholder, or hook point; raw source shows only pass-through.
- For 0x004B26D0 the pairing of globals flt_59E448/flt_5ACCB0 with the 0.05 vs 0.002 scales is unproven; for 0x004B28F0 the pairing of flt_59E444/flt_5AC988 is unproven.
- 0x004B28F0's a2 entry selector and the containing array layout are undocumented; the class IndexedPackedFieldContainer has no fixed-offset fields.
- The inverse-of-pack claim for the +0x2C 15-bit field (0x004B2980) is external skeleton prose, not packet evidence.
- Semantic meaning of the +0x2C and +0x30 bitfield subfields (nibble/5-bit/7-bit/15-bit/2-bit/3-bit/bit-test) is unknown.
- For 0x004B3CE0 the roles of globals flt_59E450/flt_5ACCF8 (0.5 vs 0.35355338 scale) are unverified; 0.35355338 ~ 1/sqrt(8) is inferred; the noise-table array base (this+257 dwords) is out of allowed evidence and not declared as a field.
- SessionLapData sentinels -1 and float -1.0 mark invalid/not-set but semantics are unconfirmed; -1082130432 equals the IEEE-754 float -1.0f bit pattern (DERIVED).
- Legacy ABI lead name Vehicle_Array_Buffer_Allocator conflicts with the SessionLapDataAllocator interpretation of 0x004BB810; owner remains UnknownObject.
- FileFinder format-string globals (0x005BE860, 0x005C6784, 0x005D30B4) association with '%s%s'/'%s%s%s'/'%scommon\%s' is DERIVED, not pinned in raw source; sub_587DB0 (file open) and sub_587C20 (path suffix check) semantics are inferred; a4 is unused; byte_5EA438 fallback semantics unknown.
- StringCopyWithValidation a4 argument meaning (section identifier?) unconfirmed; sub_587DD0 copy semantics unconfirmed; structural-twin relationship to sub_45B5C0 not verified.
- UiWindowBlock identity and the semantics of its 21 zeroed dwords are unknown; whether it is the enclosing UI window object or a data-only sub-block is undetermined.
- NoopStub2 (0x004B0170) replaces what may have been a shared hook; origin and purpose unknown.
- off_5ACBF0 and the other +0x0 vtable globals are labeled vtable pointers by prior analysis, which this packet's evidence does not independently prove.
