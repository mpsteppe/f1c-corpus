# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED proposal for 28 generic runtime objects. The strongest groupings are (a) a HighResolutionTimer with a 64-bit timestamp/accumulator layout and QPC/RDTSC mode flag, plus a channel-index accessor over a global channel array; (b) a device-backed resource object that dispatches texture creation and getters through a graphics-device pointer stored at this+0x1100; (c) a texture surface pool using a global buffer-lock manager; (d) generic singly linked lists sharing a node next-pointer at +0x1C; (e) a resource-registry facade over global 0x008B8F2C; and (f) buffered line/token parsers sharing an input-string / working-buffer / token-pointer layout (this+0xC / +0x18C / +0x30C). Owners are UNKNOWN for all functions; classes are conservative groupings with DERIVED fields and GUESS names. Several odd artifacts (global 0xFF00000000005406, global 0x0059E430, unaccessed field 0x10 and 0x3C0/0x3D0/0x3D8) are carried in unresolved rather than laundered into structure.

## Function roles

- `0x00554E90` **GraphicsDeviceBackedResource** — Texture-resource creation: resolves the resource descriptor at *(a2+84), dispatches begin-creation (device vtable +0x48) and final creation (device vtable +0x50) through the device at this+0x1100, maps compressed-format enum values 9..0xD to opaque format constants via jump table 0x00554F6C (uncompressed path delegates to 0x0055C650), sets ready flag 0x8 on *(v3+24), and returns -2/-1/0 by stage.
- `0x005550A0` **GraphicsDeviceBackedResource** — Unconditional getter wrapper: loads the device pointer at this+0x1100, calls its vtable method at +0x88 (stdcall, device pointer as arg), caches the returned integer at this+0x0, and returns it.
- `0x005550C0` **GraphicsDeviceBackedResource** — Unconditional getter dispatch: calls vtable method at byte offset 0x8C on the sub-object at this+0x1100 (sub-object pointer as arg), caches the result at this+0x0, and returns it; shared by sub_553070, sub_553700 and sub_557120.
- `0x00556220` **GenericZeroInitBase** — Shared prefix zero-initializer: calls GlobalZeroInit_c2a0(this) then explicitly zeroes seventeen DWORD fields (0x0 and 0x8 through 0x44); returns this.
- `0x00556440` **HighResolutionTimer** — High-resolution timer reset: samples a fresh timestamp (QueryPerformanceCounter when mode bit 0 at this+0x48 is set, else RDTSC via 0x0055687B), stores it at 0x18/0x1C, snapshots to 0x20/0x24, clears accumulators 0x10/0x14, 0x28/0x2C and previous timestamps 0x30/0x34, and returns the frequency word at this+0x0; body runs only when the timer is initialized.
- `0x00556510` **HighResolutionTimer** — Timer elapsed-time query: computes the delta of a fresh timestamp (via 0x005564B0) against the snapshot at this+0x20/0x24, stores the new timestamp back, and converts ticks to seconds using the frequency word at this+0x0 and the reciprocal scaling factor at this+0x8.
- `0x005565B0` **HighResolutionTimer** — Adjusted elapsed-time query: samples a fresh timestamp (via 0x005564B0), subtracts the reference timestamp at this+0x18/0x1C and the accumulated delta at this+0x28/0x2C, and converts to seconds with a fixed-point divisor built from the frequency word at this+0x0 plus the 0x4 factor and the 0x8 base term; read-only.
- `0x00556650` **HighResolutionTimer** — Reference-delta query: samples a fresh timestamp (via 0x005564B0), subtracts the reference timestamp at this+0x18/0x1C, and converts the tick delta to seconds using the frequency word at this+0x0 and the reciprocal scaling factor at this+0x8; read-only.
- `0x00556730` **AudioChannelTimerIndex** — Bounds-checked per-channel timer query: validates index a1 against the global channel count 0x008B8E48 (returns 0.0 out of range), indexes the per-channel entry &dword_8B6C28[19*a1+608] (19-DWORD stride, 608-DWORD base), and returns GetElapsedTimeSeconds (0x00556510) on that entry.
- `0x005568B0` **FixedTableInitializer** — Fixed 512-iteration constructor walk: seeds the pointer at global table 0x008CBF70, advances 6 dwords (24 bytes) per entry, calls ShortComputation_8e00 (0x00548E00) on each entry, and returns the last call's result.
- `0x00556930` **SceneNodeTree** — Recursive scene-node traversal over the sibling chain: reads the node mask at this+0x38 and breaks when the masked global render-visibility mask (0x008B8E34 combined with the caller mask at a2+0x84) does not cover it; dispatches animation updates via 0x00556980, recurses into children when this+0x44 is set, and follows the next-sibling pointer at this+0x4C until null or the sibling continuation flag at this+0x40 is zero.
- `0x005572B0` **SubResourceArrayOwner** — Clears a per-element flag dword at byte offset 520 (element stride 132 dwords) of each of four sub-resource arrays, each driven by its own count/pointer pair (0x1B4/0x1B8, 0x1C4/0x1C8, 0x1BC/0x1C0, 0x1CC/0x1D0); render/scene cleanup helper.
- `0x00557350` **DefaultsObject** — Constructor/initializer writing literal defaults: zero byte at this+0x0, zero dwords at this+0x20/0x24, three 1.0f floats (0x28/0x2C/0x30), a 100.0f float (0x34), zero dwords at 0x58/0x5C, 0xFFFFFF at 0x60, 65538 at 0x64, 0 at 0x68, 3 at 0x6C, zero bytes at 0x70 and 0x90; returns this.
- `0x00557480` **FlagGuardedDispatcher** — Flag-based dispatcher: tests bit 0x8 at a2+32; set -> call sub_557670(a2), clear -> call sub_557CE0(this, a2); a non-zero callee return yields -1, else 0.
- `0x005575F0` **FlagGuardedDispatcher** — Init-once dispatcher on the flags dword at this+0x20: returns 0 immediately when bit 0x400 is set (already initialized); otherwise bit 0x8 selects Return0Stub (0x0047ABB0) or sub_558310(this); non-zero callee return yields -1, and on success bit 0x400 is OR-ed into the flags and 0 returned.
- `0x00558D10` **TextureSurfacePool** — Lazy texture-buffer allocation: skips when bit 0x100 is already set at this+0x20 (guarded path returns the stored flags), sets bit 0x100, indexes the descriptor table at this[20] (this+0x50) by slot a2<<6 (64-byte stride), selects a 96-byte or 32-byte entry size from flag bit 0x80, allocates through BufferLockAllocate (0x00540F00) on the buffer-lock manager global 0x008B78A0, and stores the returned handle at descriptor+32.
- `0x00558D80` **TextureSurfacePool** — Texture-surface release: when bit 0x100 is set at this+0x20, clears that bit, releases the surface's audio resource via ArithmeticComparison_0f90 (0x00540F90) on the buffer-lock manager global 0x008B78A0 using the descriptor at this+0x50 (64-byte stride) selected by index a2<<6 plus 0x1C, and zeroes descriptor+0x20; otherwise does nothing.
- `0x00559630` **PairKeyedLinkedList** — Search-or-append in a pair-keyed singly linked list: walks the chain rooted at this+0x8 matching node keys +0x14/+0x18 against (a2,a3); on a miss allocates a 32-byte node via 0x00587C03, zero-initializes via 0x00559330, links it at the tail (or head when the list was empty), and sets the keys via StructFieldInit_9390 (0x00559390).
- `0x00559760` **StringKeyedLinkedList** — Linear string search over a singly linked list rooted at this+0x0: compares each node-start string against target a2 via strcmp and returns the first matching node, or 0 when the list is empty or the next pointer (node+0x1C) goes null.
- `0x005597C0` **StringKeyedLinkedList** — Linear string search over a singly linked list rooted at this+0x4: compares each node-start string against key a2 via strcmp, advances through the next pointer at node+0x1C, and returns the matching node or 0 on empty/exhausted lists.
- `0x005599D0` **ResourceRegistryFacade** — Resource-lookup facade over the global registry object 0x008B8F2C: when non-null, delegates (a1,a2,a3) to sub_5594B0 on that object and returns its result; when null, logs the 'Could not find re...' literal 0x005DC1D8 via sub_53C590 and returns -1.
- `0x00559A00` **ResourceRegistryFacade** — Stdcall dispatcher over the global registry object 0x008B8F2C: when non-null, forwards all three arguments to sub_559570 with the global as the leading this-like argument and returns its result; when null, logs the 'Could not find re...' literal 0x005DC1D8 via sub_53C590 with code -1 and returns -1.
- `0x00559A40` **BufferedTextLineReader** — Large-buffer initializer: memsets a 0x180-byte body span starting at this+0xC, zeroes the leading fields at this+0x0/0x4/0x8 and the trailing fields at this+0x30C/0x310, and returns this.
- `0x00559A70` **BufferedTextLineReader** — Line reader: copies bytes from the data buffer at this+0x310 (position this+0x4) into the line buffer at this+0xC until a newline (10) or buffer size this+0x8, sets reader status this+0x0 to 3 on buffer exhaustion, null-terminates the line, and post-processes via sub_559AD0 when the line is non-empty and status is not 3.
- `0x00559D10` **TokenLookupParser** — Prefix tokenizer lookup: copies the string at this+0xC into the working buffer at this+0x18C, tokenizes with the delimiter 0x005C30AC, returns FALSE when no token exists or the token equals key a2 (per 0x00588410); otherwise runs a second tokenizer pass with 0x005EA438 and returns TRUE only on a non-null token; token tracked at this+0x30C.
- `0x00559D80` **TokenLookupParser** — Chain tokenizer lookup: copies the string at this+0xC into the working buffer at this+0x18C, then steps past '.HOT' delimited candidates (delimiter 0x005C32D8, tokens split by 0x005C30AC) seeking the first token not equal to key a2, tracking the current token at this+0x30C; returns FALSE on exhaustion.
- `0x00559F00` **TokenLookupParser** — Parse up to four integers: gates on the sub_559D80 lookup (0 on failure), seeds the parse position from the token pointer at this+0x30C plus one, parses up to four integers via CallWrapperWith0 (0x00589278) into each non-null optional output pointer, and returns the lookup success flag.
- `0x00559FB0` **TokenLookupParser** — Generate up to four uniform floats: gates on the sub_559D80 seeding/validation call (0 on failure), reads and increments the seed at this+0x30C, and for each non-null output pointer draws a uniform float via sub_58B077 (0x0058B077) with an advancing seed state; returns 1 when generation ran.

