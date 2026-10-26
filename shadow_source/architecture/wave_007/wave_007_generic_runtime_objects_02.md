# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Evidence-linked reconstruction of the generic runtime objects region. No function carries a proven owner class; each function is assigned to a conservative cluster keyed on shared fields, shared callees, or a shared behavioral pattern. The most defensible groupings are: a callback-address registration helper family (passing callback addresses through BooleanToIntConversion 0x00587B3E), a DynMan lifecycle family (StringSplitLoop + DebugLogWrite), and a forwarding-thunk family. Virtual-dispatch contracts (bounded index change callback, triple interface release, normalized-range update) are GUESS because their callee interfaces are not resolvable from this packet. Several functions are empty no-op slots, and two (0x004156FA, 0x00429FC2) are decompiler-corrupt or deliberate traps whose bodies are unreliable.

## Function roles

- `0x0040B6C0` **IndexedCollectionSearch** — Linear search over fixed-stride (0xD0) records; returns record index or -1
- `0x0040B6F0` **IndexedCollectionSearch** — Bounded index setter: writes this+0x14 and fires vtable+16 callback when 0<=a2<count
- `0x0040BE20` **PolymorphicSlotReleaser** — Conditional vtable[0] invoke+null on three interface slots; returns last call result
- `0x0040CDD0` **SimpleSetterAccessor** — Unconditional single-field setter (this+0x8), returns argument
- `0x0040D080` **ByteGetterAccessor** — Read-only byte getter at this+0x24
- `0x0040D470` **CameraDirectorStateInit** — Init entry: set first dword then delegate field init to StructFieldInit (0x0040D490)
- `0x0040DBC0` **ModeStatePredicate** — Mode predicate: true iff this+0x0 mode equals 3 or 4
- `0x0040DBD5` **ReservedNoOpSlot** — Empty void stub ignoring its argument
- `0x0040E1C0` **GraphicsResourceBlock** — Zero graphics-resource block globals then call resource destructor; returns block base
- `0x0040E1D0` **CallbackRegistrationHelper** — Callback-address-to-int registration query wrapper (reads 0x0040E1E0)
- `0x0040E1E0` **GraphicsResourceBlock** — Destroy global graphics resource at 0x005EA560
- `0x0040E710` **StatusValueWriter** — Mode-switch (0-5) status writer into sub-struct destination field
- `0x00410880` **ReservedNoOpSlot** — Constant-1 stub
- `0x00410979` **ReservedNoOpSlot** — Empty no-op stub (nullsub)
- `0x00410B20` **IndexedListInsert** — Compute 36-byte-strided element by index (a2+4) and insert into linked list
- `0x00410B40` **IndexedListInsert** — Compute 36-byte-strided element by index (a2+4) and forward to sub_410AF0
- `0x00411570` **StatusFieldCopier** — Copy vehicle status fields from global block 0x005ECDC8 into three target arrays via 0x0040E710
- `0x004116B0` **ForwardingThunk** — Always-0 wrapper invoking RandomRangeTableInitializer
- `0x004119B0` **GlobalBufferHelper** — Free globally tracked buffer dword_5EA5D0 if non-null
- `0x004119D0` **PredicateUtility** — Integer range classifier over a1: returns 0/1 for two intervals, else -1
- `0x004141F0` **GlobalBufferHelper** — Zero-init global dword_5EA5E8 via StructZeroInit
- `0x00414200` **CallbackRegistrationHelper** — Register global list cleanup callback (callback-address-to-int ABI)
- `0x00414490` **ForwardingThunk** — Forward float global flt_5EA618 to UtilityFunction_84b0
- `0x004144A0` **CallbackRegistrationHelper** — Unregister global list cleanup callback (callback-address-to-int ABI)
- `0x004144B0` **ForwardingThunk** — Forward float global flt_5EA618 to EmptyStub_7470
- `0x004155D0` **NamedEntryList** — Search named linked list by string; null string falls back to global byte_5EA438
- `0x004156FA` **AbnormalCodeStub** — Noreturn ud0 undefined-opcode trap; decompiler reports unbalanced stack
- `0x0041869A` **ReservedNoOpSlot** — Empty subroutine
- `0x00418970` **ThresholdGatedCaller** — Range-gated virtual dispatch: call vtable+0x1C on this+0xAF4 object when parameter in [0,1]
- `0x00418DD0` **CallbackRegistrationHelper** — Callback-address-to-int wrapper for sub_418DE0
- `0x00418DE0` **ForwardingThunk** — Forward global dword_5EB978 to linked-list destructor
- `0x004198A2` **ReservedNoOpSlot** — Bare-return stub (decompiler MK_FP artifact)
- `0x0041F180` **PredicateUtility** — Boolean wrapper: true iff loc_41F040() returns exactly 1
- `0x0041FDF0` **PredicateUtility** — Boolean predicate: true iff ConfigSectionSearchByKeyValue() returns 2
- `0x00423070` **StringConfigUtility** — Read config key via sub_587C20, format 'config=%s', copy to persistent buffer
- `0x00423490` **GlobalBufferHelper** — Zero the 13-byte global buffer at 0x5EC4C0; returns buffer base
- `0x00423830` **StringConfigUtility** — Null-safe string compare with fallback string byte_5EA438
- `0x00429FC2` **AbnormalCodeStub** — Decompiler-corrupt fragment: byte increment at 0xCE8B0875 + tail-jump to 0x42A206
- `0x0042B8A0` **ForwardingThunk** — Forward global unk_5EC6D0 to sub_4B3DB0
- `0x0042B8B0` **CallbackRegistrationHelper** — Callback-address-to-int wrapper for StubToNullsub (0x0042B8C0)
- `0x0042B8C0` **ForwardingThunk** — Forward global unk_5EC6D0 to EmptyStub_0170
- `0x0042BB80` **CallbackRegistrationHelper** — Thunk: BooleanToIntConversion(0x0042BB90 address)
- `0x0042BD98` **ReservedNoOpSlot** — Empty no-op stub (nullsub)
- `0x0042C130` **DynManLifecycle** — DynMan enter: split build path, debug-log on non-zero status, reset season scoring
- `0x0042C170` **DynManLifecycle** — DynMan setup: split build path, debug-log on non-zero status
- `0x0042CA70` **DynManLifecycle** — DynMan exit: split build path, debug-log on non-zero status
- `0x0042CE00` **GlobalBufferHelper** — Init global block at 0x7C569C to constant state (1,3,1,0,0,0,0,0,-1)
- `0x0042CE10` **CallbackRegistrationHelper** — Thunk: BooleanToIntConversion(SessionType5Nullsub 0x0042CE20 address)

