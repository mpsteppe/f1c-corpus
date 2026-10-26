# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

45 generic runtime-object functions reconstructed from validated IR. The majority (28) are small wrappers, mutators, and guards with no identifiable owning class; three defensible GUESS groupings emerge from shared evidence: (1) a family of compiler-generated thunks that forward a fixed function address to the BooleanToIntConversion helper at 0x00587B3E, (2) a driver-table container whose entries live at object base + 916 with a 140-byte stride and a count at +0x3E14, and (3) a visibility-grid accumulator object holding a float at +0x68 that is incremented/threshold-checked or decremented/clamped. Two MSVC scalar-deleting destructors and several allocate-and-init wrappers over module globals are recognized as idiomatic shapes with unknown concrete types. All proposals are DERIVED or GUESS; no CONFIRMED/FACT claims are made.

## Function roles

- `0x0044E090` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk: passes the address of null stub nullsub_165 (0x0044E0A0) to the helper at 0x00587B3E and returns the int result. Compiler-generated family member.
- `0x0044E150` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk: passes the address of null stub nullsub_167 (0x0044E160) to the helper at 0x00587B3E and returns the int result. Compiler-generated family member.
- `0x0044E1B0` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk: passes the address of null stub nullsub_168 (0x0044E1C0) to the helper at 0x00587B3E and returns the int result. Compiler-generated family member.
- `0x0044E630` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk (legacy label StringLogDeallocate2): passes the address of null stub nullsub_180 (0x0044E640) to the helper at 0x00587B3E and returns the constant result. No log/teardown behavior visible in the body.
- `0x0044E750` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk: passes the address of null stub nullsub_183 (0x0044E760) to the helper at 0x00587B3E and returns the constant result. Does not forward a real data argument.
- `0x0044E810` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk: reads the stub function pointer global at 0x0044E820, casts it to int, passes it to the helper at 0x00587B3E, and returns the result.
- `0x0044E8D0` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk (legacy label AtexitHandlerRegistration): reads the stub function pointer global at 0x0044E8E0, casts it to int, passes it to the helper at 0x00587B3E, and returns the result. Atexit-style registration role is name-carried only.
- `0x0044E930` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk: reads the stub function pointer global at 0x0044E940, casts it to int, passes it to the helper at 0x00587B3E, and returns the result.
- `0x0044EDD0` **UnknownObject** — Conditional collector (legacy label collectAudioSourceEntry): when bit 0 of the byte at this+0x1C is set, appends the dword at this+0x18 into the global array dword_7CC9CC at index dword_7CD07C and increments that counter; returns whether the counter is below 8. Audio-source interpretation is unconfirmed.
- `0x0044F010` **UnknownObject** — Stores -abs(a2) into this+0xC7C and -abs(a3) into this+0xC80. Straight-line float magnitude setter; target fields per existing analysis were surface constants. The flagged global flt_59E440 does not appear in the raw body.
- `0x0044F5E2` **UnknownObject** — Accumulates byte argument a2 into the byte at offset 0 of buffer a1, then calls UIInputPropertySetter (0x0044F6F6) with arguments the decompiler reports as uninitialized locals (positive-sp warning); returns 0.
- `0x00452700` **UnknownObject** — One-shot activation capture (legacy label ConditionalFieldSetterWithState): with override this+0x8 set, always stores input into this+0x10; otherwise captures the first non-zero input into this+0x10 and sets state this+0xC = 1, resets state on zero input, and clears this+0x10 on re-activation; returns the input in all paths. Called by sub_4537B0.
- `0x004541D0` **UnknownObject** — PAUSE-menu key-name string copier: gated by count at this+0xC88 > 0, writes the index byte at this+0xC8C to *a3, and copies a NUL-terminated string from table aPause_0 (0x005C4890, 16-byte stride, index < 0x5A) or from table aEmpty_0 (0x005C4E30, via index-128, bound 0x58) into output a2; returns 1 on copy, 0 when gated or out of range.
- `0x004542D0` **UnknownObject** — Per-entry swept-interval overlap test (legacy label SweptAABBOverlapDetection): selects a data base at this+3464 or this+4484 by selector a3, rejects when the scaled interval test is below -0.34999999, and on overlap writes float bit pattern 1056964608 or 1065353216 into dword_7D1490[216*a3 + 27*a2] depending on the caller input at a4 + 4*a2; returns 1/0. Called by sub_454350.
- `0x004562C0` **UnknownObject** — Scalar-deleting destructor shape: writes the global pointer off_59EFCC into this[0], frees this[1] (offset 0x4) via FreeWrapper_7bcf when non-null, and frees this itself via FreeWrapper_7bcf when (a2 & 1) is set; returns this. Structural twin of 004562A0 extended with the delete-this branch.
- `0x00456F60` **UnknownObject** — Unconditional byte flag setter: writes literal 1 to the byte at this+0x7C. No guards, globals, or callees; owning object unknown.
- `0x0045B300` **UnknownObject** — Single-call delegation wrapper: invokes the object-allocation routine with the address of global dword_7CD204 and returns the allocation result directly.
- `0x0045B3E0` **UnknownObject** — Scalar-deleting destructor: runs DestructorWithResourceCleanup (0x0045B400) on this, then frees this via FreeWrapper_7bcf when the low bit of the deletion flag a2 is set, and returns this.
- `0x0045BB90` **UnknownObject** — Object allocator: allocates an 812-byte block via the operator-new wrapper 0x00587C03, initializes it with 0x0045BB40 on success and stores the pointer into this[0], or stores 0 on failure; returns this.
- `0x0045BE70` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk: passes the code address of sub_45BE80 (AVIStreamGlobalCleanup) to the helper at 0x00587B3E and returns its result.
- `0x0045BE80` **UnknownObject** — Global AVI-stream cleanup: passes the address of global dword_7CD208 to AVIStreamCleanup (0x0045BEA0), snapshots the global, and frees the object via FreeWrapper_7bcf when the global was non-null; returns the free result or the null snapshot.
- `0x0045BF50` **UnknownObject** — Audio-channel storage init: allocates a 118368-byte block via the operator-new wrapper; on success runs AudioChannelInit on the storage at global dword_7CD25C and stores the result into dword_7CD25C[0], on failure stores 0; returns the dword_7CD25C pointer. Raw source writes the global despite the packet's rw=R label.
- `0x0045BFF0` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk: passes the code address of sub_45C000 (closeHandleIfOpen) to the helper at 0x00587B3E and returns its result.
- `0x0045C000` **UnknownObject** — Guarded handle close: when the byte flag at 0x007CD26C is non-zero, closes the cached handle dword_7CD264 via CloseHandle (import thunk 0x0059E1A8) and clears it on success; returns the flag byte or the CloseHandle result.
- `0x0045C3C0` **UnknownObject** — Writes parameter a2 into the byte at this+0x0 and a3 into the byte at this+0x1; returns a2.
- `0x0045C760` **UnknownObject** — Computes the difference of the __int16 values pointed to by a1 and a2 and returns it as int. __cdecl helper with no this context; the packet's field:this:0 entry is a template artifact.
- `0x0045D490` **UnknownObject** — State-gated setter: calls StateCheckWrapper (0x00461DC0) on global dword_7CD25C; when it passes, calls sub_45CD70(this) and sets the byte at this+1 to the value of global byte_7D0F94 (1 or 0); returns the state-check result or the flag value. Called by 0x00463F70.
- `0x0045D4E0` **UnknownObject** — Flag-dispatch helper (legacy label StringLengthCheckDispatch): returns early when this[0] is zero; otherwise when this[1] is non-zero calls the inactivity-timeout handler on the off_5E4DFC pointer, then calls NetworkPacketReceive on both paths and returns its result. Invoked by SessionScoringUpdate (0x004643C0).
- `0x004615C0` **UnknownObject** — Bit-field mutator (legacy label SetOrClearFlagBit): builds mask 1 << a2 and sets or clears that bit in the byte at this+0x6E according to boolean a3; returns the (possibly inverted) mask.
- `0x00462310` **UnknownObject** — Forwarder: dereferences this, reads the COM interface pointer at obj+0x3FB8, passes it to ShortComputation_a820 (0x0057A820), and returns the unsigned-byte result. Called by InputCommandDispatchToEntities (0x0045F4A0).
- `0x00462380` **DriverTableContainer** — Counts driver-table entries with flag bit 2 set (legacy label FlaggedDriverCount): gated by the driver count at obj+0x3E14 > 0, iterates 140-byte-stride entries starting at obj+916 calling FlagBitTest (0x00461530) per entry, and returns the count.
- `0x00462460` **DriverTableContainer** — Driver-entry lookup by ID byte (legacy label DriverDataCopyByID): gated by the driver count at obj+0x3E14 > 0, iterates 140-byte-stride entries starting at obj+916, compares the ID byte at entry+0x7C with a2, and on match qmemcpys the 0x8C-byte block at entry+916 into a3 and writes the parallel dword (obj + 15476 + 4*index) into *a4; returns 1 on match else 0. Used by 0x0045D890 and 0x0046E1B0.
- `0x004630C0` **UnknownObject** — Trivial stdcall passthrough (legacy label PathRegistryCallWrapper): forwards its single argument to StringCopyWithBufferRealloc and returns that result unchanged. Sole caller sub_45D2D0.
- `0x00463C40` **UnknownObject** — Getter: reads the pointer at this+0, adds 284 (0x11C), and returns that string pointer when the NUL-terminated string there is non-empty, else NULL.
- `0x00463CA0` **UnknownObject** — Guarded radio-message pump: when the state flag at obj+0x3FC4 (obj = *this) is non-zero, calls sub_57A730(256) and then TeamRadioNetworkMessageProcessing(obj), returning its result; otherwise returns the object primary pointer. Called by GamePostMainLoop (0x0042D8A0).
- `0x00463E00` **UnknownObject** — State-guarded delegation: dereferences this to obj and, when the dword at obj+0x3FC4 equals 3, calls the particle/sound spawner on obj and returns its result; on state != 3 the fall-through return is an uninitialized decompiler artifact. Invoked by sub_4A00A0.
- `0x00464930` **UnknownObject** — Allocates a 58832-byte buffer, initializes a large struct into global dword_7CD2A8 (via LargeStructInitialization on success, 0 on failure), and returns the address of dword_7CD2A8.
- `0x00464940` **BooleanToIntConversionThunks** — BooleanToIntConversion thunk: calls the helper at 0x00587B3E with the int-cast address of sub_464950 (0x00464950) and returns the result. Referenced routine is passed by address, not invoked.
- `0x00464950` **UnknownObject** — Thin wrapper (legacy label CallHandlerOnLargeStruct): calls sub_465000 with the address of global dword_7CD2A8 and returns its integer result.
- `0x00464990` **UnknownObject** — Squared-distance query: reads the entity pointer from this[0], computes squared Euclidean distance between entity offsets +0x75/+0x79/+0x7D and reference a2[3384..3386], stores the sum into this[1] (offset +0x4), and returns the entity pointer. Called by EntityVisibilityGridManager (0x00465460).
- `0x00464BB0` **VisibilityAccumulator** — Accumulator with threshold check: adds the float input a2 to this[26] (offset +0x68), stores the sum back, and returns true when the accumulated value is >= threshold a3. Called by EntityVisibilityGridManager (0x00465460).
- `0x00464BD0` **VisibilityAccumulator** — Decrements the float field this[26] (offset +0x68) by a2 and clamps the result into [0.0, a2]; always writes the field. Called by EntityVisibilityGridManager (0x00465460). The flagged global flt_59E440 does not appear in the raw body.
- `0x00464D20` **UnknownObject** — Clears the byte at this[0] to 0 and returns the this pointer. No static callers recorded.
- `0x00464E90` **UnknownObject** — Buffer-size lookup: maps selector a1 through the jump table at 0x00464ECC to a fixed size (1 -> 2975, 2 -> 7200, 3 -> 28800, 4 -> 625000, default 1487). Called by 0x00464EE0 and 0x00465430.
- `0x00464EE0` **UnknownObject** — Counter-gated delegate (legacy label ConditionalDelegateBasedOnCounter): returns the counter at this[20] (offset +0x50) directly when positive, otherwise delegates to BufferSizeLookup(*this) and returns its result. Called by DivisionWithCapComputation (0x00464F50).