## Proposed classes

### GraphicsDeviceBackedResource

Resource object that holds a graphics-device sub-object pointer at this+0x1100 and performs texture-resource creation plus cached value getters through that device's vtable.

Methods: `0x00554E90`, `0x005550A0`, `0x005550C0`

- `this+0x00000000` `int32 cached_result` (read_write, DERIVED)
- `this+0x00001100` `GraphicsDeviceInterface* device_ptr` (read, DERIVED)

### HighResolutionTimer

High-resolution timer object: samples timestamps from QPC or RDTSC (mode flag at 0x48), keeps a reference timestamp, snapshot, and accumulators as 64-bit word pairs, and converts tick deltas to seconds using a frequency word and reciprocal scaling factor.

Methods: `0x00556440`, `0x00556510`, `0x005565B0`, `0x00556650`

- `this+0x00000000` `int32 frequency` (read, DERIVED)
- `this+0x00000004` `int32 scale_factor` (read, GUESS)
- `this+0x00000008` `int32 reciprocal_scale` (read, DERIVED)
- `this+0x00000010` `int32 accumulator_low` (write, DERIVED)
- `this+0x00000014` `int32 accumulator_high` (write, DERIVED)
- `this+0x00000018` `int32 current_timestamp_low` (read_write, DERIVED)
- `this+0x0000001C` `int32 current_timestamp_high` (read_write, DERIVED)
- `this+0x00000020` `int32 snapshot_timestamp_low` (read_write, DERIVED)
- `this+0x00000024` `int32 snapshot_timestamp_high` (read_write, DERIVED)
- `this+0x00000028` `int32 delta_accumulator_low` (write, DERIVED)
- `this+0x0000002C` `int32 delta_accumulator_high` (write, DERIVED)
- `this+0x00000030` `int32 previous_timestamp_low` (write, DERIVED)
- `this+0x00000034` `int32 previous_timestamp_high` (write, DERIVED)
- `this+0x00000048` `int32 (bit0 selects QPC) mode_flags` (read, DERIVED)