## Proposed classes

### IndexedCollectionSearch

Bounded index storage plus linear address search over a fixed-stride record array. Record stride 0xD0, array start this+0x0C, count this+0x10, stored index this+0x14.

Methods: `0x0040B6C0`, `0x0040B6F0`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `this+0x0000000C` `pointer records_array` (read, DERIVED)
- `this+0x00000010` `int record_count` (read, DERIVED)
- `this+0x00000014` `int current_index` (write, DERIVED)

### PolymorphicSlotReleaser

Holds up to three polymorphic interface pointers; each non-null pointer is invoked at vtable[0] with integer flag 1 and then nulled. Consistent with release/cleanup chaining.

Methods: `0x0040BE20`

- `this+0x00000018` `pointer slot0_interface` (read_write, DERIVED)
- `this+0x0000001C` `pointer slot1_interface` (read_write, DERIVED)
- `this+0x00000020` `pointer slot2_interface` (read_write, DERIVED)

### StatusValueWriter

Switch on mode field this+0x1C; for modes 0-5 writes a2 into a destination field of the sub-struct at this+0x20 (packet representation this+0xF0). Returns mode except for modes 1/4 where it returns a2.

Methods: `0x0040E710`

- `this+0x0000001C` `int mode` (read, DERIVED)
- `this+0x00000020` `pointer sub_struct_ptr` (read, DERIVED)
- `this+0x000000F0` `int write_target_field` (write, GUESS)

### StatusFieldCopier

Copies status field values from the per-vehicle global block at 0x005ECDC8 (stride 18624 per index) into three target field arrays (this+0x4C, this+0x58, this+0x64), each value stored through StatusValueWriter 0x0040E710. A non-zero a3 flag reads the source; zero forces a 0 (reset).

Methods: `0x00411570`

- `this+0x0000004C` `pointer status_array_group1` (read_write, DERIVED)
- `this+0x00000058` `pointer status_array_group2` (read_write, DERIVED)
- `this+0x00000064` `pointer status_array_group3` (read_write, DERIVED)

### NamedEntryList

Linked list of string-named entries (head this+0x20, count this+0x2C). Each node carries a string pointer (+0x0) and next pointer (+0x4); a null string falls back to the global default byte_5EA438. Search by string via 0x00588410.

Methods: `0x004155D0`

- `this+0x00000020` `pointer list_head` (read, DERIVED)
- `this+0x0000002C` `int entry_count` (read, DERIVED)
- `*(this+0x20)+0x00000000` `pointer node_name_ptr` (read, DERIVED)
- `*(this+0x24)+0x00000004` `pointer node_next_ptr` (read, GUESS)

### IndexedListInsert

