# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from twelve validated functions. One DERIVED UI control-window constructor (0x004A70E0) builds a window with ~200 per-sub-control blocks via a uniform block-initializer pattern (GUESS interface ISubControlBlockInitializer). Four GUESS classes cover vehicle physics-body state (0x0045A8E0), fixed-stride element/proximity processing (0x004047D0), a reusable three-field linked node (0x004BAC20), and a session/scoring reset struct (0x004BB950). Seven functions (counted-loop helper 0x00401000, guarded mutex trigger 0x00406640, three getters/accessors, a flag dispatch wrapper, and a null subroutine) have UNKNOWN owners and are kept unowned. No state machine evidence was found. Field semantics and several owner identities remain unresolved; the bulk sub-control-block field offsets are preserved in UIControlWindow's evidence without forcing per-block meaning.

## Function roles

- `0x00401000` **UnknownObject** — Generic counted-loop iteration helper: invokes a caller-supplied __thiscall callback a4 over a3 elements, advancing the element pointer by stride a2 each iteration; returns the last callback result (or a3-1 when count is zero).
- `0x004047D0` **HeightfieldProximityProcessor** — Counted element-loop driver: reads element count from this+0x130, loops calling VehicleProximity (0x004FB2E0) per element of the +0x134 table with a 316-byte stride; invoked from heightfield collision processing (0x00404250).
- `0x00406640` **UnknownObject** — Guarded mutex trigger: compares this+0xC with argument a2; on match acquires a mutex via MutexLockWithTimeout(1) and returns the lock result, otherwise returns the field value unchanged (not a pure getter).
- `0x00406B40` **UnknownObject** — Trivial read-only getter returning the DWORD at this+0x4.
- `0x00406B70` **UnknownObject** — Trivial read-only getter returning the DWORD at this+0x54.
- `0x0045A8E0` **VehiclePhysicsBody** — Vehicle physics body update: writes requested speed limit to +0x24, clamps against +0x1C/+0x20 bounds, runs the velocity/angular-velocity integrator (0x00459AE0) at step 0.0125 when +0xD0 is enabled, computes attitude angles, emits 3D position via 0x0054B4D0, and handles out-of-range/reset paths.
- `0x004636E0` **UnknownObject** — Double-indirected byte accessor: loads the object pointer stored at this+0x0 and returns the BYTE at obj+0x20.
- `0x00464AD0` **UnknownObject** — Byte-offset flag dispatch: forms &this[a2] and forwards it to BitFlagSetter (0x004649F0) to set a single bit; used by the entity visibility grid manager.
- `0x004A70E0` **UIControlWindow** — Constructor of a large UI control window: zeroes the leading callback/state dwords and byte flag, seeds ~200 sub-control blocks with sentinel defaults, vtable pointers from the fixed table 0x005ACB6C..0x005ACBFC, state dword 0 and target/sentinel -1, zeroes tail flags, then applies player-options defaults (0x004AA270).
- `0x004BAC20` **GenericLinkedNode** — Reusable three-field node initializer: stores a2 at this+0x0 (data), nulls this+0x4 (next), stores byte flag a3 at this+0x8; used across directory, collision, physics, AI, and network callers.
- `0x004BB950` **SessionScoringManager** — Session/scoring struct reset: frees owned allocations +0x8C/+0x90/+0x94, counts '1' entries of the +0x94 array into +0x98 before freeing, reinitializes ~40 scalar fields with -1.0/0/-1 defaults, memsets the trailing 0x28-byte block to 0xFF, and returns -1.
- `0x008D903C` **UnknownObject** — Null subroutine: body has no executable statements and returns immediately (IDA nullsub_134 marker; the MK_FP retaddr expression is a decompiler artifact of a bare ret).

## Proposed classes

### UIControlWindow

Large UI control window object: leading callback/state dwords, a ~200-element array of per-sub-control blocks (each holding a vtable header, a state dword reset to 0, and a target/sentinel dword set to -1), tail flags, and player-options defaults; constructed by 0x004A70E0.

Methods: `0x004A70E0`

- `this+0x00000000` `dword callback_state_0` (read_write, GUESS)
- `this+0x00000004` `dword callback_state_1` (read_write, GUESS)
- `this+0x00000008` `dword callback_state_2` (read_write, GUESS)
- `this+0x0000000C` `dword callback_state_3` (read_write, GUESS)
- `this+0x00000010` `byte byte_flag` (write, GUESS)
- `this+0x00000014` `byte late_byte_state` (write, GUESS)
- `this+0x00000114` `dword late_state_dword` (write, GUESS)
- `this+0x00000124` `dword sub_block_vtable_header` (write, GUESS)
- `this+0x00000130` `dword sub_block_state_rep` (write, GUESS)
- `this+0x00000134` `dword sub_block_target_rep` (write, GUESS)
- `this+0x000049A8` `byte tail_byte_flag_0` (write, GUESS)
- `this+0x000049A9` `byte tail_byte_flag_1` (write, GUESS)
- `this+0x000049B0` `dword tail_dword_flag` (write, GUESS)

