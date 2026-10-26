# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 32 validated function IR records. The packet supplies no DERIVED owner classes; every owner is UNKNOWN, so all classes below are GUESS-level proposals. The packed vehicle-orientation state is the strongest grouping: five functions (0x004B2B90, 0x004B2BF0, 0x004B2C20, 0x004B2C50, 0x004B31A0) share the this+0xF dword as a bitfield (2-bit class in bits[1:0], 6-bit scaled value in bits[7:2]) alongside int16 components at +0xC/+0xE/+0x10, and are called by VehicleOrientationFromEulerAngles (0x004B2DD0), sub_4B32A0 (0x004B32A0) and VectorToShort3Conversion (0x004B2C80). The stride-176 circular buffer groups 0x004B6920/0x004B69A0/0x004B69F0 over this+0x9B0/0x9B4/0x9B8/0x9BC, consumed by pit-stall and pitstop callers. Config-line serialization groups 0x004B1B10/0x004B1C80/0x004B1E20 on the shared this+0xC key/this+0x14 value layout with common separator/terminator globals and the 0x00566C30 length-checked writer. The three thin forwarders 0x004B9870/0x004B9880/0x004B9CD0 share only the deref-this+0x0-and-forward shape (synthetic grouping, flagged). The 12-byte linked-list node record (data/+0, next/+4, flag/+8) is shared between the append list (0x004A1DC0) and the fixed-block pool (0x004B44E0/0x004B45F0). Game_Post (0x0042DA30) drives two post-lifecycle hooks (0x004B1900, 0x004B4170) that both use the StringSplitLoop source-path assertion plus DebugLogWrite pattern. Read-only float globals flagged by packet facts but absent from the raw decompilation (compiled-in literals) are deferred to unresolved_evidence_refs.

## Function roles

