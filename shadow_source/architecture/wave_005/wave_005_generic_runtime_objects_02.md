# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from 26 validated functions. Two GUESS vtable-initialized 24-byte objects are constructed by SceneLoadObject (0x0040AC00, installs off_59E678, named VTable_UIObject_59E678 at DERIVED trust) and ModulePathResolverObject (0x0040B560, installs off_59E6AC), each zeroing five dword fields after the vtable. A GUESS camera family covers CameraShakeController (0x0040ADB0), CameraModeManager (0x0040C610, 0x0040C720) and the loader-registry style dispatchers LoaderRegistry (0x0040C890, 0x0040D0B0), plus the ScoringGateConditionCheck timer gate (0x0040C780) shared as a call target. A GUESS state-gated update object (0x0040F130) dispatches on a 0-5 state range with a -1 sentinel branch, and a GUESS circular index buffer (0x00411650) wraps an incrementing index. The text-format slot array (0x00414D70) and the linked-list-embedding destructor (0x00418DF0) are GUESS classes whose field writes are well evidenced. Three name-to-ID lookup functions (0x00415D90, 0x00417640, 0x00417AF0) map driver and team names against fixed global string tables into a shared output record at a1+8/+12/+16. The remaining eleven functions are unowned: generic struct/field initializers, an enum translator, global field selectors, pointer-array teardown, an indexed table lookup, a text-format/struct zero initializer, the finish-position team lookup, an audio-load forwarding wrapper, the state flag query and the empty pfnAPC callback. No defensible state-machine model is proposed; the camera and state dispatches are input/global-driven and their transitions are not evidenced.

## Function roles