## Proposed classes

### BooleanToIntConversionThunks

Compiler-generated thunk family: each member passes a fixed function address (code address or stub-pointer global) as the single argument to the shared BooleanToIntConversion helper at 0x00587B3E and returns the coerced integer result. The pattern is uniform across members; whether the helper registers (atexit-style), invokes, or merely coerces the pointer value is not established. Grouping reflects the shared callee and identical call shape, not a proven domain class.

Methods: `0x0044E090`, `0x0044E150`, `0x0044E1B0`, `0x0044E630`, `0x0044E750`, `0x0044E810`, `0x0044E8D0`, `0x0044E930`, `0x0045BE70`, `0x0045BFF0`, `0x00464940`


### DriverTableContainer

Hosts a per-driver table reached through the object pointer stored at this+0: the driver count lives at obj+0x3E14 and driver entries are 140-byte blocks starting at obj+916, each carrying an ID byte (entry+0x7C) and flag bits. Exposes a counted walk (FlaggedDriverCount) and an ID-keyed lookup that copies a matched entry into a caller buffer (DriverDataCopyByID). Layout values are DERIVED from raw source text, not from the deterministic field list.

Methods: `0x00462380`, `0x00462460`

- `this+0x00000000` `void* driverTableObject` (read, GUESS)
- `obj+0x00003E14` `int driverCount` (read, GUESS)

