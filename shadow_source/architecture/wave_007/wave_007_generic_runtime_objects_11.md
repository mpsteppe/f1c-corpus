# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 38 validated functions in scope generic_runtime_objects. The most defensible grouping is the GUESS class GlobalDispatcher (0x004C85C0, 0x004C8900, 0x004C8A10): null-guarded thiscall dispatch through the two global object-pointer singletons dword_8AC4C8 (vtable slots at byte offsets 0x14 and 0x28) and dword_8AC4CC (vtable slot at byte offset 0x0C), reached from the file-load retry, UI-loading, sound-entry, render-tick and sound-post paths. Sound and rendering helpers form GUESS single/two-method classes: SoundRenderFadeController (0x004C8830, fields 0x10/0x14/0x18 against the render-fade alpha global flt_7CF380 and the mixer at dword_8AC4C8), SceneNodeHandleForwarder (0x004C8F80, handle at 0x4 and negated-Y position via SceneNodePositionGetter), and SoundObject (0x004C9060, 0x004C9600), two scalar-deleting destructors that install a destructor-stage vtable (off_5ACE3C or off_5ACE5C), run a release body, restore the shared base vtable off_5ACE2C and free via FreeWrapper_7bcf on the a2 bit-0 flag. A GUESS SubObjectHolder (0x004C94D0 three-slot release, 0x004C9960 single-slot release) releases owned sub-objects at this+0x1C..0x24 through vtable slot 0 with final-flag 1. A GUESS StateIndexedObject (0x004C9260 getter, 0x004C92B0 setter) maps a selector at this+0x1C to value slots 0x20/0x24/0x28. The special-effects surface is a GUESS SpecialFX class (0x004C9D10 field init plus the four debug trace hooks 0x004CEE90/0x004CEEC0/0x004CFC90/0x004CFFF0 gated by StringSplitLoop into DebugLogWrite), plus GUESS TreeFreeNode (0x004C9D30 recursive free), GlobalDefaultsBlock (0x004C9B70) and GlobalDataStruct (0x004D0030) global initializers, GUESS SpeedSumSortComparator (0x004C9BA0) and DriverGridSortComparator (0x004D0CF0, 18624-byte driver entries at unk_5F070C), GUESS BestLapSlotTable (0x004D1C40, AIOvertakeDefendStateChange notification), GUESS WarningCooldownGate (0x004D2170, timestamp field 0xB4 and per-vehicle check), GUESS DebugLogFileObject (0x004D5C40/0x004D5C60/0x004D7920/0x004D7940 over globals 0x008AD254/0x008AD258/0x008AD25C), GUESS CallbackRegistrationStub (0x004C9B80/0x004D0040/0x004D5C50/0x004D7930 through BooleanToIntConversion), GUESS StateArrayDispatcher (0x004D47C0/0x004D4800), GUESS RuntimeForwarderStub (0x004D4780/0x004D4790/0x004D4A20/0x004D1027) and GUESS ExternalProcessLauncher (0x004D5885). All class assignments are proposals, never CONFIRMED; the a2 & 1 delete flag and the mixer-value interpretation are DERIVED only.

## Function roles

