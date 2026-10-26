# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Thirty validated functions reconstructed into seventeen GUESS-level runtime-object classes plus three unknown-owner helpers. The largest coherent group is the spatial proximity grid: InsertIntoGridCells (0x004BE1D0, packet owner SpatialGridIndex DERIVED), GridCellIterate (0x004BE340) and SpriteGridRender (0x004BE4E0) all use the same transform fields (+0x924/+0x928 X origin/scale, +0x92C/+0x930 Y origin/scale) and the tag cursor +0x934; ProximityCheckWithTagUpdate (0x004BDA20) retags the children stored in a grid cell's two dynamic child arrays and dispatches them through SwitchBasedStateHandler. A family of eight adjacent session scoring helpers (0x004C2BE0..0x004C2DC0) is grouped into SessionScoringObject by a shared sample-count field (+0x28), counter field (+0x2C) and caller overlap (SeasonScoringInfoUpdater 0x004C2A80 / sub_4C29F0 0x004C29F0). Two linked-list destructors (0x004C2F20, 0x004C8210) share the same 12-byte owned-data node layout (data at +0, next at +4, ownership flag byte at +8). All packet owners except SpatialGridIndex are UNKNOWN; class identities and field meanings are GUESS proposals only. The x87/FPU compare-flag guards in several functions and nine float globals read by the fact table but absent from the raw source remain unresolved.

## Function roles