- `0x0049E170` **HudCharacterGridRenderer** — Batch-renders eleven single characters at fixed 2-row grid positions. Guards on the format context at this+0xC, the display context at this+0x14, and the non-zero sub-field at display+84; formats each of eleven character-source globals (dword_7CE6AC..dword_7CE8A4, each plus a small per-slot offset) as '%c' via StringFormatWithBufferOverflowCheck (0x0058815F) into a local buffer, then places each character at a fixed (x,row) coordinate through the render-placement helper 0x00553070. Row 0 holds seven characters at x=0..210 (y=11); row 1 holds five at x=20..188 (y=65). Returns the result of the final placement call.
- `0x0049E3E0` **HudRenderDispatchController** — Guarded rendering dispatch. When the render-surface pointer at this+0x8 and the display-context pointer at this+0x14 are both non-null, reads the sub-context pointer at this+0x68 (*(this+0x14 + 84)) and, if also non-null, calls 0x0049F1C0 with fixed flags (1, 1, 0) plus the two guarded pointers. Any null check aborts the dispatch. Invoked by sub_49D5D0 (0x0049D5D0).
- `0x0049E5B0` **ARGBGradientEncoder** — Pure float-to-ARGB gradient encoder. Clamps the input into 30.0..150.0 and selects one of three channel branches (blue below 70.0, green mid-range, red at/above 110.0), computing the channel via CRTFtol (0x00587BDC) and combining with the ARGB mask constants (0xFF0000FF, 0xFFFF0000, 0xFFFFFF00).
- `0x0049E8F0` **StateZeroInitStruct** — State-struct zero-initializer: writes 0 to the 19 consecutive dword fields this+0x0..0x48 (4-byte stride) and returns the original this pointer. No reads, no callees, no globals. Invoked by MultiCallSequence (0x0049AFE0) as part of a state-setup sequence.
- `0x0049ED00` **UIParamEffectTrigger** — Stores parameter a2 into this+0x1C, then invokes UISparkleEffect (0x0049ED30) and returns its result. Used by ParamRangeClampedLerp (0x0049F530) to commit a computed value before triggering the sparkle effect.
- `0x0049ED10` **UIParamEffectTrigger** — Guard-then-forward: if the dword at this+0x0 is non-zero, calls the raw-source helper sub_553700(a2) and returns its result; otherwise falls through with an uninitialized result register. Invoked by ParamRangeClampedLerp (0x0049F530).
- `0x0049ED20` **UIParamEffectTrigger** — Conditional dispatch: if the int flag at this+0x4 is non-zero, calls the raw-source helper sub_553700 with a2 and returns its result; when zero, falls through returning an uninitialized local. Invoked by ParamRangeClampedLerp (0x0049F530).
- `0x004A0DE8` **SessionStateFlagSetter** — Sets the global byte byte_7CE25E (0x007CE25E) to 1. A single race-state flag write with no arguments, guards, or side effects beyond the one global store.
- `0x004A1DC0` **AppendLinkedList** — Appends a node containing data a2 to a singly-linked list (head this+0x0, tail this+0x4, first-node anchor this+0x8, count this+0xC), gated by the enabled flag byte at this+0x10 and a2 non-null. Allocates a 12-byte node via OperatorNewNhMallocWrapper (0x00587C03), initializes data/+0, next/+4, flag/+8, links at the tail (setting head/anchor/tail on the first insert), and increments the count. Returns the new node pointer, or 0 when guarded out or allocation fails.
- `0x004A4050` **ModeSwitchFloatAccumulator** — Per-frame accumulator update gated on the mode word at this+0x78: mode 0 skips, mode 1 resets the accumulator float at this+0x84 to 0, any other non-zero mode adds argument a2 to it. After the update the accumulator value is forwarded to the raw-source sub_4A2840 for further processing. Invoked from ThreeTargetAnimationDispatcher (0x004A55A0).
- `0x004A55A0` **ThreeTargetAnimationDispatcher** — Per-frame dispatcher that forwards to up to three sub-object pointers held in this: calls 0x004A3570 on the objects at this+0x10 and this+0xC passing a3, and calls AccumulatorWithStateSwitch (0x004A4050) on the object at this+0x14 passing a2. Each call is independently null-guarded.
- `0x004A5700` **ChampionshipScoreTable** — Linear search over up to three stride-2 championship score thresholds starting at this+0x164 (entry count at this+0x160, hard cap 3). Each stride-2 entry qualifies when its value is greater than the player score at *this+0x403C and lower than the total-race-laps global dword_8ACF8C. Returns the first qualifying entry via this[2*v2+89], or -1 when none qualifies. Invoked by ShortComputation_c8a0 (0x0049C8A0).
- `0x004A8B50` **SevenDwordVTableObject** — Straight-line constructor for a seven-dword object: installs the vtable pointer off_5ACC14 at this+0x0 and initializes +0x4 (0), +0x8 (-1 sentinel), +0xC (0), +0x10 (89), +0x14 (0), +0x18 (89). Returns this. No branches, no calls.
- `0x004B1900` **PlayerFileRecord** — Player-file post-processing invoked by Game_Post (0x0042DA30). When StringSplitLoop(2, aDDevF119992002_20, 2515) (0x004D7A50) returns non-zero, writes the debug message aEnteredPlayerf_2 into dword_8AD25C via DebugLogWrite (0x004D7AA0). Runs player-data init sub_4B0770(this, 1). When the state field at this+0x1F78 is not 4, runs the raw-source additional setup sub_4B17B0(this); otherwise returns the sub_4B0770 result.
- `0x004B1B10` **ConfigLineSerializer** — Formats and writes a debug log entry into the output buffer a2. Copies the label string from this+0x14 into a 256-byte local via FormattedStringCopy (0x004A1A60), writes the separator aSS_6 (0x005CD13C), conditionally appends a comment taken from this+0x0C (falling back to byte_5EA438 when null, skipped when empty) via aS_8 (0x005D23A8), then writes the suffix token word_5C30B4. All writes use the length-checked writer 0x00566C30. Returns 0.
- `0x004B1C80` **ConfigLineSerializer** — Serializes one config key/value pair into the output buffer a2. Formats the value field at this+0x14 (float) into a 256-byte scratch via ArithmeticComparison (0x004A1B20), writes the key prefix aSS_6, conditionally writes the key name from this+0xC (defaulting to byte_5EA438 when null) via aS_8, and terminates with word_5C30B4. Returns 0.
- `0x004B1E20` **ConfigLineSerializer** — Writes one config key/value pair into the output buffer a2. Formats the value field at this+0x14 (float) into a 256-byte scratch via StringFormatCopyWithFloat (0x004A1A00), writes the key prefix aSS_6, conditionally writes the key name from this+0xC (defaulting to byte_5EA438 when null) via aS_8, and terminates with word_5C30B4. Returns 0.
- `0x004B2B90` **OrientationPackedField** — Classifies float a2 into one of four 2-bit categories written into bits[1:0] of the dword at this+0xF (mask 0xFFFFFFFC). Ranges: a2<=0.75 -> 0, (0.75, 0.85000002) -> 1, [0.85000002, 0.94999999) -> 2, >=0.94999999 -> 3. Called by VectorToShort3Conversion (0x004B2C80).
- `0x004B2BF0` **OrientationPackedField** — Selector that reads the 2-bit classification field at this+0xF, masks with 3, and returns one of four blend constants: 0 -> 0.69999999, 1 -> 0.80000001, 2 -> 0.89999998, 3 -> 1.0. Called by VehicleOrientationFromEulerAngles (0x004B2DD0) and sub_4B32A0 (0x004B32A0).
- `0x004B2C20` **OrientationPackedField** — Encodes a float argument into a 6-bit field of the byte at this+0x0F: scaled by ~0.0180018 (packed constant referenced by global 0x005ACCE0), truncated by CRTFtol (0x00587BDC), masked to 6 bits, shifted left 2, and XOR-merged into bits[7:2] with mask 0xFFFFFF03, preserving bits[1:0]. Stores the merged word back and returns it. Called by VectorToShort3Conversion (0x004B2C80).
- `0x004B2C50` **OrientationPackedField** — Decodes the 6-bit field from the dword at this+0xF: shift right 2, mask 0x3F, multiply by the 55.549999 scale held in flt_5ACCE4, and return the product as double. Consumed by VehicleOrientationFromEulerAngles (0x004B2DD0) and sub_4B32A0 (0x004B32A0).
- `0x004B31A0` **OrientationPackedField** — Converts three float inputs a2[0..2] into int16 values at this+0xC, this+0xE and this+0x10 using a 2048.0 scale with saturation at +/-15.999512 (0x7FFF / -32767 clamps). Returns the third converted value. Caller VehicleOrientationFromEulerAngles (0x004B2DD0) suggests the packed int16 values encode an orientation derived from Euler angles.
- `0x004B4170` **RenderPostLifecycleMarker** — Post-render lifecycle marker. Runs StringSplitLoop(2, aDDevF119992002_21, 438) (0x004D7A50); when the byte result is non-zero writes 'Entered Render Post' into dword_8AD25C via DebugLogWrite (0x004D7AA0) and returns that result, otherwise returns the zero result. Invoked by Game_Post (0x0042DA30) as part of shutdown/cleanup sequencing.
- `0x004B44E0` **FixedBlockPool** — One-time initialization of a fixed-block pool and its two linked lists. Zeroes the eight pool globals dword_8AB6F0..dword_8AB70C, allocates a 4-byte root node plus a 13824-byte buffer via OperatorNewNhMallocWrapper (0x00587C03), builds one 12-byte active-list head node (flag byte 1) linked through dword_8AB6F0/8AB6F4/8AB6F8/8AB6FC, then in 32 iterations of 432 bytes creates one 12-byte free-list node (flag byte 0) per sub-block, linking front-first through dword_8AB700/8AB704/8AB708 and counting in dword_8AB70C. Returns the last allocation result.
- `0x004B45F0` **FixedBlockPool** — Tears down the fixed-block pool, guarded by byte_8AB6E0 bit 0 (set on entry to prevent double-free). Walks the free list (head dword_8AB700) and the active list (head dword_8AB6F0), freeing each node's buffer pointer via FreeWrapper_7bcf (0x00587BCF) when the in-use flag byte at node+8 is set, then frees the node struct. Resets all free-list and active-list globals to zero. Returns 1 on both paths.
- `0x004B6920` **Stride176CircularBuffer** — Returns base + 176 * a2 where base is the pointer stored at this+0x9B0: the address of the a2-th element of a 176-byte-stride array. Caller is PitStallProximityCheck (0x004B5DA0).
- `0x004B69A0` **Stride176CircularBuffer** — Advances a circular write index: reads the buffer base at this+0x9B0, computes (index at this+0x9B8 + 1) modulo the modulus at this+0x9B4, stores the new index, and calls the raw-source PhysicsObjectListManager on the entry at base + 176 * new_index. Caller is PitstopActionSet (0x004B6940).
- `0x004B69F0` **Stride176CircularBuffer** — Returns TRUE when either this[622] (0x9B8) or this[623] (0x9BC) is negative, i.e. when either index field is in the invalid/uninitialized state; FALSE only when both are >= 0. Called by CircularBufferCheck (0x004B68C0) and PitstopActionSet (0x004B6940).
- `0x004B9870` **PointerFieldForwarder** — Thin forwarding wrapper: dereferences the pointer at this+0x0, passes it as the first argument to the raw-source PitTimingUpdate along with a2/a3/a4, and returns the helper's char result unchanged. Callers are ConditionalStateUpdate (0x004BA150) and TwoPathDispatch (0x004BA6C0).
- `0x004B9880` **PointerFieldForwarder** — Thin forwarder: dereferences the pointer stored at this+0x0, passes it to the raw-source sub_4B7DE0, and returns that call's char result. The prelabel getter template is structurally inaccurate; the actual behavior is a delegation. Invoked by GuardedDispatchWithStateCheck (0x004BA740).
- `0x004B9CD0` **PointerFieldForwarder** — Thin void forwarder: reads the int stored at this+0x0 and calls the raw-source AngleClampWrap(*this, a2) with the field value and the incoming float a2. Callers sub_4B9890 and FloatAccumulator (0x004B9D00) feed time/accumulator values, consistent with an angle/time clamp application.
- `0x004BA140` **AIBehaviorFieldAccessor** — Loads the target struct pointer from this+8, writes the byte argument a2 into its field at offset 0xF80, and returns the intermediate pointer. Unconditional write; the field is likely a per-object flag or state byte set by AIBehaviorInitialization (0x004BF0A0).