- `0x0040AC00` **SceneLoadObject** — Struct constructor/reset: installs the vtable pointer off_59E678 (named VTable_UIObject_59E678 at DERIVED trust) at this+0x0, zeroes the five dword fields this+0x4 through this+0x14, and returns the this pointer. No guard conditions; every write executes unconditionally. Invoked by SceneFileLoadByCurrentIndex (0x0040C240); the object's role in the scene-load path is not established.
- `0x0040ADB0` **CameraShakeController** — Camera shake / collision-reaction step: selects a stride-160 camera entry (index = this+0x14, base = this+0xC), builds a negated reference position, and when the enable flag this+0x4 and the entry flag (byte at entry+0x74, bit 2) allow it, scans the vehicle array (count global:0x005C329C, pointer array global:0x007C54F0) for a vehicle whose squared distance is below 250.0 and whose speed exceeds 35.0. On a hit it derives collision strength (1.0 - dist * 0.0040000002) and calls CollisionResponseWithRandomPerturbation (0x00457A00) after ScoringGateConditionCheck (0x0040C780); on no hit it falls through to StateActivatedPositionSaveRestore (0x00457B00). It then reads the local player vehicle (global:0x007C54E0), dispatches the camera-entry vtable slot +24, processes position/orientation via UtilityFunction_1cd0 (0x00541CD0), converts two angle fields (DualFieldGetter 0x00456060) from degrees to radians (0.01745433) and applies them via sub_542050 (0x00542050), fetches two integer parameters (0x00456080), sets two fields (TwoFieldSetterCall 0x005423C0), and returns ConditionalFloatSetter (0x00542680) of the entry float at +0x48.
- `0x0040B560` **ModulePathResolverObject** — Struct constructor/reset: installs the vtable pointer off_59E6AC (named VTable_59E6AC at DERIVED trust) at this+0x0, zeroes the five dword fields this+0x4 through this+0x14, and returns the this pointer. No guard conditions; every write executes unconditionally. Invoked by ModuleAssetPathResolver (0x0040C3B0); the object's role in module/asset-path resolution is not established.
- `0x0040BDE0` **UnknownObject** — Plain object-field initializer: writes literal defaults into fourteen fields (dwords at +0x0, +0x4, +0x8, +0x18, +0x1C, +0x20, +0x28 and bytes at +0x24, +0x25, +0x2C, +0x2D, +0x2E), with the dword at +0xC set to 2 and the dword at +0x14 set to the unsigned literal 18446744073709551615 (bit pattern of -1, a sentinel); the remaining fields are zeroed. Returns this. No reads, globals, callees or guards.
- `0x0040C540` **UnknownObject** — Finish-position team lookup used by CameraTargetRaceLeader: reads the finish position of entry a1 from the dword-indexed table global:0x005F0738 (stride 4656 per index), derives the target position as v2-1 normally or v2+1 when a2 >= 0, clamps it into [1, global:0x005C329C], scans the active-vehicle pointer table global:0x007C54F0 for the car whose live position field (offset 16480) equals the target, and returns that car's team-ID field (offset 18580). Returns 0 when no matching car is found. The vehicle offsets 16480/18580 carry no field evidence refs in this packet and are unproven.
- `0x0040C610` **CameraModeManager** — Conditional camera-mode dispatch gated by the global queued-mode flag global:0x007CFCC8. Queued path: only a requested mode of 1 passes - it stores 1 into this+0x14 and returns GameActionStateMachine (0x0040CDE0) with first argument 2; anything else returns 1 (blocked). Immediate path: requested modes 1 and 2 pass - the value is stored into this+0x14 and GameActionStateMachine(0, 0) is returned; anything else returns the requested mode this+0xC unchanged. Called from CameraViewAssignment.
- `0x0040C720` **CameraModeManager** — Camera-lock gate: default result 1 (lock allowed). When the occupant identifier at (global:0x007C54F0[global:0x007C54E4] + 18580) differs from that at (global:0x007C54F0[global:0x007C54DC] + 18580), the camera is treated as unlocked: either the call returns 0 (lock denied) when mode a2 equals 3 and the gate flag global:0x007CFE88 is clear while the byte at (global:0x007C54E0 + 13388) is set, or the lock-mode field this+0x14 is set to -1 and 1 is returned. Offsets 18580 and 13388 are unproven.
- `0x0040C780` **UnknownObject** — No-argument function returning a double, used as a per-tick timer source by camera callers: when the gate global:0x008AB6E4 equals 2 it returns fabs(FloatDifference(&dword_8AB6EC)) computed via callee 0x004B9CF0; otherwise it returns the default double global:0x008AFE98. The consumer timer semantics are prose, not packet evidence.
- `0x0040C890` **LoaderRegistry** — Trackside camera-target lookup: when the lookup key a2 is non-zero, queries up to three registered loader objects at this+0x18, this+0x1C and this+0x20, dispatching the virtual slot at vtable+0x1C (28) on each with argument a2, and returns the first non-zero result; otherwise returns 0.
- `0x0040D0B0` **LoaderRegistry** — Mode-dispatched subsystem call: reads the subsystem object at this+0x18; when non-null, calls UtilityFunction_a610 (0x0040A610) with the object and a mode argument selected by a switch on global:0x007CFDC4 (case 1->1, 2->0, 3->3, default->2) via the jump table global:0x0040D0EC; returns the call result, or 0 when the object pointer is null.
- `0x0040DBE0` **UnknownObject** — Thin forwarding wrapper: calls AudioFileLoadDecode (0x00567F40) with the single argument a1 and a constant second argument of 0, returning its result unchanged. No other state is read or written. Invoked by StringPathExtensionManipulation (0x0040DC00).
- `0x0040E6A0` **UnknownObject** — Constructor-style constant initializer: writes seven consecutive float fields - 10.0 (+0x0), 1.0 (+0x4), 1.0 (+0x8), 1.0 (+0xC), 2500.0 (+0x10), 60.0 (+0x14) and 0.7 (+0x18) - and returns the this pointer. Called from ConstructorZeroInitSubCalls (0x004F2430); on the frame path.
- `0x0040F130` **StateGatedUpdateObject** — State-ranged update dispatch: reads the state selector this+0x1C; only states 0-5 reach the update path (jump table global:0x0040F19C), any other value returns the selector unchanged. The update path transforms coordinate data at this+0xC via FloatDoubleCoordinateTransform (0x00459830), then branches on the sentinel this+0x0 == -1: the sentinel path runs NestedLoopCall (0x004BE180), the normal path runs sub_410AF0 (0x00410AF0) and ArithmeticComparison_df90 (0x004BDF90), and both converge on the final processing call sub_4BE010 (0x004BE010) whose result is returned.
- `0x00411650` **CircularIndexBuffer** — Circular buffer index increment with wrap: reads capacity at this+0x0 and the current index at this+0x2; when capacity > 1 increments the index, wraps it to 0 when it reaches capacity, and returns the previous index. When capacity <= 1 the index is left unchanged and 0 is returned. Sole static caller ShortComputation_1a50 (0x00411A50).
- `0x00414010` **UnknownObject** — Enum translation mapper (stdcall): switch on a2 through the jump table global:0x004140E4; cases 1..22 map to the translated literal 113..134 (a2 + 112), write the translated value to the dword at a1+8 and the result of sub_414180(0) (0x00414180) to the dword at a1+12, and return 1. Any other a2 leaves the record untouched and returns -1. Existing analysis suggests a sound-event mapping role (prose, not packet evidence).
- `0x00414160` **UnknownObject** — Pure read-only selector: selector 0 returns the value of global:0x005BF8C8, selector 1 returns global:0x005BF8D0, and any other selector value returns -1. No side effects.
- `0x00414420` **UnknownObject** — Pointer-array resource teardown structurally related to MultiFieldPointerFree (0x00414380, out of scope): resets the text-format struct via TextFormatStructInitializer_4fe0 (0x00414FE0), runs two two-iteration countdown loops that free four pointer slots spaced at a 5-dword stride below the anchors this+23 and this+13 (each slot freed only when non-null via FreeWrapper_7bcf 0x00587BCF), then frees the main pointer field at this+0 when non-null and returns its prior value. Invoked by GlobalListTripleCleanupWithTimerRemoval (0x00414210).
- `0x004144C0` **UnknownObject** — Indexed table read on global:0x005BF9B0: computes the element offset as 5 * a1 and returns the dword at that slot. Read-only; no guards, fields or callees. Called by ShortComputation_1a00 (0x00411A00) and RandomRangeTableInitializer (0x00411AB0).
- `0x00414D70` **TextFormatSlotArray** — Text-format struct reset: before each of eight slot blocks the global string buffer global:0x005EA438 is reinitialized via StringCopyWithBufferRealloc (0x00566650), then each slot block has its two dword fields set to -1 and its byte field cleared to 0. Slots 0 through 7 are written through this (offsets 0x8..0x94); after the this pointer advances 152 bytes a trailing block is written with the same -1/-1/0 pattern. Returns the result of the last StringCopyWithBufferRealloc call.
- `0x00415060` **UnknownObject** — Constructor-style initializer: zeroes the twelve contiguous dword members at this+0x0 through this+0x2C inclusive and returns the this pointer. No reads, globals or callees.
- `0x00415D90` **UnknownObject** — Driver-name to driver-ID lookup: computes v6 = ShortComputation_41a0(a3) (0x004141A0); when v6 >= 0 and the driver-record index a2 >= 0, indexes the per-driver table global:0x008AC394 + 1060*a2, reads the name string at entry+188, and compares it via sub_566810 (0x00566810) against the 39 driver-name globals (0x005C2418..0x005C25A8) with the ID column selected by a3 (0/1) and a5 and the variant by a4. On a match it copies the global name buffer via StringCopyWithBufferRealloc(&byte_5EA438) (0x00566650), writes the matched ID to a1+8, the secondary value to a1+12, clears the byte at a1+16, and returns 0 when v6 > 0 and the matched ID > 0; otherwise returns 1. Called by sub_414600 (0x00414600).
- `0x00417640` **UnknownObject** — Team-name to commentary audio-ID mapper: indexes the team entry array global:0x008AC394 + 1060*a2, reads the team name string at entry+124, and runs sub_566810 (0x00566810) comparisons against the team-name globals (0x005C25B4..0x005C2620). The a3 value (0/1) selects the commentary ID table and a4 the language-variant flag (base or +11): a3==1 yields IDs 425/436 (McLaren) through 432/443 (Minardi), off_5C25E0 433/444, Jaguar 435/446, Benetton 22-(a4!=0), Renault 330-(a4!=0), Stewart 418-(a4!=0), Toyota 454-(a4!=0); a3==0 yields 408/419 through 415/426, off_5C25E0 416/427, Jaguar 418/429, Benetton 460-(a4!=0), Renault 474-(a4!=0), Stewart 480-(a4!=0), Toyota 490-(a4!=0). Computes v5 = ShortComputation_41a0(a3) (0x004141A0); when v5 > 0 and a match was found (v4 > 0), runs StringCopyWithBufferRealloc(&byte_5EA438) (0x00566650), writes v4 to a1+8, v5 to a1+12, clears the flag byte at a1+16 to 0, and returns 0; otherwise returns 1. Called by sub_414A90.
- `0x00417AF0` **UnknownObject** — Structural twin of sub_417640 (0x00417640) mapping F1 team names to a different commentary audio-ID table: same entry array global:0x008AC394 + 1060*a2, team name at entry+124, same sub_566810 (0x00566810) comparison chain. a3==1 yields IDs 121/131 (McLaren) through 130/140 (Jaguar), Renault 328-(a4!=0), Toyota 452-(a4!=0), Benetton 20-(a4!=0), Stewart 416-(a4!=0); a3==0 yields low even IDs 66-(a4!=0) through 84-(a4!=0), Renault 472-(a4!=0), Toyota 488-(a4!=0), Benetton 458-(a4!=0), Stewart 478-(a4!=0). Same success/failure commit pattern (StringCopyWithBufferRealloc 0x00566650, writes at a1+8/+12/+16) and the same caller sub_414A90.
- `0x00418940` **UnknownObject** — Boolean state query: returns true when the object pointer at this+0xAF4 is non-null and its vfunc at vtable+8 (field:*(this+0xAF4):0x00000008) returns non-zero, OR the active slot index at this+0x864 is not -1. Returns false only when the object is null or ready AND the slot index is -1.
- `0x00418DF0` **EmbeddedLinkedListOwner** — Destructor for an object embedding a linked list: calls the pre-cleanup helper sub_4190C0 (0x004190C0) and retains its result, then iterates nodes from the head at this+0x1A0 following the next pointer at node+4; when a node's flag byte at +8 is non-zero and its data pointer at +0 is non-null, frees the data via FreeWrapper_7bcf (0x00587BCF), then frees the node. Zeroes the four list-management fields this+0x1A0..0x1AC and returns the retained sub_4190C0 result.
- `0x0041A160` **UnknownObject** — Empty stdcall callback (pfnAPC): the raw source body is empty (';'); it accepts a ULONG_PTR parameter and returns void immediately. Referenced as a completion/APC-style callback by MemoryAllocationWithBufferRead (0x004080F0) and TrackTemperatureDisplay (0x004D37B0); whether it is an intentional no-op stub or the body failed to be recovered is unknown.

