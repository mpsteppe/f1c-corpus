# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 46 validated function IR records. The packet labels every function owner UNKNOWN, so all class groupings are DERIVED-proposed or GUESS proposals, never CONFIRMED. Five clusters have direct call-edge or shared-field support: (1) MilesAudioSampleObject groups 0x004059F0/0x00405A30/0x00406100 on the shared sample-handle cluster this+0x58/this+0x68 with the handle at *(this+0x68)+0x10; (2) IndexedElementArrayObject groups 0x0040ACC6/0x0040ACD0/0x0040AD60/0x0040AD90/0x0040B450/0x0040B630 on the shared array base/count/index layout this+0xC/0x10/0x14 with the direct call edges 0x0040B450 -> 0x0040AD60/0x0040AD90; (3) MutexProtectedValueObject groups 0x004064B0/0x004066C0 on the direct call edge and shared this+0x4C/0x50/0x54 layout; (4) ConfigParserProxyAccessor groups the four getters/setters on the shared this+0x0 proxy slot and the ConfigIniParser/0x00422BE0 call context; (5) BooleanConversionRegistration groups 0x00404830/0x00408220/0x00408260 on the identical BooleanToIntConversion (0x00587B3E) delegation shape. VTableSwitchProxyObject groups 0x0040AC40/0x0040B5A0 on the identical vtable-switch/sub-object call shape. MilesSoundFilterTable groups the two 4-entry 32-byte-stride name tables by shared accessor shape while keeping the two table bases (0x005BE720, 0x005BE7A0) distinct. The remaining stateless wrappers, stubs and the corrupted thunk are assigned to FreeFunction. Offset coincidences across different bases (this+0x4C as mutex protected_value vs spatial entry_count; this+0x54 as wait_timeout vs selection_field; this+0x58 as sample-handle struct in the raw source vs dereference base this+0x68 in the packet fields) are recorded as explicit unresolved contradictions, never merged, per rule 8.

## Function roles