### VehiclePhysicsBody

Vehicle physics body state: speed-limit storage and clamping, velocity/angular-velocity integration (step 0.0125), attitude-angle computation, 3D position doubles, and conditional reset paths; updated by 0x0045A8E0.

Methods: `0x0045A8E0`

- `this+0x00000000` `void* owned_object_ptr` (read, GUESS)
- `obj+0x00000004` `void* vtable` (read, GUESS)
- `this+0x0000001C` `float speed_bound_a` (read, GUESS)
- `this+0x00000020` `float speed_bound_b` (read_write, GUESS)
- `this+0x00000024` `float requested_speed_limit` (write, GUESS)
- `this+0x000000C0` `dword reset_seed_a` (write, GUESS)
- `this+0x000000C4` `dword reset_seed_b` (write, GUESS)
- `this+0x000000C8` `dword reset_seed_c` (write, GUESS)
- `this+0x000000D0` `dword integration_enabled` (read, GUESS)
- `this+0x000000D8` `double position_x` (read, GUESS)
- `this+0x000000E0` `double position_y` (read, GUESS)
- `this+0x000000E8` `double position_z` (read, GUESS)
- `this+0x000000F0` `double motion_component_0` (read, GUESS)
- `this+0x00000100` `double motion_component_1` (read, GUESS)
- `this+0x00000108` `double motion_component_2` (read, GUESS)
- `this+0x00000110` `double motion_component_3` (read, GUESS)
- `this+0x00000118` `double motion_component_4` (read, GUESS)
- `this+0x00000120` `double motion_component_5` (read, GUESS)
- `this+0x00000130` `double motion_component_6` (read, GUESS)
- `this+0x00000140` `float state_guard` (read, GUESS)

### HeightfieldProximityProcessor

Processes a fixed-stride element table anchored at +0x134 with count at +0x130, driving VehicleProximity (0x004FB2E0) per element; invoked from heightfield collision processing.

Methods: `0x004047D0`

- `this+0x00000130` `dword element_count` (read, GUESS)
- `this+0x00000134` `dword element_table_base` (read, GUESS)

### GenericLinkedNode

Reusable three-field linked node (data dword, next pointer, byte flag) initialized by 0x004BAC20; used as a node constructor across directory, collision, physics, AI, and network subsystems.

Methods: `0x004BAC20`

- `this+0x00000000` `dword data` (write, GUESS)
- `this+0x00000004` `void* next` (write, GUESS)
- `this+0x00000008` `byte flag` (write, GUESS)

### SessionScoringManager

Racing/session scoring management struct: owns three allocations (+0x8C, +0x90, +0x94), a '1'-counted byte array, ~40 scalar/vector fields with -1.0/0/-1 defaults, and a trailing 0x28-byte 0xFF-sentinel block; reset by 0x004BB950.

Methods: `0x004BB950`

- `this+0x00000008` `byte flag_byte` (write, GUESS)
- `this+0x0000000C` `dword mode` (write, GUESS)
- `this+0x00000010` `dword zero_dword` (write, GUESS)
- `this+0x00000014` `float neg_one_float_0` (write, GUESS)
- `this+0x00000018` `float neg_one_float_1` (write, GUESS)
- `this+0x0000001C` `float neg_one_float_2` (write, GUESS)
- `this+0x00000020` `float neg_one_float_3` (write, GUESS)
- `this+0x00000034` `float zero_float_0` (write, GUESS)
- `this+0x00000038` `float zero_float_1` (write, GUESS)
- `this+0x0000003C` `float zero_float_2` (write, GUESS)
- `this+0x00000060` `dword zero_dword_1` (write, GUESS)
- `this+0x00000064` `dword zero_dword_2` (write, GUESS)
- `this+0x00000068` `float[7] neg_one_float_block` (write, GUESS)
- `this+0x0000006C` `float[7] neg_one_float_block` (write, GUESS)
- `this+0x00000070` `float[7] neg_one_float_block` (write, GUESS)
- `this+0x00000074` `float[7] neg_one_float_block` (write, GUESS)
- `this+0x00000078` `float[7] neg_one_float_block` (write, GUESS)
- `this+0x0000007C` `float[7] neg_one_float_block` (write, GUESS)
- `this+0x00000080` `float[7] neg_one_float_block` (write, GUESS)
- `this+0x00000084` `dword zero_dword_3` (write, GUESS)
- `this+0x00000088` `dword zero_dword_4` (write, GUESS)
- `this+0x0000008C` `void* owned_alloc_1` (read_write, GUESS)
- `this+0x00000090` `void* owned_alloc_2` (read_write, GUESS)
- `this+0x00000094` `byte* byte_array_ptr` (read_write, GUESS)
- `this+0x00000098` `dword ones_count` (read_write, GUESS)
- `this+0x0000009C` `dword zero_state_0` (write, GUESS)
- `this+0x000000A0` `dword zero_state_1` (write, GUESS)
- `this+0x000000A8` `byte zero_byte_0` (write, GUESS)
- `this+0x000000AC` `dword zero_state_2` (write, GUESS)
- `this+0x000000B0` `dword zero_state_3` (write, GUESS)
- `this+0x000000B4` `byte zero_byte_1` (write, GUESS)
- `this+0x000000B8` `dword zero_state_4` (write, GUESS)
- `this+0x000000BC` `dword neg_one_index_0` (write, GUESS)
- `this+0x000000C0` `dword neg_one_index_1` (write, GUESS)
- `this+0x000000C4` `dword zero_state_5` (write, GUESS)
- `this+0x000000C8` `dword zero_state_6` (write, GUESS)
- `this+0x000000CC` `dword zero_state_7` (write, GUESS)
- `this+0x000000D0` `dword zero_state_8` (write, GUESS)
- `this+0x000000D4` `byte zero_byte_2` (write, GUESS)
- `this+0x000000D8` `dword neg_one_index_2` (write, GUESS)
- `this+0x000000DC` `dword zero_state_9` (write, GUESS)
- `this+0x000000E0` `byte[0x28] sentinel_block` (write, GUESS)