## Proposed classes

### SceneLoadObject

24-byte vtable-initialized object constructed in the scene-load path: vtable pointer at this+0x0 (off_59E678, named VTable_UIObject_59E678 at DERIVED trust) followed by five zeroed dword fields at this+0x4..0x14. One method 0x0040AC00, invoked by SceneFileLoadByCurrentIndex.

Methods: `0x0040AC00`

- `this+0x00000000` `void* vtable_ptr` (read_write, DERIVED)
- `this+0x00000004` `dword zeroed_dword_04` (write, DERIVED)
- `this+0x00000008` `dword zeroed_dword_08` (write, DERIVED)
- `this+0x0000000C` `dword zeroed_dword_0C` (write, DERIVED)
- `this+0x00000010` `dword zeroed_dword_10` (write, DERIVED)
- `this+0x00000014` `dword zeroed_dword_14` (write, DERIVED)

### ModulePathResolverObject

24-byte vtable-initialized object constructed in the module/asset-path resolution path: vtable pointer at this+0x0 (off_59E6AC, named VTable_59E6AC at DERIVED trust) followed by five zeroed dword fields at this+0x4..0x14. One method 0x0040B560, invoked by ModuleAssetPathResolver.

Methods: `0x0040B560`

- `this+0x00000000` `void* vtable_ptr` (read_write, DERIVED)
- `this+0x00000004` `dword zeroed_dword_04` (write, DERIVED)
- `this+0x00000008` `dword zeroed_dword_08` (write, DERIVED)
- `this+0x0000000C` `dword zeroed_dword_0C` (write, DERIVED)
- `this+0x00000010` `dword zeroed_dword_10` (write, DERIVED)
- `this+0x00000014` `dword zeroed_dword_14` (write, DERIVED)