- `0x004BDA20` **GridCell** — Retag children of a grid cell's two dynamic child arrays: for the first array retag any element whose tag (dword +4) differs from a2 and whose type (dword +0x20) differs from a3, dispatching each through SwitchBasedStateHandler; for the second array retag any element whose tag differs from a2 (no type check); return this[4]. Both loops gate on the uninterpreted decompiled x87 flag expression !(v9|v10).
- `0x004BDB90` **AudioMixerChannel** — Initialize an audio-mixer channel object: run the field-initializer F_3FieldInitCall (0x004BD7D0) over 64 consecutive 9-dword sub-structures starting at this, run it once more at this + 576 dwords, zero the five trailing dwords at this[585]..this[589] (byte offsets 0x924..0x934), and return this.
- `0x004BE1D0` **SpatialGridIndex** — Convert the float extent carried in a2 into four grid cell indices via CRTFtol against the grid transform (origin this+0x924 / scale this+0x928 for rows, origin this+0x92C / scale this+0x930 for columns), clamp each to 0..7, and append a2 to every cell of the covered rectangle with DynamicArrayAppendWithRealloc (0x004BD9B0); when any index clamped, also append to the fallback array at this + 576 and return the clamp/append status.
- `0x004BE340` **SpatialGridIndex** — Iterate the spatial-grid cells overlapped by an axis-aligned box centred on a3 with radius a4: compute four clamped cell indices via CRTFtol ((pos -/+ radius - origin) * scale), call ProximityCheckWithTagUpdate (0x004BDA20) on every cell in the non-degenerate X/Y range passing the tag at this+0x934, additionally on the overflow list when any index clamped, then increment the counter at this+0x934 and return it. Invoked by ParticleEffectUpdateDispatch.
- `0x004BE4E0` **SpatialGridIndex** — Render a sprite footprint into the 8x8 proximity grid: convert (a3[0], a3[2]) with radius a4 into clamped cell ranges via CRTFtol against grid origin (this+0x924 / this+0x92C) and scale (this+0x928 / this+0x930), call SphereProximityTag (0x004BDB10) for every cell of the covered rectangle tagging each with the tag cursor this+0x934, tag the extra cell at this+0x900 when any index clamped, then bump and return the tag cursor.
- `0x004BE700` **AiPerformanceSetupConfig** — Initialize an AI performance/setup configuration struct to defaults: enable byte flags at +0x340 and +0x341, disable the flag at +0x342, write float parameters 1.0/1.0/600.0/10.0 at +0x344/+0x348/+0x34C/+0x350, zero the accumulators at +0x354 and +0x358, set the integer countdown 10 at +0x35C and mode identifier 5 at +0x360, and return 0.
- `0x004C1660` **SessionPhaseController** — Jump-thunk that forwards a thiscall of this to the RaceStandingsRankingsComputation implementation and returns its char result unchanged; the target implementation is outside this packet. Invoked by PitStopPhaseAdvance when session standings/rankings must be recomputed.
- `0x004C1670` **SessionPhaseController** — Advance a countdown timer driving a session-phase transition: when the timer-active flag byte at +45392 (0xB150) is non-zero, increment the counter at +45384 (0xB148), read the scene-order threshold via SceneOrderReader (0x004C1190), and when the counter reaches it set the session phase at +45380 (0xB144) to 3, reset the phase counter at +45388 (0xB14C) to 1 and clear the flag; return the threshold on the active path.
- `0x004C1E20` **PitStopObject** — Pit-stop destructor-style method: run PitStopMemoryCleanup (0x004C0B10) on the object, then conditionally free the wrapper via FreeWrapper_7bcf (0x00587BCF) when bit 0 of the flag argument a2 is set; always return the object pointer.
- `0x004C1E40` **DoubleChildOwner** — Conditional destruction of a two-pointer object: free the child pointer at this+0x8 when non-zero, free the child pointer at this+0x0 when non-zero, and when bit 0 of the flag a2 is set free the receiver this as well, all via FreeWrapper_7bcf (0x00587BCF); return this. Called by DoubleListCleanup.
- `0x004C29B0` **DelegationWrapper** — Conditional dispatch wrapper: dereference the linked list behind this via LinkedListDereference (0x004C2850); when it yields a non-null node forward the node and argument a2 to the session config reader named in the raw source and return its result; on the null path return the indeterminate value of the uninitialized local v3. Invoked by DelegationChain.
- `0x004C2BE0` **SessionScoringObject** — Field accumulator: add the input a2 to the running total at this[9] (this+0x24) unconditionally and return the original input a2. Called by SeasonScoringInfoUpdater to accumulate a session scoring quantity.
- `0x004C2BF0` **SessionScoringObject** — Side-effecting counter increment: perform ++this[10], a read-modify-write of the dword at this+0x28, and return void. Called by sub_4C29F0. The packet's template prelabel (a side-effect-free getter of 0x28) contradicts the raw source and is not reflected here.
- `0x004C2C00` **SessionScoringObject** — Accumulate the argument a2 into the caller's field at this+0x30 (this[12]) and return a2 unchanged. Called by SeasonScoringInfoUpdater as a field-accumulation step. A structural twin of ConditionalSetter0x30 per the prelabel cluster.
- `0x004C2C20` **SessionScoringObject** — Void counter increment: pre-increment the caller's int32 field at this+0x38 (this[14]) by one, no guard, no callee, no return value. Invoked from SeasonScoringInfoUpdater.
- `0x004C2C40` **SessionScoringObject** — Compute an incremental running average of input a2 using the sample count at this+0x28 as the weighting denominator and store the result at this+0x44; count 0 is a no-op, count 1 stores the input directly, otherwise the weighted average ((count-1)*old + input)/count; then clamp via an FPU compare-status branch writing 1065353216 (1.0f) or, above 22.0, 1102053376 (22.0f). Called by sub_4C29F0.
- `0x004C2CB0` **SessionScoringObject** — Compute an incremental moving average of input a2 using the sample count at this+0x28 and storing the result at this+0x48; base term is the old average at this+0x48 when count is 1, the raw input when count is 0, and (count-1)*old_average otherwise; zero-count stores the input directly, then the averaged value is clamped by an FPU compare-status branch to 1065353216 (1.0f) or, above 22.0, 1102053376 (22.0f). Called by SeasonScoringInfoUpdater.
- `0x004C2D30` **SessionScoringObject** — Compute a running average of the per-call input scaled by 100.0, weighted by the sample count at this+0x28, and store the result at this+0x4C; count 0 stores the scaled input directly, count 1 keeps the previous average, count > 1 uses ((count-1)*average + scaled_input)/count; then post-process through a compare-status branch against 100.0 writing 1084227584 or, above 100.0, 1120403456.
- `0x004C2DC0` **SessionScoringObject** — Compute an incremental running average: increment the counter at this+0x2C (resetting to 1 when the old value is -1), accumulate old_count * previous_average(this+0x50) + input, divide by the updated counter and store at this+0x50; then post-process through a compare-status branch against 120.0 writing 1116471296 or, above 120.0, 1123024896.
- `0x004C2F20` **OwnedDataLinkedList** — Destroy a singly linked list and release the data each node owns: nodes are 12 bytes with a value pointer at +0, next at +4 and an ownership flag byte at +8; walk from the head at this+0, and for every flag-set node free its value wrapper (and the data object it points to when non-null), free each node via FreeWrapper_7bcf, then zero the four head dwords this+0/+4/+8/+0xC and return the last FreeWrapper result. Invoked by AIPathPerformanceFunction.
- `0x004C2FE0` **SceneList** — Reinitialize the 6-dword global array dword_8AC36C to the literal state { 0, -1, 0, 0, 0, 0 } (index 1 set to -1 as the only non-zero entry), invoke SceneListCleanup(), and return a pointer to the reinitialized buffer.
- `0x004C4930` **SceneList** — Scene list and data cleanup: release primary scene-list resources via SceneListCleanup (0x004C4CF0), walk the singly linked list rooted at this+0x8 freeing each node's data payload when the node ownership flag byte at node+8 is set and freeing each node via FreeWrapper_7bcf, zero the four list pointers this+0x8..this+0x14, then free the primary pointer at this+0x0 when non-null and return the earlier result otherwise.
- `0x004C6760` **IndexedContainer** — Bounds-checked index setter: store the candidate index a2 into the index field this[6] (offset 0x18) only when 0 <= a2 < this[5] (item count at offset 0x14); return a2 unchanged whether or not the write occurs.
- `0x004C8210` **OwnedDataLinkedList** — Linked-list destructor with sub-free: walk the singly linked list rooted at *this (next pointer at node+4); for every node, if the flag byte at node+8 is set free the data object at node+0 (and its first member when non-null), then free the node via FreeWrapper_7bcf; the body appears as two successive walk/free passes each followed by zeroing the header this[0..3]; between the passes call ArithmeticComparison_8350 (0x004C8350) and return its result.
- `0x004C8D80` **GlobalObjectDispatcher** — Guarded indirect call: when the global object pointer dword_8AC4C4 is non-null, read its vtable and call the __thiscall slot at vtable offset +16 (index 4) with dword_8AC4C4 as this, returning the call's result; on the null path fall through and return the uninitialized result register. Called from sub_46BF10, sub_46DC60 and sub_4A0250.
- `0x004C8DC0` **GlobalObjectDispatcher** — Guarded dispatch through a virtual method table: when the global object pointer dword_8AC4C4 is non-null, load its vtable, select the method slot at vtable byte offset +80 (index 20) and invoke it thiscall-style as (this=dword_8AC4C4, arg=a1), returning its int result; on the null path fall through and return whatever stale value is left in EAX.
- `0x004C8F10` **ParticleEmitter** — Initialize a particle-emitter object: store the interface pointer off_5ACE2C at +0x0, clear state floats at +0x4, +0x8, +0xC and +0x10, set the emitter duration at +0x14 to the caller-supplied a2 (defaulting to 1.0 when a2 <= 0.0), compute a randomized end boundary v2 = flt_8AAE74[(byte)dword_8AAE70++] * 1.5 and store duration + v2 at +0x18, and return this.
- `0x004C9000` **SessionValidationObject** — Three-stage session validation guard: compute a short value from the global at 0x005EA510 via ShortComputation_c910 (0x0040C910), then return 1 only when the this+0x4 enable flag is non-zero, the computed value is non-zero, and sub_54C0E0 (0x0054C0E0) of the computed value is non-zero; otherwise return 0. Invoked from sub_4C8FC0.
- `0x004C9C70` **SortedFloatKeyRangeSearch** — Binary search over a sorted float key array rooted at this[104] with element count in the global dword_5C329C; return a pointer to the first element whose key lies within [a2 - a3, a2 + a3] and write the count of in-range elements to *a4, or null with *a4 = 0 when the count is zero. Callers are per-frame rendering and animation paths.
- `0x004CA410` **SingleChildOwner** — Free a dynamically-allocated child object held at this+0x50 when non-null: invoke the no-op stub EmptyStub_0170 (0x004B0170) and return FreeWrapper_7bcf (0x00587BCF) of the child; the null branch falls through to return an uninitialized result. Existing analysis places this on the SpecialFX_Post cleanup path.