### VisibilityAccumulator

Per-object float accumulator/timer at +0x68 used by the visibility-grid manager (0x00465460): one method adds a caller-supplied increment and reports whether the accumulated value crossed a threshold, the other decrements by a caller-supplied amount and clamps into [0.0, amount]. Common ownership is inferred from the shared base-this offset +0x68 and the shared caller; the field's semantic role is not otherwise evidenced.

Methods: `0x00464BB0`, `0x00464BD0`

- `this+0x00000068` `float accumulator` (read_write, GUESS)

## Compatibility contracts

- **ScalarDeletingDestructorConvention** — 0x0045B3E0 and 0x004562C0 follow the MSVC scalar-deleting destructor convention: they return the this pointer, and the low bit of the second argument (a2 & 1) selects whether the object itself is freed through the FreeWrapper_7bcf allocation domain. A replacement executable exposing these slots must preserve this convention and the free-domain pairing.
- **BufferSizeSelectorTable** — 0x00464E90 maps a selector argument to a fixed buffer size through the jump table at 0x00464ECC: 1 -> 2975, 2 -> 7200, 3 -> 28800, 4 -> 625000, any other value -> 1487. Callers 0x00464EE0 and 0x00465430 rely on these exact sizes.
- **AudioSourceCollectionSink** — 0x0044EDD0 appends a source dword into the global array dword_7CC9CC indexed by the counter dword_7CD07C, gated on bit 0 of the source entry flag byte at this+0x1C, and reports buffer-not-full while the counter is below 8. Consumers of dword_7CC9CC depend on this 8-slot collection contract.