- `0x004C85C0` **GlobalDispatcher** — Null-guarded indirect dispatch through the global object pointer dword_8AC4C8: when non-null, loads the vtable base, invokes the member at vtable byte offset 0x14 as a __thiscall with dword_8AC4C8 as this, and returns its result; on the null path the uninitialized local result is returned. Called from FileLoadWithRetryLoop (0x004F9B70).
- `0x004C8830` **SoundRenderFadeController** — Conditional render-fade update: only when the this+0x10 enable byte is set, the mixer object at dword_8AC4C8 is non-null, its current value at +4 differs from the render-fade alpha global flt_7CF380 and flt_7CF380 is non-zero, sets this+0x14 (update pending) to 1 and computes this+0x18 as flt_7CF380 (a2 <= 0.0) or flt_7CF380 / a2 (a2 > 0.0); otherwise no write. Called from ConditionalSoundRenderDispatchOnParamCheck (0x00404970).
- `0x004C8900` **GlobalDispatcher** — Guarded indirect dispatch through dword_8AC4C8: when non-null, calls the vtable entry at byte offset 0x1C (28) with the object as this and argument a1, returning the result; a null global short-circuits to the uninitialized local. Reached from UILoadingPercentDisplay (0x0047C860) and Sound_Enter (0x004C8A20), so the same global object serves UI and audio paths.
- `0x004C8A10` **GlobalDispatcher** — Null-guarded indirect dispatch through the second global object pointer dword_8AC4CC: when non-null, invokes the member at vtable byte offset 0x0C as a __thiscall with dword_8AC4CC as this, returning the result; null path yields the uninitialized local. Called from RenderTickUpdate (0x004C8B70) and Sound_Post (0x004C8CA0).
- `0x004C8F80` **SceneNodeHandleForwarder** — Scene-node position forwarder: stores the handle argument at this+0x4, fills the scene-node position X/Y/Z into this+0x8/+0xC/+0x10 via SceneNodePositionGetter (0x0054B950), negates the Y component (this+0xC), then dispatches the virtual method at vtable+4 on this and returns its result; returns 1 immediately when the handle is null. Reached from 0x004C7CA0.
- `0x004C9060` **SoundObject** — Sound-object destructor: installs the destructor-stage vtable off_5ACE3C, runs the three-stage release chain TripleVTableDestructorRelease (0x004C91D0), restores the base vtable off_5ACE2C, frees this via FreeWrapper_7bcf only when a2 bit 0 is set, and returns this.
- `0x004C9260` **StateIndexedObject** — Indexed field selector: reads the selector at this+0x1C and returns this+0x20 (selector 0), this+0x24 (selector 1), this+0x28 (selector 2), or 0 for any other value; read-only. Called by EqualityStateCheck (0x004C9280) and ObjectPropertySetter (0x004C92B0), consistent with a state-keyed field accessor.
- `0x004C92B0` **StateIndexedObject** — Indexed property setter: stores a2 into the selector at this+0x1C, resolves the selected object via StateIndexedFieldGetter (0x004C9260); when non-null, zeroes a local 3-dword buffer and dispatches an indirect thiscall through the selected object's vtable slot +4 with arguments (object, 2, v4+8, zeroed buffer, a3, 1065353216, 1), returning its result; a null object returns immediately.
- `0x004C94D0` **SubObjectHolder** — Three-slot sub-object release: for each non-null dword slot in the run this+0x1C..0x24, dispatches the sub-object's vtable slot 0 (Release) via __thiscall with final-flag argument 1, then nulls the slot so it is not released twice; returns the last Release result. Part of an object-teardown destructor path.
- `0x004C9600` **SoundObject** — Vtable-switch destructor: writes the destructor-stage vtable pointer off_5ACE5C to this+0x0, runs the destructor body VtableDestructorNull (0x004C9790), restores the base vtable off_5ACE2C, then frees this via FreeWrapper_7bcf when a2 bit 0 is set; returns this. No static caller recorded.
- `0x004C9960` **SubObjectHolder** — Single owned-object release: loads the handle at this+0x1C; when non-null invokes its vtable entry 0 with argument 1, clears this+0x1C and returns the call result; a null handle returns the uninitialized local. Prior skeleton analysis (DERIVED only) reads this as StopAndReleaseOwnedObject.
- `0x004C9B70` **GlobalDefaultsBlock** — Global defaults-block initializer: zeroes the thirteen leading 32-bit fields of the block at dword_8ACEA0, then writes 1.0 to flt_8ACED0, 0.80000001 to flt_8ACED4 and -1 to dword_8ACED8; returns the block base address dword_8ACEA0. No callers recorded in the packet.
- `0x004C9B80` **CallbackRegistrationStub** — Thin registration stub: returns BooleanToIntConversion((int)NullsubWrapperForRenderObject@0x004C9B90), i.e. converts the routine address to an integer boolean. No callers recorded; the registration target and callback semantics are unknown.
- `0x004C9BA0` **SpeedSumSortComparator** — qsort-style comparator over an array of object pointers: each argument points to an object pointer; sums the floats at obj+0x738 and obj+0x740 for both operands and returns 1 / 0 / -1 by the larger total. No static caller; invoked indirectly (e.g. via qsort).
- `0x004C9D10` **SpecialFX** — Special-FX field initializer: writes -1.0f (sentinel/inactive) to this+0x20 and 0 to this+0x24, then returns the object pointer unchanged; invoked during special-FX setup.
- `0x004C9D30` **TreeFreeNode** — Recursive tree teardown: reads the child pointer at this+0x24; when non-null recurses into the child subtree then frees the child node via FreeWrapper_7bcf; the null-child path returns the uninitialized decompiler result.
- `0x004CEE90` **SpecialFX** — Special-FX debug entry hook: calls StringSplitLoop(2, source-path string, 2798) and, when its low byte is non-zero, writes the 'entered special' message into the debug-log buffer dword_8AD25C via DebugLogWrite (0x004D7AA0); otherwise returns the split-loop result unchanged. Called from Game_Enter (0x0042D370). Packet owner trust DERIVED.
- `0x004CEEC0` **SpecialFX** — Special-FX debug entry hook (setup variant): StringSplitLoop(2, source-path string, line 2804) gates a DebugLogWrite of the entered-special message into dword_8AD25C; returns the split-loop result when the gate is false.
- `0x004CFC90` **SpecialFX** — Special-FX debug entry hook (restart variant): StringSplitLoop(2, source-path string, line 3295) gates a DebugLogWrite of the entered-special message into dword_8AD25C; returns the split-loop result when the gate is false.
- `0x004CFFF0` **SpecialFX** — Special-FX debug entry hook (exit variant): StringSplitLoop(2, source-path string, line 3408) gates a DebugLogWrite of the entered-special message into dword_8AD25C; returns the split-loop result when the gate is false.
- `0x004D0030` **GlobalDataStruct** — Global data-struct initialization and reset: initializes the struct at dword_8ACEE0, zeroes a run of adjacent control globals, installs sentinel defaults (dword_8ACF8C = 0x7FFFFFFF, flt_8ACF9C = 1.0, unk_8ACF98 = 1172373504), fills 0x68 bytes at byte_8AD008 with 0xFF, sets unk_8AD070/unk_8AD072 to -1, and clears 104 consecutive dwords via a 52-iteration double-store loop; returns the global struct pointer dword_8ACEE0.
- `0x004D0040` **CallbackRegistrationStub** — Thin registration stub: returns BooleanToIntConversion((int)dword_4D0050), converting the global's value to an integer boolean. No callers recorded; the registration target and the meaning of the conversion are unknown.
- `0x004D0CF0` **DriverGridSortComparator** — qsort-style driver-grid comparator over the per-driver entry array based at unk_5F070C (stride 18624): entries with status dword 3 (retired marker) sort last; among non-3 entries a primary rank dword is compared, then the status-1 (racing) subgroup compares a float time while other statuses compare a secondary rank dword and a float time; a shared tiebreak dword and a final pointer-order fallback settle remaining ties; returns -1/0/1.
- `0x004D1027` **RuntimeForwarderStub** — Minimal thiscall setter: stores argument a2 into this+0x0 and returns a2. Structurally identical to FloatClamp (0x004646C0) per the DERIVED cluster-copy prelabel, but the stored field type and owning class are unproven.
- `0x004D1C40` **BestLapSlotTable** — Best-lap slot-owner update: this is a byte array whose element this[a2+400] records which driver currently owns slot a2; a non-zero force flag a4 bypasses the comparison and installs a3 directly; otherwise ownership changes when the current owner is out of range (>= dword_5C329C) or the new driver's lap time (flt_5F0774[a2 + 4656*a3]) is valid and no worse than the current owner's time. On takeover, notifies AIOvertakeDefendStateChange (0x00419690) with the game-state pointer dword_5EB978, the slot, the new and old drivers, then writes the new owner and returns 1; otherwise 0. Called from the LapCompletion path (0x004BC4E0).
- `0x004D2170` **WarningCooldownGate** — Readiness gate: returns 1 when the stored trigger timestamp this+0xB4 plus 30.0 is <= session time dbl_8AFEA0 AND every vehicle in the array at dword_7C54F0 (count bounded by dword_5C329C) passes the per-vehicle check sub_4BC9B0 (0x004BC9B0) at base+16436; an empty field (count <= 0) trivially returns 1; returns 0 when the cooldown has not elapsed or any vehicle fails. Called from 0x004D4580.
- `0x004D4780` **RuntimeForwarderStub** — Thin __thiscall forwarder: invokes sub_587DB0 (0x00587DB0) with the instance pointer this and the constant aRb at 0x005BE828 as arguments, returning the callee's result unchanged.
- `0x004D4790` **RuntimeForwarderStub** — Trivial thiscall delegation: passes the receiver this directly to FileCloseWithLock (0x00587D02) and returns that call's result unchanged; the wrapper contributes no logic of its own.
- `0x004D47C0` **StateArrayDispatcher** — Thin __fastcall pass-through: calls sub_587F64 (0x00587F64) with all three arguments (a1, a2, a3) forwarded unchanged and returns the callee's result. Called by StateGetSetWrapper (0x004D4800), placing it in that wrapper's get/set dispatch path.
- `0x004D4800` **StateArrayDispatcher** — State read/modify wrapper: reads the array state via ArrayStateRead (0x004D47E0), delegates once with a fixed mode of 2, re-reads the array state, delegates a second time passing the first read value with a mode of 0, then returns the re-read value.
- `0x004D4A20` **RuntimeForwarderStub** — Thin wrapper with a single side effect: zeroes the global dword_8AD238, then calls StructFieldInitializer_4a58 with the address of that global and returns its result. The callee is named only in the raw source (no address in the packet).
- `0x004D5885` **ExternalProcessLauncher** — External process launcher: builds a command line as '"<exe>" <args>' into a 256-char buffer via StringFormatWithBufferOverflowCheck (0x0058815F) with the format string at 0x005D45B8, taking the executable from dword_7CEA18 (fallback byte_5EA438) and the argument from a1 (fallback byte_5EA438); zeroes a STARTUPINFOA (cb = 68) and calls CreateProcessA through the IAT slot at 0x0059E0D0 with creation flag 0x20 (CREATE_NO_WINDOW), returning the BOOL result.
- `0x004D5C40` **DebugLogFileObject** — Trivial reset routine: zeroes the two adjacent module globals dword_8AD254 and dword_8AD258 and returns 0; no arguments, calls, or branches.
- `0x004D5C50` **CallbackRegistrationStub** — Single-thunk registration stub: reads the GlobalQueryWrapper value at 0x004D5C60, casts it to int and passes it to BooleanToIntConversion (0x00587B3E), returning the conversion result directly.
- `0x004D5C60` **DebugLogFileObject** — Thin pass-through wrapper: calls TextureSurfaceDestroyer with the address of the global dword_8AD254 and returns the result directly. The callee is named only in the raw source; no destruction behavior is observable in this function itself.
- `0x004D7920` **DebugLogFileObject** — Thin pass-through wrapper: calls DualFieldZeroInit with the address of the global dword_8AD25C and returns the result directly. The callee is named only in the raw source; no zeroing behavior is observable in this function itself.
- `0x004D7930` **CallbackRegistrationStub** — Callback-to-boolean stub: returns BooleanToIntConversion((int)sub_4D7940), converting the callback address to an integer boolean (effectively 1 for a valid function address); any real unregistration side effect is not visible in this function.
- `0x004D7940` **DebugLogFileObject** — Conditional file-handle close callback: reads the second dword element dword_8AD25C[1]; when non-zero treats it as a file handle and passes it to FileCloseWithLock (0x00587D02), returning its result; when the value is zero returns 0 without calling.