- `0x00401080` **GlobalSettingsBlock** — One-time static-data initializer for the global block anchored at dword_5EA2C0 (0x005EA2C0): fills the index table at [2..5] with 1,2,3,4, zeroes several byte/dword/float fields, stores two large constants at [0..1], stores 0.995, sets four small constant fields, and returns the block base pointer. No calls appear in the raw source despite the ABI lead naming a callee; the ABI-named relationship is unverified.
- `0x00401130` **FreePointerArrayOwnerObject** — Thiscall cleanup routine that behaves like a destructor: frees up to three optional heap sub-allocations at this+0x150/0x154/0x158 via FreeWrapper_7bcf (each guarded on non-null), then calls ObjectReleaseArrayIterator on this and returns its result. The array-iterator callee address is not in the packet.
- `0x00404820` **RenderNodeListGlobalOwner** — Single-call delegation wrapper: passes &dword_5EA43C (0x005EA43C) to FAILWRONGTRIAGE and returns the callee result unchanged; FAILWRONGTRIAGE appears only in the raw source text and has no packet callee address.
- `0x00404830` **BooleanConversionRegistration** — Thin registration wrapper: passes the address of sub_404840 (global 0x00404840) cast to int into BooleanToIntConversion (0x00587B3E) and returns the conversion result. No callers are recorded, so the registration target is unknown.
- `0x00404840` **RenderNodeListGlobalOwner** — Thin wrapper: forwards &dword_5EA43C (0x005EA43C) to the render-node-list destructor and returns the destructor's result. The destructor address and the nature of the global are not established beyond the callee name.
- `0x00404B4F` **FreeFunction** — Empty stub (nullsub) with no body, no parameters observed, no calls, no field or global accesses and no recorded callers; the raw source is an empty body.
- `0x00404D10` **ConfigParserProxyAccessor** — Trivial thiscall getter: reads the pointer at this+0x0 and returns the dword at obj+0x20 of the pointed-to object; unconditional, no guards or callees; called by sub_422BE0 (0x00422BE0).
- `0x00404D20` **ConfigParserProxyAccessor** — Trivial thiscall getter: reads the pointer at this+0x0 and returns the float at obj+0x18 of the pointed-to object, promoted to double per the signature; called by sub_422BE0 (0x00422BE0).
- `0x00404D30` **ConfigParserProxyAccessor** — Trivial thiscall setter: reads the pointer at this+0x0, stores the caller dword a2 at obj+0x18 of the pointed-to object, and returns the object pointer; called by ConfigIniParser (0x00421CD0), consistent with a config value being applied to an object field.
- `0x00404D40` **ConfigParserProxyAccessor** — Thiscall setter: writes the caller-supplied dword a2 into obj+0x20 of the object pointed to by *this and returns the original object pointer unchanged; sole known caller is ConfigIniParser (0x00421CD0).
- `0x00404EE8` **FreeFunction** — In-place byte accumulation: adds the byte value a1 into the byte at (a2 + 94); parameter a3 is unused by the body. Decompiler flags a positive-sp warning on the __userpurge signature, so the parameter layout may be inexact.
- `0x00404EF0` **FreeFunction** — Thin stdcall forwarding wrapper: passes its single argument a1 straight through to StringCopyWithBufferRealloc and returns that callee's result unchanged; the only recorded caller is ConfigIniParser (0x00421CD0), consistent with a glue/adaptor used while parsing configuration text.
- `0x00404FA0` **MilesSoundFilterTable** — Bounded lookup into the string table at global 0x005BE720: for index a1 < 4 returns the address of the a1-th 32-byte-strided entry, otherwise NULL. The label aLowpassFilter and the caller MilesSoundSystemFilterOpenByIndex (0x00405D70) imply a sound-filter-name table.
- `0x00404FC0` **MilesSoundFilterTable** — Bounded table getter over the low-pass cutoff table at 0x005BE7A0: returns a pointer to the a1-th entry (each entry is 32 bytes) when a1 < 4, otherwise NULL; consumed by MilesSoundSampleProcessorSetup (0x004060C0).
- `0x00405013` **FreeFunction** — Corrupted thunk (IDA warns 'positive sp value has been detected'): reads an uninitialized local v1, computes the call target v1 - 5477, performs an indirect call through that computed pointer and returns the call's result. The call target is data-dependent garbage and is not resolvable from the packet.
- `0x00405030` **FreeFunction** — stdcall wrapper: runs a one-time initialization-style registration call OneTimeInitializationWithAtexitStyleRegistration (0x00404FE0) with no arguments, then forwards a1 unchanged to ShortComputation_7dd0 (0x00407DD0) and returns that call's result.
- `0x004059F0` **MilesAudioSampleObject** — Ends a Miles sample and reinitializes its handle: reads the sample-handle struct pointer at this+0x58, if non-null dereferences the handle at *(this+0x68)+0x10, calls AIL_end_sample then AIL_init_sample (imports 0x0059E3D8/0x0059E3DC), clears the sample struct's first dword and the this+0x58 pointer, and returns the AIL_init_sample result (or 0 on the early null exits).
- `0x00405A30` **MilesAudioSampleObject** — Stops a Miles sample: reads the sample-handle struct pointer at this+0x58, dereferences its +0x10 sample handle via *(this+0x68)+0x10, and when both levels are non-null passes the handle to AIL_stop_sample (0x0059E3FC); returns the final sample handle value (0 when either level is null).
- `0x00406020` **AttenuationSmoothstepObject** — Attenuation-style smoothstep helper (thiscall, double result): forms the linear parameter v2 = this[7]*a2 + this[8] from this+0x1C/this+0x20; when v2 >= 1.0 returns this[16] (this+0x40) scaled by an inverse blend using this[9] (this+0x24), otherwise returns this+0x40 unchanged; called by F_3DSoundPositioningUpdate (0x00405B90).
- `0x00406100` **MilesAudioSampleObject** — Guarded audio-side initialization and delegated computation: reads this+0x58; when it is non-null and the dword at +16 of the pointed structure is non-null, performs a one-time registration via OneTimeInitializationWithAtexitStyleRegistration (0x00404FE0) and returns the result of ShortComputation_7e10 (0x00407E10) invoked with three local byte buffers; otherwise returns the stored this+0x58 pointer. Called from F_3DSoundPositioningUpdate (0x00405B90).
- `0x00406230` **FreeFunction** — Runs the primary computation ShortComputation_6250 (0x00406250) on the thiscall receiver, then conditionally frees the receiver through FreeWrapper_7bcf (0x00587BCF) when bit 0 of argument a2 is set, and returns the receiver pointer; the a2 flag selects an ownership/free-after-compute path.
- `0x004064B0` **MutexProtectedValueObject** — Thin wrapper: reads the protected value through MutexProtectedValueReadWithTimeout (0x004066C0) and returns whether it is non-zero as a BOOL.
- `0x004066C0` **MutexProtectedValueObject** — Reads a mutex-protected integer: waits on the mutex handle at this+0x50 with the timeout at this+0x54 (WaitForSingleObject 0x0059E1A0), reads the value at this+0x4C when the wait result is 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED), releases via ReleaseMutex (0x0059E1A4) and returns the value; returns -1 when the mutex handle is null or the wait fails.
- `0x00406B30` **SimpleFieldSetterObject** — Simple setter: writes the input integer a2 to this+0x4 and returns a2.
- `0x00406B60` **SimpleFieldSetterObject** — Simple setter: writes the input integer a2 to this+0x54 and returns a2; selection semantics (menu/track index) are not established by this setter alone.
- `0x004070E0` **SpatialEntryQueryObject** — Spatial best-candidate query: scans the 20-byte entries at this+0x48 (count at this+0x4C), each holding an object pointer at +0, a LOD/weight at +4 and a distance at +8; retains the entry minimizing (2^LOD * inputDist^2) against (entryDist^2 * 2^a2); breaks when an entry is null or the a4 filter's vtable+28 call returns 2; on success invokes the selected object's vtable+8 method and returns the entry pointer.
- `0x00407E10` **TripleDwordOwnerObject** — Reads three consecutive dwords at this+0x94/+0x98/+0x9C and writes them through output pointers a2/a3/a4; returns the third value (this[39]); called by ShortComputation_6100 (0x00406100).
- `0x00407F01` **TripleDwordOwnerObject** — Trivial member getter: reads this[39] (byte offset 0x9C), writes the value through the output pointer a4 and returns the same value; parameters a2 and a3 are unused.
- `0x00408220` **BooleanConversionRegistration** — Thin wrapper: calls BooleanToIntConversion (0x00587B3E) with the address of nullsub_11 (0x00408230) cast to int as its single argument and returns the conversion result.
- `0x00408230` **FreeFunction** — Empty no-op stub (nullsub): the body is empty, so it performs no work, touches no memory and has no observable effect; referenced only as a placeholder.
- `0x00408234` **FreeFunction** — Empty no-op stub (nullsub) declared stdcall with one ignored parameter a1: the body is empty, so it performs no work and has no observable effect.
- `0x00408250` **FreeFunction** — Thin wrapper: calls StructFieldInitializer with the address of the global dword_5EA510 (0x005EA510) and returns its result; StructFieldInitializer appears only in the raw source text, so its address and behavior are unverified.
- `0x00408260` **BooleanConversionRegistration** — Registration helper: takes the address of sub_408270 (0x00408270), casts it to int, passes it to BooleanToIntConversion (0x00587B3E) and returns that function's boolean-to-int result; returns 0 or -1 depending on the registered callback's acceptance.
- `0x00408270` **FreeFunction** — Thin wrapper: calls ConditionalVirtualCallTriplet with the address of the global dword_5EA510 (0x005EA510) and returns its result; the callee name and the 'triplet' identity are caller-supplied in the raw source, so the condition and virtual-call targets are unverified.
- `0x004085B0` **FreeFunction** — Trivial stub: ignores its single argument and returns 0 unconditionally; no side effects visible in the recovered source.
- `0x004085C0` **FreeFunction** — Trivial stub: ignores both arguments and returns the constant 1 unconditionally; the ABI lead Stub_Return_1 corroborates the constant-return shape.
- `0x00408868` **FreeFunction** — Trivial stub: ignores both arguments and returns the constant 1 unconditionally; the ABI lead StubReturnOne corroborates the constant-return shape.
- `0x0040A88F` **FreeFunction** — Trivial no-op stub: takes no arguments and has an empty body, so it returns void with no observable side effects; the raw source renders an empty function body.
- `0x0040AC40` **VTableSwitchProxyObject** — Vtable transition sequence: loads the sub-object pointer at this+0xC, switches this object's vtable (this+0x0) to off_59E678, calls virtual entry 0 of the sub-object with argument 3 when the sub-object is non-null, then restores the vtable to off_59E634 and returns the virtual call result.
- `0x0040ACC6` **IndexedElementArrayObject** — Bulk setter: writes the same dword a2 to the three consecutive fields this+0x0C/+0x10/+0x14, then returns the this pointer; unconditional, no guards, calls or globals.
- `0x0040ACD0` **IndexedElementArrayObject** — Minimum-distance search over stride-160 entries at this+0xC (count this+0x10): finds the entry whose float at +140 is closest to the reference returned by EmptyStub(a2) (0x004579C0), writes the winning index to *a3 and the minimum delta to *a4, returns a3; when the count is not positive the outputs keep the init values (index -1, delta FLT_MAX).
- `0x0040AD60` **IndexedElementArrayObject** — Linear search for the value a2 in an array of stride-160 elements rooted at this[3] (offset 0xC) with this[4] (offset 0x10) entries; returns the zero-based matching index or -1 when absent or empty; called by LookupWithOptionalCallback (0x0040B450).
- `0x0040AD90` **IndexedElementArrayObject** — Bounded index setter: writes a2 into this[5] (offset 0x14) only when 0 <= a2 < this[4] (offset 0x10, the upper bound); always returns a2 unchanged; called by LookupWithOptionalCallback (0x0040B450).
- `0x0040B450` **IndexedElementArrayObject** — Lookup with optional virtual callback: returns 0 when a2 is null; searches the stride-0xA0 array via LinearSearchWithStride0xA0 (0x0040AD60), records the found index via BoundedIndexSetter (0x0040AD90), and when the a3 flag is set dispatches the virtual callback at vtable+0x10 via the vtable pointer at this+0x0; returns 1 on success.
- `0x0040B5A0` **VTableSwitchProxyObject** — Vtable transition sequence structurally identical to 0x0040AC40 but switching this object's vtable (this+0x0) to off_59E6AC and restoring off_59E634: sub-object at this+0xC, virtual entry 0 with argument 3 when non-null, returns the virtual call result.
- `0x0040B630` **IndexedElementArrayObject** — Minimum-distance search over stride-208 entries at this+0xC (count this+0x10): reads each entry's float at +140, measures the signed difference against EmptyStub(a2) (0x004579C0), stores the best index to *a3 and the best delta to *a4, returns a3; defaults to -1/FLT_MAX when the count is not positive; structural twin of 0x0040ACD0 with a different stride.