## Proposed classes

### SpatialGridIndex

8x8 proximity grid with a per-axis origin and scale transform, a monotonic tag cursor and an overflow cell: InsertIntoGridCells (0x004BE1D0) converts extents to clamped 0..7 cell indices and appends into each covered cell, GridCellIterate (0x004BE340) visits every cell overlapped by an axis-aligned box and runs the per-cell proximity tag pass, and SpriteGridRender (0x004BE4E0) tags every cell covered by a sprite footprint. All three share the transform fields at +0x924/+0x928 (X) and +0x92C/+0x930 (Y), the tag cursor at +0x934 and the overflow cell at +0x900. GridCellIterate also names the per-cell retag helper ProximityCheckWithTagUpdate (0x004BDA20) and is itself reached from ParticleEffectUpdateDispatch.

Methods: `0x004BE1D0`, `0x004BE340`, `0x004BE4E0`

- `this+0x00000924` `float grid_origin_x` (read, DERIVED)
- `this+0x00000928` `float grid_scale_x` (read, DERIVED)
- `this+0x0000092C` `float grid_origin_y` (read, DERIVED)
- `this+0x00000930` `float grid_scale_y` (read, DERIVED)
- `this+0x00000934` `dword tag_cursor` (read_write, GUESS)

### GridCell