### AudioChannelTimerIndex

Static, bounds-checked accessor over a global per-channel array; returns the embedded high-resolution timer's elapsed seconds for a valid channel index.

Methods: `0x00556730`


### FixedTableInitializer

Runs a fixed 512-iteration constructor/init pass over a global 512-entry, 24-byte-stride table.

Methods: `0x005568B0`


### SceneNodeTree

Scene node traversal over a sibling-linked node chain with visibility-mask gating, per-node animation dispatch, and child recursion.

Methods: `0x00556930`

- `this+0x00000038` `int32 bitmask node_mask` (read, DERIVED)
- `this+0x00000040` `int32 sibling_continue_flag` (read, DERIVED)
- `this+0x00000044` `int32 children_flag` (read, DERIVED)
- `this+0x0000004C` `pointer next_sibling_ptr` (read, DERIVED)

### SubResourceArrayOwner

Owner of four parallel sub-resource arrays described by count/pointer pairs; clears a per-element flag dword at byte offset 520 in each array.

Methods: `0x005572B0`

- `this+0x000001B4` `int32 array_a_count` (read, DERIVED)
- `this+0x000001B8` `pointer array_a_base` (read, DERIVED)
- `this+0x000001BC` `int32 array_c_count` (read, DERIVED)
- `this+0x000001C0` `pointer array_c_base` (read, DERIVED)
- `this+0x000001C4` `int32 array_b_count` (read, DERIVED)
- `this+0x000001C8` `pointer array_b_base` (read, DERIVED)
- `this+0x000001CC` `int32 array_d_count` (read, DERIVED)
- `this+0x000001D0` `pointer array_d_base` (read, DERIVED)