## Proposed classes

### GlobalDispatcher

Null-guarded indirect thiscall dispatch through two global object-pointer singletons: dword_8AC4C8 (vtable slots at byte offsets 0x14 and 0x1C) reached from the file-load retry path (0x004F9B70), UI-loading (0x0047C860) and sound-entry (0x004C8A20) paths, and dword_8AC4CC (vtable slot at byte offset 0x0C) reached from the render-tick (0x004C8B70) and sound-post (0x004C8CA0) paths. The dispatch targets are unknown and the two globals may reference the same or different objects; only the guarded indirection is asserted. No instance fields are evidenced beyond the globals.

Methods: `0x004C85C0`, `0x004C8900`, `0x004C8A10`


### SoundRenderFadeController

Conditional render-fade update driven by the audio-mixer object at dword_8AC4C8 and the global render-fade alpha flt_7CF380: requires the enable byte at this+0x10, sets the update-pending flag at this+0x14, and computes the fade target float at this+0x18 as flt_7CF380 or flt_7CF380 divided by the a2 divisor. The meaning of *(dword_8AC4C8+4) as the mixer's current fade value is DERIVED from the comparison, not proven.

Methods: `0x004C8830`

- `this+0x00000010` `byte enableFlag` (read, GUESS)
- `this+0x00000014` `dword updatePendingFlag` (write, GUESS)
- `this+0x00000018` `float computedFadeTarget` (write, GUESS)