Spatial-grid cell object holding two dynamic child arrays (count at +0x4 / data at +0x8 and count at +0x10 / data at +0x14). ProximityCheckWithTagUpdate (0x004BDA20) walks both arrays and, depending on the uncompiled x87 guard, retags children whose stored tag dword (+4 of the child) differs from the incoming tag, dispatching them through SwitchBasedStateHandler (0x0040F380); the first array additionally requires the child type dword (+0x20) to differ. The cell is the per-cell receiver passed by SpatialGridIndex::GridCellIterate.

Methods: `0x004BDA20`

- `this+0x00000004` `dword child_array1_count` (read, GUESS)
- `this+0x00000008` `uint32 child_array1_data` (read, GUESS)
- `this+0x00000010` `dword child_array2_count` (read, GUESS)
- `this+0x00000014` `uint32 child_array2_data` (read, GUESS)

### AudioMixerChannel

Audio-mixer channel object initialized by running the field-initializer helper F_3FieldInitCall (0x004BD7D0) over 64 consecutive 9-dword sub-structures starting at this, once more at this + 576 dwords, and zeroing the five trailing dwords at byte offsets 0x924..0x934. The 9-dword sub-structure meaning and the owning class are unknown; the 'audio-mixer' label comes from the packet prose.

Methods: `0x004BDB90`

- `this+0x00000924` `dword trailing_field_585` (write, GUESS)
- `this+0x00000928` `dword trailing_field_586` (write, GUESS)
- `this+0x0000092C` `dword trailing_field_587` (write, GUESS)
- `this+0x00000930` `dword trailing_field_588` (write, GUESS)
- `this+0x00000934` `dword trailing_field_589` (write, GUESS)

### AiPerformanceSetupConfig

AI performance/setup configuration struct initialized to defaults by PerformanceSetupStructInitializer (0x004BE700): two enabled byte flags (+0x340, +0x341), one disabled flag (+0x342), four float parameters 1.0/1.0/600.0/10.0 (+0x344/+0x348/+0x34C/+0x350), two zeroed accumulators (+0x354/+0x358), an integer countdown 10 (+0x35C) and a mode identifier 5 (+0x360). The purpose of each parameter depends on the owning struct's role in the AI performance/setup system, which is unidentified.

Methods: `0x004BE700`

- `this+0x00000340` `byte flag_enabled_a` (write, GUESS)
- `this+0x00000341` `byte flag_enabled_b` (write, GUESS)
- `this+0x00000342` `byte flag_disabled_c` (write, GUESS)
- `this+0x00000344` `float param_float_1` (write, GUESS)
- `this+0x00000348` `float param_float_1b` (write, GUESS)
- `this+0x0000034C` `float param_float_600` (write, GUESS)
- `this+0x00000350` `float param_float_10` (write, GUESS)
- `this+0x00000354` `float accumulator_a` (write, GUESS)
- `this+0x00000358` `float accumulator_b` (write, GUESS)
- `this+0x0000035C` `dword countdown_limit` (write, GUESS)
- `this+0x00000360` `dword mode_identifier` (write, GUESS)

### SessionPhaseController

Session-phase transition machinery on the PitStopPhaseAdvance path: TimerCountdownWithStateTransition (0x004C1670) advances a countdown counter (+0xB148) while the timer-active flag (+0xB150) is set, reads the scene-order threshold via SceneOrderReader (0x004C1190) and, when the counter reaches it, sets the session phase (+0xB144) to 3, resets the phase counter (+0xB14C) to 1 and clears the flag. RaceStandingsRankingsComputationThunk (0x004C1660) is a pure forwarding thunk to an out-of-packet standings implementation on the same session path; its receiver may or may not be this same object.

Methods: `0x004C1660`, `0x004C1670`

- `this+0x0000B144` `dword session_phase` (write, GUESS)
- `this+0x0000B148` `dword countdown_counter` (read_write, GUESS)
- `this+0x0000B14C` `dword phase_counter` (write, GUESS)
- `this+0x0000B150` `byte timer_active_flag` (read_write, GUESS)

### PitStopObject

Pit-stop object whose memory resources are released by a dedicated cleanup and whose wrapper allocation is conditionally freed on bit 0 of the destructor flag. PitStopCleanupConditionalFree (0x004C1E20) runs PitStopMemoryCleanup (0x004C0B10), then FreeWrapper_7bcf (0x00587BCF) when (a2 & 1) is set, and always returns the object pointer. No field evidence binds this receiver; the class name is a GUESS label from the packet prose.

Methods: `0x004C1E20`


### DoubleChildOwner

Object owning two child pointers at +0x0 and +0x8 that are conditionally released. ConditionalDestructor (0x004C1E40) frees the +0x8 child when non-zero, then the +0x0 child when non-zero, then the receiver itself when bit 0 of the flag is set, all via FreeWrapper_7bcf (0x00587BCF). Invoked by DoubleListCleanup (0x004C1700); the two-pointer 'double-list' interpretation is inferred from the caller name only.