Resolves an element pointer as *(this+0x10) + 36*index (index read from a2+4) and forwards it to a list-insert or forward helper. Called by VehgenScnFileLoader and sub_4C6E80.

Methods: `0x00410B20`, `0x00410B40`

- `this+0x00000010` `pointer element_array` (read, DERIVED)

### ThresholdGatedCaller

Range-gated virtual dispatch: when this+0xAF4 is non-null and parameter a2 is in [0.0,1.0], invokes vtable+0x1C on the target object passing a2.

Methods: `0x00418970`

- `this+0x00000AF4` `pointer target_object` (read, DERIVED)
- `*(this+0xAF4)+0x0000001C` `pointer virtual_update_method` (read, DERIVED)

### CameraDirectorStateInit

Init/reset entry (invoked by 0x0040DA30 during camera-director reset/init): sets the first dword this+0x0 (vtable or parent pointer, ambiguous) then delegates remaining-field init to StructFieldInit 0x0040D490. Returns this for chaining.

Methods: `0x0040D470`

- `this+0x00000000` `pointer first_dword` (write, GUESS)

### ModeStatePredicate

Mode gate: reads a single dword mode field at this+0x0 and reports true when it equals 3 or 4. Caller 0x004D4580 gates mode-dependent processing on this predicate.

Methods: `0x0040DBC0`

- `this+0x00000000` `int mode` (read, DERIVED)

### SimpleSetterAccessor

Trivial setter: unconditionally stores the argument at this+0x8 and returns the same value. Used by session-phase dispatch 0x0040D1B0.

Methods: `0x0040CDD0`

- `this+0x00000008` `int value` (write, DERIVED)

### ByteGetterAccessor

Read-only getter returning the byte at this+0x24 with no side effects.

Methods: `0x0040D080`

- `this+0x00000024` `byte byte_value` (read, DERIVED)

### GraphicsResourceBlock

Global graphics-resource block anchored at 0x005EA560: zeroing of a contiguous run of block globals plus destructor delegation, and a parameterless destroy wrapper. Block layout and per-field meaning are unknown.

Methods: `0x0040E1C0`, `0x0040E1E0`


### CallbackRegistrationHelper

Family of wrappers that pass a stored callback/stub code address to BooleanToIntConversion (0x00587B3E) and return its integer result, matching a legacy callback-registration ABI. Register, unregister and query variants.

Methods: `0x0040E1D0`, `0x00414200`, `0x004144A0`, `0x00418DD0`, `0x0042B8B0`, `0x0042BB80`, `0x0042CE10`


### DynManLifecycle

Dynamic-manager lifecycle handlers (enter/setup/exit). Each runs a build-path split via StringSplitLoop (0x004D7A50) and, on a non-zero status, writes an entry message into the global debug buffer at 0x008AD25C via DebugLogWrite (0x004D7AA0).

Methods: `0x0042C130`, `0x0042C170`, `0x0042CA70`


### ForwardingThunk

Plain forwarding wrappers that pass one global or constant argument to a single utility call and return its result unchanged (or a constant). Callee identities are often known only by source name.

Methods: `0x004116B0`, `0x00414490`, `0x004144B0`, `0x00418DE0`, `0x0042B8A0`, `0x0042B8C0`


### ReservedNoOpSlot

Empty or trivial no-op stubs with no observable effect: void stubs, constant-return stubs and bare-return slots. Likely reserved placeholders or vtable slots.

Methods: `0x0040DBD5`, `0x00410880`, `0x00410979`, `0x0041869A`, `0x004198A2`, `0x0042BD98`


### GlobalBufferHelper

Free, zero or init helpers over named global buffers: dword_5EA5D0 (free), dword_5EA5E8 (zero init), byte_5EC4C0 (clear), block at 0x7C569C (constant-state init).

Methods: `0x004119B0`, `0x004141F0`, `0x00423490`, `0x0042CE00`


### StringConfigUtility

String/config helpers: null-safe string comparison with a fixed fallback string, and a config-key reader that formats 'config=%s' into a length-checked buffer and copies it to a persistent buffer.

Methods: `0x00423070`, `0x00423830`


### PredicateUtility

Small boolean/range predicates: an integer range classifier (0/1/-1), a wrapper returning true iff its callee returns exactly 1, and a wrapper returning true iff a config search returns 2.

Methods: `0x004119D0`, `0x0041F180`, `0x0041FDF0`


### AbnormalCodeStub

Decompiler-corrupt or deliberate-trap functions whose bodies are unreliable: a noreturn ud0 undefined-opcode trap and a fragment that increments a non-image address byte then tail-jumps.

Methods: `0x004156FA`, `0x00429FC2`


## Compatibility contracts