### SceneNodeHandleForwarder

Stores a scene-node handle at this+0x4, fills the scene-node position floats at this+0x8/+0xC/+0x10 via SceneNodePositionGetter (0x0054B950), negates the Y component at this+0xC, then dispatches the virtual method at vtable+4 and returns its result; a null handle returns 1 immediately. The purpose of the negated Y before dispatch is unclear.

Methods: `0x004C8F80`

- `this+0x00000000` `void* vtablePointer` (read, GUESS)
- `this+0x00000004` `void* sceneNodeHandle` (write, GUESS)
- `this+0x0000000C` `float scenePositionY` (write, GUESS)
- `this+0x00000010` `float scenePositionZ` (write, GUESS)

### SoundObject

Sound-object destructor family: both scalar-deleting destructors install a destructor-stage vtable (off_5ACE3C for 0x004C9060, off_5ACE5C for 0x004C9600), run a release/destructor body (TripleVTableDestructorRelease 0x004C91D0 or VtableDestructorNull 0x004C9790), restore the shared base vtable off_5ACE2C, and free this via FreeWrapper_7bcf when the a2 bit-0 delete flag is set; both return this. Two variants share the base vtable constant; the object layout beyond the vtable pointer is not merged.

Methods: `0x004C9060`, `0x004C9600`

- `this+0x00000000` `void* vtablePointer` (write, GUESS)

### SubObjectHolder