Methods: `0x004C1E40`

- `this+0x00000000` `uint32 child_a` (read, GUESS)
- `this+0x00000008` `uint32 child_b` (read, GUESS)

### DelegationWrapper

Guarded delegation wrapper on the 0x004C29D0 chain: ConditionalCallWrapper (0x004C29B0) dereferences the receiver's linked list via LinkedListDereference (0x004C2850) and, when a non-null node results, forwards the node and argument a2 to the session config reader named only in the raw source; on the null path it returns the value of an uninitialized local. The reader's identity and address are not evidenced.

Methods: `0x004C29B0`


### SessionScoringObject

Session scoring/statistics object accumulating counters and maintaining clamped running averages. The field-accumulators and counters (0x004C2BE0 accumulates this+0x24, 0x004C2C00 accumulates this+0x30, 0x004C2BF0 increments this+0x28, 0x004C2C20 increments this+0x38) are called from SeasonScoringInfoUpdater (0x004C2A80) and sub_4C29F0 (0x004C29F0); the running-average filters (0x004C2C40 at this+0x44, 0x004C2CB0 at this+0x48, 0x004C2D30 scaled at this+0x4C, 0x004C2DC0 at this+0x50) all use the sample count at this+0x28 (or the counter at this+0x2C) as the weighting denominator and clamp their output via FPU compare-status branches. Grouping is by shared sample-count/counter fields and caller overlap; all packet owners are UNKNOWN, so the common-ownership claim is GUESS.

Methods: `0x004C2BE0`, `0x004C2BF0`, `0x004C2C00`, `0x004C2C20`, `0x004C2C40`, `0x004C2CB0`, `0x004C2D30`, `0x004C2DC0`

- `this+0x00000024` `dword accumulator_24` (read_write, GUESS)
- `this+0x00000028` `dword sample_count` (read_write, GUESS)
- `this+0x0000002C` `dword counter_2C` (read_write, GUESS)
- `this+0x00000030` `dword accumulator_30` (read_write, GUESS)
- `this+0x00000038` `dword counter_38` (read_write, GUESS)
- `this+0x00000044` `float running_average_44` (write, GUESS)
- `this+0x00000048` `float moving_average_48` (write, GUESS)
- `this+0x0000004C` `float scaled_average_4C` (write, GUESS)
- `this+0x00000050` `float incremental_average_50` (write, GUESS)

### OwnedDataLinkedList

Singly linked list whose 12-byte nodes own optional data payloads and whose destructors release node data and nodes then clear the four-slot header at +0x0..+0xC. LinkedListDestructorWithData (0x004C2F20) walks the head at this+0, freeing each flag-set node's value (and its data object) and each node via FreeWrapper_7bcf (0x00587BCF); ListDestructorWithSubFree (0x004C8210) does the same including a sub-free of the data object's first member and calls ArithmeticComparison_8350 (0x004C8350) between two decompiler-duplicated passes. The node layout (data at +0, next at +4, ownership flag byte at +8) is shared by both destructors.

Methods: `0x004C2F20`, `0x004C8210`

- `this+0x00000000` `uint32 head` (read_write, GUESS)
- `this+0x00000004` `dword header_slot_4` (write, GUESS)
- `this+0x00000008` `dword header_slot_8` (write, GUESS)
- `this+0x0000000C` `dword header_slot_C` (write, GUESS)
- `obj+0x00000000` `uint32 node_data` (read, GUESS)
- `*(obj+0x4)+0x00000004` `uint32 node_next` (read, GUESS)
- `obj+0x00000008` `byte node_owns_data` (read, GUESS)

### SceneList

Scene-list container: a primary scene-list pointer at +0x0 plus an owned-data linked list rooted at +0x8. SceneListAndDataCleanup (0x004C4930) releases the primary resources via SceneListCleanup (0x004C4CF0), drains the linked list freeing flag-set data payloads and nodes via FreeWrapper_7bcf (0x00587BCF), zeroes the four list pointers +0x8..+0x14, then frees the primary pointer when non-null. ResetSceneListBuffer (0x004C2FE0) targets the global 6-dword buffer dword_8AC36C (reset to { 0, -1, 0, 0, 0, 0 }) and calls SceneListCleanup; the global-vs-this duality means the two functions may belong to different objects.

Methods: `0x004C2FE0`, `0x004C4930`

- `this+0x00000000` `uint32 primary_list` (read, GUESS)
- `this+0x00000008` `uint32 linked_list_head` (read_write, GUESS)
- `this+0x0000000C` `dword list_slot_C` (write, GUESS)
- `this+0x00000010` `dword list_slot_10` (write, GUESS)
- `this+0x00000014` `dword list_slot_14` (write, GUESS)