### CameraShakeController

Camera shake / collision-reaction processor object: enable flag at this+0x4, stride-160 camera-entry array base at this+0xC and entry index at this+0x14. Method 0x0040ADB0 scans the vehicle grid for proximity/speed hits, dispatches the camera-entry vtable slot +24, applies position/orientation processing and returns a camera-entry float setter.

Methods: `0x0040ADB0`

- `this+0x00000004` `dword enable_flag` (read, GUESS)
- `this+0x0000000C` `void* camera_entry_array` (read, GUESS)
- `this+0x00000014` `dword camera_entry_index` (read, GUESS)

### CameraModeManager

Camera mode/lock manager: requested mode at this+0xC and the dispatched/lock mode field at this+0x14. Conditional mode dispatch gated by the global queued-mode flag (0x0040C610) and the camera-lock gate (0x0040C720) both write the mode field.

Methods: `0x0040C610`, `0x0040C720`

- `this+0x0000000C` `dword requested_mode` (read, GUESS)
- `this+0x00000014` `dword mode` (read_write, GUESS)

### LoaderRegistry

Registry of three loader/subsystem object pointers at this+0x18, this+0x1C and this+0x20. Trackside camera-target lookup (0x0040C890) dispatches the vtable slot +0x1C on each until one returns non-zero; mode-dispatched subsystem call (0x0040D0B0) dispatches UtilityFunction_a610 on the object at this+0x18 with a mode-selected argument.