Owns up to three releaseable sub-objects in the dword run this+0x1C..0x24. ReleaseTripleSubObjects (0x004C94D0) releases all three non-null slots via their vtable slot 0 with final-flag 1 and nulls each slot; ShortComputation_9960 (0x004C9960) releases the single slot at this+0x1C via vtable slot 0 with argument 1 and nulls it. Sub-object identity and the meaning of the Release argument are unknown.

Methods: `0x004C94D0`, `0x004C9960`

- `this+0x0000001C` `void* subObjectSlot0` (read_write, GUESS)
- `this+0x00000020` `void* subObjectSlot1` (read_write, GUESS)
- `this+0x00000024` `void* subObjectSlot2` (read_write, GUESS)
- `*(this+0x1C)+0x00000000` `vtable_method subObjectVtableSlot0` (read, GUESS)
- `*(*(this+0x1C)+0x0)+0x00000000` `void* releaseTargetPointer` (read, GUESS)

### StateIndexedObject

Small state-keyed object: the selector at this+0x1C indexes three value slots (this+0x20/0x24/0x28). The getter (0x004C9260) returns the selected slot (0 for out of range); the setter (0x004C92B0) writes the selector, resolves the selected object through the getter and, when non-null, dispatches an indirect thiscall through its vtable slot +4 with a fixed 7-argument signature including the literal 1065353216. The meaning of the three slots and the dispatch semantics are unproven.

Methods: `0x004C9260`, `0x004C92B0`

- `this+0x0000001C` `dword selectorIndex` (read_write, GUESS)
- `this+0x00000020` `void* valueSlot0` (read, GUESS)
- `this+0x00000024` `void* valueSlot1` (read, GUESS)
- `this+0x00000028` `void* valueSlot2` (read, GUESS)

### SpecialFX

Special-effects subsystem surface: the field initializer (0x004C9D10) writes a -1.0f inactive sentinel to this+0x20 and 0 to this+0x24; the four entry hooks (Enter/Setup/Restart/Exit, lines 2798/2804/3295/3408) gate a debug trace through StringSplitLoop (0x004D7A50) and write an 'entered special' message into the debug-log buffer dword_8AD25C via DebugLogWrite (0x004D7AA0), returning the split-loop result when the gate is false. The owner is DERIVED for the Enter hook only (SpecialFX); the class grouping as a whole is GUESS.

Methods: `0x004C9D10`, `0x004CEE90`, `0x004CEEC0`, `0x004CFC90`, `0x004CFFF0`

- `this+0x00000020` `float inactiveSentinel` (write, GUESS)
- `this+0x00000024` `dword stateOrCounter` (write, GUESS)

### TreeFreeNode

Recursive tree teardown node: reads the child pointer at this+0x24 and, when non-null, recurses into the child subtree first then frees the child node via FreeWrapper_7bcf. Node layout beyond the child pointer is not evidenced; the null-path return value is an uninitialized decompiler artifact.

Methods: `0x004C9D30`

- `this+0x00000024` `void* childNode` (read, GUESS)

### GlobalDefaultsBlock

Initializes a global defaults block based at dword_8ACEA0: zeroes the thirteen leading 32-bit fields and installs sentinel values (1.0, 0.80000001, -1). The block's semantic identity and its consumer are unknown; no callers are recorded.

Methods: `0x004C9B70`


### GlobalDataStruct

Initializes the global data struct at dword_8ACEE0 and resets a large block of adjacent control globals: sentinel defaults (dword_8ACF8C = 0x7FFFFFFF, flt_8ACF9C = 1.0, unk_8ACF98 = 1172373504), a 0xFF-filled 0x68-byte block at byte_8AD008, -1 sentinels at unk_8AD070/unk_8AD072, and a trailing 104-dword clear. The semantic roles of the reset globals are unknown.

Methods: `0x004D0030`


### CallbackRegistrationStub

Thin stubs that funnel a single value (a routine address such as NullsubWrapperForRenderObject@0x004C9B90 or sub_4D7940, or a global value such as dword_4D0050) through BooleanToIntConversion (0x00587B3E) and return the boolean result. Likely compiler-generated registration/teardown callbacks; the registration target and the meaning of the converted value are unknown.

Methods: `0x004C9B80`, `0x004D0040`, `0x004D5C50`, `0x004D7930`


### SpeedSumSortComparator

qsort-style comparator: each argument points to an object pointer; the comparator sums the floats at obj+0x738 and obj+0x740 for both operands and returns -1/0/1 ordering by the larger total speed sum. The meaning of the two summed fields is not established; 'speed' is a legacy naming hint, not evidence.

Methods: `0x004C9BA0`

- `obj+0x00000738` `float speedComponentA` (read, GUESS)
- `obj+0x00000740` `float speedComponentB` (read, GUESS)

### DriverGridSortComparator