### IndexedContainer

Container holding an item count at +0x14 and a bounds-checked current index at +0x18. BoundsCheckedIndexSetter_6760 (0x004C6760) stores the candidate index into +0x18 only when 0 <= a2 < count and returns the candidate unchanged; out-of-range writes are silently dropped. The list the index selects is unidentified.

Methods: `0x004C6760`

- `this+0x00000014` `dword item_count` (read, GUESS)
- `this+0x00000018` `dword current_index` (read_write, GUESS)

### GlobalObjectDispatcher

Guarded virtual dispatch through the global polymorphic object pointer dword_8AC4C4. InvokeVtableSlot4OnGlobalObject (0x004C8D80) invokes vtable slot +16 (index 4) and GuardedVirtualCall (0x004C8DC0) invokes vtable slot +80 (index 20), both thiscall with dword_8AC4C4 as this, and both return the uninitialized result register on the null path. The concrete type and the meaning of the two slots are not evidenced.

Methods: `0x004C8D80`, `0x004C8DC0`


### ParticleEmitter

Particle-emitter object initialized by ParticleEmitterInit (0x004C8F10): interface pointer off_5ACE2C at +0x0, cleared state floats at +0x4/+0x8/+0xC/+0x10, duration at +0x14 (default 1.0 when the argument is non-positive), and a randomized end boundary at +0x18 computed as duration + flt_8AAE74[(byte)dword_8AAE70++] * 1.5. The randomized end boundary's downstream use and the interface role of off_5ACE2C are unknown.

Methods: `0x004C8F10`

- `this+0x00000000` `uint32 interface_ptr` (write, GUESS)
- `this+0x00000004` `float state_float_4` (write, GUESS)
- `this+0x00000008` `float state_float_8` (write, GUESS)
- `this+0x0000000C` `float state_float_C` (write, GUESS)
- `this+0x00000010` `float state_float_10` (write, GUESS)
- `this+0x00000014` `float duration` (read_write, GUESS)
- `this+0x00000018` `float end_boundary` (write, GUESS)

### SessionValidationObject

Session-validation guard object with an enable/state flag at +0x4. ArithmeticComparison_9000 (0x004C9000) returns 1 only when the +0x4 flag is non-zero, the short value computed by ShortComputation_c910 (0x0040C910) from the global at 0x005EA510 is non-zero, and sub_54C0E0 (0x0054C0E0) of that value is non-zero; otherwise returns 0. The meaning of the short value and the check performed by sub_54C0E0 are not established.

Methods: `0x004C9000`

- `this+0x00000004` `dword enable_flag` (read, GUESS)

### SortedFloatKeyRangeSearch

Binary search over a sorted float key array rooted at this[104] with element count in the global dword_5C329C. FindDriversInRange (0x004C9C70) locates the first key within [a2 - a3, a2 + a3], writes the number of in-range elements to *a4 and returns the first in-range key pointer, or null with *a4 = 0. Per-frame rendering/animation callers suggest a spatial-range query role, but the owning object and the key meaning are unknown.

Methods: `0x004C9C70`


### SingleChildOwner

Object holding a dynamically allocated child at +0x50. FreeChild (0x004CA410) invokes the no-op stub EmptyStub_0170 (0x004B0170) and returns FreeWrapper_7bcf (0x00587BCF) of the child when it is non-null; the null branch returns an uninitialized result. Existing analysis names the owner SpecialFXFreeChild on the SpecialFX_Post cleanup path, but that attribution is not adopted here because the packet owner is UNKNOWN.

Methods: `0x004CA410`

- `this+0x00000050` `pointer child_object` (read, GUESS)

## Compatibility contracts

- **SpatialGridTransformContract** — Replacement must preserve the proximity-grid transform: fields +0x924/+0x928 (X origin/scale) and +0x92C/+0x930 (Y origin/scale) convert world coordinates to cell indices via CRTFtol((pos - origin) * scale) clamped to 0..7, and out-of-range positions are routed to the overflow cell rather than dropped.
- **GridCellProximityTaggingContract** — Replacement must preserve that grid cells hold two dynamic child arrays and that children whose stored tag dword (+4) differs from the incoming tag and whose type dword (+0x20) differs from the incoming type are retagged and dispatched through SwitchBasedStateHandler; cell iteration and sprite tagging advance the grid tag cursor at +0x934.
- **SessionPhaseCountdownContract** — Replacement must reproduce the countdown-driven phase transition: while the timer-active flag at +0xB150 is set, the counter at +0xB148 increments each call and, once it reaches the SceneOrderReader threshold, the session phase at +0xB144 is set to 3, the phase counter at +0xB14C reset to 1 and the timer-active flag cleared to 0.
- **OwnedDataReleaseContract** — Replacement must route owned-data frees through a single release routine (FreeWrapper_7bcf at 0x00587BCF): list nodes carry an ownership flag byte at +8 that decides whether the data pointer at +0 is released before the node itself, conditional frees key on bit 0 of the destructor flag, and list destructors clear the four header dwords at +0x0..+0xC after draining.