## Proposed classes

### GlobalSettingsBlock

Global-scope block anchored at dword_5EA2C0 (0x005EA2C0), populated once by InitializeStaticGlobalBlock (0x00401080): an index table at [2..5], two large constants at [0..1], cleared byte/dword/float fields, the fixed fractional value 0.995 and four small constant fields. The owning struct is not identified; only the block base is evidenced.

Methods: `0x00401080`


### FreePointerArrayOwnerObject

Thiscall object owning up to three optional heap sub-allocations at this+0x150/0x154/0x158 plus an array released through ObjectReleaseArrayIterator; FreePointersAndReleaseIterator (0x00401130) frees each pointer via FreeWrapper_7bcf when non-null and returns the array-iterator result, behaving like a destructor. The array-iterator callee address and the object type are not in the packet.

Methods: `0x00401130`

- `this+0x00000150` `pointer owned_suballoc_0` (read, GUESS)
- `this+0x00000154` `pointer owned_suballoc_1` (read, GUESS)
- `this+0x00000158` `pointer owned_suballoc_2` (read, GUESS)

### RenderNodeListGlobalOwner

Global render-node-list block at dword_5EA43C (0x005EA43C) operated on by two thin global-scope wrappers: 0x00404820 forwards its address to FAILWRONGTRIAGE and 0x00404840 forwards it to the render-node-list destructor, both returning the callee result. Neither callee has a packet address; the global's role as a render node list is inferred from the callee names only.