qsort-style comparator over per-driver entries based at unk_5F070C with stride 18624: entries with status 3 (retired) sort last; non-3 entries compare a primary rank, then the status-1 (racing) subgroup compares a float time while other statuses compare a secondary rank and a float time; a shared tiebreak dword and a pointer-order fallback settle ties. Entry-internal offsets (status 0x30, rank 0x08, secondary 0x0C, time 0x10, tiebreak 0x2C, racing time 0x84) are described in the packet but not evidenced as allowed field refs, so they are not asserted as class fields.

Methods: `0x004D0CF0`

- `this+0x00000000` `byte* driverIndexArgument` (read, GUESS)

### BestLapSlotTable

Per-slot best-lap-time ownership bookkeeping: this is a byte array whose element this[a2+400] records the current owner of slot a2; lap times come from the float table flt_5F0774 at stride 4656, the vehicle count from dword_5C329C, and on takeover AIOvertakeDefendStateChange (0x00419690) is notified with the game-state pointer dword_5EB978, the slot, and the new and old drivers. Invoked from the LapCompletion path (0x004BC4E0).

Methods: `0x004D1C40`


### WarningCooldownGate

Readiness gate: returns 1 when the stored last-trigger timestamp at this+0xB4 plus 30.0 is <= the session time dbl_8AFEA0 and every vehicle in the array at dword_7C54F0 (count bounded by dword_5C329C) passes the per-vehicle check sub_4BC9B0 (0x004BC9B0) at base+16436; an empty field trivially returns 1. Called from 0x004D4580; the consumed result at that call site is outside this packet.

Methods: `0x004D2170`

- `this+0x000000B4` `float lastTriggerTimestamp` (read, GUESS)

### DebugLogFileObject

Module debug-log/file state centered on the adjacent globals dword_8AD254, dword_8AD258 and dword_8AD25C: a reset routine (0x004D5C40) zeroes the first two, a wrapper (0x004D5C60) passes &dword_8AD254 to TextureSurfaceDestroyer, another wrapper (0x004D7920) passes &dword_8AD25C to DualFieldZeroInit, and a callback (0x004D7940) closes the file handle stored at dword_8AD25C[1] via FileCloseWithLock (0x00587D02). dword_8AD25C also serves as the debug-log message buffer written by DebugLogWrite from the SpecialFX hooks. The callees TextureSurfaceDestroyer and DualFieldZeroInit are name-only in the packet.

Methods: `0x004D5C40`, `0x004D5C60`, `0x004D7920`, `0x004D7940`


### StateArrayDispatcher

Array-state get/set dispatch: StateGetSetWrapper (0x004D4800) reads array state via ArrayStateRead (0x004D47E0), delegates once with a fixed mode of 2, re-reads the state, then delegates again passing the first read value with mode 0 and returns the re-read value; Delegation_47c0 (0x004D47C0) is the pass-through to sub_587F64 (0x00587F64). The mode constants 0/2 and the array-state object are unidentified.

Methods: `0x004D47C0`, `0x004D4800`


### RuntimeForwarderStub

Thin pass-through wrappers and minimal setters contributing no logic of their own: 0x004D4780 forwards (this, constant aRb at 0x005BE828) to sub_587DB0 (0x00587DB0); 0x004D4790 delegates this to FileCloseWithLock (0x00587D02); 0x004D4A20 zeroes dword_8AD238 then passes its address to StructFieldInitializer_4a58 (name-only callee); 0x004D1027 stores its argument into this+0x0 and returns it. Owning classes and callee contracts are unknown.

Methods: `0x004D4780`, `0x004D4790`, `0x004D4A20`, `0x004D1027`

- `this+0x00000000` `dword storedValue` (write, GUESS)

### ExternalProcessLauncher

External process launcher: formats a command line as '"<exe>" <args>' into a 256-char buffer via StringFormatWithBufferOverflowCheck (0x0058815F) with the format string at 0x005D45B8, executable from dword_7CEA18 (fallback byte_5EA438) and argument from a1 (fallback byte_5EA438), then launches via CreateProcessA through the IAT slot at 0x0059E0D0 with a zeroed STARTUPINFOA (cb = 68) and creation flag 0x20 (CREATE_NO_WINDOW), returning the BOOL result. The ProcessInformation structure is populated but not consumed here.

Methods: `0x004D5885`


## Compatibility contracts