## Unresolved

- All `this` object owners are UNKNOWN in the packet except SpatialGridIndex (DERIVED for 0x004BE1D0); every other class identity in this proposal is a GUESS-level label for an otherwise unnamed receiver.
- ProximityCheckWithTagUpdate (0x004BDA20): the guards !(v9|v10) and !(v15|v16) read uninitialized locals from the decompiled x87/FPU comparison; the real flag semantics are not evidenced.
- GridCell child layout (tag dword at +4, type dword at +0x20) is on the pointed-to child objects, not on the packet's this fields; only the dword indices are visible.
- The type-field check v7[8] != a3 appears only in the first child-array loop of 0x004BDA20; the second loop omits it, which may or may not be intentional.
- AudioMixerChannelInit (0x004BDB90): the meaning of the 64 repetitions of the 9-dword sub-structure and of the helper F_3FieldInitCall (0x004BD7D0) is unknown; no caller is recorded in the packet so the construction site is unknown.
- The offsets 0x924..0x934 coincide on the SpatialGridIndex class (grid transform + tag cursor) and the AudioMixerChannel class (trailing zeroed dwords). Equal offsets on unrelated this pointers do not prove common ownership; the two classes keep them as separate fields despite the identical receiver offsets.
- InsertIntoGridCells (0x004BE1D0): the meaning of a2[3]/a2[5]/a2[6] (range extents) is inferred from the arithmetic; the element layout of a2 is unproven; the fallback array at this + 576 (byte offset 0x900) is referenced in raw source but has no permitted field evidence ref; the cell geometry (9 floats per cell, 72 floats per row) is inferred from the loop strides only; the relationship to sub_4BDE20 (004bde20) is DERIVED, not confirmed.
- GridCellIterate (0x004BE340): the overflow list base at this+0x900 has no packet field evidence ref; the meaning of the counter/tag at +0x934 (iteration counter vs per-object tag id passed to ProximityCheckWithTagUpdate) is not fully confirmed; the a3 float-array layout (indices 0 and 2 as X/Y centres) and the grid storage layout are inferred.
- SpriteGridRender (0x004BE4E0): the 36-byte cell and 72-dword row-stride geometry is inferred from the loop arithmetic; only a3[0] and a3[2] are read so the position-vector layout is unknown; the purpose of the extra-cell tag at this+0x900 is not named by evidence.
- PerformanceSetupStructInitializer (0x004BE700): the purpose of the float parameters (1.0, 1.0, 600.0, 10.0) and of the integer fields 10 and 5 depends on the unidentified owning struct; the global dword_5ACDAC (0x005ACDAC) is listed as read by the fact table but does not appear in the raw decompiled source.
- RaceStandingsRankingsComputationThunk (0x004C1660): the jump-thunk target is not listed in the packet callees, so its address and implementation are outside this packet; the standings/rankings semantics and the abi LEGACY FAIL are resolved only at the target.
- TimerCountdownWithStateTransition (0x004C1670): the meaning of session-phase value 3 at +0xB144 is unknown and the wider transition is owned by the caller PitStopPhaseAdvance; the return value on the flag-zero path is unspecified; the meaning of SceneOrderReader is unknown.
- PitStopCleanupConditionalFree (0x004C1E20): no caller is recorded in the packet; FreeWrapper_7bcf free-vs-delete semantics are not defined here.
- ConditionalDestructor (0x004C1E40): why the object keeps two child pointers at +0x0 and +0x8 (double-list nodes per the caller name DoubleListCleanup) is inferred, not grounded.
- ConditionalCallWrapper (0x004C29B0): v3 is declared but never assigned, so the null-path return value is indeterminate; SessionConfigReader appears only in the raw source text with no callee evidence ref or address; the meaning of a2 is not documented.
- IncrementFieldAt28 (0x004C2BF0): the packet prelabel (a side-effect-free getter of 0x28) contradicts the raw source, which performs a side-effecting increment and returns void; the packet field entry marks this:0x28 read-only (R) while the raw source performs a read-modify-write.
- AccumulateField30AndReturnInput (0x004C2C00): the semantics of the accumulated field at +0x30 are not evidenced; the structural-twin relationship to ConditionalSetter0x30 (cluster_rep 004980c0) is a prelabel cluster claim only.
- RunningAverageFilter (0x004C2C40): globals flt_59E43C and flt_59E85C are read per the deterministic facts but do not appear as symbols in the raw source; the v6|v7 compare-flag test is a decompiler artifact of an FPU compare.
- MovingAverageFilterWithClamp (0x004C2CB0): the same flt_59E43C/flt_59E85C discrepancy applies; the zero-count guard stores the raw input and then falls through to a division by a non-positive count, so the intended count invariant is not established.
- ScaledRunningAverageWithClamp (0x004C2D30): globals flt_59E6F8 and flt_59E7EC are read per the fact table but absent from the raw source; literal 1084227584 (decoded 5.0f) is applied only on the unordered compare branch, not as a symmetric lower clamp.
- IncrementalRunningAverageWithClamp (0x004C2DC0): globals flt_59E968 and flt_5ACB00 are read per the fact table but absent from the raw source; literal 1116471296 (decoded 64.0f) is applied only on the unordered compare branch.
- The eight session scoring helpers (0x004C2BE0..0x004C2DC0) are grouped into SessionScoringObject by shared sample-count field (+0x28), counter (+0x2C) and caller overlap (0x004C2A80 / 0x004C29F0); all packet owners are UNKNOWN, so common ownership is GUESS, and the four average outputs (+0x44/+0x48/+0x4C/+0x50) may belong to distinct sub-structures.
- LinkedListDestructorWithData (0x004C2F20): the value layout is two-level (node+0 points to a wrapper whose first dword is a heap object) yet no packet evidence defines the wrapper or data structures; the list owner and the meaning of its four cleared dwords are unknown; the prelabel structural twin of ListFullDestruction (004bb650) is DERIVED only.
- ResetSceneListBuffer (0x004C2FE0): SceneListCleanup() has no packet callee entry or address, so its side effects are uncharacterized; the roles of the 6 array entries and the -1 sentinel at index 1 are inferred.
- SceneListAndDataCleanup (0x004C4930): the owner and no caller are recorded; the linked-list node layout is inferred from the raw access pattern; the role of packet guard 0 (this+0x10 == 0) in the control flow is not fully established.
- BoundsCheckedIndexSetter_6760 (0x004C6760): the semantics of the index field at 0x18 (which list it selects) and the count field at 0x14 depend on the unidentified owner; out-of-range writes are silently dropped.
- ListDestructorWithSubFree (0x004C8210): whether the two walk/free passes are a genuine duplicate pass or decompiler loop duplication is unresolved; the identity and purpose of ArithmeticComparison_8350 (0x004C8350) is unknown; the meaning of the flag byte at node+8 is inferred; the prelabel structural twin (004bb4f0) is DERIVED only.
- InvokeVtableSlot4OnGlobalObject (0x004C8D80): the concrete type behind dword_8AC4C4 and the semantics of vtable slot +16 are not evidenced; the null branch returns an uninitialized value.
- GuardedVirtualCall (0x004C8DC0): the vtable slot at byte offset +80 is resolved at runtime; on the null-guard path the function returns an uninitialized EAX; the meaning of argument a1 is caller-defined.
- ParticleEmitterInit (0x004C8F10): globals flt_59E440 and flt_59E8A4 are listed as read by the fact table but do not appear in the raw source; off_5ACE2C is treated as an interface pointer but no virtual dispatch is visible; the semantics of the randomized end boundary (flt_8AAE74 entry * 1.5) and its downstream consumption are unknown.
- ArithmeticComparison_9000 (0x004C9000): the semantic role of the value produced by ShortComputation_c910 (0x0040C910) and of the check performed by sub_54C0E0 (0x0054C0E0) is not established.
- FindDriversInRange (0x004C9C70): the key array rooted at this[104] has no packet field evidence ref (its byte displacement is derived from the source index and not independently evidenced); the sort invariant is assumed from the binary-search pattern; the owning object is unknown.
- FreeChild (0x004CA410): the null branch returns an uninitialized result (a Hex-Rays artifact); the existing SpecialFXFreeChild owner claim on the SpecialFX_Post (0x004CFED0) cleanup phase is DERIVED elsewhere but not adopted here because the packet owner is UNKNOWN.
- 0x004C2FE0 targets the global buffer dword_8AC36C while 0x004C4930 operates on a this object; grouping both into the SceneList class is GUESS and the global-vs-this duality may mean they belong to different objects.
- 0x004C1660 is grouped into SessionPhaseController as a pure forwarding thunk; its receiver and the target of the 0x004C1670 countdown may be different objects despite the shared PitStopPhaseAdvance caller; the grouping is GUESS.
- Proximity grid helper SphereProximityTag (0x004BDB10) is a callee of 0x004BE4E0 but its own behavior and any state it maintains on the grid are not part of this packet.