Methods: `0x0040C890`, `0x0040D0B0`

- `this+0x00000018` `void* loader_or_subsystem_0` (read, DERIVED)
- `this+0x0000001C` `void* loader_1` (read, DERIVED)
- `this+0x00000020` `void* loader_2` (read, DERIVED)
- `*(this+0x18)+0x0000001C` `void* dispatch_slot_0` (read, DERIVED)
- `*(this+0x1C)+0x0000001C` `void* dispatch_slot_1` (read, DERIVED)
- `*(this+0x20)+0x0000001C` `void* dispatch_slot_2` (read, DERIVED)

### StateGatedUpdateObject

State-gated UI/input-style update object: state selector at this+0x1C (valid states 0-5), coordinate data at this+0xC, and a -1 sentinel flag at this+0x0 that selects the nested-loop path. Method 0x0040F130 dispatches per state and converges on a final processing call.

Methods: `0x0040F130`

- `this+0x00000000` `dword sentinel_flag` (read, GUESS)
- `this+0x0000000C` `float[3] coordinate_data` (read_write, GUESS)
- `this+0x0000001C` `dword state_selector` (read, GUESS)

### CircularIndexBuffer

Circular buffer index holder: capacity dword at this+0x0 and current index (word at this+0x2). Method 0x00411650 increments the index with wrap and returns the previous index.

Methods: `0x00411650`

- `this+0x00000000` `dword capacity` (read, DERIVED)
- `this+0x00000002` `word index` (read_write, DERIVED)

### TextFormatSlotArray

Text-format slot array reset by 0x00414D70: eight slot blocks of (dword, dword, byte) at this+0x8..0x94, each block defaulted to (-1, -1, 0) after the shared string buffer byte_5EA438 is reinitialized; a trailing block with the same pattern is written after the this pointer advances 152 bytes.

Methods: `0x00414D70`