## Proposed classes

### HudCharacterGridRenderer

HUD text renderer that formats eleven global character sources as '%c' and places each at a fixed 2-row grid position. Gates rendering on a format context pointer at this+0xC, a display context pointer at this+0x14, and a non-zero sub-field at display+84. The HUD indicator interpretation is DERIVED prose only.

Methods: `0x0049E170`

- `this+0x0000000C` `pointer format_context_ptr` (read, GUESS)
- `this+0x00000014` `pointer display_context_ptr` (read, GUESS)

### HudRenderDispatchController

Guarded rendering dispatch controller: requires a render-surface pointer at this+0x8, a display-context pointer at this+0x14, and a sub-context pointer at this+0x68 (loaded as *(display+84)) before calling 0x0049F1C0 with fixed flags (1, 1, 0). Invoked by sub_49D5D0.

Methods: `0x0049E3E0`

- `this+0x00000008` `pointer render_surface_ptr` (read, GUESS)
- `this+0x00000014` `pointer display_context_ptr` (read, GUESS)
- `this+0x00000068` `pointer sub_context_ptr` (read, GUESS)

### ARGBGradientEncoder

Free float-to-ARGB gradient encoder mapping 30.0..150.0 through blue/green/red channel branches computed with CRTFtol (0x00587BDC). Whether the caller consumes a full ARGB color or a single channel is unverified.