## Unresolved

- The purpose of BooleanToIntConversion (0x00587B3E) is not established: atexit-style registration, function-pointer invocation, or mere integer coercion are all unproven; the thunk family is grouped on call-shape evidence only.
- The null-stub targets nullsub_165/167/168/180/183/185/187/188 have no bodies; their intended callback behavior is unrecoverable from this packet.
- Owner object types are unidentified for the majority of functions (28 of 45), including all allocators, destructors, flag setters, and lookup helpers; these remain UnknownObject.
- The PAUSE-string copy tables aPause_0 (0x005C4890) and aEmpty_0 (0x005C4E30) contents are unknown beyond the 16-byte stride.
- The driver-table geometry (entries at obj+916, 140-byte stride, ID at entry+0x7C, parallel dword table at obj+15476) is DERIVED from raw source text only and is absent from the deterministic field list.
- flt_59E440 is flagged as read by 0x0044F010 and 0x00464BD0 but never appears in either raw body; flt_59EF7C/flt_59EF80 are similarly flagged for 0x004542D0 but absent from its raw source.
- Packet labels dword_7CD25C and dword_7CD2A8 as read-only (rw=R) even though raw source writes them; raw source is treated as authoritative.
- The 118368-byte audio-channel allocation and the 58832-byte large struct imply fixed layouts that are not established by this packet.
- The 812-byte layout produced by initializer 0x0045BB40 is outside packet coverage.
- 0x0045D4E0 returns an uninitialized local on its this[0] == 0 path and 0x00463E00 returns an uninitialized local on its state != 3 path; both are decompiler artifacts whose real fall-through values are unproven.
- 0x0044F5E2 passes uninitialized locals to UIInputPropertySetter under a positive-sp compiler warning; the rendered call arguments may be wrong.
- Whether FreeWrapper_7bcf (0x00587BCF) is operator delete or a custom free is unverified, so allocation-domain pairing for the destructors and AVI-stream cleanup is unproven.
- The entity struct referenced by 0x00464990 (offsets +0x75/+0x79/+0x7D) and the reference object a2 (indices 3384..3386) are unidentified.
- State values of obj+0x3FC4 (non-zero gate in 0x00463CA0 vs equality-3 gate in 0x00463E00) may belong to one shared object but common ownership is not proven; they are left as separate UnknownObject entries.
- Which of the 45 functions are vtable slots versus free functions is not evidenced by this packet; 0x004562C0's write of off_59EFCC to slot 0 is treated as a vtable/base-pointer pattern, not proven.