Methods: `0x00404820`, `0x00404840`


### BooleanConversionRegistration

Registration helper family that passes a routine's address cast to int through BooleanToIntConversion (0x00587B3E) and propagates the result: 0x00404830 (address of sub_404840), 0x00408220 (address of nullsub_11) and 0x00408260 (address of sub_408270). The purpose of the conversion and the registration target are not established.

Methods: `0x00404830`, `0x00408220`, `0x00408260`


### ConfigParserProxyAccessor

Proxy/accessor object holding a target object pointer at this+0x0; the four thiscall methods provide read/write access to the target's dword/float at obj+0x18 and dword at obj+0x20. The read pair (0x00404D10, 0x00404D20) is called by 0x00422BE0; the write pair (0x00404D30, 0x00404D40) by ConfigIniParser (0x00421CD0). Grouping DERIVED-proposed from the shared this+0x0 proxy slot and the shared configuration call context.

Methods: `0x00404D10`, `0x00404D20`, `0x00404D30`, `0x00404D40`

- `this+0x00000000` `pointer target_object_ptr` (read, GUESS)
- `obj+0x00000018` `dword_or_float config_value_0x18` (read_write, GUESS)
- `obj+0x00000020` `dword config_value_0x20` (read_write, GUESS)

### MilesSoundFilterTable