### DefaultsObject

Object whose initializer writes literal defaults including a 1.0f float triple, a 100.0f float, a white color, a packed flag word, and a count/category.

Methods: `0x00557350`

- `this+0x00000000` `byte type_or_flag_byte` (write, DERIVED)
- `this+0x00000020` `int32 dword_zero_a` (write, DERIVED)
- `this+0x00000024` `int32 dword_zero_b` (write, DERIVED)
- `this+0x00000028` `float (1.0f) default_scale_x` (write, DERIVED)
- `this+0x0000002C` `float (1.0f) default_scale_y` (write, DERIVED)
- `this+0x00000030` `float (1.0f) default_scale_z` (write, DERIVED)
- `this+0x00000034` `float (100.0f) default_length` (write, DERIVED)
- `this+0x00000058` `int32 dword_zero_c` (write, DERIVED)
- `this+0x0000005C` `int32 dword_zero_d` (write, DERIVED)
- `this+0x00000060` `int32 (0xFFFFFF) default_color` (write, DERIVED)
- `this+0x00000064` `int32 (65538) packed_flags` (write, DERIVED)
- `this+0x00000068` `int32 dword_zero_e` (write, DERIVED)
- `this+0x0000006C` `int32 (3) count_or_category` (write, DERIVED)
- `this+0x00000070` `byte flag_byte_a` (write, DERIVED)
- `this+0x00000090` `byte flag_byte_b` (write, DERIVED)

### FlagGuardedDispatcher

Guard-then-dispatch wrappers that select among guarded init/update subroutines based on flag bits, propagate callee failure as -1, and set init-done flags.

Methods: `0x00557480`, `0x005575F0`

- `this+0x00000020` `int32 bitmask (0x8 select, 0x400 init-done) flags` (read_write, DERIVED)

### TextureSurfacePool

Lazily allocates and releases texture-surface buffers through a global buffer-lock manager, tracking allocation state in a flags dword and per-surface handles in a 64-byte-stride descriptor table.

Methods: `0x00558D10`, `0x00558D80`

- `this+0x00000020` `int32 bitmask (0x100 allocated) flags` (read_write, DERIVED)
- `this+0x0000002C` `int32 element_size_multiplier` (read, GUESS)
- `this+0x00000050` `pointer (64-byte stride) descriptor_table_ptr` (read, DERIVED)

### PairKeyedLinkedList

Singly linked list keyed by an integer pair; searches nodes by matching keys and appends a newly allocated 32-byte node on a miss.