- **BoundedIndexChangeCallback** — When a bounded index request is accepted, the owning object writes the index at this+0x14 and invokes its vtable+16 __thiscall callback with `this`; out-of-bounds requests are rejected without write or callback and the argument is returned unchanged.
- **InterfaceSlotReleaseDispatch** — Up to three stored interface pointers (this+0x18/0x1C/0x20) are non-null tested; each non-null pointer is invoked at vtable[0] with integer flag 1, then the slot is nulled. The callee interface is unknown; the release interpretation is DERIVED from the call pattern.
- **NormalizedRangeVirtualUpdate** — When the target object pointer at this+0xAF4 is non-null and the parameter lies in [0.0,1.0], the vtable+0x1C __thiscall of that object is invoked with the parameter; otherwise nothing happens.
- **CallbackAddressRegistrationAbi** — Callback register/unregister/query wrappers pass the callback's code address to BooleanToIntConversion (0x00587B3E) and return its integer result; the returned value is treated as success/registration status by legacy ABI callers.
- **VehicleStatusBlockCopy** — Status fields are copied from the per-vehicle block at 0x005ECDC8 (18624-byte stride per index) into three target arrays on the receiver (this+0x4C/+0x58/+0x64); a zero a3 flag forces zeros (reset) instead of source values. Group source strides differ (74 dwords, fixed dwords 377/394, 17 dwords).
- **GlobalDebugBufferLifecycleLog** — DynMan lifecycle handlers run a build-path split via StringSplitLoop (0x004D7A50) and, when its status is non-zero, write an entry message into the global debug buffer at 0x008AD25C via DebugLogWrite (0x004D7AA0), returning the write result.

## Unresolved

- All packet owners are UnknownObject/UNKNOWN; every class cluster above is an evidence-based grouping, not a proven class identity. Equal offsets on unrelated this pointers were not merged.
- ShortComputation_e710's written destination is represented two ways in the packet (field this+0xF0 vs raw source this[8]+208); their structural identity is assumed, not proven.
- field:obj:0x00000010 duplicates field:this:0x00000010 at the same byte offset under a different base name; treated as an extraction artifact of the same upper-bound read in SetBoundedIndexWithCallback.
- BooleanToIntConversion (0x00587B3E) semantics are unresolved: registration bookkeeping vs pure boolean/pointer-to-int coercion; the meaning of its integer result is unknown.
- GraphicsResourceDestructor identity/address and the layout and per-field meaning of the global block at 0x005EA560 are unknown; why a caller receives &dword_5EA560 after teardown is unclear.
- The vehicle status block at 0x005ECDC8 uses mixed source strides (74-dword groups, fixed dword indices 377/394, 17-dword groups); the identity of each individual status field is undocumented.
- Mode value meanings are unknown: modes 0-5 for ShortComputation_e710 (and why modes 1/4 return a2 instead of the mode), and modes 3/4 for ModeValidationCheck (prior analysis suggests replay/cinematic, not established here).
- DynMan lifecycle parameters are undocumented: StringSplitLoop delimiter 2 and maximum lengths 507/519/953; the literal content of aDDevF119992002_12 is not in the packet; SeasonScoringReset appears in raw source but has no address evidence.
- Global buffers dword_5EA5D0, dword_5EA5E8, unk_5EC6D0 and float flt_5EA618: their allocation/writer paths are unknown.
- 0x004156FA (ud0 trap) and 0x00429FC2 (byte increment at non-image address + tail-jump) are decompiler-corrupt or deliberate traps; their bodies are unreliable beyond the observed instruction.
- 0xCE8B0875 is not a normal game image address; the write target is likely misdecoded data.
- LinkedListNodeInsert_0ad0 and sub_410AF0 are not in the packet callee lists; their contracts are unknown.
- The semantic of value 2 in ConfigSearchResultIsTwo (section index, result code, or enum) is undocumented.
- The content and length of the fallback string byte_5EA438 are not established.
- Callback slots unk_42BB90, SessionType5Nullsub (0x0042CE20) and StubToNullsub (0x0042B8C0) may be function-pointer slots rather than data objects; whether deferred callbacks ever invoke them is unproven.
- ClearEmptyStringBuffer lists callees 0x00587B3E and 0x00587BCF that are not called by its body; their relation to this function is unknown.
- Global 0x005C3030 (aConfigS) appears in skeleton analysis but is not referenced by ReadConfigValueAndFormat's raw source; role unconfirmed.
- The virtual callback targets (vtable+16 in SetBoundedIndexWithCallback, vtable[0] in ConditionalVirtualCallTriplet, vtable+0x1C in ThresholdGatedVirtualDispatch) are indirect and not statically resolvable from this packet.