Two 4-entry, 32-byte-strided sound-filter name tables: the filter-name table at 0x005BE720 (label aLowpassFilter) accessed by FilterNameByIndex (0x00404FA0) and the low-pass cutoff table at 0x005BE7A0 accessed by LowpassCutoffTableEntry (0x00404FC0); both return NULL for indexes >= 4. Consumed by MilesSoundSystemFilterOpenByIndex (0x00405D70) and MilesSoundSampleProcessorSetup (0x004060C0). Kept as one GUESS class because both are the same table-accessor shape in the same Miles filter domain; the two table bases are distinct and not merged.

Methods: `0x00404FA0`, `0x00404FC0`


### MilesAudioSampleObject

Miles audio sample object: owns the sample-handle struct pointer at this+0x58 and an alternative dereference base this+0x68 whose +0x10 holds the Miles sample handle (field *(this+0x68)+0x10). AudioSampleEndAndReinit (0x004059F0) ends and re-inits the sample via AIL_end_sample/AIL_init_sample and clears the sample struct and this+0x58; AudioSampleStop (0x00405A30) stops via AIL_stop_sample; GuardedAudioInitCompute (0x00406100) runs one-time registration and a delegated computation when this+0x58 and the pointed +16 dword are valid. Grouping DERIVED-proposed from the shared this+0x58/this+0x68 handle cluster and the shared Miles AIL sample API. The relationship between this+0x58 and this+0x68 is not evidenced and is left unresolved.

Methods: `0x004059F0`, `0x00405A30`, `0x00406100`

- `this+0x00000058` `pointer sample_handle_struct_ptr` (read_write, GUESS)
- `this+0x00000068` `pointer handle_deref_base` (read, GUESS)
- `*(this+0x68)+0x00000010` `pointer miles_sample_handle` (read, GUESS)

### AttenuationSmoothstepObject

Thiscall object whose SmoothstepInterpolation (0x00406020) forms a linear blend parameter from this+0x1C and this+0x20, scales the base value this+0x40 by an inverse-blend attenuation using the factor this+0x24 when the parameter exceeds 1.0, and otherwise returns this+0x40 unchanged. Called by F_3DSoundPositioningUpdate (0x00405B90); the owning sound object type is not identified.

Methods: `0x00406020`

- `this+0x0000001C` `float blend_slope` (read, GUESS)
- `this+0x00000020` `float blend_offset` (read, GUESS)
- `this+0x00000024` `float attenuation_factor` (read, GUESS)
- `this+0x00000040` `float base_scale` (read, GUESS)

### MutexProtectedValueObject

Mutex-protected value object: OS mutex handle at this+0x50, wait timeout at this+0x54 and the protected integer at this+0x4C. MutexProtectedValueReadWithTimeout (0x004066C0) reads the value under the mutex with a bounded wait (accepting WAIT_OBJECT_0 and WAIT_ABANDONED) and returns -1 on null/failed wait; queryMutexProtectedValue (0x004064B0) wraps the read as a BOOL. Grouping DERIVED-proposed from the direct call edge 0x004064B0 -> 0x004066C0 and the shared handle/timeout/value layout.

Methods: `0x004064B0`, `0x004066C0`

- `this+0x0000004C` `int protected_value` (read, GUESS)
- `this+0x00000050` `pointer mutex_handle` (read_write, GUESS)
- `this+0x00000054` `int wait_timeout` (read, GUESS)

### SimpleFieldSetterObject

Simple thiscall setter object: setIntegerField (0x00406B30) writes this+0x4 and setSelectionField (0x00406B60) writes this+0x54, both returning the input value. The two methods write different offsets and no evidence proves a common owner, so this GUESS grouping is tentative; the this+0x54 offset coincides with MutexProtectedValueObject's wait_timeout but is not merged per rule 8.

Methods: `0x00406B30`, `0x00406B60`

- `this+0x00000004` `int integer_field` (write, GUESS)
- `this+0x00000054` `int selection_field` (write, GUESS)

### SpatialEntryQueryObject

Object owning an array of 20-byte spatial entries at this+0x48 with a count at this+0x4C; SpatialQueryBestCandidateByWeightedDistance (0x004070E0) selects the best candidate by a weighted distance score and invokes the selected object's vtable+8 method. The LOD/weight and distance field semantics are caller-defined.

Methods: `0x004070E0`

- `this+0x00000048` `pointer spatial_entry_array` (read, GUESS)
- `this+0x0000004C` `int entry_count` (read, GUESS)