Methods: `0x00559630`

- `this+0x00000008` `pointer head_ptr` (read, DERIVED)

### StringKeyedLinkedList

Singly linked list searched linearly by strcmp against the node-start string; nodes carry the next pointer at +0x1C and the two search methods read their list head from different holder offsets (0x0 and 0x4).

Methods: `0x00559760`, `0x005597C0`

- `this+0x00000000` `pointer head_slot_a` (read, GUESS)
- `this+0x00000004` `pointer head_slot_b` (read, GUESS)

### ResourceRegistryFacade

Static facade over a global resource-registry object (0x008B8F2C); delegates lookups through a forward handler or reports the missing-object message and returns -1.

Methods: `0x005599D0`, `0x00559A00`


### BufferedTextLineReader

Buffered reader that zero-initializes a large object, then reads one line at a time from an in-object data buffer into a line buffer, tracking position, buffer size, and a reader status field.

Methods: `0x00559A40`, `0x00559A70`

- `this+0x00000000` `int32 (3 = exhausted) status` (read_write, DERIVED)
- `this+0x00000004` `int32 position` (read_write, DERIVED)
- `this+0x00000008` `int32 buffer_size` (read, DERIVED)
- `this+0x0000000C` `byte[0x180] line_buffer_region` (write, GUESS)
- `this+0x0000030C` `int32 tail_dword_a` (write, DERIVED)
- `this+0x00000310` `pointer data_buffer_ptr` (read, DERIVED)

### TokenLookupParser

Scene/token parser utilities: copies an input string to a working buffer, tokenizes with chain/prefix delimiters, and parses up to four integers or generates up to four uniform floats from the resulting token state.

Methods: `0x00559D10`, `0x00559D80`, `0x00559F00`, `0x00559FB0`

- `this+0x0000000C` `pointer input_string_ptr` (read, DERIVED)
- `this+0x0000018C` `byte array working_buffer` (read_write, DERIVED)
- `this+0x0000030C` `pointer token_ptr` (read_write, DERIVED)

### GenericZeroInitBase

Base zero-initializer that invokes a shared global zero-init helper and then zeroes seventeen DWORD prefix fields (0x0, 0x8 through 0x44).

Methods: `0x00556220`

- `this+0x00000000` `int32 prefix_dword_00` (write, DERIVED)
- `this+0x00000008` `int32 prefix_dword_08` (write, DERIVED)
- `this+0x0000000C` `int32 prefix_dword_0C` (write, DERIVED)
- `this+0x00000010` `int32 prefix_dword_10` (write, DERIVED)
- `this+0x00000014` `int32 prefix_dword_14` (write, DERIVED)
- `this+0x00000018` `int32 prefix_dword_18` (write, DERIVED)
- `this+0x0000001C` `int32 prefix_dword_1C` (write, DERIVED)
- `this+0x00000020` `int32 prefix_dword_20` (write, DERIVED)
- `this+0x00000024` `int32 prefix_dword_24` (write, DERIVED)
- `this+0x00000028` `int32 prefix_dword_28` (write, DERIVED)
- `this+0x0000002C` `int32 prefix_dword_2C` (write, DERIVED)
- `this+0x00000030` `int32 prefix_dword_30` (write, DERIVED)
- `this+0x00000034` `int32 prefix_dword_34` (write, DERIVED)
- `this+0x00000038` `int32 prefix_dword_38` (write, DERIVED)
- `this+0x0000003C` `int32 prefix_dword_3C` (write, DERIVED)
- `this+0x00000040` `int32 prefix_dword_40` (write, DERIVED)
- `this+0x00000044` `int32 prefix_dword_44` (write, DERIVED)

## Compatibility contracts