- **GlobalDispatchSingletonGlobals** — dword_8AC4C8 and dword_8AC4CC are global object-pointer singletons dispatched through vtable slots 0x14/0x1C (8AC4C8) and 0x0C (8AC4CC) with a null guard; callers FileLoadWithRetryLoop (0x004F9B70), UILoadingPercentDisplay (0x0047C860), Sound_Enter (0x004C8A20), RenderTickUpdate (0x004C8B70) and Sound_Post (0x004C8CA0). A replacement executable must preserve the globals, the null guard, and the __thiscall dispatch convention.
- **SoundRenderFadeFieldLayout** — The render-fade update (0x004C8830) requires an enable byte at this+0x10, an update-pending dword at this+0x14, a computed fade-target float at this+0x18, the global render-fade alpha flt_7CF380, and the mixer object at dword_8AC4C8 with its current value read at +4; the target is flt_7CF380 or flt_7CF380 divided by the a2 divisor.
- **SceneNodeHandleForwarderLayout** — The forwarder (0x004C8F80) stores the handle at this+0x4, fills position floats at this+0x8/+0xC/+0x10 via SceneNodePositionGetter (0x0054B950), negates Y at this+0xC, then dispatches vtable slot +4; a null handle returns 1 immediately.
- **ScalarDeletingDestructorFlag** — The SoundObject destructors (0x004C9060, 0x004C9600) follow the MSVC scalar-deleting-destructor convention: install a destructor-stage vtable, run the release/destructor body (0x004C91D0 or 0x004C9790), restore the base vtable off_5ACE2C, free this via FreeWrapper_7bcf only when a2 bit 0 is set, and return this on all paths.
- **SubObjectReleaseProtocol** — Owned sub-objects in the dword run this+0x1C..0x24 are released by invoking their vtable slot 0 as a __thiscall with argument 1 and then nulling the slot (0x004C94D0 for all three, 0x004C9960 for the slot at this+0x1C), so the same sub-object is not released twice.
- **StateIndexedSelectorLayout** — The state object maps a selector at this+0x1C to value slots this+0x20/0x24/0x28 (0 for out of range); the setter (0x004C92B0) writes the selector and, when the selected object is non-null, dispatches its vtable slot +4 with the fixed argument list (object, 2, v4+8, zeroed 3-dword buffer, a3, 1065353216, 1).
- **BestLapSlotOwnerTable** — Slot-owner bookkeeping (0x004D1C40): a byte array indexed this[a2+400], lap times from the float table flt_5F0774 at stride 4656, vehicle count from dword_5C329C; on takeover AIOvertakeDefendStateChange (0x00419690) is notified with the game-state pointer dword_5EB978, the slot, and the new and old drivers; called from LapCompletion (0x004BC4E0).
- **WarningGateFieldLayout** — The readiness gate (0x004D2170) requires the last-trigger timestamp float at this+0xB4 compared with 30.0 against the session time dbl_8AFEA0, and iterates the vehicle pointers at dword_7C54F0 (count dword_5C329C) calling sub_4BC9B0 (0x004BC9B0) at vehicle base + 16436 with two zero arguments.
- **DriverGridArrayStride** — Driver-grid sorting (0x004D0CF0) iterates per-driver entries of stride 18624 bytes based at unk_5F070C; status 3 (retired) sorts last, primary rank at entry index 2, status-1 racing time float at index 33, secondary rank/time at indices 3/4, tiebreak dword at index 11; the comparator returns -1/0/1.
- **GlobalDefaultsAndDataStructs** — The dword_8ACEA0 defaults block (0x004C9B70) zeroes thirteen leading dwords then writes 1.0 / 0.80000001 / -1 sentinels; the dword_8ACEE0 data struct (0x004D0030) is initialized and the surrounding control globals reset, including a 0xFF-filled 0x68-byte block at byte_8AD008 and a trailing 104-dword clear. A replacement executable must preserve these global layouts.
- **DebugLogAndFileGlobals** — dword_8AD25C is the debug-log buffer (written by DebugLogWrite from the SpecialFX hooks) with its [1] element used as a file handle closed via FileCloseWithLock (0x00587D02); dword_8AD254 and dword_8AD258 are reset together (0x004D5C40), and their addresses are passed to the name-only wrappers TextureSurfaceDestroyer (0x004D5C60) and DualFieldZeroInit (0x004D7920).
- **ExternalProcessLaunchContract** — CreateProcessA is launched through the IAT slot at 0x0059E0D0 with a zeroed STARTUPINFOA (cb = 68) and creation flag 0x20 (CREATE_NO_WINDOW); the command line is formatted as '"<exe>" <args>' into a 256-char buffer via 0x0058815F, with executable default byte_5EA438 (override dword_7CEA18) and format string at 0x005D45B8.

## Unresolved