### TripleDwordOwnerObject

Thiscall object exposing three consecutive dwords at this+0x94/+0x98/+0x9C; TripleDwordGetterFromStruct (0x00407E10) reads all three through output pointers and GetSlot39Member (0x00407F01) reads the +0x9C slot alone. Consumed by 0x00406100; the meaning of the triple is not established.

Methods: `0x00407E10`, `0x00407F01`

- `this+0x00000094` `dword slot_0x94` (read, GUESS)
- `this+0x00000098` `dword slot_0x98` (read, GUESS)
- `this+0x0000009C` `dword slot_0x9C` (read, GUESS)

### IndexedElementArrayObject

Container object owning an element array: base pointer at this+0xC, entry count at this+0x10 and a stored index at this+0x14, with a vtable at this+0x0. Six methods operate on this layout: linear pointer search (0x0040AD60, stride-160), bounded index set (0x0040AD90), two minimum-distance searches using the float at entry+140 (0x0040ACD0 stride-160, 0x0040B630 stride-208), the lookup wrapper with optional vtable+0x10 callback (0x0040B450) and a bulk setter writing all three slots (0x0040ACC6). Grouping DERIVED-proposed from the direct call edges 0x0040B450 -> 0x0040AD60/0x0040AD90 and the shared array-base/count/index field cluster. The stride difference (160 vs 208) between the two search twins is unresolved.

Methods: `0x0040ACC6`, `0x0040ACD0`, `0x0040AD60`, `0x0040AD90`, `0x0040B450`, `0x0040B630`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `this+0x0000000C` `pointer element_array_base` (read_write, GUESS)
- `this+0x00000010` `int element_count` (read, GUESS)
- `this+0x00000014` `int stored_index` (read_write, GUESS)

### VTableSwitchProxyObject

Object whose vtable (this+0x0) is temporarily swapped while invoking a sub-object at this+0xC: VTableSwitch (0x0040AC40) installs off_59E678 and VTableSwitchWithVirtualCall (0x0040B5A0) installs off_59E6AC, both call virtual entry 0 of the sub-object with argument 3 when it is non-null, then restore off_59E634. The sub-object class and the meaning of argument 3 are unconfirmed.

Methods: `0x0040AC40`, `0x0040B5A0`

- `this+0x00000000` `pointer vtable_ptr` (read_write, GUESS)
- `this+0x0000000C` `pointer sub_object_ptr` (read, GUESS)
- `*(this+0xC)+0x00000000` `pointer sub_object_vslot0` (read, GUESS)

### FreeFunction

Stateless global-scope helpers, wrappers and stubs without identifiable object state: the byte accumulator (0x00404EE8), the string-forward wrapper (0x00404EF0), the empty/constant-return stubs (0x00404B4F, 0x00408230, 0x00408234, 0x004085B0, 0x004085C0, 0x00408868, 0x0040A88F), the corrupted thunk (0x00405013), the one-time-init plus delegation wrappers (0x00405030, 0x00406230) and the global-argument delegates (0x00408250, 0x00408270). No shared field layout justifies a tighter grouping; this is a residual bucket, not a real class.

Methods: `0x00404EE8`, `0x00404EF0`, `0x00404B4F`, `0x00405013`, `0x00405030`, `0x00406230`, `0x00408230`, `0x00408234`, `0x00408250`, `0x00408270`, `0x004085B0`, `0x004085C0`, `0x00408868`, `0x0040A88F`


## Compatibility contracts