- `this+0x00000008` `dword slot0_primary` (write, DERIVED)
- `this+0x0000000C` `dword slot0_secondary` (write, DERIVED)
- `this+0x00000010` `byte slot0_flag` (write, DERIVED)
- `this+0x00000014` `dword slot1_primary` (write, DERIVED)
- `this+0x00000018` `dword slot1_secondary` (write, DERIVED)
- `this+0x0000001C` `byte slot1_flag` (write, DERIVED)
- `this+0x00000028` `dword slot2_primary` (write, DERIVED)
- `this+0x0000002C` `dword slot2_secondary` (write, DERIVED)
- `this+0x00000030` `byte slot2_flag` (write, DERIVED)
- `this+0x0000003C` `dword slot3_primary` (write, DERIVED)
- `this+0x00000040` `dword slot3_secondary` (write, DERIVED)
- `this+0x00000044` `byte slot3_flag` (write, DERIVED)
- `this+0x00000050` `dword slot4_primary` (write, DERIVED)
- `this+0x00000054` `dword slot4_secondary` (write, DERIVED)
- `this+0x00000058` `byte slot4_flag` (write, DERIVED)
- `this+0x00000064` `dword slot5_primary` (write, DERIVED)
- `this+0x00000068` `dword slot5_secondary` (write, DERIVED)
- `this+0x0000006C` `byte slot5_flag` (write, DERIVED)
- `this+0x00000078` `dword slot6_primary` (write, DERIVED)
- `this+0x0000007C` `dword slot6_secondary` (write, DERIVED)
- `this+0x00000080` `byte slot6_flag` (write, DERIVED)
- `this+0x0000008C` `dword slot7_primary` (write, DERIVED)
- `this+0x00000090` `dword slot7_secondary` (write, DERIVED)
- `this+0x00000094` `byte slot7_flag` (write, DERIVED)

### EmbeddedLinkedListOwner

Object embedding a linked list at this+0x1A0..0x1AC, torn down by the destructor 0x00418DF0: iterates nodes from this+0x1A0 following the next pointer at node+4, conditionally frees each node's data and the node itself, then zeroes the four list-management fields.

Methods: `0x00418DF0`

- `this+0x000001A0` `void* list_head` (read_write, DERIVED)
- `this+0x000001A4` `void* list_cursor` (read_write, DERIVED)
- `this+0x000001A8` `dword list_state` (read_write, DERIVED)
- `this+0x000001AC` `void* list_tail` (write, DERIVED)
- `*(this+0x1A4)+0x00000004` `void* node_next` (read, DERIVED)

## Compatibility contracts

- **VtableInstalledStructInit** — Two constructor-style initializers (0x0040AC00, 0x0040B560) unconditionally install distinct vtable pointers at this+0x0 (off_59E678 / off_59E6AC) and zero the five dword fields at this+0x4..0x14, returning this. A replacement executable must reproduce the vtable install plus the zeroed 20-byte field block for these 24-byte objects.
- **CameraModeGateAndLock** — Camera-mode dispatch is gated by the global queued-mode flag (0x007CFCC8): when set, only mode 1 dispatches (as GameActionStateMachine(2,0)) and everything else is blocked (returns 1); when clear, modes 1 and 2 dispatch and other modes return the requested mode unchanged. The camera-lock check compares the occupant identifiers of the current vs player vehicle slots and denies lock (returns 0) only for mode 3 when byte_7CFE88 is clear and the player-vehicle byte at +13388 is set; otherwise it sets this+0x14 to -1 and allows.
- **DriverNameTableMapping** — Driver-name lookup maps a record name string (per-driver table 0x008AC394 + 1060*a2, name at entry+188) against 39 driver-name globals (0x005C2418..0x005C25A8) via string comparison, with the ID column selected by the name-category index a3, the boolean a4 and the flag a5; on success it writes (matched ID, secondary value, 0) to the output record at a1+8/+12/+16 and returns 0, else returns 1.
- **CommentaryIdTables** — Team-name to commentary audio-ID mapping reads the team name at table entry+124 and matches it against 14 team-name globals (0x005C25B4..0x005C2620); the a3 value selects the ID table (two distinct table families implemented by 0x00417640 and 0x00417AF0) and a4 selects the language variant (base or base+11). The commentary-ID semantics are proposed, not evidenced.
- **ConditionalFreeNonNullGuard** — Pointer teardown frees each slot through the shared free wrapper (0x00587BCF) only when the pointer is non-null and returns the original pointer value; observed in MultiPointerFree (0x00414420) and LinkedListDestructorWithConditionalCleanup (0x00418DF0).