## Compatibility contracts

- **UIWindowSubControlInit** — Constructing the profile/exists UI window must zero the leading callback/state fields (+0x0..+0x10), seed every sub-control block with sentinel defaults, assign vtable pointers from the fixed table 0x005ACB6C..0x005ACBFC, reset each block's state dword to 0 and target/sentinel to -1, zero the tail flags, and apply player-options defaults (0x004AA270).
- **VehiclePhysicsBodySpeedLimit** — A speed-limit request must be stored at +0x24, clamped against the +0x1C/+0x20 bounds, and, when within bounds and integration enabled (+0xD0), integrated at step 0.0125 and emitted as 3D position (+0xD8/+0xE0/+0xE8) via 0x0054B4D0; out-of-range requests follow the clamp or reset path.
- **SessionScoringStructReset** — Resetting the session/scoring struct must free the +0x8C, +0x90, and +0x94 allocations, count '1' entries of the +0x94 byte array into +0x98 before freeing, restore ~40 scalar fields (floats to -1.0, indexes to 0/-1), memset the trailing 0x28 bytes to 0xFF, and return -1.

## Unresolved

- Owner identity remains UNKNOWN for 0x00401000, 0x00406640, 0x00406B40, 0x00406B70, 0x004636E0, 0x00464AD0, 0x008D903C; no packet evidence constrains their owning classes.
- MutexLockWithTimeout is named in raw source but has no callee address evidence; described from source text only.
- Whether this+0xC in 0x00406640 is a mutex handle/id to compare against, or a state token, is unconfirmed; the DERIVED 'getter / no side effects' prelabel is contradicted by the guarded mutex acquire, so raw source outranks the prelabel.
- 0x004636E0: semantics of the byte at pointed-object +0x20 (flag/state?) are unknown.
- 0x00464AD0: what the single bit flag set at byte offset a2 represents in the entity visibility grid is not known; the 'entity visibility grid manager' usage is stated by the prelabel, not owner evidence.
- 0x004047D0: element stride 316 and base +0x134 imply a packed element table, but element type/size is not confirmed by the packet.
- 0x0045A8E0: double constants dbl_59E420/59E430/59F060/59F068/59F070 are listed as read globals but do not appear in the raw decompiled body (likely consumed inside callees).
- 0x0045A8E0: the FPU comparison flags in the +0x140 guard encode an unordered/NaN comparison whose exact meaning is not resolved; the object behind this+0x0 whose +0x4 is dispatched through the vtable is unidentified.
- 0x004A70E0: per-sub-control-block semantics (0 = inactive state, -1 = no target) are inferred from the recurring init pattern, not confirmed by a live reference; the sub-block struct layout written inside InitWithSentinelValues (0x004A8B10) is callee-internal and not captured here; meaning of the distinct vtable pointers off_5ACB6C..off_5ACBFC is unknown; byte-flag semantics at +0x49A8/+0x49A9 and dword at +0x49B0 are unknown.
- 0x004BAC20: whether this+0x0 holds an integer value or an object pointer is not determinable from raw source; whether callers invoke it as a C++ constructor (this in ECX) versus a plain initializer is unconfirmed; layout beyond this+0x8 is not evidenced.
- 0x004BB950: owner type and field semantics are unknown; callers (Steward_Post 0x004D4600 and several setup readers) suggest a session/scoring management struct; the +0x8C/+0x90/+0x94 allocations are not among the declared fields in the packet but are accessed as pointers in raw source.
- 0x008D903C: true purpose of the null subroutine is unknown; the packet records no callers.