Methods: `0x0049E5B0`


### StateZeroInitStruct

State struct with a 76-byte zeroed footprint (19 dwords, offsets 0x0..0x48). 0x0049E8F0 writes 0 to every field and returns this; invoked by MultiCallSequence (0x0049AFE0) during a state-setup sequence. Concrete type and semantics unknown.

Methods: `0x0049E8F0`

- `this+0x00000000` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000004` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000008` `int zeroed_state_dword` (write, GUESS)
- `this+0x0000000C` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000010` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000014` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000018` `int zeroed_state_dword` (write, GUESS)
- `this+0x0000001C` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000020` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000024` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000028` `int zeroed_state_dword` (write, GUESS)
- `this+0x0000002C` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000030` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000034` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000038` `int zeroed_state_dword` (write, GUESS)
- `this+0x0000003C` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000040` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000044` `int zeroed_state_dword` (write, GUESS)
- `this+0x00000048` `int zeroed_state_dword` (write, GUESS)

### UIParamEffectTrigger

Small __thiscall helpers invoked by ParamRangeClampedLerp (0x0049F530): 0x0049ED00 commits a parameter into this+0x1C then triggers UISparkleEffect (0x0049ED30); 0x0049ED10 and 0x0049ED20 are guard-then-forward helpers keyed on this+0x0 and this+0x4 that delegate to the raw-source sub_553700. The grouping is a GUESS synthesis based on the shared caller; the three methods use overlapping field regions.

Methods: `0x0049ED00`, `0x0049ED10`, `0x0049ED20`

- `this+0x00000000` `int guard_flag` (read, GUESS)
- `this+0x00000004` `int guard_flag` (read, GUESS)
- `this+0x0000001C` `int stored_param` (write, GUESS)

### SessionStateFlagSetter

Session-subsystem flag writer that sets the global byte byte_7CE25E to 1. No object state is touched; the flag's meaning is not evidenced by this packet.

Methods: `0x004A0DE8`


### LinkedListNodeRecord

12-byte singly-linked list node record established by the append operation of 0x004A1DC0 and the pool node wiring of 0x004B44E0/0x004B45F0: data pointer at +0, next pointer at +4, flag byte at +8. Only the next-pointer field has a packet evidence ref; the data/flag offsets come from the raw source. The payload type is unknown.

Methods: 

- `*(this+0x4)+0x00000004` `pointer next_ptr` (read_write, GUESS)

### AppendLinkedList

Singly-linked list container with head at this+0x0, tail at this+0x4, a first-node anchor at this+0x8, element count at this+0xC and an enabled flag byte at this+0x10. 0x004A1DC0 appends a 12-byte node holding data a2, linking at the tail and setting head/anchor/tail together on the first insert.

Methods: `0x004A1DC0`

- `this+0x00000000` `pointer list_head` (read_write, GUESS)
- `this+0x00000004` `pointer list_tail` (read_write, GUESS)
- `this+0x00000008` `pointer first_node_anchor` (write, GUESS)
- `this+0x0000000C` `int element_count` (read_write, GUESS)
- `this+0x00000010` `byte enabled_flag` (read, GUESS)

### ModeSwitchFloatAccumulator

Accumulator object gated by a mode word at this+0x78 (0 = disabled, 1 = reset, other = accumulate) operating on the float at this+0x84. After the per-frame update the accumulator value is forwarded to the raw-source sub_4A2840. Invoked from the three-target dispatcher.

Methods: `0x004A4050`

- `this+0x00000078` `int mode_word` (read, GUESS)
- `this+0x00000084` `float accumulator_float` (read_write, GUESS)

### ThreeTargetAnimationDispatcher

Per-frame dispatcher holding three sub-object pointers (this+0x10 and this+0xC targeted by 0x004A3570 with a3, this+0x14 targeted by the accumulator 0x004A4050 with a2). Each call is independently null-guarded. The animation interpretation is DERIVED prose; the owner and sub-object identities are unknown.

Methods: `0x004A55A0`

- `this+0x0000000C` `pointer sub_object_a` (read, GUESS)
- `this+0x00000010` `pointer sub_object_b` (read, GUESS)
- `this+0x00000014` `pointer accumulator_sub_object` (read, GUESS)

### ChampionshipScoreTable

Championship score-threshold table: stride-2 entries starting at this+0x164 (up to 3, count at this+0x160). An entry qualifies when above the player score at *this+0x403C and below the total-race-laps global dword_8ACF8C; the lookup returns this[2*v2+89] or -1. The player-score owner object is unidentified.

Methods: `0x004A5700`

- `this+0x00000160` `int entry_count` (read, GUESS)
- `this+0x00000164` `int[3] threshold_entries` (read, GUESS)
- `obj+0x0000403C` `int player_score` (read, GUESS)

### SevenDwordVTableObject

Seven-dword object constructed by 0x004A8B50: installs the vtable off_5ACC14 at this+0x0 and initializes +0x4 (0), +0x8 (-1 sentinel), +0xC (0), +0x10 (89), +0x14 (0), +0x18 (89). The meaning of the 89 values and the -1 sentinel is unconfirmed.

Methods: `0x004A8B50`

- `this+0x00000000` `pointer vtable_ptr` (write, GUESS)
- `this+0x00000004` `int init_zero` (write, GUESS)
- `this+0x00000008` `int sentinel_neg1` (write, GUESS)
- `this+0x0000000C` `int init_zero` (write, GUESS)
- `this+0x00000010` `int init_89` (write, GUESS)
- `this+0x00000014` `int init_zero` (write, GUESS)
- `this+0x00000018` `int init_89` (write, GUESS)

### PlayerFileRecord

Player-file record processed by Game_Post (0x0042DA30): the post routine runs player-data init sub_4B0770(this, 1) and branches on the state field at this+0x1F78, taking an additional raw-source setup (sub_4B17B0) when the state is not 4. State value 4 as a ready/completed marker is DERIVED prose, not proven here.

Methods: `0x004B1900`

- `this+0x00001F78` `int state_field` (read, GUESS)

### ConfigLineSerializer

Config/debug line serializer writing into an output buffer a2. Shared layout: key/name pointer at this+0xC (fallback default byte_5EA438 when null) and a value/label field at this+0x14 (float for the two config writers, string source for the log-line formatter). All three write the separator aSS_6 (0x005CD13C), the conditional name/label via aS_8 (0x005D23A8) and terminate with word_5C30B4 through the length-checked writer 0x00566C30. In 0x004B1C80 and 0x004B1E20 the formatted value buffer is never written to a2 in the visible body.

Methods: `0x004B1B10`, `0x004B1C80`, `0x004B1E20`

- `this+0x0000000C` `pointer key_name_ptr` (read, GUESS)
- `this+0x00000014` `float value_or_label_field` (read, GUESS)

### OrientationPackedField

Packed vehicle-orientation state: the dword at this+0xF holds a 2-bit class in bits[1:0] and a 6-bit scaled value in bits[7:2], alongside int16 components at this+0xC/+0xE/+0x10. Encoders/decoders/selectors are 0x004B2B90 (classify), 0x004B2BF0 (blend select), 0x004B2C20 (6-bit encode), 0x004B2C50 (6-bit decode) and 0x004B31A0 (3-float to int16 pack), consumed by VehicleOrientationFromEulerAngles (0x004B2DD0), sub_4B32A0 (0x004B32A0) and VectorToShort3Conversion (0x004B2C80). The grouping is a GUESS synthesis from the shared field region and caller set; physical meaning of the packed values is unknown.

Methods: `0x004B2B90`, `0x004B2BF0`, `0x004B2C20`, `0x004B2C50`, `0x004B31A0`

- `this+0x0000000C` `int16 packed_int16_0` (write, GUESS)
- `this+0x0000000E` `int16 packed_int16_1` (write, GUESS)
- `this+0x0000000F` `byte bitfield_byte` (read_write, GUESS)
- `this+0x00000010` `int16 packed_int16_2` (read_write, GUESS)

### RenderPostLifecycleMarker

Post-render lifecycle marker invoked by Game_Post (0x0042DA30): runs the StringSplitLoop source-path assertion (2, aDDevF119992002_21, 438) and, on non-zero, writes the 'Entered Render Post' debug message into dword_8AD25C. The literals 2 and 438 carry no established semantics.

Methods: `0x004B4170`


### FixedBlockPool

Global fixed-block pool (state in dword_8AB6F0..dword_8AB70C) with two linked lists: an active list (head dword_8AB6F0, tail dword_8AB6F4, anchor dword_8AB6F8, count dword_8AB6FC, head flag byte 1) and a free list (head dword_8AB700, anchors dword_8AB704/8AB708, count dword_8AB70C, head flag byte 0), built over a 13824-byte buffer carved into 32 x 432-byte sub-blocks. 0x004B44E0 initializes, 0x004B45F0 tears down under the byte_8AB6E0 bit-0 re-entry guard. The pool consumer is unknown.

Methods: `0x004B44E0`, `0x004B45F0`


### Stride176CircularBuffer

Circular/array buffer with base pointer at this+0x9B0, element modulus at this+0x9B4, write index at this+0x9B8 and read index at this+0x9BC, element stride 176 bytes. 0x004B6920 resolves an element by index, 0x004B69A0 advances the write index modulo the modulus, 0x004B69F0 reports invalid state when either index is negative. Consumed by pit-stall/pitstop callers (0x004B5DA0, 0x004B68C0, 0x004B6940). The 176-byte element type is unknown.

Methods: `0x004B6920`, `0x004B69A0`, `0x004B69F0`

- `this+0x000009B0` `pointer buffer_base_ptr` (read, GUESS)
- `this+0x000009B4` `int element_modulus` (read, GUESS)
- `this+0x000009B8` `int write_index` (read_write, GUESS)
- `this+0x000009BC` `int read_index` (read, GUESS)

### PointerFieldForwarder

Thin __thiscall delegation wrappers that dereference the pointer/int stored at this+0x0 and forward it (plus unchanged arguments) to a raw-source helper: PitTimingUpdate (0x004B9870), sub_4B7DE0 (0x004B9880), AngleClampWrap (0x004B9CD0). The grouping is a GUESS synthesis from the shared deref-this+0x0 shape only; the three callees and their semantics are distinct and unverified.

Methods: `0x004B9870`, `0x004B9880`, `0x004B9CD0`

- `this+0x00000000` `pointer delegated_target` (read, GUESS)

### AIBehaviorFieldAccessor

Accessor into an AI-behavior data struct: loads the target struct pointer from this+8 and writes a byte argument to its field at offset 0xF80 (the packet encodes that nested offset as this+0xF80). Invoked by AIBehaviorInitialization (0x004BF0A0); the enum values written are unknown.

Methods: `0x004BA140`

- `this+0x00000008` `pointer nested_struct_ptr` (read, GUESS)
- `this+0x00000F80` `byte ai_state_flag` (write, GUESS)

## Compatibility contracts

- **PackedOrientationStateLayout** — The dword at this+0xF is a packed bitfield: bits[1:0] hold a 2-bit class (written with mask 0xFFFFFFFC, values 0..3), bits[7:2] hold a 6-bit scaled value (written with mask 0xFFFFFF03). The int16 components at this+0xC, +0xE and +0x10 hold float inputs scaled by 2048.0 and saturated at +/-15.999512 (0x7FFF / -32767). Encode scale ~0.0180018 (0x005ACCE0), decode scale 55.549999 (0x005ACCE4), integer conversion via CRTFtol (0x00587BDC).
- **Stride176BufferContract** — The object holds an array base pointer at this+0x9B0 with per-element stride 176 bytes, an element-count/modulus at this+0x9B4, a write index at this+0x9B8 and a read index at this+0x9BC. Element access is base + 176 * index; the write index advances as (index + 1) modulo the modulus. A negative write or read index marks the buffer invalid (TRUE from 0x004B69F0).
- **AppendLinkedListContract** — The append list keeps head at this+0x0, tail at this+0x4, a first-node anchor at this+0x8, element count at this+0xC and an enabled flag byte at this+0x10. Nodes are 12-byte records (data at +0, next link at +4, flag byte at +8) allocated via OperatorNewNhMallocWrapper (0x00587C03). The first insert sets head/anchor/tail to the new node and count to 1; subsequent appends link the old tail's +4 slot to the new node and increment the count.
- **FixedBlockPoolContract** — The global pool state (dword_8AB6F0..dword_8AB70C) must be zeroed on init; a 13824-byte buffer is carved into 32 sub-blocks of 432 bytes, each covered by a 12-byte free-list node (flag byte 0) wired front-first through dword_8AB700/8AB704/8AB708/8AB70C, while one active-list head node (flag byte 1) is wired through dword_8AB6F0/8AB6F4/8AB6F8/8AB6FC. Teardown is re-entry guarded by byte_8AB6E0 bit 0 and frees node buffers through FreeWrapper_7bcf (0x00587BCF) only when the node in-use flag byte at +8 is set, then resets the list globals.
- **ChampionshipThresholdLookupContract** — Championship score-threshold lookup: stride-2 entries begin at this+0x164 (entry count at this+0x160, hard cap of 3). A threshold entry qualifies when it is greater than the player score at *this+0x403C and lower than the total-race-laps global dword_8ACF8C. The first qualifying entry is returned via this[2*v2+89]; -1 when no entry qualifies or the cap is reached.
- **PlayerFilePostContract** — Player-file post-processing must run the player-data init sub_4B0770(this, 1) and branch on the state field at this+0x1F78: when the state is not 4 the additional raw-source setup sub_4B17B0(this) runs and its result is returned; when the state equals 4 the sub_4B0770 result is returned. The routine is driven by Game_Post (0x0042DA30).
- **ConfigLineSerializationContract** — Config/debug line serializers write into the output buffer a2: the key prefix string aSS_6 (0x005CD13C), then the key name from this+0xC (fallback default byte_5EA438 when null, skipped when empty) via aS_8 (0x005D23A8), terminated with word_5C30B4; every write uses the length-checked writer 0x00566C30. The value/label field at this+0x14 (float) is formatted into a 256-byte scratch by the per-function formatter (ArithmeticComparison 0x004A1B20 for serialize, StringFormatCopyWithFloat 0x004A1A00 for write, FormattedStringCopy 0x004A1A60 for the log-line formatter).
- **AiStateFlagWriteContract** — An AI-behavior data struct reached through the pointer at this+8 receives a caller-supplied byte at offset 0xF80 (encoded by the packet facts as this+0xF80). The write is unconditional; a replacement must preserve the target struct layout up to 0xF80 for the byte write to land on the same field.

## Unresolved

- 0x0049E170 (FormatStringBatchDisplay): field this+0x68 is listed in the packet but has no access in the decompiled source; the small decimal offsets (33..62) added to the character-source dwords are likely per-slot indices but their meaning is unknown; sub_553070 and the display-context field at +84 semantics are unestablished; whether this renders a control-scheme / steering-assist HUD indicator is DERIVED prose.
- 0x0049E3E0 (ConditionalRenderDispatch): global dword_7CE048 is flagged by packet facts but appears nowhere in the raw source (skeleton fill labels it RaceSessionState, not verifiable here); the roles of the fixed flags (1, 1, 0) and of sub_49F1C0 are not established.
- 0x0049E5B0 (FloatToColorEncoding): all seven read-only float globals (flt_59E43C, flt_59E468, flt_59E87C, flt_59FEC8, flt_5ACB00, flt_5ACB04, flt_5ACB08) are referenced by the packet but absent from the raw source (compiled-in literals); the global-to-literal mapping is not derivable; the caller SuspensionCornerCheck (0x0049E570) is not in the allowed caller set and whether a full ARGB or single channel is encoded is unverified.
- 0x0049E8F0 (ZeroStateStruct): the concrete state-struct type and semantics are unknown; the abi label State_Struct_Zero_Init is LEGACY trust and not independently corroborated.
- 0x0049ED00/0x0049ED10/0x0049ED20 (UIParamEffectTrigger): grouping is a GUESS synthesis from the shared caller ParamRangeClampedLerp; the raw-source helper sub_553700 has no callee evidence ref in the packet so its identity is unverified; the fall-through return values are uninitialized in the decompiled form; the meaning of the stored value at this+0x1C (float-as-int for UISparkleEffect) is not re-established.
- 0x004A0DE8 (SetRaceStateFlag): the meaning of byte_7CE25E is not evidenced by this function; no callers are recorded so its session-flow role cannot be placed.
- 0x004A1DC0 (linkedListAppend): the role of the second tracker pointer at this+0x8 (written only on first append) is unconfirmed; the list payload type is unknown; the caller ShortComputation_1b70 (0x004A1B70) is not in the allowed caller set.
- 0x004A4050 (AccumulatorWithStateSwitch): the identity of the object owning offsets 0x78/0x84 is unknown; mode values beyond 0=disabled and 1=reset are undocumented; sub_4A2840 (raw-source only) behavior is outside the packet.
- 0x004A55A0 (ThreeTargetAnimationDispatcher): the owner and the three sub-objects are unidentified; the asymmetric argument forwarding (a3 to 0x004A3570 targets, a2 to the accumulator) is delegated to the callees; the AnimationTargetPropagator / accumulator roles are DERIVED prose.
- 0x004A5700 (FindFirstQualifyingScoreThreshold): the stride-2 array layout (even elements thresholds, odd return slots) is inferred from the return index 2*v2+89; the object behind *this and field obj:0x403C ownership are unidentified.
- 0x004A8B50 (ObjectConstructor_4A8B50): owning class unnamed; the 89 values at +0x10/+0x18 and the -1 sentinel at +0x8 are unconfirmed (sentinel-as-empty-marker is GUESS); the off_5ACC14 vtable target is not described.
- 0x004B1900 (PlayerFile_Post): sub_4B17B0 is called in the state != 4 branch but absent from the packet callee list; the StringSplitLoop literals (2, aDDevF119992002_20, 2515) are unexplained; state value 4 as ready/completed is DERIVED; the string/global roles (aDDevF119992002_20 source path, aEnteredPlayerf_2 message, dword_8AD25C buffer) are inferred.
- 0x004B1B10 (formatDebugLogLine): the separator/comment-format/suffix string contents (aSS_6, aS_8, word_5C30B4) and the default string byte_5EA438 are unknown; the 256-byte buffer populated by FormattedStringCopy is not read in the visible path.
- 0x004B1C80 (ConfigKeyValueSerialize) / 0x004B1E20 (ConfigKeyValueWrite): the value buffer v5 populated by the formatter is never written to a2 in the function body, so value emission appears dead here; the value field at this+0x14 is not in the packet field list (only +0xC is); string contents are unknown.
- 0x004B2B90/0x004B2BF0/0x004B2C20/0x004B2C50/0x004B31A0 (OrientationPackedField): the read-only float globals flt_59E7FC, flt_59E908, flt_59EE8C, flt_59E43C, flt_59E6E8, flt_59E824, flt_59E8CC, flt_59E714, flt_5ACC90, flt_5ACC94 are flagged as read but absent from the raw source (compiled-in literals); the 2-bit/6-bit field meanings and the 55.55 scale are unproven; the ABI label FAIL_4b31a0 for 0x004B31A0 is a failed-name placeholder and was not adopted.
- 0x004B4170 (RenderPost): the literals 2 and 438 passed to StringSplitLoop carry no established semantics; dword_8AD25C is only known as a debug message buffer.
- 0x004B44E0/0x004B45F0 (FixedBlockPool): the meaning of the two list heads and their flag bytes (1 active vs 0 free) is inferred; dword_8AB6F8 and dword_8AB708 are written only on the first node and their distinct role is unresolved; the 32-iteration count (13824/432) is derived arithmetic; the node +8 in-use flag semantics are DERIVED.
- 0x004B6920/0x004B69A0/0x004B69F0 (Stride176CircularBuffer): the 176-byte element type and entry layout are inferred from the raw source only; the raw-source callee PhysicsObjectListManager has no callee evidence ref in the packet; the index fields as write/read indices are DERIVED prose; the pit context implied by the caller names is not independent evidence.
- 0x004B9870/0x004B9880/0x004B9CD0 (PointerFieldForwarder): the raw-source callees PitTimingUpdate, sub_4B7DE0 and AngleClampWrap are absent from the packet callee set, so their identities are unverified; the meaning of the dword at this+0x0 and the reason for the indirection are unresolved; the prelabel getter template classifications do not match the actual delegations.
- 0x004BA140 (SetNestedByteField): the meaning and enum values of the byte written at offset 0xF80 are unresolved; the type of the object reached through this+8 is unknown; the packet encodes the nested offset as field:this:0x00000F80.
- General: equal offsets on unrelated this pointers are not proof of identical types; the read-only float globals deferred to unresolved_evidence_refs are compiled-in literals whose global-to-literal mapping this packet cannot prove.
- No evidence in the packet establishes runtime truth; every class here is a GUESS proposal.