- **HighResolutionTimerLayout** — A replacement executable must preserve the timer object layout: frequency word at this+0x0, reciprocal scale at this+0x8, accumulators at +0x10/+0x14, current timestamp +0x18/+0x1C, snapshot +0x20/+0x24, delta accumulator +0x28/+0x2C, previous timestamps +0x30/+0x34, and mode flag at +0x48 where bit 0 selects QueryPerformanceCounter vs RDTSC as the timestamp source.
- **DeviceBackedResourceDispatch** — Resource objects must keep the graphics-device pointer at this+0x1100 and route creation/getters through that device's vtable slots +0x48 (begin creation), +0x50 (final creation), +0x88 and +0x8C (getters); results are cached at this+0x0. Slot targets are unresolved.
- **CompressedFormatConstantTable** — Format enum values 9..0xD map through the jump table at 0x00554F6C to the constants 827611204, 844388420, 861165636, 877942852 and 894720068 (interpreted in prior analysis as DXT FourCC codes; that mapping is not proven by this packet).
- **StringListSearchContract** — String-keyed linked-list nodes store the compared string at the node address and the next pointer at node+0x1C; searches compare via strcmp and return the first matching node or 0 when the list is empty or exhausted.
- **TextureSurfacePoolContract** — The surface pool tracks allocation state in bit 0x100 of the flags dword at this+0x20 and manages per-surface descriptors (64-byte stride) under this+0x50; allocation and release go through the global buffer-lock manager 0x008B78A0 (allocate 0x00540F00, release 0x00540F90).
- **ResourceRegistryGlobalContract** — The global registry object at 0x008B8F2C backs resource lookups; when it is null, the lookup facades log the 'Could not find re...' message literal 0x005DC1D8 via 0x0053C590 and return -1.

## Unresolved

- The two graphics-device virtual-dispatch targets (vtable +0x48 begin-create and +0x50 final-create) and the getter slots +0x88/+0x8C are opaque interface methods; their concrete targets are unresolved.
- The 827611204/844388420/861165636/877942852/894720068 constants are interpreted in prior analysis as DXT FourCC codes, but that mapping is not proven by the packet and they are treated here as opaque format constants.
- Global 0xFF00000000005406 is listed by packet facts but does not appear in the raw decompilation of HighResolutionTimerReset; it is likely a mis-extracted constant associated with the RDTSC path and is left unresolved.
- Global 0x0059E430 (dbl_59E430) is listed as read by AudioChannelGetTimerElapsed but does not appear in the raw source text; its role is not established.
- TimerQueryAdjustedElapsedTime reads an unlisted field at this+0x4 (factor) and uses a fixed-point divisor whose exact semantics are inferred rather than documented.
- HighResolutionTimer field 0x10 is listed by packet facts as read-only but never referenced in the decompiled bodies that use other timer fields; its role is unconfirmed.
- Caller sub_554F80 (0x00554F80) of the texture-resource creation routine is not analyzed in this packet.
- The forward handlers sub_5594B0 and sub_559570 are called in raw source but absent from the packet callee lists; their semantics are unknown.
- PairKeyedLinkedList allocation-path return values are Hex-Rays artifacts reading never-initialized registers; only the search-hit path return is well-defined.
- StringKeyedLinkedList reads its list head from this+0x0 in one search and this+0x4 in the other; the two may be distinct holder layouts, so grouping the two functions is provisional.
- Global dword_8B78A0 is carried from prior analysis with the name 'SoundManager' but with no packet evidence; it is treated here only as the buffer-lock manager pointer used by the texture surface pool.
- SceneNodeTree recursion passes a2 rather than a child pointer; the callee's own 'this' must be derived elsewhere.
- InitializeDefaults writes no vtable pointer, so it cannot be determined whether it is a complete constructor or a partial field reset on an already-vtabled object; its callers (named in the packet as MaterialShaderReactionEffectParser and UIListNodeManager) are not in the allowed evidence set.
- TokenLookupParser groups a seeded-float generator (0x00559FB0) with tokenizer/parser utilities on the strength of the shared this+0xC/0x18C/0x30C field layout and the common sub_559D80 gating call; the PRNG semantics are not resolved.
- The channel-count (0x008B8E48) and channel-array (0x008B6C28, 19-DWORD stride, 608-DWORD base) interpretation of AudioChannelTimerIndex is DERIVED from prior analysis and is not independently evidenced.
- LineReaderStatus states other than the exhausted value 3 are unknown; the status field's full enumeration is not evidenced.
- The line buffer capacity at this+0xC in BufferedTextLineReader is not a tracked field; its bound is unknown.
- ClearSubResourceFlags lists fields this+0x3C0, this+0x3D0 and this+0x3D8 in packet facts, but none is accessed in the function body; their roles are unconfirmed.