- **MutexProtectedReadContract** — The mutex-protected read must wait on the handle at this+0x50 with the timeout at this+0x54, treat only results 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED) as success, read the protected value at this+0x4C, release the mutex, and return the value; it must return -1 when the handle is null or the wait fails. The BOOL wrapper (0x004064B0) must report non-zero only when the read succeeded with a non-zero value.
- **MilesSampleStopEndContract** — Sample teardown/reinit must locate the Miles sample handle through the sample-handle struct (this+0x58, with dereference base this+0x68) at +0x10, guard both pointer levels, call AIL_end_sample then AIL_init_sample on the reinit path (returning the init result) or AIL_stop_sample on the stop path (returning the handle), and clear the sample-struct first dword and the this+0x58 pointer on the reinit path.
- **IndexedElementArraySearchContract** — The element array must store its base at this+0xC and its count at this+0x10, support linear pointer search (0x0040AD60) and minimum-distance search on the float at entry+140 against the EmptyStub probe (0x0040ACD0, 0x0040B630), store a resolved index into this+0x14 only when it is within [0, count) (0x0040AD90), and optionally dispatch the vtable+0x10 callback on a successful lookup (0x0040B450).
- **ConfigParserFieldAccessContract** — The proxy object must expose the target object through this+0x0 and provide read/write access to the dword/float at obj+0x18 and the dword at obj+0x20; ConfigIniParser (0x00421CD0) and 0x00422BE0 rely on these accessors to apply and fetch configuration values.
- **MilesFilterNameTableContract** — The sound-filter name tables must be addressable as 4 entries of 32-byte stride at 0x005BE720 (filter names) and 0x005BE7A0 (low-pass cutoffs), returning a pointer to the selected entry for indexes 0..3 and NULL for indexes >= 4; consumed by MilesSoundSampleProcessorSetup (0x004060C0) and MilesSoundSystemFilterOpenByIndex (0x00405D70).
- **VTableSwitchDispatchContract** — Vtable-switch dispatch must install the alternate vtable (off_59E678 for 0x0040AC40, off_59E6AC for 0x0040B5A0) at this+0x0, call virtual entry 0 of the sub-object at this+0xC with argument 3 when the sub-object is non-null, restore off_59E634, and return the virtual call result.
- **BooleanConversionRegistrationContract** — The registration wrappers must pass a routine's address (0x00404840, 0x00408230, 0x00408270) cast to int through BooleanToIntConversion (0x00587B3E) and propagate the result to the caller.
- **GlobalRenderNodeListTeardownContract** — The global at 0x005EA43C must be torn down through both thin wrappers: 0x00404820 forwards its address to FAILWRONGTRIAGE and 0x00404840 forwards it to the render-node-list destructor; both propagate the callee result. The callee addresses are outside the packet.

## Unresolved