- The identity and type of the object(s) behind dword_8AC4C8 and dword_8AC4CC and the meaning of the dispatched vtable methods (slots 0x14/0x1C and 0x0C) are not established; the two adjacent globals may reference the same or different objects, and both callers sharing one global do not prove identical receivers across paths.
- The null-guard paths of 0x004C85C0, 0x004C8900, 0x004C8A10, 0x004C8F80, 0x004C9960, 0x004C94D0 and 0x004C9D30 return an uninitialized decompiler local; the runtime behavior on those paths is undefined.
- flt_59E440 is listed as a read global for 0x004C8830 but does not appear in its raw source; its role is unexplained (carried in unresolved_evidence_refs).
- The meaning of *(dword_8AC4C8 + 4) as the audio mixer's current fade value is DERIVED from the comparison against flt_7CF380, not proven.
- The purpose of a2 in 0x004C8830 (time divisor versus target scale) and of the consumption of this+0x14 / this+0x18 is DERIVED and unproven.
- The indirect dispatch target at vtable+4 of 0x004C8F80 and the significance of negating the scene-node Y component before dispatch are unknown.
- The roles of off_5ACE3C and off_5ACE5C as destructor-stage vtables and off_5ACE2C as a shared base vtable are DERIVED (fill prose), not confirmed by this packet; VtableDestructorNull (0x004C9790) may itself free or modify sub-objects.
- Offset 0x1C collides across classes: selector index (StateIndexedObject), sub-object slot 0 (SubObjectHolder), and the owned-object handle released by 0x004C9960; offsets 0x20/0x24 also collide across StateIndexedObject value slots, SubObjectHolder sub-object slots and TreeFreeNode's child pointer. The offsets are kept in their respective classes, not merged.
- Offset 0x10 collides across classes: render-fade enable byte (SoundRenderFadeController) versus the scene-node Z position (SceneNodeHandleForwarder); kept in their respective classes, not merged.
- The selector semantics of this+0x1C (state id versus property index) and the meaning of the three value slots in StateIndexedObject are unproven; v4 is uninitialized in the decompilation yet flows into the 0x004C92B0 indirect-call argument v4+8.
- The meaning of the vtable Release argument (1) and the identity of the released sub-object classes in 0x004C94D0/0x004C9960 are unknown.
- The a2 & 1 delete-flag convention is DERIVED (standard MSVC scalar-deleting-destructor pattern), not confirmed by packet evidence.
- The semantic identity of the defaults block at dword_8ACEA0 and the data struct at dword_8ACEE0, and their consumers, are unknown; the reset control globals (8ACFC0..8AD08C) and the 0xFF-filled / 104-dword-cleared blocks have unexplained meanings.
- The value 1172373504 at unk_8ACF98 is left as the raw decimal literal; its float bit-pattern interpretation is intentionally not synthesized.
- The status enum of the driver comparator (3 = retired, 1 = racing) is inferred from prior-analysis prose, not from the raw source alone; the decompiler's final line 'return v4 < v3' is an ambiguous pointer-order fallback.
- flt_59E468 (0x004D2170) and flt_59E670 (0x004D1C40) are flagged as packet globals but do not appear in their functions' raw source; carried in unresolved_evidence_refs.
- The exact semantics of sub_4BC9B0 and the meaning of the vehicle offset +16436 in 0x004D2170 are DERIVED from their boolean use, not independently identified.
- The 4656-byte stride of the flt_5F0774 lap-time table is not proven to equal the vehicle struct stride from 0x004D1C40 alone.
- The string-split loop return value used as a boolean trace gate in the SpecialFX hooks is inferred; the literal 2798 and the message content of the entered-special strings are not established.
- The SpecialFX owner is DERIVED only for the Enter hook (0x004CEE90); the Setup/Restart/Exit hooks (0x004CEEC0/0x004CFC90/0x004CFFF0) keep UNKNOWN owners in the packet.
- The callees StructFieldInitializer_4a58 (0x004D4A20), TextureSurfaceDestroyer (0x004D5C60) and DualFieldZeroInit (0x004D7920) are name-only in the raw source; their signatures and behavior are not in the packet.
- The meaning of the mode arguments 0 and 2 passed by StateGetSetWrapper (0x004D4800) to Delegation_47c0, and why the first ArrayStateRead value is fed back into the second delegation, are unknown.
- The constant aRb at 0x005BE828 and the signature/purpose of sub_587DB0 / sub_587F64 / FileCloseWithLock are undefined in this packet; 0x004D4790 and 0x004D7940 both call FileCloseWithLock on different receivers.
- BooleanToIntConversion (0x00587B3E) semantics beyond 'non-zero value to 1' are not established; the registration stubs' target and the meaning of the converted values are unknown.
- dword_8AD25C is used both as the debug-log message buffer (DebugLogWrite target) and, at element [1], as a file handle; the array element type and the meaning of index [1] are not confirmed from this packet alone.
- The ProcessInformation structure in 0x004D5885 is populated by CreateProcessA but not consumed; byte_FF000000000053DE is a misidentified write global (carried in unresolved_evidence_refs).
- The field type of this+0x0 in 0x004D1027 is unknown (dword-sized scalar/pointer/float); the structural twin of FloatClamp (0x004646C0) does not confirm field semantics.