## Unresolved

- SceneLoadObject (0x0040AC00): the concrete class of `this` is unknown; the installed vtable off_59E678 is named VTable_UIObject_59E678 only at DERIVED trust, and the object's role in the SceneFileLoadByCurrentIndex scene-load path is not established.
- ModulePathResolverObject (0x0040B560): the concrete class of `this` is unknown; the installed vtable off_59E6AC is named VTable_59E6AC only at DERIVED trust, and the object's role in module/asset-path resolution is not established.
- CameraShakeController (0x0040ADB0): the stride-160 camera-entry layout (vtable at +0, negated position at +0xC/+0x10/+0x14, flag byte bit at +0x74, float at +0x48) and the vehicle-struct offsets (+88 velocity, +1796/+1800/+1804, +1860/+1864/+1868 position) come from raw source only; field names and types are unproven.
- CameraShakeController (0x0040ADB0): the indirect dispatch at the camera-entry vtable +24 and the callee names are semantic proposals; callee identity is confirmed only by static call/ABI facts.
- CameraShakeController (0x0040ADB0): `result` is returned without initialization when the enable flag this+0x4 is zero (compiler artifact / undefined value).
- CameraShakeController (0x0040ADB0): the globals flt_59E43C, flt_59E65C, flt_59E670, flt_59E6A0, flt_59E6A4, flt_59E6A8 are listed in the packet but are not referenced by the raw source text; their roles are unconfirmed.
- CameraModeManager: the writer and semantics of dword_7CFCC8 (queued-mode flag) are outside this packet; the queued/immediate distinction is DERIVED from its use. The mapping of the stored mode to the first argument of GameActionStateMachine (2 vs 0) and the meaning of its second argument are not grounded.
- CameraModeManager: the occupant-identifier offset 18580, the player-vehicle flag offset 13388, and the gate flag byte_7CFE88 / mode-3 semantics are caller-dependent and not evidenced.
- CameraModeManager vs CameraShakeController: this+0x14 is read as an entry index by 0x0040ADB0 but written as a mode/lock field by 0x0040C610/0x0040C720; common ownership of `this` across the two classes is a GUESS and the exact field semantics are unresolved.
- GetTeamIDByFinishPosition (0x0040C540): dword_5F0738 is a dword-indexed table with a stride of 4656 entries per index; its layout beyond the finish-position value is not in this packet. The vehicle fields at byte offsets 16480 (position) and 18580 (team ID) carry no field evidence refs and their names are inferred. a2 is treated as a direction sign; a wider screen-side bias semantic is not determinable.
- ScoringGateConditionCheck (0x0040C780): the identity and meaning of the data at dword_8AB6EC and why a gate value of exactly 2 selects it are unknown; the default double dbl_8AFE98 meaning is unknown; fabs has no callee evidence ref (inline intrinsic vs resolved call not evidenced); the per-tick timer-consumer semantics are prose.
- TracksideCameraTargetLookup (0x0040C890): the identity and roles of the three loader objects (config/scene/module proposed by prior analysis, not evidenced) are unknown; the virtual method at vtable+28 is dispatched through raw slots with no concrete callee target; the meaning of the lookup key a2 is caller-supplied.
- ModeDispatchedSubsystemCall (0x0040D0B0): the identity of the subsystem object at this+0x18 and the meaning of the mode argument (0-3) and dispatch selector dword_7CFDC4 are unknown.
- AudioFileLoadDecodeWrapper (0x0040DBE0): the meaning of the constant second argument 0 to AudioFileLoadDecode and the contract of a1 depend on callee semantics outside this packet.
- ConstantsStructInit (0x0040E6A0): the object class and the meaning of each constant field (10.0, 1.0, 1.0, 1.0, 2500.0, 60.0, 0.7) are not established.
- StateGatedUpdateObject (0x0040F130): the semantics of the state selector values at this+0x1C beyond the 0-5 range and the meaning of the -1 sentinel state (and how the object gets into it) are not established. Globals dword_5EA560 and dword_8AB710 do not appear in the raw body; they are likely forwarded to one of the callees.
- StructFieldInitializer (0x0040BDE0): the owning object class, the meaning of the value 2 at +0xC and the -1 sentinel at +0x14, and whether +0x24/+0x25/+0x2C/+0x2D/+0x2E are standalone flags or packed fields are unresolved.
- CircularIndexBuffer (0x00411650): the byte offset 0x2 for the index field suggests a packed word layout whose full struct shape is unresolved; capacity is read as a dword at 0x0. Only the single static caller ShortComputation_1a50 (0x00411A50) is known; the buffer owner is unknown.
- EnumValueTranslation (0x00414010): the meaning of the translated range 113..134, the constant 0 argument to sub_414180, and the identity/type of the output record at a1 are unknown. The callers FontCharacterRenderDispatcher (0x00411DB0) and SoundEventDispatcher (0x00411E90) named in prior analysis are not evidenced in this packet.
- GlobalFieldSelectorByIndex (0x00414160): what dword_5BF8C8 and dword_5BF8D0 represent, why non-matching selectors return -1, and whether the two close globals are distinct fields or array elements of one object are unresolved.
- MultiPointerFree (0x00414420): the identity of the five pointer fields is not established (loop slot offsets are dword-slot displacements, not verified byte field offsets); TextFormatStructInitializer_4fe0 is called with no visible arguments, so its target (this vs a global) is unresolved; the prelabel twin MultiFieldPointerFree (0x00414380) shows four loops while this function has only two, so the field sets differ.
- TableLookupByIndex (0x004144C0): the stride-5 record layout of dword_5BF9B0 and the caller-visible meaning of a1 as a lookup key are undefined.
- TextFormatSlotArray (0x00414D70): the owner type and the (dword, dword, byte) slot layout are unconfirmed; the purpose of the global byte_5EA438 path-string reinitialization is unknown; whether the trailing block at effective offsets 160/164/168 belongs to the same slot array is unverified (those offsets are not in the deterministic field list); the -1 sentinel semantics are unknown.
- StructZeroInit (0x00415060): the owning type of the zeroed 12-dword struct is unknown; no caller or vtable evidence is present in the packet.
- DriverNameIDLookup (0x00415D90): the exact meaning of the ID columns (selected by a4) and of the a3/a5 table axes is not documented (2000/2001 driver-set variants are prose); the semantics of sub_566810 and StringCopyWithBufferRealloc and the role of the flt_5EA618 global are only evidenced as packet globals, not from the function body.
- TeamNameToCommentaryIdMapper (0x00417640) / Variant (0x00417AF0): the flt_5EA618 global has no visible use in the raw source; the semantic difference between the a3==0 and a3==1 ID tables (e.g. race vs qualifying commentary set) is not established; whether the team-name strings come from a per-driver or per-team entry depends on the dword_8AC394 array layout and the car-index interpretation.
- StateFlagCheck (0x00418940): the meaning of the vfunc at offset 0x8 of the this+0xAF4 object and of the active slot index at this+0x864 (-1 sentinel) are unknown.
- LinkedListDestructorWithConditionalCleanup (0x00418DF0): the packet guard (field this+0x1A8 == 0) is not visible as an explicit test in the raw pseudocode, whose loop is driven by the node pointer at this+0x1A0; the exact role of the 0x1A8 comparison is ambiguous. sub_4190C0 side effects are out of scope; no static callers exist (entry path is top-level or indirect).
- pfnAPC (0x0041A160): the body is empty in the raw source; whether it is an intentional no-op stub or a failed recovery, and the meaning of Parameter and the callback registration, are unknown.
- No defensible state-machine model is proposed for this scope: the camera-mode, camera-lock and state-gated dispatches are input/global-driven and their transitions are not evidenced in the packet.