- 0x00401080 (GlobalSettingsBlock): the two large constants 1083703296 and 1082785792 written to dword_5EA2C0[0..1] are likely float bit patterns but their meaning is not named in the packet; the ABI lead names a callee yet the raw source contains no call, so the relationship is unverified; the block's owning struct is unidentified.
- 0x00401130 (FreePointerArrayOwnerObject): the ObjectReleaseArrayIterator callee address and signature are absent from the packet; the object type owning the three freed pointers and the released array is unknown; the return-value semantics (status, count, sentinel) are unknown; whether the three pointers at this+0x150/0x154/0x158 are the same or distinct allocation types is unresolved.
- 0x00404820 / 0x00404840 (RenderNodeListGlobalOwner): FAILWRONGTRIAGE and the render-node-list destructor are named only in the raw source with no packet addresses; the role of dword_5EA43C as a render node list is inferred from the callee names only.
- 0x00404830 / 0x00408220 / 0x00408260 (BooleanConversionRegistration): the purpose of passing a function address through BooleanToIntConversion is unclear; no callers are recorded so the registration target is unknown; whether sub_404840 / sub_408270 are code or data pointers is not resolvable.
- 0x00404D10 / 0x00404D20 / 0x00404D30 / 0x00404D40 (ConfigParserProxyAccessor): the type and semantic role of the object behind the this+0x0 proxy and of the obj+0x18/obj+0x20 fields are unknown, only the double indirection is evidenced; returning the object pointer from the setters may be fluent-style or incidental codegen.
- 0x00404EE8 (FreeFunction): the buffer type behind a2 and the meaning of offset 94 are unknown; parameter a3 is unused; the positive-sp warning on the __userpurge convention leaves the true ABI parameter layout uncertain.
- 0x00404EF0 (FreeFunction): the semantics and address of StringCopyWithBufferRealloc are not present in the packet.
- 0x00404FA0 / 0x00404FC0 (MilesSoundFilterTable): only entry 0 of each table is identifiable by its string label; the 32-byte record layout (null-padded name) is not evidenced; how 0x004060C0 and 0x00405D70 consume the returned names is outside the packet.
- 0x00405013 (FreeFunction): v1 is uninitialized so the indirect call target (v1 - 5477) is garbage; the decompiler flags the stack frame as corrupted so even the body shape is unreliable; caller 0x00406659 hints at an audio stream/volume path but no semantics are readable.
- 0x00405030 / 0x00406100 / 0x00406230 (FreeFunction / MilesAudioSampleObject): whether OneTimeInitializationWithAtexitStyleRegistration actually runs once or on every call is not decidable from these functions alone; the a2 bit-0 flag in 0x00406230 (ownership transfer vs pool hint) is caller-supplied; the three local byte buffers passed to ShortComputation_7e10 are unidentified.
- 0x004059F0 / 0x00405A30 (MilesAudioSampleObject): the packet fields describe the sample-handle dereference base as *(this+0x68) while the raw source reads the struct pointer via this[22] (this+0x58); the relationship between this+0x58 and this+0x68 is not evidenced and is left as-is; the AIL_init_sample return value is returned but never checked; no callers are recorded.
- 0x00406020 (AttenuationSmoothstepObject): global flt_59E43C (0x0059E43C) is packet-flagged as read but appears nowhere in the raw decompiled source, so its role is unverifiable; the blend-factor/base-scale semantics outside the 3D-sound caller are caller-context dependent.
- 0x004064B0 / 0x004066C0 (MutexProtectedValueObject): the meaning of the protected integer at this+0x4C is not established; the timeout semantics at this+0x54 (units, sentinels) are caller-side; the 128 wait result is read as Win32 WAIT_ABANDONED from API semantics, not named by the packet.
- 0x00406B30 / 0x00406B60 (SimpleFieldSetterObject): the owning class of this+0x4 / this+0x54 is unknown; setSelectionField writes this+0x54 which coincides with MutexProtectedValueObject's wait_timeout offset, but common ownership is unproven and the two are kept separate per rule 8.
- 0x004070E0 (SpatialEntryQueryObject): the LOD/weight field at entry+4 and the distance field at entry+8 depend on the caller's spatial layout; the vtable+28 filter return-2 rule and the vtable+8 acquire callback are interpretations only; the this+0x4C count offset coincides with MutexProtectedValueObject's protected_value but is not merged.
- 0x00407E10 / 0x00407F01 (TripleDwordOwnerObject): the meaning of the triple at +0x94/+0x98/+0x9C and the consuming context in 0x00406100 are not described in the packet; parameters a2/a3 of 0x00407F01 are unused.
- 0x00408250 / 0x00408270 (FreeFunction): StructFieldInitializer and ConditionalVirtualCallTriplet are absent from the packet callee evidence, so their addresses, conditions and virtual-call targets are unknown; the underlying layout of dword_5EA510 is not evidenced.
- 0x00404B4F / 0x00408230 / 0x00408234 / 0x004085B0 / 0x004085C0 / 0x00408868 / 0x0040A88F (FreeFunction): purpose, callers and parameter meanings of these empty/constant-return stubs are undocumented by the packet; whether they are disabled callbacks, vtable placeholders or ABI padding cannot be determined.
- 0x0040AC40 / 0x0040B5A0 (VTableSwitchProxyObject): the identity and purpose of the argument-3 virtual call are unknown; the sub-object class at this+0xC is unconfirmed; what off_59E678 / off_59E6AC / off_59E634 represent is at most DERIVED from the packet analysis; the return value is uninitialized when the sub-object is null.
- 0x0040ACD0 / 0x0040B630 (IndexedElementArrayObject): the entry type of the stride-160/208 array is unresolved (only a float at +140 is evidenced, the remaining entry bytes are undescribed); EmptyStub (0x004579C0) semantics and the a2 argument are unknown; the stored difference is signed (probe - value) and truncated to float, whether non-negative or absolute distances are intended is unknown; 0x0040B630 is a structural twin of 0x0040ACD0 with a different stride, and field layout equality between the two is not independently established.
- 0x0040AD60 / 0x0040AD90 (IndexedElementArrayObject): the stride-160 element layout and whether a2 is a pointer vs a value are not recoverable from these functions alone; the identity of the owning object and the role of the stored index depend on the caller at 0x0040B450.
- 0x0040B450 (IndexedElementArrayObject): the read of field obj+0x10 is not visible in the raw decompilation and its exact role is unclear, possibly an array base or member read inside a callee; the semantics of the optional vtable+0x10 callback and the a3 flag are caller-specific; the stride-0xA0 element type is unestablished.
- General: equal offsets on different bases (this+0x4C as mutex protected_value vs spatial entry_count; this+0x54 as wait_timeout vs selection_field; this+0x58 as the sample-handle struct in the raw source vs the dereference base this+0x68 in the packet fields) are never merged into a shared type without packet proof of common ownership (rule 8); every class except the DERIVED-proposed clusters (ConfigParserProxyAccessor, MilesAudioSampleObject, MutexProtectedValueObject, IndexedElementArrayObject) is a GUESS proposal; worker proposals cannot create CONFIRMED facts.
